#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "cbf_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block cbf/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_cbf_std_msgs_Float64> Sub_cbf_429;

// For Block cbf/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_cbf_std_msgs_Float64> Sub_cbf_527;

// For Block cbf/Subscribe4
extern SimulinkSubscriber<geometry_msgs::Twist, SL_Bus_cbf_geometry_msgs_Twist> Sub_cbf_430;

// For Block cbf/Subscribe6
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_cbf_std_msgs_Float64> Sub_cbf_476;

// For Block cbf/Subscribe7
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_cbf_std_msgs_Bool> Sub_cbf_481;

// For Block cbf/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_cbf_std_msgs_Float64> Pub_cbf_401;

// For Block cbf/Publish2
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_cbf_geometry_msgs_Twist> Pub_cbf_520;

// For Block cbf/cbf_filter/Get Parameter1
extern SimulinkParameterGetter<real64_T, double> ParamGet_cbf_447;

// For Block cbf/cbf_filter/Get Parameter2
extern SimulinkParameterGetter<real64_T, double> ParamGet_cbf_448;

// For Block cbf/cbf_filter/Get Parameter3
extern SimulinkParameterGetter<real64_T, double> ParamGet_cbf_449;

// For Block cbf/cbf_filter/Get Parameter4
extern SimulinkParameterGetter<real64_T, double> ParamGet_cbf_450;

// For Block cbf/cbf_filter/Get Parameter5
extern SimulinkParameterGetter<real64_T, double> ParamGet_cbf_463;

// For Block cbf/cbf_filter/Get Parameter6
extern SimulinkParameterGetter<real64_T, double> ParamGet_cbf_465;

void slros_node_init(int argc, char** argv);

#endif
