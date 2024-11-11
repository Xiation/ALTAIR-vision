// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from ball_detector:msg/BallDistance.idl
// generated code does not contain a copyright notice
#include "ball_detector/msg/detail/ball_distance__rosidl_typesupport_fastrtps_cpp.hpp"
#include "ball_detector/msg/detail/ball_distance__functions.h"
#include "ball_detector/msg/detail/ball_distance__struct.hpp"

#include <cstddef>
#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace ball_detector
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{


bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ball_detector
cdr_serialize(
  const ball_detector::msg::BallDistance & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: ball_ada_cok
  cdr << (ros_message.ball_ada_cok ? true : false);

  // Member: jaraknya_jing
  cdr << ros_message.jaraknya_jing;

  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ball_detector
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  ball_detector::msg::BallDistance & ros_message)
{
  // Member: ball_ada_cok
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.ball_ada_cok = tmp ? true : false;
  }

  // Member: jaraknya_jing
  cdr >> ros_message.jaraknya_jing;

  return true;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ball_detector
get_serialized_size(
  const ball_detector::msg::BallDistance & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: ball_ada_cok
  {
    size_t item_size = sizeof(ros_message.ball_ada_cok);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: jaraknya_jing
  {
    size_t item_size = sizeof(ros_message.jaraknya_jing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ball_detector
max_serialized_size_BallDistance(
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

  // Member: ball_ada_cok
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }
  // Member: jaraknya_jing
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
    using DataType = ball_detector::msg::BallDistance;
    is_plain =
      (
      offsetof(DataType, jaraknya_jing) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ball_detector
cdr_serialize_key(
  const ball_detector::msg::BallDistance & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: ball_ada_cok
  cdr << (ros_message.ball_ada_cok ? true : false);

  // Member: jaraknya_jing
  cdr << ros_message.jaraknya_jing;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ball_detector
get_serialized_size_key(
  const ball_detector::msg::BallDistance & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: ball_ada_cok
  {
    size_t item_size = sizeof(ros_message.ball_ada_cok);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  // Member: jaraknya_jing
  {
    size_t item_size = sizeof(ros_message.jaraknya_jing);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_ball_detector
max_serialized_size_key_BallDistance(
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

  // Member: ball_ada_cok
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: jaraknya_jing
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
    using DataType = ball_detector::msg::BallDistance;
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
  auto typed_message =
    static_cast<const ball_detector::msg::BallDistance *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _BallDistance__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<ball_detector::msg::BallDistance *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _BallDistance__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const ball_detector::msg::BallDistance *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _BallDistance__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_BallDistance(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _BallDistance__callbacks = {
  "ball_detector::msg",
  "BallDistance",
  _BallDistance__cdr_serialize,
  _BallDistance__cdr_deserialize,
  _BallDistance__get_serialized_size,
  _BallDistance__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _BallDistance__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_BallDistance__callbacks,
  get_message_typesupport_handle_function,
  &ball_detector__msg__BallDistance__get_type_hash,
  &ball_detector__msg__BallDistance__get_type_description,
  &ball_detector__msg__BallDistance__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace ball_detector

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_ball_detector
const rosidl_message_type_support_t *
get_message_type_support_handle<ball_detector::msg::BallDistance>()
{
  return &ball_detector::msg::typesupport_fastrtps_cpp::_BallDistance__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, ball_detector, msg, BallDistance)() {
  return &ball_detector::msg::typesupport_fastrtps_cpp::_BallDistance__handle;
}

#ifdef __cplusplus
}
#endif
