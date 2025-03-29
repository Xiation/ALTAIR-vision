// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from temp_ball_detector:msg/BallDistance.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "temp_ball_detector/msg/ball_distance.hpp"


#ifndef TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__TRAITS_HPP_
#define TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "temp_ball_detector/msg/detail/ball_distance__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace temp_ball_detector
{

namespace msg
{

inline void to_flow_style_yaml(
  const BallDistance & msg,
  std::ostream & out)
{
  out << "{";
  // member: ball_ada_cok
  {
    out << "ball_ada_cok: ";
    rosidl_generator_traits::value_to_yaml(msg.ball_ada_cok, out);
    out << ", ";
  }

  // member: jaraknya_jing
  {
    out << "jaraknya_jing: ";
    rosidl_generator_traits::value_to_yaml(msg.jaraknya_jing, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const BallDistance & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ball_ada_cok
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ball_ada_cok: ";
    rosidl_generator_traits::value_to_yaml(msg.ball_ada_cok, out);
    out << "\n";
  }

  // member: jaraknya_jing
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "jaraknya_jing: ";
    rosidl_generator_traits::value_to_yaml(msg.jaraknya_jing, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const BallDistance & msg, bool use_flow_style = false)
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

}  // namespace temp_ball_detector

namespace rosidl_generator_traits
{

[[deprecated("use temp_ball_detector::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const temp_ball_detector::msg::BallDistance & msg,
  std::ostream & out, size_t indentation = 0)
{
  temp_ball_detector::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use temp_ball_detector::msg::to_yaml() instead")]]
inline std::string to_yaml(const temp_ball_detector::msg::BallDistance & msg)
{
  return temp_ball_detector::msg::to_yaml(msg);
}

template<>
inline const char * data_type<temp_ball_detector::msg::BallDistance>()
{
  return "temp_ball_detector::msg::BallDistance";
}

template<>
inline const char * name<temp_ball_detector::msg::BallDistance>()
{
  return "temp_ball_detector/msg/BallDistance";
}

template<>
struct has_fixed_size<temp_ball_detector::msg::BallDistance>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<temp_ball_detector::msg::BallDistance>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<temp_ball_detector::msg::BallDistance>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__TRAITS_HPP_
