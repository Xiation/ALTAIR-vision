import cv2 as cv
import numpy as np

# Define the lower and upper bounds for the green color in HSV space
low_green = np.array([35, 100, 100])
up_green = np.array([85, 255, 255])

def process_image(image_path, low_bound, up_bound):
    """
    Process an image to extract the region of interest (ROI) based on a color range.

    Parameters:
    - image_path: Path to the image file.
    - low_bound: Lower bound of the color range in HSV space.
    - up_bound: Upper bound of the color range in HSV space.

    Returns:
    - roi_image: The image with the region of interest (ROI) extracted.
    - green_mask_cleaned: The cleaned mask showing the green regions.
    """
    # Load the image
    img = cv.imread(image_path)

    if img is None:
        raise ValueError("Image not found or invalid image path")

    # Convert the image from BGR to HSV color space
    hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)

    # Create a mask for the specified color range (green in this case)
    green_mask = cv.inRange(hsv, low_bound, up_bound)

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

    # Apply the ROI mask to the image to extract the region of interest
    roi_image = cv.bitwise_and(img, img, mask=roi_mask)

    return roi_image, green_mask_cleaned

def display_results(original_image, roi_image, mask_image):
    """Display the original image, the ROI image, and the mask."""
    cv.imshow('Original Image', original_image)
    cv.imshow('Masked Image', roi_image)
    cv.imshow('Mask', mask_image)
    cv.waitKey(0)
    cv.destroyAllWindows()

if __name__ == "__main__":
    image_path = "/home/altair/Documents/ALTAIR-vision/src/sample_program/samplesIMG/sampleLineDet.jpeg"  # Provide the correct image path here
    roi_image, green_mask_cleaned = process_image(image_path, low_green, up_green)
    original_image = cv.imread(image_path)  # Use the image path here to load the original image
    display_results(original_image, roi_image, green_mask_cleaned)



# combine the mask with the zhang suen alg