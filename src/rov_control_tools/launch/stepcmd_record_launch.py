from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        # 启动 DataLogger 节点
        Node(
            package='rov_control_tools',
            executable='data_logger',
            name='data_logger'
        ),
        # 启动 CmdPosePublisher 节点
        Node(
            package='rov_control_tools',
            executable='cmd_publisher',
            name='cmd_pose_publisher'
        )
    ])