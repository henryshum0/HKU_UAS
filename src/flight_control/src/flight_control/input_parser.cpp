#include <flight_control/input_parser.hpp>

InputParser::InputParser(std::shared_ptr<ExecutorStorage> executor_storage) : rclcpp::Node("input_parser")
{
    this->executor_storage = executor_storage;
    response_publisher = this->create_publisher<UserCommand>("/flight_control/input_response", 10);

    auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);
    input_subscriber = this->create_subscription<UserCommand>("/flight_control/user_input", 
        qos, std::bind(&InputParser::new_input_callback, this, std::placeholders::_1));
}

void InputParser::new_input_callback(const UserCommand::UniquePtr msg)
{
    UserCommand response_msg{};
    switch(msg->command)
    {
        //case when user input a TAKEOFF waypoint
        case(UserCommand::TAKEOFF):
            //perform checking
            int takeoff_c = executor_storage->get_mission_count(MISSION::TAKEOFF);
            int landing_c = executor_storage->get_mission_count(MISSION::LAND);
            if(takeoff_c != landing_c)
            {
                response_msg.response = UserCommand::REJECT_LAND_BEFORE_TAKEOFF;
                this->response_publisher->publish(response_msg);
                RCLCPP_INFO(this->get_logger(), "received takeoff waypoint FAILED REJECT_LAND_BEFORE_TAKEOFF");
            }
            else if (msg->z > TAKEOFF_HEIGHT_MAX)
            {
                response_msg.response = UserCommand::REJECT_TAKEOFF_HEIGHTINFEASIBLE;
                this->response_publisher->publish(response_msg);
                RCLCPP_INFO(this->get_logger(), "received takeoff waypoint FAILED REJECT_TAKEOFF_HEIGHTINFEASIBLE");
            }

            //add waypoint to executor storage
            else
            {
                executor_storage->add_waypoint(std::make_shared<Waypoint>
                    (
                        Vector3f(NAN, NAN, msg->z),
                        1.f,
                        MISSION::TAKEOFF            
                    ));
                response_msg.response = UserCommand::SUCCESS;
                this->response_publisher->publish(response_msg);
                RCLCPP_INFO(this->get_logger(), "received takeoff waypoint SUCCESS");
            }
            break;
        
        //case when user input a WAYPOINT waypoint
        case UserCommand::WAYPOINT:
            
        default:
            response_msg.response = UserCommand::REJECT;
            this->response_publisher->publish(response_msg);
            break;
    }
}
