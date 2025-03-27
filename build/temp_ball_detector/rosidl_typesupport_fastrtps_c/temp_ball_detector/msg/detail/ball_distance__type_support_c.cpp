// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from temp_ball_detector:msg/BallDistance.idl
// generated code does not contain a copyright notice
#include "temp_ball_detector/msg/detail/ball_distance__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "temp_ball_detector/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "temp_ball_detector/msg/detail/ball_distance__struct.h"
#include "temp_ball_detector/msg/detail/ball_distance__functions.h"
#include "fastcdr/Cdr.h"

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

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _BallDistance__ros_msg_type = temp_ball_detector__msg__BallDistance;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_temp_ball_detector
bool cdr_serialize_temp_ball_detector__msg__BallDistance(
  const temp_ball_detector__msg__BallDistance * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: ball_ada_cok
  {
    cdr << (ros_message->ball_ada_cok ? true : false);
  }

  // Field name: jaraknya_jing
  {
    cdr << ros_message->jaraknya_jing;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_temp_ball_detector
bool cdr_deserialize_temp_ball_detector__msg__BallDistance(
  eprosima::fastcdr::Cdr & cdr,
  temp_ball_detector__msg__BallDistance * ros_message)
{
  // Field name: ball_ada_cok
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->ball_ada_cok = tmp ? true : false;
  }

  // Field name: jaraknya_jing
  {
    cdr >> ros_message->jaraknya_jing;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_temp_ball_detector
size_t get_serialized_size_temp_ball_detector__msg__BallDistance(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BallDistance__ros_msg_type * ros_message = static_cast<const _BallDistance__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: ball_ada_cok
  {
    size_t item_size = sizeof(ros_message->ball_ada_cok);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: jaraknya_jing
  {
    size_t item_size = sizeof(ros_message->jaraknya_jing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_temp_ball_detector
size_t max_serialized_size_temp_ball_detector__msg__BallDistance(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;

  // Field name: ball_ada_cok
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: jaraknya_jing
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = temp_ball_detector__msg__BallDistance;
    is_plain =
      (
      offsetof(DataType, jaraknya_jing) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_temp_ball_detector
bool cdr_serialize_key_temp_ball_detector__msg__BallDistance(
  const temp_ball_detector__msg__BallDistance * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: ball_ada_cok
  {
    cdr << (ros_message->ball_ada_cok ? true : false);
  }

  // Field name: jaraknya_jing
  {
    cdr << ros_message->jaraknya_jing;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_temp_ball_detector
size_t get_serialized_size_key_temp_ball_detector__msg__BallDistance(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _BallDistance__ros_msg_type * ros_message = static_cast<const _BallDistance__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: ball_ada_cok
  {
    size_t item_size = sizeof(ros_message->ball_ada_cok);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Field name: jaraknya_jing
  {
    size_t item_size = sizeof(ros_message->jaraknya_jing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_temp_ball_detector
size_t max_serialized_size_key_temp_ball_detector__msg__BallDistance(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;
  // Field name: ball_ada_cok
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Field name: jaraknya_jing
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = temp_ball_detector__msg__BallDistance;
    is_plain =
      (
      offsetof(DataType, jaraknya_jing) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _BallDistance__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const temp_ball_detector__msg__BallDistance * ros_message = static_cast<const temp_ball_detector__msg__BallDistance *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_temp_ball_detector__msg__BallDistance(ros_message, cdr);
}

static bool _BallDistance__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  temp_ball_detector__msg__BallDistance * ros_message = static_cast<temp_ball_detector__msg__BallDistance *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_temp_ball_detector__msg__BallDistance(cdr, ros_message);
}

static uint32_t _BallDistance__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_temp_ball_detector__msg__BallDistance(
      untyped_ros_message, 0));
}

static size_t _BallDistance__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_temp_ball_detector__msg__BallDistance(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_BallDistance = {
  "temp_ball_detector::msg",
  "BallDistance",
  _BallDistance__cdr_serialize,
  _BallDistance__cdr_deserialize,
  _BallDistance__get_serialized_size,
  _BallDistance__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _BallDistance__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_BallDistance,
  get_message_typesupport_handle_function,
  &temp_ball_detector__msg__BallDistance__get_type_hash,
  &temp_ball_detector__msg__BallDistance__get_type_description,
  &temp_ball_detector__msg__BallDistance__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, temp_ball_detector, msg, BallDistance)() {
  return &_BallDistance__type_support;
}

#if defined(__cplusplus)
}
#endif
