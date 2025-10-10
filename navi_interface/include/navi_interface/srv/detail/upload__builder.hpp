// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from navi_interface:srv/Upload.idl
// generated code does not contain a copyright notice

#ifndef NAVI_INTERFACE__SRV__DETAIL__UPLOAD__BUILDER_HPP_
#define NAVI_INTERFACE__SRV__DETAIL__UPLOAD__BUILDER_HPP_

#include "navi_interface/srv/detail/upload__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace navi_interface
{

namespace srv
{

namespace builder
{

class Init_Upload_Request_start_pose
{
public:
  explicit Init_Upload_Request_start_pose(::navi_interface::srv::Upload_Request & msg)
  : msg_(msg)
  {}
  ::navi_interface::srv::Upload_Request start_pose(::navi_interface::srv::Upload_Request::_start_pose_type arg)
  {
    msg_.start_pose = std::move(arg);
    return std::move(msg_);
  }

private:
  ::navi_interface::srv::Upload_Request msg_;
};

class Init_Upload_Request_target_pose
{
public:
  explicit Init_Upload_Request_target_pose(::navi_interface::srv::Upload_Request & msg)
  : msg_(msg)
  {}
  Init_Upload_Request_start_pose target_pose(::navi_interface::srv::Upload_Request::_target_pose_type arg)
  {
    msg_.target_pose = std::move(arg);
    return Init_Upload_Request_start_pose(msg_);
  }

private:
  ::navi_interface::srv::Upload_Request msg_;
};

class Init_Upload_Request_step
{
public:
  explicit Init_Upload_Request_step(::navi_interface::srv::Upload_Request & msg)
  : msg_(msg)
  {}
  Init_Upload_Request_target_pose step(::navi_interface::srv::Upload_Request::_step_type arg)
  {
    msg_.step = std::move(arg);
    return Init_Upload_Request_target_pose(msg_);
  }

private:
  ::navi_interface::srv::Upload_Request msg_;
};

class Init_Upload_Request_task_type
{
public:
  explicit Init_Upload_Request_task_type(::navi_interface::srv::Upload_Request & msg)
  : msg_(msg)
  {}
  Init_Upload_Request_step task_type(::navi_interface::srv::Upload_Request::_task_type_type arg)
  {
    msg_.task_type = std::move(arg);
    return Init_Upload_Request_step(msg_);
  }

private:
  ::navi_interface::srv::Upload_Request msg_;
};

class Init_Upload_Request_instruction
{
public:
  explicit Init_Upload_Request_instruction(::navi_interface::srv::Upload_Request & msg)
  : msg_(msg)
  {}
  Init_Upload_Request_task_type instruction(::navi_interface::srv::Upload_Request::_instruction_type arg)
  {
    msg_.instruction = std::move(arg);
    return Init_Upload_Request_task_type(msg_);
  }

private:
  ::navi_interface::srv::Upload_Request msg_;
};

class Init_Upload_Request_image
{
public:
  Init_Upload_Request_image()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Upload_Request_instruction image(::navi_interface::srv::Upload_Request::_image_type arg)
  {
    msg_.image = std::move(arg);
    return Init_Upload_Request_instruction(msg_);
  }

private:
  ::navi_interface::srv::Upload_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::navi_interface::srv::Upload_Request>()
{
  return navi_interface::srv::builder::Init_Upload_Request_image();
}

}  // namespace navi_interface


namespace navi_interface
{

namespace srv
{

namespace builder
{

class Init_Upload_Response_result
{
public:
  Init_Upload_Response_result()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::navi_interface::srv::Upload_Response result(::navi_interface::srv::Upload_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::navi_interface::srv::Upload_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::navi_interface::srv::Upload_Response>()
{
  return navi_interface::srv::builder::Init_Upload_Response_result();
}

}  // namespace navi_interface

#endif  // NAVI_INTERFACE__SRV__DETAIL__UPLOAD__BUILDER_HPP_
