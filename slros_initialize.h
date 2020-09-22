#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block director/Subscribe2
extern SimulinkSubscriber<std_msgs::Int8, SL_Bus_director_std_msgs_Int8> Sub_director_14;

// For Block director/Setpoint Publisher/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_director_std_msgs_Float64> Pub_director_5;

// For Block director/feedback_type Publisher/Publish2
extern SimulinkPublisher<std_msgs::UInt8, SL_Bus_director_std_msgs_UInt8> Pub_director_8;

// For Block director/mode publisher/Publish
extern SimulinkPublisher<std_msgs::UInt8, SL_Bus_director_std_msgs_UInt8> Pub_director_1;

void slros_node_init(int argc, char** argv);

#endif
