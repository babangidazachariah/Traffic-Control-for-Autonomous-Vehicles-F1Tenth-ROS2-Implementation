// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from trafficrecord:action/VehWaitTime.idl
// generated code does not contain a copyright notice
#include "trafficrecord/action/detail/veh_wait_time__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `approachleg`
#include "rosidl_runtime_c/string_functions.h"

bool
trafficrecord__action__VehWaitTime_Goal__init(trafficrecord__action__VehWaitTime_Goal * msg)
{
  if (!msg) {
    return false;
  }
  // approachleg
  if (!rosidl_runtime_c__String__init(&msg->approachleg)) {
    trafficrecord__action__VehWaitTime_Goal__fini(msg);
    return false;
  }
  // waittime
  return true;
}

void
trafficrecord__action__VehWaitTime_Goal__fini(trafficrecord__action__VehWaitTime_Goal * msg)
{
  if (!msg) {
    return;
  }
  // approachleg
  rosidl_runtime_c__String__fini(&msg->approachleg);
  // waittime
}

bool
trafficrecord__action__VehWaitTime_Goal__are_equal(const trafficrecord__action__VehWaitTime_Goal * lhs, const trafficrecord__action__VehWaitTime_Goal * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // approachleg
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->approachleg), &(rhs->approachleg)))
  {
    return false;
  }
  // waittime
  if (lhs->waittime != rhs->waittime) {
    return false;
  }
  return true;
}

bool
trafficrecord__action__VehWaitTime_Goal__copy(
  const trafficrecord__action__VehWaitTime_Goal * input,
  trafficrecord__action__VehWaitTime_Goal * output)
{
  if (!input || !output) {
    return false;
  }
  // approachleg
  if (!rosidl_runtime_c__String__copy(
      &(input->approachleg), &(output->approachleg)))
  {
    return false;
  }
  // waittime
  output->waittime = input->waittime;
  return true;
}

trafficrecord__action__VehWaitTime_Goal *
trafficrecord__action__VehWaitTime_Goal__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_Goal * msg = (trafficrecord__action__VehWaitTime_Goal *)allocator.allocate(sizeof(trafficrecord__action__VehWaitTime_Goal), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trafficrecord__action__VehWaitTime_Goal));
  bool success = trafficrecord__action__VehWaitTime_Goal__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trafficrecord__action__VehWaitTime_Goal__destroy(trafficrecord__action__VehWaitTime_Goal * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trafficrecord__action__VehWaitTime_Goal__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trafficrecord__action__VehWaitTime_Goal__Sequence__init(trafficrecord__action__VehWaitTime_Goal__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_Goal * data = NULL;

  if (size) {
    data = (trafficrecord__action__VehWaitTime_Goal *)allocator.zero_allocate(size, sizeof(trafficrecord__action__VehWaitTime_Goal), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trafficrecord__action__VehWaitTime_Goal__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trafficrecord__action__VehWaitTime_Goal__fini(&data[i - 1]);
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
trafficrecord__action__VehWaitTime_Goal__Sequence__fini(trafficrecord__action__VehWaitTime_Goal__Sequence * array)
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
      trafficrecord__action__VehWaitTime_Goal__fini(&array->data[i]);
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

trafficrecord__action__VehWaitTime_Goal__Sequence *
trafficrecord__action__VehWaitTime_Goal__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_Goal__Sequence * array = (trafficrecord__action__VehWaitTime_Goal__Sequence *)allocator.allocate(sizeof(trafficrecord__action__VehWaitTime_Goal__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trafficrecord__action__VehWaitTime_Goal__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trafficrecord__action__VehWaitTime_Goal__Sequence__destroy(trafficrecord__action__VehWaitTime_Goal__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trafficrecord__action__VehWaitTime_Goal__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trafficrecord__action__VehWaitTime_Goal__Sequence__are_equal(const trafficrecord__action__VehWaitTime_Goal__Sequence * lhs, const trafficrecord__action__VehWaitTime_Goal__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trafficrecord__action__VehWaitTime_Goal__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trafficrecord__action__VehWaitTime_Goal__Sequence__copy(
  const trafficrecord__action__VehWaitTime_Goal__Sequence * input,
  trafficrecord__action__VehWaitTime_Goal__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trafficrecord__action__VehWaitTime_Goal);
    trafficrecord__action__VehWaitTime_Goal * data =
      (trafficrecord__action__VehWaitTime_Goal *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trafficrecord__action__VehWaitTime_Goal__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          trafficrecord__action__VehWaitTime_Goal__fini(&data[i]);
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
    if (!trafficrecord__action__VehWaitTime_Goal__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
trafficrecord__action__VehWaitTime_Result__init(trafficrecord__action__VehWaitTime_Result * msg)
{
  if (!msg) {
    return false;
  }
  // recorded
  return true;
}

void
trafficrecord__action__VehWaitTime_Result__fini(trafficrecord__action__VehWaitTime_Result * msg)
{
  if (!msg) {
    return;
  }
  // recorded
}

bool
trafficrecord__action__VehWaitTime_Result__are_equal(const trafficrecord__action__VehWaitTime_Result * lhs, const trafficrecord__action__VehWaitTime_Result * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // recorded
  if (lhs->recorded != rhs->recorded) {
    return false;
  }
  return true;
}

bool
trafficrecord__action__VehWaitTime_Result__copy(
  const trafficrecord__action__VehWaitTime_Result * input,
  trafficrecord__action__VehWaitTime_Result * output)
{
  if (!input || !output) {
    return false;
  }
  // recorded
  output->recorded = input->recorded;
  return true;
}

trafficrecord__action__VehWaitTime_Result *
trafficrecord__action__VehWaitTime_Result__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_Result * msg = (trafficrecord__action__VehWaitTime_Result *)allocator.allocate(sizeof(trafficrecord__action__VehWaitTime_Result), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trafficrecord__action__VehWaitTime_Result));
  bool success = trafficrecord__action__VehWaitTime_Result__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trafficrecord__action__VehWaitTime_Result__destroy(trafficrecord__action__VehWaitTime_Result * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trafficrecord__action__VehWaitTime_Result__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trafficrecord__action__VehWaitTime_Result__Sequence__init(trafficrecord__action__VehWaitTime_Result__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_Result * data = NULL;

  if (size) {
    data = (trafficrecord__action__VehWaitTime_Result *)allocator.zero_allocate(size, sizeof(trafficrecord__action__VehWaitTime_Result), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trafficrecord__action__VehWaitTime_Result__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trafficrecord__action__VehWaitTime_Result__fini(&data[i - 1]);
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
trafficrecord__action__VehWaitTime_Result__Sequence__fini(trafficrecord__action__VehWaitTime_Result__Sequence * array)
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
      trafficrecord__action__VehWaitTime_Result__fini(&array->data[i]);
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

trafficrecord__action__VehWaitTime_Result__Sequence *
trafficrecord__action__VehWaitTime_Result__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_Result__Sequence * array = (trafficrecord__action__VehWaitTime_Result__Sequence *)allocator.allocate(sizeof(trafficrecord__action__VehWaitTime_Result__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trafficrecord__action__VehWaitTime_Result__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trafficrecord__action__VehWaitTime_Result__Sequence__destroy(trafficrecord__action__VehWaitTime_Result__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trafficrecord__action__VehWaitTime_Result__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trafficrecord__action__VehWaitTime_Result__Sequence__are_equal(const trafficrecord__action__VehWaitTime_Result__Sequence * lhs, const trafficrecord__action__VehWaitTime_Result__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trafficrecord__action__VehWaitTime_Result__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trafficrecord__action__VehWaitTime_Result__Sequence__copy(
  const trafficrecord__action__VehWaitTime_Result__Sequence * input,
  trafficrecord__action__VehWaitTime_Result__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trafficrecord__action__VehWaitTime_Result);
    trafficrecord__action__VehWaitTime_Result * data =
      (trafficrecord__action__VehWaitTime_Result *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trafficrecord__action__VehWaitTime_Result__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          trafficrecord__action__VehWaitTime_Result__fini(&data[i]);
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
    if (!trafficrecord__action__VehWaitTime_Result__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
trafficrecord__action__VehWaitTime_Feedback__init(trafficrecord__action__VehWaitTime_Feedback * msg)
{
  if (!msg) {
    return false;
  }
  // partiallyrecorded
  return true;
}

void
trafficrecord__action__VehWaitTime_Feedback__fini(trafficrecord__action__VehWaitTime_Feedback * msg)
{
  if (!msg) {
    return;
  }
  // partiallyrecorded
}

bool
trafficrecord__action__VehWaitTime_Feedback__are_equal(const trafficrecord__action__VehWaitTime_Feedback * lhs, const trafficrecord__action__VehWaitTime_Feedback * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // partiallyrecorded
  if (lhs->partiallyrecorded != rhs->partiallyrecorded) {
    return false;
  }
  return true;
}

bool
trafficrecord__action__VehWaitTime_Feedback__copy(
  const trafficrecord__action__VehWaitTime_Feedback * input,
  trafficrecord__action__VehWaitTime_Feedback * output)
{
  if (!input || !output) {
    return false;
  }
  // partiallyrecorded
  output->partiallyrecorded = input->partiallyrecorded;
  return true;
}

trafficrecord__action__VehWaitTime_Feedback *
trafficrecord__action__VehWaitTime_Feedback__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_Feedback * msg = (trafficrecord__action__VehWaitTime_Feedback *)allocator.allocate(sizeof(trafficrecord__action__VehWaitTime_Feedback), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trafficrecord__action__VehWaitTime_Feedback));
  bool success = trafficrecord__action__VehWaitTime_Feedback__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trafficrecord__action__VehWaitTime_Feedback__destroy(trafficrecord__action__VehWaitTime_Feedback * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trafficrecord__action__VehWaitTime_Feedback__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trafficrecord__action__VehWaitTime_Feedback__Sequence__init(trafficrecord__action__VehWaitTime_Feedback__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_Feedback * data = NULL;

  if (size) {
    data = (trafficrecord__action__VehWaitTime_Feedback *)allocator.zero_allocate(size, sizeof(trafficrecord__action__VehWaitTime_Feedback), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trafficrecord__action__VehWaitTime_Feedback__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trafficrecord__action__VehWaitTime_Feedback__fini(&data[i - 1]);
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
trafficrecord__action__VehWaitTime_Feedback__Sequence__fini(trafficrecord__action__VehWaitTime_Feedback__Sequence * array)
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
      trafficrecord__action__VehWaitTime_Feedback__fini(&array->data[i]);
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

trafficrecord__action__VehWaitTime_Feedback__Sequence *
trafficrecord__action__VehWaitTime_Feedback__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_Feedback__Sequence * array = (trafficrecord__action__VehWaitTime_Feedback__Sequence *)allocator.allocate(sizeof(trafficrecord__action__VehWaitTime_Feedback__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trafficrecord__action__VehWaitTime_Feedback__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trafficrecord__action__VehWaitTime_Feedback__Sequence__destroy(trafficrecord__action__VehWaitTime_Feedback__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trafficrecord__action__VehWaitTime_Feedback__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trafficrecord__action__VehWaitTime_Feedback__Sequence__are_equal(const trafficrecord__action__VehWaitTime_Feedback__Sequence * lhs, const trafficrecord__action__VehWaitTime_Feedback__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trafficrecord__action__VehWaitTime_Feedback__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trafficrecord__action__VehWaitTime_Feedback__Sequence__copy(
  const trafficrecord__action__VehWaitTime_Feedback__Sequence * input,
  trafficrecord__action__VehWaitTime_Feedback__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trafficrecord__action__VehWaitTime_Feedback);
    trafficrecord__action__VehWaitTime_Feedback * data =
      (trafficrecord__action__VehWaitTime_Feedback *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trafficrecord__action__VehWaitTime_Feedback__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          trafficrecord__action__VehWaitTime_Feedback__fini(&data[i]);
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
    if (!trafficrecord__action__VehWaitTime_Feedback__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `goal`
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__functions.h"

bool
trafficrecord__action__VehWaitTime_SendGoal_Request__init(trafficrecord__action__VehWaitTime_SendGoal_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    trafficrecord__action__VehWaitTime_SendGoal_Request__fini(msg);
    return false;
  }
  // goal
  if (!trafficrecord__action__VehWaitTime_Goal__init(&msg->goal)) {
    trafficrecord__action__VehWaitTime_SendGoal_Request__fini(msg);
    return false;
  }
  return true;
}

void
trafficrecord__action__VehWaitTime_SendGoal_Request__fini(trafficrecord__action__VehWaitTime_SendGoal_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // goal
  trafficrecord__action__VehWaitTime_Goal__fini(&msg->goal);
}

bool
trafficrecord__action__VehWaitTime_SendGoal_Request__are_equal(const trafficrecord__action__VehWaitTime_SendGoal_Request * lhs, const trafficrecord__action__VehWaitTime_SendGoal_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // goal
  if (!trafficrecord__action__VehWaitTime_Goal__are_equal(
      &(lhs->goal), &(rhs->goal)))
  {
    return false;
  }
  return true;
}

bool
trafficrecord__action__VehWaitTime_SendGoal_Request__copy(
  const trafficrecord__action__VehWaitTime_SendGoal_Request * input,
  trafficrecord__action__VehWaitTime_SendGoal_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // goal
  if (!trafficrecord__action__VehWaitTime_Goal__copy(
      &(input->goal), &(output->goal)))
  {
    return false;
  }
  return true;
}

trafficrecord__action__VehWaitTime_SendGoal_Request *
trafficrecord__action__VehWaitTime_SendGoal_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_SendGoal_Request * msg = (trafficrecord__action__VehWaitTime_SendGoal_Request *)allocator.allocate(sizeof(trafficrecord__action__VehWaitTime_SendGoal_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trafficrecord__action__VehWaitTime_SendGoal_Request));
  bool success = trafficrecord__action__VehWaitTime_SendGoal_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trafficrecord__action__VehWaitTime_SendGoal_Request__destroy(trafficrecord__action__VehWaitTime_SendGoal_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trafficrecord__action__VehWaitTime_SendGoal_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence__init(trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_SendGoal_Request * data = NULL;

  if (size) {
    data = (trafficrecord__action__VehWaitTime_SendGoal_Request *)allocator.zero_allocate(size, sizeof(trafficrecord__action__VehWaitTime_SendGoal_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trafficrecord__action__VehWaitTime_SendGoal_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trafficrecord__action__VehWaitTime_SendGoal_Request__fini(&data[i - 1]);
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
trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence__fini(trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence * array)
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
      trafficrecord__action__VehWaitTime_SendGoal_Request__fini(&array->data[i]);
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

trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence *
trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence * array = (trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence *)allocator.allocate(sizeof(trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence__destroy(trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence__are_equal(const trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence * lhs, const trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trafficrecord__action__VehWaitTime_SendGoal_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence__copy(
  const trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence * input,
  trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trafficrecord__action__VehWaitTime_SendGoal_Request);
    trafficrecord__action__VehWaitTime_SendGoal_Request * data =
      (trafficrecord__action__VehWaitTime_SendGoal_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trafficrecord__action__VehWaitTime_SendGoal_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          trafficrecord__action__VehWaitTime_SendGoal_Request__fini(&data[i]);
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
    if (!trafficrecord__action__VehWaitTime_SendGoal_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__functions.h"

bool
trafficrecord__action__VehWaitTime_SendGoal_Response__init(trafficrecord__action__VehWaitTime_SendGoal_Response * msg)
{
  if (!msg) {
    return false;
  }
  // accepted
  // stamp
  if (!builtin_interfaces__msg__Time__init(&msg->stamp)) {
    trafficrecord__action__VehWaitTime_SendGoal_Response__fini(msg);
    return false;
  }
  return true;
}

void
trafficrecord__action__VehWaitTime_SendGoal_Response__fini(trafficrecord__action__VehWaitTime_SendGoal_Response * msg)
{
  if (!msg) {
    return;
  }
  // accepted
  // stamp
  builtin_interfaces__msg__Time__fini(&msg->stamp);
}

bool
trafficrecord__action__VehWaitTime_SendGoal_Response__are_equal(const trafficrecord__action__VehWaitTime_SendGoal_Response * lhs, const trafficrecord__action__VehWaitTime_SendGoal_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // accepted
  if (lhs->accepted != rhs->accepted) {
    return false;
  }
  // stamp
  if (!builtin_interfaces__msg__Time__are_equal(
      &(lhs->stamp), &(rhs->stamp)))
  {
    return false;
  }
  return true;
}

bool
trafficrecord__action__VehWaitTime_SendGoal_Response__copy(
  const trafficrecord__action__VehWaitTime_SendGoal_Response * input,
  trafficrecord__action__VehWaitTime_SendGoal_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // accepted
  output->accepted = input->accepted;
  // stamp
  if (!builtin_interfaces__msg__Time__copy(
      &(input->stamp), &(output->stamp)))
  {
    return false;
  }
  return true;
}

trafficrecord__action__VehWaitTime_SendGoal_Response *
trafficrecord__action__VehWaitTime_SendGoal_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_SendGoal_Response * msg = (trafficrecord__action__VehWaitTime_SendGoal_Response *)allocator.allocate(sizeof(trafficrecord__action__VehWaitTime_SendGoal_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trafficrecord__action__VehWaitTime_SendGoal_Response));
  bool success = trafficrecord__action__VehWaitTime_SendGoal_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trafficrecord__action__VehWaitTime_SendGoal_Response__destroy(trafficrecord__action__VehWaitTime_SendGoal_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trafficrecord__action__VehWaitTime_SendGoal_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence__init(trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_SendGoal_Response * data = NULL;

  if (size) {
    data = (trafficrecord__action__VehWaitTime_SendGoal_Response *)allocator.zero_allocate(size, sizeof(trafficrecord__action__VehWaitTime_SendGoal_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trafficrecord__action__VehWaitTime_SendGoal_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trafficrecord__action__VehWaitTime_SendGoal_Response__fini(&data[i - 1]);
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
trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence__fini(trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence * array)
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
      trafficrecord__action__VehWaitTime_SendGoal_Response__fini(&array->data[i]);
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

trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence *
trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence * array = (trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence *)allocator.allocate(sizeof(trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence__destroy(trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence__are_equal(const trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence * lhs, const trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trafficrecord__action__VehWaitTime_SendGoal_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence__copy(
  const trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence * input,
  trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trafficrecord__action__VehWaitTime_SendGoal_Response);
    trafficrecord__action__VehWaitTime_SendGoal_Response * data =
      (trafficrecord__action__VehWaitTime_SendGoal_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trafficrecord__action__VehWaitTime_SendGoal_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          trafficrecord__action__VehWaitTime_SendGoal_Response__fini(&data[i]);
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
    if (!trafficrecord__action__VehWaitTime_SendGoal_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"

bool
trafficrecord__action__VehWaitTime_GetResult_Request__init(trafficrecord__action__VehWaitTime_GetResult_Request * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    trafficrecord__action__VehWaitTime_GetResult_Request__fini(msg);
    return false;
  }
  return true;
}

void
trafficrecord__action__VehWaitTime_GetResult_Request__fini(trafficrecord__action__VehWaitTime_GetResult_Request * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
}

bool
trafficrecord__action__VehWaitTime_GetResult_Request__are_equal(const trafficrecord__action__VehWaitTime_GetResult_Request * lhs, const trafficrecord__action__VehWaitTime_GetResult_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  return true;
}

bool
trafficrecord__action__VehWaitTime_GetResult_Request__copy(
  const trafficrecord__action__VehWaitTime_GetResult_Request * input,
  trafficrecord__action__VehWaitTime_GetResult_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  return true;
}

trafficrecord__action__VehWaitTime_GetResult_Request *
trafficrecord__action__VehWaitTime_GetResult_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_GetResult_Request * msg = (trafficrecord__action__VehWaitTime_GetResult_Request *)allocator.allocate(sizeof(trafficrecord__action__VehWaitTime_GetResult_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trafficrecord__action__VehWaitTime_GetResult_Request));
  bool success = trafficrecord__action__VehWaitTime_GetResult_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trafficrecord__action__VehWaitTime_GetResult_Request__destroy(trafficrecord__action__VehWaitTime_GetResult_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trafficrecord__action__VehWaitTime_GetResult_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trafficrecord__action__VehWaitTime_GetResult_Request__Sequence__init(trafficrecord__action__VehWaitTime_GetResult_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_GetResult_Request * data = NULL;

  if (size) {
    data = (trafficrecord__action__VehWaitTime_GetResult_Request *)allocator.zero_allocate(size, sizeof(trafficrecord__action__VehWaitTime_GetResult_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trafficrecord__action__VehWaitTime_GetResult_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trafficrecord__action__VehWaitTime_GetResult_Request__fini(&data[i - 1]);
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
trafficrecord__action__VehWaitTime_GetResult_Request__Sequence__fini(trafficrecord__action__VehWaitTime_GetResult_Request__Sequence * array)
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
      trafficrecord__action__VehWaitTime_GetResult_Request__fini(&array->data[i]);
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

trafficrecord__action__VehWaitTime_GetResult_Request__Sequence *
trafficrecord__action__VehWaitTime_GetResult_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_GetResult_Request__Sequence * array = (trafficrecord__action__VehWaitTime_GetResult_Request__Sequence *)allocator.allocate(sizeof(trafficrecord__action__VehWaitTime_GetResult_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trafficrecord__action__VehWaitTime_GetResult_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trafficrecord__action__VehWaitTime_GetResult_Request__Sequence__destroy(trafficrecord__action__VehWaitTime_GetResult_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trafficrecord__action__VehWaitTime_GetResult_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trafficrecord__action__VehWaitTime_GetResult_Request__Sequence__are_equal(const trafficrecord__action__VehWaitTime_GetResult_Request__Sequence * lhs, const trafficrecord__action__VehWaitTime_GetResult_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trafficrecord__action__VehWaitTime_GetResult_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trafficrecord__action__VehWaitTime_GetResult_Request__Sequence__copy(
  const trafficrecord__action__VehWaitTime_GetResult_Request__Sequence * input,
  trafficrecord__action__VehWaitTime_GetResult_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trafficrecord__action__VehWaitTime_GetResult_Request);
    trafficrecord__action__VehWaitTime_GetResult_Request * data =
      (trafficrecord__action__VehWaitTime_GetResult_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trafficrecord__action__VehWaitTime_GetResult_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          trafficrecord__action__VehWaitTime_GetResult_Request__fini(&data[i]);
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
    if (!trafficrecord__action__VehWaitTime_GetResult_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `result`
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__functions.h"

bool
trafficrecord__action__VehWaitTime_GetResult_Response__init(trafficrecord__action__VehWaitTime_GetResult_Response * msg)
{
  if (!msg) {
    return false;
  }
  // status
  // result
  if (!trafficrecord__action__VehWaitTime_Result__init(&msg->result)) {
    trafficrecord__action__VehWaitTime_GetResult_Response__fini(msg);
    return false;
  }
  return true;
}

void
trafficrecord__action__VehWaitTime_GetResult_Response__fini(trafficrecord__action__VehWaitTime_GetResult_Response * msg)
{
  if (!msg) {
    return;
  }
  // status
  // result
  trafficrecord__action__VehWaitTime_Result__fini(&msg->result);
}

bool
trafficrecord__action__VehWaitTime_GetResult_Response__are_equal(const trafficrecord__action__VehWaitTime_GetResult_Response * lhs, const trafficrecord__action__VehWaitTime_GetResult_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // result
  if (!trafficrecord__action__VehWaitTime_Result__are_equal(
      &(lhs->result), &(rhs->result)))
  {
    return false;
  }
  return true;
}

bool
trafficrecord__action__VehWaitTime_GetResult_Response__copy(
  const trafficrecord__action__VehWaitTime_GetResult_Response * input,
  trafficrecord__action__VehWaitTime_GetResult_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // status
  output->status = input->status;
  // result
  if (!trafficrecord__action__VehWaitTime_Result__copy(
      &(input->result), &(output->result)))
  {
    return false;
  }
  return true;
}

trafficrecord__action__VehWaitTime_GetResult_Response *
trafficrecord__action__VehWaitTime_GetResult_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_GetResult_Response * msg = (trafficrecord__action__VehWaitTime_GetResult_Response *)allocator.allocate(sizeof(trafficrecord__action__VehWaitTime_GetResult_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trafficrecord__action__VehWaitTime_GetResult_Response));
  bool success = trafficrecord__action__VehWaitTime_GetResult_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trafficrecord__action__VehWaitTime_GetResult_Response__destroy(trafficrecord__action__VehWaitTime_GetResult_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trafficrecord__action__VehWaitTime_GetResult_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trafficrecord__action__VehWaitTime_GetResult_Response__Sequence__init(trafficrecord__action__VehWaitTime_GetResult_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_GetResult_Response * data = NULL;

  if (size) {
    data = (trafficrecord__action__VehWaitTime_GetResult_Response *)allocator.zero_allocate(size, sizeof(trafficrecord__action__VehWaitTime_GetResult_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trafficrecord__action__VehWaitTime_GetResult_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trafficrecord__action__VehWaitTime_GetResult_Response__fini(&data[i - 1]);
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
trafficrecord__action__VehWaitTime_GetResult_Response__Sequence__fini(trafficrecord__action__VehWaitTime_GetResult_Response__Sequence * array)
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
      trafficrecord__action__VehWaitTime_GetResult_Response__fini(&array->data[i]);
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

trafficrecord__action__VehWaitTime_GetResult_Response__Sequence *
trafficrecord__action__VehWaitTime_GetResult_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_GetResult_Response__Sequence * array = (trafficrecord__action__VehWaitTime_GetResult_Response__Sequence *)allocator.allocate(sizeof(trafficrecord__action__VehWaitTime_GetResult_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trafficrecord__action__VehWaitTime_GetResult_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trafficrecord__action__VehWaitTime_GetResult_Response__Sequence__destroy(trafficrecord__action__VehWaitTime_GetResult_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trafficrecord__action__VehWaitTime_GetResult_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trafficrecord__action__VehWaitTime_GetResult_Response__Sequence__are_equal(const trafficrecord__action__VehWaitTime_GetResult_Response__Sequence * lhs, const trafficrecord__action__VehWaitTime_GetResult_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trafficrecord__action__VehWaitTime_GetResult_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trafficrecord__action__VehWaitTime_GetResult_Response__Sequence__copy(
  const trafficrecord__action__VehWaitTime_GetResult_Response__Sequence * input,
  trafficrecord__action__VehWaitTime_GetResult_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trafficrecord__action__VehWaitTime_GetResult_Response);
    trafficrecord__action__VehWaitTime_GetResult_Response * data =
      (trafficrecord__action__VehWaitTime_GetResult_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trafficrecord__action__VehWaitTime_GetResult_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          trafficrecord__action__VehWaitTime_GetResult_Response__fini(&data[i]);
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
    if (!trafficrecord__action__VehWaitTime_GetResult_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__functions.h"
// Member `feedback`
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__functions.h"

bool
trafficrecord__action__VehWaitTime_FeedbackMessage__init(trafficrecord__action__VehWaitTime_FeedbackMessage * msg)
{
  if (!msg) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__init(&msg->goal_id)) {
    trafficrecord__action__VehWaitTime_FeedbackMessage__fini(msg);
    return false;
  }
  // feedback
  if (!trafficrecord__action__VehWaitTime_Feedback__init(&msg->feedback)) {
    trafficrecord__action__VehWaitTime_FeedbackMessage__fini(msg);
    return false;
  }
  return true;
}

void
trafficrecord__action__VehWaitTime_FeedbackMessage__fini(trafficrecord__action__VehWaitTime_FeedbackMessage * msg)
{
  if (!msg) {
    return;
  }
  // goal_id
  unique_identifier_msgs__msg__UUID__fini(&msg->goal_id);
  // feedback
  trafficrecord__action__VehWaitTime_Feedback__fini(&msg->feedback);
}

bool
trafficrecord__action__VehWaitTime_FeedbackMessage__are_equal(const trafficrecord__action__VehWaitTime_FeedbackMessage * lhs, const trafficrecord__action__VehWaitTime_FeedbackMessage * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__are_equal(
      &(lhs->goal_id), &(rhs->goal_id)))
  {
    return false;
  }
  // feedback
  if (!trafficrecord__action__VehWaitTime_Feedback__are_equal(
      &(lhs->feedback), &(rhs->feedback)))
  {
    return false;
  }
  return true;
}

bool
trafficrecord__action__VehWaitTime_FeedbackMessage__copy(
  const trafficrecord__action__VehWaitTime_FeedbackMessage * input,
  trafficrecord__action__VehWaitTime_FeedbackMessage * output)
{
  if (!input || !output) {
    return false;
  }
  // goal_id
  if (!unique_identifier_msgs__msg__UUID__copy(
      &(input->goal_id), &(output->goal_id)))
  {
    return false;
  }
  // feedback
  if (!trafficrecord__action__VehWaitTime_Feedback__copy(
      &(input->feedback), &(output->feedback)))
  {
    return false;
  }
  return true;
}

trafficrecord__action__VehWaitTime_FeedbackMessage *
trafficrecord__action__VehWaitTime_FeedbackMessage__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_FeedbackMessage * msg = (trafficrecord__action__VehWaitTime_FeedbackMessage *)allocator.allocate(sizeof(trafficrecord__action__VehWaitTime_FeedbackMessage), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(trafficrecord__action__VehWaitTime_FeedbackMessage));
  bool success = trafficrecord__action__VehWaitTime_FeedbackMessage__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
trafficrecord__action__VehWaitTime_FeedbackMessage__destroy(trafficrecord__action__VehWaitTime_FeedbackMessage * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    trafficrecord__action__VehWaitTime_FeedbackMessage__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence__init(trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_FeedbackMessage * data = NULL;

  if (size) {
    data = (trafficrecord__action__VehWaitTime_FeedbackMessage *)allocator.zero_allocate(size, sizeof(trafficrecord__action__VehWaitTime_FeedbackMessage), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = trafficrecord__action__VehWaitTime_FeedbackMessage__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        trafficrecord__action__VehWaitTime_FeedbackMessage__fini(&data[i - 1]);
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
trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence__fini(trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence * array)
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
      trafficrecord__action__VehWaitTime_FeedbackMessage__fini(&array->data[i]);
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

trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence *
trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence * array = (trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence *)allocator.allocate(sizeof(trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence__destroy(trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence__are_equal(const trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence * lhs, const trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!trafficrecord__action__VehWaitTime_FeedbackMessage__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence__copy(
  const trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence * input,
  trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(trafficrecord__action__VehWaitTime_FeedbackMessage);
    trafficrecord__action__VehWaitTime_FeedbackMessage * data =
      (trafficrecord__action__VehWaitTime_FeedbackMessage *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!trafficrecord__action__VehWaitTime_FeedbackMessage__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          trafficrecord__action__VehWaitTime_FeedbackMessage__fini(&data[i]);
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
    if (!trafficrecord__action__VehWaitTime_FeedbackMessage__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
