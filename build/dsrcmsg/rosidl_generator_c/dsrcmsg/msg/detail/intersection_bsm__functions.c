// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dsrcmsg:msg/IntersectionBSM.idl
// generated code does not contain a copyright notice
#include "dsrcmsg/msg/detail/intersection_bsm__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `vehicleid`
// Member `junctionid`
// Member `approachleg`
// Member `departleg`
#include "rosidl_runtime_c/string_functions.h"
// Member `point`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
dsrcmsg__msg__IntersectionBSM__init(dsrcmsg__msg__IntersectionBSM * msg)
{
  if (!msg) {
    return false;
  }
  // vehicleid
  if (!rosidl_runtime_c__String__init(&msg->vehicleid)) {
    dsrcmsg__msg__IntersectionBSM__fini(msg);
    return false;
  }
  // junctionid
  if (!rosidl_runtime_c__String__init(&msg->junctionid)) {
    dsrcmsg__msg__IntersectionBSM__fini(msg);
    return false;
  }
  // approachleg
  if (!rosidl_runtime_c__String__init(&msg->approachleg)) {
    dsrcmsg__msg__IntersectionBSM__fini(msg);
    return false;
  }
  // departleg
  if (!rosidl_runtime_c__String__init(&msg->departleg)) {
    dsrcmsg__msg__IntersectionBSM__fini(msg);
    return false;
  }
  // distfromstopline
  // point
  if (!rosidl_runtime_c__float__Sequence__init(&msg->point, 0)) {
    dsrcmsg__msg__IntersectionBSM__fini(msg);
    return false;
  }
  // arrivaltime
  // vehicletype
  // speed
  // priority
  // stoppedtime
  // timestamp
  return true;
}

void
dsrcmsg__msg__IntersectionBSM__fini(dsrcmsg__msg__IntersectionBSM * msg)
{
  if (!msg) {
    return;
  }
  // vehicleid
  rosidl_runtime_c__String__fini(&msg->vehicleid);
  // junctionid
  rosidl_runtime_c__String__fini(&msg->junctionid);
  // approachleg
  rosidl_runtime_c__String__fini(&msg->approachleg);
  // departleg
  rosidl_runtime_c__String__fini(&msg->departleg);
  // distfromstopline
  // point
  rosidl_runtime_c__float__Sequence__fini(&msg->point);
  // arrivaltime
  // vehicletype
  // speed
  // priority
  // stoppedtime
  // timestamp
}

bool
dsrcmsg__msg__IntersectionBSM__are_equal(const dsrcmsg__msg__IntersectionBSM * lhs, const dsrcmsg__msg__IntersectionBSM * rhs)
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
  // junctionid
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->junctionid), &(rhs->junctionid)))
  {
    return false;
  }
  // approachleg
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->approachleg), &(rhs->approachleg)))
  {
    return false;
  }
  // departleg
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->departleg), &(rhs->departleg)))
  {
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
  // arrivaltime
  if (lhs->arrivaltime != rhs->arrivaltime) {
    return false;
  }
  // vehicletype
  if (lhs->vehicletype != rhs->vehicletype) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // priority
  if (lhs->priority != rhs->priority) {
    return false;
  }
  // stoppedtime
  if (lhs->stoppedtime != rhs->stoppedtime) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  return true;
}

bool
dsrcmsg__msg__IntersectionBSM__copy(
  const dsrcmsg__msg__IntersectionBSM * input,
  dsrcmsg__msg__IntersectionBSM * output)
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
  // junctionid
  if (!rosidl_runtime_c__String__copy(
      &(input->junctionid), &(output->junctionid)))
  {
    return false;
  }
  // approachleg
  if (!rosidl_runtime_c__String__copy(
      &(input->approachleg), &(output->approachleg)))
  {
    return false;
  }
  // departleg
  if (!rosidl_runtime_c__String__copy(
      &(input->departleg), &(output->departleg)))
  {
    return false;
  }
  // distfromstopline
  output->distfromstopline = input->distfromstopline;
  // point
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->point), &(output->point)))
  {
    return false;
  }
  // arrivaltime
  output->arrivaltime = input->arrivaltime;
  // vehicletype
  output->vehicletype = input->vehicletype;
  // speed
  output->speed = input->speed;
  // priority
  output->priority = input->priority;
  // stoppedtime
  output->stoppedtime = input->stoppedtime;
  // timestamp
  output->timestamp = input->timestamp;
  return true;
}

dsrcmsg__msg__IntersectionBSM *
dsrcmsg__msg__IntersectionBSM__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dsrcmsg__msg__IntersectionBSM * msg = (dsrcmsg__msg__IntersectionBSM *)allocator.allocate(sizeof(dsrcmsg__msg__IntersectionBSM), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dsrcmsg__msg__IntersectionBSM));
  bool success = dsrcmsg__msg__IntersectionBSM__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dsrcmsg__msg__IntersectionBSM__destroy(dsrcmsg__msg__IntersectionBSM * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dsrcmsg__msg__IntersectionBSM__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dsrcmsg__msg__IntersectionBSM__Sequence__init(dsrcmsg__msg__IntersectionBSM__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dsrcmsg__msg__IntersectionBSM * data = NULL;

  if (size) {
    data = (dsrcmsg__msg__IntersectionBSM *)allocator.zero_allocate(size, sizeof(dsrcmsg__msg__IntersectionBSM), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dsrcmsg__msg__IntersectionBSM__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dsrcmsg__msg__IntersectionBSM__fini(&data[i - 1]);
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
dsrcmsg__msg__IntersectionBSM__Sequence__fini(dsrcmsg__msg__IntersectionBSM__Sequence * array)
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
      dsrcmsg__msg__IntersectionBSM__fini(&array->data[i]);
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

dsrcmsg__msg__IntersectionBSM__Sequence *
dsrcmsg__msg__IntersectionBSM__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dsrcmsg__msg__IntersectionBSM__Sequence * array = (dsrcmsg__msg__IntersectionBSM__Sequence *)allocator.allocate(sizeof(dsrcmsg__msg__IntersectionBSM__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dsrcmsg__msg__IntersectionBSM__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dsrcmsg__msg__IntersectionBSM__Sequence__destroy(dsrcmsg__msg__IntersectionBSM__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dsrcmsg__msg__IntersectionBSM__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dsrcmsg__msg__IntersectionBSM__Sequence__are_equal(const dsrcmsg__msg__IntersectionBSM__Sequence * lhs, const dsrcmsg__msg__IntersectionBSM__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dsrcmsg__msg__IntersectionBSM__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dsrcmsg__msg__IntersectionBSM__Sequence__copy(
  const dsrcmsg__msg__IntersectionBSM__Sequence * input,
  dsrcmsg__msg__IntersectionBSM__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dsrcmsg__msg__IntersectionBSM);
    dsrcmsg__msg__IntersectionBSM * data =
      (dsrcmsg__msg__IntersectionBSM *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dsrcmsg__msg__IntersectionBSM__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          dsrcmsg__msg__IntersectionBSM__fini(&data[i]);
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
    if (!dsrcmsg__msg__IntersectionBSM__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
