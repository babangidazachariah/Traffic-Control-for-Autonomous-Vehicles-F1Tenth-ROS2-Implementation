// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from trafficrecord:action/VehWaitTime.idl
// generated code does not contain a copyright notice

#ifndef TRAFFICRECORD__ACTION__DETAIL__VEH_WAIT_TIME__TRAITS_HPP_
#define TRAFFICRECORD__ACTION__DETAIL__VEH_WAIT_TIME__TRAITS_HPP_

#include "trafficrecord/action/detail/veh_wait_time__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::VehWaitTime_Goal>()
{
  return "trafficrecord::action::VehWaitTime_Goal";
}

template<>
inline const char * name<trafficrecord::action::VehWaitTime_Goal>()
{
  return "trafficrecord/action/VehWaitTime_Goal";
}

template<>
struct has_fixed_size<trafficrecord::action::VehWaitTime_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<trafficrecord::action::VehWaitTime_Goal>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<trafficrecord::action::VehWaitTime_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::VehWaitTime_Result>()
{
  return "trafficrecord::action::VehWaitTime_Result";
}

template<>
inline const char * name<trafficrecord::action::VehWaitTime_Result>()
{
  return "trafficrecord/action/VehWaitTime_Result";
}

template<>
struct has_fixed_size<trafficrecord::action::VehWaitTime_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<trafficrecord::action::VehWaitTime_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<trafficrecord::action::VehWaitTime_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::VehWaitTime_Feedback>()
{
  return "trafficrecord::action::VehWaitTime_Feedback";
}

template<>
inline const char * name<trafficrecord::action::VehWaitTime_Feedback>()
{
  return "trafficrecord/action/VehWaitTime_Feedback";
}

template<>
struct has_fixed_size<trafficrecord::action::VehWaitTime_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<trafficrecord::action::VehWaitTime_Feedback>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<trafficrecord::action::VehWaitTime_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "trafficrecord/action/detail/veh_wait_time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::VehWaitTime_SendGoal_Request>()
{
  return "trafficrecord::action::VehWaitTime_SendGoal_Request";
}

template<>
inline const char * name<trafficrecord::action::VehWaitTime_SendGoal_Request>()
{
  return "trafficrecord/action/VehWaitTime_SendGoal_Request";
}

template<>
struct has_fixed_size<trafficrecord::action::VehWaitTime_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<trafficrecord::action::VehWaitTime_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<trafficrecord::action::VehWaitTime_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<trafficrecord::action::VehWaitTime_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<trafficrecord::action::VehWaitTime_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::VehWaitTime_SendGoal_Response>()
{
  return "trafficrecord::action::VehWaitTime_SendGoal_Response";
}

template<>
inline const char * name<trafficrecord::action::VehWaitTime_SendGoal_Response>()
{
  return "trafficrecord/action/VehWaitTime_SendGoal_Response";
}

template<>
struct has_fixed_size<trafficrecord::action::VehWaitTime_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<trafficrecord::action::VehWaitTime_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<trafficrecord::action::VehWaitTime_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::VehWaitTime_SendGoal>()
{
  return "trafficrecord::action::VehWaitTime_SendGoal";
}

template<>
inline const char * name<trafficrecord::action::VehWaitTime_SendGoal>()
{
  return "trafficrecord/action/VehWaitTime_SendGoal";
}

template<>
struct has_fixed_size<trafficrecord::action::VehWaitTime_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<trafficrecord::action::VehWaitTime_SendGoal_Request>::value &&
    has_fixed_size<trafficrecord::action::VehWaitTime_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<trafficrecord::action::VehWaitTime_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<trafficrecord::action::VehWaitTime_SendGoal_Request>::value &&
    has_bounded_size<trafficrecord::action::VehWaitTime_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<trafficrecord::action::VehWaitTime_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<trafficrecord::action::VehWaitTime_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<trafficrecord::action::VehWaitTime_SendGoal_Response>
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
inline const char * data_type<trafficrecord::action::VehWaitTime_GetResult_Request>()
{
  return "trafficrecord::action::VehWaitTime_GetResult_Request";
}

template<>
inline const char * name<trafficrecord::action::VehWaitTime_GetResult_Request>()
{
  return "trafficrecord/action/VehWaitTime_GetResult_Request";
}

template<>
struct has_fixed_size<trafficrecord::action::VehWaitTime_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<trafficrecord::action::VehWaitTime_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<trafficrecord::action::VehWaitTime_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "trafficrecord/action/detail/veh_wait_time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::VehWaitTime_GetResult_Response>()
{
  return "trafficrecord::action::VehWaitTime_GetResult_Response";
}

template<>
inline const char * name<trafficrecord::action::VehWaitTime_GetResult_Response>()
{
  return "trafficrecord/action/VehWaitTime_GetResult_Response";
}

template<>
struct has_fixed_size<trafficrecord::action::VehWaitTime_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<trafficrecord::action::VehWaitTime_Result>::value> {};

template<>
struct has_bounded_size<trafficrecord::action::VehWaitTime_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<trafficrecord::action::VehWaitTime_Result>::value> {};

template<>
struct is_message<trafficrecord::action::VehWaitTime_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::VehWaitTime_GetResult>()
{
  return "trafficrecord::action::VehWaitTime_GetResult";
}

template<>
inline const char * name<trafficrecord::action::VehWaitTime_GetResult>()
{
  return "trafficrecord/action/VehWaitTime_GetResult";
}

template<>
struct has_fixed_size<trafficrecord::action::VehWaitTime_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<trafficrecord::action::VehWaitTime_GetResult_Request>::value &&
    has_fixed_size<trafficrecord::action::VehWaitTime_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<trafficrecord::action::VehWaitTime_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<trafficrecord::action::VehWaitTime_GetResult_Request>::value &&
    has_bounded_size<trafficrecord::action::VehWaitTime_GetResult_Response>::value
  >
{
};

template<>
struct is_service<trafficrecord::action::VehWaitTime_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<trafficrecord::action::VehWaitTime_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<trafficrecord::action::VehWaitTime_GetResult_Response>
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
// #include "trafficrecord/action/detail/veh_wait_time__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<trafficrecord::action::VehWaitTime_FeedbackMessage>()
{
  return "trafficrecord::action::VehWaitTime_FeedbackMessage";
}

template<>
inline const char * name<trafficrecord::action::VehWaitTime_FeedbackMessage>()
{
  return "trafficrecord/action/VehWaitTime_FeedbackMessage";
}

template<>
struct has_fixed_size<trafficrecord::action::VehWaitTime_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<trafficrecord::action::VehWaitTime_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<trafficrecord::action::VehWaitTime_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<trafficrecord::action::VehWaitTime_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<trafficrecord::action::VehWaitTime_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<trafficrecord::action::VehWaitTime>
  : std::true_type
{
};

template<>
struct is_action_goal<trafficrecord::action::VehWaitTime_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<trafficrecord::action::VehWaitTime_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<trafficrecord::action::VehWaitTime_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // TRAFFICRECORD__ACTION__DETAIL__VEH_WAIT_TIME__TRAITS_HPP_
