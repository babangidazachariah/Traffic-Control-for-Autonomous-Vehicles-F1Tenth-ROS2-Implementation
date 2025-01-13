// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from trafficrecord:action/HybridCIM.idl
// generated code does not contain a copyright notice

#ifndef TRAFFICRECORD__ACTION__DETAIL__HYBRID_CIM__TRAITS_HPP_
#define TRAFFICRECORD__ACTION__DETAIL__HYBRID_CIM__TRAITS_HPP_

#include "trafficrecord/action/detail/hybrid_cim__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::HybridCIM_Goal>()
{
  return "trafficrecord::action::HybridCIM_Goal";
}

template<>
inline const char * name<trafficrecord::action::HybridCIM_Goal>()
{
  return "trafficrecord/action/HybridCIM_Goal";
}

template<>
struct has_fixed_size<trafficrecord::action::HybridCIM_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trafficrecord::action::HybridCIM_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trafficrecord::action::HybridCIM_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::HybridCIM_Result>()
{
  return "trafficrecord::action::HybridCIM_Result";
}

template<>
inline const char * name<trafficrecord::action::HybridCIM_Result>()
{
  return "trafficrecord/action/HybridCIM_Result";
}

template<>
struct has_fixed_size<trafficrecord::action::HybridCIM_Result>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trafficrecord::action::HybridCIM_Result>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trafficrecord::action::HybridCIM_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::HybridCIM_Feedback>()
{
  return "trafficrecord::action::HybridCIM_Feedback";
}

template<>
inline const char * name<trafficrecord::action::HybridCIM_Feedback>()
{
  return "trafficrecord/action/HybridCIM_Feedback";
}

template<>
struct has_fixed_size<trafficrecord::action::HybridCIM_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trafficrecord::action::HybridCIM_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trafficrecord::action::HybridCIM_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "trafficrecord/action/detail/hybrid_cim__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::HybridCIM_SendGoal_Request>()
{
  return "trafficrecord::action::HybridCIM_SendGoal_Request";
}

template<>
inline const char * name<trafficrecord::action::HybridCIM_SendGoal_Request>()
{
  return "trafficrecord/action/HybridCIM_SendGoal_Request";
}

template<>
struct has_fixed_size<trafficrecord::action::HybridCIM_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<trafficrecord::action::HybridCIM_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<trafficrecord::action::HybridCIM_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<trafficrecord::action::HybridCIM_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<trafficrecord::action::HybridCIM_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::HybridCIM_SendGoal_Response>()
{
  return "trafficrecord::action::HybridCIM_SendGoal_Response";
}

template<>
inline const char * name<trafficrecord::action::HybridCIM_SendGoal_Response>()
{
  return "trafficrecord/action/HybridCIM_SendGoal_Response";
}

template<>
struct has_fixed_size<trafficrecord::action::HybridCIM_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<trafficrecord::action::HybridCIM_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<trafficrecord::action::HybridCIM_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::HybridCIM_SendGoal>()
{
  return "trafficrecord::action::HybridCIM_SendGoal";
}

template<>
inline const char * name<trafficrecord::action::HybridCIM_SendGoal>()
{
  return "trafficrecord/action/HybridCIM_SendGoal";
}

template<>
struct has_fixed_size<trafficrecord::action::HybridCIM_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<trafficrecord::action::HybridCIM_SendGoal_Request>::value &&
    has_fixed_size<trafficrecord::action::HybridCIM_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<trafficrecord::action::HybridCIM_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<trafficrecord::action::HybridCIM_SendGoal_Request>::value &&
    has_bounded_size<trafficrecord::action::HybridCIM_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<trafficrecord::action::HybridCIM_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<trafficrecord::action::HybridCIM_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<trafficrecord::action::HybridCIM_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::HybridCIM_GetResult_Request>()
{
  return "trafficrecord::action::HybridCIM_GetResult_Request";
}

template<>
inline const char * name<trafficrecord::action::HybridCIM_GetResult_Request>()
{
  return "trafficrecord/action/HybridCIM_GetResult_Request";
}

template<>
struct has_fixed_size<trafficrecord::action::HybridCIM_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<trafficrecord::action::HybridCIM_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<trafficrecord::action::HybridCIM_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::HybridCIM_GetResult_Response>()
{
  return "trafficrecord::action::HybridCIM_GetResult_Response";
}

template<>
inline const char * name<trafficrecord::action::HybridCIM_GetResult_Response>()
{
  return "trafficrecord/action/HybridCIM_GetResult_Response";
}

template<>
struct has_fixed_size<trafficrecord::action::HybridCIM_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<trafficrecord::action::HybridCIM_Result>::value> {};

template<>
struct has_bounded_size<trafficrecord::action::HybridCIM_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<trafficrecord::action::HybridCIM_Result>::value> {};

template<>
struct is_message<trafficrecord::action::HybridCIM_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::HybridCIM_GetResult>()
{
  return "trafficrecord::action::HybridCIM_GetResult";
}

template<>
inline const char * name<trafficrecord::action::HybridCIM_GetResult>()
{
  return "trafficrecord/action/HybridCIM_GetResult";
}

template<>
struct has_fixed_size<trafficrecord::action::HybridCIM_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<trafficrecord::action::HybridCIM_GetResult_Request>::value &&
    has_fixed_size<trafficrecord::action::HybridCIM_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<trafficrecord::action::HybridCIM_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<trafficrecord::action::HybridCIM_GetResult_Request>::value &&
    has_bounded_size<trafficrecord::action::HybridCIM_GetResult_Response>::value
  >
{
};

template<>
struct is_service<trafficrecord::action::HybridCIM_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<trafficrecord::action::HybridCIM_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<trafficrecord::action::HybridCIM_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "trafficrecord/action/detail/hybrid_cim__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::HybridCIM_FeedbackMessage>()
{
  return "trafficrecord::action::HybridCIM_FeedbackMessage";
}

template<>
inline const char * name<trafficrecord::action::HybridCIM_FeedbackMessage>()
{
  return "trafficrecord/action/HybridCIM_FeedbackMessage";
}

template<>
struct has_fixed_size<trafficrecord::action::HybridCIM_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<trafficrecord::action::HybridCIM_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<trafficrecord::action::HybridCIM_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<trafficrecord::action::HybridCIM_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<trafficrecord::action::HybridCIM_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<trafficrecord::action::HybridCIM>
  : std::true_type
{
};

template<>
struct is_action_goal<trafficrecord::action::HybridCIM_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<trafficrecord::action::HybridCIM_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<trafficrecord::action::HybridCIM_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // TRAFFICRECORD__ACTION__DETAIL__HYBRID_CIM__TRAITS_HPP_
