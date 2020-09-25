/*
 * director.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "director".
 *
 * Model version              : 1.60
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Fri Sep 25 11:31:32 2020
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_director_h_
#define RTW_HEADER_director_h_
#include <string.h>
#include <stddef.h>
#include <stddef.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "slros_initialize.h"
#include "director_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_i32zcfcn.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Block signals (default storage) */
typedef struct {
  real_T previous;                     /* '<Root>/sendPrevious' */
  real_T next;                         /* '<Root>/sendNext' */
  real_T setpoint;                     /* '<Root>/Chart' */
  SL_Bus_director_std_msgs_Int8 In1;   /* '<S10>/In1' */
  uint8_T mode;                        /* '<Root>/Chart' */
  uint8_T feedback_type;               /* '<Root>/Chart' */
} B_director_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  ros_slros_internal_block_Publ_T obj; /* '<S13>/SinkBlock' */
  ros_slros_internal_block_Publ_T obj_k;/* '<S11>/SinkBlock' */
  ros_slros_internal_block_Publ_T obj_d;/* '<S8>/SinkBlock' */
  ros_slros_internal_block_Subs_T obj_p;/* '<S3>/SourceBlock' */
  real_T previous_msgData;             /* '<Root>/sendPrevious' */
  real_T next_msgData;                 /* '<Root>/sendNext' */
  real_T sp[7];                        /* '<Root>/Chart' */
  real_T next_msgData_h;               /* '<Root>/Chart' */
  real_T previous_msgData_g;           /* '<Root>/Chart' */
  Msg_real_T Queue_InsertedFor_Chart_at_inpo[10];/* synthesized block */
  Msg_real_T Queue_InsertedFor_Chart_at_in_o;/* synthesized block */
  Msg_real_T Queue_InsertedFor_Chart_at_in_h[10];/* synthesized block */
  Msg_real_T Queue_InsertedFor_Chart_at_in_n;/* synthesized block */
  Queue_real_T Queue_InsertedFor_Chart_at_in_e;/* synthesized block */
  Queue_real_T Queue_InsertedFor_Chart_at_i_ox;/* synthesized block */
  void* previous_msgInterface;         /* '<Root>/sendPrevious' */
  void* next_msgInterface;             /* '<Root>/sendNext' */
  void* next_msgInterface_o;           /* '<Root>/Chart' */
  void* next_msgHandle;                /* '<Root>/Chart' */
  void* next_msgDataPtr;               /* '<Root>/Chart' */
  void* previous_msgInterface_p;       /* '<Root>/Chart' */
  void* previous_msgHandle;            /* '<Root>/Chart' */
  void* previous_msgDataPtr;           /* '<Root>/Chart' */
  uint16_T temporalCounter_i1;         /* '<Root>/Chart' */
  uint8_T is_active_c5_director;       /* '<Root>/sendPrevious' */
  uint8_T is_active_c4_director;       /* '<Root>/sendNext' */
  uint8_T is_active_c1_director;       /* '<Root>/Chart' */
  uint8_T is_c1_director;              /* '<Root>/Chart' */
  uint8_T sp_index;                    /* '<Root>/Chart' */
  boolean_T objisempty;                /* '<S13>/SinkBlock' */
  boolean_T objisempty_l;              /* '<S11>/SinkBlock' */
  boolean_T objisempty_d;              /* '<S3>/SourceBlock' */
  boolean_T objisempty_o;              /* '<S8>/SinkBlock' */
  boolean_T next_isValid;              /* '<Root>/Chart' */
  boolean_T previous_isValid;          /* '<Root>/Chart' */
} DW_director_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState sendPrevious_Trig_ZCE;    /* '<Root>/sendPrevious' */
  ZCSigState sendNext_Trig_ZCE;        /* '<Root>/sendNext' */
} PrevZCX_director_T;

/* Parameters (default storage) */
struct P_director_T_ {
  SL_Bus_director_std_msgs_Float64 Constant_Value;/* Computed Parameter: Constant_Value
                                                   * Referenced by: '<S9>/Constant'
                                                   */
  SL_Bus_director_std_msgs_Int8 Out1_Y0;/* Computed Parameter: Out1_Y0
                                         * Referenced by: '<S10>/Out1'
                                         */
  SL_Bus_director_std_msgs_Int8 Constant_Value_n;/* Computed Parameter: Constant_Value_n
                                                  * Referenced by: '<S3>/Constant'
                                                  */
  SL_Bus_director_std_msgs_UInt8 Constant_Value_l;/* Computed Parameter: Constant_Value_l
                                                   * Referenced by: '<S12>/Constant'
                                                   */
  SL_Bus_director_std_msgs_UInt8 Constant_Value_h;/* Computed Parameter: Constant_Value_h
                                                   * Referenced by: '<S14>/Constant'
                                                   */
};

/* Real-time Model Data Structure */
struct tag_RTM_director_T {
  const char_T *errorStatus;
};

/* Block parameters (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern P_director_T director_P;

#ifdef __cplusplus

}
#endif

/* Block signals (default storage) */
#ifdef __cplusplus

extern "C" {

#endif

  extern B_director_T director_B;

#ifdef __cplusplus

}
#endif

/* Block states (default storage) */
extern DW_director_T director_DW;

/* Zero-crossing (trigger) state */
extern PrevZCX_director_T director_PrevZCX;

#ifdef __cplusplus

extern "C" {

#endif

  /* Model entry point functions */
  extern void director_initialize(void);
  extern void director_step(void);
  extern void director_terminate(void);

#ifdef __cplusplus

}
#endif

/* Real-time Model object */
#ifdef __cplusplus

extern "C" {

#endif

  extern RT_MODEL_director_T *const director_M;

#ifdef __cplusplus

}
#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Data Type Conversion' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'director'
 * '<S1>'   : 'director/Chart'
 * '<S2>'   : 'director/Setpoint Publisher'
 * '<S3>'   : 'director/Subscribe2'
 * '<S4>'   : 'director/feedback_type Publisher'
 * '<S5>'   : 'director/mode publisher'
 * '<S6>'   : 'director/sendNext'
 * '<S7>'   : 'director/sendPrevious'
 * '<S8>'   : 'director/Setpoint Publisher/Publish1'
 * '<S9>'   : 'director/Setpoint Publisher/setpoint'
 * '<S10>'  : 'director/Subscribe2/Enabled Subsystem'
 * '<S11>'  : 'director/feedback_type Publisher/Publish2'
 * '<S12>'  : 'director/feedback_type Publisher/setpoint1'
 * '<S13>'  : 'director/mode publisher/Publish'
 * '<S14>'  : 'director/mode publisher/mode'
 */
#endif                                 /* RTW_HEADER_director_h_ */
