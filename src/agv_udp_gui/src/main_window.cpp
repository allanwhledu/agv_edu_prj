/**
 * @file /src/main_window.cpp
 *
 * @brief Implementation for the qt gui.
 *
 * @date February 2011
 **/
/*****************************************************************************
** Includes
*****************************************************************************/

#include <QtGui>
#include <QMessageBox>
#include <iostream>
#include "../include/agv_udp_gui/main_window.hpp"
#include <QSignalMapper>
#include <geometry_msgs/Twist.h>

/*****************************************************************************
** Namespaces
*****************************************************************************/

namespace agv_udp_gui {

using namespace Qt;

/*****************************************************************************
** Implementation [MainWindow]
*****************************************************************************/
typedef enum{
BUTTON_1,BUTTON_2,BUTTON_3,BUTTON_4,BUTTON_5,BUTTON_6,BUTTON_7,
BUTTON_8,BUTTON_9,BUTTON_10,BUTTON_11,BUTTON_12,BUTTON_13,BUTTON_14,
BUTTON_15,BUTTON_16,BUTTON_17,BUTTON_18,BUTTON_19,BUTTON_20,BUTTON_21,
BUTTON_22,BUTTON_23,BUTTON_24,BUTTON_25,BUTTON_26,BUTTON_27,BUTTON_28
}BUTTON;

MainWindow::MainWindow(int argc, char** argv, QWidget *parent)
	: QMainWindow(parent)
	, qnode(argc,argv)
{
	ui.setupUi(this); // Calling this incidentally connects all ui's triggers to on_...() callbacks in this class.
    QObject::connect(ui.actionAbout_Qt, SIGNAL(triggered(bool)), qApp, SLOT(aboutQt())); // qApp is a global variable for the application

    ReadSettings();
	setWindowIcon(QIcon(":/images/icon.png"));
	ui.tab_manager->setCurrentIndex(0); // ensure the first tab is showing - qt-designer should have this already hardwired, but often loses it (settings?).
    //QObject::connect(&qnode, SIGNAL(rosShutdown()), this, SLOT(close()));

	/*********************
	** Logging
	**********************/
    ui.view_logging_1->setModel(qnode.loggingModel(1));
    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

    ui.view_logging_2->setModel(qnode.loggingModel(2));
    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

    ui.view_logging_3->setModel(qnode.loggingModel(3));
    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

    ui.view_logging_4->setModel(qnode.loggingModel(4));
    QObject::connect(&qnode, SIGNAL(loggingUpdated()), this, SLOT(updateLoggingView()));

    QSignalMapper *signal_mapper_1 = new QSignalMapper(this);
//AGV1
    connect(ui.pushButton_1,SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_2, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_3, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_4, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_5, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_6, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_7, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));

    signal_mapper_1->setMapping(ui.pushButton_1, QString::number(BUTTON_1, 10));
    signal_mapper_1->setMapping(ui.pushButton_2, QString::number(BUTTON_2, 10));
    signal_mapper_1->setMapping(ui.pushButton_3, QString::number(BUTTON_3, 10));
    signal_mapper_1->setMapping(ui.pushButton_4, QString::number(BUTTON_4, 10));
    signal_mapper_1->setMapping(ui.pushButton_5, QString::number(BUTTON_5, 10));
    signal_mapper_1->setMapping(ui.pushButton_6, QString::number(BUTTON_6, 10));
    signal_mapper_1->setMapping(ui.pushButton_7, QString::number(BUTTON_7, 10));
//AGV2
    connect(ui.pushButton_8,SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_9, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_10, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_11, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_12, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_13, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_14, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));

    signal_mapper_1->setMapping(ui.pushButton_8, QString::number(BUTTON_8, 10));
    signal_mapper_1->setMapping(ui.pushButton_9, QString::number(BUTTON_9, 10));
    signal_mapper_1->setMapping(ui.pushButton_10, QString::number(BUTTON_10, 10));
    signal_mapper_1->setMapping(ui.pushButton_11, QString::number(BUTTON_11, 10));
    signal_mapper_1->setMapping(ui.pushButton_12, QString::number(BUTTON_12, 10));
    signal_mapper_1->setMapping(ui.pushButton_13, QString::number(BUTTON_13, 10));
    signal_mapper_1->setMapping(ui.pushButton_14, QString::number(BUTTON_14, 10));

//AGV3
    connect(ui.pushButton_15,SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_16, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_17, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_18, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_19, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_20, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_21, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));

    signal_mapper_1->setMapping(ui.pushButton_15, QString::number(BUTTON_15, 10));
    signal_mapper_1->setMapping(ui.pushButton_16, QString::number(BUTTON_16, 10));
    signal_mapper_1->setMapping(ui.pushButton_17, QString::number(BUTTON_17, 10));
    signal_mapper_1->setMapping(ui.pushButton_18, QString::number(BUTTON_18, 10));
    signal_mapper_1->setMapping(ui.pushButton_19, QString::number(BUTTON_19, 10));
    signal_mapper_1->setMapping(ui.pushButton_20, QString::number(BUTTON_20, 10));
    signal_mapper_1->setMapping(ui.pushButton_21, QString::number(BUTTON_21, 10));


//AGV4
    connect(ui.pushButton_22,SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_23, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_24, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_25, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_26, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_27, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));
    connect(ui.pushButton_28, SIGNAL (pressed()), signal_mapper_1, SLOT(map()));

    signal_mapper_1->setMapping(ui.pushButton_22, QString::number(BUTTON_22, 10));
    signal_mapper_1->setMapping(ui.pushButton_23, QString::number(BUTTON_23, 10));
    signal_mapper_1->setMapping(ui.pushButton_24, QString::number(BUTTON_24, 10));
    signal_mapper_1->setMapping(ui.pushButton_25, QString::number(BUTTON_25, 10));
    signal_mapper_1->setMapping(ui.pushButton_26, QString::number(BUTTON_26, 10));
    signal_mapper_1->setMapping(ui.pushButton_27, QString::number(BUTTON_27, 10));
    signal_mapper_1->setMapping(ui.pushButton_28, QString::number(BUTTON_28, 10));


    connect(signal_mapper_1, SIGNAL(mapped(QString)), this, SLOT(on_button_cmd_vel_1_clicked(QString)));





    /*********************
    ** Auto Start
    **********************/
    if ( ui.checkbox_remember_settings->isChecked() ) {
        on_button_connect_clicked(true);
    }

    ui.lineEdit_1->setPlaceholderText("input velocity");
    ui.lineEdit_2->setPlaceholderText("input velocity");
    ui.lineEdit_3->setPlaceholderText("input velocity");
    ui.lineEdit_4->setPlaceholderText("input velocity");
}

MainWindow::~MainWindow() {}

/*****************************************************************************
** Implementation [Slots]
*****************************************************************************/

void MainWindow::showNoMasterMessage() {
	QMessageBox msgBox;
	msgBox.setText("Couldn't find the ros master.");
	msgBox.exec();
    close();
}

/*
 * These triggers whenever the button is clicked, regardless of whether it
 * is already checked or not.
 */

void MainWindow::on_button_connect_clicked(bool check ) {
	if ( ui.checkbox_use_environment->isChecked() ) {
		if ( !qnode.init() ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
		}
	} else {
		if ( ! qnode.init(ui.line_edit_master->text().toStdString(),
				   ui.line_edit_host->text().toStdString()) ) {
			showNoMasterMessage();
		} else {
			ui.button_connect->setEnabled(false);
			ui.line_edit_master->setReadOnly(true);
			ui.line_edit_host->setReadOnly(true);
			ui.line_edit_topic->setReadOnly(true);
		}
	}
}




void MainWindow::on_button_cmd_vel_1_clicked(QString text)
{
    ui.lineEdit_1->setPlaceholderText("input velocity");
    QString string_1 = ui.lineEdit_1->text();
    double input_num_1 = string_1.toDouble();

    ui.lineEdit_2->setPlaceholderText("input velocity");
    QString string_2 = ui.lineEdit_2->text();
    double input_num_2 = string_2.toDouble();

    ui.lineEdit_3->setPlaceholderText("input velocity");
    QString string_3 = ui.lineEdit_3->text();
    double input_num_3 = string_3.toDouble();

    ui.lineEdit_4->setPlaceholderText("input velocity");
    QString string_4 = ui.lineEdit_4->text();
    double input_num_4 = string_4.toDouble();

    geometry_msgs::Twist velocity;
    int index = text.toInt();
    QString information = QString("");
    switch(index)
    {
    //agv1
    case BUTTON_1:
        information = QString("clicked 1");
        velocity.linear.x = input_num_1;
        break;

    case BUTTON_2:
        information = QString("clicked 2");
        velocity.linear.x = -1*input_num_1;
        break;

    case BUTTON_3:
        information = QString("clicked 3");
        velocity.linear.y = input_num_1;
        break;

    case BUTTON_4:
        information = QString("clicked 4");
        velocity.linear.y = -1*input_num_1;
        break;
    case BUTTON_5:
        information = QString("clicked 5");
        velocity.angular.z = input_num_1;
        break;
    case BUTTON_6:
        information = QString("clicked 6");
        velocity.angular.z = -1*input_num_1;
        break;
    case BUTTON_7:
        information = QString("clicked 6");
        break;

    //AGV2
    case BUTTON_8:
        information = QString("clicked 1");
        velocity.linear.x = input_num_2;
        break;

    case BUTTON_9:
        information = QString("clicked 2");
        velocity.linear.x = -1*input_num_2;
        break;

    case BUTTON_10:
        information = QString("clicked 3");
        velocity.linear.y = input_num_2;
        break;

    case BUTTON_11:
        information = QString("clicked 4");
        velocity.linear.y = -1*input_num_2;
        break;
    case BUTTON_12:
        information = QString("clicked 5");
        velocity.angular.z = input_num_2;
        break;
    case BUTTON_13:
        information = QString("clicked 6");
        velocity.angular.z = -1*input_num_2;
        break;
    case BUTTON_14:
        information = QString("clicked 6");
        break;

    //AGV3
    case BUTTON_15:
        information = QString("clicked 1");
        velocity.linear.x = input_num_3;
        break;

    case BUTTON_16:
        information = QString("clicked 2");
        velocity.linear.x = -1*input_num_3;
        break;

    case BUTTON_17:
        information = QString("clicked 3");
        velocity.linear.y = input_num_3;
        break;

    case BUTTON_18:
        information = QString("clicked 4");
        velocity.linear.y = -1*input_num_3;
        break;
    case BUTTON_19:
        information = QString("clicked 5");
        velocity.angular.z = input_num_3;
        break;
    case BUTTON_20:
        information = QString("clicked 6");
        velocity.angular.z = -1*input_num_3;
        break;
    case BUTTON_21:
        information = QString("clicked 6");
        break;


    //AGV4
    case BUTTON_22:
        information = QString("clicked 1");
        velocity.linear.x = input_num_4;
        break;

    case BUTTON_23:
        information = QString("clicked 2");
        velocity.linear.x = -1*input_num_4;
        break;

    case BUTTON_24:
        information = QString("clicked 3");
        velocity.linear.y = input_num_4;
        break;

    case BUTTON_25:
        information = QString("clicked 4");
        velocity.linear.y = -1*input_num_4;
        break;
    case BUTTON_26:
        information = QString("clicked 5");
        velocity.angular.z = input_num_4;
        break;
    case BUTTON_27:
        information = QString("clicked 6");
        velocity.angular.z = -1*input_num_4;
        break;
    case BUTTON_28:
        information = QString("clicked 6");
        break;




    default:
        information = QString("which is clicked?");
        break;
    }
    //QMessageBox::information(NULL, QString("Title"), information);
    int robot_index = 0;
    if(index >= BUTTON_1&& index <= BUTTON_7)
        robot_index  = 1;
    else if(index >= BUTTON_8&& index <= BUTTON_14)
        robot_index  = 2;
    else if(index >= BUTTON_15&& index <= BUTTON_21)
        robot_index  = 3;
    else if(index >= BUTTON_22&& index <= BUTTON_28)
        robot_index  = 4;
    qnode.publish_cmd_vel(velocity, robot_index);
    std::cout<<"hello world1"<<" "<<index<<std::endl;
}



void MainWindow::on_checkbox_use_environment_stateChanged(int state) {
	bool enabled;
	if ( state == 0 ) {
		enabled = true;
	} else {
		enabled = false;
	}
	ui.line_edit_master->setEnabled(enabled);
	ui.line_edit_host->setEnabled(enabled);
	//ui.line_edit_topic->setEnabled(enabled);
}

/*****************************************************************************
** Implemenation [Slots][manually connected]
*****************************************************************************/

/**
 * This function is signalled by the underlying model. When the model changes,
 * this will drop the cursor down to the last line in the QListview to ensure
 * the user can always see the latest log message.
 */
void MainWindow::updateLoggingView() {
        ui.view_logging_1->scrollToBottom();
        ui.view_logging_2->scrollToBottom();
        ui.view_logging_3->scrollToBottom();
        ui.view_logging_4->scrollToBottom();
}

/*****************************************************************************
** Implementation [Menu]
*****************************************************************************/

void MainWindow::on_actionAbout_triggered() {
    QMessageBox::about(this, tr("About ..."),tr("<h2>PACKAGE_NAME Test Program 0.10</h2><p>Copyright Yujin Robot</p><p>This package needs an about description.</p>"));
}

/*****************************************************************************
** Implementation [Configuration]
*****************************************************************************/

void MainWindow::ReadSettings() {
    QSettings settings("Qt-Ros Package", "agv_udp_gui");
    restoreGeometry(settings.value("geometry").toByteArray());
    restoreState(settings.value("windowState").toByteArray());
    QString master_url = settings.value("master_url",QString("http://192.168.1.2:11311/")).toString();
    QString host_url = settings.value("host_url", QString("192.168.1.3")).toString();
    //QString topic_name = settings.value("topic_name", QString("/chatter")).toString();
    ui.line_edit_master->setText(master_url);
    ui.line_edit_host->setText(host_url);
    //ui.line_edit_topic->setText(topic_name);
    bool remember = settings.value("remember_settings", false).toBool();
    ui.checkbox_remember_settings->setChecked(remember);
    bool checked = settings.value("use_environment_variables", false).toBool();
    ui.checkbox_use_environment->setChecked(checked);
    if ( checked ) {
    	ui.line_edit_master->setEnabled(false);
    	ui.line_edit_host->setEnabled(false);
    	//ui.line_edit_topic->setEnabled(false);
    }
}

void MainWindow::WriteSettings() {
    QSettings settings("Qt-Ros Package", "agv_udp_gui");
    settings.setValue("master_url",ui.line_edit_master->text());
    settings.setValue("host_url",ui.line_edit_host->text());
    //settings.setValue("topic_name",ui.line_edit_topic->text());
    settings.setValue("use_environment_variables",QVariant(ui.checkbox_use_environment->isChecked()));
    settings.setValue("geometry", saveGeometry());
    settings.setValue("windowState", saveState());
    settings.setValue("remember_settings",QVariant(ui.checkbox_remember_settings->isChecked()));

}

void MainWindow::closeEvent(QCloseEvent *event)
{
	WriteSettings();
	QMainWindow::closeEvent(event);
}

}  // namespace agv_udp_gui

