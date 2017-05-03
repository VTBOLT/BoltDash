#include <stdio.h>
#include <wiringPi.h>
#include <std_msgs/Int8.h>
#include <std_msgs/String.h>
#include <can_to_qt_bolt3/gpio_msg.h>


#include <ros/ros.h>

#define MESSAGE_BUFFER_SIZE 10
#define IGNOK_PIN 27
#define IMD_PIN 24
#define PRESSURE_PIN 28
#define BMSDE_PIN 25

int main (int argc, char** argv) {
	ros::init(argc, argv, "gpio_node");
	ros::NodeHandle nh;
	int IGNOK;
	int IMD;
	int PRESSURE;
	int BMSDE;
	std_msgs::String msg_all;
	std_msgs::Int8 msg_IGNOK;
	std_msgs::Int8 msg_IMD;
	std_msgs::Int8 msg_PRESSURE;
	std_msgs::Int8 msg_BMSDE;

	can_to_qt_bolt3::gpio_msg msg_gpio;

	ros::Publisher system_state = nh.advertise<std_msgs::String>("gpio/readable", MESSAGE_BUFFER_SIZE);
	ros::Publisher state_gpio = nh.advertise<can_to_qt_bolt3::gpio_msg>("gpio/all", MESSAGE_BUFFER_SIZE);

	ros::Publisher state_IGNOK = nh.advertise<std_msgs::Int8>("gpio/IGNOK", MESSAGE_BUFFER_SIZE);
	ros::Publisher state_IMD = nh.advertise<std_msgs::Int8>("gpio/IMD", MESSAGE_BUFFER_SIZE);
	ros::Publisher state_PRESSURE = nh.advertise<std_msgs::Int8>("gpio/PRESSURE", MESSAGE_BUFFER_SIZE);
	ros::Publisher state_BMSDE = nh.advertise<std_msgs::Int8>("gpio/BMSDE", MESSAGE_BUFFER_SIZE);

	// ros::Subscriber write_sub = nh.subscribe("write", 1000, write_callback);

	ros::Rate loop_rate(5);
	// ROS_INFO_STREAM("Reading System State");
	while (ros::ok()) {

		// Setup GPIO
		wiringPiSetup();
		// Setup Dash Pin as Input
		pinMode(IGNOK_PIN, INPUT);
		pinMode(IMD_PIN, INPUT);
		pinMode(PRESSURE_PIN, INPUT);
		pinMode(BMSDE_PIN, INPUT);

		// Read Dash Pin State
		IGNOK = digitalRead(IGNOK_PIN);
		IMD = digitalRead(IMD_PIN);
		PRESSURE = digitalRead(PRESSURE_PIN);
		if(digitalRead(BMSDE_PIN) == 1){
			BMSDE = 0;
		}

		if (digitalRead(BMSDE_PIN) == 0){
			BMSDE = 1;
		}
		
		// Record Dash States
		// std::cout << IGNOK << IMD  << PRESSURE << BMSDE << std::endl;
		// ROS_INFO_STREAM("IGNOK: " << IGNOK << " IMD: " << IMD << " PRESSURE: " << PRESSURE << " BMSDE: " << BMSDE);
		std::stringstream ss;
    	ss << "IGNOK: " << IGNOK << " IMD: " << IMD << " PRESSURE: " << PRESSURE << " BMSDE: " << BMSDE;
    	msg_all.data = ss.str();
    	msg_IGNOK.data = IGNOK;
    	msg_IMD.data = IMD;
		msg_PRESSURE.data = PRESSURE;
		msg_BMSDE.data = BMSDE;

		msg_gpio.header.stamp = ros::Time::now();
		msg_gpio.IGNOK = IGNOK;
		msg_gpio.IMD = IMD;
		msg_gpio.PRESSURE = PRESSURE;
		msg_gpio.BMSDE = BMSDE;

		// Publish Dash States
    	// ROS_INFO("%s", msg_all.data.c_str());

		system_state.publish(msg_all);
		state_gpio.publish(msg_gpio);
		state_IGNOK.publish(msg_IGNOK);
		state_IMD.publish(msg_IMD);
		state_PRESSURE.publish(msg_PRESSURE);
		state_BMSDE.publish(msg_BMSDE);

		ros::spinOnce();
		loop_rate.sleep();

	}
}
