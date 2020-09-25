/*
 * director_private.h
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

#ifndef RTW_HEADER_director_private_h_
#define RTW_HEADER_director_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Exported functions */
extern void director_initQueue(Queue_real_T *q, QueuePolicy_T policy, int32_T
  capacity, Msg_real_T *qPool);
extern Msg_real_T director_createMsg(const real_T *data);
extern int32_T director_size(const Queue_real_T *q);
extern boolean_T director_push(Queue_real_T *q, const Msg_real_T *element);
extern int32_T director_Chart_In1_SendData(const real_T *data);
extern int32_T director_Chart_In2_SendData(const real_T *data);
extern boolean_T director_pop(Queue_real_T *q, Msg_real_T *elementOut);
extern Msg_real_T *director_Chart_In2_RecvMsg(void);
extern Msg_real_T *director_Chart_In1_RecvMsg(void);

#endif                                 /* RTW_HEADER_director_private_h_ */
