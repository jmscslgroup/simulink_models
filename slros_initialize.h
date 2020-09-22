#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block mode_changer/Subscribe2
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_mode_changer_geometry_msgs_Twist> Sub_mode_changer_2;

// For Block mode_changer/Subsystem/Publish
extern SimulinkPublisher<std_msgs::Int8, SL_Bus_mode_changer_std_msgs_Int8> Pub_mode_changer_19;

void slros_node_init(int argc, char** argv);

#endif
