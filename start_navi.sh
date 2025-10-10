#!/bin/bash
# 启动 Navi Robot
source ~/unitree_ros2/setup.sh
source ~/navi_release/setup.sh
# 等待 1 秒，确保环境加载完成
sleep 1

# 启动并记录日志
ros2 launch navi_robot robot.launch.py >> ~/navi_release/navi_robot.log 2>&1
