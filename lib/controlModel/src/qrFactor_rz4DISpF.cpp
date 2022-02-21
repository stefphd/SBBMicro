//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: qrFactor_rz4DISpF.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 1.136
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Feb 21 08:54:05 2022
//
#include "rtwtypes.h"
#include <cmath>
#include "rt_hypotf_snf.h"
#include "xgemv_iT7V1Got.h"
#include "xgerc_UV7q7Hce.h"
#include "xnrm2_GwEXRqZL.h"
#include "qrFactor_rz4DISpF.h"

// Function for MATLAB Function: '<S9>/Correct'
void qrFactor_rz4DISpF(const real32_T A[4], real32_T S[4], const real32_T Ns[2])
{
  int32_T aoffset;
  int32_T coffset;
  int32_T exitg1;
  int32_T knt;
  real32_T b_A[6];
  real32_T y[4];
  real32_T work[2];
  real32_T beta1;
  real32_T s;
  real32_T tau_idx_0;
  for (knt = 0; knt < 2; knt++) {
    coffset = (knt << 1ULL);
    s = A[knt + 2];
    y[coffset] = (s * S[1]) + (S[0] * A[knt]);
    y[coffset + 1] = (s * S[3]) + (S[2] * A[knt]);
  }

  b_A[0] = y[0];
  b_A[1] = y[1];
  b_A[2] = Ns[0];
  work[0] = 0.0F;
  b_A[3] = y[2];
  b_A[4] = y[3];
  b_A[5] = Ns[1];
  work[1] = 0.0F;
  s = y[0];
  tau_idx_0 = 0.0F;
  beta1 = xnrm2_GwEXRqZL(2, b_A, 2);
  if (beta1 != 0.0F) {
    beta1 = rt_hypotf_snf(y[0], beta1);
    if (y[0] >= 0.0F) {
      beta1 = -beta1;
    }

    if (std::abs(beta1) < 9.86076132E-32F) {
      knt = -1;
      coffset = 0;
      do {
        knt++;
        for (aoffset = 1; aoffset < 3; aoffset++) {
          b_A[aoffset] *= 1.01412048E+31F;
        }

        beta1 *= 1.01412048E+31F;
        s *= 1.01412048E+31F;
      } while (static_cast<boolean_T>(static_cast<int32_T>(((std::abs(beta1) >=
                   9.86076132E-32F) ? (static_cast<int32_T>(1)) :
                  (static_cast<int32_T>(0))) ^ 1)));

      beta1 = rt_hypotf_snf(s, xnrm2_GwEXRqZL(2, b_A, 2));
      if (s >= 0.0F) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - s) / beta1;
      s = 1.0F / (s - beta1);
      for (aoffset = 1; aoffset < 3; aoffset++) {
        b_A[aoffset] *= s;
      }

      while (coffset <= knt) {
        beta1 *= 9.86076132E-32F;
        coffset++;
      }

      s = beta1;
    } else {
      tau_idx_0 = (beta1 - y[0]) / beta1;
      s = 1.0F / (y[0] - beta1);
      for (coffset = 1; coffset < 3; coffset++) {
        b_A[coffset] *= s;
      }

      s = beta1;
    }
  }

  b_A[0] = 1.0F;
  if (tau_idx_0 != 0.0F) {
    knt = 3;
    coffset = 2;
    while ((knt > 0) && (b_A[coffset] == 0.0F)) {
      knt--;
      coffset--;
    }

    coffset = 1;
    aoffset = 0;
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
    xgemv_iT7V1Got(knt, coffset, b_A, 4, b_A, 1, work);
    xgerc_UV7q7Hce(knt, coffset, -tau_idx_0, 1, work, b_A, 4);
  }

  b_A[0] = s;
  s = b_A[4];
  beta1 = xnrm2_GwEXRqZL(1, b_A, 6);
  if (beta1 != 0.0F) {
    beta1 = rt_hypotf_snf(b_A[4], beta1);
    if (b_A[4] >= 0.0F) {
      beta1 = -beta1;
    }

    if (std::abs(beta1) < 9.86076132E-32F) {
      knt = -1;
      do {
        knt++;
        for (aoffset = 5; aoffset < 6; aoffset++) {
          b_A[aoffset] *= 1.01412048E+31F;
        }

        beta1 *= 1.01412048E+31F;
        s *= 1.01412048E+31F;
      } while (static_cast<boolean_T>(static_cast<int32_T>(((std::abs(beta1) >=
                   9.86076132E-32F) ? (static_cast<int32_T>(1)) :
                  (static_cast<int32_T>(0))) ^ 1)));

      beta1 = rt_hypotf_snf(s, xnrm2_GwEXRqZL(1, b_A, 6));
      if (s >= 0.0F) {
        beta1 = -beta1;
      }

      s = 1.0F / (s - beta1);
      for (aoffset = 5; aoffset < 6; aoffset++) {
        b_A[aoffset] *= s;
      }

      for (coffset = 0; coffset <= knt; coffset++) {
        beta1 *= 9.86076132E-32F;
      }

      s = beta1;
    } else {
      s = 1.0F / (b_A[4] - beta1);
      for (coffset = 5; coffset < 6; coffset++) {
        b_A[coffset] *= s;
      }

      s = beta1;
    }
  }

  b_A[4] = s;
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
