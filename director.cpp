//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: director.cpp
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
#include "director.h"
#include "director_private.h"

// Named constants for Chart: '<Root>/Chart'
const uint8_T dire_IN_Instructed_vel_matching = 9U;
const uint8_T direct_IN_Instructed_dynamic_th = 8U;
const uint8_T directo_IN_Coached_vel_matching = 3U;
const uint8_T director_IN_Coached_const_th = 1U;
const uint8_T director_IN_Coached_dynamic_th = 2U;
const uint8_T director_IN_Const_th = 4U;
const uint8_T director_IN_END = 5U;
const uint8_T director_IN_Ghost_mode = 6U;
const uint8_T director_IN_Init = 7U;

// Block signals (default storage)
B_director_T director_B;

// Block states (default storage)
DW_director_T director_DW;

// Real-time model
RT_MODEL_director_T director_M_ = RT_MODEL_director_T();
RT_MODEL_director_T *const director_M = &director_M_;

// Forward declaration for local functions
static void matlabCodegenHandle_matlabCod_n(ros_slros_internal_block_Subs_T *obj);
static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj);
static void matlabCodegenHandle_matlabCod_n(ros_slros_internal_block_Subs_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

static void matlabCodegenHandle_matlabCodeg(ros_slros_internal_block_Publ_T *obj)
{
  if (!obj->matlabCodegenIsDeleted) {
    obj->matlabCodegenIsDeleted = true;
  }
}

// Model step function
void director_step(void)
{
  SL_Bus_director_std_msgs_Int8 b_varargout_2;
  boolean_T b_varargout_1;
  SL_Bus_director_std_msgs_UInt8 rtb_BusAssignment;
  SL_Bus_director_std_msgs_UInt8 rtb_BusAssignment2;
  SL_Bus_director_std_msgs_Float64 rtb_BusAssignment1;
  int32_T tmp;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  boolean_T guard4 = false;
  boolean_T guard5 = false;

  // Outputs for Atomic SubSystem: '<Root>/Subscribe2'
  // MATLABSystem: '<S3>/SourceBlock' incorporates:
  //   Inport: '<S8>/In1'

  b_varargout_1 = Sub_director_14.getLatestMessage(&b_varargout_2);

  // Outputs for Enabled SubSystem: '<S3>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S8>/Enable'

  if (b_varargout_1) {
    director_B.In1 = b_varargout_2;
  }

  // End of MATLABSystem: '<S3>/SourceBlock'
  // End of Outputs for SubSystem: '<S3>/Enabled Subsystem'
  // End of Outputs for SubSystem: '<Root>/Subscribe2'

  // Chart: '<Root>/Chart'
  if (director_DW.temporalCounter_i1 < 1023U) {
    director_DW.temporalCounter_i1 = static_cast<uint16_T>
      (director_DW.temporalCounter_i1 + 1U);
  }

  if (director_DW.is_active_c1_director == 0U) {
    director_DW.is_active_c1_director = 1U;
    director_DW.is_c1_director = director_IN_Init;
    director_DW.temporalCounter_i1 = 0U;
    director_B.mode = 1U;
    director_B.setpoint = 0.0;
    director_B.feedback_type = 0U;
  } else {
    guard1 = false;
    guard2 = false;
    guard3 = false;
    guard4 = false;
    guard5 = false;
    switch (director_DW.is_c1_director) {
     case director_IN_Coached_const_th:
      director_B.mode = 3U;
      director_B.feedback_type = 1U;
      if (director_DW.temporalCounter_i1 >= 720U) {
        guard2 = true;
      } else if (director_B.In1.Data == -1) {
        director_DW.sp_index = 1U;
        director_DW.is_c1_director = director_IN_Const_th;
        director_DW.temporalCounter_i1 = 0U;
        director_B.mode = 2U;
        director_B.setpoint = 0.0;
        director_B.feedback_type = 0U;
      } else {
        if (director_B.In1.Data == 1) {
          guard2 = true;
        }
      }
      break;

     case director_IN_Coached_dynamic_th:
      director_B.mode = 5U;
      director_B.feedback_type = 1U;
      if ((director_DW.temporalCounter_i1 >= 120U) && (director_DW.sp_index <= 7))
      {
        director_DW.is_c1_director = director_IN_Coached_dynamic_th;
        director_DW.temporalCounter_i1 = 0U;
        director_B.mode = 5U;
        director_B.setpoint = director_DW.sp[director_DW.sp_index - 1];
        tmp = static_cast<int32_T>(director_DW.sp_index + 1U);
        if (static_cast<uint32_T>(tmp) > 255U) {
          tmp = 255;
        }

        director_DW.sp_index = static_cast<uint8_T>(tmp);
        director_B.feedback_type = 1U;
      } else if ((director_DW.temporalCounter_i1 >= 120U) &&
                 (director_DW.sp_index > 7)) {
        director_DW.sp_index = 1U;
        guard3 = true;
      } else if (director_B.In1.Data == -1) {
        director_DW.sp_index = 1U;
        director_DW.is_c1_director = direct_IN_Instructed_dynamic_th;
        director_DW.temporalCounter_i1 = 0U;
        director_B.mode = 4U;
        director_B.setpoint = director_DW.sp[director_DW.sp_index - 1];
        tmp = static_cast<int32_T>(director_DW.sp_index + 1U);
        if (static_cast<uint32_T>(tmp) > 255U) {
          tmp = 255;
        }

        director_DW.sp_index = static_cast<uint8_T>(tmp);
        director_B.feedback_type = 0U;
      } else {
        if (director_B.In1.Data == 1) {
          director_DW.sp_index = 1U;
          guard3 = true;
        }
      }
      break;

     case directo_IN_Coached_vel_matching:
      director_B.mode = 7U;
      director_B.feedback_type = 2U;
      if (director_DW.temporalCounter_i1 >= 720U) {
        director_DW.sp_index = 1U;
        guard4 = true;
      } else if (director_B.In1.Data == -1) {
        director_DW.is_c1_director = dire_IN_Instructed_vel_matching;
        director_DW.temporalCounter_i1 = 0U;
        director_B.mode = 6U;
        director_B.setpoint = 0.0;
        director_B.feedback_type = 0U;
      } else {
        if (director_B.In1.Data == 1) {
          director_DW.sp_index = 1U;
          guard4 = true;
        }
      }
      break;

     case director_IN_Const_th:
      director_B.mode = 2U;
      director_B.feedback_type = 0U;
      if ((director_DW.temporalCounter_i1 >= 720U) || (director_B.In1.Data == 1))
      {
        director_DW.is_c1_director = director_IN_Coached_const_th;
        director_DW.temporalCounter_i1 = 0U;
        director_B.mode = 3U;
        director_B.setpoint = 0.0;
        director_B.feedback_type = 1U;
      } else {
        if (director_B.In1.Data == -1) {
          director_DW.is_c1_director = director_IN_Init;
          director_DW.temporalCounter_i1 = 0U;
          director_B.mode = 1U;
          director_B.setpoint = 0.0;
          director_B.feedback_type = 0U;
        }
      }
      break;

     case director_IN_END:
      break;

     case director_IN_Ghost_mode:
      director_B.mode = 8U;
      director_B.feedback_type = 1U;
      if ((director_DW.temporalCounter_i1 >= 120U) && (director_DW.sp_index <= 7))
      {
        director_DW.is_c1_director = director_IN_Ghost_mode;
        director_DW.temporalCounter_i1 = 0U;
        director_B.mode = 8U;
        director_B.setpoint = director_DW.sp[director_DW.sp_index - 1];
        tmp = static_cast<int32_T>(director_DW.sp_index + 1U);
        if (static_cast<uint32_T>(tmp) > 255U) {
          tmp = 255;
        }

        director_DW.sp_index = static_cast<uint8_T>(tmp);
        director_B.feedback_type = 1U;
      } else if (director_DW.sp_index > 7) {
        director_DW.is_c1_director = director_IN_END;
      } else {
        if (director_B.In1.Data == -1) {
          director_DW.is_c1_director = directo_IN_Coached_vel_matching;
          director_DW.temporalCounter_i1 = 0U;
          director_B.mode = 7U;
          director_B.setpoint = 0.0;
          director_B.feedback_type = 2U;
        }
      }
      break;

     case director_IN_Init:
      director_B.mode = 1U;
      director_B.feedback_type = 0U;
      if ((director_B.In1.Data == 1) || (director_DW.temporalCounter_i1 >= 720U))
      {
        director_DW.is_c1_director = director_IN_Const_th;
        director_DW.temporalCounter_i1 = 0U;
        director_B.mode = 2U;
        director_B.setpoint = 0.0;
        director_B.feedback_type = 0U;
      }
      break;

     case direct_IN_Instructed_dynamic_th:
      director_B.mode = 4U;
      director_B.feedback_type = 0U;
      if ((director_DW.temporalCounter_i1 >= 120U) && (director_DW.sp_index > 7))
      {
        director_DW.sp_index = 1U;
        guard5 = true;
      } else if ((director_DW.temporalCounter_i1 >= 120U) &&
                 (director_DW.sp_index <= 7)) {
        director_DW.is_c1_director = direct_IN_Instructed_dynamic_th;
        director_DW.temporalCounter_i1 = 0U;
        director_B.mode = 4U;
        director_B.setpoint = director_DW.sp[director_DW.sp_index - 1];
        tmp = static_cast<int32_T>(director_DW.sp_index + 1U);
        if (static_cast<uint32_T>(tmp) > 255U) {
          tmp = 255;
        }

        director_DW.sp_index = static_cast<uint8_T>(tmp);
        director_B.feedback_type = 0U;
      } else if (director_B.In1.Data == 1) {
        director_DW.sp_index = 1U;
        guard5 = true;
      } else {
        if (director_B.In1.Data == -1) {
          director_DW.is_c1_director = director_IN_Coached_const_th;
          director_DW.temporalCounter_i1 = 0U;
          director_B.mode = 3U;
          director_B.setpoint = 0.0;
          director_B.feedback_type = 1U;
        }
      }
      break;

     default:
      // case IN_Instructed_vel_matching:
      director_B.mode = 6U;
      director_B.feedback_type = 0U;
      if (director_DW.temporalCounter_i1 >= 720U) {
        guard1 = true;
      } else if (director_B.In1.Data == -1) {
        director_DW.sp_index = 1U;
        director_DW.is_c1_director = director_IN_Coached_dynamic_th;
        director_DW.temporalCounter_i1 = 0U;
        director_B.mode = 5U;
        director_B.setpoint = director_DW.sp[director_DW.sp_index - 1];
        tmp = static_cast<int32_T>(director_DW.sp_index + 1U);
        if (static_cast<uint32_T>(tmp) > 255U) {
          tmp = 255;
        }

        director_DW.sp_index = static_cast<uint8_T>(tmp);
        director_B.feedback_type = 1U;
      } else {
        if (director_B.In1.Data == 1) {
          guard1 = true;
        }
      }
      break;
    }

    if (guard5) {
      director_DW.is_c1_director = director_IN_Coached_dynamic_th;
      director_DW.temporalCounter_i1 = 0U;
      director_B.mode = 5U;
      director_B.setpoint = director_DW.sp[director_DW.sp_index - 1];
      tmp = static_cast<int32_T>(director_DW.sp_index + 1U);
      if (static_cast<uint32_T>(tmp) > 255U) {
        tmp = 255;
      }

      director_DW.sp_index = static_cast<uint8_T>(tmp);
      director_B.feedback_type = 1U;
    }

    if (guard4) {
      director_DW.is_c1_director = director_IN_Ghost_mode;
      director_DW.temporalCounter_i1 = 0U;
      director_B.mode = 8U;
      director_B.setpoint = director_DW.sp[director_DW.sp_index - 1];
      tmp = static_cast<int32_T>(director_DW.sp_index + 1U);
      if (static_cast<uint32_T>(tmp) > 255U) {
        tmp = 255;
      }

      director_DW.sp_index = static_cast<uint8_T>(tmp);
      director_B.feedback_type = 1U;
    }

    if (guard3) {
      director_DW.is_c1_director = dire_IN_Instructed_vel_matching;
      director_DW.temporalCounter_i1 = 0U;
      director_B.mode = 6U;
      director_B.setpoint = 0.0;
      director_B.feedback_type = 0U;
    }

    if (guard2) {
      director_DW.sp_index = 1U;
      director_DW.is_c1_director = direct_IN_Instructed_dynamic_th;
      director_DW.temporalCounter_i1 = 0U;
      director_B.mode = 4U;
      director_B.setpoint = director_DW.sp[director_DW.sp_index - 1];
      tmp = static_cast<int32_T>(director_DW.sp_index + 1U);
      if (static_cast<uint32_T>(tmp) > 255U) {
        tmp = 255;
      }

      director_DW.sp_index = static_cast<uint8_T>(tmp);
      director_B.feedback_type = 0U;
    }

    if (guard1) {
      director_DW.is_c1_director = directo_IN_Coached_vel_matching;
      director_DW.temporalCounter_i1 = 0U;
      director_B.mode = 7U;
      director_B.setpoint = 0.0;
      director_B.feedback_type = 2U;
    }
  }

  // End of Chart: '<Root>/Chart'

  // BusAssignment: '<S2>/Bus Assignment1'
  rtb_BusAssignment1.Data = director_B.setpoint;

  // Outputs for Atomic SubSystem: '<S2>/Publish1'
  // MATLABSystem: '<S6>/SinkBlock'
  Pub_director_5.publish(&rtb_BusAssignment1);

  // End of Outputs for SubSystem: '<S2>/Publish1'

  // BusAssignment: '<S4>/Bus Assignment2'
  rtb_BusAssignment2.Data = director_B.feedback_type;

  // Outputs for Atomic SubSystem: '<S4>/Publish2'
  // MATLABSystem: '<S9>/SinkBlock'
  Pub_director_8.publish(&rtb_BusAssignment2);

  // End of Outputs for SubSystem: '<S4>/Publish2'

  // BusAssignment: '<S5>/Bus Assignment'
  rtb_BusAssignment.Data = director_B.mode;

  // Outputs for Atomic SubSystem: '<S5>/Publish'
  // MATLABSystem: '<S11>/SinkBlock'
  Pub_director_1.publish(&rtb_BusAssignment);

  // End of Outputs for SubSystem: '<S5>/Publish'
}

// Model initialize function
void director_initialize(void)
{
  {
    char_T tmp[12];
    char_T tmp_0[9];
    char_T tmp_1[14];
    char_T tmp_2[5];
    int32_T i;
    static const char_T tmp_3[11] = { 'm', 'o', 'd', 'e', 'C', 'h', 'a', 'n',
      'g', 'e', 'r' };

    static const char_T tmp_4[8] = { 's', 'e', 't', 'p', 'o', 'i', 'n', 't' };

    static const char_T tmp_5[13] = { 'f', 'e', 'e', 'd', 'b', 'a', 'c', 'k',
      '_', 't', 'y', 'p', 'e' };

    // SystemInitialize for Atomic SubSystem: '<Root>/Subscribe2'
    // SystemInitialize for Enabled SubSystem: '<S3>/Enabled Subsystem'
    // SystemInitialize for Outport: '<S8>/Out1'
    director_B.In1 = director_P.Out1_Y0;

    // End of SystemInitialize for SubSystem: '<S3>/Enabled Subsystem'

    // Start for MATLABSystem: '<S3>/SourceBlock'
    director_DW.obj_p.matlabCodegenIsDeleted = false;
    director_DW.obj_p.isInitialized = 1;
    for (i = 0; i < 11; i++) {
      tmp[i] = tmp_3[i];
    }

    tmp[11] = '\x00';
    Sub_director_14.createSubscriber(tmp, 1);
    director_DW.obj_p.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S3>/SourceBlock'
    // End of SystemInitialize for SubSystem: '<Root>/Subscribe2'

    // SystemInitialize for Chart: '<Root>/Chart'
    director_DW.sp[0] = 2.25;
    director_DW.sp[1] = 1.8;
    director_DW.sp[2] = 1.35;
    director_DW.sp[3] = 1.8;
    director_DW.sp[4] = 2.25;
    director_DW.sp[5] = 1.35;
    director_DW.sp[6] = 2.25;

    // SystemInitialize for Atomic SubSystem: '<S2>/Publish1'
    // Start for MATLABSystem: '<S6>/SinkBlock'
    director_DW.obj_d.matlabCodegenIsDeleted = false;
    director_DW.obj_d.isInitialized = 1;
    for (i = 0; i < 8; i++) {
      tmp_0[i] = tmp_4[i];
    }

    tmp_0[8] = '\x00';
    Pub_director_5.createPublisher(tmp_0, 1);
    director_DW.obj_d.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S6>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S2>/Publish1'

    // SystemInitialize for Atomic SubSystem: '<S4>/Publish2'
    // Start for MATLABSystem: '<S9>/SinkBlock'
    director_DW.obj_k.matlabCodegenIsDeleted = false;
    director_DW.obj_k.isInitialized = 1;
    for (i = 0; i < 13; i++) {
      tmp_1[i] = tmp_5[i];
    }

    tmp_1[13] = '\x00';
    Pub_director_8.createPublisher(tmp_1, 1);
    director_DW.obj_k.isSetupComplete = true;

    // End of Start for MATLABSystem: '<S9>/SinkBlock'
    // End of SystemInitialize for SubSystem: '<S4>/Publish2'

    // SystemInitialize for Atomic SubSystem: '<S5>/Publish'
    // Start for MATLABSystem: '<S11>/SinkBlock'
    director_DW.obj.matlabCodegenIsDeleted = false;
    director_DW.obj.isInitialized = 1;
    tmp_2[0] = 'm';
    tmp_2[1] = 'o';
    tmp_2[2] = 'd';
    tmp_2[3] = 'e';
    tmp_2[4] = '\x00';
    Pub_director_1.createPublisher(tmp_2, 1);
    director_DW.obj.isSetupComplete = true;

    // End of SystemInitialize for SubSystem: '<S5>/Publish'
  }
}

// Model terminate function
void director_terminate(void)
{
  // Terminate for Atomic SubSystem: '<Root>/Subscribe2'
  // Terminate for MATLABSystem: '<S3>/SourceBlock'
  matlabCodegenHandle_matlabCod_n(&director_DW.obj_p);

  // End of Terminate for SubSystem: '<Root>/Subscribe2'

  // Terminate for Atomic SubSystem: '<S2>/Publish1'
  // Terminate for MATLABSystem: '<S6>/SinkBlock'
  matlabCodegenHandle_matlabCodeg(&director_DW.obj_d);

  // End of Terminate for SubSystem: '<S2>/Publish1'

  // Terminate for Atomic SubSystem: '<S4>/Publish2'
  // Terminate for MATLABSystem: '<S9>/SinkBlock'
  matlabCodegenHandle_matlabCodeg(&director_DW.obj_k);

  // End of Terminate for SubSystem: '<S4>/Publish2'

  // Terminate for Atomic SubSystem: '<S5>/Publish'
  // Terminate for MATLABSystem: '<S11>/SinkBlock'
  matlabCodegenHandle_matlabCodeg(&director_DW.obj);

  // End of Terminate for SubSystem: '<S5>/Publish'
}

//
// File trailer for generated code.
//
// [EOF]
//
