#!/usr/bin/env python3

import rclpy
from arduinobot_py_examples.simple_parameter import SimpleParameter


def main(args=None):
    rclpy.init(args=args)
    node = SimpleParameter()
    rclpy.spin(node=node)
    rclpy.shutdown()


if __name__ == '__main__':
    main()
