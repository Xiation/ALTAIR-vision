# Ball detection information (temporarily)
std_msgs/Header header
float64 distance      # Distance to ball in meters
int32 x_pixel         # X coordinate in image (pixels)
int32 y_pixel         # Y coordinate in image (pixels)
float64 radius_pixel  # Radius in pixels
float64 confidence    # Detection confidence (0-1)