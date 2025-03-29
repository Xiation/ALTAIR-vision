#ifndef BALL_DETECT_HPP_
#define BALL_DETECT_HPP_

#include <opencv2/opencv.hpp>
#include <vector>
#include <numeric>

#include <utility>
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>

#include <chrono>
#include <functional>
#include <memory>
#include <string>

#include "std_msgs/msg/string.hpp"
#include "cv_bridge/cv_bridge.h"

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher();

 private:
  void timer_callback();
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  size_t count_;
};

#endif // BALL_DETECT_HPP_