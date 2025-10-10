# 导入库
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.actions import IncludeLaunchDescription

def generate_launch_description():
    root_dir = get_package_share_directory('navi_controller')
    params_file = os.path.join(root_dir, 'config/params.yaml')
    """launch内容描述函数，由ros2 launch 扫描调用"""

    motion_controller = Node(
        package="navi_controller",
        executable="motion_controller",
        name='motion_controller',
        parameters=[params_file]
    )
    motion_controller_nav = Node(
        package="navi_controller",
        executable="motion_controller_nav",
        name='motion_controller_nav',
        parameters=[params_file]
    )

    dynamic_param = Node(
        package="navi_controller",
        executable="dynamic_param",
        name='dynamic_param',
        parameters=[params_file]
    )

    # # 创建LaunchDescription对象launch_description,用于描述launch文件
    # launch_description = LaunchDescription(
    #     [camera, processer, communicator_wbs, client, agent, logger, motion_controller_nav])

    launch_description = LaunchDescription(
        [motion_controller_nav])
    # 返回让ROS2根据launch描述执行节点
    return launch_description
