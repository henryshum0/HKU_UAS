#ifndef FLIGHT_MODE_H
#define FLIGHT_MODE_H

#include <rclcpp/rclcpp.hpp>

#include <flight_control/offboard_controller.hpp>
#include <flight_mode/flight_mode_enums.hpp>

namespace flight_mode{
    
    //base class for all flight modes
    class FlightMode{
    
    public:
        
        FlightMode(std::shared_ptr<flight_control::OffboardController> offboard_controller, std::string mode_name);
        
        /**
         * @brief wrapper to the one in flight_control::OffboardController
         */
        void publish_vehicle_command(const uint16_t command, const float param1 = 0.0, const float param2 = 0.0);

        /**
         * @brief   wrapper for the same function in flight_control::OffboardController
         */
        void publish_offboard_mode();

        /**
         * @brief this is used to publish a series of setpoints to control the vehicle
         * is a wrapper to the one in flight_control::OffboardController. each mode should publish
         * their own set of trajectory
         * see definition from px4_msgs::msg::TrajectorySetpoint
         */
        void publish_trajectory_setpoint(const Vector3f& input, const float yaw = 0.0);

        //wrapper get functions
        Vector3f get_enu_local();
        Vector3f get_enu_vel();
        Vector3f get_enu_accel();
        bool get_armed();
        

        //wrapper set functions
        void set_trajectory_mode(const OffboardTrajectoryControlModeEnum mode);
        void set_is_complete(bool is_not);

    private:
        std::shared_ptr<flight_control::OffboardController> offboard_controller;
        std::string mode_name;
        rclcpp::TimerBase::SharedPtr timer;

        
    };



    //TakeoffMode
    class TakeoffMode : public FlightMode
    {
    public:
        TakeoffMode(std::shared_ptr<flight_control::OffboardController> offboard_controller, float takeoff_height);
        void execute_mode();
        void kill();        
        
    private:
        float takeoff_height;
        Vector3f target_pos;
    };
}

#endif
