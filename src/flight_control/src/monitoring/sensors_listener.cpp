
 #include <rclcpp/rclcpp.hpp>
 #include <px4_msgs/msg/sensor_combined.hpp>
 
 #include <cstdlib>
 
 /**
  * @brief Sensor Combined uORB topic data callback
  */
 class SensorCombinedListener : public rclcpp::Node
 {
 public:
     explicit SensorCombinedListener() : Node("sensor_combined_listener")
     {
         rmw_qos_profile_t qos_profile = rmw_qos_profile_sensor_data;
         auto qos = rclcpp::QoS(rclcpp::QoSInitialization(qos_profile.history, 5), qos_profile);
         
         subscription_ = this->create_subscription<px4_msgs::msg::SensorCombined>("/fmu/out/sensor_combined", qos,
         [this](const px4_msgs::msg::SensorCombined::UniquePtr msg) {
             std::system("clear");
             std::cout << "\rRECEIVED SENSOR COMBINED DATA" <<std::endl
                       << " | ts: " << msg->timestamp  << std::endl
                       << " | gyro_rad[0]: " << msg->gyro_rad[0] << std::endl
                       << " | gyro_rad[1]: " << msg->gyro_rad[1] << std::endl
                       << " | gyro_rad[2]: " << msg->gyro_rad[2] << std::endl
                       << " | gyro_integral_dt: " << msg->gyro_integral_dt << std::endl
                       << " | accelerometer_timestamp_relative: " << msg->accelerometer_timestamp_relative << std::endl
                       << " | accelerometer_m_s2[0]: " << msg->accelerometer_m_s2[0] << std::endl
                       << " | accelerometer_m_s2[1]: " << msg->accelerometer_m_s2[1] << std::endl
                       << " | accelerometer_m_s2[2]: " << msg->accelerometer_m_s2[2] << std::endl
                       << " | accelerometer_integral_dt: " << msg->accelerometer_integral_dt << std::endl
                       << "    " // Padding to clear previous content
                       << std::flush<<std::endl;
         });
     }
 
 private:
     rclcpp::Subscription<px4_msgs::msg::SensorCombined>::SharedPtr subscription_;
 
 };
 
 int main(int argc, char *argv[])
 {
     std::cout << "Starting sensor_combined listener node..." << std::endl;
     setvbuf(stdout, NULL, _IONBF, BUFSIZ);
     rclcpp::init(argc, argv);
     rclcpp::spin(std::make_shared<SensorCombinedListener>());
 
     rclcpp::shutdown();
     return 0;
 }
 