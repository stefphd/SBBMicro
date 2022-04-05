//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xgerc_QRNcmuGi.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 3.0
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Apr  4 21:26:13 2022
//
#include "rtwtypes.h"
#include "xgerc_QRNcmuGi.h"

// Function for MATLAB Function: '<S62>/Predict'
void xgerc_QRNcmuGi(int32_T m, int32_T n, real32_T alpha1, int32_T ix0, const
                    real32_T y[2], real32_T A[8], int32_T ia0)
{
  if (static_cast<boolean_T>(static_cast<int32_T>(((alpha1 == 0.0F) ? (
          static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) ^ 1))) {
    int32_T jA;
    int32_T jy;
    jA = ia0 - 1;
    jy = 0;
    for (int32_T j = 0; j < n; j++) {
      if (y[jy] != 0.0F) {
        int32_T b;
        int32_T ijA;
        int32_T ix;
        real32_T temp;
        temp = y[jy] * alpha1;
        ix = ix0;
        ijA = jA;
        b = m + jA;
        while ((ijA + 1) <= b) {
          A[ijA] += A[ix - 1] * temp;
          ix++;
          ijA++;
        }
      }

      jy++;
      jA += 4;
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
