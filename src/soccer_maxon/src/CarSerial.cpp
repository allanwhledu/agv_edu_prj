#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include <soccer_maxon/SerialPort.h>

#define FREQUENCY 10
#define COMMAND_SIZE 11 
 
#define MAXZERONUM 5



class DataUpdater
{
public:
	DataUpdater(ros::NodeHandle &nh);
	~DataUpdater();
	geometry_msgs::Twist getCarVel();

private:
	// callback functions
	void carVelCallback(const geometry_msgs::Twist::ConstPtr& msg);

	// subscribers
	ros::Subscriber carVelSub;

	// data
	geometry_msgs::Twist::ConstPtr carVel; //boost::shared_ptr<const geometry_msgs::Twist_<std::allocator<void> > >	
	// the latest time that recieve a message
	ros::Time carVelTime;
	int ACCEPTTIME;
};

DataUpdater::DataUpdater(ros::NodeHandle &nh)
{
	carVelSub = nh.subscribe("cmd_vel",1,&DataUpdater::carVelCallback,this);
	ACCEPTTIME = 500000000; // 0.5s, unit: ns(10^-9s) TODO: this may need change
}

DataUpdater::~DataUpdater()
{
}

void DataUpdater::carVelCallback(const geometry_msgs::Twist::ConstPtr& msg)
{
	carVel = msg;
	//ROS_INFO("car_vel: %.4f, %.4f, %.4f", msg->linear.x, msg->linear.y, msg->angular.z);
	carVelTime = ros::Time::now();
}

geometry_msgs::Twist DataUpdater::getCarVel()
{
	ros::Time nowTime = ros::Time::now();
	ros::Duration timediff = nowTime-carVelTime;
	if(carVel && timediff.nsec<ACCEPTTIME && timediff.sec==0 ) // this message is new enough
		return *carVel;
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

int main(int argc, char **argv)
{
    char* CommPort = "/dev/ttyUSB0";  //default port

    ros::init(argc, argv, "car_serial");
    ros::NodeHandle nh;
    DataUpdater dataUpdater(nh);

    serial::SerialPort device;
    char cmd[COMMAND_SIZE];

    // Change the next line according to your port name and baud rate
    try
    { 
    	device.open(CommPort, 115200); // TODO:
    }  
    catch(serial::Exception& e)
    {
        ROS_FATAL("Failed to open the serial port!!!");
        ROS_BREAK();
    }
    ROS_INFO("The serial port is open...");

    ros::Rate rate(FREQUENCY); // TODO: 

    geometry_msgs::Twist carVelocity;
    int zeroCount = 0;
    short lastvx=0;
    short lastvy=0;
    short lastva=0;
    short vx,vy,va;
    double velx,vely,vela;
    while(ros::ok())
    {
        ros::spinOnce();
        rate.sleep();
        
	// Read the velocity
        carVelocity = dataUpdater.getCarVel();
        velx = carVelocity.linear.x;
        vely = carVelocity.linear.y;
        vela = carVelocity.angular.z;
        vx = (int)(velx*1000.0);
        vy = (int)(vely*1000.0);
        va = (int)(vela*1000.0);

        velFilter(vx,vy,va,zeroCount,lastvx,lastvy,lastva); // filt out single zero

        genCmd(cmd,vx,vy,va); // adjust the opsite direction
	
        try{
            device.write(cmd,COMMAND_SIZE);
            ROS_INFO("Send cmd %02x, %02x, %02x, %02x, %02x, %02x.",(unsigned char)cmd[4],(unsigned char)cmd[5],(unsigned char)cmd[6],(unsigned char)cmd[7],(unsigned char)cmd[8],(unsigned char)cmd[9]);
        }catch(serial::Exception e)
        {
          ROS_INFO("Write error..");
        }
    }   
}

