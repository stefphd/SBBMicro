//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: svd_GjfntRyt.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 3.0
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Mon Apr  4 21:26:13 2022
//
#include "rtwtypes.h"
#include "svd_GjfntRyt.h"
#include "xnrm2_sAuJgc24.h"
#include <cmath>
#include "xscal_MZz1kJjZ.h"
#include "xdotc_EihJC7F3.h"
#include "xaxpy_hYt0bdta.h"
#include "xscal_u81h4dmT.h"

extern "C" {

#include "rt_nonfinite.h"

}
#include "xrotg_wo9Bb2WO.h"
#include "xrot_kJoGnQw0.h"
#include "xswap_5FNSjdoT.h"

// Function for MATLAB Function: '<S62>/Predict'
void svd_GjfntRyt(const real32_T A[4], real32_T U[4], real32_T s[2], real32_T V
                  [4])
{
  int32_T iter;
  int32_T m;
  real32_T b_A[4];
  real32_T b_s[2];
  real32_T e[2];
  real32_T nrm;
  real32_T rt;
  real32_T smm1;
  real32_T sqds;
  real32_T ztest;
  b_A[0] = A[0];
  b_A[1] = A[1];
  b_A[2] = A[2];
  b_A[3] = A[3];
  nrm = xnrm2_sAuJgc24(A);
  if (nrm > 0.0F) {
    if (A[0] < 0.0F) {
      b_s[0] = -nrm;
    } else {
      b_s[0] = nrm;
    }

    if (std::abs(b_s[0]) >= 9.86076132E-32F) {
      xscal_MZz1kJjZ(1.0F / b_s[0], b_A);
    } else {
      b_A[0] = A[0] / b_s[0];
      b_A[1] = A[1] / b_s[0];
    }

    b_A[0]++;
    b_s[0] = -b_s[0];
    xaxpy_hYt0bdta(-(xdotc_EihJC7F3(b_A, b_A) / b_A[0]), b_A);
  } else {
    b_s[0] = 0.0F;
  }

  b_s[1] = b_A[3];
  e[1] = 0.0F;
  U[0] = b_A[0];
  U[2] = 0.0F;
  U[1] = b_A[1];
  m = 0;
  U[3] = 1.0F;
  if (b_s[0] != 0.0F) {
    xaxpy_hYt0bdta(-(xdotc_EihJC7F3(U, U) / b_A[0]), U);
    U[1] = -U[1];
    U[0] = (-U[0]) + 1.0F;
  } else {
    U[1] = 0.0F;
    U[0] = 1.0F;
  }

  V[2] = 0.0F;
  V[3] = 1.0F;
  V[1] = 0.0F;
  V[0] = 1.0F;
  ztest = b_A[2];
  if (b_s[0] != 0.0F) {
    rt = std::abs(b_s[0]);
    nrm = b_s[0] / rt;
    b_s[0] = rt;
    ztest = b_A[2] / nrm;
    xscal_u81h4dmT(nrm, U, 1);
  }

  if (ztest != 0.0F) {
    rt = std::abs(ztest);
    nrm = rt / ztest;
    ztest = rt;
    b_s[1] = b_A[3] * nrm;
    xscal_u81h4dmT(nrm, V, 3);
  }

  if (b_s[1] != 0.0F) {
    rt = std::abs(b_s[1]);
    nrm = b_s[1] / rt;
    b_s[1] = rt;
    xscal_u81h4dmT(nrm, U, 3);
  }

  e[0] = ztest;
  iter = 0;
  if (static_cast<boolean_T>(static_cast<int32_T>(((b_s[0] >= ztest) ? (
          static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) | (rtIsNaNF
         (ztest) ? (static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) {
    nrm = b_s[0];
  } else {
    nrm = ztest;
  }

  if (b_s[1] >= 0.0F) {
    ztest = b_s[1];
  } else {
    ztest = 0.0F;
  }

  if (static_cast<boolean_T>(static_cast<int32_T>(((static_cast<boolean_T>(
           static_cast<int32_T>(((nrm >= ztest) ? (static_cast<int32_T>(1)) : (
              static_cast<int32_T>(0))) ^ 1))) ? (static_cast<int32_T>(1)) : (
          static_cast<int32_T>(0))) & ((static_cast<boolean_T>
          (static_cast<int32_T>((rtIsNaNF(ztest) ? (static_cast<int32_T>(1)) : (
              static_cast<int32_T>(0))) ^ 1))) ? (static_cast<int32_T>(1)) : (
          static_cast<int32_T>(0)))))) {
    nrm = ztest;
  }

  while (static_cast<boolean_T>(static_cast<int32_T>((((m + 2) > 0) ? (
             static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) & ((iter < 75)
            ? (static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) {
    int32_T kase;
    int32_T q;
    int32_T qs;
    boolean_T exitg1;
    q = m + 1;
    exitg1 = false;
    while (!(((exitg1 ? (static_cast<uint32_T>(1U)) : (static_cast<uint32_T>(0U)))
              == true) || (q == 0))) {
      rt = std::abs(e[0]);
      if (rt <= ((std::abs(b_s[0]) + std::abs(b_s[1])) * 1.1920929E-7F)) {
        e[0] = 0.0F;
        exitg1 = true;
      } else if (static_cast<boolean_T>(static_cast<int32_T>(((static_cast<
          boolean_T>(static_cast<int32_T>(((rt <= (1.1920929E-7F * nrm)) ? (
          static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) & ((iter > 20) ?
        (static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) ? (
          static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) | ((rt <=
          9.86076132E-32F) ? (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))))))
      {
        e[0] = 0.0F;
        exitg1 = true;
      } else {
        q = 0;
      }
    }

    if ((m + 1) == q) {
      kase = 4;
    } else {
      qs = m + 2;
      kase = m + 2;
      exitg1 = false;
      while (((exitg1 ? (static_cast<uint32_T>(1U)) : (static_cast<uint32_T>(0U)))
              == false) && (kase >= q)) {
        qs = kase;
        if (kase == q) {
          exitg1 = true;
        } else {
          rt = 0.0F;
          if (kase < (m + 2)) {
            rt = std::abs(e[kase - 1]);
          }

          if (kase > (q + 1)) {
            rt += std::abs(e[0]);
          }

          ztest = std::abs(b_s[kase - 1]);
          if (static_cast<boolean_T>(static_cast<int32_T>(((ztest <=
                  (1.1920929E-7F * rt)) ? (static_cast<int32_T>(1)) : (
                  static_cast<int32_T>(0))) | ((ztest <= 9.86076132E-32F) ? (
                  static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) {
            b_s[kase - 1] = 0.0F;
            exitg1 = true;
          } else {
            kase--;
          }
        }
      }

      if (qs == q) {
        kase = 3;
      } else if ((m + 2) == qs) {
        kase = 1;
      } else {
        kase = 2;
        q = qs;
      }
    }

    switch (kase) {
     case 1:
      rt = e[m];
      e[m] = 0.0F;
      qs = m + 1;
      while (qs >= (q + 1)) {
        xrotg_wo9Bb2WO(&b_s[0], &rt, &ztest, &sqds);
        xrot_kJoGnQw0(V, 1, ((m + 1) << 1ULL) + 1, ztest, sqds);
        qs = 0;
      }
      break;

     case 2:
      rt = e[q - 1];
      e[q - 1] = 0.0F;
      for (qs = q; qs < (m + 2); qs++) {
        xrotg_wo9Bb2WO(&b_s[qs], &rt, &ztest, &sqds);
        rt = (-sqds) * e[qs];
        e[qs] *= ztest;
        xrot_kJoGnQw0(U, (qs << 1ULL) + 1, ((q - 1) << 1ULL) + 1, ztest, sqds);
      }
      break;

     case 3:
      {
        real32_T emm1;
        real32_T shift;
        rt = b_s[m + 1];
        ztest = std::abs(rt);
        sqds = std::abs(b_s[m]);
        if (static_cast<boolean_T>(static_cast<int32_T>(((ztest >= sqds) ? (
                static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) |
              (rtIsNaNF(sqds) ? (static_cast<int32_T>(1)) : (static_cast<int32_T>
                (0)))))) {
          sqds = ztest;
        }

        ztest = std::abs(e[m]);
        if (static_cast<boolean_T>(static_cast<int32_T>(((sqds >= ztest) ? (
                static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) |
              (rtIsNaNF(ztest) ? (static_cast<int32_T>(1)) :
               (static_cast<int32_T>(0)))))) {
          ztest = sqds;
        }

        sqds = std::abs(b_s[q]);
        if (static_cast<boolean_T>(static_cast<int32_T>(((ztest >= sqds) ? (
                static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) |
              (rtIsNaNF(sqds) ? (static_cast<int32_T>(1)) : (static_cast<int32_T>
                (0)))))) {
          sqds = ztest;
        }

        ztest = std::abs(e[q]);
        if (static_cast<boolean_T>(static_cast<int32_T>(((sqds >= ztest) ? (
                static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) |
              (rtIsNaNF(ztest) ? (static_cast<int32_T>(1)) :
               (static_cast<int32_T>(0)))))) {
          ztest = sqds;
        }

        rt /= ztest;
        smm1 = b_s[m] / ztest;
        emm1 = e[m] / ztest;
        sqds = b_s[q] / ztest;
        smm1 = (((smm1 + rt) * (smm1 - rt)) + (emm1 * emm1)) / 2.0F;
        emm1 *= rt;
        emm1 *= emm1;
        if (static_cast<boolean_T>(static_cast<int32_T>(((smm1 != 0.0F) ? (
                static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) | ((emm1
                != 0.0F) ? (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))))))
        {
          shift = std::sqrt((smm1 * smm1) + emm1);
          if (smm1 < 0.0F) {
            shift = -shift;
          }

          shift = emm1 / (smm1 + shift);
        } else {
          shift = 0.0F;
        }

        rt = ((sqds + rt) * (sqds - rt)) + shift;
        ztest = (e[q] / ztest) * sqds;
        while ((q + 1) <= (m + 1)) {
          xrotg_wo9Bb2WO(&rt, &ztest, &sqds, &smm1);
          rt = (sqds * b_s[0]) + (smm1 * e[0]);
          e[0] = (sqds * e[0]) - (smm1 * b_s[0]);
          ztest = smm1 * b_s[1];
          b_s[1] *= sqds;
          xrot_kJoGnQw0(V, 1, 3, sqds, smm1);
          b_s[0] = rt;
          xrotg_wo9Bb2WO(&b_s[0], &ztest, &sqds, &smm1);
          rt = (sqds * e[0]) + (smm1 * b_s[1]);
          b_s[1] = ((-smm1) * e[0]) + (sqds * b_s[1]);
          ztest = smm1 * e[1];
          e[1] *= sqds;
          xrot_kJoGnQw0(U, 1, 3, sqds, smm1);
          q = 1;
        }

        e[m] = rt;
        iter++;
      }
      break;

     default:
      if (b_s[q] < 0.0F) {
        b_s[q] = -b_s[q];
        xscal_u81h4dmT(-1.0F, V, (q << 1ULL) + 1);
      }

      iter = q + 1;
      while (((q + 1) < 2) && (b_s[q] < b_s[iter])) {
        rt = b_s[q];
        b_s[q] = b_s[iter];
        b_s[iter] = rt;
        xswap_5FNSjdoT(V, (q << 1ULL) + 1, ((q + 1) << 1ULL) + 1);
        xswap_5FNSjdoT(U, (q << 1ULL) + 1, ((q + 1) << 1ULL) + 1);
        q = iter;
        iter++;
      }

      iter = 0;
      m--;
      break;
    }
  }

  s[0] = b_s[0];
  s[1] = b_s[1];
}

//
// File trailer for generated code.
//
// [EOF]
//
