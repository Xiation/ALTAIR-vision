import cv2 as cv
import numpy as np
from typing import Tuple, List, Optional
import math

class LineBasedLocalizer:
    def __init__(self, camera_matrix: np.ndarray, dist_coeffs: np.ndarray):
        self.camera_matrix = camera_matrix
        self.dist_coeffs = dist_coeffs
        self.previous_position: Optional[Tuple[float, float, float]] = None
    
    def estimate_line_equation(self, major_nodes: List[Tuple[int, int, int]]) -> Tuple[float, float, float]:
        if len(major_nodes) < 2:
            raise ValueError("Need at least 2 nodes to estimate line")
            
        points = np.array([[x, y] for x, y, _ in major_nodes])
        vx, vy, x0, y0 = cv.fitLine(points, cv.DIST_L2, 0, 0.01, 0.01)
        
        a = vy[0]
        b = -vx[0]
        c = -a*x0[0] - b*y0[0]
        
        return a, b, c
    
    def get_robot_pose(self, major_nodes: List[Tuple[int, int, int]]) -> Tuple[float, float, float]:
        """
        Simplified version that returns robot pose relative to the detected line
        """
        image_line = self.estimate_line_equation(major_nodes)
        a, b, c = image_line
        
        # Calculate angle of the line relative to horizontal
        theta = math.atan2(b, a)
        
        # Calculate approximate position relative to line
        # Using the center point of all nodes as reference
        points = np.array([[x, y] for x, y, _ in major_nodes])
        center = np.mean(points, axis=0)
        
        # Distance from center to line
        d = abs(a*center[0] + b*center[1] + c) / math.sqrt(a*a + b*b)
        
        # Use center point as x, distance to line as y, and line angle as theta
        x = center[0]
        y = d
        
        # Apply simple position smoothing if we have previous position
        if self.previous_position is not None:
            prev_x, prev_y, prev_theta = self.previous_position
            alpha = 0.7  # Weight for new measurement
            x = alpha * x + (1 - alpha) * prev_x
            y = alpha * y + (1 - alpha) * prev_y
            theta = alpha * theta + (1 - alpha) * prev_theta
        
        self.previous_position = (x, y, theta)
        return x, y, theta

def process_image(image_path):
    low_green = np.array([35, 100, 100])
    up_green = np.array([85, 255, 255])

    img = cv.imread(image_path)
    if img is None:
        raise ValueError("Image not found or invalid image path")

    hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)
    green_mask = cv.inRange(hsv, low_green, up_green)

    kernel = cv.getStructuringElement(cv.MORPH_ELLIPSE, (3, 3))
    mask1 = cv.erode(green_mask, kernel, iterations=1)
    green_mask_cleaned = cv.dilate(mask1, kernel, iterations=6)

    contours, _ = cv.findContours(green_mask_cleaned, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
    largest_contour = max(contours, key=cv.contourArea) if contours else None

    roi_mask = np.zeros(green_mask_cleaned.shape, dtype=np.uint8)
    if largest_contour is not None:
        cv.drawContours(roi_mask, [cv.convexHull(largest_contour)], -1, 255, thickness=-1)
    
    if largest_contour is None:
        return img, green_mask_cleaned

    roi_image = cv.bitwise_and(img, img, mask=roi_mask)
    return roi_image, green_mask_cleaned

def binarizing(roi_image_hsv):
    roi_image_hsv = cv.cvtColor(roi_image_hsv, cv.COLOR_BGR2HSV)
    white_lower = np.array([0, 0, 155], dtype=np.uint8)
    white_upper = np.array([255, 155, 255], dtype=np.uint8)

    line_mask = cv.inRange(roi_image_hsv, white_lower, white_upper)
    kernel = np.ones((2, 2), np.uint8)
    line_mask = cv.morphologyEx(line_mask, cv.MORPH_CLOSE, kernel)
    return line_mask

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

def find_nodes_with_weights(skeleton):
    nodes = []
    rows, cols = skeleton.shape

    for y in range(1, rows - 1):
        for x in range(1, cols - 1):
            if skeleton[y, x] == 255:
                neighbors = skeleton[y-1:y+2, x-1:x+2] > 0
                num_neighbors = np.sum(neighbors) - 1
                weight = num_neighbors
                if weight > 0:
                    nodes.append((x, y, weight))

    return nodes

def digestion_algorithm(nodes, radius):
    nodes = sorted(nodes, key=lambda n: n[2], reverse=True)
    consumed = set()
    major_nodes = []

    for i, (x1, y1, weight1) in enumerate(nodes):
        if i in consumed:
            continue

        current_node = [x1, y1, weight1]
        for j, (x2, y2, weight2) in enumerate(nodes):
            if i == j or j in consumed:
                continue

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
    binarized_image = binarizing(roi_image)
    filtered_image = medianFilter(binarized_image)
    thinned_line = zhangsuen(filtered_image)
    enhanced_line = enchanceThinned(thinned_line)
    nodes = find_nodes_with_weights(enhanced_line)
    major_nodes = digestion_algorithm(nodes, 5)
    return enhanced_line, major_nodes

def display_results_with_pose(original_image, roi_image, mask_image, line_mask, thinned_line, major_nodes, robot_pose):
    """Display all results including robot pose visualization"""
    # Original displays
    cv.imshow('Original Image', original_image)
    cv.imshow('Masked Image', roi_image)
    cv.imshow('Mask', mask_image)
    cv.imshow('Line Mask', line_mask)
    cv.imshow('Thinned Line', thinned_line)

    # Create pose visualization
    pose_viz = original_image.copy()
    x, y, theta = robot_pose
    
    # Draw major nodes
    for node_x, node_y, weight in major_nodes:
        cv.circle(pose_viz, (node_x, node_y), 3, (0, 0, 255), -1)
    
    # Draw robot position and orientation
    scale = 50  # Scale factor for visualization
    robot_pos = (int(x), int(y))
    orientation_end = (
        int(x + scale * math.cos(theta)),
        int(y + scale * math.sin(theta))
    )
    
    cv.circle(pose_viz, robot_pos, 5, (0, 255, 0), -1)  # Robot position
    cv.line(pose_viz, robot_pos, orientation_end, (0, 255, 0), 2)  # Robot orientation
    
    # Add text with pose information
    text_pos = (10, pose_viz.shape[0] - 20)
    cv.putText(pose_viz, f"x:{x:.1f} y:{y:.1f} theta:{math.degrees(theta):.1f}deg",
              text_pos, cv.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 1)
    
    cv.imshow('Robot Pose', pose_viz)

def main():
    # Initialize camera parameters (replace with your calibrated values)
    camera_matrix = np.array([
        [500, 0, 320],
        [0, 500, 240],
        [0, 0, 1]
    ])
    dist_coeffs = np.zeros(5)
    
    # Initialize localizer
    localizer = LineBasedLocalizer(camera_matrix, dist_coeffs)
    
    # Your image path
    image_path = "/home/altair/Documents/ALTAIR-vision/src/sample_program/samplesIMG/sampleLineDet.jpeg"
    
    # Process image
    roi_image, green_mask_cleaned = process_image(image_path)
    original_image = cv.imread(image_path)
    
    # Get line and nodes
    thinned_line, major_nodes = processing(roi_image)
    
    # Get robot pose
    robot_pose = localizer.get_robot_pose(major_nodes)
    
    # Display results
    display_results_with_pose(
        original_image, roi_image, green_mask_cleaned,
        binarizing(roi_image), thinned_line, major_nodes,
        robot_pose
    )
    
    # Print pose information
    print(f"Robot pose - X: {robot_pose[0]:.2f}, Y: {robot_pose[1]:.2f}, "
          f"Theta: {math.degrees(robot_pose[2]):.2f}°")
    
    cv.waitKey(0)
    cv.destroyAllWindows()

if __name__ == "__main__":
    main()