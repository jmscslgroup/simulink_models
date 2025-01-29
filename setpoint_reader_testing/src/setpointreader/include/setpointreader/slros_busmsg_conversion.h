#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Vector3.h>
#include <std_msgs/Float64.h>
#include "setpointreader_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(geometry_msgs::Point* msgPtr, SL_Bus_setpointreader_geometry_msgs_Point const* busPtr);
void convertToBus(SL_Bus_setpointreader_geometry_msgs_Point* busPtr, geometry_msgs::Point const* msgPtr);

void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_setpointreader_geometry_msgs_Twist const* busPtr);
void convertToBus(SL_Bus_setpointreader_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr);

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_setpointreader_geometry_msgs_Vector3 const* busPtr);
void convertToBus(SL_Bus_setpointreader_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);

void convertFromBus(std_msgs::Float64* msgPtr, SL_Bus_setpointreader_std_msgs_Float64 const* busPtr);
void convertToBus(SL_Bus_setpointreader_std_msgs_Float64* busPtr, std_msgs::Float64 const* msgPtr);


#endif
