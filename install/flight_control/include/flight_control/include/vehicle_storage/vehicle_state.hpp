#ifndef VEHICLE_STATE_HPP
#define VEHICLE_STATE_HPP

#include <Eigen/Dense>
#include <chrono>

using namespace Eigen;
using namespace std::literals::chrono_literals;

enum  FlightMode{
    TAKEOFF = 1,
    LANDING,
    NAV,
    TASK,
    IDLE
};



class VehicleState
{
    public:
    VehicleState();

    bool get_is_landed();
    bool get_is_arm();
    bool get_is_offboard();

    Vector3f get_pos();
    Vector3f get_vel();
    Vector3f get_accel();
    float get_yaw();

    Vector3f get_home();
    
    FlightMode get_flight_mode();
    float get_dt();

    

    //set by subscribers
    void set_is_landed(const bool is_no);
    void set_is_arm(const bool is_no);
    void set_is_offboard(const bool is_no);

    void set_pos(const Vector3f pos);
    void set_vel(const Vector3f vel);
    void set_accel(const Vector3f accel);
    void set_yaw(const float yaw);

    //set by mode executor
    void set_home(const Vector3f home);
    void set_flight_mode(const FlightMode mode);
    
    


    private:
    bool is_landed, is_arm, is_offboard;
    Vector3f pos, vel, accel, home; float yaw;
    float dt = 1/50;  //50hz
    FlightMode in_flightmode;

};






#endif
