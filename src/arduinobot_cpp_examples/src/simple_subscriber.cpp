/**
 * @file simple_subscriber.cpp
 * @author vaibhav
 * @brief
 * @version 0.1
 * @date 2023-11-02
 *
 *
 */

#include "arduinobot_cpp_examples/simple_subscriber.h"

SimpleSubscriber::SimpleSubscriber() : Node("simple_subscriber_cpp")
{
    sub_ = this->create_subscription<std_msgs::msg::String>("chatter", 10,
                                                            std::bind(&SimpleSubscriber::subCallback, this, std::placeholders::_1));
}

void SimpleSubscriber::subCallback(const std_msgs::msg::String::SharedPtr msg)
{
    RCLCPP_INFO_STREAM(this->get_logger(), "Received: " << msg->data.c_str());
}
