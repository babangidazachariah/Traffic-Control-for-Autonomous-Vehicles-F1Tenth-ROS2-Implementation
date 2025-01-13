# generated from rosidl_generator_py/resource/_idl.py.em
# with input from dsrcmsg:msg/IntersectionBSM.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'point'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_IntersectionBSM(type):
    """Metaclass of message 'IntersectionBSM'."""

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
            module = import_type_support('dsrcmsg')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'dsrcmsg.msg.IntersectionBSM')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__intersection_bsm
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__intersection_bsm
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__intersection_bsm
            cls._TYPE_SUPPORT = module.type_support_msg__msg__intersection_bsm
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__intersection_bsm

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class IntersectionBSM(metaclass=Metaclass_IntersectionBSM):
    """Message class 'IntersectionBSM'."""

    __slots__ = [
        '_vehicleid',
        '_junctionid',
        '_approachleg',
        '_departleg',
        '_distfromstopline',
        '_point',
        '_arrivaltime',
        '_vehicletype',
        '_speed',
        '_priority',
        '_stoppedtime',
        '_timestamp',
    ]

    _fields_and_field_types = {
        'vehicleid': 'string',
        'junctionid': 'string',
        'approachleg': 'string',
        'departleg': 'string',
        'distfromstopline': 'double',
        'point': 'sequence<float>',
        'arrivaltime': 'double',
        'vehicletype': 'int32',
        'speed': 'double',
        'priority': 'int32',
        'stoppedtime': 'double',
        'timestamp': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.vehicleid = kwargs.get('vehicleid', str())
        self.junctionid = kwargs.get('junctionid', str())
        self.approachleg = kwargs.get('approachleg', str())
        self.departleg = kwargs.get('departleg', str())
        self.distfromstopline = kwargs.get('distfromstopline', float())
        self.point = array.array('f', kwargs.get('point', []))
        self.arrivaltime = kwargs.get('arrivaltime', float())
        self.vehicletype = kwargs.get('vehicletype', int())
        self.speed = kwargs.get('speed', float())
        self.priority = kwargs.get('priority', int())
        self.stoppedtime = kwargs.get('stoppedtime', float())
        self.timestamp = kwargs.get('timestamp', float())

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
        if self.junctionid != other.junctionid:
            return False
        if self.approachleg != other.approachleg:
            return False
        if self.departleg != other.departleg:
            return False
        if self.distfromstopline != other.distfromstopline:
            return False
        if self.point != other.point:
            return False
        if self.arrivaltime != other.arrivaltime:
            return False
        if self.vehicletype != other.vehicletype:
            return False
        if self.speed != other.speed:
            return False
        if self.priority != other.priority:
            return False
        if self.stoppedtime != other.stoppedtime:
            return False
        if self.timestamp != other.timestamp:
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
    def junctionid(self):
        """Message field 'junctionid'."""
        return self._junctionid

    @junctionid.setter
    def junctionid(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'junctionid' field must be of type 'str'"
        self._junctionid = value

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
    def distfromstopline(self):
        """Message field 'distfromstopline'."""
        return self._distfromstopline

    @distfromstopline.setter
    def distfromstopline(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'distfromstopline' field must be of type 'float'"
        self._distfromstopline = value

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

    @property
    def stoppedtime(self):
        """Message field 'stoppedtime'."""
        return self._stoppedtime

    @stoppedtime.setter
    def stoppedtime(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'stoppedtime' field must be of type 'float'"
        self._stoppedtime = value

    @property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'timestamp' field must be of type 'float'"
        self._timestamp = value
