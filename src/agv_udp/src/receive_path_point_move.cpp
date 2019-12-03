#include "receive_path_point_move.h"

RecvPathPointMove::RecvPathPointMove(ros::NodeHandle &nh, int robot_id_)
{
	robot_id = robot_id_;
	//ros initial
	std::stringstream pos_topic, vel_topic, col_topic;
	pos_topic<<"/robot"<<robot_id<<"/robot_pos";
	pos_sub = nh.subscribe(pos_topic.str(), 1, &RecvPathPointMove::pos_cb, this);

	vel_topic<<"/robot"<<robot_id<<"/cmd_vel";
	cmd_pub = nh.advertise<geometry_msgs::Twist>(vel_topic.str(), 1);

	col_topic<<"/robot"<<robot_id<<"/col_dis";
	col_sub = nh.subscribe(col_topic.str(), 1, &RecvPathPointMove::col_cb, this);
	
	final_goal = false;
	close_goal = false;
	while(robot_pos.x == 0 && robot_pos.y == 0 && robot_pos.z == 0)
	{
		ros::spinOnce();
		sleep(1);
		//std::cout<<"fail"<<std::endl;
	}
	//ros::spinOnce();
	run_time = 0.0;

	start_time = ros::Time::now();
	max_v_x = 0.5;
	max_v_y = 0.05;
	max_v_a = 0.5;
	acc_x = 5.0;
	acc_y = 0.0;
	acc_a = 5.0;
}

RecvPathPointMove::~RecvPathPointMove()
{

}

void RecvPathPointMove::pos_cb(const geometry_msgs::Point::ConstPtr&  p)
{
	robot_pos = *p;
}

void RecvPathPointMove::col_cb(const sensor_msgs::LaserScan::ConstPtr& col)
{
	col_info = *col;
}

bool RecvPathPointMove::modify_path(TimePoint point)
{
	close_goal = false;
	if(path.empty())
	{
		point.move_state = false;
		if(hypot(fabs(point.point.x - robot_pos.x), fabs(point.point.y - robot_pos.y)) > 0.35)
		{
			std::cout<<"robot_pose"<<robot_pos.x<<std::endl;
			std::cout<<"illegal path point!!!"<<point.point.x<<" "<<hypot(fabs(point.point.x - robot_pos.x), fabs(point.point.y - robot_pos.y))<<std::endl;
			return false;
		}
	}
	else
	{
		TimePoint last_point = path.back();
		if(last_point.point.x == point.point.x && 
			last_point.point.y == point.point.y && 
			last_point.point.z != point.point.z)
		{
			point.move_state = false;
		}

		if((last_point.point.x != point.point.x || 
		last_point.point.y != point.point.y) )//&& last_point.point.z == point.point.z)
		{
			point.move_state = true;
		}
	}
	point.is_arrival = false;

	path.push_back(point);
	return true;
	// if(path.empty())
	// {
	// 	path.push_back(point);
	// 	receive_path_point.push_back(point);
	// }
	// else
	// {
	// 	run_time = (ros::Time::now() - start_time).toSec();
	// 	TimePoint last_point = receive_path_point.back();
	// 	if(last_point.point.x == point.point.x && 
	// 		last_point.point.y == point.point.y && 
	// 		last_point.point.z != point.point.z)   //the same point with different orientation
	// 	{
	// 		int temp_insert_size = (int)(100*fabs(point.point.z - last_point.point.z));
	// 		for(int i=0; i<temp_insert_size; ++i)
	// 		{
	// 			TimePoint temp_point;
	// 			temp_point.point.x = last_point.point.x;
	// 			temp_point.point.y = last_point.point.y;
	// 			temp_point.point.z = last_point.point.z + i*(point.point.z - last_point.point.z)/temp_insert_size;
	// 			temp_point.move_time = std::max(last_point.move_time, run_time) + i*(point.move_time - last_point.move_time)/temp_insert_size;
	// 			path.push_back(temp_point);
	// 		}
	// 	}

	// 	if((last_point.point.x != point.point.x || 
	// 	last_point.point.y != point.point.y) && 
	// 	last_point.point.z == point.point.z)   //the different with same orientation
	// 	{
	// 		int temp_insert_size = (int)(100*hypot(fabs(last_point.point.x - point.point.x), 
	// 			fabs(last_point.point.y - point.point.y)));
	// 		for(int i=0; i<temp_insert_size; ++i)
	// 		{
	// 			TimePoint temp_point;
	// 			temp_point.point.x = last_point.point.x + i*(point.point.x - last_point.point.x)/temp_insert_size;
	// 			temp_point.point.y = last_point.point.y + i*(point.point.y - last_point.point.y)/temp_insert_size;
	// 			temp_point.point.z = last_point.point.z;
	// 			temp_point.move_time = std::max(last_point.move_time, run_time) + i*(point.move_time - last_point.move_time)/temp_insert_size;
	// 			path.push_back(temp_point);
	// 		}
	// 	}

	// }
}

void RecvPathPointMove::execute()
{
	ros::Rate rate(1000);
	double last_circle_run_time = 0;
	run_time = 0;
	while(ros::ok())
	{
		rate.sleep();
		//sleep(0.001);
		ros::spinOnce();
		ros::Duration temp_dur = ros::Time::now() - start_time;
		run_time = temp_dur.toSec();
		std::vector<TimePoint> temp_path = path;  //use the current path 
		// std::cout<<"last_circle_run_time "<<last_circle_run_time<<"  run_time: "<<run_time<<std::endl;

		if(temp_path.empty())
		{
			cmd_pub.publish(geometry_msgs::Twist());
			std::cerr<<"path is empty"<<std::endl;
			continue;
		}

		// //find the nearest point in the path
		// int path_size = temp_path.size();
		// int nearest_point_index;
		// std::vector<int> nearest_dist_with_dif_ori_array;
		// double nearest_dist = 10000;
		// for(int i=0; i<path_size;++i)
		// {
		// 	double temp_dist = hypot(fabs(temp_path[i].point.x - robot_pos.x), 
		// 		fabs(temp_path[i].point.y - robot_pos.y));
		// 	if(temp_dist < nearest_dist)
		// 	{
		// 		nearest_point_index = i;
		// 		nearest_dist = temp_dist;
		// 	}
		// 	else if(temp_dist == nearest_dist)
		// 	{
		// 		nearest_dist_with_dif_ori_array.push_back(i);
		// 	}
		// }
		// nearest_dist_with_dif_ori_array.push_back(nearest_point_index);
		// //find the nearest orientation
		// int nearest_point_index_;
		// double nearest_angle_error = 10;
		// for(int i=0; i<nearest_dist_with_dif_ori_array.size(); ++i)
		// {
		// 	double temp_angle_error = fabs(temp_path[nearest_dist_with_dif_ori_array[i]].point.z - robot_pos.z);
		// 	if(temp_angle_error < nearest_angle_error)
		// 	{
		// 		nearest_point_index_ = nearest_dist_with_dif_ori_array[i];
		// 		nearest_angle_error = temp_angle_error;
		// 	}
		// }
		// //get the following point
		// TimePoint following_point;
		// //final_goal = false;
		// if(nearest_point_index_ + 10 < path_size)
		// {
		// 	following_point = temp_path[nearest_point_index_ + 10];
		// }
		// else
		// {
		// 	following_point = temp_path.back();
		// 	final_goal = true;
		// }


		//get the following point
		if(temp_path.size() == 1)
		{
			following_point = temp_path.back();
		}
		//calculate the velocity
		double v_x_last, v_y_last, v_a_last;
		double v_x, v_y, v_a;
		double e_x, e_y, e_a;

		v_x_last = velocity.linear.x;
		v_y_last = velocity.linear.y;
		v_a_last = velocity.angular.z;

		//tf transform point in the /map to the point in the /base_link

		tf::Transform tf_base_in_map, tf_point_in_map, tf_point_in_base;

        tf_base_in_map.setOrigin( tf::Vector3(robot_pos.x, robot_pos.y, 0.0) );
        tf::Quaternion q_tf_base_in_map;
        q_tf_base_in_map.setRPY(0, 0, robot_pos.z);
        tf_base_in_map.setRotation(q_tf_base_in_map);

        tf_point_in_map.setOrigin( tf::Vector3(following_point.point.x, following_point.point.y, 0.0) );
        tf::Quaternion q_tf_point_in_map;
        q_tf_point_in_map.setRPY(0, 0, following_point.point.z);
        tf_point_in_map.setRotation(q_tf_point_in_map);

        tf_point_in_base = tf_base_in_map.inverse()*tf_point_in_map;


        std::cout<<following_point.point.x<<"  "<<following_point.point.y<<" "<<following_point.point.z<<std::endl;

        // std::cout<<" x: "<<tf_point_in_base.getOrigin().x()<<"y: "<<tf_point_in_base.getOrigin().y()<<
        // "theta"<<tf::getYaw(tf_point_in_base.getRotation())<<std::endl; 



		e_x = tf_point_in_base.getOrigin().x();
		e_y = tf_point_in_base.getOrigin().y();

		std::cout<<e_x<<e_y<<std::endl;
		if(!following_point.move_state)
		{
			//e_a = tf::getYaw(tf_point_in_base.getRotation());
			e_a = following_point.point.z - robot_pos.z;
		}
		else
		{
			e_a = atan2(e_y, e_x);
		}
		if(e_a < 0 && fabs(e_a) > M_PI) {e_a = 2*M_PI + e_a;}
		if(e_a > 0 && fabs(e_a) > M_PI) {e_a = e_a - 2*M_PI;}

		//rotate
		if(!following_point.move_state)
		{
			if(fabs(e_a) < 0.5)
			{
				close_goal = true;
				following_point.is_arrival = true;
				ROS_INFO("ROBOT %a following_point.is_arrival", following_point.is_arrival);
			}
			if(fabs(e_a) < 0.2) 
			{
				//close_goal = false;
				following_point = temp_path.back();
			}
			v_x = 0;
			v_y = 0;
			v_a = e_a/fabs(e_a)*max_v_a;
			// v_a = fabs(v_a - v_a_last)*100 > acc_a ?
			// (v_a_last + acc_a*0.01*(v_a > v_a_last ? 1:-1)):v_a;//acceleration limit
			// v_a = fabs(v_a) > max_v_a ? (v_a/fabs(v_a)*max_v_a):v_a;  //velocity limit
			if(fabs(e_a) <= 0.5)
			{
				v_a = e_a;
				if(following_point.final_goal && fabs(e_a) <= 0.2)
				{
					v_x = e_x;
					v_y = e_y;
				}

				if(hypot(fabs(e_x), fabs(e_y)) < 0.01 && fabs(e_a) <= 0.05 && following_point.final_goal)
				{
					v_x = 0;
					v_y = 0;
					v_a = 0;
				}

			}

			//acceleration limit
			v_x = fabs(v_x - v_x_last)/(run_time - last_circle_run_time) > acc_x ?
			(v_x_last + acc_x * (run_time - last_circle_run_time)*(v_x > v_x_last ? 1:-1)):v_x;

			v_y = fabs(v_y - v_y_last)/(run_time - last_circle_run_time) > acc_y ?
			(v_y_last + acc_y * (run_time - last_circle_run_time)*(v_y > v_y_last ? 1:-1)):v_y;

			v_a = fabs(v_a - v_a_last)/(run_time - last_circle_run_time) > acc_a ?
			(v_a_last + acc_a * (run_time - last_circle_run_time)*(v_a > v_a_last ? 1:-1)):v_a;



			std::cout<<"rotate"<<std::endl;
		}
		//move
		else
		{


			if(hypot(fabs(e_x), fabs(e_y)) < 0.5)// && fabs(e_a) < 0.3) 
			{
				close_goal = true;
				following_point.is_arrival = true;
			}
			if(hypot(fabs(e_x), fabs(e_y)) < 0.1 )//&& fabs(e_a) < 0.3) 
			{
				//close_goal = false;
				following_point = temp_path.back();
			}

			v_x = max_v_x;
			v_x = v_x > max_v_x ? max_v_x:v_x;   //velocity limit
			v_x = fabs(v_x - v_x_last)*100 > acc_x ? 
			(v_x_last+ acc_x*0.01*(v_x > v_x_last?1:-1)):v_x;//acceleration limit

			v_y = 0;

			v_a = e_a;
			v_a = fabs(v_a) > max_v_a ? (v_a/fabs(v_a)*max_v_a):v_a;  //velocity limit

			v_x = fabs(v_a) > 0.3 ? 0:v_x;  //just rotate

			if(hypot(fabs(e_x), fabs(e_y)) < 0.3)// && fabs(e_a) < 0.3)
			{
				v_x = e_x/2;
				v_y = e_y;
				v_a = e_a;
				if(hypot(fabs(e_x), fabs(e_y)) < 0.1)
					v_a = following_point.point.z - robot_pos.z;
			}



			//acceleration limit
			v_x = fabs(v_x - v_x_last)/(run_time - last_circle_run_time) > acc_x ?
			(v_x_last + acc_x * (run_time - last_circle_run_time)*(v_x > v_x_last ? 1:-1)):v_x;

			v_y = fabs(v_y - v_y_last)/(run_time - last_circle_run_time) > acc_y ?
			(v_y_last + acc_y * (run_time - last_circle_run_time)*(v_y > v_y_last ? 1:-1)):v_y;

			v_a = fabs(v_a - v_a_last)/(run_time - last_circle_run_time) > acc_a ?
			(v_a_last + acc_a * (run_time - last_circle_run_time)*(v_a > v_a_last ? 1:-1)):v_a;


			std::cout<<"move"<<std::endl;
		}

		// if(col_info.intensities[0] == 1 && col_info.ranges[0] <= 0.7)
		// {
		// 	v_x = 0;
		// 	v_y = 0;
		// 	v_a = 0;
		// }
		velocity.linear.x = v_x;
		velocity.linear.y = v_y;
		velocity.angular.z = v_a;
		// std::cout<<"temp_path.size(): "<<temp_path.size()<<std::endl;
		
		// std::cout<<"path[0].point.x: "<<path[0].point.x<<"path[1].point.x: "<<path[1].point.x<<std::endl;
		cmd_pub.publish(velocity);

		last_circle_run_time = run_time;

		ROS_INFO("following_point: %d", robot_id);
		std::cout<<"robot "<<robot_id<<" following_point"<<std::endl;
		std::cout<<following_point.point<<"  "<<following_point.is_arrival<<std::endl;
		std::cout<<"e_x: "<<e_x<<"e_y: "<<e_y<<"e_a: "<<e_a<<std::endl<<std::endl;
	}
}


boost::thread RecvPathPointMove::thread_exe()
{
	return boost::thread(&RecvPathPointMove::execute, this);
}