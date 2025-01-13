# generated from rosidl_generator_py/resource/_idl.py.em
# with input from trafficrecord:action/HybridCIM.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'point'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_HybridCIM_Goal(type):
    """Metaclass of message 'HybridCIM_Goal'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trafficrecord')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trafficrecord.action.HybridCIM_Goal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hybrid_cim__goal
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hybrid_cim__goal
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hybrid_cim__goal
            cls._TYPE_SUPPORT = module.type_support_msg__action__hybrid_cim__goal
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hybrid_cim__goal

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HybridCIM_Goal(metaclass=Metaclass_HybridCIM_Goal):
    """Message class 'HybridCIM_Goal'."""

    __slots__ = [
        '_vehicleid',
        '_junction',
        '_approachleg',
        '_departleg',
        '_arrivaltime',
        '_point',
        '_speed',
        '_vehicletype',
        '_priority',
    ]

    _fields_and_field_types = {
        'vehicleid': 'string',
        'junction': 'string',
        'approachleg': 'string',
        'departleg': 'string',
        'arrivaltime': 'double',
        'point': 'sequence<float>',
        'speed': 'float',
        'vehicletype': 'int32',
        'priority': 'int32',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.vehicleid = kwargs.get('vehicleid', str())
        self.junction = kwargs.get('junction', str())
        self.approachleg = kwargs.get('approachleg', str())
        self.departleg = kwargs.get('departleg', str())
        self.arrivaltime = kwargs.get('arrivaltime', float())
        self.point = array.array('f', kwargs.get('point', []))
        self.speed = kwargs.get('speed', float())
        self.vehicletype = kwargs.get('vehicletype', int())
        self.priority = kwargs.get('priority', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.vehicleid != other.vehicleid:
            return False
        if self.junction != other.junction:
            return False
        if self.approachleg != other.approachleg:
            return False
        if self.departleg != other.departleg:
            return False
        if self.arrivaltime != other.arrivaltime:
            return False
        if self.point != other.point:
            return False
        if self.speed != other.speed:
            return False
        if self.vehicletype != other.vehicletype:
            return False
        if self.priority != other.priority:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def vehicleid(self):
        """Message field 'vehicleid'."""
        return self._vehicleid

    @vehicleid.setter
    def vehicleid(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'vehicleid' field must be of type 'str'"
        self._vehicleid = value

    @property
    def junction(self):
        """Message field 'junction'."""
        return self._junction

    @junction.setter
    def junction(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'junction' field must be of type 'str'"
        self._junction = value

    @property
    def approachleg(self):
        """Message field 'approachleg'."""
        return self._approachleg

    @approachleg.setter
    def approachleg(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'approachleg' field must be of type 'str'"
        self._approachleg = value

    @property
    def departleg(self):
        """Message field 'departleg'."""
        return self._departleg

    @departleg.setter
    def departleg(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'departleg' field must be of type 'str'"
        self._departleg = value

    @property
    def arrivaltime(self):
        """Message field 'arrivaltime'."""
        return self._arrivaltime

    @arrivaltime.setter
    def arrivaltime(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'arrivaltime' field must be of type 'float'"
        self._arrivaltime = value

    @property
    def point(self):
        """Message field 'point'."""
        return self._point

    @point.setter
    def point(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'f', \
                "The 'point' array.array() must have the type code of 'f'"
            self._point = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 True), \
                "The 'point' field must be a set or sequence and each value of type 'float'"
        self._point = array.array('f', value)

    @property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed' field must be of type 'float'"
        self._speed = value

    @property
    def vehicletype(self):
        """Message field 'vehicletype'."""
        return self._vehicletype

    @vehicletype.setter
    def vehicletype(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'vehicletype' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'vehicletype' field must be an integer in [-2147483648, 2147483647]"
        self._vehicletype = value

    @property
    def priority(self):
        """Message field 'priority'."""
        return self._priority

    @priority.setter
    def priority(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'priority' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'priority' field must be an integer in [-2147483648, 2147483647]"
        self._priority = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_HybridCIM_Result(type):
    """Metaclass of message 'HybridCIM_Result'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trafficrecord')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trafficrecord.action.HybridCIM_Result')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hybrid_cim__result
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hybrid_cim__result
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hybrid_cim__result
            cls._TYPE_SUPPORT = module.type_support_msg__action__hybrid_cim__result
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hybrid_cim__result

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HybridCIM_Result(metaclass=Metaclass_HybridCIM_Result):
    """Message class 'HybridCIM_Result'."""

    __slots__ = [
        '_vehicleids',
        '_starttime',
        '_duration',
        '_speed',
        '_recorded',
    ]

    _fields_and_field_types = {
        'vehicleids': 'sequence<string>',
        'starttime': 'double',
        'duration': 'int32',
        'speed': 'int32',
        'recorded': 'boolean',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.vehicleids = kwargs.get('vehicleids', [])
        self.starttime = kwargs.get('starttime', float())
        self.duration = kwargs.get('duration', int())
        self.speed = kwargs.get('speed', int())
        self.recorded = kwargs.get('recorded', bool())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.vehicleids != other.vehicleids:
            return False
        if self.starttime != other.starttime:
            return False
        if self.duration != other.duration:
            return False
        if self.speed != other.speed:
            return False
        if self.recorded != other.recorded:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def vehicleids(self):
        """Message field 'vehicleids'."""
        return self._vehicleids

    @vehicleids.setter
    def vehicleids(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'vehicleids' field must be a set or sequence and each value of type 'str'"
        self._vehicleids = value

    @property
    def starttime(self):
        """Message field 'starttime'."""
        return self._starttime

    @starttime.setter
    def starttime(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'starttime' field must be of type 'float'"
        self._starttime = value

    @property
    def duration(self):
        """Message field 'duration'."""
        return self._duration

    @duration.setter
    def duration(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'duration' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'duration' field must be an integer in [-2147483648, 2147483647]"
        self._duration = value

    @property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'speed' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'speed' field must be an integer in [-2147483648, 2147483647]"
        self._speed = value

    @property
    def recorded(self):
        """Message field 'recorded'."""
        return self._recorded

    @recorded.setter
    def recorded(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'recorded' field must be of type 'bool'"
        self._recorded = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_HybridCIM_Feedback(type):
    """Metaclass of message 'HybridCIM_Feedback'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trafficrecord')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trafficrecord.action.HybridCIM_Feedback')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hybrid_cim__feedback
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hybrid_cim__feedback
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hybrid_cim__feedback
            cls._TYPE_SUPPORT = module.type_support_msg__action__hybrid_cim__feedback
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hybrid_cim__feedback

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HybridCIM_Feedback(metaclass=Metaclass_HybridCIM_Feedback):
    """Message class 'HybridCIM_Feedback'."""

    __slots__ = [
        '_schedulein',
        '_nextapproachleg',
    ]

    _fields_and_field_types = {
        'schedulein': 'int32',
        'nextapproachleg': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.schedulein = kwargs.get('schedulein', int())
        self.nextapproachleg = kwargs.get('nextapproachleg', str())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.schedulein != other.schedulein:
            return False
        if self.nextapproachleg != other.nextapproachleg:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def schedulein(self):
        """Message field 'schedulein'."""
        return self._schedulein

    @schedulein.setter
    def schedulein(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'schedulein' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'schedulein' field must be an integer in [-2147483648, 2147483647]"
        self._schedulein = value

    @property
    def nextapproachleg(self):
        """Message field 'nextapproachleg'."""
        return self._nextapproachleg

    @nextapproachleg.setter
    def nextapproachleg(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'nextapproachleg' field must be of type 'str'"
        self._nextapproachleg = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_HybridCIM_SendGoal_Request(type):
    """Metaclass of message 'HybridCIM_SendGoal_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trafficrecord')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trafficrecord.action.HybridCIM_SendGoal_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hybrid_cim__send_goal__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hybrid_cim__send_goal__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hybrid_cim__send_goal__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__hybrid_cim__send_goal__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hybrid_cim__send_goal__request

            from trafficrecord.action import HybridCIM
            if HybridCIM.Goal.__class__._TYPE_SUPPORT is None:
                HybridCIM.Goal.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HybridCIM_SendGoal_Request(metaclass=Metaclass_HybridCIM_SendGoal_Request):
    """Message class 'HybridCIM_SendGoal_Request'."""

    __slots__ = [
        '_goal_id',
        '_goal',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'goal': 'trafficrecord/HybridCIM_Goal',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['trafficrecord', 'action'], 'HybridCIM_Goal'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from trafficrecord.action._hybrid_cim import HybridCIM_Goal
        self.goal = kwargs.get('goal', HybridCIM_Goal())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.goal != other.goal:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @property
    def goal(self):
        """Message field 'goal'."""
        return self._goal

    @goal.setter
    def goal(self, value):
        if __debug__:
            from trafficrecord.action._hybrid_cim import HybridCIM_Goal
            assert \
                isinstance(value, HybridCIM_Goal), \
                "The 'goal' field must be a sub message of type 'HybridCIM_Goal'"
        self._goal = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_HybridCIM_SendGoal_Response(type):
    """Metaclass of message 'HybridCIM_SendGoal_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trafficrecord')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trafficrecord.action.HybridCIM_SendGoal_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hybrid_cim__send_goal__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hybrid_cim__send_goal__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hybrid_cim__send_goal__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__hybrid_cim__send_goal__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hybrid_cim__send_goal__response

            from builtin_interfaces.msg import Time
            if Time.__class__._TYPE_SUPPORT is None:
                Time.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HybridCIM_SendGoal_Response(metaclass=Metaclass_HybridCIM_SendGoal_Response):
    """Message class 'HybridCIM_SendGoal_Response'."""

    __slots__ = [
        '_accepted',
        '_stamp',
    ]

    _fields_and_field_types = {
        'accepted': 'boolean',
        'stamp': 'builtin_interfaces/Time',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['builtin_interfaces', 'msg'], 'Time'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.accepted = kwargs.get('accepted', bool())
        from builtin_interfaces.msg import Time
        self.stamp = kwargs.get('stamp', Time())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.accepted != other.accepted:
            return False
        if self.stamp != other.stamp:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def accepted(self):
        """Message field 'accepted'."""
        return self._accepted

    @accepted.setter
    def accepted(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'accepted' field must be of type 'bool'"
        self._accepted = value

    @property
    def stamp(self):
        """Message field 'stamp'."""
        return self._stamp

    @stamp.setter
    def stamp(self, value):
        if __debug__:
            from builtin_interfaces.msg import Time
            assert \
                isinstance(value, Time), \
                "The 'stamp' field must be a sub message of type 'Time'"
        self._stamp = value


class Metaclass_HybridCIM_SendGoal(type):
    """Metaclass of service 'HybridCIM_SendGoal'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trafficrecord')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trafficrecord.action.HybridCIM_SendGoal')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__hybrid_cim__send_goal

            from trafficrecord.action import _hybrid_cim
            if _hybrid_cim.Metaclass_HybridCIM_SendGoal_Request._TYPE_SUPPORT is None:
                _hybrid_cim.Metaclass_HybridCIM_SendGoal_Request.__import_type_support__()
            if _hybrid_cim.Metaclass_HybridCIM_SendGoal_Response._TYPE_SUPPORT is None:
                _hybrid_cim.Metaclass_HybridCIM_SendGoal_Response.__import_type_support__()


class HybridCIM_SendGoal(metaclass=Metaclass_HybridCIM_SendGoal):
    from trafficrecord.action._hybrid_cim import HybridCIM_SendGoal_Request as Request
    from trafficrecord.action._hybrid_cim import HybridCIM_SendGoal_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_HybridCIM_GetResult_Request(type):
    """Metaclass of message 'HybridCIM_GetResult_Request'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trafficrecord')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trafficrecord.action.HybridCIM_GetResult_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hybrid_cim__get_result__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hybrid_cim__get_result__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hybrid_cim__get_result__request
            cls._TYPE_SUPPORT = module.type_support_msg__action__hybrid_cim__get_result__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hybrid_cim__get_result__request

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HybridCIM_GetResult_Request(metaclass=Metaclass_HybridCIM_GetResult_Request):
    """Message class 'HybridCIM_GetResult_Request'."""

    __slots__ = [
        '_goal_id',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_HybridCIM_GetResult_Response(type):
    """Metaclass of message 'HybridCIM_GetResult_Response'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trafficrecord')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trafficrecord.action.HybridCIM_GetResult_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hybrid_cim__get_result__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hybrid_cim__get_result__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hybrid_cim__get_result__response
            cls._TYPE_SUPPORT = module.type_support_msg__action__hybrid_cim__get_result__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hybrid_cim__get_result__response

            from trafficrecord.action import HybridCIM
            if HybridCIM.Result.__class__._TYPE_SUPPORT is None:
                HybridCIM.Result.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HybridCIM_GetResult_Response(metaclass=Metaclass_HybridCIM_GetResult_Response):
    """Message class 'HybridCIM_GetResult_Response'."""

    __slots__ = [
        '_status',
        '_result',
    ]

    _fields_and_field_types = {
        'status': 'int8',
        'result': 'trafficrecord/HybridCIM_Result',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('int8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['trafficrecord', 'action'], 'HybridCIM_Result'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.status = kwargs.get('status', int())
        from trafficrecord.action._hybrid_cim import HybridCIM_Result
        self.result = kwargs.get('result', HybridCIM_Result())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.status != other.status:
            return False
        if self.result != other.result:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def status(self):
        """Message field 'status'."""
        return self._status

    @status.setter
    def status(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'status' field must be of type 'int'"
            assert value >= -128 and value < 128, \
                "The 'status' field must be an integer in [-128, 127]"
        self._status = value

    @property
    def result(self):
        """Message field 'result'."""
        return self._result

    @result.setter
    def result(self, value):
        if __debug__:
            from trafficrecord.action._hybrid_cim import HybridCIM_Result
            assert \
                isinstance(value, HybridCIM_Result), \
                "The 'result' field must be a sub message of type 'HybridCIM_Result'"
        self._result = value


class Metaclass_HybridCIM_GetResult(type):
    """Metaclass of service 'HybridCIM_GetResult'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trafficrecord')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trafficrecord.action.HybridCIM_GetResult')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__action__hybrid_cim__get_result

            from trafficrecord.action import _hybrid_cim
            if _hybrid_cim.Metaclass_HybridCIM_GetResult_Request._TYPE_SUPPORT is None:
                _hybrid_cim.Metaclass_HybridCIM_GetResult_Request.__import_type_support__()
            if _hybrid_cim.Metaclass_HybridCIM_GetResult_Response._TYPE_SUPPORT is None:
                _hybrid_cim.Metaclass_HybridCIM_GetResult_Response.__import_type_support__()


class HybridCIM_GetResult(metaclass=Metaclass_HybridCIM_GetResult):
    from trafficrecord.action._hybrid_cim import HybridCIM_GetResult_Request as Request
    from trafficrecord.action._hybrid_cim import HybridCIM_GetResult_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_HybridCIM_FeedbackMessage(type):
    """Metaclass of message 'HybridCIM_FeedbackMessage'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trafficrecord')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trafficrecord.action.HybridCIM_FeedbackMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__action__hybrid_cim__feedback_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__action__hybrid_cim__feedback_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__action__hybrid_cim__feedback_message
            cls._TYPE_SUPPORT = module.type_support_msg__action__hybrid_cim__feedback_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__action__hybrid_cim__feedback_message

            from trafficrecord.action import HybridCIM
            if HybridCIM.Feedback.__class__._TYPE_SUPPORT is None:
                HybridCIM.Feedback.__class__.__import_type_support__()

            from unique_identifier_msgs.msg import UUID
            if UUID.__class__._TYPE_SUPPORT is None:
                UUID.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class HybridCIM_FeedbackMessage(metaclass=Metaclass_HybridCIM_FeedbackMessage):
    """Message class 'HybridCIM_FeedbackMessage'."""

    __slots__ = [
        '_goal_id',
        '_feedback',
    ]

    _fields_and_field_types = {
        'goal_id': 'unique_identifier_msgs/UUID',
        'feedback': 'trafficrecord/HybridCIM_Feedback',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['unique_identifier_msgs', 'msg'], 'UUID'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['trafficrecord', 'action'], 'HybridCIM_Feedback'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from unique_identifier_msgs.msg import UUID
        self.goal_id = kwargs.get('goal_id', UUID())
        from trafficrecord.action._hybrid_cim import HybridCIM_Feedback
        self.feedback = kwargs.get('feedback', HybridCIM_Feedback())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.goal_id != other.goal_id:
            return False
        if self.feedback != other.feedback:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def goal_id(self):
        """Message field 'goal_id'."""
        return self._goal_id

    @goal_id.setter
    def goal_id(self, value):
        if __debug__:
            from unique_identifier_msgs.msg import UUID
            assert \
                isinstance(value, UUID), \
                "The 'goal_id' field must be a sub message of type 'UUID'"
        self._goal_id = value

    @property
    def feedback(self):
        """Message field 'feedback'."""
        return self._feedback

    @feedback.setter
    def feedback(self, value):
        if __debug__:
            from trafficrecord.action._hybrid_cim import HybridCIM_Feedback
            assert \
                isinstance(value, HybridCIM_Feedback), \
                "The 'feedback' field must be a sub message of type 'HybridCIM_Feedback'"
        self._feedback = value


class Metaclass_HybridCIM(type):
    """Metaclass of action 'HybridCIM'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('trafficrecord')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'trafficrecord.action.HybridCIM')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_action__action__hybrid_cim

            from action_msgs.msg import _goal_status_array
            if _goal_status_array.Metaclass_GoalStatusArray._TYPE_SUPPORT is None:
                _goal_status_array.Metaclass_GoalStatusArray.__import_type_support__()
            from action_msgs.srv import _cancel_goal
            if _cancel_goal.Metaclass_CancelGoal._TYPE_SUPPORT is None:
                _cancel_goal.Metaclass_CancelGoal.__import_type_support__()

            from trafficrecord.action import _hybrid_cim
            if _hybrid_cim.Metaclass_HybridCIM_SendGoal._TYPE_SUPPORT is None:
                _hybrid_cim.Metaclass_HybridCIM_SendGoal.__import_type_support__()
            if _hybrid_cim.Metaclass_HybridCIM_GetResult._TYPE_SUPPORT is None:
                _hybrid_cim.Metaclass_HybridCIM_GetResult.__import_type_support__()
            if _hybrid_cim.Metaclass_HybridCIM_FeedbackMessage._TYPE_SUPPORT is None:
                _hybrid_cim.Metaclass_HybridCIM_FeedbackMessage.__import_type_support__()


class HybridCIM(metaclass=Metaclass_HybridCIM):

    # The goal message defined in the action definition.
    from trafficrecord.action._hybrid_cim import HybridCIM_Goal as Goal
    # The result message defined in the action definition.
    from trafficrecord.action._hybrid_cim import HybridCIM_Result as Result
    # The feedback message defined in the action definition.
    from trafficrecord.action._hybrid_cim import HybridCIM_Feedback as Feedback

    class Impl:

        # The send_goal service using a wrapped version of the goal message as a request.
        from trafficrecord.action._hybrid_cim import HybridCIM_SendGoal as SendGoalService
        # The get_result service using a wrapped version of the result message as a response.
        from trafficrecord.action._hybrid_cim import HybridCIM_GetResult as GetResultService
        # The feedback message with generic fields which wraps the feedback message.
        from trafficrecord.action._hybrid_cim import HybridCIM_FeedbackMessage as FeedbackMessage

        # The generic service to cancel a goal.
        from action_msgs.srv._cancel_goal import CancelGoal as CancelGoalService
        # The generic message for get the status of a goal.
        from action_msgs.msg._goal_status_array import GoalStatusArray as GoalStatusMessage

    def __init__(self):
        raise NotImplementedError('Action classes can not be instantiated')
