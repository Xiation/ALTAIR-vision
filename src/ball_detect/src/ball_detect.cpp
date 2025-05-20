#include "ball_detect/ball_detect.hpp"

// constructor
BallDetector::BallDetector():Node("ball_detector")
{  
  // parameter declaration
  this->declare_parameter("focal_length", 710.1);
  this->declare_parameter("actual_diameter", 0.13);
  this->declare_parameter("moving_average_window", 10);
  this->declare_parameter("orange_lower_bound", std::vector<int>{1, 80, 20});
  this->declare_parameter("orange_upper_bound", std::vector<int>{25,255,255});
  this->declare_parameter("green_lower_bound", std::vector<int>{30,30,45});
  this->declare_parameter("green_upper_bound", std::vector<int>{85,255,255});

  // get params
  auto orange_lower_bound = this->get_parameter("orange_lower_bound").as_integer_array();
  auto orange_upper_bound = this->get_parameter("orange_upper_bound").as_integer_array();

  auto green_lower_bound = this->get_parameter("green_lower_bound").as_integer_array();
  auto green_upper_bound = this->get_parameter("green_upper_bound").as_integer_array();

  focal_length_ = this->get_parameter("focal_length").as_double();
  actual_diameter_ = this->get_parameter("actual_diameter").as_double();
  moving_average_window_ = this->get_parameter("moving_average_window").as_int();

  lower_orange_ = cv::Scalar (orange_lower_bound[0], orange_lower_bound[1], orange_lower_bound[2]);
  upper_orange_ = cv::Scalar (orange_upper_bound[0], orange_upper_bound[1], orange_upper_bound[2]);

  lower_green_ = cv::Scalar(green_lower_bound[0], green_lower_bound[1], green_lower_bound[2]);
  upper_green_ = cv::Scalar(green_upper_bound[0], green_upper_bound[1], green_upper_bound[2]);


  // intialize camera subscriber
  image_sub_ = image_transport::create_camera_subscription(
    this, "image_raw", [this](const sensor_msgs::msg::Image::ConstSharedPtr& img, 
      const sensor_msgs::msg::CameraInfo::ConstSharedPtr& cinfo) {image_callback(img, cinfo);}, "raw", rmw_qos_profile_sensor_data);

      // in case need camera info, add info beside img
      // add this const sensor_msgs::msg::CameraInfo::ConstSharedPtr& info for camera info
      // put camera info beside const sensor_msgs::msg::Image::ConstSharedPtr& img
      // TODO: add subcribing to camera info

  // initialize publisher
  ball_distance_pub_ = create_publisher<std_msgs::msg::Float64MultiArray>("ball_distances", 10);
  ball_image_pub_ = create_publisher<sensor_msgs::msg::Image>("ball_image", 10);
  ball_info_pub_ = create_publisher<ball_detect::msg::BallInfo>("ball_info", 10);
  RCLCPP_INFO(this->get_logger(), "Ball Detector Node Initialized");
    // RCLCPP_INFO(this->get_logger(), "Focal Length: %.2f, Actual Diameter: %.2f, Moving Average Window: %d", 
    //     focal_length_, actual_diameter_, moving_average_window_);
    // Add a periodic status message every 5 seconds
    status_timer_ = this->create_wall_timer(
        std::chrono::seconds(1),
        [this]() {
            RCLCPP_INFO(this->get_logger(), "Ball Detector Node is running...");
        }
    );

}

cv::Mat BallDetector::ball(const cv::Mat &frame) {
  // Convert to HSV color space
  cv::Mat hsv;
  cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);

  // Threshold the HSV image to get only orange colors
  cv::Mat mask_ball;
  cv::inRange(hsv, lower_orange_, upper_orange_, mask_ball);

  // Create a kernel of ones for morphological operations
  cv::Mat kernel = cv::Mat::ones(15, 15, CV_8U);
  cv::morphologyEx(mask_ball, mask_ball, cv::MORPH_CLOSE, kernel);

  return mask_ball;
}

std::pair<cv::Mat, cv::Mat> BallDetector::field(const cv::Mat &frame){
  cv::Mat hsv;
  cv::cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
  
  // Create an elliptical structuring element (kernel) for morphological operations
  cv::Mat kernel = cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(3, 3));
  
  // Threshold the HSV image to get only green colors
  cv::Mat green_mask;
  cv::inRange(hsv, lower_green_, upper_green_, green_mask);
  
  // Perform erosion followed by dilation
  cv::Mat green_mask1, green_mask2;
  cv::erode(green_mask, green_mask1, kernel, cv::Point(-1,-1), 1);
  cv::dilate(green_mask1, green_mask2, kernel, cv::Point(-1,-1), 6);

  // Find contours in the mask
  std::vector<std::vector<cv::Point>> contours;
  std::vector<cv::Vec4i> hierarchy;
  cv::findContours(green_mask2, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
  
  if (contours.empty()) {
      // If no contours found, return the original frame and an empty mask of the same size as green_mask2
      return std::make_pair(frame, cv::Mat::zeros(green_mask2.size(), green_mask2.type()));
  }
  
  // Find the largest contour based on area
  double max_area = 0;
  int max_index = -1;
  for (size_t i = 0; i < contours.size(); i++) {
      double area = cv::contourArea(contours[i]);
      if (area > max_area) {
          max_area = area;
          max_index = static_cast<int>(i);
      }
  }
  
  std::vector<cv::Point> largest_contour = contours[max_index];
  
  // Compute the convex hull of the largest contour
  std::vector<cv::Point> hull;
  cv::convexHull(largest_contour, hull);

  // Create a mask of zeros and draw the convex hull on it
  cv::Mat mask = cv::Mat::zeros(green_mask2.size(), green_mask2.type());
  std::vector<std::vector<cv::Point>> hulls;
  hulls.push_back(hull);
  cv::drawContours(mask, hulls, -1, cv::Scalar(255), cv::FILLED);
  
  // Create ROI by masking the original frame
  cv::Mat roi_frame;
  cv::bitwise_and(frame, frame, roi_frame, mask);
  
  return std::make_pair(roi_frame, mask);
}

std::pair<int, int>BallDetector::find_first_last_orange(const cv::Mat &line_data, int line_start) {
  int first_orange = -1;
  int last_orange = -1;
  
  // Loop from beginning of the line_data row
  for (int idx = 0; idx < line_data.cols; idx++) {
      if (line_data.at<uchar>(0, idx) == 255) {
          first_orange = line_start + idx;
          break;
      }
  }
  
  // Loop from end of the line_data row backward
  for (int idx = line_data.cols - 1; idx >= 0; idx--) {
      if (line_data.at<uchar>(0, idx) == 255) {
          last_orange = line_start + idx;
          break;
      }
  }
  
  return std::make_pair(first_orange, last_orange);
}

std::pair<int, int>BallDetector::find_top_bottom_orange(const cv::Mat &column_data, int col_start) {
  int top_orange = -1;
  int bot_orange = -1;
  
  // Loop from top of the column_data
  for (int idy = 0; idy < column_data.rows; idy++) {
      if (column_data.at<uchar>(idy, 0) == 255) {
          top_orange = col_start + idy;
          break;
      }
  }
  
  // Loop from bottom of the column_data upward
  for (int idy = column_data.rows - 1; idy >= 0; idy--) {
      if (column_data.at<uchar>(idy, 0) == 255) {
          bot_orange = col_start + idy;
          break;
      }
  }
  
  return std::make_pair(top_orange, bot_orange);
}

// function for moving average
std::vector<double> BallDetector::movingAverage(const std::vector<double>& data, int windowSize) {
  std::vector<double> smoothedData;
  if (data.empty() || windowSize <= 0) {
      return smoothedData; // return empty for invalid input
  }
  for (size_t i = 0; i < data.size(); ++i) {
      int start = std::max(0, static_cast<int>(i) - windowSize + 1); // ensure start isn't negative

      // extract window of data
      std::vector<double> window;
      for (size_t j = start; j <= i; ++j){
          window.push_back(data[j]);
      }
      // calculate the average of the window
      double sum = std::accumulate(window.begin(), window.end(), 0.0);
      smoothedData.push_back(sum / window.size());
  }
  return smoothedData;
}

cv::Mat BallDetector::detect(const cv::Mat &mask_ball, const cv::Mat &mask_field, cv::Mat frame, std::vector<double>& distanceHistory ) {
  cv::Mat blurred_ball_mask;
  cv::GaussianBlur(mask_ball, blurred_ball_mask, cv::Size(9, 9), 2);

  // Detect circles using HoughCircles
  std::vector<cv::Vec3f> circles;
  cv::HoughCircles(blurred_ball_mask, circles, cv::HOUGH_GRADIENT, 1.2, 50, 50, 30, 1, 1000);

  if (!circles.empty()) {
    RCLCPP_INFO(this->get_logger(), "Found %zu potential circles", circles.size());
  
    // Convert circle parameters to integer values (the rounding is achieved by casting after rounding)
      for (size_t i = 0; i < circles.size(); i++) {
          int x = cvRound(circles[i][0]);
          int y = cvRound(circles[i][1]);
          int r = cvRound(circles[i][2]);
          int stroke = static_cast<int>(1.1 * r);
          
          // Horizontal line processing
          int line_y = y;
          int line_x_start = std::max(0, x - stroke);
          int line_x_end = std::min(mask_ball.cols - 1, x + stroke);
          // Get a horizontal slice (row) from mask_ball with proper range
          cv::Rect hRect(line_x_start, line_y, line_x_end - line_x_start, 1);
          if (hRect.width <= 0) {
              continue;
          }
          cv::Mat orange_hline = mask_ball(hRect).clone();
          // Reshape to 1 row for processingdouble
          orange_hline = orange_hline.reshape(0, 1);
          
          std::pair<int, int> first_last = find_first_last_orange(orange_hline, line_x_start);
          int first_orange = first_last.first;
          int last_orange = first_last.second;
          
          if (first_orange == -1 || last_orange == -1) {
              continue;
          }
          
          int total_x_pixel = last_orange - first_orange;
          int r_new = total_x_pixel / 2;
          int x_new = first_orange + r_new;
          
          // Vertical line processing
          int line_x = x_new;
          int line_y_start = y - stroke;
          int line_y_end = y + stroke;

          // Clamp vertical boundaries
          line_y_start = std::max(0, line_y_start);
          line_y_end = std::min(mask_ball.rows - 1, line_y_end);
          if (line_y_end - line_y_start <= 0) {
              continue;
          }
          cv::Rect vRect(line_x, line_y_start, 1, line_y_end - line_y_start);
          cv::Mat orange_vline = mask_ball(vRect).clone();

          // Reshape to single column
          orange_vline = orange_vline.reshape(0, orange_vline.rows);
          
          std::pair<int, int> top_bot = find_top_bottom_orange(orange_vline, line_y_start);
          int top_orange = top_bot.first;
          int bot_orange = top_bot.second;
          
          if (top_orange == -1 || bot_orange == -1) {
              continue;
          }
          
          int total_y_pixel = abs(top_orange - bot_orange);
          int y_new = bot_orange - (total_y_pixel / 2);
          
          if (y_new != y) {
              line_y = y_new;
              cv::Rect hRect2(line_x_start, line_y, line_x_end - line_x_start, 1);
              if (hRect2.width <= 0) {
                  continue;
              }
              cv::Mat orange_hline2 = mask_ball(hRect2).clone();
              orange_hline2 = orange_hline2.reshape(0, 1);
              std::pair<int, int> first_last2 = find_first_last_orange(orange_hline2, line_x_start);
              first_orange = first_last2.first;
              last_orange = first_last2.second;
              
              if (first_orange == -1 || last_orange == -1) {
                  continue;
              }
              
              total_x_pixel = last_orange - first_orange;
              r_new = total_x_pixel / 2;
              x_new = first_orange + r_new;
          }
          
          int R = static_cast<int>(r_new * 1.5);  // jarak deteksi
          
          int x1 = std::max(x_new - R, 0);
          int y1 = std::max(y_new - R, 0);
          int x2 = std::min(x_new + R, frame.cols);
          int y2 = std::min(y_new + R, frame.rows);
          // cv::rectangle(frame, Point(x1, y1), Point(x2, y2), Scalar(0, 255, 0), 2);

          // Compute the ratio of green in the surrounding field area
          cv::Rect surroundingRect(x1, y1, x2 - x1, y2 - y1);
          cv::Mat surrounding_field = mask_field(surroundingRect);
          double field_pixels = cv::countNonZero(surrounding_field);
          double field_ratio = field_pixels / (surrounding_field.size().area());

          // Compute the ratio of orange in the surrounding ball area
          cv::Mat surrounding_ball = mask_ball(surroundingRect);
          double ball_pixels = cv::countNonZero(surrounding_ball);
          double ball_ratio = ball_pixels / (surrounding_ball.size().area());

          if ((field_ratio > 0.16) && (ball_ratio < 0.47)) {
              cv::line(frame, cv::Point(x_new, y_new + r_new), cv::Point(x_new, y_new - r_new), cv::Scalar(0, 255, 0), 2);
              cv::line(frame, cv::Point(x_new - r_new, y_new), cv::Point(x_new + r_new, y_new), cv::Scalar(0, 255, 0), 2);
              cv::circle(frame, cv::Point(x_new, y_new), r_new, cv::Scalar(0, 255, 0), 2);
          } else {
            RCLCPP_WARN(this->get_logger(), "Circle failed ratio test: field_ratio=%.2f, ball_ratio=%.2f", 
                field_ratio, ball_ratio);
            continue;
          }

        int detected_diameter=total_x_pixel; 
        double distance = 0;

        if(detected_diameter==0){
            distance=0 ;
        } else {
            distance=(actual_diameter_ * focal_length_) / detected_diameter ;
            RCLCPP_INFO(this->get_logger(), "Ball detected! Position: (%d, %d), Radius: %d, Distance: %.2f m", 
                  x_new, y_new, r_new, distance);
        }

        distanceHistory.push_back(distance);

        ball_detect::msg::BallInfo ball_info_msg;
        ball_info_msg.header.stamp = this->now();
        ball_info_msg.header.frame_id = "camera_frame";

        ball_info_msg.x_pixel = x_new;
        ball_info_msg.y_pixel = y_new;
        ball_info_msg.radius_pixel = r_new;
        ball_info_msg.distance = distance;

        // Distance prediction
        // Apply moving average if we have enough data points
        if(distanceHistory.size() >= static_cast<size_t> (moving_average_window_)) { 
            std::vector<double> smoothedDistances= movingAverage(distanceHistory,moving_average_window_); 

            // The latest smoothed distance is at the end of the vector
            // double smoothedDistance = smoothedDistances.back(); 

            // Trend Analysis (Linear Extrapolation)
            double predictedDistance=0; 
            if(smoothedDistances.size() >= 2){ 
                double currentSmoothed=smoothedDistances.back(); 
                double previousSmoothed=smoothedDistances[smoothedDistances.size()-2]; 
                double trend=currentSmoothed-previousSmoothed; 
                predictedDistance = currentSmoothed+trend; 
            }
            
            // set the ball distance
            ball_info_msg.distance = predictedDistance;
            ball_info_msg.confidence = 1.0 - ball_ratio; // higher confidence when ball_ratio is lower

            // publish ball info
            ball_info_pub_ ->publish(ball_info_msg);

            // CLI debugging
            RCLCPP_INFO(this->get_logger(), "Predicted Distance: %.2f m", predictedDistance);
            std::cout << "Ball Ratio: " << ball_ratio << std::endl;
            
            // publishing distance data
            std_msgs::msg::Float64MultiArray distance_msg;
            distance_msg.data.push_back(predictedDistance);
            ball_distance_pub_ ->publish(distance_msg);

        } else { 
            // If not enough data points, use the current distance
            ball_info_msg.distance = distance;
            ball_info_msg.confidence = 1.0 - ball_ratio; // higher confidence when ball_ratio is lower

            // publish ball info
            ball_info_pub_ ->publish(ball_info_msg);

            // publishing distance data
            std_msgs::msg::Float64MultiArray distance_msg;
            distance_msg.data.push_back(distance);
            ball_distance_pub_ ->publish(distance_msg);
        }
       break ; 
    } 
 } else if (circles.empty()) {
    RCLCPP_WARN(this->get_logger(), "No circles detected in this frame");
 } 

 return frame ; 
}

void BallDetector::image_callback(const sensor_msgs::msg::Image::ConstSharedPtr& img_msg, 
   const sensor_msgs::msg::CameraInfo::ConstSharedPtr& cinfo_msg) {
  try{
    RCLCPP_INFO(this->get_logger(), "Image converted, calling detect()");
    // convert ros image to opencv
    double fx = cinfo_msg->k[0];  // Focal length in x
    double fy = cinfo_msg->k[4];  // Focal length in y
    double cx = cinfo_msg->k[2];  // Principal point x 
    double cy = cinfo_msg->k[5];  // Principal point y

    // Use camera calibration instead of parameter if available
    if (fx > 0) {
        focal_length_ = fx;
    }

    // convert ros image to opencv
    cv::Mat frame = cv_bridge::toCvShare(img_msg, "bgr8") -> image;

    // processing pipeline
    auto [seg_field, mask_field] = field(frame);
    cv::Mat mask_ball = ball(seg_field);
    cv::Mat final_frame = detect(mask_ball, mask_field, frame, distanceHistory);

    // publish detection results
    if(!final_frame.empty()){
      sensor_msgs::msg::Image::SharedPtr ball_img_msg = cv_bridge::CvImage(std_msgs::msg::Header(), "bgr8", final_frame).toImageMsg();

    //   ball_image_pub_ -> publish(*ball_img_msg.get());
        ball_image_pub_ -> publish(*ball_img_msg);
    }
    
  } catch(cv_bridge::Exception &e) {
    RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
  }
 } 
 
 