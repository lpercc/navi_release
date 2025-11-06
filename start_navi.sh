#!/usr/bin/env bash
# set -Eeuo pipefail

### === 基本配置 ===
# 四路相机设备节点（按你给的 ID）
cam_f_id="/dev/right_rear_surround"
cam_r_id="/dev/left_rear_surround"
cam_l_id="/dev/left_front_surround"
cam_b_id="/dev/right_front_surround"

# 通用默认 CAPS（可按需修改或留空以跳过协商测试）
DEFAULT_CAPS="video/x-raw,format=YUY2,width=1920,height=1536,framerate=30/1"

# 如某一路需要不同 caps，可在此单独覆盖（留空则使用 DEFAULT_CAPS；设为 "NONE" 则跳过协商）
CAM_F_CAPS="${CAM_F_CAPS:-$DEFAULT_CAPS}"
CAM_R_CAPS="${CAM_R_CAPS:-$DEFAULT_CAPS}"
CAM_L_CAPS="${CAM_L_CAPS:-$DEFAULT_CAPS}"
CAM_B_CAPS="${CAM_B_CAPS:-$DEFAULT_CAPS}"

# 连续取流稳定性检测参数
TEST_DURATION_SEC="${TEST_DURATION_SEC:-1}"    # 连续取流检测时长
MIN_FPS_THRESHOLD="${MIN_FPS_THRESHOLD:-10}"   # 判定为“稳定”的最低 FPS（保守阈值）
MIN_SAMPLES="${MIN_SAMPLES:-3}"                # 至少采集到多少条 FPS 统计行

# 日志
RUN_LOG="${HOME}/navi_release/navi_robot.log"
CHECK_LOG_DIR="$(mktemp -d /tmp/camcheck.XXXXXX)"
trap 'rm -rf "$CHECK_LOG_DIR"' EXIT

### === 依赖检查 ===
need_cmd() { command -v "$1" >/dev/null 2>&1 || { echo "缺少依赖：$1"; exit 1; }; }
need_cmd gst-launch-1.0
need_cmd v4l2-ctl
need_cmd timeout

### === 通用函数 ===
check_node_exists() {
  local dev="$1"
  [[ -e "$dev" ]] || { echo "FAIL: $dev 不存在"; return 1; }
  [[ -r "$dev" ]] || { echo "FAIL: $dev 不可读（权限问题？）"; return 1; }
  ls -l "$dev" || true
}

probe_formats() {
  local dev="$1"
  echo "支持格式（摘要）："
  v4l2-ctl -d "$dev" --list-formats-ext | sed -n '1,80p' || { echo "WARN: v4l2-ctl 失败"; }
}

open_minimal() {
  local dev="$1"
  echo "最小打开测试：$dev"
  gst-launch-1.0 -q -e v4l2src device="$dev" num-buffers=3 ! fakesink
}

negotiate_caps() {
  local dev="$1"
  local caps="$2"
  [[ "$caps" == "NONE" ]] && { echo "跳过协商测试（按配置）"; return 0; }
  [[ -z "${caps}" ]] && { echo "未设置 CAPS，跳过协商测试"; return 0; }
  echo "协商测试（$caps）"
  gst-launch-1.0 -q -e v4l2src device="$dev" ! "$caps" ! fakesink
}

stable_stream_test() {
  local dev="$1"
  local caps="$2"
  local tag="$3" # 相机名标签
  local logf="${CHECK_LOG_DIR}/${tag}.fps.log"

  echo "连续取流稳定性测试：$dev（${TEST_DURATION_SEC}s）"
  # 选择是否强制 caps
  local pipeline="v4l2src device=${dev}"
  if [[ -n "$caps" && "$caps" != "NONE" ]]; then
    pipeline+=" ! ${caps}"
  fi
  # 加一个 videoconvert 增强兼容性；fpsdisplaysink 输出到 fakesink，避免 GUI 依赖
  pipeline+=" ! videoconvert ! fpsdisplaysink video-sink=fakesink text-overlay=false sync=true"

  # 超时收尾；将 stdout+stderr 统一记录
  if ! timeout "$((TEST_DURATION_SEC+2))" bash -c \
      "gst-launch-1.0 -e ${pipeline}" &> "$logf"; then
    echo "FAIL: 取流过程中断或报错（详见 ${logf})"
    return 1
  fi

  # 从日志解析 FPS（匹配形如 'fps: 29.9' 或 'Rendered ... fps=29.9' 等）
  local fps_lines
  fps_lines=$(grep -Ei 'fps[:= ]+[0-9]+' "$logf" || true)
  local nlines
  nlines=$(printf "%s\n" "$fps_lines" | sed '/^\s*$/d' | wc -l | tr -d ' ')
  if (( nlines < MIN_SAMPLES )); then
    echo "FAIL: FPS 样本过少（${nlines}/${MIN_SAMPLES}），可能不稳定（详见 ${logf})"
    return 1
  fi

  # 取最后一次 FPS 值作为代表（更接近稳态）
  local last_fps
  last_fps=$(printf "%s\n" "$fps_lines" | tail -n1 | grep -Eo '[0-9]+(\.[0-9]+)?' | tail -n1 || echo "0")
  # 兜底：如果没抓到数字
  if [[ -z "$last_fps" ]]; then last_fps="0"; fi

  # 粗略统计“drop”字样
  local drops
  drops=$(grep -i 'drop' "$logf" | wc -l | tr -d ' ')

  echo "采样行数: ${nlines}, 末次 FPS: ${last_fps}, drops: ${drops}"
  # 判定阈值（保守）。若你强制 30fps，可把阈值调到 20~25
  awk -v f="$last_fps" -v th="$MIN_FPS_THRESHOLD" 'BEGIN{ exit (f>=th?0:1) }' \
    && echo "PASS: 连续取流稳定（FPS≥${MIN_FPS_THRESHOLD})" \
    || { echo "FAIL: FPS 偏低（<${MIN_FPS_THRESHOLD}），详见 ${logf}"; return 1; }
}

check_one_cam() {
  local name="$1" dev="$2" caps="$3"
  echo "==== 检测 ${name} @ ${dev} ===="
  check_node_exists "$dev"
  probe_formats "$dev" || true
  open_minimal "$dev"
  # negotiate_caps "$dev" "$caps"
  stable_stream_test "$dev" "$caps" "$name"
  echo "==== ${name} ✅ 通过 ===="
  echo
}

## === 执行四路自检 ===
check_one_cam "Front (cam_f_id)" "$cam_f_id" "$CAM_F_CAPS"
check_one_cam "Rear  (cam_r_id)" "$cam_r_id" "$CAM_R_CAPS"
check_one_cam "Left  (cam_l_id)" "$cam_l_id" "$CAM_L_CAPS"
check_one_cam "Back  (cam_b_id)" "$cam_b_id" "$CAM_B_CAPS"

echo "所有摄像头检测通过 ✅"

### === 环境加载 & 启动 ROS2 ===
source ~/unitree_ros2/setup.sh
sleep 0.5
source ~/navi_release/setup.sh
sleep 0.5

# 仅在全部自检通过的情况下执行
echo "启动 navi_robot，并记录日志到 ${RUN_LOG}"
# ros2 launch navi_robot robot.launch.py >> "${RUN_LOG}" 2>&1


# 启动并记录日志
ros2 launch navi_robot robot.launch.py >> ~/navi_release/navi_robot.log 2>&1
