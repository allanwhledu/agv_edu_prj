#include "receive_path_point_move.h"
const int robot_num = 4;
TimePoint path_point[15];
void get_point()
{
    //read the location of path point
    char buf[100];
    std::string message;
    std::ifstream infile_loc;
    infile_loc.open("/home/hxq/agv_ws/src/agv_udp/map/location.txt", std::ios_base::in);
    if(!infile_loc)
    {
        ROS_INFO("can not open location file");
    }
    else
    {
    	int count = 0;
        while(infile_loc.good() &&  !infile_loc.eof())
        {
            infile_loc.getline(buf, 100);
            message = buf;
            double x_coord, y_coord;
            sscanf(message.c_str(), "%lf%lf", &x_coord, &y_coord);
            path_point[count].point.x = x_coord;
            path_point[count].point.y = y_coord;
            count++;
        }
    }
    infile_loc.close();

}
int main(int argc, char** argv)
{
	ros::init(argc, argv, "receive_path_point_move");
	ros::NodeHandle node;
	//robot	
	RecvPathPointMove* robot[robot_num];
	boost::thread robot_th[robot_num];
	for(int i=0; i<robot_num; i++)
	{
		robot[i] = new RecvPathPointMove(node, i+1); 

	}
	ROS_INFO("1111");


	//point in world
	get_point();
	//read path from txt
	std::vector<std::vector<int> > path_index(robot_num);
	std::fstream infile_path;
    infile_path.open("/home/hxq/agv_ws/src/agv_udp/map/path.txt",std::ios_base::in);
    int a;
    int count_read_file = 0;
    while(infile_path >> a)
    {
    	count_read_file++;
    	if(count_read_file % robot_num == 0)
    		path_index[robot_num - 1].push_back(a);
    	else
    		path_index[count_read_file % robot_num - 1].push_back(a);
    }

    //path_index[0].push_back(0);path_index[0].push_back(1);
    for(int i=0; i<path_index[0].size(); i++)
	{
		for(int j=0; j<robot_num;j++)
			std::cout<<j<<" "<<i<<" "<<path_index[j][i]<<std::endl;
	}

	// path_index[0].push_back(2);path_index[0].push_back(1);//path_index[0].push_back(2);
	// path_index[1].push_back(1);path_index[1].push_back(0);//path_index[1].push_back(1);
	std::vector<std::vector<TimePoint> > path_coor(robot_num), path_coor_exec(robot_num);
	int path_len = path_index[0].size();
	for(int i=0; i<path_len; i++)
	{
		for(int j=0; j<robot_num; j++)
		{
			if(i==0)
			{
				TimePoint cur_point, pro_point;
				cur_point = path_point[path_index[j][i]];
				pro_point = path_point[path_index[j][i+1]];

				cur_point.point.z = atan2(pro_point.point.y - cur_point.point.y, pro_point.point.x - cur_point.point.x);
				if(i == path_len - 1) //current point is des
				{
					cur_point.final_goal = true;
				}
				path_coor[j].push_back(cur_point);
			}
			else
			{
				TimePoint pre_point, cur_point;
				pre_point = path_point[path_index[j][i-1]];
				cur_point = path_point[path_index[j][i]];

				cur_point.point.z = atan2(cur_point.point.y - pre_point.point.y, cur_point.point.x - pre_point.point.x);
				if(i == path_len - 1) //current point is des
				{
					cur_point.final_goal = true;
				}
				path_coor[j].push_back(cur_point);
			}
			std::cout<<j<<" "<<i<<" "<<path_coor[j][i].point.x<<" "<<path_coor[j][i].point.y<<" "<<path_coor[j][i].point.z<<std::endl;
		}
	}
	//handle the path point with different position and different orientation
	for(int i=0; i<path_len - 1 ; i++)
	{
		bool insert = false;
		TimePoint insert_point[robot_num];
		for(int j=0; j<robot_num; j++)
		{
			double ori_first, ori_sec;
			ori_first = path_coor[j][i].point.z;
			ori_sec = atan2(path_coor[j][i+1].point.y - path_coor[j][i].point.y, path_coor[j][i+1].point.x - path_coor[j][i].point.x);
			std::cout<<"ori_first: "<<ori_first<<" ori_sec: "<<ori_sec<<std::endl;
			if(fabs(ori_first - ori_sec) >= 0.1)   //point with different position and different orientation
			{
				insert = true;
				insert_point[j].point.x = path_coor[j][i].point.x;
				insert_point[j].point.y = path_coor[j][i].point.y;
				insert_point[j].point.z = ori_sec;
				std::cout<<" hello"<<std::endl;
			}
			else
			{
				insert_point[j] = path_coor[j][i];
			}

			path_coor_exec[j].push_back(path_coor[j][i]);
			std::cout<<" hello world"<<std::endl;
		}
		if(insert)
		{
			for(int k=0; k<robot_num; k++)
			{
				path_coor_exec[k].push_back(insert_point[k]);
				std::cout<<insert_point[k].point.x<<" "<<insert_point[k].point.y<<" "<<insert_point[k].point.z<<std::endl;
			}
		}
		//add the final point
		if(i == path_len - 2)
		{
			for(int k=0; k<robot_num; k++)
			{
				path_coor_exec[k].push_back(path_coor[k].back());
				path_coor_exec[k].push_back(path_coor[k].back());
			}
		}
	}

	path_len = path_coor_exec[0].size();
	for(int i=0; i<path_coor_exec[0].size(); i++)
	{
		for(int j=0; j<robot_num;j++)
			std::cout<<j<<" "<<i<<" "<<path_coor_exec[j][i].point.x<<" "<<path_coor_exec[j][i].point.y<<" "<<path_coor_exec[j][i].point.z<<std::endl;
	}


	bool add_point[50] = {false};
	bool legal_start = true;
	for(int i=0; i<robot_num; i++)
	{
		if(!robot[i]->modify_path(path_coor_exec[i][0]))
			legal_start = false;
	}
	if(legal_start)
	{
		add_point[0] = true;
		for(int i=0; i<robot_num; i++)
		{
			robot_th[i] = robot[i]->thread_exe();	
			robot_th[i].detach();
		}
	}

	int count = 0;

	while(ros::ok())
	{
		if(count > path_len - 2)
			continue;
		int pub_next_point = 0;
		for(int i=0; i<robot_num; i++)
		{
			if(robot[i]->following_point.is_arrival && !add_point[count+1] && 
				robot[i]->following_point.point.x == path_coor_exec[i][count].point.x &&
				robot[i]->following_point.point.y == path_coor_exec[i][count].point.y &&
				robot[i]->following_point.point.z == path_coor_exec[i][count].point.z)
				pub_next_point++;
		}

		if(pub_next_point == robot_num)
		{
			for(int i=0; i<robot_num; i++)
			{
				robot[i]->modify_path(path_coor_exec[i][count+1]);
			}
			count++;
			add_point[count] = true;
		}
		ROS_INFO("COUNT :%d, pub_next_point: %d", count, pub_next_point);
	}
	// while(ros::ok())
	// {
	// 	if(count > path_len - 2)
	// 		continue;
	// 	if(robot_1->close_goal && !add_point[count+1] &&  //close to temp goal, next point not in the path
	// 		robot_1->following_point.point.x == path_point[count].point.x&&
	// 		robot_1->following_point.point.y == path_point[count].point.y&&  //make sure following point is path_point[count]
	// 		robot_1->following_point.point.z == path_point[count].point.z) 
	// 	{
	// 		if(robot_1->modify_path(path_point[count+1]))
	// 		{
	// 			count++;
	// 			add_point[count] = true;
	// 		}
				
	// 	}

	// }

	return 0;
}