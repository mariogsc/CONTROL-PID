/*
 * PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022".
 *
 * Model version              : 1.7
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Mon Oct 14 22:05:10 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_h_
#define RTW_HEADER_PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_h_
#ifndef PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_COMMON_INCLUDES_
#define PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduino_digitalio.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#endif             /* PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_COMMON_INCLUDES_ */

#include "PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_types.h"
#include "multiword_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <math.h>
#include <string.h>
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

#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
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

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
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

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                ((rtm)->Timing.t)
#endif

#define PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_M (PID_VELOCIDAD_MOTORDC_ANTI_W_M)

/* Block signals (default storage) */
typedef struct {
  int64m_T Gain;                       /* '<Root>/Gain' */
  int64m_T Delay;                      /* '<S2>/Delay' */
  real_T SliderGain;                   /* '<S4>/Slider Gain' */
  real_T tiempoms;                     /* '<S2>/tiempo (ms)' */
  real_T Gain_k;                       /* '<S2>/Gain' */
  real_T ManualSwitch3;                /* '<Root>/Manual Switch3' */
  real_T TmpSignalConversionAtTAQSigLogg[3];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  real_T Sum;                          /* '<S1>/Sum' */
  real_T Saturation;                   /* '<S1>/Saturation' */
  real_T Sum3;                         /* '<S6>/Sum3' */
  real_T Sum_p;                        /* '<S3>/Sum' */
  real_T Saturation_n;                 /* '<S3>/Saturation' */
  real_T Sum3_l;                       /* '<S19>/Sum3' */
  real_T Sum1;                         /* '<S3>/Sum1' */
  real_T Sum1_n;                       /* '<S1>/Sum1' */
  real_T ManualSwitch2;                /* '<Root>/Manual Switch2' */
  real_T Saturation_m;                 /* '<Root>/Saturation' */
  real_T Sum3_lv;                      /* '<S17>/Sum3' */
  real_T Sum3_l2;                      /* '<S5>/Sum3' */
  real_T Internal;                     /* '<S13>/Internal' */
  real_T Internal_g;                   /* '<S9>/Internal' */
  real_T Sum3_d;                       /* '<S18>/Sum3' */
  int32_T Encoder;                     /* '<Root>/Encoder' */
} B_PID_VELOCIDAD_MOTORDC_ANTI__T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Encoder' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Output3' */
  codertarget_arduinobase_block_T obj_n;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_int_o_T obj_e;/* '<Root>/PWM' */
  int64m_T Delay_DSTATE[100];          /* '<S2>/Delay' */
  real_T TimeStampA;                   /* '<S6>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S6>/Derivative' */
  real_T TimeStampB;                   /* '<S6>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S6>/Derivative' */
  real_T TimeStampA_n;                 /* '<S19>/Derivative' */
  real_T LastUAtTimeA_l;               /* '<S19>/Derivative' */
  real_T TimeStampB_g;                 /* '<S19>/Derivative' */
  real_T LastUAtTimeB_p;               /* '<S19>/Derivative' */
  real_T TimeStampA_j;                 /* '<S17>/Derivative' */
  real_T LastUAtTimeA_e;               /* '<S17>/Derivative' */
  real_T TimeStampB_f;                 /* '<S17>/Derivative' */
  real_T LastUAtTimeB_i;               /* '<S17>/Derivative' */
  real_T TimeStampA_a;                 /* '<S18>/Derivative' */
  real_T LastUAtTimeA_a;               /* '<S18>/Derivative' */
  real_T TimeStampB_b;                 /* '<S18>/Derivative' */
  real_T LastUAtTimeB_j;               /* '<S18>/Derivative' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  boolean_T objisempty;                /* '<Root>/PWM' */
  boolean_T objisempty_f;              /* '<Root>/Encoder' */
  boolean_T objisempty_i;              /* '<Root>/Digital Output3' */
  boolean_T objisempty_p;              /* '<Root>/Digital Output1' */
} DW_PID_VELOCIDAD_MOTORDC_ANTI_T;

/* Continuous states (default storage) */
typedef struct {
  real_T ModeloSystemIdentification_CSTA;
                                     /* '<S3>/Modelo (System Identification)' */
  real_T ModeloSystemIdentification_CS_f;
                                     /* '<S1>/Modelo (System Identification)' */
  real_T Integrator_CSTATE;            /* '<S6>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S19>/Integrator' */
  real_T Integrator_CSTATE_o;          /* '<S17>/Integrator' */
  real_T TransferFcn1_CSTATE;          /* '<S7>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_a;        /* '<S8>/Transfer Fcn1' */
  real_T Internal_CSTATE[11];          /* '<S13>/Internal' */
  real_T Internal_CSTATE_o[11];        /* '<S9>/Internal' */
  real_T Integrator_CSTATE_h;          /* '<S18>/Integrator' */
} X_PID_VELOCIDAD_MOTORDC_ANTI__T;

/* State derivatives (default storage) */
typedef struct {
  real_T ModeloSystemIdentification_CSTA;
                                     /* '<S3>/Modelo (System Identification)' */
  real_T ModeloSystemIdentification_CS_f;
                                     /* '<S1>/Modelo (System Identification)' */
  real_T Integrator_CSTATE;            /* '<S6>/Integrator' */
  real_T Integrator_CSTATE_i;          /* '<S19>/Integrator' */
  real_T Integrator_CSTATE_o;          /* '<S17>/Integrator' */
  real_T TransferFcn1_CSTATE;          /* '<S7>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_a;        /* '<S8>/Transfer Fcn1' */
  real_T Internal_CSTATE[11];          /* '<S13>/Internal' */
  real_T Internal_CSTATE_o[11];        /* '<S9>/Internal' */
  real_T Integrator_CSTATE_h;          /* '<S18>/Integrator' */
} XDot_PID_VELOCIDAD_MOTORDC_AN_T;

/* State disabled  */
typedef struct {
  boolean_T ModeloSystemIdentification_CSTA;
                                     /* '<S3>/Modelo (System Identification)' */
  boolean_T ModeloSystemIdentification_CS_f;
                                     /* '<S1>/Modelo (System Identification)' */
  boolean_T Integrator_CSTATE;         /* '<S6>/Integrator' */
  boolean_T Integrator_CSTATE_i;       /* '<S19>/Integrator' */
  boolean_T Integrator_CSTATE_o;       /* '<S17>/Integrator' */
  boolean_T TransferFcn1_CSTATE;       /* '<S7>/Transfer Fcn1' */
  boolean_T TransferFcn1_CSTATE_a;     /* '<S8>/Transfer Fcn1' */
  boolean_T Internal_CSTATE[11];       /* '<S13>/Internal' */
  boolean_T Internal_CSTATE_o[11];     /* '<S9>/Internal' */
  boolean_T Integrator_CSTATE_h;       /* '<S18>/Integrator' */
} XDis_PID_VELOCIDAD_MOTORDC_AN_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* Parameters (default storage) */
struct P_PID_VELOCIDAD_MOTORDC_ANTI__T_ {
  real_T kd;                           /* Variable: kd
                                        * Referenced by:
                                        *   '<S5>/Gain1'
                                        *   '<S17>/Gain1'
                                        */
  real_T ki;                           /* Variable: ki
                                        * Referenced by:
                                        *   '<S5>/Gain2'
                                        *   '<S6>/Gain2'
                                        *   '<S17>/Gain2'
                                        *   '<S18>/Gain2'
                                        *   '<S19>/Gain2'
                                        */
  real_T kp;                           /* Variable: kp
                                        * Referenced by:
                                        *   '<S5>/Gain3'
                                        *   '<S6>/Gain3'
                                        *   '<S17>/Gain3'
                                        *   '<S18>/Gain3'
                                        *   '<S19>/Gain3'
                                        */
  real_T SliderGain_gain;              /* Mask Parameter: SliderGain_gain
                                        * Referenced by: '<S4>/Slider Gain'
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
  real_T ModeloSystemIdentification_A;
                             /* Computed Parameter: ModeloSystemIdentification_A
                              * Referenced by: '<S3>/Modelo (System Identification)'
                              */
  real_T ModeloSystemIdentification_C;
                             /* Computed Parameter: ModeloSystemIdentification_C
                              * Referenced by: '<S3>/Modelo (System Identification)'
                              */
  real_T ModeloSystemIdentification_A_f;
                           /* Computed Parameter: ModeloSystemIdentification_A_f
                            * Referenced by: '<S1>/Modelo (System Identification)'
                            */
  real_T ModeloSystemIdentification_C_n;
                           /* Computed Parameter: ModeloSystemIdentification_C_n
                            * Referenced by: '<S1>/Modelo (System Identification)'
                            */
  real_T Gain1_Gain;                   /* Expression: 0
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S6>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 0.5
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -0.5
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Gain_Gain_a;                  /* Expression: (1/ki)^0.5
                                        * Referenced by: '<S6>/Gain'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: 0
                                        * Referenced by: '<S19>/Gain1'
                                        */
  real_T Integrator_IC_h;              /* Expression: 0
                                        * Referenced by: '<S19>/Integrator'
                                        */
  real_T Saturation_UpperSat_o;        /* Expression: 0.5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Saturation_LowerSat_p;        /* Expression: -0.5
                                        * Referenced by: '<S3>/Saturation'
                                        */
  real_T Gain_Gain_o;                  /* Expression: (1/ki)^0.5
                                        * Referenced by: '<S19>/Gain'
                                        */
  real_T Integrator_IC_i;              /* Expression: 0
                                        * Referenced by: '<S17>/Integrator'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S7>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S7>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_A_j;             /* Computed Parameter: TransferFcn1_A_j
                                        * Referenced by: '<S8>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_h;             /* Computed Parameter: TransferFcn1_C_h
                                        * Referenced by: '<S8>/Transfer Fcn1'
                                        */
  real_T Saturation_UpperSat_oo;       /* Expression: 255
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat_n;        /* Expression: 0
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Gain_Gain_g;                  /* Expression: (kp/ki)^0.5
                                        * Referenced by: '<S17>/Gain'
                                        */
  real_T Gain_Gain_k;                  /* Expression: (kd/ki)^0.5
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Internal_A_pr[66];            /* Computed Parameter: Internal_A_pr
                                        * Referenced by: '<S13>/Internal'
                                        */
  real_T Internal_B_pr[11];            /* Computed Parameter: Internal_B_pr
                                        * Referenced by: '<S13>/Internal'
                                        */
  real_T Internal_C_pr[11];            /* Computed Parameter: Internal_C_pr
                                        * Referenced by: '<S13>/Internal'
                                        */
  real_T Internal_D_pr;                /* Computed Parameter: Internal_D_pr
                                        * Referenced by: '<S13>/Internal'
                                        */
  real_T Internal_InitialCondition;    /* Expression: 0.0
                                        * Referenced by: '<S13>/Internal'
                                        */
  real_T Internal_A_pr_g[66];          /* Computed Parameter: Internal_A_pr_g
                                        * Referenced by: '<S9>/Internal'
                                        */
  real_T Internal_B_pr_f[11];          /* Computed Parameter: Internal_B_pr_f
                                        * Referenced by: '<S9>/Internal'
                                        */
  real_T Internal_C_pr_h[11];          /* Computed Parameter: Internal_C_pr_h
                                        * Referenced by: '<S9>/Internal'
                                        */
  real_T Internal_D_pr_l;              /* Computed Parameter: Internal_D_pr_l
                                        * Referenced by: '<S9>/Internal'
                                        */
  real_T Internal_InitialCondition_p;  /* Expression: 0.0
                                        * Referenced by: '<S9>/Internal'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: 0
                                        * Referenced by: '<S18>/Gain1'
                                        */
  real_T Integrator_IC_n;              /* Expression: 0
                                        * Referenced by: '<S18>/Integrator'
                                        */
  real_T Gain_Gain_op;                 /* Expression: (1/ki)^0.5
                                        * Referenced by: '<S18>/Gain'
                                        */
  int64m_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S2>/Delay'
                                    */
  int32_T Gain_Gain_n;                 /* Computed Parameter: Gain_Gain_n
                                        * Referenced by: '<Root>/Gain'
                                        */
  uint32_T Internal_A_ir[66];          /* Computed Parameter: Internal_A_ir
                                        * Referenced by: '<S13>/Internal'
                                        */
  uint32_T Internal_A_jc[12];          /* Computed Parameter: Internal_A_jc
                                        * Referenced by: '<S13>/Internal'
                                        */
  uint32_T Internal_B_ir[11];          /* Computed Parameter: Internal_B_ir
                                        * Referenced by: '<S13>/Internal'
                                        */
  uint32_T Internal_B_jc[2];           /* Computed Parameter: Internal_B_jc
                                        * Referenced by: '<S13>/Internal'
                                        */
  uint32_T Internal_C_ir[11];          /* Computed Parameter: Internal_C_ir
                                        * Referenced by: '<S13>/Internal'
                                        */
  uint32_T Internal_C_jc[12];          /* Computed Parameter: Internal_C_jc
                                        * Referenced by: '<S13>/Internal'
                                        */
  uint32_T Internal_D_ir;              /* Computed Parameter: Internal_D_ir
                                        * Referenced by: '<S13>/Internal'
                                        */
  uint32_T Internal_D_jc[2];           /* Computed Parameter: Internal_D_jc
                                        * Referenced by: '<S13>/Internal'
                                        */
  uint32_T Internal_A_ir_g[66];        /* Computed Parameter: Internal_A_ir_g
                                        * Referenced by: '<S9>/Internal'
                                        */
  uint32_T Internal_A_jc_k[12];        /* Computed Parameter: Internal_A_jc_k
                                        * Referenced by: '<S9>/Internal'
                                        */
  uint32_T Internal_B_ir_g[11];        /* Computed Parameter: Internal_B_ir_g
                                        * Referenced by: '<S9>/Internal'
                                        */
  uint32_T Internal_B_jc_g[2];         /* Computed Parameter: Internal_B_jc_g
                                        * Referenced by: '<S9>/Internal'
                                        */
  uint32_T Internal_C_ir_k[11];        /* Computed Parameter: Internal_C_ir_k
                                        * Referenced by: '<S9>/Internal'
                                        */
  uint32_T Internal_C_jc_o[12];        /* Computed Parameter: Internal_C_jc_o
                                        * Referenced by: '<S9>/Internal'
                                        */
  uint32_T Internal_D_ir_p;            /* Computed Parameter: Internal_D_ir_p
                                        * Referenced by: '<S9>/Internal'
                                        */
  uint32_T Internal_D_jc_a[2];         /* Computed Parameter: Internal_D_jc_a
                                        * Referenced by: '<S9>/Internal'
                                        */
  uint8_T ManualSwitch3_CurrentSetting;
                             /* Computed Parameter: ManualSwitch3_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch3'
                              */
  uint8_T ManualSwitch2_CurrentSetting;
                             /* Computed Parameter: ManualSwitch2_CurrentSetting
                              * Referenced by: '<Root>/Manual Switch2'
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
struct tag_RTM_PID_VELOCIDAD_MOTORDC_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_PID_VELOCIDAD_MOTORDC_ANTI__T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_PID_VELOCIDAD_MOTORDC_AN_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][30];
  ODE1_IntgData intgData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numSampTimes;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

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
    time_T tFinal;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *t;
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_PID_VELOCIDAD_MOTORDC_ANTI__T PID_VELOCIDAD_MOTORDC_ANTI_WI_P;

/* Block signals (default storage) */
extern B_PID_VELOCIDAD_MOTORDC_ANTI__T PID_VELOCIDAD_MOTORDC_ANTI_WI_B;

/* Continuous states (default storage) */
extern X_PID_VELOCIDAD_MOTORDC_ANTI__T PID_VELOCIDAD_MOTORDC_ANTI_WI_X;

/* Block states (default storage) */
extern DW_PID_VELOCIDAD_MOTORDC_ANTI_T PID_VELOCIDAD_MOTORDC_ANTI_W_DW;

/* Model entry point functions */
extern void PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_initialize(void);
extern void PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_step(void);
extern void PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_terminate(void);

/* Real-time Model object */
extern RT_MODEL_PID_VELOCIDAD_MOTORD_T *const PID_VELOCIDAD_MOTORDC_ANTI_W_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

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
 * '<Root>' : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022'
 * '<S1>'   : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/FOPID CONTROL'
 * '<S2>'   : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/Lectura del encoder'
 * '<S3>'   : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/PID CONTROL'
 * '<S4>'   : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/Slider Gain'
 * '<S5>'   : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/FOPID CONTROL/PID ANTI WINDUP'
 * '<S6>'   : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/FOPID CONTROL/PID ANTI WINDUP2'
 * '<S7>'   : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/FOPID CONTROL/PID ANTI WINDUP/Fractional derivative'
 * '<S8>'   : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/FOPID CONTROL/PID ANTI WINDUP/Fractional integrator'
 * '<S9>'   : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/FOPID CONTROL/PID ANTI WINDUP/Fractional derivative/LTI System'
 * '<S10>'  : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/FOPID CONTROL/PID ANTI WINDUP/Fractional derivative/LTI System/IO Delay'
 * '<S11>'  : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/FOPID CONTROL/PID ANTI WINDUP/Fractional derivative/LTI System/Input Delay'
 * '<S12>'  : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/FOPID CONTROL/PID ANTI WINDUP/Fractional derivative/LTI System/Output Delay'
 * '<S13>'  : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/FOPID CONTROL/PID ANTI WINDUP/Fractional integrator/LTI System'
 * '<S14>'  : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/FOPID CONTROL/PID ANTI WINDUP/Fractional integrator/LTI System/IO Delay'
 * '<S15>'  : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/FOPID CONTROL/PID ANTI WINDUP/Fractional integrator/LTI System/Input Delay'
 * '<S16>'  : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/FOPID CONTROL/PID ANTI WINDUP/Fractional integrator/LTI System/Output Delay'
 * '<S17>'  : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/PID CONTROL/PID ANTI WINDUP'
 * '<S18>'  : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/PID CONTROL/PID ANTI WINDUP1'
 * '<S19>'  : 'PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022/PID CONTROL/PID ANTI WINDUP2'
 */
#endif                /* RTW_HEADER_PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_h_ */
