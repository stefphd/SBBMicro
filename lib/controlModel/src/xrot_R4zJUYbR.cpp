//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xrot_R4zJUYbR.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 1.136
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Feb 21 08:54:05 2022
//
#include "rtwtypes.h"
#include "xrot_R4zJUYbR.h"

// Function for MATLAB Function: '<S11>/Predict'
void xrot_R4zJUYbR(real32_T x[4], int32_T ix0, int32_T iy0, real32_T c, real32_T
                   s)
{
  real32_T temp;
  real32_T temp_tmp;
  temp = x[iy0 - 1];
  temp_tmp = x[ix0 - 1];
  x[iy0 - 1] = (temp * c) - (temp_tmp * s);
  x[ix0 - 1] = (temp_tmp * c) + (temp * s);
  temp = (x[ix0] * c) + (x[iy0] * s);
  x[iy0] = (x[iy0] * c) - (x[ix0] * s);
  x[ix0] = temp;
}

//
// File trailer for generated code.
//
// [EOF]
//
