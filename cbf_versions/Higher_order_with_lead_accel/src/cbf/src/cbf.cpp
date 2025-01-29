//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: cbf.cpp
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
#include "cbf.h"
#include "rtwtypes.h"
#include "cbf_types.h"
#include "cbf_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

// Block signals (default storage)
B_cbf_T cbf_B;

// Block states (default storage)
DW_cbf_T cbf_DW;

// Real-time model
RT_MODEL_cbf_T cbf_M_ = RT_MODEL_cbf_T();
RT_MODEL_cbf_T *const cbf_M = &cbf_M_;

// Forward declaration for local functions
static void cbf_SystemCore_setup(dsp_simulink_MovingAverage_cb_T *obj);

// Forward declaration for local functions
static void cbf_SystemCore_setup_h(dsp_simulink_MovingAverage_h_T *obj);
static void cbf_SystemCore_setup(dsp_simulink_MovingAverage_cb_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;

  // Start for MATLABSystem: '<Root>/Moving Average'
  obj->NumChannels = 1;
  obj->FrameLength = 1;
  obj->_pobj0.isInitialized = 0;
  obj->_pobj0.isInitialized = 0;
  obj->pStatistic = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

// System initialize for atomic system:
void cbf_MovingAverage_Init(DW_MovingAverage_cbf_T *localDW)
{
  h_dsp_internal_SlidingWindowA_T *obj;

  // Start for MATLABSystem: '<Root>/Moving Average'
  localDW->obj.isInitialized = 0;
  localDW->obj.NumChannels = -1;
  localDW->obj.FrameLength = -1;
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  cbf_SystemCore_setup(&localDW->obj);

  // InitializeConditions for MATLABSystem: '<Root>/Moving Average'
  obj = localDW->obj.pStatistic;
  if (obj->isInitialized == 1) {
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  // End of InitializeConditions for MATLABSystem: '<Root>/Moving Average'
}

// Output and update for atomic system:
void cbf_MovingAverage(real_T rtu_0, B_MovingAverage_cbf_T *localB,
  DW_MovingAverage_cbf_T *localDW)
{
  h_dsp_internal_SlidingWindowA_T *obj;
  real_T csumrev[3];
  real_T csum;
  real_T cumRevIndex;
  real_T modValueRev;
  real_T z;

  // MATLABSystem: '<Root>/Moving Average'
  if (localDW->obj.TunablePropsChanged) {
    localDW->obj.TunablePropsChanged = false;
  }

  obj = localDW->obj.pStatistic;
  if (localDW->obj.pStatistic->isInitialized != 1) {
    localDW->obj.pStatistic->isSetupComplete = false;
    localDW->obj.pStatistic->isInitialized = 1;
    obj->pCumSum = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
    obj->isSetupComplete = true;
    obj->pCumSum = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[0] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[1] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumSumRev[2] = 0.0;
    obj->pCumRevIndex = 1.0;
    obj->pModValueRev = 0.0;
  }

  cumRevIndex = obj->pCumRevIndex;
  csum = obj->pCumSum;
  csumrev[0] = obj->pCumSumRev[0];
  csumrev[1] = obj->pCumSumRev[1];
  csumrev[2] = obj->pCumSumRev[2];
  modValueRev = obj->pModValueRev;
  z = 0.0;

  // MATLABSystem: '<Root>/Moving Average'
  localB->MovingAverage = 0.0;

  // MATLABSystem: '<Root>/Moving Average'
  csum += rtu_0;
  if (modValueRev == 0.0) {
    z = csumrev[static_cast<int32_T>(cumRevIndex) - 1] + csum;
  }

  csumrev[static_cast<int32_T>(cumRevIndex) - 1] = rtu_0;
  if (cumRevIndex != 3.0) {
    cumRevIndex++;
  } else {
    cumRevIndex = 1.0;
    csum = 0.0;
    csumrev[1] += csumrev[2];
    csumrev[0] += csumrev[1];
  }

  if (modValueRev == 0.0) {
    // MATLABSystem: '<Root>/Moving Average'
    localB->MovingAverage = z / 4.0;
  }

  obj->pCumSum = csum;
  obj->pCumSumRev[0] = csumrev[0];
  obj->pCumSumRev[1] = csumrev[1];
  obj->pCumSumRev[2] = csumrev[2];
  obj->pCumRevIndex = cumRevIndex;
  if (modValueRev > 0.0) {
    obj->pModValueRev = modValueRev - 1.0;
  } else {
    obj->pModValueRev = 0.0;
  }
}

// Termination for atomic system:
void cbf_MovingAverage_Term(DW_MovingAverage_cbf_T *localDW)
{
  h_dsp_internal_SlidingWindowA_T *obj;

  // Terminate for MATLABSystem: '<Root>/Moving Average'
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1) && localDW->obj.isSetupComplete) {
      obj = localDW->obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      localDW->obj.NumChannels = -1;
      localDW->obj.FrameLength = -1;
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/Moving Average'
}

static void cbf_SystemCore_setup_h(dsp_simulink_MovingAverage_h_T *obj)
{
  obj->isSetupComplete = false;
  obj->isInitialized = 1;

  // Start for MATLABSystem: '<Root>/Moving Average2'
  obj->NumChannels = 1;
  obj->FrameLength = 1;
  obj->_pobj0.isInitialized = 0;
  obj->_pobj0.isInitialized = 0;
  obj->pStatistic = &obj->_pobj0;
  obj->isSetupComplete = true;
  obj->TunablePropsChanged = false;
}

// Model step function
void cbf_step(void)
{
  {
    h_dsp_internal_SlidingWindo_h_T *obj;
    real_T *lastU;

    // Outputs for Atomic SubSystem: '<Root>/Subscribe6'
    // MATLABSystem: '<S14>/SourceBlock'
    cbf_B.b_varargout_1 = Sub_cbf_551.getLatestMessage(&cbf_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S14>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S21>/Enable'

    // Start for MATLABSystem: '<S14>/SourceBlock'
    if (cbf_B.b_varargout_1) {
      // SignalConversion generated from: '<S21>/In1'
      cbf_B.In1 = cbf_B.b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S14>/SourceBlock'
    // End of Outputs for SubSystem: '<S14>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe6'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // MATLABSystem: '<S10>/SourceBlock'
    cbf_B.b_varargout_1 = Sub_cbf_547.getLatestMessage(&cbf_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S10>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S17>/Enable'

    // Start for MATLABSystem: '<S10>/SourceBlock'
    if (cbf_B.b_varargout_1) {
      // SignalConversion generated from: '<S17>/In1'
      cbf_B.In1_j = cbf_B.b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S10>/SourceBlock'
    // End of Outputs for SubSystem: '<S10>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe3'
    // MATLABSystem: '<S13>/SourceBlock'
    cbf_B.b_varargout_1 = Sub_cbf_634.getLatestMessage(&cbf_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S13>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S20>/Enable'

    // Start for MATLABSystem: '<S13>/SourceBlock'
    if (cbf_B.b_varargout_1) {
      // SignalConversion generated from: '<S20>/In1'
      cbf_B.In1_f = cbf_B.b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S13>/SourceBlock'
    // End of Outputs for SubSystem: '<S13>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe3'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S11>/SourceBlock'
    cbf_B.b_varargout_1 = Sub_cbf_548.getLatestMessage(&cbf_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S11>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S18>/Enable'

    // Start for MATLABSystem: '<S11>/SourceBlock'
    if (cbf_B.b_varargout_1) {
      // SignalConversion generated from: '<S18>/In1'
      cbf_B.In1_m = cbf_B.b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S11>/SourceBlock'
    // End of Outputs for SubSystem: '<S11>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'
    cbf_MovingAverage(cbf_B.In1_m.Data, &cbf_B.MovingAverage1,
                      &cbf_DW.MovingAverage1);

    // Derivative: '<Root>/Derivative1' incorporates:
    //   Derivative: '<Root>/Derivative'

    cbf_B.Derivative = cbf_M->Timing.t[0];
    if ((cbf_DW.TimeStampA >= cbf_B.Derivative) && (cbf_DW.TimeStampB >=
         cbf_B.Derivative)) {
      cbf_B.Derivative1 = 0.0;
    } else {
      cbf_B.u = cbf_DW.TimeStampA;
      lastU = &cbf_DW.LastUAtTimeA;
      if (cbf_DW.TimeStampA < cbf_DW.TimeStampB) {
        if (cbf_DW.TimeStampB < cbf_B.Derivative) {
          cbf_B.u = cbf_DW.TimeStampB;
          lastU = &cbf_DW.LastUAtTimeB;
        }
      } else if (cbf_DW.TimeStampA >= cbf_B.Derivative) {
        cbf_B.u = cbf_DW.TimeStampB;
        lastU = &cbf_DW.LastUAtTimeB;
      }

      cbf_B.Derivative1 = (cbf_B.MovingAverage1.MovingAverage - *lastU) /
        (cbf_B.Derivative - cbf_B.u);
    }

    // End of Derivative: '<Root>/Derivative1'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
    // MATLABSystem: '<S12>/SourceBlock'
    cbf_B.b_varargout_1 = Sub_cbf_549.getLatestMessage(&cbf_B.b_varargout_2);

    // Outputs for Enabled SubSystem: '<S12>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S19>/Enable'

    // Start for MATLABSystem: '<S12>/SourceBlock'
    if (cbf_B.b_varargout_1) {
      // SignalConversion generated from: '<S19>/In1'
      cbf_B.In1_g = cbf_B.b_varargout_2;
    }

    // End of Start for MATLABSystem: '<S12>/SourceBlock'
    // End of Outputs for SubSystem: '<S12>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe2'
    cbf_MovingAverage(cbf_B.In1_g.Data, &cbf_B.MovingAverage,
                      &cbf_DW.MovingAverage);

    // Derivative: '<Root>/Derivative'
    if ((cbf_DW.TimeStampA_h >= cbf_B.Derivative) && (cbf_DW.TimeStampB_e >=
         cbf_B.Derivative)) {
      cbf_B.Derivative = 0.0;
    } else {
      cbf_B.u = cbf_DW.TimeStampA_h;
      lastU = &cbf_DW.LastUAtTimeA_k;
      if (cbf_DW.TimeStampA_h < cbf_DW.TimeStampB_e) {
        if (cbf_DW.TimeStampB_e < cbf_B.Derivative) {
          cbf_B.u = cbf_DW.TimeStampB_e;
          lastU = &cbf_DW.LastUAtTimeB_l;
        }
      } else if (cbf_DW.TimeStampA_h >= cbf_B.Derivative) {
        cbf_B.u = cbf_DW.TimeStampB_e;
        lastU = &cbf_DW.LastUAtTimeB_l;
      }

      cbf_B.Derivative = (cbf_B.MovingAverage.MovingAverage - *lastU) /
        (cbf_B.Derivative - cbf_B.u);
    }

    // MATLABSystem: '<S16>/Get Parameter2'
    ParamGet_cbf_567.get_parameter(&cbf_B.u);

    // MATLABSystem: '<S16>/Get Parameter3'
    ParamGet_cbf_568.get_parameter(&cbf_B.minmax1550);

    // MATLABSystem: '<S16>/Get Parameter4'
    ParamGet_cbf_569.get_parameter(&cbf_B.b_value);

    // MATLABSystem: '<S16>/Get Parameter5'
    ParamGet_cbf_570.get_parameter(&cbf_B.b_value_b);

    // MATLABSystem: '<S16>/Get Parameter7'
    ParamGet_cbf_595.get_parameter(&cbf_B.b_value_p);

    // MATLAB Function: '<S16>/MATLAB Function1' incorporates:
    //   MATLABSystem: '<S16>/Get Parameter2'
    //   MATLABSystem: '<S16>/Get Parameter3'
    //   MATLABSystem: '<S16>/Get Parameter4'
    //   MATLABSystem: '<S16>/Get Parameter5'
    //   MATLABSystem: '<S16>/Get Parameter7'
    //
    cbf_B.u = (((cbf_B.u / cbf_B.b_value_p * cbf_B.Derivative1 +
                 cbf_B.Derivative) + (cbf_B.In1_f.Data - cbf_B.u *
      cbf_B.Derivative1) * (cbf_B.b_value + cbf_B.b_value_b)) +
               ((cbf_B.In1_j.Data - cbf_B.u * cbf_B.In1_m.Data) -
                cbf_B.minmax1550) * (cbf_B.b_value * cbf_B.b_value_b)) *
      (cbf_B.b_value_p / cbf_B.u);

    // Switch: '<Root>/Switch' incorporates:
    //   Constant: '<Root>/Constant2'
    //   SignalConversion generated from: '<Root>/Bus Selector7'

    if (cbf_P.Constant2_Value > cbf_P.Switch_Threshold) {
      // MinMax: '<Root>/MinMax' incorporates:
      //   SignalConversion generated from: '<Root>/Bus Selector7'

      if ((cbf_B.u <= cbf_B.In1.Data) || rtIsNaN(cbf_B.In1.Data)) {
        cbf_B.minmax1550 = cbf_B.u;
      } else {
        cbf_B.minmax1550 = cbf_B.In1.Data;
      }

      // End of MinMax: '<Root>/MinMax'
    } else {
      cbf_B.minmax1550 = cbf_B.In1.Data;
    }

    // End of Switch: '<Root>/Switch'

    // Saturate: '<Root>/min//max 1.5//-5.0'
    if (cbf_B.minmax1550 > cbf_P.minmax1550_UpperSat) {
      cbf_B.minmax1550 = cbf_P.minmax1550_UpperSat;
    } else if (cbf_B.minmax1550 < cbf_P.minmax1550_LowerSat) {
      cbf_B.minmax1550 = cbf_P.minmax1550_LowerSat;
    }

    // End of Saturate: '<Root>/min//max 1.5//-5.0'

    // BusAssignment: '<Root>/Bus Assignment1'
    cbf_B.BusAssignment1.Data = cbf_B.minmax1550;

    // Outputs for Atomic SubSystem: '<Root>/Publish1'
    // MATLABSystem: '<S5>/SinkBlock'
    Pub_cbf_544.publish(&cbf_B.BusAssignment1);

    // End of Outputs for SubSystem: '<Root>/Publish1'

    // BusAssignment: '<Root>/Bus Assignment2' incorporates:
    //   Constant: '<Root>/Constant'
    //   Constant: '<Root>/Constant3'
    //   Constant: '<S2>/Constant'
    //   SignalConversion generated from: '<Root>/Bus Selector7'

    cbf_B.BusAssignment2 = cbf_P.Constant_Value;
    cbf_B.BusAssignment2.Linear.X = cbf_B.In1.Data;
    cbf_B.BusAssignment2.Linear.Y = cbf_B.u;
    cbf_B.BusAssignment2.Linear.Z = cbf_B.minmax1550;
    cbf_B.BusAssignment2.Angular.Y = cbf_P.Constant_Value_jt;
    cbf_B.BusAssignment2.Angular.Z = cbf_P.Constant3_Value;

    // Outputs for Atomic SubSystem: '<Root>/Publish2'
    // MATLABSystem: '<S6>/SinkBlock'
    Pub_cbf_545.publish(&cbf_B.BusAssignment2);

    // End of Outputs for SubSystem: '<Root>/Publish2'

    // BusAssignment: '<Root>/Bus Assignment3' incorporates:
    //   Constant: '<S3>/Constant'

    cbf_B.BusAssignment2 = cbf_P.Constant_Value_i;
    cbf_B.BusAssignment2.Linear.X = cbf_B.Derivative;
    cbf_B.BusAssignment2.Linear.Y = cbf_B.MovingAverage.MovingAverage;

    // Outputs for Atomic SubSystem: '<Root>/Publish3'
    // MATLABSystem: '<S7>/SinkBlock'
    Pub_cbf_612.publish(&cbf_B.BusAssignment2);

    // End of Outputs for SubSystem: '<Root>/Publish3'

    // BusAssignment: '<Root>/Bus Assignment4' incorporates:
    //   Constant: '<S3>/Constant'

    cbf_B.BusAssignment2 = cbf_P.Constant_Value_i;
    cbf_B.BusAssignment2.Linear.X = cbf_B.Derivative1;
    cbf_B.BusAssignment2.Linear.Y = cbf_B.MovingAverage1.MovingAverage;

    // Outputs for Atomic SubSystem: '<Root>/Publish5'
    // MATLABSystem: '<S9>/SinkBlock'
    Pub_cbf_614.publish(&cbf_B.BusAssignment2);

    // End of Outputs for SubSystem: '<Root>/Publish5'

    // MATLABSystem: '<Root>/Moving Average2'
    if (cbf_DW.obj.TunablePropsChanged) {
      cbf_DW.obj.TunablePropsChanged = false;
    }

    obj = cbf_DW.obj.pStatistic;
    if (cbf_DW.obj.pStatistic->isInitialized != 1) {
      cbf_DW.obj.pStatistic->isSetupComplete = false;
      cbf_DW.obj.pStatistic->isInitialized = 1;
      obj->pCumSum = 0.0;
      obj->pCumRevIndex = 1.0;
      obj->pModValueRev = 0.0;
      obj->isSetupComplete = true;
      obj->pCumSum = 0.0;
      for (cbf_B.i = 0; cbf_B.i < 24; cbf_B.i++) {
        obj->pCumSumRev[cbf_B.i] = 0.0;
        obj->pCumSumRev[cbf_B.i] = 0.0;
      }

      obj->pCumRevIndex = 1.0;
      obj->pModValueRev = 0.0;
    }

    cbf_B.Derivative1 = obj->pCumRevIndex;
    cbf_B.Derivative = obj->pCumSum;
    for (cbf_B.i = 0; cbf_B.i < 24; cbf_B.i++) {
      cbf_B.csumrev[cbf_B.i] = obj->pCumSumRev[cbf_B.i];
    }

    cbf_B.u = obj->pModValueRev;
    cbf_B.minmax1550 = 0.0;
    cbf_B.b_value = 0.0;
    cbf_B.Derivative += cbf_B.In1_f.Data;
    if (cbf_B.u == 0.0) {
      cbf_B.minmax1550 = cbf_B.csumrev[static_cast<int32_T>(cbf_B.Derivative1) -
        1] + cbf_B.Derivative;
    }

    cbf_B.csumrev[static_cast<int32_T>(cbf_B.Derivative1) - 1] =
      cbf_B.In1_f.Data;
    if (cbf_B.Derivative1 != 24.0) {
      cbf_B.Derivative1++;
    } else {
      cbf_B.Derivative1 = 1.0;
      cbf_B.Derivative = 0.0;
      for (cbf_B.i = 22; cbf_B.i >= 0; cbf_B.i--) {
        cbf_B.csumrev[cbf_B.i] += cbf_B.csumrev[cbf_B.i + 1];
      }
    }

    if (cbf_B.u == 0.0) {
      cbf_B.b_value = cbf_B.minmax1550 / 25.0;
    }

    obj->pCumSum = cbf_B.Derivative;
    for (cbf_B.i = 0; cbf_B.i < 24; cbf_B.i++) {
      obj->pCumSumRev[cbf_B.i] = cbf_B.csumrev[cbf_B.i];
    }

    obj->pCumRevIndex = cbf_B.Derivative1;
    if (cbf_B.u > 0.0) {
      obj->pModValueRev = cbf_B.u - 1.0;
    } else {
      obj->pModValueRev = 0.0;
    }

    // BusAssignment: '<Root>/Bus Assignment5' incorporates:
    //   Constant: '<S3>/Constant'
    //   MATLABSystem: '<Root>/Moving Average2'

    cbf_B.BusAssignment2 = cbf_P.Constant_Value_i;
    cbf_B.BusAssignment2.Linear.X = cbf_B.b_value;

    // Outputs for Atomic SubSystem: '<Root>/Publish4'
    // MATLABSystem: '<S8>/SinkBlock'
    Pub_cbf_642.publish(&cbf_B.BusAssignment2);

    // End of Outputs for SubSystem: '<Root>/Publish4'

    // MATLAB Function: '<Root>/MATLAB Function1'
    cbf_DW.relative_distance_prev_not_empt = true;

    // Outputs for Atomic SubSystem: '<Root>/Subscribe7'
    // MATLABSystem: '<S15>/SourceBlock'
    Sub_cbf_552.getLatestMessage(&cbf_B.b_varargout_2_c);

    // End of Outputs for SubSystem: '<Root>/Subscribe7'
  }

  {
    real_T *lastU;

    // Update for Derivative: '<Root>/Derivative1'
    if (cbf_DW.TimeStampA == (rtInf)) {
      cbf_DW.TimeStampA = cbf_M->Timing.t[0];
      lastU = &cbf_DW.LastUAtTimeA;
    } else if (cbf_DW.TimeStampB == (rtInf)) {
      cbf_DW.TimeStampB = cbf_M->Timing.t[0];
      lastU = &cbf_DW.LastUAtTimeB;
    } else if (cbf_DW.TimeStampA < cbf_DW.TimeStampB) {
      cbf_DW.TimeStampA = cbf_M->Timing.t[0];
      lastU = &cbf_DW.LastUAtTimeA;
    } else {
      cbf_DW.TimeStampB = cbf_M->Timing.t[0];
      lastU = &cbf_DW.LastUAtTimeB;
    }

    *lastU = cbf_B.MovingAverage1.MovingAverage;

    // End of Update for Derivative: '<Root>/Derivative1'

    // Update for Derivative: '<Root>/Derivative'
    if (cbf_DW.TimeStampA_h == (rtInf)) {
      cbf_DW.TimeStampA_h = cbf_M->Timing.t[0];
      lastU = &cbf_DW.LastUAtTimeA_k;
    } else if (cbf_DW.TimeStampB_e == (rtInf)) {
      cbf_DW.TimeStampB_e = cbf_M->Timing.t[0];
      lastU = &cbf_DW.LastUAtTimeB_l;
    } else if (cbf_DW.TimeStampA_h < cbf_DW.TimeStampB_e) {
      cbf_DW.TimeStampA_h = cbf_M->Timing.t[0];
      lastU = &cbf_DW.LastUAtTimeA_k;
    } else {
      cbf_DW.TimeStampB_e = cbf_M->Timing.t[0];
      lastU = &cbf_DW.LastUAtTimeB_l;
    }

    *lastU = cbf_B.MovingAverage.MovingAverage;

    // End of Update for Derivative: '<Root>/Derivative'
  }

  // Update absolute time for base rate
  // The "clockTick0" counts the number of times the code of this task has
  //  been executed. The absolute time is the multiplication of "clockTick0"
  //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
  //  overflow during the application lifespan selected.

  cbf_M->Timing.t[0] =
    ((time_T)(++cbf_M->Timing.clockTick0)) * cbf_M->Timing.stepSize0;

  {
    // Update absolute timer for sample time: [0.05s, 0.0s]
    // The "clockTick1" counts the number of times the code of this task has
    //  been executed. The resolution of this integer timer is 0.05, which is the step size
    //  of the task. Size of "clockTick1" ensures timer will not overflow during the
    //  application lifespan selected.

    cbf_M->Timing.clockTick1++;
  }
}

// Model initialize function
void cbf_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&cbf_M->solverInfo, &cbf_M->Timing.simTimeStep);
    rtsiSetTPtr(&cbf_M->solverInfo, &rtmGetTPtr(cbf_M));
    rtsiSetStepSizePtr(&cbf_M->solverInfo, &cbf_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&cbf_M->solverInfo, (&rtmGetErrorStatus(cbf_M)));
    rtsiSetRTModelPtr(&cbf_M->solverInfo, cbf_M);
  }

  rtsiSetSimTimeStep(&cbf_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&cbf_M->solverInfo, false);
  rtsiSetSolverName(&cbf_M->solverInfo,"FixedStepDiscrete");
  rtmSetTPtr(cbf_M, &cbf_M->Timing.tArray[0]);
  cbf_M->Timing.stepSize0 = 0.05;

  {
    h_dsp_internal_SlidingWindo_h_T *obj;
    int32_T i;
    char_T b_zeroDelimTopic[10];
    char_T b_zeroDelimTopic_0[8];
    char_T b_zeroDelimName[6];
    char_T b_zeroDelimName_1[4];
    char_T b_zeroDelimName_0[3];
    static const char_T b_zeroDelimTopic_1[14] = "cmd_accel_pre";
    static const char_T b_zeroDelimTopic_2[10] = "lead_dist";
    static const char_T b_zeroDelimTopic_3[8] = "rel_vel";
    static const char_T b_zeroDelimTopic_4[17] = "/car/state/vel_x";
    static const char_T b_zeroDelimTopic_5[18] = "radar_rv_estimate";
    static const char_T b_zeroDelimTopic_6[10] = "cmd_accel";
    static const char_T b_zeroDelimTopic_7[15] = "/cbf/cbf_debug";
    static const char_T b_zeroDelimTopic_8[17] = "radar_processing";
    static const char_T b_zeroDelimTopic_9[17] = "accel_processing";
    static const char_T b_zeroDelimTopic_a[18] = "rel_vel_smoothing";
    static const char_T b_zeroDelimTopic_b[25] = "/car/hud/mini_car_enable";
    static const char_T b_zeroDelimName_2[8] = "timegap";
    static const char_T b_zeroDelimName_3[6] = "s_min";

    // InitializeConditions for Derivative: '<Root>/Derivative1'
    cbf_DW.TimeStampA = (rtInf);
    cbf_DW.TimeStampB = (rtInf);

    // InitializeConditions for Derivative: '<Root>/Derivative'
    cbf_DW.TimeStampA_h = (rtInf);
    cbf_DW.TimeStampB_e = (rtInf);

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe6'
    // SystemInitialize for Enabled SubSystem: '<S14>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S21>/In1' incorporates:
    //   Outport: '<S21>/Out1'

    cbf_B.In1 = cbf_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S14>/Enabled Subsystem'

    // Start for MATLABSystem: '<S14>/SourceBlock'
    cbf_DW.obj_f.matlabCodegenIsDeleted = false;
    cbf_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      cbf_B.b_zeroDelimTopic_cx[i] = b_zeroDelimTopic_1[i];
    }

    Sub_cbf_551.createSubscriber(&cbf_B.b_zeroDelimTopic_cx[0], 1);
    cbf_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S14>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe6'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S10>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S17>/In1' incorporates:
    //   Outport: '<S17>/Out1'

    cbf_B.In1_j = cbf_P.Out1_Y0_e;

    // End of SystemInitialize for SubSystem: '<S10>/Enabled Subsystem'

    // Start for MATLABSystem: '<S10>/SourceBlock'
    cbf_DW.obj_c.matlabCodegenIsDeleted = false;
    cbf_DW.obj_c.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_2[i];
    }

    Sub_cbf_547.createSubscriber(&b_zeroDelimTopic[0], 1);
    cbf_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe3'
    // SystemInitialize for Enabled SubSystem: '<S13>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S20>/In1' incorporates:
    //   Outport: '<S20>/Out1'

    cbf_B.In1_f = cbf_P.Out1_Y0_c;

    // End of SystemInitialize for SubSystem: '<S13>/Enabled Subsystem'

    // Start for MATLABSystem: '<S13>/SourceBlock'
    cbf_DW.obj_o.matlabCodegenIsDeleted = false;
    cbf_DW.obj_o.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_3[i];
    }

    Sub_cbf_634.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    cbf_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S13>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe3'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S11>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S18>/In1' incorporates:
    //   Outport: '<S18>/Out1'

    cbf_B.In1_m = cbf_P.Out1_Y0_m;

    // End of SystemInitialize for SubSystem: '<S11>/Enabled Subsystem'

    // Start for MATLABSystem: '<S11>/SourceBlock'
    cbf_DW.obj_i.matlabCodegenIsDeleted = false;
    cbf_DW.obj_i.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      cbf_B.b_zeroDelimTopic_c[i] = b_zeroDelimTopic_4[i];
    }

    Sub_cbf_548.createSubscriber(&cbf_B.b_zeroDelimTopic_c[0], 1);
    cbf_DW.obj_i.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S11>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S12>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S19>/In1' incorporates:
    //   Outport: '<S19>/Out1'

    cbf_B.In1_g = cbf_P.Out1_Y0_ea;

    // End of SystemInitialize for SubSystem: '<S12>/Enabled Subsystem'

    // Start for MATLABSystem: '<S12>/SourceBlock'
    cbf_DW.obj_j.matlabCodegenIsDeleted = false;
    cbf_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      cbf_B.b_zeroDelimTopic_m[i] = b_zeroDelimTopic_5[i];
    }

    Sub_cbf_549.createSubscriber(&cbf_B.b_zeroDelimTopic_m[0], 1);
    cbf_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S12>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    cbf_DW.obj_p.matlabCodegenIsDeleted = false;
    cbf_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_6[i];
    }

    Pub_cbf_544.createPublisher(&b_zeroDelimTopic[0], 1);
    cbf_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    cbf_DW.obj_ng.matlabCodegenIsDeleted = false;
    cbf_DW.obj_ng.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      cbf_B.b_zeroDelimTopic_k[i] = b_zeroDelimTopic_7[i];
    }

    Pub_cbf_545.createPublisher(&cbf_B.b_zeroDelimTopic_k[0], 1);
    cbf_DW.obj_ng.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish3'
    // Start for MATLABSystem: '<S7>/SinkBlock'
    cbf_DW.obj_ni.matlabCodegenIsDeleted = false;
    cbf_DW.obj_ni.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      cbf_B.b_zeroDelimTopic_c[i] = b_zeroDelimTopic_8[i];
    }

    Pub_cbf_612.createPublisher(&cbf_B.b_zeroDelimTopic_c[0], 1);
    cbf_DW.obj_ni.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish3'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish5'
    // Start for MATLABSystem: '<S9>/SinkBlock'
    cbf_DW.obj_d.matlabCodegenIsDeleted = false;
    cbf_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 17; i++) {
      cbf_B.b_zeroDelimTopic_c[i] = b_zeroDelimTopic_9[i];
    }

    Pub_cbf_614.createPublisher(&cbf_B.b_zeroDelimTopic_c[0], 1);
    cbf_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish5'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish4'
    // Start for MATLABSystem: '<S8>/SinkBlock'
    cbf_DW.obj_h.matlabCodegenIsDeleted = false;
    cbf_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 18; i++) {
      cbf_B.b_zeroDelimTopic_m[i] = b_zeroDelimTopic_a[i];
    }

    Pub_cbf_642.createPublisher(&cbf_B.b_zeroDelimTopic_m[0], 1);
    cbf_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish4'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe7'
    // Start for MATLABSystem: '<S15>/SourceBlock'
    cbf_DW.obj_bu.matlabCodegenIsDeleted = false;
    cbf_DW.obj_bu.isInitialized = 1;
    for (i = 0; i < 25; i++) {
      cbf_B.b_zeroDelimTopic[i] = b_zeroDelimTopic_b[i];
    }

    Sub_cbf_552.createSubscriber(&cbf_B.b_zeroDelimTopic[0], 1);
    cbf_DW.obj_bu.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S15>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe7'
    cbf_MovingAverage_Init(&cbf_DW.MovingAverage1);
    cbf_MovingAverage_Init(&cbf_DW.MovingAverage);

    // Start for MATLABSystem: '<S16>/Get Parameter2'
    cbf_DW.obj_n.matlabCodegenIsDeleted = false;
    cbf_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimName_2[i];
    }

    ParamGet_cbf_567.initialize(&b_zeroDelimTopic_0[0]);
    ParamGet_cbf_567.initialize_error_codes(0, 1, 2, 3);
    ParamGet_cbf_567.set_initial_value(2.0);
    cbf_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S16>/Get Parameter2'

    // Start for MATLABSystem: '<S16>/Get Parameter3'
    cbf_DW.obj_m.matlabCodegenIsDeleted = false;
    cbf_DW.obj_m.isInitialized = 1;
    for (i = 0; i < 6; i++) {
      b_zeroDelimName[i] = b_zeroDelimName_3[i];
    }

    ParamGet_cbf_568.initialize(&b_zeroDelimName[0]);
    ParamGet_cbf_568.initialize_error_codes(0, 1, 2, 3);
    ParamGet_cbf_568.set_initial_value(7.0);
    cbf_DW.obj_m.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S16>/Get Parameter3'

    // Start for MATLABSystem: '<S16>/Get Parameter4'
    cbf_DW.obj_b.matlabCodegenIsDeleted = false;
    cbf_DW.obj_b.isInitialized = 1;
    b_zeroDelimName_0[0] = 'k';
    b_zeroDelimName_0[1] = '1';
    b_zeroDelimName_0[2] = '\x00';
    ParamGet_cbf_569.initialize(&b_zeroDelimName_0[0]);
    ParamGet_cbf_569.initialize_error_codes(0, 1, 2, 3);
    ParamGet_cbf_569.set_initial_value(0.5);
    cbf_DW.obj_b.isSetupComplete = true;

    // Start for MATLABSystem: '<S16>/Get Parameter5'
    cbf_DW.obj_lb.matlabCodegenIsDeleted = false;
    cbf_DW.obj_lb.isInitialized = 1;
    b_zeroDelimName_0[0] = 'k';
    b_zeroDelimName_0[1] = '2';
    b_zeroDelimName_0[2] = '\x00';
    ParamGet_cbf_570.initialize(&b_zeroDelimName_0[0]);
    ParamGet_cbf_570.initialize_error_codes(0, 1, 2, 3);
    ParamGet_cbf_570.set_initial_value(0.5);
    cbf_DW.obj_lb.isSetupComplete = true;

    // Start for MATLABSystem: '<S16>/Get Parameter7'
    cbf_DW.obj_l.matlabCodegenIsDeleted = false;
    cbf_DW.obj_l.isInitialized = 1;
    b_zeroDelimName_1[0] = 't';
    b_zeroDelimName_1[1] = 'a';
    b_zeroDelimName_1[2] = 'u';
    b_zeroDelimName_1[3] = '\x00';
    ParamGet_cbf_595.initialize(&b_zeroDelimName_1[0]);
    ParamGet_cbf_595.initialize_error_codes(0, 1, 2, 3);
    ParamGet_cbf_595.set_initial_value(1.5);
    cbf_DW.obj_l.isSetupComplete = true;

    // Start for MATLABSystem: '<Root>/Moving Average2'
    cbf_DW.obj.isInitialized = 0;
    cbf_DW.obj.NumChannels = -1;
    cbf_DW.obj.FrameLength = -1;
    cbf_DW.obj.matlabCodegenIsDeleted = false;
    cbf_SystemCore_setup_h(&cbf_DW.obj);

    // InitializeConditions for MATLABSystem: '<Root>/Moving Average2'
    obj = cbf_DW.obj.pStatistic;
    if (obj->isInitialized == 1) {
      obj->pCumSum = 0.0;
      for (i = 0; i < 24; i++) {
        obj->pCumSumRev[i] = 0.0;
      }

      obj->pCumRevIndex = 1.0;
      obj->pModValueRev = 0.0;
    }

    // End of InitializeConditions for MATLABSystem: '<Root>/Moving Average2'
  }
}

// Model terminate function
void cbf_terminate(void)
{
  h_dsp_internal_SlidingWindo_h_T *obj;

  // Terminate for Atomic SubSystem: '<Root>/Subscribe6'
  // Terminate for MATLABSystem: '<S14>/SourceBlock'
  if (!cbf_DW.obj_f.matlabCodegenIsDeleted) {
    cbf_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S14>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe6'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S10>/SourceBlock'
  if (!cbf_DW.obj_c.matlabCodegenIsDeleted) {
    cbf_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe3'
  // Terminate for MATLABSystem: '<S13>/SourceBlock'
  if (!cbf_DW.obj_o.matlabCodegenIsDeleted) {
    cbf_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S13>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe3'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S11>/SourceBlock'
  if (!cbf_DW.obj_i.matlabCodegenIsDeleted) {
    cbf_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'
  cbf_MovingAverage_Term(&cbf_DW.MovingAverage1);

  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S12>/SourceBlock'
  if (!cbf_DW.obj_j.matlabCodegenIsDeleted) {
    cbf_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S12>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'
  cbf_MovingAverage_Term(&cbf_DW.MovingAverage);

  // Terminate for MATLABSystem: '<S16>/Get Parameter2'
  if (!cbf_DW.obj_n.matlabCodegenIsDeleted) {
    cbf_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/Get Parameter2'

  // Terminate for MATLABSystem: '<S16>/Get Parameter3'
  if (!cbf_DW.obj_m.matlabCodegenIsDeleted) {
    cbf_DW.obj_m.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/Get Parameter3'

  // Terminate for MATLABSystem: '<S16>/Get Parameter4'
  if (!cbf_DW.obj_b.matlabCodegenIsDeleted) {
    cbf_DW.obj_b.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/Get Parameter4'

  // Terminate for MATLABSystem: '<S16>/Get Parameter5'
  if (!cbf_DW.obj_lb.matlabCodegenIsDeleted) {
    cbf_DW.obj_lb.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/Get Parameter5'

  // Terminate for MATLABSystem: '<S16>/Get Parameter7'
  if (!cbf_DW.obj_l.matlabCodegenIsDeleted) {
    cbf_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S16>/Get Parameter7'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  if (!cbf_DW.obj_p.matlabCodegenIsDeleted) {
    cbf_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Terminate for MATLABSystem: '<S6>/SinkBlock'
  if (!cbf_DW.obj_ng.matlabCodegenIsDeleted) {
    cbf_DW.obj_ng.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'

  // Terminate for Atomic SubSystem: '<Root>/Publish3'
  // Terminate for MATLABSystem: '<S7>/SinkBlock'
  if (!cbf_DW.obj_ni.matlabCodegenIsDeleted) {
    cbf_DW.obj_ni.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish3'

  // Terminate for Atomic SubSystem: '<Root>/Publish5'
  // Terminate for MATLABSystem: '<S9>/SinkBlock'
  if (!cbf_DW.obj_d.matlabCodegenIsDeleted) {
    cbf_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish5'

  // Terminate for MATLABSystem: '<Root>/Moving Average2'
  if (!cbf_DW.obj.matlabCodegenIsDeleted) {
    cbf_DW.obj.matlabCodegenIsDeleted = true;
    if ((cbf_DW.obj.isInitialized == 1) && cbf_DW.obj.isSetupComplete) {
      obj = cbf_DW.obj.pStatistic;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      cbf_DW.obj.NumChannels = -1;
      cbf_DW.obj.FrameLength = -1;
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/Moving Average2'

  // Terminate for Atomic SubSystem: '<Root>/Publish4'
  // Terminate for MATLABSystem: '<S8>/SinkBlock'
  if (!cbf_DW.obj_h.matlabCodegenIsDeleted) {
    cbf_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish4'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe7'
  // Terminate for MATLABSystem: '<S15>/SourceBlock'
  if (!cbf_DW.obj_bu.matlabCodegenIsDeleted) {
    cbf_DW.obj_bu.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S15>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe7'
}

//
// File trailer for generated code.
//
// [EOF]
//
