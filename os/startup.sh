sudo ip link set can0 type can bitrate 500000
ifconfig can0 up

byobu new-window "roscore && exec bash"
byobu new-window "rosrun gpio gpio_node && exec bashl"
byobu new-window "rosrun can_to_qt_bolt3 can_talker_bolt3 && exec bash"
byobu new-window "./BoltDash && exec bash"