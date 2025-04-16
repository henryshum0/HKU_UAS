#include <rclcpp/rclcpp.hpp>
#include <offboard_control_interfaces/msg/user_command.hpp>

#include <sstream>
using namespace offboard_control_interfaces::msg;
class UserInput : public rclcpp::Node
{
    public:
    UserInput() : Node("user_input")
    {
        user_input_publisher = this->create_publisher<UserCommand>("/flight_control/user_input",10);
        auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);
        response_subscriber = this->create_subscription<UserCommand>("/flight_control/user_input_ack", 
            qos, std::bind(&UserInput::response_callback, this, std::placeholders::_1));

        user_input_thread = std::thread(&UserInput::query_user, this);
        user_input_thread.detach();
    }


    private:
    rclcpp::Publisher<UserCommand>::SharedPtr user_input_publisher;
    rclcpp::Subscription<UserCommand>::SharedPtr response_subscriber;
    rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;

    std::thread user_input_thread;
    std::istringstream iss;
    
    void query_user();
    void send(const int &cmd, const bool &use_xy, const float &x_lon,
            const float &y_lat, const float &z, const float &speed, const float &yaw);
    bool check_valid_coord(const bool &use_xy, const float &x_lon, const float &y_lat);
    bool check_valid_z(const float &z);
    bool check_valid_speed(const float &speed);
    bool check_valid_yaw(const float &yaw);

    void response_callback(const UserCommand::UniquePtr msg);
    void print_rej_msg(const uint8_t reason);
};

void UserInput::query_user()
{
    while (rclcpp::ok())
    {
        std::cout << "\n[COMMAND] [XYZ?] [x/lon] [y/lat] [z wrp to drone start pos] [speed] [yaw in rad optional wrt ENU]" << std::endl
                  << "input your command: " <<std::endl;

        std::string input;
        std::string input_cmd;
        iss.clear();
        std::cin.clear();
        std::getline(std::cin, input);
        iss.str(input);
    
        if (!(iss >> input_cmd))
        {
            std::cout << "incorrect command\n" << std::endl;  
            continue;
        }
        if (input_cmd == "TAKEOFF")
        {
            float takeoff_height;
            if(!(iss>>takeoff_height))
            {
                takeoff_height = NAN;
            }
            if(!check_valid_z(takeoff_height))
            {
                std::cout <<"incorrect takeoff height" << std::endl;
                continue;
            }
            send(UserCommand::TAKEOFF, 1, NAN, NAN, takeoff_height, NAN, NAN);
            continue;
        }
        else if (input_cmd == "LAND")
        {
            send(UserCommand::LAND, 1, NAN, NAN, NAN, NAN, NAN);
            continue;
        }
        else if (input_cmd == "WAYPOINT")
        {
            std::string use_xy_str;
            bool use_xy;
            float x_lon, y_lat, z, speed, yaw;
            if(!(iss>>use_xy_str))
            {
                std::cout<<"invalid input"<<std::endl;
            }
            else
            {
                if (use_xy_str == "false") {use_xy = false;}
                else if (use_xy_str == "true") {use_xy = true;}
                else
                {   
                    std::cout<<"specify use_xy or not, true to use xy false to use lon lat"<<std::endl;
                    continue;
                }
            }
            
            if(!(iss>>x_lon>>y_lat) || !check_valid_coord(use_xy, x_lon, y_lat))
            {
                std::cout<<"invalid x_lon or y_lat"<<std::endl;
                continue;
            }

            if(!(iss>>z) || !check_valid_z(z))
            {   
                std::cout<<"invalid z"<<std::endl;
                continue;
            }
            
            if(!(iss>>speed) || !check_valid_speed(speed))
            {
                std::cout<<"invalid speed"<<std::endl;
                continue;
            }
            
            if(!(iss>>yaw) || !check_valid_yaw(yaw))
            {
                std::cout<<"invalid yaw"<<std::endl;
                continue;
            }

            send(UserCommand::WAYPOINT, use_xy, x_lon, y_lat, z, speed, yaw);
        }
        else if (input_cmd == "AIRDROP")
        {
            std::cout << "unavailable" << std::endl;  
            continue;
        }
        else if (input_cmd == "MAPPING")
        {
            std::cout << "unavailable" << std::endl;  
            continue;
        }
        else if (input_cmd == "EXECUTE")
        {
            send(UserCommand::EXECUTE, 1, NAN, NAN, NAN, NAN, NAN);
        }
        else
        {
            std::cout << "incorrect input\n" << std::endl;  
            continue;
        }
    }
}

void UserInput::send(const int &cmd, const bool &use_xy, const float &x_lon,
    const float &y_lat, const float &z, const float &speed, const float &yaw)
{
    UserCommand msg{};
    msg.command = cmd;
    msg.use_xy = use_xy;
    if(use_xy)
    {
        msg.x = x_lon;
        msg.y = y_lat;
        msg.lat = NAN;
        msg.lon = NAN;
    }
    else
    {
        msg.lon = x_lon;
        msg.lat = y_lat;
        msg.x = NAN;
        msg.y = NAN;
    }
    z == -1.f ? msg.z = NAN : msg.z = z;
    speed == -1.f ? msg.speed = NAN : msg.speed = speed;
    yaw == -1.f ? msg.yaw = NAN : msg.yaw = yaw;
    this->user_input_publisher->publish(msg);
    // RCLCPP_INFO_STREAM(this->get_logger(),
    //     "\nsend command: "<<cmd<<std::endl
    //     <<"use_xyz: "<<use_xy<<std::endl
    //     <<"x or longitude: "<< x_lon<<std::endl
    //     <<"y or latitude: "<< y_lat<<std::endl
    //     <<"z: "<<z<<std::endl
    //     <<"speed: " <<speed<<std::endl
    //     <<"yaw: "<<yaw  
    // );
}

void UserInput::response_callback(const UserCommand::UniquePtr msg)
{
    if(msg->response == UserCommand::SUCCESS)
    {
        RCLCPP_INFO(this->get_logger(), "WAYPOINT accepted");
    }
    else
    {
        print_rej_msg(msg->response);
    }
}

bool UserInput::check_valid_coord(const bool &use_xy, const float &x_lon, const float &y_lat)
{
    if(!use_xy && (x_lon < -180 || x_lon > 180 || y_lat < -90 || y_lat > 90))
    {
        return false;
    }
    return true;
}

bool UserInput::check_valid_z(const float &z)
{
    if(z == -1) {return true;}
    if(z < 1 || z > 150)
    {
        return false;
    }
    return true;
}

bool UserInput::check_valid_yaw(const float &yaw)
{
    if(yaw == -1) {return true;}
    if(yaw < -180 || yaw > 180)
    {
        return false;
    }
    return true;
}

bool UserInput::check_valid_speed(const float &speed)
{
    if(speed == -1) {return true;}
    if (speed<0 || speed > 20)
    {
        return false;
    }
    return true;
}


void UserInput::print_rej_msg(const uint8_t reason)
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
        case UserCommand::REJECT_SETPOINT_OUTOFREACH:
            reason_str = "the waypoint is out of reach"; 
            break;
        case UserCommand::REJECT_TAKEOFF_HEIGHTINFEASIBLE:
            reason_str = "take off height is not feasible";
            break;
        case UserCommand::REJECT_SPEED_INFEASIBLE:
            reason_str = "speed is not feasible";
            break;
        case UserCommand::REJECT_EMPTY_WAYPOINTS:
            reason_str = "has empty waypoints, cannot execute";
            break;
        default:
            reason_str = "none";
            break;
    }
    RCLCPP_INFO_STREAM(this->get_logger(), "WAYPOINT is rejected" <<std::endl<< "Reason:" <<reason_str);
}

int main(int argc, char *argv[])
{
	setvbuf(stdout, NULL, _IONBF, BUFSIZ);
	rclcpp::init(argc, argv);
	rclcpp::spin(std::make_shared<UserInput>());
	rclcpp::shutdown();
	return 0;
}
