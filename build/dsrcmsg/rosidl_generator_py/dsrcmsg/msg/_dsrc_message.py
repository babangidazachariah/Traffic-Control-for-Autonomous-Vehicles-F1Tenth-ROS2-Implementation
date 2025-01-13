# generated from rosidl_generator_py/resource/_idl.py.em
# with input from dsrcmsg:msg/DSRCMessage.idl
# generated code does not contain a copyright notice


# Import statements for member types

# Member 'point'
import array  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DSRCMessage(type):
    """Metaclass of message 'DSRCMessage'."""

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
                'dsrcmsg.msg.DSRCMessage')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__dsrc_message
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__dsrc_message
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__dsrc_message
            cls._TYPE_SUPPORT = module.type_support_msg__msg__dsrc_message
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__dsrc_message

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DSRCMessage(metaclass=Metaclass_DSRCMessage):
    """Message class 'DSRCMessage'."""

    __slots__ = [
        '_vehicleid',
        '_initialtime',
        '_currenttime',
        '_approachleg',
        '_departureleg',
        '_disttostopline',
        '_distfromstopline',
        '_point',
        '_speed',
    ]

    _fields_and_field_types = {
        'vehicleid': 'string',
        'initialtime': 'double',
        'currenttime': 'double',
        'approachleg': 'string',
        'departureleg': 'string',
        'disttostopline': 'double',
        'distfromstopline': 'double',
        'point': 'sequence<float>',
        'speed': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('float')),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.vehicleid = kwargs.get('vehicleid', str())
        self.initialtime = kwargs.get('initialtime', float())
        self.currenttime = kwargs.get('currenttime', float())
        self.approachleg = kwargs.get('approachleg', str())
        self.departureleg = kwargs.get('departureleg', str())
        self.disttostopline = kwargs.get('disttostopline', float())
        self.distfromstopline = kwargs.get('distfromstopline', float())
        self.point = array.array('f', kwargs.get('point', []))
        self.speed = kwargs.get('speed', float())

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
        if self.initialtime != other.initialtime:
            return False
        if self.currenttime != other.currenttime:
            return False
        if self.approachleg != other.approachleg:
            return False
        if self.departureleg != other.departureleg:
            return False
        if self.disttostopline != other.disttostopline:
            return False
        if self.distfromstopline != other.distfromstopline:
            return False
        if self.point != other.point:
            return False
        if self.speed != other.speed:
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
    def initialtime(self):
        """Message field 'initialtime'."""
        return self._initialtime

    @initialtime.setter
    def initialtime(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'initialtime' field must be of type 'float'"
        self._initialtime = value

    @property
    def currenttime(self):
        """Message field 'currenttime'."""
        return self._currenttime

    @currenttime.setter
    def currenttime(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'currenttime' field must be of type 'float'"
        self._currenttime = value

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
    def departureleg(self):
        """Message field 'departureleg'."""
        return self._departureleg

    @departureleg.setter
    def departureleg(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'departureleg' field must be of type 'str'"
        self._departureleg = value

    @property
    def disttostopline(self):
        """Message field 'disttostopline'."""
        return self._disttostopline

    @disttostopline.setter
    def disttostopline(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'disttostopline' field must be of type 'float'"
        self._disttostopline = value

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
