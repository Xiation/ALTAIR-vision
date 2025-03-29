// generated from rosidl_typesupport_fastrtps_c/resource/idl__rosidl_typesupport_fastrtps_c.h.em
// with input from temp_ball_detector:msg/BallDistance.idl
// generated code does not contain a copyright notice
#ifndef TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
#define TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_


#include <stddef.h>
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "temp_ball_detector/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "temp_ball_detector/msg/detail/ball_distance__struct.h"
#include "fastcdr/Cdr.h"

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_temp_ball_detector
bool cdr_serialize_temp_ball_detector__msg__BallDistance(
  const temp_ball_detector__msg__BallDistance * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_temp_ball_detector
bool cdr_deserialize_temp_ball_detector__msg__BallDistance(
  eprosima::fastcdr::Cdr &,
  temp_ball_detector__msg__BallDistance * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_temp_ball_detector
size_t get_serialized_size_temp_ball_detector__msg__BallDistance(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_temp_ball_detector
size_t max_serialized_size_temp_ball_detector__msg__BallDistance(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_temp_ball_detector
bool cdr_serialize_key_temp_ball_detector__msg__BallDistance(
  const temp_ball_detector__msg__BallDistance * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_temp_ball_detector
size_t get_serialized_size_key_temp_ball_detector__msg__BallDistance(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_temp_ball_detector
size_t max_serialized_size_key_temp_ball_detector__msg__BallDistance(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_temp_ball_detector
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, temp_ball_detector, msg, BallDistance)();

#ifdef __cplusplus
}
#endif

#endif  // TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__ROSIDL_TYPESUPPORT_FASTRTPS_C_H_
