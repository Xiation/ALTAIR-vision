# Copyright (c) 2022 Hamburg Bit-Bots
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

from typing import Optional

from builtin_interfaces.msg import Time
import cv2
from geometry_msgs.msg import Transform
import numpy as np
from rclpy.duration import Duration
from sensor_msgs.msg import CameraInfo
from shape_msgs.msg import Plane
from tf2_geometry_msgs import PointStamped
import tf2_ros


def plane_general_to_point_normal(plane: Plane) -> tuple[np.ndarray, np.ndarray]:
    """
    Convert general plane form to point normal form.

    :param plane: The input plane in general form
    :returns: A tuple with the point and normal
    """
    # ax + by + cz + d = 0 where a, b, c are the normal vector
    a, b, c, d = plane.coef
    # A perpendicular array to the plane
    perpendicular = np.array([a, b, c])
    # Get closest point from (0, 0, 0) to the plane
    point = perpendicular * -d / np.dot(perpendicular, perpendicular)
    # A normal vector to the plane
    normal = perpendicular / np.linalg.norm(perpendicular)
    return point, normal


def transform_plane_to_frame(
        plane: tuple[np.ndarray, np.ndarray],
        input_frame: str,
        output_frame: str,
        time: Time,
        buffer: tf2_ros.Buffer,
        timeout: Optional[Duration] = None) -> tuple[np.ndarray, np.ndarray]:
    """
    Transform a plane from one frame to another.

    :param plane: The planes base point and normal vector as numpy arrays
    :param input_frame: Current frame of the plane
    :param output_frame: The desired frame of the plane
    :param time: Timestamp which is used to query the tf buffer and get the tranform at this moment
    :param buffer: The refrence to the used tf buffer
    :param timeout: An optinal timeout after which an exception is raised
    :returns: A Tuple containing the planes base point and normal vector in the
         new frame at the provided timestamp
    """
    # Set optional timeout
    if timeout is None:
        timeout = Duration(seconds=0.5)

    # Create two points to transform the base point and the normal vector
    # The second point is generated by adding the normal to the base point
    field_normal = PointStamped()
    field_normal.header.frame_id = input_frame
    field_normal.header.stamp = time
    field_normal.point.x = plane[0][0] + plane[1][0]
    field_normal.point.y = plane[0][1] + plane[1][1]
    field_normal.point.z = plane[0][2] + plane[1][2]
    field_normal = buffer.transform(
        field_normal, output_frame, timeout=timeout)
    field_point = PointStamped()
    field_point.header.frame_id = input_frame
    field_point.header.stamp = time
    field_point.point.x = plane[0][0]
    field_point.point.y = plane[0][1]
    field_point.point.z = plane[0][2]
    field_point = buffer.transform(field_point, output_frame, timeout=timeout)

    field_point = np.array([
        field_point.point.x,
        field_point.point.y,
        field_point.point.z])
    field_normal = np.array([
        field_normal.point.x,
        field_normal.point.y,
        field_normal.point.z])

    # field normal is a vector! so it stats at field point and goes up in z direction
    field_normal = field_point - field_normal
    return field_point, field_normal


def get_field_intersection_for_pixels(
        camera_info: CameraInfo,
        points: np.ndarray,
        plane_normal: np.ndarray,
        plane_base_point: np.ndarray,
        scale: float = 1.0,
        use_distortion: bool = False) -> np.ndarray:
    """
    Map a NumPy array of points in image space on the given plane.

    :param points: A nx2 array with n being the number of points
    :param plane_normal: The normal vector of the mapping plane
    :param plane_base_point: The base point of the mapping plane
    :param scale: A scaling factor used if e.g. a mask with a lower resolution is transformed
    :param use_distortion: A flag to indicate if distortion should be accounted for.
        Do not use this if you are working with pixel coordinates from a rectified image.
    :returns: A NumPy array containing the mapped points
        in 3d relative to the camera optical frame
    """
    # Apply binning and scale
    binning_x = max(camera_info.binning_x, 1) / scale
    binning_y = max(camera_info.binning_y, 1) / scale
    points = points * np.array([binning_x, binning_y])

    # Create identity distortion coefficients if no distortion is used
    if use_distortion:
        distortion_coefficients = np.array(camera_info.d)
    else:
        distortion_coefficients = np.zeros(5)

    # Get the ray directions relative to the camera optical frame for each of the points
    ray_directions = np.ones((points.shape[0], 3))
    if points.shape[0] > 0:
        ray_directions[:, :2] = cv2.undistortPoints(
            points.reshape(1, -1, 2).astype(np.float32),
            np.array(camera_info.k).reshape(3, 3),
            distortion_coefficients).reshape(-1, 2)

    # Calculate ray -> plane intersections
    intersections = line_plane_intersections(
        plane_normal, plane_base_point, ray_directions)

    return intersections


def line_plane_intersections(
        plane_normal: np.ndarray,
        plane_base_point: np.ndarray,
        ray_directions: np.ndarray) -> np.ndarray:
    """
    Calculate the intersections of rays with a plane described by a normal and a point.

    :param plane_normal: The normal vector of the mapping plane
    :param plane_base_point: The base point of the mapping plane
    :param ray_directions: A nx3 array with n being the number of rays
    :returns: A nx3 array containing the 3d intersection points with n being the number of rays.
    """
    n_dot_u = np.tensordot(plane_normal, ray_directions, axes=([0], [1]))
    relative_ray_distance = plane_normal.dot(plane_base_point) / n_dot_u

    # we are casting a ray, intersections need to be in front of the camera
    relative_ray_distance[relative_ray_distance <= 0] = np.nan

    ray_directions[:, 0] = np.multiply(
        relative_ray_distance, ray_directions[:, 0])
    ray_directions[:, 1] = np.multiply(
        relative_ray_distance, ray_directions[:, 1])
    ray_directions[:, 2] = np.multiply(
        relative_ray_distance, ray_directions[:, 2])

    return ray_directions


def transform_points(point_cloud: np.ndarray, transform: Transform) -> np.ndarray:
    """
    Transform a bulk of points from an numpy array using a provided `Transform`.

    :param point_cloud: nx3 Array of points where n is the number of points
    :param transform: TF2 transform used for the transformation
    :returns: Array with the same shape as the input array, but with the transformation applied
    """
    # Build affine transformation
    transform_translation = np.array([
        transform.translation.x,
        transform.translation.y,
        transform.translation.z
    ])
    transform_rotation_matrix = _get_mat_from_quat(
        np.array([
            transform.rotation.w,
            transform.rotation.x,
            transform.rotation.y,
            transform.rotation.z
        ]))

    # "Batched" matmul meaning a matmul for each point
    # First we offset all points by the translation part
    # followed by a rotation using the rotation matrix
    return np.einsum(
        'ij, pj -> pi',
        transform_rotation_matrix,
        point_cloud) + transform_translation


def _get_mat_from_quat(quaternion: np.ndarray) -> np.ndarray:
    """
    Convert a quaternion to a rotation matrix.

    This method is currently needed because transforms3d is not released as a `.dep` and
    would require user interaction to set up.
    For reference see: https://github.com/matthew-brett/transforms3d/blob/
    f185e866ecccb66c545559bc9f2e19cb5025e0ab/transforms3d/quaternions.py#L101

    :param quaternion: A numpy array containing the w, x, y, and z components of the quaternion
    :returns: The rotation matrix
    """
    Nq = np.sum(np.square(quaternion))
    if Nq < np.finfo(np.float64).eps:
        return np.eye(3)

    XYZ = quaternion[1:] * 2.0 / Nq
    wXYZ = XYZ * quaternion[0]
    xXYZ = XYZ * quaternion[1]
    yYZ = XYZ[1:] * quaternion[2]
    zZ = XYZ[2] * quaternion[3]

    return np.array(
        [[1.0-(yYZ[0]+zZ), xXYZ[1]-wXYZ[2], xXYZ[2]+wXYZ[1]],
         [xXYZ[1]+wXYZ[2], 1.0-(xXYZ[0]+zZ), yYZ[1]-wXYZ[0]],
         [xXYZ[2]-wXYZ[1], yYZ[1]+wXYZ[0], 1.0-(xXYZ[0]+yYZ[0])]])


def create_horizontal_plane(
        height_offset: float = 0.0) -> Plane:
    """Create a plane message for a given frame at a given time, with a given height offset."""
    plane = Plane()
    plane.coef[2] = 1.0  # Normal in z direction
    plane.coef[3] = -height_offset  # Distance above the ground
    return plane
