// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from navi_interface:srv/Upload.idl
// generated code does not contain a copyright notice

#ifndef NAVI_INTERFACE__SRV__DETAIL__UPLOAD__TRAITS_HPP_
#define NAVI_INTERFACE__SRV__DETAIL__UPLOAD__TRAITS_HPP_

#include "navi_interface/srv/detail/upload__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'image'
#include "sensor_msgs/msg/detail/image__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<navi_interface::srv::Upload_Request>()
{
  return "navi_interface::srv::Upload_Request";
}

template<>
inline const char * name<navi_interface::srv::Upload_Request>()
{
  return "navi_interface/srv/Upload_Request";
}

template<>
struct has_fixed_size<navi_interface::srv::Upload_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<navi_interface::srv::Upload_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<navi_interface::srv::Upload_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<navi_interface::srv::Upload_Response>()
{
  return "navi_interface::srv::Upload_Response";
}

template<>
inline const char * name<navi_interface::srv::Upload_Response>()
{
  return "navi_interface/srv/Upload_Response";
}

template<>
struct has_fixed_size<navi_interface::srv::Upload_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<navi_interface::srv::Upload_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<navi_interface::srv::Upload_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<navi_interface::srv::Upload>()
{
  return "navi_interface::srv::Upload";
}

template<>
inline const char * name<navi_interface::srv::Upload>()
{
  return "navi_interface/srv/Upload";
}

template<>
struct has_fixed_size<navi_interface::srv::Upload>
  : std::integral_constant<
    bool,
    has_fixed_size<navi_interface::srv::Upload_Request>::value &&
    has_fixed_size<navi_interface::srv::Upload_Response>::value
  >
{
};

template<>
struct has_bounded_size<navi_interface::srv::Upload>
  : std::integral_constant<
    bool,
    has_bounded_size<navi_interface::srv::Upload_Request>::value &&
    has_bounded_size<navi_interface::srv::Upload_Response>::value
  >
{
};

template<>
struct is_service<navi_interface::srv::Upload>
  : std::true_type
{
};

template<>
struct is_service_request<navi_interface::srv::Upload_Request>
  : std::true_type
{
};

template<>
struct is_service_response<navi_interface::srv::Upload_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // NAVI_INTERFACE__SRV__DETAIL__UPLOAD__TRAITS_HPP_
