//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_hypotf_snf.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 3.0
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Apr  4 21:26:13 2022
//
#include "rtwtypes.h"
#include "rt_hypotf_snf.h"
#include <cmath>

extern "C" {

#include "rt_nonfinite.h"

}
  real32_T rt_hypotf_snf(real32_T u0, real32_T u1)
{
  real32_T a;
  real32_T y;
  a = std::abs(u0);
  y = std::abs(u1);
  if (a < y) {
    a /= y;
    y *= std::sqrt((a * a) + 1.0F);
  } else if (a > y) {
    y /= a;
    y = std::sqrt((y * y) + 1.0F) * a;
  } else if (static_cast<boolean_T>(static_cast<int32_T>((rtIsNaNF(y) ? (
      static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) ^ 1))) {
    y = a * 1.41421354F;
  } else {
    // no actions
  }

  return y;
}

//
// File trailer for generated code.
//
// [EOF]
//
