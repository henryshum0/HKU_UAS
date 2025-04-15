#include <flight_control/control_publishers.hpp>
#include <flight_control/state_subscribers.hpp>
#include <flight_control/flight_executor.hpp>
#include <flight_control/input_parser.hpp>

#include <vehicle_storage/vehicle_state_storage.hpp>
#include <vehicle_storage/executor_storage.hpp>

#include <memory>
#define TEST

int main(int argc, char* argv[])
{
    setvbuf(stdout, NULL, _IONBF, BUFSIZ);
    rclcpp::init(argc, argv);
    auto vehicle_state_storage = std::make_shared<VehicleStateStorage>();
    auto executor_storage = std::make_shared<ExecutorStorage>();

    auto state_subscribers = std::make_shared<StateSubscriber>(vehicle_state_storage);
    auto control_publishers = std::make_shared<ControlPublisher>(executor_storage);
    auto flight_executor = std::make_shared<FlightExecutor>(vehicle_state_storage, executor_storage);
    auto input_parser = std::make_shared<InputParser>(executor_storage);

    rclcpp::executors::SingleThreadedExecutor executor;
    executor.add_node(state_subscribers);
    executor.add_node(control_publishers);
    executor.add_node(flight_executor);
    executor.add_node(input_parser);
    executor.spin();

    rclcpp::shutdown();
    return 0;
}