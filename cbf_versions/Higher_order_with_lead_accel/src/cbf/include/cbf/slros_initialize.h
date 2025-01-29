#ifndef _SLROS_INITIALIZE_H_
#define _SLROS_INITIALIZE_H_

#include "slros_busmsg_conversion.h"
#include "slros_generic.h"
#include "cbf_types.h"

extern ros::NodeHandle * SLROSNodePtr;
extern const std::string SLROSNodeName;

// For Block cbf/Subscribe
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_cbf_std_msgs_Float64> Sub_cbf_547;

// For Block cbf/Subscribe1
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_cbf_std_msgs_Float64> Sub_cbf_548;

// For Block cbf/Subscribe2
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_cbf_std_msgs_Float64> Sub_cbf_549;

// For Block cbf/Subscribe3
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_cbf_std_msgs_Float64> Sub_cbf_634;

// For Block cbf/Subscribe6
extern SimulinkSubscriber<std_msgs::Float64, SL_Bus_cbf_std_msgs_Float64> Sub_cbf_551;

// For Block cbf/Subscribe7
extern SimulinkSubscriber<std_msgs::Bool, SL_Bus_cbf_std_msgs_Bool> Sub_cbf_552;

// For Block cbf/Publish1
extern SimulinkPublisher<std_msgs::Float64, SL_Bus_cbf_std_msgs_Float64> Pub_cbf_544;

// For Block cbf/Publish2
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_cbf_geometry_msgs_Twist> Pub_cbf_545;

// For Block cbf/Publish3
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_cbf_geometry_msgs_Twist> Pub_cbf_612;

// For Block cbf/Publish4
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_cbf_geometry_msgs_Twist> Pub_cbf_642;

// For Block cbf/Publish5
extern SimulinkPublisher<geometry_msgs::Twist, SL_Bus_cbf_geometry_msgs_Twist> Pub_cbf_614;

// For Block cbf/cbf_filter/Get Parameter2
extern SimulinkParameterGetter<real64_T, double> ParamGet_cbf_567;

// For Block cbf/cbf_filter/Get Parameter3
extern SimulinkParameterGetter<real64_T, double> ParamGet_cbf_568;

// For Block cbf/cbf_filter/Get Parameter4
extern SimulinkParameterGetter<real64_T, double> ParamGet_cbf_569;

// For Block cbf/cbf_filter/Get Parameter5
extern SimulinkParameterGetter<real64_T, double> ParamGet_cbf_570;

// For Block cbf/cbf_filter/Get Parameter7
extern SimulinkParameterGetter<real64_T, double> ParamGet_cbf_595;

void slros_node_init(int argc, char** argv);

#endif
