//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xrotg_wo9Bb2WO.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 3.0
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Apr  4 21:26:13 2022
//
#include "rtwtypes.h"
#include "xrotg_wo9Bb2WO.h"
#include <cmath>

// Function for MATLAB Function: '<S62>/Predict'
void xrotg_wo9Bb2WO(real32_T *a, real32_T *b, real32_T *c, real32_T *s)
{
  real32_T absa;
  real32_T absb;
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
    *a = 0.0F;
    *b = 0.0F;
  } else {
    real32_T ads;
    real32_T bds;
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

    *a = scale;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
