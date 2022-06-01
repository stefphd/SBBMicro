//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xrot_kJoGnQw0.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 3.2
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Apr  5 09:35:42 2022
//
#include "rtwtypes.h"
#include "xrot_kJoGnQw0.h"

// Function for MATLAB Function: '<S62>/Predict'
void xrot_kJoGnQw0(real32_T x[4], int32_T ix0, int32_T iy0, real32_T c, real32_T
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
