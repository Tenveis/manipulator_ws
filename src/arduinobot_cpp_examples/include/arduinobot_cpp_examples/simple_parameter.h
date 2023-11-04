/**
 * @file simple_parameter.h
 * @author vaibhav
 * @brief 
 * @version 0.1
 * @date 2023-11-04
 */

#ifndef INCLUDE_SIMPLE_PARAMETER_H
#define INCLUDE_SIMPLE_PARAMETER_H
#pragma once

///< ros lib
#include <rclcpp/rclcpp.hpp>
#include <rcl_interfaces/msg/set_parameters_result.hpp>

///< std lib
#include <string>
#include <vector>

/**
 * @class SimpleParameter
 * @brief A ROS 2 node for managing parameters.
 */
class SimpleParameter : public rclcpp::Node
{
public:
    /**
     * @brief Constructor for the SimpleParameter class.
     */
    SimpleParameter();

private:
    OnSetParametersCallbackHandle::SharedPtr param_callback_handle_;

    /**
     * @brief Callback function to handle parameter changes.
     * @param params A vector of parameters.
     * @return A rcl_interfaces::msg::SetParametersResult indicating the success or failure of parameter changes.
     */
    rcl_interfaces::msg::SetParametersResult paramChangeCallback(const std::vector<rclcpp::Parameter> &params);
};

#endif
