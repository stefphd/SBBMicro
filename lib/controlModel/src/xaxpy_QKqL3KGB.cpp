//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xaxpy_QKqL3KGB.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 1.136
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Feb 21 08:54:05 2022
//
#include "rtwtypes.h"
#include "xaxpy_QKqL3KGB.h"

// Function for MATLAB Function: '<S11>/Predict'
void xaxpy_QKqL3KGB(real32_T a, real32_T y[4])
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
