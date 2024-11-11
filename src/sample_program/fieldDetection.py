import numpy as np
import cv2

# Define color thresholds in HSV color space for field and lines

# green field
green_lower = np.array([36,100,100], dtype=np.uint8)
green_upper = np.array([86,255,255], dtype=np.uint8)

# white line
white_lower = np.array([0,0,200], dtype=np.uint8)
white_upper = np.array([180,20,255], dtype=np.uint8)

def removeBackground(image_hsv):
    field_mask = cv2.inRange(image_hsv, green_lower, green_upper)
    field_area = cv2.bitwise_and(image_hsv, image_hsv, field_mask)
    return field_area

def binarizing(image_hsv):
    line_mask = cv2.inRange(image_hsv, white_lower, white_upper)
    kernel = np.ones((3,3), np.uint8)
    line_mask = cv2.morphologyEx(line_mask, cv2.MORPH_CLOSE, kernel)
    return line_mask

def detect_transitions(binarized_image):
    height, width = binarized_image.shape
    points = []

    # horizontal scanning
    for y in range(height):
        for x in range(1, width - 1):
            if binarized_image[y, x-1] == 0 and binarized_image[y, x] == 255 and binarized_image[y, x+1] == 255:
                points.append((x, y))

    # Vertical scanning
    for x in range(width):
        for y in range(1, height - 1):
            if binarized_image[y-1, x] == 0 and binarized_image[y, x] == 255 and binarized_image[y+1, x] == 255:
                points.append((x, y))
    return points

def calculate_error(line, points):
    if len(line) < 2:
        return 0
    x0, y0 = line[0]
    x1, y1 = line[-1]
    px, py = points
    # line equation: (y - y0) =  m * (x - xo) where m is the slope
    # error is the perpendicular distance from the point to the line 
    if x1 == x0:
        return abs(px-x0)
    else:
        m = (y1 - y0) / (x1 - x0)
        b = y0 - m * x0
        error = abs(m * px - py + b ) / np.sqrt(m**2 + 1)
        return error
