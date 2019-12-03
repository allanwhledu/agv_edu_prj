/**
 * @file /include/agv_udp_gui/qnode.hpp
 *
 * @brief Communications central!
 *
 * @date February 2011
 **/
/*****************************************************************************
** Ifdefs
*****************************************************************************/

#ifndef agv_udp_gui_QNODE_HPP_
#define agv_udp_gui_QNODE_HPP_

/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <string>
#include <QThread>
#include <QStringListModel>
#include <geometry_msgs/Twist.h>

#define ROBOTSIZE  4
/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace agv_udp_gui {

/*****************************************************************************
** Class
*****************************************************************************/

class QNode : public QThread {
    Q_OBJECT
public:
	QNode(int argc, char** argv );
	virtual ~QNode();
	bool init();
	bool init(const std::string &master_url, const std::string &host_url);
	void run();
	/*********************
	** hxq 2019.01.01
	**********************/	
	void publish_cmd_vel(geometry_msgs::Twist velocity, int index);

	/*********************
	** Logging
	**********************/
	enum LogLevel {
	         Debug,
	         Info,
	         Warn,
	         Error,
	         Fatal
	 };

	QStringListModel* loggingModel(int robot_index) { return &logging_model[robot_index-1]; }
	void log( const LogLevel &level, const std::string &msg, int robot_index);

Q_SIGNALS:
	void loggingUpdated();
    void rosShutdown();

private:
	int init_argc;
	char** init_argv;
	ros::Publisher chatter_publisher;
	ros::Publisher cmd_vel_pub[ROBOTSIZE];
    QStringListModel logging_model[ROBOTSIZE];
};

}  // namespace agv_udp_gui

#endif /* agv_udp_gui_QNODE_HPP_ */
