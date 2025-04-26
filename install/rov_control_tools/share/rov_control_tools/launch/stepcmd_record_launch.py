from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration


def generate_launch_description():
     # 声明控制算法参数，默认值为 'pid'
    control_algo_arg = DeclareLaunchArgument(
        'control_algo',
        default_value='pid',
        description='Control algorithm type (e.g., pid, smc)'
    )

    return LaunchDescription([
            control_algo_arg,
            # 启动 DataLogger 节点，并传入控制算法参数
            Node(
                package='rov_control_tools',
                executable='data_logger',
                name='data_logger',
                parameters=[{'control_algo': LaunchConfiguration('control_algo')}]
            ),
            # 启动 CmdPosePublisher 节点（假设该节点无需区分控制算法）
            Node(
                package='rov_control_tools',
                executable='cmd_publisher',
                name='cmd_pose_publisher'
            )
        ])