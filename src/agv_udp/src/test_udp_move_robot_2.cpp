#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <vector>
#include <geometry_msgs/Point.h>
#include <math.h>

geometry_msgs::Point cur, goal;
geometry_msgs::Point point[9];
void get_point()
{
point[0].x = -4.402;
point[0].y = 1.547;
point[0].z = -2.42;

point[1].x = -5.644;
point[1].y = 0.463;
point[1].z = -2.572;

point[2].x = -6.436;
point[2].y = 0.335;
point[2].z = -3.012;

point[3].x = -8.002;
point[3].y = 0.2;
point[3].z = -3.005;

point[4].x = -7.94;
point[4].y = -0.764;//zhong zhuan dian 
point[4].z = -3.012;

point[5].x = -9.328;
point[5].y = -0.045;
point[5].z = -3.079;

point[6].x = -10.575;
point[6].y = -0.075;
point[6].z = -2.665;

point[7].x = -11.405;
point[7].y = -0.529;
point[7].z = -2.509;

point[8].x = -12.564;
point[8].y = -1.515;
point[8].z = 0.51;
}


void pose_cb(const geometry_msgs::Point::ConstPtr&  p)
{
	cur = *p;
}
int main(int argc, char** argv)
{
	std::cout<<"1"<<std::endl;
	get_point();
	ros::init(argc, argv, "udp_move_robot2");
	ros::NodeHandle node;
	ros::Publisher cmd_vel = node.advertise<geometry_msgs::Twist>("/robot2/cmd_vel", 100);
	ros::Subscriber pos_sub = node.subscribe("/robot2/robot_pos", 1, pose_cb);
	std::vector<int> path_index = {0, 1, 2, 3};//, 5, 6, 7, 8};
	bool reverse = false;
	if(atoi(argv[1]) == 1) {reverse = true;}
	if(reverse) 
	{
		std::reverse(path_index.begin(), path_index.end());
	}

	bool path_insert[8] = {false, false, false, false, false, false, false, false};
	std::vector<geometry_msgs::Point> path;
	int count = 0;
	std::cout<<"2"<<std::endl;
	while(ros::ok())
	{
		ros::spinOnce();
		std::cout<<"count:"<<count<<std::endl;
		geometry_msgs::Point pursuit_point = point[path_index[count]];
		if(hypot(fabs(pursuit_point.x - cur.x), fabs(pursuit_point.y - cur.y))< 0.5)  //very near
		{
			if(count < path_index.size() - 1)
			{
				count++;
				continue;
			}
		}
		std::cout<<"3"<<std::endl;
		if(!path_insert[count])
		{
			path_insert[count] = true;
			//insert point 
			geometry_msgs::Point first_point, second_point;
			int insert_size;
			if(count == 0)  //initial
			{
				first_point = cur;
				second_point = point[path_index[count]];
				insert_size = 5;
			}
			else
			{
				first_point = point[path_index[count-1]];
				second_point = point[path_index[count]];
				insert_size = 50;
			}

			for(int i=0; i<insert_size;i++)
			{
				geometry_msgs::Point temp_insert_point;
				temp_insert_point.x = i*(second_point.x - first_point.x)/insert_size + first_point.x;
				temp_insert_point.y = i*(second_point.y - first_point.y)/insert_size + first_point.y;
				temp_insert_point.z = atan2(second_point.y - first_point.y, second_point.x - first_point.x);
				path.push_back(temp_insert_point);
			}
			//add the goal point in the path
			if(count == path_index.size()-1)
			{
				path.push_back(point[path_index[count]]);
			}
		}
		if(path.empty())
			continue;
		std::cout<<"4"<<std::endl;
		//find the nearest point in the point
		int nearest_point_index;
		double nearest_dist = 10000;
		for(int i=0; i<path.size(); i++)
		{
			if(hypot(fabs(path[i].x - cur.x), fabs(path[i].y - cur.y))  < nearest_dist)
			{
				nearest_point_index = i;
				nearest_dist = hypot(fabs(path[i].x - cur.x), fabs(path[i].y - cur.y));
			}
		}
		std::cout<<"5"<<std::endl;

		//get the following point
		geometry_msgs::Point nearest_point;
		if(nearest_point_index + 30 < path.size())
		{
			nearest_point = path[nearest_point_index + 30];
		}
		else
		{
			nearest_point = path.back();
		}
		// std::cout<<nearest_point<<std::endl;
		// std::cout<<"path size"<<path.size()<<path.back()<<std::endl;
		// std::cout<<"robot pose"<<cur<<std::endl;
		// std::cout<<"path_insert"<<path_insert[count]<<std::endl;
		// for(int i=0; i<path.size();i++)
		// {
		// 	std::cout<<"path_"<<path[i]<<std::endl;
		// }

		//c
		//calculate the velocity
		double v_x, v_y, v_a;  //velocity
		double e_x, e_y, e_a;  //error in dist
		e_x = nearest_point.x - cur.x;
		e_y = nearest_point.y - cur.y;
		e_a = atan2(e_y, e_x) - cur.z;

		if(e_a < 0 && fabs(e_a) > M_PI) {e_a = 2*M_PI + e_a;}
		if(e_a > 0 && fabs(e_a) > M_PI) {e_a = e_a - 2*M_PI;}

		if(hypot(fabs(e_x), fabs(e_y)) < 0.1 && count == path_index.size() - 1)
		{
			v_x = hypot(fabs(e_x), fabs(e_y));
		}
		else
		{
			v_x = 0.3;
		}

		if(fabs(e_a) < 0.5)
		{
			v_a = e_a;
		}
		else
		{
			v_a = 0.5*e_a/fabs(e_a);
		}
		if(fabs(e_a) > 0.5 && fabs(v_x) > 0.02)
		{
			v_x = 0;
		}

		if(count == path_index.size() - 1 && hypot(fabs(cur.x - path.back().x), fabs(cur.y - path.back().y)) < 0.1)//near the goal
		{
			v_x = e_x;
			v_y = e_y;
			v_a = path.back().z - cur.z;
			if(v_a < 0 && fabs(v_a) > M_PI) {v_a = 2*M_PI + v_a;}
		    if(v_a > 0 && fabs(v_a) > M_PI) {v_a = v_a - 2*M_PI;}
			if(fabs(v_a) > 0.5)
			{
				v_a = 0.5*v_a/fabs(v_a);
				v_x = 0;
				v_y = 0;
			}
			if(fabs(v_x) < 0.1&& fabs(v_y) < 0.1&&fabs(v_a) < 0.1)
			{
				return 1;
			}
		}
		geometry_msgs::Twist velocity;
		velocity.linear.x = v_x;
		velocity.linear.y = 0;
		velocity.angular.z = v_a;
		cmd_vel.publish(velocity);

	}

	return 0;

}
