#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "setpointreader_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block setpointreader/Subscribe1
extern SimulinkSubscriber<geometry_msgs::Point, SL_Bus_setpointreader_geometry_msgs_Point> Sub_setpointreader_31;

// For Block setpointreader/Publish
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_setpointreader_geometry_msgs_Twist> Pub_setpointreader_3;

// For Block setpointreader/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_setpointreader_std_msgs_Float64> Pub_setpointreader_44;

void slros_node_init(int argc, char** argv);

#endif
