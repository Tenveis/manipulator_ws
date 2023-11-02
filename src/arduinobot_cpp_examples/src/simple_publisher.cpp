/**
 * @file simple_publisher.cpp
 * @author vaibhav
 * @brief
 * @version 0.1
 * @date 2023-11-02
 *
 *
 */

#include "arduinobot_cpp_examples/simple_publisher.h"

SimplePublisher::SimplePublisher() : Node("simple_publisher_cpp"), counter_(0)
{
    pub_ = this->create_publisher<std_msgs::msg::String>("chatter", 10);

    pub_timer_ = this->create_wall_timer(std::chrono::milliseconds(314),
                                         std::bind(&SimplePublisher::pubTimerCallback, this));

    RCLCPP_INFO(this->get_logger(), "object of SimplePublisher class has beencreated.");
    RCLCPP_INFO(this->get_logger(), "published frequency: 3.14");
}

void SimplePublisher::pubTimerCallback()
{
    auto msg = std_msgs::msg::String();
    msg.data = "[HI -> " + std::to_string(counter_) + "]";
    pub_->publish(msg);
    counter_++;
}