#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <geometry_msgs/PoseStamped.h>
#include <geometry_msgs/PoseWithCovarianceStamped.h>
#include <signal.h>
#include <tf/transform_listener.h>
#include <tf/transform_datatypes.h>

int main(int argc, char** argv)
{

    ros::init(argc, argv, "jrc_move2_initialpose");
    ros::NodeHandle node;
    ros::Publisher initial_pose_pub = node.advertise<geometry_msgs::PoseWithCovarianceStamped>("/initialpose", 100);

    //publish the initial pose
    geometry_msgs::PoseWithCovarianceStamped initial_pose;
    initial_pose.header.stamp = ros::Time(0);
    initial_pose.header.frame_id = "map";
    initial_pose.pose.pose.position.x = atof(argv[1]);//-4.402, 1.547
    initial_pose.pose.pose.position.y = atof(argv[2]);
    initial_pose.pose.pose.orientation = tf::createQuaternionMsgFromYaw(atof(argv[3]));


    int initial_time_counter = 0;
    while(initial_time_counter < 5)
    {
        ros::spinOnce();
        initial_pose_pub.publish(initial_pose);
        ROS_INFO("the robot initial pose");
        initial_time_counter = initial_time_counter + 1;
        sleep(1);
    }

return 0;

}
