import cv2 as cv
import numpy as np


def process_image(image_path):
    low_green = np.array([35, 100, 100])
    upper_green = np.array([85,255,255])

    img = cv.imread(image_path)

    if img is None:
        raise ValueError('image is not found or invalid path')
    
    hsv = cv.cvtColor(img, cv.COLOR_BGR2HSV)

    v_channel = hsv[:, :, 2]
    adaptive_thresh = cv.adaptiveThreshold(v_channel, 255, cv.ADAPTIVE_THRESH_GAUSSIAN_C, cv.THRESH_BINARY, 11, 2)

    green_mask = cv.inRange(hsv, low_green, upper_green)

    # combine green mask with adaptive threshold
    green_mask_thresh = cv.bitwise_and(green_mask, adaptive_thresh)

    # closing to remove holes
    kernel = cv.getStructuringElement(cv.MORPH_ELLIPSE, (3, 3))
    green_mask_cleaned = cv.morphologyEx(green_mask_thresh, cv.MORPH_CLOSE, kernel, iterations=3)
    
    contours, _ = cv.findContours(green_mask_cleaned, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
    largest_contour = max(contours, key=cv.contourArea) if contours else None

    roi_mask = np.zeros(green_mask_cleaned.shape, dtype=np.uint8)
    if largest_contour is not None:
        cv.drawContours(roi_mask, [cv.convexHull(largest_contour)], -1, 255, thickness=-1)
    
    if largest_contour is None:
        return img, green_mask_cleaned  # Return original image and mask if no contour is found
    
    roi_image = cv.bitwise_and(img, img, mask=roi_mask)

    return roi_image, green_mask_cleaned


def main():
    image_path = "/home/altair/Documents/ALTAIR-vision/src/sample_program/samplesIMG/sampleLineDet.jpeg"
    try:
        roi_image, green_mask_cleaned = process_image(image_path)
         
        # Load the original image again for display purposes
        original_image = cv.imread(image_path)
        if original_image is None:
            raise ValueError("Could not load the original image for display.")
        cv.imshow("roi image", roi_image, )
        cv.imshow( "mask", green_mask_cleaned)
        cv.imshow("original image", original_image )

        cv.waitKey(0)
        cv.destroyAllWindows()
       
    except ValueError as e:
        print(f"Error: {e}")
    except Exception as e:
        print(f"An unexpected error occurred: {e}")

if __name__ == "__main__":
    main()