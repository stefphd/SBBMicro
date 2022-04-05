//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xgemv_ndIKoEsw.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 3.0
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Apr  4 21:26:13 2022
//
#include "rtwtypes.h"
#include "xgemv_ndIKoEsw.h"

// Function for MATLAB Function: '<S60>/Correct'
void xgemv_ndIKoEsw(int32_T m, int32_T n, const real32_T A[6], int32_T ia0,
                    const real32_T x[6], int32_T ix0, real32_T y[2])
{
  if (static_cast<boolean_T>(static_cast<int32_T>(((m != 0) ?
         (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) & ((n != 0) ? (
          static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) {
    int32_T b;
    int32_T b_iy;
    for (b_iy = 0; b_iy < n; b_iy++) {
      y[b_iy] = 0.0F;
    }

    b_iy = 0;
    b = ((n - 1) * 3) + ia0;
    for (int32_T iac = ia0; iac <= b; iac += 3) {
      int32_T d;
      int32_T ix;
      real32_T c;
      ix = ix0;
      c = 0.0F;
      d = (iac + m) - 1;
      for (int32_T ia = iac; ia <= d; ia++) {
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
