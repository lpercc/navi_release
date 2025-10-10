#!/bin/bash
echo "Setup unitree ros2 environment"
source /opt/ros/foxy/setup.bash
source $HOME/unitree_ros2/cyclonedds_ws/install/setup.bash
export RMW_IMPLEMENTATION=rmw_cyclonedds_cpp
# 查找 IP 为 192.168.123.* 的网卡名
IFACE=$(ip -o -4 addr show | awk '/192\.168\.123\./ {print $2; exit}')

if [ -z "$IFACE" ]; then
    echo "未找到 IP 为 192.168.123.* 的网络接口"
    exit 1
fi

# 设置 CycloneDDS 的网络接口配置
export CYCLONEDDS_URI="<CycloneDDS><Domain><General><Interfaces><NetworkInterface name=\"$IFACE\" priority=\"default\" multicast=\"default\" /></Interfaces></General></Domain></CycloneDDS>"
