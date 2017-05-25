#include <ros/ros.h>
#include <servo_msgs/Ping.h>
#include <servo_msgs/Reset.h>

void pingCallback(const servo_msgs::Ping::ConstPtr& msg)
{
	ROS_INFO("servo_node ping test. servo_id: %d", msg->id);
}

void resetCallback(const servo_msgs::Reset::ConstPtr& msg)
{
	ROS_INFO("servo_node reset test. servo_id: %d", msg->id);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "servo_node");
	ros::NodeHandle nh;
	ros::Subscriber ping_sub = nh.subscribe("servo_control/ping", 10, pingCallback);
	ros::Subscriber reset_sub = nh.subscribe("servo_control/reset", 10, resetCallback);
	ros::spin();

	return 0;
}

