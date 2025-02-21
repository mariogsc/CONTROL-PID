/*
 * DC_MOTOR_CONTROL.h
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DC_MOTOR_CONTROL".
 *
 * Model version              : 1.63
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Thu Nov  7 16:26:23 2024
 *
 * Target selection: ert.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: ARM Compatible->ARM Cortex
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_DC_MOTOR_CONTROL_h_
#define RTW_HEADER_DC_MOTOR_CONTROL_h_
#ifndef DC_MOTOR_CONTROL_COMMON_INCLUDES_
#define DC_MOTOR_CONTROL_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "MW_arduino_digitalio.h"
#include "MW_ArduinoEncoder.h"
#include "MW_PWM.h"
#endif                                 /* DC_MOTOR_CONTROL_COMMON_INCLUDES_ */

#include "DC_MOTOR_CONTROL_types.h"
#include "multiword_types.h"
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

/* Block signals (default storage) */
typedef struct {
  int64m_T pulses2angle;               /* '<Root>/pulses2angle' */
  real_T CastToDouble1;                /* '<Root>/Cast To Double1' */
  real_T CastToDouble;                 /* '<Root>/Cast To Double' */
  real_T Output;                       /* '<S52>/Output' */
  real_T tiempoms;                     /* '<S2>/tiempo (ms)' */
  real_T Gain;                         /* '<S2>/Gain' */
  real_T Sum;                          /* '<S3>/Sum' */
  real_T Sum1;                         /* '<S11>/Sum1' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T CastToDouble2;                /* '<Root>/Cast To Double2' */
  real_T TmpSignalConversionAtTAQSigLogg[3];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux1_at_outport_0Inport1' */
  real_T Switch2[2];                   /* '<S55>/Switch2' */
  real_T Sum1_l;                       /* '<S8>/Sum1' */
  real_T Sum1_a;                       /* '<S10>/Sum1' */
  real_T Sum1_n;                       /* '<S57>/Sum1' */
  real_T Switch2_p[2];                 /* '<S53>/Switch2' */
  real_T Derivative1;                  /* '<S57>/Derivative1' */
  real_T Switch2_a[2];                 /* '<S54>/Switch2' */
  real_T CastToDouble3;                /* '<Root>/Cast To Double3' */
  real_T TmpSignalConversionAtTAQSigLo_i[2];
  /* '<Root>/TmpSignal ConversionAtTAQSigLogging_InsertedFor_Mux_at_outport_0Inport1' */
  real_T Pow;                          /* '<S57>/Pow' */
  real_T Sum3;                         /* '<S57>/Sum3' */
  real_T Pow_d;                        /* '<S56>/Pow' */
  real_T Sum3_i;                       /* '<S56>/Sum3' */
  real_T Internal;                     /* '<S64>/Internal' */
  real_T Derivative;                   /* '<S57>/Derivative' */
  real_T Pow_p;                        /* '<S10>/Pow' */
  real_T Sum3_d;                       /* '<S10>/Sum3' */
  real_T Pow_a;                        /* '<S8>/Pow' */
  real_T Sum3_k;                       /* '<S8>/Sum3' */
  real_T Internal_i;                   /* '<S18>/Internal' */
  real_T Internal_l;                   /* '<S14>/Internal' */
  real_T Sum1_o;                       /* '<S9>/Sum1' */
  real_T Product1;                     /* '<S22>/Product1' */
  real_T Internal_ii;                  /* '<S42>/Internal' */
  real_T Product;                      /* '<S9>/Product' */
  real_T Internal_n;                   /* '<S46>/Internal' */
  real_T Internal_m;                   /* '<S30>/Internal' */
  real_T Internal_o;                   /* '<S34>/Internal' */
  real_T Internal_b;                   /* '<S60>/Internal' */
  real_T Internal_d;                   /* '<S38>/Internal' */
  real_T Product1_j;                   /* '<S8>/Product1' */
  real_T Product1_e;                   /* '<S56>/Product1' */
  real_T Product_a;                    /* '<S8>/Product' */
  real_T Add_c;                        /* '<S56>/Add' */
  real_T Derivative_m;                 /* '<S11>/Derivative' */
  real_T Derivative1_c;                /* '<S11>/Derivative1' */
  real_T S;                            /* '<S11>/MATLAB Function2' */
  real_T Product1_k;                   /* '<S57>/Product1' */
  real_T u0;
  int32_T Delay;                       /* '<S2>/Delay' */
  int32_T Encoder;                     /* '<Root>/Encoder' */
  boolean_T GreaterThan;               /* '<S5>/GreaterThan' */
  boolean_T GreaterThan_e;             /* '<S4>/GreaterThan' */
  boolean_T GreaterThan_o;             /* '<S55>/GreaterThan' */
  boolean_T GreaterThan_a;             /* '<S53>/GreaterThan' */
  boolean_T GreaterThan_h;             /* '<S54>/GreaterThan' */
} B_DC_MOTOR_CONTROL_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  codertarget_arduinobase_inter_T obj; /* '<Root>/Encoder' */
  codertarget_arduinobase_block_T obj_h;/* '<Root>/Digital Output3' */
  codertarget_arduinobase_block_T obj_n;/* '<Root>/Digital Output1' */
  codertarget_arduinobase_int_p_T obj_e;/* '<Root>/PWM' */
  real_T NextOutput;                   /* '<S52>/White Noise' */
  real_T TimeStampA;                   /* '<S11>/Derivative' */
  real_T LastUAtTimeA;                 /* '<S11>/Derivative' */
  real_T TimeStampB;                   /* '<S11>/Derivative' */
  real_T LastUAtTimeB;                 /* '<S11>/Derivative' */
  real_T TimeStampA_b;                 /* '<S11>/Derivative1' */
  real_T LastUAtTimeA_f;               /* '<S11>/Derivative1' */
  real_T TimeStampB_h;                 /* '<S11>/Derivative1' */
  real_T LastUAtTimeB_a;               /* '<S11>/Derivative1' */
  real_T TimeStampA_j;                 /* '<S10>/Derivative' */
  real_T LastUAtTimeA_j;               /* '<S10>/Derivative' */
  real_T TimeStampB_p;                 /* '<S10>/Derivative' */
  real_T LastUAtTimeB_b;               /* '<S10>/Derivative' */
  real_T TimeStampA_c;                 /* '<S57>/Derivative1' */
  real_T LastUAtTimeA_l;               /* '<S57>/Derivative1' */
  real_T TimeStampB_f;                 /* '<S57>/Derivative1' */
  real_T LastUAtTimeB_f;               /* '<S57>/Derivative1' */
  real_T TimeStampA_i;                 /* '<S57>/Derivative' */
  real_T LastUAtTimeA_d;               /* '<S57>/Derivative' */
  real_T TimeStampB_m;                 /* '<S57>/Derivative' */
  real_T LastUAtTimeB_n;               /* '<S57>/Derivative' */
  struct {
    void *LoggedData;
  } Scope2_PWORK;                      /* '<Root>/Scope2' */

  struct {
    void *LoggedData[3];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[2];
  } Scope1_PWORK_m;                    /* '<S57>/Scope1' */

  int32_T Delay_DSTATE[100];           /* '<S2>/Delay' */
  uint32_T RandSeed;                   /* '<S52>/White Noise' */
  boolean_T objisempty;                /* '<Root>/PWM' */
  boolean_T objisempty_f;              /* '<Root>/Encoder' */
  boolean_T objisempty_i;              /* '<Root>/Digital Output3' */
  boolean_T objisempty_p;              /* '<Root>/Digital Output1' */
} DW_DC_MOTOR_CONTROL_T;

/* Continuous states (default storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<S58>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_o;        /* '<S59>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_f;        /* '<S25>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_i;        /* '<S28>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_l;        /* '<S27>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_d;        /* '<S13>/Transfer Fcn1' */
  real_T Integrator_CSTATE;            /* '<S10>/Integrator' */
  real_T Integrator_CSTATE_a;          /* '<S57>/Integrator' */
  real_T TransferFcn1_CSTATE_a;        /* '<S12>/Transfer Fcn1' */
  real_T Internal_CSTATE[11];          /* '<S64>/Internal' */
  real_T Internal_CSTATE_h[11];        /* '<S18>/Internal' */
  real_T Internal_CSTATE_c[11];        /* '<S14>/Internal' */
  real_T TransferFcn1_CSTATE_b;        /* '<S24>/Transfer Fcn1' */
  real_T Internal_CSTATE_k[13];        /* '<S42>/Internal' */
  real_T Internal_CSTATE_f[13];        /* '<S46>/Internal' */
  real_T Internal_CSTATE_b[13];        /* '<S30>/Internal' */
  real_T Internal_CSTATE_p[13];        /* '<S34>/Internal' */
  real_T Internal_CSTATE_j[11];        /* '<S60>/Internal' */
  real_T Internal_CSTATE_o[11];        /* '<S38>/Internal' */
  real_T TransferFcn1_CSTATE_od;       /* '<S26>/Transfer Fcn1' */
} X_DC_MOTOR_CONTROL_T;

/* State derivatives (default storage) */
typedef struct {
  real_T TransferFcn1_CSTATE;          /* '<S58>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_o;        /* '<S59>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_f;        /* '<S25>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_i;        /* '<S28>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_l;        /* '<S27>/Transfer Fcn1' */
  real_T TransferFcn1_CSTATE_d;        /* '<S13>/Transfer Fcn1' */
  real_T Integrator_CSTATE;            /* '<S10>/Integrator' */
  real_T Integrator_CSTATE_a;          /* '<S57>/Integrator' */
  real_T TransferFcn1_CSTATE_a;        /* '<S12>/Transfer Fcn1' */
  real_T Internal_CSTATE[11];          /* '<S64>/Internal' */
  real_T Internal_CSTATE_h[11];        /* '<S18>/Internal' */
  real_T Internal_CSTATE_c[11];        /* '<S14>/Internal' */
  real_T TransferFcn1_CSTATE_b;        /* '<S24>/Transfer Fcn1' */
  real_T Internal_CSTATE_k[13];        /* '<S42>/Internal' */
  real_T Internal_CSTATE_f[13];        /* '<S46>/Internal' */
  real_T Internal_CSTATE_b[13];        /* '<S30>/Internal' */
  real_T Internal_CSTATE_p[13];        /* '<S34>/Internal' */
  real_T Internal_CSTATE_j[11];        /* '<S60>/Internal' */
  real_T Internal_CSTATE_o[11];        /* '<S38>/Internal' */
  real_T TransferFcn1_CSTATE_od;       /* '<S26>/Transfer Fcn1' */
} XDot_DC_MOTOR_CONTROL_T;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn1_CSTATE;       /* '<S58>/Transfer Fcn1' */
  boolean_T TransferFcn1_CSTATE_o;     /* '<S59>/Transfer Fcn1' */
  boolean_T TransferFcn1_CSTATE_f;     /* '<S25>/Transfer Fcn1' */
  boolean_T TransferFcn1_CSTATE_i;     /* '<S28>/Transfer Fcn1' */
  boolean_T TransferFcn1_CSTATE_l;     /* '<S27>/Transfer Fcn1' */
  boolean_T TransferFcn1_CSTATE_d;     /* '<S13>/Transfer Fcn1' */
  boolean_T Integrator_CSTATE;         /* '<S10>/Integrator' */
  boolean_T Integrator_CSTATE_a;       /* '<S57>/Integrator' */
  boolean_T TransferFcn1_CSTATE_a;     /* '<S12>/Transfer Fcn1' */
  boolean_T Internal_CSTATE[11];       /* '<S64>/Internal' */
  boolean_T Internal_CSTATE_h[11];     /* '<S18>/Internal' */
  boolean_T Internal_CSTATE_c[11];     /* '<S14>/Internal' */
  boolean_T TransferFcn1_CSTATE_b;     /* '<S24>/Transfer Fcn1' */
  boolean_T Internal_CSTATE_k[13];     /* '<S42>/Internal' */
  boolean_T Internal_CSTATE_f[13];     /* '<S46>/Internal' */
  boolean_T Internal_CSTATE_b[13];     /* '<S30>/Internal' */
  boolean_T Internal_CSTATE_p[13];     /* '<S34>/Internal' */
  boolean_T Internal_CSTATE_j[11];     /* '<S60>/Internal' */
  boolean_T Internal_CSTATE_o[11];     /* '<S38>/Internal' */
  boolean_T TransferFcn1_CSTATE_od;    /* '<S26>/Transfer Fcn1' */
} XDis_DC_MOTOR_CONTROL_T;

#ifndef ODE3_INTG
#define ODE3_INTG

/* ODE3 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[3];                        /* derivatives */
} ODE3_IntgData;

#endif

/* Parameters (default storage) */
struct P_DC_MOTOR_CONTROL_T_ {
  real_T BandLimitedWhiteNoise_Cov; /* Mask Parameter: BandLimitedWhiteNoise_Cov
                                     * Referenced by: '<S52>/Output'
                                     */
  real_T BandLimitedWhiteNoise_seed;
                                   /* Mask Parameter: BandLimitedWhiteNoise_seed
                                    * Referenced by: '<S52>/White Noise'
                                    */
  real_T Encoder_SampleTime;           /* Expression: -1
                                        * Referenced by: '<Root>/Encoder'
                                        */
  real_T position_target_Value;        /* Expression: 0
                                        * Referenced by: '<Root>/position_target'
                                        */
  real_T Kp_v_Value;                   /* Expression: 7
                                        * Referenced by: '<Root>/Kp_v'
                                        */
  real_T velocity_target_Value;        /* Expression: -16.58756103515623
                                        * Referenced by: '<Root>/velocity_target'
                                        */
  real_T WhiteNoise_Mean;              /* Expression: 0
                                        * Referenced by: '<S52>/White Noise'
                                        */
  real_T WhiteNoise_StdDev;            /* Computed Parameter: WhiteNoise_StdDev
                                        * Referenced by: '<S52>/White Noise'
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
  real_T mode_Value;                   /* Expression: 1
                                        * Referenced by: '<Root>/mode'
                                        */
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<S5>/Constant9'
                                        */
  real_T Kd_v_Value;                   /* Expression: 9
                                        * Referenced by: '<Root>/Kd_v'
                                        */
  real_T TransferFcn1_A;               /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S58>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C;               /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S58>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_A_b;             /* Computed Parameter: TransferFcn1_A_b
                                        * Referenced by: '<S59>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_f;             /* Computed Parameter: TransferFcn1_C_f
                                        * Referenced by: '<S59>/Transfer Fcn1'
                                        */
  real_T Constant9_Value_j;            /* Expression: 0
                                        * Referenced by: '<S4>/Constant9'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S11>/Constant'
                                        */
  real_T lambda_Value;                 /* Expression: 10
                                        * Referenced by: '<S11>/lambda'
                                        */
  real_T K_Value;                      /* Expression: 25
                                        * Referenced by: '<S11>/K'
                                        */
  real_T W_Value;                      /* Expression: 0.0001
                                        * Referenced by: '<S11>/W'
                                        */
  real_T Constant_Value_l;             /* Expression: 0
                                        * Referenced by: '<S9>/Constant'
                                        */
  real_T TransferFcn1_A_h;             /* Computed Parameter: TransferFcn1_A_h
                                        * Referenced by: '<S25>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_g;             /* Computed Parameter: TransferFcn1_C_g
                                        * Referenced by: '<S25>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_A_j;             /* Computed Parameter: TransferFcn1_A_j
                                        * Referenced by: '<S28>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_i;             /* Computed Parameter: TransferFcn1_C_i
                                        * Referenced by: '<S28>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_A_n;             /* Computed Parameter: TransferFcn1_A_n
                                        * Referenced by: '<S27>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_fc;            /* Computed Parameter: TransferFcn1_C_fc
                                        * Referenced by: '<S27>/Transfer Fcn1'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 255
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -255
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T TransferFcn1_A_m;             /* Computed Parameter: TransferFcn1_A_m
                                        * Referenced by: '<S13>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_gz;            /* Computed Parameter: TransferFcn1_C_gz
                                        * Referenced by: '<S13>/Transfer Fcn1'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S10>/Integrator'
                                        */
  real_T Integrator_IC_m;              /* Expression: 0
                                        * Referenced by: '<S57>/Integrator'
                                        */
  real_T Constant9_Value_f;            /* Expression: 0
                                        * Referenced by: '<S55>/Constant9'
                                        */
  real_T Kp_p_Value;                   /* Expression: 19.5
                                        * Referenced by: '<Root>/Kp_p'
                                        */
  real_T Constant9_Value_n;            /* Expression: 0
                                        * Referenced by: '<S53>/Constant9'
                                        */
  real_T Kd_p_Value;                   /* Expression: 1
                                        * Referenced by: '<Root>/Kd_p'
                                        */
  real_T TransferFcn1_A_bm;            /* Computed Parameter: TransferFcn1_A_bm
                                        * Referenced by: '<S12>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_k;             /* Computed Parameter: TransferFcn1_C_k
                                        * Referenced by: '<S12>/Transfer Fcn1'
                                        */
  real_T Constant9_Value_i;            /* Expression: 0
                                        * Referenced by: '<S54>/Constant9'
                                        */
  real_T Constant_Value_d;             /* Expression: 0.5
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T Ki_v_Value;                   /* Expression: 31
                                        * Referenced by: '<Root>/Ki_v'
                                        */
  real_T Constant_Value_e;             /* Expression: 0.5
                                        * Referenced by: '<S56>/Constant'
                                        */
  real_T Internal_A_pr[66];            /* Computed Parameter: Internal_A_pr
                                        * Referenced by: '<S64>/Internal'
                                        */
  real_T Internal_B_pr[11];            /* Computed Parameter: Internal_B_pr
                                        * Referenced by: '<S64>/Internal'
                                        */
  real_T Internal_C_pr[11];            /* Computed Parameter: Internal_C_pr
                                        * Referenced by: '<S64>/Internal'
                                        */
  real_T Internal_D_pr;                /* Computed Parameter: Internal_D_pr
                                        * Referenced by: '<S64>/Internal'
                                        */
  real_T Internal_InitialCondition;    /* Expression: 0.0
                                        * Referenced by: '<S64>/Internal'
                                        */
  real_T Constant_Value_h;             /* Expression: 0.5
                                        * Referenced by: '<S10>/Constant'
                                        */
  real_T Ki_p_Value;                   /* Expression: 10
                                        * Referenced by: '<Root>/Ki_p'
                                        */
  real_T Constant_Value_dt;            /* Expression: 0.5
                                        * Referenced by: '<S8>/Constant'
                                        */
  real_T Internal_A_pr_i[66];          /* Computed Parameter: Internal_A_pr_i
                                        * Referenced by: '<S18>/Internal'
                                        */
  real_T Internal_B_pr_o[11];          /* Computed Parameter: Internal_B_pr_o
                                        * Referenced by: '<S18>/Internal'
                                        */
  real_T Internal_C_pr_d[11];          /* Computed Parameter: Internal_C_pr_d
                                        * Referenced by: '<S18>/Internal'
                                        */
  real_T Internal_D_pr_c;              /* Computed Parameter: Internal_D_pr_c
                                        * Referenced by: '<S18>/Internal'
                                        */
  real_T Internal_InitialCondition_n;  /* Expression: 0.0
                                        * Referenced by: '<S18>/Internal'
                                        */
  real_T Internal_A_pr_i1[66];         /* Computed Parameter: Internal_A_pr_i1
                                        * Referenced by: '<S14>/Internal'
                                        */
  real_T Internal_B_pr_e[11];          /* Computed Parameter: Internal_B_pr_e
                                        * Referenced by: '<S14>/Internal'
                                        */
  real_T Internal_C_pr_g[11];          /* Computed Parameter: Internal_C_pr_g
                                        * Referenced by: '<S14>/Internal'
                                        */
  real_T Internal_D_pr_cg;             /* Computed Parameter: Internal_D_pr_cg
                                        * Referenced by: '<S14>/Internal'
                                        */
  real_T Internal_InitialCondition_f;  /* Expression: 0.0
                                        * Referenced by: '<S14>/Internal'
                                        */
  real_T Constant2_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant3'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T Constant4_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant4'
                                        */
  real_T Constant1_Value;              /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T TransferFcn1_A_c;             /* Computed Parameter: TransferFcn1_A_c
                                        * Referenced by: '<S24>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_d;             /* Computed Parameter: TransferFcn1_C_d
                                        * Referenced by: '<S24>/Transfer Fcn1'
                                        */
  real_T lambda_Value_p;               /* Expression: 8
                                        * Referenced by: '<S9>/lambda'
                                        */
  real_T W_Value_e;                    /* Expression: 0.00001
                                        * Referenced by: '<S9>/W'
                                        */
  real_T K_Value_b;                    /* Expression: 6
                                        * Referenced by: '<S9>/K'
                                        */
  real_T Internal_A_pr_j[91];          /* Computed Parameter: Internal_A_pr_j
                                        * Referenced by: '<S42>/Internal'
                                        */
  real_T Internal_B_pr_d[13];          /* Computed Parameter: Internal_B_pr_d
                                        * Referenced by: '<S42>/Internal'
                                        */
  real_T Internal_C_pr_h[13];          /* Computed Parameter: Internal_C_pr_h
                                        * Referenced by: '<S42>/Internal'
                                        */
  real_T Internal_D_pr_i;              /* Computed Parameter: Internal_D_pr_i
                                        * Referenced by: '<S42>/Internal'
                                        */
  real_T Internal_InitialCondition_ns; /* Expression: 0.0
                                        * Referenced by: '<S42>/Internal'
                                        */
  real_T Internal_A_pr_c[91];          /* Computed Parameter: Internal_A_pr_c
                                        * Referenced by: '<S46>/Internal'
                                        */
  real_T Internal_B_pr_p[13];          /* Computed Parameter: Internal_B_pr_p
                                        * Referenced by: '<S46>/Internal'
                                        */
  real_T Internal_C_pr_h0[13];         /* Computed Parameter: Internal_C_pr_h0
                                        * Referenced by: '<S46>/Internal'
                                        */
  real_T Internal_D_pr_a;              /* Computed Parameter: Internal_D_pr_a
                                        * Referenced by: '<S46>/Internal'
                                        */
  real_T Internal_InitialCondition_o;  /* Expression: 0.0
                                        * Referenced by: '<S46>/Internal'
                                        */
  real_T Internal_A_pr_a[91];          /* Computed Parameter: Internal_A_pr_a
                                        * Referenced by: '<S30>/Internal'
                                        */
  real_T Internal_B_pr_ob[13];         /* Computed Parameter: Internal_B_pr_ob
                                        * Referenced by: '<S30>/Internal'
                                        */
  real_T Internal_C_pr_l[13];          /* Computed Parameter: Internal_C_pr_l
                                        * Referenced by: '<S30>/Internal'
                                        */
  real_T Internal_D_pr_k;              /* Computed Parameter: Internal_D_pr_k
                                        * Referenced by: '<S30>/Internal'
                                        */
  real_T Internal_InitialCondition_k;  /* Expression: 0.0
                                        * Referenced by: '<S30>/Internal'
                                        */
  real_T Internal_A_pr_iu[91];         /* Computed Parameter: Internal_A_pr_iu
                                        * Referenced by: '<S34>/Internal'
                                        */
  real_T Internal_B_pr_j[13];          /* Computed Parameter: Internal_B_pr_j
                                        * Referenced by: '<S34>/Internal'
                                        */
  real_T Internal_C_pr_j[13];          /* Computed Parameter: Internal_C_pr_j
                                        * Referenced by: '<S34>/Internal'
                                        */
  real_T Internal_D_pr_g;              /* Computed Parameter: Internal_D_pr_g
                                        * Referenced by: '<S34>/Internal'
                                        */
  real_T Internal_InitialCondition_a;  /* Expression: 0.0
                                        * Referenced by: '<S34>/Internal'
                                        */
  real_T Internal_A_pr_l[66];          /* Computed Parameter: Internal_A_pr_l
                                        * Referenced by: '<S60>/Internal'
                                        */
  real_T Internal_B_pr_c[11];          /* Computed Parameter: Internal_B_pr_c
                                        * Referenced by: '<S60>/Internal'
                                        */
  real_T Internal_C_pr_n[11];          /* Computed Parameter: Internal_C_pr_n
                                        * Referenced by: '<S60>/Internal'
                                        */
  real_T Internal_D_pr_kw;             /* Computed Parameter: Internal_D_pr_kw
                                        * Referenced by: '<S60>/Internal'
                                        */
  real_T Internal_InitialCondition_h;  /* Expression: 0.0
                                        * Referenced by: '<S60>/Internal'
                                        */
  real_T Internal_A_pr_a2[66];         /* Computed Parameter: Internal_A_pr_a2
                                        * Referenced by: '<S38>/Internal'
                                        */
  real_T Internal_B_pr_a[11];          /* Computed Parameter: Internal_B_pr_a
                                        * Referenced by: '<S38>/Internal'
                                        */
  real_T Internal_C_pr_b[11];          /* Computed Parameter: Internal_C_pr_b
                                        * Referenced by: '<S38>/Internal'
                                        */
  real_T Internal_D_pr_j;              /* Computed Parameter: Internal_D_pr_j
                                        * Referenced by: '<S38>/Internal'
                                        */
  real_T Internal_InitialCondition_kz; /* Expression: 0.0
                                        * Referenced by: '<S38>/Internal'
                                        */
  real_T TransferFcn1_A_f;             /* Computed Parameter: TransferFcn1_A_f
                                        * Referenced by: '<S26>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C_n;             /* Computed Parameter: TransferFcn1_C_n
                                        * Referenced by: '<S26>/Transfer Fcn1'
                                        */
  int32_T Delay_InitialCondition;  /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S2>/Delay'
                                    */
  int32_T pulses2angle_Gain;           /* Computed Parameter: pulses2angle_Gain
                                        * Referenced by: '<Root>/pulses2angle'
                                        */
  uint32_T Internal_A_ir[66];          /* Computed Parameter: Internal_A_ir
                                        * Referenced by: '<S64>/Internal'
                                        */
  uint32_T Internal_A_jc[12];          /* Computed Parameter: Internal_A_jc
                                        * Referenced by: '<S64>/Internal'
                                        */
  uint32_T Internal_B_ir[11];          /* Computed Parameter: Internal_B_ir
                                        * Referenced by: '<S64>/Internal'
                                        */
  uint32_T Internal_B_jc[2];           /* Computed Parameter: Internal_B_jc
                                        * Referenced by: '<S64>/Internal'
                                        */
  uint32_T Internal_C_ir[11];          /* Computed Parameter: Internal_C_ir
                                        * Referenced by: '<S64>/Internal'
                                        */
  uint32_T Internal_C_jc[12];          /* Computed Parameter: Internal_C_jc
                                        * Referenced by: '<S64>/Internal'
                                        */
  uint32_T Internal_D_ir;              /* Computed Parameter: Internal_D_ir
                                        * Referenced by: '<S64>/Internal'
                                        */
  uint32_T Internal_D_jc[2];           /* Computed Parameter: Internal_D_jc
                                        * Referenced by: '<S64>/Internal'
                                        */
  uint32_T Internal_A_ir_e[66];        /* Computed Parameter: Internal_A_ir_e
                                        * Referenced by: '<S18>/Internal'
                                        */
  uint32_T Internal_A_jc_d[12];        /* Computed Parameter: Internal_A_jc_d
                                        * Referenced by: '<S18>/Internal'
                                        */
  uint32_T Internal_B_ir_o[11];        /* Computed Parameter: Internal_B_ir_o
                                        * Referenced by: '<S18>/Internal'
                                        */
  uint32_T Internal_B_jc_n[2];         /* Computed Parameter: Internal_B_jc_n
                                        * Referenced by: '<S18>/Internal'
                                        */
  uint32_T Internal_C_ir_n[11];        /* Computed Parameter: Internal_C_ir_n
                                        * Referenced by: '<S18>/Internal'
                                        */
  uint32_T Internal_C_jc_f[12];        /* Computed Parameter: Internal_C_jc_f
                                        * Referenced by: '<S18>/Internal'
                                        */
  uint32_T Internal_D_ir_k;            /* Computed Parameter: Internal_D_ir_k
                                        * Referenced by: '<S18>/Internal'
                                        */
  uint32_T Internal_D_jc_d[2];         /* Computed Parameter: Internal_D_jc_d
                                        * Referenced by: '<S18>/Internal'
                                        */
  uint32_T Internal_A_ir_d[66];        /* Computed Parameter: Internal_A_ir_d
                                        * Referenced by: '<S14>/Internal'
                                        */
  uint32_T Internal_A_jc_f[12];        /* Computed Parameter: Internal_A_jc_f
                                        * Referenced by: '<S14>/Internal'
                                        */
  uint32_T Internal_B_ir_i[11];        /* Computed Parameter: Internal_B_ir_i
                                        * Referenced by: '<S14>/Internal'
                                        */
  uint32_T Internal_B_jc_l[2];         /* Computed Parameter: Internal_B_jc_l
                                        * Referenced by: '<S14>/Internal'
                                        */
  uint32_T Internal_C_ir_e[11];        /* Computed Parameter: Internal_C_ir_e
                                        * Referenced by: '<S14>/Internal'
                                        */
  uint32_T Internal_C_jc_i[12];        /* Computed Parameter: Internal_C_jc_i
                                        * Referenced by: '<S14>/Internal'
                                        */
  uint32_T Internal_D_ir_o;            /* Computed Parameter: Internal_D_ir_o
                                        * Referenced by: '<S14>/Internal'
                                        */
  uint32_T Internal_D_jc_d0[2];        /* Computed Parameter: Internal_D_jc_d0
                                        * Referenced by: '<S14>/Internal'
                                        */
  uint32_T Internal_A_ir_p[91];        /* Computed Parameter: Internal_A_ir_p
                                        * Referenced by: '<S42>/Internal'
                                        */
  uint32_T Internal_A_jc_c[14];        /* Computed Parameter: Internal_A_jc_c
                                        * Referenced by: '<S42>/Internal'
                                        */
  uint32_T Internal_B_ir_m[13];        /* Computed Parameter: Internal_B_ir_m
                                        * Referenced by: '<S42>/Internal'
                                        */
  uint32_T Internal_B_jc_h[2];         /* Computed Parameter: Internal_B_jc_h
                                        * Referenced by: '<S42>/Internal'
                                        */
  uint32_T Internal_C_ir_h[13];        /* Computed Parameter: Internal_C_ir_h
                                        * Referenced by: '<S42>/Internal'
                                        */
  uint32_T Internal_C_jc_g[14];        /* Computed Parameter: Internal_C_jc_g
                                        * Referenced by: '<S42>/Internal'
                                        */
  uint32_T Internal_D_ir_e;            /* Computed Parameter: Internal_D_ir_e
                                        * Referenced by: '<S42>/Internal'
                                        */
  uint32_T Internal_D_jc_m[2];         /* Computed Parameter: Internal_D_jc_m
                                        * Referenced by: '<S42>/Internal'
                                        */
  uint32_T Internal_A_ir_n[91];        /* Computed Parameter: Internal_A_ir_n
                                        * Referenced by: '<S46>/Internal'
                                        */
  uint32_T Internal_A_jc_b[14];        /* Computed Parameter: Internal_A_jc_b
                                        * Referenced by: '<S46>/Internal'
                                        */
  uint32_T Internal_B_ir_j[13];        /* Computed Parameter: Internal_B_ir_j
                                        * Referenced by: '<S46>/Internal'
                                        */
  uint32_T Internal_B_jc_e[2];         /* Computed Parameter: Internal_B_jc_e
                                        * Referenced by: '<S46>/Internal'
                                        */
  uint32_T Internal_C_ir_d[13];        /* Computed Parameter: Internal_C_ir_d
                                        * Referenced by: '<S46>/Internal'
                                        */
  uint32_T Internal_C_jc_n[14];        /* Computed Parameter: Internal_C_jc_n
                                        * Referenced by: '<S46>/Internal'
                                        */
  uint32_T Internal_D_ir_d;            /* Computed Parameter: Internal_D_ir_d
                                        * Referenced by: '<S46>/Internal'
                                        */
  uint32_T Internal_D_jc_n[2];         /* Computed Parameter: Internal_D_jc_n
                                        * Referenced by: '<S46>/Internal'
                                        */
  uint32_T Internal_A_ir_a[91];        /* Computed Parameter: Internal_A_ir_a
                                        * Referenced by: '<S30>/Internal'
                                        */
  uint32_T Internal_A_jc_a[14];        /* Computed Parameter: Internal_A_jc_a
                                        * Referenced by: '<S30>/Internal'
                                        */
  uint32_T Internal_B_ir_k[13];        /* Computed Parameter: Internal_B_ir_k
                                        * Referenced by: '<S30>/Internal'
                                        */
  uint32_T Internal_B_jc_b[2];         /* Computed Parameter: Internal_B_jc_b
                                        * Referenced by: '<S30>/Internal'
                                        */
  uint32_T Internal_C_ir_df[13];       /* Computed Parameter: Internal_C_ir_df
                                        * Referenced by: '<S30>/Internal'
                                        */
  uint32_T Internal_C_jc_a[14];        /* Computed Parameter: Internal_C_jc_a
                                        * Referenced by: '<S30>/Internal'
                                        */
  uint32_T Internal_D_ir_eq;           /* Computed Parameter: Internal_D_ir_eq
                                        * Referenced by: '<S30>/Internal'
                                        */
  uint32_T Internal_D_jc_a[2];         /* Computed Parameter: Internal_D_jc_a
                                        * Referenced by: '<S30>/Internal'
                                        */
  uint32_T Internal_A_ir_b[91];        /* Computed Parameter: Internal_A_ir_b
                                        * Referenced by: '<S34>/Internal'
                                        */
  uint32_T Internal_A_jc_n[14];        /* Computed Parameter: Internal_A_jc_n
                                        * Referenced by: '<S34>/Internal'
                                        */
  uint32_T Internal_B_ir_n[13];        /* Computed Parameter: Internal_B_ir_n
                                        * Referenced by: '<S34>/Internal'
                                        */
  uint32_T Internal_B_jc_k[2];         /* Computed Parameter: Internal_B_jc_k
                                        * Referenced by: '<S34>/Internal'
                                        */
  uint32_T Internal_C_ir_eq[13];       /* Computed Parameter: Internal_C_ir_eq
                                        * Referenced by: '<S34>/Internal'
                                        */
  uint32_T Internal_C_jc_e[14];        /* Computed Parameter: Internal_C_jc_e
                                        * Referenced by: '<S34>/Internal'
                                        */
  uint32_T Internal_D_ir_l;            /* Computed Parameter: Internal_D_ir_l
                                        * Referenced by: '<S34>/Internal'
                                        */
  uint32_T Internal_D_jc_e[2];         /* Computed Parameter: Internal_D_jc_e
                                        * Referenced by: '<S34>/Internal'
                                        */
  uint32_T Internal_A_ir_aq[66];       /* Computed Parameter: Internal_A_ir_aq
                                        * Referenced by: '<S60>/Internal'
                                        */
  uint32_T Internal_A_jc_k[12];        /* Computed Parameter: Internal_A_jc_k
                                        * Referenced by: '<S60>/Internal'
                                        */
  uint32_T Internal_B_ir_jh[11];       /* Computed Parameter: Internal_B_ir_jh
                                        * Referenced by: '<S60>/Internal'
                                        */
  uint32_T Internal_B_jc_bv[2];        /* Computed Parameter: Internal_B_jc_bv
                                        * Referenced by: '<S60>/Internal'
                                        */
  uint32_T Internal_C_ir_hf[11];       /* Computed Parameter: Internal_C_ir_hf
                                        * Referenced by: '<S60>/Internal'
                                        */
  uint32_T Internal_C_jc_fs[12];       /* Computed Parameter: Internal_C_jc_fs
                                        * Referenced by: '<S60>/Internal'
                                        */
  uint32_T Internal_D_ir_h;            /* Computed Parameter: Internal_D_ir_h
                                        * Referenced by: '<S60>/Internal'
                                        */
  uint32_T Internal_D_jc_k[2];         /* Computed Parameter: Internal_D_jc_k
                                        * Referenced by: '<S60>/Internal'
                                        */
  uint32_T Internal_A_ir_ew[66];       /* Computed Parameter: Internal_A_ir_ew
                                        * Referenced by: '<S38>/Internal'
                                        */
  uint32_T Internal_A_jc_m[12];        /* Computed Parameter: Internal_A_jc_m
                                        * Referenced by: '<S38>/Internal'
                                        */
  uint32_T Internal_B_ir_mn[11];       /* Computed Parameter: Internal_B_ir_mn
                                        * Referenced by: '<S38>/Internal'
                                        */
  uint32_T Internal_B_jc_a[2];         /* Computed Parameter: Internal_B_jc_a
                                        * Referenced by: '<S38>/Internal'
                                        */
  uint32_T Internal_C_ir_i[11];        /* Computed Parameter: Internal_C_ir_i
                                        * Referenced by: '<S38>/Internal'
                                        */
  uint32_T Internal_C_jc_o[12];        /* Computed Parameter: Internal_C_jc_o
                                        * Referenced by: '<S38>/Internal'
                                        */
  uint32_T Internal_D_ir_n;            /* Computed Parameter: Internal_D_ir_n
                                        * Referenced by: '<S38>/Internal'
                                        */
  uint32_T Internal_D_jc_c[2];         /* Computed Parameter: Internal_D_jc_c
                                        * Referenced by: '<S38>/Internal'
                                        */
  uint8_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<S1>/Manual Switch'
                               */
};

/* Real-time Model Data Structure */
struct tag_RTM_DC_MOTOR_CONTROL_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  X_DC_MOTOR_CONTROL_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  XDis_DC_MOTOR_CONTROL_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeY[118];
  real_T odeF[3][118];
  ODE3_IntgData intgData;

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
extern P_DC_MOTOR_CONTROL_T DC_MOTOR_CONTROL_P;

/* Block signals (default storage) */
extern B_DC_MOTOR_CONTROL_T DC_MOTOR_CONTROL_B;

/* Continuous states (default storage) */
extern X_DC_MOTOR_CONTROL_T DC_MOTOR_CONTROL_X;

/* Block states (default storage) */
extern DW_DC_MOTOR_CONTROL_T DC_MOTOR_CONTROL_DW;

/* Model entry point functions */
extern void DC_MOTOR_CONTROL_initialize(void);
extern void DC_MOTOR_CONTROL_step(void);
extern void DC_MOTOR_CONTROL_terminate(void);

/* Real-time Model object */
extern RT_MODEL_DC_MOTOR_CONTROL_T *const DC_MOTOR_CONTROL_M;
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S1>/Constant' : Unused code path elimination
 * Block '<S1>/GreaterThan' : Unused code path elimination
 * Block '<S1>/Switch' : Unused code path elimination
 * Block '<S7>/Constant' : Unused code path elimination
 * Block '<S56>/Derivative' : Unused code path elimination
 * Block '<S7>/GreaterThan' : Unused code path elimination
 * Block '<S7>/Switch' : Unused code path elimination
 * Block '<Root>/controller' : Unused code path elimination
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
 * '<Root>' : 'DC_MOTOR_CONTROL'
 * '<S1>'   : 'DC_MOTOR_CONTROL/POSITION CONTROL'
 * '<S2>'   : 'DC_MOTOR_CONTROL/Pulses2velocity'
 * '<S3>'   : 'DC_MOTOR_CONTROL/Subsystem'
 * '<S4>'   : 'DC_MOTOR_CONTROL/Subsystem1'
 * '<S5>'   : 'DC_MOTOR_CONTROL/Subsystem2'
 * '<S6>'   : 'DC_MOTOR_CONTROL/Subsystem3'
 * '<S7>'   : 'DC_MOTOR_CONTROL/VELOCITY CONTROL'
 * '<S8>'   : 'DC_MOTOR_CONTROL/POSITION CONTROL/FOPID '
 * '<S9>'   : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC'
 * '<S10>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/PID'
 * '<S11>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/SMC '
 * '<S12>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FOPID /Fractional derivative'
 * '<S13>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FOPID /Fractional integrator'
 * '<S14>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FOPID /Fractional derivative/LTI System'
 * '<S15>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FOPID /Fractional derivative/LTI System/IO Delay'
 * '<S16>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FOPID /Fractional derivative/LTI System/Input Delay'
 * '<S17>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FOPID /Fractional derivative/LTI System/Output Delay'
 * '<S18>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FOPID /Fractional integrator/LTI System'
 * '<S19>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FOPID /Fractional integrator/LTI System/IO Delay'
 * '<S20>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FOPID /Fractional integrator/LTI System/Input Delay'
 * '<S21>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FOPID /Fractional integrator/LTI System/Output Delay'
 * '<S22>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/A2'
 * '<S23>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Control action'
 * '<S24>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative'
 * '<S25>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative1'
 * '<S26>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative2'
 * '<S27>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative3'
 * '<S28>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative4'
 * '<S29>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/A2/MATLAB Function2'
 * '<S30>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative/LTI System'
 * '<S31>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative/LTI System/IO Delay'
 * '<S32>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative/LTI System/Input Delay'
 * '<S33>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative/LTI System/Output Delay'
 * '<S34>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative1/LTI System'
 * '<S35>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative1/LTI System/IO Delay'
 * '<S36>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative1/LTI System/Input Delay'
 * '<S37>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative1/LTI System/Output Delay'
 * '<S38>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative2/LTI System'
 * '<S39>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative2/LTI System/IO Delay'
 * '<S40>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative2/LTI System/Input Delay'
 * '<S41>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative2/LTI System/Output Delay'
 * '<S42>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative3/LTI System'
 * '<S43>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative3/LTI System/IO Delay'
 * '<S44>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative3/LTI System/Input Delay'
 * '<S45>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative3/LTI System/Output Delay'
 * '<S46>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative4/LTI System'
 * '<S47>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative4/LTI System/IO Delay'
 * '<S48>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative4/LTI System/Input Delay'
 * '<S49>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/FO_SMC/Fractional derivative4/LTI System/Output Delay'
 * '<S50>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/SMC /Control action'
 * '<S51>'  : 'DC_MOTOR_CONTROL/POSITION CONTROL/SMC /MATLAB Function2'
 * '<S52>'  : 'DC_MOTOR_CONTROL/Subsystem/Band-Limited White Noise'
 * '<S53>'  : 'DC_MOTOR_CONTROL/Subsystem3/Subsystem'
 * '<S54>'  : 'DC_MOTOR_CONTROL/Subsystem3/Subsystem1'
 * '<S55>'  : 'DC_MOTOR_CONTROL/Subsystem3/Subsystem2'
 * '<S56>'  : 'DC_MOTOR_CONTROL/VELOCITY CONTROL/FOPI-D anti windup'
 * '<S57>'  : 'DC_MOTOR_CONTROL/VELOCITY CONTROL/PI-D anti windup'
 * '<S58>'  : 'DC_MOTOR_CONTROL/VELOCITY CONTROL/FOPI-D anti windup/Fractional derivative'
 * '<S59>'  : 'DC_MOTOR_CONTROL/VELOCITY CONTROL/FOPI-D anti windup/Fractional integrator'
 * '<S60>'  : 'DC_MOTOR_CONTROL/VELOCITY CONTROL/FOPI-D anti windup/Fractional derivative/LTI System'
 * '<S61>'  : 'DC_MOTOR_CONTROL/VELOCITY CONTROL/FOPI-D anti windup/Fractional derivative/LTI System/IO Delay'
 * '<S62>'  : 'DC_MOTOR_CONTROL/VELOCITY CONTROL/FOPI-D anti windup/Fractional derivative/LTI System/Input Delay'
 * '<S63>'  : 'DC_MOTOR_CONTROL/VELOCITY CONTROL/FOPI-D anti windup/Fractional derivative/LTI System/Output Delay'
 * '<S64>'  : 'DC_MOTOR_CONTROL/VELOCITY CONTROL/FOPI-D anti windup/Fractional integrator/LTI System'
 * '<S65>'  : 'DC_MOTOR_CONTROL/VELOCITY CONTROL/FOPI-D anti windup/Fractional integrator/LTI System/IO Delay'
 * '<S66>'  : 'DC_MOTOR_CONTROL/VELOCITY CONTROL/FOPI-D anti windup/Fractional integrator/LTI System/Input Delay'
 * '<S67>'  : 'DC_MOTOR_CONTROL/VELOCITY CONTROL/FOPI-D anti windup/Fractional integrator/LTI System/Output Delay'
 */
#endif                                 /* RTW_HEADER_DC_MOTOR_CONTROL_h_ */
