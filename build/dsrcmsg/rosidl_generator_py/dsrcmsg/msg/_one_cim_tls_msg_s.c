// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from dsrcmsg:msg/OneCIMTlsMsg.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "dsrcmsg/msg/detail/one_cim_tls_msg__struct.h"
#include "dsrcmsg/msg/detail/one_cim_tls_msg__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "dsrcmsg/msg/detail/one_cim_keypoints__functions.h"
// end nested array functions include
bool dsrcmsg__msg__one_cim_keypoints__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * dsrcmsg__msg__one_cim_keypoints__convert_to_py(void * raw_ros_message);
bool dsrcmsg__msg__one_cim_keypoints__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * dsrcmsg__msg__one_cim_keypoints__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool dsrcmsg__msg__one_cim_tls_msg__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[42];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("dsrcmsg.msg._one_cim_tls_msg.OneCIMTlsMsg", full_classname_dest, 41) == 0);
  }
  dsrcmsg__msg__OneCIMTlsMsg * ros_message = _ros_message;
  {  // junctionid
    PyObject * field = PyObject_GetAttrString(_pymsg, "junctionid");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->junctionid, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // vehicleid
    PyObject * field = PyObject_GetAttrString(_pymsg, "vehicleid");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->vehicleid, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // pathids
    PyObject * field = PyObject_GetAttrString(_pymsg, "pathids");
    if (!field) {
      return false;
    }
    {
      PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'pathids'");
      if (!seq_field) {
        Py_DECREF(field);
        return false;
      }
      Py_ssize_t size = PySequence_Size(field);
      if (-1 == size) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      if (!rosidl_runtime_c__String__Sequence__init(&(ros_message->pathids), size)) {
        PyErr_SetString(PyExc_RuntimeError, "unable to create String__Sequence ros_message");
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
      rosidl_runtime_c__String * dest = ros_message->pathids.data;
      for (Py_ssize_t i = 0; i < size; ++i) {
        PyObject * item = PySequence_Fast_GET_ITEM(seq_field, i);
        if (!item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        assert(PyUnicode_Check(item));
        PyObject * encoded_item = PyUnicode_AsUTF8String(item);
        if (!encoded_item) {
          Py_DECREF(seq_field);
          Py_DECREF(field);
          return false;
        }
        rosidl_runtime_c__String__assign(&dest[i], PyBytes_AS_STRING(encoded_item));
        Py_DECREF(encoded_item);
      }
      Py_DECREF(seq_field);
    }
    Py_DECREF(field);
  }
  {  // starttime
    PyObject * field = PyObject_GetAttrString(_pymsg, "starttime");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->starttime = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // duration
    PyObject * field = PyObject_GetAttrString(_pymsg, "duration");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->duration = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // approachpoints
    PyObject * field = PyObject_GetAttrString(_pymsg, "approachpoints");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'approachpoints'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!dsrcmsg__msg__OneCIMKeypoints__Sequence__init(&(ros_message->approachpoints), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create dsrcmsg__msg__OneCIMKeypoints__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    dsrcmsg__msg__OneCIMKeypoints * dest = ros_message->approachpoints.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!dsrcmsg__msg__one_cim_keypoints__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // departpoints
    PyObject * field = PyObject_GetAttrString(_pymsg, "departpoints");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'departpoints'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!dsrcmsg__msg__OneCIMKeypoints__Sequence__init(&(ros_message->departpoints), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create dsrcmsg__msg__OneCIMKeypoints__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    dsrcmsg__msg__OneCIMKeypoints * dest = ros_message->departpoints.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!dsrcmsg__msg__one_cim_keypoints__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }
  {  // speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * dsrcmsg__msg__one_cim_tls_msg__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of OneCIMTlsMsg */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("dsrcmsg.msg._one_cim_tls_msg");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "OneCIMTlsMsg");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  dsrcmsg__msg__OneCIMTlsMsg * ros_message = (dsrcmsg__msg__OneCIMTlsMsg *)raw_ros_message;
  {  // junctionid
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->junctionid.data,
      strlen(ros_message->junctionid.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "junctionid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // vehicleid
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->vehicleid.data,
      strlen(ros_message->vehicleid.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "vehicleid", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // pathids
    PyObject * field = NULL;
    size_t size = ros_message->pathids.size;
    rosidl_runtime_c__String * src = ros_message->pathids.data;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    for (size_t i = 0; i < size; ++i) {
      PyObject * decoded_item = PyUnicode_DecodeUTF8(src[i].data, strlen(src[i].data), "replace");
      if (!decoded_item) {
        return NULL;
      }
      int rc = PyList_SetItem(field, i, decoded_item);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "pathids", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // starttime
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->starttime);
    {
      int rc = PyObject_SetAttrString(_pymessage, "starttime", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // duration
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->duration);
    {
      int rc = PyObject_SetAttrString(_pymessage, "duration", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // approachpoints
    PyObject * field = NULL;
    size_t size = ros_message->approachpoints.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    dsrcmsg__msg__OneCIMKeypoints * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->approachpoints.data[i]);
      PyObject * pyitem = dsrcmsg__msg__one_cim_keypoints__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "approachpoints", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // departpoints
    PyObject * field = NULL;
    size_t size = ros_message->departpoints.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    dsrcmsg__msg__OneCIMKeypoints * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->departpoints.data[i]);
      PyObject * pyitem = dsrcmsg__msg__one_cim_keypoints__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "departpoints", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
