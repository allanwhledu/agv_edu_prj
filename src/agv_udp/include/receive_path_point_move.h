#include "ros/ros.h"
#include <string>
#include <geometry_msgs/Twist.h>
#include <vector>
#include <geometry_msgs/Point.h>
#include <sensor_msgs/LaserScan.h>
#include <math.h>
#include <sstream>
#include <boost/thread/thread.hpp>
#include <thread>
#include <tf/transform_broadcaster.h>
#include <fstream>
//enum state{move, rotate};
struct TimePoint
{
	geometry_msgs::Point point;
	double move_time;
	bool move_state;
	bool final_goal;
	bool is_arrival;
};

class RecvPathPointMove
{
public:
	RecvPathPointMove(ros::NodeHandle &nh, int robot_id_);
	~RecvPathPointMove();
	void execute();
	void pos_cb(const geometry_msgs::Point::ConstPtr&  p);
	void col_cb(const sensor_msgs::LaserScan::ConstPtr& col);
	bool modify_path(TimePoint point);
	boost::thread thread_exe();
	//ros
	int robot_id;
	ros::Publisher cmd_pub;
	ros::Subscriber pos_sub, col_sub;
	std::vector<TimePoint> path;
	std::vector<TimePoint> receive_path_point;
	TimePoint following_point;
	geometry_msgs::Point robot_pos;
	geometry_msgs::Twist velocity;
	sensor_msgs::LaserScan col_info;
	bool final_goal, close_goal;
	double run_time;
	ros::Time start_time;
	double acc_x, acc_y, acc_a;
	double max_v_x, max_v_y, max_v_a;


};