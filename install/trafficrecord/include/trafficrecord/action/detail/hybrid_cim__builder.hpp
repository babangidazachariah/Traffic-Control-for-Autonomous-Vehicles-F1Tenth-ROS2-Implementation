// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trafficrecord:action/HybridCIM.idl
// generated code does not contain a copyright notice

#ifndef TRAFFICRECORD__ACTION__DETAIL__HYBRID_CIM__BUILDER_HPP_
#define TRAFFICRECORD__ACTION__DETAIL__HYBRID_CIM__BUILDER_HPP_

#include "trafficrecord/action/detail/hybrid_cim__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trafficrecord
{

namespace action
{

namespace builder
{

class Init_HybridCIM_Goal_priority
{
public:
  explicit Init_HybridCIM_Goal_priority(::trafficrecord::action::HybridCIM_Goal & msg)
  : msg_(msg)
  {}
  ::trafficrecord::action::HybridCIM_Goal priority(::trafficrecord::action::HybridCIM_Goal::_priority_type arg)
  {
    msg_.priority = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_Goal msg_;
};

class Init_HybridCIM_Goal_vehicletype
{
public:
  explicit Init_HybridCIM_Goal_vehicletype(::trafficrecord::action::HybridCIM_Goal & msg)
  : msg_(msg)
  {}
  Init_HybridCIM_Goal_priority vehicletype(::trafficrecord::action::HybridCIM_Goal::_vehicletype_type arg)
  {
    msg_.vehicletype = std::move(arg);
    return Init_HybridCIM_Goal_priority(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_Goal msg_;
};

class Init_HybridCIM_Goal_speed
{
public:
  explicit Init_HybridCIM_Goal_speed(::trafficrecord::action::HybridCIM_Goal & msg)
  : msg_(msg)
  {}
  Init_HybridCIM_Goal_vehicletype speed(::trafficrecord::action::HybridCIM_Goal::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_HybridCIM_Goal_vehicletype(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_Goal msg_;
};

class Init_HybridCIM_Goal_point
{
public:
  explicit Init_HybridCIM_Goal_point(::trafficrecord::action::HybridCIM_Goal & msg)
  : msg_(msg)
  {}
  Init_HybridCIM_Goal_speed point(::trafficrecord::action::HybridCIM_Goal::_point_type arg)
  {
    msg_.point = std::move(arg);
    return Init_HybridCIM_Goal_speed(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_Goal msg_;
};

class Init_HybridCIM_Goal_arrivaltime
{
public:
  explicit Init_HybridCIM_Goal_arrivaltime(::trafficrecord::action::HybridCIM_Goal & msg)
  : msg_(msg)
  {}
  Init_HybridCIM_Goal_point arrivaltime(::trafficrecord::action::HybridCIM_Goal::_arrivaltime_type arg)
  {
    msg_.arrivaltime = std::move(arg);
    return Init_HybridCIM_Goal_point(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_Goal msg_;
};

class Init_HybridCIM_Goal_departleg
{
public:
  explicit Init_HybridCIM_Goal_departleg(::trafficrecord::action::HybridCIM_Goal & msg)
  : msg_(msg)
  {}
  Init_HybridCIM_Goal_arrivaltime departleg(::trafficrecord::action::HybridCIM_Goal::_departleg_type arg)
  {
    msg_.departleg = std::move(arg);
    return Init_HybridCIM_Goal_arrivaltime(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_Goal msg_;
};

class Init_HybridCIM_Goal_approachleg
{
public:
  explicit Init_HybridCIM_Goal_approachleg(::trafficrecord::action::HybridCIM_Goal & msg)
  : msg_(msg)
  {}
  Init_HybridCIM_Goal_departleg approachleg(::trafficrecord::action::HybridCIM_Goal::_approachleg_type arg)
  {
    msg_.approachleg = std::move(arg);
    return Init_HybridCIM_Goal_departleg(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_Goal msg_;
};

class Init_HybridCIM_Goal_junction
{
public:
  explicit Init_HybridCIM_Goal_junction(::trafficrecord::action::HybridCIM_Goal & msg)
  : msg_(msg)
  {}
  Init_HybridCIM_Goal_approachleg junction(::trafficrecord::action::HybridCIM_Goal::_junction_type arg)
  {
    msg_.junction = std::move(arg);
    return Init_HybridCIM_Goal_approachleg(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_Goal msg_;
};

class Init_HybridCIM_Goal_vehicleid
{
public:
  Init_HybridCIM_Goal_vehicleid()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HybridCIM_Goal_junction vehicleid(::trafficrecord::action::HybridCIM_Goal::_vehicleid_type arg)
  {
    msg_.vehicleid = std::move(arg);
    return Init_HybridCIM_Goal_junction(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trafficrecord::action::HybridCIM_Goal>()
{
  return trafficrecord::action::builder::Init_HybridCIM_Goal_vehicleid();
}

}  // namespace trafficrecord


namespace trafficrecord
{

namespace action
{

namespace builder
{

class Init_HybridCIM_Result_recorded
{
public:
  explicit Init_HybridCIM_Result_recorded(::trafficrecord::action::HybridCIM_Result & msg)
  : msg_(msg)
  {}
  ::trafficrecord::action::HybridCIM_Result recorded(::trafficrecord::action::HybridCIM_Result::_recorded_type arg)
  {
    msg_.recorded = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_Result msg_;
};

class Init_HybridCIM_Result_speed
{
public:
  explicit Init_HybridCIM_Result_speed(::trafficrecord::action::HybridCIM_Result & msg)
  : msg_(msg)
  {}
  Init_HybridCIM_Result_recorded speed(::trafficrecord::action::HybridCIM_Result::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_HybridCIM_Result_recorded(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_Result msg_;
};

class Init_HybridCIM_Result_duration
{
public:
  explicit Init_HybridCIM_Result_duration(::trafficrecord::action::HybridCIM_Result & msg)
  : msg_(msg)
  {}
  Init_HybridCIM_Result_speed duration(::trafficrecord::action::HybridCIM_Result::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return Init_HybridCIM_Result_speed(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_Result msg_;
};

class Init_HybridCIM_Result_starttime
{
public:
  explicit Init_HybridCIM_Result_starttime(::trafficrecord::action::HybridCIM_Result & msg)
  : msg_(msg)
  {}
  Init_HybridCIM_Result_duration starttime(::trafficrecord::action::HybridCIM_Result::_starttime_type arg)
  {
    msg_.starttime = std::move(arg);
    return Init_HybridCIM_Result_duration(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_Result msg_;
};

class Init_HybridCIM_Result_vehicleids
{
public:
  Init_HybridCIM_Result_vehicleids()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HybridCIM_Result_starttime vehicleids(::trafficrecord::action::HybridCIM_Result::_vehicleids_type arg)
  {
    msg_.vehicleids = std::move(arg);
    return Init_HybridCIM_Result_starttime(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trafficrecord::action::HybridCIM_Result>()
{
  return trafficrecord::action::builder::Init_HybridCIM_Result_vehicleids();
}

}  // namespace trafficrecord


namespace trafficrecord
{

namespace action
{

namespace builder
{

class Init_HybridCIM_Feedback_nextapproachleg
{
public:
  explicit Init_HybridCIM_Feedback_nextapproachleg(::trafficrecord::action::HybridCIM_Feedback & msg)
  : msg_(msg)
  {}
  ::trafficrecord::action::HybridCIM_Feedback nextapproachleg(::trafficrecord::action::HybridCIM_Feedback::_nextapproachleg_type arg)
  {
    msg_.nextapproachleg = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_Feedback msg_;
};

class Init_HybridCIM_Feedback_schedulein
{
public:
  Init_HybridCIM_Feedback_schedulein()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HybridCIM_Feedback_nextapproachleg schedulein(::trafficrecord::action::HybridCIM_Feedback::_schedulein_type arg)
  {
    msg_.schedulein = std::move(arg);
    return Init_HybridCIM_Feedback_nextapproachleg(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trafficrecord::action::HybridCIM_Feedback>()
{
  return trafficrecord::action::builder::Init_HybridCIM_Feedback_schedulein();
}

}  // namespace trafficrecord


namespace trafficrecord
{

namespace action
{

namespace builder
{

class Init_HybridCIM_SendGoal_Request_goal
{
public:
  explicit Init_HybridCIM_SendGoal_Request_goal(::trafficrecord::action::HybridCIM_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::trafficrecord::action::HybridCIM_SendGoal_Request goal(::trafficrecord::action::HybridCIM_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_SendGoal_Request msg_;
};

class Init_HybridCIM_SendGoal_Request_goal_id
{
public:
  Init_HybridCIM_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HybridCIM_SendGoal_Request_goal goal_id(::trafficrecord::action::HybridCIM_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_HybridCIM_SendGoal_Request_goal(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trafficrecord::action::HybridCIM_SendGoal_Request>()
{
  return trafficrecord::action::builder::Init_HybridCIM_SendGoal_Request_goal_id();
}

}  // namespace trafficrecord


namespace trafficrecord
{

namespace action
{

namespace builder
{

class Init_HybridCIM_SendGoal_Response_stamp
{
public:
  explicit Init_HybridCIM_SendGoal_Response_stamp(::trafficrecord::action::HybridCIM_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::trafficrecord::action::HybridCIM_SendGoal_Response stamp(::trafficrecord::action::HybridCIM_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_SendGoal_Response msg_;
};

class Init_HybridCIM_SendGoal_Response_accepted
{
public:
  Init_HybridCIM_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HybridCIM_SendGoal_Response_stamp accepted(::trafficrecord::action::HybridCIM_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_HybridCIM_SendGoal_Response_stamp(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trafficrecord::action::HybridCIM_SendGoal_Response>()
{
  return trafficrecord::action::builder::Init_HybridCIM_SendGoal_Response_accepted();
}

}  // namespace trafficrecord


namespace trafficrecord
{

namespace action
{

namespace builder
{

class Init_HybridCIM_GetResult_Request_goal_id
{
public:
  Init_HybridCIM_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::trafficrecord::action::HybridCIM_GetResult_Request goal_id(::trafficrecord::action::HybridCIM_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trafficrecord::action::HybridCIM_GetResult_Request>()
{
  return trafficrecord::action::builder::Init_HybridCIM_GetResult_Request_goal_id();
}

}  // namespace trafficrecord


namespace trafficrecord
{

namespace action
{

namespace builder
{

class Init_HybridCIM_GetResult_Response_result
{
public:
  explicit Init_HybridCIM_GetResult_Response_result(::trafficrecord::action::HybridCIM_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::trafficrecord::action::HybridCIM_GetResult_Response result(::trafficrecord::action::HybridCIM_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_GetResult_Response msg_;
};

class Init_HybridCIM_GetResult_Response_status
{
public:
  Init_HybridCIM_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HybridCIM_GetResult_Response_result status(::trafficrecord::action::HybridCIM_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_HybridCIM_GetResult_Response_result(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trafficrecord::action::HybridCIM_GetResult_Response>()
{
  return trafficrecord::action::builder::Init_HybridCIM_GetResult_Response_status();
}

}  // namespace trafficrecord


namespace trafficrecord
{

namespace action
{

namespace builder
{

class Init_HybridCIM_FeedbackMessage_feedback
{
public:
  explicit Init_HybridCIM_FeedbackMessage_feedback(::trafficrecord::action::HybridCIM_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::trafficrecord::action::HybridCIM_FeedbackMessage feedback(::trafficrecord::action::HybridCIM_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_FeedbackMessage msg_;
};

class Init_HybridCIM_FeedbackMessage_goal_id
{
public:
  Init_HybridCIM_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_HybridCIM_FeedbackMessage_feedback goal_id(::trafficrecord::action::HybridCIM_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_HybridCIM_FeedbackMessage_feedback(msg_);
  }

private:
  ::trafficrecord::action::HybridCIM_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trafficrecord::action::HybridCIM_FeedbackMessage>()
{
  return trafficrecord::action::builder::Init_HybridCIM_FeedbackMessage_goal_id();
}

}  // namespace trafficrecord

#endif  // TRAFFICRECORD__ACTION__DETAIL__HYBRID_CIM__BUILDER_HPP_
