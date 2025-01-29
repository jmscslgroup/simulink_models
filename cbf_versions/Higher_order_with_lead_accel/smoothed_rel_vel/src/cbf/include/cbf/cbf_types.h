//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: cbf_types.h
//
// Code generated for Simulink model 'cbf'.
//
// Model version                  : 8.10
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Jan 28 20:44:23 2025
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

#ifndef struct_h_dsp_internal_SlidingWindowA_T
#define struct_h_dsp_internal_SlidingWindowA_T

struct h_dsp_internal_SlidingWindowA_T
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[3];
  real_T pCumRevIndex;
  real_T pModValueRev;
};

#endif                                // struct_h_dsp_internal_SlidingWindowA_T

#ifndef struct_cell_wrap_cbf_T
#define struct_cell_wrap_cbf_T

struct cell_wrap_cbf_T
{
  uint32_T f1[8];
};

#endif                                 // struct_cell_wrap_cbf_T

#ifndef struct_dsp_simulink_MovingAverage_cb_T
#define struct_dsp_simulink_MovingAverage_cb_T

struct dsp_simulink_MovingAverage_cb_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_cbf_T inputVarSize;
  h_dsp_internal_SlidingWindowA_T *pStatistic;
  int32_T NumChannels;
  int32_T FrameLength;
  h_dsp_internal_SlidingWindowA_T _pobj0;
};

#endif                                // struct_dsp_simulink_MovingAverage_cb_T

#ifndef struct_h_dsp_internal_SlidingWindo_h_T
#define struct_h_dsp_internal_SlidingWindo_h_T

struct h_dsp_internal_SlidingWindo_h_T
{
  int32_T isInitialized;
  boolean_T isSetupComplete;
  real_T pCumSum;
  real_T pCumSumRev[10];
  real_T pCumRevIndex;
  real_T pModValueRev;
};

#endif                                // struct_h_dsp_internal_SlidingWindo_h_T

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

#ifndef struct_dsp_simulink_MovingAverage_h_T
#define struct_dsp_simulink_MovingAverage_h_T

struct dsp_simulink_MovingAverage_h_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  boolean_T TunablePropsChanged;
  cell_wrap_cbf_T inputVarSize;
  h_dsp_internal_SlidingWindo_h_T *pStatistic;
  int32_T NumChannels;
  int32_T FrameLength;
  h_dsp_internal_SlidingWindo_h_T _pobj0;
};

#endif                                 // struct_dsp_simulink_MovingAverage_h_T

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
