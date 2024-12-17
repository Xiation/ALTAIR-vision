import cv2
import numpy as np

# Define color thresholds for white lines
white_lower = np.array([0, 0, 210], dtype=np.uint8)
white_upper = np.array([180, 30, 255], dtype=np.uint8)

def create_green_mask(image_hsv):
    # Define thresholds for green color in HSV
    green_lower = np.array([36, 100, 100], dtype=np.uint8)
    green_upper = np.array([86, 255, 255], dtype=np.uint8)
    return cv2.inRange(image_hsv, green_lower, green_upper)

def mask_lines_near_green(line_mask, green_mask):
    # Create an output mask initialized to zero
    output_mask = np.zeros_like(line_mask)

    # Get the indices of the line mask where there are lines
    line_indices = np.argwhere(line_mask > 0)

    for x, y in line_indices:
        # Check neighboring pixels (3x3 area)
        neighbors = [
            (x-1, y), (x+1, y), (x, y-1), (x, y+1),
            (x-1, y-1), (x-1, y+1), (x+1, y-1), (x+1, y+1)
        ]
        
        # Check if any neighbor is part of the green mask
        if any(0 <= nx < line_mask.shape[0] and 0 <= ny < line_mask.shape[1] and green_mask[nx, ny] > 0 for nx, ny in neighbors):
            output_mask[x, y] = 255  # Keep this pixel

    return output_mask

def binarizing(image_hsv):
    line_mask = cv2.inRange(image_hsv, white_lower, white_upper)
    kernel = np.ones((3, 3), np.uint8)  # Use a larger kernel for better results
    line_mask = cv2.morphologyEx(line_mask, cv2.MORPH_CLOSE, kernel)  # Fill small gaps
    return line_mask

if __name__ == "__main__":
    # Load image and convert to HSV
    image = cv2.imread("/home/altair/Documents/ALTAIR-vision/src/sample_program/samplesIMG/sampleLineDet.jpeg")
    image_hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

    # Create masks
    line_mask = binarizing(image_hsv)  # Binarize to get line mask
    green_mask = create_green_mask(image_hsv)  # Create mask for green areas

    # Extract lines near green areas
    final_line_mask = mask_lines_near_green(line_mask, green_mask)

    # Display results
    cv2.imshow("Original Image", image)
    cv2.imshow("Green Mask", green_mask)
    cv2.imshow("Line Mask", line_mask)
    cv2.imshow("Final Line Mask", final_line_mask)
    
    cv2.waitKey(0)
    cv2.destroyAllWindows()
