
#include <rclcpp/rclcpp.hpp>
#include <px4_msgs/msg/trajectory_setpoint.hpp>

#include <cstdlib>

class TrajectorySetpointListener : public rclcpp::Node
{
public:
    explicit TrajectorySetpointListener() : Node("publish_trj_listener")
    {
        rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
        auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);
        
        subscription_ = this->create_subscription<px4_msgs::msg::TrajectorySetpoint>("/fmu/in/trajectory_setpoint", qos,
        [this](const px4_msgs::msg::TrajectorySetpoint::UniquePtr msg) {
            std::system("clear");
            std::cout << "\rRECEIVED SENSOR COMBINED DATA" <<std::endl
                      << " | ts: " << msg->timestamp  << std::endl
                      << " | pos_published: " << msg->position[0] <<' '<<msg->position[1] <<' '<< msg->position[2] <<' ' << std::endl
                      << " | vel_published: " << msg->velocity[0] <<' '<<msg->velocity[1] <<' '<< msg->velocity[2] <<' ' << std::endl
                      << " | accel_published: " << msg->acceleration[0] <<' '<<msg->acceleration[1] <<' '<< msg->acceleration[2] <<' ' << std::endl
                      << " | yaw_published: " << msg->yaw << std::endl
                      << "    " // Padding to clear previous content
                      << std::flush<<std::endl;
        });
    }

private:
    rclcpp::Subscription<px4_msgs::msg::TrajectorySetpoint>::SharedPtr subscription_;

};

int main(int argc, char *argv[])
{
    std::cout << "Starting sensor_combined listener node..." << std::endl;
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TrajectorySetpointListener>());

    rclcpp::shutdown();
    return 0;
}
