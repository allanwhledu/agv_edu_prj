#include <iostream>
#include <ros/ros.h>
#include <signal.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <tf/transform_listener.h>
#include <tf/transform_datatypes.h>
#include <boost/thread/thread.hpp>
using namespace std;

geometry_msgs::Pose pose_cur;
ros::Publisher cmd_vel_pub;
void amcl_pose_cb(const geometry_msgs::PoseWithCovarianceStamped::ConstPtr& amcl_pose)
{
    pose_cur = amcl_pose->pose.pose;
}

void shutdown(int sig)
{
    cmd_vel_pub.publish(geometry_msgs::Twist());
    ros::Duration(1).sleep();
    ROS_INFO("shut down");
    ros::shutdown();
}

int main(int argc, char** argv)
{
ros::init(argc, argv, "move_forward");
ros::NodeHandle node;
ros::Subscriber amcl_pose_sub = node.subscribe("amcl_pose", 1, amcl_pose_cb);
cmd_vel_pub = node.advertise<geometry_msgs::Twist>("cmd_vel", 1000);
signal(SIGINT, shutdown);

//initial goal position in frame base_link
geometry_msgs::PoseStamped goal_in_base[2], goal_in_map[2];
goal_in_base[0].header.stamp = ros::Time(0);
goal_in_base[1].header.stamp = ros::Time(0);

goal_in_base[0].header.frame_id = "base_link";
goal_in_base[1].header.frame_id = "base_link";

goal_in_base[0].pose.position.x = 0.0;
goal_in_base[0].pose.orientation.w = 1.0;

goal_in_base[1].pose.position.x = 1.0; //move forward for 1m;
goal_in_base[1].pose.orientation.w = 1.0;

goal_in_map[0].header.stamp = goal_in_base[0].header.stamp;
goal_in_map[1].header.stamp = goal_in_base[1].header.stamp;

goal_in_map[0].header.frame_id = "map";
goal_in_map[1].header.frame_id = "map";
//get the tf from base_link to map

tf::TransformListener listener(ros::Duration(100.0));

tf::StampedTransform transform;
try{
   listener.waitForTransform("/map", "/base_link", ros::Time(0), ros::Duration(100.0) );
   listener.lookupTransform("/map", "/base_link", ros::Time(0), transform);
    }
catch (tf::TransformException ex){
   ROS_ERROR("%s",ex.what());
   ros::Duration(1.0).sleep();
   }

listener.transformPose("/map",ros::Time(0), goal_in_base[0], "/base_link", goal_in_map[0]);
listener.transformPose("/map",ros::Time(0), goal_in_base[1], "/base_link", goal_in_map[1]);


geometry_msgs::PoseStamped  goal_map = goal_in_map[1];

while(ros::ok())
{
    ros::spinOnce();
    try{
       listener.waitForTransform("/base_link", "/map", ros::Time(0), ros::Duration(100.0) );
       listener.lookupTransform("/base_link", "/map", ros::Time(0), transform);
        }
    catch (tf::TransformException ex){
       ROS_ERROR("%s",ex.what());
       ros::Duration(1.0).sleep();
       }
    geometry_msgs::PoseStamped goal;

    listener.transformPose("/base_link",ros::Time(0), goal_map, "/map", goal);

    geometry_msgs::Twist velocity;
    double vx = goal.pose.position.x;
    double vy = goal.pose.position.y;
    if(fabs(vx) > 0.1)
    {
        vx = vx/(fabs(vx)) * 0.1;
    }
    else
    {
        vx = vx;
    }
    if(fabs(vy) > 0.1)
    {
        vy = vy/(fabs(vy)) * 0.1;
    }
    else
    {
        vy = vy;
    }

    velocity.linear.x = vx;
    velocity.linear.y = vy;

    cmd_vel_pub.publish(velocity);
/*

    if(fabs(vx) + fabs(vy) < 0.1)
    {
        cmd_vel_pub.publish(geometry_msgs::Twist());
        goal_map = goal_in_map[0];
    }

*/

}

return 0;
}
