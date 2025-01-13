// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from trafficrecord:action/VehWaitTime.idl
// generated code does not contain a copyright notice

#ifndef TRAFFICRECORD__ACTION__DETAIL__VEH_WAIT_TIME__BUILDER_HPP_
#define TRAFFICRECORD__ACTION__DETAIL__VEH_WAIT_TIME__BUILDER_HPP_

#include "trafficrecord/action/detail/veh_wait_time__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace trafficrecord
{

namespace action
{

namespace builder
{

class Init_VehWaitTime_Goal_waittime
{
public:
  explicit Init_VehWaitTime_Goal_waittime(::trafficrecord::action::VehWaitTime_Goal & msg)
  : msg_(msg)
  {}
  ::trafficrecord::action::VehWaitTime_Goal waittime(::trafficrecord::action::VehWaitTime_Goal::_waittime_type arg)
  {
    msg_.waittime = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trafficrecord::action::VehWaitTime_Goal msg_;
};

class Init_VehWaitTime_Goal_approachleg
{
public:
  Init_VehWaitTime_Goal_approachleg()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehWaitTime_Goal_waittime approachleg(::trafficrecord::action::VehWaitTime_Goal::_approachleg_type arg)
  {
    msg_.approachleg = std::move(arg);
    return Init_VehWaitTime_Goal_waittime(msg_);
  }

private:
  ::trafficrecord::action::VehWaitTime_Goal msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trafficrecord::action::VehWaitTime_Goal>()
{
  return trafficrecord::action::builder::Init_VehWaitTime_Goal_approachleg();
}

}  // namespace trafficrecord


namespace trafficrecord
{

namespace action
{

namespace builder
{

class Init_VehWaitTime_Result_recorded
{
public:
  Init_VehWaitTime_Result_recorded()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::trafficrecord::action::VehWaitTime_Result recorded(::trafficrecord::action::VehWaitTime_Result::_recorded_type arg)
  {
    msg_.recorded = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trafficrecord::action::VehWaitTime_Result msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trafficrecord::action::VehWaitTime_Result>()
{
  return trafficrecord::action::builder::Init_VehWaitTime_Result_recorded();
}

}  // namespace trafficrecord


namespace trafficrecord
{

namespace action
{

namespace builder
{

class Init_VehWaitTime_Feedback_partiallyrecorded
{
public:
  Init_VehWaitTime_Feedback_partiallyrecorded()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::trafficrecord::action::VehWaitTime_Feedback partiallyrecorded(::trafficrecord::action::VehWaitTime_Feedback::_partiallyrecorded_type arg)
  {
    msg_.partiallyrecorded = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trafficrecord::action::VehWaitTime_Feedback msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trafficrecord::action::VehWaitTime_Feedback>()
{
  return trafficrecord::action::builder::Init_VehWaitTime_Feedback_partiallyrecorded();
}

}  // namespace trafficrecord


namespace trafficrecord
{

namespace action
{

namespace builder
{

class Init_VehWaitTime_SendGoal_Request_goal
{
public:
  explicit Init_VehWaitTime_SendGoal_Request_goal(::trafficrecord::action::VehWaitTime_SendGoal_Request & msg)
  : msg_(msg)
  {}
  ::trafficrecord::action::VehWaitTime_SendGoal_Request goal(::trafficrecord::action::VehWaitTime_SendGoal_Request::_goal_type arg)
  {
    msg_.goal = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trafficrecord::action::VehWaitTime_SendGoal_Request msg_;
};

class Init_VehWaitTime_SendGoal_Request_goal_id
{
public:
  Init_VehWaitTime_SendGoal_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehWaitTime_SendGoal_Request_goal goal_id(::trafficrecord::action::VehWaitTime_SendGoal_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_VehWaitTime_SendGoal_Request_goal(msg_);
  }

private:
  ::trafficrecord::action::VehWaitTime_SendGoal_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trafficrecord::action::VehWaitTime_SendGoal_Request>()
{
  return trafficrecord::action::builder::Init_VehWaitTime_SendGoal_Request_goal_id();
}

}  // namespace trafficrecord


namespace trafficrecord
{

namespace action
{

namespace builder
{

class Init_VehWaitTime_SendGoal_Response_stamp
{
public:
  explicit Init_VehWaitTime_SendGoal_Response_stamp(::trafficrecord::action::VehWaitTime_SendGoal_Response & msg)
  : msg_(msg)
  {}
  ::trafficrecord::action::VehWaitTime_SendGoal_Response stamp(::trafficrecord::action::VehWaitTime_SendGoal_Response::_stamp_type arg)
  {
    msg_.stamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trafficrecord::action::VehWaitTime_SendGoal_Response msg_;
};

class Init_VehWaitTime_SendGoal_Response_accepted
{
public:
  Init_VehWaitTime_SendGoal_Response_accepted()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehWaitTime_SendGoal_Response_stamp accepted(::trafficrecord::action::VehWaitTime_SendGoal_Response::_accepted_type arg)
  {
    msg_.accepted = std::move(arg);
    return Init_VehWaitTime_SendGoal_Response_stamp(msg_);
  }

private:
  ::trafficrecord::action::VehWaitTime_SendGoal_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trafficrecord::action::VehWaitTime_SendGoal_Response>()
{
  return trafficrecord::action::builder::Init_VehWaitTime_SendGoal_Response_accepted();
}

}  // namespace trafficrecord


namespace trafficrecord
{

namespace action
{

namespace builder
{

class Init_VehWaitTime_GetResult_Request_goal_id
{
public:
  Init_VehWaitTime_GetResult_Request_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::trafficrecord::action::VehWaitTime_GetResult_Request goal_id(::trafficrecord::action::VehWaitTime_GetResult_Request::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trafficrecord::action::VehWaitTime_GetResult_Request msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trafficrecord::action::VehWaitTime_GetResult_Request>()
{
  return trafficrecord::action::builder::Init_VehWaitTime_GetResult_Request_goal_id();
}

}  // namespace trafficrecord


namespace trafficrecord
{

namespace action
{

namespace builder
{

class Init_VehWaitTime_GetResult_Response_result
{
public:
  explicit Init_VehWaitTime_GetResult_Response_result(::trafficrecord::action::VehWaitTime_GetResult_Response & msg)
  : msg_(msg)
  {}
  ::trafficrecord::action::VehWaitTime_GetResult_Response result(::trafficrecord::action::VehWaitTime_GetResult_Response::_result_type arg)
  {
    msg_.result = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trafficrecord::action::VehWaitTime_GetResult_Response msg_;
};

class Init_VehWaitTime_GetResult_Response_status
{
public:
  Init_VehWaitTime_GetResult_Response_status()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehWaitTime_GetResult_Response_result status(::trafficrecord::action::VehWaitTime_GetResult_Response::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_VehWaitTime_GetResult_Response_result(msg_);
  }

private:
  ::trafficrecord::action::VehWaitTime_GetResult_Response msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trafficrecord::action::VehWaitTime_GetResult_Response>()
{
  return trafficrecord::action::builder::Init_VehWaitTime_GetResult_Response_status();
}

}  // namespace trafficrecord


namespace trafficrecord
{

namespace action
{

namespace builder
{

class Init_VehWaitTime_FeedbackMessage_feedback
{
public:
  explicit Init_VehWaitTime_FeedbackMessage_feedback(::trafficrecord::action::VehWaitTime_FeedbackMessage & msg)
  : msg_(msg)
  {}
  ::trafficrecord::action::VehWaitTime_FeedbackMessage feedback(::trafficrecord::action::VehWaitTime_FeedbackMessage::_feedback_type arg)
  {
    msg_.feedback = std::move(arg);
    return std::move(msg_);
  }

private:
  ::trafficrecord::action::VehWaitTime_FeedbackMessage msg_;
};

class Init_VehWaitTime_FeedbackMessage_goal_id
{
public:
  Init_VehWaitTime_FeedbackMessage_goal_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_VehWaitTime_FeedbackMessage_feedback goal_id(::trafficrecord::action::VehWaitTime_FeedbackMessage::_goal_id_type arg)
  {
    msg_.goal_id = std::move(arg);
    return Init_VehWaitTime_FeedbackMessage_feedback(msg_);
  }

private:
  ::trafficrecord::action::VehWaitTime_FeedbackMessage msg_;
};

}  // namespace builder

}  // namespace action

template<typename MessageType>
auto build();

template<>
inline
auto build<::trafficrecord::action::VehWaitTime_FeedbackMessage>()
{
  return trafficrecord::action::builder::Init_VehWaitTime_FeedbackMessage_goal_id();
}

}  // namespace trafficrecord

#endif  // TRAFFICRECORD__ACTION__DETAIL__VEH_WAIT_TIME__BUILDER_HPP_
