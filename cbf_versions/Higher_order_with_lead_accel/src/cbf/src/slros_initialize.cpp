#include "slros_initialize.h"

ros::NodeHandle * SLROSNodePtr;
const std::string SLROSNodeName = "cbf";

// For Block cbf/Subscribe
SimulinkSubscriber<std_msgs::Float64, SL_Bus_cbf_std_msgs_Float64> Sub_cbf_547;

// For Block cbf/Subscribe1
SimulinkSubscriber<std_msgs::Float64, SL_Bus_cbf_std_msgs_Float64> Sub_cbf_548;

// For Block cbf/Subscribe2
SimulinkSubscriber<std_msgs::Float64, SL_Bus_cbf_std_msgs_Float64> Sub_cbf_549;

// For Block cbf/Subscribe3
SimulinkSubscriber<std_msgs::Float64, SL_Bus_cbf_std_msgs_Float64> Sub_cbf_634;

// For Block cbf/Subscribe6
SimulinkSubscriber<std_msgs::Float64, SL_Bus_cbf_std_msgs_Float64> Sub_cbf_551;

// For Block cbf/Subscribe7
SimulinkSubscriber<std_msgs::Bool, SL_Bus_cbf_std_msgs_Bool> Sub_cbf_552;

// For Block cbf/Publish1
SimulinkPublisher<std_msgs::Float64, SL_Bus_cbf_std_msgs_Float64> Pub_cbf_544;

// For Block cbf/Publish2
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_cbf_geometry_msgs_Twist> Pub_cbf_545;

// For Block cbf/Publish3
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_cbf_geometry_msgs_Twist> Pub_cbf_612;

// For Block cbf/Publish4
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_cbf_geometry_msgs_Twist> Pub_cbf_642;

// For Block cbf/Publish5
SimulinkPublisher<geometry_msgs::Twist, SL_Bus_cbf_geometry_msgs_Twist> Pub_cbf_614;

// For Block cbf/cbf_filter/Get Parameter2
SimulinkParameterGetter<real64_T, double> ParamGet_cbf_567;

// For Block cbf/cbf_filter/Get Parameter3
SimulinkParameterGetter<real64_T, double> ParamGet_cbf_568;

// For Block cbf/cbf_filter/Get Parameter4
SimulinkParameterGetter<real64_T, double> ParamGet_cbf_569;

// For Block cbf/cbf_filter/Get Parameter5
SimulinkParameterGetter<real64_T, double> ParamGet_cbf_570;

// For Block cbf/cbf_filter/Get Parameter7
SimulinkParameterGetter<real64_T, double> ParamGet_cbf_595;

void slros_node_init(int argc, char** argv)
{
  ros::init(argc, argv, SLROSNodeName);
  SLROSNodePtr = new ros::NodeHandle();
}

