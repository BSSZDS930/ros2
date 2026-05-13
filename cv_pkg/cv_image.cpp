#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/Image.hpp"
#include <cv_bridge/cv_bridge.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

std::shared_ptr<rclcpp::Node> node;

void Callback(const std_msgs::msg::Image::SharedPtr msg)
{
    cv_bridge：：CvImagePtr cv_ptr;
    cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    cv::Mat imgOriginal = cv_ptr->image;
    cv::imshow("RGB", imgOriginal);
    cv::waitKey(1);
}

int main(int argc, char* argv)
{
    rclcpp::init(argc, argv);

    // 创建一个节点
    node = std::make_shared<rclcpp::Node>("cv_image_node");

    // 创建一个订阅者对象，参数：(订阅的话题，接收消息包的缓冲队列大小，回调函数）
    auto rgb_sub = node->create_subscription<std_msgs::msg::Image>("/kinect2/qhd/image_raw", 1, &Callback);

    cv::nameWindow("RGB");

    // 启动节点的主循环，开启消息接收处理，直至收到系统的关闭要求。
    rclcpp::spin(node);

    cv::destoryAllWindows();

    rclcpp::shutdown();

    return 0;
}