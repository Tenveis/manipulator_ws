/**
 * @file simple_parameter.cpp
 * @author vaibhav
 * @brief
 * @version 0.1
 * @date 2023-11-04
 *
 *
 */

#include "arduinobot_cpp_examples/simple_parameter.h"

SimpleParameter::SimpleParameter() : Node("simple_parameter_cpp")
{
    this->declare_parameter<int>("int_param", 47);
    this->declare_parameter<std::string>("str_param", "asdf");

    param_callback_handle_ = this->add_on_set_parameters_callback(std::bind(
        &SimpleParameter::paramChangeCallback, this, std::placeholders::_1));
}

rcl_interfaces::msg::SetParametersResult SimpleParameter::paramChangeCallback(const std::vector<rclcpp::Parameter> &params)
{
    rcl_interfaces::msg::SetParametersResult result;

    for (const auto &param : params)
    {
        if ((param.get_name() == "int_param") && (param.get_type() == rclcpp::ParameterType::PARAMETER_INTEGER))
        {
            RCLCPP_INFO_STREAM(this->get_logger(), "Param 'int_param' has been changed. New Value is: " << param.as_int());
            result.successful = true;
        }

        if ((param.get_name() == "str_param") && (param.get_type() == rclcpp::ParameterType::PARAMETER_STRING))
        {
            RCLCPP_INFO_STREAM(this->get_logger(), "Param 'str_param' has been changed. New Value is: " << param.as_string());
            result.successful = true;
        }
    }

    return result;
}
