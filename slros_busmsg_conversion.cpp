#include "slros_busmsg_conversion.h"


// Conversions between SL_Bus_mode_changer_geometry_msgs_Twist and geometry_msgs::Twist

void convertFromBus(geometry_msgs::Twist* msgPtr, SL_Bus_mode_changer_geometry_msgs_Twist const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertFromBus(&msgPtr->angular, &busPtr->Angular);
  convertFromBus(&msgPtr->linear, &busPtr->Linear);
}

void convertToBus(SL_Bus_mode_changer_geometry_msgs_Twist* busPtr, geometry_msgs::Twist const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  convertToBus(&busPtr->Angular, &msgPtr->angular);
  convertToBus(&busPtr->Linear, &msgPtr->linear);
}


// Conversions between SL_Bus_mode_changer_geometry_msgs_Vector3 and geometry_msgs::Vector3

void convertFromBus(geometry_msgs::Vector3* msgPtr, SL_Bus_mode_changer_geometry_msgs_Vector3 const* busPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  msgPtr->x =  busPtr->X;
  msgPtr->y =  busPtr->Y;
  msgPtr->z =  busPtr->Z;
}

void convertToBus(SL_Bus_mode_changer_geometry_msgs_Vector3* busPtr, geometry_msgs::Vector3 const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  busPtr->X =  msgPtr->x;
  busPtr->Y =  msgPtr->y;
  busPtr->Z =  msgPtr->z;
}


// Conversions between SL_Bus_mode_changer_std_msgs_Int8 and std_msgs::Int8

void convertFromBus(std_msgs::Int8* msgPtr, SL_Bus_mode_changer_std_msgs_Int8 const* busPtr)
{
  const std::string rosMessageType("std_msgs/Int8");

  msgPtr->data =  busPtr->Data;
}

void convertToBus(SL_Bus_mode_changer_std_msgs_Int8* busPtr, std_msgs::Int8 const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Int8");

  busPtr->Data =  msgPtr->data;
}

