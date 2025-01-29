#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "setpointreader";

// For Block setpointreader/Subscribe1
SimulinkSubscriber<geometry_msgs::Point, SL_Bus_setpointreader_geometry_msgs_Point> Sub_setpointreader_31;

// For Block setpointreader/Publish
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_setpointreader_geometry_msgs_Twist> Pub_setpointreader_3;

// For Block setpointreader/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_setpointreader_std_msgs_Float64> Pub_setpointreader_44;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

