#ifndef _SLROS_BUSMSG_CONVERSION_H_
#define _SLROS_BUSMSG_CONVERSION_H_

#include <ros/ros.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Int8.h>
#include <std_msgs/UInt8.h>
#include "director_types.h"
#include "slros_msgconvert_utils.h"


void convertFromBus(std_msgs::Float64* msgPtr, SL_Bus_director_std_msgs_Float64 const* busPtr);
void convertToBus(SL_Bus_director_std_msgs_Float64* busPtr, std_msgs::Float64 const* msgPtr);

void convertFromBus(std_msgs::Int8* msgPtr, SL_Bus_director_std_msgs_Int8 const* busPtr);
void convertToBus(SL_Bus_director_std_msgs_Int8* busPtr, std_msgs::Int8 const* msgPtr);

void convertFromBus(std_msgs::UInt8* msgPtr, SL_Bus_director_std_msgs_UInt8 const* busPtr);
void convertToBus(SL_Bus_director_std_msgs_UInt8* busPtr, std_msgs::UInt8 const* msgPtr);


#endif
