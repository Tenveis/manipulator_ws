/**
 * @file simple_subscriber.h
 * @author vaibhav
 * @brief Header file for the SimpleSubscriber class.
 * @version 0.1
 * @date 2023-11-02
 */

#ifndef INCLUDE_SIMPLE_SUBSCRIBER_H
#define INCLUDE_SIMPLE_SUBSCRIBER_H
#pragma once

///< ros lib
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

/**
 * @class SimpleSubscriber
 * @brief A class that defines a ROS subscriber node for receiving string messages.
 */
class SimpleSubscriber: public rclcpp::Node
{
public:
    /**
     * @brief Constructor for the SimpleSubscriber class.
     */
    SimpleSubscriber();

private:
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr sub_; ///< The subscription for string messages.

    /**
     * @brief Callback function for processing incoming string messages.
     * @param msg  Pointer to the received string message.
     */
    void subCallback(const std_msgs::msg::String::SharedPtr msg);
};

#endif
