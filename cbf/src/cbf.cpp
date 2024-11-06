//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: cbf.cpp
//
// Code generated for Simulink model 'cbf'.
//
// Model version                  : 7.3
// Simulink Coder version         : 9.9 (R2023a) 19-Nov-2022
// C/C++ source code generated on : Thu Oct 12 14:21:34 2023
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "cbf.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rtwtypes.h"
#include "cbf_types.h"

// Block signals (default storage)
B_cbf_T cbf_B;

// Block states (default storage)
DW_cbf_T cbf_DW;

// Real-time model
RT_MODEL_cbf_T cbf_M_ = RT_MODEL_cbf_T();
RT_MODEL_cbf_T *const cbf_M = &cbf_M_;

// Model step function
void cbf_step(void)
{
  SL_Bus_cbf_std_msgs_Bool b_varargout_2_0;
  SL_Bus_cbf_std_msgs_Float64 b_varargout_2;
  SL_Bus_cbf_std_msgs_Float64 rtb_BusAssignment1;
  real_T b_value;
  real_T b_value_0;
  real_T b_value_1;
  real_T rtb_cmd_accel;
  real_T rtb_minmax1530;
  boolean_T b_varargout_1;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe6'
  // MATLABSystem: '<S9>/SourceBlock'
  b_varargout_1 = Sub_cbf_476.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S9>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S15>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S15>/In1'
    cbf_B.In1_o = b_varargout_2;
  }

  // End of MATLABSystem: '<S9>/SourceBlock'
  // End of Outputs for SubSystem: '<S9>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe6'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe'
  // MATLABSystem: '<S6>/SourceBlock'
  b_varargout_1 = Sub_cbf_429.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S6>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S12>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S12>/In1'
    cbf_B.In1_m = b_varargout_2;
  }

  // End of MATLABSystem: '<S6>/SourceBlock'
  // End of Outputs for SubSystem: '<S6>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe4'
  // MATLABSystem: '<S8>/SourceBlock'
  b_varargout_1 = Sub_cbf_430.getLatestMessage(&cbf_B.BusAssignment2);

  // Outputs for Enabled SubSystem: '<S8>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S14>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S14>/In1'
    cbf_B.In1 = cbf_B.BusAssignment2;
  }

  // End of MATLABSystem: '<S8>/SourceBlock'
  // End of Outputs for SubSystem: '<S8>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe4'

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S7>/SourceBlock'
  b_varargout_1 = Sub_cbf_527.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S7>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S13>/Enable'

  if (b_varargout_1) {
    // SignalConversion generated from: '<S13>/In1'
    cbf_B.In1_f = b_varargout_2;
  }

  // End of MATLABSystem: '<S7>/SourceBlock'
  // End of Outputs for SubSystem: '<S7>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // MATLABSystem: '<S11>/Get Parameter2'
  ParamGet_cbf_448.get_parameter(&b_value);

  // MATLABSystem: '<S11>/Get Parameter1'
  ParamGet_cbf_447.get_parameter(&b_value_0);

  // MATLABSystem: '<S11>/Get Parameter3'
  ParamGet_cbf_449.get_parameter(&b_value_1);

  // MATLABSystem: '<S11>/Get Parameter4'
  ParamGet_cbf_450.get_parameter(&rtb_cmd_accel);

  // MATLABSystem: '<S11>/Get Parameter5'
  ParamGet_cbf_463.get_parameter(&rtb_minmax1530);

  // MATLAB Function: '<S11>/MATLAB Function1' incorporates:
  //   MATLABSystem: '<S11>/Get Parameter1'
  //   MATLABSystem: '<S11>/Get Parameter2'
  //   MATLABSystem: '<S11>/Get Parameter3'
  //   MATLABSystem: '<S11>/Get Parameter4'
  //   MATLABSystem: '<S11>/Get Parameter5'

  b_value = (cbf_B.In1_m.Data - b_value * cbf_B.In1_f.Data) * (b_value_0 /
    b_value) + 1.0 / b_value * cbf_B.In1.Linear.Z;
  b_value_1 = (rtb_cmd_accel + rtb_minmax1530) * cbf_B.In1.Linear.Z +
    rtb_cmd_accel * rtb_minmax1530 * (cbf_B.In1_m.Data - b_value_1);
  if ((b_value <= b_value_1) || rtIsNaN(b_value_1)) {
    rtb_cmd_accel = b_value;
  } else {
    rtb_cmd_accel = b_value_1;
  }

  // Switch: '<Root>/Switch' incorporates:
  //   Constant: '<Root>/Constant2'
  //   SignalConversion generated from: '<Root>/Bus Selector7'

  if (cbf_P.Constant2_Value > cbf_P.Switch_Threshold) {
    // MinMax: '<Root>/MinMax' incorporates:
    //   SignalConversion generated from: '<Root>/Bus Selector7'

    if ((rtb_cmd_accel <= cbf_B.In1_o.Data) || rtIsNaN(cbf_B.In1_o.Data)) {
      rtb_minmax1530 = rtb_cmd_accel;
    } else {
      rtb_minmax1530 = cbf_B.In1_o.Data;
    }

    // End of MinMax: '<Root>/MinMax'
  } else {
    rtb_minmax1530 = cbf_B.In1_o.Data;
  }

  // End of Switch: '<Root>/Switch'

  // Saturate: '<Root>/min//max 1.5//-3.0'
  if (rtb_minmax1530 > cbf_P.minmax1530_UpperSat) {
    rtb_minmax1530 = cbf_P.minmax1530_UpperSat;
  } else if (rtb_minmax1530 < cbf_P.minmax1530_LowerSat) {
    rtb_minmax1530 = cbf_P.minmax1530_LowerSat;
  }

  // End of Saturate: '<Root>/min//max 1.5//-3.0'

  // BusAssignment: '<Root>/Bus Assignment1'
  rtb_BusAssignment1.Data = rtb_minmax1530;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_cbf_401.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'

  // BusAssignment: '<Root>/Bus Assignment2' incorporates:
  //   Constant: '<S2>/Constant'
  //   MATLAB Function: '<S11>/MATLAB Function1'
  //   SignalConversion generated from: '<Root>/Bus Selector7'

  cbf_B.BusAssignment2 = cbf_P.Constant_Value;
  cbf_B.BusAssignment2.Linear.X = cbf_B.In1_o.Data;
  cbf_B.BusAssignment2.Linear.Y = rtb_cmd_accel;
  cbf_B.BusAssignment2.Linear.Z = rtb_minmax1530;
  cbf_B.BusAssignment2.Angular.Y = b_value;
  cbf_B.BusAssignment2.Angular.Z = b_value_1;

  // Outputs for Atomic SubSystem: '<Root>/Publish2'
  // MATLABSystem: '<S5>/SinkBlock'
  Pub_cbf_520.publish(&cbf_B.BusAssignment2);

  // End of Outputs for SubSystem: '<Root>/Publish2'

  // MATLAB Function: '<Root>/MATLAB Function1'
  cbf_DW.relative_distance_prev_not_empt = true;

  // MATLABSystem: '<S11>/Get Parameter6'
  ParamGet_cbf_465.get_parameter(&b_value);

  // Outputs for Atomic SubSystem: '<Root>/Subscribe7'
  // MATLABSystem: '<S10>/SourceBlock'
  Sub_cbf_481.getLatestMessage(&b_varargout_2_0);

  // End of Outputs for SubSystem: '<Root>/Subscribe7'
}

// Model initialize function
void cbf_initialize(void)
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    int32_T i;
    char_T b_zeroDelimTopic_2[15];
    char_T b_zeroDelimTopic[14];
    char_T b_zeroDelimTopic_0[10];
    char_T b_zeroDelimTopic_1[8];
    char_T b_zeroDelimName[6];
    char_T b_zeroDelimName_0[3];
    static const char_T tmp[13] = { 'c', 'm', 'd', '_', 'a', 'c', 'c', 'e', 'l',
      '_', 'p', 'r', 'e' };

    static const char_T tmp_0[9] = { 'l', 'e', 'a', 'd', '_', 'd', 'i', 's', 't'
    };

    static const char_T tmp_1[7] = { 'r', 'e', 'l', '_', 'v', 'e', 'l' };

    static const char_T tmp_2[16] = { '/', 'c', 'a', 'r', '/', 's', 't', 'a',
      't', 'e', '/', 'v', 'e', 'l', '_', 'x' };

    static const char_T tmp_3[9] = { 'c', 'm', 'd', '_', 'a', 'c', 'c', 'e', 'l'
    };

    static const char_T tmp_4[14] = { '/', 'c', 'b', 'f', '/', 'c', 'b', 'f',
      '_', 'd', 'e', 'b', 'u', 'g' };

    static const char_T tmp_5[24] = { '/', 'c', 'a', 'r', '/', 'h', 'u', 'd',
      '/', 'm', 'i', 'n', 'i', '_', 'c', 'a', 'r', '_', 'e', 'n', 'a', 'b', 'l',
      'e' };

    static const char_T tmp_6[7] = { 't', 'i', 'm', 'e', 'g', 'a', 'p' };

    static const char_T tmp_7[9] = { 'k', '_', 't', 'i', 'm', 'e', 'g', 'a', 'p'
    };

    static const char_T tmp_8[5] = { 's', '_', 'm', 'i', 'n' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe6'
    // SystemInitialize for Enabled SubSystem: '<S9>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S15>/In1' incorporates:
    //   Outport: '<S15>/Out1'

    cbf_B.In1_o = cbf_P.Out1_Y0_a;

    // End of SystemInitialize for SubSystem: '<S9>/Enabled Subsystem'

    // Start for MATLABSystem: '<S9>/SourceBlock'
    cbf_DW.obj_n0.matlabCodegenIsDeleted = false;
    cbf_DW.obj_n0.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      b_zeroDelimTopic[i] = tmp[i];
    }

    b_zeroDelimTopic[13] = '\x00';
    Sub_cbf_476.createSubscriber(&b_zeroDelimTopic[0], 1);
    cbf_DW.obj_n0.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe6'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe'
    // SystemInitialize for Enabled SubSystem: '<S6>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S12>/In1' incorporates:
    //   Outport: '<S12>/Out1'

    cbf_B.In1_m = cbf_P.Out1_Y0_f;

    // End of SystemInitialize for SubSystem: '<S6>/Enabled Subsystem'

    // Start for MATLABSystem: '<S6>/SourceBlock'
    cbf_DW.obj_f.matlabCodegenIsDeleted = false;
    cbf_DW.obj_f.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      b_zeroDelimTopic_0[i] = tmp_0[i];
    }

    b_zeroDelimTopic_0[9] = '\x00';
    Sub_cbf_429.createSubscriber(&b_zeroDelimTopic_0[0], 1);
    cbf_DW.obj_f.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe4'
    // SystemInitialize for Enabled SubSystem: '<S8>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S14>/In1' incorporates:
    //   Outport: '<S14>/Out1'

    cbf_B.In1 = cbf_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S8>/Enabled Subsystem'

    // Start for MATLABSystem: '<S8>/SourceBlock'
    cbf_DW.obj_o.matlabCodegenIsDeleted = false;
    cbf_DW.obj_o.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic_1[i] = tmp_1[i];
    }

    b_zeroDelimTopic_1[7] = '\x00';
    Sub_cbf_430.createSubscriber(&b_zeroDelimTopic_1[0], 1);
    cbf_DW.obj_o.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S8>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe4'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S7>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S13>/In1' incorporates:
    //   Outport: '<S13>/Out1'

    cbf_B.In1_f = cbf_P.Out1_Y0_n;

    // End of SystemInitialize for SubSystem: '<S7>/Enabled Subsystem'

    // Start for MATLABSystem: '<S7>/SourceBlock'
    cbf_DW.obj_h.matlabCodegenIsDeleted = false;
    cbf_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 16; i++) {
      cbf_B.b_zeroDelimTopic_m[i] = tmp_2[i];
    }

    cbf_B.b_zeroDelimTopic_m[16] = '\x00';
    Sub_cbf_527.createSubscriber(&cbf_B.b_zeroDelimTopic_m[0], 1);
    cbf_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S7>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    cbf_DW.obj_c.matlabCodegenIsDeleted = false;
    cbf_DW.obj_c.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      b_zeroDelimTopic_0[i] = tmp_3[i];
    }

    b_zeroDelimTopic_0[9] = '\x00';
    Pub_cbf_401.createPublisher(&b_zeroDelimTopic_0[0], 1);
    cbf_DW.obj_c.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish2'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    cbf_DW.obj_j.matlabCodegenIsDeleted = false;
    cbf_DW.obj_j.isInitialized = 1;
    for (i = 0; i < 14; i++) {
      b_zeroDelimTopic_2[i] = tmp_4[i];
    }

    b_zeroDelimTopic_2[14] = '\x00';
    Pub_cbf_520.createPublisher(&b_zeroDelimTopic_2[0], 1);
    cbf_DW.obj_j.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish2'

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe7'
    // Start for MATLABSystem: '<S10>/SourceBlock'
    cbf_DW.obj_d.matlabCodegenIsDeleted = false;
    cbf_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 24; i++) {
      cbf_B.b_zeroDelimTopic[i] = tmp_5[i];
    }

    cbf_B.b_zeroDelimTopic[24] = '\x00';
    Sub_cbf_481.createSubscriber(&cbf_B.b_zeroDelimTopic[0], 1);
    cbf_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S10>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe7'

    // Start for MATLABSystem: '<S11>/Get Parameter2'
    cbf_DW.obj_p.matlabCodegenIsDeleted = false;
    cbf_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 7; i++) {
      b_zeroDelimTopic_1[i] = tmp_6[i];
    }

    b_zeroDelimTopic_1[7] = '\x00';
    ParamGet_cbf_448.initialize(&b_zeroDelimTopic_1[0]);
    ParamGet_cbf_448.initialize_error_codes(0, 1, 2, 3);
    ParamGet_cbf_448.set_initial_value(2.0);
    cbf_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S11>/Get Parameter2'

    // Start for MATLABSystem: '<S11>/Get Parameter1'
    cbf_DW.obj_n.matlabCodegenIsDeleted = false;
    cbf_DW.obj_n.isInitialized = 1;
    for (i = 0; i < 9; i++) {
      b_zeroDelimTopic_0[i] = tmp_7[i];
    }

    b_zeroDelimTopic_0[9] = '\x00';
    ParamGet_cbf_447.initialize(&b_zeroDelimTopic_0[0]);
    ParamGet_cbf_447.initialize_error_codes(0, 1, 2, 3);
    ParamGet_cbf_447.set_initial_value(0.1);
    cbf_DW.obj_n.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S11>/Get Parameter1'

    // Start for MATLABSystem: '<S11>/Get Parameter3'
    cbf_DW.obj_i.matlabCodegenIsDeleted = false;
    cbf_DW.obj_i.isInitialized = 1;
    for (i = 0; i < 5; i++) {
      b_zeroDelimName[i] = tmp_8[i];
    }

    b_zeroDelimName[5] = '\x00';
    ParamGet_cbf_449.initialize(&b_zeroDelimName[0]);
    ParamGet_cbf_449.initialize_error_codes(0, 1, 2, 3);
    ParamGet_cbf_449.set_initial_value(15.0);
    cbf_DW.obj_i.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S11>/Get Parameter3'

    // Start for MATLABSystem: '<S11>/Get Parameter4'
    cbf_DW.obj_k.matlabCodegenIsDeleted = false;
    cbf_DW.obj_k.isInitialized = 1;
    b_zeroDelimName_0[0] = 'k';
    b_zeroDelimName_0[1] = '1';
    b_zeroDelimName_0[2] = '\x00';
    ParamGet_cbf_450.initialize(&b_zeroDelimName_0[0]);
    ParamGet_cbf_450.initialize_error_codes(0, 1, 2, 3);
    ParamGet_cbf_450.set_initial_value(0.5);
    cbf_DW.obj_k.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Get Parameter5'
    cbf_DW.obj_e.matlabCodegenIsDeleted = false;
    cbf_DW.obj_e.isInitialized = 1;
    b_zeroDelimName_0[0] = 'k';
    b_zeroDelimName_0[1] = '2';
    b_zeroDelimName_0[2] = '\x00';
    ParamGet_cbf_463.initialize(&b_zeroDelimName_0[0]);
    ParamGet_cbf_463.initialize_error_codes(0, 1, 2, 3);
    ParamGet_cbf_463.set_initial_value(0.5);
    cbf_DW.obj_e.isSetupComplete = true;

    // Start for MATLABSystem: '<S11>/Get Parameter6'
    cbf_DW.obj.matlabCodegenIsDeleted = false;
    cbf_DW.obj.isInitialized = 1;
    b_zeroDelimName_0[0] = 'w';
    b_zeroDelimName_0[1] = '3';
    b_zeroDelimName_0[2] = '\x00';
    ParamGet_cbf_465.initialize(&b_zeroDelimName_0[0]);
    ParamGet_cbf_465.initialize_error_codes(0, 1, 2, 3);
    ParamGet_cbf_465.set_initial_value(6.0);
    cbf_DW.obj.isSetupComplete = true;
  }
}

// Model terminate function
void cbf_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe6'
  // Terminate for MATLABSystem: '<S9>/SourceBlock'
  if (!cbf_DW.obj_n0.matlabCodegenIsDeleted) {
    cbf_DW.obj_n0.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S9>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe6'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe'
  // Terminate for MATLABSystem: '<S6>/SourceBlock'
  if (!cbf_DW.obj_f.matlabCodegenIsDeleted) {
    cbf_DW.obj_f.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S6>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe4'
  // Terminate for MATLABSystem: '<S8>/SourceBlock'
  if (!cbf_DW.obj_o.matlabCodegenIsDeleted) {
    cbf_DW.obj_o.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S8>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe4'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S7>/SourceBlock'
  if (!cbf_DW.obj_h.matlabCodegenIsDeleted) {
    cbf_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S7>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for MATLABSystem: '<S11>/Get Parameter2'
  if (!cbf_DW.obj_p.matlabCodegenIsDeleted) {
    cbf_DW.obj_p.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Get Parameter2'

  // Terminate for MATLABSystem: '<S11>/Get Parameter1'
  if (!cbf_DW.obj_n.matlabCodegenIsDeleted) {
    cbf_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Get Parameter1'

  // Terminate for MATLABSystem: '<S11>/Get Parameter3'
  if (!cbf_DW.obj_i.matlabCodegenIsDeleted) {
    cbf_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Get Parameter3'

  // Terminate for MATLABSystem: '<S11>/Get Parameter4'
  if (!cbf_DW.obj_k.matlabCodegenIsDeleted) {
    cbf_DW.obj_k.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Get Parameter4'

  // Terminate for MATLABSystem: '<S11>/Get Parameter5'
  if (!cbf_DW.obj_e.matlabCodegenIsDeleted) {
    cbf_DW.obj_e.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Get Parameter5'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  if (!cbf_DW.obj_c.matlabCodegenIsDeleted) {
    cbf_DW.obj_c.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'

  // Terminate for Atomic SubSystem: '<Root>/Publish2'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  if (!cbf_DW.obj_j.matlabCodegenIsDeleted) {
    cbf_DW.obj_j.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish2'

  // Terminate for MATLABSystem: '<S11>/Get Parameter6'
  if (!cbf_DW.obj.matlabCodegenIsDeleted) {
    cbf_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S11>/Get Parameter6'

  // Terminate for Atomic SubSystem: '<Root>/Subscribe7'
  // Terminate for MATLABSystem: '<S10>/SourceBlock'
  if (!cbf_DW.obj_d.matlabCodegenIsDeleted) {
    cbf_DW.obj_d.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S10>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe7'
}

//
// File trailer for generated code.
//
// [EOF]
//
