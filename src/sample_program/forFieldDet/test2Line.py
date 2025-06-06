import cv2 as cv
import numpy as np

def process_image(image_path):
    """
    Process an image to extract the region of interest (ROI) based on a color range.
    Returns:
    - roi_image: The image with the region of interest (ROI) extracted.
    - green_mask_cleaned: The cleaned mask showing the green regions.
    """
    low_green = np.array([35, 100, 100])
    up_green = np.array([85, 255, 255])

    img = cv.imread(image_path)

    if img is None:
        raise ValueError("Image not found or invalid image path")

    hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)

    green_mask = cv.inRange(hsv, low_green, up_green)

    # Apply morphological operations (erosion and dilation)
    kernel = cv.getStructuringElement(cv.MORPH_ELLIPSE, (3, 3))
    mask1 = cv.erode(green_mask, kernel, iterations=1)
    green_mask_cleaned = cv.dilate(mask1, kernel, iterations=6)

    # Find the largest contour in the mask
    contours, _ = cv.findContours(green_mask_cleaned, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
    largest_contour = max(contours, key=cv.contourArea) if contours else None

    # Create a mask for the region of interest (ROI) based on the contour
    roi_mask = np.zeros(green_mask_cleaned.shape, dtype=np.uint8)
    if largest_contour is not None:
        cv.drawContours(roi_mask, [cv.convexHull(largest_contour)], -1, 255, thickness=-1)
    
    if largest_contour is None:
        return img, green_mask_cleaned  # Return original image and mask if no contour is found

    # Apply the ROI mask to the image to extract the region of interest
    roi_image = cv.bitwise_and(img, img, mask=roi_mask)

    return roi_image, green_mask_cleaned



# binarizing for line masking
def binarizing(roi_image_hsv):
    # white line
    roi_image_hsv = cv.cvtColor(roi_image_hsv, cv.COLOR_BGR2HSV)
    white_lower = np.array([0,0,155], dtype=np.uint8)
    white_upper = np.array([255,155,255], dtype=np.uint8)

    line_mask = cv.inRange(roi_image_hsv, white_lower, white_upper)
    kernel = np.ones((2,2), np.uint8)

    # line_mask = cv2.morphologyEx(line_mask, cv2.MORPH_OPEN, kernel)  # Remove small noise

    line_mask = cv.morphologyEx(line_mask, cv.MORPH_CLOSE, kernel) # Fill small gaps
    return line_mask


# adding median filter before thinning process, filter may be unnessary
# depending on neccessity
def medianFilter(binarized_roi_image, kernel_size=3):
    """
    applying median filter for binarized roi image
    """
    filter_roi = cv.medianBlur(binarized_roi_image, kernel_size)
    return filter_roi

# the thinning process require the image with roi extracted
def zhangsuen(binarized_roi_image):
    skeleton = binarized_roi_image.copy() // 255
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
        changing_pixels = []

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

# receives thinned line from zhangsuen
def enchanceThinned(zhangsuenThinned):
    kernel1 = np.ones((2,2), np.uint8)
    kernel2 = np.ones((3,3),np.uint8)
    kernel_rect = cv.getStructuringElement(cv.MORPH_RECT,(5,3))
     
    # dilated_thinned_line = cv.dilate(zhangsuenThinned, kernel1, iterations = 1)
    dilated_thinned_line = cv.dilate(zhangsuenThinned, kernel_rect)

    # remove noise
    dilated_thinned_line = cv.morphologyEx(dilated_thinned_line, cv.MORPH_OPEN, kernel1)

    # closing gaps
    # dilated_thinned_line = cv.morphologyEx(dilated_thinned_line, cv.MORPH_CLOSE, kernel2)
    return dilated_thinned_line



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


def processing(roi_image):
    # Apply binarization (convert to binary image)
    binarized_image = binarizing(roi_image)

    # Apply median filter before thinning
    filtered_image = medianFilter(binarized_image)

    # Perform thinning (Zhang-Suen)
    thinned_line = zhangsuen(filtered_image)

    # enhance line for preserving connectivity
    thinned_line = enchanceThinned(thinned_line)

    return thinned_line

# using hough line transform to detect lines
def LineDetect(roi_image):
    # using standard hough line transform

    line_image = roi_image.copy()

    thinned_line = processing(roi_image)
    lines = cv.HoughLines(thinned_line, 1, np.pi/180, 200)

    if lines is not None:
        for rho, theta in lines[:, 0]:
            a = np.cos(theta)
            b = np.sin(theta)
            x0 = a * rho
            y0 = b * rho

            x1 = int(x0 + 1000 * (-b))
            x2 = int(x0 - 1000 * (-b))

            y1 = int(y0 + 1000 * (a))
            y2 = int(y0 - 1000 * (a))

            cv.line(line_image, (x1, y1), (x2, y2), (0,0,255), 2)

def display_results(original_image, roi_image, mask_image, line_mask, thinned_line):
    """Display the original image, the ROI image, and the mask."""
    cv.imshow('Original Image', original_image)
    cv.imshow('Masked Image', roi_image)
    cv.imshow('Mask', mask_image)
    cv.imshow('line mask', line_mask)

    # zhangsuen
    cv.imshow('thinned line', thinned_line )

    cv.waitKey(0)
    cv.destroyAllWindows()

def main():
    image_path = "/home/altair/Documents/ALTAIR-vision/src/sample_program/samplesIMG/sampleLineDet.jpeg"  # Provide the correct image path here
    roi_image, green_mask_cleaned = process_image(image_path)
    original_image = cv.imread(image_path)  # Use the image path here to load the original image
   # Process with median filter before thinning
    thinned_line = processing(roi_image)
    
    display_results(original_image, roi_image, green_mask_cleaned, binarizing(roi_image), thinned_line)


if __name__ == "__main__":
    main()
