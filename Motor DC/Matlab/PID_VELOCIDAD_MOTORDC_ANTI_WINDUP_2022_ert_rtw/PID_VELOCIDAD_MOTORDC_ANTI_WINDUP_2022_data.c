/*
 * PID_VELOCIDAD_MOTORDC_ANTI_WINDUP_2022_data.c
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

/* Block parameters (default storage) */
P_PID_VELOCIDAD_MOTORDC_ANTI__T PID_VELOCIDAD_MOTORDC_ANTI_WI_P = {
  /* Variable: kd
   * Referenced by:
   *   '<S5>/Gain1'
   *   '<S17>/Gain1'
   */
  12.0,

  /* Variable: ki
   * Referenced by:
   *   '<S5>/Gain2'
   *   '<S6>/Gain2'
   *   '<S17>/Gain2'
   *   '<S18>/Gain2'
   *   '<S19>/Gain2'
   */
  7.2,

  /* Variable: kp
   * Referenced by:
   *   '<S5>/Gain3'
   *   '<S6>/Gain3'
   *   '<S17>/Gain3'
   *   '<S18>/Gain3'
   *   '<S19>/Gain3'
   */
  9.0,

  /* Mask Parameter: SliderGain_gain
   * Referenced by: '<S4>/Slider Gain'
   */
  55.0,

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

  /* Computed Parameter: ModeloSystemIdentification_A
   * Referenced by: '<S3>/Modelo (System Identification)'
   */
  -1.449,

  /* Computed Parameter: ModeloSystemIdentification_C
   * Referenced by: '<S3>/Modelo (System Identification)'
   */
  0.2875,

  /* Computed Parameter: ModeloSystemIdentification_A_f
   * Referenced by: '<S1>/Modelo (System Identification)'
   */
  -1.449,

  /* Computed Parameter: ModeloSystemIdentification_C_n
   * Referenced by: '<S1>/Modelo (System Identification)'
   */
  0.2875,

  /* Expression: 0
   * Referenced by: '<S6>/Gain1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S6>/Integrator'
   */
  0.0,

  /* Expression: 0.5
   * Referenced by: '<S1>/Saturation'
   */
  0.5,

  /* Expression: -0.5
   * Referenced by: '<S1>/Saturation'
   */
  -0.5,

  /* Expression: (1/ki)^0.5
   * Referenced by: '<S6>/Gain'
   */
  0.37267799624996495,

  /* Expression: 0
   * Referenced by: '<S19>/Gain1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S19>/Integrator'
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

  /* Expression: (1/ki)^0.5
   * Referenced by: '<S19>/Gain'
   */
  0.37267799624996495,

  /* Expression: 0
   * Referenced by: '<S17>/Integrator'
   */
  0.0,

  /* Computed Parameter: TransferFcn1_A
   * Referenced by: '<S7>/Transfer Fcn1'
   */
  -500.0,

  /* Computed Parameter: TransferFcn1_C
   * Referenced by: '<S7>/Transfer Fcn1'
   */
  500.0,

  /* Computed Parameter: TransferFcn1_A_j
   * Referenced by: '<S8>/Transfer Fcn1'
   */
  -500.0,

  /* Computed Parameter: TransferFcn1_C_h
   * Referenced by: '<S8>/Transfer Fcn1'
   */
  500.0,

  /* Expression: 255
   * Referenced by: '<Root>/Saturation'
   */
  255.0,

  /* Expression: 0
   * Referenced by: '<Root>/Saturation'
   */
  0.0,

  /* Expression: (kp/ki)^0.5
   * Referenced by: '<S17>/Gain'
   */
  1.1180339887498949,

  /* Expression: (kd/ki)^0.5
   * Referenced by: '<S5>/Gain'
   */
  1.2909944487358056,

  /* Computed Parameter: Internal_A_pr
   * Referenced by: '<S13>/Internal'
   */
  { -0.0010302727295166936, 0.0039393864767634235, -0.00339656857161106,
    0.00715274398519451, 0.012987237180082805, -0.01119769332055274,
    0.012987237180082734, 0.023580926413814252, 0.042815887846145304,
    -0.03691617968474261, 0.023580926413814006, 0.042815887846145782,
    0.077740807120274216, 0.1411539826857944, -0.121704022739657,
    0.042815887846145463, 0.077740807120275326, 0.14115398268579413,
    0.25629328490551984, 0.46535171475733622, -0.40122973930415951,
    0.077740807120274216, 0.14115398268579515, 0.25629328490551762,
    0.46535171475733439, 0.84493910368124681, 1.5341559218320657,
    -1.3227607442890768, 0.14115398268579449, 0.25629328490552195,
    0.46535171475733478, 0.84493910368125158, 1.53415592183207,
    2.785566891434001, 5.05775377602237, -4.3608332464752966,
    0.25629328490551834, 0.46535171475733833, 0.84493910368124447,
    1.5341559218320646, 2.7855668914339828, 5.0577537760223716,
    9.1833634789145542, 16.67423297386895, -14.376648751989563,
    0.46535171475733506, 0.8449391036812568, 1.5341559218320622,
    2.7855668914339926, 5.0577537760223734, 9.1833634789146217,
    16.674232973868914, 30.275404638532319, 54.97105188966168,
    -47.39645330514297, 0.84493910368124592, 1.5341559218320755,
    2.7855668914339717, 5.057753776022361, 9.18336347891457, 16.674232973868936,
    30.27540463853207, 54.97105188966173, 99.8109383486136, 181.22671972926875,
    -156.25503722456443 },

  /* Computed Parameter: Internal_B_pr
   * Referenced by: '<S13>/Internal'
   */
  { 0.0029112015020178773, 0.005285868537162711, 0.0095975514483622563,
    0.017426274065719633, 0.031640885641242469, 0.057450355732187534,
    0.10431261030989476, 0.18940040546289838, 0.34389431424387645,
    0.624408902822721, 1.1337392384096807 },

  /* Computed Parameter: Internal_C_pr
   * Referenced by: '<S13>/Internal'
   */
  { 0.0020337179782230759, 0.0036926217120663955, 0.0067046932044813774,
    0.012173711382166949, 0.022103807630936029, 0.040133883287321634,
    0.0728710914705031, 0.13231204003077321, 0.24023896971806821,
    0.43620189483720423, 0.79201177595316674 },

  /* Computed Parameter: Internal_D_pr
   * Referenced by: '<S13>/Internal'
   */
  0.0027288426606428377,

  /* Expression: 0.0
   * Referenced by: '<S13>/Internal'
   */
  0.0,

  /* Computed Parameter: Internal_A_pr_g
   * Referenced by: '<S9>/Internal'
   */
  { -0.0030146130063174346, -0.0034879919274122713, -0.0099384750265411863,
    -0.0063331469065972508, -0.0114990947729341, -0.032764831056653732,
    -0.011499094772934051, -0.020878906260515827, -0.037909829881693606,
    -0.10801799584988063, -0.020878906260515629, -0.037909829881693675,
    -0.06883287772486249, -0.1249798553744982, -0.35611010498573265,
    -0.037909829881693252, -0.0688328777248625, -0.12497985537449732,
    -0.22692592211335705, -0.41202939443875347, -1.1740118475183632,
    -0.068832877724861991, -0.12497985537449779, -0.2269259221133563,
    -0.4120293944387543, -0.7481217672292253, -1.3583646850355291,
    -3.8704428737530723, -0.12497985537449767, -0.22692592211335863,
    -0.41202939443875553, -0.74812176722923152, -1.3583646850355429,
    -2.4663827445971549, -4.4782111239055435, -12.759946222562922,
    -0.22692592211335613, -0.41202939443875569, -0.74812176722922652,
    -1.3583646850355406, -2.4663827445971553, -4.4782111239055276,
    -8.1310878914484341, -14.763616200568954, -42.066562642433965,
    -0.41202939443875347, -0.74812176722923085, -1.3583646850355389,
    -2.4663827445971651, -4.4782111239055533, -8.13108789144845,
    -14.76361620056889, -26.806297782974031, -48.672194607834783,
    -138.68363249217506, -0.74812176722922419, -1.3583646850355422,
    -2.4663827445971536, -4.478211123905556, -8.1310878914484679,
    -14.763616200568869, -26.806297782973822, -48.672194607834882,
    -88.374103247021338, -160.46085835336544, -457.20754711304789 },

  /* Computed Parameter: Internal_B_pr_f
   * Referenced by: '<S9>/Internal'
   */
  { 0.70127066573316055, 1.2732971405327644, 2.31192560492158,
    4.1977632969910168, 7.6218787750146948, 13.839045213116437,
    25.127554250600429, 45.624099993433511, 82.839677887117077,
    150.41200228451697, 273.10307099535243 },

  /* Computed Parameter: Internal_C_pr_h
   * Referenced by: '<S9>/Internal'
   */
  { -0.53922523829692626, -0.97907125960952357, -1.777699675966433,
    -3.22776928330176, -5.8606606543719861, -10.641201489645853,
    -19.321229434904989, -35.081556085511664, -63.697581022330034,
    -115.6556972047195, -209.99604822074008 },

  /* Computed Parameter: Internal_D_pr_l
   * Referenced by: '<S9>/Internal'
   */
  196.84505248725054,

  /* Expression: 0.0
   * Referenced by: '<S9>/Internal'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S18>/Gain1'
   */
  0.0,

  /* Expression: 0
   * Referenced by: '<S18>/Integrator'
   */
  0.0,

  /* Expression: (1/ki)^0.5
   * Referenced by: '<S18>/Gain'
   */
  0.37267799624996495,

  /* Computed Parameter: Delay_InitialCondition
   * Referenced by: '<S2>/Delay'
   */
  { { 0UL, 0UL } },

  /* Computed Parameter: Gain_Gain_n
   * Referenced by: '<Root>/Gain'
   */
  MIN_int32_T,

  /* Computed Parameter: Internal_A_ir
   * Referenced by: '<S13>/Internal'
   */
  { 0U, 0U, 1U, 0U, 1U, 2U, 0U, 1U, 2U, 3U, 0U, 1U, 2U, 3U, 4U, 0U, 1U, 2U, 3U,
    4U, 5U, 0U, 1U, 2U, 3U, 4U, 5U, 6U, 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 0U, 1U,
    2U, 3U, 4U, 5U, 6U, 7U, 8U, 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 0U, 1U,
    2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U },

  /* Computed Parameter: Internal_A_jc
   * Referenced by: '<S13>/Internal'
   */
  { 0U, 1U, 3U, 6U, 10U, 15U, 21U, 28U, 36U, 45U, 55U, 66U },

  /* Computed Parameter: Internal_B_ir
   * Referenced by: '<S13>/Internal'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U },

  /* Computed Parameter: Internal_B_jc
   * Referenced by: '<S13>/Internal'
   */
  { 0U, 11U },

  /* Computed Parameter: Internal_C_ir
   * Referenced by: '<S13>/Internal'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Internal_C_jc
   * Referenced by: '<S13>/Internal'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U },

  /* Computed Parameter: Internal_D_ir
   * Referenced by: '<S13>/Internal'
   */
  0U,

  /* Computed Parameter: Internal_D_jc
   * Referenced by: '<S13>/Internal'
   */
  { 0U, 1U },

  /* Computed Parameter: Internal_A_ir_g
   * Referenced by: '<S9>/Internal'
   */
  { 0U, 0U, 1U, 0U, 1U, 2U, 0U, 1U, 2U, 3U, 0U, 1U, 2U, 3U, 4U, 0U, 1U, 2U, 3U,
    4U, 5U, 0U, 1U, 2U, 3U, 4U, 5U, 6U, 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 0U, 1U,
    2U, 3U, 4U, 5U, 6U, 7U, 8U, 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 0U, 1U,
    2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U },

  /* Computed Parameter: Internal_A_jc_k
   * Referenced by: '<S9>/Internal'
   */
  { 0U, 1U, 3U, 6U, 10U, 15U, 21U, 28U, 36U, 45U, 55U, 66U },

  /* Computed Parameter: Internal_B_ir_g
   * Referenced by: '<S9>/Internal'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U },

  /* Computed Parameter: Internal_B_jc_g
   * Referenced by: '<S9>/Internal'
   */
  { 0U, 11U },

  /* Computed Parameter: Internal_C_ir_k
   * Referenced by: '<S9>/Internal'
   */
  { 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U },

  /* Computed Parameter: Internal_C_jc_o
   * Referenced by: '<S9>/Internal'
   */
  { 0U, 1U, 2U, 3U, 4U, 5U, 6U, 7U, 8U, 9U, 10U, 11U },

  /* Computed Parameter: Internal_D_ir_p
   * Referenced by: '<S9>/Internal'
   */
  0U,

  /* Computed Parameter: Internal_D_jc_a
   * Referenced by: '<S9>/Internal'
   */
  { 0U, 1U },

  /* Computed Parameter: ManualSwitch3_CurrentSetting
   * Referenced by: '<Root>/Manual Switch3'
   */
  0U,

  /* Computed Parameter: ManualSwitch2_CurrentSetting
   * Referenced by: '<Root>/Manual Switch2'
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
