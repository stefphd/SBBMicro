//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xscal_u81h4dmT.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 3.0
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Apr  4 21:26:13 2022
//
#include "rtwtypes.h"
#include "xscal_u81h4dmT.h"

// Function for MATLAB Function: '<S62>/Predict'
void xscal_u81h4dmT(real32_T a, real32_T x[4], int32_T ix0)
{
  for (int32_T k = ix0; k <= (ix0 + 1); k++) {
    x[k - 1] *= a;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
