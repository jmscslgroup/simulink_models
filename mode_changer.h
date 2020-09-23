//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mode_changer.h
//
// Code generated for Simulink model 'mode_changer'.
//
// Model version                  : 1.112
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Tue Sep 22 17:17:32 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_mode_changer_h_
#define RTW_HEADER_mode_changer_h_
#include <stddef.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "slros_initialize.h"
#include "mode_changer_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  SL_Bus_mode_changer_geometry_msgs_Twist In1;// '<S3>/In1'
} B_mode_changer_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slros_internal_block_Subs_T obj; // '<S1>/SourceBlock'
  ros_slros_internal_block_Publ_T obj_a;// '<S5>/SinkBlock'
  real_T n_toggle;                     // '<S2>/MATLAB Function'
  real_T n_high;                       // '<S2>/MATLAB Function'
  real_T previous;                     // '<S2>/MATLAB Function'
  boolean_T n_toggle_not_empty;        // '<S2>/MATLAB Function'
} DW_mode_changer_T;

// Zero-crossing (trigger) state
typedef struct {
  ZCSigState Subsystem_Trig_ZCE;       // '<Root>/Subsystem'
} PrevZCX_mode_changer_T;

// Parameters (default storage)
struct P_mode_changer_T_ {
  SL_Bus_mode_changer_geometry_msgs_Twist Out1_Y0;// Computed Parameter: Out1_Y0
                                                     //  Referenced by: '<S3>/Out1'

  SL_Bus_mode_changer_geometry_msgs_Twist Constant_Value;// Computed Parameter: Constant_Value
                                                            //  Referenced by: '<S1>/Constant'

  SL_Bus_mode_changer_std_msgs_Int8 Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                        //  Referenced by: '<S6>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_mode_changer_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_mode_changer_T mode_changer_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_mode_changer_T mode_changer_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_mode_changer_T mode_changer_DW;

// Zero-crossing (trigger) state
extern PrevZCX_mode_changer_T mode_changer_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void mode_changer_initialize(void);
  extern void mode_changer_step(void);
  extern void mode_changer_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_mode_changer_T *const mode_changer_M;

#ifdef __cplusplus

}
#endif

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S2>/Scope' : Unused code path elimination


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
//  '<Root>' : 'mode_changer'
//  '<S1>'   : 'mode_changer/Subscribe2'
//  '<S2>'   : 'mode_changer/Subsystem'
//  '<S3>'   : 'mode_changer/Subscribe2/Enabled Subsystem'
//  '<S4>'   : 'mode_changer/Subsystem/MATLAB Function'
//  '<S5>'   : 'mode_changer/Subsystem/Publish'
//  '<S6>'   : 'mode_changer/Subsystem/modeInput'

#endif                                 // RTW_HEADER_mode_changer_h_

//
// File trailer for generated code.
//
// [EOF]
//
