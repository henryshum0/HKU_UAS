cmake_minimum_required(VERSION 3.8)
project(flight_control)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(px4_msgs REQUIRED)
find_package(px4_ros_com REQUIRED)
find_package(eigen3_cmake_module REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(offboard_control_interfaces REQUIRED)


add_subdirectory(matplotplusplus)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(flight_control_lib SHARED
  src/flight_control/control_publishers.cpp
  src/flight_control/state_subscribers.cpp
  src/flight_control/flight_executor.cpp
  src/vehicle_storage/vehicle_state_storage.cpp
  src/vehicle_storage/executor_storage.cpp
  src/lib/frame_conversion.cpp
)
ament_target_dependencies(flight_control_lib
  rclcpp
  px4_msgs
  px4_ros_com  
  Eigen3
)
target_include_directories(flight_control_lib PUBLIC 
	$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	$<INSTALL_INTERFACE:include>
)

add_executable(offboard_controller src/main.cpp)
target_link_libraries(offboard_controller flight_control_lib)
install(TARGETS offboard_controller DESTINATION lib/${PROJECT_NAME})

add_executable(user_input src/user_input.cpp)
ament_target_dependencies(user_input rclcpp offboard_control_interfaces)
install(TARGETS user_input DESTINATION lib/${PROJECT_NAME})


#listeners for printing out readings
add_executable(sensor_combined_listener src/monitoring/sensors_listener.cpp)
ament_target_dependencies(sensor_combined_listener
  rclcpp
  px4_msgs
  px4_ros_com  
)
install(TARGETS sensor_combined_listener DESTINATION lib/${PROJECT_NAME})

add_executable(publish_trj_listener src/monitoring/publish_trj_listener.cpp)
ament_target_dependencies(publish_trj_listener
  rclcpp
  px4_msgs
  px4_ros_com  
)
install(TARGETS publish_trj_listener DESTINATION lib/${PROJECT_NAME})

add_executable(vehicle_pos_listener src/monitoring/local_pos_listener.cpp)
ament_target_dependencies(vehicle_pos_listener
  rclcpp
  px4_msgs
  px4_ros_com  
)
install(TARGETS vehicle_pos_listener DESTINATION lib/${PROJECT_NAME})

add_executable(cmd_ack_listener src/monitoring/cmd_ack_listener.cpp)
ament_target_dependencies(cmd_ack_listener
  rclcpp
  px4_msgs
  px4_ros_com  
)
install(TARGETS cmd_ack_listener DESTINATION lib/${PROJECT_NAME})


# test
# add_executable(test_function src/test.cpp)
# target_link_libraries(test_function PUBLIC matplot)
# install(TARGETS test_function DESTINATION lib/${PROJECT_NAME})



# Install header files
install(DIRECTORY include DESTINATION include/${PROJECT_NAME})

install(TARGETS flight_control_lib
	EXPORT export_flight_control_lib
	ARCHIVE DESTINATION lib
	LIBRARY DESTINATION lib
	RUNTIME DESTINATION bin
	INCLUDES DESTINATION include
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
