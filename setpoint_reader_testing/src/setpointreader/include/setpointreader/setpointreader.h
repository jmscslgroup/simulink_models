//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: setpointreader.h
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
#ifndef RTW_HEADER_setpointreader_h_
#define RTW_HEADER_setpointreader_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "setpointreader_types.h"
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_setpointreader_T {
  SL_Bus_setpointreader_geometry_msgs_Twist BusAssignment;// '<Root>/Bus Assignment' 
  SL_Bus_setpointreader_geometry_msgs_Point In1;// '<S6>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_setpointreader_T {
  ros_slroscpp_internal_block_P_T obj; // '<S4>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_h;// '<S3>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_g;// '<S5>/SourceBlock'
};

// Parameters (default storage)
struct P_setpointreader_T_ {
  SL_Bus_setpointreader_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                              //  Referenced by: '<S1>/Constant'

  SL_Bus_setpointreader_geometry_msgs_Point Out1_Y0;// Computed Parameter: Out1_Y0
                                                       //  Referenced by: '<S6>/Out1'

  SL_Bus_setpointreader_geometry_msgs_Point Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                                //  Referenced by: '<S5>/Constant'

  SL_Bus_setpointreader_std_msgs_Float64 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                             //  Referenced by: '<S2>/Constant'

  real_T Gain_Gain;                    // Expression: 0.27777
                                          //  Referenced by: '<Root>/Gain'

};

// Real-time Model Data Structure
struct tag_RTM_setpointreader_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_setpointreader_T setpointreader_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_setpointreader_T setpointreader_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_setpointreader_T setpointreader_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void setpointreader_initialize(void);
  extern void setpointreader_step(void);
  extern void setpointreader_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_setpointreader_T *const setpointreader_M;

#ifdef __cplusplus

}

#endif

extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
//  '<Root>' : 'setpointreader'
//  '<S1>'   : 'setpointreader/Blank Message'
//  '<S2>'   : 'setpointreader/Blank Message2'
//  '<S3>'   : 'setpointreader/Publish'
//  '<S4>'   : 'setpointreader/Publish1'
//  '<S5>'   : 'setpointreader/Subscribe1'
//  '<S6>'   : 'setpointreader/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_setpointreader_h_

//
// File trailer for generated code.
//
// [EOF]
//
