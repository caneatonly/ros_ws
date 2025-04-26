import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseStamped
import csv
import os

class DataLogger(Node):
    def __init__(self):
        super().__init__('data_logger')
        qos = 10
        # 订阅 odom 和 cmd_pose 节点
        self.odom_sub = self.create_subscription(
            Odometry, '/bluerov2/odom', self.odom_callback, qos)
        self.cmd_sub = self.create_subscription(
            PoseStamped, '/bluerov2/cmd_pose', self.cmd_callback, qos)
        self.recording = False
        self.start_time = None


        # 申明参数，用于区分不同算法记录数据的 CSV 文件路径
        self.declare_parameter('control_algo', 'pid')
        control_algo = self.get_parameter('control_algo').value
        # 配置日志文件名称根据控制算法
        self.log_file = os.path.join(os.getcwd(), f'rov_trajectory_{control_algo}.csv')
        # 写入 CSV 表头
        with open(self.log_file, mode='w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow(['source', 'time_since_cmd', 'x', 'y', 'z'])
        self.get_logger().info(f'Data Logger started, log file: {self.log_file}')

    
    def cmd_callback(self, msg: PoseStamped):
        # 仅在第一次触发时开始记录，后续触发忽略
        if not self.recording:
            self.get_logger().info(f"Received cmd_pose trigger, stamp: {msg.header.stamp}")
            self.recording = True
            # 采用系统当前时间作为记录起始点，确保统一时钟
            self.start_time = self.get_clock().now()
        else:
            self.get_logger().debug("cmd_pose received but already recording; ignored.")
        # 记录 cmd_pose 的位姿数据
        with open(self.log_file, mode='a', newline='') as f:
            writer = csv.writer(f)
            # 对于cmd_pose，用0作为相对时间，或根据需要计算相对时间
            time_offset = (self.get_clock().now() - self.start_time).nanoseconds / 1e9
            writer.writerow(["cmd_pose",time_offset, msg.pose.position.x, msg.pose.position.y, msg.pose.position.z])
        self.get_logger().info(f"Recorded cmd_pose trigger, stamp: {msg.header.stamp}")

    def odom_callback(self, msg: Odometry):
        if self.recording:
            # 用记录起始时刻计算时间偏移（单位：秒）
            time_offset = (self.get_clock().now() - self.start_time).nanoseconds / 1e9
            pos = msg.pose.pose.position
            with open(self.log_file, mode='a', newline='') as f:
                writer = csv.writer(f)
                writer.writerow(["odom", time_offset, pos.x, pos.y, pos.z])
            self.get_logger().debug(f"Logged odom data at t={time_offset:.3f}")

def main(args=None):
    rclpy.init(args=args)
    node = DataLogger()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()