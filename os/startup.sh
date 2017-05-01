#!/bin/bash
screen -d -m -S roscore -Q select . ;  screen -dmS roscore bash -c 'source /home/dash/dash/catkin_ws/devel/setup.bash; roscore; exec bash;';
screen -d -m -S gpio -Q select . ; screen -dmS gpio bash -c 'source /home/dash/dash/catkin_ws/devel/setup.bash; rosrun gpio gpio_node; exec bash;';
screen -d -m -S can -Q select . ; screen -dmS can bash -c 'source /home/dash/dash/catkin_ws/devel/setup.bash; rosrun can_to_qt_bolt3 can_talker_bolt3; exec bash;';
screen -d -m -S qt -Q select . ; screen -dmS qt bash -c '/home/dash/BoltDash; exec bash;';
