#ifndef EXECUTOR_CMD_STORAGE_HPP
#define EXECUTOR_CMD_STORAGE_HPP

#include <Eigen/Dense>

#include <queue>
#include <memory>

using namespace Eigen;

#define TAKEOFF_HEIGHT_MAX 100.f
#define TAKEOFF_HEIGHT_DEFAULT 3.f
#define TAKEOFF_SPEED 1.f

#define LAND_DESCENT_SPEED 0.8f

#define WAYPOINT_SPEED_DEFAULT 5.f

enum VehicleCMD
{
    ARM = 1,
    DISARM,
    PUBLISH_TRJ,
    TERMINATE,
    NO_CMD
};

enum TrjControlMode
{
    POSITION = 1,
    VELOCITY,
    ACCELERATION
};

enum MISSION
{
    TAKEOFF = 1,
    LAND,
    WAYPOINT_XY,
    WAYPONT_LONLAT,
    AIDROP,
    MAPPING
};

struct Waypoint
{
    Vector3f target;
    float speed;
    MISSION mission;
    bool is_reached = false;
    bool mission_completed = false;

    Waypoint(const Vector3f waypoint_loc, const float reference_speed, const MISSION which_mission): 
        target(waypoint_loc), speed(reference_speed), mission(which_mission) {}
};

class ExecutorStorage
{
    public:
    //get methods
    ExecutorStorage();

    bool get_is_init();
    bool get_is_mission_fin();
    bool get_is_execute();
    void set_is_init();
    void set_is_mission_fin(bool is_no);
    void set_is_execute(bool is_no);

    VehicleCMD get_vehicle_cmd_curr();
    TrjControlMode get_trj_ctrl_mode();
    void set_vehicle_cmd_curr(const VehicleCMD cmd);
    void set_trj_ctrl_mode(const TrjControlMode mode);

    Vector3f get_desired_trj();
    float get_desired_yaw();
    void set_desired_trj(const Vector3f pos);
    void set_desired_yaw(const float yaw);

    void add_waypoint(const std::shared_ptr<Waypoint> waypoint);
    void pop_waypoints_end();
    std::shared_ptr<Waypoint> get_waypoint_curr();
    std::shared_ptr<Waypoint> get_waypoint_completed_last();

    int get_mission_count(MISSION mission);
    int get_waypoints_count();


    private:
    bool is_mission_fin, is_execute, is_init;

    std::deque<std::shared_ptr<Waypoint>> waypoints;
    std::vector<std::shared_ptr<Waypoint>> waypoints_fin;

    VehicleCMD cmd_curr;
    TrjControlMode trj_control_mode;

    Vector3f desired_trj; 
    float desired_yaw;
    
    float dt;
};
#endif
