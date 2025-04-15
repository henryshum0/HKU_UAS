
#include <rclcpp/rclcpp.hpp>
#include <px4_msgs/msg/vehicle_command_ack.hpp>

#include <cstdlib>

/**
 * @brief Sensor Combined uORB topic data callback
 */
class VehicleCommandAckListener : public rclcpp::Node
{
public:
    explicit VehicleCommandAckListener() : Node("cmd_ack_listener")
    {
        rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
        auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);
        
        subscription_ = this->create_subscription<px4_msgs::msg::VehicleCommandAck>("/fmu/out/vehicle_command_ack", qos,
        [this](const px4_msgs::msg::VehicleCommandAck::UniquePtr msg) {
            std::system("clear");
            std::cout << "\rCommand Ack" <<std::endl
                      << " | ts: " << msg->timestamp  << std::endl
                      << " | result: " << static_cast<int>(msg->result) << std::endl
                      << " | result-param1: " << static_cast<int>(msg->result_param1) << std::endl
                      << " | result-param2: " << msg->result_param2 << std::endl
                      << "    " // Padding to clear previous content
                      << std::flush<<std::endl;
        });
    }

private:
    rclcpp::Subscription<px4_msgs::msg::VehicleCommandAck>::SharedPtr subscription_;

};

int main(int argc, char *argv[])
{
    std::cout << "Starting cmd_ack listener node..." << std::endl;
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<VehicleCommandAckListener>());

    rclcpp::shutdown();
    return 0;
}
