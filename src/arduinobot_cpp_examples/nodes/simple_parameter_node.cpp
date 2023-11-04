/**
 * @file simple_parameter_node.cpp
 * @author vaibhav
 * @brief
 * @version 0.1
 * @date 2023-11-04
 *
 *
 */

#include "arduinobot_cpp_examples/simple_parameter.h"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<SimpleParameter>();

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}