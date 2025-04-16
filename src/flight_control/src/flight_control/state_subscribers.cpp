#include <flight_control/state_subscribers.hpp>


StateSubscriber::StateSubscriber(const std::shared_ptr<VehicleStateStorage> vehicle_state_storage):rclcpp::Node("state_subscriber")
{
    this->vehicle_state_storage = vehicle_state_storage;

    //create subscribition
    auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);
    this->local_position_subscriber = this->create_subscription<VehicleLocalPosition>("/fmu/out/vehicle_local_position", 
        qos, std::bind(&StateSubscriber::local_pos_callback, this, std::placeholders::_1));
    this -> vehicle_status_subscriber = this->create_subscription<VehicleStatus>("/fmu/out/vehicle_status_v1", 
        qos, std::bind(&StateSubscriber::vehicle_status_callback, this, std::placeholders::_1));
    this -> vehicle_land_subscriber = this->create_subscription<VehicleLandDetected>("/fmu/out/vehicle_land_detected", 
        qos, std::bind(&StateSubscriber::vehicle_land_callback, this, std::placeholders::_1));
    this -> vehicle_global_pos_subscriber = this->create_subscription<SensorGps>("/fmu/out/vehicle_gps_position", 
        qos, std::bind(&StateSubscriber::global_pos_callback, this, std::placeholders::_1));
}

void StateSubscriber::local_pos_callback(const VehicleLocalPosition::UniquePtr msg)
{
    Vector3f ned_pos(msg->x, msg->y, msg->z);
    Vector3f ned_vel(msg->vx, msg->vy, msg->vz);
    Vector3f ned_accel(msg->ax, msg->ay, msg->az);
    Vector3f home(msg->ref_lon, msg->ref_lat, msg->ref_alt);

    Vector3f pos_enu = utils::enu_ned_convert(ned_pos);
    Vector3f vel_enu = utils::enu_ned_convert(ned_vel);
    Vector3f accel_enu = utils::enu_ned_convert(ned_accel);
    float yaw_enu = utils::enu_ned_yaw_convert(msg->heading);

    vehicle_state_storage->set_pos(pos_enu);
    vehicle_state_storage->set_pos_avg(pos_enu);
    vehicle_state_storage->set_vel(vel_enu);
    vehicle_state_storage->set_vel_avg(vel_enu);
    vehicle_state_storage->set_accel(accel_enu);
    vehicle_state_storage->set_accel_avg(accel_enu);
    vehicle_state_storage->set_yaw(yaw_enu);
    vehicle_state_storage->set_yaw_avg(yaw_enu);

    vehicle_state_storage->set_is_init();
    RCLCPP_INFO_STREAM_ONCE
    (
        this->get_logger(), 
        "state storage initialized "<<std::endl
        <<"home[lon, lat, AMSL]: "<<home.x()<<" "<<home.y()<<" "<<home.z() <<std::endl
        <<"pos: "<<pos_enu.x()<<" "<<pos_enu.y()<<" "<<pos_enu.z()<<std::endl
        <<"heading: "<<yaw_enu
    );
}

void StateSubscriber::vehicle_status_callback(const VehicleStatus::UniquePtr msg)
{
    switch(msg -> arming_state)
    {
        case VehicleStatus::ARMING_STATE_ARMED: 
            if(!vehicle_state_storage->get_is_arm())
            {
                vehicle_state_storage->set_is_arm(true); 
                RCLCPP_INFO(this->get_logger(), "Vehicle is armed!");
            }
            break;
        default: 
            if(vehicle_state_storage->get_is_arm())
            {
                vehicle_state_storage->set_is_arm(false); 
                RCLCPP_INFO(this->get_logger(), "Vehicle is disarmed!");
            }
            break;
    }

    switch(msg -> nav_state)
    {
        case VehicleStatus::NAVIGATION_STATE_OFFBOARD: 
            if(!vehicle_state_storage->get_is_offboard())
            {
                vehicle_state_storage->set_is_offboard(true); 
                RCLCPP_INFO(this->get_logger(), "offboard mode is active!");
            }
            break;
            
        default:
            if(vehicle_state_storage->get_is_offboard())
            {
                vehicle_state_storage->set_is_offboard(false); 
                RCLCPP_INFO(this->get_logger(), "offboard mode is inactive!");
            }
            break; 
    }
}

void StateSubscriber::vehicle_land_callback(const VehicleLandDetected::UniquePtr msg)
{
    if(!vehicle_state_storage->get_is_landed() && msg->landed) 
    {
        vehicle_state_storage->set_is_landed(msg->landed);
        RCLCPP_INFO(this->get_logger(), "vehicle land detected!");
    }
    else if (vehicle_state_storage->get_is_landed() && !msg->landed)
    {
        vehicle_state_storage->set_is_landed(msg->landed);
        RCLCPP_INFO(this->get_logger(), "vehicle takeoff!");
    }
    
}

void StateSubscriber::global_pos_callback(const SensorGps::UniquePtr msg)
{   
    vehicle_state_storage->set_pos_lon_lat(Vector3f(msg->longitude_deg, msg->latitude_deg, msg->altitude_msl_m));
    RCLCPP_INFO_STREAM
    (
        this->get_logger(), 
        "pos[lon, lat, AMSL]: "<<msg->longitude_deg<<" "<<msg->latitude_deg<<" "<<msg->altitude_msl_m
    );
}