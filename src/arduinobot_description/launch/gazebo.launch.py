#!/usr/bin/env python3


from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import (
    DeclareLaunchArgument,
    SetEnvironmentVariable,
    IncludeLaunchDescription,
)
from ament_index_python.packages import get_package_share_directory, get_package_prefix
from launch_ros.parameter_descriptions import ParameterValue
from launch.substitutions import Command, LaunchConfiguration
from launch.launch_description_sources import PythonLaunchDescriptionSource

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
    env_var = SetEnvironmentVariable(
        "GAZEBO_MODEL_PATH",
        os.path.join(get_package_prefix("arduinobot_description"), "share"),
    )

    robot_description = ParameterValue(
        Command(["xacro ", LaunchConfiguration("model")]), value_type=str
    )

    robot_state_publisher = Node(
        package="robot_state_publisher",
        executable="robot_state_publisher",
        parameters=[{"robot_description": robot_description}],
    )

    gazebo_server = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("gazebo_ros"),
                "launch",
                "gzserver.launch.py",
            )
        )
    )

    gazebo_client = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(
                get_package_share_directory("gazebo_ros"),
                "launch",
                "gzclient.launch.py",
            )
        )
    )

    spawn_entity = Node(
        package="gazebo_ros",
        executable="spawn_entity.py",
        arguments=["-entity", "mybot", "-topic", "robot_description"],
    )

    ld.add_action(env_var)
    ld.add_action(model_arg)
    ld.add_action(robot_state_publisher)
    ld.add_action(gazebo_server)
    ld.add_action(gazebo_client)
    ld.add_action(spawn_entity)

    return ld


# LaunchDescription(
#     [
#         env_var,
#         model_arg,
#         robot_state_publisher,
#         gazebo_server,
#         gazebo_client,
#         spawn_entity,
#     ]
# )
