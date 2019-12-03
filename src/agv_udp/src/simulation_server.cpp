#include "simulation_server.h"

simulation_server::simulation_server(ros::NodeHandle &nh, int robot_id_)
{
	robot_id =robot_id_;
	std::stringstream pos_pub_topic, col_pub_topic, laser_sub_topic, pos_tf_sub_topic;

	pos_pub_topic<<"/robot"<<robot_id<<"/robot_pos";
	pos_pub = nh.advertise<geometry_msgs::Point>(pos_pub_topic.str(), 100);

	col_pub_topic<<"/robot"<<robot_id<<"/col_dis";
	col_pub = nh.advertise<sensor_msgs::LaserScan>(col_pub_topic.str(), 100);

	laser_sub_topic<<"/robot"<<robot_id<<"/scan";
	laser_sub = nh.subscribe(laser_sub_topic.str(),1,&simulation_server::laser_cb,this);

	pos_tf_sub_topic<<"/robot"<<robot_id<<"/odom";
	pos_tf_sub = nh.subscribe(pos_tf_sub_topic.str(),1,&simulation_server::odom_cb,this);
}

simulation_server::~simulation_server()
{

}

void simulation_server::laser_cb(const sensor_msgs::LaserScan::ConstPtr& laser)
{
	sensor_msgs::LaserScan temp_col;
    int front_stop, back_stop, left_stop, right_stop;
    front_stop = 0;  
    back_stop = 0; 
    left_stop = 0;  
    right_stop = 0;
    double min_front, min_back, min_left, min_right;
    min_front = 1.2;
    min_back = 1.2;
    min_left = 1.2;
    min_right = 1.2;

    for(int i=0; i<laser->ranges.size(); i++)
    {
        //count for stop
        if(laser->ranges[i] < 1.2)
        {
            double angle = laser->angle_min + i*laser->angle_increment;
            if( angle >= -0.52 && angle < 0.52)
            {
                front_stop = front_stop + 1;
                if(laser->ranges[i] < min_front)
                    min_front = laser->ranges[i];
            }
            else if(angle >= 0.52 && angle < 2.62)
            {
                left_stop = left_stop + 1;
                if(laser->ranges[i] < min_left)
                    min_left = laser->ranges[i];
            }
            else if(angle >= -2.62 && angle < 0.52)
            {
                right_stop = right_stop + 1;
                if(laser->ranges[i] < min_right)
                    min_right = laser->ranges[i];
            }
            else
            {
                back_stop = back_stop + 1;
                if(laser->ranges[i] < min_back)
                    min_back = laser->ranges[i];
            }
        }
    }
    int temp_num = 5;
    //STOP
    if(front_stop >= temp_num)
    {
        temp_col.intensities.push_back(1);
    }
    else
    {
    	temp_col.intensities.push_back(0);
    }
    temp_col.ranges.push_back(min_front);


    if(back_stop >= temp_num)
    {
        temp_col.intensities.push_back(1);
    }
    else
    {
		temp_col.intensities.push_back(0);
    }
	temp_col.ranges.push_back(min_back);


    if(left_stop >= temp_num)
    {
		temp_col.intensities.push_back(1);
    }
    else
    {
    	temp_col.intensities.push_back(0);
    }
    temp_col.ranges.push_back(min_left);

    if(right_stop >= temp_num)
    {
		temp_col.intensities.push_back(1);
    }
    else
    {
    	temp_col.intensities.push_back(0);
    }
    temp_col.ranges.push_back(min_right);


    col_pub.publish(temp_col);
}
void simulation_server::odom_cb(const nav_msgs::Odometry::ConstPtr& odom)
{
	geometry_msgs::Point temp_robot_pose;
	temp_robot_pose.x = odom->pose.pose.position.x;
	temp_robot_pose.y = odom->pose.pose.position.y;
	temp_robot_pose.z = tf::getYaw(odom->pose.pose.orientation);
	pos_pub.publish(temp_robot_pose);
}

void simulation_server::execute()
{
	ros::Rate rate(10);
	while(ros::ok())
	{
		rate.sleep();
		ros::spinOnce();
	}
}

boost::thread simulation_server::thread_exe()
{
	return boost::thread(&simulation_server::execute, this);
}