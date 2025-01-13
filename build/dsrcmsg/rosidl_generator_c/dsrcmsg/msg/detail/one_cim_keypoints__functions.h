// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from dsrcmsg:msg/OneCIMKeypoints.idl
// generated code does not contain a copyright notice

#ifndef DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__FUNCTIONS_H_
#define DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "dsrcmsg/msg/rosidl_generator_c__visibility_control.h"

#include "dsrcmsg/msg/detail/one_cim_keypoints__struct.h"

/// Initialize msg/OneCIMKeypoints message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * dsrcmsg__msg__OneCIMKeypoints
 * )) before or use
 * dsrcmsg__msg__OneCIMKeypoints__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_dsrcmsg
bool
dsrcmsg__msg__OneCIMKeypoints__init(dsrcmsg__msg__OneCIMKeypoints * msg);

/// Finalize msg/OneCIMKeypoints message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dsrcmsg
void
dsrcmsg__msg__OneCIMKeypoints__fini(dsrcmsg__msg__OneCIMKeypoints * msg);

/// Create msg/OneCIMKeypoints message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * dsrcmsg__msg__OneCIMKeypoints__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dsrcmsg
dsrcmsg__msg__OneCIMKeypoints *
dsrcmsg__msg__OneCIMKeypoints__create();

/// Destroy msg/OneCIMKeypoints message.
/**
 * It calls
 * dsrcmsg__msg__OneCIMKeypoints__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dsrcmsg
void
dsrcmsg__msg__OneCIMKeypoints__destroy(dsrcmsg__msg__OneCIMKeypoints * msg);

/// Check for msg/OneCIMKeypoints message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dsrcmsg
bool
dsrcmsg__msg__OneCIMKeypoints__are_equal(const dsrcmsg__msg__OneCIMKeypoints * lhs, const dsrcmsg__msg__OneCIMKeypoints * rhs);

/// Copy a msg/OneCIMKeypoints message.
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
ROSIDL_GENERATOR_C_PUBLIC_dsrcmsg
bool
dsrcmsg__msg__OneCIMKeypoints__copy(
  const dsrcmsg__msg__OneCIMKeypoints * input,
  dsrcmsg__msg__OneCIMKeypoints * output);

/// Initialize array of msg/OneCIMKeypoints messages.
/**
 * It allocates the memory for the number of elements and calls
 * dsrcmsg__msg__OneCIMKeypoints__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_dsrcmsg
bool
dsrcmsg__msg__OneCIMKeypoints__Sequence__init(dsrcmsg__msg__OneCIMKeypoints__Sequence * array, size_t size);

/// Finalize array of msg/OneCIMKeypoints messages.
/**
 * It calls
 * dsrcmsg__msg__OneCIMKeypoints__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dsrcmsg
void
dsrcmsg__msg__OneCIMKeypoints__Sequence__fini(dsrcmsg__msg__OneCIMKeypoints__Sequence * array);

/// Create array of msg/OneCIMKeypoints messages.
/**
 * It allocates the memory for the array and calls
 * dsrcmsg__msg__OneCIMKeypoints__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_dsrcmsg
dsrcmsg__msg__OneCIMKeypoints__Sequence *
dsrcmsg__msg__OneCIMKeypoints__Sequence__create(size_t size);

/// Destroy array of msg/OneCIMKeypoints messages.
/**
 * It calls
 * dsrcmsg__msg__OneCIMKeypoints__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_dsrcmsg
void
dsrcmsg__msg__OneCIMKeypoints__Sequence__destroy(dsrcmsg__msg__OneCIMKeypoints__Sequence * array);

/// Check for msg/OneCIMKeypoints message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_dsrcmsg
bool
dsrcmsg__msg__OneCIMKeypoints__Sequence__are_equal(const dsrcmsg__msg__OneCIMKeypoints__Sequence * lhs, const dsrcmsg__msg__OneCIMKeypoints__Sequence * rhs);

/// Copy an array of msg/OneCIMKeypoints messages.
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
ROSIDL_GENERATOR_C_PUBLIC_dsrcmsg
bool
dsrcmsg__msg__OneCIMKeypoints__Sequence__copy(
  const dsrcmsg__msg__OneCIMKeypoints__Sequence * input,
  dsrcmsg__msg__OneCIMKeypoints__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // DSRCMSG__MSG__DETAIL__ONE_CIM_KEYPOINTS__FUNCTIONS_H_
