/*Author:huangxiaqnun  2018.12.27*/

//ros
#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Point.h"
#include <sstream>
#include <boost/thread/thread.hpp>
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

#define FREQUENCY 10
#define COMMAND_SIZE 11
#define MAXZERONUM 5
#define ROBOTSIZE 4
#define SERV_PORT   7838

class DataUpdater
{
public:
    DataUpdater(ros::NodeHandle &nh);
    ~DataUpdater();
    geometry_msgs::Twist getCarVel(int idx);
private:
    // callback functions
    void carVelCallback(const geometry_msgs::Twist::ConstPtr& msg, int idx);

    // subscribers
    ros::Subscriber carVelSub[ROBOTSIZE];

    // data
    geometry_msgs::Twist carVel[ROBOTSIZE]; //boost::shared_ptr<const geometry_msgs::Twist_<std::allocator<void> > >
    // the latest time that recieve a message
    ros::Time carVelTime[ROBOTSIZE];
    int ACCEPTTIME;
};

DataUpdater::DataUpdater(ros::NodeHandle &nh)
{
    for(int i=0; i<ROBOTSIZE; i++)
    {
        std::stringstream topic;
        topic<<"/robot"<<i+1<<"/cmd_vel";
        carVelSub[i] = nh.subscribe<geometry_msgs::Twist>(topic.str(), 1, boost::bind(&DataUpdater::carVelCallback,this, _1, i));
    }
    ACCEPTTIME = 500000000;
}

DataUpdater::~DataUpdater()
{
}

void DataUpdater::carVelCallback(const geometry_msgs::Twist::ConstPtr& msg, int idx)
{
    carVel[idx] = *msg;
    carVelTime[idx] = ros::Time::now();
}


geometry_msgs::Twist DataUpdater::getCarVel(int idx)
{

    ros::Time nowTime = ros::Time::now();
    ros::Duration timediff = nowTime-carVelTime[idx];
    if(&carVel[idx] && timediff.nsec<ACCEPTTIME && timediff.sec==0 ) // this message is new enough
        return carVel[idx];
    geometry_msgs::Twist dummyZero;
    //ROS_INFO("RETURN DUMMY");
    return dummyZero;
}


void genCmd(char* cmdData, short vx, short vy, short va)
{
    void* tempP1 = &vx;
    void* tempP2 = &vy;
    void* tempP3 = &va;
    char* velxChar = (char*)tempP1;
    char* velyChar = (char*)tempP2;
    char* velaChar = (char*)tempP3;

    cmdData[0] = (char)0x53;
    cmdData[1] = (char)0x4A;
    cmdData[2] = (char)0x54;
    cmdData[3] = (char)0x55;
    cmdData[4] = velxChar[1]; //swap the high byte and the low byte
    cmdData[5] = velxChar[0];
    cmdData[6] = velyChar[1];
    cmdData[7] = velyChar[0];
    cmdData[8] = velaChar[1];
    cmdData[9] = velaChar[0];
    cmdData[10] = (char)0x01; //

}

void velFilter(short &vx, short &vy, short &va, int &count, short &lastvx, short &lastvy, short &lastva)
{
    if(vx==0 && vy==0 && va==0)
    {
        count++;
        if(count>MAXZERONUM)
        {
            count = MAXZERONUM;
        }
        else
        {
            vx = lastvx;
            vy = lastvy;
            va = lastva;
            ROS_INFO("*****FILT OUT********");
        }
    }
    else
    {
        count = 0;
        lastvx = vx;
        lastvy = vy;
        lastva = va;
    }
}

int main(int argc, char* argv[])
{
ros::init(argc, argv, "agv_udp");
ros::NodeHandle nh;
DataUpdater dataUpdater(nh);
char cmd[COMMAND_SIZE];
ros::Rate rate(FREQUENCY);
ros::Publisher pos_pub[2];
pos_pub[0] = nh.advertise<geometry_msgs::Point>("/robot1/robot_pos", 100);
pos_pub[1] = nh.advertise<geometry_msgs::Point>("/robot2/robot_pos", 100);

//udp virable
int sock_fd;
struct sockaddr_in addr_serv;
int len;
int recv_num;
int send_num;
char send_buf[ROBOTSIZE][1024];
char recv_buf[1024];
struct sockaddr_in addr_client;

//udp
sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
if(sock_fd < 0)
{
  perror("socket");
  exit(1);
}

memset(&addr_serv, 0, sizeof(struct sockaddr_in));
addr_serv.sin_family = AF_INET;
addr_serv.sin_port = htons(SERV_PORT);
addr_serv.sin_addr.s_addr = htonl(INADDR_ANY);
len = sizeof(addr_serv);

if(bind(sock_fd, (struct sockaddr *)&addr_serv, sizeof(addr_serv)) < 0)
{
  perror("bind error:");
  exit(1);
}


geometry_msgs::Twist carVelocity[ROBOTSIZE];
int zeroCount[ROBOTSIZE];
short lastvx[ROBOTSIZE], lastvy[ROBOTSIZE], lastva[ROBOTSIZE];
short vx[ROBOTSIZE],vy[ROBOTSIZE],va[ROBOTSIZE];
double velx[ROBOTSIZE],vely[ROBOTSIZE],vela[ROBOTSIZE];

for(int i=0; i<ROBOTSIZE;i++)
{
    zeroCount[i] = 0;
    lastvx[i] = 0;
    lastvy[i] = 0;
    lastva[i] = 0;
}


while(ros::ok())
{
    ros::spinOnce();
    //sleep(1);
    //rate.sleep();
    //read the velocity
    for(int i=0; i<ROBOTSIZE;i++)
    {
        carVelocity[i] = dataUpdater.getCarVel(i);
        velx[i] = carVelocity[i].linear.x;
        vely[i] = carVelocity[i].linear.y;
        vela[i] = carVelocity[i].angular.z;
        vx[i] = (int)(velx[i]*1000.0);
        vy[i] = (int)(vely[i]*1000.0);
        va[i] = (int)(vela[i]*1000.0);
        velFilter(vx[i],vy[i],va[i],zeroCount[i],lastvx[i],lastvy[i],lastva[i]); // filt out single zer
        genCmd(send_buf[i],vx[i],vy[i],va[i]);
    }

    //receive information from the client
    recv_num = recvfrom(sock_fd, recv_buf, sizeof(recv_buf), 0, (struct sockaddr *)&addr_client, (socklen_t *)&len);
    if(recv_num < 0)
    {
      perror("recvfrom error:");
      exit(1);
    }

    //judge agv id
    if(addr_client.sin_addr.s_addr == inet_addr("192.168.2.201"))
    {
        double t_x, t_y, t_theta;
        std::sscanf(recv_buf, "x:%lf y:%lf theta:%lf", &t_x, &t_y, &t_theta);
        printf("i am agv 201:\n");
        recv_buf[recv_num] = '\0';
        printf("server receive %d bytes: %s\n", recv_num, recv_buf);
        std::cout<<t_x<<" "<<t_y<<" "<<t_theta<<std::endl;
        geometry_msgs::Point robot_pos;
        robot_pos.x = t_x;
        robot_pos.y = t_y;
        robot_pos.z = t_theta;
        pos_pub[0].publish(robot_pos);
        send_num = sendto(sock_fd, send_buf[0], COMMAND_SIZE, 0, (struct sockaddr *)&addr_client, len);

    }

    if(addr_client.sin_addr.s_addr == inet_addr("192.168.2.202"))
    {
        double t_x, t_y, t_theta;
        std::sscanf(recv_buf, "x:%lf y:%lf theta:%lf", &t_x, &t_y, &t_theta);
        printf("i am agv 202:\n");
        recv_buf[recv_num] = '\0';
        printf("server receive %d bytes: %s\n", recv_num, recv_buf);
        std::cout<<t_x<<" "<<t_y<<" "<<t_theta<<std::endl;
        geometry_msgs::Point robot_pos;
        robot_pos.x = t_x;
        robot_pos.y = t_y;
        robot_pos.z = t_theta;
        pos_pub[1].publish(robot_pos);
        send_num = sendto(sock_fd, send_buf[1], COMMAND_SIZE, 0, (struct sockaddr *)&addr_client, len);
//        printf("peer:%02x,%02x,%02x,%02x,%02x,%02x  \n", (unsigned char)send_buf[1][4], (unsigned char)send_buf[1][5], (unsigned char)send_buf[1][6],
//                (unsigned char)send_buf[1][7], (unsigned char)send_buf[1][8], (unsigned char)send_buf[1][9] );

    }

    if(send_num < 0)
    {
      perror("sendto error:");
      exit(1);
    }

}

close(sock_fd);
return 0;
}
