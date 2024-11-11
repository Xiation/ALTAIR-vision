import rclpy 
from rclpy import Node
from std_msgs.msg import Float64
import cv2
import numpy as np
import time

class BallDetector(Node):
    def __init__(self):
        super().__init__('ball_detector')
        self.ball_distance_publisher = self.create_publisher(Float64, 'vision/ball_distance', 10)

    def ball(self, frame):
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        lower_orange = np.array([1, 120, 110])
        upper_orange = np.array([25, 255, 255])
        mask_ball = cv2.inRange(hsv, lower_orange, upper_orange)
        return mask_ball

    def field(self, frame):
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
        lower_green = np.array([30, 50, 15])
        upper_green = np.array([100, 255, 255])
        mask_green = cv2.inRange(hsv, lower_green, upper_green)
        lower_white = np.array([0, 0, 180])
        upper_white = np.array([190, 25, 255])
        mask_white = cv2.inRange(hsv, lower_white, upper_white)
        mask_field = cv2.bitwise_or(mask_green, mask_white)
        return mask_field

    def detect(self, mask_ball, mask_field, frame):
        blurred_ball_mask = cv2.GaussianBlur(mask_ball, (9, 9), 2)
        circles = cv2.HoughCircles(
            blurred_ball_mask,
            cv2.HOUGH_GRADIENT,
            dp=1.2,
            minDist=50,
            param1=50,
            param2=30,
            minRadius=10,
            maxRadius=100
        )

        if circles is not None:
            circles = np.uint16(np.around(circles))
            for i in circles[0, :]:
                x, y, r = i[0], i[1], i[2]
                R = int(r * 1.5)
                x1, y1 = max(x - R, 0), max(y - R, 0)
                x2, y2 = min(x + R, frame.shape[1]), min(y + R, frame.shape[0])

                surrounding_field = mask_field[y1:y2, x1:x2]
                field_ratio = np.sum(surrounding_field == 255) / surrounding_field.size
                surrounding_ball = mask_ball[y1:y2, x1:x2]
                ball_ratio = np.sum(surrounding_ball == 255) / surrounding_ball.size

                mask_circle = np.zeros(mask_ball.shape, dtype=np.uint8)
                cv2.circle(mask_circle, (x, y), R, 255, thickness=-1)
                masked_orange_in_circle = cv2.bitwise_and(mask_ball, mask_ball, mask=mask_circle)
                
                line_y = y
                line_x_start = max(x - R, 0)
                line_x_end = min(x + R, frame.shape[1])
                orange_line = masked_orange_in_circle[line_y, line_x_start:line_x_end]

                first_orange = next((idx + line_x_start for idx in range(orange_line.size) if orange_line[idx] == 255), None)
                last_orange = next((idx + line_x_start for idx in range(orange_line.size - 1, -1, -1) if orange_line[idx] == 255), None)

                if first_orange is not None and last_orange is not None:
                    total_pixel = last_orange - first_orange
                    actual_diameter = 0.13  # in meters
                    focal_length = 700
                    distance = (actual_diameter * focal_length) / total_pixel

                    return total_pixel, distance

        return None, None

def main(args=None):
    rclpy.init(args=args)
    bd = BallDetector()
    cap = cv2.VideoCapture(0)

    if not cap.isOpened():
        print("Error: Cannot open video.")
        exit()

    while rclpy.ok():
        ret, frame = cap.read()
        if not ret:
            print("No frames left, terminating.")
            break

        mask_ball = bd.ball(frame)
        mask_field = bd.field(frame)
        diameter, distance = bd.detect(mask_ball, mask_field, frame)

        if diameter is not None and distance is not None:
            bd.get_logger().info(f"Detected Diameter: {diameter} pixels, Distance: {distance:.2f} meters")
            msg = Float64()
            msg.data = distance
            bd.ball_distance_publisher.publish(msg)

    cap.release()

if __name__ == "__main__":
    main()
