#ifndef VEHICLE_STATE_HPP
#define VEHICLE_STATE_HPP

#include <Eigen/Dense>

using namespace Eigen;

enum  FlightMode{
    LANDED = 1,
    TAKEOFF,
    LANDING,
    NAV,
    TASK
};


class VehicleState
{
    public:
    private:
    bool is_takeoff, is_arm;
    Vector3f enu_pos, enu_vel, enu_accel, enu_home;
    FlightMode exec_flightmode;
};






#endif
