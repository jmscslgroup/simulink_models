//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: setpointreader.cpp
//
// Code generated for Simulink model 'setpointreader'.
//
// Model version                  : 6.0
// Simulink Coder version         : 23.2 (R2023b) 01-Aug-2023
// C/C++ source code generated on : Tue Jan 28 11:52:32 2025
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "setpointreader.h"
#include "rtwtypes.h"
#include "setpointreader_types.h"

// Block signals (default storage)
B_setpointreader_T setpointreader_B;

// Block states (default storage)
DW_setpointreader_T setpointreader_DW;

// Real-time model
RT_MODEL_setpointreader_T setpointreader_M_ = RT_MODEL_setpointreader_T();
RT_MODEL_setpointreader_T *const setpointreader_M = &setpointreader_M_;

// Model step function
void setpointreader_step(void)
{
  SL_Bus_setpointreader_geometry_msgs_Point b_varargout_2;
  SL_Bus_setpointreader_std_msgs_Float64 rtb_BusAssignment1;
  real_T rtb_Gain;
  boolean_T b_varargout_1;

  // BusAssignment: '<Root>/Bus Assignment' incorporates:
  //   Constant: '<S1>/Constant'

  setpointreader_B.BusAssignment = setpointreader_P.Constant_Value;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe1'
  // MATLABSystem: '<S5>/SourceBlock'
  b_varargout_1 = Sub_setpointreader_31.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S5>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S6>/Enable'

  // Start for MATLABSystem: '<S5>/SourceBlock'
  if (b_varargout_1) {
    // SignalConversion generated from: '<S6>/In1'
    setpointreader_B.In1 = b_varargout_2;
  }

  // End of Start for MATLABSystem: '<S5>/SourceBlock'
  // End of Outputs for SubSystem: '<S5>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe1'

  // Gain: '<Root>/Gain'
  rtb_Gain = setpointreader_P.Gain_Gain * setpointreader_B.In1.Y;

  // BusAssignment: '<Root>/Bus Assignment'
  setpointreader_B.BusAssignment.Linear.X = rtb_Gain;

  // Outputs for Atomic SubSystem: '<Root>/Publish'
  // MATLABSystem: '<S3>/SinkBlock'
  Pub_setpointreader_3.publish(&setpointreader_B.BusAssignment);

  // End of Outputs for SubSystem: '<Root>/Publish'

  // BusAssignment: '<Root>/Bus Assignment1'
  rtb_BusAssignment1.Data = rtb_Gain;

  // Outputs for Atomic SubSystem: '<Root>/Publish1'
  // MATLABSystem: '<S4>/SinkBlock'
  Pub_setpointreader_44.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<Root>/Publish1'
}

// Model initialize function
void setpointreader_initialize(void)
{
  {
    int32_T i;
    char_T b_zeroDelimTopic_1[12];
    char_T b_zeroDelimTopic[8];
    char_T b_zeroDelimTopic_0[6];
    static const char_T b_zeroDelimTopic_2[8] = "msg_467";
    static const char_T b_zeroDelimTopic_3[6] = "v_ref";
    static const char_T b_zeroDelimTopic_4[12] = "v_ref_float";

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe1'
    // SystemInitialize for Enabled SubSystem: '<S5>/Enabled Subsystem'
    // SystemInitialize for SignalConversion generated from: '<S6>/In1' incorporates:
    //   Outport: '<S6>/Out1'

    setpointreader_B.In1 = setpointreader_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S5>/Enabled Subsystem'

    // Start for MATLABSystem: '<S5>/SourceBlock'
    setpointreader_DW.obj_g.matlabCodegenIsDeleted = false;
    setpointreader_DW.obj_g.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      b_zeroDelimTopic[i] = b_zeroDelimTopic_2[i];
    }

    Sub_setpointreader_31.createSubscriber(&b_zeroDelimTopic[0], 1);
    setpointreader_DW.obj_g.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe1'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish'
    // Start for MATLABSystem: '<S3>/SinkBlock'
    setpointreader_DW.obj_h.matlabCodegenIsDeleted = false;
    setpointreader_DW.obj_h.isInitialized = 1;
    for (i = 0; i < 6; i++) {
      b_zeroDelimTopic_0[i] = b_zeroDelimTopic_3[i];
    }

    Pub_setpointreader_3.createPublisher(&b_zeroDelimTopic_0[0], 1);
    setpointreader_DW.obj_h.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish'

    // SystemInitialize for Atomic SubSystem: '<Root>/Publish1'
    // Start for MATLABSystem: '<S4>/SinkBlock'
    setpointreader_DW.obj.matlabCodegenIsDeleted = false;
    setpointreader_DW.obj.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      b_zeroDelimTopic_1[i] = b_zeroDelimTopic_4[i];
    }

    Pub_setpointreader_44.createPublisher(&b_zeroDelimTopic_1[0], 1);
    setpointreader_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S4>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Publish1'
  }
}

// Model terminate function
void setpointreader_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe1'
  // Terminate for MATLABSystem: '<S5>/SourceBlock'
  if (!setpointreader_DW.obj_g.matlabCodegenIsDeleted) {
    setpointreader_DW.obj_g.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S5>/SourceBlock'
  // End of Terminate for SubSystem: '<Root>/Subscribe1'

  // Terminate for Atomic SubSystem: '<Root>/Publish'
  // Terminate for MATLABSystem: '<S3>/SinkBlock'
  if (!setpointreader_DW.obj_h.matlabCodegenIsDeleted) {
    setpointreader_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S3>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish'

  // Terminate for Atomic SubSystem: '<Root>/Publish1'
  // Terminate for MATLABSystem: '<S4>/SinkBlock'
  if (!setpointreader_DW.obj.matlabCodegenIsDeleted) {
    setpointreader_DW.obj.matlabCodegenIsDeleted = true;
  }

  // End of Terminate for MATLABSystem: '<S4>/SinkBlock'
  // End of Terminate for SubSystem: '<Root>/Publish1'
}

//
// File trailer for generated code.
//
// [EOF]
//
