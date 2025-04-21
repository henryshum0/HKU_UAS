#include <flight_control/input_parser.hpp>

InputParser::InputParser(std::shared_ptr<ExecutorStorage> executor_storage) : rclcpp::Node("input_parser")
{
    this->executor_storage = executor_storage;
    response_publisher = this->create_publisher<UserCommand>("/flight_control/user_input_ack", 10);

    auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);
    input_subscriber = this->create_subscription<UserCommand>("/flight_control/user_input", 
        qos, std::bind(&InputParser::new_input_callback, this, std::placeholders::_1));
}

void InputParser::new_input_callback(const UserCommand::UniquePtr msg)
{
    UserCommand response_msg{};
    int takeoff_c = executor_storage->get_takeoff_C();
    int landing_c = executor_storage->get_land_c();
    switch(msg->command)
    {
        case UserCommand::TAKEOFF:
            //perform checking
            if(takeoff_c != landing_c)
            {
                response_msg.response = UserCommand::REJECT_LAND_BEFORE_TAKEOFF;
                this->response_publisher->publish(response_msg);
                print_rej_msg(UserCommand::REJECT_LAND_BEFORE_TAKEOFF);
            }
            else if (msg->z > TAKEOFF_HEIGHT_MAX)
            {
                response_msg.response = UserCommand::REJECT_TAKEOFF_HEIGHTINFEASIBLE;
                this->response_publisher->publish(response_msg);
                print_rej_msg(UserCommand::REJECT_TAKEOFF_HEIGHTINFEASIBLE);
            }

            //add waypoint to executor storage
            else
            {
                executor_storage->add_waypoint(std::make_shared<Waypoint>
                    (
                        Vector3f(NAN, NAN, msg->z),
                        TAKEOFF_SPEED,
                        MISSION::TAKEOFF            
                    ));
                executor_storage->takeoff_c_incr();
                response_msg.response = UserCommand::SUCCESS;
                this->response_publisher->publish(response_msg);
                RCLCPP_INFO(this->get_logger(), "received TAKEOFF waypoint SUCCESS");
            }
            break;
        
        case UserCommand::LAND:
            if(landing_c >= takeoff_c)
            {
                response_msg.response = UserCommand::REJECT_TAKEOFF_BEFORE_LAND;
                this->response_publisher->publish(response_msg);
                print_rej_msg(UserCommand::REJECT_TAKEOFF_BEFORE_LAND);
            }
            else
            {
                executor_storage->add_waypoint(std::make_shared<Waypoint>
                (
                    Vector3f(NAN, NAN, NAN),
                    LAND_DESCENT_SPEED,
                    MISSION::LAND            
                ));
                executor_storage->land_c_incr();
                response_msg.response = UserCommand::SUCCESS;
                this->response_publisher->publish(response_msg);
                RCLCPP_INFO(this->get_logger(), "received LAND waypoint SUCCESS");
            }
            break;

        case UserCommand::WAYPOINT:
            if(takeoff_c - landing_c<= 0)
            {
                response_msg.response = UserCommand::REJECT_TAKEOFF_REQUIRED;
                this->response_publisher->publish(response_msg);
                print_rej_msg(UserCommand::REJECT_TAKEOFF_REQUIRED);
            }
            else if(msg->use_xy)
            {
                executor_storage->add_waypoint(std::make_shared<Waypoint>
                (
                    Vector3f(msg->x, msg->y, msg->z),
                    msg->speed,
                    MISSION::WAYPOINT_XY           
                ));
                response_msg.response = UserCommand::SUCCESS;
                this->response_publisher->publish(response_msg);
                RCLCPP_INFO(this->get_logger(), "received WAYPOINT_XY waypoint SUCCESS");
            }
            else
            {
                executor_storage->add_waypoint(std::make_shared<Waypoint>
                (
                    Vector3f(msg->lon, msg->lat, msg->z),
                    msg->speed,
                    MISSION::WAYPONT_LONLAT            
                ));
                response_msg.response = UserCommand::SUCCESS;
                this->response_publisher->publish(response_msg);
                RCLCPP_INFO(this->get_logger(), "received WAYPOINT_LONLAT waypoint SUCCESS");
            }
            break;

        case UserCommand::EXECUTE:
            if(executor_storage->get_waypoints_count() < 1)
            {
                response_msg.response = UserCommand::REJECT_EMPTY_WAYPOINTS;
                this->response_publisher->publish(response_msg);
            }
            else
            {
                executor_storage->set_is_execute(true);
                response_msg.response = UserCommand::SUCCESS;
                this->response_publisher->publish(response_msg);
                RCLCPP_INFO(this->get_logger(), "received user command to EXECUTE");
            }
            
            break;
            
        default:
            response_msg.response = UserCommand::REJECT;
            this->response_publisher->publish(response_msg);
            break;
    }
}

void InputParser::print_rej_msg(const uint8_t reason)
{
    std::string reason_str ;
    switch (reason)
    {
        case UserCommand::REJECT:
            reason_str = "none";
            break;
        case UserCommand::REJECT_LAND_BEFORE_TAKEOFF:
            reason_str = "must land before takeoff";
            break;
        case UserCommand::REJECT_TAKEOFF_REQUIRED:
            reason_str = "must take off first";
            break;
        case UserCommand::REJECT_TAKEOFF_BEFORE_LAND:
            reason_str = "must takeoff before land"; 
            break;
        case UserCommand::REJECT_SETPOINT_OUTOFREACH: //unused
            reason_str = "the waypoint is out of reach"; 
            break;
        case UserCommand::REJECT_TAKEOFF_HEIGHTINFEASIBLE:
            reason_str = "take off height is not feasible";
            break;
        case UserCommand::REJECT_SPEED_INFEASIBLE: //unused
            reason_str = "speed is not feasible";
            break;
        case UserCommand::REJECT_EMPTY_WAYPOINTS:
            reason_str = "has empty waypoints, cannot execute";
            break;
        default:
            reason_str = "none";
            break;
    }
    RCLCPP_INFO_STREAM(this->get_logger(), "WAYPOINT is rejected, " << "Reason:" <<reason_str);
}