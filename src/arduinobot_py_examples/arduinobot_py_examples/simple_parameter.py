#!/usr/bin/env python3


from rclpy.node import Node
from rcl_interfaces.msg import SetParametersResult
from rclpy.parameter import Parameter


class SimpleParameter(Node):
    def __init__(self):
        super().__init__("simple_parameter_py")

        self.declare_parameter("int_param", 13)
        self.declare_parameter("str_param", "L2d2")

        self.add_on_set_parameters_callback(self.paramChangeCallback)

    def paramChangeCallback(self, params: Parameter):
        result = SetParametersResult()

        for param in params:
            if (param.name == "int_param") and (param.type_ == Parameter.Type.INTEGER):
                self.get_logger().info(
                    "Param: 'int_param' has been changed. New value is: %d"
                    % param.value
                )
                result.successful = True

            if (param.name == "str_param") and (param.type_ == Parameter.Type.STRING):
                self.get_logger().info(
                    "Param: 'str_param' has been changed. New value is: %s"
                    % param.value
                )
                result.successful = True

        return result
