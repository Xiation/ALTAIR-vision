import cv2 as cv
import numpy as np

# Define the lower and upper bounds for the green color in HSV space
low_green = np.array([35, 100, 100])
up_green = np.array([85, 255, 255])

def process_and_thin_image(image_path):
    """
    Process an image to extract the region of interest (ROI), 
    apply binarization, median filtering, and Zhang-Suen thinning.

    Parameters:
    - image_path: Path to the image file.

    Returns:
    - original_image: The original image.
    - roi_image: The extracted region of interest (ROI).
    - green_mask_cleaned: The cleaned mask showing the green regions.
    - thinned_line: The enhanced thinned line after processing.
    """
    
    # Step 1: Read and process the image to extract the ROI
    img = cv.imread(image_path)
    if img is None:
        raise ValueError("Image not found or invalid image path")

    hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)
    green_mask = cv.inRange(hsv, low_green, up_green)

    # Morphological operations
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

    roi_image = cv.bitwise_and(img, img, mask=roi_mask)

    # Step 2: Binarize and filter the ROI image
    roi_image_hsv = cv.cvtColor(roi_image, cv.COLOR_BGR2HSV)
    
    white_lower = np.array([0, 0, 155], dtype=np.uint8)
    white_upper = np.array([255, 155, 255], dtype=np.uint8)
    
    line_mask = cv.inRange(roi_image_hsv, white_lower, white_upper)
    
    kernel_open = np.ones((2, 2), np.uint8)
    line_mask = cv.morphologyEx(line_mask, cv.MORPH_CLOSE, kernel_open)  # Fill small gaps
    
    # Apply median filter before thinning
    filtered_image = cv.medianBlur(line_mask, 3)

    # Step 3: Perform Zhang-Suen thinning
    thinned_line = zhangsuen(filtered_image)

    # Step 4: Enhance thinned lines
    thinned_line = enhance_thinned(thinned_line)

    return img, roi_image, green_mask_cleaned, thinned_line

def zhangsuen(binarized_roi_image):
    skeleton = binarized_roi_image.copy() // 255
    changing_pixels = True

    while changing_pixels:
        changing_pixels = []

        # First sub-iteration
        for x in range(1, skeleton.shape[0] - 1):
            for y in range(1, skeleton.shape[1] - 1):
                if skeleton[x, y] == 1:  
                    neighbors = get_neighbors(skeleton, x, y)
                    if (2 <= sum(neighbors) <= 6 and
                        count_transitions(neighbors) == 1 and
                        neighbors[1] * neighbors[3] * neighbors[5] == 0 and
                        neighbors[3] * neighbors[5] * neighbors[7] == 0):
                        changing_pixels.append((x, y))
        
        for x, y in changing_pixels:
            skeleton[x, y] = 0

        changing_pixels = []

        # Second sub-iteration
        for x in range(1, skeleton.shape[0] - 1):
            for y in range(1, skeleton.shape[1] - 1):
                if skeleton[x, y] == 1:  
                    neighbors = get_neighbors(skeleton, x, y)
                    if (2 <= sum(neighbors) <= 6 and
                        count_transitions(neighbors) == 1 and
                        neighbors[1] * neighbors[3] * neighbors[7] == 0 and
                        neighbors[1] * neighbors[5] * neighbors[7] == 0):
                        changing_pixels.append((x, y))
        
        for x, y in changing_pixels:
            skeleton[x, y] = 0

        if not changing_pixels:
            break

    return (skeleton * 255).astype(np.uint8)

def enhance_thinned(zhangsuen_thinned):
    kernel_rect = cv.getStructuringElement(cv.MORPH_RECT,(5,3))
     
    dilated_thinned_line = cv.dilate(zhangsuen_thinned / 255.0 , kernel_rect)

    kernel_open = np.ones((2 ,2), np.uint8)
    
    dilated_thinned_line = cv.morphologyEx(dilated_thinned_line.astype(np.uint8), 
                                            cv.MORPH_OPEN ,kernel_open)

    return dilated_thinned_line

def get_neighbors(image,x,y):
    neighbors=[
        image[x-1,y],   # P2
        image[x-1,y+1], # P3
        image[x,y+1],   # P4
        image[x+1,y+1], # P5
        image[x+1,y],   # P6
        image[x+1,y-1], # P7
        image[x,y-1],   # P8
        image[x-1,y-1]  # P9
   ]
    return neighbors

def count_transitions(neighbors):
   transitions=0
   for i in range(len(neighbors)):
       if neighbors[i]==0 and neighbors[(i+1)%len(neighbors)]==1:
           transitions+=1 
   return transitions

def display_results(original_image ,roi_image ,mask_image ,thinned_line):
   """Display the original image ,the ROI image ,and the mask ."""
   cv.imshow('Original Image', original_image)
   cv.imshow('Masked Image', roi_image)
   cv.imshow('Mask', mask_image)
   cv.imshow('Thinned Line', thinned_line)
   
   cv.waitKey(0)
   cv.destroyAllWindows()

def main():
   image_path="/home/altair/Documents/ALTAIR-vision/src/sample_program/samplesIMG/sampleLineDet.jpeg"  
   
   original_image ,roi_image ,green_mask_cleaned ,thinned_line=process_and_thin_image(image_path)

   display_results(original_image ,roi_image ,green_mask_cleaned ,thinned_line)

if __name__=="__main__":
   main()
