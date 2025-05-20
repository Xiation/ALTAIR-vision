// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from ball_detect:msg/BallInfo.idl
// generated code does not contain a copyright notice

#ifndef BALL_DETECT__MSG__DETAIL__BALL_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define BALL_DETECT__MSG__DETAIL__BALL_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include <cstddef>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "ball_detect/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "ball_detect/msg/detail/ball_info__struct.hpp"

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

namespace ball_detect
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ball_detect
cdr_serialize(
  const ball_detect::msg::BallInfo & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ball_detect
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ball_detect::msg::BallInfo & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ball_detect
get_serialized_size(
  const ball_detect::msg::BallInfo & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ball_detect
max_serialized_size_BallInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ball_detect
cdr_serialize_key(
  const ball_detect::msg::BallInfo & ros_message,
  eprosima::fastcdr::Cdr &);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ball_detect
get_serialized_size_key(
  const ball_detect::msg::BallInfo & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ball_detect
max_serialized_size_key_BallInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ball_detect

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ball_detect
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ball_detect, msg, BallInfo)();

#ifdef __cplusplus
}
#endif

#endif  // BALL_DETECT__MSG__DETAIL__BALL_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
