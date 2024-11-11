// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from ball_detector:msg/BallDistance.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ball_detector/msg/ball_distance.hpp"


#ifndef BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__BUILDER_HPP_
#define BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "ball_detector/msg/detail/ball_distance__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace ball_detector
{

namespace msg
{

namespace builder
{

class Init_BallDistance_jaraknya_jing
{
public:
  explicit Init_BallDistance_jaraknya_jing(::ball_detector::msg::BallDistance & msg)
  : msg_(msg)
  {}
  ::ball_detector::msg::BallDistance jaraknya_jing(::ball_detector::msg::BallDistance::_jaraknya_jing_type arg)
  {
    msg_.jaraknya_jing = std::move(arg);
    return std::move(msg_);
  }

private:
  ::ball_detector::msg::BallDistance msg_;
};

class Init_BallDistance_ball_ada_cok
{
public:
  Init_BallDistance_ball_ada_cok()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_BallDistance_jaraknya_jing ball_ada_cok(::ball_detector::msg::BallDistance::_ball_ada_cok_type arg)
  {
    msg_.ball_ada_cok = std::move(arg);
    return Init_BallDistance_jaraknya_jing(msg_);
  }

private:
  ::ball_detector::msg::BallDistance msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::ball_detector::msg::BallDistance>()
{
  return ball_detector::msg::builder::Init_BallDistance_ball_ada_cok();
}

}  // namespace ball_detector

#endif  // BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__BUILDER_HPP_
