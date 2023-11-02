# /usr/bin/env python3

from rclpy.node import Node
from std_msgs.msg import String


class SimpleSubsriber(Node):
    def __init__(self):
        super().__init__("simple_subscriber_py")

        self.sub_ = self.create_subscription(String, "chatter", self.subCallback, 10)

    def subCallback(self, msg: String):
        self.get_logger().info("Received msg: %s" % msg.data)
