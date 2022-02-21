//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xgerc_UV7q7Hce.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 1.136
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Feb 21 08:54:05 2022
//
#include "rtwtypes.h"
#include "xgerc_UV7q7Hce.h"

// Function for MATLAB Function: '<S9>/Correct'
void xgerc_UV7q7Hce(int32_T m, int32_T n, real32_T alpha1, int32_T ix0, const
                    real32_T y[2], real32_T A[6], int32_T ia0)
{
  int32_T b;
  int32_T ijA;
  int32_T ix;
  int32_T j;
  int32_T jA;
  int32_T jy;
  real32_T temp;
  if (static_cast<boolean_T>(static_cast<int32_T>(((alpha1 == 0.0F) ? (
          static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) ^ 1))) {
    jA = ia0 - 1;
    jy = 0;
    for (j = 0; j < n; j++) {
      if (y[jy] != 0.0F) {
        temp = y[jy] * alpha1;
        ix = ix0;
        b = m + jA;
        for (ijA = jA; ijA < b; ijA++) {
          A[ijA] += A[ix - 1] * temp;
          ix++;
        }
      }

      jy++;
      jA += 3;
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
