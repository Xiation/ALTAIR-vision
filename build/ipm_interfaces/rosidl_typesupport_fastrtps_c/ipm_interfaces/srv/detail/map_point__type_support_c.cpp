// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from ipm_interfaces:srv/MapPoint.idl
// generated code does not contain a copyright notice
#include "ipm_interfaces/srv/detail/map_point__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <cstddef>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "ipm_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ipm_interfaces/srv/detail/map_point__struct.h"
#include "ipm_interfaces/srv/detail/map_point__functions.h"
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

#include "builtin_interfaces/msg/detail/time__functions.h"  // time
#include "rosidl_runtime_c/string.h"  // output_frame_id, plane_frame_id
#include "rosidl_runtime_c/string_functions.h"  // output_frame_id, plane_frame_id
#include "shape_msgs/msg/detail/plane__functions.h"  // plane
#include "vision_msgs/msg/detail/point2_d__functions.h"  // point

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
bool cdr_serialize_builtin_interfaces__msg__Time(
  const builtin_interfaces__msg__Time * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
bool cdr_deserialize_builtin_interfaces__msg__Time(
  eprosima::fastcdr::Cdr & cdr,
  builtin_interfaces__msg__Time * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t get_serialized_size_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t max_serialized_size_builtin_interfaces__msg__Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
bool cdr_serialize_key_builtin_interfaces__msg__Time(
  const builtin_interfaces__msg__Time * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t get_serialized_size_key_builtin_interfaces__msg__Time(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t max_serialized_size_key_builtin_interfaces__msg__Time(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, builtin_interfaces, msg, Time)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
bool cdr_serialize_shape_msgs__msg__Plane(
  const shape_msgs__msg__Plane * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
bool cdr_deserialize_shape_msgs__msg__Plane(
  eprosima::fastcdr::Cdr & cdr,
  shape_msgs__msg__Plane * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t get_serialized_size_shape_msgs__msg__Plane(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t max_serialized_size_shape_msgs__msg__Plane(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
bool cdr_serialize_key_shape_msgs__msg__Plane(
  const shape_msgs__msg__Plane * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t get_serialized_size_key_shape_msgs__msg__Plane(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t max_serialized_size_key_shape_msgs__msg__Plane(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, shape_msgs, msg, Plane)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
bool cdr_serialize_vision_msgs__msg__Point2D(
  const vision_msgs__msg__Point2D * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
bool cdr_deserialize_vision_msgs__msg__Point2D(
  eprosima::fastcdr::Cdr & cdr,
  vision_msgs__msg__Point2D * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t get_serialized_size_vision_msgs__msg__Point2D(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t max_serialized_size_vision_msgs__msg__Point2D(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
bool cdr_serialize_key_vision_msgs__msg__Point2D(
  const vision_msgs__msg__Point2D * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t get_serialized_size_key_vision_msgs__msg__Point2D(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t max_serialized_size_key_vision_msgs__msg__Point2D(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, vision_msgs, msg, Point2D)();


using _MapPoint_Request__ros_msg_type = ipm_interfaces__srv__MapPoint_Request;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
bool cdr_serialize_ipm_interfaces__srv__MapPoint_Request(
  const ipm_interfaces__srv__MapPoint_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: plane
  {
    cdr_serialize_shape_msgs__msg__Plane(
      &ros_message->plane, cdr);
  }

  // Field name: point
  {
    cdr_serialize_vision_msgs__msg__Point2D(
      &ros_message->point, cdr);
  }

  // Field name: time
  {
    cdr_serialize_builtin_interfaces__msg__Time(
      &ros_message->time, cdr);
  }

  // Field name: plane_frame_id
  {
    const rosidl_runtime_c__String * str = &ros_message->plane_frame_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: output_frame_id
  {
    const rosidl_runtime_c__String * str = &ros_message->output_frame_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
bool cdr_deserialize_ipm_interfaces__srv__MapPoint_Request(
  eprosima::fastcdr::Cdr & cdr,
  ipm_interfaces__srv__MapPoint_Request * ros_message)
{
  // Field name: plane
  {
    cdr_deserialize_shape_msgs__msg__Plane(cdr, &ros_message->plane);
  }

  // Field name: point
  {
    cdr_deserialize_vision_msgs__msg__Point2D(cdr, &ros_message->point);
  }

  // Field name: time
  {
    cdr_deserialize_builtin_interfaces__msg__Time(cdr, &ros_message->time);
  }

  // Field name: plane_frame_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->plane_frame_id.data) {
      rosidl_runtime_c__String__init(&ros_message->plane_frame_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->plane_frame_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'plane_frame_id'\n");
      return false;
    }
  }

  // Field name: output_frame_id
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->output_frame_id.data) {
      rosidl_runtime_c__String__init(&ros_message->output_frame_id);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->output_frame_id,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'output_frame_id'\n");
      return false;
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
size_t get_serialized_size_ipm_interfaces__srv__MapPoint_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MapPoint_Request__ros_msg_type * ros_message = static_cast<const _MapPoint_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: plane
  current_alignment += get_serialized_size_shape_msgs__msg__Plane(
    &(ros_message->plane), current_alignment);

  // Field name: point
  current_alignment += get_serialized_size_vision_msgs__msg__Point2D(
    &(ros_message->point), current_alignment);

  // Field name: time
  current_alignment += get_serialized_size_builtin_interfaces__msg__Time(
    &(ros_message->time), current_alignment);

  // Field name: plane_frame_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->plane_frame_id.size + 1);

  // Field name: output_frame_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->output_frame_id.size + 1);

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
size_t max_serialized_size_ipm_interfaces__srv__MapPoint_Request(
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

  // Field name: plane
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_shape_msgs__msg__Plane(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: point
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_vision_msgs__msg__Point2D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: time
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: plane_frame_id
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: output_frame_id
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ipm_interfaces__srv__MapPoint_Request;
    is_plain =
      (
      offsetof(DataType, output_frame_id) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
bool cdr_serialize_key_ipm_interfaces__srv__MapPoint_Request(
  const ipm_interfaces__srv__MapPoint_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: plane
  {
    cdr_serialize_key_shape_msgs__msg__Plane(
      &ros_message->plane, cdr);
  }

  // Field name: point
  {
    cdr_serialize_key_vision_msgs__msg__Point2D(
      &ros_message->point, cdr);
  }

  // Field name: time
  {
    cdr_serialize_key_builtin_interfaces__msg__Time(
      &ros_message->time, cdr);
  }

  // Field name: plane_frame_id
  {
    const rosidl_runtime_c__String * str = &ros_message->plane_frame_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  // Field name: output_frame_id
  {
    const rosidl_runtime_c__String * str = &ros_message->output_frame_id;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
size_t get_serialized_size_key_ipm_interfaces__srv__MapPoint_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MapPoint_Request__ros_msg_type * ros_message = static_cast<const _MapPoint_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: plane
  current_alignment += get_serialized_size_key_shape_msgs__msg__Plane(
    &(ros_message->plane), current_alignment);

  // Field name: point
  current_alignment += get_serialized_size_key_vision_msgs__msg__Point2D(
    &(ros_message->point), current_alignment);

  // Field name: time
  current_alignment += get_serialized_size_key_builtin_interfaces__msg__Time(
    &(ros_message->time), current_alignment);

  // Field name: plane_frame_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->plane_frame_id.size + 1);

  // Field name: output_frame_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->output_frame_id.size + 1);

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
size_t max_serialized_size_key_ipm_interfaces__srv__MapPoint_Request(
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
  // Field name: plane
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_shape_msgs__msg__Plane(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: point
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_vision_msgs__msg__Point2D(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: time
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_builtin_interfaces__msg__Time(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: plane_frame_id
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Field name: output_frame_id
  {
    size_t array_size = 1;
    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ipm_interfaces__srv__MapPoint_Request;
    is_plain =
      (
      offsetof(DataType, output_frame_id) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _MapPoint_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const ipm_interfaces__srv__MapPoint_Request * ros_message = static_cast<const ipm_interfaces__srv__MapPoint_Request *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_ipm_interfaces__srv__MapPoint_Request(ros_message, cdr);
}

static bool _MapPoint_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  ipm_interfaces__srv__MapPoint_Request * ros_message = static_cast<ipm_interfaces__srv__MapPoint_Request *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_ipm_interfaces__srv__MapPoint_Request(cdr, ros_message);
}

static uint32_t _MapPoint_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ipm_interfaces__srv__MapPoint_Request(
      untyped_ros_message, 0));
}

static size_t _MapPoint_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ipm_interfaces__srv__MapPoint_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MapPoint_Request = {
  "ipm_interfaces::srv",
  "MapPoint_Request",
  _MapPoint_Request__cdr_serialize,
  _MapPoint_Request__cdr_deserialize,
  _MapPoint_Request__get_serialized_size,
  _MapPoint_Request__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _MapPoint_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MapPoint_Request,
  get_message_typesupport_handle_function,
  &ipm_interfaces__srv__MapPoint_Request__get_type_hash,
  &ipm_interfaces__srv__MapPoint_Request__get_type_description,
  &ipm_interfaces__srv__MapPoint_Request__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ipm_interfaces, srv, MapPoint_Request)() {
  return &_MapPoint_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "ipm_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "ipm_interfaces/srv/detail/map_point__struct.h"
// already included above
// #include "ipm_interfaces/srv/detail/map_point__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

#include "geometry_msgs/msg/detail/point_stamped__functions.h"  // point

// forward declare type support functions

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
bool cdr_serialize_geometry_msgs__msg__PointStamped(
  const geometry_msgs__msg__PointStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
bool cdr_deserialize_geometry_msgs__msg__PointStamped(
  eprosima::fastcdr::Cdr & cdr,
  geometry_msgs__msg__PointStamped * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t get_serialized_size_geometry_msgs__msg__PointStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t max_serialized_size_geometry_msgs__msg__PointStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
bool cdr_serialize_key_geometry_msgs__msg__PointStamped(
  const geometry_msgs__msg__PointStamped * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t get_serialized_size_key_geometry_msgs__msg__PointStamped(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t max_serialized_size_key_geometry_msgs__msg__PointStamped(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, PointStamped)();


using _MapPoint_Response__ros_msg_type = ipm_interfaces__srv__MapPoint_Response;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
bool cdr_serialize_ipm_interfaces__srv__MapPoint_Response(
  const ipm_interfaces__srv__MapPoint_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: point
  {
    cdr_serialize_geometry_msgs__msg__PointStamped(
      &ros_message->point, cdr);
  }

  // Field name: result
  {
    cdr << ros_message->result;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
bool cdr_deserialize_ipm_interfaces__srv__MapPoint_Response(
  eprosima::fastcdr::Cdr & cdr,
  ipm_interfaces__srv__MapPoint_Response * ros_message)
{
  // Field name: point
  {
    cdr_deserialize_geometry_msgs__msg__PointStamped(cdr, &ros_message->point);
  }

  // Field name: result
  {
    cdr >> ros_message->result;
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
size_t get_serialized_size_ipm_interfaces__srv__MapPoint_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MapPoint_Response__ros_msg_type * ros_message = static_cast<const _MapPoint_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: point
  current_alignment += get_serialized_size_geometry_msgs__msg__PointStamped(
    &(ros_message->point), current_alignment);

  // Field name: result
  {
    size_t item_size = sizeof(ros_message->result);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
size_t max_serialized_size_ipm_interfaces__srv__MapPoint_Response(
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

  // Field name: point
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_geometry_msgs__msg__PointStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: result
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ipm_interfaces__srv__MapPoint_Response;
    is_plain =
      (
      offsetof(DataType, result) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
bool cdr_serialize_key_ipm_interfaces__srv__MapPoint_Response(
  const ipm_interfaces__srv__MapPoint_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: point
  {
    cdr_serialize_key_geometry_msgs__msg__PointStamped(
      &ros_message->point, cdr);
  }

  // Field name: result
  {
    cdr << ros_message->result;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
size_t get_serialized_size_key_ipm_interfaces__srv__MapPoint_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MapPoint_Response__ros_msg_type * ros_message = static_cast<const _MapPoint_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: point
  current_alignment += get_serialized_size_key_geometry_msgs__msg__PointStamped(
    &(ros_message->point), current_alignment);

  // Field name: result
  {
    size_t item_size = sizeof(ros_message->result);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
size_t max_serialized_size_key_ipm_interfaces__srv__MapPoint_Response(
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
  // Field name: point
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_geometry_msgs__msg__PointStamped(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: result
  {
    size_t array_size = 1;
    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ipm_interfaces__srv__MapPoint_Response;
    is_plain =
      (
      offsetof(DataType, result) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _MapPoint_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const ipm_interfaces__srv__MapPoint_Response * ros_message = static_cast<const ipm_interfaces__srv__MapPoint_Response *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_ipm_interfaces__srv__MapPoint_Response(ros_message, cdr);
}

static bool _MapPoint_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  ipm_interfaces__srv__MapPoint_Response * ros_message = static_cast<ipm_interfaces__srv__MapPoint_Response *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_ipm_interfaces__srv__MapPoint_Response(cdr, ros_message);
}

static uint32_t _MapPoint_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ipm_interfaces__srv__MapPoint_Response(
      untyped_ros_message, 0));
}

static size_t _MapPoint_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ipm_interfaces__srv__MapPoint_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MapPoint_Response = {
  "ipm_interfaces::srv",
  "MapPoint_Response",
  _MapPoint_Response__cdr_serialize,
  _MapPoint_Response__cdr_deserialize,
  _MapPoint_Response__get_serialized_size,
  _MapPoint_Response__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _MapPoint_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MapPoint_Response,
  get_message_typesupport_handle_function,
  &ipm_interfaces__srv__MapPoint_Response__get_type_hash,
  &ipm_interfaces__srv__MapPoint_Response__get_type_description,
  &ipm_interfaces__srv__MapPoint_Response__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ipm_interfaces, srv, MapPoint_Response)() {
  return &_MapPoint_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <cstddef>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/serialization_helpers.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "ipm_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "ipm_interfaces/srv/detail/map_point__struct.h"
// already included above
// #include "ipm_interfaces/srv/detail/map_point__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

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

#include "service_msgs/msg/detail/service_event_info__functions.h"  // info

// forward declare type support functions

bool cdr_serialize_ipm_interfaces__srv__MapPoint_Request(
  const ipm_interfaces__srv__MapPoint_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_ipm_interfaces__srv__MapPoint_Request(
  eprosima::fastcdr::Cdr & cdr,
  ipm_interfaces__srv__MapPoint_Request * ros_message);

size_t get_serialized_size_ipm_interfaces__srv__MapPoint_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_ipm_interfaces__srv__MapPoint_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_ipm_interfaces__srv__MapPoint_Request(
  const ipm_interfaces__srv__MapPoint_Request * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_ipm_interfaces__srv__MapPoint_Request(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_ipm_interfaces__srv__MapPoint_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ipm_interfaces, srv, MapPoint_Request)();

bool cdr_serialize_ipm_interfaces__srv__MapPoint_Response(
  const ipm_interfaces__srv__MapPoint_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool cdr_deserialize_ipm_interfaces__srv__MapPoint_Response(
  eprosima::fastcdr::Cdr & cdr,
  ipm_interfaces__srv__MapPoint_Response * ros_message);

size_t get_serialized_size_ipm_interfaces__srv__MapPoint_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_ipm_interfaces__srv__MapPoint_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

bool cdr_serialize_key_ipm_interfaces__srv__MapPoint_Response(
  const ipm_interfaces__srv__MapPoint_Response * ros_message,
  eprosima::fastcdr::Cdr & cdr);

size_t get_serialized_size_key_ipm_interfaces__srv__MapPoint_Response(
  const void * untyped_ros_message,
  size_t current_alignment);

size_t max_serialized_size_key_ipm_interfaces__srv__MapPoint_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ipm_interfaces, srv, MapPoint_Response)();

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
bool cdr_serialize_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
bool cdr_deserialize_service_msgs__msg__ServiceEventInfo(
  eprosima::fastcdr::Cdr & cdr,
  service_msgs__msg__ServiceEventInfo * ros_message);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t get_serialized_size_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t max_serialized_size_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
bool cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
  const service_msgs__msg__ServiceEventInfo * ros_message,
  eprosima::fastcdr::Cdr & cdr);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
size_t max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_ipm_interfaces
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, service_msgs, msg, ServiceEventInfo)();


using _MapPoint_Event__ros_msg_type = ipm_interfaces__srv__MapPoint_Event;


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
bool cdr_serialize_ipm_interfaces__srv__MapPoint_Event(
  const ipm_interfaces__srv__MapPoint_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    cdr_serialize_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_ipm_interfaces__srv__MapPoint_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_ipm_interfaces__srv__MapPoint_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
bool cdr_deserialize_ipm_interfaces__srv__MapPoint_Event(
  eprosima::fastcdr::Cdr & cdr,
  ipm_interfaces__srv__MapPoint_Event * ros_message)
{
  // Field name: info
  {
    cdr_deserialize_service_msgs__msg__ServiceEventInfo(cdr, &ros_message->info);
  }

  // Field name: request
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->request.data) {
      ipm_interfaces__srv__MapPoint_Request__Sequence__fini(&ros_message->request);
    }
    if (!ipm_interfaces__srv__MapPoint_Request__Sequence__init(&ros_message->request, size)) {
      fprintf(stderr, "failed to create array for field 'request'");
      return false;
    }
    auto array_ptr = ros_message->request.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_ipm_interfaces__srv__MapPoint_Request(cdr, &array_ptr[i]);
    }
  }

  // Field name: response
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->response.data) {
      ipm_interfaces__srv__MapPoint_Response__Sequence__fini(&ros_message->response);
    }
    if (!ipm_interfaces__srv__MapPoint_Response__Sequence__init(&ros_message->response, size)) {
      fprintf(stderr, "failed to create array for field 'response'");
      return false;
    }
    auto array_ptr = ros_message->response.data;
    for (size_t i = 0; i < size; ++i) {
      cdr_deserialize_ipm_interfaces__srv__MapPoint_Response(cdr, &array_ptr[i]);
    }
  }

  return true;
}  // NOLINT(readability/fn_size)


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
size_t get_serialized_size_ipm_interfaces__srv__MapPoint_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MapPoint_Event__ros_msg_type * ros_message = static_cast<const _MapPoint_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += get_serialized_size_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_ipm_interfaces__srv__MapPoint_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_ipm_interfaces__srv__MapPoint_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}


ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
size_t max_serialized_size_ipm_interfaces__srv__MapPoint_Event(
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

  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_ipm_interfaces__srv__MapPoint_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_ipm_interfaces__srv__MapPoint_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }


  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ipm_interfaces__srv__MapPoint_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
bool cdr_serialize_key_ipm_interfaces__srv__MapPoint_Event(
  const ipm_interfaces__srv__MapPoint_Event * ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Field name: info
  {
    cdr_serialize_key_service_msgs__msg__ServiceEventInfo(
      &ros_message->info, cdr);
  }

  // Field name: request
  {
    size_t size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_ipm_interfaces__srv__MapPoint_Request(
        &array_ptr[i], cdr);
    }
  }

  // Field name: response
  {
    size_t size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    if (size > 1) {
      fprintf(stderr, "array size exceeds upper bound\n");
      return false;
    }
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      cdr_serialize_key_ipm_interfaces__srv__MapPoint_Response(
        &array_ptr[i], cdr);
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
size_t get_serialized_size_key_ipm_interfaces__srv__MapPoint_Event(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _MapPoint_Event__ros_msg_type * ros_message = static_cast<const _MapPoint_Event__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;

  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Field name: info
  current_alignment += get_serialized_size_key_service_msgs__msg__ServiceEventInfo(
    &(ros_message->info), current_alignment);

  // Field name: request
  {
    size_t array_size = ros_message->request.size;
    auto array_ptr = ros_message->request.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_ipm_interfaces__srv__MapPoint_Request(
        &array_ptr[index], current_alignment);
    }
  }

  // Field name: response
  {
    size_t array_size = ros_message->response.size;
    auto array_ptr = ros_message->response.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += get_serialized_size_key_ipm_interfaces__srv__MapPoint_Response(
        &array_ptr[index], current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_ipm_interfaces
size_t max_serialized_size_key_ipm_interfaces__srv__MapPoint_Event(
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
  // Field name: info
  {
    size_t array_size = 1;
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_service_msgs__msg__ServiceEventInfo(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: request
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_ipm_interfaces__srv__MapPoint_Request(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  // Field name: response
  {
    size_t array_size = 1;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size;
      inner_size =
        max_serialized_size_key_ipm_interfaces__srv__MapPoint_Response(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = ipm_interfaces__srv__MapPoint_Event;
    is_plain =
      (
      offsetof(DataType, response) +
      last_member_size
      ) == ret_val;
  }
  return ret_val;
}


static bool _MapPoint_Event__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const ipm_interfaces__srv__MapPoint_Event * ros_message = static_cast<const ipm_interfaces__srv__MapPoint_Event *>(untyped_ros_message);
  (void)ros_message;
  return cdr_serialize_ipm_interfaces__srv__MapPoint_Event(ros_message, cdr);
}

static bool _MapPoint_Event__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  ipm_interfaces__srv__MapPoint_Event * ros_message = static_cast<ipm_interfaces__srv__MapPoint_Event *>(untyped_ros_message);
  (void)ros_message;
  return cdr_deserialize_ipm_interfaces__srv__MapPoint_Event(cdr, ros_message);
}

static uint32_t _MapPoint_Event__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_ipm_interfaces__srv__MapPoint_Event(
      untyped_ros_message, 0));
}

static size_t _MapPoint_Event__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_ipm_interfaces__srv__MapPoint_Event(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_MapPoint_Event = {
  "ipm_interfaces::srv",
  "MapPoint_Event",
  _MapPoint_Event__cdr_serialize,
  _MapPoint_Event__cdr_deserialize,
  _MapPoint_Event__get_serialized_size,
  _MapPoint_Event__max_serialized_size,
  nullptr
};

static rosidl_message_type_support_t _MapPoint_Event__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_MapPoint_Event,
  get_message_typesupport_handle_function,
  &ipm_interfaces__srv__MapPoint_Event__get_type_hash,
  &ipm_interfaces__srv__MapPoint_Event__get_type_description,
  &ipm_interfaces__srv__MapPoint_Event__get_type_description_sources,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ipm_interfaces, srv, MapPoint_Event)() {
  return &_MapPoint_Event__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "ipm_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "ipm_interfaces/srv/map_point.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t MapPoint__callbacks = {
  "ipm_interfaces::srv",
  "MapPoint",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ipm_interfaces, srv, MapPoint_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ipm_interfaces, srv, MapPoint_Response)(),
};

static rosidl_service_type_support_t MapPoint__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &MapPoint__callbacks,
  get_service_typesupport_handle_function,
  &_MapPoint_Request__type_support,
  &_MapPoint_Response__type_support,
  &_MapPoint_Event__type_support,
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_CREATE_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    ipm_interfaces,
    srv,
    MapPoint
  ),
  ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_DESTROY_EVENT_MESSAGE_SYMBOL_NAME(
    rosidl_typesupport_c,
    ipm_interfaces,
    srv,
    MapPoint
  ),
  &ipm_interfaces__srv__MapPoint__get_type_hash,
  &ipm_interfaces__srv__MapPoint__get_type_description,
  &ipm_interfaces__srv__MapPoint__get_type_description_sources,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, ipm_interfaces, srv, MapPoint)() {
  return &MapPoint__handle;
}

#if defined(__cplusplus)
}
#endif
