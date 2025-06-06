from setuptools import find_packages, setup

package_name = 'rov_control_tools'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
        #加入launch文件
        ('share/' + package_name + '/launch', ['launch/cmd_record_launch.py']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='ros2',
    maintainer_email='ros2@todo.todo',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'cmd_publisher_point = rov_control_tools.cmd_publisher_point:main',
            'data_logger = rov_control_tools.data_logger:main',
            "cmd_publisher_circle = rov_control_tools.cmd_publisher_circle:main",
            "cmd_publisher_start = rov_control_tools.cmd_publisher_start:main",
        ],
    },
)
