//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xnrm2_36w0EM2n.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 3.2
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Apr  5 09:35:42 2022
//
#include "rtwtypes.h"
#include "xnrm2_36w0EM2n.h"
#include <cmath>

// Function for MATLAB Function: '<S60>/Correct'
real32_T xnrm2_36w0EM2n(int32_T n, const real32_T x[3], int32_T ix0)
{
  real32_T y;
  y = 0.0F;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      int32_T kend;
      real32_T scale;
      scale = 1.29246971E-26F;
      kend = (ix0 + n) - 1;
      for (int32_T k = ix0; k <= kend; k++) {
        real32_T absxk;
        absxk = std::abs(x[k - 1]);
        if (absxk > scale) {
          real32_T t;
          t = scale / absxk;
          y = ((y * t) * t) + 1.0F;
          scale = absxk;
        } else {
          real32_T t;
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
