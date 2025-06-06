// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ipm_interfaces:srv/MapPointCloud2.idl
// generated code does not contain a copyright notice
#include "ipm_interfaces/srv/detail/map_point_cloud2__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `plane`
#include "shape_msgs/msg/detail/plane__functions.h"
// Member `points`
#include "sensor_msgs/msg/detail/point_cloud2__functions.h"
// Member `plane_frame_id`
// Member `output_frame_id`
#include "rosidl_runtime_c/string_functions.h"

bool
ipm_interfaces__srv__MapPointCloud2_Request__init(ipm_interfaces__srv__MapPointCloud2_Request * msg)
{
  if (!msg) {
    return false;
  }
  // plane
  if (!shape_msgs__msg__Plane__init(&msg->plane)) {
    ipm_interfaces__srv__MapPointCloud2_Request__fini(msg);
    return false;
  }
  // points
  if (!sensor_msgs__msg__PointCloud2__init(&msg->points)) {
    ipm_interfaces__srv__MapPointCloud2_Request__fini(msg);
    return false;
  }
  // plane_frame_id
  if (!rosidl_runtime_c__String__init(&msg->plane_frame_id)) {
    ipm_interfaces__srv__MapPointCloud2_Request__fini(msg);
    return false;
  }
  // output_frame_id
  if (!rosidl_runtime_c__String__init(&msg->output_frame_id)) {
    ipm_interfaces__srv__MapPointCloud2_Request__fini(msg);
    return false;
  }
  return true;
}

void
ipm_interfaces__srv__MapPointCloud2_Request__fini(ipm_interfaces__srv__MapPointCloud2_Request * msg)
{
  if (!msg) {
    return;
  }
  // plane
  shape_msgs__msg__Plane__fini(&msg->plane);
  // points
  sensor_msgs__msg__PointCloud2__fini(&msg->points);
  // plane_frame_id
  rosidl_runtime_c__String__fini(&msg->plane_frame_id);
  // output_frame_id
  rosidl_runtime_c__String__fini(&msg->output_frame_id);
}

bool
ipm_interfaces__srv__MapPointCloud2_Request__are_equal(const ipm_interfaces__srv__MapPointCloud2_Request * lhs, const ipm_interfaces__srv__MapPointCloud2_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // plane
  if (!shape_msgs__msg__Plane__are_equal(
      &(lhs->plane), &(rhs->plane)))
  {
    return false;
  }
  // points
  if (!sensor_msgs__msg__PointCloud2__are_equal(
      &(lhs->points), &(rhs->points)))
  {
    return false;
  }
  // plane_frame_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->plane_frame_id), &(rhs->plane_frame_id)))
  {
    return false;
  }
  // output_frame_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->output_frame_id), &(rhs->output_frame_id)))
  {
    return false;
  }
  return true;
}

bool
ipm_interfaces__srv__MapPointCloud2_Request__copy(
  const ipm_interfaces__srv__MapPointCloud2_Request * input,
  ipm_interfaces__srv__MapPointCloud2_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // plane
  if (!shape_msgs__msg__Plane__copy(
      &(input->plane), &(output->plane)))
  {
    return false;
  }
  // points
  if (!sensor_msgs__msg__PointCloud2__copy(
      &(input->points), &(output->points)))
  {
    return false;
  }
  // plane_frame_id
  if (!rosidl_runtime_c__String__copy(
      &(input->plane_frame_id), &(output->plane_frame_id)))
  {
    return false;
  }
  // output_frame_id
  if (!rosidl_runtime_c__String__copy(
      &(input->output_frame_id), &(output->output_frame_id)))
  {
    return false;
  }
  return true;
}

ipm_interfaces__srv__MapPointCloud2_Request *
ipm_interfaces__srv__MapPointCloud2_Request__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ipm_interfaces__srv__MapPointCloud2_Request * msg = (ipm_interfaces__srv__MapPointCloud2_Request *)allocator.allocate(sizeof(ipm_interfaces__srv__MapPointCloud2_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ipm_interfaces__srv__MapPointCloud2_Request));
  bool success = ipm_interfaces__srv__MapPointCloud2_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ipm_interfaces__srv__MapPointCloud2_Request__destroy(ipm_interfaces__srv__MapPointCloud2_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ipm_interfaces__srv__MapPointCloud2_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ipm_interfaces__srv__MapPointCloud2_Request__Sequence__init(ipm_interfaces__srv__MapPointCloud2_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ipm_interfaces__srv__MapPointCloud2_Request * data = NULL;

  if (size) {
    data = (ipm_interfaces__srv__MapPointCloud2_Request *)allocator.zero_allocate(size, sizeof(ipm_interfaces__srv__MapPointCloud2_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ipm_interfaces__srv__MapPointCloud2_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ipm_interfaces__srv__MapPointCloud2_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ipm_interfaces__srv__MapPointCloud2_Request__Sequence__fini(ipm_interfaces__srv__MapPointCloud2_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ipm_interfaces__srv__MapPointCloud2_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ipm_interfaces__srv__MapPointCloud2_Request__Sequence *
ipm_interfaces__srv__MapPointCloud2_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ipm_interfaces__srv__MapPointCloud2_Request__Sequence * array = (ipm_interfaces__srv__MapPointCloud2_Request__Sequence *)allocator.allocate(sizeof(ipm_interfaces__srv__MapPointCloud2_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ipm_interfaces__srv__MapPointCloud2_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ipm_interfaces__srv__MapPointCloud2_Request__Sequence__destroy(ipm_interfaces__srv__MapPointCloud2_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ipm_interfaces__srv__MapPointCloud2_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ipm_interfaces__srv__MapPointCloud2_Request__Sequence__are_equal(const ipm_interfaces__srv__MapPointCloud2_Request__Sequence * lhs, const ipm_interfaces__srv__MapPointCloud2_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ipm_interfaces__srv__MapPointCloud2_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ipm_interfaces__srv__MapPointCloud2_Request__Sequence__copy(
  const ipm_interfaces__srv__MapPointCloud2_Request__Sequence * input,
  ipm_interfaces__srv__MapPointCloud2_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ipm_interfaces__srv__MapPointCloud2_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ipm_interfaces__srv__MapPointCloud2_Request * data =
      (ipm_interfaces__srv__MapPointCloud2_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ipm_interfaces__srv__MapPointCloud2_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ipm_interfaces__srv__MapPointCloud2_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ipm_interfaces__srv__MapPointCloud2_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `points`
// already included above
// #include "sensor_msgs/msg/detail/point_cloud2__functions.h"

bool
ipm_interfaces__srv__MapPointCloud2_Response__init(ipm_interfaces__srv__MapPointCloud2_Response * msg)
{
  if (!msg) {
    return false;
  }
  // points
  if (!sensor_msgs__msg__PointCloud2__init(&msg->points)) {
    ipm_interfaces__srv__MapPointCloud2_Response__fini(msg);
    return false;
  }
  // result
  return true;
}

void
ipm_interfaces__srv__MapPointCloud2_Response__fini(ipm_interfaces__srv__MapPointCloud2_Response * msg)
{
  if (!msg) {
    return;
  }
  // points
  sensor_msgs__msg__PointCloud2__fini(&msg->points);
  // result
}

bool
ipm_interfaces__srv__MapPointCloud2_Response__are_equal(const ipm_interfaces__srv__MapPointCloud2_Response * lhs, const ipm_interfaces__srv__MapPointCloud2_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // points
  if (!sensor_msgs__msg__PointCloud2__are_equal(
      &(lhs->points), &(rhs->points)))
  {
    return false;
  }
  // result
  if (lhs->result != rhs->result) {
    return false;
  }
  return true;
}

bool
ipm_interfaces__srv__MapPointCloud2_Response__copy(
  const ipm_interfaces__srv__MapPointCloud2_Response * input,
  ipm_interfaces__srv__MapPointCloud2_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // points
  if (!sensor_msgs__msg__PointCloud2__copy(
      &(input->points), &(output->points)))
  {
    return false;
  }
  // result
  output->result = input->result;
  return true;
}

ipm_interfaces__srv__MapPointCloud2_Response *
ipm_interfaces__srv__MapPointCloud2_Response__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ipm_interfaces__srv__MapPointCloud2_Response * msg = (ipm_interfaces__srv__MapPointCloud2_Response *)allocator.allocate(sizeof(ipm_interfaces__srv__MapPointCloud2_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ipm_interfaces__srv__MapPointCloud2_Response));
  bool success = ipm_interfaces__srv__MapPointCloud2_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ipm_interfaces__srv__MapPointCloud2_Response__destroy(ipm_interfaces__srv__MapPointCloud2_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ipm_interfaces__srv__MapPointCloud2_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ipm_interfaces__srv__MapPointCloud2_Response__Sequence__init(ipm_interfaces__srv__MapPointCloud2_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ipm_interfaces__srv__MapPointCloud2_Response * data = NULL;

  if (size) {
    data = (ipm_interfaces__srv__MapPointCloud2_Response *)allocator.zero_allocate(size, sizeof(ipm_interfaces__srv__MapPointCloud2_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ipm_interfaces__srv__MapPointCloud2_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ipm_interfaces__srv__MapPointCloud2_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ipm_interfaces__srv__MapPointCloud2_Response__Sequence__fini(ipm_interfaces__srv__MapPointCloud2_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ipm_interfaces__srv__MapPointCloud2_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ipm_interfaces__srv__MapPointCloud2_Response__Sequence *
ipm_interfaces__srv__MapPointCloud2_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ipm_interfaces__srv__MapPointCloud2_Response__Sequence * array = (ipm_interfaces__srv__MapPointCloud2_Response__Sequence *)allocator.allocate(sizeof(ipm_interfaces__srv__MapPointCloud2_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ipm_interfaces__srv__MapPointCloud2_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ipm_interfaces__srv__MapPointCloud2_Response__Sequence__destroy(ipm_interfaces__srv__MapPointCloud2_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ipm_interfaces__srv__MapPointCloud2_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ipm_interfaces__srv__MapPointCloud2_Response__Sequence__are_equal(const ipm_interfaces__srv__MapPointCloud2_Response__Sequence * lhs, const ipm_interfaces__srv__MapPointCloud2_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ipm_interfaces__srv__MapPointCloud2_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ipm_interfaces__srv__MapPointCloud2_Response__Sequence__copy(
  const ipm_interfaces__srv__MapPointCloud2_Response__Sequence * input,
  ipm_interfaces__srv__MapPointCloud2_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ipm_interfaces__srv__MapPointCloud2_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ipm_interfaces__srv__MapPointCloud2_Response * data =
      (ipm_interfaces__srv__MapPointCloud2_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ipm_interfaces__srv__MapPointCloud2_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ipm_interfaces__srv__MapPointCloud2_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ipm_interfaces__srv__MapPointCloud2_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `info`
#include "service_msgs/msg/detail/service_event_info__functions.h"
// Member `request`
// Member `response`
// already included above
// #include "ipm_interfaces/srv/detail/map_point_cloud2__functions.h"

bool
ipm_interfaces__srv__MapPointCloud2_Event__init(ipm_interfaces__srv__MapPointCloud2_Event * msg)
{
  if (!msg) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__init(&msg->info)) {
    ipm_interfaces__srv__MapPointCloud2_Event__fini(msg);
    return false;
  }
  // request
  if (!ipm_interfaces__srv__MapPointCloud2_Request__Sequence__init(&msg->request, 0)) {
    ipm_interfaces__srv__MapPointCloud2_Event__fini(msg);
    return false;
  }
  // response
  if (!ipm_interfaces__srv__MapPointCloud2_Response__Sequence__init(&msg->response, 0)) {
    ipm_interfaces__srv__MapPointCloud2_Event__fini(msg);
    return false;
  }
  return true;
}

void
ipm_interfaces__srv__MapPointCloud2_Event__fini(ipm_interfaces__srv__MapPointCloud2_Event * msg)
{
  if (!msg) {
    return;
  }
  // info
  service_msgs__msg__ServiceEventInfo__fini(&msg->info);
  // request
  ipm_interfaces__srv__MapPointCloud2_Request__Sequence__fini(&msg->request);
  // response
  ipm_interfaces__srv__MapPointCloud2_Response__Sequence__fini(&msg->response);
}

bool
ipm_interfaces__srv__MapPointCloud2_Event__are_equal(const ipm_interfaces__srv__MapPointCloud2_Event * lhs, const ipm_interfaces__srv__MapPointCloud2_Event * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  // request
  if (!ipm_interfaces__srv__MapPointCloud2_Request__Sequence__are_equal(
      &(lhs->request), &(rhs->request)))
  {
    return false;
  }
  // response
  if (!ipm_interfaces__srv__MapPointCloud2_Response__Sequence__are_equal(
      &(lhs->response), &(rhs->response)))
  {
    return false;
  }
  return true;
}

bool
ipm_interfaces__srv__MapPointCloud2_Event__copy(
  const ipm_interfaces__srv__MapPointCloud2_Event * input,
  ipm_interfaces__srv__MapPointCloud2_Event * output)
{
  if (!input || !output) {
    return false;
  }
  // info
  if (!service_msgs__msg__ServiceEventInfo__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  // request
  if (!ipm_interfaces__srv__MapPointCloud2_Request__Sequence__copy(
      &(input->request), &(output->request)))
  {
    return false;
  }
  // response
  if (!ipm_interfaces__srv__MapPointCloud2_Response__Sequence__copy(
      &(input->response), &(output->response)))
  {
    return false;
  }
  return true;
}

ipm_interfaces__srv__MapPointCloud2_Event *
ipm_interfaces__srv__MapPointCloud2_Event__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ipm_interfaces__srv__MapPointCloud2_Event * msg = (ipm_interfaces__srv__MapPointCloud2_Event *)allocator.allocate(sizeof(ipm_interfaces__srv__MapPointCloud2_Event), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ipm_interfaces__srv__MapPointCloud2_Event));
  bool success = ipm_interfaces__srv__MapPointCloud2_Event__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ipm_interfaces__srv__MapPointCloud2_Event__destroy(ipm_interfaces__srv__MapPointCloud2_Event * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ipm_interfaces__srv__MapPointCloud2_Event__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ipm_interfaces__srv__MapPointCloud2_Event__Sequence__init(ipm_interfaces__srv__MapPointCloud2_Event__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ipm_interfaces__srv__MapPointCloud2_Event * data = NULL;

  if (size) {
    data = (ipm_interfaces__srv__MapPointCloud2_Event *)allocator.zero_allocate(size, sizeof(ipm_interfaces__srv__MapPointCloud2_Event), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ipm_interfaces__srv__MapPointCloud2_Event__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ipm_interfaces__srv__MapPointCloud2_Event__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
ipm_interfaces__srv__MapPointCloud2_Event__Sequence__fini(ipm_interfaces__srv__MapPointCloud2_Event__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      ipm_interfaces__srv__MapPointCloud2_Event__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

ipm_interfaces__srv__MapPointCloud2_Event__Sequence *
ipm_interfaces__srv__MapPointCloud2_Event__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ipm_interfaces__srv__MapPointCloud2_Event__Sequence * array = (ipm_interfaces__srv__MapPointCloud2_Event__Sequence *)allocator.allocate(sizeof(ipm_interfaces__srv__MapPointCloud2_Event__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ipm_interfaces__srv__MapPointCloud2_Event__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ipm_interfaces__srv__MapPointCloud2_Event__Sequence__destroy(ipm_interfaces__srv__MapPointCloud2_Event__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ipm_interfaces__srv__MapPointCloud2_Event__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ipm_interfaces__srv__MapPointCloud2_Event__Sequence__are_equal(const ipm_interfaces__srv__MapPointCloud2_Event__Sequence * lhs, const ipm_interfaces__srv__MapPointCloud2_Event__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ipm_interfaces__srv__MapPointCloud2_Event__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ipm_interfaces__srv__MapPointCloud2_Event__Sequence__copy(
  const ipm_interfaces__srv__MapPointCloud2_Event__Sequence * input,
  ipm_interfaces__srv__MapPointCloud2_Event__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ipm_interfaces__srv__MapPointCloud2_Event);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ipm_interfaces__srv__MapPointCloud2_Event * data =
      (ipm_interfaces__srv__MapPointCloud2_Event *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ipm_interfaces__srv__MapPointCloud2_Event__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ipm_interfaces__srv__MapPointCloud2_Event__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ipm_interfaces__srv__MapPointCloud2_Event__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
