#include <ros/ros.h>
#include <iostream>
#include <sstream>
#include <agv_udp/CenterCmd.h>
#include <agv_udp/ReserveArea.h>
#include <nav_msgs/Odometry.h>
const int r_num = 4;
using namespace std;
agv_udp::ReserveArea reserve_area[r_num];
agv_udp::CenterCmd center_command, center_command_last;
vector<int> list_first_ra, list_second_ra;
bool SUB_FLAG[r_num];
bool robot_conflict_with_other_robot(int robot_index, int priority[]);
bool robot_conflict_with_other_r_a(int robot_index, int priority[]);

void Callback_ra(const agv_udp::ReserveArea::ConstPtr&  r_a, int idx)
{
    SUB_FLAG[idx] = true;
    reserve_area[idx] = *r_a;
    // ROS_INFO("i have receive the reserve area from robot");
}
int main(int argc, char ** argv)
{
    std::cout<<"this is command center!"<<std::endl;
    ros::init(argc, argv, "center_command_pub");
    ros::NodeHandle node;
    ros::Subscriber reserva_area_sub[r_num];
    for (int i=0; i<r_num; i++)
    {
        SUB_FLAG[i] = false;
        stringstream topic;
        topic<<"/robot"<<i+1<<"/reserve_area";
        std::cout<<topic.str()<<std::endl;
        reserva_area_sub[i] = node.subscribe<agv_udp::ReserveArea>(topic.str(), 100, boost::bind(&Callback_ra, _1, i));
    }
    ros::Publisher center_cmd_pub = node.advertise<agv_udp::CenterCmd>("/center_command", 100);
    //initial the vector
    for (int i=0;i<r_num;i++)
    {
        center_command.reserve_area_first.push_back(10000);
        center_command.reserve_area_second.push_back(10000);
    }

    while (ros::ok())
    {
        ros::spinOnce();
        center_command_last = center_command;
        int priority_array[r_num];
        int head = 0; 
        int tail = r_num - 1;
        for (int i=0; i<r_num; i++)
        {
            if(center_command_last.reserve_area_first[i] == reserve_area[i].first_area && 
                center_command_last.reserve_area_second[i] == reserve_area[i].second_area) 
            {
                priority_array[head] = i;
                head++;
            }
            else
            {
                priority_array[tail] = i;
                tail--;
            }
        }

        std::cout<<priority_array[0]<<" "<<priority_array[1]<<" "<<priority_array[2]<<" "<<priority_array[3]<<std::endl;
        for (int i=0; i<r_num; i++)   
        {
            int temp_index = priority_array[i];
            if (SUB_FLAG[temp_index])
            {
                SUB_FLAG[temp_index] = false;

                if(center_command_last.reserve_area_first[temp_index] == reserve_area[temp_index].first_area && 
                center_command_last.reserve_area_second[temp_index] == reserve_area[temp_index].second_area) 
                    continue;

                if (robot_conflict_with_other_robot(i, priority_array) || robot_conflict_with_other_r_a(i, priority_array))
                {
                    center_command.reserve_area_first[temp_index] = reserve_area[temp_index].first_area;
                    center_command.reserve_area_second[temp_index] = reserve_area[temp_index].first_area;
                }
                else
                {
                    center_command.reserve_area_first[temp_index] = reserve_area[temp_index].first_area;
                    center_command.reserve_area_second[temp_index] = reserve_area[temp_index].second_area;
                }

            }

        }

        center_cmd_pub.publish(center_command);
    }
return 0;
}



bool robot_conflict_with_other_robot(int robot_index, int priority[])
{
    for (int i=0; i<r_num; i++)
    {
        if(i != robot_index)
        {
            if(reserve_area[priority[robot_index]].second_area == reserve_area[priority[i]].first_area)
            {
                return true;
            }
        }
    }
    return false;

}
bool robot_conflict_with_other_r_a(int robot_index, int priority[])
{
    for (int i= 0; i<robot_index; i++)
    {
        if(reserve_area[priority[robot_index]].second_area == center_command.reserve_area_second[priority[i]])
        {
            return true;
        }
    }
    return false;
}
