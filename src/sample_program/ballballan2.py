import cv2
import numpy as np

prev_data = []

def ball(frame):
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    lower_orange = np.array([1, 120, 75])
    upper_orange = np.array([25, 255, 255])

    mask_ball = cv2.inRange(hsv, lower_orange, upper_orange)

    kernel = np.ones((15, 15), np.uint8)
    mask_ball = cv2.morphologyEx(mask_ball, cv2.MORPH_CLOSE, kernel)

    contours, _ = cv2.findContours(mask_ball, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    min_area_threshold = 700  # Ambang batas minimum area hijau untuk dianggap sebagai lapangan
    ball_cleaned = np.zeros_like(mask_ball)

    for contour in contours:
        area = cv2.contourArea(contour)
        if area > min_area_threshold:
            cv2.drawContours(ball_cleaned, [contour], -1, 255, thickness=cv2.FILLED)  # Hanya gambar area besar

    return ball_cleaned

def field(frame):
    hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

    # green
    lower_green = np.array([30, 50, 15])
    upper_green = np.array([100, 255, 255])
    mask_green = cv2.inRange(hsv, lower_green, upper_green)

    # white
    lower_white = np.array([0, 0, 180])
    upper_white = np.array([190, 25, 255])
    mask_white = cv2.inRange(hsv, lower_white, upper_white)

    mask_field = cv2.bitwise_or(mask_green, mask_white)

    kernel = np.ones((15, 15), np.uint8)
    mask_field = cv2.morphologyEx(mask_field, cv2.MORPH_CLOSE, kernel)

    contours, _ = cv2.findContours(mask_field, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
    min_area_threshold = 5000
    field_cleaned = np.zeros_like(mask_field)

    for contour in contours:
        area = cv2.contourArea(contour)
        if area > min_area_threshold:
            cv2.drawContours(field_cleaned, [contour], -1, 255, thickness=cv2.FILLED)

    return field_cleaned

def detect(mask_ball, mask_field, frame):
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

            R = int(r * 1.5)  #jarak deteksi
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

            first_orange = None
            last_orange = None

            for idx in range(orange_line.size):
                if orange_line[idx] == 255:
                    first_orange = idx + line_x_start
                    break

            for idx in range(orange_line.size - 1, -1, -1):
                if orange_line[idx] == 255:
                    last_orange = idx + line_x_start
                    break

            cv2.line(frame, (first_orange, line_y), (last_orange, line_y), (0, 255, 0), 2)

            orange_pixel_count = np.sum(orange_line == 255)
            total_pixel = last_orange - first_orange

            text = f"Diameter: {total_pixel} pixel"
            cv2.putText(frame, text, (x - r, y + r + 20), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)

            for px in range(first_orange, last_orange):
                if orange_line[px - line_x_start] != 255:
                    cv2.circle(frame, (px, line_y), 1, (0, 0, 255), -1)

            if (field_ratio > 0.16 and ball_ratio < 0.37):
                x_new = int((last_orange + first_orange)/2)
                r_new = int(orange_pixel_count/2)
                cv2.circle(frame, (x_new, y), r_new, (0, 255, 0), 2)
                cv2.circle(frame, (x_new, y), 2, (0, 0, 255), 3)
                prev_data = [x_new, y, r_new]
            elif circles is None:
                x, y, r = prev_data
                cv2.circle(frame, (x, y), r, (0, 255, 0), 2)
                cv2.circle(frame, (x, y), 2, (0, 0, 255), 3)
                break

            actual_diameter = 0.13  # meter
            focal_length = 700
            detected_diameter = total_pixel
            distance = (actual_diameter * focal_length) / detected_diameter
            text2 = f"Distance: {distance:.2f} meter"
            cv2.putText(frame, text2, (x - r, y + r + 40), cv2.FONT_HERSHEY_SIMPLEX, 0.6, (255, 255, 255), 2)

    return frame

def main():
    # Read image instead of video
    image_path = "/home/altair/Documents/ALTAIR-vision/src/sample_program/samplesIMG/sampleLineDet.jpeg"  # Replace with your image path
    frame = cv2.imread(image_path)
    
    if frame is None:
        print("Error: Cannot read the image.")
        return

    # Process the image
    mask_ball = ball(frame)
    mask_field = field(frame)
    final_frame = detect(mask_ball, mask_field, frame.copy())

    # Show results
    cv2.imshow("Ball Detection and Measurement", final_frame)
    cv2.imshow("Ball Mask", mask_ball)
    cv2.imshow("Field Mask", mask_field)
    
    # Save the result
    cv2.imwrite("result.jpg", final_frame)
    
    # Wait for key press and close windows
    cv2.waitKey(0)
    cv2.destroyAllWindows()

if __name__ == "__main__":
    main()