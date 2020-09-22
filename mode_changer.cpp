//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: mode_changer.cpp
//
// Code generated for Simulink model 'mode_changer'.
//
// Model version                  : 1.110
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Tue Sep 22 16:57:27 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Generic->Unspecified (assume 32-bit Generic)
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "mode_changer.h"
#include "mode_changer_private.h"

// Block signals (default storage)
B_mode_changer_T mode_changer_B;

// Block states (default storage)
DW_mode_changer_T mode_changer_DW;

// Previous zero-crossings (trigger) states
PrevZCX_mode_changer_T mode_changer_PrevZCX;

// Real-time model
RT_MODEL_mode_changer_T mode_changer_M_ = RT_MODEL_mode_changer_T();
RT_MODEL_mode_changer_T *const mode_changer_M = &mode_changer_M_;

// Forward declaration for local functions
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Subs_T *obj);
static void matlabCodegenHandle_matlabCod_l(ros_slros_internal_block_Publ_T *obj);
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCod_l(ros_slros_internal_block_Publ_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

// Model step function
void mode_changer_step(void)
{
  SL_Bus_mode_changer_geometry_msgs_Twist b_varargout_2;
  boolean_T b_varargout_1;
  SL_Bus_mode_changer_std_msgs_Int8 rtb_BusAssignment;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
  // MATLABSystem: '<S1>/SourceBlock' incorporates:
  //   Inport: '<S3>/In1'

  b_varargout_1 = Sub_mode_changer_2.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S1>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S3>/Enable'

  if (b_varargout_1) {
    mode_changer_B.In1 = b_varargout_2;
  }

  // End of Outputs for SubSystem: '<S1>/Enabled Subsystem'

  // Outputs for Triggered SubSystem: '<Root>/Subsystem' incorporates:
  //   TriggerPort: '<S2>/Trigger'

  if (b_varargout_1 && (mode_changer_PrevZCX.Subsystem_Trig_ZCE != POS_ZCSIG)) {
    // MATLAB Function: '<S2>/MATLAB Function' incorporates:
    //   SignalConversion generated from: '<Root>/Bus Selector1'

    if (!mode_changer_DW.n_toggle_not_empty) {
      mode_changer_DW.n_toggle_not_empty = true;
      mode_changer_DW.previous = mode_changer_B.In1.Linear.X;
    }

    if (mode_changer_B.In1.Linear.X == 0.0) {
      if ((mode_changer_DW.previous == 1.0) && (mode_changer_DW.n_high < 4.0)) {
        mode_changer_DW.n_toggle++;
      } else {
        if (mode_changer_DW.previous == 0.0) {
          mode_changer_DW.n_toggle = 0.0;
        }
      }

      mode_changer_DW.n_high = 0.0;
    } else {
      if (mode_changer_B.In1.Linear.X == 1.0) {
        mode_changer_DW.n_high++;
      }
    }

    mode_changer_DW.previous = mode_changer_B.In1.Linear.X;
    if (mode_changer_DW.n_toggle == 2.0) {
      // BusAssignment: '<S2>/Bus Assignment'
      rtb_BusAssignment.Data = 1;
    } else if (mode_changer_DW.n_toggle == 3.0) {
      // BusAssignment: '<S2>/Bus Assignment'
      rtb_BusAssignment.Data = -1;
    } else {
      // BusAssignment: '<S2>/Bus Assignment'
      rtb_BusAssignment.Data = 0;
    }

    // End of MATLAB Function: '<S2>/MATLAB Function'

    // Outputs for Atomic SubSystem: '<S2>/Publish'
    // MATLABSystem: '<S5>/SinkBlock'
    Pub_mode_changer_19.publish(&rtb_BusAssignment);

    // End of Outputs for SubSystem: '<S2>/Publish'
  }

  mode_changer_PrevZCX.Subsystem_Trig_ZCE = b_varargout_1;

  // End of MATLABSystem: '<S1>/SourceBlock'
  // End of Outputs for SubSystem: '<Root>/Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe2'
}

// Model initialize function
void mode_changer_initialize(void)
{
  {
    char_T tmp[11];
    char_T tmp_0[13];
    int32_T i;
    static const char_T tmp_1[10] = { '/', 'h', 'i', 'g', 'h', 'b', 'e', 'a',
      'm', 's' };

    static const char_T tmp_2[12] = { '/', 'm', 'o', 'd', 'e', 'C', 'h', 'a',
      'n', 'g', 'e', 'r' };

    mode_changer_PrevZCX.Subsystem_Trig_ZCE = POS_ZCSIG;

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S1>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S3>/Out1'
    mode_changer_B.In1 = mode_changer_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S1>/Enabled Subsystem'

    // Start for MATLABSystem: '<S1>/SourceBlock'
    mode_changer_DW.obj.matlabCodegenIsDeleted = false;
    mode_changer_DW.obj.isInitialized = 1;
    for (i = 0; i < 10; i++) {
      tmp[i] = tmp_1[i];
    }

    tmp[10] = '\x00';
    Sub_mode_changer_2.createSubscriber(tmp, 1);
    mode_changer_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S1>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Triggered SubSystem: '<Root>/Subsystem'
    // SystemInitialize for Atomic SubSystem: '<S2>/Publish'
    // Start for MATLABSystem: '<S5>/SinkBlock'
    mode_changer_DW.obj_a.matlabCodegenIsDeleted = false;
    mode_changer_DW.obj_a.isInitialized = 1;
    for (i = 0; i < 12; i++) {
      tmp_0[i] = tmp_2[i];
    }

    tmp_0[12] = '\x00';
    Pub_mode_changer_19.createPublisher(tmp_0, 1);
    mode_changer_DW.obj_a.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S5>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S2>/Publish'
    // End of SystemInitialize for SubSystem: '<Root>/Subsystem'
  }
}

// Model terminate function
void mode_changer_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S1>/SourceBlock'
  matlabCodegenHandle_matlabCodeg(&mode_changer_DW.obj);

  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Triggered SubSystem: '<Root>/Subsystem'
  // Terminate for Atomic SubSystem: '<S2>/Publish'
  // Terminate for MATLABSystem: '<S5>/SinkBlock'
  matlabCodegenHandle_matlabCod_l(&mode_changer_DW.obj_a);

  // End of Terminate for SubSystem: '<S2>/Publish'
  // End of Terminate for SubSystem: '<Root>/Subsystem'
}

//
// File trailer for generated code.
//
// [EOF]
//
