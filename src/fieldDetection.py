import numpy as np
import cv2

# Define color thresholds in HSV color space for field and lines

# green field
green_lower = np.array([36,100,100], dtype=np.uint8)
green_upper = np.array([86,255,255], dtype=np.uint8)

# white line
white_lower = np.array([0,0,200], dtype=np.uint8)
white_upper = np.array([180,20,255], dtype=np.uint8)

def removeBackground():
    ''''''''

def binarizing():
    ''''''''