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
    if(!executor_storage->get_is_init())
    {
        if(vehicle_state_storage->get_is_init())
        {
            init_executor_storage();
            RCLCPP_INFO_ONCE(this->get_logger(), "executor storage initialized");
            executor_storage->set_is_init();
        }
        else 
        {
            RCLCPP_INFO(this->get_logger(), "state storage is not init, must init before executor storage");
            return;
        }
    }

    if(!this->vehicle_state_storage->get_is_arm()) {this->executor_storage->set_vehicle_cmd_curr(VehicleCMD::ARM); return;}
    else {this->executor_storage->set_vehicle_cmd_curr(VehicleCMD::PUBLISH_TRJ);}

    //execute main loop only when user input command EXECUTE
    if(executor_storage->get_is_execute())
    {
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
                break;

            case MISSION::WAYPOINT:
                move_to_waypoint(waypoint_curr);
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
}


void FlightExecutor::init_executor_storage()
{
    executor_storage->set_is_execute(true); //FIXME: 
}

//take_off is just a special way point
void FlightExecutor::take_off(std::shared_ptr<Waypoint> take_off_waypoint)
{
    if(take_off_waypoint->is_reached) {take_off_waypoint->mission_completed = true;}
    if(take_off_waypoint->target.hasNaN())
    {
        float height;
        if(take_off_waypoint->target.z() == NAN)
        {
            height = TAKEOFF_HEIGHT_DEFAULT;
        }
        else
        {
            float height = take_off_waypoint->target.z();
        }
        Vector3f pos_curr = vehicle_state_storage->get_pos_avg();
        pos_curr.z()+=height;
        take_off_waypoint->target = pos_curr;
    }
    move_to_waypoint(take_off_waypoint);
    if(take_off_waypoint->is_reached) take_off_waypoint->mission_completed = true;
}

void FlightExecutor::move_to_waypoint(std::shared_ptr<Waypoint> waypoint)
{
    if(!waypoint->is_reached)
    {
        Vector3f pos_avg_curr = vehicle_state_storage->get_pos_avg();
        Vector3f dir = (waypoint->target - pos_avg_curr).normalized();
        set_trj_setpoint_vel(dir * waypoint->speed);
        
        if((waypoint->target - pos_avg_curr).norm() < 2) 
        {
            waypoint->is_reached = true;
            RCLCPP_INFO_STREAM(this->get_logger(), "Waypoint "<<waypoint->target.transpose()<<" is reached");
            set_trj_setpoint_pos(waypoint->target);
            if(waypoint->mission == MISSION::WAYPOINT) {waypoint->mission_completed = true;}
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