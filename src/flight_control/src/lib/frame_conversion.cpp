#include <lib/utils.hpp>

using namespace Eigen;



namespace utils{

    Vector3f enu_ned_convert(const Vector3f& in){
        Vector3f out;
        out.x() = in.y();
        out.y() = in.x();
        out.z() = -in.z();
        return out;
    }


    Vector3f flu_frd_convert(const Vector3f& in){
        Vector3f out;
        out.x() = in.x();
        out.y() = -in.y();
        out.z() = -in.z();
        return out;
    }

    float enu_ned_yaw_convert(const float yaw)
    {
        return M_PI/2 - yaw;
    }
}

