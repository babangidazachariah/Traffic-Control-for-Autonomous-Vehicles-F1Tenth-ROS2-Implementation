// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from trafficrecord:action/VehWaitTime.idl
// generated code does not contain a copyright notice

#ifndef TRAFFICRECORD__ACTION__DETAIL__VEH_WAIT_TIME__FUNCTIONS_H_
#define TRAFFICRECORD__ACTION__DETAIL__VEH_WAIT_TIME__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "trafficrecord/msg/rosidl_generator_c__visibility_control.h"

#include "trafficrecord/action/detail/veh_wait_time__struct.h"

/// Initialize action/VehWaitTime message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trafficrecord__action__VehWaitTime_Goal
 * )) before or use
 * trafficrecord__action__VehWaitTime_Goal__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Goal__init(trafficrecord__action__VehWaitTime_Goal * msg);

/// Finalize action/VehWaitTime message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_Goal__fini(trafficrecord__action__VehWaitTime_Goal * msg);

/// Create action/VehWaitTime message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trafficrecord__action__VehWaitTime_Goal__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
trafficrecord__action__VehWaitTime_Goal *
trafficrecord__action__VehWaitTime_Goal__create();

/// Destroy action/VehWaitTime message.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_Goal__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_Goal__destroy(trafficrecord__action__VehWaitTime_Goal * msg);

/// Check for action/VehWaitTime message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Goal__are_equal(const trafficrecord__action__VehWaitTime_Goal * lhs, const trafficrecord__action__VehWaitTime_Goal * rhs);

/// Copy a action/VehWaitTime message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Goal__copy(
  const trafficrecord__action__VehWaitTime_Goal * input,
  trafficrecord__action__VehWaitTime_Goal * output);

/// Initialize array of action/VehWaitTime messages.
/**
 * It allocates the memory for the number of elements and calls
 * trafficrecord__action__VehWaitTime_Goal__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Goal__Sequence__init(trafficrecord__action__VehWaitTime_Goal__Sequence * array, size_t size);

/// Finalize array of action/VehWaitTime messages.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_Goal__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_Goal__Sequence__fini(trafficrecord__action__VehWaitTime_Goal__Sequence * array);

/// Create array of action/VehWaitTime messages.
/**
 * It allocates the memory for the array and calls
 * trafficrecord__action__VehWaitTime_Goal__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
trafficrecord__action__VehWaitTime_Goal__Sequence *
trafficrecord__action__VehWaitTime_Goal__Sequence__create(size_t size);

/// Destroy array of action/VehWaitTime messages.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_Goal__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_Goal__Sequence__destroy(trafficrecord__action__VehWaitTime_Goal__Sequence * array);

/// Check for action/VehWaitTime message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Goal__Sequence__are_equal(const trafficrecord__action__VehWaitTime_Goal__Sequence * lhs, const trafficrecord__action__VehWaitTime_Goal__Sequence * rhs);

/// Copy an array of action/VehWaitTime messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Goal__Sequence__copy(
  const trafficrecord__action__VehWaitTime_Goal__Sequence * input,
  trafficrecord__action__VehWaitTime_Goal__Sequence * output);

/// Initialize action/VehWaitTime message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trafficrecord__action__VehWaitTime_Result
 * )) before or use
 * trafficrecord__action__VehWaitTime_Result__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Result__init(trafficrecord__action__VehWaitTime_Result * msg);

/// Finalize action/VehWaitTime message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_Result__fini(trafficrecord__action__VehWaitTime_Result * msg);

/// Create action/VehWaitTime message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trafficrecord__action__VehWaitTime_Result__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
trafficrecord__action__VehWaitTime_Result *
trafficrecord__action__VehWaitTime_Result__create();

/// Destroy action/VehWaitTime message.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_Result__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_Result__destroy(trafficrecord__action__VehWaitTime_Result * msg);

/// Check for action/VehWaitTime message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Result__are_equal(const trafficrecord__action__VehWaitTime_Result * lhs, const trafficrecord__action__VehWaitTime_Result * rhs);

/// Copy a action/VehWaitTime message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Result__copy(
  const trafficrecord__action__VehWaitTime_Result * input,
  trafficrecord__action__VehWaitTime_Result * output);

/// Initialize array of action/VehWaitTime messages.
/**
 * It allocates the memory for the number of elements and calls
 * trafficrecord__action__VehWaitTime_Result__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Result__Sequence__init(trafficrecord__action__VehWaitTime_Result__Sequence * array, size_t size);

/// Finalize array of action/VehWaitTime messages.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_Result__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_Result__Sequence__fini(trafficrecord__action__VehWaitTime_Result__Sequence * array);

/// Create array of action/VehWaitTime messages.
/**
 * It allocates the memory for the array and calls
 * trafficrecord__action__VehWaitTime_Result__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
trafficrecord__action__VehWaitTime_Result__Sequence *
trafficrecord__action__VehWaitTime_Result__Sequence__create(size_t size);

/// Destroy array of action/VehWaitTime messages.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_Result__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_Result__Sequence__destroy(trafficrecord__action__VehWaitTime_Result__Sequence * array);

/// Check for action/VehWaitTime message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Result__Sequence__are_equal(const trafficrecord__action__VehWaitTime_Result__Sequence * lhs, const trafficrecord__action__VehWaitTime_Result__Sequence * rhs);

/// Copy an array of action/VehWaitTime messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Result__Sequence__copy(
  const trafficrecord__action__VehWaitTime_Result__Sequence * input,
  trafficrecord__action__VehWaitTime_Result__Sequence * output);

/// Initialize action/VehWaitTime message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trafficrecord__action__VehWaitTime_Feedback
 * )) before or use
 * trafficrecord__action__VehWaitTime_Feedback__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Feedback__init(trafficrecord__action__VehWaitTime_Feedback * msg);

/// Finalize action/VehWaitTime message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_Feedback__fini(trafficrecord__action__VehWaitTime_Feedback * msg);

/// Create action/VehWaitTime message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trafficrecord__action__VehWaitTime_Feedback__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
trafficrecord__action__VehWaitTime_Feedback *
trafficrecord__action__VehWaitTime_Feedback__create();

/// Destroy action/VehWaitTime message.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_Feedback__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_Feedback__destroy(trafficrecord__action__VehWaitTime_Feedback * msg);

/// Check for action/VehWaitTime message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Feedback__are_equal(const trafficrecord__action__VehWaitTime_Feedback * lhs, const trafficrecord__action__VehWaitTime_Feedback * rhs);

/// Copy a action/VehWaitTime message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Feedback__copy(
  const trafficrecord__action__VehWaitTime_Feedback * input,
  trafficrecord__action__VehWaitTime_Feedback * output);

/// Initialize array of action/VehWaitTime messages.
/**
 * It allocates the memory for the number of elements and calls
 * trafficrecord__action__VehWaitTime_Feedback__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Feedback__Sequence__init(trafficrecord__action__VehWaitTime_Feedback__Sequence * array, size_t size);

/// Finalize array of action/VehWaitTime messages.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_Feedback__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_Feedback__Sequence__fini(trafficrecord__action__VehWaitTime_Feedback__Sequence * array);

/// Create array of action/VehWaitTime messages.
/**
 * It allocates the memory for the array and calls
 * trafficrecord__action__VehWaitTime_Feedback__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
trafficrecord__action__VehWaitTime_Feedback__Sequence *
trafficrecord__action__VehWaitTime_Feedback__Sequence__create(size_t size);

/// Destroy array of action/VehWaitTime messages.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_Feedback__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_Feedback__Sequence__destroy(trafficrecord__action__VehWaitTime_Feedback__Sequence * array);

/// Check for action/VehWaitTime message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Feedback__Sequence__are_equal(const trafficrecord__action__VehWaitTime_Feedback__Sequence * lhs, const trafficrecord__action__VehWaitTime_Feedback__Sequence * rhs);

/// Copy an array of action/VehWaitTime messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_Feedback__Sequence__copy(
  const trafficrecord__action__VehWaitTime_Feedback__Sequence * input,
  trafficrecord__action__VehWaitTime_Feedback__Sequence * output);

/// Initialize action/VehWaitTime message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trafficrecord__action__VehWaitTime_SendGoal_Request
 * )) before or use
 * trafficrecord__action__VehWaitTime_SendGoal_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_SendGoal_Request__init(trafficrecord__action__VehWaitTime_SendGoal_Request * msg);

/// Finalize action/VehWaitTime message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_SendGoal_Request__fini(trafficrecord__action__VehWaitTime_SendGoal_Request * msg);

/// Create action/VehWaitTime message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trafficrecord__action__VehWaitTime_SendGoal_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
trafficrecord__action__VehWaitTime_SendGoal_Request *
trafficrecord__action__VehWaitTime_SendGoal_Request__create();

/// Destroy action/VehWaitTime message.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_SendGoal_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_SendGoal_Request__destroy(trafficrecord__action__VehWaitTime_SendGoal_Request * msg);

/// Check for action/VehWaitTime message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_SendGoal_Request__are_equal(const trafficrecord__action__VehWaitTime_SendGoal_Request * lhs, const trafficrecord__action__VehWaitTime_SendGoal_Request * rhs);

/// Copy a action/VehWaitTime message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_SendGoal_Request__copy(
  const trafficrecord__action__VehWaitTime_SendGoal_Request * input,
  trafficrecord__action__VehWaitTime_SendGoal_Request * output);

/// Initialize array of action/VehWaitTime messages.
/**
 * It allocates the memory for the number of elements and calls
 * trafficrecord__action__VehWaitTime_SendGoal_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence__init(trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence * array, size_t size);

/// Finalize array of action/VehWaitTime messages.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_SendGoal_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence__fini(trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence * array);

/// Create array of action/VehWaitTime messages.
/**
 * It allocates the memory for the array and calls
 * trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence *
trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence__create(size_t size);

/// Destroy array of action/VehWaitTime messages.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence__destroy(trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence * array);

/// Check for action/VehWaitTime message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence__are_equal(const trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence * lhs, const trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence * rhs);

/// Copy an array of action/VehWaitTime messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence__copy(
  const trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence * input,
  trafficrecord__action__VehWaitTime_SendGoal_Request__Sequence * output);

/// Initialize action/VehWaitTime message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trafficrecord__action__VehWaitTime_SendGoal_Response
 * )) before or use
 * trafficrecord__action__VehWaitTime_SendGoal_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_SendGoal_Response__init(trafficrecord__action__VehWaitTime_SendGoal_Response * msg);

/// Finalize action/VehWaitTime message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_SendGoal_Response__fini(trafficrecord__action__VehWaitTime_SendGoal_Response * msg);

/// Create action/VehWaitTime message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trafficrecord__action__VehWaitTime_SendGoal_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
trafficrecord__action__VehWaitTime_SendGoal_Response *
trafficrecord__action__VehWaitTime_SendGoal_Response__create();

/// Destroy action/VehWaitTime message.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_SendGoal_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_SendGoal_Response__destroy(trafficrecord__action__VehWaitTime_SendGoal_Response * msg);

/// Check for action/VehWaitTime message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_SendGoal_Response__are_equal(const trafficrecord__action__VehWaitTime_SendGoal_Response * lhs, const trafficrecord__action__VehWaitTime_SendGoal_Response * rhs);

/// Copy a action/VehWaitTime message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_SendGoal_Response__copy(
  const trafficrecord__action__VehWaitTime_SendGoal_Response * input,
  trafficrecord__action__VehWaitTime_SendGoal_Response * output);

/// Initialize array of action/VehWaitTime messages.
/**
 * It allocates the memory for the number of elements and calls
 * trafficrecord__action__VehWaitTime_SendGoal_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence__init(trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence * array, size_t size);

/// Finalize array of action/VehWaitTime messages.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_SendGoal_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence__fini(trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence * array);

/// Create array of action/VehWaitTime messages.
/**
 * It allocates the memory for the array and calls
 * trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence *
trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence__create(size_t size);

/// Destroy array of action/VehWaitTime messages.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence__destroy(trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence * array);

/// Check for action/VehWaitTime message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence__are_equal(const trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence * lhs, const trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence * rhs);

/// Copy an array of action/VehWaitTime messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence__copy(
  const trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence * input,
  trafficrecord__action__VehWaitTime_SendGoal_Response__Sequence * output);

/// Initialize action/VehWaitTime message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trafficrecord__action__VehWaitTime_GetResult_Request
 * )) before or use
 * trafficrecord__action__VehWaitTime_GetResult_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_GetResult_Request__init(trafficrecord__action__VehWaitTime_GetResult_Request * msg);

/// Finalize action/VehWaitTime message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_GetResult_Request__fini(trafficrecord__action__VehWaitTime_GetResult_Request * msg);

/// Create action/VehWaitTime message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trafficrecord__action__VehWaitTime_GetResult_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
trafficrecord__action__VehWaitTime_GetResult_Request *
trafficrecord__action__VehWaitTime_GetResult_Request__create();

/// Destroy action/VehWaitTime message.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_GetResult_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_GetResult_Request__destroy(trafficrecord__action__VehWaitTime_GetResult_Request * msg);

/// Check for action/VehWaitTime message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_GetResult_Request__are_equal(const trafficrecord__action__VehWaitTime_GetResult_Request * lhs, const trafficrecord__action__VehWaitTime_GetResult_Request * rhs);

/// Copy a action/VehWaitTime message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_GetResult_Request__copy(
  const trafficrecord__action__VehWaitTime_GetResult_Request * input,
  trafficrecord__action__VehWaitTime_GetResult_Request * output);

/// Initialize array of action/VehWaitTime messages.
/**
 * It allocates the memory for the number of elements and calls
 * trafficrecord__action__VehWaitTime_GetResult_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_GetResult_Request__Sequence__init(trafficrecord__action__VehWaitTime_GetResult_Request__Sequence * array, size_t size);

/// Finalize array of action/VehWaitTime messages.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_GetResult_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_GetResult_Request__Sequence__fini(trafficrecord__action__VehWaitTime_GetResult_Request__Sequence * array);

/// Create array of action/VehWaitTime messages.
/**
 * It allocates the memory for the array and calls
 * trafficrecord__action__VehWaitTime_GetResult_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
trafficrecord__action__VehWaitTime_GetResult_Request__Sequence *
trafficrecord__action__VehWaitTime_GetResult_Request__Sequence__create(size_t size);

/// Destroy array of action/VehWaitTime messages.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_GetResult_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_GetResult_Request__Sequence__destroy(trafficrecord__action__VehWaitTime_GetResult_Request__Sequence * array);

/// Check for action/VehWaitTime message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_GetResult_Request__Sequence__are_equal(const trafficrecord__action__VehWaitTime_GetResult_Request__Sequence * lhs, const trafficrecord__action__VehWaitTime_GetResult_Request__Sequence * rhs);

/// Copy an array of action/VehWaitTime messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_GetResult_Request__Sequence__copy(
  const trafficrecord__action__VehWaitTime_GetResult_Request__Sequence * input,
  trafficrecord__action__VehWaitTime_GetResult_Request__Sequence * output);

/// Initialize action/VehWaitTime message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trafficrecord__action__VehWaitTime_GetResult_Response
 * )) before or use
 * trafficrecord__action__VehWaitTime_GetResult_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_GetResult_Response__init(trafficrecord__action__VehWaitTime_GetResult_Response * msg);

/// Finalize action/VehWaitTime message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_GetResult_Response__fini(trafficrecord__action__VehWaitTime_GetResult_Response * msg);

/// Create action/VehWaitTime message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trafficrecord__action__VehWaitTime_GetResult_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
trafficrecord__action__VehWaitTime_GetResult_Response *
trafficrecord__action__VehWaitTime_GetResult_Response__create();

/// Destroy action/VehWaitTime message.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_GetResult_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_GetResult_Response__destroy(trafficrecord__action__VehWaitTime_GetResult_Response * msg);

/// Check for action/VehWaitTime message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_GetResult_Response__are_equal(const trafficrecord__action__VehWaitTime_GetResult_Response * lhs, const trafficrecord__action__VehWaitTime_GetResult_Response * rhs);

/// Copy a action/VehWaitTime message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_GetResult_Response__copy(
  const trafficrecord__action__VehWaitTime_GetResult_Response * input,
  trafficrecord__action__VehWaitTime_GetResult_Response * output);

/// Initialize array of action/VehWaitTime messages.
/**
 * It allocates the memory for the number of elements and calls
 * trafficrecord__action__VehWaitTime_GetResult_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_GetResult_Response__Sequence__init(trafficrecord__action__VehWaitTime_GetResult_Response__Sequence * array, size_t size);

/// Finalize array of action/VehWaitTime messages.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_GetResult_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_GetResult_Response__Sequence__fini(trafficrecord__action__VehWaitTime_GetResult_Response__Sequence * array);

/// Create array of action/VehWaitTime messages.
/**
 * It allocates the memory for the array and calls
 * trafficrecord__action__VehWaitTime_GetResult_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
trafficrecord__action__VehWaitTime_GetResult_Response__Sequence *
trafficrecord__action__VehWaitTime_GetResult_Response__Sequence__create(size_t size);

/// Destroy array of action/VehWaitTime messages.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_GetResult_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_GetResult_Response__Sequence__destroy(trafficrecord__action__VehWaitTime_GetResult_Response__Sequence * array);

/// Check for action/VehWaitTime message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_GetResult_Response__Sequence__are_equal(const trafficrecord__action__VehWaitTime_GetResult_Response__Sequence * lhs, const trafficrecord__action__VehWaitTime_GetResult_Response__Sequence * rhs);

/// Copy an array of action/VehWaitTime messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_GetResult_Response__Sequence__copy(
  const trafficrecord__action__VehWaitTime_GetResult_Response__Sequence * input,
  trafficrecord__action__VehWaitTime_GetResult_Response__Sequence * output);

/// Initialize action/VehWaitTime message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * trafficrecord__action__VehWaitTime_FeedbackMessage
 * )) before or use
 * trafficrecord__action__VehWaitTime_FeedbackMessage__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_FeedbackMessage__init(trafficrecord__action__VehWaitTime_FeedbackMessage * msg);

/// Finalize action/VehWaitTime message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_FeedbackMessage__fini(trafficrecord__action__VehWaitTime_FeedbackMessage * msg);

/// Create action/VehWaitTime message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * trafficrecord__action__VehWaitTime_FeedbackMessage__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
trafficrecord__action__VehWaitTime_FeedbackMessage *
trafficrecord__action__VehWaitTime_FeedbackMessage__create();

/// Destroy action/VehWaitTime message.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_FeedbackMessage__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_FeedbackMessage__destroy(trafficrecord__action__VehWaitTime_FeedbackMessage * msg);

/// Check for action/VehWaitTime message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_FeedbackMessage__are_equal(const trafficrecord__action__VehWaitTime_FeedbackMessage * lhs, const trafficrecord__action__VehWaitTime_FeedbackMessage * rhs);

/// Copy a action/VehWaitTime message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_FeedbackMessage__copy(
  const trafficrecord__action__VehWaitTime_FeedbackMessage * input,
  trafficrecord__action__VehWaitTime_FeedbackMessage * output);

/// Initialize array of action/VehWaitTime messages.
/**
 * It allocates the memory for the number of elements and calls
 * trafficrecord__action__VehWaitTime_FeedbackMessage__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence__init(trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence * array, size_t size);

/// Finalize array of action/VehWaitTime messages.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_FeedbackMessage__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence__fini(trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence * array);

/// Create array of action/VehWaitTime messages.
/**
 * It allocates the memory for the array and calls
 * trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence *
trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence__create(size_t size);

/// Destroy array of action/VehWaitTime messages.
/**
 * It calls
 * trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
void
trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence__destroy(trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence * array);

/// Check for action/VehWaitTime message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence__are_equal(const trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence * lhs, const trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence * rhs);

/// Copy an array of action/VehWaitTime messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_trafficrecord
bool
trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence__copy(
  const trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence * input,
  trafficrecord__action__VehWaitTime_FeedbackMessage__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // TRAFFICRECORD__ACTION__DETAIL__VEH_WAIT_TIME__FUNCTIONS_H_
