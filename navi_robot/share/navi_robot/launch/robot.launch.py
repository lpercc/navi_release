# 导入库
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import IncludeLaunchDescription

def generate_launch_description():
    root_dir = get_package_share_directory('navi_robot')
    params_file = os.path.join(root_dir, 'config/params.yaml')

    sensor_dir = get_package_share_directory('navi_sensor')
    controller_dir = get_package_share_directory('navi_controller')
    data_dir = get_package_share_directory('navi_data')

    """launch内容描述函数，由ros2 launch 扫描调用"""
    sensor_launch  = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(sensor_dir, 'launch', 'sensor.launch.py')
        )
    )

    data_launch  = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(data_dir, 'launch', 'data.launch.py')
        )
    )

    controller_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(controller_dir, 'launch', 'controller.launch.py')
        )
    )


    nav2_local_planner_launch = IncludeLaunchDescription(
        PythonLaunchDescriptionSource(
            os.path.join(controller_dir, 'launch', 'nav2_local_planner.launch.py')
        )
    )

    agent = Node(
        package="navi_robot",
        executable="agent",
        name='agent',
        parameters=[params_file]
    )
    # # 创建LaunchDescription对象launch_description,用于描述launch文件
    # launch_description = LaunchDescription(
    #     [camera, processer, communicator_wbs, client, agent, logger, motion_controller_nav])
    # controller_launch
    launch_description = LaunchDescription(
        [sensor_launch, data_launch, nav2_local_planner_launch, controller_launch, agent])
    # 返回让ROS2根据launch描述执行节点
    return launch_description
