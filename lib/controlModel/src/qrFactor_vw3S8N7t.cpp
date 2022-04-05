//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: qrFactor_vw3S8N7t.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 3.2
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Apr  5 09:35:42 2022
//
#include "rtwtypes.h"
#include "qrFactor_vw3S8N7t.h"
#include "xnrm2_Gh1C4Ta8.h"
#include "rt_hypotf_snf.h"
#include <cmath>
#include "xgemv_ndIKoEsw.h"
#include "xgerc_FYuPyMLf.h"

// Function for MATLAB Function: '<S60>/Correct'
void qrFactor_vw3S8N7t(const real32_T A[4], real32_T S[4], const real32_T Ns[2])
{
  int32_T aoffset;
  int32_T coffset;
  int32_T knt;
  real32_T b_A[6];
  real32_T y[4];
  real32_T work[2];
  real32_T atmp;
  real32_T s;
  real32_T y_tmp;
  for (knt = 0; knt < 2; knt++) {
    coffset = (knt << 1ULL);
    y_tmp = A[knt + 2];
    y[coffset] = (y_tmp * S[1]) + (S[0] * A[knt]);
    y[coffset + 1] = (y_tmp * S[3]) + (S[2] * A[knt]);
  }

  b_A[0] = y[0];
  b_A[1] = y[1];
  b_A[2] = Ns[0];
  y_tmp = 0.0F;
  work[0] = 0.0F;
  b_A[3] = y[2];
  b_A[4] = y[3];
  b_A[5] = Ns[1];
  work[1] = 0.0F;
  atmp = y[0];
  s = xnrm2_Gh1C4Ta8(2, b_A, 2);
  if (s != 0.0F) {
    s = rt_hypotf_snf(y[0], s);
    if (y[0] >= 0.0F) {
      s = -s;
    }

    if (std::abs(s) < 9.86076132E-32F) {
      knt = 0;
      do {
        knt++;
        for (aoffset = 1; aoffset < 3; aoffset++) {
          b_A[aoffset] *= 1.01412048E+31F;
        }

        s *= 1.01412048E+31F;
        atmp *= 1.01412048E+31F;
      } while (static_cast<boolean_T>(static_cast<int32_T>(((std::abs(s) <
                   9.86076132E-32F) ? (static_cast<int32_T>(1)) :
                  (static_cast<int32_T>(0))) & ((knt < 20) ?
                  (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))))));

      s = rt_hypotf_snf(atmp, xnrm2_Gh1C4Ta8(2, b_A, 2));
      if (atmp >= 0.0F) {
        s = -s;
      }

      y_tmp = (s - atmp) / s;
      atmp = 1.0F / (atmp - s);
      for (aoffset = 1; aoffset < 3; aoffset++) {
        b_A[aoffset] *= atmp;
      }

      for (coffset = 0; coffset < knt; coffset++) {
        s *= 9.86076132E-32F;
      }

      atmp = s;
    } else {
      y_tmp = (s - y[0]) / s;
      atmp = 1.0F / (y[0] - s);
      for (coffset = 1; coffset < 3; coffset++) {
        b_A[coffset] *= atmp;
      }

      atmp = s;
    }
  }

  b_A[0] = 1.0F;
  if (y_tmp != 0.0F) {
    knt = 3;
    coffset = 2;
    while ((knt > 0) && (b_A[coffset] == 0.0F)) {
      knt--;
      coffset--;
    }

    coffset = 1;
    aoffset = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if ((aoffset + 4) <= (knt + 3)) {
        if (b_A[aoffset + 3] != 0.0F) {
          exitg1 = 1;
        } else {
          aoffset++;
        }
      } else {
        coffset = 0;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    knt = 0;
    coffset = 0;
  }

  if (knt > 0) {
    xgemv_ndIKoEsw(knt, coffset, b_A, 4, b_A, 1, work);
    xgerc_FYuPyMLf(knt, coffset, -y_tmp, 1, work, b_A, 4);
  }

  b_A[0] = atmp;
  atmp = b_A[4];
  s = xnrm2_Gh1C4Ta8(1, b_A, 6);
  if (s != 0.0F) {
    s = rt_hypotf_snf(b_A[4], s);
    if (b_A[4] >= 0.0F) {
      s = -s;
    }

    if (std::abs(s) < 9.86076132E-32F) {
      knt = 0;
      do {
        knt++;
        for (aoffset = 5; aoffset < 6; aoffset++) {
          b_A[aoffset] *= 1.01412048E+31F;
        }

        s *= 1.01412048E+31F;
        atmp *= 1.01412048E+31F;
      } while (static_cast<boolean_T>(static_cast<int32_T>(((std::abs(s) <
                   9.86076132E-32F) ? (static_cast<int32_T>(1)) :
                  (static_cast<int32_T>(0))) & ((knt < 20) ?
                  (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))))));

      s = rt_hypotf_snf(atmp, xnrm2_Gh1C4Ta8(1, b_A, 6));
      if (atmp >= 0.0F) {
        s = -s;
      }

      atmp = 1.0F / (atmp - s);
      for (aoffset = 5; aoffset < 6; aoffset++) {
        b_A[aoffset] *= atmp;
      }

      for (coffset = 0; coffset < knt; coffset++) {
        s *= 9.86076132E-32F;
      }

      atmp = s;
    } else {
      atmp = 1.0F / (b_A[4] - s);
      for (coffset = 5; coffset < 6; coffset++) {
        b_A[coffset] *= atmp;
      }

      atmp = s;
    }
  }

  b_A[4] = atmp;
  y[0] = b_A[0];
  for (coffset = 0; coffset < 2; coffset++) {
    y[coffset + 2] = b_A[coffset + 3];
  }

  S[0] = y[0];
  S[1] = y[2];
  S[2] = 0.0F;
  S[3] = y[3];
}

//
// File trailer for generated code.
//
// [EOF]
//
