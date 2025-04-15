#ifndef MODE_EXECUTOR_H
#define MODE_EXECUTOR_H

#include <string>
#include <memory>
#include <math.h>

#include <rclcpp/rclcpp.hpp>

#include <vehicle_storage/vehicle_state_storage.hpp>
#include <vehicle_storage/executor_storage.hpp>

using namespace Eigen;

class FlightExecutor : public rclcpp::Node
{
    public:
    FlightExecutor(const std::shared_ptr<VehicleStateStorage> vehicle_state_storage, const std::shared_ptr<ExecutorStorage> executor_storage);

    private:
    
    std::shared_ptr<VehicleStateStorage> vehicle_state_storage;
    std::shared_ptr<ExecutorStorage> executor_storage;

    rclcpp::TimerBase::SharedPtr timer_publish_control;
    
    void publish_control();


    void take_off(std::shared_ptr<Waypoint> take_off_waypoint);

    void move_to_waypoint(std::shared_ptr<Waypoint> waypoint);
    void run_avoidance(std::shared_ptr<Waypoint> waypoint, Vector3f ideal_vel); //TODO
    void get_desired_yaw(); //TODO

    void set_trj_setpoint_pos(const Vector3f trj_sp_pos, const float yaw = NAN);
    void set_trj_setpoint_vel(const Vector3f trj_sp_vel, const float yaw = NAN);
    void set_trj_setpoint_accel(const Vector3f trj_sp_accel, const float yaw = NAN);
    
    
    

};

#endif
