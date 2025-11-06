#!/usr/bin/env bash
# set -Eeuo pipefail

### === 基本配置 ===
# 四路相机设备节点（按你给的 ID）
cam_f_id="/dev/right_rear_surround"
cam_r_id="/dev/left_rear_surround"
cam_l_id="/dev/left_front_surround"
cam_b_id="/dev/right_front_surround"

# 日志
RUN_LOG="${HOME}/navi_release/navi_robot.log"

# 超时时间设置（例如 30 秒超时）
MAX_WAIT_TIME=120
WAIT_INTERVAL=2  # 每次检查间隔时间

### === 依赖检查 ===
need_cmd() { command -v "$1" >/dev/null 2>&1 || { echo "缺少依赖：$1"; exit 1; }; }
need_cmd timeout

### === 通用函数 ===
check_node_exists() {
  local dev="$1"
  [[ -e "$dev" ]] || { echo "FAIL: $dev 不存在"; return 1; }
  [[ -r "$dev" ]] || { echo "FAIL: $dev 不可读（权限问题？）"; return 1; }
  ls -l "$dev" || true
}

### === 执行四路自检 ===
wait_for_device() {
  local dev="$1"
  local timeout="$2"
  local interval="$3"

  local elapsed=0
  while [[ ! -e "$dev" && $elapsed -lt $timeout ]]; do
    echo "等待设备 $dev 加载..."
    sleep "$interval"
    elapsed=$((elapsed + interval))
  done

  if [[ ! -e "$dev" ]]; then
    echo "FAIL: 设备 $dev 仍然没有加载，超时 $timeout 秒。"
    return 1
  fi
  echo "设备 $dev 已加载。"
}

# 等待设备加载并执行检查
wait_for_device "$cam_f_id" "$MAX_WAIT_TIME" "$WAIT_INTERVAL" || exit 1
wait_for_device "$cam_r_id" "$MAX_WAIT_TIME" "$WAIT_INTERVAL" || exit 1
wait_for_device "$cam_l_id" "$MAX_WAIT_TIME" "$WAIT_INTERVAL" || exit 1
wait_for_device "$cam_b_id" "$MAX_WAIT_TIME" "$WAIT_INTERVAL" || exit 1


echo "所有摄像头检测通过 ✅"

### === 环境加载 & 启动 ROS2 ===
source ~/unitree_ros2/setup.sh
sleep 0.5
source ~/navi_release/setup.sh
sleep 0.5

# 仅在全部自检通过的情况下执行
echo "启动 navi_robot，并记录日志到 ${RUN_LOG}"
ros2 launch navi_robot robot.launch.py >> "${RUN_LOG}" 2>&1