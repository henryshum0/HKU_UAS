#include <vehicle_storage/executor_storage.hpp>

ExecutorStorage::ExecutorStorage()
{
    this->is_init = false;
    this->is_execute = false;
    this->is_mission_fin = false;
    this->cmd_curr = VehicleCMD::NO_CMD;
    this->trj_control_mode = TrjControlMode::VELOCITY;
    this->desired_trj = Vector3f(0.f, 0.f, 0.f);
    this->desired_yaw = NAN;
    this->takeoff_c = 0;
    this->land_c = 0;
}

bool ExecutorStorage::get_is_init() {return this->is_init;}
bool ExecutorStorage::get_is_execute() {return this->is_execute;}
bool ExecutorStorage::get_is_mission_fin() {return this->is_mission_fin;}
void ExecutorStorage::set_is_init() {this->is_init = true;}
void ExecutorStorage::set_is_execute(const bool is_no) {this->is_execute = is_no;}
void ExecutorStorage::set_is_mission_fin(const bool is_no) {this->is_mission_fin = is_no;}

void ExecutorStorage::takeoff_c_incr() {this->takeoff_c++;}
void ExecutorStorage::land_c_incr() {this->land_c++;}
int ExecutorStorage::get_takeoff_C() {return this->takeoff_c;}
int ExecutorStorage::get_land_c() {return this->land_c;}

VehicleCMD ExecutorStorage::get_vehicle_cmd_curr() {return this->cmd_curr;}
TrjControlMode ExecutorStorage::get_trj_ctrl_mode() {return this->trj_control_mode;}
void ExecutorStorage::set_vehicle_cmd_curr(const VehicleCMD cmd) {this->cmd_curr = cmd;}
void ExecutorStorage::set_trj_ctrl_mode(const TrjControlMode mode) {this->trj_control_mode = mode;}

Vector3f ExecutorStorage::get_desired_trj() {return this->desired_trj;}
float ExecutorStorage::get_desired_yaw() {return this->desired_yaw;}
void ExecutorStorage::set_desired_trj(const Vector3f pos) {this->desired_trj = pos;}
void ExecutorStorage::set_desired_yaw(const float yaw) {this->desired_yaw = yaw;}


void ExecutorStorage::add_waypoint(const std::shared_ptr<Waypoint> waypoint) {this->waypoints.push_back(waypoint);}
void ExecutorStorage::pop_waypoints_end() {this->waypoints.pop_back();}
std::shared_ptr<Waypoint> ExecutorStorage::get_waypoint_curr() 
{
    if (waypoints.empty()) return nullptr;
    
    if(waypoints.front()->mission_completed)
    {
        waypoints_fin.push_back(waypoints.front());
        waypoints.pop_front();
        if(waypoints.empty()) return nullptr;
    }

    return waypoints.front();
}
std::shared_ptr<Waypoint> ExecutorStorage::get_waypoint_completed_last() 
{
    if(waypoints_fin.empty()) return nullptr;
    else return waypoints_fin.back();
}

int ExecutorStorage::get_mission_count(MISSION mission)
{
    int count = 0;
    for (const auto &waypoint : this->waypoints)
    {
        if(waypoint && waypoint->mission == mission) {count++;}
    }
    return count;
}
int ExecutorStorage::get_waypoints_count()
{
    return this->waypoints.size();
}