//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controlModel_data.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 4.103
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Jan 22 10:43:19 2024
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
//    3. ROM efficiency
//    4. MISRA C:2012 guidelines
// Validation result: Not run
//
#include "controlModel.h"

// Invariant block signals (default storage)
const ControlClass::ConstB_controlModel_T controlModel_ConstB = {
  {
    0.00113212655F,
    -0.000141341283F
  }
  ,                                    // '<S51>/Conversion'

  {
    0.00113198522F,
    -0.000141341283F
  }
  ,                                    // '<S52>/Conversion'

  {
    0.00056599261F,
    -7.06706414E-5F,
    -7.06706414E-5F,
    8.00887865E-5F
  }
  ,                                    // '<S54>/Conversion'

  {
    0.270321041F,
    0.0178489387F,
    -0.0269543678F,
    4.96149187E-5F,
    0.0140111456F,
    9.4104922E-5F
  }
  ,                                    // '<S103>/Conversion'

  {
    0.270276219F,
    0.0178489387F,
    -0.0269543678F,
    3.5697878E-5F,
    0.0140111456F,
    9.4104922E-5F
  }
  ,                                    // '<S104>/Conversion'

  {
    2.70276232E-5F,
    1.78489381E-6F,
    -2.69543671E-6F,
    1.78489381E-6F,
    0.000700557255F,
    4.70524583E-6F,
    -2.69543671E-6F,
    4.70524583E-6F,
    0.00100281509F
  }
  ,                                    // '<S106>/Conversion'

  {
    0.0952455923F,
    0.00220547104F,
    -0.00950936228F,
    0.000251590565F,
    0.0311179552F,
    7.44899735E-5F
  }
  ,                                    // '<S155>/Conversion'

  {
    0.0952338725F,
    0.00220547104F,
    -0.00950936228F,
    0.000220547096F,
    0.0311179552F,
    7.44899735E-5F
  }
  ,                                    // '<S156>/Conversion'

  {
    9.52338742E-5F,
    2.20547099E-6F,
    -9.50936192E-6F,
    2.20547099E-6F,
    0.000311179552F,
    7.44899751E-7F,
    -9.50936192E-6F,
    7.44899751E-7F,
    0.00100149983F
  }
  // '<S158>/Conversion'
};

// Constant parameters (default storage)
const ControlClass::ConstP_controlModel_T controlModel_ConstP = {
  // Pooled Parameter (Expression: )
  //  Referenced by:
  //    '<S6>/A'
  //    '<S8>/A'

  { 1.0F, 0.0F, 0.0F, 0.001F, 1.0F, 0.0F, -0.001F, 0.0F, 1.0F },

  // Pooled Parameter (Expression: )
  //  Referenced by:
  //    '<S6>/C'
  //    '<S8>/C'

  { 1.0F, 0.0F, 0.0F, 1.0F, 0.0F, 0.0F },

  // Pooled Parameter (Mixed Expressions)
  //  Referenced by:
  //    '<Root>/Constant2'
  //    '<S4>/X0'
  //    '<S6>/D'
  //    '<S8>/D'

  { 0.0F, 0.0F }
};

//
// File trailer for generated code.
//
// [EOF]
//
