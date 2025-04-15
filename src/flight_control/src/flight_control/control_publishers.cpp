#include <flight_control/control_publishers.hpp>

// #define TEST_CTRL_PUBLISHERS

ControlPublisher::ControlPublisher(const std::shared_ptr<ExecutorStorage> executor_storage): rclcpp::Node("control_publisher")
{   

    this->executor_storage = executor_storage;
    rclcpp::Time arm_cmd_sent_time = this->get_clock()->now();

    //create publishers
    this -> offboard_control_mode_publisher = this->create_publisher<OffboardControlMode>("/fmu/in/offboard_control_mode", 10);
    this -> trajectory_setpoint_publisher = this->create_publisher<TrajectorySetpoint>("/fmu/in/trajectory_setpoint", 10);
    this -> vehicle_command_publisher = this->create_publisher<VehicleCommand>("/fmu/in/vehicle_command", 10);
    
    //create timers
    this->timer_query_cmd = this->create_wall_timer(20ms, std::bind(&ControlPublisher::timer_query_cmd_callback,this));
}

void ControlPublisher::publish_vehicle_command(const uint16_t command, const float param1, const float param2)
{
    VehicleCommand msg{};
    msg.param1 = param1;
    msg.param2 = param2;
    msg.command = command;
    msg.target_system = 1;
    msg.target_component = 1;
    msg.source_system = 1;
    msg.source_component = 1;
    msg.from_external = true;
    msg.timestamp = this->get_clock()->now().nanoseconds() / 1000;
    vehicle_command_publisher->publish(msg);
}

void ControlPublisher::publish_offboard_mode(const TrjControlMode trj_ctrl_mode)
{
    OffboardControlMode msg{};

    msg.timestamp = this -> get_clock()->now().nanoseconds() / 1000;
    msg.position = false;
	msg.velocity = false;
	msg.acceleration = false;
	msg.attitude = false;
	msg.body_rate = false;
    
    switch(trj_ctrl_mode)
    {
        case TrjControlMode::POSITION:
            msg.position = true;
            break;

        case TrjControlMode::VELOCITY:
            msg.velocity = true;
            break;

        case TrjControlMode::ACCELERATION:
            msg.acceleration = true;
            break;
    }
    offboard_control_mode_publisher->publish(msg);
}

void ControlPublisher::publish_trajectory_setpoint(const TrjControlMode trj_ctrl_mode, const Vector3f& input, const float yaw)
{
    Vector3f ned_output = utils::enu_ned_convert(input);
    float yaw_ned = utils::enu_ned_yaw_convert(yaw);

    TrajectorySetpoint msg{};

    msg.timestamp = this -> get_clock()->now().nanoseconds() / 1000;

    if(yaw_ned > M_PI) {msg.yaw = M_PI-yaw_ned;}
    else if(yaw_ned < -M_PI) {msg.yaw = -(yaw_ned-M_PI);}
    else {msg.yaw = yaw_ned;}
    
    std::string trj_ctrl_mode_name;
    switch(trj_ctrl_mode)
    {
        case TrjControlMode::POSITION:
            msg.position = {ned_output.x(), ned_output.y(), ned_output.z()};
            trj_ctrl_mode_name = "POSITION";
            break;

        case TrjControlMode::VELOCITY:
            msg.position = {NAN, NAN, NAN};
            msg.velocity = {ned_output.x(), ned_output.y(), ned_output.z()};
            trj_ctrl_mode_name = "VELOCITY";
            break;

        case TrjControlMode::ACCELERATION:
            msg.position = {NAN, NAN, NAN};
            msg.velocity = {NAN, NAN, NAN};
            msg.acceleration = {ned_output.x(), ned_output.y(), ned_output.z()};
            trj_ctrl_mode_name = "ACCELERATION";
            break;
    }
    // RCLCPP_INFO_STREAM
    // (
    //     this->get_logger(), 
    //     "published "<< trj_ctrl_mode_name <<" setpoints: "<<std::endl
    //     <<"ENU: "<<input.x()<<' '<<input.y()<<' '<<input.z()<<' '<<yaw<<std::endl
    //     <<"NED: "<<ned_output.x()<<' '<<ned_output.y()<<' '<<ned_output.z()<<' '<<yaw_ned
    // );

    trajectory_setpoint_publisher -> publish(msg);
}

void ControlPublisher::arm()
{
    publish_vehicle_command(VehicleCommand::VEHICLE_CMD_COMPONENT_ARM_DISARM, 1.0);
	RCLCPP_INFO(this->get_logger(), "Arm command send");
}

void ControlPublisher::disarm()
{
    publish_vehicle_command(VehicleCommand::VEHICLE_CMD_COMPONENT_ARM_DISARM, 0.0);
	RCLCPP_INFO(this->get_logger(), "Disarm command send");
}


void ControlPublisher::timer_query_cmd_callback()
{
    const VehicleCMD cmd_curr = this->executor_storage->get_vehicle_cmd_curr();
    const Vector3f desired_trj =  this->executor_storage->get_desired_trj();
    const float desired_yaw = this->executor_storage->get_desired_yaw();
    const TrjControlMode trj_ctrl_mode = this->executor_storage->get_trj_ctrl_mode();

    this->publish_offboard_mode(trj_ctrl_mode);

    switch (cmd_curr)
    {
        case VehicleCMD::ARM:
        if(this->get_clock()->now().seconds() - arm_cmd_sent_time.seconds() > 5)
        {
            this->publish_vehicle_command(VehicleCommand::VEHICLE_CMD_DO_SET_MODE, 1, 6);
            this->arm();
            arm_cmd_sent_time = this->get_clock()->now();
            RCLCPP_INFO(this->get_logger(), "VehicleCMD: ARM");
        }
        break;

        case VehicleCMD::DISARM:
            this->disarm();
            RCLCPP_INFO(this->get_logger(), "VehicleCMD: DISARM");
            break;

        case VehicleCMD::PUBLISH_TRJ:
            RCLCPP_INFO(this->get_logger(), "VehicleCMD: PUBLISH_TRJ");
            break;

        case VehicleCMD::NO_CMD:
            RCLCPP_INFO(this->get_logger(), "VehicleCMD: NO_CMD");
            break;

        default:
            RCLCPP_INFO(this->get_logger(), "ERROR");
    }
    
    if(true)//executor_storage->get_is_init())
    {
        this->publish_trajectory_setpoint(trj_ctrl_mode, desired_trj, desired_yaw);
    }
}

