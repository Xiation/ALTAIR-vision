// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from ball_detect:msg/BallInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ball_detect/msg/ball_info.hpp"


#ifndef BALL_DETECT__MSG__DETAIL__BALL_INFO__TRAITS_HPP_
#define BALL_DETECT__MSG__DETAIL__BALL_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "ball_detect/msg/detail/ball_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace ball_detect
{

namespace msg
{

inline void to_flow_style_yaml(
  const BallInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: distance
  {
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << ", ";
  }

  // member: x_pixel
  {
    out << "x_pixel: ";
    rosidl_generator_traits::value_to_yaml(msg.x_pixel, out);
    out << ", ";
  }

  // member: y_pixel
  {
    out << "y_pixel: ";
    rosidl_generator_traits::value_to_yaml(msg.y_pixel, out);
    out << ", ";
  }

  // member: radius_pixel
  {
    out << "radius_pixel: ";
    rosidl_generator_traits::value_to_yaml(msg.radius_pixel, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BallInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: distance
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "distance: ";
    rosidl_generator_traits::value_to_yaml(msg.distance, out);
    out << "\n";
  }

  // member: x_pixel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x_pixel: ";
    rosidl_generator_traits::value_to_yaml(msg.x_pixel, out);
    out << "\n";
  }

  // member: y_pixel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y_pixel: ";
    rosidl_generator_traits::value_to_yaml(msg.y_pixel, out);
    out << "\n";
  }

  // member: radius_pixel
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "radius_pixel: ";
    rosidl_generator_traits::value_to_yaml(msg.radius_pixel, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BallInfo & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace ball_detect

namespace rosidl_generator_traits
{

[[deprecated("use ball_detect::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const ball_detect::msg::BallInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  ball_detect::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use ball_detect::msg::to_yaml() instead")]]
inline std::string to_yaml(const ball_detect::msg::BallInfo & msg)
{
  return ball_detect::msg::to_yaml(msg);
}

template<>
inline const char * data_type<ball_detect::msg::BallInfo>()
{
  return "ball_detect::msg::BallInfo";
}

template<>
inline const char * name<ball_detect::msg::BallInfo>()
{
  return "ball_detect/msg/BallInfo";
}

template<>
struct has_fixed_size<ball_detect::msg::BallInfo>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<ball_detect::msg::BallInfo>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<ball_detect::msg::BallInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // BALL_DETECT__MSG__DETAIL__BALL_INFO__TRAITS_HPP_
