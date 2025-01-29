//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: setpointreader_types.h
//
// Code generated for Simulink model 'setpointreader'.
//
// Model version                  : 6.0
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Jan 28 11:52:32 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_setpointreader_types_h_
#define RTW_HEADER_setpointreader_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_setpointreader_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_setpointreader_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_setpointreader_geometry_msgs_Vector3
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_setpointreader_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_setpointreader_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
struct SL_Bus_setpointreader_geometry_msgs_Twist
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_setpointreader_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_setpointreader_geometry_msgs_Vector3 Angular;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_setpointreader_std_msgs_Float64_
#define DEFINED_TYPEDEF_FOR_SL_Bus_setpointreader_std_msgs_Float64_

// MsgType=std_msgs/Float64
struct SL_Bus_setpointreader_std_msgs_Float64
{
  real_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_setpointreader_geometry_msgs_Point_
#define DEFINED_TYPEDEF_FOR_SL_Bus_setpointreader_geometry_msgs_Point_

// MsgType=geometry_msgs/Point
struct SL_Bus_setpointreader_geometry_msgs_Point
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef struct_ros_slroscpp_internal_block_P_T
#define struct_ros_slroscpp_internal_block_P_T

struct ros_slroscpp_internal_block_P_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_P_T

#ifndef struct_ros_slroscpp_internal_block_S_T
#define struct_ros_slroscpp_internal_block_S_T

struct ros_slroscpp_internal_block_S_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                // struct_ros_slroscpp_internal_block_S_T

// Parameters (default storage)
typedef struct P_setpointreader_T_ P_setpointreader_T;

// Forward declaration for rtModel
typedef struct tag_RTM_setpointreader_T RT_MODEL_setpointreader_T;

#endif                                 // RTW_HEADER_setpointreader_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
