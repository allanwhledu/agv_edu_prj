#include "simulation_server.h"

int main(int argc, char** argv)
{
ros::init(argc, argv, "simulation_server_v3");
ros::NodeHandle node;
//robot	1
simulation_server* server = new simulation_server(node, 1);
boost::thread th_server = server->thread_exe();
th_server.detach();


//robot 2
simulation_server* server_ = new simulation_server(node, 2);
boost::thread th_server_ = server_->thread_exe();
th_server_.detach();

//robot 3
simulation_server* server_3 = new simulation_server(node, 3);
boost::thread th_server_3 = server_3->thread_exe();
th_server_3.detach();

simulation_server* server_4 = new simulation_server(node, 4);
boost::thread th_server_4 = server_4->thread_exe();
th_server_4.join();


return 0;
}