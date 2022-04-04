//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xaxpy_hYt0bdta.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 3.0
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Apr  4 21:26:13 2022
//
#include "rtwtypes.h"
#include "xaxpy_hYt0bdta.h"

// Function for MATLAB Function: '<S62>/Predict'
void xaxpy_hYt0bdta(real32_T a, real32_T y[4])
{
  if (static_cast<boolean_T>(static_cast<int32_T>(((a == 0.0F) ? (static_cast<
          int32_T>(1)) : (static_cast<int32_T>(0))) ^ 1))) {
    y[2] += a * y[0];
    y[3] += a * y[1];
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
