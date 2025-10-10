# 导入库
from launch import LaunchDescription
from launch_ros.actions import Node
from ament_index_python.packages import get_package_share_directory
import os

def generate_launch_description():
    root_dir = get_package_share_directory('navi_data')
    params_file = os.path.join(root_dir, 'config/params.yaml')
    """launch内容描述函数，由ros2 launch 扫描调用"""
    communicator_wbs = Node(
        package="navi_data",
        executable="communicator_wbs",
        name='communicator_wbs',
        output='screen',
        parameters=[params_file]
    )
    logger = Node(
        package="navi_data",
        executable="logger",
        name='logger',
        output='screen',
        parameters=[params_file]
    )
    replay = Node(
        package="navi_data",
        executable="replay",
        name='replay',
        output='screen',
        parameters=[params_file]
    )
    launch_description = LaunchDescription(
        [communicator_wbs, logger])
    # 返回让ROS2根据launch描述执行节点
    return launch_description
