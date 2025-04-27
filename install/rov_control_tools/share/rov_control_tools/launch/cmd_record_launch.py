from launch import LaunchDescription
from launch_ros.actions import Node
from launch.actions import DeclareLaunchArgument
from launch.substitutions import LaunchConfiguration, PythonExpression
from launch.conditions import IfCondition, UnlessCondition

def generate_launch_description():
    # 声明控制算法参数和命令类型参数
    control_algo_arg = DeclareLaunchArgument(
        'control_algo',
        default_value='pid',
        description='Control algorithm type (e.g., pid, smc)'
    )
    cmd_type_arg = DeclareLaunchArgument(
        'cmd_type',
        default_value='point',
        description='Command type (e.g., point, circle)'
    )
    target_depth_arg = DeclareLaunchArgument(
        'target_depth',
        default_value='-2.0',
        description='Target depth for constant depth control (e.g., -2.0, -5.0, -8.0)'
    )
    # DataLogger 节点始终启动
    data_logger_node = Node(
        package='rov_control_tools',
        executable='data_logger',
        name='data_logger',
        parameters=[{'control_algo': LaunchConfiguration('control_algo'),
                     'cmd_type': LaunchConfiguration('cmd_type'),
                     }],
    )

    # 如果 cmd_type 为 'circle' 启动 cmd_publisher_circle，否则启动 cmd_publisher_point
    cmd_publisher_circle_node = Node(
        package='rov_control_tools',
        executable='cmd_publisher_circle',
        name='cmd_pose_publisher_circle',
        condition=IfCondition(PythonExpression(
            ["'", LaunchConfiguration('cmd_type'), "' == 'circle'"]
        ))
    )
    cmd_publisher_point_node = Node(
        package='rov_control_tools',
        executable='cmd_publisher_point',
        name='cmd_pose_publisher_point',
        parameters=[{'target_depth': LaunchConfiguration('target_depth')}],
        condition=UnlessCondition(PythonExpression(
            ["'", LaunchConfiguration('cmd_type'), "' == 'circle'"]
        ))
    )

    return LaunchDescription([
        control_algo_arg,
        cmd_type_arg,
        target_depth_arg,
        data_logger_node,
        cmd_publisher_circle_node,
        cmd_publisher_point_node,
    ])