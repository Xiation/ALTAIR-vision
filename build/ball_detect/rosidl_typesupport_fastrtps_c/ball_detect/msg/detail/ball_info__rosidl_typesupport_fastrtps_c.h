// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from ball_detect:msg/BallInfo.idl
// generated code does not contain a copyright notice
#ifndef BALL_DETECT__MSG__DETAIL__BALL_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define BALL_DETECT__MSG__DETAIL__BALL_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "ball_detect/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ball_detect/msg/detail/ball_info__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ball_detect
bool cdr_serialize_ball_detect__msg__BallInfo(
  const ball_detect__msg__BallInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ball_detect
bool cdr_deserialize_ball_detect__msg__BallInfo(
  eprosima::fastcdr::Cdr &,
  ball_detect__msg__BallInfo * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ball_detect
size_t get_serialized_size_ball_detect__msg__BallInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ball_detect
size_t max_serialized_size_ball_detect__msg__BallInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ball_detect
bool cdr_serialize_key_ball_detect__msg__BallInfo(
  const ball_detect__msg__BallInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ball_detect
size_t get_serialized_size_key_ball_detect__msg__BallInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ball_detect
size_t max_serialized_size_key_ball_detect__msg__BallInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ball_detect
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ball_detect, msg, BallInfo)();

#ifdef __cplusplus
}
#endif

#endif  // BALL_DETECT__MSG__DETAIL__BALL_INFO__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
