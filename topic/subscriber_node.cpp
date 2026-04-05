#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

std::shared_ptr<rclcpp::Node> node;

void Callback(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO(node->get_logger(), "Receive:%s", msg->data.c_str());
}

int main(int argc, char* argv)
{
    rclcpp::init(argc, argv);

    // 创建一个节点
    node = std::make_shared<rclcpp::Node>("subscriber_node");

    // 创建一个订阅者对象，参数：(订阅的话题，接收消息包的缓冲队列大小，回调函数）
    auto  subscriber = node->create_subscription<std_msgs::msg::String>("/my_topic", 10, &Callback);

    // 启动节点的主循环，开启消息接收处理，直至收到系统的关闭要求。
    rclcpp::spin(node);

    rclcpp::shutdown();

    return 0;
}