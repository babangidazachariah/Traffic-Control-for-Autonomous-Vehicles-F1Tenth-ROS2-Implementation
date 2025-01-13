// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dsrcmsg:msg/TrafficLightsMessage.idl
// generated code does not contain a copyright notice
#include "dsrcmsg/msg/detail/traffic_lights_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `pathids`
#include "rosidl_runtime_c/string_functions.h"

bool
dsrcmsg__msg__TrafficLightsMessage__init(dsrcmsg__msg__TrafficLightsMessage * msg)
{
  if (!msg) {
    return false;
  }
  // pathids
  if (!rosidl_runtime_c__String__Sequence__init(&msg->pathids, 0)) {
    dsrcmsg__msg__TrafficLightsMessage__fini(msg);
    return false;
  }
  // starttime
  // duration
  // speed
  return true;
}

void
dsrcmsg__msg__TrafficLightsMessage__fini(dsrcmsg__msg__TrafficLightsMessage * msg)
{
  if (!msg) {
    return;
  }
  // pathids
  rosidl_runtime_c__String__Sequence__fini(&msg->pathids);
  // starttime
  // duration
  // speed
}

bool
dsrcmsg__msg__TrafficLightsMessage__are_equal(const dsrcmsg__msg__TrafficLightsMessage * lhs, const dsrcmsg__msg__TrafficLightsMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // pathids
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->pathids), &(rhs->pathids)))
  {
    return false;
  }
  // starttime
  if (lhs->starttime != rhs->starttime) {
    return false;
  }
  // duration
  if (lhs->duration != rhs->duration) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  return true;
}

bool
dsrcmsg__msg__TrafficLightsMessage__copy(
  const dsrcmsg__msg__TrafficLightsMessage * input,
  dsrcmsg__msg__TrafficLightsMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // pathids
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->pathids), &(output->pathids)))
  {
    return false;
  }
  // starttime
  output->starttime = input->starttime;
  // duration
  output->duration = input->duration;
  // speed
  output->speed = input->speed;
  return true;
}

dsrcmsg__msg__TrafficLightsMessage *
dsrcmsg__msg__TrafficLightsMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dsrcmsg__msg__TrafficLightsMessage * msg = (dsrcmsg__msg__TrafficLightsMessage *)allocator.allocate(sizeof(dsrcmsg__msg__TrafficLightsMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dsrcmsg__msg__TrafficLightsMessage));
  bool success = dsrcmsg__msg__TrafficLightsMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dsrcmsg__msg__TrafficLightsMessage__destroy(dsrcmsg__msg__TrafficLightsMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dsrcmsg__msg__TrafficLightsMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dsrcmsg__msg__TrafficLightsMessage__Sequence__init(dsrcmsg__msg__TrafficLightsMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dsrcmsg__msg__TrafficLightsMessage * data = NULL;

  if (size) {
    data = (dsrcmsg__msg__TrafficLightsMessage *)allocator.zero_allocate(size, sizeof(dsrcmsg__msg__TrafficLightsMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dsrcmsg__msg__TrafficLightsMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dsrcmsg__msg__TrafficLightsMessage__fini(&data[i - 1]);
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
dsrcmsg__msg__TrafficLightsMessage__Sequence__fini(dsrcmsg__msg__TrafficLightsMessage__Sequence * array)
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
      dsrcmsg__msg__TrafficLightsMessage__fini(&array->data[i]);
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

dsrcmsg__msg__TrafficLightsMessage__Sequence *
dsrcmsg__msg__TrafficLightsMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dsrcmsg__msg__TrafficLightsMessage__Sequence * array = (dsrcmsg__msg__TrafficLightsMessage__Sequence *)allocator.allocate(sizeof(dsrcmsg__msg__TrafficLightsMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dsrcmsg__msg__TrafficLightsMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dsrcmsg__msg__TrafficLightsMessage__Sequence__destroy(dsrcmsg__msg__TrafficLightsMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dsrcmsg__msg__TrafficLightsMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dsrcmsg__msg__TrafficLightsMessage__Sequence__are_equal(const dsrcmsg__msg__TrafficLightsMessage__Sequence * lhs, const dsrcmsg__msg__TrafficLightsMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dsrcmsg__msg__TrafficLightsMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dsrcmsg__msg__TrafficLightsMessage__Sequence__copy(
  const dsrcmsg__msg__TrafficLightsMessage__Sequence * input,
  dsrcmsg__msg__TrafficLightsMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dsrcmsg__msg__TrafficLightsMessage);
    dsrcmsg__msg__TrafficLightsMessage * data =
      (dsrcmsg__msg__TrafficLightsMessage *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dsrcmsg__msg__TrafficLightsMessage__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          dsrcmsg__msg__TrafficLightsMessage__fini(&data[i]);
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
    if (!dsrcmsg__msg__TrafficLightsMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
