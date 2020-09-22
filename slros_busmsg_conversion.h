#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Vector3.h>
#include <std_msgs/Int8.h>
#include "mode_changer_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_mode_changer_geometry_msgs_Twist const* busPtr);
void convertToBus(SL_Bus_mode_changer_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr);

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_mode_changer_geometry_msgs_Vector3 const* busPtr);
void convertToBus(SL_Bus_mode_changer_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr);

void convertFromBus(std_msgs::Int8* msgPtr, SL_Bus_mode_changer_std_msgs_Int8 const* busPtr);
void convertToBus(SL_Bus_mode_changer_std_msgs_Int8* busPtr, std_msgs::Int8 const* msgPtr);


#endif
