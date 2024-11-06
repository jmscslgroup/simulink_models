#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "velocity_controller_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block velocity_controller/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_velocity_controller_std_msgs_Float64> Sub_velocity_controller_10;

// For Block velocity_controller/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_velocity_controller_std_msgs_Float64> Sub_velocity_controller_31;

// For Block velocity_controller/Subscribe2
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_velocity_controller_std_msgs_Bool> Sub_velocity_controller_40;

// For Block velocity_controller/Publish
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_velocity_controller_std_msgs_Float64> Pub_velocity_controller_3;

void slros_node_init(int argc, char** argv);

#endif
