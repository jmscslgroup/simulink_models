#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "mode_changer";

// For Block mode_changer/Subscribe2
SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_mode_changer_geometry_msgs_Twist> Sub_mode_changer_2;

// For Block mode_changer/Subsystem/Publish
SimulinkPublisher<std_msgs::Int8, SL_Bus_mode_changer_std_msgs_Int8> Pub_mode_changer_19;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

