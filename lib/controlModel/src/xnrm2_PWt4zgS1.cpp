//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xnrm2_PWt4zgS1.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 1.140
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Wed Feb 23 12:14:32 2022
//
#include "rtwtypes.h"
#include <cmath>
#include "xnrm2_PWt4zgS1.h"

// Function for MATLAB Function: '<S11>/Predict'
real32_T xnrm2_PWt4zgS1(int32_T n, const real32_T x[8], int32_T ix0)
{
  int32_T k;
  int32_T kend;
  real32_T absxk;
  real32_T scale;
  real32_T t;
  real32_T y;
  y = 0.0F;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      scale = 1.29246971E-26F;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = std::abs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = ((y * t) * t) + 1.0F;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  return y;
}

//
// File trailer for generated code.
//
// [EOF]
//
