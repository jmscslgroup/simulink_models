//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: velocity_controller.cpp
//
// Code generated for Simulink model 'velocity_controller'.
//
// Model version                  : 5.2
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Wed Oct 18 15:57:41 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "velocity_controller.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include <math.h>
#include "rtwtypes.h"
#include "velocity_controller_types.h"
#include "velocity_controller_private.h"
#include "zero_crossing_types.h"

// Block signals (default storage)
B_velocity_controller_T velocity_controller_B;

// Continuous states
X_velocity_controller_T velocity_controller_X;

// Block states (default storage)
DW_velocity_controller_T velocity_controller_DW;

// Previous zero-crossings (trigger) states
PrevZCX_velocity_controller_T velocity_controller_PrevZCX;

// Real-time model
RT_MODEL_velocity_controller_T velocity_controller_M_ =
  RT_MODEL_velocity_controller_T();
RT_MODEL_velocity_controller_T *const velocity_controller_M =
  &velocity_controller_M_;

//
// This function updates continuous states using the ODE3 fixed-step
// solver algorithm
//
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  // Solver Matrices
  static const real_T rt_ODE3_A[3] = {
    1.0/2.0, 3.0/4.0, 1.0
  };

  static const real_T rt_ODE3_B[3][3] = {
    { 1.0/2.0, 0.0, 0.0 },

    { 0.0, 3.0/4.0, 0.0 },

    { 2.0/9.0, 1.0/3.0, 4.0/9.0 }
  };

  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE3_IntgData *id = static_cast<ODE3_IntgData *>(rtsiGetSolverData(si));
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  // Save the state values at time t in y, we'll use x as ynew.
  (void) memcpy(y, x,
                static_cast<uint_T>(nXc)*sizeof(real_T));

  // Assumes that rtsiSetT and ModelOutputs are up-to-date
  // f0 = f(t,y)
  rtsiSetdX(si, f0);
  velocity_controller_derivatives();

  // f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*));
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  velocity_controller_step();
  velocity_controller_derivatives();

  // f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*));
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  velocity_controller_step();
  velocity_controller_derivatives();

  // tnew = t + hA(3);
  // ynew = y + f*hB(:,3);
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

// Model step function
void velocity_controller_step(void)
{
  SL_Bus_velocity_controller_std_msgs_Bool b_varargout_2_0;
  SL_Bus_velocity_controller_std_msgs_Float64 b_varargout_2;
  SL_Bus_velocity_controller_std_msgs_Float64 rtb_BusAssignment;
  real_T rtb_IntegralGain;
  real_T rtb_Saturation;
  real_T rtb_SignPreSat;
  real_T tmp_0;
  int32_T tmp;
  boolean_T b_varargout_1;
  ZCEventType zcEvent;
  if (rtmIsMajorTimeStep(velocity_controller_M)) {
    // set solver stop time
    rtsiSetSolverStopTime(&velocity_controller_M->solverInfo,
                          ((velocity_controller_M->Timing.clockTick0+1)*
      velocity_controller_M->Timing.stepSize0));
  }                                    // end MajorTimeStep

  // Update absolute time of base rate at minor time step
  if (rtmIsMinorTimeStep(velocity_controller_M)) {
    velocity_controller_M->Timing.t[0] = rtsiGetT
      (&velocity_controller_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(velocity_controller_M)) {
    // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
    // MATLABSystem: '<S5>/SourceBlock'
    b_varargout_1 = Sub_velocity_controller_31.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S9>/Enable'

    if (b_varargout_1) {
      // SignalConversion generated from: '<S9>/In1'
      velocity_controller_B.In1 = b_varargout_2;
    }

    // End of MATLABSystem: '<S5>/SourceBlock'
    // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe1'

    // Outputs for Atomic SubSystem: '<Root>/Subscribe'
    // MATLABSystem: '<S4>/SourceBlock'
    b_varargout_1 = Sub_velocity_controller_10.getLatestMessage(&b_varargout_2);

    // Outputs for Enabled SubSystem: '<S4>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S8>/Enable'

    if (b_varargout_1) {
      // SignalConversion generated from: '<S8>/In1'
      velocity_controller_B.In1_d = b_varargout_2;
    }

    // End of MATLABSystem: '<S4>/SourceBlock'
    // End of Outputs for SubSystem: '<S4>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe'

    // Sum: '<Root>/Sum'
    rtb_IntegralGain = velocity_controller_B.In1.Data -
      velocity_controller_B.In1_d.Data;

    // Gain: '<S49>/Proportional Gain'
    velocity_controller_B.ProportionalGain =
      velocity_controller_P.reference_tracking_P * rtb_IntegralGain;

    // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
    // MATLABSystem: '<S6>/SourceBlock'
    b_varargout_1 = Sub_velocity_controller_40.getLatestMessage(&b_varargout_2_0);

    // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
    //   EnablePort: '<S10>/Enable'

    if (b_varargout_1) {
      // SignalConversion generated from: '<S10>/In1'
      velocity_controller_B.In1_g = b_varargout_2_0;
    }

    // End of MATLABSystem: '<S6>/SourceBlock'
    // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
    // End of Outputs for SubSystem: '<Root>/Subscribe2'

    // DataTypeConversion: '<Root>/Data Type Conversion'
    velocity_controller_B.DataTypeConversion = velocity_controller_B.In1_g.Data;
  }

  // Integrator: '<S44>/Integrator'
  if (rtsiIsModeUpdateTimeStep(&velocity_controller_M->solverInfo)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &velocity_controller_PrevZCX.Integrator_Reset_ZCE,
                       (velocity_controller_B.DataTypeConversion));

    // evaluate zero-crossings
    if (zcEvent != NO_ZCEVENT) {
      velocity_controller_X.Integrator_CSTATE =
        velocity_controller_P.reference_tracking_InitialCon_n;
    }
  }

  if (rtmIsMajorTimeStep(velocity_controller_M)) {
    // Gain: '<S38>/Derivative Gain'
    velocity_controller_B.DerivativeGain =
      velocity_controller_P.reference_tracking_D * rtb_IntegralGain;
  }

  // Integrator: '<S39>/Filter'
  if (rtsiIsModeUpdateTimeStep(&velocity_controller_M->solverInfo)) {
    zcEvent = rt_ZCFcn(RISING_ZERO_CROSSING,
                       &velocity_controller_PrevZCX.Filter_Reset_ZCE,
                       (velocity_controller_B.DataTypeConversion));

    // evaluate zero-crossings
    if (zcEvent != NO_ZCEVENT) {
      velocity_controller_X.Filter_CSTATE =
        velocity_controller_P.reference_tracking_InitialCondi;
    }
  }

  // Gain: '<S47>/Filter Coefficient' incorporates:
  //   Integrator: '<S39>/Filter'
  //   Sum: '<S39>/SumD'

  velocity_controller_B.FilterCoefficient =
    (velocity_controller_B.DerivativeGain - velocity_controller_X.Filter_CSTATE)
    * velocity_controller_P.reference_tracking_N;

  // Sum: '<S53>/Sum' incorporates:
  //   Integrator: '<S44>/Integrator'

  rtb_SignPreSat = (velocity_controller_B.ProportionalGain +
                    velocity_controller_X.Integrator_CSTATE) +
    velocity_controller_B.FilterCoefficient;

  // Saturate: '<S51>/Saturation'
  if (rtb_SignPreSat > velocity_controller_P.reference_tracking_UpperSaturat) {
    rtb_Saturation = velocity_controller_P.reference_tracking_UpperSaturat;
  } else if (rtb_SignPreSat <
             velocity_controller_P.reference_tracking_LowerSaturat) {
    rtb_Saturation = velocity_controller_P.reference_tracking_LowerSaturat;
  } else {
    rtb_Saturation = rtb_SignPreSat;
  }

  // End of Saturate: '<S51>/Saturation'

  // Saturate: '<Root>/Saturation'
  if (rtb_Saturation > velocity_controller_P.Saturation_UpperSat) {
    rtb_Saturation = velocity_controller_P.Saturation_UpperSat;
  } else if (rtb_Saturation < velocity_controller_P.Saturation_LowerSat) {
    rtb_Saturation = velocity_controller_P.Saturation_LowerSat;
  }

  // End of Saturate: '<Root>/Saturation'

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   MATLAB Function: '<Root>/Brake at low velocities'

  rtb_BusAssignment.Data = rtb_Saturation;

  // MATLAB Function: '<Root>/Brake at low velocities'
  if ((velocity_controller_B.In1_d.Data < 0.3) &&
      (velocity_controller_B.In1.Data < 0.1)) {
    // BusAssignment: '<Root>/Bus Assignment'
    rtb_BusAssignment.Data = -1.0;
  } else if ((velocity_controller_B.In1_d.Data < 1.0) &&
             (velocity_controller_B.In1.Data < 0.1)) {
    if ((1.0 - velocity_controller_B.In1_d.Data) - 1.0 < rtb_Saturation) {
      // BusAssignment: '<Root>/Bus Assignment'
      rtb_BusAssignment.Data = (1.0 - velocity_controller_B.In1_d.Data) - 1.0;
    }
  } else if ((velocity_controller_B.In1_d.Data < 0.5) &&
             (velocity_controller_B.In1.Data > 1.0)) {
    if ((rtb_Saturation <= 0.0) || rtIsNaN(rtb_Saturation)) {
      // BusAssignment: '<Root>/Bus Assignment'
      rtb_BusAssignment.Data = 0.0;
    } else {
      // BusAssignment: '<Root>/Bus Assignment'
      rtb_BusAssignment.Data = rtb_Saturation;
    }
  }

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_velocity_controller_3.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // Gain: '<S35>/ZeroGain'
  rtb_Saturation = velocity_controller_P.ZeroGain_Gain * rtb_SignPreSat;

  // DeadZone: '<S37>/DeadZone'
  if (rtb_SignPreSat > velocity_controller_P.reference_tracking_UpperSaturat) {
    rtb_SignPreSat -= velocity_controller_P.reference_tracking_UpperSaturat;
  } else if (rtb_SignPreSat >=
             velocity_controller_P.reference_tracking_LowerSaturat) {
    rtb_SignPreSat = 0.0;
  } else {
    rtb_SignPreSat -= velocity_controller_P.reference_tracking_LowerSaturat;
  }

  // End of DeadZone: '<S37>/DeadZone'
  if (rtmIsMajorTimeStep(velocity_controller_M)) {
    // Gain: '<S41>/Integral Gain'
    rtb_IntegralGain *= velocity_controller_P.reference_tracking_I;

    // Signum: '<S35>/SignPreIntegrator'
    if (rtIsNaN(rtb_IntegralGain)) {
      // DataTypeConversion: '<S35>/DataTypeConv2'
      tmp_0 = (rtNaN);
    } else if (rtb_IntegralGain < 0.0) {
      // DataTypeConversion: '<S35>/DataTypeConv2'
      tmp_0 = -1.0;
    } else {
      // DataTypeConversion: '<S35>/DataTypeConv2'
      tmp_0 = (rtb_IntegralGain > 0.0);
    }

    // End of Signum: '<S35>/SignPreIntegrator'

    // DataTypeConversion: '<S35>/DataTypeConv2'
    if (rtIsNaN(tmp_0)) {
      tmp = 0;
    } else {
      tmp = static_cast<int32_T>(fmod(tmp_0, 256.0));
    }

    // DataTypeConversion: '<S35>/DataTypeConv2'
    velocity_controller_B.DataTypeConv2 = static_cast<int8_T>(tmp < 0 ?
      static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>(static_cast<
      uint8_T>(-static_cast<real_T>(tmp))))) : tmp);
  }

  // Signum: '<S35>/SignPreSat'
  if (rtIsNaN(rtb_SignPreSat)) {
    // DataTypeConversion: '<S35>/DataTypeConv1'
    tmp_0 = (rtNaN);
  } else if (rtb_SignPreSat < 0.0) {
    // DataTypeConversion: '<S35>/DataTypeConv1'
    tmp_0 = -1.0;
  } else {
    // DataTypeConversion: '<S35>/DataTypeConv1'
    tmp_0 = (rtb_SignPreSat > 0.0);
  }

  // End of Signum: '<S35>/SignPreSat'

  // DataTypeConversion: '<S35>/DataTypeConv1'
  if (rtIsNaN(tmp_0)) {
    tmp = 0;
  } else {
    tmp = static_cast<int32_T>(fmod(tmp_0, 256.0));
  }

  // Logic: '<S35>/AND3' incorporates:
  //   DataTypeConversion: '<S35>/DataTypeConv1'
  //   RelationalOperator: '<S35>/Equal1'
  //   RelationalOperator: '<S35>/NotEqual'

  velocity_controller_B.AND3 = ((rtb_Saturation != rtb_SignPreSat) && ((tmp < 0 ?
    static_cast<int32_T>(static_cast<int8_T>(-static_cast<int8_T>
    (static_cast<uint8_T>(-static_cast<real_T>(tmp))))) : tmp) ==
    velocity_controller_B.DataTypeConv2));
  if (rtmIsMajorTimeStep(velocity_controller_M)) {
    // Switch: '<S35>/Switch' incorporates:
    //   Memory: '<S35>/Memory'

    if (velocity_controller_DW.Memory_PreviousInput) {
      // Switch: '<S35>/Switch' incorporates:
      //   Constant: '<S35>/Constant1'

      velocity_controller_B.Switch = velocity_controller_P.Constant1_Value;
    } else {
      // Switch: '<S35>/Switch'
      velocity_controller_B.Switch = rtb_IntegralGain;
    }

    // End of Switch: '<S35>/Switch'
  }

  if (rtmIsMajorTimeStep(velocity_controller_M)) {
    if (rtmIsMajorTimeStep(velocity_controller_M)) {
      // Update for Memory: '<S35>/Memory'
      velocity_controller_DW.Memory_PreviousInput = velocity_controller_B.AND3;
    }
  }                                    // end MajorTimeStep

  if (rtmIsMajorTimeStep(velocity_controller_M)) {
    rt_ertODEUpdateContinuousStates(&velocity_controller_M->solverInfo);

    // Update absolute time for base rate
    // The "clockTick0" counts the number of times the code of this task has
    //  been executed. The absolute time is the multiplication of "clockTick0"
    //  and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
    //  overflow during the application lifespan selected.

    ++velocity_controller_M->Timing.clockTick0;
    velocity_controller_M->Timing.t[0] = rtsiGetSolverStopTime
      (&velocity_controller_M->solverInfo);

    {
      // Update absolute timer for sample time: [0.02s, 0.0s]
      // The "clockTick1" counts the number of times the code of this task has
      //  been executed. The resolution of this integer timer is 0.02, which is the step size
      //  of the task. Size of "clockTick1" ensures timer will not overflow during the
      //  application lifespan selected.

      velocity_controller_M->Timing.clockTick1++;
    }
  }                                    // end MajorTimeStep
}

// Derivatives for root system: '<Root>'
void velocity_controller_derivatives(void)
{
  XDot_velocity_controller_T *_rtXdot;
  _rtXdot = ((XDot_velocity_controller_T *) velocity_controller_M->derivs);

  // Derivatives for Integrator: '<S44>/Integrator'
  _rtXdot->Integrator_CSTATE = velocity_controller_B.Switch;

  // Derivatives for Integrator: '<S39>/Filter'
  _rtXdot->Filter_CSTATE = velocity_controller_B.FilterCoefficient;
}

// Model initialize function
void velocity_controller_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    // Setup solver object
    rtsiSetSimTimeStepPtr(&velocity_controller_M->solverInfo,
                          &velocity_controller_M->Timing.simTimeStep);
    rtsiSetTPtr(&velocity_controller_M->solverInfo, &rtmGetTPtr
                (velocity_controller_M));
    rtsiSetStepSizePtr(&velocity_controller_M->solverInfo,
                       &velocity_controller_M->Timing.stepSize0);
    rtsiSetdXPtr(&velocity_controller_M->solverInfo,
                 &velocity_controller_M->derivs);
    rtsiSetContStatesPtr(&velocity_controller_M->solverInfo, (real_T **)
                         &velocity_controller_M->contStates);
    rtsiSetNumContStatesPtr(&velocity_controller_M->solverInfo,
      &velocity_controller_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&velocity_controller_M->solverInfo,
      &velocity_controller_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&velocity_controller_M->solverInfo,
      &velocity_controller_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&velocity_controller_M->solverInfo,
      &velocity_controller_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&velocity_controller_M->solverInfo,
                          (&rtmGetErrorStatus(velocity_controller_M)));
    rtsiSetRTModelPtr(&velocity_controller_M->solverInfo, velocity_controller_M);
  }

  rtsiSetSimTimeStep(&velocity_controller_M->solverInfo, MAJOR_TIME_STEP);
  velocity_controller_M->intgData.y = velocity_controller_M->odeY;
  velocity_controller_M->intgData.f[0] = velocity_controller_M->odeF[0];
  velocity_controller_M->intgData.f[1] = velocity_controller_M->odeF[1];
  velocity_controller_M->intgData.f[2] = velocity_controller_M->odeF[2];
  velocity_controller_M->contStates = ((X_velocity_controller_T *)
    &velocity_controller_X);
  rtsiSetSolverData(&velocity_controller_M->solverInfo, static_cast<void *>
                    (&velocity_controller_M->intgData));
  rtsiSetIsMinorTimeStepWithModeChange(&velocity_controller_M->solverInfo, false);
  rtsiSetSolverName(&velocity_controller_M->solverInfo,"ode3");
  rtmSetTPtr(velocity_controller_M, &velocity_controller_M->Timing.tArray[0]);
  velocity_controller_M->Timing.stepSize0 = 0.02;

  {
    int32_T i;
    char_T b_zeroDelimTopic_0[16];
    char_T b_zeroDelimTopic_1[10];
    char_T b_zeroDelimTopic[8];
    static const char_T tmp[7] = { 'c', 'm', 'd', '_', 'v', 'e', 'l' };

    static const char_T tmp_0[15] = { 'c', 'a', 'r', '/', 's', 't', 'a', 't',
      'e', '/', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_1[27] = { '/', 'c', 'a', 'r', '/', 'p', 'a', 'n',
      'd', 'a', '/', 'c', 'o', 'n', 't', 'r', 'o', 'l', 's', '_', 'a', 'l', 'l',
      'o', 'w', 'e', 'd' };

    static const char_T tmp_2[9] = { 'c', 'm', 'd', '_', 'a', 'c', 'c', 'e', 'l'
    };

    velocity_controller_PrevZCX.Integrator_Reset_ZCE = UNINITIALIZED_ZCSIG;
    velocity_controller_PrevZCX.Filter_Reset_ZCE = UNINITIALIZED_ZCSIG;

    // InitializeConditions for Integrator: '<S44>/Integrator'
    velocity_controller_X.Integrator_CSTATE =
      velocity_controller_P.reference_tracking_InitialCon_n;

    // InitializeConditions for Integrator: '<S39>/Filter'
    velocity_controller_X.Filter_CSTATE =
      velocity_controller_P.reference_tracking_InitialCondi;

    // InitializeConditions for Memory: '<S35>/Memory'
    velocity_controller_DW.Memory_PreviousInput =
      velocity_controller_P.Memory_InitialCondition;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S9>/In1' incorporates:
    //   Outport: '<S9>/Out1'

    velocity_controller_B.In1 = velocity_controller_P.Out1_Y0_h;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    velocity_controller_DW.obj_g.matlabCodegenIsDeleted = false;
    velocity_controller_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[7] = '\x00';
    Sub_velocity_controller_31.createSubscriber(&b_zeroDelimTopic[0], 1);
    velocity_controller_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S4>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S8>/In1' incorporates:
    //   Outport: '<S8>/Out1'

    velocity_controller_B.In1_d = velocity_controller_P.Out1_Y0_p;

    // End of SystemInitialize for SubSystem: '<S4>/Enabled Subsystem'

    // Start for MATLABSystem: '<S4>/SourceBlock'
    velocity_controller_DW.obj_n.matlabCodegenIsDeleted = false;
    velocity_controller_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 15; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[15] = '\x00';
    Sub_velocity_controller_10.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    velocity_controller_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S10>/In1' incorporates:
    //   Outport: '<S10>/Out1'

    velocity_controller_B.In1_g = velocity_controller_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    velocity_controller_DW.obj_f.matlabCodegenIsDeleted = false;
    velocity_controller_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 27; i++) {
      velocity_controller_B.b_zeroDelimTopic[i] = tmp_1[i];
    }

    velocity_controller_B.b_zeroDelimTopic[27] = '\x00';
    Sub_velocity_controller_40.createSubscriber
      (&velocity_controller_B.b_zeroDelimTopic[0], 1);
    velocity_controller_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    velocity_controller_DW.obj.matlabCodegenIsDeleted = false;
    velocity_controller_DW.obj.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      b_zeroDelimTopic_1[i] = tmp_2[i];
    }

    b_zeroDelimTopic_1[9] = '\x00';
    Pub_velocity_controller_3.createPublisher(&b_zeroDelimTopic_1[0], 1);
    velocity_controller_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'
  }
}

// Model terminate function
void velocity_controller_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!velocity_controller_DW.obj_g.matlabCodegenIsDeleted) {
    velocity_controller_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S4>/SourceBlock'
  if (!velocity_controller_DW.obj_n.matlabCodegenIsDeleted) {
    velocity_controller_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!velocity_controller_DW.obj_f.matlabCodegenIsDeleted) {
    velocity_controller_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!velocity_controller_DW.obj.matlabCodegenIsDeleted) {
    velocity_controller_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
