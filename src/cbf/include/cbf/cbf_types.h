//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: cbf_types.h
//
// Code generated for Simulink model 'cbf'.
//
// Model version                  : 7.3
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Thu Oct 12 14:21:34 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_cbf_types_h_
#define RTW_HEADER_cbf_types_h_
#include "rtwtypes.h"
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_cbf_std_msgs_Float64_
#define DEFINED_TYPEDEF_FOR_SL_Bus_cbf_std_msgs_Float64_

// MsgType=std_msgs/Float64
struct SL_Bus_cbf_std_msgs_Float64
{
  real_T Data;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_cbf_geometry_msgs_Vector3_
#define DEFINED_TYPEDEF_FOR_SL_Bus_cbf_geometry_msgs_Vector3_

// MsgType=geometry_msgs/Vector3
struct SL_Bus_cbf_geometry_msgs_Vector3
{
  real_T X;
  real_T Y;
  real_T Z;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_cbf_geometry_msgs_Twist_
#define DEFINED_TYPEDEF_FOR_SL_Bus_cbf_geometry_msgs_Twist_

// MsgType=geometry_msgs/Twist
struct SL_Bus_cbf_geometry_msgs_Twist
{
  // MsgType=geometry_msgs/Vector3
  SL_Bus_cbf_geometry_msgs_Vector3 Linear;

  // MsgType=geometry_msgs/Vector3
  SL_Bus_cbf_geometry_msgs_Vector3 Angular;
};

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_cbf_std_msgs_Bool_
#define DEFINED_TYPEDEF_FOR_SL_Bus_cbf_std_msgs_Bool_

// MsgType=std_msgs/Bool
struct SL_Bus_cbf_std_msgs_Bool
{
  boolean_T Data;
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

#ifndef struct_f_robotics_slcore_internal_bl_T
#define struct_f_robotics_slcore_internal_bl_T

struct f_robotics_slcore_internal_bl_T
{
  int32_T __dummy;
};

#endif                                // struct_f_robotics_slcore_internal_bl_T

#ifndef struct_ros_slros_internal_block_GetP_T
#define struct_ros_slros_internal_block_GetP_T

struct ros_slros_internal_block_GetP_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  f_robotics_slcore_internal_bl_T SampleTimeHandler;
};

#endif                                // struct_ros_slros_internal_block_GetP_T

// Parameters (default storage)
typedef struct P_cbf_T_ P_cbf_T;

// Forward declaration for rtModel
typedef struct tag_RTM_cbf_T RT_MODEL_cbf_T;

#endif                                 // RTW_HEADER_cbf_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
