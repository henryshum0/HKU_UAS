#ifndef STATE_SUB_HPP
#define STATE_SUB_HPP

#include <rclcpp/rclcpp.hpp>

#include <px4_msgs/msg/vehicle_local_position.hpp>
#include <px4_msgs/msg/vehicle_status.hpp>
#include <px4_msgs/msg/vehicle_land_detected.hpp>
#include <px4_msgs/msg/sensor_gps.hpp>

#include <vehicle_storage/vehicle_state_storage.hpp>
#include <lib/utils.hpp>

#include <math.h>

using namespace px4_msgs::msg;

//update state variables
class StateSubscriber : public rclcpp::Node
{
    public:
    StateSubscriber(std::shared_ptr<VehicleStateStorage> vehicle_state_storage);

    private:
    std::shared_ptr<VehicleStateStorage> vehicle_state_storage;

    //subscribers qos
    rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
    //subscriber
    rclcpp::Subscription<VehicleLocalPosition>::SharedPtr local_position_subscriber;
    rclcpp::Subscription<VehicleStatus>::SharedPtr vehicle_status_subscriber;
    rclcpp::Subscription<VehicleLandDetected>::SharedPtr vehicle_land_subscriber;
    rclcpp::Subscription<SensorGps>::SharedPtr vehicle_global_pos_subscriber;

    //subscriber callback
    void local_pos_callback(const VehicleLocalPosition::UniquePtr msg);
    void vehicle_status_callback(const VehicleStatus::UniquePtr msg);
    void vehicle_land_callback(const VehicleLandDetected::UniquePtr msg);
    void global_pos_callback(const SensorGps::UniquePtr msg);
};

#endif
