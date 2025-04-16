#ifndef UTILS_H
#define UTILS_H

#include <Eigen/Dense>
#include <cmath>

using namespace Eigen;



namespace utils{
    
    /**
     * @brief convertion between ros2 and px4 for LOCAL WORLD frame
     * @return Eigen::Vector3f transformed coordinates
     */
    Vector3f enu_ned_convert(const Vector3f& in);


    /**
     * @brief convertion between ros2 and px4 for BODY frame
     * @return Eigen::Vector3f transformed coordinates
     */
    Vector3f flu_frd_convert(const Vector3f& in);

    float enu_ned_yaw_convert(const float yaw);
    Vector3f gps_vector_enu(const float target_lon, const float target_lat, const float source_lon, const float source_lat);
}

#endif
