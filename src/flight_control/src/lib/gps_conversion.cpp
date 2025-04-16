#include <lib/utils.hpp>
#include <cmath> // For M_PI


#define EARTH_RADIUS 6371000.0f
namespace utils
{
    Vector3f gps_vector_enu(const float target_lon, const float target_lat, const float source_lon, const float source_lat)
    {
        Vector3f dir;
        dir.x() = M_PI / 180 * (target_lon - source_lon) * EARTH_RADIUS;
        dir.y() = M_PI / 180 * (target_lat - source_lat) * EARTH_RADIUS;
        dir.z() = 0;
        return dir;
    }
}
