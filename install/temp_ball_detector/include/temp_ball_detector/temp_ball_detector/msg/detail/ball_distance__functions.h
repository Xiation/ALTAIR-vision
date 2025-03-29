// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from temp_ball_detector:msg/BallDistance.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "temp_ball_detector/msg/ball_distance.h"


#ifndef TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__FUNCTIONS_H_
#define TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/action_type_support_struct.h"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_runtime_c/service_type_support_struct.h"
#include "rosidl_runtime_c/type_description/type_description__struct.h"
#include "rosidl_runtime_c/type_description/type_source__struct.h"
#include "rosidl_runtime_c/type_hash.h"
#include "rosidl_runtime_c/visibility_control.h"
#include "temp_ball_detector/msg/rosidl_generator_c__visibility_control.h"

#include "temp_ball_detector/msg/detail/ball_distance__struct.h"

/// Initialize msg/BallDistance message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * temp_ball_detector__msg__BallDistance
 * )) before or use
 * temp_ball_detector__msg__BallDistance__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
bool
temp_ball_detector__msg__BallDistance__init(temp_ball_detector__msg__BallDistance * msg);

/// Finalize msg/BallDistance message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
void
temp_ball_detector__msg__BallDistance__fini(temp_ball_detector__msg__BallDistance * msg);

/// Create msg/BallDistance message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * temp_ball_detector__msg__BallDistance__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
temp_ball_detector__msg__BallDistance *
temp_ball_detector__msg__BallDistance__create(void);

/// Destroy msg/BallDistance message.
/**
 * It calls
 * temp_ball_detector__msg__BallDistance__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
void
temp_ball_detector__msg__BallDistance__destroy(temp_ball_detector__msg__BallDistance * msg);

/// Check for msg/BallDistance message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
bool
temp_ball_detector__msg__BallDistance__are_equal(const temp_ball_detector__msg__BallDistance * lhs, const temp_ball_detector__msg__BallDistance * rhs);

/// Copy a msg/BallDistance message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
bool
temp_ball_detector__msg__BallDistance__copy(
  const temp_ball_detector__msg__BallDistance * input,
  temp_ball_detector__msg__BallDistance * output);

/// Retrieve pointer to the hash of the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
const rosidl_type_hash_t *
temp_ball_detector__msg__BallDistance__get_type_hash(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
const rosidl_runtime_c__type_description__TypeDescription *
temp_ball_detector__msg__BallDistance__get_type_description(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the single raw source text that defined this type.
ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
const rosidl_runtime_c__type_description__TypeSource *
temp_ball_detector__msg__BallDistance__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support);

/// Retrieve pointer to the recursive raw sources that defined the description of this type.
ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
const rosidl_runtime_c__type_description__TypeSource__Sequence *
temp_ball_detector__msg__BallDistance__get_type_description_sources(
  const rosidl_message_type_support_t * type_support);

/// Initialize array of msg/BallDistance messages.
/**
 * It allocates the memory for the number of elements and calls
 * temp_ball_detector__msg__BallDistance__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
bool
temp_ball_detector__msg__BallDistance__Sequence__init(temp_ball_detector__msg__BallDistance__Sequence * array, size_t size);

/// Finalize array of msg/BallDistance messages.
/**
 * It calls
 * temp_ball_detector__msg__BallDistance__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
void
temp_ball_detector__msg__BallDistance__Sequence__fini(temp_ball_detector__msg__BallDistance__Sequence * array);

/// Create array of msg/BallDistance messages.
/**
 * It allocates the memory for the array and calls
 * temp_ball_detector__msg__BallDistance__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
temp_ball_detector__msg__BallDistance__Sequence *
temp_ball_detector__msg__BallDistance__Sequence__create(size_t size);

/// Destroy array of msg/BallDistance messages.
/**
 * It calls
 * temp_ball_detector__msg__BallDistance__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
void
temp_ball_detector__msg__BallDistance__Sequence__destroy(temp_ball_detector__msg__BallDistance__Sequence * array);

/// Check for msg/BallDistance message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
bool
temp_ball_detector__msg__BallDistance__Sequence__are_equal(const temp_ball_detector__msg__BallDistance__Sequence * lhs, const temp_ball_detector__msg__BallDistance__Sequence * rhs);

/// Copy an array of msg/BallDistance messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_temp_ball_detector
bool
temp_ball_detector__msg__BallDistance__Sequence__copy(
  const temp_ball_detector__msg__BallDistance__Sequence * input,
  temp_ball_detector__msg__BallDistance__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TEMP_BALL_DETECTOR__MSG__DETAIL__BALL_DISTANCE__FUNCTIONS_H_
