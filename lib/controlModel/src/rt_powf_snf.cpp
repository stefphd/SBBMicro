//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_powf_snf.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 3.2
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Apr  5 09:35:42 2022
//
#include "rtwtypes.h"
#include "rt_powf_snf.h"

extern "C" {

#include "rt_nonfinite.h"

}
#include <cmath>

extern "C" {

#include "rtGetNaN.h"

}
  extern "C"
{

#include "rtGetInf.h"

}

real32_T rt_powf_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (static_cast<boolean_T>(static_cast<int32_T>((rtIsNaNF(u0) ? (static_cast<
          int32_T>(1)) : (static_cast<int32_T>(0))) | (rtIsNaNF(u1) ? (
          static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) {
    y = (rtNaNF);
  } else {
    real32_T tmp;
    real32_T tmp_0;
    tmp = std::abs(u0);
    tmp_0 = std::abs(u1);
    if (rtIsInfF(u1)) {
      if (tmp == 1.0F) {
        y = 1.0F;
      } else if (tmp > 1.0F) {
        if (u1 > 0.0F) {
          y = (rtInfF);
        } else {
          y = 0.0F;
        }
      } else if (u1 > 0.0F) {
        y = 0.0F;
      } else {
        y = (rtInfF);
      }
    } else if (tmp_0 == 0.0F) {
      y = 1.0F;
    } else if (tmp_0 == 1.0F) {
      if (u1 > 0.0F) {
        y = u0;
      } else {
        y = 1.0F / u0;
      }
    } else if (u1 == 2.0F) {
      y = u0 * u0;
    } else if (static_cast<boolean_T>(static_cast<int32_T>(((u1 == 0.5F) ? (
        static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) & ((u0 >= 0.0F) ?
                  (static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) {
      y = std::sqrt(u0);
    } else if (static_cast<boolean_T>(static_cast<int32_T>(((u0 < 0.0F) ? (
        static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) & ((u1 > std::
        floor(u1)) ? (static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) {
      y = (rtNaNF);
    } else {
      y = std::pow(u0, u1);
    }
  }

  return y;
}

//
// File trailer for generated code.
//
// [EOF]
//
