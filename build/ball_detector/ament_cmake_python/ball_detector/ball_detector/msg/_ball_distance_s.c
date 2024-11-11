// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from ball_detector:msg/BallDistance.idl
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
#include "ball_detector/msg/detail/ball_distance__struct.h"
#include "ball_detector/msg/detail/ball_distance__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool ball_detector__msg__ball_distance__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[46];
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
    assert(strncmp("ball_detector.msg._ball_distance.BallDistance", full_classname_dest, 45) == 0);
  }
  ball_detector__msg__BallDistance * ros_message = _ros_message;
  {  // ball_ada_cok
    PyObject * field = PyObject_GetAttrString(_pymsg, "ball_ada_cok");
    if (!field) {
      return false;
    }
    assert(PyBool_Check(field));
    ros_message->ball_ada_cok = (Py_True == field);
    Py_DECREF(field);
  }
  {  // jaraknya_jing
    PyObject * field = PyObject_GetAttrString(_pymsg, "jaraknya_jing");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->jaraknya_jing = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * ball_detector__msg__ball_distance__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of BallDistance */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("ball_detector.msg._ball_distance");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "BallDistance");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  ball_detector__msg__BallDistance * ros_message = (ball_detector__msg__BallDistance *)raw_ros_message;
  {  // ball_ada_cok
    PyObject * field = NULL;
    field = PyBool_FromLong(ros_message->ball_ada_cok ? 1 : 0);
    {
      int rc = PyObject_SetAttrString(_pymessage, "ball_ada_cok", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // jaraknya_jing
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->jaraknya_jing);
    {
      int rc = PyObject_SetAttrString(_pymessage, "jaraknya_jing", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
