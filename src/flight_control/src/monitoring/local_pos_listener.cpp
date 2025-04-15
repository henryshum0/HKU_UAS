
 #include <rclcpp/rclcpp.hpp>
 #include <px4_msgs/msg/vehicle_local_position.hpp>
 
 #include <cstdlib>
 
 /**
  * @brief Sensor Combined uORB topic data callback
  */
 class VehicleLocalPositionListener : public rclcpp::Node
 {
 public:
     explicit VehicleLocalPositionListener() : Node("local_pos_listener")
     {
         rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
         auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);
         
         subscription_ = this->create_subscription<px4_msgs::msg::VehicleLocalPosition>("/fmu/out/vehicle_local_position", qos,
         [this](const px4_msgs::msg::VehicleLocalPosition::UniquePtr msg) {
             std::system("clear");
             std::cout << "\rVehicle Local Position" <<std::endl
                       << " | ts: " << msg->timestamp  << std::endl
                       << " | x: " << msg->x << std::endl
                       << " | y: " << msg->y << std::endl
                       << " | z: " << msg->z << std::endl
                       << " | vx: " << msg->vx << std::endl
                       << " | vy: " << msg->vy << std::endl
                       << " | vz: " << msg->vz << std::endl
                       << " | ax: " << msg->ax << std::endl
                       << " | ay: " << msg->ay << std::endl
                       << " | az: " << msg->az << std::endl
                       << "    " // Padding to clear previous content
                       << std::flush<<std::endl;
         });
     }
 
 private:
     rclcpp::Subscription<px4_msgs::msg::VehicleLocalPosition>::SharedPtr subscription_;
 
 };
 
 int main(int argc, char *argv[])
 {
     std::cout << "Starting sensor_combined listener node..." << std::endl;
     setvbuf(stdout, NULL, _IONBF, BUFSIZ);
     rclcpp::init(argc, argv);
     rclcpp::spin(std::make_shared<VehicleLocalPositionListener>());
 
     rclcpp::shutdown();
     return 0;
 }
 