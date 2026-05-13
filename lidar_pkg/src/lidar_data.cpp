#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/laser_scan.hpp>

/*
    激光雷达中ROS2中的应用
*/

void LidarCallback(const sensor_msgs::msg::LaserScan::SharedPtr msg)
{
    int nNum = msg->ranges.size();
    int nMid = nNum / 2;
    float fMidDist = msg->ranges[nMid];

    // RCLCPP_INFO宏：终端显示
    RCLCPP_INFO(node->get_logger(), "ranges[%d]=%f", nMid, fMidDist);
}

int main(int argc, char* argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("lidar_data_node");

    auto lidar_sub = node->create_subscriber<sensor_msgs::msg::LaserScan>("/scan", 10, LidarCallback);

    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}