//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: cbf.h
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
#ifndef RTW_HEADER_cbf_h_
#define RTW_HEADER_cbf_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "cbf_types.h"

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

// Block signals for system '<Root>/Moving Average'
struct B_MovingAverage_cbf_T {
  real_T MovingAverage;                // '<Root>/Moving Average'
};

// Block states (default storage) for system '<Root>/Moving Average'
struct DW_MovingAverage_cbf_T {
  dsp_simulink_MovingAverage_cb_T obj; // '<Root>/Moving Average'
  boolean_T objisempty;                // '<Root>/Moving Average'
};

// Block signals (default storage)
struct B_cbf_T {
  real_T csumrev[10];
  SL_Bus_cbf_geometry_msgs_Twist BusAssignment2;// '<Root>/Bus Assignment2'
  char_T b_zeroDelimTopic[25];
  char_T b_zeroDelimTopic_m[18];
  char_T b_zeroDelimTopic_c[17];
  char_T b_zeroDelimTopic_k[15];
  char_T b_zeroDelimTopic_cx[14];
  real_T d;
  real_T cumRevIndex;
  real_T csum;
  real_T modValueRev;
  real_T z;
  real_T b_value;
  real_T Derivative1;                  // '<Root>/Derivative1'
  real_T d1;
  SL_Bus_cbf_std_msgs_Float64 In1;     // '<S21>/In1'
  SL_Bus_cbf_std_msgs_Float64 In1_f;   // '<S20>/In1'
  SL_Bus_cbf_std_msgs_Float64 In1_g;   // '<S19>/In1'
  SL_Bus_cbf_std_msgs_Float64 In1_m;   // '<S18>/In1'
  SL_Bus_cbf_std_msgs_Float64 In1_j;   // '<S17>/In1'
  SL_Bus_cbf_std_msgs_Float64 b_varargout_2;
  SL_Bus_cbf_std_msgs_Float64 BusAssignment1;// '<Root>/Bus Assignment1'
  int32_T i;
  boolean_T b_varargout_1;
  SL_Bus_cbf_std_msgs_Bool b_varargout_2_b;
  B_MovingAverage_cbf_T MovingAverage1;// '<Root>/Moving Average'
  B_MovingAverage_cbf_T MovingAverage; // '<Root>/Moving Average'
};

// Block states (default storage) for system '<Root>'
struct DW_cbf_T {
  dsp_simulink_MovingAverage_h_T obj;  // '<Root>/Moving Average2'
  ros_slros_internal_block_GetP_T obj_l;// '<S16>/Get Parameter7'
  ros_slros_internal_block_GetP_T obj_lb;// '<S16>/Get Parameter5'
  ros_slros_internal_block_GetP_T obj_b;// '<S16>/Get Parameter4'
  ros_slros_internal_block_GetP_T obj_m;// '<S16>/Get Parameter3'
  ros_slros_internal_block_GetP_T obj_n;// '<S16>/Get Parameter2'
  ros_slroscpp_internal_block_P_T obj_d;// '<S9>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_h;// '<S8>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_ni;// '<S7>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_ng;// '<S6>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_p;// '<S5>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_bu;// '<S15>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_f;// '<S14>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_o;// '<S13>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_j;// '<S12>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_i;// '<S11>/SourceBlock'
  ros_slroscpp_internal_block_S_T obj_c;// '<S10>/SourceBlock'
  real_T TimeStampA;                   // '<Root>/Derivative1'
  real_T LastUAtTimeA;                 // '<Root>/Derivative1'
  real_T TimeStampB;                   // '<Root>/Derivative1'
  real_T LastUAtTimeB;                 // '<Root>/Derivative1'
  real_T TimeStampA_h;                 // '<Root>/Derivative'
  real_T LastUAtTimeA_k;               // '<Root>/Derivative'
  real_T TimeStampB_e;                 // '<Root>/Derivative'
  real_T LastUAtTimeB_l;               // '<Root>/Derivative'
  boolean_T relative_distance_prev_not_empt;// '<Root>/MATLAB Function1'
  DW_MovingAverage_cbf_T MovingAverage1;// '<Root>/Moving Average'
  DW_MovingAverage_cbf_T MovingAverage;// '<Root>/Moving Average'
};

// Parameters (default storage)
struct P_cbf_T_ {
  SL_Bus_cbf_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                   //  Referenced by: '<S2>/Constant'

  SL_Bus_cbf_geometry_msgs_Twist Constant_Value_i;// Computed Parameter: Constant_Value_i
                                                     //  Referenced by: '<S3>/Constant'

  SL_Bus_cbf_std_msgs_Bool Out1_Y0;    // Computed Parameter: Out1_Y0
                                          //  Referenced by: '<S22>/Out1'

  SL_Bus_cbf_std_msgs_Bool Constant_Value_o;// Computed Parameter: Constant_Value_o
                                               //  Referenced by: '<S15>/Constant'

  SL_Bus_cbf_std_msgs_Float64 Constant_Value_e;// Computed Parameter: Constant_Value_e
                                                  //  Referenced by: '<S1>/Constant'

  SL_Bus_cbf_std_msgs_Float64 Out1_Y0_e;// Computed Parameter: Out1_Y0_e
                                           //  Referenced by: '<S17>/Out1'

  SL_Bus_cbf_std_msgs_Float64 Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                  //  Referenced by: '<S10>/Constant'

  SL_Bus_cbf_std_msgs_Float64 Out1_Y0_m;// Computed Parameter: Out1_Y0_m
                                           //  Referenced by: '<S18>/Out1'

  SL_Bus_cbf_std_msgs_Float64 Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                  //  Referenced by: '<S11>/Constant'

  SL_Bus_cbf_std_msgs_Float64 Out1_Y0_ea;// Computed Parameter: Out1_Y0_ea
                                            //  Referenced by: '<S19>/Out1'

  SL_Bus_cbf_std_msgs_Float64 Constant_Value_f;// Computed Parameter: Constant_Value_f
                                                  //  Referenced by: '<S12>/Constant'

  SL_Bus_cbf_std_msgs_Float64 Out1_Y0_c;// Computed Parameter: Out1_Y0_c
                                           //  Referenced by: '<S20>/Out1'

  SL_Bus_cbf_std_msgs_Float64 Constant_Value_ne;// Computed Parameter: Constant_Value_ne
                                                   //  Referenced by: '<S13>/Constant'

  SL_Bus_cbf_std_msgs_Float64 Out1_Y0_p;// Computed Parameter: Out1_Y0_p
                                           //  Referenced by: '<S21>/Out1'

  SL_Bus_cbf_std_msgs_Float64 Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                  //  Referenced by: '<S14>/Constant'

  real_T Constant2_Value;              // Expression: 1.0
                                          //  Referenced by: '<Root>/Constant2'

  real_T Switch_Threshold;             // Expression: 0.5
                                          //  Referenced by: '<Root>/Switch'

  real_T minmax1550_UpperSat;          // Expression: 1.5
                                          //  Referenced by: '<Root>/min//max 1.5//-5.0'

  real_T minmax1550_LowerSat;          // Expression: -5.0
                                          //  Referenced by: '<Root>/min//max 1.5//-5.0'

  real_T Constant_Value_jt;            // Expression: 0
                                          //  Referenced by: '<Root>/Constant'

  real_T Constant3_Value;              // Expression: 0
                                          //  Referenced by: '<Root>/Constant3'

  real_T Constant1_Value;              // Expression: 5
                                          //  Referenced by: '<Root>/Constant1'

};

// Real-time Model Data Structure
struct tag_RTM_cbf_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;

  //
  //  Timing:
  //  The following substructure contains information regarding
  //  the timing information for the model.

  struct {
    uint32_T clockTick0;
    time_T stepSize0;
    uint32_T clockTick1;
    SimTimeStep simTimeStep;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_cbf_T cbf_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_cbf_T cbf_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_cbf_T cbf_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void cbf_initialize(void);
  extern void cbf_step(void);
  extern void cbf_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_cbf_T *const cbf_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Scope' : Unused code path elimination


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'cbf'
//  '<S1>'   : 'cbf/Blank Message1'
//  '<S2>'   : 'cbf/Blank Message2'
//  '<S3>'   : 'cbf/Blank Message3'
//  '<S4>'   : 'cbf/MATLAB Function1'
//  '<S5>'   : 'cbf/Publish1'
//  '<S6>'   : 'cbf/Publish2'
//  '<S7>'   : 'cbf/Publish3'
//  '<S8>'   : 'cbf/Publish4'
//  '<S9>'   : 'cbf/Publish5'
//  '<S10>'  : 'cbf/Subscribe'
//  '<S11>'  : 'cbf/Subscribe1'
//  '<S12>'  : 'cbf/Subscribe2'
//  '<S13>'  : 'cbf/Subscribe3'
//  '<S14>'  : 'cbf/Subscribe6'
//  '<S15>'  : 'cbf/Subscribe7'
//  '<S16>'  : 'cbf/cbf_filter'
//  '<S17>'  : 'cbf/Subscribe/Enabled Subsystem'
//  '<S18>'  : 'cbf/Subscribe1/Enabled Subsystem'
//  '<S19>'  : 'cbf/Subscribe2/Enabled Subsystem'
//  '<S20>'  : 'cbf/Subscribe3/Enabled Subsystem'
//  '<S21>'  : 'cbf/Subscribe6/Enabled Subsystem'
//  '<S22>'  : 'cbf/Subscribe7/Enabled Subsystem'
//  '<S23>'  : 'cbf/cbf_filter/MATLAB Function1'

#endif                                 // RTW_HEADER_cbf_h_

//
// File trailer for generated code.
//
// [EOF]
//
