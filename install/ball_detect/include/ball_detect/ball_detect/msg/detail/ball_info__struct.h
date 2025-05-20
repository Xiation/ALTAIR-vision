// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from ball_detect:msg/BallInfo.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "ball_detect/msg/ball_info.h"


#ifndef BALL_DETECT__MSG__DETAIL__BALL_INFO__STRUCT_H_
#define BALL_DETECT__MSG__DETAIL__BALL_INFO__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

/// Struct defined in msg/BallInfo in the package ball_detect.
/**
  * Ball detection information (temporarily)
 */
typedef struct ball_detect__msg__BallInfo
{
  std_msgs__msg__Header header;
  /// Distance to ball in meters
  double distance;
  /// X coordinate in image (pixels)
  int32_t x_pixel;
  /// Y coordinate in image (pixels)
  int32_t y_pixel;
  /// Radius in pixels
  double radius_pixel;
  /// Detection confidence (0-1)
  double confidence;
} ball_detect__msg__BallInfo;

// Struct for a sequence of ball_detect__msg__BallInfo.
typedef struct ball_detect__msg__BallInfo__Sequence
{
  ball_detect__msg__BallInfo * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} ball_detect__msg__BallInfo__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // BALL_DETECT__MSG__DETAIL__BALL_INFO__STRUCT_H_
