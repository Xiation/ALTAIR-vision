import cv2 as cv
import numpy as np

def process_image(image_path):
    
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

# Binarizing for line masking
def binarizing(roi_image_hsv):
    # White line
    roi_image_hsv = cv.cvtColor(roi_image_hsv, cv.COLOR_BGR2HSV)
    white_lower = np.array([0, 0, 155], dtype=np.uint8)
    white_upper = np.array([255, 155, 255], dtype=np.uint8)

    line_mask = cv.inRange(roi_image_hsv, white_lower, white_upper)
    kernel = np.ones((2, 2), np.uint8)

    line_mask = cv.morphologyEx(line_mask, cv.MORPH_CLOSE, kernel)  # Fill small gaps
    return line_mask

# Adding median filter before thinning process, filter may be unnecessary depending on necessity
def medianFilter(binarized_roi_image, kernel_size=3):
    
    filter_roi = cv.medianBlur(binarized_roi_image, kernel_size)
    return filter_roi

# The thinning process requires the image with ROI extracted
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
                    if (2 <= sum(neighbors) <= 5 and
                        count_transitions(neighbors) == 1 and
                        neighbors[1] * neighbors[3] * neighbors[5] == 0 and
                        neighbors[3] * neighbors[5] * neighbors[7] == 0):
                        changing_pixels.append((x, y))
        
        # Remove flagged pixels
        for x, y in changing_pixels:
            skeleton[x, y] = 0

        # Reset changing_pixels for the second sub-iteration
        changing_pixels = []

        # Second sub-iteration
        for x in range(1, skeleton.shape[0] - 1):
            for y in range(1, skeleton.shape[1] - 1):
                if skeleton[x, y] == 1:  # Only process white pixels
                    neighbors = get_neighbors(skeleton, x, y)
                    if (2 <= sum(neighbors) <= 5 and
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

# Receives thinned line from zhangsuen
def enchanceThinned(zhangsuenThinned):
    kernel1 = np.ones((2, 2), np.uint8)
    kernel_rect = cv.getStructuringElement(cv.MORPH_RECT, (5, 3))
     
    dilated_thinned_line = cv.dilate(zhangsuenThinned, kernel_rect)

    # Remove noise
    dilated_thinned_line = cv.morphologyEx(dilated_thinned_line, cv.MORPH_OPEN, kernel1)

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

# Detect line using graph implementation
def find_nodes_with_weights(skeleton):
    nodes = []
    rows, cols = skeleton.shape

    for y in range(1, rows - 1):
        for x in range(1, cols - 1):
            if skeleton[y, x] == 255:  # Line pixel
                # Count neighbors in 3x3 window
                neighbors = skeleton[y-1:y+2, x-1:x+2] > 0
                num_neighbors = np.sum(neighbors) - 1  # Exclude center pixel
                
                # Assign weight based on connectivity
                weight = num_neighbors
                if weight > 0:
                    nodes.append((x, y, weight))

    return nodes

def digestion_algorithm(nodes, radius):
    nodes = sorted(nodes, key=lambda n: n[2], reverse=True)  # Sort by weight
    consumed = set()
    major_nodes = []

    for i, (x1, y1, weight1) in enumerate(nodes):
        if i in consumed:
            continue

        current_node = [x1, y1, weight1]
        for j, (x2, y2, weight2) in enumerate(nodes):
            if i == j or j in consumed:
                continue

            # Check distance between nodes
            distance = np.sqrt((x1 - x2)**2 + (y1 - y2)**2)
            if distance <= radius:
                if weight1 >= weight2:
                    current_node[2] += weight2
                    consumed.add(j)
                else:
                    consumed.add(i)
                    break

        if i not in consumed:
            major_nodes.append(tuple(current_node))

    return major_nodes

def processing(roi_image):
    # Apply binarization (convert to binary image)
    binarized_image = binarizing(roi_image)

    # Apply median filter before thinning
    filtered_image = medianFilter(binarized_image)

    # Perform thinning (Zhang-Suen)
    thinned_line = zhangsuen(filtered_image)

    # Enhance line for preserving connectivity
    enhanced_line = enchanceThinned(thinned_line)

    # Detect nodes with weights
    nodes = find_nodes_with_weights(enhanced_line)

    # Perform digestion to simplify nodes
    digestion_radius = 5
    major_nodes = digestion_algorithm(nodes, digestion_radius)

    return enhanced_line, major_nodes



def display_results(original_image, roi_image, mask_image, line_mask, thinned_line, major_nodes):
    """Display the original image, the ROI image, and the mask."""
    cv.imshow('Original Image', original_image)
    cv.imshow('Masked Image', roi_image)
    cv.imshow('Mask', mask_image)
    cv.imshow('Line Mask', line_mask)

    cv.imshow('Thinned Line', thinned_line)

    # Overlay major nodes on the thinned line
    node_overlay = cv.cvtColor(thinned_line, cv.COLOR_GRAY2BGR)
    for x, y, weight in major_nodes:
        cv.circle(node_overlay, (x, y), 3, (0, 0, 255), -1)  # Red dots for nodes
    cv.imshow('Major Nodes', node_overlay)

    cv.waitKey(0)
    cv.destroyAllWindows()

def main():
    image_path = "/home/altair/Documents/ALTAIR-vision/src/sample_program/samplesIMG/sampleLineDet.jpeg"  # Provide the correct image path here
    roi_image, green_mask_cleaned = process_image(image_path)
    original_image = cv.imread(image_path)  


    thinned_line, major_nodes = processing(roi_image)    
    display_results(original_image, roi_image, green_mask_cleaned, binarizing(roi_image), thinned_line, major_nodes)

if __name__ == "__main__":
    main()
