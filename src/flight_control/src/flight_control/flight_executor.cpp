#include <flight_control/flight_executor.hpp>

FlightExecutor::FlightExecutor( const std::shared_ptr<VehicleStateStorage> vehicle_state_storage, 
                                const std::shared_ptr<ExecutorStorage> executor_storage) : 
                                Node("flight_executor")
{
    this->vehicle_state_storage = vehicle_state_storage;
    this->executor_storage = executor_storage;

    this->timer_publish_control =this->create_wall_timer(20ms, std::bind(&FlightExecutor::publish_control,this));
}

void FlightExecutor::publish_control()
{
    if(vehicle_state_storage->get_is_init())
    {
        RCLCPP_INFO_ONCE(this->get_logger(), "vehicle state initialized, ready to execute");
        executor_storage->set_is_init();
    }
    else
    {
        RCLCPP_INFO_ONCE(this->get_logger(), "await vehicle state to initialize");
        return;
    }

    if(!executor_storage->get_is_execute()) {return;}

    //execute main loop only when user input command EXECUTE
    
    
    auto waypoint_curr = executor_storage->get_waypoint_curr();

    if(waypoint_curr == nullptr)
    {
        RCLCPP_INFO(this->get_logger(), "All setpoints completed");
        std::shared_ptr<Waypoint> waypoint_cmplt_last = executor_storage->get_waypoint_completed_last();
        if(waypoint_cmplt_last == nullptr) {set_trj_setpoint_vel(Vector3f(0.f,0.f,0.f));}
        else {set_trj_setpoint_pos(waypoint_cmplt_last->target);}
        executor_storage->set_is_execute(false);
        return;
    }

    switch(waypoint_curr->mission)
    {
        case MISSION::TAKEOFF:
            take_off(waypoint_curr);
            break;

        case MISSION::LAND:
            land(waypoint_curr);
            break;

        case MISSION::WAYPOINT_XY:
            move_to_waypoint(waypoint_curr);
            break;

        case MISSION::WAYPONT_LONLAT:
            move_to_waypoint_lonlat(waypoint_curr);
            break;

        case MISSION::AIDROP:
            break;
            
        case MISSION::MAPPING:
            break;
            
        default:
            RCLCPP_WARN(this->get_logger(), "unknown mission");
            break;
    }
    
}


//take_off is just a special way point
void FlightExecutor::take_off(std::shared_ptr<Waypoint> take_off_waypoint)
{
    if(take_off_waypoint->is_reached) 
    {
        take_off_waypoint->mission_completed = true;
        set_trj_setpoint_pos(take_off_waypoint->target);
        return;
    }
    if(!vehicle_state_storage->get_is_arm())
    {
        executor_storage->set_vehicle_cmd_curr(VehicleCMD::ARM);
    }
    if(take_off_waypoint->target.hasNaN())
    {
        float height;
        if(std::isnan(take_off_waypoint->target.z()))
        {
            height = TAKEOFF_HEIGHT_DEFAULT;
        }
        else
        {
            height = take_off_waypoint->target.z();
        }
        Vector3f pos_curr = vehicle_state_storage->get_pos_avg();
        pos_curr.z()+=height;
        take_off_waypoint->target = pos_curr;
    }
    move_to_waypoint(take_off_waypoint);
}

void FlightExecutor::land(std::shared_ptr<Waypoint> land_waypoint)
{
    if(land_waypoint->is_reached) 
    {
        if(!vehicle_state_storage->get_is_arm()) 
        {
            land_waypoint->mission_completed = true; 
            executor_storage->set_vehicle_cmd_curr(VehicleCMD::NO_CMD);
            return;
        }
        if(!vehicle_state_storage->get_is_landed()) {set_trj_setpoint_vel(Vector3f(0.f, 0.f, -.5));}
        else {executor_storage->set_vehicle_cmd_curr(VehicleCMD::DISARM);}
        return;
    }
    
    if(land_waypoint->target.hasNaN())
    {
        Vector3f pos_land = vehicle_state_storage->get_pos_avg();
        pos_land.z() = 0;
        land_waypoint->target = pos_land;
        land_waypoint->speed = LAND_DESCENT_SPEED;
    }
    move_to_waypoint(land_waypoint);
}

void FlightExecutor::move_to_waypoint_lonlat(std::shared_ptr<Waypoint> waypoint_lonlat)
{
    const Vector3f vector_relative = utils::gps_vector_enu
    (
        waypoint_lonlat->target.x(), 
        waypoint_lonlat->target.y(),
        vehicle_state_storage->get_pos_lon_lat().x(),
        vehicle_state_storage->get_pos_lon_lat().y()
    );
    const Vector3f pos_avg = vehicle_state_storage->get_pos_avg();
    waypoint_lonlat->target.x() = vector_relative.x() + pos_avg.x();
    waypoint_lonlat->target.y() = vector_relative.y() + pos_avg.y();
    if(std::isnan(waypoint_lonlat->target.z())) { waypoint_lonlat->target.z() = executor_storage->get_waypoint_completed_last()->target.z();}
    move_to_waypoint(waypoint_lonlat);
}

void FlightExecutor::move_to_waypoint(std::shared_ptr<Waypoint> waypoint)
{
    if(!waypoint->is_reached)
    {
        Vector3f pos_avg_curr = vehicle_state_storage->get_pos_avg();
        Vector3f dir = (waypoint->target - pos_avg_curr).normalized();
        if(std::isnan(waypoint->target.z())) { waypoint->target.z() = executor_storage->get_waypoint_completed_last()->target.z();}
        if(std::isnan(waypoint->speed))  {waypoint->speed = WAYPOINT_SPEED_DEFAULT;}
        set_trj_setpoint_vel(dir * waypoint->speed);
        if((waypoint->target - pos_avg_curr).norm() < 0.5) 
        {
            waypoint->is_reached = true;
            RCLCPP_INFO_STREAM(this->get_logger(), "Waypoint "<<waypoint->target.transpose()<<" is reached");
            set_trj_setpoint_pos(waypoint->target);
            if(waypoint->mission == MISSION::WAYPOINT_XY || waypoint->mission == MISSION::WAYPONT_LONLAT) {waypoint->mission_completed = true;}
        }
    }
}

void FlightExecutor::set_trj_setpoint_pos(const Vector3f trj_sp_pos, const float yaw)
{
    executor_storage->set_trj_ctrl_mode(TrjControlMode::POSITION);
    executor_storage->set_desired_trj(trj_sp_pos);
    executor_storage->set_desired_yaw(yaw);
}

void FlightExecutor::set_trj_setpoint_vel(const Vector3f trj_sp_vel, const float yaw)
{
    executor_storage->set_trj_ctrl_mode(TrjControlMode::VELOCITY);
    executor_storage->set_desired_trj(trj_sp_vel);
    executor_storage->set_desired_yaw(yaw);
}

void FlightExecutor::set_trj_setpoint_accel(const Vector3f trj_sp_accel, const float yaw)
{
    executor_storage->set_trj_ctrl_mode(TrjControlMode::ACCELERATION);
    executor_storage->set_desired_trj(trj_sp_accel);
    executor_storage->set_desired_yaw(yaw);
}

int main(int argc, char *argv[])
{
	std::cout << "Starting..." << std::endl;
	setvbuf(stdout, NULL, _IONBF, BUFSIZ);

    auto vehicle_state = std::make_shared<VehicleStateStorage>();
    auto executor_cmd = std::make_shared<ExecutorStorage>();

	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<FlightExecutor>(vehicle_state, executor_cmd));

	rclcpp::shutdown();
	return 0;
}