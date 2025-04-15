#ifndef CTRL_PUBLISHER_HPP
#define CTRL_PUBLISHER_HPP

#include <rclcpp/rclcpp.hpp>

#include <px4_msgs/msg/offboard_control_mode.hpp>
#include <px4_msgs/msg/trajectory_setpoint.hpp>
#include <px4_msgs/msg/vehicle_command.hpp>

#include <Eigen/Dense>

#include <vehicle_storage/executor_storage.hpp>
#include <vehicle_storage/vehicle_state_storage.hpp>
#include <lib/utils.hpp>

using namespace px4_msgs::msg;
using namespace Eigen;

//issue trajectory to px4
class ControlPublisher : public rclcpp::Node
{
    public:
    ControlPublisher(const std::shared_ptr<ExecutorStorage> executor_storage);
    


    private:
    rclcpp::Time arm_cmd_sent_time;

    rclcpp::TimerBase::SharedPtr timer_query_cmd;

    std::shared_ptr<ExecutorStorage> executor_storage;


    rclcpp::Publisher<OffboardControlMode>::SharedPtr offboard_control_mode_publisher;
    rclcpp::Publisher<TrajectorySetpoint>::SharedPtr trajectory_setpoint_publisher;
    rclcpp::Publisher<VehicleCommand>::SharedPtr vehicle_command_publisher;
    

    void publish_vehicle_command(const uint16_t command, const float param1 = 0.0, const float param2 = 0.0);
    void publish_offboard_mode(const TrjControlMode trj_ctrl_mode);
    void publish_trajectory_setpoint(const TrjControlMode trj_ctrl_mode, const Vector3f& input, const float yaw = 0.0);
    void arm();
    void disarm();
    
    //callbacks
    void timer_query_cmd_callback();


};

#endif

