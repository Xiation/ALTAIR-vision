// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ball_detect:msg/BallInfo.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ball_detect/msg/detail/ball_info__rosidl_typesupport_introspection_c.h"
#include "ball_detect/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ball_detect/msg/detail/ball_info__functions.h"
#include "ball_detect/msg/detail/ball_info__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ball_detect__msg__BallInfo__rosidl_typesupport_introspection_c__BallInfo_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ball_detect__msg__BallInfo__init(message_memory);
}

void ball_detect__msg__BallInfo__rosidl_typesupport_introspection_c__BallInfo_fini_function(void * message_memory)
{
  ball_detect__msg__BallInfo__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ball_detect__msg__BallInfo__rosidl_typesupport_introspection_c__BallInfo_message_member_array[6] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ball_detect__msg__BallInfo, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "distance",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ball_detect__msg__BallInfo, distance),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "x_pixel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ball_detect__msg__BallInfo, x_pixel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "y_pixel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ball_detect__msg__BallInfo, y_pixel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "radius_pixel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ball_detect__msg__BallInfo, radius_pixel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "confidence",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ball_detect__msg__BallInfo, confidence),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ball_detect__msg__BallInfo__rosidl_typesupport_introspection_c__BallInfo_message_members = {
  "ball_detect__msg",  // message namespace
  "BallInfo",  // message name
  6,  // number of fields
  sizeof(ball_detect__msg__BallInfo),
  false,  // has_any_key_member_
  ball_detect__msg__BallInfo__rosidl_typesupport_introspection_c__BallInfo_message_member_array,  // message members
  ball_detect__msg__BallInfo__rosidl_typesupport_introspection_c__BallInfo_init_function,  // function to initialize message memory (memory has to be allocated)
  ball_detect__msg__BallInfo__rosidl_typesupport_introspection_c__BallInfo_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ball_detect__msg__BallInfo__rosidl_typesupport_introspection_c__BallInfo_message_type_support_handle = {
  0,
  &ball_detect__msg__BallInfo__rosidl_typesupport_introspection_c__BallInfo_message_members,
  get_message_typesupport_handle_function,
  &ball_detect__msg__BallInfo__get_type_hash,
  &ball_detect__msg__BallInfo__get_type_description,
  &ball_detect__msg__BallInfo__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ball_detect
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ball_detect, msg, BallInfo)() {
  ball_detect__msg__BallInfo__rosidl_typesupport_introspection_c__BallInfo_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!ball_detect__msg__BallInfo__rosidl_typesupport_introspection_c__BallInfo_message_type_support_handle.typesupport_identifier) {
    ball_detect__msg__BallInfo__rosidl_typesupport_introspection_c__BallInfo_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ball_detect__msg__BallInfo__rosidl_typesupport_introspection_c__BallInfo_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
