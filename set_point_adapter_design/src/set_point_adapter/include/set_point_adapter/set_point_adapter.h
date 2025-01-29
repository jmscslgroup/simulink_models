//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: set_point_adapter.h
//
// Code generated for Simulink model 'set_point_adapter'.
//
// Model version                  : 6.3
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Jan 28 17:35:17 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_set_point_adapter_h_
#define RTW_HEADER_set_point_adapter_h_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "set_point_adapter_types.h"
#include <stddef.h>

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
struct B_set_point_adapter_T {
  SL_Bus_set_point_adapter_std_msgs_Float64 In1;// '<S6>/In1'
};

// Block states (default storage) for system '<Root>'
struct DW_set_point_adapter_T {
  ros_slroscpp_internal_block_P_T obj; // '<S4>/SinkBlock'
  ros_slroscpp_internal_block_P_T obj_g;// '<S3>/SinkBlock'
  ros_slroscpp_internal_block_S_T obj_gs;// '<S5>/SourceBlock'
};

// Parameters (default storage)
struct P_set_point_adapter_T_ {
  SL_Bus_set_point_adapter_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                              //  Referenced by: '<S1>/Constant'

  SL_Bus_set_point_adapter_std_msgs_Float64 Constant_Value_d;// Computed Parameter: Constant_Value_d
                                                                //  Referenced by: '<S2>/Constant'

  SL_Bus_set_point_adapter_std_msgs_Float64 Out1_Y0;// Computed Parameter: Out1_Y0
                                                       //  Referenced by: '<S6>/Out1'

  SL_Bus_set_point_adapter_std_msgs_Float64 Constant_Value_j;// Computed Parameter: Constant_Value_j
                                                                //  Referenced by: '<S5>/Constant'

  real_T Gain_Gain;                    // Expression: 0.44704
                                          //  Referenced by: '<Root>/Gain'

};

// Real-time Model Data Structure
struct tag_RTM_set_point_adapter_T {
  const char_T * volatile errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern P_set_point_adapter_T set_point_adapter_P;

#ifdef __cplusplus

}

#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C"
{

#endif

  extern struct B_set_point_adapter_T set_point_adapter_B;

#ifdef __cplusplus

}

#endif

// Block states (default storage)
extern struct DW_set_point_adapter_T set_point_adapter_DW;

#ifdef __cplusplus

extern "C"
{

#endif

  // Model entry point functions
  extern void set_point_adapter_initialize(void);
  extern void set_point_adapter_step(void);
  extern void set_point_adapter_terminate(void);

#ifdef __cplusplus

}

#endif

// Real-time Model object
#ifdef __cplusplus

extern "C"
{

#endif

  extern RT_MODEL_set_point_adapter_T *const set_point_adapter_M;

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
//  '<Root>' : 'set_point_adapter'
//  '<S1>'   : 'set_point_adapter/Blank Message1'
//  '<S2>'   : 'set_point_adapter/Blank Message2'
//  '<S3>'   : 'set_point_adapter/Publish1'
//  '<S4>'   : 'set_point_adapter/Publish2'
//  '<S5>'   : 'set_point_adapter/Subscribe1'
//  '<S6>'   : 'set_point_adapter/Subscribe1/Enabled Subsystem'

#endif                                 // RTW_HEADER_set_point_adapter_h_

//
// File trailer for generated code.
//
// [EOF]
//
