//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xgemv_iT7V1Got.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 1.136
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Feb 21 08:54:05 2022
//
#include "rtwtypes.h"
#include "xgemv_iT7V1Got.h"

// Function for MATLAB Function: '<S9>/Correct'
void xgemv_iT7V1Got(int32_T m, int32_T n, const real32_T A[6], int32_T ia0,
                    const real32_T x[6], int32_T ix0, real32_T y[2])
{
  int32_T b;
  int32_T b_iy;
  int32_T d;
  int32_T ia;
  int32_T iac;
  int32_T ix;
  real32_T c;
  if (static_cast<boolean_T>(static_cast<int32_T>(((m != 0) ?
         (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) & ((n != 0) ? (
          static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) {
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0F;
    }

    b_iy = 0;
    b = ((n - 1) * 3) + ia0;
    for (iac = ia0; iac <= b; iac += 3) {
      ix = ix0;
      c = 0.0F;
      d = (iac + m) - 1;
      for (ia = iac; ia <= d; ia++) {
        c += A[ia - 1] * x[ix - 1];
        ix++;
      }

      y[b_iy] += c;
      b_iy++;
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
