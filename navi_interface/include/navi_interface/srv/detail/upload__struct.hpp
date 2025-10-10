// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from navi_interface:srv/Upload.idl
// generated code does not contain a copyright notice

#ifndef NAVI_INTERFACE__SRV__DETAIL__UPLOAD__STRUCT_HPP_
#define NAVI_INTERFACE__SRV__DETAIL__UPLOAD__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__navi_interface__srv__Upload_Request __attribute__((deprecated))
#else
# define DEPRECATED__navi_interface__srv__Upload_Request __declspec(deprecated)
#endif

namespace navi_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Upload_Request_
{
  using Type = Upload_Request_<ContainerAllocator>;

  explicit Upload_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->instruction = "";
      this->task_type = "";
      this->step = 0ul;
      this->target_pose = "";
      this->start_pose = "";
    }
  }

  explicit Upload_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : image(_alloc, _init),
    instruction(_alloc),
    task_type(_alloc),
    target_pose(_alloc),
    start_pose(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->instruction = "";
      this->task_type = "";
      this->step = 0ul;
      this->target_pose = "";
      this->start_pose = "";
    }
  }

  // field types and members
  using _image_type =
    sensor_msgs::msg::Image_<ContainerAllocator>;
  _image_type image;
  using _instruction_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _instruction_type instruction;
  using _task_type_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _task_type_type task_type;
  using _step_type =
    uint32_t;
  _step_type step;
  using _target_pose_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _target_pose_type target_pose;
  using _start_pose_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _start_pose_type start_pose;

  // setters for named parameter idiom
  Type & set__image(
    const sensor_msgs::msg::Image_<ContainerAllocator> & _arg)
  {
    this->image = _arg;
    return *this;
  }
  Type & set__instruction(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->instruction = _arg;
    return *this;
  }
  Type & set__task_type(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->task_type = _arg;
    return *this;
  }
  Type & set__step(
    const uint32_t & _arg)
  {
    this->step = _arg;
    return *this;
  }
  Type & set__target_pose(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->target_pose = _arg;
    return *this;
  }
  Type & set__start_pose(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->start_pose = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    navi_interface::srv::Upload_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const navi_interface::srv::Upload_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<navi_interface::srv::Upload_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<navi_interface::srv::Upload_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      navi_interface::srv::Upload_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<navi_interface::srv::Upload_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      navi_interface::srv::Upload_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<navi_interface::srv::Upload_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<navi_interface::srv::Upload_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<navi_interface::srv::Upload_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__navi_interface__srv__Upload_Request
    std::shared_ptr<navi_interface::srv::Upload_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__navi_interface__srv__Upload_Request
    std::shared_ptr<navi_interface::srv::Upload_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Upload_Request_ & other) const
  {
    if (this->image != other.image) {
      return false;
    }
    if (this->instruction != other.instruction) {
      return false;
    }
    if (this->task_type != other.task_type) {
      return false;
    }
    if (this->step != other.step) {
      return false;
    }
    if (this->target_pose != other.target_pose) {
      return false;
    }
    if (this->start_pose != other.start_pose) {
      return false;
    }
    return true;
  }
  bool operator!=(const Upload_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Upload_Request_

// alias to use template instance with default allocator
using Upload_Request =
  navi_interface::srv::Upload_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace navi_interface


#ifndef _WIN32
# define DEPRECATED__navi_interface__srv__Upload_Response __attribute__((deprecated))
#else
# define DEPRECATED__navi_interface__srv__Upload_Response __declspec(deprecated)
#endif

namespace navi_interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct Upload_Response_
{
  using Type = Upload_Response_<ContainerAllocator>;

  explicit Upload_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
    }
  }

  explicit Upload_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : result(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->result = "";
    }
  }

  // field types and members
  using _result_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _result_type result;

  // setters for named parameter idiom
  Type & set__result(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->result = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    navi_interface::srv::Upload_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const navi_interface::srv::Upload_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<navi_interface::srv::Upload_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<navi_interface::srv::Upload_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      navi_interface::srv::Upload_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<navi_interface::srv::Upload_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      navi_interface::srv::Upload_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<navi_interface::srv::Upload_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<navi_interface::srv::Upload_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<navi_interface::srv::Upload_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__navi_interface__srv__Upload_Response
    std::shared_ptr<navi_interface::srv::Upload_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__navi_interface__srv__Upload_Response
    std::shared_ptr<navi_interface::srv::Upload_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Upload_Response_ & other) const
  {
    if (this->result != other.result) {
      return false;
    }
    return true;
  }
  bool operator!=(const Upload_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Upload_Response_

// alias to use template instance with default allocator
using Upload_Response =
  navi_interface::srv::Upload_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace navi_interface

namespace navi_interface
{

namespace srv
{

struct Upload
{
  using Request = navi_interface::srv::Upload_Request;
  using Response = navi_interface::srv::Upload_Response;
};

}  // namespace srv

}  // namespace navi_interface

#endif  // NAVI_INTERFACE__SRV__DETAIL__UPLOAD__STRUCT_HPP_
