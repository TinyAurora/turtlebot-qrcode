# turtlebot-qrcode

### 项目功能：  
- 基于turtlebot2标准平台，实现通过二维码识别的方法来确定turtlebot初始位姿以及导航目标，
从而替代在rviz上通过鼠标操作点击2D Pose Estimate以及2D Nav Goal的方法。  
- 主要实现文件为simple_navigation_goals_debug.cpp和simple_navigation_initialpose_debug.cpp

### 项目操作步骤如下：

- roslaunch turtlebot_bringup minimal.launch
- roslaunch turtlebot_navigation amcl_demo.launch map_file:=/tmp/my_map.yaml
- roslaunch turtlebot_rviz_launchers view_navigation.launch --screen

- rosrun simple_navigation_goals simple_navigation_goals   
- rosrun simple_navigation_goals simple_navigation_initialpose

- roslaunch qr_detector detector
