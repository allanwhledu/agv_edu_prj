#include <ros/ros.h>
#include <agv_udp/Replan.h>
#include <fstream>
#include <time.h>
#include <vector>

using namespace std;

vector<int>  task_list;
int r_s_count;
bool assign_task(agv_udp::Replan::Request &req, agv_udp::Replan::Response &res)
{
    ROS_INFO("ahha hh");
    if(req.replan)
    {
       res.new_goal = task_list[r_s_count];

        ROS_INFO("i have receive the request");
    }
    r_s_count++;
    r_s_count = r_s_count%10;
    return true;
}


void get_task_list()
{
    task_list.push_back(2);
    task_list.push_back(10);
    task_list.push_back(6);
    task_list.push_back(14);
    task_list.push_back(1);
    task_list.push_back(8);
    task_list.push_back(13);
    task_list.push_back(0);
    task_list.push_back(3);
    task_list.push_back(5);
}
 int main(int argc, char ** argv)
 {
     ros::init(argc, argv, "replan_server");
     ros::NodeHandle node;
     ros::ServiceServer service = node.advertiseService("/assignment_center", assign_task);
     get_task_list();
     r_s_count = 0;
     ROS_INFO("ready to assign task to robot");
     ros::spin();

     return 0;
 }
