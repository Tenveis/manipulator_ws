/**
 * @file simple_publisher_node.cpp
 * @author vaibhav
 * @brief
 * @version 0.1
 * @date 2023-11-02
 *
 */

#include "arduinobot_cpp_examples/simple_publisher.h"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SimplePublisher>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}