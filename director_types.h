/*
 * director_types.h
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

#ifndef RTW_HEADER_director_types_h_
#define RTW_HEADER_director_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_director_std_msgs_Float64_
#define DEFINED_TYPEDEF_FOR_SL_Bus_director_std_msgs_Float64_

typedef struct {
  real_T Data;
} SL_Bus_director_std_msgs_Float64;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_director_std_msgs_Int8_
#define DEFINED_TYPEDEF_FOR_SL_Bus_director_std_msgs_Int8_

typedef struct {
  int8_T Data;
} SL_Bus_director_std_msgs_Int8;

#endif

#ifndef DEFINED_TYPEDEF_FOR_SL_Bus_director_std_msgs_UInt8_
#define DEFINED_TYPEDEF_FOR_SL_Bus_director_std_msgs_UInt8_

typedef struct {
  uint8_T Data;
} SL_Bus_director_std_msgs_UInt8;

#endif

#ifndef DEFINED_TYPEDEF_FOR_QueuePolicy_T_
#define DEFINED_TYPEDEF_FOR_QueuePolicy_T_

typedef enum {
  MSG_QUEUE_UNUSED = -1,               /* Default value */
  MSG_FIFO_QUEUE,
  MSG_LIFO_QUEUE,
  MSG_PRIORITY_QUEUE
} QueuePolicy_T;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Msg_real_T_
#define DEFINED_TYPEDEF_FOR_Msg_real_T_

typedef struct {
  real_T fData;
} Msg_real_T;

#endif

#ifndef DEFINED_TYPEDEF_FOR_Queue_real_T_
#define DEFINED_TYPEDEF_FOR_Queue_real_T_

typedef struct {
  QueuePolicy_T fPolicy;
  int32_T fHead;
  int32_T fTail;
  int32_T fCapacity;
  Msg_real_T *fArray;
} Queue_real_T;

#endif

#ifndef struct_tag_rkSooZHJZnr3Dpfu1LNqfH
#define struct_tag_rkSooZHJZnr3Dpfu1LNqfH

struct tag_rkSooZHJZnr3Dpfu1LNqfH
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /*struct_tag_rkSooZHJZnr3Dpfu1LNqfH*/

#ifndef typedef_ros_slros_internal_block_Publ_T
#define typedef_ros_slros_internal_block_Publ_T

typedef struct tag_rkSooZHJZnr3Dpfu1LNqfH ros_slros_internal_block_Publ_T;

#endif                               /*typedef_ros_slros_internal_block_Publ_T*/

#ifndef struct_tag_9SewJ4y3IXNs5GrZti8qkG
#define struct_tag_9SewJ4y3IXNs5GrZti8qkG

struct tag_9SewJ4y3IXNs5GrZti8qkG
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
};

#endif                                 /*struct_tag_9SewJ4y3IXNs5GrZti8qkG*/

#ifndef typedef_ros_slros_internal_block_Subs_T
#define typedef_ros_slros_internal_block_Subs_T

typedef struct tag_9SewJ4y3IXNs5GrZti8qkG ros_slros_internal_block_Subs_T;

#endif                               /*typedef_ros_slros_internal_block_Subs_T*/

/* Parameters (default storage) */
typedef struct P_director_T_ P_director_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_director_T RT_MODEL_director_T;

#endif                                 /* RTW_HEADER_director_types_h_ */
