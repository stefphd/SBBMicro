//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rtGetInf.h
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 8.0
// Simulink Coder version         : 24.2 (R2024b) 21-Jun-2024
// C/C++ source code generated on : Thu Jul  3 09:15:31 2025
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
#ifndef rtGetInf_h_
#define rtGetInf_h_

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rtwtypes.h"
#ifdef __cplusplus

extern "C"
{

#endif

  extern real_T rtGetInf(void);
  extern real32_T rtGetInfF(void);
  extern real_T rtGetMinusInf(void);
  extern real32_T rtGetMinusInfF(void);

#ifdef __cplusplus

}                                      // extern "C"

#endif
#endif                                 // rtGetInf_h_

//
// File trailer for generated code.
//
// [EOF]
//
