/*
 * rt_i32zcfcn.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "director".
 *
 * Model version              : 1.59
 * Simulink Coder version : 9.3 (R2020a) 18-Nov-2019
 * C++ source code generated on : Fri Sep 25 11:30:16 2020
 */

#ifndef RTW_HEADER_rt_i32zcfcn_h_
#define RTW_HEADER_rt_i32zcfcn_h_
#include "rtwtypes.h"
#include "solver_zc.h"
#ifndef slZcHadEvent
#define slZcHadEvent(ev, zcsDir)       (((ev) & (zcsDir)) != 0x00 )
#endif

#ifndef slZcUnAliasEvents
#define slZcUnAliasEvents(evL, evR)    ((((slZcHadEvent((evL), (SL_ZCS_EVENT_N2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2P))) || (slZcHadEvent((evL), (SL_ZCS_EVENT_P2Z)) && slZcHadEvent((evR), (SL_ZCS_EVENT_Z2N)))) ? (SL_ZCS_EVENT_NUL) : (evR)))
#endif

#ifdef __cplusplus

extern "C" {

#endif

  extern ZCEventType rt_I32ZCFcn(ZCDirection zcDir, ZCSigState *prevZc, int32_T
    currValue);

#ifdef __cplusplus

}                                      /* extern "C" */
#endif
#endif                                 /* RTW_HEADER_rt_i32zcfcn_h_ */
