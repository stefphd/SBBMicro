//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xswap_PQB3sQhy.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 1.140
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Wed Feb 23 12:14:32 2022
//
#include "rtwtypes.h"
#include "xswap_PQB3sQhy.h"

// Function for MATLAB Function: '<S11>/Predict'
void xswap_PQB3sQhy(real32_T x[4], int32_T ix0, int32_T iy0)
{
  real32_T temp;
  temp = x[ix0 - 1];
  x[ix0 - 1] = x[iy0 - 1];
  x[iy0 - 1] = temp;
  temp = x[ix0];
  x[ix0] = x[iy0];
  x[iy0] = temp;
}

//
// File trailer for generated code.
//
// [EOF]
//
