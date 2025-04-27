import rclpy
from rclpy.node import Node
from geometry_msgs.msg import PoseStamped
import math

class CircularTrajectoryPublisher(Node):
    def __init__(self):
        super().__init__('circular_trajectory_publisher')
        self.publisher_ = self.create_publisher(PoseStamped, '/bluerov2/cmd_pose', 10)
        # 定时器周期（单位：秒），可调整发布频率
        self.timer_period = 0.1 
        self.timer = self.create_timer(self.timer_period, self.timer_callback)
        self.start_time = self.get_clock().now()
        # 圆轨迹的参数
        self.radius = 5.0         # 圆半径
        self.center_x = 0.0       # 圆心 x 坐标
        self.center_y = 0.0       # 圆心 y 坐标
        self.center_z = -5.0      # 圆心 z 坐标（高度，保持常数）
        self.angular_rate = 0.1   # 角速度（rad/s）

    def timer_callback(self):
        # 计算经过时间（秒），并由此计算当前角度
        t = (self.get_clock().now() - self.start_time).nanoseconds / 1e9
        theta = self.angular_rate * t
        # 计算当前圆上目标点
        x = self.center_x + self.radius * math.cos(theta)
        y = self.center_y + self.radius * math.sin(theta)
        z = self.center_z
        # 构造 PoseStamped 消息
        msg = PoseStamped()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'world'
        msg.pose.position.x = x
        msg.pose.position.y = y
        msg.pose.position.z = z
        # 此处简单设置为单位四元数（无旋转），你也可以按照需要计算使姿态与圆轨迹切线对齐
        msg.pose.orientation.w = 1.0
        msg.pose.orientation.x = 0.0
        msg.pose.orientation.y = 0.0
        msg.pose.orientation.z = 0.0

        # 发布目标位姿
        self.publisher_.publish(msg)
        self.get_logger().info("Published Circular cmd_pose: (%.2f, %.2f, %.2f)" % (x, y, z))

def main(args=None):
    rclpy.init(args=args)
    node = CircularTrajectoryPublisher()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()