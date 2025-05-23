#!/usr/bin/env python
#
# Software License Agreement (BSD License)
#
# Copyright (c) 2009, Willow Garage, Inc.
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
#
#  * Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
#  * Redistributions in binary form must reproduce the above
#    copyright notice, this list of conditions and the following
#    disclaimer in the documentation and/or other materials provided
#    with the distribution.
#  * Neither the name of the Willow Garage nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
# FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
# COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
# BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
# LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
# CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
# LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
# ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

import cv2
import cv_bridge
import functools
import numpy
import threading
try:
    from queue import Queue
except ImportError:
    from Queue import Queue

import message_filters
from message_filters import ApproximateTimeSynchronizer
import rclpy
from rclpy.node import Node
import sensor_msgs.msg
import sensor_msgs.srv

from camera_calibration.mono_calibrator import MonoCalibrator
from camera_calibration.stereo_calibrator import StereoCalibrator
from camera_calibration.calibrator import ChessboardInfo


def mean(seq):
    return sum(seq) / len(seq)


def lmin(seq1, seq2):
    """ Pairwise minimum of two sequences """
    return [min(a, b) for (a, b) in zip(seq1, seq2)]


def lmax(seq1, seq2):
    """ Pairwise maximum of two sequences """
    return [max(a, b) for (a, b) in zip(seq1, seq2)]


class ConsumerThread(threading.Thread):
    def __init__(self, queue, function):
        threading.Thread.__init__(self)
        self.queue = queue
        self.function = function

    def run(self):
        while rclpy.ok():
            if self.queue.empty():
                continue
            m = self.queue.get()
            self.function(m)


class CameraCheckerNode(Node):

    def __init__(self, name, chess_size, dim, approximate=0):
        super().__init__(name)
        self.board = ChessboardInfo()
        self.board.n_cols = chess_size[0]
        self.board.n_rows = chess_size[1]
        self.board.dim = dim

        # make sure n_cols is not smaller than n_rows, otherwise error computation will be off
        if self.board.n_cols < self.board.n_rows:
            self.board.n_cols, self.board.n_rows = self.board.n_rows, self.board.n_cols

        image_topic = "monocular/image_rect"
        camera_topic = "monocular/camera_info"

        tosync_mono = [
            (image_topic, sensor_msgs.msg.Image),
            (camera_topic, sensor_msgs.msg.CameraInfo),
        ]

        if approximate <= 0:
            sync = message_filters.TimeSynchronizer
        else:
            sync = functools.partial(
                ApproximateTimeSynchronizer, slop=approximate)

        tsm = sync([message_filters.Subscriber(self, type, topic)
                   for (topic, type) in tosync_mono], 10)
        tsm.registerCallback(self.queue_monocular)

        left_topic = "stereo/left/image_rect"
        left_camera_topic = "stereo/left/camera_info"
        right_topic = "stereo/right/image_rect"
        right_camera_topic = "stereo/right/camera_info"

        tosync_stereo = [
            (left_topic, sensor_msgs.msg.Image),
            (left_camera_topic, sensor_msgs.msg.CameraInfo),
            (right_topic, sensor_msgs.msg.Image),
            (right_camera_topic, sensor_msgs.msg.CameraInfo)
        ]

        tss = sync([message_filters.Subscriber(self, type, topic)
                   for (topic, type) in tosync_stereo], 10)
        tss.registerCallback(self.queue_stereo)

        self.br = cv_bridge.CvBridge()

        self.q_mono = Queue()
        self.q_stereo = Queue()

        mth = ConsumerThread(self.q_mono, self.handle_monocular)
        mth.setDaemon(True)
        mth.start()

        sth = ConsumerThread(self.q_stereo, self.handle_stereo)
        sth.setDaemon(True)
        sth.start()

        self.mc = MonoCalibrator([self.board])
        self.sc = StereoCalibrator([self.board])

    def queue_monocular(self, msg, cmsg):
        self.q_mono.put((msg, cmsg))

    def queue_stereo(self, lmsg, lcmsg, rmsg, rcmsg):
        self.q_stereo.put((lmsg, lcmsg, rmsg, rcmsg))

    def mkgray(self, msg):
        return self.mc.mkgray(msg)

    def image_corners(self, im):
        (ok, corners, ids, b) = self.mc.get_corners(im)
        if ok:
            return corners, ids
        else:
            return None, None

    def handle_monocular(self, msg):

        (image, camera) = msg
        gray = self.mkgray(image)
        C, ids = self.image_corners(gray)
        if C is not None:
            linearity_rms = self.mc.linear_error(C, ids, self.board)

            # Add in reprojection check
            image_points = C
            object_points = self.mc.mk_object_points(
                [self.board], use_board_size=True)[0]
            dist_coeffs = numpy.zeros((4, 1))
            camera_matrix = numpy.array([[camera.p[0], camera.p[1], camera.p[2]],
                                         [camera.p[4], camera.p[5], camera.p[6]],
                                         [camera.p[8], camera.p[9], camera.p[10]]])
            ok, rot, trans = cv2.solvePnP(
                object_points, image_points, camera_matrix, dist_coeffs)
            # Convert rotation into a 3x3 Rotation Matrix
            rot3x3, _ = cv2.Rodrigues(rot)
            # Reproject model points into image
            object_points_world = numpy.asmatrix(
                rot3x3) * numpy.asmatrix(object_points.squeeze().T) + numpy.asmatrix(trans)
            reprojected_h = camera_matrix * object_points_world
            reprojected = (reprojected_h[0:2, :] / reprojected_h[2, :])
            reprojection_errors = image_points.squeeze().T - reprojected

            reprojection_rms = numpy.sqrt(numpy.sum(numpy.array(
                reprojection_errors) ** 2) / numpy.product(reprojection_errors.shape))

            # Print the results
            self.get_logger().info("Linearity RMS Error: %.3f Pixels      Reprojection RMS Error: %.3f Pixels" % (
                linearity_rms, reprojection_rms))
        else:
            self.get_logger().info('no chessboard')

    def handle_stereo(self, msg):

        (lmsg, lcmsg, rmsg, rcmsg) = msg
        lgray = self.mkgray(lmsg)
        rgray = self.mkgray(rmsg)

        L, _ = self.image_corners(lgray)
        R, _ = self.image_corners(rgray)
        if L is not None and R is not None:
            epipolar = self.sc.epipolar_error(L, R)

            dimension = self.sc.chessboard_size(
                L, R, self.board, msg=(lcmsg, rcmsg))

            self.get_logger().info("epipolar error: %f pixels   dimension: %f m" %
                  (epipolar, dimension))
        else:
            self.get_logger().info("no chessboard")
