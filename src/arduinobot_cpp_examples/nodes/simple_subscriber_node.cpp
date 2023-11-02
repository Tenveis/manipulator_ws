/**
 * @file simple_subscriber_node.cpp
 * @author vaibhav
 * @brief
 * @version 0.1
 * @date 2023-11-02
 *
 *
 */

#include "arduinobot_cpp_examples/simple_subscriber.h"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SimpleSubscriber>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}