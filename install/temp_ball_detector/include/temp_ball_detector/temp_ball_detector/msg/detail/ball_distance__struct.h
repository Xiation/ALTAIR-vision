// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from temp_ball_detector:msg/BallDistance.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "temp_ball_detector/msg/ball_distance.h"


#ifndef TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__STRUCT_H_
#define TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/BallDistance in the package temp_ball_detector.
typedef struct temp_ball_detector__msg__BallDistance
{
  bool ball_ada_cok;
  double jaraknya_jing;
} temp_ball_detector__msg__BallDistance;

// Struct for a sequence of temp_ball_detector__msg__BallDistance.
typedef struct temp_ball_detector__msg__BallDistance__Sequence
{
  temp_ball_detector__msg__BallDistance * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} temp_ball_detector__msg__BallDistance__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__STRUCT_H_
