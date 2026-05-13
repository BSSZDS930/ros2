
# x寻找依赖项
find_package(rclcpp REQUIRED)
find_package(str_msgs REQUIRED)

# 编译规则
add_executable(publisher_node src/publisher_node.cpp)
ament_target_dependencies(publisher_node "rclcpp" "std_msgs")

#安装规则
install(TARGETS publisher_node DESTINATION lib/${PROJECT_NAME})
install(DIRECTORY launch DESTINATION share/${PROJECT_NAME})



<depend>rclcpp</depend>
<depend>std_msgs</depend>
