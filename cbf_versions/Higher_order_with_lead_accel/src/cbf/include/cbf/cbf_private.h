//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: cbf_private.h
//
// Code generated for Simulink model 'cbf'.
//
// Model version                  : 8.10
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Jan 28 16:45:02 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#ifndef RTW_HEADER_cbf_private_h_
#define RTW_HEADER_cbf_private_h_
#include "rtwtypes.h"
#include "cbf.h"
#include "cbf_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"

// Private macros used by the generated code to access rtModel
#ifndef rtmIsMajorTimeStep
#define rtmIsMajorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
#define rtmIsMinorTimeStep(rtm)        (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmSetTPtr
#define rtmSetTPtr(rtm, val)           ((rtm)->Timing.t = (val))
#endif

extern void cbf_MovingAverage_Init(DW_MovingAverage_cbf_T *localDW);
extern void cbf_MovingAverage(real_T rtu_0, B_MovingAverage_cbf_T *localB,
  DW_MovingAverage_cbf_T *localDW);
extern void cbf_MovingAverage_Term(DW_MovingAverage_cbf_T *localDW);

#endif                                 // RTW_HEADER_cbf_private_h_

//
// File trailer for generated code.
//
// [EOF]
//
