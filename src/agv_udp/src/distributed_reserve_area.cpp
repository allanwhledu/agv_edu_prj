#include "distributed_reserve_area.h"

distributed_reserve_area::distributed_reserve_area(
	ros::NodeHandle &nh, int robot_id_, 
	const int x, const int y,
	int input_map[], int input_weight[][4], 
	geometry_msgs::Point input_loc[]):map_row(x), map_column(y)
{
	robot_id = robot_id_;
	std::stringstream pos_topic, vel_topic, col_topic, r_a_topic;
	pos_topic<<"/robot"<<robot_id<<"/robot_pos";

	vel_topic<<"/robot"<<robot_id<<"/cmd_vel";

	col_topic<<"/robot"<<robot_id<<"/col_dis";

	r_a_topic<<"/robot"<<robot_id<<"/reserve_area";
	//subscriber
	pos_sub = nh.subscribe(pos_topic.str(), 1, &distributed_reserve_area::pose_cb, this);
    center_cmd_sub = nh.subscribe("/center_command", 1,&distributed_reserve_area::ccmd_cb, this);
    col_sub = nh.subscribe(col_topic.str(), 1, &distributed_reserve_area::col_cb, this);
    //publisher
    cmd_vel_pub = nh.advertise<geometry_msgs::Twist>(vel_topic.str(),100);
    reserve_area_pub = nh.advertise<agv_udp::ReserveArea>(r_a_topic.str(), 100);
    //client
    assign_client = nh.serviceClient<agv_udp::Replan>("/assignment_center");

    acc_x = 5.0;
    acc_y = 1.0;
    acc_a = 5.0;

    max_v_x = 0.2;
    max_v_y = 0.1;
    max_v_a = 0.3;

    run_time = 0.0;

    receive_cmd_flag = false;
    replan_flag = false;
    wait_topic_flag = false;

    //initial map
    for(int i=0; i<map_row*map_column; ++i)
	{
		plan_map[i] = input_map[i];
		location[i] = input_loc[i];
		for(int j=0; j<4; ++j)
			weight[i][j] = input_weight[i][j];
	}
	//wait until the receive the informaion from topic
	while(!wait_topic_flag)
	{
		ros::spinOnce();
		sleep(1);
	}

}
distributed_reserve_area::~distributed_reserve_area()
{

}

void distributed_reserve_area::shutdown()
{

		cmd_vel_pub.publish(geometry_msgs::Twist());
    
}

void distributed_reserve_area::single_robot_path_planning(int goal_x, int goal_y)
{
    //get the current position of the r_idx_th robot
    int start_index;
    int start_x, start_y;
	start_index = coords_2_index(robot_pos);
	start_x = start_index / map_column;    //row_index
	start_y = start_index % map_column;
	if(start_x != goal_x || start_y != goal_y)
	{
		// std::cout<<"start point"<<robot_pos.x<<" "<<robot_pos.y<<std::endl;
		// std::cout<<"start index"<<start_x<<" "<<start_y<<std::endl;

	    CAstar* plan = new CAstar(plan_map, weight, map_row, map_column);
	    CPoint* start = new CPoint(start_x, start_y);
	    CPoint* end = new CPoint(goal_x, goal_y);
	    CPoint* parent = plan->find_path(start, end);
	    path.clear();
	    while(parent !=NULL)
	    {
	        path.push_back(parent->X*map_column+parent->Y);
	        parent = parent->m_parent_point;
	    }
	    std::reverse(path.begin(), path.end());
	    ROS_INFO("path size%d", path.size());
	    for(int i=0; i<path.size(); i++)
	    {
	        ROS_INFO("%d", path[i]);
	    }
	}

}

geometry_msgs::Point distributed_reserve_area::index_2_coords(int index)
{
	return location[index];
}


int distributed_reserve_area::coords_2_index(geometry_msgs::Point coords)
{
	 std::map<int, geometry_msgs::Point>::iterator iter;
	 double min_dis = 1000;
	 int min_index;
	for(iter = location.begin(); iter != location.end(); iter++)
	{
		geometry_msgs::Point temp_point = iter->second;
		if(hypot(fabs(temp_point.x - robot_pos.x), fabs(temp_point.y - robot_pos.y))  < min_dis)
		{
			min_index = iter->first;
			min_dis = hypot(fabs(temp_point.x - robot_pos.x), fabs(temp_point.y - robot_pos.y));
		}
	}
	std::cout<<"min_dist"<<min_dis<<std::endl;
	return min_index;
}


bool distributed_reserve_area::robot_in_area(int point_index)
{
	geometry_msgs::Point temp_point = index_2_coords(point_index);
	double temp_dist = hypot(fabs(temp_point.y - robot_pos.y), fabs(temp_point.x - robot_pos.x));
	if(temp_dist < 0.2)
		return true;
	else
		return false;
}

inline void distributed_reserve_area::reserve_area_publish(int count)
{

	if(count < path.size() - 1)
	{
		r_a.first_area = path[count];
        r_a.second_area = path[count + 1];
        reserve_area_pub.publish(r_a);
	}
	else
	{
        r_a.first_area = path[count];
        r_a.second_area = path[count];
        reserve_area_pub.publish(r_a);
	}
}


void distributed_reserve_area::ccmd_cb(const agv_udp::CenterCmd::ConstPtr& center)
{
	std::cout<<"center_cmd"<<std::endl;
	receive_cmd_flag = true;
	center_cmd = *center;
}
void distributed_reserve_area::pose_cb(const geometry_msgs::Point::ConstPtr& p)
{
	std::cout<<"robot_pos"<<std::endl;
	robot_pos = *p;
	wait_topic_flag = true;
}
void distributed_reserve_area::col_cb(const sensor_msgs::LaserScan::ConstPtr& col)
{
	std::cout<<"col_cb"<<std::endl;
	col_info = *col;
}
void distributed_reserve_area::request_assignment()
{
	//std::cout<<"hello"<<std::endl;
	if(assign_client.call(srv))
    {
        ROS_INFO("replan");
        //route.clear();
        std::cout<<srv.response.new_goal<<" "<<srv.response.new_goal/map_column<<" "<<srv.response.new_goal%map_column<<std::endl;
        single_robot_path_planning(srv.response.new_goal/map_column, srv.response.new_goal%map_column);
    }
    else
    {
        ROS_INFO("request replan failed");
    }
    replan_flag = false;
}

void distributed_reserve_area::execute()
{
	int path_count = 0;
	ros::Rate rate(100);
	last_circle_run_time = 0;
	run_time = 0;
	int display_count = 0;
	while(ros::ok())
	{
		display_count++;
		if(display_count > 100)
			display_count = display_count%100;
		rate.sleep();
		ros::spinOnce();
		ros::Duration temp_dur = ros::Time::now() - start_time;
		run_time = temp_dur.toSec();

		if(path.empty())
		{
			srv.request.replan = true;
			srv.request.robot_index = robot_id;
			request_assignment();
			// for(int i=0;i<path.size();i++)
			// 	std::cout<<path[i]<<" ";
			// sleep(1000);
			path_count = 0;
			continue;
		}
		//publish the request
		reserve_area_publish(path_count);
		//ROS_INFO("i have finish publish reserve area");
		//receive the command from the center, update the receive area
		if(receive_cmd_flag && center_cmd.reserve_area_first[robot_id-1]!=10000)
		{
			receive_cmd_flag = false;
			r_a.first_area = center_cmd.reserve_area_first[robot_id-1];
            r_a.second_area = center_cmd.reserve_area_second[robot_id-1];
            if(display_count > 98)
            {
            	ROS_INFO("fir:%d", r_a.first_area);
		        ROS_INFO("sec:%d", r_a.second_area);
		        ROS_INFO("routesize:%d", path.size());
		        ROS_INFO("pathcount:%d", path_count);
		        ROS_INFO("the current position:%.3f %.3f", robot_pos.x, robot_pos.y);

            }
            //Calcu the execute path 
            path_coords.clear();
        	geometry_msgs::Point pre_point, cur_point;
        	if(path_count == 0)
        		pre_point = index_2_coords(path[0]);
        	else
        		pre_point = index_2_coords(path[path_count-1]);
        	cur_point = index_2_coords(path[path_count]);
        	if(pre_point.x != cur_point.x || pre_point.y != cur_point.y)
			{
				for(int i=0; i<50;++i)
	        	{
	        		geometry_msgs::Point temp_point;
	        		temp_point.x = pre_point.x + (cur_point.x - pre_point.x)/50*i;
	        		temp_point.y = pre_point.y + (cur_point.y - pre_point.y)/50*i;
	        		temp_point.z = atan2(cur_point.y - pre_point.y, cur_point.x - pre_point.x);
	        		path_coords.push_back(temp_point);
	        	}
		    }
        	if(r_a.first_area != r_a.second_area) 
        	{
        		geometry_msgs::Point pro_point = index_2_coords(r_a.second_area);
        		for(int i=0; i<50;++i)
	        	{
	        		geometry_msgs::Point temp_point;
	        		temp_point.x = cur_point.x + (pro_point.x - cur_point.x)/50*i;
	        		temp_point.y = cur_point.y + (pro_point.y - cur_point.y)/50*i;
	        		temp_point.z = atan2(pro_point.y - cur_point.y, pro_point.x - cur_point.x);
	        		path_coords.push_back(temp_point);
	        	}
        	}
        	//Follow the path_coords
        	if(path_coords.empty())
        		continue;
    		follow_path();
        	
    		if(path_count< path.size() - 1)
    		{
	    		geometry_msgs::Point fir_point, sec_point;
	        	fir_point = index_2_coords(path[path_count]);
	        	sec_point = index_2_coords(path[path_count+1]);
	        	double fir_dis, sec_dis;
	        	fir_dis = hypot(fabs(fir_point.x - robot_pos.x), fabs(fir_point.y - robot_pos.y));
	        	sec_dis = hypot(fabs(sec_point.x - robot_pos.x), fabs(sec_point.y - robot_pos.y));
	        	if(fir_dis > sec_dis)
	        		path_count++;
    		}


        	if(robot_in_area(path[path_count]) && path_count == path.size() - 1 && !replan_flag)
        	{

    			srv.request.replan = true;
				srv.request.robot_index = robot_id;
				cmd_vel_pub.publish(geometry_msgs::Twist());
				boost::thread thrd(&distributed_reserve_area::request_assignment, this);
				//request_assignment(assign_client);
				replan_flag = true;
				path_count = 0;
				continue;
        	}
		}
		else
		{
			cmd_vel_pub.publish(geometry_msgs::Twist());
		}
		last_circle_run_time = run_time;
	}
}

boost::thread distributed_reserve_area::thread_exe()
{
	return boost::thread(&distributed_reserve_area::execute, this);
}

void distributed_reserve_area::follow_path()
{
	//find the nearest point in the path 
	int min_index;
	double min_dist = 100;
	for(int i=0; i<path_coords.size(); i++)
	{
		double temp_dist = hypot(fabs(robot_pos.x - path_coords[i].x), fabs(robot_pos.y - path_coords[i].y));
		if(temp_dist < min_dist)
		{
			min_dist = temp_dist;
			min_index = i;
		}
	}
	//get the following point
	bool final = false;
	geometry_msgs::Point following_point;
	if(min_index + 20 >= path_coords.size() - 1)
	{
		following_point = path_coords.back();
		final = true;
	}
	else
		following_point = path_coords[min_index + 20];
	ROS_INFO("following_point:%lf %lf", following_point.x, following_point.y);
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

    tf_point_in_map.setOrigin( tf::Vector3(following_point.x, following_point.y, 0.0) );
    tf::Quaternion q_tf_point_in_map;
    q_tf_point_in_map.setRPY(0, 0, following_point.z);
    tf_point_in_map.setRotation(q_tf_point_in_map);

    tf_point_in_base = tf_base_in_map.inverse()*tf_point_in_map;


    std::cout<<following_point.x<<" "<<following_point.y<<" "<<following_point.z<<std::endl;

    // std::cout<<" x: "<<tf_point_in_base.getOrigin().x()<<"y: "<<tf_point_in_base.getOrigin().y()<<
    // "theta"<<tf::getYaw(tf_point_in_base.getRotation())<<std::endl; 

	e_x = tf_point_in_base.getOrigin().x();
	e_y = tf_point_in_base.getOrigin().y();
	e_a = atan2(following_point.y - robot_pos.y, following_point.x - robot_pos.x) - robot_pos.z;

	ROS_INFO("e_x e_y  e_a:%lf %lf %lf", e_x, e_y, e_a);

	if(e_a < 0 && fabs(e_a) > M_PI) {e_a = 2*M_PI + e_a;}
	if(e_a > 0 && fabs(e_a) > M_PI) {e_a = e_a - 2*M_PI;}

	v_x = max_v_x;
	if(hypot(fabs(e_x), fabs(e_y)) < 0.1)
		v_x  = e_x;
	v_x = v_x > max_v_x ? max_v_x:v_x;   //velocity limit

	v_y = 0;

	v_a = e_a;
	v_a = fabs(v_a) > max_v_a ? (v_a/fabs(v_a)*max_v_a):v_a;  //velocity limit

	//v_x = fabs(v_a) > 0.5 ? 0:v_x;  //just rotate
	if(fabs(e_a) > 1.5)
	{
		if(fabs(e_x) > 0.01)
			v_x = 0.01;
	}
	else if(fabs(e_a) > 0.5)
	{
		if(fabs(e_x) > 0.03)
			v_x = 0.03;
	}
	else
	{
		v_x = v_x;
	}

	if(final && hypot(fabs(e_x), fabs(e_y)) < 0.1)
	{
		v_x = 0;
		v_y = 0;
		v_a = following_point.z - robot_pos.z;
	}

	v_x = fabs(v_x - v_x_last)/(run_time - last_circle_run_time) > acc_x ?
	(v_x_last + acc_x * (run_time - last_circle_run_time)*(v_x > v_x_last ? 1:-1)):v_x;

	v_y = fabs(v_y - v_y_last)/(run_time - last_circle_run_time) > acc_y ?
	(v_y_last + acc_y * (run_time - last_circle_run_time)*(v_y > v_y_last ? 1:-1)):v_y;

	v_a = fabs(v_a - v_a_last)/(run_time - last_circle_run_time) > acc_a ?
	(v_a_last + acc_a * (run_time - last_circle_run_time)*(v_a > v_a_last ? 1:-1)):v_a;

	if(col_info.intensities[0] == 1 && col_info.ranges[0] <= 0.7)
	{
		v_x = 0;
		v_y = 0;
		v_a = 0;
	}

	velocity.linear.x = v_x;
	velocity.linear.y = v_y;
	velocity.angular.z = v_a;

	ROS_INFO("v_x v_y  v_a:%lf %lf %lf", v_x, v_y, v_a);

	cmd_vel_pub.publish(velocity);
}