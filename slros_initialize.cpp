#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "director";

// For Block director/Subscribe2
SimulinkSubscriber<std_msgs::Int8, SL_Bus_director_std_msgs_Int8> Sub_director_14;

// For Block director/Setpoint Publisher/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_director_std_msgs_Float64> Pub_director_5;

// For Block director/feedback_type Publisher/Publish2
SimulinkPublisher<std_msgs::UInt8, SL_Bus_director_std_msgs_UInt8> Pub_director_8;

// For Block director/mode publisher/Publish
SimulinkPublisher<std_msgs::UInt8, SL_Bus_director_std_msgs_UInt8> Pub_director_1;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

