// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dsrcmsg:msg/OneCIMKeypoints.idl
// generated code does not contain a copyright notice
#include "dsrcmsg/msg/detail/one_cim_keypoints__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `key`
#include "rosidl_runtime_c/string_functions.h"

bool
dsrcmsg__msg__OneCIMKeypoints__init(dsrcmsg__msg__OneCIMKeypoints * msg)
{
  if (!msg) {
    return false;
  }
  // key
  if (!rosidl_runtime_c__String__init(&msg->key)) {
    dsrcmsg__msg__OneCIMKeypoints__fini(msg);
    return false;
  }
  // x
  // y
  return true;
}

void
dsrcmsg__msg__OneCIMKeypoints__fini(dsrcmsg__msg__OneCIMKeypoints * msg)
{
  if (!msg) {
    return;
  }
  // key
  rosidl_runtime_c__String__fini(&msg->key);
  // x
  // y
}

bool
dsrcmsg__msg__OneCIMKeypoints__are_equal(const dsrcmsg__msg__OneCIMKeypoints * lhs, const dsrcmsg__msg__OneCIMKeypoints * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // key
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->key), &(rhs->key)))
  {
    return false;
  }
  // x
  if (lhs->x != rhs->x) {
    return false;
  }
  // y
  if (lhs->y != rhs->y) {
    return false;
  }
  return true;
}

bool
dsrcmsg__msg__OneCIMKeypoints__copy(
  const dsrcmsg__msg__OneCIMKeypoints * input,
  dsrcmsg__msg__OneCIMKeypoints * output)
{
  if (!input || !output) {
    return false;
  }
  // key
  if (!rosidl_runtime_c__String__copy(
      &(input->key), &(output->key)))
  {
    return false;
  }
  // x
  output->x = input->x;
  // y
  output->y = input->y;
  return true;
}

dsrcmsg__msg__OneCIMKeypoints *
dsrcmsg__msg__OneCIMKeypoints__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dsrcmsg__msg__OneCIMKeypoints * msg = (dsrcmsg__msg__OneCIMKeypoints *)allocator.allocate(sizeof(dsrcmsg__msg__OneCIMKeypoints), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dsrcmsg__msg__OneCIMKeypoints));
  bool success = dsrcmsg__msg__OneCIMKeypoints__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dsrcmsg__msg__OneCIMKeypoints__destroy(dsrcmsg__msg__OneCIMKeypoints * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dsrcmsg__msg__OneCIMKeypoints__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dsrcmsg__msg__OneCIMKeypoints__Sequence__init(dsrcmsg__msg__OneCIMKeypoints__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dsrcmsg__msg__OneCIMKeypoints * data = NULL;

  if (size) {
    data = (dsrcmsg__msg__OneCIMKeypoints *)allocator.zero_allocate(size, sizeof(dsrcmsg__msg__OneCIMKeypoints), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dsrcmsg__msg__OneCIMKeypoints__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dsrcmsg__msg__OneCIMKeypoints__fini(&data[i - 1]);
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
dsrcmsg__msg__OneCIMKeypoints__Sequence__fini(dsrcmsg__msg__OneCIMKeypoints__Sequence * array)
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
      dsrcmsg__msg__OneCIMKeypoints__fini(&array->data[i]);
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

dsrcmsg__msg__OneCIMKeypoints__Sequence *
dsrcmsg__msg__OneCIMKeypoints__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dsrcmsg__msg__OneCIMKeypoints__Sequence * array = (dsrcmsg__msg__OneCIMKeypoints__Sequence *)allocator.allocate(sizeof(dsrcmsg__msg__OneCIMKeypoints__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dsrcmsg__msg__OneCIMKeypoints__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dsrcmsg__msg__OneCIMKeypoints__Sequence__destroy(dsrcmsg__msg__OneCIMKeypoints__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dsrcmsg__msg__OneCIMKeypoints__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dsrcmsg__msg__OneCIMKeypoints__Sequence__are_equal(const dsrcmsg__msg__OneCIMKeypoints__Sequence * lhs, const dsrcmsg__msg__OneCIMKeypoints__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dsrcmsg__msg__OneCIMKeypoints__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dsrcmsg__msg__OneCIMKeypoints__Sequence__copy(
  const dsrcmsg__msg__OneCIMKeypoints__Sequence * input,
  dsrcmsg__msg__OneCIMKeypoints__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dsrcmsg__msg__OneCIMKeypoints);
    dsrcmsg__msg__OneCIMKeypoints * data =
      (dsrcmsg__msg__OneCIMKeypoints *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dsrcmsg__msg__OneCIMKeypoints__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          dsrcmsg__msg__OneCIMKeypoints__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!dsrcmsg__msg__OneCIMKeypoints__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
