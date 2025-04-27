import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
from rclpy.qos import QoSProfile
from functools import partial

class CmdPosePublisher(Node):
    def __init__(self):
        super().__init__('cmd_pose_publisher')
        qos = QoSProfile(depth=10)
        self.publisher_ = self.create_publisher(PoseStamped, '/bluerov2/cmd_pose', qos)
        # 定时器会在5秒后首次触发
        self.timer = self.create_timer(0.1, self.publish_pose)

    def publish_pose(self):
        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()  # 使用仿真时间，如果 use_sim_time true
        msg.header.frame_id = "world"  # 设置坐标系为世界坐标系
        # 设置目标位姿，可按实际需求进行配置
        msg.pose.position.x = 0.0
        msg.pose.position.y = 0.0
        msg.pose.position.z = -10.0
        msg.pose.orientation.w = 1.0
        msg.pose.orientation.x = 0.0
        msg.pose.orientation.y = 0.0
        msg.pose.orientation.z = 0.0
        self.publisher_.publish(msg)
        self.get_logger().info("Published cmd_pose.")
        self.get_logger().info("Published position: x=%f, y=%f, z=%f" % (msg.pose.position.x, msg.pose.position.y, msg.pose.position.z))

def main(args=None):
    rclpy.init(args=args)
    node = CmdPosePublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()