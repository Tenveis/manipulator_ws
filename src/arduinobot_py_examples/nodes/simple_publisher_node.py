#!/usr/bin/env python3


# simple_publisher_node.py

import rclpy
from arduinobot_py_examples.simple_publisher import SimplePublisher


def main():
    rclpy.init()
    simple_publisher = SimplePublisher()
    rclpy.spin(simple_publisher)
    simple_publisher.destroy_node()
    rclpy.shutdown()


if __name__ == "__main__":
    main()
