#include "distributed_reserve_area.h"
#include <signal.h>

distributed_reserve_area* test_1;
distributed_reserve_area* test_2;
distributed_reserve_area* test_3;
distributed_reserve_area* test_4;

boost::thread th_test_1;
boost::thread th_test_2;
boost::thread th_test_3;
boost::thread th_test_4;
void initial_map(int map_[], int weight_[][4], geometry_msgs::Point loc_[], int column);
void shutdown(int sig)
{
    ros::Time start_time = ros::Time::now();
    ros::Duration dur;
    while(1)
    {


        th_test_1.interrupt();
        th_test_2.interrupt();
        th_test_3.interrupt();
        th_test_4.interrupt();

        test_1->shutdown();
        test_2->shutdown();
        test_3->shutdown();
        test_4->shutdown();
        dur = ros::Time::now() - start_time;
        if(dur.sec > 2)
            break;
    }

    ros::Duration(1).sleep();
    ROS_INFO("END ..........");
    ros::shutdown();
}

int main(int argc, char** argv)
{
	/* code */
	ros::init(argc, argv, "distributed_reserve_area");
	ros::NodeHandle node;


	const int row = 3;
	const int column = 5;
	int map[row*column];
	int weight[row*column][4] = {0};
	geometry_msgs::Point loc[row*column];

    signal(SIGINT, shutdown);

	initial_map(map, weight, loc, column);
	test_1 = new distributed_reserve_area(node, 1, row, column, map, weight, loc);
	test_2 = new distributed_reserve_area(node, 2, row, column, map, weight, loc);
    test_3 = new distributed_reserve_area(node, 3, row, column, map, weight, loc);
    test_4 = new distributed_reserve_area(node, 4, row, column, map, weight, loc);

	th_test_1 = test_1->thread_exe();
	th_test_1.detach();

	th_test_2 = test_2->thread_exe();
	th_test_2.detach();

    th_test_3 = test_3->thread_exe();
    th_test_3.detach();

    th_test_4 = test_4->thread_exe();
    th_test_4.join();

	std::cout<<"success"<<std::endl;

	// ROS_INFO("output map info");
	// for(int i=0; i<row; i++)
	// {
	// 	for(int j=0; j<column; j++)
	// 		std::cout<<map[i*column+j];
	// 	std::cout<<std::endl;
	// }

	// ROS_INFO("output weight info");
	// for(int i=0; i<row*column; i++)
	// {
	// 	for(int j=0; j<4; j++)
	// 		std::cout<<weight[i][j];
	// 	std::cout<<std::endl;
	// }

	// ROS_INFO("output loc info");
	// for(int i=0; i<row*column; i++)
	// {
	// 	std::cout<<loc[i].x<<" "<<loc[i].y<<std::endl;
	// }

	return 0;
}



void initial_map(int map_[], int weight_[][4], geometry_msgs::Point loc_[], int column)
{
	std::ifstream infile_map;
	infile_map.open("/home/hxq/agv_ws/src/agv_udp/map/map.txt", std::ios_base::in);
	if(!infile_map)
		ROS_INFO("can not open map file");
	else
	{
		int* p = &map_[0];
		int t;
		while(infile_map>>t)
		{
			*p = t;
			p++;
		}
		infile_map.close();
	}

	//read the weight.txt, and change the weight array
    char buf[100];
    std::string message;
    std::ifstream infile_weight;
    infile_weight.open("/home/hxq/agv_ws/src/agv_udp/map/weight.txt", std::ios_base::in);
    if(!infile_weight)
    {
        ROS_INFO("can not open weight file");
    }
    else
    {
        while(infile_weight.good() &&  !infile_weight.eof())
        {
            infile_weight.getline(buf, 100);
            message = buf;
            int start_x, start_y, end_x, end_y;
            sscanf(message.c_str(), "%d%d%d%d", &start_x, &start_y, &end_x, &end_y);
           // cout<<start_x<<"\t"<<start_y<<"\t"<<end_x<<"\t"<<end_y<<endl;
            if(start_y==end_y)
            {
                if(start_x>end_x)  //arrow up
                {
                    for(int i=start_x;i>end_x;i--)
                    {
                        weight_[i*column+start_y][0] = 1;
                    }
                }
                else               //arrow down
                {
                    for(int i=start_x;i<end_x;i++)
                    {
                        weight_[i*column+start_y][1] = 1;
                    }
                }
            }

            if(start_x==end_x)
            {
                if(start_y>end_y) //arrow left
                {
                    for(int i=start_y;i>end_y;i--)
                    {
                        weight_[start_x*column+i][2] = 1;
                    }
                }
                else             //arrow right
                {
                    for(int i=start_y;i<end_y;i++)
                    {
                        weight_[start_x*column+i][3] = 1;
                    }
                }
            }
        }
    }
    infile_weight.close();


    //read the location of path point
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
            loc_[count].x = x_coord;
            loc_[count].y = y_coord;
            count++;
        }
    }
    infile_loc.close();



}