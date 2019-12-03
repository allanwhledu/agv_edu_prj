#include "udp_server_v3.h"

int main(int argc, char** argv)
{
ros::init(argc, argv, "udp_server_v3");
ros::NodeHandle node;
//robot	1
UdpServer* server = new UdpServer(node, 8001, 1);
boost::thread th_server = server->thread_exe();
th_server.join();


// //robot 2
// UdpServer* server_ = new UdpServer(node, 8002, 2);
// boost::thread th_server_ = server_->thread_exe();
// th_server_.detach();

// //robot 3
// UdpServer* server_3 = new UdpServer(node, 8003, 3);
// boost::thread th_server_3 = server_3->thread_exe();
// th_server_3.detach();

// //robot 4
// UdpServer* server_4 = new UdpServer(node, 8004, 4);
// boost::thread th_server_4 = server_4->thread_exe();
// th_server_4.join();


return 0;
}
