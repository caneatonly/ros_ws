from simple_launch import SimpleLauncher, GazeboBridge

sl = SimpleLauncher(use_sim_time = True)

sl.declare_arg('namespace', default_value='bluerov2')
sl.declare_arg('ground_truth',default_value=True)
sl.declare_arg('sliders',default_value=False)
sl.declare_arg('camera', True)
sl.declare_arg('gazebo_world_name', 'none')

# initial pose
sl.declare_gazebo_axes(x=0.0, y=0.0, z=-10.0, roll=0.,pitch=0., yaw=0.)


def launch_setup():
    
    ns = sl.arg('namespace')

    if sl.arg('gazebo_world_name') != 'none':
        gn = sl.arg('gazebo_world_name')
        # 如果传入的 world 名称不以 [ 和 ] 包裹，则添加上，保证格式如 "[myworld]"
        if not (gn.startswith('[') and gn.endswith(']')):
            gn = f'[{gn}]'
        # 直接设置内部变量，使 GazeboBridge.world() 返回正确的名称
        GazeboBridge._world_name = gn[1:-1]
    else :
        GazeboBridge._world_name = 'bluerov2_world'
    
    # robot state publisher
    sl.include('bluerov2_description', 'state_publisher_launch.py',
               launch_arguments={'namespace': ns, 'use_sim_time': sl.sim_time})
               
    with sl.group(ns=ns):
                    
        # URDF spawner to Gazebo, defaults to relative robot_description topic
        sl.spawn_gz_model(ns, spawn_args = sl.gazebo_axes_args())
            
        # ROS-Gz bridges
        bridges = []
        gz_js_topic = GazeboBridge.model_prefix(ns) + '/joint_state'
        bridges.append(GazeboBridge(gz_js_topic, 'joint_states', 'sensor_msgs/JointState', GazeboBridge.gz2ros))
        
        # pose ground truth
        bridges.append(GazeboBridge(f'/model/{ns}/pose',
                                     'pose_gt', 'geometry_msgs/Pose', GazeboBridge.gz2ros))
        
        # ground truth if requested
        if sl.arg('ground_truth'):
            bridges.append(GazeboBridge(f'/model/{ns}/odometry',
                                     'odom', 'nav_msgs/Odometry', GazeboBridge.gz2ros,
                                     'gz.msgs.Odometry'))
            sl.node('pose_to_tf',parameters={'child_frame': ns + '/base_link'})
        else:
            # otherwise publish ground truth as another link to get, well, ground truth
            sl.node('pose_to_tf',parameters={'child_frame': ns+'/base_link_gt'})

        # imu
        for imu in ('mpu', 'lsm'):
            bridges.append(GazeboBridge(f'{ns}/{imu}',
                          imu, 'sensor_msgs/Imu', GazeboBridge.gz2ros))

        # sonar (as laser scan for now...)
        bridges.append(GazeboBridge(f'{ns}/sonar', 'sonar', 'sensor_msgs/LaserScan', GazeboBridge.gz2ros))
        bridges.append(GazeboBridge(f'{ns}/sonar/points', 'cloud', 'sensor_msgs/PointCloud2', GazeboBridge.gz2ros))

        # camera
        if sl.arg('camera'):
            bridges.append(GazeboBridge(f'{ns}/image', 'image', 'sensor_msgs/Image', GazeboBridge.gz2ros))
        
        # tilt control
        bridges.append(GazeboBridge(f'/model/{ns}/joint/tilt/0/cmd_pos',
                                     'cmd_tilt', 'std_msgs/Float64', GazeboBridge.ros2gz))
        
        # thrusters
        for thr in range(1, 7):
            thruster = f'thruster{thr}'
            gz_thr_topic = f'/{ns}/{thruster}/cmd'
            bridges.append(GazeboBridge(gz_thr_topic, f'cmd_{thruster}', 'std_msgs/Float64', GazeboBridge.ros2gz))

        sl.create_gz_bridge(bridges)

        if sl.arg('sliders'):
            sl.node('slider_publisher', arguments=[sl.find('bluerov2_description', 'manual.yaml')])
    
    return sl.launch_description()


generate_launch_description = sl.launch_description(launch_setup)
