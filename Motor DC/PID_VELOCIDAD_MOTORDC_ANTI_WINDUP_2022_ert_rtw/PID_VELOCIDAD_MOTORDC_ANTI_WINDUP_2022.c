/*
 * PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022.c
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

#include "PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022.h"
#include "rtwtypes.h"
#include "PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_types.h"
#include "PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_private.h"
#include "multiword_types.h"
#include <string.h>
#include <math.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_PID_VELOCIDAD_MOTORDC_ANTI__T PID_VELOCIDAD_MOTORDC_ANTI_WI_B;

/* Continuous states */
X_PID_VELOCIDAD_MOTORDC_ANTI__T PID_VELOCIDAD_MOTORDC_ANTI_WI_X;

/* Block states (default storage) */
DW_PID_VELOCIDAD_MOTORDC_ANTI_T PID_VELOCIDAD_MOTORDC_ANTI_W_DW;

/* Real-time model */
static RT_MODEL_PID_VELOCIDAD_MOTORD_T PID_VELOCIDAD_MOTORDC_ANTI_W_M_;
RT_MODEL_PID_VELOCIDAD_MOTORD_T *const PID_VELOCIDAD_MOTORDC_ANTI_W_M =
  &PID_VELOCIDAD_MOTORDC_ANTI_W_M_;
void sMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[], int32_T
                   n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T ni;
  uint32_T a0;
  uint32_T a1;
  uint32_T b1;
  uint32_T cb;
  uint32_T cb1;
  uint32_T cb2;
  uint32_T u1i;
  uint32_T w01;
  uint32_T w10;
  uint32_T yk;
  boolean_T isNegative1;
  boolean_T isNegative2;
  isNegative1 = ((u1[n1 - 1] & 2147483648U) != 0U);
  isNegative2 = ((u2[n2 - 1] & 2147483648U) != 0U);
  cb1 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative1) {
      u1i = ~u1i + cb1;
      cb1 = (uint32_T)(u1i < cb1);
    }

    a1 = u1i >> 16U;
    a0 = u1i & 65535U;
    cb2 = 1U;
    ni = n - i;
    ni = n2 <= ni ? n2 : ni;
    k = i;
    for (j = 0; j < ni; j++) {
      u1i = u2[j];
      if (isNegative2) {
        u1i = ~u1i + cb2;
        cb2 = (uint32_T)(u1i < cb2);
      }

      b1 = u1i >> 16U;
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk = y[k] + cb;
      cb = (uint32_T)(yk < cb);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w10 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      u1i = w01 << 16U;
      yk += u1i;
      cb += (uint32_T)(yk < u1i);
      y[k] = yk;
      cb += w10 >> 16U;
      cb += w01 >> 16U;
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1 != isNegative2) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = ~y[k] + cb;
      y[k] = yk;
      cb = (uint32_T)(yk < cb);
    }
  }
}

real_T sMultiWord2Double(const uint32_T u1[], int32_T n1, int32_T e1)
{
  real_T y;
  int32_T exp_0;
  int32_T i;
  uint32_T cb;
  uint32_T u1i;
  y = 0.0;
  exp_0 = e1;
  if ((u1[n1 - 1] & 2147483648U) != 0U) {
    cb = 1U;
    for (i = 0; i < n1; i++) {
      u1i = ~u1[i];
      cb += u1i;
      y -= ldexp(cb, exp_0);
      cb = (uint32_T)(cb < u1i);
      exp_0 += 32;
    }
  } else {
    for (i = 0; i < n1; i++) {
      y += ldexp(u1[i], exp_0);
      exp_0 += 32;
    }
  }

  return y;
}

void MultiWordSub(const uint32_T u1[], const uint32_T u2[], uint32_T y[],
                  int32_T n)
{
  int32_T i;
  uint32_T borrow = 0U;
  uint32_T u1i;
  uint32_T yi;
  for (i = 0; i < n; i++) {
    u1i = u1[i];
    yi = (u1i - u2[i]) - borrow;
    y[i] = yi;
    borrow = borrow != 0U ? (uint32_T)(yi >= u1i) : (uint32_T)(yi > u1i);
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 30;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_step(void)
{
  if (rtmIsMajorTimeStep(PID_VELOCIDAD_MOTORDC_ANTI_W_M)) {
    /* set solver stop time */
    if (!(PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo,
                            ((PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.clockTickH0
        + 1) * PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo,
                            ((PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.clockTick0
        + 1) * PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.stepSize0 +
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.clockTickH0 *
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PID_VELOCIDAD_MOTORDC_ANTI_W_M)) {
    PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0] = rtsiGetT
      (&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo);
  }

  {
    codertarget_arduinobase_int_o_T *obj;
    int64m_T tmp_1;
    real_T rtb_Add;
    real_T rtb_Sum2_o;
    real_T tmp;
    real_T *lastU;
    int32_T ci;
    uint32_T ri;
    uint32_T tmp_0;
    uint8_T tmp_2;
    if (rtmIsMajorTimeStep(PID_VELOCIDAD_MOTORDC_ANTI_W_M)) {
      /* Gain: '<S4>/Slider Gain' incorporates:
       *  Constant: '<Root>/Constant'
       */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.SliderGain =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.SliderGain_gain *
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Constant_Value;
    }

    /* MATLABSystem: '<Root>/Encoder' */
    if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.SampleTime !=
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Encoder_SampleTime) {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.SampleTime =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Encoder_SampleTime;
    }

    if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.TunablePropsChanged) {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<Root>/Encoder' */
    MW_EncoderRead(PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.Index,
                   &PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Encoder);

    /* Gain: '<Root>/Gain' */
    ri = (uint32_T)PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Gain_Gain_n;
    tmp_0 = (uint32_T)PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Encoder;
    sMultiWordMul(&ri, 1, &tmp_0, 1,
                  &PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Gain.chunks[0U], 2);
    if (rtmIsMajorTimeStep(PID_VELOCIDAD_MOTORDC_ANTI_W_M)) {
      /* Delay: '<S2>/Delay' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Delay =
        PID_VELOCIDAD_MOTORDC_ANTI_W_DW.Delay_DSTATE[0];

      /* Product: '<S2>/tiempo (ms)' incorporates:
       *  Constant: '<S2>/nº medidas'
       *  Constant: '<S2>/tiempo de muestreo (ms)'
       */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.tiempoms =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.nmedidas_Value *
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.tiempodemuestreoms_Value;
    }

    /* Sum: '<S2>/Add' incorporates:
     *  Delay: '<S2>/Delay'
     *  Gain: '<Root>/Gain'
     */
    MultiWordSub(&PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Gain.chunks[0U],
                 &PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Delay.chunks[0U],
                 &tmp_1.chunks[0U], 2);

    /* Product: '<S2>/Divide' */
    rtb_Add = sMultiWord2Double(&tmp_1.chunks[0U], 2, 0) *
      4.6566128730773926E-10 / PID_VELOCIDAD_MOTORDC_ANTI_WI_B.tiempoms;

    /* Gain: '<S2>/Gain' incorporates:
     *  Gain: '<S2>/ms//s'
     *  Gain: '<S2>/rev//pulso'
     */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Gain_k =
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.mss_Gain * rtb_Add *
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.revpulso_Gain *
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Gain_Gain;

    /* TransferFcn: '<S3>/Modelo (System Identification)' */
    rtb_Add = PID_VELOCIDAD_MOTORDC_ANTI_WI_P.ModeloSystemIdentification_C *
      PID_VELOCIDAD_MOTORDC_ANTI_WI_X.ModeloSystemIdentification_CSTA;

    /* TransferFcn: '<S1>/Modelo (System Identification)' */
    rtb_Sum2_o = PID_VELOCIDAD_MOTORDC_ANTI_WI_P.ModeloSystemIdentification_C_n *
      PID_VELOCIDAD_MOTORDC_ANTI_WI_X.ModeloSystemIdentification_CS_f;

    /* ManualSwitch: '<Root>/Manual Switch3' */
    if (PID_VELOCIDAD_MOTORDC_ANTI_WI_P.ManualSwitch3_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch3' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.ManualSwitch3 = rtb_Add;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch3' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.ManualSwitch3 = rtb_Sum2_o;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch3' */
    if (rtmIsMajorTimeStep(PID_VELOCIDAD_MOTORDC_ANTI_W_M)) {
      /* SignalConversion generated from: '<Root>/Mux' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.TmpSignalConversionAtTAQSigLogg[0] =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_B.ManualSwitch3;
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.TmpSignalConversionAtTAQSigLogg[1] =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_B.SliderGain;
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.TmpSignalConversionAtTAQSigLogg[2] =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Gain_k;
    }

    /* Sum: '<S1>/Sum' */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum =
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.SliderGain - rtb_Sum2_o;

    /* Derivative: '<S6>/Derivative' incorporates:
     *  Derivative: '<S17>/Derivative'
     *  Derivative: '<S18>/Derivative'
     *  Derivative: '<S19>/Derivative'
     */
    tmp = PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
    if ((PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA >= tmp) &&
        (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB >= tmp)) {
      rtb_Sum2_o = 0.0;
    } else {
      rtb_Sum2_o = PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA;
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeA;
      if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA <
          PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB) {
        if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB < tmp) {
          rtb_Sum2_o = PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB;
          lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeB;
        }
      } else if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA >= tmp) {
        rtb_Sum2_o = PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB;
        lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeB;
      }

      rtb_Sum2_o = (PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum - *lastU) / (tmp -
        rtb_Sum2_o);
    }

    /* End of Derivative: '<S6>/Derivative' */

    /* Sum: '<S6>/Add' incorporates:
     *  Gain: '<S6>/Gain1'
     *  Gain: '<S6>/Gain3'
     *  Integrator: '<S6>/Integrator'
     */
    rtb_Sum2_o = (PID_VELOCIDAD_MOTORDC_ANTI_WI_P.kp *
                  PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum +
                  PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Gain1_Gain * rtb_Sum2_o) +
      PID_VELOCIDAD_MOTORDC_ANTI_WI_X.Integrator_CSTATE;

    /* Saturate: '<S1>/Saturation' */
    if (rtb_Sum2_o > PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Saturation_UpperSat) {
      /* Saturate: '<S1>/Saturation' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Saturation_UpperSat;
    } else if (rtb_Sum2_o < PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Saturation_LowerSat)
    {
      /* Saturate: '<S1>/Saturation' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<S1>/Saturation' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation = rtb_Sum2_o;
    }

    /* End of Saturate: '<S1>/Saturation' */

    /* Sum: '<S6>/Sum3' incorporates:
     *  Gain: '<S6>/Gain'
     *  Gain: '<S6>/Gain2'
     *  Sum: '<S6>/Sum2'
     */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum3 =
      (PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation - rtb_Sum2_o) *
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Gain_Gain_a +
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.ki * PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum;

    /* Sum: '<S3>/Sum' */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum_p =
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.SliderGain - rtb_Add;

    /* Derivative: '<S19>/Derivative' */
    if ((PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_n >= tmp) &&
        (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_g >= tmp)) {
      rtb_Sum2_o = 0.0;
    } else {
      rtb_Sum2_o = PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_n;
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeA_l;
      if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_n <
          PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_g) {
        if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_g < tmp) {
          rtb_Sum2_o = PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_g;
          lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeB_p;
        }
      } else if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_n >= tmp) {
        rtb_Sum2_o = PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_g;
        lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeB_p;
      }

      rtb_Sum2_o = (PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum_p - *lastU) / (tmp -
        rtb_Sum2_o);
    }

    /* Sum: '<S19>/Add' incorporates:
     *  Gain: '<S19>/Gain1'
     *  Gain: '<S19>/Gain3'
     *  Integrator: '<S19>/Integrator'
     */
    rtb_Sum2_o = (PID_VELOCIDAD_MOTORDC_ANTI_WI_P.kp *
                  PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum_p +
                  PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Gain1_Gain_k * rtb_Sum2_o) +
      PID_VELOCIDAD_MOTORDC_ANTI_WI_X.Integrator_CSTATE_i;

    /* Saturate: '<S3>/Saturation' */
    if (rtb_Sum2_o > PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Saturation_UpperSat_o) {
      /* Saturate: '<S3>/Saturation' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation_n =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Saturation_UpperSat_o;
    } else if (rtb_Sum2_o <
               PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Saturation_LowerSat_p) {
      /* Saturate: '<S3>/Saturation' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation_n =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Saturation_LowerSat_p;
    } else {
      /* Saturate: '<S3>/Saturation' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation_n = rtb_Sum2_o;
    }

    /* End of Saturate: '<S3>/Saturation' */

    /* Sum: '<S19>/Sum3' incorporates:
     *  Gain: '<S19>/Gain'
     *  Gain: '<S19>/Gain2'
     *  Sum: '<S19>/Sum2'
     */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum3_l =
      (PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation_n - rtb_Sum2_o) *
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Gain_Gain_o +
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.ki * PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum_p;
    if (rtmIsMajorTimeStep(PID_VELOCIDAD_MOTORDC_ANTI_W_M)) {
    }

    /* Sum: '<S3>/Sum1' incorporates:
     *  Sum: '<S1>/Sum1'
     */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum1 =
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.SliderGain -
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Gain_k;

    /* Derivative: '<S17>/Derivative' */
    if ((PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_j >= tmp) &&
        (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_f >= tmp)) {
      rtb_Sum2_o = 0.0;
    } else {
      rtb_Sum2_o = PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_j;
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeA_e;
      if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_j <
          PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_f) {
        if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_f < tmp) {
          rtb_Sum2_o = PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_f;
          lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeB_i;
        }
      } else if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_j >= tmp) {
        rtb_Sum2_o = PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_f;
        lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeB_i;
      }

      rtb_Sum2_o = (PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum1 - *lastU) / (tmp -
        rtb_Sum2_o);
    }

    /* Sum: '<S17>/Add' incorporates:
     *  Gain: '<S17>/Gain1'
     *  Gain: '<S17>/Gain3'
     *  Integrator: '<S17>/Integrator'
     */
    rtb_Sum2_o = (PID_VELOCIDAD_MOTORDC_ANTI_WI_P.kp *
                  PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum1 +
                  PID_VELOCIDAD_MOTORDC_ANTI_WI_P.kd * rtb_Sum2_o) +
      PID_VELOCIDAD_MOTORDC_ANTI_WI_X.Integrator_CSTATE_o;

    /* Sum: '<S1>/Sum1' */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum1_n =
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum1;

    /* Sum: '<S5>/Add' incorporates:
     *  Gain: '<S5>/Gain1'
     *  Gain: '<S5>/Gain3'
     *  TransferFcn: '<S7>/Transfer Fcn1'
     *  TransferFcn: '<S8>/Transfer Fcn1'
     */
    rtb_Add = (PID_VELOCIDAD_MOTORDC_ANTI_WI_P.TransferFcn1_C *
               PID_VELOCIDAD_MOTORDC_ANTI_WI_X.TransferFcn1_CSTATE *
               PID_VELOCIDAD_MOTORDC_ANTI_WI_P.kd +
               PID_VELOCIDAD_MOTORDC_ANTI_WI_P.kp *
               PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum1_n) +
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.TransferFcn1_C_h *
      PID_VELOCIDAD_MOTORDC_ANTI_WI_X.TransferFcn1_CSTATE_a;

    /* ManualSwitch: '<Root>/Manual Switch2' */
    if (PID_VELOCIDAD_MOTORDC_ANTI_WI_P.ManualSwitch2_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch2' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.ManualSwitch2 = rtb_Sum2_o;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch2' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.ManualSwitch2 = rtb_Add;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch2' */

    /* Saturate: '<Root>/Saturation' */
    if (PID_VELOCIDAD_MOTORDC_ANTI_WI_B.ManualSwitch2 >
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Saturation_UpperSat_oo) {
      /* Saturate: '<Root>/Saturation' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation_m =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Saturation_UpperSat_oo;
    } else if (PID_VELOCIDAD_MOTORDC_ANTI_WI_B.ManualSwitch2 <
               PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Saturation_LowerSat_n) {
      /* Saturate: '<Root>/Saturation' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation_m =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Saturation_LowerSat_n;
    } else {
      /* Saturate: '<Root>/Saturation' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation_m =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_B.ManualSwitch2;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* Sum: '<S17>/Sum3' incorporates:
     *  Gain: '<S17>/Gain'
     *  Gain: '<S17>/Gain2'
     *  Sum: '<S17>/Sum2'
     */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum3_lv =
      (PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation_m - rtb_Sum2_o) *
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Gain_Gain_g +
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.ki * PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum1;

    /* MATLABSystem: '<Root>/PWM' */
    obj = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_e;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8U);
    if (PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation_m <= 255.0) {
      rtb_Sum2_o = PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation_m;
    } else {
      rtb_Sum2_o = 255.0;
    }

    if (!(rtb_Sum2_o >= 0.0)) {
      rtb_Sum2_o = 0.0;
    }

    MW_PWM_SetDutyCycle
      (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
       rtb_Sum2_o);

    /* End of MATLABSystem: '<Root>/PWM' */
    if (rtmIsMajorTimeStep(PID_VELOCIDAD_MOTORDC_ANTI_W_M)) {
    }

    /* Sum: '<S5>/Sum3' incorporates:
     *  Gain: '<S5>/Gain'
     *  Gain: '<S5>/Gain2'
     *  Sum: '<S5>/Sum2'
     */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum3_l2 =
      (PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation_m - rtb_Add) *
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Gain_Gain_k +
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.ki *
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum1_n;

    /* StateSpace: '<S13>/Internal' */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Internal = 0.0;

    /* StateSpace: '<S13>/Internal' */
    for (ci = 0; ci < 11; ci++) {
      for (ri = PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_C_jc[(uint32_T)ci]; ri <
           PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_C_jc[(uint32_T)ci + 1U]; ri
           ++) {
        /* StateSpace: '<S13>/Internal' */
        PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Internal +=
          PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_C_pr[ri] *
          PID_VELOCIDAD_MOTORDC_ANTI_WI_X.Internal_CSTATE[(uint32_T)ci];
      }
    }

    for (ri = PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_D_jc[0U]; ri <
         PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_D_jc[1U]; ri++) {
      /* StateSpace: '<S13>/Internal' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Internal +=
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_D_pr *
        PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum3_l2;
    }

    if (rtmIsMajorTimeStep(PID_VELOCIDAD_MOTORDC_ANTI_W_M)) {
    }

    /* StateSpace: '<S9>/Internal' */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Internal_g = 0.0;

    /* StateSpace: '<S9>/Internal' */
    for (ci = 0; ci < 11; ci++) {
      for (ri = PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_C_jc_o[(uint32_T)ci];
           ri < PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_C_jc_o[(uint32_T)ci +
           1U]; ri++) {
        /* StateSpace: '<S9>/Internal' */
        PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Internal_g +=
          PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_C_pr_h[ri] *
          PID_VELOCIDAD_MOTORDC_ANTI_WI_X.Internal_CSTATE_o[(uint32_T)ci];
      }
    }

    for (ri = PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_D_jc_a[0U]; ri <
         PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_D_jc_a[1U]; ri++) {
      /* StateSpace: '<S9>/Internal' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Internal_g +=
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_D_pr_l *
        PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum1_n;
    }

    /* Derivative: '<S18>/Derivative' */
    if ((PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_a >= tmp) &&
        (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_b >= tmp)) {
      rtb_Sum2_o = 0.0;
    } else {
      rtb_Sum2_o = PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_a;
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeA_a;
      if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_a <
          PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_b) {
        if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_b < tmp) {
          rtb_Sum2_o = PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_b;
          lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeB_j;
        }
      } else if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_a >= tmp) {
        rtb_Sum2_o = PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_b;
        lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeB_j;
      }

      rtb_Sum2_o = (PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum1 - *lastU) / (tmp -
        rtb_Sum2_o);
    }

    /* Sum: '<S18>/Sum3' incorporates:
     *  Gain: '<S18>/Gain'
     *  Gain: '<S18>/Gain1'
     *  Gain: '<S18>/Gain2'
     *  Gain: '<S18>/Gain3'
     *  Integrator: '<S18>/Integrator'
     *  Sum: '<S18>/Add'
     *  Sum: '<S18>/Sum2'
     */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum3_d = (0.0 -
      ((PID_VELOCIDAD_MOTORDC_ANTI_WI_P.kp *
        PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum1 +
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Gain1_Gain_a * rtb_Sum2_o) +
       PID_VELOCIDAD_MOTORDC_ANTI_WI_X.Integrator_CSTATE_h)) *
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Gain_Gain_op +
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.ki * PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum1;
    if (rtmIsMajorTimeStep(PID_VELOCIDAD_MOTORDC_ANTI_W_M)) {
      /* ManualSwitch: '<Root>/Manual Switch' incorporates:
       *  Constant: '<Root>/Constant2'
       *  Constant: '<Root>/Constant3'
       */
      if (PID_VELOCIDAD_MOTORDC_ANTI_WI_P.ManualSwitch_CurrentSetting == 1) {
        tmp = PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Constant2_Value;
      } else {
        tmp = PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Constant3_Value;
      }

      /* MATLABSystem: '<Root>/Digital Output1' incorporates:
       *  ManualSwitch: '<Root>/Manual Switch'
       */
      tmp = rt_roundd_snf(tmp);
      if (tmp < 256.0) {
        if (tmp >= 0.0) {
          tmp_2 = (uint8_T)tmp;
        } else {
          tmp_2 = 0U;
        }
      } else {
        tmp_2 = MAX_uint8_T;
      }

      writeDigitalPin(5, tmp_2);

      /* End of MATLABSystem: '<Root>/Digital Output1' */

      /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
       *  Constant: '<Root>/Constant8'
       *  Constant: '<Root>/Constant9'
       */
      if (PID_VELOCIDAD_MOTORDC_ANTI_WI_P.ManualSwitch1_CurrentSetting == 1) {
        tmp = PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Constant8_Value;
      } else {
        tmp = PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Constant9_Value;
      }

      /* MATLABSystem: '<Root>/Digital Output3' incorporates:
       *  ManualSwitch: '<Root>/Manual Switch1'
       */
      tmp = rt_roundd_snf(tmp);
      if (tmp < 256.0) {
        if (tmp >= 0.0) {
          tmp_2 = (uint8_T)tmp;
        } else {
          tmp_2 = 0U;
        }
      } else {
        tmp_2 = MAX_uint8_T;
      }

      writeDigitalPin(4, tmp_2);

      /* End of MATLABSystem: '<Root>/Digital Output3' */
    }
  }

  if (rtmIsMajorTimeStep(PID_VELOCIDAD_MOTORDC_ANTI_W_M)) {
    real_T *lastU;
    int_T idxDelay;
    if (rtmIsMajorTimeStep(PID_VELOCIDAD_MOTORDC_ANTI_W_M)) {
      /* Update for Delay: '<S2>/Delay' incorporates:
       *  Gain: '<Root>/Gain'
       */
      for (idxDelay = 0; idxDelay < 99; idxDelay++) {
        PID_VELOCIDAD_MOTORDC_ANTI_W_DW.Delay_DSTATE[idxDelay] =
          PID_VELOCIDAD_MOTORDC_ANTI_W_DW.Delay_DSTATE[idxDelay + 1];
      }

      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.Delay_DSTATE[99] =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Gain;

      /* End of Update for Delay: '<S2>/Delay' */
    }

    /* Update for Derivative: '<S6>/Derivative' */
    if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA == (rtInf)) {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA =
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeA;
    } else if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB == (rtInf)) {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB =
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeB;
    } else if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA <
               PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB) {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA =
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeA;
    } else {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB =
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeB;
    }

    *lastU = PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum;

    /* End of Update for Derivative: '<S6>/Derivative' */

    /* Update for Derivative: '<S19>/Derivative' */
    if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_n == (rtInf)) {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_n =
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeA_l;
    } else if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_g == (rtInf)) {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_g =
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeB_p;
    } else if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_n <
               PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_g) {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_n =
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeA_l;
    } else {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_g =
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeB_p;
    }

    *lastU = PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum_p;

    /* End of Update for Derivative: '<S19>/Derivative' */

    /* Update for Derivative: '<S17>/Derivative' */
    if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_j == (rtInf)) {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_j =
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeA_e;
    } else if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_f == (rtInf)) {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_f =
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeB_i;
    } else if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_j <
               PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_f) {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_j =
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeA_e;
    } else {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_f =
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeB_i;
    }

    *lastU = PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum1;

    /* End of Update for Derivative: '<S17>/Derivative' */

    /* Update for Derivative: '<S18>/Derivative' */
    if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_a == (rtInf)) {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_a =
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeA_a;
    } else if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_b == (rtInf)) {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_b =
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeB_j;
    } else if (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_a <
               PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_b) {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_a =
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeA_a;
    } else {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_b =
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];
      lastU = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.LastUAtTimeB_j;
    }

    *lastU = PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum1;

    /* End of Update for Derivative: '<S18>/Derivative' */
    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0];

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(PID_VELOCIDAD_MOTORDC_ANTI_W_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        (((PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.clockTick1+
           PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.clockTickH1* 4294967296.0)) *
         0.01);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(PID_VELOCIDAD_MOTORDC_ANTI_W_M)) {
    rt_ertODEUpdateContinuousStates(&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.clockTick0)) {
      ++PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.clockTickH0;
    }

    PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.t[0] = rtsiGetSolverStopTime
      (&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.01s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.01, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.clockTick1++;
      if (!PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.clockTick1) {
        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_derivatives(void)
{
  XDot_PID_VELOCIDAD_MOTORDC_AN_T *_rtXdot;
  int_T is;
  uint32_T ri;
  _rtXdot = ((XDot_PID_VELOCIDAD_MOTORDC_AN_T *)
             PID_VELOCIDAD_MOTORDC_ANTI_W_M->derivs);

  /* Derivatives for TransferFcn: '<S3>/Modelo (System Identification)' */
  _rtXdot->ModeloSystemIdentification_CSTA =
    PID_VELOCIDAD_MOTORDC_ANTI_WI_P.ModeloSystemIdentification_A *
    PID_VELOCIDAD_MOTORDC_ANTI_WI_X.ModeloSystemIdentification_CSTA;
  _rtXdot->ModeloSystemIdentification_CSTA +=
    PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation_n;

  /* Derivatives for TransferFcn: '<S1>/Modelo (System Identification)' */
  _rtXdot->ModeloSystemIdentification_CS_f =
    PID_VELOCIDAD_MOTORDC_ANTI_WI_P.ModeloSystemIdentification_A_f *
    PID_VELOCIDAD_MOTORDC_ANTI_WI_X.ModeloSystemIdentification_CS_f;
  _rtXdot->ModeloSystemIdentification_CS_f +=
    PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Saturation;

  /* Derivatives for Integrator: '<S6>/Integrator' */
  _rtXdot->Integrator_CSTATE = PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum3;

  /* Derivatives for Integrator: '<S19>/Integrator' */
  _rtXdot->Integrator_CSTATE_i = PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum3_l;

  /* Derivatives for Integrator: '<S17>/Integrator' */
  _rtXdot->Integrator_CSTATE_o = PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum3_lv;

  /* Derivatives for TransferFcn: '<S7>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = PID_VELOCIDAD_MOTORDC_ANTI_WI_P.TransferFcn1_A *
    PID_VELOCIDAD_MOTORDC_ANTI_WI_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Internal_g;

  /* Derivatives for TransferFcn: '<S8>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_a =
    PID_VELOCIDAD_MOTORDC_ANTI_WI_P.TransferFcn1_A_j *
    PID_VELOCIDAD_MOTORDC_ANTI_WI_X.TransferFcn1_CSTATE_a;
  _rtXdot->TransferFcn1_CSTATE_a += PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Internal;

  /* Derivatives for StateSpace: '<S13>/Internal' */
  memset(&_rtXdot->Internal_CSTATE[0], 0, 11U * sizeof(real_T));
  for (is = 0; is < 11; is++) {
    for (ri = PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_A_jc[(uint32_T)is]; ri <
         PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_A_jc[(uint32_T)is + 1U]; ri++)
    {
      _rtXdot->Internal_CSTATE[PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_A_ir[ri]]
        += PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_A_pr[ri] *
        PID_VELOCIDAD_MOTORDC_ANTI_WI_X.Internal_CSTATE[(uint32_T)is];
    }
  }

  for (ri = PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_B_jc[0U]; ri <
       PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_B_jc[1U]; ri++) {
    _rtXdot->Internal_CSTATE[PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_B_ir[ri]] +=
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_B_pr[ri] *
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum3_l2;
  }

  /* End of Derivatives for StateSpace: '<S13>/Internal' */

  /* Derivatives for StateSpace: '<S9>/Internal' */
  memset(&_rtXdot->Internal_CSTATE_o[0], 0, 11U * sizeof(real_T));
  for (is = 0; is < 11; is++) {
    for (ri = PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_A_jc_k[(uint32_T)is]; ri <
         PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_A_jc_k[(uint32_T)is + 1U]; ri
         ++) {
      _rtXdot->
        Internal_CSTATE_o[PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_A_ir_g[ri]] +=
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_A_pr_g[ri] *
        PID_VELOCIDAD_MOTORDC_ANTI_WI_X.Internal_CSTATE_o[(uint32_T)is];
    }
  }

  for (ri = PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_B_jc_g[0U]; ri <
       PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_B_jc_g[1U]; ri++) {
    _rtXdot->
      Internal_CSTATE_o[PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_B_ir_g[ri]] +=
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_B_pr_f[ri] *
      PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum1_n;
  }

  /* End of Derivatives for StateSpace: '<S9>/Internal' */

  /* Derivatives for Integrator: '<S18>/Integrator' */
  _rtXdot->Integrator_CSTATE_h = PID_VELOCIDAD_MOTORDC_ANTI_WI_B.Sum3_d;
}

/* Model initialize function */
void PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)PID_VELOCIDAD_MOTORDC_ANTI_W_M, 0,
                sizeof(RT_MODEL_PID_VELOCIDAD_MOTORD_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo,
                          &PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.simTimeStep);
    rtsiSetTPtr(&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo, &rtmGetTPtr
                (PID_VELOCIDAD_MOTORDC_ANTI_W_M));
    rtsiSetStepSizePtr(&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo,
                       &PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.stepSize0);
    rtsiSetdXPtr(&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo,
                 &PID_VELOCIDAD_MOTORDC_ANTI_W_M->derivs);
    rtsiSetContStatesPtr(&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo, (real_T **)
                         &PID_VELOCIDAD_MOTORDC_ANTI_W_M->contStates);
    rtsiSetNumContStatesPtr(&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo,
      &PID_VELOCIDAD_MOTORDC_ANTI_W_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo,
      &PID_VELOCIDAD_MOTORDC_ANTI_W_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr
      (&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo,
       &PID_VELOCIDAD_MOTORDC_ANTI_W_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr
      (&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo,
       &PID_VELOCIDAD_MOTORDC_ANTI_W_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo,
                          (&rtmGetErrorStatus(PID_VELOCIDAD_MOTORDC_ANTI_W_M)));
    rtsiSetRTModelPtr(&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo,
                      PID_VELOCIDAD_MOTORDC_ANTI_W_M);
  }

  rtsiSetSimTimeStep(&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange
    (&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo, false);
  PID_VELOCIDAD_MOTORDC_ANTI_W_M->intgData.f[0] =
    PID_VELOCIDAD_MOTORDC_ANTI_W_M->odeF[0];
  PID_VELOCIDAD_MOTORDC_ANTI_W_M->contStates = ((X_PID_VELOCIDAD_MOTORDC_ANTI__T
    *) &PID_VELOCIDAD_MOTORDC_ANTI_WI_X);
  rtsiSetSolverData(&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo, (void *)
                    &PID_VELOCIDAD_MOTORDC_ANTI_W_M->intgData);
  rtsiSetSolverName(&PID_VELOCIDAD_MOTORDC_ANTI_W_M->solverInfo,"ode1");
  rtmSetTPtr(PID_VELOCIDAD_MOTORDC_ANTI_W_M,
             &PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.tArray[0]);
  rtmSetTFinal(PID_VELOCIDAD_MOTORDC_ANTI_W_M, -1);
  PID_VELOCIDAD_MOTORDC_ANTI_W_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  PID_VELOCIDAD_MOTORDC_ANTI_W_M->Sizes.checksums[0] = (3125141258U);
  PID_VELOCIDAD_MOTORDC_ANTI_W_M->Sizes.checksums[1] = (710421819U);
  PID_VELOCIDAD_MOTORDC_ANTI_W_M->Sizes.checksums[2] = (3376519148U);
  PID_VELOCIDAD_MOTORDC_ANTI_W_M->Sizes.checksums[3] = (3219518378U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[9];
    PID_VELOCIDAD_MOTORDC_ANTI_W_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = &rtAlwaysEnabled;
    systemRan[2] = &rtAlwaysEnabled;
    systemRan[3] = &rtAlwaysEnabled;
    systemRan[4] = &rtAlwaysEnabled;
    systemRan[5] = &rtAlwaysEnabled;
    systemRan[6] = &rtAlwaysEnabled;
    systemRan[7] = &rtAlwaysEnabled;
    systemRan[8] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(PID_VELOCIDAD_MOTORDC_ANTI_W_M->extModeInfo,
      &PID_VELOCIDAD_MOTORDC_ANTI_W_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(PID_VELOCIDAD_MOTORDC_ANTI_W_M->extModeInfo,
                        PID_VELOCIDAD_MOTORDC_ANTI_W_M->Sizes.checksums);
    rteiSetTPtr(PID_VELOCIDAD_MOTORDC_ANTI_W_M->extModeInfo, rtmGetTPtr
                (PID_VELOCIDAD_MOTORDC_ANTI_W_M));
  }

  /* block I/O */
  (void) memset(((void *) &PID_VELOCIDAD_MOTORDC_ANTI_WI_B), 0,
                sizeof(B_PID_VELOCIDAD_MOTORDC_ANTI__T));

  /* states (continuous) */
  {
    (void) memset((void *)&PID_VELOCIDAD_MOTORDC_ANTI_WI_X, 0,
                  sizeof(X_PID_VELOCIDAD_MOTORDC_ANTI__T));
  }

  /* states (dwork) */
  (void) memset((void *)&PID_VELOCIDAD_MOTORDC_ANTI_W_DW, 0,
                sizeof(DW_PID_VELOCIDAD_MOTORDC_ANTI_T));

  {
    codertarget_arduinobase_int_o_T *obj;

    /* Start for MATLABSystem: '<Root>/Encoder' */
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.Index = 0U;
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.matlabCodegenIsDeleted = false;
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.objisempty_f = true;
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.SampleTime =
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Encoder_SampleTime;
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.isInitialized = 1;
    MW_EncoderSetup(2U, 3U, &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.Index);
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.isSetupComplete = true;
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.TunablePropsChanged = false;

    /* Start for MATLABSystem: '<Root>/PWM' */
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_e.matlabCodegenIsDeleted = false;
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.objisempty = true;
    obj = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_e;
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_e.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(8U, 0.0, 0.0);
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_e.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_n.matlabCodegenIsDeleted = false;
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.objisempty_p = true;
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_n.isInitialized = 1;
    digitalIOSetup(5, 1);
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output3' */
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_h.matlabCodegenIsDeleted = false;
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.objisempty_i = true;
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_h.isInitialized = 1;
    digitalIOSetup(4, 1);
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_h.isSetupComplete = true;
  }

  {
    int32_T i;

    /* InitializeConditions for Delay: '<S2>/Delay' */
    for (i = 0; i < 100; i++) {
      PID_VELOCIDAD_MOTORDC_ANTI_W_DW.Delay_DSTATE[i] =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S2>/Delay' */

    /* InitializeConditions for TransferFcn: '<S3>/Modelo (System Identification)' */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_X.ModeloSystemIdentification_CSTA = 0.0;

    /* InitializeConditions for TransferFcn: '<S1>/Modelo (System Identification)' */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_X.ModeloSystemIdentification_CS_f = 0.0;

    /* InitializeConditions for Derivative: '<S6>/Derivative' */
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA = (rtInf);
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Integrator: '<S6>/Integrator' */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_X.Integrator_CSTATE =
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Integrator_IC;

    /* InitializeConditions for Derivative: '<S19>/Derivative' */
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_n = (rtInf);
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_g = (rtInf);

    /* InitializeConditions for Integrator: '<S19>/Integrator' */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_X.Integrator_CSTATE_i =
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Integrator_IC_h;

    /* InitializeConditions for Derivative: '<S17>/Derivative' */
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_j = (rtInf);
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_f = (rtInf);

    /* InitializeConditions for Integrator: '<S17>/Integrator' */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_X.Integrator_CSTATE_o =
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Integrator_IC_i;

    /* InitializeConditions for TransferFcn: '<S7>/Transfer Fcn1' */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_X.TransferFcn1_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S8>/Transfer Fcn1' */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_X.TransferFcn1_CSTATE_a = 0.0;
    for (i = 0; i < 11; i++) {
      /* InitializeConditions for StateSpace: '<S13>/Internal' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_X.Internal_CSTATE[i] =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_InitialCondition;

      /* InitializeConditions for StateSpace: '<S9>/Internal' */
      PID_VELOCIDAD_MOTORDC_ANTI_WI_X.Internal_CSTATE_o[i] =
        PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Internal_InitialCondition_p;
    }

    /* InitializeConditions for Derivative: '<S18>/Derivative' */
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampA_a = (rtInf);
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.TimeStampB_b = (rtInf);

    /* InitializeConditions for Integrator: '<S18>/Integrator' */
    PID_VELOCIDAD_MOTORDC_ANTI_WI_X.Integrator_CSTATE_h =
      PID_VELOCIDAD_MOTORDC_ANTI_WI_P.Integrator_IC_n;

    /* InitializeConditions for MATLABSystem: '<Root>/Encoder' */
    MW_EncoderReset(PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.Index);
  }
}

/* Model terminate function */
void PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_terminate(void)
{
  codertarget_arduinobase_int_o_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.matlabCodegenIsDeleted) {
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.matlabCodegenIsDeleted = true;
    if ((PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.isInitialized == 1) &&
        PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj = &PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_e;
  if (!PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_e.matlabCodegenIsDeleted) {
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_e.isInitialized == 1) &&
        PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_e.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8U);
      MW_PWM_SetDutyCycle
        (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8U);
      MW_PWM_Close
        (PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_n.matlabCodegenIsDeleted) {
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  if (!PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_h.matlabCodegenIsDeleted) {
    PID_VELOCIDAD_MOTORDC_ANTI_W_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output3' */
}
