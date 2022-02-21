//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xrotg_arF5SisE.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 1.136
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Feb 21 08:54:05 2022
//
#include "rtwtypes.h"
#include <cmath>
#include "xrotg_arF5SisE.h"

// Function for MATLAB Function: '<S11>/Predict'
void xrotg_arF5SisE(real32_T *a, real32_T *b, real32_T *c, real32_T *s)
{
  real32_T absa;
  real32_T absb;
  real32_T ads;
  real32_T bds;
  real32_T roe;
  real32_T scale;
  roe = *b;
  absa = std::abs(*a);
  absb = std::abs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0F) {
    *s = 0.0F;
    *c = 1.0F;
    *b = 0.0F;
  } else {
    ads = absa / scale;
    bds = absb / scale;
    scale *= std::sqrt((ads * ads) + (bds * bds));
    if (roe < 0.0F) {
      scale = -scale;
    }

    *c = (*a) / scale;
    *s = (*b) / scale;
    if (absa > absb) {
      *b = *s;
    } else if ((*c) != 0.0F) {
      *b = 1.0F / (*c);
    } else {
      *b = 1.0F;
    }
  }

  *a = scale;
}

//
// File trailer for generated code.
//
// [EOF]
//
