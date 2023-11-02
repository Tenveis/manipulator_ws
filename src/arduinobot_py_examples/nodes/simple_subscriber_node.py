#!/usr/bin/env python3

import rclpy
from arduinobot_py_examples.simple_subscriber import SimpleSubsriber


def main(args=None):
    rclpy.init(args=args)
    node = SimpleSubsriber()
    rclpy.spin(node=node)
    node.destroy_node()
    rclpy.shutdown()


if __name__ == '__main__':
    main()
