// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from ipm_interfaces:srv/MapPoint.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "ipm_interfaces/srv/detail/map_point__rosidl_typesupport_introspection_c.h"
#include "ipm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "ipm_interfaces/srv/detail/map_point__functions.h"
#include "ipm_interfaces/srv/detail/map_point__struct.h"


// Include directives for member types
// Member `plane`
#include "shape_msgs/msg/plane.h"
// Member `plane`
#include "shape_msgs/msg/detail/plane__rosidl_typesupport_introspection_c.h"
// Member `point`
#include "vision_msgs/msg/point2_d.h"
// Member `point`
#include "vision_msgs/msg/detail/point2_d__rosidl_typesupport_introspection_c.h"
// Member `time`
#include "builtin_interfaces/msg/time.h"
// Member `time`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"
// Member `plane_frame_id`
// Member `output_frame_id`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ipm_interfaces__srv__MapPoint_Request__rosidl_typesupport_introspection_c__MapPoint_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ipm_interfaces__srv__MapPoint_Request__init(message_memory);
}

void ipm_interfaces__srv__MapPoint_Request__rosidl_typesupport_introspection_c__MapPoint_Request_fini_function(void * message_memory)
{
  ipm_interfaces__srv__MapPoint_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ipm_interfaces__srv__MapPoint_Request__rosidl_typesupport_introspection_c__MapPoint_Request_message_member_array[5] = {
  {
    "plane",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ipm_interfaces__srv__MapPoint_Request, plane),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ipm_interfaces__srv__MapPoint_Request, point),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "time",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ipm_interfaces__srv__MapPoint_Request, time),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "plane_frame_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ipm_interfaces__srv__MapPoint_Request, plane_frame_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "output_frame_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ipm_interfaces__srv__MapPoint_Request, output_frame_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ipm_interfaces__srv__MapPoint_Request__rosidl_typesupport_introspection_c__MapPoint_Request_message_members = {
  "ipm_interfaces__srv",  // message namespace
  "MapPoint_Request",  // message name
  5,  // number of fields
  sizeof(ipm_interfaces__srv__MapPoint_Request),
  false,  // has_any_key_member_
  ipm_interfaces__srv__MapPoint_Request__rosidl_typesupport_introspection_c__MapPoint_Request_message_member_array,  // message members
  ipm_interfaces__srv__MapPoint_Request__rosidl_typesupport_introspection_c__MapPoint_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ipm_interfaces__srv__MapPoint_Request__rosidl_typesupport_introspection_c__MapPoint_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ipm_interfaces__srv__MapPoint_Request__rosidl_typesupport_introspection_c__MapPoint_Request_message_type_support_handle = {
  0,
  &ipm_interfaces__srv__MapPoint_Request__rosidl_typesupport_introspection_c__MapPoint_Request_message_members,
  get_message_typesupport_handle_function,
  &ipm_interfaces__srv__MapPoint_Request__get_type_hash,
  &ipm_interfaces__srv__MapPoint_Request__get_type_description,
  &ipm_interfaces__srv__MapPoint_Request__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ipm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ipm_interfaces, srv, MapPoint_Request)() {
  ipm_interfaces__srv__MapPoint_Request__rosidl_typesupport_introspection_c__MapPoint_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, shape_msgs, msg, Plane)();
  ipm_interfaces__srv__MapPoint_Request__rosidl_typesupport_introspection_c__MapPoint_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, vision_msgs, msg, Point2D)();
  ipm_interfaces__srv__MapPoint_Request__rosidl_typesupport_introspection_c__MapPoint_Request_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!ipm_interfaces__srv__MapPoint_Request__rosidl_typesupport_introspection_c__MapPoint_Request_message_type_support_handle.typesupport_identifier) {
    ipm_interfaces__srv__MapPoint_Request__rosidl_typesupport_introspection_c__MapPoint_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ipm_interfaces__srv__MapPoint_Request__rosidl_typesupport_introspection_c__MapPoint_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "ipm_interfaces/srv/detail/map_point__rosidl_typesupport_introspection_c.h"
// already included above
// #include "ipm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "ipm_interfaces/srv/detail/map_point__functions.h"
// already included above
// #include "ipm_interfaces/srv/detail/map_point__struct.h"


// Include directives for member types
// Member `point`
#include "geometry_msgs/msg/point_stamped.h"
// Member `point`
#include "geometry_msgs/msg/detail/point_stamped__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ipm_interfaces__srv__MapPoint_Response__rosidl_typesupport_introspection_c__MapPoint_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ipm_interfaces__srv__MapPoint_Response__init(message_memory);
}

void ipm_interfaces__srv__MapPoint_Response__rosidl_typesupport_introspection_c__MapPoint_Response_fini_function(void * message_memory)
{
  ipm_interfaces__srv__MapPoint_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ipm_interfaces__srv__MapPoint_Response__rosidl_typesupport_introspection_c__MapPoint_Response_message_member_array[2] = {
  {
    "point",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ipm_interfaces__srv__MapPoint_Response, point),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ipm_interfaces__srv__MapPoint_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ipm_interfaces__srv__MapPoint_Response__rosidl_typesupport_introspection_c__MapPoint_Response_message_members = {
  "ipm_interfaces__srv",  // message namespace
  "MapPoint_Response",  // message name
  2,  // number of fields
  sizeof(ipm_interfaces__srv__MapPoint_Response),
  false,  // has_any_key_member_
  ipm_interfaces__srv__MapPoint_Response__rosidl_typesupport_introspection_c__MapPoint_Response_message_member_array,  // message members
  ipm_interfaces__srv__MapPoint_Response__rosidl_typesupport_introspection_c__MapPoint_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ipm_interfaces__srv__MapPoint_Response__rosidl_typesupport_introspection_c__MapPoint_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ipm_interfaces__srv__MapPoint_Response__rosidl_typesupport_introspection_c__MapPoint_Response_message_type_support_handle = {
  0,
  &ipm_interfaces__srv__MapPoint_Response__rosidl_typesupport_introspection_c__MapPoint_Response_message_members,
  get_message_typesupport_handle_function,
  &ipm_interfaces__srv__MapPoint_Response__get_type_hash,
  &ipm_interfaces__srv__MapPoint_Response__get_type_description,
  &ipm_interfaces__srv__MapPoint_Response__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ipm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ipm_interfaces, srv, MapPoint_Response)() {
  ipm_interfaces__srv__MapPoint_Response__rosidl_typesupport_introspection_c__MapPoint_Response_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, PointStamped)();
  if (!ipm_interfaces__srv__MapPoint_Response__rosidl_typesupport_introspection_c__MapPoint_Response_message_type_support_handle.typesupport_identifier) {
    ipm_interfaces__srv__MapPoint_Response__rosidl_typesupport_introspection_c__MapPoint_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ipm_interfaces__srv__MapPoint_Response__rosidl_typesupport_introspection_c__MapPoint_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "ipm_interfaces/srv/detail/map_point__rosidl_typesupport_introspection_c.h"
// already included above
// #include "ipm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "ipm_interfaces/srv/detail/map_point__functions.h"
// already included above
// #include "ipm_interfaces/srv/detail/map_point__struct.h"


// Include directives for member types
// Member `info`
#include "service_msgs/msg/service_event_info.h"
// Member `info`
#include "service_msgs/msg/detail/service_event_info__rosidl_typesupport_introspection_c.h"
// Member `request`
// Member `response`
#include "ipm_interfaces/srv/map_point.h"
// Member `request`
// Member `response`
// already included above
// #include "ipm_interfaces/srv/detail/map_point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__MapPoint_Event_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  ipm_interfaces__srv__MapPoint_Event__init(message_memory);
}

void ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__MapPoint_Event_fini_function(void * message_memory)
{
  ipm_interfaces__srv__MapPoint_Event__fini(message_memory);
}

size_t ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__size_function__MapPoint_Event__request(
  const void * untyped_member)
{
  const ipm_interfaces__srv__MapPoint_Request__Sequence * member =
    (const ipm_interfaces__srv__MapPoint_Request__Sequence *)(untyped_member);
  return member->size;
}

const void * ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__get_const_function__MapPoint_Event__request(
  const void * untyped_member, size_t index)
{
  const ipm_interfaces__srv__MapPoint_Request__Sequence * member =
    (const ipm_interfaces__srv__MapPoint_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__get_function__MapPoint_Event__request(
  void * untyped_member, size_t index)
{
  ipm_interfaces__srv__MapPoint_Request__Sequence * member =
    (ipm_interfaces__srv__MapPoint_Request__Sequence *)(untyped_member);
  return &member->data[index];
}

void ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__fetch_function__MapPoint_Event__request(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const ipm_interfaces__srv__MapPoint_Request * item =
    ((const ipm_interfaces__srv__MapPoint_Request *)
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__get_const_function__MapPoint_Event__request(untyped_member, index));
  ipm_interfaces__srv__MapPoint_Request * value =
    (ipm_interfaces__srv__MapPoint_Request *)(untyped_value);
  *value = *item;
}

void ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__assign_function__MapPoint_Event__request(
  void * untyped_member, size_t index, const void * untyped_value)
{
  ipm_interfaces__srv__MapPoint_Request * item =
    ((ipm_interfaces__srv__MapPoint_Request *)
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__get_function__MapPoint_Event__request(untyped_member, index));
  const ipm_interfaces__srv__MapPoint_Request * value =
    (const ipm_interfaces__srv__MapPoint_Request *)(untyped_value);
  *item = *value;
}

bool ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__resize_function__MapPoint_Event__request(
  void * untyped_member, size_t size)
{
  ipm_interfaces__srv__MapPoint_Request__Sequence * member =
    (ipm_interfaces__srv__MapPoint_Request__Sequence *)(untyped_member);
  ipm_interfaces__srv__MapPoint_Request__Sequence__fini(member);
  return ipm_interfaces__srv__MapPoint_Request__Sequence__init(member, size);
}

size_t ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__size_function__MapPoint_Event__response(
  const void * untyped_member)
{
  const ipm_interfaces__srv__MapPoint_Response__Sequence * member =
    (const ipm_interfaces__srv__MapPoint_Response__Sequence *)(untyped_member);
  return member->size;
}

const void * ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__get_const_function__MapPoint_Event__response(
  const void * untyped_member, size_t index)
{
  const ipm_interfaces__srv__MapPoint_Response__Sequence * member =
    (const ipm_interfaces__srv__MapPoint_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void * ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__get_function__MapPoint_Event__response(
  void * untyped_member, size_t index)
{
  ipm_interfaces__srv__MapPoint_Response__Sequence * member =
    (ipm_interfaces__srv__MapPoint_Response__Sequence *)(untyped_member);
  return &member->data[index];
}

void ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__fetch_function__MapPoint_Event__response(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const ipm_interfaces__srv__MapPoint_Response * item =
    ((const ipm_interfaces__srv__MapPoint_Response *)
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__get_const_function__MapPoint_Event__response(untyped_member, index));
  ipm_interfaces__srv__MapPoint_Response * value =
    (ipm_interfaces__srv__MapPoint_Response *)(untyped_value);
  *value = *item;
}

void ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__assign_function__MapPoint_Event__response(
  void * untyped_member, size_t index, const void * untyped_value)
{
  ipm_interfaces__srv__MapPoint_Response * item =
    ((ipm_interfaces__srv__MapPoint_Response *)
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__get_function__MapPoint_Event__response(untyped_member, index));
  const ipm_interfaces__srv__MapPoint_Response * value =
    (const ipm_interfaces__srv__MapPoint_Response *)(untyped_value);
  *item = *value;
}

bool ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__resize_function__MapPoint_Event__response(
  void * untyped_member, size_t size)
{
  ipm_interfaces__srv__MapPoint_Response__Sequence * member =
    (ipm_interfaces__srv__MapPoint_Response__Sequence *)(untyped_member);
  ipm_interfaces__srv__MapPoint_Response__Sequence__fini(member);
  return ipm_interfaces__srv__MapPoint_Response__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__MapPoint_Event_message_member_array[3] = {
  {
    "info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(ipm_interfaces__srv__MapPoint_Event, info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "request",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(ipm_interfaces__srv__MapPoint_Event, request),  // bytes offset in struct
    NULL,  // default value
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__size_function__MapPoint_Event__request,  // size() function pointer
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__get_const_function__MapPoint_Event__request,  // get_const(index) function pointer
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__get_function__MapPoint_Event__request,  // get(index) function pointer
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__fetch_function__MapPoint_Event__request,  // fetch(index, &value) function pointer
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__assign_function__MapPoint_Event__request,  // assign(index, value) function pointer
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__resize_function__MapPoint_Event__request  // resize(index) function pointer
  },
  {
    "response",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is key
    true,  // is array
    1,  // array size
    true,  // is upper bound
    offsetof(ipm_interfaces__srv__MapPoint_Event, response),  // bytes offset in struct
    NULL,  // default value
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__size_function__MapPoint_Event__response,  // size() function pointer
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__get_const_function__MapPoint_Event__response,  // get_const(index) function pointer
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__get_function__MapPoint_Event__response,  // get(index) function pointer
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__fetch_function__MapPoint_Event__response,  // fetch(index, &value) function pointer
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__assign_function__MapPoint_Event__response,  // assign(index, value) function pointer
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__resize_function__MapPoint_Event__response  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__MapPoint_Event_message_members = {
  "ipm_interfaces__srv",  // message namespace
  "MapPoint_Event",  // message name
  3,  // number of fields
  sizeof(ipm_interfaces__srv__MapPoint_Event),
  false,  // has_any_key_member_
  ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__MapPoint_Event_message_member_array,  // message members
  ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__MapPoint_Event_init_function,  // function to initialize message memory (memory has to be allocated)
  ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__MapPoint_Event_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__MapPoint_Event_message_type_support_handle = {
  0,
  &ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__MapPoint_Event_message_members,
  get_message_typesupport_handle_function,
  &ipm_interfaces__srv__MapPoint_Event__get_type_hash,
  &ipm_interfaces__srv__MapPoint_Event__get_type_description,
  &ipm_interfaces__srv__MapPoint_Event__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ipm_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ipm_interfaces, srv, MapPoint_Event)() {
  ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__MapPoint_Event_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, service_msgs, msg, ServiceEventInfo)();
  ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__MapPoint_Event_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ipm_interfaces, srv, MapPoint_Request)();
  ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__MapPoint_Event_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ipm_interfaces, srv, MapPoint_Response)();
  if (!ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__MapPoint_Event_message_type_support_handle.typesupport_identifier) {
    ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__MapPoint_Event_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__MapPoint_Event_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "ipm_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "ipm_interfaces/srv/detail/map_point__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers ipm_interfaces__srv__detail__map_point__rosidl_typesupport_introspection_c__MapPoint_service_members = {
  "ipm_interfaces__srv",  // service namespace
  "MapPoint",  // service name
  // the following fields are initialized below on first access
  NULL,  // request message
  // ipm_interfaces__srv__detail__map_point__rosidl_typesupport_introspection_c__MapPoint_Request_message_type_support_handle,
  NULL,  // response message
  // ipm_interfaces__srv__detail__map_point__rosidl_typesupport_introspection_c__MapPoint_Response_message_type_support_handle
  NULL  // event_message
  // ipm_interfaces__srv__detail__map_point__rosidl_typesupport_introspection_c__MapPoint_Response_message_type_support_handle
};


static rosidl_service_type_support_t ipm_interfaces__srv__detail__map_point__rosidl_typesupport_introspection_c__MapPoint_service_type_support_handle = {
  0,
  &ipm_interfaces__srv__detail__map_point__rosidl_typesupport_introspection_c__MapPoint_service_members,
  get_service_typesupport_handle_function,
  &ipm_interfaces__srv__MapPoint_Request__rosidl_typesupport_introspection_c__MapPoint_Request_message_type_support_handle,
  &ipm_interfaces__srv__MapPoint_Response__rosidl_typesupport_introspection_c__MapPoint_Response_message_type_support_handle,
  &ipm_interfaces__srv__MapPoint_Event__rosidl_typesupport_introspection_c__MapPoint_Event_message_type_support_handle,
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

// Forward declaration of message type support functions for service members
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ipm_interfaces, srv, MapPoint_Request)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ipm_interfaces, srv, MapPoint_Response)(void);

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ipm_interfaces, srv, MapPoint_Event)(void);

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_ipm_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ipm_interfaces, srv, MapPoint)(void) {
  if (!ipm_interfaces__srv__detail__map_point__rosidl_typesupport_introspection_c__MapPoint_service_type_support_handle.typesupport_identifier) {
    ipm_interfaces__srv__detail__map_point__rosidl_typesupport_introspection_c__MapPoint_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)ipm_interfaces__srv__detail__map_point__rosidl_typesupport_introspection_c__MapPoint_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ipm_interfaces, srv, MapPoint_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ipm_interfaces, srv, MapPoint_Response)()->data;
  }
  if (!service_members->event_members_) {
    service_members->event_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, ipm_interfaces, srv, MapPoint_Event)()->data;
  }

  return &ipm_interfaces__srv__detail__map_point__rosidl_typesupport_introspection_c__MapPoint_service_type_support_handle;
}
