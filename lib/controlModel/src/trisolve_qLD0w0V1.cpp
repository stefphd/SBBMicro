//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: trisolve_qLD0w0V1.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 3.2
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Apr  5 09:35:42 2022
//
#include "rtwtypes.h"
#include "trisolve_qLD0w0V1.h"

// Function for MATLAB Function: '<S60>/Correct'
void trisolve_qLD0w0V1(real32_T A, real32_T B[2])
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
