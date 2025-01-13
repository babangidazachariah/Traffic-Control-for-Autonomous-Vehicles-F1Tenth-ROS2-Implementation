// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from dsrcmsg:msg/OneCIMTlsMsg.idl
// generated code does not contain a copyright notice
#include "dsrcmsg/msg/detail/one_cim_tls_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `junctionid`
// Member `vehicleid`
// Member `pathids`
#include "rosidl_runtime_c/string_functions.h"
// Member `approachpoints`
// Member `departpoints`
#include "dsrcmsg/msg/detail/one_cim_keypoints__functions.h"

bool
dsrcmsg__msg__OneCIMTlsMsg__init(dsrcmsg__msg__OneCIMTlsMsg * msg)
{
  if (!msg) {
    return false;
  }
  // junctionid
  if (!rosidl_runtime_c__String__init(&msg->junctionid)) {
    dsrcmsg__msg__OneCIMTlsMsg__fini(msg);
    return false;
  }
  // vehicleid
  if (!rosidl_runtime_c__String__init(&msg->vehicleid)) {
    dsrcmsg__msg__OneCIMTlsMsg__fini(msg);
    return false;
  }
  // pathids
  if (!rosidl_runtime_c__String__Sequence__init(&msg->pathids, 0)) {
    dsrcmsg__msg__OneCIMTlsMsg__fini(msg);
    return false;
  }
  // starttime
  // duration
  // approachpoints
  if (!dsrcmsg__msg__OneCIMKeypoints__Sequence__init(&msg->approachpoints, 0)) {
    dsrcmsg__msg__OneCIMTlsMsg__fini(msg);
    return false;
  }
  // departpoints
  if (!dsrcmsg__msg__OneCIMKeypoints__Sequence__init(&msg->departpoints, 0)) {
    dsrcmsg__msg__OneCIMTlsMsg__fini(msg);
    return false;
  }
  // speed
  return true;
}

void
dsrcmsg__msg__OneCIMTlsMsg__fini(dsrcmsg__msg__OneCIMTlsMsg * msg)
{
  if (!msg) {
    return;
  }
  // junctionid
  rosidl_runtime_c__String__fini(&msg->junctionid);
  // vehicleid
  rosidl_runtime_c__String__fini(&msg->vehicleid);
  // pathids
  rosidl_runtime_c__String__Sequence__fini(&msg->pathids);
  // starttime
  // duration
  // approachpoints
  dsrcmsg__msg__OneCIMKeypoints__Sequence__fini(&msg->approachpoints);
  // departpoints
  dsrcmsg__msg__OneCIMKeypoints__Sequence__fini(&msg->departpoints);
  // speed
}

bool
dsrcmsg__msg__OneCIMTlsMsg__are_equal(const dsrcmsg__msg__OneCIMTlsMsg * lhs, const dsrcmsg__msg__OneCIMTlsMsg * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // junctionid
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->junctionid), &(rhs->junctionid)))
  {
    return false;
  }
  // vehicleid
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->vehicleid), &(rhs->vehicleid)))
  {
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
  // approachpoints
  if (!dsrcmsg__msg__OneCIMKeypoints__Sequence__are_equal(
      &(lhs->approachpoints), &(rhs->approachpoints)))
  {
    return false;
  }
  // departpoints
  if (!dsrcmsg__msg__OneCIMKeypoints__Sequence__are_equal(
      &(lhs->departpoints), &(rhs->departpoints)))
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
dsrcmsg__msg__OneCIMTlsMsg__copy(
  const dsrcmsg__msg__OneCIMTlsMsg * input,
  dsrcmsg__msg__OneCIMTlsMsg * output)
{
  if (!input || !output) {
    return false;
  }
  // junctionid
  if (!rosidl_runtime_c__String__copy(
      &(input->junctionid), &(output->junctionid)))
  {
    return false;
  }
  // vehicleid
  if (!rosidl_runtime_c__String__copy(
      &(input->vehicleid), &(output->vehicleid)))
  {
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
  // approachpoints
  if (!dsrcmsg__msg__OneCIMKeypoints__Sequence__copy(
      &(input->approachpoints), &(output->approachpoints)))
  {
    return false;
  }
  // departpoints
  if (!dsrcmsg__msg__OneCIMKeypoints__Sequence__copy(
      &(input->departpoints), &(output->departpoints)))
  {
    return false;
  }
  // speed
  output->speed = input->speed;
  return true;
}

dsrcmsg__msg__OneCIMTlsMsg *
dsrcmsg__msg__OneCIMTlsMsg__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dsrcmsg__msg__OneCIMTlsMsg * msg = (dsrcmsg__msg__OneCIMTlsMsg *)allocator.allocate(sizeof(dsrcmsg__msg__OneCIMTlsMsg), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(dsrcmsg__msg__OneCIMTlsMsg));
  bool success = dsrcmsg__msg__OneCIMTlsMsg__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
dsrcmsg__msg__OneCIMTlsMsg__destroy(dsrcmsg__msg__OneCIMTlsMsg * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    dsrcmsg__msg__OneCIMTlsMsg__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
dsrcmsg__msg__OneCIMTlsMsg__Sequence__init(dsrcmsg__msg__OneCIMTlsMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dsrcmsg__msg__OneCIMTlsMsg * data = NULL;

  if (size) {
    data = (dsrcmsg__msg__OneCIMTlsMsg *)allocator.zero_allocate(size, sizeof(dsrcmsg__msg__OneCIMTlsMsg), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = dsrcmsg__msg__OneCIMTlsMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        dsrcmsg__msg__OneCIMTlsMsg__fini(&data[i - 1]);
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
dsrcmsg__msg__OneCIMTlsMsg__Sequence__fini(dsrcmsg__msg__OneCIMTlsMsg__Sequence * array)
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
      dsrcmsg__msg__OneCIMTlsMsg__fini(&array->data[i]);
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

dsrcmsg__msg__OneCIMTlsMsg__Sequence *
dsrcmsg__msg__OneCIMTlsMsg__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  dsrcmsg__msg__OneCIMTlsMsg__Sequence * array = (dsrcmsg__msg__OneCIMTlsMsg__Sequence *)allocator.allocate(sizeof(dsrcmsg__msg__OneCIMTlsMsg__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = dsrcmsg__msg__OneCIMTlsMsg__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
dsrcmsg__msg__OneCIMTlsMsg__Sequence__destroy(dsrcmsg__msg__OneCIMTlsMsg__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    dsrcmsg__msg__OneCIMTlsMsg__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
dsrcmsg__msg__OneCIMTlsMsg__Sequence__are_equal(const dsrcmsg__msg__OneCIMTlsMsg__Sequence * lhs, const dsrcmsg__msg__OneCIMTlsMsg__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!dsrcmsg__msg__OneCIMTlsMsg__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
dsrcmsg__msg__OneCIMTlsMsg__Sequence__copy(
  const dsrcmsg__msg__OneCIMTlsMsg__Sequence * input,
  dsrcmsg__msg__OneCIMTlsMsg__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(dsrcmsg__msg__OneCIMTlsMsg);
    dsrcmsg__msg__OneCIMTlsMsg * data =
      (dsrcmsg__msg__OneCIMTlsMsg *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!dsrcmsg__msg__OneCIMTlsMsg__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          dsrcmsg__msg__OneCIMTlsMsg__fini(&data[i]);
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
    if (!dsrcmsg__msg__OneCIMTlsMsg__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
