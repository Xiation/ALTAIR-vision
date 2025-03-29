// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from temp_ball_detector:msg/BallDistance.idl
// generated code does not contain a copyright notice
#include "temp_ball_detector/msg/detail/ball_distance__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
temp_ball_detector__msg__BallDistance__init(temp_ball_detector__msg__BallDistance * msg)
{
  if (!msg) {
    return false;
  }
  // ball_ada_cok
  // jaraknya_jing
  return true;
}

void
temp_ball_detector__msg__BallDistance__fini(temp_ball_detector__msg__BallDistance * msg)
{
  if (!msg) {
    return;
  }
  // ball_ada_cok
  // jaraknya_jing
}

bool
temp_ball_detector__msg__BallDistance__are_equal(const temp_ball_detector__msg__BallDistance * lhs, const temp_ball_detector__msg__BallDistance * rhs)
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
temp_ball_detector__msg__BallDistance__copy(
  const temp_ball_detector__msg__BallDistance * input,
  temp_ball_detector__msg__BallDistance * output)
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

temp_ball_detector__msg__BallDistance *
temp_ball_detector__msg__BallDistance__create(void)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  temp_ball_detector__msg__BallDistance * msg = (temp_ball_detector__msg__BallDistance *)allocator.allocate(sizeof(temp_ball_detector__msg__BallDistance), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(temp_ball_detector__msg__BallDistance));
  bool success = temp_ball_detector__msg__BallDistance__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
temp_ball_detector__msg__BallDistance__destroy(temp_ball_detector__msg__BallDistance * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    temp_ball_detector__msg__BallDistance__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
temp_ball_detector__msg__BallDistance__Sequence__init(temp_ball_detector__msg__BallDistance__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  temp_ball_detector__msg__BallDistance * data = NULL;

  if (size) {
    data = (temp_ball_detector__msg__BallDistance *)allocator.zero_allocate(size, sizeof(temp_ball_detector__msg__BallDistance), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = temp_ball_detector__msg__BallDistance__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        temp_ball_detector__msg__BallDistance__fini(&data[i - 1]);
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
temp_ball_detector__msg__BallDistance__Sequence__fini(temp_ball_detector__msg__BallDistance__Sequence * array)
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
      temp_ball_detector__msg__BallDistance__fini(&array->data[i]);
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

temp_ball_detector__msg__BallDistance__Sequence *
temp_ball_detector__msg__BallDistance__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  temp_ball_detector__msg__BallDistance__Sequence * array = (temp_ball_detector__msg__BallDistance__Sequence *)allocator.allocate(sizeof(temp_ball_detector__msg__BallDistance__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = temp_ball_detector__msg__BallDistance__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
temp_ball_detector__msg__BallDistance__Sequence__destroy(temp_ball_detector__msg__BallDistance__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    temp_ball_detector__msg__BallDistance__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
temp_ball_detector__msg__BallDistance__Sequence__are_equal(const temp_ball_detector__msg__BallDistance__Sequence * lhs, const temp_ball_detector__msg__BallDistance__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!temp_ball_detector__msg__BallDistance__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
temp_ball_detector__msg__BallDistance__Sequence__copy(
  const temp_ball_detector__msg__BallDistance__Sequence * input,
  temp_ball_detector__msg__BallDistance__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(temp_ball_detector__msg__BallDistance);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    temp_ball_detector__msg__BallDistance * data =
      (temp_ball_detector__msg__BallDistance *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!temp_ball_detector__msg__BallDistance__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          temp_ball_detector__msg__BallDistance__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!temp_ball_detector__msg__BallDistance__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
