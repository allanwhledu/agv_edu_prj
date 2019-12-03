#include <ros/ros.h>
#include <signal.h>
#include <string.h>
#include <boost/thread/thread.hpp>
#include <cmath>
#include <sstream>
#include <Astar.h>
#include <fstream>
#include <map> 
#include <nav_msgs/Odometry.h>
#include <agv_udp/ReserveArea.h>
#include <agv_udp/CenterCmd.h>
#include <agv_udp/Replan.h>
#include <tf/transform_listener.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/Point.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Point.h>

class distributed_reserve_area
{
public:
	//VARIABLE

	//ros
	ros::Subscriber pos_sub, center_cmd_sub, col_sub;
	ros::Publisher cmd_vel_pub, reserve_area_pub;
	ros::ServiceClient assign_client;


	//map
	const int map_row;
	const int map_column;
	int plan_map[100];
	int weight[100][4];
	std::map<int, geometry_msgs::Point> location;  

	//robot 
	int robot_id;
	geometry_msgs::Point robot_pos;
	geometry_msgs::Twist velocity;
	std::vector<int> path;
	std::vector<geometry_msgs::Point> path_coords;
	double acc_x, acc_y, acc_a;
	double max_v_x, max_v_y, max_v_a;
	bool receive_cmd_flag, replan_flag;
	bool wait_topic_flag;
	agv_udp::CenterCmd center_cmd;
	sensor_msgs::LaserScan col_info;
	agv_udp::ReserveArea r_a, r_a_last;
	agv_udp::Replan srv;
	double run_time;
	double last_circle_run_time;
	ros::Time start_time;

	//FUNCTION

	distributed_reserve_area(
	ros::NodeHandle &nh, int robot_id_, 
	const int x, const int y,
	int input_map[], int input_weight[][4], 
	geometry_msgs::Point input_loc[]);

	~distributed_reserve_area();

	//void initial_map(int map[], int o_edge[][4], geometry_msgs::Point loc[]);
	void single_robot_path_planning(int goal_x, int goal_y);
	geometry_msgs::Point index_2_coords(int index);
	int coords_2_index(geometry_msgs::Point coords);
	bool robot_in_area(int point_index);
	inline void reserve_area_publish(int count);

	void ccmd_cb(const agv_udp::CenterCmd::ConstPtr& center);
	void pose_cb(const geometry_msgs::Point::ConstPtr& p);
	void col_cb(const sensor_msgs::LaserScan::ConstPtr& col);
	void request_assignment();
	void follow_path();
	void shutdown();

	void execute();
	boost::thread thread_exe();

};
