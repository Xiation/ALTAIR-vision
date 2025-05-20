#ifndef BALL_DETECT_HPP_
#define BALL_DETECT_HPP_

// Standard Library Includes
#include <vector>
#include <numeric>
#include <utility>
#include <functional>
#include <memory>
#include <string>
#include <chrono>

// OpenCV Includes
#include <opencv2/opencv.hpp>

// ROS2 Includes
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "sensor_msgs/msg/camera_info.hpp"
#include "std_msgs/msg/float64_multi_array.hpp"
#include "cv_bridge/cv_bridge.hpp"
#include "image_transport/image_transport.hpp"
#include "ball_detect/msg/ball_info.hpp"

class BallDetector : public rclcpp::Node
{
public:
    /**
     * @brief Constructor for the BallDetector node.
     */
    BallDetector();

private:
    /**
     * @brief Callback function for processing incoming images and camera info.
     * @param msg Image message.
     * @param cinfo Camera info message.
     */

    // callback function 
    void image_callback(
        const sensor_msgs::msg::Image::ConstSharedPtr& msg,
        const sensor_msgs::msg::CameraInfo::ConstSharedPtr& cinfo
    );

    // Vision processing methods
    cv::Mat ball(const cv::Mat &frame); ///< Isolates the ball using color segmentation.
    std::pair<cv::Mat, cv::Mat> field(const cv::Mat &frame); ///< Segments the field.
    std::pair<int, int> find_first_last_orange(const cv::Mat &line_data, int line_start); ///< Finds orange pixels horizontally.
    std::pair<int, int> find_top_bottom_orange(const cv::Mat &column_data, int col_start); ///< Finds orange pixels vertically.
    std::vector<double> movingAverage(const std::vector<double>& data, int windowSize); ///< Computes moving average.
    cv::Mat detect(const cv::Mat &mask_ball, const cv::Mat &mask_field, cv::Mat frame, std::vector<double>& distanceHistory); ///< Detects and tracks the ball.

    // Subscribers and publishers
    image_transport::CameraSubscriber image_sub_; ///< Subscribes to the input image topic.

    rclcpp::TimerBase::SharedPtr status_timer_;

    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr ball_image_pub_; //< published bounded ball images
    rclcpp::Publisher<std_msgs::msg::Float64MultiArray>::SharedPtr ball_distance_pub_; ///< Publishes distance results.

    // change publisher definition with new message
    rclcpp::Publisher<ball_detect::msg::BallInfo>::SharedPtr ball_info_pub_; ///< Publishes ball information.

    // Distance history for smoothing
    std::vector<double> distanceHistory;

    // Parameters
    double focal_length_; ///< Focal length of the camera.
    double actual_diameter_; ///< Actual diameter of the ball.
    int moving_average_window_; ///< Window size for moving average.

    int center_x ;
    int center_y ;

    // Orange color bounds
    cv::Scalar lower_orange_ ; ///< Lower bound for orange color in HSV.
    cv::Scalar upper_orange_ ; ///< Upper bound for orange color in HSV.
    // green color bounds
    cv::Scalar lower_green_; ///< Lower bound for green color in HSV.
    cv::Scalar upper_green_; ///< Upper bound for green color in HSV.

};

#endif // BALL_DETECT_HPP_