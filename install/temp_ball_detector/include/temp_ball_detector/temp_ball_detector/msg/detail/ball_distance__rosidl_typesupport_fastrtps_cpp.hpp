// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from temp_ball_detector:msg/BallDistance.idl
// generated code does not contain a copyright notice

#ifndef TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "temp_ball_detector/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "temp_ball_detector/msg/detail/ball_distance__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace temp_ball_detector
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_temp_ball_detector
cdr_serialize(
  const temp_ball_detector::msg::BallDistance & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_temp_ball_detector
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  temp_ball_detector::msg::BallDistance & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_temp_ball_detector
get_serialized_size(
  const temp_ball_detector::msg::BallDistance & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_temp_ball_detector
max_serialized_size_BallDistance(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_temp_ball_detector
cdr_serialize_key(
  const temp_ball_detector::msg::BallDistance & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_temp_ball_detector
get_serialized_size_key(
  const temp_ball_detector::msg::BallDistance & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_temp_ball_detector
max_serialized_size_key_BallDistance(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace temp_ball_detector

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_temp_ball_detector
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, temp_ball_detector, msg, BallDistance)();

#ifdef __cplusplus
}
#endif

#endif  // TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
