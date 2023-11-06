#!/usr/bin/env python3


from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from ament_index_python.packages import get_package_share_directory
from launch_ros.parameter_descriptions import ParameterValue
from launch.substitutions import Command, LaunchConfiguration

import xacro
import os


def generate_launch_description():
    ld = LaunchDescription()

    model_arg = DeclareLaunchArgument(
        name="model",
        default_value=os.path.join(
            get_package_share_directory("arduinobot_description"),
            "urdf",
            "robot.urdf.xacro",
        ),
        description="Absolute path to the Robot urdf-xacro file.",
    )

    robot_description = ParameterValue(
        Command(["xacro ", LaunchConfiguration("model")]), value_type=str
    )

    robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[{"robot_description": robot_description}],
    )
    joint_state_publisher_gui = Node(
        package="joint_state_publisher_gui",
        executable="joint_state_publisher_gui",
    )
    rviz2_node = Node(
        package="rviz2",
        executable="rviz2",
        output="screen",
        arguments=[
            "-d",
            os.path.join(
                get_package_share_directory("arduinobot_description"),
                "config",
                "display.rviz",
            ),
        ],
    )

    ld.add_entity(model_arg)
    ld.add_action(robot_state_publisher)
    ld.add_action(joint_state_publisher_gui)
    ld.add_action(rviz2_node)

    return ld
