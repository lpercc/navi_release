#!/bin/bash

# 1. ROS2
wget http://fishros.com/install -O fishros
chmod +x fishros
printf "1\n1\n2\n1\n2\n1\n1\n" | ./fishros

# 2. 安装相关依赖
sudo apt install -y ros-foxy-tf-transformations ros-foxy-sensor-msgs-py portaudio19-dev ffmpeg tmux ros-foxy-navigation2 ros-foxy-nav2-bringup ros-foxy-joint-state-publisher ros-foxy-robot-localization ros-foxy-rmw-cyclonedds-cpp ros-foxy-rosidl-generator-dds-idl

# 3. Pip安装环境依赖
pip install Flask pyrealsense2 transforms3d websocket-client websockets PyAudio SpeechRecognition pydub scipy==1.10.1 -i https://pypi.tuna.tsinghua.edu.cn/simple

# 4. 安装unitree ROS2 服务接口

# 查找 ~/.bashrc 文件中是否存在 ROS2 环境变量设置
ROS2_SETUP_LINE='source /opt/ros/foxy/setup.bash'

# 如果 ~/.bashrc 中有该行，则注释掉
if grep -q "$ROS2_SETUP_LINE" ~/.bashrc; then
    echo "注释掉 ROS2 环境变量设置..."
    sed -i "s|$ROS2_SETUP_LINE|#$ROS2_SETUP_LINE|g" ~/.bashrc
fi

# 设置bash环境
ln -s ~/navi_release/unitree_ros2 ~/unitree_ros2
echo "source ~/unitree_ros2/setup.sh" >> ~/.bashrc

# 5. 连接测试
ros2 topic list

# 6. 程序环境设置
mkdir -p ~/navi_ws/install
ln -s ~/navi_release/* ~/navi_ws/install
echo "source ~/navi_release/setup.sh" >> ~/.bashrc

7. 设置路由和网络

# 自动查找带有192.168.123.*的连接名
CON_NAME=$(nmcli device show | grep -B3 '192.168.123.' | grep -i 'GENERAL.CONNECTION' | cut -d: -f2 | xargs)

# 如果没找到，退出
if [ -z "$CON_NAME" ]; then
    echo "未找到包含 192.168.123.* 的活动连接"
    exit 1
fi

echo "找到连接名: $CON_NAME"

# 设置 静态 IP 地址和子网掩码网关
sudo nmcli connection modify "$CON_NAME" ipv4.addresses 192.168.123.100/24
sudo nmcli connection modify "$CON_NAME" ipv4.gateway 192.168.123.1
sudo nmcli connection modify "$CON_NAME" ipv4.method manual
sudo nmcli connection down "$CON_NAME" && sudo nmcli connection up "$CON_NAME"

# 修改路由不影响联网
sudo nmcli connection modify "$CON_NAME" ipv4.never-default yes
sudo nmcli connection modify "$CON_NAME" +ipv4.routes "192.168.123.0/24 192.168.123.1"
sudo nmcli connection down "$CON_NAME" && sudo nmcli connection up "$CON_NAME"

# 8. 自启动

# 获取当前用户名
USER_NAME=$(whoami)
echo $USER_NAME

# 生成 systemd 服务文件
echo "[Unit]
Description=Start Navi Robot with ROS2
After=network.target

[Service]
User=$USER_NAME
WorkingDirectory=/home/$USER_NAME
ExecStart=/bin/bash /home/$USER_NAME/navi_release/start_navi.sh
Restart=always

[Install]
WantedBy=multi-user.target" > "navi_robot.service"

sudo cp ~/navi_release/navi_robot.service /etc/systemd/system

sudo systemctl daemon-reexec
sudo systemctl disable start_rtsp_surrounds.service
sudo systemctl stop start_rtsp_surrounds.service

sudo systemctl enable navi_robot.service
sudo systemctl start navi_robot.service

echo "Navi robot service has been created and started successfully."