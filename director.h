//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: director.h
//
// Code generated for Simulink model 'director'.
//
// Model version                  : 1.50
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Tue Sep 22 13:47:24 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_director_h_
#define RTW_HEADER_director_h_
#include <stddef.h>
#include "rtwtypes.h"
#include "slros_initialize.h"
#include "director_types.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Block signals (default storage)
typedef struct {
  real_T setpoint;                     // '<Root>/Chart'
  SL_Bus_director_std_msgs_Int8 In1;   // '<S8>/In1'
  uint8_T mode;                        // '<Root>/Chart'
  uint8_T feedback_type;               // '<Root>/Chart'
} B_director_T;

// Block states (default storage) for system '<Root>'
typedef struct {
  ros_slros_internal_block_Publ_T obj; // '<S11>/SinkBlock'
  ros_slros_internal_block_Publ_T obj_k;// '<S9>/SinkBlock'
  ros_slros_internal_block_Publ_T obj_d;// '<S6>/SinkBlock'
  ros_slros_internal_block_Subs_T obj_p;// '<S3>/SourceBlock'
  real_T sp[7];                        // '<Root>/Chart'
  uint16_T temporalCounter_i1;         // '<Root>/Chart'
  uint8_T is_active_c1_director;       // '<Root>/Chart'
  uint8_T is_c1_director;              // '<Root>/Chart'
  uint8_T sp_index;                    // '<Root>/Chart'
} DW_director_T;

// Parameters (default storage)
struct P_director_T_ {
  SL_Bus_director_std_msgs_Float64 Constant_Value;// Computed Parameter: Constant_Value
                                                     //  Referenced by: '<S7>/Constant'

  SL_Bus_director_std_msgs_Int8 Out1_Y0;// Computed Parameter: Out1_Y0
                                           //  Referenced by: '<S8>/Out1'

  SL_Bus_director_std_msgs_Int8 Constant_Value_n;// Computed Parameter: Constant_Value_n
                                                    //  Referenced by: '<S3>/Constant'

  SL_Bus_director_std_msgs_UInt8 Constant_Value_l;// Computed Parameter: Constant_Value_l
                                                     //  Referenced by: '<S10>/Constant'

  SL_Bus_director_std_msgs_UInt8 Constant_Value_h;// Computed Parameter: Constant_Value_h
                                                     //  Referenced by: '<S12>/Constant'

};

// Real-time Model Data Structure
struct tag_RTM_director_T {
  const char_T *errorStatus;
};

// Block parameters (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern P_director_T director_P;

#ifdef __cplusplus

}
#endif

// Block signals (default storage)
#ifdef __cplusplus

extern "C" {

#endif

  extern B_director_T director_B;

#ifdef __cplusplus

}
#endif

// Block states (default storage)
extern DW_director_T director_DW;

#ifdef __cplusplus

extern "C" {

#endif

  // Model entry point functions
  extern void director_initialize(void);
  extern void director_step(void);
  extern void director_terminate(void);

#ifdef __cplusplus

}
#endif

// Real-time Model object
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_director_T *const director_M;

#ifdef __cplusplus

}
#endif

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
//  '<Root>' : 'director'
//  '<S1>'   : 'director/Chart'
//  '<S2>'   : 'director/Setpoint Publisher'
//  '<S3>'   : 'director/Subscribe2'
//  '<S4>'   : 'director/feedback_type Publisher'
//  '<S5>'   : 'director/mode publisher'
//  '<S6>'   : 'director/Setpoint Publisher/Publish1'
//  '<S7>'   : 'director/Setpoint Publisher/setpoint'
//  '<S8>'   : 'director/Subscribe2/Enabled Subsystem'
//  '<S9>'   : 'director/feedback_type Publisher/Publish2'
//  '<S10>'  : 'director/feedback_type Publisher/setpoint1'
//  '<S11>'  : 'director/mode publisher/Publish'
//  '<S12>'  : 'director/mode publisher/mode'

#endif                                 // RTW_HEADER_director_h_

//
// File trailer for generated code.
//
// [EOF]
//
