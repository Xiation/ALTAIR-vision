import cv2
import numpy as np

# define color thresholds in HSV color space for field and lines

# green field
green_lower = np.array([36,100,100], dtype=np.uint8)
green_upper = np.array([86,255,255], dtype=np.uint8)

# white line
white_lower = np.array([0,0,210], dtype=np.uint8)
white_upper = np.array([180,30,255], dtype=np.uint8)

def removeBG(image_hsv):
    field_mask = cv2.inRange(image_hsv, green_lower, green_upper)
    field_area = cv2.bitwise_and(image_hsv, image_hsv, field_mask)
    return field_mask

def binarizing(image_hsv):
    line_mask = cv2.inRange(image_hsv, white_lower, white_upper)
    kernel = np.ones((2,2), np.uint8)
    # line_mask = cv2.morphologyEx(line_mask, cv2.MORPH_OPEN, kernel)  # Remove small noise
    line_mask = cv2.morphologyEx(line_mask, cv2.MORPH_CLOSE, kernel) # Fill small gaps
    return line_mask

def zhangSuen(binary_image):
    skeleton = binary_image.copy() // 255
    changing_pixels = True

    while changing_pixels:
        changing_pixels = []

        # First sub-iteration
        for x in range(1, skeleton.shape[0] - 1):
            for y in range(1, skeleton.shape[1] - 1):
                if skeleton[x, y] == 1:  # Only process white pixels
                    neighbors = get_neighbors(skeleton, x, y)
                    if (2 <= sum(neighbors) <= 6 and
                        count_transitions(neighbors) == 1 and
                        neighbors[1] * neighbors[3] * neighbors[5] == 0 and
                        neighbors[3] * neighbors[5] * neighbors[7] == 0):
                        changing_pixels.append((x, y))
        
        # Remove flagged pixels
        for x, y in changing_pixels:
            skeleton[x, y] = 0

        # reset changing_pixels for the second sub-iteration
        # changing_pixels = []

        # Second sub-iteration
        for x in range(1, skeleton.shape[0] - 1):
            for y in range(1, skeleton.shape[1] - 1):
                if skeleton[x, y] == 1:  # Only process white pixels
                    neighbors = get_neighbors(skeleton, x, y)
                    if (2 <= sum(neighbors) <= 6 and
                        count_transitions(neighbors) == 1 and
                        neighbors[1] * neighbors[3] * neighbors[7] == 0 and
                        neighbors[1] * neighbors[5] * neighbors[7] == 0):
                        changing_pixels.append((x, y))
        
        # Remove flagged pixels
        for x, y in changing_pixels:
            skeleton[x, y] = 0

        if not changing_pixels:
            break

    # Convert back to 255 (white) for visualization
    return (skeleton * 255).astype(np.uint8)

def get_neighbors(image, x, y):
    """
    Return the 3x3 neighborhood of a pixel as a list in clockwise order.
    """
    neighbors = [
        image[x-1, y],   # P2
        image[x-1, y+1], # P3
        image[x, y+1],   # P4
        image[x+1, y+1], # P5
        image[x+1, y],   # P6
        image[x+1, y-1], # P7
        image[x, y-1],   # P8
        image[x-1, y-1]  # P9
    ]
    return neighbors

def count_transitions(neighbors):
    """
    Count the number of 0-1 transitions in the neighborhood list.
    """
    transitions = 0
    for i in range(len(neighbors)):
        if neighbors[i] == 0 and neighbors[(i + 1) % len(neighbors)] == 1:
            transitions += 1
    return transitions

if __name__ == "__main__":
    image = cv2.imread("/home/altair/Documents/ALTAIR-vision/src/sample_program/samplesIMG/sampleLineDet.jpeg")
    image_hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)

    # preprocessing
    field_mask = removeBG(image_hsv)
    line_mask = binarizing(image_hsv)

    # combined_mask = cv2.bitwise_and(line_mask, field_mask)
    _, binary = cv2.threshold(line_mask, 127, 255, cv2.THRESH_BINARY)



    skeleton = zhangSuen(binary)
    
    #  Display results
    cv2.imshow("Original Image", image)
    cv2.imshow("Field Mask", field_mask)
    cv2.imshow("Binarized Lines", line_mask)
    # cv2.imshow("combined", combined_mask)
    cv2.imshow("Skeleton", skeleton)
    cv2.waitKey(0)
    cv2.destroyAllWindows()