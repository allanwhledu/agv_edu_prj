#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
 #include<stdlib.h>
using namespace std;
 int main(int argc, char** argv)
{
ros::init(argc, argv, "cmd_vel");
ros::NodeHandle node;
ros::Rate loop_rate(10);
ros::Publisher  cmd_vel_pub = node.advertise<geometry_msgs::Twist>("/cmd_vel", 1000);

while (ros::ok())
{
        ros::spinOnce();
        loop_rate.sleep();
	geometry_msgs::Twist velocity;
	velocity.linear.x = 0.1*(rand()%10);
        velocity.linear.y = 0;
        velocity.linear.z = 0;
        velocity.angular.x = 0;
        velocity.angular.y = 0;
        velocity.angular.z = 0.1*(rand()%5);
	cmd_vel_pub.publish(velocity);
	cout<<velocity.linear.x<<endl;
}
return 0;
}
