import rclpy
from rclpy.node import Node
from nav_msgs.msg import Odometry
from geometry_msgs.msg import PoseStamped
from sensor_msgs.msg import Imu   # 新增Imu消息类型，用于订阅加速度
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
        self.mpu_sub = self.create_subscription(
            Imu, '/bluerov2/mpu', self.mpu_callback, qos)
        self.recording = False
        self.start_time = None
        # 申明参数，用于区分不同算法记录数据的 CSV 文件路径
        self.declare_parameter('control_algo', 'pid')
        control_algo = self.get_parameter('control_algo').value
        self.declare_parameter('cmd_type', 'point')
        cmd_type = self.get_parameter('cmd_type').value

        self.log_file = os.path.join(os.getcwd(), 
            f'rov_trajectory_{control_algo}_{cmd_type}_-8.0.csv')

        # 写入 CSV 表头
        with open(self.log_file, mode='w', newline='') as f:
            writer = csv.writer(f)
            writer.writerow([
                'source', 'time_since_cmd',
                'x', 'y', 'z',
                'qx', 'qy', 'qz', 'qw',
                'vx', 'vy', 'vz',
                'ax', 'ay', 'az'
            ])
        self.get_logger().info(f'Data Logger started, log file: {self.log_file}')

    # 订阅 cmd_pose 触发器,写入cmd_pose数据
    def cmd_callback(self, msg: PoseStamped):
        if not self.recording:
            self.get_logger().info(f"Received cmd_pose trigger, stamp: {msg.header.stamp}")
            self.recording = True
            self.start_time = self.get_clock().now()
        else:
            self.get_logger().debug("cmd_pose received but already recording; ignored.")
        with open(self.log_file, mode='a', newline='') as f:
            writer = csv.writer(f)
            time_offset = (self.get_clock().now() - self.start_time).nanoseconds / 1e9
            writer.writerow([
                "cmd_pose", time_offset,
                msg.pose.position.x, msg.pose.position.y, msg.pose.position.z,
                msg.pose.orientation.x, msg.pose.orientation.y, msg.pose.orientation.z, msg.pose.orientation.w,
                0.0, 0.0, 0.0,   # vx, vy, vz (无速度数据)
                0.0, 0.0, 0.0    # ax, ay, az (无加速度数据)
            ])
        self.get_logger().info(f"Recorded cmd_pose trigger, stamp: {msg.header.stamp}")
     
     # 订阅 odom 触发器,写入odom数据
    def odom_callback(self, msg: Odometry):
        if self.recording:
            time_offset = (self.get_clock().now() - self.start_time).nanoseconds / 1e9
            pos = msg.pose.pose.position
            ori = msg.pose.pose.orientation
            twist = msg.twist.twist
            with open(self.log_file, mode='a', newline='') as f:
                writer = csv.writer(f)
                writer.writerow([
                    "odom", time_offset,
                    pos.x, pos.y, pos.z,
                    ori.x, ori.y, ori.z, ori.w,
                    twist.linear.x, twist.linear.y, twist.linear.z,
                    0.0, 0.0, 0.0   # ax, ay, az (odom消息不含加速度)
                ])
            self.get_logger().debug(f"Logged odom data at t={time_offset:.3f}")
    # 订阅 mpu 触发器, 写入加速度数据（其余列填 "N/A" 表示无数据）
    def mpu_callback(self, msg: Imu):
        if self.recording:
            time_offset = (self.get_clock().now() - self.start_time).nanoseconds / 1e9
            acc = msg.linear_acceleration
            with open(self.log_file, mode='a', newline='') as f:
                writer = csv.writer(f)
                writer.writerow([
                    "mpu", time_offset,
                    "N/A", "N/A", "N/A",      # x, y, z
                    "N/A", "N/A", "N/A", "N/A",# qx, qy, qz, qw
                    "N/A", "N/A", "N/A",       # vx, vy, vz
                    acc.x, acc.y, acc.z        # 加速度 ax, ay, az
                ])
            self.get_logger().debug(f"Logged mpu acceleration at t={time_offset:.3f}")

def main(args=None):
    rclpy.init(args=args)
    node = DataLogger()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()