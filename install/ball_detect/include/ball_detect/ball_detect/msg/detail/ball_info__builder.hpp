// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ball_detect:msg/BallInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ball_detect/msg/ball_info.hpp"


#ifndef BALL_DETECT__MSG__DETAIL__BALL_INFO__BUILDER_HPP_
#define BALL_DETECT__MSG__DETAIL__BALL_INFO__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ball_detect/msg/detail/ball_info__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ball_detect
{

namespace msg
{

namespace builder
{

class Init_BallInfo_confidence
{
public:
  explicit Init_BallInfo_confidence(::ball_detect::msg::BallInfo & msg)
  : msg_(msg)
  {}
  ::ball_detect::msg::BallInfo confidence(::ball_detect::msg::BallInfo::_confidence_type arg)
  {
    msg_.confidence = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ball_detect::msg::BallInfo msg_;
};

class Init_BallInfo_radius_pixel
{
public:
  explicit Init_BallInfo_radius_pixel(::ball_detect::msg::BallInfo & msg)
  : msg_(msg)
  {}
  Init_BallInfo_confidence radius_pixel(::ball_detect::msg::BallInfo::_radius_pixel_type arg)
  {
    msg_.radius_pixel = std::move(arg);
    return Init_BallInfo_confidence(msg_);
  }

private:
  ::ball_detect::msg::BallInfo msg_;
};

class Init_BallInfo_y_pixel
{
public:
  explicit Init_BallInfo_y_pixel(::ball_detect::msg::BallInfo & msg)
  : msg_(msg)
  {}
  Init_BallInfo_radius_pixel y_pixel(::ball_detect::msg::BallInfo::_y_pixel_type arg)
  {
    msg_.y_pixel = std::move(arg);
    return Init_BallInfo_radius_pixel(msg_);
  }

private:
  ::ball_detect::msg::BallInfo msg_;
};

class Init_BallInfo_x_pixel
{
public:
  explicit Init_BallInfo_x_pixel(::ball_detect::msg::BallInfo & msg)
  : msg_(msg)
  {}
  Init_BallInfo_y_pixel x_pixel(::ball_detect::msg::BallInfo::_x_pixel_type arg)
  {
    msg_.x_pixel = std::move(arg);
    return Init_BallInfo_y_pixel(msg_);
  }

private:
  ::ball_detect::msg::BallInfo msg_;
};

class Init_BallInfo_distance
{
public:
  explicit Init_BallInfo_distance(::ball_detect::msg::BallInfo & msg)
  : msg_(msg)
  {}
  Init_BallInfo_x_pixel distance(::ball_detect::msg::BallInfo::_distance_type arg)
  {
    msg_.distance = std::move(arg);
    return Init_BallInfo_x_pixel(msg_);
  }

private:
  ::ball_detect::msg::BallInfo msg_;
};

class Init_BallInfo_header
{
public:
  Init_BallInfo_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BallInfo_distance header(::ball_detect::msg::BallInfo::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_BallInfo_distance(msg_);
  }

private:
  ::ball_detect::msg::BallInfo msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ball_detect::msg::BallInfo>()
{
  return ball_detect::msg::builder::Init_BallInfo_header();
}

}  // namespace ball_detect

#endif  // BALL_DETECT__MSG__DETAIL__BALL_INFO__BUILDER_HPP_
