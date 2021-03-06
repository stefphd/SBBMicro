//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_atan2f_snf.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 3.2
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Apr  5 09:35:42 2022
//
#include "rtwtypes.h"
#include "rt_atan2f_snf.h"

extern "C" {

#include "rt_nonfinite.h"

}
#include <cmath>
#include "rt_defines.h"

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (static_cast<boolean_T>(static_cast<int32_T>((rtIsNaNF(u0) ? (static_cast<
          int32_T>(1)) : (static_cast<int32_T>(0))) | (rtIsNaNF(u1) ? (
          static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) {
    y = (rtNaNF);
  } else if (static_cast<boolean_T>(static_cast<int32_T>((rtIsInfF(u0) ? (
      static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) & (rtIsInfF(u1) ? (
      static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) {
    int32_T u0_0;
    int32_T u1_0;
    if (u0 > 0.0F) {
      u0_0 = 1;
    } else {
      u0_0 = -1;
    }

    if (u1 > 0.0F) {
      u1_0 = 1;
    } else {
      u1_0 = -1;
    }

    y = std::atan2(static_cast<real32_T>(u0_0), static_cast<real32_T>(u1_0));
  } else if (u1 == 0.0F) {
    if (u0 > 0.0F) {
      y = RT_PIF / 2.0F;
    } else if (u0 < 0.0F) {
      y = -(RT_PIF / 2.0F);
    } else {
      y = 0.0F;
    }
  } else {
    y = std::atan2(u0, u1);
  }

  return y;
}

//
// File trailer for generated code.
//
// [EOF]
//
