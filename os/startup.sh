#!/bin/bash
#echo -e "bolt\n" | sudo ip link set can0 type can bitrate 500000 && echo -e " bolt\n" | sudo ifconfig can0 up
source /opt/ros/kinetic/setup.bash
source /home/dash/dash/catkin_ws/devel/setup.bash
sleep 5
screen -d -m -S roscore -Q select . ;  screen -dmS roscore bash -c 'source /home/dash/dash/catkin_ws/devel/setup.bash; roscore; exec bash;'
sleep 5
screen -d -m -S gpio -Q select . ; screen -dmS gpio bash -c 'source /home/dash/dash/catkin_ws/devel/setup.bash; rosrun gpio gpio_node; exec bash;'
screen -d -m -S can -Q select . ; screen -dmS can bash -c 'source /home/dash/dash/catkin_ws/devel/setup.bash; rosrun can_to_qt_bolt3 can_talker_bolt3; exec bash;'
screen -d -m -S gui -Q select . ; screen -dmS gui bash -c 'source /home/dash/dash/catkin_ws/devel/setup.bash; roslaunch dash_gui dash_gui.launch; exec bash;'
