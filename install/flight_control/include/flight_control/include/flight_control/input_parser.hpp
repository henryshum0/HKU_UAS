#ifndef UESR_INPUT_PARSER_HPP
#define UESR_INPUT_PARSER_HPP
#include <rclcpp/rclcpp.hpp>
#include <offboard_control_interfaces/msg/user_command.hpp>
#include <vehicle_storage/executor_storage.hpp>

using namespace offboard_control_interfaces::msg;
class InputParser : public rclcpp::Node
{
    public:
    InputParser(std::shared_ptr<ExecutorStorage> executor_storage);

    private:
    rclcpp::Subscription<UserCommand>::SharedPtr input_subscriber;
    rclcpp::Publisher<UserCommand>::SharedPtr response_publisher;
    rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;

    std::shared_ptr<ExecutorStorage> executor_storage;

    void new_input_callback(const UserCommand::UniquePtr msg); //called when there is new input from user
    void print_rej_msg(const uint8_t reason);
};

#endif
