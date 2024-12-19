import cv2 as cv
import numpy as np

class ImageProcessor:
    def __init__(self, image_path):
        self.image_path = image_path
        self.original_image = cv.imread(image_path)
        if self.original_image is None:
            raise ValueError("Image not found or invalid image path")
        self.hsv_image = cv.cvtColor(self.original_image, cv.COLOR_BGR2HSV)

    def extract_roi(self, low_bound, up_bound):
        green_mask = cv.inRange(self.hsv_image, low_bound, up_bound)
        kernel = cv.getStructuringElement(cv.MORPH_ELLIPSE, (3, 3))
        cleaned_mask = cv.dilate(cv.erode(green_mask, kernel, iterations=1), kernel, iterations=6)

        # Find the largest contour
        contours, _ = cv.findContours(cleaned_mask, cv.RETR_EXTERNAL, cv.CHAIN_APPROX_SIMPLE)
        largest_contour = max(contours, key=cv.contourArea) if contours else None

        roi_mask = np.zeros(cleaned_mask.shape, dtype=np.uint8)
        if largest_contour is not None:
            cv.drawContours(roi_mask, [cv.convexHull(largest_contour)], -1, 255, thickness=-1)

        roi_image = cv.bitwise_and(self.original_image, self.original_image, mask=roi_mask)
        return roi_image, cleaned_mask

    @staticmethod
    def binarize(roi_image_hsv):
        white_lower = np.array([0, 0, 155], dtype=np.uint8)
        white_upper = np.array([255, 155, 255], dtype=np.uint8)
        line_mask = cv.inRange(roi_image_hsv, white_lower, white_upper)
        kernel = np.ones((2, 2), np.uint8)
        return cv.morphologyEx(line_mask, cv.MORPH_CLOSE, kernel)

    @staticmethod
    def apply_median_filter(image, kernel_size=3):
        return cv.medianBlur(image, kernel_size)

    @staticmethod
    def zhang_suen_thinning(binarized_image):
        def get_neighbors(image, x, y):
            neighbors = [
                image[x-1, y], image[x-1, y+1], image[x, y+1], image[x+1, y+1],
                image[x+1, y], image[x+1, y-1], image[x, y-1], image[x-1, y-1]
            ]
            return neighbors

        def count_transitions(neighbors):
            return sum((neighbors[i] == 0 and neighbors[(i + 1) % len(neighbors)] == 1) for i in range(len(neighbors)))

        skeleton = binarized_image.copy() // 255
        changing = True

        while changing:
            changing_pixels = []
            for sub_iter in [((1, 3, 5, 7), (3, 5, 7), (1, 5, 7)),
                             ((1, 3, 5, 7), (1, 3, 7), (1, 3, 5))]:
                for x in range(1, skeleton.shape[0] - 1):
                    for y in range(1, skeleton.shape[1] - 1):
                        if skeleton[x, y] == 1:
                            neighbors = get_neighbors(skeleton, x, y)
                            if (2 <= sum(neighbors) <= 6 and
                                    count_transitions(neighbors) == 1 and
                                    all(neighbors[i] * neighbors[j] * neighbors[k] == 0 for i, j, k in zip(*sub_iter))):
                                changing_pixels.append((x, y))
                for x, y in changing_pixels:
                    skeleton[x, y] = 0
            changing = bool(changing_pixels)

        return (skeleton * 255).astype(np.uint8)

    @staticmethod
    def enhance_thinned(thinned_image):
        kernel_rect = cv.getStructuringElement(cv.MORPH_RECT, (5, 3))
        enhanced_image = cv.dilate(thinned_image, kernel_rect)
        kernel = np.ones((2, 2), np.uint8)
        return cv.morphologyEx(enhanced_image, cv.MORPH_OPEN, kernel)

    def process_image(self, low_bound, up_bound):
        roi_image, green_mask_cleaned = self.extract_roi(low_bound, up_bound)
        binarized_image = self.binarize(roi_image)
        filtered_image = self.apply_median_filter(binarized_image)
        thinned_image = self.zhang_suen_thinning(filtered_image)
        enhanced_image = self.enhance_thinned(thinned_image)
        return roi_image, green_mask_cleaned, binarized_image, enhanced_image

    def display_results(self, roi_image, mask_image, binarized_image, thinned_image):
        cv.imshow('Original Image', self.original_image)
        cv.imshow('Masked Image', roi_image)
        cv.imshow('Mask', mask_image)
        cv.imshow('Binarized Image', binarized_image)
        cv.imshow('Thinned Image', thinned_image)
        cv.waitKey(0)
        cv.destroyAllWindows()


def main():
    image_path = "/home/altair/Documents/ALTAIR-vision/src/sample_program/samplesIMG/sampleLineDet.jpeg"
    low_green = np.array([35, 100, 100])
    up_green = np.array([85, 255, 255])

    processor = ImageProcessor(image_path)
    roi_image, green_mask_cleaned, binarized_image, thinned_image = processor.process_image(low_green, up_green)
    processor.display_results(roi_image, green_mask_cleaned, binarized_image, thinned_image)


if __name__ == "__main__":
    main()
