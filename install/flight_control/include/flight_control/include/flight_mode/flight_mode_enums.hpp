#ifndef FLIGHT_MODE_ENUM_HPP
#define FLIGHT_MODE_ENUM_HPP

namespace flight_mode{
        enum OffboardTrajectoryControlModeEnum{
            TRAJECTORY_MODE_POSITION = 1,
            TRAJECTORY_MODE_VELOCITY,
            TRAJECTORY_MODE_ACCELERATION
        };

        enum MainModeEnum{
            MODE_TAKEOFF = 1,
            MODE_LANDING
        };

        enum ModuleEnum{
            MODULE_AVOID_OBSTACLES = 1
        };
}


#endif
