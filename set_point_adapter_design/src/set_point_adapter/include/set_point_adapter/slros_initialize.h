#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "set_point_adapter_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block set_point_adapter/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_set_point_adapter_std_msgs_Float64> Sub_set_point_adapter_31;

// For Block set_point_adapter/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_set_point_adapter_std_msgs_Float64> Pub_set_point_adapter_44;

// For Block set_point_adapter/Publish2
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_set_point_adapter_std_msgs_Float64> Pub_set_point_adapter_54;

void slros_node_init(int argc, char** argv);

#endif
