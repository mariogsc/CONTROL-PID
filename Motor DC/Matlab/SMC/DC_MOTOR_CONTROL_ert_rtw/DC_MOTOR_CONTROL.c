/*
 * DC_MOTOR_CONTROL.c
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

#include "DC_MOTOR_CONTROL.h"
#include "rtwtypes.h"
#include "DC_MOTOR_CONTROL_types.h"
#include <math.h>
#include "rt_nonfinite.h"
#include "DC_MOTOR_CONTROL_private.h"
#include <string.h>

/* Block signals (default storage) */
B_DC_MOTOR_CONTROL_T DC_MOTOR_CONTROL_B;

/* Continuous states */
X_DC_MOTOR_CONTROL_T DC_MOTOR_CONTROL_X;

/* Block states (default storage) */
DW_DC_MOTOR_CONTROL_T DC_MOTOR_CONTROL_DW;

/* Real-time model */
static RT_MODEL_DC_MOTOR_CONTROL_T DC_MOTOR_CONTROL_M_;
RT_MODEL_DC_MOTOR_CONTROL_T *const DC_MOTOR_CONTROL_M = &DC_MOTOR_CONTROL_M_;
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

/*
 * This function updates continuous states using the ODE3 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  /* Solver Matrices */
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
  ODE3_IntgData *id = (ODE3_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T hB[3];
  int_T i;
  int_T nXc = 118;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  DC_MOTOR_CONTROL_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  DC_MOTOR_CONTROL_step();
  DC_MOTOR_CONTROL_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  DC_MOTOR_CONTROL_step();
  DC_MOTOR_CONTROL_derivatives();

  /* tnew = t + hA(3);
     ynew = y + f*hB(:,3); */
  for (i = 0; i <= 2; i++) {
    hB[i] = h * rt_ODE3_B[2][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1] + f2[i]*hB[2]);
  }

  rtsiSetT(si, tnew);
  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

real_T rt_urand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  uint32_T hi;
  uint32_T lo;

  /* Uniform random number generator (random number between 0 and 1)

     #define IA      16807                      magic multiplier = 7^5
     #define IM      2147483647                 modulus = 2^31-1
     #define IQ      127773                     IM div IA
     #define IR      2836                       IM modulo IA
     #define S       4.656612875245797e-10      reciprocal of 2^31-1
     test = IA * (seed % IQ) - IR * (seed/IQ)
     seed = test < 0 ? (test + IM) : test
     return (seed*S)
   */
  lo = *u % 127773U * 16807U;
  hi = *u / 127773U * 2836U;
  if (lo < hi) {
    *u = 2147483647U - (hi - lo);
  } else {
    *u = lo - hi;
  }

  return (real_T)*u * 4.6566128752457969E-10;
}

real_T rt_nrand_Upu32_Yd_f_pw_snf(uint32_T *u)
{
  real_T si;
  real_T sr;
  real_T y;

  /* Normal (Gaussian) random number generator */
  do {
    sr = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = 2.0 * rt_urand_Upu32_Yd_f_pw_snf(u) - 1.0;
    si = sr * sr + si * si;
  } while (si > 1.0);

  y = sqrt(-2.0 * log(si) / si) * sr;
  return y;
}

real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T tmp;
  real_T tmp_0;
  real_T y;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else {
    tmp = fabs(u0);
    tmp_0 = fabs(u1);
    if (rtIsInf(u1)) {
      if (tmp == 1.0) {
        y = 1.0;
      } else if (tmp > 1.0) {
        if (u1 > 0.0) {
          y = (rtInf);
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = (rtInf);
      }
    } else if (tmp_0 == 0.0) {
      y = 1.0;
    } else if (tmp_0 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = (rtNaN);
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
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
void DC_MOTOR_CONTROL_step(void)
{
  if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
    /* set solver stop time */
    if (!(DC_MOTOR_CONTROL_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&DC_MOTOR_CONTROL_M->solverInfo,
                            ((DC_MOTOR_CONTROL_M->Timing.clockTickH0 + 1) *
        DC_MOTOR_CONTROL_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&DC_MOTOR_CONTROL_M->solverInfo,
                            ((DC_MOTOR_CONTROL_M->Timing.clockTick0 + 1) *
        DC_MOTOR_CONTROL_M->Timing.stepSize0 +
        DC_MOTOR_CONTROL_M->Timing.clockTickH0 *
        DC_MOTOR_CONTROL_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(DC_MOTOR_CONTROL_M)) {
    DC_MOTOR_CONTROL_M->Timing.t[0] = rtsiGetT(&DC_MOTOR_CONTROL_M->solverInfo);
  }

  {
    codertarget_arduinobase_int_p_T *obj;
    real_T Sum3_tmp;
    real_T rtb_Product1_j_tmp;
    real_T *lastU;
    int32_T ci;
    uint32_T ri;
    uint32_T tmp;
    uint8_T tmp_0;
    if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
      /* DataTypeConversion: '<Root>/Cast To Double1' incorporates:
       *  Constant: '<Root>/position_target'
       */
      DC_MOTOR_CONTROL_B.CastToDouble1 =
        DC_MOTOR_CONTROL_P.position_target_Value;

      /* DataTypeConversion: '<Root>/Cast To Double' incorporates:
       *  Constant: '<Root>/velocity_target'
       */
      DC_MOTOR_CONTROL_B.CastToDouble = DC_MOTOR_CONTROL_P.velocity_target_Value;

      /* Gain: '<S52>/Output' incorporates:
       *  RandomNumber: '<S52>/White Noise'
       */
      DC_MOTOR_CONTROL_B.Output = sqrt
        (DC_MOTOR_CONTROL_P.BandLimitedWhiteNoise_Cov) / 0.1 *
        DC_MOTOR_CONTROL_DW.NextOutput;
    }

    /* MATLABSystem: '<Root>/Encoder' */
    if (DC_MOTOR_CONTROL_DW.obj.SampleTime !=
        DC_MOTOR_CONTROL_P.Encoder_SampleTime) {
      DC_MOTOR_CONTROL_DW.obj.SampleTime = DC_MOTOR_CONTROL_P.Encoder_SampleTime;
    }

    if (DC_MOTOR_CONTROL_DW.obj.TunablePropsChanged) {
      DC_MOTOR_CONTROL_DW.obj.TunablePropsChanged = false;
    }

    /* MATLABSystem: '<Root>/Encoder' */
    MW_EncoderRead(DC_MOTOR_CONTROL_DW.obj.Index, &DC_MOTOR_CONTROL_B.Encoder);
    if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
      /* Delay: '<S2>/Delay' */
      DC_MOTOR_CONTROL_B.Delay = DC_MOTOR_CONTROL_DW.Delay_DSTATE[0];

      /* Product: '<S2>/tiempo (ms)' incorporates:
       *  Constant: '<S2>/nº medidas'
       *  Constant: '<S2>/tiempo de muestreo (ms)'
       */
      DC_MOTOR_CONTROL_B.tiempoms = DC_MOTOR_CONTROL_P.nmedidas_Value *
        DC_MOTOR_CONTROL_P.tiempodemuestreoms_Value;

      /* RelationalOperator: '<S5>/GreaterThan' incorporates:
       *  Constant: '<Root>/mode'
       *  Constant: '<S5>/Constant9'
       */
      DC_MOTOR_CONTROL_B.GreaterThan = (DC_MOTOR_CONTROL_P.mode_Value ==
        DC_MOTOR_CONTROL_P.Constant9_Value);
    }

    /* Gain: '<S2>/Gain' incorporates:
     *  Gain: '<S2>/ms//s'
     *  Gain: '<S2>/rev//pulso'
     *  Product: '<S2>/Divide'
     *  Sum: '<S2>/Add'
     */
    DC_MOTOR_CONTROL_B.Gain = (real_T)(DC_MOTOR_CONTROL_B.Encoder -
      DC_MOTOR_CONTROL_B.Delay) / DC_MOTOR_CONTROL_B.tiempoms *
      DC_MOTOR_CONTROL_P.mss_Gain * DC_MOTOR_CONTROL_P.revpulso_Gain *
      DC_MOTOR_CONTROL_P.Gain_Gain;

    /* Gain: '<Root>/pulses2angle' */
    ri = (uint32_T)DC_MOTOR_CONTROL_P.pulses2angle_Gain;
    tmp = (uint32_T)DC_MOTOR_CONTROL_B.Encoder;
    sMultiWordMul(&ri, 1, &tmp, 1, &DC_MOTOR_CONTROL_B.pulses2angle.chunks[0U],
                  2);

    /* Switch: '<S5>/Switch2' incorporates:
     *  Gain: '<Root>/pulses2angle'
     */
    if (DC_MOTOR_CONTROL_B.GreaterThan) {
      DC_MOTOR_CONTROL_B.u0 = DC_MOTOR_CONTROL_B.Gain;
    } else {
      DC_MOTOR_CONTROL_B.u0 = sMultiWord2Double
        (&DC_MOTOR_CONTROL_B.pulses2angle.chunks[0U], 2, 0) *
        2.9103830456733704E-11;
    }

    /* Sum: '<S3>/Sum' incorporates:
     *  Switch: '<S5>/Switch2'
     */
    DC_MOTOR_CONTROL_B.Sum = DC_MOTOR_CONTROL_B.Output + DC_MOTOR_CONTROL_B.u0;

    /* Sum: '<S56>/Sum1' incorporates:
     *  Sum: '<S57>/Sum1'
     */
    DC_MOTOR_CONTROL_B.Sum1_n = DC_MOTOR_CONTROL_B.CastToDouble -
      DC_MOTOR_CONTROL_B.Sum;

    /* Product: '<S56>/Product' incorporates:
     *  Constant: '<Root>/Kp_v'
     *  Product: '<S57>/Product'
     *  Sum: '<S56>/Sum1'
     */
    rtb_Product1_j_tmp = DC_MOTOR_CONTROL_P.Kp_v_Value *
      DC_MOTOR_CONTROL_B.Sum1_n;

    /* Product: '<S56>/Product1' incorporates:
     *  Constant: '<Root>/Kd_v'
     *  TransferFcn: '<S58>/Transfer Fcn1'
     */
    DC_MOTOR_CONTROL_B.Product1_e = DC_MOTOR_CONTROL_P.TransferFcn1_C *
      DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE * DC_MOTOR_CONTROL_P.Kd_v_Value;

    /* TransferFcn: '<S59>/Transfer Fcn1' */
    DC_MOTOR_CONTROL_B.Product_a = DC_MOTOR_CONTROL_P.TransferFcn1_C_f *
      DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_o;

    /* Sum: '<S56>/Add' incorporates:
     *  Product: '<S56>/Product'
     */
    DC_MOTOR_CONTROL_B.Add_c = (rtb_Product1_j_tmp -
      DC_MOTOR_CONTROL_B.Product1_e) + DC_MOTOR_CONTROL_B.Product_a;
    if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
      /* RelationalOperator: '<S4>/GreaterThan' incorporates:
       *  Constant: '<Root>/mode'
       *  Constant: '<S4>/Constant9'
       */
      DC_MOTOR_CONTROL_B.GreaterThan_e = (DC_MOTOR_CONTROL_P.mode_Value ==
        DC_MOTOR_CONTROL_P.Constant9_Value_j);
    }

    /* Derivative: '<S11>/Derivative' incorporates:
     *  Derivative: '<S10>/Derivative'
     *  Derivative: '<S11>/Derivative1'
     *  Derivative: '<S57>/Derivative'
     *  Derivative: '<S57>/Derivative1'
     */
    DC_MOTOR_CONTROL_B.u0 = DC_MOTOR_CONTROL_M->Timing.t[0];
    if ((DC_MOTOR_CONTROL_DW.TimeStampA >= DC_MOTOR_CONTROL_B.u0) &&
        (DC_MOTOR_CONTROL_DW.TimeStampB >= DC_MOTOR_CONTROL_B.u0)) {
      DC_MOTOR_CONTROL_B.Derivative_m = 0.0;
    } else {
      DC_MOTOR_CONTROL_B.Product1_k = DC_MOTOR_CONTROL_DW.TimeStampA;
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeA;
      if (DC_MOTOR_CONTROL_DW.TimeStampA < DC_MOTOR_CONTROL_DW.TimeStampB) {
        if (DC_MOTOR_CONTROL_DW.TimeStampB < DC_MOTOR_CONTROL_B.u0) {
          DC_MOTOR_CONTROL_B.Product1_k = DC_MOTOR_CONTROL_DW.TimeStampB;
          lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB;
        }
      } else if (DC_MOTOR_CONTROL_DW.TimeStampA >= DC_MOTOR_CONTROL_B.u0) {
        DC_MOTOR_CONTROL_B.Product1_k = DC_MOTOR_CONTROL_DW.TimeStampB;
        lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB;
      }

      DC_MOTOR_CONTROL_B.Derivative_m = (DC_MOTOR_CONTROL_B.Sum - *lastU) /
        (DC_MOTOR_CONTROL_B.u0 - DC_MOTOR_CONTROL_B.Product1_k);
    }

    /* End of Derivative: '<S11>/Derivative' */

    /* Sum: '<S11>/Sum1' incorporates:
     *  Sum: '<S10>/Sum1'
     *  Sum: '<S8>/Sum1'
     */
    DC_MOTOR_CONTROL_B.Sum1 = DC_MOTOR_CONTROL_B.CastToDouble1 -
      DC_MOTOR_CONTROL_B.Sum;

    /* Derivative: '<S11>/Derivative1' */
    if ((DC_MOTOR_CONTROL_DW.TimeStampA_b >= DC_MOTOR_CONTROL_B.u0) &&
        (DC_MOTOR_CONTROL_DW.TimeStampB_h >= DC_MOTOR_CONTROL_B.u0)) {
      DC_MOTOR_CONTROL_B.Derivative1_c = 0.0;
    } else {
      DC_MOTOR_CONTROL_B.Product1_k = DC_MOTOR_CONTROL_DW.TimeStampA_b;
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeA_f;
      if (DC_MOTOR_CONTROL_DW.TimeStampA_b < DC_MOTOR_CONTROL_DW.TimeStampB_h) {
        if (DC_MOTOR_CONTROL_DW.TimeStampB_h < DC_MOTOR_CONTROL_B.u0) {
          DC_MOTOR_CONTROL_B.Product1_k = DC_MOTOR_CONTROL_DW.TimeStampB_h;
          lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB_a;
        }
      } else if (DC_MOTOR_CONTROL_DW.TimeStampA_b >= DC_MOTOR_CONTROL_B.u0) {
        DC_MOTOR_CONTROL_B.Product1_k = DC_MOTOR_CONTROL_DW.TimeStampB_h;
        lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB_a;
      }

      DC_MOTOR_CONTROL_B.Derivative1_c = (DC_MOTOR_CONTROL_B.Sum1 - *lastU) /
        (DC_MOTOR_CONTROL_B.u0 - DC_MOTOR_CONTROL_B.Product1_k);
    }

    /* MATLAB Function: '<S11>/MATLAB Function2' incorporates:
     *  Constant: '<S11>/lambda'
     */
    DC_MOTOR_CONTROL_B.S = DC_MOTOR_CONTROL_P.lambda_Value *
      DC_MOTOR_CONTROL_B.Sum1 + DC_MOTOR_CONTROL_B.Derivative1_c;

    /* Switch: '<S4>/Switch2' incorporates:
     *  Constant: '<S9>/Constant'
     *  MATLAB Function: '<S9>/Control action'
     *  ManualSwitch: '<S1>/Manual Switch'
     *  TransferFcn: '<S25>/Transfer Fcn1'
     *  TransferFcn: '<S27>/Transfer Fcn1'
     *  TransferFcn: '<S28>/Transfer Fcn1'
     */
    if (DC_MOTOR_CONTROL_B.GreaterThan_e) {
      DC_MOTOR_CONTROL_B.Derivative_m = DC_MOTOR_CONTROL_B.Add_c;
    } else if (DC_MOTOR_CONTROL_P.ManualSwitch_CurrentSetting == 1) {
      /* MATLAB Function: '<S11>/Control action' */
      if (rtIsNaN(DC_MOTOR_CONTROL_B.S)) {
        DC_MOTOR_CONTROL_B.Product1_k = (rtNaN);
      } else if (DC_MOTOR_CONTROL_B.S < 0.0) {
        DC_MOTOR_CONTROL_B.Product1_k = -1.0;
      } else {
        DC_MOTOR_CONTROL_B.Product1_k = (DC_MOTOR_CONTROL_B.S > 0.0);
      }

      /* ManualSwitch: '<S1>/Manual Switch' incorporates:
       *  Constant: '<S11>/Constant'
       *  Constant: '<S11>/K'
       *  Constant: '<S11>/W'
       *  Constant: '<S11>/lambda'
       *  MATLAB Function: '<S11>/Control action'
       */
      DC_MOTOR_CONTROL_B.Derivative_m = (((DC_MOTOR_CONTROL_P.Constant_Value - (
        -4.48 * DC_MOTOR_CONTROL_B.Derivative_m - 0.4322 *
        DC_MOTOR_CONTROL_B.Sum)) + DC_MOTOR_CONTROL_P.lambda_Value *
        DC_MOTOR_CONTROL_B.Derivative1_c) + (DC_MOTOR_CONTROL_P.W_Value *
        DC_MOTOR_CONTROL_B.Product1_k + DC_MOTOR_CONTROL_B.S) *
        DC_MOTOR_CONTROL_P.K_Value) * 0.19700551615445233;
    } else {
      DC_MOTOR_CONTROL_B.Derivative_m = (((DC_MOTOR_CONTROL_P.Constant_Value_l -
        (DC_MOTOR_CONTROL_P.TransferFcn1_C_g *
         DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_f * -4.48 - 0.4322 *
         DC_MOTOR_CONTROL_B.Sum)) + DC_MOTOR_CONTROL_P.TransferFcn1_C_i *
        DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_i) +
        DC_MOTOR_CONTROL_P.TransferFcn1_C_fc *
        DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_l) * 0.19700551615445233;
    }

    /* End of Switch: '<S4>/Switch2' */

    /* Saturate: '<Root>/Saturation' */
    if (DC_MOTOR_CONTROL_B.Derivative_m > DC_MOTOR_CONTROL_P.Saturation_UpperSat)
    {
      /* Saturate: '<Root>/Saturation' */
      DC_MOTOR_CONTROL_B.Saturation = DC_MOTOR_CONTROL_P.Saturation_UpperSat;
    } else if (DC_MOTOR_CONTROL_B.Derivative_m <
               DC_MOTOR_CONTROL_P.Saturation_LowerSat) {
      /* Saturate: '<Root>/Saturation' */
      DC_MOTOR_CONTROL_B.Saturation = DC_MOTOR_CONTROL_P.Saturation_LowerSat;
    } else {
      /* Saturate: '<Root>/Saturation' */
      DC_MOTOR_CONTROL_B.Saturation = DC_MOTOR_CONTROL_B.Derivative_m;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* DataTypeConversion: '<Root>/Cast To Double2' */
    DC_MOTOR_CONTROL_B.CastToDouble2 = DC_MOTOR_CONTROL_B.Sum;
    if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
      /* SignalConversion generated from: '<Root>/Mux1' */
      DC_MOTOR_CONTROL_B.TmpSignalConversionAtTAQSigLogg[0] =
        DC_MOTOR_CONTROL_B.CastToDouble1;
      DC_MOTOR_CONTROL_B.TmpSignalConversionAtTAQSigLogg[1] =
        DC_MOTOR_CONTROL_B.CastToDouble2;
      DC_MOTOR_CONTROL_B.TmpSignalConversionAtTAQSigLogg[2] =
        DC_MOTOR_CONTROL_B.Saturation;

      /* RelationalOperator: '<S55>/GreaterThan' incorporates:
       *  Constant: '<Root>/mode'
       *  Constant: '<S55>/Constant9'
       */
      DC_MOTOR_CONTROL_B.GreaterThan_o = (DC_MOTOR_CONTROL_P.mode_Value ==
        DC_MOTOR_CONTROL_P.Constant9_Value_f);
    }

    /* TransferFcn: '<S13>/Transfer Fcn1' */
    DC_MOTOR_CONTROL_B.Derivative_m = DC_MOTOR_CONTROL_P.TransferFcn1_C_gz *
      DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_d;

    /* Switch: '<S55>/Switch2' */
    if (DC_MOTOR_CONTROL_B.GreaterThan_o) {
      /* Switch: '<S55>/Switch2' incorporates:
       *  Integrator: '<S57>/Integrator'
       */
      DC_MOTOR_CONTROL_B.Switch2[0] = DC_MOTOR_CONTROL_X.Integrator_CSTATE_a;
      DC_MOTOR_CONTROL_B.Switch2[1] = DC_MOTOR_CONTROL_B.Product_a;
    } else {
      /* Switch: '<S55>/Switch2' incorporates:
       *  Integrator: '<S10>/Integrator'
       */
      DC_MOTOR_CONTROL_B.Switch2[0] = DC_MOTOR_CONTROL_X.Integrator_CSTATE;
      DC_MOTOR_CONTROL_B.Switch2[1] = DC_MOTOR_CONTROL_B.Derivative_m;
    }

    /* End of Switch: '<S55>/Switch2' */
    if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
      /* RelationalOperator: '<S53>/GreaterThan' incorporates:
       *  Constant: '<Root>/mode'
       *  Constant: '<S53>/Constant9'
       */
      DC_MOTOR_CONTROL_B.GreaterThan_a = (DC_MOTOR_CONTROL_P.mode_Value ==
        DC_MOTOR_CONTROL_P.Constant9_Value_n);
    }

    /* Sum: '<S8>/Sum1' */
    DC_MOTOR_CONTROL_B.Sum1_l = DC_MOTOR_CONTROL_B.Sum1;

    /* Product: '<S8>/Product' incorporates:
     *  Constant: '<Root>/Kp_p'
     */
    DC_MOTOR_CONTROL_B.Product_a = DC_MOTOR_CONTROL_P.Kp_p_Value *
      DC_MOTOR_CONTROL_B.Sum1_l;

    /* Sum: '<S10>/Sum1' */
    DC_MOTOR_CONTROL_B.Sum1_a = DC_MOTOR_CONTROL_B.Sum1;

    /* Product: '<S10>/Product' incorporates:
     *  Constant: '<Root>/Kp_p'
     */
    DC_MOTOR_CONTROL_B.Derivative1_c = DC_MOTOR_CONTROL_P.Kp_p_Value *
      DC_MOTOR_CONTROL_B.Sum1_a;

    /* Switch: '<S53>/Switch2' */
    if (DC_MOTOR_CONTROL_B.GreaterThan_a) {
      /* Switch: '<S53>/Switch2' incorporates:
       *  Product: '<S56>/Product'
       */
      DC_MOTOR_CONTROL_B.Switch2_p[0] = rtb_Product1_j_tmp;
      DC_MOTOR_CONTROL_B.Switch2_p[1] = rtb_Product1_j_tmp;
    } else {
      /* Switch: '<S53>/Switch2' */
      DC_MOTOR_CONTROL_B.Switch2_p[0] = DC_MOTOR_CONTROL_B.Derivative1_c;
      DC_MOTOR_CONTROL_B.Switch2_p[1] = DC_MOTOR_CONTROL_B.Product_a;
    }

    /* End of Switch: '<S53>/Switch2' */

    /* Product: '<S8>/Product1' incorporates:
     *  Constant: '<Root>/Kd_p'
     *  TransferFcn: '<S12>/Transfer Fcn1'
     */
    DC_MOTOR_CONTROL_B.Product1_j = DC_MOTOR_CONTROL_P.TransferFcn1_C_k *
      DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_a * DC_MOTOR_CONTROL_P.Kd_p_Value;

    /* Derivative: '<S10>/Derivative' */
    if ((DC_MOTOR_CONTROL_DW.TimeStampA_j >= DC_MOTOR_CONTROL_B.u0) &&
        (DC_MOTOR_CONTROL_DW.TimeStampB_p >= DC_MOTOR_CONTROL_B.u0)) {
      DC_MOTOR_CONTROL_B.S = 0.0;
    } else {
      DC_MOTOR_CONTROL_B.Product1_k = DC_MOTOR_CONTROL_DW.TimeStampA_j;
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeA_j;
      if (DC_MOTOR_CONTROL_DW.TimeStampA_j < DC_MOTOR_CONTROL_DW.TimeStampB_p) {
        if (DC_MOTOR_CONTROL_DW.TimeStampB_p < DC_MOTOR_CONTROL_B.u0) {
          DC_MOTOR_CONTROL_B.Product1_k = DC_MOTOR_CONTROL_DW.TimeStampB_p;
          lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB_b;
        }
      } else if (DC_MOTOR_CONTROL_DW.TimeStampA_j >= DC_MOTOR_CONTROL_B.u0) {
        DC_MOTOR_CONTROL_B.Product1_k = DC_MOTOR_CONTROL_DW.TimeStampB_p;
        lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB_b;
      }

      DC_MOTOR_CONTROL_B.S = (DC_MOTOR_CONTROL_B.Sum1_a - *lastU) /
        (DC_MOTOR_CONTROL_B.u0 - DC_MOTOR_CONTROL_B.Product1_k);
    }

    /* Product: '<S10>/Product1' incorporates:
     *  Constant: '<Root>/Kd_p'
     */
    DC_MOTOR_CONTROL_B.S *= DC_MOTOR_CONTROL_P.Kd_p_Value;

    /* Derivative: '<S57>/Derivative1' */
    if ((DC_MOTOR_CONTROL_DW.TimeStampA_c >= DC_MOTOR_CONTROL_B.u0) &&
        (DC_MOTOR_CONTROL_DW.TimeStampB_f >= DC_MOTOR_CONTROL_B.u0)) {
      /* Derivative: '<S57>/Derivative1' */
      DC_MOTOR_CONTROL_B.Derivative1 = 0.0;
    } else {
      DC_MOTOR_CONTROL_B.Product1_k = DC_MOTOR_CONTROL_DW.TimeStampA_c;
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeA_l;
      if (DC_MOTOR_CONTROL_DW.TimeStampA_c < DC_MOTOR_CONTROL_DW.TimeStampB_f) {
        if (DC_MOTOR_CONTROL_DW.TimeStampB_f < DC_MOTOR_CONTROL_B.u0) {
          DC_MOTOR_CONTROL_B.Product1_k = DC_MOTOR_CONTROL_DW.TimeStampB_f;
          lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB_f;
        }
      } else if (DC_MOTOR_CONTROL_DW.TimeStampA_c >= DC_MOTOR_CONTROL_B.u0) {
        DC_MOTOR_CONTROL_B.Product1_k = DC_MOTOR_CONTROL_DW.TimeStampB_f;
        lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB_f;
      }

      /* Derivative: '<S57>/Derivative1' */
      DC_MOTOR_CONTROL_B.Derivative1 = (DC_MOTOR_CONTROL_B.Sum - *lastU) /
        (DC_MOTOR_CONTROL_B.u0 - DC_MOTOR_CONTROL_B.Product1_k);
    }

    /* Product: '<S57>/Product1' incorporates:
     *  Constant: '<Root>/Kd_v'
     */
    DC_MOTOR_CONTROL_B.Product1_k = DC_MOTOR_CONTROL_P.Kd_v_Value *
      DC_MOTOR_CONTROL_B.Derivative1;
    if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
      /* RelationalOperator: '<S54>/GreaterThan' incorporates:
       *  Constant: '<Root>/mode'
       *  Constant: '<S54>/Constant9'
       */
      DC_MOTOR_CONTROL_B.GreaterThan_h = (DC_MOTOR_CONTROL_P.mode_Value ==
        DC_MOTOR_CONTROL_P.Constant9_Value_i);
    }

    /* Switch: '<S54>/Switch2' */
    if (DC_MOTOR_CONTROL_B.GreaterThan_h) {
      /* Switch: '<S54>/Switch2' */
      DC_MOTOR_CONTROL_B.Switch2_a[0] = DC_MOTOR_CONTROL_B.Product1_k;
      DC_MOTOR_CONTROL_B.Switch2_a[1] = DC_MOTOR_CONTROL_B.Product1_e;
    } else {
      /* Switch: '<S54>/Switch2' */
      DC_MOTOR_CONTROL_B.Switch2_a[0] = DC_MOTOR_CONTROL_B.S;
      DC_MOTOR_CONTROL_B.Switch2_a[1] = DC_MOTOR_CONTROL_B.Product1_j;
    }

    /* End of Switch: '<S54>/Switch2' */
    if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
    }

    /* DataTypeConversion: '<Root>/Cast To Double3' */
    DC_MOTOR_CONTROL_B.CastToDouble3 = DC_MOTOR_CONTROL_B.Gain;
    if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
      /* SignalConversion generated from: '<Root>/Mux' */
      DC_MOTOR_CONTROL_B.TmpSignalConversionAtTAQSigLo_i[0] =
        DC_MOTOR_CONTROL_B.CastToDouble;
      DC_MOTOR_CONTROL_B.TmpSignalConversionAtTAQSigLo_i[1] =
        DC_MOTOR_CONTROL_B.CastToDouble3;

      /* Product: '<S57>/Divide' incorporates:
       *  Constant: '<Root>/Kd_v'
       *  Constant: '<Root>/Ki_v'
       */
      DC_MOTOR_CONTROL_B.Product1_e = DC_MOTOR_CONTROL_P.Ki_v_Value /
        DC_MOTOR_CONTROL_P.Kd_v_Value;

      /* Math: '<S57>/Pow' incorporates:
       *  Constant: '<S57>/Constant'
       */
      if ((DC_MOTOR_CONTROL_B.Product1_e < 0.0) &&
          (DC_MOTOR_CONTROL_P.Constant_Value_d > floor
           (DC_MOTOR_CONTROL_P.Constant_Value_d))) {
        /* Math: '<S57>/Pow' */
        DC_MOTOR_CONTROL_B.Pow = -rt_powd_snf(-DC_MOTOR_CONTROL_B.Product1_e,
          DC_MOTOR_CONTROL_P.Constant_Value_d);
      } else {
        /* Math: '<S57>/Pow' */
        DC_MOTOR_CONTROL_B.Pow = rt_powd_snf(DC_MOTOR_CONTROL_B.Product1_e,
          DC_MOTOR_CONTROL_P.Constant_Value_d);
      }

      /* End of Math: '<S57>/Pow' */
    }

    /* Product: '<S57>/Product2' incorporates:
     *  Constant: '<Root>/Ki_v'
     *  Product: '<S56>/Product2'
     */
    Sum3_tmp = DC_MOTOR_CONTROL_B.Sum1_n * DC_MOTOR_CONTROL_P.Ki_v_Value;

    /* Sum: '<S57>/Sum3' incorporates:
     *  Integrator: '<S57>/Integrator'
     *  Product: '<S57>/Product2'
     *  Product: '<S57>/Product3'
     *  Sum: '<S57>/Add'
     *  Sum: '<S57>/Sum2'
     */
    DC_MOTOR_CONTROL_B.Sum3 = (DC_MOTOR_CONTROL_B.Saturation -
      ((rtb_Product1_j_tmp - DC_MOTOR_CONTROL_B.Product1_k) +
       DC_MOTOR_CONTROL_X.Integrator_CSTATE_a)) * DC_MOTOR_CONTROL_B.Pow +
      Sum3_tmp;
    if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
      /* Product: '<S56>/Divide' incorporates:
       *  Constant: '<Root>/Kd_v'
       *  Constant: '<Root>/Ki_v'
       */
      DC_MOTOR_CONTROL_B.Product1_e = DC_MOTOR_CONTROL_P.Ki_v_Value /
        DC_MOTOR_CONTROL_P.Kd_v_Value;

      /* Math: '<S56>/Pow' incorporates:
       *  Constant: '<S56>/Constant'
       */
      if ((DC_MOTOR_CONTROL_B.Product1_e < 0.0) &&
          (DC_MOTOR_CONTROL_P.Constant_Value_e > floor
           (DC_MOTOR_CONTROL_P.Constant_Value_e))) {
        /* Math: '<S56>/Pow' */
        DC_MOTOR_CONTROL_B.Pow_d = -rt_powd_snf(-DC_MOTOR_CONTROL_B.Product1_e,
          DC_MOTOR_CONTROL_P.Constant_Value_e);
      } else {
        /* Math: '<S56>/Pow' */
        DC_MOTOR_CONTROL_B.Pow_d = rt_powd_snf(DC_MOTOR_CONTROL_B.Product1_e,
          DC_MOTOR_CONTROL_P.Constant_Value_e);
      }

      /* End of Math: '<S56>/Pow' */
    }

    /* Sum: '<S56>/Sum3' incorporates:
     *  Product: '<S56>/Product3'
     *  Sum: '<S56>/Sum2'
     */
    DC_MOTOR_CONTROL_B.Sum3_i = (DC_MOTOR_CONTROL_B.Saturation -
      DC_MOTOR_CONTROL_B.Add_c) * DC_MOTOR_CONTROL_B.Pow_d + Sum3_tmp;

    /* StateSpace: '<S64>/Internal' */
    DC_MOTOR_CONTROL_B.Internal = 0.0;

    /* StateSpace: '<S64>/Internal' */
    for (ci = 0; ci < 11; ci++) {
      for (ri = DC_MOTOR_CONTROL_P.Internal_C_jc[(uint32_T)ci]; ri <
           DC_MOTOR_CONTROL_P.Internal_C_jc[(uint32_T)ci + 1U]; ri++) {
        /* StateSpace: '<S64>/Internal' */
        DC_MOTOR_CONTROL_B.Internal += DC_MOTOR_CONTROL_P.Internal_C_pr[ri] *
          DC_MOTOR_CONTROL_X.Internal_CSTATE[(uint32_T)ci];
      }
    }

    for (ri = DC_MOTOR_CONTROL_P.Internal_D_jc[0U]; ri <
         DC_MOTOR_CONTROL_P.Internal_D_jc[1U]; ri++) {
      /* StateSpace: '<S64>/Internal' */
      DC_MOTOR_CONTROL_B.Internal += DC_MOTOR_CONTROL_P.Internal_D_pr *
        DC_MOTOR_CONTROL_B.Sum3_i;
    }

    if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
    }

    /* Derivative: '<S57>/Derivative' */
    if ((DC_MOTOR_CONTROL_DW.TimeStampA_i >= DC_MOTOR_CONTROL_B.u0) &&
        (DC_MOTOR_CONTROL_DW.TimeStampB_m >= DC_MOTOR_CONTROL_B.u0)) {
      /* Derivative: '<S57>/Derivative' */
      DC_MOTOR_CONTROL_B.Derivative = 0.0;
    } else {
      DC_MOTOR_CONTROL_B.Product1_k = DC_MOTOR_CONTROL_DW.TimeStampA_i;
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeA_d;
      if (DC_MOTOR_CONTROL_DW.TimeStampA_i < DC_MOTOR_CONTROL_DW.TimeStampB_m) {
        if (DC_MOTOR_CONTROL_DW.TimeStampB_m < DC_MOTOR_CONTROL_B.u0) {
          DC_MOTOR_CONTROL_B.Product1_k = DC_MOTOR_CONTROL_DW.TimeStampB_m;
          lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB_n;
        }
      } else if (DC_MOTOR_CONTROL_DW.TimeStampA_i >= DC_MOTOR_CONTROL_B.u0) {
        DC_MOTOR_CONTROL_B.Product1_k = DC_MOTOR_CONTROL_DW.TimeStampB_m;
        lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB_n;
      }

      /* Derivative: '<S57>/Derivative' */
      DC_MOTOR_CONTROL_B.Derivative = (DC_MOTOR_CONTROL_B.Sum1_n - *lastU) /
        (DC_MOTOR_CONTROL_B.u0 - DC_MOTOR_CONTROL_B.Product1_k);
    }

    if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
      /* Product: '<S10>/Divide' incorporates:
       *  Constant: '<Root>/Ki_p'
       *  Constant: '<Root>/Kp_p'
       */
      DC_MOTOR_CONTROL_B.Product1_e = DC_MOTOR_CONTROL_P.Kp_p_Value /
        DC_MOTOR_CONTROL_P.Ki_p_Value;

      /* Math: '<S10>/Pow' incorporates:
       *  Constant: '<S10>/Constant'
       */
      if ((DC_MOTOR_CONTROL_B.Product1_e < 0.0) &&
          (DC_MOTOR_CONTROL_P.Constant_Value_h > floor
           (DC_MOTOR_CONTROL_P.Constant_Value_h))) {
        /* Math: '<S10>/Pow' */
        DC_MOTOR_CONTROL_B.Pow_p = -rt_powd_snf(-DC_MOTOR_CONTROL_B.Product1_e,
          DC_MOTOR_CONTROL_P.Constant_Value_h);
      } else {
        /* Math: '<S10>/Pow' */
        DC_MOTOR_CONTROL_B.Pow_p = rt_powd_snf(DC_MOTOR_CONTROL_B.Product1_e,
          DC_MOTOR_CONTROL_P.Constant_Value_h);
      }

      /* End of Math: '<S10>/Pow' */
    }

    /* Sum: '<S10>/Sum3' incorporates:
     *  Constant: '<Root>/Ki_p'
     *  Integrator: '<S10>/Integrator'
     *  Product: '<S10>/Product2'
     *  Product: '<S10>/Product3'
     *  Sum: '<S10>/Add'
     *  Sum: '<S10>/Sum2'
     */
    DC_MOTOR_CONTROL_B.Sum3_d = (DC_MOTOR_CONTROL_B.Saturation -
      ((DC_MOTOR_CONTROL_B.Derivative1_c + DC_MOTOR_CONTROL_B.S) +
       DC_MOTOR_CONTROL_X.Integrator_CSTATE)) * DC_MOTOR_CONTROL_B.Pow_p +
      DC_MOTOR_CONTROL_B.Sum1_a * DC_MOTOR_CONTROL_P.Ki_p_Value;
    if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
      /* Product: '<S8>/Divide' incorporates:
       *  Constant: '<Root>/Ki_p'
       *  Constant: '<Root>/Kp_p'
       */
      DC_MOTOR_CONTROL_B.Product1_e = DC_MOTOR_CONTROL_P.Kp_p_Value /
        DC_MOTOR_CONTROL_P.Ki_p_Value;

      /* Math: '<S8>/Pow' incorporates:
       *  Constant: '<S8>/Constant'
       */
      if ((DC_MOTOR_CONTROL_B.Product1_e < 0.0) &&
          (DC_MOTOR_CONTROL_P.Constant_Value_dt > floor
           (DC_MOTOR_CONTROL_P.Constant_Value_dt))) {
        /* Math: '<S8>/Pow' */
        DC_MOTOR_CONTROL_B.Pow_a = -rt_powd_snf(-DC_MOTOR_CONTROL_B.Product1_e,
          DC_MOTOR_CONTROL_P.Constant_Value_dt);
      } else {
        /* Math: '<S8>/Pow' */
        DC_MOTOR_CONTROL_B.Pow_a = rt_powd_snf(DC_MOTOR_CONTROL_B.Product1_e,
          DC_MOTOR_CONTROL_P.Constant_Value_dt);
      }

      /* End of Math: '<S8>/Pow' */
    }

    /* Sum: '<S8>/Sum3' incorporates:
     *  Constant: '<Root>/Ki_p'
     *  Product: '<S8>/Product2'
     *  Product: '<S8>/Product3'
     *  Sum: '<S8>/Add'
     *  Sum: '<S8>/Sum2'
     */
    DC_MOTOR_CONTROL_B.Sum3_k = (DC_MOTOR_CONTROL_B.Saturation -
      ((DC_MOTOR_CONTROL_B.Product_a + DC_MOTOR_CONTROL_B.Product1_j) +
       DC_MOTOR_CONTROL_B.Derivative_m)) * DC_MOTOR_CONTROL_B.Pow_a +
      DC_MOTOR_CONTROL_B.Sum1_l * DC_MOTOR_CONTROL_P.Ki_p_Value;

    /* StateSpace: '<S18>/Internal' */
    DC_MOTOR_CONTROL_B.Internal_i = 0.0;

    /* StateSpace: '<S18>/Internal' */
    for (ci = 0; ci < 11; ci++) {
      for (ri = DC_MOTOR_CONTROL_P.Internal_C_jc_f[(uint32_T)ci]; ri <
           DC_MOTOR_CONTROL_P.Internal_C_jc_f[(uint32_T)ci + 1U]; ri++) {
        /* StateSpace: '<S18>/Internal' */
        DC_MOTOR_CONTROL_B.Internal_i += DC_MOTOR_CONTROL_P.Internal_C_pr_d[ri] *
          DC_MOTOR_CONTROL_X.Internal_CSTATE_h[(uint32_T)ci];
      }
    }

    for (ri = DC_MOTOR_CONTROL_P.Internal_D_jc_d[0U]; ri <
         DC_MOTOR_CONTROL_P.Internal_D_jc_d[1U]; ri++) {
      /* StateSpace: '<S18>/Internal' */
      DC_MOTOR_CONTROL_B.Internal_i += DC_MOTOR_CONTROL_P.Internal_D_pr_c *
        DC_MOTOR_CONTROL_B.Sum3_k;
    }

    /* StateSpace: '<S14>/Internal' */
    DC_MOTOR_CONTROL_B.Internal_l = 0.0;

    /* StateSpace: '<S14>/Internal' */
    for (ci = 0; ci < 11; ci++) {
      for (ri = DC_MOTOR_CONTROL_P.Internal_C_jc_i[(uint32_T)ci]; ri <
           DC_MOTOR_CONTROL_P.Internal_C_jc_i[(uint32_T)ci + 1U]; ri++) {
        /* StateSpace: '<S14>/Internal' */
        DC_MOTOR_CONTROL_B.Internal_l += DC_MOTOR_CONTROL_P.Internal_C_pr_g[ri] *
          DC_MOTOR_CONTROL_X.Internal_CSTATE_c[(uint32_T)ci];
      }
    }

    for (ri = DC_MOTOR_CONTROL_P.Internal_D_jc_d0[0U]; ri <
         DC_MOTOR_CONTROL_P.Internal_D_jc_d0[1U]; ri++) {
      /* StateSpace: '<S14>/Internal' */
      DC_MOTOR_CONTROL_B.Internal_l += DC_MOTOR_CONTROL_P.Internal_D_pr_cg *
        DC_MOTOR_CONTROL_B.Sum1_l;
    }

    /* Switch: '<Root>/Switch' incorporates:
     *  Constant: '<Root>/Constant2'
     *  Constant: '<Root>/Constant3'
     */
    if (DC_MOTOR_CONTROL_B.Saturation > DC_MOTOR_CONTROL_P.Switch_Threshold) {
      DC_MOTOR_CONTROL_B.u0 = DC_MOTOR_CONTROL_P.Constant2_Value;
    } else {
      DC_MOTOR_CONTROL_B.u0 = DC_MOTOR_CONTROL_P.Constant3_Value;
    }

    /* MATLABSystem: '<Root>/Digital Output1' incorporates:
     *  Switch: '<Root>/Switch'
     */
    DC_MOTOR_CONTROL_B.u0 = rt_roundd_snf(DC_MOTOR_CONTROL_B.u0);
    if (DC_MOTOR_CONTROL_B.u0 < 256.0) {
      if (DC_MOTOR_CONTROL_B.u0 >= 0.0) {
        tmp_0 = (uint8_T)DC_MOTOR_CONTROL_B.u0;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    writeDigitalPin(7, tmp_0);

    /* End of MATLABSystem: '<Root>/Digital Output1' */

    /* Switch: '<Root>/Switch1' incorporates:
     *  Constant: '<Root>/Constant1'
     *  Constant: '<Root>/Constant4'
     */
    if (DC_MOTOR_CONTROL_B.Saturation > DC_MOTOR_CONTROL_P.Switch1_Threshold) {
      DC_MOTOR_CONTROL_B.u0 = DC_MOTOR_CONTROL_P.Constant4_Value;
    } else {
      DC_MOTOR_CONTROL_B.u0 = DC_MOTOR_CONTROL_P.Constant1_Value;
    }

    /* MATLABSystem: '<Root>/Digital Output3' incorporates:
     *  Switch: '<Root>/Switch1'
     */
    DC_MOTOR_CONTROL_B.u0 = rt_roundd_snf(DC_MOTOR_CONTROL_B.u0);
    if (DC_MOTOR_CONTROL_B.u0 < 256.0) {
      if (DC_MOTOR_CONTROL_B.u0 >= 0.0) {
        tmp_0 = (uint8_T)DC_MOTOR_CONTROL_B.u0;
      } else {
        tmp_0 = 0U;
      }
    } else {
      tmp_0 = MAX_uint8_T;
    }

    writeDigitalPin(5, tmp_0);

    /* End of MATLABSystem: '<Root>/Digital Output3' */
    if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
    }

    /* MATLABSystem: '<Root>/PWM' */
    obj = &DC_MOTOR_CONTROL_DW.obj_e;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8U);

    /* Abs: '<Root>/Abs' */
    DC_MOTOR_CONTROL_B.u0 = fabs(DC_MOTOR_CONTROL_B.Saturation);

    /* MATLABSystem: '<Root>/PWM' */
    if (!(DC_MOTOR_CONTROL_B.u0 <= 255.0)) {
      DC_MOTOR_CONTROL_B.u0 = 255.0;
    }

    MW_PWM_SetDutyCycle(DC_MOTOR_CONTROL_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
                        DC_MOTOR_CONTROL_B.u0);

    /* Sum: '<S9>/Sum1' */
    DC_MOTOR_CONTROL_B.Sum1_o = DC_MOTOR_CONTROL_B.CastToDouble1 -
      DC_MOTOR_CONTROL_B.Sum;

    /* TransferFcn: '<S24>/Transfer Fcn1' */
    DC_MOTOR_CONTROL_B.Product1_j = DC_MOTOR_CONTROL_P.TransferFcn1_C_d *
      DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_b;

    /* MATLAB Function: '<S22>/MATLAB Function2' incorporates:
     *  Constant: '<S9>/lambda'
     */
    DC_MOTOR_CONTROL_B.Product_a = DC_MOTOR_CONTROL_P.lambda_Value_p *
      DC_MOTOR_CONTROL_B.Sum1_o + DC_MOTOR_CONTROL_B.Product1_j;

    /* Signum: '<S22>/Sign' */
    if (rtIsNaN(DC_MOTOR_CONTROL_B.Product_a)) {
      DC_MOTOR_CONTROL_B.u0 = (rtNaN);
    } else if (DC_MOTOR_CONTROL_B.Product_a < 0.0) {
      DC_MOTOR_CONTROL_B.u0 = -1.0;
    } else {
      DC_MOTOR_CONTROL_B.u0 = (DC_MOTOR_CONTROL_B.Product_a > 0.0);
    }

    /* Product: '<S22>/Product1' incorporates:
     *  Constant: '<S9>/K'
     *  Constant: '<S9>/W'
     *  Product: '<S22>/Product'
     *  Signum: '<S22>/Sign'
     *  Sum: '<S22>/Sum'
     */
    DC_MOTOR_CONTROL_B.Product1 = (DC_MOTOR_CONTROL_B.u0 *
      DC_MOTOR_CONTROL_P.W_Value_e + DC_MOTOR_CONTROL_B.Product_a) *
      DC_MOTOR_CONTROL_P.K_Value_b;

    /* StateSpace: '<S42>/Internal' */
    DC_MOTOR_CONTROL_B.Internal_ii = 0.0;

    /* StateSpace: '<S42>/Internal' */
    for (ci = 0; ci < 13; ci++) {
      for (ri = DC_MOTOR_CONTROL_P.Internal_C_jc_g[(uint32_T)ci]; ri <
           DC_MOTOR_CONTROL_P.Internal_C_jc_g[(uint32_T)ci + 1U]; ri++) {
        /* StateSpace: '<S42>/Internal' */
        DC_MOTOR_CONTROL_B.Internal_ii += DC_MOTOR_CONTROL_P.Internal_C_pr_h[ri]
          * DC_MOTOR_CONTROL_X.Internal_CSTATE_k[(uint32_T)ci];
      }
    }

    for (ri = DC_MOTOR_CONTROL_P.Internal_D_jc_m[0U]; ri <
         DC_MOTOR_CONTROL_P.Internal_D_jc_m[1U]; ri++) {
      /* StateSpace: '<S42>/Internal' */
      DC_MOTOR_CONTROL_B.Internal_ii += DC_MOTOR_CONTROL_P.Internal_D_pr_i *
        DC_MOTOR_CONTROL_B.Product1;
    }

    /* Product: '<S9>/Product' incorporates:
     *  Constant: '<S9>/lambda'
     */
    DC_MOTOR_CONTROL_B.Product = DC_MOTOR_CONTROL_B.Product1_j *
      DC_MOTOR_CONTROL_P.lambda_Value_p;

    /* StateSpace: '<S46>/Internal' */
    DC_MOTOR_CONTROL_B.Internal_n = 0.0;

    /* StateSpace: '<S46>/Internal' */
    for (ci = 0; ci < 13; ci++) {
      for (ri = DC_MOTOR_CONTROL_P.Internal_C_jc_n[(uint32_T)ci]; ri <
           DC_MOTOR_CONTROL_P.Internal_C_jc_n[(uint32_T)ci + 1U]; ri++) {
        /* StateSpace: '<S46>/Internal' */
        DC_MOTOR_CONTROL_B.Internal_n += DC_MOTOR_CONTROL_P.Internal_C_pr_h0[ri]
          * DC_MOTOR_CONTROL_X.Internal_CSTATE_f[(uint32_T)ci];
      }
    }

    for (ri = DC_MOTOR_CONTROL_P.Internal_D_jc_n[0U]; ri <
         DC_MOTOR_CONTROL_P.Internal_D_jc_n[1U]; ri++) {
      /* StateSpace: '<S46>/Internal' */
      DC_MOTOR_CONTROL_B.Internal_n += DC_MOTOR_CONTROL_P.Internal_D_pr_a *
        DC_MOTOR_CONTROL_B.Product;
    }

    /* StateSpace: '<S30>/Internal' */
    DC_MOTOR_CONTROL_B.Internal_m = 0.0;

    /* StateSpace: '<S30>/Internal' */
    for (ci = 0; ci < 13; ci++) {
      for (ri = DC_MOTOR_CONTROL_P.Internal_C_jc_a[(uint32_T)ci]; ri <
           DC_MOTOR_CONTROL_P.Internal_C_jc_a[(uint32_T)ci + 1U]; ri++) {
        /* StateSpace: '<S30>/Internal' */
        DC_MOTOR_CONTROL_B.Internal_m += DC_MOTOR_CONTROL_P.Internal_C_pr_l[ri] *
          DC_MOTOR_CONTROL_X.Internal_CSTATE_b[(uint32_T)ci];
      }
    }

    for (ri = DC_MOTOR_CONTROL_P.Internal_D_jc_a[0U]; ri <
         DC_MOTOR_CONTROL_P.Internal_D_jc_a[1U]; ri++) {
      /* StateSpace: '<S30>/Internal' */
      DC_MOTOR_CONTROL_B.Internal_m += DC_MOTOR_CONTROL_P.Internal_D_pr_k *
        DC_MOTOR_CONTROL_B.Sum1_o;
    }

    /* StateSpace: '<S34>/Internal' */
    DC_MOTOR_CONTROL_B.Internal_o = 0.0;

    /* StateSpace: '<S34>/Internal' */
    for (ci = 0; ci < 13; ci++) {
      for (ri = DC_MOTOR_CONTROL_P.Internal_C_jc_e[(uint32_T)ci]; ri <
           DC_MOTOR_CONTROL_P.Internal_C_jc_e[(uint32_T)ci + 1U]; ri++) {
        /* StateSpace: '<S34>/Internal' */
        DC_MOTOR_CONTROL_B.Internal_o += DC_MOTOR_CONTROL_P.Internal_C_pr_j[ri] *
          DC_MOTOR_CONTROL_X.Internal_CSTATE_p[(uint32_T)ci];
      }
    }

    for (ri = DC_MOTOR_CONTROL_P.Internal_D_jc_e[0U]; ri <
         DC_MOTOR_CONTROL_P.Internal_D_jc_e[1U]; ri++) {
      /* StateSpace: '<S34>/Internal' */
      DC_MOTOR_CONTROL_B.Internal_o += DC_MOTOR_CONTROL_P.Internal_D_pr_g *
        DC_MOTOR_CONTROL_B.Sum;
    }

    /* StateSpace: '<S60>/Internal' */
    DC_MOTOR_CONTROL_B.Internal_b = 0.0;

    /* StateSpace: '<S60>/Internal' */
    for (ci = 0; ci < 11; ci++) {
      for (ri = DC_MOTOR_CONTROL_P.Internal_C_jc_fs[(uint32_T)ci]; ri <
           DC_MOTOR_CONTROL_P.Internal_C_jc_fs[(uint32_T)ci + 1U]; ri++) {
        /* StateSpace: '<S60>/Internal' */
        DC_MOTOR_CONTROL_B.Internal_b += DC_MOTOR_CONTROL_P.Internal_C_pr_n[ri] *
          DC_MOTOR_CONTROL_X.Internal_CSTATE_j[(uint32_T)ci];
      }
    }

    for (ri = DC_MOTOR_CONTROL_P.Internal_D_jc_k[0U]; ri <
         DC_MOTOR_CONTROL_P.Internal_D_jc_k[1U]; ri++) {
      /* StateSpace: '<S60>/Internal' */
      DC_MOTOR_CONTROL_B.Internal_b += DC_MOTOR_CONTROL_P.Internal_D_pr_kw *
        DC_MOTOR_CONTROL_B.Sum;
    }

    if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
    }

    /* StateSpace: '<S38>/Internal' */
    DC_MOTOR_CONTROL_B.Internal_d = 0.0;

    /* StateSpace: '<S38>/Internal' */
    for (ci = 0; ci < 11; ci++) {
      for (ri = DC_MOTOR_CONTROL_P.Internal_C_jc_o[(uint32_T)ci]; ri <
           DC_MOTOR_CONTROL_P.Internal_C_jc_o[(uint32_T)ci + 1U]; ri++) {
        /* StateSpace: '<S38>/Internal' */
        DC_MOTOR_CONTROL_B.Internal_d += DC_MOTOR_CONTROL_P.Internal_C_pr_b[ri] *
          DC_MOTOR_CONTROL_X.Internal_CSTATE_o[(uint32_T)ci];
      }
    }

    for (ri = DC_MOTOR_CONTROL_P.Internal_D_jc_c[0U]; ri <
         DC_MOTOR_CONTROL_P.Internal_D_jc_c[1U]; ri++) {
      /* StateSpace: '<S38>/Internal' */
      DC_MOTOR_CONTROL_B.Internal_d += DC_MOTOR_CONTROL_P.Internal_D_pr_j * 0.0;
    }
  }

  if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
    real_T *lastU;
    int_T idxDelay;
    if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
      /* Update for RandomNumber: '<S52>/White Noise' */
      DC_MOTOR_CONTROL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
        (&DC_MOTOR_CONTROL_DW.RandSeed) * DC_MOTOR_CONTROL_P.WhiteNoise_StdDev +
        DC_MOTOR_CONTROL_P.WhiteNoise_Mean;

      /* Update for Delay: '<S2>/Delay' */
      for (idxDelay = 0; idxDelay < 99; idxDelay++) {
        DC_MOTOR_CONTROL_DW.Delay_DSTATE[idxDelay] =
          DC_MOTOR_CONTROL_DW.Delay_DSTATE[idxDelay + 1];
      }

      DC_MOTOR_CONTROL_DW.Delay_DSTATE[99] = DC_MOTOR_CONTROL_B.Encoder;

      /* End of Update for Delay: '<S2>/Delay' */
    }

    /* Update for Derivative: '<S11>/Derivative' */
    if (DC_MOTOR_CONTROL_DW.TimeStampA == (rtInf)) {
      DC_MOTOR_CONTROL_DW.TimeStampA = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeA;
    } else if (DC_MOTOR_CONTROL_DW.TimeStampB == (rtInf)) {
      DC_MOTOR_CONTROL_DW.TimeStampB = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB;
    } else if (DC_MOTOR_CONTROL_DW.TimeStampA < DC_MOTOR_CONTROL_DW.TimeStampB)
    {
      DC_MOTOR_CONTROL_DW.TimeStampA = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeA;
    } else {
      DC_MOTOR_CONTROL_DW.TimeStampB = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB;
    }

    *lastU = DC_MOTOR_CONTROL_B.Sum;

    /* End of Update for Derivative: '<S11>/Derivative' */

    /* Update for Derivative: '<S11>/Derivative1' */
    if (DC_MOTOR_CONTROL_DW.TimeStampA_b == (rtInf)) {
      DC_MOTOR_CONTROL_DW.TimeStampA_b = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeA_f;
    } else if (DC_MOTOR_CONTROL_DW.TimeStampB_h == (rtInf)) {
      DC_MOTOR_CONTROL_DW.TimeStampB_h = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB_a;
    } else if (DC_MOTOR_CONTROL_DW.TimeStampA_b <
               DC_MOTOR_CONTROL_DW.TimeStampB_h) {
      DC_MOTOR_CONTROL_DW.TimeStampA_b = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeA_f;
    } else {
      DC_MOTOR_CONTROL_DW.TimeStampB_h = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB_a;
    }

    *lastU = DC_MOTOR_CONTROL_B.Sum1;

    /* End of Update for Derivative: '<S11>/Derivative1' */

    /* Update for Derivative: '<S10>/Derivative' */
    if (DC_MOTOR_CONTROL_DW.TimeStampA_j == (rtInf)) {
      DC_MOTOR_CONTROL_DW.TimeStampA_j = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeA_j;
    } else if (DC_MOTOR_CONTROL_DW.TimeStampB_p == (rtInf)) {
      DC_MOTOR_CONTROL_DW.TimeStampB_p = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB_b;
    } else if (DC_MOTOR_CONTROL_DW.TimeStampA_j <
               DC_MOTOR_CONTROL_DW.TimeStampB_p) {
      DC_MOTOR_CONTROL_DW.TimeStampA_j = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeA_j;
    } else {
      DC_MOTOR_CONTROL_DW.TimeStampB_p = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB_b;
    }

    *lastU = DC_MOTOR_CONTROL_B.Sum1_a;

    /* End of Update for Derivative: '<S10>/Derivative' */

    /* Update for Derivative: '<S57>/Derivative1' */
    if (DC_MOTOR_CONTROL_DW.TimeStampA_c == (rtInf)) {
      DC_MOTOR_CONTROL_DW.TimeStampA_c = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeA_l;
    } else if (DC_MOTOR_CONTROL_DW.TimeStampB_f == (rtInf)) {
      DC_MOTOR_CONTROL_DW.TimeStampB_f = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB_f;
    } else if (DC_MOTOR_CONTROL_DW.TimeStampA_c <
               DC_MOTOR_CONTROL_DW.TimeStampB_f) {
      DC_MOTOR_CONTROL_DW.TimeStampA_c = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeA_l;
    } else {
      DC_MOTOR_CONTROL_DW.TimeStampB_f = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB_f;
    }

    *lastU = DC_MOTOR_CONTROL_B.Sum;

    /* End of Update for Derivative: '<S57>/Derivative1' */

    /* Update for Derivative: '<S57>/Derivative' */
    if (DC_MOTOR_CONTROL_DW.TimeStampA_i == (rtInf)) {
      DC_MOTOR_CONTROL_DW.TimeStampA_i = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeA_d;
    } else if (DC_MOTOR_CONTROL_DW.TimeStampB_m == (rtInf)) {
      DC_MOTOR_CONTROL_DW.TimeStampB_m = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB_n;
    } else if (DC_MOTOR_CONTROL_DW.TimeStampA_i <
               DC_MOTOR_CONTROL_DW.TimeStampB_m) {
      DC_MOTOR_CONTROL_DW.TimeStampA_i = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeA_d;
    } else {
      DC_MOTOR_CONTROL_DW.TimeStampB_m = DC_MOTOR_CONTROL_M->Timing.t[0];
      lastU = &DC_MOTOR_CONTROL_DW.LastUAtTimeB_n;
    }

    *lastU = DC_MOTOR_CONTROL_B.Sum1_n;

    /* End of Update for Derivative: '<S57>/Derivative' */
    {                                  /* Sample time: [0.0s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        DC_MOTOR_CONTROL_M->Timing.t[0];

      /* Trigger External Mode event */
      errorCode = extmodeEvent(0,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }

    if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {/* Sample time: [0.01s, 0.0s] */
      extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
      extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T)
        (((DC_MOTOR_CONTROL_M->Timing.clockTick1+
           DC_MOTOR_CONTROL_M->Timing.clockTickH1* 4294967296.0)) * 0.01);

      /* Trigger External Mode event */
      errorCode = extmodeEvent(1,currentTime);
      if (errorCode != EXTMODE_SUCCESS) {
        /* Code to handle External Mode event errors
           may be added here */
      }
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(DC_MOTOR_CONTROL_M)) {
    rt_ertODEUpdateContinuousStates(&DC_MOTOR_CONTROL_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++DC_MOTOR_CONTROL_M->Timing.clockTick0)) {
      ++DC_MOTOR_CONTROL_M->Timing.clockTickH0;
    }

    DC_MOTOR_CONTROL_M->Timing.t[0] = rtsiGetSolverStopTime
      (&DC_MOTOR_CONTROL_M->solverInfo);

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
      DC_MOTOR_CONTROL_M->Timing.clockTick1++;
      if (!DC_MOTOR_CONTROL_M->Timing.clockTick1) {
        DC_MOTOR_CONTROL_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void DC_MOTOR_CONTROL_derivatives(void)
{
  XDot_DC_MOTOR_CONTROL_T *_rtXdot;
  int_T is;
  uint32_T ri;
  _rtXdot = ((XDot_DC_MOTOR_CONTROL_T *) DC_MOTOR_CONTROL_M->derivs);

  /* Derivatives for TransferFcn: '<S58>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = DC_MOTOR_CONTROL_P.TransferFcn1_A *
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += DC_MOTOR_CONTROL_B.Internal_b;

  /* Derivatives for TransferFcn: '<S59>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_o = DC_MOTOR_CONTROL_P.TransferFcn1_A_b *
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_o;
  _rtXdot->TransferFcn1_CSTATE_o += DC_MOTOR_CONTROL_B.Internal;

  /* Derivatives for TransferFcn: '<S25>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_f = DC_MOTOR_CONTROL_P.TransferFcn1_A_h *
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_f;
  _rtXdot->TransferFcn1_CSTATE_f += DC_MOTOR_CONTROL_B.Internal_o;

  /* Derivatives for TransferFcn: '<S28>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_i = DC_MOTOR_CONTROL_P.TransferFcn1_A_j *
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_i;
  _rtXdot->TransferFcn1_CSTATE_i += DC_MOTOR_CONTROL_B.Internal_n;

  /* Derivatives for TransferFcn: '<S27>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_l = DC_MOTOR_CONTROL_P.TransferFcn1_A_n *
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_l;
  _rtXdot->TransferFcn1_CSTATE_l += DC_MOTOR_CONTROL_B.Internal_ii;

  /* Derivatives for TransferFcn: '<S13>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_d = DC_MOTOR_CONTROL_P.TransferFcn1_A_m *
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_d;
  _rtXdot->TransferFcn1_CSTATE_d += DC_MOTOR_CONTROL_B.Internal_i;

  /* Derivatives for Integrator: '<S10>/Integrator' */
  _rtXdot->Integrator_CSTATE = DC_MOTOR_CONTROL_B.Sum3_d;

  /* Derivatives for Integrator: '<S57>/Integrator' */
  _rtXdot->Integrator_CSTATE_a = DC_MOTOR_CONTROL_B.Sum3;

  /* Derivatives for TransferFcn: '<S12>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_a = DC_MOTOR_CONTROL_P.TransferFcn1_A_bm *
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_a;
  _rtXdot->TransferFcn1_CSTATE_a += DC_MOTOR_CONTROL_B.Internal_l;

  /* Derivatives for StateSpace: '<S64>/Internal' */
  memset(&_rtXdot->Internal_CSTATE[0], 0, 11U * sizeof(real_T));
  for (is = 0; is < 11; is++) {
    for (ri = DC_MOTOR_CONTROL_P.Internal_A_jc[(uint32_T)is]; ri <
         DC_MOTOR_CONTROL_P.Internal_A_jc[(uint32_T)is + 1U]; ri++) {
      _rtXdot->Internal_CSTATE[DC_MOTOR_CONTROL_P.Internal_A_ir[ri]] +=
        DC_MOTOR_CONTROL_P.Internal_A_pr[ri] *
        DC_MOTOR_CONTROL_X.Internal_CSTATE[(uint32_T)is];
    }
  }

  for (ri = DC_MOTOR_CONTROL_P.Internal_B_jc[0U]; ri <
       DC_MOTOR_CONTROL_P.Internal_B_jc[1U]; ri++) {
    _rtXdot->Internal_CSTATE[DC_MOTOR_CONTROL_P.Internal_B_ir[ri]] +=
      DC_MOTOR_CONTROL_P.Internal_B_pr[ri] * DC_MOTOR_CONTROL_B.Sum3_i;
  }

  /* End of Derivatives for StateSpace: '<S64>/Internal' */

  /* Derivatives for StateSpace: '<S18>/Internal' */
  memset(&_rtXdot->Internal_CSTATE_h[0], 0, 11U * sizeof(real_T));
  for (is = 0; is < 11; is++) {
    for (ri = DC_MOTOR_CONTROL_P.Internal_A_jc_d[(uint32_T)is]; ri <
         DC_MOTOR_CONTROL_P.Internal_A_jc_d[(uint32_T)is + 1U]; ri++) {
      _rtXdot->Internal_CSTATE_h[DC_MOTOR_CONTROL_P.Internal_A_ir_e[ri]] +=
        DC_MOTOR_CONTROL_P.Internal_A_pr_i[ri] *
        DC_MOTOR_CONTROL_X.Internal_CSTATE_h[(uint32_T)is];
    }
  }

  for (ri = DC_MOTOR_CONTROL_P.Internal_B_jc_n[0U]; ri <
       DC_MOTOR_CONTROL_P.Internal_B_jc_n[1U]; ri++) {
    _rtXdot->Internal_CSTATE_h[DC_MOTOR_CONTROL_P.Internal_B_ir_o[ri]] +=
      DC_MOTOR_CONTROL_P.Internal_B_pr_o[ri] * DC_MOTOR_CONTROL_B.Sum3_k;
  }

  /* End of Derivatives for StateSpace: '<S18>/Internal' */

  /* Derivatives for StateSpace: '<S14>/Internal' */
  memset(&_rtXdot->Internal_CSTATE_c[0], 0, 11U * sizeof(real_T));
  for (is = 0; is < 11; is++) {
    for (ri = DC_MOTOR_CONTROL_P.Internal_A_jc_f[(uint32_T)is]; ri <
         DC_MOTOR_CONTROL_P.Internal_A_jc_f[(uint32_T)is + 1U]; ri++) {
      _rtXdot->Internal_CSTATE_c[DC_MOTOR_CONTROL_P.Internal_A_ir_d[ri]] +=
        DC_MOTOR_CONTROL_P.Internal_A_pr_i1[ri] *
        DC_MOTOR_CONTROL_X.Internal_CSTATE_c[(uint32_T)is];
    }
  }

  for (ri = DC_MOTOR_CONTROL_P.Internal_B_jc_l[0U]; ri <
       DC_MOTOR_CONTROL_P.Internal_B_jc_l[1U]; ri++) {
    _rtXdot->Internal_CSTATE_c[DC_MOTOR_CONTROL_P.Internal_B_ir_i[ri]] +=
      DC_MOTOR_CONTROL_P.Internal_B_pr_e[ri] * DC_MOTOR_CONTROL_B.Sum1_l;
  }

  /* End of Derivatives for StateSpace: '<S14>/Internal' */

  /* Derivatives for TransferFcn: '<S24>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_b = DC_MOTOR_CONTROL_P.TransferFcn1_A_c *
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_b;
  _rtXdot->TransferFcn1_CSTATE_b += DC_MOTOR_CONTROL_B.Internal_m;

  /* Derivatives for StateSpace: '<S42>/Internal' */
  memset(&_rtXdot->Internal_CSTATE_k[0], 0, 13U * sizeof(real_T));
  for (is = 0; is < 13; is++) {
    for (ri = DC_MOTOR_CONTROL_P.Internal_A_jc_c[(uint32_T)is]; ri <
         DC_MOTOR_CONTROL_P.Internal_A_jc_c[(uint32_T)is + 1U]; ri++) {
      _rtXdot->Internal_CSTATE_k[DC_MOTOR_CONTROL_P.Internal_A_ir_p[ri]] +=
        DC_MOTOR_CONTROL_P.Internal_A_pr_j[ri] *
        DC_MOTOR_CONTROL_X.Internal_CSTATE_k[(uint32_T)is];
    }
  }

  for (ri = DC_MOTOR_CONTROL_P.Internal_B_jc_h[0U]; ri <
       DC_MOTOR_CONTROL_P.Internal_B_jc_h[1U]; ri++) {
    _rtXdot->Internal_CSTATE_k[DC_MOTOR_CONTROL_P.Internal_B_ir_m[ri]] +=
      DC_MOTOR_CONTROL_P.Internal_B_pr_d[ri] * DC_MOTOR_CONTROL_B.Product1;
  }

  /* End of Derivatives for StateSpace: '<S42>/Internal' */

  /* Derivatives for StateSpace: '<S46>/Internal' */
  memset(&_rtXdot->Internal_CSTATE_f[0], 0, 13U * sizeof(real_T));
  for (is = 0; is < 13; is++) {
    for (ri = DC_MOTOR_CONTROL_P.Internal_A_jc_b[(uint32_T)is]; ri <
         DC_MOTOR_CONTROL_P.Internal_A_jc_b[(uint32_T)is + 1U]; ri++) {
      _rtXdot->Internal_CSTATE_f[DC_MOTOR_CONTROL_P.Internal_A_ir_n[ri]] +=
        DC_MOTOR_CONTROL_P.Internal_A_pr_c[ri] *
        DC_MOTOR_CONTROL_X.Internal_CSTATE_f[(uint32_T)is];
    }
  }

  for (ri = DC_MOTOR_CONTROL_P.Internal_B_jc_e[0U]; ri <
       DC_MOTOR_CONTROL_P.Internal_B_jc_e[1U]; ri++) {
    _rtXdot->Internal_CSTATE_f[DC_MOTOR_CONTROL_P.Internal_B_ir_j[ri]] +=
      DC_MOTOR_CONTROL_P.Internal_B_pr_p[ri] * DC_MOTOR_CONTROL_B.Product;
  }

  /* End of Derivatives for StateSpace: '<S46>/Internal' */

  /* Derivatives for StateSpace: '<S30>/Internal' */
  memset(&_rtXdot->Internal_CSTATE_b[0], 0, 13U * sizeof(real_T));
  for (is = 0; is < 13; is++) {
    for (ri = DC_MOTOR_CONTROL_P.Internal_A_jc_a[(uint32_T)is]; ri <
         DC_MOTOR_CONTROL_P.Internal_A_jc_a[(uint32_T)is + 1U]; ri++) {
      _rtXdot->Internal_CSTATE_b[DC_MOTOR_CONTROL_P.Internal_A_ir_a[ri]] +=
        DC_MOTOR_CONTROL_P.Internal_A_pr_a[ri] *
        DC_MOTOR_CONTROL_X.Internal_CSTATE_b[(uint32_T)is];
    }
  }

  for (ri = DC_MOTOR_CONTROL_P.Internal_B_jc_b[0U]; ri <
       DC_MOTOR_CONTROL_P.Internal_B_jc_b[1U]; ri++) {
    _rtXdot->Internal_CSTATE_b[DC_MOTOR_CONTROL_P.Internal_B_ir_k[ri]] +=
      DC_MOTOR_CONTROL_P.Internal_B_pr_ob[ri] * DC_MOTOR_CONTROL_B.Sum1_o;
  }

  /* End of Derivatives for StateSpace: '<S30>/Internal' */

  /* Derivatives for StateSpace: '<S34>/Internal' */
  memset(&_rtXdot->Internal_CSTATE_p[0], 0, 13U * sizeof(real_T));
  for (is = 0; is < 13; is++) {
    for (ri = DC_MOTOR_CONTROL_P.Internal_A_jc_n[(uint32_T)is]; ri <
         DC_MOTOR_CONTROL_P.Internal_A_jc_n[(uint32_T)is + 1U]; ri++) {
      _rtXdot->Internal_CSTATE_p[DC_MOTOR_CONTROL_P.Internal_A_ir_b[ri]] +=
        DC_MOTOR_CONTROL_P.Internal_A_pr_iu[ri] *
        DC_MOTOR_CONTROL_X.Internal_CSTATE_p[(uint32_T)is];
    }
  }

  for (ri = DC_MOTOR_CONTROL_P.Internal_B_jc_k[0U]; ri <
       DC_MOTOR_CONTROL_P.Internal_B_jc_k[1U]; ri++) {
    _rtXdot->Internal_CSTATE_p[DC_MOTOR_CONTROL_P.Internal_B_ir_n[ri]] +=
      DC_MOTOR_CONTROL_P.Internal_B_pr_j[ri] * DC_MOTOR_CONTROL_B.Sum;
  }

  /* End of Derivatives for StateSpace: '<S34>/Internal' */

  /* Derivatives for StateSpace: '<S60>/Internal' */
  memset(&_rtXdot->Internal_CSTATE_j[0], 0, 11U * sizeof(real_T));
  for (is = 0; is < 11; is++) {
    for (ri = DC_MOTOR_CONTROL_P.Internal_A_jc_k[(uint32_T)is]; ri <
         DC_MOTOR_CONTROL_P.Internal_A_jc_k[(uint32_T)is + 1U]; ri++) {
      _rtXdot->Internal_CSTATE_j[DC_MOTOR_CONTROL_P.Internal_A_ir_aq[ri]] +=
        DC_MOTOR_CONTROL_P.Internal_A_pr_l[ri] *
        DC_MOTOR_CONTROL_X.Internal_CSTATE_j[(uint32_T)is];
    }
  }

  for (ri = DC_MOTOR_CONTROL_P.Internal_B_jc_bv[0U]; ri <
       DC_MOTOR_CONTROL_P.Internal_B_jc_bv[1U]; ri++) {
    _rtXdot->Internal_CSTATE_j[DC_MOTOR_CONTROL_P.Internal_B_ir_jh[ri]] +=
      DC_MOTOR_CONTROL_P.Internal_B_pr_c[ri] * DC_MOTOR_CONTROL_B.Sum;
  }

  /* End of Derivatives for StateSpace: '<S60>/Internal' */

  /* Derivatives for StateSpace: '<S38>/Internal' */
  memset(&_rtXdot->Internal_CSTATE_o[0], 0, 11U * sizeof(real_T));
  for (is = 0; is < 11; is++) {
    for (ri = DC_MOTOR_CONTROL_P.Internal_A_jc_m[(uint32_T)is]; ri <
         DC_MOTOR_CONTROL_P.Internal_A_jc_m[(uint32_T)is + 1U]; ri++) {
      _rtXdot->Internal_CSTATE_o[DC_MOTOR_CONTROL_P.Internal_A_ir_ew[ri]] +=
        DC_MOTOR_CONTROL_P.Internal_A_pr_a2[ri] *
        DC_MOTOR_CONTROL_X.Internal_CSTATE_o[(uint32_T)is];
    }
  }

  for (ri = DC_MOTOR_CONTROL_P.Internal_B_jc_a[0U]; ri <
       DC_MOTOR_CONTROL_P.Internal_B_jc_a[1U]; ri++) {
    _rtXdot->Internal_CSTATE_o[DC_MOTOR_CONTROL_P.Internal_B_ir_mn[ri]] +=
      DC_MOTOR_CONTROL_P.Internal_B_pr_a[ri] * 0.0;
  }

  /* End of Derivatives for StateSpace: '<S38>/Internal' */

  /* Derivatives for TransferFcn: '<S26>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_od = DC_MOTOR_CONTROL_P.TransferFcn1_A_f *
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_od;
  _rtXdot->TransferFcn1_CSTATE_od += DC_MOTOR_CONTROL_B.Internal_d;
}

/* Model initialize function */
void DC_MOTOR_CONTROL_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)DC_MOTOR_CONTROL_M, 0,
                sizeof(RT_MODEL_DC_MOTOR_CONTROL_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&DC_MOTOR_CONTROL_M->solverInfo,
                          &DC_MOTOR_CONTROL_M->Timing.simTimeStep);
    rtsiSetTPtr(&DC_MOTOR_CONTROL_M->solverInfo, &rtmGetTPtr(DC_MOTOR_CONTROL_M));
    rtsiSetStepSizePtr(&DC_MOTOR_CONTROL_M->solverInfo,
                       &DC_MOTOR_CONTROL_M->Timing.stepSize0);
    rtsiSetdXPtr(&DC_MOTOR_CONTROL_M->solverInfo, &DC_MOTOR_CONTROL_M->derivs);
    rtsiSetContStatesPtr(&DC_MOTOR_CONTROL_M->solverInfo, (real_T **)
                         &DC_MOTOR_CONTROL_M->contStates);
    rtsiSetNumContStatesPtr(&DC_MOTOR_CONTROL_M->solverInfo,
      &DC_MOTOR_CONTROL_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&DC_MOTOR_CONTROL_M->solverInfo,
      &DC_MOTOR_CONTROL_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&DC_MOTOR_CONTROL_M->solverInfo,
      &DC_MOTOR_CONTROL_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&DC_MOTOR_CONTROL_M->solverInfo,
      &DC_MOTOR_CONTROL_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&DC_MOTOR_CONTROL_M->solverInfo, (&rtmGetErrorStatus
      (DC_MOTOR_CONTROL_M)));
    rtsiSetRTModelPtr(&DC_MOTOR_CONTROL_M->solverInfo, DC_MOTOR_CONTROL_M);
  }

  rtsiSetSimTimeStep(&DC_MOTOR_CONTROL_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&DC_MOTOR_CONTROL_M->solverInfo, false);
  DC_MOTOR_CONTROL_M->intgData.y = DC_MOTOR_CONTROL_M->odeY;
  DC_MOTOR_CONTROL_M->intgData.f[0] = DC_MOTOR_CONTROL_M->odeF[0];
  DC_MOTOR_CONTROL_M->intgData.f[1] = DC_MOTOR_CONTROL_M->odeF[1];
  DC_MOTOR_CONTROL_M->intgData.f[2] = DC_MOTOR_CONTROL_M->odeF[2];
  DC_MOTOR_CONTROL_M->contStates = ((X_DC_MOTOR_CONTROL_T *) &DC_MOTOR_CONTROL_X);
  rtsiSetSolverData(&DC_MOTOR_CONTROL_M->solverInfo, (void *)
                    &DC_MOTOR_CONTROL_M->intgData);
  rtsiSetSolverName(&DC_MOTOR_CONTROL_M->solverInfo,"ode3");
  rtmSetTPtr(DC_MOTOR_CONTROL_M, &DC_MOTOR_CONTROL_M->Timing.tArray[0]);
  rtmSetTFinal(DC_MOTOR_CONTROL_M, -1);
  DC_MOTOR_CONTROL_M->Timing.stepSize0 = 0.01;

  /* External mode info */
  DC_MOTOR_CONTROL_M->Sizes.checksums[0] = (1059370160U);
  DC_MOTOR_CONTROL_M->Sizes.checksums[1] = (3412073034U);
  DC_MOTOR_CONTROL_M->Sizes.checksums[2] = (1327702667U);
  DC_MOTOR_CONTROL_M->Sizes.checksums[3] = (383130336U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[10];
    DC_MOTOR_CONTROL_M->extModeInfo = (&rt_ExtModeInfo);
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
    systemRan[9] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DC_MOTOR_CONTROL_M->extModeInfo,
      &DC_MOTOR_CONTROL_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DC_MOTOR_CONTROL_M->extModeInfo,
                        DC_MOTOR_CONTROL_M->Sizes.checksums);
    rteiSetTPtr(DC_MOTOR_CONTROL_M->extModeInfo, rtmGetTPtr(DC_MOTOR_CONTROL_M));
  }

  /* block I/O */
  (void) memset(((void *) &DC_MOTOR_CONTROL_B), 0,
                sizeof(B_DC_MOTOR_CONTROL_T));

  /* states (continuous) */
  {
    (void) memset((void *)&DC_MOTOR_CONTROL_X, 0,
                  sizeof(X_DC_MOTOR_CONTROL_T));
  }

  /* states (dwork) */
  (void) memset((void *)&DC_MOTOR_CONTROL_DW, 0,
                sizeof(DW_DC_MOTOR_CONTROL_T));

  {
    codertarget_arduinobase_int_p_T *obj;

    /* Start for MATLABSystem: '<Root>/Encoder' */
    DC_MOTOR_CONTROL_DW.obj.Index = 0U;
    DC_MOTOR_CONTROL_DW.obj.matlabCodegenIsDeleted = false;
    DC_MOTOR_CONTROL_DW.objisempty_f = true;
    DC_MOTOR_CONTROL_DW.obj.SampleTime = DC_MOTOR_CONTROL_P.Encoder_SampleTime;
    DC_MOTOR_CONTROL_DW.obj.isInitialized = 1;
    MW_EncoderSetup(3U, 2U, &DC_MOTOR_CONTROL_DW.obj.Index);
    DC_MOTOR_CONTROL_DW.obj.isSetupComplete = true;
    DC_MOTOR_CONTROL_DW.obj.TunablePropsChanged = false;

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    DC_MOTOR_CONTROL_DW.obj_n.matlabCodegenIsDeleted = false;
    DC_MOTOR_CONTROL_DW.objisempty_p = true;
    DC_MOTOR_CONTROL_DW.obj_n.isInitialized = 1;
    digitalIOSetup(7, 1);
    DC_MOTOR_CONTROL_DW.obj_n.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output3' */
    DC_MOTOR_CONTROL_DW.obj_h.matlabCodegenIsDeleted = false;
    DC_MOTOR_CONTROL_DW.objisempty_i = true;
    DC_MOTOR_CONTROL_DW.obj_h.isInitialized = 1;
    digitalIOSetup(5, 1);
    DC_MOTOR_CONTROL_DW.obj_h.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/PWM' */
    DC_MOTOR_CONTROL_DW.obj_e.matlabCodegenIsDeleted = false;
    DC_MOTOR_CONTROL_DW.objisempty = true;
    obj = &DC_MOTOR_CONTROL_DW.obj_e;
    DC_MOTOR_CONTROL_DW.obj_e.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(8U, 0.0, 0.0);
    DC_MOTOR_CONTROL_DW.obj_e.isSetupComplete = true;
  }

  {
    real_T tmp;
    int32_T i;
    int32_T t;
    uint32_T tseed;

    /* InitializeConditions for RandomNumber: '<S52>/White Noise' */
    tmp = floor(DC_MOTOR_CONTROL_P.BandLimitedWhiteNoise_seed);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 4.294967296E+9);
    }

    tseed = tmp < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp : (uint32_T)tmp;
    i = (int32_T)(tseed >> 16U);
    t = (int32_T)(tseed & 32768U);
    DC_MOTOR_CONTROL_DW.RandSeed = ((((tseed - ((uint32_T)i << 16U)) + (uint32_T)
      t) << 16U) + (uint32_T)t) + (uint32_T)i;
    if (DC_MOTOR_CONTROL_DW.RandSeed < 1U) {
      DC_MOTOR_CONTROL_DW.RandSeed = 1144108930U;
    } else if (DC_MOTOR_CONTROL_DW.RandSeed > 2147483646U) {
      DC_MOTOR_CONTROL_DW.RandSeed = 2147483646U;
    }

    DC_MOTOR_CONTROL_DW.NextOutput = rt_nrand_Upu32_Yd_f_pw_snf
      (&DC_MOTOR_CONTROL_DW.RandSeed) * DC_MOTOR_CONTROL_P.WhiteNoise_StdDev +
      DC_MOTOR_CONTROL_P.WhiteNoise_Mean;

    /* End of InitializeConditions for RandomNumber: '<S52>/White Noise' */

    /* InitializeConditions for Delay: '<S2>/Delay' */
    for (i = 0; i < 100; i++) {
      DC_MOTOR_CONTROL_DW.Delay_DSTATE[i] =
        DC_MOTOR_CONTROL_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S2>/Delay' */

    /* InitializeConditions for TransferFcn: '<S58>/Transfer Fcn1' */
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S59>/Transfer Fcn1' */
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_o = 0.0;

    /* InitializeConditions for Derivative: '<S11>/Derivative' */
    DC_MOTOR_CONTROL_DW.TimeStampA = (rtInf);
    DC_MOTOR_CONTROL_DW.TimeStampB = (rtInf);

    /* InitializeConditions for Derivative: '<S11>/Derivative1' */
    DC_MOTOR_CONTROL_DW.TimeStampA_b = (rtInf);
    DC_MOTOR_CONTROL_DW.TimeStampB_h = (rtInf);

    /* InitializeConditions for TransferFcn: '<S25>/Transfer Fcn1' */
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_f = 0.0;

    /* InitializeConditions for TransferFcn: '<S28>/Transfer Fcn1' */
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_i = 0.0;

    /* InitializeConditions for TransferFcn: '<S27>/Transfer Fcn1' */
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_l = 0.0;

    /* InitializeConditions for TransferFcn: '<S13>/Transfer Fcn1' */
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_d = 0.0;

    /* InitializeConditions for Integrator: '<S10>/Integrator' */
    DC_MOTOR_CONTROL_X.Integrator_CSTATE = DC_MOTOR_CONTROL_P.Integrator_IC;

    /* InitializeConditions for Integrator: '<S57>/Integrator' */
    DC_MOTOR_CONTROL_X.Integrator_CSTATE_a = DC_MOTOR_CONTROL_P.Integrator_IC_m;

    /* InitializeConditions for TransferFcn: '<S12>/Transfer Fcn1' */
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_a = 0.0;

    /* InitializeConditions for Derivative: '<S10>/Derivative' */
    DC_MOTOR_CONTROL_DW.TimeStampA_j = (rtInf);
    DC_MOTOR_CONTROL_DW.TimeStampB_p = (rtInf);

    /* InitializeConditions for Derivative: '<S57>/Derivative1' */
    DC_MOTOR_CONTROL_DW.TimeStampA_c = (rtInf);
    DC_MOTOR_CONTROL_DW.TimeStampB_f = (rtInf);

    /* InitializeConditions for Derivative: '<S57>/Derivative' */
    DC_MOTOR_CONTROL_DW.TimeStampA_i = (rtInf);
    DC_MOTOR_CONTROL_DW.TimeStampB_m = (rtInf);
    for (i = 0; i < 11; i++) {
      /* InitializeConditions for StateSpace: '<S64>/Internal' */
      DC_MOTOR_CONTROL_X.Internal_CSTATE[i] =
        DC_MOTOR_CONTROL_P.Internal_InitialCondition;

      /* InitializeConditions for StateSpace: '<S18>/Internal' */
      DC_MOTOR_CONTROL_X.Internal_CSTATE_h[i] =
        DC_MOTOR_CONTROL_P.Internal_InitialCondition_n;

      /* InitializeConditions for StateSpace: '<S14>/Internal' */
      DC_MOTOR_CONTROL_X.Internal_CSTATE_c[i] =
        DC_MOTOR_CONTROL_P.Internal_InitialCondition_f;
    }

    /* InitializeConditions for TransferFcn: '<S24>/Transfer Fcn1' */
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_b = 0.0;
    for (i = 0; i < 13; i++) {
      /* InitializeConditions for StateSpace: '<S42>/Internal' */
      DC_MOTOR_CONTROL_X.Internal_CSTATE_k[i] =
        DC_MOTOR_CONTROL_P.Internal_InitialCondition_ns;

      /* InitializeConditions for StateSpace: '<S46>/Internal' */
      DC_MOTOR_CONTROL_X.Internal_CSTATE_f[i] =
        DC_MOTOR_CONTROL_P.Internal_InitialCondition_o;

      /* InitializeConditions for StateSpace: '<S30>/Internal' */
      DC_MOTOR_CONTROL_X.Internal_CSTATE_b[i] =
        DC_MOTOR_CONTROL_P.Internal_InitialCondition_k;

      /* InitializeConditions for StateSpace: '<S34>/Internal' */
      DC_MOTOR_CONTROL_X.Internal_CSTATE_p[i] =
        DC_MOTOR_CONTROL_P.Internal_InitialCondition_a;
    }

    for (i = 0; i < 11; i++) {
      /* InitializeConditions for StateSpace: '<S60>/Internal' */
      DC_MOTOR_CONTROL_X.Internal_CSTATE_j[i] =
        DC_MOTOR_CONTROL_P.Internal_InitialCondition_h;

      /* InitializeConditions for StateSpace: '<S38>/Internal' */
      DC_MOTOR_CONTROL_X.Internal_CSTATE_o[i] =
        DC_MOTOR_CONTROL_P.Internal_InitialCondition_kz;
    }

    /* InitializeConditions for TransferFcn: '<S26>/Transfer Fcn1' */
    DC_MOTOR_CONTROL_X.TransferFcn1_CSTATE_od = 0.0;

    /* InitializeConditions for MATLABSystem: '<Root>/Encoder' */
    MW_EncoderReset(DC_MOTOR_CONTROL_DW.obj.Index);
  }
}

/* Model terminate function */
void DC_MOTOR_CONTROL_terminate(void)
{
  codertarget_arduinobase_int_p_T *obj;

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!DC_MOTOR_CONTROL_DW.obj.matlabCodegenIsDeleted) {
    DC_MOTOR_CONTROL_DW.obj.matlabCodegenIsDeleted = true;
    if ((DC_MOTOR_CONTROL_DW.obj.isInitialized == 1) &&
        DC_MOTOR_CONTROL_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */
  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!DC_MOTOR_CONTROL_DW.obj_n.matlabCodegenIsDeleted) {
    DC_MOTOR_CONTROL_DW.obj_n.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  if (!DC_MOTOR_CONTROL_DW.obj_h.matlabCodegenIsDeleted) {
    DC_MOTOR_CONTROL_DW.obj_h.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output3' */
  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj = &DC_MOTOR_CONTROL_DW.obj_e;
  if (!DC_MOTOR_CONTROL_DW.obj_e.matlabCodegenIsDeleted) {
    DC_MOTOR_CONTROL_DW.obj_e.matlabCodegenIsDeleted = true;
    if ((DC_MOTOR_CONTROL_DW.obj_e.isInitialized == 1) &&
        DC_MOTOR_CONTROL_DW.obj_e.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8U);
      MW_PWM_SetDutyCycle(DC_MOTOR_CONTROL_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE,
                          0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8U);
      MW_PWM_Close(DC_MOTOR_CONTROL_DW.obj_e.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */
}
