import cv2 as cv
import numpy as np


def process_image(frame_path):
    low_green = np.array([35, 100, 100])
    upper_green = np.array([85,255,255])

    frame = cv.imread(frame_path)

    if frame is None:
        raise ValueError('image is not found or invalid path')
    
    hsv = cv.cvtColor(frame, cv.COLOR_BGR2HSV)

    green_mask = cv.inRange(hsv, low_green, upper_green)
    kernel = cv.getStructuringElement(cv.MORPH_ELLIPSE, (3, 3))

    green_mask_cleaned = cv.morphologyEx(green_mask, cv.MORPH_CLOSE, kernel, iterations=3)
    contours, _ = cv.findContours(green_mask_cleaned, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
    largest_contour = max(contours, key=cv.contourArea) if contours else None

    roi_mask = np.zeros(green_mask_cleaned.shape, dtype=np.uint8)
    if largest_contour is not None:
        cv.drawContours(roi_mask, [cv.convexHull(largest_contour)], -1, 255, thickness=-1)
    
    if largest_contour is None:
        return frame, green_mask_cleaned  # Return original image and mask if no contour is found
    
    roi_image = cv.bitwise_and(frame, frame, mask=roi_mask)

    return roi_image, green_mask_cleaned

def binarizing(roi_image_hsv):
    # White line
    roi_image_hsv = cv.cvtColor(roi_image_hsv, cv.COLOR_BGR2HSV)
    white_lower = np.array([0, 0, 155], dtype=np.uint8)
    white_upper = np.array([255, 155, 255], dtype=np.uint8)

    line_mask = cv.inRange(roi_image_hsv, white_lower, white_upper)
    kernel = np.ones((2, 2), np.uint8)

    line_mask = cv.morphologyEx(line_mask, cv.MORPH_CLOSE, kernel)  # Fill small gaps
    return line_mask

def medianFilter(binarized_roi_image, kernel_size=3):
    
    filter_roi = cv.medianBlur(binarized_roi_image, kernel_size)
    return filter_roi

def thinning(binarized_roi_image):
    kernel = np.ones((2,2), np.uint8)
    kernel_rect = cv.getStructuringElement(cv.MORPH_RECT, (5, 3))

    thinned = cv.ximgproc.thinning(binarized_roi_image, thinningType=cv.ximgproc.THINNING_ZHANGSUEN)
    # thinned = cv.erode(thinned, kernel_rect)
    return thinned

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



# adding graph building function

def build_lines_from_nodes(major_nodes, radius):
    lines = []
    used = set()

    for i, (x1, y1, _) in enumerate(major_nodes):
        if i in used:
            continue

        line = [(x1, y1)]  # Start a new line
        used.add(i)

        # Find connected nodes
        for j, (x2, y2, _) in enumerate(major_nodes):
            if j not in used:
                distance = np.sqrt((x1 - x2)**2 + (y1 - y2)**2)
                if distance <= radius:
                    angle = np.arctan2(y2 - y1, x2 - x1)
                    if len(line) > 1:  # Check alignment with previous point
                        prev_angle = np.arctan2(line[-1][1] - line[-2][1], line[-1][0] - line[-2][0])
                        if abs(angle - prev_angle) > np.pi / 8:  # Not aligned
                            continue

                    line.append((x2, y2))
                    used.add(j)

        lines.append(line)

    return lines

# build lines from major node continuosly
def build_lines_from_nodes_continuosly(major_nodes, radius):
    lines = []

    for i, (x1, y1, _) in enumerate(major_nodes):
        line = [(x1, y1)]  # Start a new line with the current node

        for j, (x2, y2, _) in enumerate(major_nodes):
            if i != j : # Ensure not to connect the node to itself
                distance = np.sqrt((x1 - x2)**2 + (y1 - y2)**2)
                if distance <= radius:
                    line.append((x2, y2))  # Add the connected node to the line
        
        lines.append(line) # Append the formed line
    
    return lines


def detect_intersections(lines):
    from collections import Counter

    # Flatten all line nodes into a single list
    node_counts = Counter(node for line in lines for node in line)

    intersections = {'L': [], 'T': [], 'X': []}

    for node, count in node_counts.items():
        if count == 2:
            intersections['L'].append(node)
        elif count == 3:
            intersections['T'].append(node)
        elif count >= 4:
            intersections['X'].append(node)

    return intersections

def processing(roi_image):
    roi_image_copy = roi_image.copy()
    binarized_image = binarizing(roi_image_copy)
    filtered_image = medianFilter(binarized_image)
    thinned_line = thinning(filtered_image)
    thinned_line = enchanceThinned(thinned_line)
    nodes = find_nodes_with_weights(thinned_line)

    # perform digestion
    major_nodes = digestion_algorithm(nodes, radius=5)

    lines = build_lines_from_nodes_continuosly(major_nodes, radius=10)

    # detect intersections
    intersections = detect_intersections(lines)

    return thinned_line, major_nodes, lines, intersections


# drawing intersection on original image
def draw_lines_intersection(ori_image, lines, intersections):
    # Draw lines
    for line in lines:
        for i in range(len(line) - 1):
            x1, y1 = line[i]
            x2, y2 = line[i + 1]
            cv.line(ori_image, (x1, y1), (x2, y2), (255, 0, 0), 2)  # Blue lines
    #  Draw intersections
    colors = {'L': (0, 255, 0), 'T': (0, 0, 255), 'X': (255, 255, 0)}  # Green, Red, Yellow
    for category, nodes in intersections.items():
        for x, y in nodes:
            cv.circle(ori_image, (x, y), 5, colors[category], -1)  # Filled circles   

def display_result(original_image, lines, thinned_line,intersections, major_nodes):
    result_image =original_image.copy()

    # draw lines and intersections
    draw_lines_intersection(result_image, lines, intersections)

    cv.imshow("thinned line", thinned_line)
    cv.imshow('Result Image with lines and intersections', result_image)

    node_overlay = cv.cvtColor(thinned_line, cv.COLOR_GRAY2BGR)
    for x, y, weight in major_nodes:
        cv.circle(node_overlay, (x, y), 3, (0, 0, 255), -1)  # Red dots for nodes
    cv.imshow('Major Nodes', node_overlay)
    cv.waitKey(0)
    cv.destroyAllWindows()

def main():
    image_path = "/home/altair/Documents/ALTAIR-vision/src/sample_program/samplesIMG/sampleLineDet.jpeg"
    try:
        roi_image, green_mask_cleaned = process_image(image_path)
        thinned_line, major_nodes, lines, intersections = processing(roi_image)
        
        # Load the original image again for display purposes
        original_image = cv.imread(image_path)
        if original_image is None:
            raise ValueError("Could not load the original image for display.")

        display_result(original_image, lines, thinned_line, intersections, major_nodes)

    except ValueError as e:
        print(f"Error: {e}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    main()
