#ifndef VEHICLE_STATE_STORAGE_HPP
#define VEHICLE_STATE_STORAGE_HPP

#include <Eigen/Dense>
#include <chrono>

using namespace Eigen;
using namespace std::literals::chrono_literals;


class VehicleStateStorage
{
    public:
    VehicleStateStorage();

    //get methods
    bool get_is_landed();
    bool get_is_arm();
    bool get_is_offboard();
    bool get_is_init();
    bool get_pos_lon_lat_valid();

    void set_is_landed(const bool is_no);
    void set_is_arm(const bool is_no);
    void set_is_offboard(const bool is_no);
    void set_is_init();
    void set_pos_lon_lat_valid(const bool is_no);

    Vector3f get_pos();
    Vector3f get_vel();
    Vector3f get_accel();
    float get_yaw();
    Vector3f get_pos_lon_lat();
    Vector3f get_pos_avg();
    Vector3f get_vel_avg();
    Vector3f get_accel_avg();
    float get_yaw_avg();

    void set_pos(const Vector3f pos);
    void set_vel(const Vector3f vel);
    void set_accel(const Vector3f accel);
    void set_yaw(const float yaw);
    void set_pos_lon_lat(const Vector3f pos_lon_lat);
    void set_pos_avg(const Vector3f new_pos);
    void set_vel_avg(const Vector3f new_vel);
    void set_accel_avg(const Vector3f new_accel);
    void set_yaw_avg(const float new_yaw);

    
    private:
    bool is_landed, is_arm, is_offboard, is_init, pos_lon_lat_valid;

    Vector3f pos, pos_lon_lat, vel, accel; 
    Vector3f pos_avg, vel_avg, accel_avg, origin_lon_lat;
    float yaw, yaw_avg;
};






#endif
