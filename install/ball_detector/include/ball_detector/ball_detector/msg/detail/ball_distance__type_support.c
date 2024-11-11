// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ball_detector:msg/BallDistance.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ball_detector/msg/detail/ball_distance__rosidl_typesupport_introspection_c.h"
#include "ball_detector/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ball_detector/msg/detail/ball_distance__functions.h"
#include "ball_detector/msg/detail/ball_distance__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ball_detector__msg__BallDistance__rosidl_typesupport_introspection_c__BallDistance_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ball_detector__msg__BallDistance__init(message_memory);
}

void ball_detector__msg__BallDistance__rosidl_typesupport_introspection_c__BallDistance_fini_function(void * message_memory)
{
  ball_detector__msg__BallDistance__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ball_detector__msg__BallDistance__rosidl_typesupport_introspection_c__BallDistance_message_member_array[2] = {
  {
    "ball_ada_cok",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ball_detector__msg__BallDistance, ball_ada_cok),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "jaraknya_jing",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ball_detector__msg__BallDistance, jaraknya_jing),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ball_detector__msg__BallDistance__rosidl_typesupport_introspection_c__BallDistance_message_members = {
  "ball_detector__msg",  // message namespace
  "BallDistance",  // message name
  2,  // number of fields
  sizeof(ball_detector__msg__BallDistance),
  false,  // has_any_key_member_
  ball_detector__msg__BallDistance__rosidl_typesupport_introspection_c__BallDistance_message_member_array,  // message members
  ball_detector__msg__BallDistance__rosidl_typesupport_introspection_c__BallDistance_init_function,  // function to initialize message memory (memory has to be allocated)
  ball_detector__msg__BallDistance__rosidl_typesupport_introspection_c__BallDistance_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ball_detector__msg__BallDistance__rosidl_typesupport_introspection_c__BallDistance_message_type_support_handle = {
  0,
  &ball_detector__msg__BallDistance__rosidl_typesupport_introspection_c__BallDistance_message_members,
  get_message_typesupport_handle_function,
  &ball_detector__msg__BallDistance__get_type_hash,
  &ball_detector__msg__BallDistance__get_type_description,
  &ball_detector__msg__BallDistance__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ball_detector
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ball_detector, msg, BallDistance)() {
  if (!ball_detector__msg__BallDistance__rosidl_typesupport_introspection_c__BallDistance_message_type_support_handle.typesupport_identifier) {
    ball_detector__msg__BallDistance__rosidl_typesupport_introspection_c__BallDistance_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ball_detector__msg__BallDistance__rosidl_typesupport_introspection_c__BallDistance_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
