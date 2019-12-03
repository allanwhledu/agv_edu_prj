/**
 * @file /src/qnode.cpp
 *
 * @brief Ros communication central!
 *
 * @date February 2011
 **/

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>
#include <sstream>
#include <geometry_msgs/Twist.h>
#include "../include/agv_udp_gui/qnode.hpp"

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace agv_udp_gui {

/*****************************************************************************
** Implementation
*****************************************************************************/

QNode::QNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

QNode::~QNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}

bool QNode::init() {
	ros::init(init_argc,init_argv,"agv_udp_gui");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
	chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);
    for(int i=0; i<ROBOTSIZE; i++)
    {
        std::stringstream topic;
        topic<<"/robot"<<i+1<<"/cmd_vel";
        cmd_vel_pub[i] = n.advertise<geometry_msgs::Twist>(topic.str(), 100);
    }
	start();
	return true;
}

bool QNode::init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
	ros::init(remappings,"agv_udp_gui");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
	chatter_publisher = n.advertise<std_msgs::String>("chatter", 1000);

    for(int i=0; i<ROBOTSIZE; i++)
    {
        std::stringstream topic;
        topic<<"/robot"<<i+1<<"/cmd_vel";
        cmd_vel_pub[i] = n.advertise<geometry_msgs::Twist>(topic.str(), 100);
    }
	start();
	return true;
}

void QNode::run() {
//	ros::Rate loop_rate(1);
//	int count = 0;
//	while ( ros::ok() ) {

//		std_msgs::String msg;
//		std::stringstream ss;
//		ss << "hello world " << count;
//		msg.data = ss.str();
//		chatter_publisher.publish(msg);
//		log(Info,std::string("I sent: ")+msg.data);
//		ros::spinOnce();
//		loop_rate.sleep();
//		++count;
//	}
//	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
//	Q_EMIT rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
//    std_msgs::String msg;
//    std::stringstream ss;
//    ss << "modified by hxq " ;
//    msg.data = ss.str();
//    chatter_publisher.publish(msg);
//    log(Info,std::string("I sent: ")+msg.data);
}



void QNode::publish_cmd_vel(geometry_msgs::Twist velocity, int index)
{
    cmd_vel_pub[index-1].publish(velocity);
    std::stringstream ss;
    ss<<"vx: "<<velocity.linear.x<<" vy: "<<velocity.linear.y<<" wz: "<<velocity.angular.z;
    log(Info,std::string("I sent: ")+ss.str(),index-1);
    //std::cout<<"hello world"<<std::endl;
}


void QNode::log( const LogLevel &level, const std::string &msg, int robot_index) {
    logging_model[robot_index].insertRows(logging_model[robot_index].rowCount(),1);
    std::stringstream logging_model_msg;
    switch ( level ) {
        case(Debug) : {
                ROS_DEBUG_STREAM(msg);
                logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Info) : {
                ROS_INFO_STREAM(msg);
                logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Warn) : {
                ROS_WARN_STREAM(msg);
                logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Error) : {
                ROS_ERROR_STREAM(msg);
                logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
                break;
        }
        case(Fatal) : {
                ROS_FATAL_STREAM(msg);
                logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
                break;
        }
    }
    QVariant new_row(QString(logging_model_msg.str().c_str()));
    logging_model[robot_index].setData(logging_model[robot_index].index(logging_model[robot_index].rowCount()-1),new_row);
    Q_EMIT loggingUpdated(); // used to readjust the scrollbar
}

//void QNode::log( const LogLevel &level, const std::string &msg) {
//	logging_model.insertRows(logging_model.rowCount(),1);
//	std::stringstream logging_model_msg;
//	switch ( level ) {
//		case(Debug) : {
//				ROS_DEBUG_STREAM(msg);
//				logging_model_msg << "[DEBUG] [" << ros::Time::now() << "]: " << msg;
//				break;
//		}
//		case(Info) : {
//				ROS_INFO_STREAM(msg);
//				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
//				break;
//		}
//		case(Warn) : {
//				ROS_WARN_STREAM(msg);
//				logging_model_msg << "[INFO] [" << ros::Time::now() << "]: " << msg;
//				break;
//		}
//		case(Error) : {
//				ROS_ERROR_STREAM(msg);
//				logging_model_msg << "[ERROR] [" << ros::Time::now() << "]: " << msg;
//				break;
//		}
//		case(Fatal) : {
//				ROS_FATAL_STREAM(msg);
//				logging_model_msg << "[FATAL] [" << ros::Time::now() << "]: " << msg;
//				break;
//		}
//	}
//	QVariant new_row(QString(logging_model_msg.str().c_str()));
//	logging_model.setData(logging_model.index(logging_model.rowCount()-1),new_row);
//	Q_EMIT loggingUpdated(); // used to readjust the scrollbar
//}

}  // namespace agv_udp_gui
