/*
 * PID_MOTOR_data.c
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

/* Block parameters (default storage) */
P_PID_MOTOR_T PID_MOTOR_P = {
  /* Variable: kd_fracc
   * Referenced by:
   *   '<S1>/Gain1'
   *   '<S1>/Gain4'
   */
  96.8263,

  /* Variable: ki_fracc
   * Referenced by:
   *   '<S1>/Gain2'
   *   '<S1>/Gain5'
   */
  93.9023,

  /* Variable: kp_fracc
   * Referenced by: '<S1>/Gain3'
   */
  99.6155,

  /* Mask Parameter: SliderGain_gain
   * Referenced by: '<S5>/Slider Gain'
   */
  40.0,

  /* Expression: -1
   * Referenced by: '<Root>/Encoder'
   */
  -1.0,

  /* Expression: 255
   * Referenced by: '<Root>/Constant8'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant9'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<Root>/Constant2'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<Root>/Constant3'
   */
  0.0,

  /* Expression: 255
   * Referenced by: '<S4>/Constant1'
   */
  255.0,

  /* Expression: 50
   * Referenced by: '<S4>/Constant7'
   */
  50.0,

  /* Expression: 225
   * Referenced by: '<S4>/Constant4'
   */
  225.0,

  /* Expression: 100
   * Referenced by: '<S4>/Constant6'
   */
  100.0,

  /* Expression: 200
   * Referenced by: '<S4>/Constant5'
   */
  200.0,

  /* Expression: 255
   * Referenced by: '<Root>/Saturation'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Computed Parameter: ModeloSystemIdentification_A
   * Referenced by: '<S3>/Modelo (System Identification)'
   */
  { -6.5932276969828525, -10.853049706967658 },

  /* Computed Parameter: ModeloSystemIdentification_C
   * Referenced by: '<S3>/Modelo (System Identification)'
   */
  { 0.0, 2.5189928369871937 },

  /* Computed Parameter: ModeloSystemIdentification_A_f
   * Referenced by: '<S1>/Modelo (System Identification)'
   */
  { -6.5932276969828525, -10.853049706967658 },

  /* Computed Parameter: ModeloSystemIdentification_C_b
   * Referenced by: '<S1>/Modelo (System Identification)'
   */
  { 0.0, 2.5189928369871937 },

  /* Expression: 1
   * Referenced by: '<Root>/Constant'
   */
  1.0,

  /* Expression: 100
   * Referenced by: '<S2>/nº medidas'
   */
  100.0,

  /* Expression: 10
   * Referenced by: '<S2>/tiempo de muestreo (ms)'
   */
  10.0,

  /* Expression: 1000
   * Referenced by: '<S2>/ms//s'
   */
  1000.0,

  /* Expression: 1/52
   * Referenced by: '<S2>/rev//pulso'
   */
  0.019230769230769232,

  /* Expression: 60/128
   * Referenced by: '<S2>/Gain'
   */
  0.46875,

  /* Computed Parameter: ModeloSystemIdentification_A_k
   * Referenced by: '<Root>/Modelo (System Identification)'
   */
  { -6.5932276969828525, -10.853049706967658 },

  /* Computed Parameter: ModeloSystemIdentification_C_k
   * Referenced by: '<Root>/Modelo (System Identification)'
   */
  { 0.0, 2.5189928369871937 },

  /* Computed Parameter: Internal_A_pr
   * Referenced by: '<S10>/Internal'
   */
  -1000.0,

  /* Computed Parameter: Internal_B_pr
   * Referenced by: '<S10>/Internal'
   */
  1011.9288512538814,

  /* Computed Parameter: Internal_C_pr
   * Referenced by: '<S10>/Internal'
   */
  -988.21176880261851,

  /* Computed Parameter: Internal_D_pr
   * Referenced by: '<S10>/Internal'
   */
  1000.0,

  /* Expression: 0.0
   * Referenced by: '<S10>/Internal'
   */
  0.0,

  /* Computed Parameter: Internal_A_pr_o
   * Referenced by: '<S18>/Internal'
   */
  { -0.001331117409762668, 0.0024484426974751249, -0.0046738084464285805,
    0.0045879345854041463, 0.008596951761074053, -0.016410637584404749,
    0.0085969517610740929, 0.016109117993390955, 0.030185545962929553,
    -0.057620895039562331, 0.016109117993390806, 0.030185545962929512,
    0.056562201943890007, 0.10598723947780944, -0.20231801038098918,
    0.030185545962929338, 0.056562201943890125, 0.10598723947780836,
    0.19860073593439484, 0.3721415191867613, -0.71037732573257839,
    0.056562201943890167, 0.10598723947780926, 0.19860073593439409,
    0.372141519186765, 0.6973252624218883, 1.306660226126821,
    -2.4942709942860812, 0.10598723947780889, 0.19860073593439492,
    0.37214151918676197, 0.69732526242189219, 1.3066602261268236,
    2.4484426974751266, 4.587934585404188, -8.75786369802985, 0.198600735934394,
    0.37214151918676319, 0.69732526242188586, 1.3066602261268299,
    2.4484426974751292, 4.587934585404164, 8.5969517610740933,
    16.109117993390896, -30.750538625905051, 0.37214151918676197,
    0.697325262421889, 1.3066602261268196, 2.4484426974751439,
    4.5879345854041755, 8.5969517610740578, 16.109117993390903,
    30.185545962929581, 56.562201943890322, -107.97103704594124,
    0.69732526242188586, 1.3066602261268239, 2.4484426974751217,
    4.5879345854041969, 8.5969517610740684, 16.109117993390818,
    30.185545962929556, 56.562201943890329, 105.98723947780908,
    198.60073593439463, -379.10701281034483 },

  /* Computed Parameter: Internal_B_pr_b
   * Referenced by: '<S18>/Internal'
   */
  { 0.0045184694348010691, 0.008466786751592386, 0.015865212530777221,
    0.029728511657553486, 0.055705803099631447, 0.10438250440251917,
    0.19559375539124202, 0.36650698665480147, 0.68676717719382463,
    1.2868763020744336, 2.4113712358932142 },

  /* Computed Parameter: Internal_C_pr_g
   * Referenced by: '<S18>/Internal'
   */
  { 0.0067228175142779395, 0.012597332588964987, 0.023605101286769403,
    0.044231650059532938, 0.0828820365234159, 0.15530580407972708,
    0.29101472155593522, 0.54530845556037477, 1.0218084848621167,
    1.9146825417612059, 3.5877655059987497 },

  /* Computed Parameter: Internal_D_pr_e
   * Referenced by: '<S18>/Internal'
   */
  0.0232477003941972,

  /* Expression: 0.0
   * Referenced by: '<S18>/Internal'
   */
  0.0,

  /* Expression: 5
   * Referenced by: '<S3>/Gain1'
   */
  5.0,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator2'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S3>/Saturation'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S3>/Saturation'
   */
  -0.5,

  /* Expression: 0
   * Referenced by: '<S3>/1//Tt'
   */
  0.0,

  /* Expression: 3/0.5
   * Referenced by: '<S3>/Gain2'
   */
  6.0,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S9>/Transfer Fcn1'
   */
  -1000.0,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S9>/Transfer Fcn1'
   */
  1000.0,

  /* Computed Parameter: TransferFcn1_A_a
   * Referenced by: '<S7>/Transfer Fcn1'
   */
  -1000.0,

  /* Computed Parameter: TransferFcn1_C_k
   * Referenced by: '<S7>/Transfer Fcn1'
   */
  1000.0,

  /* Computed Parameter: Internal_A_pr_j
   * Referenced by: '<S14>/Internal'
   */
  -1000.0,

  /* Computed Parameter: Internal_B_pr_f
   * Referenced by: '<S14>/Internal'
   */
  1011.9288512538814,

  /* Computed Parameter: Internal_C_pr_o
   * Referenced by: '<S14>/Internal'
   */
  -988.21176880261851,

  /* Computed Parameter: Internal_D_pr_k
   * Referenced by: '<S14>/Internal'
   */
  1000.0,

  /* Expression: 0.0
   * Referenced by: '<S14>/Internal'
   */
  0.0,

  /* Computed Parameter: Internal_A_pr_l
   * Referenced by: '<S22>/Internal'
   */
  { -0.001331117409762668, 0.0024484426974751249, -0.0046738084464285805,
    0.0045879345854041463, 0.008596951761074053, -0.016410637584404749,
    0.0085969517610740929, 0.016109117993390955, 0.030185545962929553,
    -0.057620895039562331, 0.016109117993390806, 0.030185545962929512,
    0.056562201943890007, 0.10598723947780944, -0.20231801038098918,
    0.030185545962929338, 0.056562201943890125, 0.10598723947780836,
    0.19860073593439484, 0.3721415191867613, -0.71037732573257839,
    0.056562201943890167, 0.10598723947780926, 0.19860073593439409,
    0.372141519186765, 0.6973252624218883, 1.306660226126821,
    -2.4942709942860812, 0.10598723947780889, 0.19860073593439492,
    0.37214151918676197, 0.69732526242189219, 1.3066602261268236,
    2.4484426974751266, 4.587934585404188, -8.75786369802985, 0.198600735934394,
    0.37214151918676319, 0.69732526242188586, 1.3066602261268299,
    2.4484426974751292, 4.587934585404164, 8.5969517610740933,
    16.109117993390896, -30.750538625905051, 0.37214151918676197,
    0.697325262421889, 1.3066602261268196, 2.4484426974751439,
    4.5879345854041755, 8.5969517610740578, 16.109117993390903,
    30.185545962929581, 56.562201943890322, -107.97103704594124,
    0.69732526242188586, 1.3066602261268239, 2.4484426974751217,
    4.5879345854041969, 8.5969517610740684, 16.109117993390818,
    30.185545962929556, 56.562201943890329, 105.98723947780908,
    198.60073593439463, -379.10701281034483 },

  /* Computed Parameter: Internal_B_pr_e
   * Referenced by: '<S22>/Internal'
   */
  { 0.0045184694348010691, 0.008466786751592386, 0.015865212530777221,
    0.029728511657553486, 0.055705803099631447, 0.10438250440251917,
    0.19559375539124202, 0.36650698665480147, 0.68676717719382463,
    1.2868763020744336, 2.4113712358932142 },

  /* Computed Parameter: Internal_C_pr_j
   * Referenced by: '<S22>/Internal'
   */
  { 0.0067228175142779395, 0.012597332588964987, 0.023605101286769403,
    0.044231650059532938, 0.0828820365234159, 0.15530580407972708,
    0.29101472155593522, 0.54530845556037477, 1.0218084848621167,
    1.9146825417612059, 3.5877655059987497 },

  /* Computed Parameter: Internal_D_pr_p
   * Referenced by: '<S22>/Internal'
   */
  0.0232477003941972,

  /* Expression: 0.0
   * Referenced by: '<S22>/Internal'
   */
  0.0,

  /* Expression: 1.5
   * Referenced by: '<S3>/Gain3'
   */
  1.5,

  /* Expression: 0
   * Referenced by: '<S3>/Integrator1'
   */
  0.0,

  /* Expression: 1/0.5
   * Referenced by: '<S3>/Gain4'
   */
  2.0,

  /* Computed Parameter: TransferFcn1_A_h
   * Referenced by: '<S6>/Transfer Fcn1'
   */
  -1000.0,

  /* Computed Parameter: TransferFcn1_C_f
   * Referenced by: '<S6>/Transfer Fcn1'
   */
  1000.0,

  /* Computed Parameter: TransferFcn1_A_k
   * Referenced by: '<S8>/Transfer Fcn1'
   */
  -1000.0,

  /* Computed Parameter: TransferFcn1_C_h
   * Referenced by: '<S8>/Transfer Fcn1'
   */
  1000.0,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S2>/Delay'
   */
  { { 0UL, 0UL } },

  /* Computed Parameter: Gain_Gain_o
   * Referenced by: '<Root>/Gain'
   */
  MIN_int32_T,

  /* Computed Parameter: Internal_A_ir
   * Referenced by: '<S10>/Internal'
   */
  0U,

  /* Computed Parameter: Internal_A_jc
   * Referenced by: '<S10>/Internal'
   */
  { 0U, 1U },

  /* Computed Parameter: Internal_B_ir
   * Referenced by: '<S10>/Internal'
   */
  0U,

  /* Computed Parameter: Internal_B_jc
   * Referenced by: '<S10>/Internal'
   */
  { 0U, 1U },

  /* Computed Parameter: Internal_C_ir
   * Referenced by: '<S10>/Internal'
   */
  0U,

  /* Computed Parameter: Internal_C_jc
   * Referenced by: '<S10>/Internal'
   */
  { 0U, 1U },

  /* Computed Parameter: Internal_D_ir
   * Referenced by: '<S10>/Internal'
   */
  0U,

  /* Computed Parameter: Internal_D_jc
   * Referenced by: '<S10>/Internal'
   */
  { 0U, 1U },

  /* Computed Parameter: Internal_A_ir_d
   * Referenced by: '<S18>/Internal'
   */
  { 0U, 0U, 1U, 0U, 1U, 2U, 0U, 1U, 2U, 3U, 0U, 1U, 2U, 3U, 4U, 0U, 1U, 2U, 3U,
    4U, 5U, 0U, 1U, 2U, 3U, 4U, 5U, 6U, 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 0U, 1U,
    2U, 3U, 4U, 5U, 6U, 7U, 8U, 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 0U, 1U,
    2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U },

  /* Computed Parameter: Internal_A_jc_e
   * Referenced by: '<S18>/Internal'
   */
  { 0U, 1U, 3U, 6U, 10U, 15U, 21U, 28U, 36U, 45U, 55U, 66U },

  /* Computed Parameter: Internal_B_ir_e
   * Referenced by: '<S18>/Internal'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U },

  /* Computed Parameter: Internal_B_jc_g
   * Referenced by: '<S18>/Internal'
   */
  { 0U, 11U },

  /* Computed Parameter: Internal_C_ir_n
   * Referenced by: '<S18>/Internal'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Internal_C_jc_n
   * Referenced by: '<S18>/Internal'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U },

  /* Computed Parameter: Internal_D_ir_i
   * Referenced by: '<S18>/Internal'
   */
  0U,

  /* Computed Parameter: Internal_D_jc_a
   * Referenced by: '<S18>/Internal'
   */
  { 0U, 1U },

  /* Computed Parameter: Internal_A_ir_g
   * Referenced by: '<S14>/Internal'
   */
  0U,

  /* Computed Parameter: Internal_A_jc_d
   * Referenced by: '<S14>/Internal'
   */
  { 0U, 1U },

  /* Computed Parameter: Internal_B_ir_h
   * Referenced by: '<S14>/Internal'
   */
  0U,

  /* Computed Parameter: Internal_B_jc_e
   * Referenced by: '<S14>/Internal'
   */
  { 0U, 1U },

  /* Computed Parameter: Internal_C_ir_d
   * Referenced by: '<S14>/Internal'
   */
  0U,

  /* Computed Parameter: Internal_C_jc_e
   * Referenced by: '<S14>/Internal'
   */
  { 0U, 1U },

  /* Computed Parameter: Internal_D_ir_e
   * Referenced by: '<S14>/Internal'
   */
  0U,

  /* Computed Parameter: Internal_D_jc_m
   * Referenced by: '<S14>/Internal'
   */
  { 0U, 1U },

  /* Computed Parameter: Internal_A_ir_b
   * Referenced by: '<S22>/Internal'
   */
  { 0U, 0U, 1U, 0U, 1U, 2U, 0U, 1U, 2U, 3U, 0U, 1U, 2U, 3U, 4U, 0U, 1U, 2U, 3U,
    4U, 5U, 0U, 1U, 2U, 3U, 4U, 5U, 6U, 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 0U, 1U,
    2U, 3U, 4U, 5U, 6U, 7U, 8U, 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 0U, 1U,
    2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U },

  /* Computed Parameter: Internal_A_jc_e0
   * Referenced by: '<S22>/Internal'
   */
  { 0U, 1U, 3U, 6U, 10U, 15U, 21U, 28U, 36U, 45U, 55U, 66U },

  /* Computed Parameter: Internal_B_ir_n
   * Referenced by: '<S22>/Internal'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U },

  /* Computed Parameter: Internal_B_jc_c
   * Referenced by: '<S22>/Internal'
   */
  { 0U, 11U },

  /* Computed Parameter: Internal_C_ir_a
   * Referenced by: '<S22>/Internal'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Internal_C_jc_o
   * Referenced by: '<S22>/Internal'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U },

  /* Computed Parameter: Internal_D_ir_j
   * Referenced by: '<S22>/Internal'
   */
  0U,

  /* Computed Parameter: Internal_D_jc_mu
   * Referenced by: '<S22>/Internal'
   */
  { 0U, 1U },

  /* Computed Parameter: ManualSwitch3_CurrentSetting
   * Referenced by: '<Root>/Manual Switch3'
   */
  0U,

  /* Computed Parameter: ManualSwitch_CurrentSetting
   * Referenced by: '<Root>/Manual Switch'
   */
  0U,

  /* Computed Parameter: ManualSwitch1_CurrentSetting
   * Referenced by: '<Root>/Manual Switch1'
   */
  1U
};
