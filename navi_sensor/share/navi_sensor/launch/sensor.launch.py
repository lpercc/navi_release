# 导入库
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os
def generate_launch_description():

    
    root_dir = get_package_share_directory('navi_sensor')
    params_file = os.path.join(root_dir, 'config/params.yaml')
    urdf_path = os.path.join(root_dir,'go2_description','go2_description.urdf')
    # 安全读取 URDF 文件内容
    if not os.path.exists(urdf_path):
        raise FileNotFoundError(f"URDF file not found at: {urdf_path}")
    
    with open(urdf_path, 'r') as urdf_file:
        urdf_content = urdf_file.read()
    
    if not urdf_content.strip():
        raise RuntimeError(f"URDF file is empty or whitespace only: {urdf_path}")

    """launch内容描述函数，由ros2 launch 扫描调用"""
    client = Node(
        package="navi_sensor",
        executable="client",
        name='client',
        parameters=[params_file]
    )
    camera = Node(
        package="navi_sensor",
        executable="camera",
        name='camera',
        parameters=[params_file]
    )
    lidar = Node(
        package='navi_sensor',
        executable='lidar',
        name='lidar_node',
        parameters=[params_file]
    )
    gps = Node(
            package='navi_sensor',
            executable='gps',
            name='gps_node',
            output='screen',
            parameters=[params_file]
    )

    uwb = Node(
            package='navi_sensor',
            executable='uwb',
            name='uwb_node',
            output='screen',
            parameters=[params_file]
    )

    location = Node(
        package='robot_localization',
        executable='ekf_node',
        name='ekf_filter_node',
        output='screen',
        parameters=[params_file]
    )

    laserscan = Node(
            package='pointcloud_to_laserscan',
            executable='pointcloud_to_laserscan_node',
            name='pointcloud_to_laserscan',
            output='screen',
            parameters=[params_file],
            remappings=[
                ('cloud_in', '/navi_lidar'),
                ('scan', '/scan_raw')
            ]
        )

    scan_filtered  =  Node(
            package='laser_filters',
            executable='scan_to_scan_filter_chain',
            name='scan_filter',
            parameters=[params_file],
            remappings=[
                ('scan', '/scan_raw'),        # 原始输入
                ('scan_filtered', '/scan')    # 输出过滤后的数据，供 costmap 用
            ]
        )    

    robot_state = Node(
        package='robot_state_publisher',
        executable='robot_state_publisher',
        name='robot_state_publisher',
        output='log',
        parameters=[{'robot_description': urdf_content}]
    )

    joint_state = Node(
        package='joint_state_publisher',
        executable='joint_state_publisher',
        name='joint_state_publisher',
        output='log',
    )
    # # 创建LaunchDescription对象launch_description,用于描述launch文件
    launch_description = LaunchDescription(
        [camera, client, lidar, location, robot_state, joint_state, gps, uwb]
        # [laserscan]
        )
    # 返回让ROS2根据launch描述执行节点
    return launch_description
