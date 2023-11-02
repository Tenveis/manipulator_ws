#!/usr/bin/env python3



import rclpy 
from rclpy.node import Node 
from std_msgs.msg import String

class SimplePublisher(Node):
    def __init__(self):
        super().__init__("simple_publisher_py")
        self.pub_ = self.create_publisher(String, "chatter", 10)
        self.counter_=0
        self.frequency_=3.14
        self.pub_timer_ = self.create_timer(self.frequency_,self.pubTimerCallback)
        self.get_logger().info("Object of SimplePublisher class has been created.")
        self.get_logger().info("Publishing at %f Hz"%self.frequency_)

    
    def pubTimerCallback(self):
        msg = String()
        msg.data = "[Hi there -> %d]"%self.counter_
        self.pub_.publish(msg)
        self.counter_+=1


