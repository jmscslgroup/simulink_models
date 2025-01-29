#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "set_point_adapter";

// For Block set_point_adapter/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_set_point_adapter_std_msgs_Float64> Sub_set_point_adapter_31;

// For Block set_point_adapter/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_set_point_adapter_std_msgs_Float64> Pub_set_point_adapter_44;

// For Block set_point_adapter/Publish2
SimulinkPublisher<std_msgs::Float64, SL_Bus_set_point_adapter_std_msgs_Float64> Pub_set_point_adapter_54;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

