// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from navi_interface:srv/Upload.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "navi_interface/srv/detail/upload__rosidl_typesupport_introspection_c.h"
#include "navi_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "navi_interface/srv/detail/upload__functions.h"
#include "navi_interface/srv/detail/upload__struct.h"


// Include directives for member types
// Member `image`
#include "sensor_msgs/msg/image.h"
// Member `image`
#include "sensor_msgs/msg/detail/image__rosidl_typesupport_introspection_c.h"
// Member `instruction`
// Member `task_type`
// Member `target_pose`
// Member `start_pose`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Upload_Request__rosidl_typesupport_introspection_c__Upload_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  navi_interface__srv__Upload_Request__init(message_memory);
}

void Upload_Request__rosidl_typesupport_introspection_c__Upload_Request_fini_function(void * message_memory)
{
  navi_interface__srv__Upload_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Upload_Request__rosidl_typesupport_introspection_c__Upload_Request_message_member_array[6] = {
  {
    "image",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(navi_interface__srv__Upload_Request, image),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "instruction",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(navi_interface__srv__Upload_Request, instruction),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "task_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(navi_interface__srv__Upload_Request, task_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "step",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(navi_interface__srv__Upload_Request, step),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(navi_interface__srv__Upload_Request, target_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "start_pose",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(navi_interface__srv__Upload_Request, start_pose),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Upload_Request__rosidl_typesupport_introspection_c__Upload_Request_message_members = {
  "navi_interface__srv",  // message namespace
  "Upload_Request",  // message name
  6,  // number of fields
  sizeof(navi_interface__srv__Upload_Request),
  Upload_Request__rosidl_typesupport_introspection_c__Upload_Request_message_member_array,  // message members
  Upload_Request__rosidl_typesupport_introspection_c__Upload_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  Upload_Request__rosidl_typesupport_introspection_c__Upload_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Upload_Request__rosidl_typesupport_introspection_c__Upload_Request_message_type_support_handle = {
  0,
  &Upload_Request__rosidl_typesupport_introspection_c__Upload_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_navi_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navi_interface, srv, Upload_Request)() {
  Upload_Request__rosidl_typesupport_introspection_c__Upload_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, sensor_msgs, msg, Image)();
  if (!Upload_Request__rosidl_typesupport_introspection_c__Upload_Request_message_type_support_handle.typesupport_identifier) {
    Upload_Request__rosidl_typesupport_introspection_c__Upload_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Upload_Request__rosidl_typesupport_introspection_c__Upload_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "navi_interface/srv/detail/upload__rosidl_typesupport_introspection_c.h"
// already included above
// #include "navi_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "navi_interface/srv/detail/upload__functions.h"
// already included above
// #include "navi_interface/srv/detail/upload__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void Upload_Response__rosidl_typesupport_introspection_c__Upload_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  navi_interface__srv__Upload_Response__init(message_memory);
}

void Upload_Response__rosidl_typesupport_introspection_c__Upload_Response_fini_function(void * message_memory)
{
  navi_interface__srv__Upload_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember Upload_Response__rosidl_typesupport_introspection_c__Upload_Response_message_member_array[1] = {
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(navi_interface__srv__Upload_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers Upload_Response__rosidl_typesupport_introspection_c__Upload_Response_message_members = {
  "navi_interface__srv",  // message namespace
  "Upload_Response",  // message name
  1,  // number of fields
  sizeof(navi_interface__srv__Upload_Response),
  Upload_Response__rosidl_typesupport_introspection_c__Upload_Response_message_member_array,  // message members
  Upload_Response__rosidl_typesupport_introspection_c__Upload_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  Upload_Response__rosidl_typesupport_introspection_c__Upload_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t Upload_Response__rosidl_typesupport_introspection_c__Upload_Response_message_type_support_handle = {
  0,
  &Upload_Response__rosidl_typesupport_introspection_c__Upload_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_navi_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navi_interface, srv, Upload_Response)() {
  if (!Upload_Response__rosidl_typesupport_introspection_c__Upload_Response_message_type_support_handle.typesupport_identifier) {
    Upload_Response__rosidl_typesupport_introspection_c__Upload_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &Upload_Response__rosidl_typesupport_introspection_c__Upload_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "navi_interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "navi_interface/srv/detail/upload__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers navi_interface__srv__detail__upload__rosidl_typesupport_introspection_c__Upload_service_members = {
  "navi_interface__srv",  // service namespace
  "Upload",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // navi_interface__srv__detail__upload__rosidl_typesupport_introspection_c__Upload_Request_message_type_support_handle,
  NULL  // response message
  // navi_interface__srv__detail__upload__rosidl_typesupport_introspection_c__Upload_Response_message_type_support_handle
};

static rosidl_service_type_support_t navi_interface__srv__detail__upload__rosidl_typesupport_introspection_c__Upload_service_type_support_handle = {
  0,
  &navi_interface__srv__detail__upload__rosidl_typesupport_introspection_c__Upload_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navi_interface, srv, Upload_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navi_interface, srv, Upload_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_navi_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navi_interface, srv, Upload)() {
  if (!navi_interface__srv__detail__upload__rosidl_typesupport_introspection_c__Upload_service_type_support_handle.typesupport_identifier) {
    navi_interface__srv__detail__upload__rosidl_typesupport_introspection_c__Upload_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)navi_interface__srv__detail__upload__rosidl_typesupport_introspection_c__Upload_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navi_interface, srv, Upload_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, navi_interface, srv, Upload_Response)()->data;
  }

  return &navi_interface__srv__detail__upload__rosidl_typesupport_introspection_c__Upload_service_type_support_handle;
}
