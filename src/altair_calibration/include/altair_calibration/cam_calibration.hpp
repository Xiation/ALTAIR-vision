#ifndef ALTAIR_CALIB_HPP_
#define ALTAIR_CALIB_HPP_

// Standard Library Includes
#include <vector>
#include <numeric>
#include <utility>
#include <functional>
#include <memory>
#include <string>
#include <chrono>


#include <opencv2/opencv.hpp>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cv_bridge/cv_bridge.hpp>
#include <fstream>

class CameraCalibrator : public rclcpp::Node {
    public:
        CameraCalibrator();
    private:
        void image_callback(const sensor_msgs::msg::Image::SharedPtr msg);
        void calibrate_camera();
        void save_calibration(const cv::Mat& cameraMatrix, const cv::Mat& distCoeffs);

        rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscription_;

        std::vector<std::vector<cv::Point2f>> imagePoints;
        std::vector<std::vector<cv::Point3f>> objectPoints;
        std::vector<cv::Point3f> objp;

        cv::Size imageSize;
        const cv::Size CHECKERBOARD;
        const float square_size;
        const double movement_threshold;

        bool calibrated;
        double rms_error;

        std::vector<cv::Point2f> prev_corners;
        rclcpp::Time last_capture_time;
        const double min_capture_interval_sec;

};


#endif // ALTAIR_CALIB_HPP_