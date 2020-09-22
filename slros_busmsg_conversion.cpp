#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_director_std_msgs_Float64 and std_msgs::Float64

void convertFromBus(std_msgs::Float64* msgPtr, SL_Bus_director_std_msgs_Float64 const* busPtr)
{
  const std::string rosMessageType("std_msgs/Float64");

  msgPtr->data =  busPtr->Data;
}

void convertToBus(SL_Bus_director_std_msgs_Float64* busPtr, std_msgs::Float64 const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Float64");

  busPtr->Data =  msgPtr->data;
}


// Conversions between SL_Bus_director_std_msgs_Int8 and std_msgs::Int8

void convertFromBus(std_msgs::Int8* msgPtr, SL_Bus_director_std_msgs_Int8 const* busPtr)
{
  const std::string rosMessageType("std_msgs/Int8");

  msgPtr->data =  busPtr->Data;
}

void convertToBus(SL_Bus_director_std_msgs_Int8* busPtr, std_msgs::Int8 const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Int8");

  busPtr->Data =  msgPtr->data;
}


// Conversions between SL_Bus_director_std_msgs_UInt8 and std_msgs::UInt8

void convertFromBus(std_msgs::UInt8* msgPtr, SL_Bus_director_std_msgs_UInt8 const* busPtr)
{
  const std::string rosMessageType("std_msgs/UInt8");

  msgPtr->data =  busPtr->Data;
}

void convertToBus(SL_Bus_director_std_msgs_UInt8* busPtr, std_msgs::UInt8 const* msgPtr)
{
  const std::string rosMessageType("std_msgs/UInt8");

  busPtr->Data =  msgPtr->data;
}

