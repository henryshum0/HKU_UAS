# generated from rosidl_generator_py/resource/_idl.py.em
# with input from offboard_control_interfaces:msg/UserCommand.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_UserCommand(type):
    """Metaclass of message 'UserCommand'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'TAKEOFF': 1,
        'LAND': 2,
        'WAYPOINT': 3,
        'AIRDROP': 4,
        'MAPPING': 5,
        'EXECUTE': 99,
        'POPLAST': 100,
        'SUCCESS': 200,
        'REJECT': 210,
        'REJECT_SETPOINT_OUTOFREACH': 211,
        'REJECT_SPEED_INFEASIBLE': 212,
        'REJECT_TAKEOFF_REQUIRED': 213,
        'REJECT_TAKEOFF_HEIGHTINFEASIBLE': 214,
        'REJECT_TAKEOFF_BEFORE_LAND': 215,
        'REJECT_LAND_BEFORE_TAKEOFF': 216,
        'REJECT_EMPTY_WAYPOINTS': 217,
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('offboard_control_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'offboard_control_interfaces.msg.UserCommand')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__user_command
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__user_command
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__user_command
            cls._TYPE_SUPPORT = module.type_support_msg__msg__user_command
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__user_command

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'TAKEOFF': cls.__constants['TAKEOFF'],
            'LAND': cls.__constants['LAND'],
            'WAYPOINT': cls.__constants['WAYPOINT'],
            'AIRDROP': cls.__constants['AIRDROP'],
            'MAPPING': cls.__constants['MAPPING'],
            'EXECUTE': cls.__constants['EXECUTE'],
            'POPLAST': cls.__constants['POPLAST'],
            'SUCCESS': cls.__constants['SUCCESS'],
            'REJECT': cls.__constants['REJECT'],
            'REJECT_SETPOINT_OUTOFREACH': cls.__constants['REJECT_SETPOINT_OUTOFREACH'],
            'REJECT_SPEED_INFEASIBLE': cls.__constants['REJECT_SPEED_INFEASIBLE'],
            'REJECT_TAKEOFF_REQUIRED': cls.__constants['REJECT_TAKEOFF_REQUIRED'],
            'REJECT_TAKEOFF_HEIGHTINFEASIBLE': cls.__constants['REJECT_TAKEOFF_HEIGHTINFEASIBLE'],
            'REJECT_TAKEOFF_BEFORE_LAND': cls.__constants['REJECT_TAKEOFF_BEFORE_LAND'],
            'REJECT_LAND_BEFORE_TAKEOFF': cls.__constants['REJECT_LAND_BEFORE_TAKEOFF'],
            'REJECT_EMPTY_WAYPOINTS': cls.__constants['REJECT_EMPTY_WAYPOINTS'],
        }

    @property
    def TAKEOFF(self):
        """Message constant 'TAKEOFF'."""
        return Metaclass_UserCommand.__constants['TAKEOFF']

    @property
    def LAND(self):
        """Message constant 'LAND'."""
        return Metaclass_UserCommand.__constants['LAND']

    @property
    def WAYPOINT(self):
        """Message constant 'WAYPOINT'."""
        return Metaclass_UserCommand.__constants['WAYPOINT']

    @property
    def AIRDROP(self):
        """Message constant 'AIRDROP'."""
        return Metaclass_UserCommand.__constants['AIRDROP']

    @property
    def MAPPING(self):
        """Message constant 'MAPPING'."""
        return Metaclass_UserCommand.__constants['MAPPING']

    @property
    def EXECUTE(self):
        """Message constant 'EXECUTE'."""
        return Metaclass_UserCommand.__constants['EXECUTE']

    @property
    def POPLAST(self):
        """Message constant 'POPLAST'."""
        return Metaclass_UserCommand.__constants['POPLAST']

    @property
    def SUCCESS(self):
        """Message constant 'SUCCESS'."""
        return Metaclass_UserCommand.__constants['SUCCESS']

    @property
    def REJECT(self):
        """Message constant 'REJECT'."""
        return Metaclass_UserCommand.__constants['REJECT']

    @property
    def REJECT_SETPOINT_OUTOFREACH(self):
        """Message constant 'REJECT_SETPOINT_OUTOFREACH'."""
        return Metaclass_UserCommand.__constants['REJECT_SETPOINT_OUTOFREACH']

    @property
    def REJECT_SPEED_INFEASIBLE(self):
        """Message constant 'REJECT_SPEED_INFEASIBLE'."""
        return Metaclass_UserCommand.__constants['REJECT_SPEED_INFEASIBLE']

    @property
    def REJECT_TAKEOFF_REQUIRED(self):
        """Message constant 'REJECT_TAKEOFF_REQUIRED'."""
        return Metaclass_UserCommand.__constants['REJECT_TAKEOFF_REQUIRED']

    @property
    def REJECT_TAKEOFF_HEIGHTINFEASIBLE(self):
        """Message constant 'REJECT_TAKEOFF_HEIGHTINFEASIBLE'."""
        return Metaclass_UserCommand.__constants['REJECT_TAKEOFF_HEIGHTINFEASIBLE']

    @property
    def REJECT_TAKEOFF_BEFORE_LAND(self):
        """Message constant 'REJECT_TAKEOFF_BEFORE_LAND'."""
        return Metaclass_UserCommand.__constants['REJECT_TAKEOFF_BEFORE_LAND']

    @property
    def REJECT_LAND_BEFORE_TAKEOFF(self):
        """Message constant 'REJECT_LAND_BEFORE_TAKEOFF'."""
        return Metaclass_UserCommand.__constants['REJECT_LAND_BEFORE_TAKEOFF']

    @property
    def REJECT_EMPTY_WAYPOINTS(self):
        """Message constant 'REJECT_EMPTY_WAYPOINTS'."""
        return Metaclass_UserCommand.__constants['REJECT_EMPTY_WAYPOINTS']


class UserCommand(metaclass=Metaclass_UserCommand):
    """
    Message class 'UserCommand'.

    Constants:
      TAKEOFF
      LAND
      WAYPOINT
      AIRDROP
      MAPPING
      EXECUTE
      POPLAST
      SUCCESS
      REJECT
      REJECT_SETPOINT_OUTOFREACH
      REJECT_SPEED_INFEASIBLE
      REJECT_TAKEOFF_REQUIRED
      REJECT_TAKEOFF_HEIGHTINFEASIBLE
      REJECT_TAKEOFF_BEFORE_LAND
      REJECT_LAND_BEFORE_TAKEOFF
      REJECT_EMPTY_WAYPOINTS
    """

    __slots__ = [
        '_timestamp',
        '_command',
        '_response',
        '_use_xy',
        '_x',
        '_y',
        '_lon',
        '_lat',
        '_z',
        '_speed',
        '_yaw',
    ]

    _fields_and_field_types = {
        'timestamp': 'uint64',
        'command': 'uint8',
        'response': 'uint8',
        'use_xy': 'boolean',
        'x': 'float',
        'y': 'float',
        'lon': 'float',
        'lat': 'float',
        'z': 'float',
        'speed': 'float',
        'yaw': 'float',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
        rosidl_parser.definition.BasicType('float'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.timestamp = kwargs.get('timestamp', int())
        self.command = kwargs.get('command', int())
        self.response = kwargs.get('response', int())
        self.use_xy = kwargs.get('use_xy', bool())
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())
        self.lon = kwargs.get('lon', float())
        self.lat = kwargs.get('lat', float())
        self.z = kwargs.get('z', float())
        self.speed = kwargs.get('speed', float())
        self.yaw = kwargs.get('yaw', float())

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
        if self.timestamp != other.timestamp:
            return False
        if self.command != other.command:
            return False
        if self.response != other.response:
            return False
        if self.use_xy != other.use_xy:
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.lon != other.lon:
            return False
        if self.lat != other.lat:
            return False
        if self.z != other.z:
            return False
        if self.speed != other.speed:
            return False
        if self.yaw != other.yaw:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'timestamp' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'timestamp' field must be an unsigned integer in [0, 18446744073709551615]"
        self._timestamp = value

    @builtins.property
    def command(self):
        """Message field 'command'."""
        return self._command

    @command.setter
    def command(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'command' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'command' field must be an unsigned integer in [0, 255]"
        self._command = value

    @builtins.property
    def response(self):
        """Message field 'response'."""
        return self._response

    @response.setter
    def response(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'response' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'response' field must be an unsigned integer in [0, 255]"
        self._response = value

    @builtins.property
    def use_xy(self):
        """Message field 'use_xy'."""
        return self._use_xy

    @use_xy.setter
    def use_xy(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'use_xy' field must be of type 'bool'"
        self._use_xy = value

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'x' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'y' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._y = value

    @builtins.property
    def lon(self):
        """Message field 'lon'."""
        return self._lon

    @lon.setter
    def lon(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lon' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'lon' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._lon = value

    @builtins.property
    def lat(self):
        """Message field 'lat'."""
        return self._lat

    @lat.setter
    def lat(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'lat' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'lat' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._lat = value

    @builtins.property
    def z(self):
        """Message field 'z'."""
        return self._z

    @z.setter
    def z(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'z' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'z' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._z = value

    @builtins.property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'speed' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._speed = value

    @builtins.property
    def yaw(self):
        """Message field 'yaw'."""
        return self._yaw

    @yaw.setter
    def yaw(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'yaw' field must be of type 'float'"
            assert not (value < -3.402823466e+38 or value > 3.402823466e+38) or math.isinf(value), \
                "The 'yaw' field must be a float in [-3.402823466e+38, 3.402823466e+38]"
        self._yaw = value
