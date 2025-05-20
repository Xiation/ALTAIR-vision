// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ball_detect:msg/BallInfo.idl
// generated code does not contain a copyright notice
#include "ball_detect/msg/detail/ball_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
ball_detect__msg__BallInfo__init(ball_detect__msg__BallInfo * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    ball_detect__msg__BallInfo__fini(msg);
    return false;
  }
  // distance
  // x_pixel
  // y_pixel
  // radius_pixel
  // confidence
  return true;
}

void
ball_detect__msg__BallInfo__fini(ball_detect__msg__BallInfo * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // distance
  // x_pixel
  // y_pixel
  // radius_pixel
  // confidence
}

bool
ball_detect__msg__BallInfo__are_equal(const ball_detect__msg__BallInfo * lhs, const ball_detect__msg__BallInfo * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // distance
  if (lhs->distance != rhs->distance) {
    return false;
  }
  // x_pixel
  if (lhs->x_pixel != rhs->x_pixel) {
    return false;
  }
  // y_pixel
  if (lhs->y_pixel != rhs->y_pixel) {
    return false;
  }
  // radius_pixel
  if (lhs->radius_pixel != rhs->radius_pixel) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  return true;
}

bool
ball_detect__msg__BallInfo__copy(
  const ball_detect__msg__BallInfo * input,
  ball_detect__msg__BallInfo * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // distance
  output->distance = input->distance;
  // x_pixel
  output->x_pixel = input->x_pixel;
  // y_pixel
  output->y_pixel = input->y_pixel;
  // radius_pixel
  output->radius_pixel = input->radius_pixel;
  // confidence
  output->confidence = input->confidence;
  return true;
}

ball_detect__msg__BallInfo *
ball_detect__msg__BallInfo__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_detect__msg__BallInfo * msg = (ball_detect__msg__BallInfo *)allocator.allocate(sizeof(ball_detect__msg__BallInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ball_detect__msg__BallInfo));
  bool success = ball_detect__msg__BallInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ball_detect__msg__BallInfo__destroy(ball_detect__msg__BallInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ball_detect__msg__BallInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ball_detect__msg__BallInfo__Sequence__init(ball_detect__msg__BallInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_detect__msg__BallInfo * data = NULL;

  if (size) {
    data = (ball_detect__msg__BallInfo *)allocator.zero_allocate(size, sizeof(ball_detect__msg__BallInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ball_detect__msg__BallInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ball_detect__msg__BallInfo__fini(&data[i - 1]);
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
ball_detect__msg__BallInfo__Sequence__fini(ball_detect__msg__BallInfo__Sequence * array)
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
      ball_detect__msg__BallInfo__fini(&array->data[i]);
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

ball_detect__msg__BallInfo__Sequence *
ball_detect__msg__BallInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_detect__msg__BallInfo__Sequence * array = (ball_detect__msg__BallInfo__Sequence *)allocator.allocate(sizeof(ball_detect__msg__BallInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ball_detect__msg__BallInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ball_detect__msg__BallInfo__Sequence__destroy(ball_detect__msg__BallInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ball_detect__msg__BallInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ball_detect__msg__BallInfo__Sequence__are_equal(const ball_detect__msg__BallInfo__Sequence * lhs, const ball_detect__msg__BallInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ball_detect__msg__BallInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ball_detect__msg__BallInfo__Sequence__copy(
  const ball_detect__msg__BallInfo__Sequence * input,
  ball_detect__msg__BallInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ball_detect__msg__BallInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ball_detect__msg__BallInfo * data =
      (ball_detect__msg__BallInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ball_detect__msg__BallInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ball_detect__msg__BallInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ball_detect__msg__BallInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
