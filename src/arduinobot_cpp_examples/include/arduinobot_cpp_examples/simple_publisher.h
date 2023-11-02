/**
 * @file simple_publisher.h
 * @author vaibhav
 * @brief Header file for the SimplePublisher class.
 * @version 0.1
 * @date 2023-11-02
 */

#ifndef INCLUDE_SIMPLE_PUBLISHER_H
#define INCLUDE_SIMPLE_PUBLISHER_H
#pragma once

// ros-lib
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

// std-lib
#include <stdint.h>

/**
 * @class SimplePublisher
 * @brief A class that defines a ROS publisher node for publishing string messages.
 */
class SimplePublisher : public rclcpp::Node
{

public:
    /**
     * @brief Constructor for the SimplePublisher class.
     */
    SimplePublisher();

private:
    uint32_t counter_; ///< A counter for tracking the number of published messages.

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr pub_; ///< Pointer to the publisher for string messages.
    rclcpp::TimerBase::SharedPtr pub_timer_;                  ///< Pointer to a timer for  publishing at frequency.

    /**
     * @brief Callback function for the publication timer.
     */
    void pubTimerCallback();
};

#endif
