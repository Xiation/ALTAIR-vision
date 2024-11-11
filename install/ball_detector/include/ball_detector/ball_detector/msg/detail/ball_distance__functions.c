// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from ball_detector:msg/BallDistance.idl
// generated code does not contain a copyright notice
#include "ball_detector/msg/detail/ball_distance__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
ball_detector__msg__BallDistance__init(ball_detector__msg__BallDistance * msg)
{
  if (!msg) {
    return false;
  }
  // ball_ada_cok
  // jaraknya_jing
  return true;
}

void
ball_detector__msg__BallDistance__fini(ball_detector__msg__BallDistance * msg)
{
  if (!msg) {
    return;
  }
  // ball_ada_cok
  // jaraknya_jing
}

bool
ball_detector__msg__BallDistance__are_equal(const ball_detector__msg__BallDistance * lhs, const ball_detector__msg__BallDistance * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ball_ada_cok
  if (lhs->ball_ada_cok != rhs->ball_ada_cok) {
    return false;
  }
  // jaraknya_jing
  if (lhs->jaraknya_jing != rhs->jaraknya_jing) {
    return false;
  }
  return true;
}

bool
ball_detector__msg__BallDistance__copy(
  const ball_detector__msg__BallDistance * input,
  ball_detector__msg__BallDistance * output)
{
  if (!input || !output) {
    return false;
  }
  // ball_ada_cok
  output->ball_ada_cok = input->ball_ada_cok;
  // jaraknya_jing
  output->jaraknya_jing = input->jaraknya_jing;
  return true;
}

ball_detector__msg__BallDistance *
ball_detector__msg__BallDistance__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_detector__msg__BallDistance * msg = (ball_detector__msg__BallDistance *)allocator.allocate(sizeof(ball_detector__msg__BallDistance), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(ball_detector__msg__BallDistance));
  bool success = ball_detector__msg__BallDistance__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
ball_detector__msg__BallDistance__destroy(ball_detector__msg__BallDistance * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    ball_detector__msg__BallDistance__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
ball_detector__msg__BallDistance__Sequence__init(ball_detector__msg__BallDistance__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_detector__msg__BallDistance * data = NULL;

  if (size) {
    data = (ball_detector__msg__BallDistance *)allocator.zero_allocate(size, sizeof(ball_detector__msg__BallDistance), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = ball_detector__msg__BallDistance__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        ball_detector__msg__BallDistance__fini(&data[i - 1]);
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
ball_detector__msg__BallDistance__Sequence__fini(ball_detector__msg__BallDistance__Sequence * array)
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
      ball_detector__msg__BallDistance__fini(&array->data[i]);
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

ball_detector__msg__BallDistance__Sequence *
ball_detector__msg__BallDistance__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  ball_detector__msg__BallDistance__Sequence * array = (ball_detector__msg__BallDistance__Sequence *)allocator.allocate(sizeof(ball_detector__msg__BallDistance__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = ball_detector__msg__BallDistance__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
ball_detector__msg__BallDistance__Sequence__destroy(ball_detector__msg__BallDistance__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    ball_detector__msg__BallDistance__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
ball_detector__msg__BallDistance__Sequence__are_equal(const ball_detector__msg__BallDistance__Sequence * lhs, const ball_detector__msg__BallDistance__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!ball_detector__msg__BallDistance__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
ball_detector__msg__BallDistance__Sequence__copy(
  const ball_detector__msg__BallDistance__Sequence * input,
  ball_detector__msg__BallDistance__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(ball_detector__msg__BallDistance);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    ball_detector__msg__BallDistance * data =
      (ball_detector__msg__BallDistance *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!ball_detector__msg__BallDistance__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          ball_detector__msg__BallDistance__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!ball_detector__msg__BallDistance__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
