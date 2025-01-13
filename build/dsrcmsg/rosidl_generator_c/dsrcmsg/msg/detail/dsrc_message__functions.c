// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dsrcmsg:msg/DSRCMessage.idl
// generated code does not contain a copyright notice
#include "dsrcmsg/msg/detail/dsrc_message__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `vehicleid`
// Member `approachleg`
// Member `departureleg`
#include "rosidl_runtime_c/string_functions.h"
// Member `point`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
dsrcmsg__msg__DSRCMessage__init(dsrcmsg__msg__DSRCMessage * msg)
{
  if (!msg) {
    return false;
  }
  // vehicleid
  if (!rosidl_runtime_c__String__init(&msg->vehicleid)) {
    dsrcmsg__msg__DSRCMessage__fini(msg);
    return false;
  }
  // initialtime
  // currenttime
  // approachleg
  if (!rosidl_runtime_c__String__init(&msg->approachleg)) {
    dsrcmsg__msg__DSRCMessage__fini(msg);
    return false;
  }
  // departureleg
  if (!rosidl_runtime_c__String__init(&msg->departureleg)) {
    dsrcmsg__msg__DSRCMessage__fini(msg);
    return false;
  }
  // disttostopline
  // distfromstopline
  // point
  if (!rosidl_runtime_c__float__Sequence__init(&msg->point, 0)) {
    dsrcmsg__msg__DSRCMessage__fini(msg);
    return false;
  }
  // speed
  return true;
}

void
dsrcmsg__msg__DSRCMessage__fini(dsrcmsg__msg__DSRCMessage * msg)
{
  if (!msg) {
    return;
  }
  // vehicleid
  rosidl_runtime_c__String__fini(&msg->vehicleid);
  // initialtime
  // currenttime
  // approachleg
  rosidl_runtime_c__String__fini(&msg->approachleg);
  // departureleg
  rosidl_runtime_c__String__fini(&msg->departureleg);
  // disttostopline
  // distfromstopline
  // point
  rosidl_runtime_c__float__Sequence__fini(&msg->point);
  // speed
}

bool
dsrcmsg__msg__DSRCMessage__are_equal(const dsrcmsg__msg__DSRCMessage * lhs, const dsrcmsg__msg__DSRCMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // vehicleid
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->vehicleid), &(rhs->vehicleid)))
  {
    return false;
  }
  // initialtime
  if (lhs->initialtime != rhs->initialtime) {
    return false;
  }
  // currenttime
  if (lhs->currenttime != rhs->currenttime) {
    return false;
  }
  // approachleg
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->approachleg), &(rhs->approachleg)))
  {
    return false;
  }
  // departureleg
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->departureleg), &(rhs->departureleg)))
  {
    return false;
  }
  // disttostopline
  if (lhs->disttostopline != rhs->disttostopline) {
    return false;
  }
  // distfromstopline
  if (lhs->distfromstopline != rhs->distfromstopline) {
    return false;
  }
  // point
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->point), &(rhs->point)))
  {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  return true;
}

bool
dsrcmsg__msg__DSRCMessage__copy(
  const dsrcmsg__msg__DSRCMessage * input,
  dsrcmsg__msg__DSRCMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // vehicleid
  if (!rosidl_runtime_c__String__copy(
      &(input->vehicleid), &(output->vehicleid)))
  {
    return false;
  }
  // initialtime
  output->initialtime = input->initialtime;
  // currenttime
  output->currenttime = input->currenttime;
  // approachleg
  if (!rosidl_runtime_c__String__copy(
      &(input->approachleg), &(output->approachleg)))
  {
    return false;
  }
  // departureleg
  if (!rosidl_runtime_c__String__copy(
      &(input->departureleg), &(output->departureleg)))
  {
    return false;
  }
  // disttostopline
  output->disttostopline = input->disttostopline;
  // distfromstopline
  output->distfromstopline = input->distfromstopline;
  // point
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->point), &(output->point)))
  {
    return false;
  }
  // speed
  output->speed = input->speed;
  return true;
}

dsrcmsg__msg__DSRCMessage *
dsrcmsg__msg__DSRCMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dsrcmsg__msg__DSRCMessage * msg = (dsrcmsg__msg__DSRCMessage *)allocator.allocate(sizeof(dsrcmsg__msg__DSRCMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dsrcmsg__msg__DSRCMessage));
  bool success = dsrcmsg__msg__DSRCMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dsrcmsg__msg__DSRCMessage__destroy(dsrcmsg__msg__DSRCMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dsrcmsg__msg__DSRCMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dsrcmsg__msg__DSRCMessage__Sequence__init(dsrcmsg__msg__DSRCMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dsrcmsg__msg__DSRCMessage * data = NULL;

  if (size) {
    data = (dsrcmsg__msg__DSRCMessage *)allocator.zero_allocate(size, sizeof(dsrcmsg__msg__DSRCMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dsrcmsg__msg__DSRCMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dsrcmsg__msg__DSRCMessage__fini(&data[i - 1]);
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
dsrcmsg__msg__DSRCMessage__Sequence__fini(dsrcmsg__msg__DSRCMessage__Sequence * array)
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
      dsrcmsg__msg__DSRCMessage__fini(&array->data[i]);
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

dsrcmsg__msg__DSRCMessage__Sequence *
dsrcmsg__msg__DSRCMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dsrcmsg__msg__DSRCMessage__Sequence * array = (dsrcmsg__msg__DSRCMessage__Sequence *)allocator.allocate(sizeof(dsrcmsg__msg__DSRCMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dsrcmsg__msg__DSRCMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dsrcmsg__msg__DSRCMessage__Sequence__destroy(dsrcmsg__msg__DSRCMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dsrcmsg__msg__DSRCMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dsrcmsg__msg__DSRCMessage__Sequence__are_equal(const dsrcmsg__msg__DSRCMessage__Sequence * lhs, const dsrcmsg__msg__DSRCMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dsrcmsg__msg__DSRCMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dsrcmsg__msg__DSRCMessage__Sequence__copy(
  const dsrcmsg__msg__DSRCMessage__Sequence * input,
  dsrcmsg__msg__DSRCMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dsrcmsg__msg__DSRCMessage);
    dsrcmsg__msg__DSRCMessage * data =
      (dsrcmsg__msg__DSRCMessage *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dsrcmsg__msg__DSRCMessage__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          dsrcmsg__msg__DSRCMessage__fini(&data[i]);
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
    if (!dsrcmsg__msg__DSRCMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
