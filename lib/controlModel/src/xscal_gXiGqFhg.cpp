//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xscal_gXiGqFhg.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 1.136
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Feb 21 08:54:05 2022
//
#include "rtwtypes.h"
#include "xscal_gXiGqFhg.h"

// Function for MATLAB Function: '<S11>/Predict'
void xscal_gXiGqFhg(real32_T a, real32_T x[4], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= (ix0 + 1); k++) {
    x[k - 1] *= a;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
