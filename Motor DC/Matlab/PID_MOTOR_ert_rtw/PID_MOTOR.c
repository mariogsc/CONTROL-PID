/*
 * PID_MOTOR.c
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

#include "PID_MOTOR.h"
#include "rtwtypes.h"
#include "PID_MOTOR_types.h"
#include "PID_MOTOR_private.h"
#include "multiword_types.h"
#include <string.h>
#include <math.h>

/* Block signals (default storage) */
B_PID_MOTOR_T PID_MOTOR_B;

/* Continuous states */
X_PID_MOTOR_T PID_MOTOR_X;

/* Block states (default storage) */
DW_PID_MOTOR_T PID_MOTOR_DW;

/* Real-time model */
static RT_MODEL_PID_MOTOR_T PID_MOTOR_M_;
RT_MODEL_PID_MOTOR_T *const PID_MOTOR_M = &PID_MOTOR_M_;

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 * 0 - success
 * 1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

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
  int_T nXc = 36;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  PID_MOTOR_derivatives();

  /* f(:,2) = feval(odefile, t + hA(1), y + f*hB(:,1), args(:)(*)); */
  hB[0] = h * rt_ODE3_B[0][0];
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[0]);
  rtsiSetdX(si, f1);
  PID_MOTOR_step();
  PID_MOTOR_derivatives();

  /* f(:,3) = feval(odefile, t + hA(2), y + f*hB(:,2), args(:)(*)); */
  for (i = 0; i <= 1; i++) {
    hB[i] = h * rt_ODE3_B[1][i];
  }

  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (f0[i]*hB[0] + f1[i]*hB[1]);
  }

  rtsiSetT(si, t + h*rt_ODE3_A[1]);
  rtsiSetdX(si, f2);
  PID_MOTOR_step();
  PID_MOTOR_derivatives();

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
void PID_MOTOR_step(void)
{
  if (rtmIsMajorTimeStep(PID_MOTOR_M)) {
    /* set solver stop time */
    if (!(PID_MOTOR_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&PID_MOTOR_M->solverInfo,
                            ((PID_MOTOR_M->Timing.clockTickH0 + 1) *
        PID_MOTOR_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&PID_MOTOR_M->solverInfo,
                            ((PID_MOTOR_M->Timing.clockTick0 + 1) *
        PID_MOTOR_M->Timing.stepSize0 + PID_MOTOR_M->Timing.clockTickH0 *
        PID_MOTOR_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(PID_MOTOR_M)) {
    PID_MOTOR_M->Timing.t[0] = rtsiGetT(&PID_MOTOR_M->solverInfo);
  }

  {
    codertarget_arduinobase_int_b_T *obj;
    int64m_T tmp_0;
    real_T rtb_Sum;
    real_T rtb_Sum1_tmp;
    real_T rtb_Sum_p;
    real_T rtb_TransferFcn1_m;
    int32_T rtb_Encoder_0;
    uint32_T ri;
    uint32_T tmp;
    uint8_T tmp_1;

    /* Clock: '<S4>/Clock' */
    PID_MOTOR_B.Clock = PID_MOTOR_M->Timing.t[0];

    /* Switch: '<S4>/Switch1' incorporates:
     *  Constant: '<S4>/Constant6'
     *  RelationalOperator: '<S4>/GreaterThan'
     */
    if (PID_MOTOR_B.Clock > PID_MOTOR_P.Constant6_Value) {
      /* Switch: '<S4>/Switch' incorporates:
       *  Constant: '<S4>/Constant7'
       *  RelationalOperator: '<S4>/GreaterThan1'
       */
      if (PID_MOTOR_B.Clock > PID_MOTOR_P.Constant7_Value) {
        /* Switch: '<S4>/Switch1' incorporates:
         *  Constant: '<S4>/Constant1'
         */
        PID_MOTOR_B.Switch1 = PID_MOTOR_P.Constant1_Value;
      } else {
        /* Switch: '<S4>/Switch1' incorporates:
         *  Constant: '<S4>/Constant4'
         */
        PID_MOTOR_B.Switch1 = PID_MOTOR_P.Constant4_Value;
      }

      /* End of Switch: '<S4>/Switch' */
    } else {
      /* Switch: '<S4>/Switch1' incorporates:
       *  Constant: '<S4>/Constant5'
       */
      PID_MOTOR_B.Switch1 = PID_MOTOR_P.Constant5_Value;
    }

    /* End of Switch: '<S4>/Switch1' */

    /* MATLABSystem: '<Root>/PWM' */
    obj = &PID_MOTOR_DW.obj_n;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8U);

    /* Saturate: '<Root>/Saturation' */
    if (PID_MOTOR_B.Switch1 > PID_MOTOR_P.Saturation_UpperSat) {
      PID_MOTOR_B.Clock = PID_MOTOR_P.Saturation_UpperSat;
    } else if (PID_MOTOR_B.Switch1 < PID_MOTOR_P.Saturation_LowerSat) {
      PID_MOTOR_B.Clock = PID_MOTOR_P.Saturation_LowerSat;
    } else {
      PID_MOTOR_B.Clock = PID_MOTOR_B.Switch1;
    }

    /* End of Saturate: '<Root>/Saturation' */

    /* MATLABSystem: '<Root>/PWM' */
    if (!(PID_MOTOR_B.Clock <= 255.0)) {
      PID_MOTOR_B.Clock = 255.0;
    }

    if (!(PID_MOTOR_B.Clock >= 0.0)) {
      PID_MOTOR_B.Clock = 0.0;
    }

    MW_PWM_SetDutyCycle(PID_MOTOR_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE,
                        PID_MOTOR_B.Clock);
    if (rtmIsMajorTimeStep(PID_MOTOR_M)) {
      /* ToFile: '<Root>/To File' */
      {
        if (!(++PID_MOTOR_DW.ToFile_IWORK.Decimation % 1) &&
            (PID_MOTOR_DW.ToFile_IWORK.Count * (1 + 1)) + 1 < 100000000 ) {
          FILE *fp = (FILE *) PID_MOTOR_DW.ToFile_PWORK.FilePtr;
          if (fp != (NULL)) {
            real_T u[1 + 1];
            PID_MOTOR_DW.ToFile_IWORK.Decimation = 0;
            u[0] = (((PID_MOTOR_M->Timing.clockTick1+
                      PID_MOTOR_M->Timing.clockTickH1* 4294967296.0)) * 0.01);
            u[1] = PID_MOTOR_B.Switch1;
            if (fwrite(u, sizeof(real_T), 1 + 1, fp) != 1 + 1) {
              rtmSetErrorStatus(PID_MOTOR_M,
                                "Error writing to MAT-file input.mat");
              return;
            }

            if (((++PID_MOTOR_DW.ToFile_IWORK.Count) * (1 + 1))+1 >= 100000000)
            {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file input.mat.\n");
            }
          }
        }
      }
    }

    /* TransferFcn: '<S3>/Modelo (System Identification)' */
    rtb_Sum = PID_MOTOR_P.ModeloSystemIdentification_C[0] *
      PID_MOTOR_X.ModeloSystemIdentification_CSTA[0] +
      PID_MOTOR_P.ModeloSystemIdentification_C[1] *
      PID_MOTOR_X.ModeloSystemIdentification_CSTA[1];

    /* TransferFcn: '<S1>/Modelo (System Identification)' */
    rtb_Sum_p = PID_MOTOR_P.ModeloSystemIdentification_C_b[0] *
      PID_MOTOR_X.ModeloSystemIdentification_CS_i[0] +
      PID_MOTOR_P.ModeloSystemIdentification_C_b[1] *
      PID_MOTOR_X.ModeloSystemIdentification_CS_i[1];

    /* ManualSwitch: '<Root>/Manual Switch3' */
    if (PID_MOTOR_P.ManualSwitch3_CurrentSetting == 1) {
      /* ManualSwitch: '<Root>/Manual Switch3' */
      PID_MOTOR_B.ManualSwitch3 = rtb_Sum;
    } else {
      /* ManualSwitch: '<Root>/Manual Switch3' */
      PID_MOTOR_B.ManualSwitch3 = rtb_Sum_p;
    }

    /* End of ManualSwitch: '<Root>/Manual Switch3' */
    if (rtmIsMajorTimeStep(PID_MOTOR_M)) {
      /* Gain: '<S5>/Slider Gain' incorporates:
       *  Constant: '<Root>/Constant'
       */
      PID_MOTOR_B.SliderGain = PID_MOTOR_P.SliderGain_gain *
        PID_MOTOR_P.Constant_Value;
    }

    /* MATLABSystem: '<Root>/Encoder' */
    if (PID_MOTOR_DW.obj.SampleTime != PID_MOTOR_P.Encoder_SampleTime) {
      PID_MOTOR_DW.obj.SampleTime = PID_MOTOR_P.Encoder_SampleTime;
    }

    if (PID_MOTOR_DW.obj.TunablePropsChanged) {
      PID_MOTOR_DW.obj.TunablePropsChanged = false;
    }

    MW_EncoderRead(PID_MOTOR_DW.obj.Index, &rtb_Encoder_0);

    /* Gain: '<Root>/Gain' incorporates:
     *  MATLABSystem: '<Root>/Encoder'
     */
    ri = (uint32_T)PID_MOTOR_P.Gain_Gain_o;
    tmp = (uint32_T)rtb_Encoder_0;
    sMultiWordMul(&ri, 1, &tmp, 1, &PID_MOTOR_B.Gain.chunks[0U], 2);
    if (rtmIsMajorTimeStep(PID_MOTOR_M)) {
      /* Delay: '<S2>/Delay' */
      PID_MOTOR_B.Delay = PID_MOTOR_DW.Delay_DSTATE[0];

      /* Product: '<S2>/tiempo (ms)' incorporates:
       *  Constant: '<S2>/nº medidas'
       *  Constant: '<S2>/tiempo de muestreo (ms)'
       */
      PID_MOTOR_B.tiempoms = PID_MOTOR_P.nmedidas_Value *
        PID_MOTOR_P.tiempodemuestreoms_Value;
    }

    /* Sum: '<S2>/Add' incorporates:
     *  Delay: '<S2>/Delay'
     *  Gain: '<Root>/Gain'
     */
    MultiWordSub(&PID_MOTOR_B.Gain.chunks[0U], &PID_MOTOR_B.Delay.chunks[0U],
                 &tmp_0.chunks[0U], 2);

    /* Gain: '<S2>/Gain' incorporates:
     *  Gain: '<S2>/ms//s'
     *  Gain: '<S2>/rev//pulso'
     *  Product: '<S2>/Divide'
     */
    PID_MOTOR_B.Gain_c = sMultiWord2Double(&tmp_0.chunks[0U], 2, 0) *
      4.6566128730773926E-10 / PID_MOTOR_B.tiempoms * PID_MOTOR_P.mss_Gain *
      PID_MOTOR_P.revpulso_Gain * PID_MOTOR_P.Gain_Gain;
    if (rtmIsMajorTimeStep(PID_MOTOR_M)) {
    }

    /* TransferFcn: '<Root>/Modelo (System Identification)' */
    PID_MOTOR_B.modelo = 0.0;
    PID_MOTOR_B.modelo += PID_MOTOR_P.ModeloSystemIdentification_C_k[0] *
      PID_MOTOR_X.ModeloSystemIdentification_CS_f[0];
    PID_MOTOR_B.modelo += PID_MOTOR_P.ModeloSystemIdentification_C_k[1] *
      PID_MOTOR_X.ModeloSystemIdentification_CS_f[1];
    if (rtmIsMajorTimeStep(PID_MOTOR_M)) {
      /* ToFile: '<Root>/To File1' */
      {
        if (!(++PID_MOTOR_DW.ToFile1_IWORK.Decimation % 1) &&
            (PID_MOTOR_DW.ToFile1_IWORK.Count * (1 + 1)) + 1 < 100000000 ) {
          FILE *fp = (FILE *) PID_MOTOR_DW.ToFile1_PWORK.FilePtr;
          if (fp != (NULL)) {
            real_T u[1 + 1];
            PID_MOTOR_DW.ToFile1_IWORK.Decimation = 0;
            u[0] = (((PID_MOTOR_M->Timing.clockTick1+
                      PID_MOTOR_M->Timing.clockTickH1* 4294967296.0)) * 0.01);
            u[1] = PID_MOTOR_B.Gain_c;
            if (fwrite(u, sizeof(real_T), 1 + 1, fp) != 1 + 1) {
              rtmSetErrorStatus(PID_MOTOR_M,
                                "Error writing to MAT-file output.mat");
              return;
            }

            if (((++PID_MOTOR_DW.ToFile1_IWORK.Count) * (1 + 1))+1 >= 100000000)
            {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file output.mat.\n");
            }
          }
        }
      }
    }

    /* Sum: '<S1>/Sum1' incorporates:
     *  Sum: '<S3>/Sum1'
     */
    rtb_Sum1_tmp = PID_MOTOR_B.SliderGain - PID_MOTOR_B.Gain_c;

    /* Gain: '<S1>/Gain1' incorporates:
     *  Sum: '<S1>/Sum1'
     */
    PID_MOTOR_B.Gain1 = PID_MOTOR_P.kd_fracc * rtb_Sum1_tmp;

    /* StateSpace: '<S10>/Internal' */
    PID_MOTOR_B.Internal = 0.0;

    /* StateSpace: '<S10>/Internal' */
    for (ri = PID_MOTOR_P.Internal_C_jc[0U]; ri < PID_MOTOR_P.Internal_C_jc[1U];
         ri++) {
      /* StateSpace: '<S10>/Internal' */
      PID_MOTOR_B.Internal += PID_MOTOR_P.Internal_C_pr *
        PID_MOTOR_X.Internal_CSTATE;
    }

    for (ri = PID_MOTOR_P.Internal_D_jc[0U]; ri < PID_MOTOR_P.Internal_D_jc[1U];
         ri++) {
      /* StateSpace: '<S10>/Internal' */
      PID_MOTOR_B.Internal += PID_MOTOR_P.Internal_D_pr * PID_MOTOR_B.Gain1;
    }

    /* Gain: '<S1>/Gain2' incorporates:
     *  Sum: '<S1>/Sum1'
     */
    PID_MOTOR_B.Gain2 = PID_MOTOR_P.ki_fracc * rtb_Sum1_tmp;

    /* StateSpace: '<S18>/Internal' */
    PID_MOTOR_B.Internal_m = 0.0;

    /* StateSpace: '<S18>/Internal' */
    for (rtb_Encoder_0 = 0; rtb_Encoder_0 < 11; rtb_Encoder_0++) {
      for (ri = PID_MOTOR_P.Internal_C_jc_n[(uint32_T)rtb_Encoder_0]; ri <
           PID_MOTOR_P.Internal_C_jc_n[(uint32_T)rtb_Encoder_0 + 1U]; ri++) {
        /* StateSpace: '<S18>/Internal' */
        PID_MOTOR_B.Internal_m += PID_MOTOR_P.Internal_C_pr_g[ri] *
          PID_MOTOR_X.Internal_CSTATE_n[(uint32_T)rtb_Encoder_0];
      }
    }

    for (ri = PID_MOTOR_P.Internal_D_jc_a[0U]; ri < PID_MOTOR_P.Internal_D_jc_a
         [1U]; ri++) {
      /* StateSpace: '<S18>/Internal' */
      PID_MOTOR_B.Internal_m += PID_MOTOR_P.Internal_D_pr_e * PID_MOTOR_B.Gain2;
    }

    /* Sum: '<S3>/Add1' incorporates:
     *  Gain: '<S3>/Gain1'
     *  Integrator: '<S3>/Integrator2'
     */
    rtb_TransferFcn1_m = PID_MOTOR_P.Gain1_Gain * rtb_Sum1_tmp +
      PID_MOTOR_X.Integrator2_CSTATE;

    /* Saturate: '<S3>/Saturation' */
    if (rtb_TransferFcn1_m > PID_MOTOR_P.Saturation_UpperSat_p) {
      PID_MOTOR_B.Clock = PID_MOTOR_P.Saturation_UpperSat_p;
    } else if (rtb_TransferFcn1_m < PID_MOTOR_P.Saturation_LowerSat_f) {
      PID_MOTOR_B.Clock = PID_MOTOR_P.Saturation_LowerSat_f;
    } else {
      PID_MOTOR_B.Clock = rtb_TransferFcn1_m;
    }

    /* Sum: '<S3>/Sum3' incorporates:
     *  Gain: '<S3>/1//Tt'
     *  Gain: '<S3>/Gain2'
     *  Saturate: '<S3>/Saturation'
     *  Sum: '<S3>/Sum2'
     */
    PID_MOTOR_B.Sum3 = (PID_MOTOR_B.Clock - rtb_TransferFcn1_m) *
      PID_MOTOR_P.uTt_Gain + PID_MOTOR_P.Gain2_Gain * rtb_Sum1_tmp;

    /* Sum: '<S1>/Sum' */
    rtb_Sum_p = PID_MOTOR_B.SliderGain - rtb_Sum_p;

    /* Sum: '<S1>/Add2' incorporates:
     *  Gain: '<S1>/Gain3'
     *  TransferFcn: '<S7>/Transfer Fcn1'
     *  TransferFcn: '<S9>/Transfer Fcn1'
     */
    PID_MOTOR_B.Add2 = (PID_MOTOR_P.kp_fracc * rtb_Sum_p +
                        PID_MOTOR_P.TransferFcn1_C *
                        PID_MOTOR_X.TransferFcn1_CSTATE) +
      PID_MOTOR_P.TransferFcn1_C_k * PID_MOTOR_X.TransferFcn1_CSTATE_c;

    /* Gain: '<S1>/Gain4' */
    PID_MOTOR_B.Gain4 = PID_MOTOR_P.kd_fracc * rtb_Sum_p;

    /* StateSpace: '<S14>/Internal' */
    PID_MOTOR_B.Internal_p = 0.0;

    /* StateSpace: '<S14>/Internal' */
    for (ri = PID_MOTOR_P.Internal_C_jc_e[0U]; ri < PID_MOTOR_P.Internal_C_jc_e
         [1U]; ri++) {
      /* StateSpace: '<S14>/Internal' */
      PID_MOTOR_B.Internal_p += PID_MOTOR_P.Internal_C_pr_o *
        PID_MOTOR_X.Internal_CSTATE_k;
    }

    for (ri = PID_MOTOR_P.Internal_D_jc_m[0U]; ri < PID_MOTOR_P.Internal_D_jc_m
         [1U]; ri++) {
      /* StateSpace: '<S14>/Internal' */
      PID_MOTOR_B.Internal_p += PID_MOTOR_P.Internal_D_pr_k * PID_MOTOR_B.Gain4;
    }

    /* Gain: '<S1>/Gain5' */
    PID_MOTOR_B.Gain5 = PID_MOTOR_P.ki_fracc * rtb_Sum_p;

    /* StateSpace: '<S22>/Internal' */
    PID_MOTOR_B.Internal_j = 0.0;

    /* StateSpace: '<S22>/Internal' */
    for (rtb_Encoder_0 = 0; rtb_Encoder_0 < 11; rtb_Encoder_0++) {
      for (ri = PID_MOTOR_P.Internal_C_jc_o[(uint32_T)rtb_Encoder_0]; ri <
           PID_MOTOR_P.Internal_C_jc_o[(uint32_T)rtb_Encoder_0 + 1U]; ri++) {
        /* StateSpace: '<S22>/Internal' */
        PID_MOTOR_B.Internal_j += PID_MOTOR_P.Internal_C_pr_j[ri] *
          PID_MOTOR_X.Internal_CSTATE_j[(uint32_T)rtb_Encoder_0];
      }
    }

    for (ri = PID_MOTOR_P.Internal_D_jc_mu[0U]; ri <
         PID_MOTOR_P.Internal_D_jc_mu[1U]; ri++) {
      /* StateSpace: '<S22>/Internal' */
      PID_MOTOR_B.Internal_j += PID_MOTOR_P.Internal_D_pr_p * PID_MOTOR_B.Gain5;
    }

    /* Sum: '<S3>/Sum' */
    rtb_Sum = PID_MOTOR_B.SliderGain - rtb_Sum;

    /* Sum: '<S3>/Add2' incorporates:
     *  Gain: '<S3>/Gain3'
     *  Integrator: '<S3>/Integrator1'
     */
    PID_MOTOR_B.Add2_l = PID_MOTOR_P.Gain3_Gain * rtb_Sum +
      PID_MOTOR_X.Integrator1_CSTATE;

    /* Gain: '<S3>/Gain4' */
    PID_MOTOR_B.Gain4_p = PID_MOTOR_P.Gain4_Gain * rtb_Sum;
    if (rtmIsMajorTimeStep(PID_MOTOR_M)) {
      /* ManualSwitch: '<Root>/Manual Switch' incorporates:
       *  Constant: '<Root>/Constant2'
       *  Constant: '<Root>/Constant3'
       */
      if (PID_MOTOR_P.ManualSwitch_CurrentSetting == 1) {
        PID_MOTOR_B.Clock = PID_MOTOR_P.Constant2_Value;
      } else {
        PID_MOTOR_B.Clock = PID_MOTOR_P.Constant3_Value;
      }

      /* MATLABSystem: '<Root>/Digital Output1' incorporates:
       *  ManualSwitch: '<Root>/Manual Switch'
       */
      PID_MOTOR_B.Clock = rt_roundd_snf(PID_MOTOR_B.Clock);
      if (PID_MOTOR_B.Clock < 256.0) {
        if (PID_MOTOR_B.Clock >= 0.0) {
          tmp_1 = (uint8_T)PID_MOTOR_B.Clock;
        } else {
          tmp_1 = 0U;
        }
      } else {
        tmp_1 = MAX_uint8_T;
      }

      writeDigitalPin(5, tmp_1);

      /* End of MATLABSystem: '<Root>/Digital Output1' */

      /* ManualSwitch: '<Root>/Manual Switch1' incorporates:
       *  Constant: '<Root>/Constant8'
       *  Constant: '<Root>/Constant9'
       */
      if (PID_MOTOR_P.ManualSwitch1_CurrentSetting == 1) {
        PID_MOTOR_B.Clock = PID_MOTOR_P.Constant8_Value;
      } else {
        PID_MOTOR_B.Clock = PID_MOTOR_P.Constant9_Value;
      }

      /* MATLABSystem: '<Root>/Digital Output3' incorporates:
       *  ManualSwitch: '<Root>/Manual Switch1'
       */
      PID_MOTOR_B.Clock = rt_roundd_snf(PID_MOTOR_B.Clock);
      if (PID_MOTOR_B.Clock < 256.0) {
        if (PID_MOTOR_B.Clock >= 0.0) {
          tmp_1 = (uint8_T)PID_MOTOR_B.Clock;
        } else {
          tmp_1 = 0U;
        }
      } else {
        tmp_1 = MAX_uint8_T;
      }

      writeDigitalPin(4, tmp_1);

      /* End of MATLABSystem: '<Root>/Digital Output3' */
    }
  }

  if (rtmIsMajorTimeStep(PID_MOTOR_M)) {
    int_T idxDelay;
    if (rtmIsMajorTimeStep(PID_MOTOR_M)) {
      /* Update for Delay: '<S2>/Delay' incorporates:
       *  Gain: '<Root>/Gain'
       */
      for (idxDelay = 0; idxDelay < 99; idxDelay++) {
        PID_MOTOR_DW.Delay_DSTATE[idxDelay] = PID_MOTOR_DW.Delay_DSTATE[idxDelay
          + 1];
      }

      PID_MOTOR_DW.Delay_DSTATE[99] = PID_MOTOR_B.Gain;

      /* End of Update for Delay: '<S2>/Delay' */
    }
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(PID_MOTOR_M)) {
    rt_ertODEUpdateContinuousStates(&PID_MOTOR_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++PID_MOTOR_M->Timing.clockTick0)) {
      ++PID_MOTOR_M->Timing.clockTickH0;
    }

    PID_MOTOR_M->Timing.t[0] = rtsiGetSolverStopTime(&PID_MOTOR_M->solverInfo);

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
      PID_MOTOR_M->Timing.clockTick1++;
      if (!PID_MOTOR_M->Timing.clockTick1) {
        PID_MOTOR_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void PID_MOTOR_derivatives(void)
{
  XDot_PID_MOTOR_T *_rtXdot;
  int_T is;
  uint32_T ri;
  _rtXdot = ((XDot_PID_MOTOR_T *) PID_MOTOR_M->derivs);

  /* Derivatives for TransferFcn: '<S3>/Modelo (System Identification)' */
  _rtXdot->ModeloSystemIdentification_CSTA[0] =
    PID_MOTOR_P.ModeloSystemIdentification_A[0] *
    PID_MOTOR_X.ModeloSystemIdentification_CSTA[0];

  /* Derivatives for TransferFcn: '<S1>/Modelo (System Identification)' */
  _rtXdot->ModeloSystemIdentification_CS_i[0] =
    PID_MOTOR_P.ModeloSystemIdentification_A_f[0] *
    PID_MOTOR_X.ModeloSystemIdentification_CS_i[0];

  /* Derivatives for TransferFcn: '<Root>/Modelo (System Identification)' */
  _rtXdot->ModeloSystemIdentification_CS_f[0] =
    PID_MOTOR_P.ModeloSystemIdentification_A_k[0] *
    PID_MOTOR_X.ModeloSystemIdentification_CS_f[0];

  /* Derivatives for TransferFcn: '<S3>/Modelo (System Identification)' */
  _rtXdot->ModeloSystemIdentification_CSTA[0] +=
    PID_MOTOR_P.ModeloSystemIdentification_A[1] *
    PID_MOTOR_X.ModeloSystemIdentification_CSTA[1];

  /* Derivatives for TransferFcn: '<S1>/Modelo (System Identification)' */
  _rtXdot->ModeloSystemIdentification_CS_i[0] +=
    PID_MOTOR_P.ModeloSystemIdentification_A_f[1] *
    PID_MOTOR_X.ModeloSystemIdentification_CS_i[1];

  /* Derivatives for TransferFcn: '<Root>/Modelo (System Identification)' */
  _rtXdot->ModeloSystemIdentification_CS_f[0] +=
    PID_MOTOR_P.ModeloSystemIdentification_A_k[1] *
    PID_MOTOR_X.ModeloSystemIdentification_CS_f[1];

  /* Derivatives for TransferFcn: '<S3>/Modelo (System Identification)' */
  _rtXdot->ModeloSystemIdentification_CSTA[1] =
    PID_MOTOR_X.ModeloSystemIdentification_CSTA[0];
  _rtXdot->ModeloSystemIdentification_CSTA[0] += PID_MOTOR_B.Add2_l;

  /* Derivatives for TransferFcn: '<S1>/Modelo (System Identification)' */
  _rtXdot->ModeloSystemIdentification_CS_i[1] =
    PID_MOTOR_X.ModeloSystemIdentification_CS_i[0];
  _rtXdot->ModeloSystemIdentification_CS_i[0] += PID_MOTOR_B.Add2;

  /* Derivatives for TransferFcn: '<Root>/Modelo (System Identification)' */
  _rtXdot->ModeloSystemIdentification_CS_f[1] =
    PID_MOTOR_X.ModeloSystemIdentification_CS_f[0];
  _rtXdot->ModeloSystemIdentification_CS_f[0] += PID_MOTOR_B.Switch1;

  /* Derivatives for StateSpace: '<S10>/Internal' */
  _rtXdot->Internal_CSTATE = 0.0;
  for (ri = PID_MOTOR_P.Internal_A_jc[0U]; ri < PID_MOTOR_P.Internal_A_jc[1U];
       ri++) {
    _rtXdot->Internal_CSTATE += PID_MOTOR_P.Internal_A_pr *
      PID_MOTOR_X.Internal_CSTATE;
  }

  for (ri = PID_MOTOR_P.Internal_B_jc[0U]; ri < PID_MOTOR_P.Internal_B_jc[1U];
       ri++) {
    _rtXdot->Internal_CSTATE += PID_MOTOR_P.Internal_B_pr * PID_MOTOR_B.Gain1;
  }

  /* End of Derivatives for StateSpace: '<S10>/Internal' */

  /* Derivatives for StateSpace: '<S18>/Internal' */
  memset(&_rtXdot->Internal_CSTATE_n[0], 0, 11U * sizeof(real_T));
  for (is = 0; is < 11; is++) {
    for (ri = PID_MOTOR_P.Internal_A_jc_e[(uint32_T)is]; ri <
         PID_MOTOR_P.Internal_A_jc_e[(uint32_T)is + 1U]; ri++) {
      _rtXdot->Internal_CSTATE_n[PID_MOTOR_P.Internal_A_ir_d[ri]] +=
        PID_MOTOR_P.Internal_A_pr_o[ri] * PID_MOTOR_X.Internal_CSTATE_n
        [(uint32_T)is];
    }
  }

  for (ri = PID_MOTOR_P.Internal_B_jc_g[0U]; ri < PID_MOTOR_P.Internal_B_jc_g[1U];
       ri++) {
    _rtXdot->Internal_CSTATE_n[PID_MOTOR_P.Internal_B_ir_e[ri]] +=
      PID_MOTOR_P.Internal_B_pr_b[ri] * PID_MOTOR_B.Gain2;
  }

  /* End of Derivatives for StateSpace: '<S18>/Internal' */

  /* Derivatives for Integrator: '<S3>/Integrator2' */
  _rtXdot->Integrator2_CSTATE = PID_MOTOR_B.Sum3;

  /* Derivatives for TransferFcn: '<S9>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE = PID_MOTOR_P.TransferFcn1_A *
    PID_MOTOR_X.TransferFcn1_CSTATE;
  _rtXdot->TransferFcn1_CSTATE += PID_MOTOR_B.Internal_j;

  /* Derivatives for TransferFcn: '<S7>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_c = PID_MOTOR_P.TransferFcn1_A_a *
    PID_MOTOR_X.TransferFcn1_CSTATE_c;
  _rtXdot->TransferFcn1_CSTATE_c += PID_MOTOR_B.Internal_p;

  /* Derivatives for StateSpace: '<S14>/Internal' */
  _rtXdot->Internal_CSTATE_k = 0.0;
  for (ri = PID_MOTOR_P.Internal_A_jc_d[0U]; ri < PID_MOTOR_P.Internal_A_jc_d[1U];
       ri++) {
    _rtXdot->Internal_CSTATE_k += PID_MOTOR_P.Internal_A_pr_j *
      PID_MOTOR_X.Internal_CSTATE_k;
  }

  for (ri = PID_MOTOR_P.Internal_B_jc_e[0U]; ri < PID_MOTOR_P.Internal_B_jc_e[1U];
       ri++) {
    _rtXdot->Internal_CSTATE_k += PID_MOTOR_P.Internal_B_pr_f *
      PID_MOTOR_B.Gain4;
  }

  /* End of Derivatives for StateSpace: '<S14>/Internal' */

  /* Derivatives for StateSpace: '<S22>/Internal' */
  memset(&_rtXdot->Internal_CSTATE_j[0], 0, 11U * sizeof(real_T));
  for (is = 0; is < 11; is++) {
    for (ri = PID_MOTOR_P.Internal_A_jc_e0[(uint32_T)is]; ri <
         PID_MOTOR_P.Internal_A_jc_e0[(uint32_T)is + 1U]; ri++) {
      _rtXdot->Internal_CSTATE_j[PID_MOTOR_P.Internal_A_ir_b[ri]] +=
        PID_MOTOR_P.Internal_A_pr_l[ri] * PID_MOTOR_X.Internal_CSTATE_j
        [(uint32_T)is];
    }
  }

  for (ri = PID_MOTOR_P.Internal_B_jc_c[0U]; ri < PID_MOTOR_P.Internal_B_jc_c[1U];
       ri++) {
    _rtXdot->Internal_CSTATE_j[PID_MOTOR_P.Internal_B_ir_n[ri]] +=
      PID_MOTOR_P.Internal_B_pr_e[ri] * PID_MOTOR_B.Gain5;
  }

  /* End of Derivatives for StateSpace: '<S22>/Internal' */

  /* Derivatives for Integrator: '<S3>/Integrator1' */
  _rtXdot->Integrator1_CSTATE = PID_MOTOR_B.Gain4_p;

  /* Derivatives for TransferFcn: '<S6>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_g = PID_MOTOR_P.TransferFcn1_A_h *
    PID_MOTOR_X.TransferFcn1_CSTATE_g;
  _rtXdot->TransferFcn1_CSTATE_g += PID_MOTOR_B.Internal;

  /* Derivatives for TransferFcn: '<S8>/Transfer Fcn1' */
  _rtXdot->TransferFcn1_CSTATE_n = PID_MOTOR_P.TransferFcn1_A_k *
    PID_MOTOR_X.TransferFcn1_CSTATE_n;
  _rtXdot->TransferFcn1_CSTATE_n += PID_MOTOR_B.Internal_m;
}

/* Model initialize function */
void PID_MOTOR_initialize(void)
{
  /* Registration code */

  /* initialize real-time model */
  (void) memset((void *)PID_MOTOR_M, 0,
                sizeof(RT_MODEL_PID_MOTOR_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&PID_MOTOR_M->solverInfo,
                          &PID_MOTOR_M->Timing.simTimeStep);
    rtsiSetTPtr(&PID_MOTOR_M->solverInfo, &rtmGetTPtr(PID_MOTOR_M));
    rtsiSetStepSizePtr(&PID_MOTOR_M->solverInfo, &PID_MOTOR_M->Timing.stepSize0);
    rtsiSetdXPtr(&PID_MOTOR_M->solverInfo, &PID_MOTOR_M->derivs);
    rtsiSetContStatesPtr(&PID_MOTOR_M->solverInfo, (real_T **)
                         &PID_MOTOR_M->contStates);
    rtsiSetNumContStatesPtr(&PID_MOTOR_M->solverInfo,
      &PID_MOTOR_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&PID_MOTOR_M->solverInfo,
      &PID_MOTOR_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&PID_MOTOR_M->solverInfo,
      &PID_MOTOR_M->periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&PID_MOTOR_M->solverInfo,
      &PID_MOTOR_M->periodicContStateRanges);
    rtsiSetErrorStatusPtr(&PID_MOTOR_M->solverInfo, (&rtmGetErrorStatus
      (PID_MOTOR_M)));
    rtsiSetRTModelPtr(&PID_MOTOR_M->solverInfo, PID_MOTOR_M);
  }

  rtsiSetSimTimeStep(&PID_MOTOR_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetIsMinorTimeStepWithModeChange(&PID_MOTOR_M->solverInfo, false);
  PID_MOTOR_M->intgData.y = PID_MOTOR_M->odeY;
  PID_MOTOR_M->intgData.f[0] = PID_MOTOR_M->odeF[0];
  PID_MOTOR_M->intgData.f[1] = PID_MOTOR_M->odeF[1];
  PID_MOTOR_M->intgData.f[2] = PID_MOTOR_M->odeF[2];
  PID_MOTOR_M->contStates = ((X_PID_MOTOR_T *) &PID_MOTOR_X);
  rtsiSetSolverData(&PID_MOTOR_M->solverInfo, (void *)&PID_MOTOR_M->intgData);
  rtsiSetSolverName(&PID_MOTOR_M->solverInfo,"ode3");
  rtmSetTPtr(PID_MOTOR_M, &PID_MOTOR_M->Timing.tArray[0]);
  PID_MOTOR_M->Timing.stepSize0 = 0.01;

  /* block I/O */
  (void) memset(((void *) &PID_MOTOR_B), 0,
                sizeof(B_PID_MOTOR_T));

  /* states (continuous) */
  {
    (void) memset((void *)&PID_MOTOR_X, 0,
                  sizeof(X_PID_MOTOR_T));
  }

  /* states (dwork) */
  (void) memset((void *)&PID_MOTOR_DW, 0,
                sizeof(DW_PID_MOTOR_T));

  {
    codertarget_arduinobase_int_b_T *obj;

    /* Start for MATLABSystem: '<Root>/PWM' */
    PID_MOTOR_DW.obj_n.matlabCodegenIsDeleted = false;
    PID_MOTOR_DW.objisempty = true;
    obj = &PID_MOTOR_DW.obj_n;
    PID_MOTOR_DW.obj_n.isInitialized = 1;
    obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_Open(8U, 0.0, 0.0);
    PID_MOTOR_DW.obj_n.isSetupComplete = true;

    /* Start for ToFile: '<Root>/To File' */
    {
      FILE *fp = (NULL);
      char fileName[509] = "input.mat";
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(PID_MOTOR_M, "Error creating .mat file input.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 1 + 1, 0, "ans")) {
        rtmSetErrorStatus(PID_MOTOR_M,
                          "Error writing mat file header to file input.mat");
        return;
      }

      PID_MOTOR_DW.ToFile_IWORK.Count = 0;
      PID_MOTOR_DW.ToFile_IWORK.Decimation = -1;
      PID_MOTOR_DW.ToFile_PWORK.FilePtr = fp;
    }

    /* Start for MATLABSystem: '<Root>/Encoder' */
    PID_MOTOR_DW.obj.Index = 0U;
    PID_MOTOR_DW.obj.matlabCodegenIsDeleted = false;
    PID_MOTOR_DW.objisempty_j = true;
    PID_MOTOR_DW.obj.SampleTime = PID_MOTOR_P.Encoder_SampleTime;
    PID_MOTOR_DW.obj.isInitialized = 1;
    MW_EncoderSetup(2U, 3U, &PID_MOTOR_DW.obj.Index);
    PID_MOTOR_DW.obj.isSetupComplete = true;
    PID_MOTOR_DW.obj.TunablePropsChanged = false;

    /* Start for ToFile: '<Root>/To File1' */
    {
      FILE *fp = (NULL);
      char fileName[509] = "output.mat";
      if ((fp = fopen(fileName, "wb")) == (NULL)) {
        rtmSetErrorStatus(PID_MOTOR_M, "Error creating .mat file output.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 1 + 1, 0, "ans")) {
        rtmSetErrorStatus(PID_MOTOR_M,
                          "Error writing mat file header to file output.mat");
        return;
      }

      PID_MOTOR_DW.ToFile1_IWORK.Count = 0;
      PID_MOTOR_DW.ToFile1_IWORK.Decimation = -1;
      PID_MOTOR_DW.ToFile1_PWORK.FilePtr = fp;
    }

    /* Start for MATLABSystem: '<Root>/Digital Output1' */
    PID_MOTOR_DW.obj_l.matlabCodegenIsDeleted = false;
    PID_MOTOR_DW.objisempty_b = true;
    PID_MOTOR_DW.obj_l.isInitialized = 1;
    digitalIOSetup(5, 1);
    PID_MOTOR_DW.obj_l.isSetupComplete = true;

    /* Start for MATLABSystem: '<Root>/Digital Output3' */
    PID_MOTOR_DW.obj_i.matlabCodegenIsDeleted = false;
    PID_MOTOR_DW.objisempty_h = true;
    PID_MOTOR_DW.obj_i.isInitialized = 1;
    digitalIOSetup(4, 1);
    PID_MOTOR_DW.obj_i.isSetupComplete = true;
  }

  {
    int32_T i;

    /* InitializeConditions for TransferFcn: '<S3>/Modelo (System Identification)' */
    PID_MOTOR_X.ModeloSystemIdentification_CSTA[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S1>/Modelo (System Identification)' */
    PID_MOTOR_X.ModeloSystemIdentification_CS_i[0] = 0.0;

    /* InitializeConditions for TransferFcn: '<S3>/Modelo (System Identification)' */
    PID_MOTOR_X.ModeloSystemIdentification_CSTA[1] = 0.0;

    /* InitializeConditions for TransferFcn: '<S1>/Modelo (System Identification)' */
    PID_MOTOR_X.ModeloSystemIdentification_CS_i[1] = 0.0;

    /* InitializeConditions for Delay: '<S2>/Delay' */
    for (i = 0; i < 100; i++) {
      PID_MOTOR_DW.Delay_DSTATE[i] = PID_MOTOR_P.Delay_InitialCondition;
    }

    /* End of InitializeConditions for Delay: '<S2>/Delay' */

    /* InitializeConditions for TransferFcn: '<Root>/Modelo (System Identification)' */
    PID_MOTOR_X.ModeloSystemIdentification_CS_f[0] = 0.0;
    PID_MOTOR_X.ModeloSystemIdentification_CS_f[1] = 0.0;

    /* InitializeConditions for StateSpace: '<S10>/Internal' */
    PID_MOTOR_X.Internal_CSTATE = PID_MOTOR_P.Internal_InitialCondition;

    /* InitializeConditions for Integrator: '<S3>/Integrator2' */
    PID_MOTOR_X.Integrator2_CSTATE = PID_MOTOR_P.Integrator2_IC;

    /* InitializeConditions for TransferFcn: '<S9>/Transfer Fcn1' */
    PID_MOTOR_X.TransferFcn1_CSTATE = 0.0;

    /* InitializeConditions for TransferFcn: '<S7>/Transfer Fcn1' */
    PID_MOTOR_X.TransferFcn1_CSTATE_c = 0.0;

    /* InitializeConditions for StateSpace: '<S14>/Internal' */
    PID_MOTOR_X.Internal_CSTATE_k = PID_MOTOR_P.Internal_InitialCondition_l;
    for (i = 0; i < 11; i++) {
      /* InitializeConditions for StateSpace: '<S18>/Internal' */
      PID_MOTOR_X.Internal_CSTATE_n[i] = PID_MOTOR_P.Internal_InitialCondition_h;

      /* InitializeConditions for StateSpace: '<S22>/Internal' */
      PID_MOTOR_X.Internal_CSTATE_j[i] = PID_MOTOR_P.Internal_InitialCondition_j;
    }

    /* InitializeConditions for Integrator: '<S3>/Integrator1' */
    PID_MOTOR_X.Integrator1_CSTATE = PID_MOTOR_P.Integrator1_IC;

    /* InitializeConditions for TransferFcn: '<S6>/Transfer Fcn1' */
    PID_MOTOR_X.TransferFcn1_CSTATE_g = 0.0;

    /* InitializeConditions for TransferFcn: '<S8>/Transfer Fcn1' */
    PID_MOTOR_X.TransferFcn1_CSTATE_n = 0.0;

    /* InitializeConditions for MATLABSystem: '<Root>/Encoder' */
    MW_EncoderReset(PID_MOTOR_DW.obj.Index);
  }
}

/* Model terminate function */
void PID_MOTOR_terminate(void)
{
  codertarget_arduinobase_int_b_T *obj;

  /* Terminate for MATLABSystem: '<Root>/PWM' */
  obj = &PID_MOTOR_DW.obj_n;
  if (!PID_MOTOR_DW.obj_n.matlabCodegenIsDeleted) {
    PID_MOTOR_DW.obj_n.matlabCodegenIsDeleted = true;
    if ((PID_MOTOR_DW.obj_n.isInitialized == 1) &&
        PID_MOTOR_DW.obj_n.isSetupComplete) {
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8U);
      MW_PWM_SetDutyCycle(PID_MOTOR_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE, 0.0);
      obj->PWMDriverObj.MW_PWM_HANDLE = MW_PWM_GetHandle(8U);
      MW_PWM_Close(PID_MOTOR_DW.obj_n.PWMDriverObj.MW_PWM_HANDLE);
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/PWM' */

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) PID_MOTOR_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "input.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(PID_MOTOR_M, "Error closing MAT-file input.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(PID_MOTOR_M, "Error reopening MAT-file input.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 1 + 1, PID_MOTOR_DW.ToFile_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(PID_MOTOR_M,
                          "Error writing header for ans to MAT-file input.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(PID_MOTOR_M, "Error closing MAT-file input.mat");
        return;
      }

      PID_MOTOR_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for MATLABSystem: '<Root>/Encoder' */
  if (!PID_MOTOR_DW.obj.matlabCodegenIsDeleted) {
    PID_MOTOR_DW.obj.matlabCodegenIsDeleted = true;
    if ((PID_MOTOR_DW.obj.isInitialized == 1) &&
        PID_MOTOR_DW.obj.isSetupComplete) {
      MW_EncoderRelease();
    }
  }

  /* End of Terminate for MATLABSystem: '<Root>/Encoder' */

  /* Terminate for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (FILE *) PID_MOTOR_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "output.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(PID_MOTOR_M, "Error closing MAT-file output.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(PID_MOTOR_M, "Error reopening MAT-file output.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 1 + 1, PID_MOTOR_DW.ToFile1_IWORK.Count,
           "ans")) {
        rtmSetErrorStatus(PID_MOTOR_M,
                          "Error writing header for ans to MAT-file output.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(PID_MOTOR_M, "Error closing MAT-file output.mat");
        return;
      }

      PID_MOTOR_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for MATLABSystem: '<Root>/Digital Output1' */
  if (!PID_MOTOR_DW.obj_l.matlabCodegenIsDeleted) {
    PID_MOTOR_DW.obj_l.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output1' */

  /* Terminate for MATLABSystem: '<Root>/Digital Output3' */
  if (!PID_MOTOR_DW.obj_i.matlabCodegenIsDeleted) {
    PID_MOTOR_DW.obj_i.matlabCodegenIsDeleted = true;
  }

  /* End of Terminate for MATLABSystem: '<Root>/Digital Output3' */
}
