#include <vehicle_storage/vehicle_state_storage.hpp>


    VehicleStateStorage::VehicleStateStorage()
    {
        this->is_landed = true;
        this->is_arm = false;
        this->is_offboard = false;
        this->is_init = false;
        this->pos_lon_lat_valid = false;

        this->pos = Vector3f(0.f,0.f,0.f);
        this->vel = Vector3f(0.f,0.f,0.f);
        this->accel = Vector3f(0.f,0.f,0.f);
        this->pos_avg = Vector3f(0.f,0.f,0.f);
        this->vel_avg = Vector3f(0.f,0.f,0.f);
        this->accel_avg = Vector3f(0.f,0.f,0.f);
        this->yaw = 0.f;
        this->pos_lon_lat = Vector3f(NAN, NAN, NAN);
        
    }

    bool VehicleStateStorage::get_is_landed() {return this->is_landed;}
    bool VehicleStateStorage::get_is_arm() {return this->is_arm;}
    bool VehicleStateStorage::get_is_offboard() {return this->is_offboard;}
    bool VehicleStateStorage::get_is_init() {return this->is_init;}

    void VehicleStateStorage::set_is_landed(const bool is_no) {this->is_landed = is_no;}
    void VehicleStateStorage::set_is_arm(const bool is_no) {this->is_arm = is_no;}
    void VehicleStateStorage::set_is_offboard(const bool is_no) {this->is_offboard = is_no;}
    void VehicleStateStorage::set_is_init() {this->is_init = true;}



    Vector3f VehicleStateStorage::get_pos() {return this->pos;}
    Vector3f VehicleStateStorage::get_vel() {return this->vel;}
    Vector3f VehicleStateStorage::get_accel() {return this->accel;}
    float VehicleStateStorage::get_yaw() {return this->yaw;}
    Vector3f VehicleStateStorage::get_pos_lon_lat() {return this->pos_lon_lat;}
    Vector3f VehicleStateStorage::get_pos_avg() {return this->pos_avg;}
    Vector3f VehicleStateStorage::get_vel_avg() {return this->vel_avg;}
    Vector3f VehicleStateStorage::get_accel_avg() {return this->accel_avg;}
    float VehicleStateStorage::get_yaw_avg() {return this->yaw_avg;}

    void VehicleStateStorage::set_pos(const Vector3f pos) {this->pos = pos;}
    void VehicleStateStorage::set_vel(const Vector3f vel) {this->vel = vel;}
    void VehicleStateStorage::set_accel(const Vector3f accel) {this->accel = accel;}
    void VehicleStateStorage::set_yaw(const float yaw) {this->yaw = yaw;}
    void VehicleStateStorage::set_pos_lon_lat(const Vector3f pos_lon_lat) {this->pos_lon_lat = pos_lon_lat;}
    void VehicleStateStorage::set_pos_avg(const Vector3f new_pos) {this->pos_avg = this->pos_avg * .5f + new_pos * .5f;}
    void VehicleStateStorage::set_vel_avg(const Vector3f new_vel) {this->vel_avg = this->vel_avg * .5f + new_vel * .5f;}
    void VehicleStateStorage::set_accel_avg(const Vector3f new_accel) {this->accel_avg = this->accel_avg * .5f + new_accel * .5f;}
    void VehicleStateStorage::set_yaw_avg(const float new_yaw) {this->yaw_avg = this->yaw_avg * .5f + new_yaw * .5f;}
