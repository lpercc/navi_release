// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from navi_interface:srv/Upload.idl
// generated code does not contain a copyright notice

#ifndef NAVI_INTERFACE__SRV__DETAIL__UPLOAD__STRUCT_H_
#define NAVI_INTERFACE__SRV__DETAIL__UPLOAD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.h"
// Member 'instruction'
// Member 'task_type'
// Member 'target_pose'
// Member 'start_pose'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/Upload in the package navi_interface.
typedef struct navi_interface__srv__Upload_Request
{
  sensor_msgs__msg__Image image;
  rosidl_runtime_c__String instruction;
  rosidl_runtime_c__String task_type;
  uint32_t step;
  rosidl_runtime_c__String target_pose;
  rosidl_runtime_c__String start_pose;
} navi_interface__srv__Upload_Request;

// Struct for a sequence of navi_interface__srv__Upload_Request.
typedef struct navi_interface__srv__Upload_Request__Sequence
{
  navi_interface__srv__Upload_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} navi_interface__srv__Upload_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'result'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in srv/Upload in the package navi_interface.
typedef struct navi_interface__srv__Upload_Response
{
  rosidl_runtime_c__String result;
} navi_interface__srv__Upload_Response;

// Struct for a sequence of navi_interface__srv__Upload_Response.
typedef struct navi_interface__srv__Upload_Response__Sequence
{
  navi_interface__srv__Upload_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} navi_interface__srv__Upload_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // NAVI_INTERFACE__SRV__DETAIL__UPLOAD__STRUCT_H_
