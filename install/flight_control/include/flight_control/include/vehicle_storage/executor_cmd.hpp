#ifndef VEHICLE_CMD_HPP
#define VEHICLE_CMD_HPP

#include <Eigen/Dense>

using namespace Eigen;
enum VehicleCMD
{
    ARM = 1,
    DISARM,
    PUBLISH_TRJ,
    TERMINATE,
    NO_CMD
};

class ExecutorCommand
{
    public:
    ExecutorCommand();

    VehicleCMD get_vehicle_cmd_curr();
    VehicleCMD get_vehicle_cmd_last();
    Vector3f get_desired_trj();
    Vector3f get_desired_trj_last();
    float get_desired_yaw();
    float get_desired_yaw_last();

    void set_vehicle_cmd_curr(const VehicleCMD cmd);
    void set_vehicle_cmd_last(const VehicleCMD cmd);
    void set_desired_trj(const Vector3f trj);
    void set_desired_trj_last(const Vector3f trj);
    void set_desired_yaw(const float yaw);
    void set_desired_yaw_last(const float yaw);

    private:
    VehicleCMD cmd_curr, cmd_last;
    Vector3f desired_trj, desired_trj_last; float desired_yaw, desired_yaw_last;
    
};
#endif
