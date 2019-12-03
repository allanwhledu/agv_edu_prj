//record message /scan /cmd_vel /move_base_simple/goal
#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/PoseStamped.h>
#include <move_base_msgs/MoveBaseActionGoal.h>
#include <tf/transform_listener.h>
#include <tf/transform_datatypes.h>
#include <string.h>
#include <cmath>
#include <fstream>
#include <cstdlib>


//define global variable
bool FLAG = false;
move_base_msgs::MoveBaseActionGoal    global_goal;
geometry_msgs::Twist          velocity_command;
sensor_msgs::LaserScan        LaserScan;

const char * file_goal = "goal.txt";
const char * file_laser = "laser.txt";
const char * file_cmd_vel = "cmd_vel.txt";

//写各接收者的回调函数

	//接收控制信号的回调函数
    void Callback_cmd_vel(const geometry_msgs::Twist::ConstPtr& cmd_vel)
	{
        //ROS_INFO("i heard the velocity_command information!");
		velocity_command = *cmd_vel;
	}

 
//main function/////////////////////////////////////////////////////////

int main (int argc , char** argv)
{
	ros::init(argc, argv,"record_data");
	ros::NodeHandle node;

	//subscribe cmd_vel information
    ros::Subscriber sub_cmd = node.subscribe("cmd_vel",1,Callback_cmd_vel);
	//output to screen
	ROS_INFO("start the record data");
	//loop rate
	ros::Rate loop_rate(10);
	loop_rate.sleep();
	while(ros::ok())
	{
        ros::spinOnce();
        //open multi_file,and record the data in the txt

        //record cmd_vel information
        std::ofstream f_cmd_vel(file_cmd_vel,std::ios::out|std::ios::app);
        if (!f_cmd_vel.is_open())
        {
            std::cerr<<"can't open "<<file_cmd_vel<<std::endl;
            exit(EXIT_FAILURE);

        }
        f_cmd_vel<<ros::Time::now()<<std::endl;
        f_cmd_vel<<velocity_command.linear.x<<"    "<<velocity_command.linear.y<<"    "<<velocity_command.linear.y<<"    "<<
                   velocity_command.angular.x<<"    "<<velocity_command.angular.y<<"    "<<velocity_command.angular.z<<std::endl;

        std::cout<<velocity_command.linear.x<<"    "<<velocity_command.linear.y<<"    "<<velocity_command.linear.y<<"    "<<
                   velocity_command.angular.x<<"    "<<velocity_command.angular.y<<"    "<<velocity_command.angular.z<<std::endl;
        f_cmd_vel.close();

        loop_rate.sleep();

    }//end while
return 0;
}//end main


