#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

int main(int argc,char *argv[])
{
    rclcpp::init(argc, argv);
	
	auto node = std:make_shared<rclcpp::Node>("publisher_node");
	
	auto publisher = node->create_publisher<std_msgs::msg::String>("/my_topic", 10);
	
	std_msgs::msg::String message;
	message.data = "hello world";
	
	rclcpp::Rate loop_rate(1);
	
	while(rclcpp::ok()) {
		publisher->publish(message);
		loop_rate.sleep();
	}

	rclcpp::shutdown();

    return 0;
}

/*
find_package(rclcpp REQUIRED)
find_package(str_msgs REQUIRED)

add_executable(publisher_node src/publisher_node.cpp)
ament_targetdependencies(publisher_node "rclcpp" "std_msgs")
install(TARGETS publisher_node DESTINATION lib/${PROJECT_NAME})

<depend>rclcpp</depend>
<depend>std_msgs</depend>
*/