//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: trisolve_OvFIvCwp.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 1.136
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Feb 21 08:54:05 2022
//
#include "rtwtypes.h"
#include "trisolve_OvFIvCwp.h"

// Function for MATLAB Function: '<S9>/Correct'
void trisolve_OvFIvCwp(real32_T A, real32_T B[2])
{
  if (B[0] != 0.0F) {
    B[0] /= A;
  }

  if (B[1] != 0.0F) {
    B[1] /= A;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
