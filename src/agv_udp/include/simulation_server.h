//ros
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Point.h"
#include "sensor_msgs/LaserScan.h"
#include "nav_msgs/Odometry.h"
#include <sstream>
#include <boost/thread/thread.hpp>
#include <thread>
#include <tf/transform_broadcaster.h>
#include <turtlesim/Pose.h>

#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <iostream>

class simulation_server
{
public:
	simulation_server(ros::NodeHandle &nh, int robot_id_);//构造函数;
	~simulation_server();
	ros::Publisher pos_pub, col_pub;
	ros::Subscriber laser_sub, pos_tf_sub;
	int robot_id;

	void laser_cb(const sensor_msgs::LaserScan::ConstPtr& laser);
	void odom_cb(const nav_msgs::Odometry::ConstPtr& odom);

	void execute();
	boost::thread thread_exe();

};