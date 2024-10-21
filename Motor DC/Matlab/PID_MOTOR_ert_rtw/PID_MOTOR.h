/*
 * PID_MOTOR.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PID_MOTOR".
 *
 * Model version              : 1.0
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Oct 10 21:07:41 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PID_MOTOR_h_
#define RTW_HEADER_PID_MOTOR_h_
#ifndef PID_MOTOR_COMMON_INCLUDES_
#define PID_MOTOR_COMMON_INCLUDES_
#include <stdio.h>
#include <string.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "MW_arduino_digitalio.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#endif                                 /* PID_MOTOR_COMMON_INCLUDES_ */

#include "PID_MOTOR_types.h"
#include "multiword_types.h"
#include <stddef.h>
#include <math.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetContStateDisabled
#define rtmGetContStateDisabled(rtm)   ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
#define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
#define rtmGetContStates(rtm)          ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
#define rtmSetContStates(rtm, val)     ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
#define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
#define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
#define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetIntgData
#define rtmGetIntgData(rtm)            ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
#define rtmSetIntgData(rtm, val)       ((rtm)->intgData = (val))
#endif

#ifndef rtmGetOdeF
#define rtmGetOdeF(rtm)                ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
#define rtmSetOdeF(rtm, val)           ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
#define rtmGetOdeY(rtm)                ((rtm)->odeY)
#endif

#ifndef rtmSetOdeY
#define rtmSetOdeY(rtm, val)           ((rtm)->odeY = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
#define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
#define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
#define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
#define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
#define rtmGetZCCacheNeedsReset(rtm)   ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
#define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetdX
#define rtmGetdX(rtm)                  ((rtm)->derivs)
#endif

#ifndef rtmSetdX
#define rtmSetdX(rtm, val)             ((rtm)->derivs = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
#define rtmGetT(rtm)                   (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

/* Block signals (default storage) */
typedef struct {
  int64m_T Gain;                       /* '<Root>/Gain' */
  int64m_T Delay;                      /* '<S2>/Delay' */
  real_T Switch1;                      /* '<S4>/Switch1' */
  real_T ManualSwitch3;                /* '<Root>/Manual Switch3' */
  real_T SliderGain;                   /* '<S5>/Slider Gain' */
  real_T tiempoms;                     /* '<S2>/tiempo (ms)' */
  real_T Gain_c;                       /* '<S2>/Gain' */
  real_T modelo;                   /* '<Root>/Modelo (System Identification)' */
  real_T Gain1;                        /* '<S1>/Gain1' */
  real_T Internal;                     /* '<S10>/Internal' */
  real_T Gain2;                        /* '<S1>/Gain2' */
  real_T Internal_m;                   /* '<S18>/Internal' */
  real_T Sum3;                         /* '<S3>/Sum3' */
  real_T Add2;                         /* '<S1>/Add2' */
  real_T Gain4;                        /* '<S1>/Gain4' */
  real_T Internal_p;                   /* '<S14>/Internal' */
  real_T Gain5;                        /* '<S1>/Gain5' */
  real_T Internal_j;                   /* '<S22>/Internal' */
  real_T Add2_l;                       /* '<S3>/Add2' */
  real_T Gain4_p;                      /* '<S3>/Gain4' */
  real_T Clock;                        /* '<S4>/Clock' */
} B_PID_MOTOR_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Encoder' */
  codertarget_arduinobase_block_T obj_i;/* '<Root>/Digital Output3' */
  codertarget_arduinobase_block_T obj_l;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_int_b_T obj_n;/* '<Root>/PWM' */
  int64m_T Delay_DSTATE[100];          /* '<S2>/Delay' */
  struct {
    void *FilePtr;
  } ToFile_PWORK;                      /* '<Root>/To File' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK;                     /* '<Root>/To File1' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile_IWORK;                      /* '<Root>/To File' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK;                     /* '<Root>/To File1' */

  boolean_T objisempty;                /* '<Root>/PWM' */
  boolean_T objisempty_j;              /* '<Root>/Encoder' */
  boolean_T objisempty_h;              /* '<Root>/Digital Output3' */
  boolean_T objisempty_b;              /* '<Root>/Digital Output1' */
} DW_PID_MOTOR_T;

/* Continuous states (default storage) */
typedef struct {
  real_T ModeloSystemIdentification_CSTA[2];
                                     /* '<S3>/Modelo (System Identification)' */
  real_T ModeloSystemIdentification_CS_i[2];
                                     /* '<S1>/Modelo (System Identification)' */
  real_T ModeloSystemIdentification_CS_f[2];
                                   /* '<Root>/Modelo (System Identification)' */
  real_T Internal_CSTATE;              /* '<S10>/Internal' */
  real_T Internal_CSTATE_n[11];        /* '<S18>/Internal' */
  real_T Integrator2_CSTATE;           /* '<S3>/Integrator2' */
  real_T TransferFcn1_CSTATE;          /* '<S9>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_c;        /* '<S7>/Transfer Fcn1' */
  real_T Internal_CSTATE_k;            /* '<S14>/Internal' */
  real_T Internal_CSTATE_j[11];        /* '<S22>/Internal' */
  real_T Integrator1_CSTATE;           /* '<S3>/Integrator1' */
  real_T TransferFcn1_CSTATE_g;        /* '<S6>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_n;        /* '<S8>/Transfer Fcn1' */
} X_PID_MOTOR_T;

/* State derivatives (default storage) */
typedef struct {
  real_T ModeloSystemIdentification_CSTA[2];
                                     /* '<S3>/Modelo (System Identification)' */
  real_T ModeloSystemIdentification_CS_i[2];
                                     /* '<S1>/Modelo (System Identification)' */
  real_T ModeloSystemIdentification_CS_f[2];
                                   /* '<Root>/Modelo (System Identification)' */
  real_T Internal_CSTATE;              /* '<S10>/Internal' */
  real_T Internal_CSTATE_n[11];        /* '<S18>/Internal' */
  real_T Integrator2_CSTATE;           /* '<S3>/Integrator2' */
  real_T TransferFcn1_CSTATE;          /* '<S9>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_c;        /* '<S7>/Transfer Fcn1' */
  real_T Internal_CSTATE_k;            /* '<S14>/Internal' */
  real_T Internal_CSTATE_j[11];        /* '<S22>/Internal' */
  real_T Integrator1_CSTATE;           /* '<S3>/Integrator1' */
  real_T TransferFcn1_CSTATE_g;        /* '<S6>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_n;        /* '<S8>/Transfer Fcn1' */
} XDot_PID_MOTOR_T;

/* State disabled  */
typedef struct {
  boolean_T ModeloSystemIdentification_CSTA[2];
                                     /* '<S3>/Modelo (System Identification)' */
  boolean_T ModeloSystemIdentification_CS_i[2];
                                     /* '<S1>/Modelo (System Identification)' */
  boolean_T ModeloSystemIdentification_CS_f[2];
                                   /* '<Root>/Modelo (System Identification)' */
  boolean_T Internal_CSTATE;           /* '<S10>/Internal' */
  boolean_T Internal_CSTATE_n[11];     /* '<S18>/Internal' */
  boolean_T Integrator2_CSTATE;        /* '<S3>/Integrator2' */
  boolean_T TransferFcn1_CSTATE;       /* '<S9>/Transfer Fcn1' */
  boolean_T TransferFcn1_CSTATE_c;     /* '<S7>/Transfer Fcn1' */
  boolean_T Internal_CSTATE_k;         /* '<S14>/Internal' */
  boolean_T Internal_CSTATE_j[11];     /* '<S22>/Internal' */
  boolean_T Integrator1_CSTATE;        /* '<S3>/Integrator1' */
  boolean_T TransferFcn1_CSTATE_g;     /* '<S6>/Transfer Fcn1' */
  boolean_T TransferFcn1_CSTATE_n;     /* '<S8>/Transfer Fcn1' */
} XDis_PID_MOTOR_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_PID_MOTOR_T_ {
  real_T kd_fracc;                     /* Variable: kd_fracc
                                        * Referenced by:
                                        *   '<S1>/Gain1'
                                        *   '<S1>/Gain4'
                                        */
  real_T ki_fracc;                     /* Variable: ki_fracc
                                        * Referenced by:
                                        *   '<S1>/Gain2'
                                        *   '<S1>/Gain5'
                                        */
  real_T kp_fracc;                     /* Variable: kp_fracc
                                        * Referenced by: '<S1>/Gain3'
                                        */
  real_T SliderGain_gain;              /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S5>/Slider Gain'
                                        */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<Root>/Encoder'
                                        */
  real_T Constant8_Value;              /* Expression: 255
                                        * Referenced by: '<Root>/Constant8'
                                        */
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant9'
                                        */
  real_T Constant2_Value;              /* Expression: 255
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Constant1_Value;              /* Expression: 255
                                        * Referenced by: '<S4>/Constant1'
                                        */
  real_T Constant7_Value;              /* Expression: 50
                                        * Referenced by: '<S4>/Constant7'
                                        */
  real_T Constant4_Value;              /* Expression: 225
                                        * Referenced by: '<S4>/Constant4'
                                        */
  real_T Constant6_Value;              /* Expression: 100
                                        * Referenced by: '<S4>/Constant6'
                                        */
  real_T Constant5_Value;              /* Expression: 200
                                        * Referenced by: '<S4>/Constant5'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 255
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T ModeloSystemIdentification_A[2];
                             /* Computed Parameter: ModeloSystemIdentification_A
                              * Referenced by: '<S3>/Modelo (System Identification)'
                              */
  real_T ModeloSystemIdentification_C[2];
                             /* Computed Parameter: ModeloSystemIdentification_C
                              * Referenced by: '<S3>/Modelo (System Identification)'
                              */
  real_T ModeloSystemIdentification_A_f[2];
                           /* Computed Parameter: ModeloSystemIdentification_A_f
                            * Referenced by: '<S1>/Modelo (System Identification)'
                            */
  real_T ModeloSystemIdentification_C_b[2];
                           /* Computed Parameter: ModeloSystemIdentification_C_b
                            * Referenced by: '<S1>/Modelo (System Identification)'
                            */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<Root>/Constant'
                                        */
  real_T nmedidas_Value;               /* Expression: 100
                                        * Referenced by: '<S2>/nº medidas'
                                        */
  real_T tiempodemuestreoms_Value;     /* Expression: 10
                                        * Referenced by: '<S2>/tiempo de muestreo (ms)'
                                        */
  real_T mss_Gain;                     /* Expression: 1000
                                        * Referenced by: '<S2>/ms//s'
                                        */
  real_T revpulso_Gain;                /* Expression: 1/52
                                        * Referenced by: '<S2>/rev//pulso'
                                        */
  real_T Gain_Gain;                    /* Expression: 60/128
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T ModeloSystemIdentification_A_k[2];
                           /* Computed Parameter: ModeloSystemIdentification_A_k
                            * Referenced by: '<Root>/Modelo (System Identification)'
                            */
  real_T ModeloSystemIdentification_C_k[2];
                           /* Computed Parameter: ModeloSystemIdentification_C_k
                            * Referenced by: '<Root>/Modelo (System Identification)'
                            */
  real_T Internal_A_pr;                /* Computed Parameter: Internal_A_pr
                                        * Referenced by: '<S10>/Internal'
                                        */
  real_T Internal_B_pr;                /* Computed Parameter: Internal_B_pr
                                        * Referenced by: '<S10>/Internal'
                                        */
  real_T Internal_C_pr;                /* Computed Parameter: Internal_C_pr
                                        * Referenced by: '<S10>/Internal'
                                        */
  real_T Internal_D_pr;                /* Computed Parameter: Internal_D_pr
                                        * Referenced by: '<S10>/Internal'
                                        */
  real_T Internal_InitialCondition;    /* Expression: 0.0
                                        * Referenced by: '<S10>/Internal'
                                        */
  real_T Internal_A_pr_o[66];          /* Computed Parameter: Internal_A_pr_o
                                        * Referenced by: '<S18>/Internal'
                                        */
  real_T Internal_B_pr_b[11];          /* Computed Parameter: Internal_B_pr_b
                                        * Referenced by: '<S18>/Internal'
                                        */
  real_T Internal_C_pr_g[11];          /* Computed Parameter: Internal_C_pr_g
                                        * Referenced by: '<S18>/Internal'
                                        */
  real_T Internal_D_pr_e;              /* Computed Parameter: Internal_D_pr_e
                                        * Referenced by: '<S18>/Internal'
                                        */
  real_T Internal_InitialCondition_h;  /* Expression: 0.0
                                        * Referenced by: '<S18>/Internal'
                                        */
  real_T Gain1_Gain;                   /* Expression: 5
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Integrator2_IC;               /* Expression: 0
                                        * Referenced by: '<S3>/Integrator2'
                                        */
  real_T Saturation_UpperSat_p;        /* Expression: 0.5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat_f;        /* Expression: -0.5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T uTt_Gain;                     /* Expression: 0
                                        * Referenced by: '<S3>/1//Tt'
                                        */
  real_T Gain2_Gain;                   /* Expression: 3/0.5
                                        * Referenced by: '<S3>/Gain2'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S9>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S9>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_A_a;             /* Computed Parameter: TransferFcn1_A_a
                                        * Referenced by: '<S7>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_k;             /* Computed Parameter: TransferFcn1_C_k
                                        * Referenced by: '<S7>/Transfer Fcn1'
                                        */
  real_T Internal_A_pr_j;              /* Computed Parameter: Internal_A_pr_j
                                        * Referenced by: '<S14>/Internal'
                                        */
  real_T Internal_B_pr_f;              /* Computed Parameter: Internal_B_pr_f
                                        * Referenced by: '<S14>/Internal'
                                        */
  real_T Internal_C_pr_o;              /* Computed Parameter: Internal_C_pr_o
                                        * Referenced by: '<S14>/Internal'
                                        */
  real_T Internal_D_pr_k;              /* Computed Parameter: Internal_D_pr_k
                                        * Referenced by: '<S14>/Internal'
                                        */
  real_T Internal_InitialCondition_l;  /* Expression: 0.0
                                        * Referenced by: '<S14>/Internal'
                                        */
  real_T Internal_A_pr_l[66];          /* Computed Parameter: Internal_A_pr_l
                                        * Referenced by: '<S22>/Internal'
                                        */
  real_T Internal_B_pr_e[11];          /* Computed Parameter: Internal_B_pr_e
                                        * Referenced by: '<S22>/Internal'
                                        */
  real_T Internal_C_pr_j[11];          /* Computed Parameter: Internal_C_pr_j
                                        * Referenced by: '<S22>/Internal'
                                        */
  real_T Internal_D_pr_p;              /* Computed Parameter: Internal_D_pr_p
                                        * Referenced by: '<S22>/Internal'
                                        */
  real_T Internal_InitialCondition_j;  /* Expression: 0.0
                                        * Referenced by: '<S22>/Internal'
                                        */
  real_T Gain3_Gain;                   /* Expression: 1.5
                                        * Referenced by: '<S3>/Gain3'
                                        */
  real_T Integrator1_IC;               /* Expression: 0
                                        * Referenced by: '<S3>/Integrator1'
                                        */
  real_T Gain4_Gain;                   /* Expression: 1/0.5
                                        * Referenced by: '<S3>/Gain4'
                                        */
  real_T TransferFcn1_A_h;             /* Computed Parameter: TransferFcn1_A_h
                                        * Referenced by: '<S6>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_f;             /* Computed Parameter: TransferFcn1_C_f
                                        * Referenced by: '<S6>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_A_k;             /* Computed Parameter: TransferFcn1_A_k
                                        * Referenced by: '<S8>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_h;             /* Computed Parameter: TransferFcn1_C_h
                                        * Referenced by: '<S8>/Transfer Fcn1'
                                        */
  int64m_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S2>/Delay'
                                    */
  int32_T Gain_Gain_o;                 /* Computed Parameter: Gain_Gain_o
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint32_T Internal_A_ir;              /* Computed Parameter: Internal_A_ir
                                        * Referenced by: '<S10>/Internal'
                                        */
  uint32_T Internal_A_jc[2];           /* Computed Parameter: Internal_A_jc
                                        * Referenced by: '<S10>/Internal'
                                        */
  uint32_T Internal_B_ir;              /* Computed Parameter: Internal_B_ir
                                        * Referenced by: '<S10>/Internal'
                                        */
  uint32_T Internal_B_jc[2];           /* Computed Parameter: Internal_B_jc
                                        * Referenced by: '<S10>/Internal'
                                        */
  uint32_T Internal_C_ir;              /* Computed Parameter: Internal_C_ir
                                        * Referenced by: '<S10>/Internal'
                                        */
  uint32_T Internal_C_jc[2];           /* Computed Parameter: Internal_C_jc
                                        * Referenced by: '<S10>/Internal'
                                        */
  uint32_T Internal_D_ir;              /* Computed Parameter: Internal_D_ir
                                        * Referenced by: '<S10>/Internal'
                                        */
  uint32_T Internal_D_jc[2];           /* Computed Parameter: Internal_D_jc
                                        * Referenced by: '<S10>/Internal'
                                        */
  uint32_T Internal_A_ir_d[66];        /* Computed Parameter: Internal_A_ir_d
                                        * Referenced by: '<S18>/Internal'
                                        */
  uint32_T Internal_A_jc_e[12];        /* Computed Parameter: Internal_A_jc_e
                                        * Referenced by: '<S18>/Internal'
                                        */
  uint32_T Internal_B_ir_e[11];        /* Computed Parameter: Internal_B_ir_e
                                        * Referenced by: '<S18>/Internal'
                                        */
  uint32_T Internal_B_jc_g[2];         /* Computed Parameter: Internal_B_jc_g
                                        * Referenced by: '<S18>/Internal'
                                        */
  uint32_T Internal_C_ir_n[11];        /* Computed Parameter: Internal_C_ir_n
                                        * Referenced by: '<S18>/Internal'
                                        */
  uint32_T Internal_C_jc_n[12];        /* Computed Parameter: Internal_C_jc_n
                                        * Referenced by: '<S18>/Internal'
                                        */
  uint32_T Internal_D_ir_i;            /* Computed Parameter: Internal_D_ir_i
                                        * Referenced by: '<S18>/Internal'
                                        */
  uint32_T Internal_D_jc_a[2];         /* Computed Parameter: Internal_D_jc_a
                                        * Referenced by: '<S18>/Internal'
                                        */
  uint32_T Internal_A_ir_g;            /* Computed Parameter: Internal_A_ir_g
                                        * Referenced by: '<S14>/Internal'
                                        */
  uint32_T Internal_A_jc_d[2];         /* Computed Parameter: Internal_A_jc_d
                                        * Referenced by: '<S14>/Internal'
                                        */
  uint32_T Internal_B_ir_h;            /* Computed Parameter: Internal_B_ir_h
                                        * Referenced by: '<S14>/Internal'
                                        */
  uint32_T Internal_B_jc_e[2];         /* Computed Parameter: Internal_B_jc_e
                                        * Referenced by: '<S14>/Internal'
                                        */
  uint32_T Internal_C_ir_d;            /* Computed Parameter: Internal_C_ir_d
                                        * Referenced by: '<S14>/Internal'
                                        */
  uint32_T Internal_C_jc_e[2];         /* Computed Parameter: Internal_C_jc_e
                                        * Referenced by: '<S14>/Internal'
                                        */
  uint32_T Internal_D_ir_e;            /* Computed Parameter: Internal_D_ir_e
                                        * Referenced by: '<S14>/Internal'
                                        */
  uint32_T Internal_D_jc_m[2];         /* Computed Parameter: Internal_D_jc_m
                                        * Referenced by: '<S14>/Internal'
                                        */
  uint32_T Internal_A_ir_b[66];        /* Computed Parameter: Internal_A_ir_b
                                        * Referenced by: '<S22>/Internal'
                                        */
  uint32_T Internal_A_jc_e0[12];       /* Computed Parameter: Internal_A_jc_e0
                                        * Referenced by: '<S22>/Internal'
                                        */
  uint32_T Internal_B_ir_n[11];        /* Computed Parameter: Internal_B_ir_n
                                        * Referenced by: '<S22>/Internal'
                                        */
  uint32_T Internal_B_jc_c[2];         /* Computed Parameter: Internal_B_jc_c
                                        * Referenced by: '<S22>/Internal'
                                        */
  uint32_T Internal_C_ir_a[11];        /* Computed Parameter: Internal_C_ir_a
                                        * Referenced by: '<S22>/Internal'
                                        */
  uint32_T Internal_C_jc_o[12];        /* Computed Parameter: Internal_C_jc_o
                                        * Referenced by: '<S22>/Internal'
                                        */
  uint32_T Internal_D_ir_j;            /* Computed Parameter: Internal_D_ir_j
                                        * Referenced by: '<S22>/Internal'
                                        */
  uint32_T Internal_D_jc_mu[2];        /* Computed Parameter: Internal_D_jc_mu
                                        * Referenced by: '<S22>/Internal'
                                        */
  uint8_T ManualSwitch3_CurrentSetting;
                             /* Computed Parameter: ManualSwitch3_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch3'
                              */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
  uint8_T ManualSwitch1_CurrentSetting;
                             /* Computed Parameter: ManualSwitch1_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch1'
                              */
};

/* Real-time Model Data Structure */
struct tag_RTM_PID_MOTOR_T {
  const char_T *errorStatus;
  RTWSolverInfo solverInfo;
  X_PID_MOTOR_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_PID_MOTOR_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[36];
  real_T odeF[3][36];
  ODE3_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_PID_MOTOR_T PID_MOTOR_P;

/* Block signals (default storage) */
extern B_PID_MOTOR_T PID_MOTOR_B;

/* Continuous states (default storage) */
extern X_PID_MOTOR_T PID_MOTOR_X;

/* Block states (default storage) */
extern DW_PID_MOTOR_T PID_MOTOR_DW;

/* Model entry point functions */
extern void PID_MOTOR_initialize(void);
extern void PID_MOTOR_step(void);
extern void PID_MOTOR_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PID_MOTOR_T *const PID_MOTOR_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<Root>/Acción de control' : Unused code path elimination
 * Block '<Root>/Display' : Unused code path elimination
 * Block '<S1>/Add1' : Unused code path elimination
 * Block '<S1>/Gain' : Unused code path elimination
 * Block '<Root>/Manual Switch2' : Unused code path elimination
 * Block '<S3>/Error de seguimiento' : Unused code path elimination
 * Block '<Root>/rpm' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'PID_MOTOR'
 * '<S1>'   : 'PID_MOTOR/FO-PID CONTROL'
 * '<S2>'   : 'PID_MOTOR/Lectura del encoder'
 * '<S3>'   : 'PID_MOTOR/PID CONTROL'
 * '<S4>'   : 'PID_MOTOR/REFERENCE'
 * '<S5>'   : 'PID_MOTOR/Slider Gain'
 * '<S6>'   : 'PID_MOTOR/FO-PID CONTROL/Fractional derivative'
 * '<S7>'   : 'PID_MOTOR/FO-PID CONTROL/Fractional derivative1'
 * '<S8>'   : 'PID_MOTOR/FO-PID CONTROL/Fractional integrator'
 * '<S9>'   : 'PID_MOTOR/FO-PID CONTROL/Fractional integrator1'
 * '<S10>'  : 'PID_MOTOR/FO-PID CONTROL/Fractional derivative/LTI System'
 * '<S11>'  : 'PID_MOTOR/FO-PID CONTROL/Fractional derivative/LTI System/IO Delay'
 * '<S12>'  : 'PID_MOTOR/FO-PID CONTROL/Fractional derivative/LTI System/Input Delay'
 * '<S13>'  : 'PID_MOTOR/FO-PID CONTROL/Fractional derivative/LTI System/Output Delay'
 * '<S14>'  : 'PID_MOTOR/FO-PID CONTROL/Fractional derivative1/LTI System'
 * '<S15>'  : 'PID_MOTOR/FO-PID CONTROL/Fractional derivative1/LTI System/IO Delay'
 * '<S16>'  : 'PID_MOTOR/FO-PID CONTROL/Fractional derivative1/LTI System/Input Delay'
 * '<S17>'  : 'PID_MOTOR/FO-PID CONTROL/Fractional derivative1/LTI System/Output Delay'
 * '<S18>'  : 'PID_MOTOR/FO-PID CONTROL/Fractional integrator/LTI System'
 * '<S19>'  : 'PID_MOTOR/FO-PID CONTROL/Fractional integrator/LTI System/IO Delay'
 * '<S20>'  : 'PID_MOTOR/FO-PID CONTROL/Fractional integrator/LTI System/Input Delay'
 * '<S21>'  : 'PID_MOTOR/FO-PID CONTROL/Fractional integrator/LTI System/Output Delay'
 * '<S22>'  : 'PID_MOTOR/FO-PID CONTROL/Fractional integrator1/LTI System'
 * '<S23>'  : 'PID_MOTOR/FO-PID CONTROL/Fractional integrator1/LTI System/IO Delay'
 * '<S24>'  : 'PID_MOTOR/FO-PID CONTROL/Fractional integrator1/LTI System/Input Delay'
 * '<S25>'  : 'PID_MOTOR/FO-PID CONTROL/Fractional integrator1/LTI System/Output Delay'
 */
#endif                                 /* RTW_HEADER_PID_MOTOR_h_ */
