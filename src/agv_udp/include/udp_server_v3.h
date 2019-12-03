//ros
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Point.h"
#include "sensor_msgs/LaserScan.h"
#include <sstream>
#include <boost/thread/thread.hpp>
#include <thread>
#include <tf/transform_broadcaster.h>
#include <turtlesim/Pose.h>

//udp
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <arpa/inet.h>
#include <sstream>
class UdpServer
{
public:
UdpServer(ros::NodeHandle &nh, uint16_t server_port, int robot_id);//构造函数
~UdpServer();
void execute();

//ros
ros::Publisher pos_pub, col_pub;
ros::Subscriber carVelSub;
geometry_msgs::Twist::ConstPtr carVel;
int zeroCount;
short lastvx, lastvy, lastva;
short vx, vy, va;
double velx, vely, vela;
ros::Time carVelTime;
int ACCEPTTIME;
int COMMAND_SIZE;
int MAXZERONUM;
int robot_id;


void carVelCallback(const geometry_msgs::Twist::ConstPtr& msg);
void getCarVel(geometry_msgs::Twist& velocity);
void velFilter(short &vx, short &vy, short &va, int &count, short &lastvx, short &lastvy, short &lastva);
void genCmd(char* cmdData, short vx, short vy, short va);
void receive_data();
boost::thread thread_exe();
//udp
int sock_fd;
struct sockaddr_in addr_serv;
int len;
int recv_num;
int send_num;
char send_buf[1024];
char recv_buf[1024];
struct sockaddr_in addr_client;
boost::function0<void> f_read, f_send;
bool rec_data_flag;



};
