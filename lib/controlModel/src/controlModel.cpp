//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controlModel.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 3.7
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Apr  6 08:28:55 2022
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM Cortex-M
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
//    3. ROM efficiency
//    4. MISRA C:2012 guidelines
// Validation result: Not run
//
#include "rtwtypes.h"
#include <cmath>
#include "rt_powf_snf.h"

extern "C" {

#include "rt_nonfinite.h"

}
#include "trisolve_qLD0w0V1.h"
#include "qrFactor_vw3S8N7t.h"
#include "svd_GjfntRyt.h"
#include "rt_atan2f_snf.h"
#include "controlModel_types.h"
#include "xnrm2_36w0EM2n.h"
#include "rt_hypotf_snf.h"
#include "xnrm2_sPi5ZkIa.h"
#include "xgemv_Umr6G94j.h"
#include "xgerc_QRNcmuGi.h"

// Includes for objects with custom storage classes
#include "controlModel.h"

// Exported data definition

// Definition for custom storage class: Struct
controlParams_type controlParams = {
  // wheelInertia
  0.3F,

  // rollInertia
  10.0F,

  // filterSpeed
  100.0F,

  // propGainSpeed
  1.0F,

  // Qomx
  0.001F,

  // Qphi
  0.001F,

  // Romx
  0.001F,

  // derTimeSpeed
  0.0F,

  // intTimeSpeed
  0.0F,

  // riderTrqTreshold
  0.5F,

  // maxSpeed
  8.0F,

  // gravity
  9.806F,

  // COGheight
  1.0F,

  // maxCurrent
  5.0F,

  // trqGainControl
  0.5F,

  // trqConstant
  0.0404F,

  // bikeMass
  100.0F,

  // torusRadius
  0.06F,

  // rollingRadius
  0.3F,

  // beltRatio
  1.25F,

  // gearRatio
  36.0F
};

void ControlClass::reset()
{
  // Outputs for Atomic SubSystem: '<Root>/Reset Function'
  // StateWriter: '<S5>/State Writer' incorporates:
  //   Constant: '<S5>/Constant'

  controlModel_DW.blockOrdering = false;

  // End of Outputs for SubSystem: '<Root>/Reset Function'
}

// Output and update for Simulink Function: '<Root>/Simulink Function'
void ControlClass::rollEKF_stateTransitionModel(const real32_T rtu_x[2],
  real32_T rty_xNext[2])
{
  real32_T a_tmp;
  real32_T rtb_TmpSignalConversionAtxOut_0;
  real32_T rtb_TmpSignalConversionAtxOut_1;
  real32_T tmp;

  // SignalConversion generated from: '<S6>/x'
  rtb_TmpSignalConversionAtxOut_0 = rtu_x[0];
  rtb_TmpSignalConversionAtxOut_1 = rtu_x[1];

  // MATLAB Function: '<S6>/MATLAB Function' incorporates:
  //   SignalConversion generated from: '<S6>/x'

  // states
  // inputs
  //  omegaz = u(1);
  //  V = u(2);
  // ssmodel xdot=f(x,u) -> x(k+1) = x(k) + Ts*f(x(k),u(k))
  a_tmp = std::cos(rtb_TmpSignalConversionAtxOut_0);

  // SignalConversion generated from: '<S6>/xNext' incorporates:
  //   MATLAB Function: '<S6>/MATLAB Function'
  //   SignalConversion generated from: '<S6>/x'

  rty_xNext[0] = (rtb_TmpSignalConversionAtxOut_1 * 0.001F) +
    rtb_TmpSignalConversionAtxOut_0;

  // MATLAB Function: '<S6>/MATLAB Function' incorporates:
  //   SignalConversion generated from: '<S6>/x'

  rtb_TmpSignalConversionAtxOut_0 = std::sin(rtb_TmpSignalConversionAtxOut_0);
  tmp = controlParams.COGheight * controlParams.bikeMass;

  // SignalConversion generated from: '<S6>/xNext' incorporates:
  //   Inport: '<Root>/gyros'
  //   Inport: '<Root>/speed'
  //   MATLAB Function: '<S6>/MATLAB Function'
  //   SignalConversion generated from: '<S6>/omz'
  //   SignalConversion generated from: '<S6>/x'

  rty_xNext[1] = (((((((((((controlParams.torusRadius *
    rtb_TmpSignalConversionAtxOut_0) * (rtb_TmpSignalConversionAtxOut_1 *
    rtb_TmpSignalConversionAtxOut_1)) - (controlModel_U.gyros[2] *
    controlModel_U.speed)) + (controlParams.gravity *
    rtb_TmpSignalConversionAtxOut_0)) * controlParams.COGheight) -
                       (((controlModel_U.gyros[2] * controlParams.torusRadius) *
    controlModel_U.speed) / a_tmp)) * controlParams.bikeMass) -
                     (((controlModel_U.speed / (((a_tmp - 1.0F) *
    controlParams.torusRadius) + controlParams.rollingRadius)) -
                       ((controlModel_U.gyros[2] *
    rtb_TmpSignalConversionAtxOut_0) / a_tmp)) * (controlParams.wheelInertia *
    controlModel_U.gyros[2]))) + (((((controlModel_U.gyros[2] *
    controlModel_U.gyros[2]) * tmp) * rtb_TmpSignalConversionAtxOut_0) *
    ((controlParams.COGheight * a_tmp) + controlParams.torusRadius)) / (a_tmp *
    a_tmp))) / ((((controlParams.torusRadius * a_tmp) + controlParams.COGheight)
                 * tmp) + controlParams.rollInertia)) * 0.001F) +
    rtb_TmpSignalConversionAtxOut_1;
}

// Output and update for Simulink Function: '<Root>/Simulink Function1'
void ControlClass::rollEKF_stateTransitionJac(const real32_T rtu_x[2], real32_T
  rty_F[4])
{
  real32_T a_tmp_tmp;
  real32_T b_a_tmp;
  real32_T d_a;
  real32_T i_a;
  real32_T tmp;
  real32_T tmp_0;
  real32_T tmp_1;
  real32_T tmp_2;
  real32_T tmp_3;
  real32_T tmp_4;
  real32_T tmp_5;
  real32_T tmp_6;

  // MATLAB Function: '<S7>/MATLAB Function' incorporates:
  //   SignalConversion generated from: '<S7>/x'

  // states
  // inputs
  //  omegaz = u(1);
  //  V = u(2);
  // ssmodel: xdot=f(x,u) -> x(k+1) = x(k) + f(x(k),u(k))*Ts
  a_tmp_tmp = std::cos(rtu_x[0]);
  b_a_tmp = std::sin(rtu_x[0]);
  d_a = ((a_tmp_tmp - 1.0F) * controlParams.torusRadius) +
    controlParams.rollingRadius;
  i_a = (((controlParams.torusRadius * a_tmp_tmp) + controlParams.COGheight) *
         (controlParams.COGheight * controlParams.bikeMass)) +
    controlParams.rollInertia;

  // SignalConversion generated from: '<S7>/F' incorporates:
  //   MATLAB Function: '<S7>/MATLAB Function'

  rty_F[0] = 1.0F;

  // MATLAB Function: '<S7>/MATLAB Function' incorporates:
  //   Inport: '<Root>/gyros'
  //   Inport: '<Root>/speed'
  //   SignalConversion generated from: '<S7>/omz'
  //   SignalConversion generated from: '<S7>/x'

  tmp = a_tmp_tmp * a_tmp_tmp;
  tmp_0 = controlModel_U.gyros[2] * controlModel_U.gyros[2];
  tmp_1 = b_a_tmp * b_a_tmp;
  tmp_2 = rtu_x[1] * rtu_x[1];
  tmp_3 = (controlModel_U.gyros[2] * controlParams.torusRadius) *
    controlModel_U.speed;
  tmp_4 = controlParams.wheelInertia * controlModel_U.gyros[2];
  tmp_5 = (controlParams.COGheight * controlParams.bikeMass) * tmp_0;
  tmp_6 = (controlParams.COGheight * a_tmp_tmp) + controlParams.torusRadius;

  // SignalConversion generated from: '<S7>/F' incorporates:
  //   Inport: '<Root>/gyros'
  //   Inport: '<Root>/speed'
  //   MATLAB Function: '<S7>/MATLAB Function'
  //   SignalConversion generated from: '<S7>/omz'
  //   SignalConversion generated from: '<S7>/x'

  rty_F[1] = ((((((((((((controlParams.torusRadius * std::cos(rtu_x[0])) * tmp_2)
                       + (controlParams.gravity * a_tmp_tmp)) *
                      controlParams.COGheight) - ((tmp_3 * b_a_tmp) / tmp)) *
                    controlParams.bikeMass) + (((((tmp_1 * controlModel_U.gyros
    [2]) / tmp) + controlModel_U.gyros[2]) - (((controlParams.torusRadius *
    controlModel_U.speed) * b_a_tmp) / (d_a * d_a))) * tmp_4)) + ((tmp_5 * tmp_6)
    / a_tmp_tmp)) - (((((controlParams.COGheight * controlParams.COGheight) *
                        controlParams.bikeMass) * tmp_0) * tmp_1) / tmp)) +
                ((((((2.0F * controlParams.COGheight) * controlParams.bikeMass) *
                    tmp_0) * tmp_1) * tmp_6) / rt_powf_snf(a_tmp_tmp, 3.0F))) /
               ((((controlParams.torusRadius * std::cos(rtu_x[0])) +
                  controlParams.COGheight) * (controlParams.COGheight *
    controlParams.bikeMass)) + controlParams.rollInertia)) +
              (((((((((((controlParams.torusRadius * b_a_tmp) * tmp_2) -
                       (controlModel_U.gyros[2] * controlModel_U.speed)) +
                      (controlParams.gravity * b_a_tmp)) *
                     controlParams.COGheight) - (tmp_3 / a_tmp_tmp)) *
                   controlParams.bikeMass) - (((controlModel_U.speed / (((std::
    cos(rtu_x[0]) - 1.0F) * controlParams.torusRadius) +
    controlParams.rollingRadius)) - ((controlModel_U.gyros[2] * b_a_tmp) /
    a_tmp_tmp)) * tmp_4)) + (((tmp_5 * b_a_tmp) * tmp_6) / tmp)) *
                (((controlParams.COGheight * controlParams.bikeMass) *
                  controlParams.torusRadius) * b_a_tmp)) / (i_a * i_a))) *
    0.001F;
  rty_F[2] = 0.001F;
  rty_F[3] = (((((((2.0F * controlParams.COGheight) * controlParams.bikeMass) *
                  rtu_x[1]) * controlParams.torusRadius) * b_a_tmp) /
               ((((controlParams.torusRadius * std::cos(rtu_x[0])) +
                  controlParams.COGheight) * (controlParams.COGheight *
    controlParams.bikeMass)) + controlParams.rollInertia)) * 0.001F) + 1.0F;
}

// Output and update for Simulink Function: '<Root>/Simulink Function2'
void ControlClass::rollEKF_measurementModel(const real32_T rtu_x[2], real32_T
  *rty_y)
{
  // SignalConversion generated from: '<S8>/xNext' incorporates:
  //   SignalConversion generated from: '<S8>/x'

  *rty_y = rtu_x[1];
}

// Output and update for Simulink Function: '<Root>/Simulink Function3'
void ControlClass::rollEKF_measurementJac(const real32_T rtu_x[2], real32_T
  rty_H[2])
{
  UNUSED_PARAMETER(rtu_x);

  // SignalConversion generated from: '<S9>/xNext' incorporates:
  //   Constant: '<S9>/Constant'

  rty_H[0] = 0.0F;
  rty_H[1] = 1.0F;
}

// Function for MATLAB Function: '<S58>/Correct'
void ControlClass::EKFCorrectorAdditive_getMeasure(real32_T Rs, const real32_T
  x[2], const real32_T S[4], real32_T *zEstimated, real32_T Pxy[2], real32_T *Sy,
  real32_T dHdx[2], real32_T *Rsqrt)
{
  int32_T aoffset;
  int32_T knt;
  real32_T S_0[4];
  real32_T A[3];
  real32_T xnorm;
  rollEKF_measurementJac(x, dHdx);
  *Rsqrt = Rs;
  rollEKF_measurementModel(x, zEstimated);
  for (knt = 0; knt < 2; knt++) {
    real32_T Pxy_0;
    aoffset = (knt << 1ULL);
    S_0[knt] = 0.0F;
    S_0[knt] += S[knt] * S[0];
    xnorm = S[knt + 2];
    S_0[knt] += xnorm * S[2];
    Pxy_0 = S_0[knt] * dHdx[0];
    S_0[knt + 2] = 0.0F;
    S_0[knt + 2] += S[knt] * S[1];
    S_0[knt + 2] += xnorm * S[3];
    A[knt] = (S[aoffset + 1] * dHdx[1]) + (S[aoffset] * dHdx[0]);
    Pxy[knt] = (S_0[knt + 2] * dHdx[1]) + Pxy_0;
  }

  A[2] = Rs;
  *Sy = A[0];
  xnorm = xnrm2_36w0EM2n(2, A, 2);
  if (xnorm != 0.0F) {
    xnorm = rt_hypotf_snf(A[0], xnorm);
    if (A[0] >= 0.0F) {
      xnorm = -xnorm;
    }

    if (std::abs(xnorm) < 9.86076132E-32F) {
      knt = 0;
      do {
        knt++;
        for (aoffset = 1; aoffset < 3; aoffset++) {
          A[aoffset] *= 1.01412048E+31F;
        }

        xnorm *= 1.01412048E+31F;
        *Sy *= 1.01412048E+31F;
      } while (static_cast<boolean_T>(static_cast<int32_T>(((std::abs(xnorm) <
                   9.86076132E-32F) ? (static_cast<int32_T>(1)) :
                  (static_cast<int32_T>(0))) & ((knt < 20) ?
                  (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))))));

      xnorm = rt_hypotf_snf(*Sy, xnrm2_36w0EM2n(2, A, 2));
      if ((*Sy) >= 0.0F) {
        xnorm = -xnorm;
      }

      for (aoffset = 0; aoffset < knt; aoffset++) {
        xnorm *= 9.86076132E-32F;
      }

      *Sy = xnorm;
    } else {
      *Sy = xnorm;
    }
  }
}

// Function for MATLAB Function: '<S60>/Predict'
void ControlClass::co_EKFPredictorAdditive_predict(const real32_T Qs[4],
  real32_T x[2], real32_T S[4])
{
  int32_T aoffset;
  int32_T coffset;
  int32_T knt;
  real32_T A[8];
  real32_T B[4];
  real32_T y[4];
  real32_T work[2];
  real32_T x_0[2];
  real32_T atmp;
  real32_T s;
  real32_T y_tmp;
  rollEKF_stateTransitionJac(x, B);
  for (knt = 0; knt < 2; knt++) {
    x_0[knt] = x[knt];
  }

  rollEKF_stateTransitionModel(x_0, x);
  for (knt = 0; knt < 2; knt++) {
    coffset = (knt << 1ULL);
    y_tmp = B[knt + 2];
    y[coffset] = (y_tmp * S[1]) + (S[0] * B[knt]);
    y[coffset + 1] = (y_tmp * S[3]) + (S[2] * B[knt]);
  }

  A[0] = y[0];
  A[2] = Qs[0];
  A[1] = y[1];
  A[3] = Qs[2];
  y_tmp = 0.0F;
  work[0] = 0.0F;
  A[4] = y[2];
  A[6] = Qs[1];
  A[5] = y[3];
  A[7] = Qs[3];
  work[1] = 0.0F;
  atmp = y[0];
  s = xnrm2_sPi5ZkIa(3, A, 2);
  if (s != 0.0F) {
    s = rt_hypotf_snf(y[0], s);
    if (y[0] >= 0.0F) {
      s = -s;
    }

    if (std::abs(s) < 9.86076132E-32F) {
      knt = 0;
      do {
        knt++;
        for (aoffset = 1; aoffset < 4; aoffset++) {
          A[aoffset] *= 1.01412048E+31F;
        }

        s *= 1.01412048E+31F;
        atmp *= 1.01412048E+31F;
      } while (static_cast<boolean_T>(static_cast<int32_T>(((std::abs(s) <
                   9.86076132E-32F) ? (static_cast<int32_T>(1)) :
                  (static_cast<int32_T>(0))) & ((knt < 20) ?
                  (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))))));

      s = rt_hypotf_snf(atmp, xnrm2_sPi5ZkIa(3, A, 2));
      if (atmp >= 0.0F) {
        s = -s;
      }

      y_tmp = (s - atmp) / s;
      atmp = 1.0F / (atmp - s);
      for (aoffset = 1; aoffset < 4; aoffset++) {
        A[aoffset] *= atmp;
      }

      for (coffset = 0; coffset < knt; coffset++) {
        s *= 9.86076132E-32F;
      }

      atmp = s;
    } else {
      y_tmp = (s - y[0]) / s;
      atmp = 1.0F / (y[0] - s);
      for (coffset = 1; coffset < 4; coffset++) {
        A[coffset] *= atmp;
      }

      atmp = s;
    }
  }

  A[0] = 1.0F;
  if (y_tmp != 0.0F) {
    knt = 4;
    coffset = 3;
    while ((knt > 0) && (A[coffset] == 0.0F)) {
      knt--;
      coffset--;
    }

    coffset = 1;
    aoffset = 0;
    int32_T exitg1;
    do {
      exitg1 = 0;
      if ((aoffset + 5) <= (knt + 4)) {
        if (A[aoffset + 4] != 0.0F) {
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
    xgemv_Umr6G94j(knt, coffset, A, 5, A, 1, work);
    xgerc_QRNcmuGi(knt, coffset, -y_tmp, 1, work, A, 5);
  }

  A[0] = atmp;
  atmp = A[5];
  s = xnrm2_sPi5ZkIa(2, A, 7);
  if (s != 0.0F) {
    s = rt_hypotf_snf(A[5], s);
    if (A[5] >= 0.0F) {
      s = -s;
    }

    if (std::abs(s) < 9.86076132E-32F) {
      knt = 0;
      do {
        knt++;
        for (aoffset = 6; aoffset < 8; aoffset++) {
          A[aoffset] *= 1.01412048E+31F;
        }

        s *= 1.01412048E+31F;
        atmp *= 1.01412048E+31F;
      } while (static_cast<boolean_T>(static_cast<int32_T>(((std::abs(s) <
                   9.86076132E-32F) ? (static_cast<int32_T>(1)) :
                  (static_cast<int32_T>(0))) & ((knt < 20) ?
                  (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))))));

      s = rt_hypotf_snf(atmp, xnrm2_sPi5ZkIa(2, A, 7));
      if (atmp >= 0.0F) {
        s = -s;
      }

      atmp = 1.0F / (atmp - s);
      for (aoffset = 6; aoffset < 8; aoffset++) {
        A[aoffset] *= atmp;
      }

      for (coffset = 0; coffset < knt; coffset++) {
        s *= 9.86076132E-32F;
      }

      atmp = s;
    } else {
      atmp = 1.0F / (A[5] - s);
      for (coffset = 6; coffset < 8; coffset++) {
        A[coffset] *= atmp;
      }

      atmp = s;
    }
  }

  A[5] = atmp;
  B[0] = A[0];
  for (knt = 0; knt < 2; knt++) {
    B[knt + 2] = A[knt + 4];
  }

  S[0] = B[0];
  S[1] = B[2];
  S[2] = 0.0F;
  S[3] = B[3];
}

// Model step function
void ControlClass::update()
{
  b_dsp_FIRFilter_0_controlMode_T *obj_0;
  b_dspcodegen_FIRFilter_contro_T *obj;
  int32_T n;
  real32_T A[4];
  real32_T Ss[4];
  real32_T rtb_Q[4];
  real32_T C[2];
  real32_T K[2];
  real32_T s_0[2];
  real32_T Vf;
  real32_T c_b;
  real32_T rtb_FilterCoefficient;
  real32_T rtb_Sum_h;
  real32_T s;
  real32_T unusedExpr;
  real32_T zEstimated;
  boolean_T p;

  // MATLABSystem: '<Root>/Lowpass Filter' incorporates:
  //   Inport: '<Root>/torque'

  obj = controlModel_DW.obj.FilterObj;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->isSetupComplete = true;

    // System object Initialization function: dsp.FIRFilter
    for (n = 0; n < 20; n++) {
      obj->cSFunObject.W0_states[n] = obj->cSFunObject.P0_InitialStates;
    }
  }

  obj_0 = &obj->cSFunObject;

  // System object Outputs function: dsp.FIRFilter
  rtb_Sum_h = controlModel_U.torque;
  rtb_FilterCoefficient = 0.0F;

  // load input sample
  for (n = 0; n < 20; n++) {
    // shift state
    s = rtb_Sum_h;
    rtb_Sum_h = obj_0->W0_states[n];
    obj_0->W0_states[n] = s;

    // compute one tap
    s *= obj_0->P1_Coefficients[n];
    rtb_FilterCoefficient += s;
  }

  // compute last tap
  s = obj->cSFunObject.P1_Coefficients[n] * rtb_Sum_h;

  // store output sample
  rtb_Sum_h = rtb_FilterCoefficient + s;

  // DeadZone: '<Root>/Dead Zone' incorporates:
  //   MATLABSystem: '<Root>/Lowpass Filter'

  if (rtb_Sum_h > controlParams.riderTrqTreshold) {
    rtb_FilterCoefficient = rtb_Sum_h - controlParams.riderTrqTreshold;
  } else if (rtb_Sum_h >= (-controlParams.riderTrqTreshold)) {
    rtb_FilterCoefficient = 0.0F;
  } else {
    rtb_FilterCoefficient = rtb_Sum_h - (-controlParams.riderTrqTreshold);
  }

  // End of DeadZone: '<Root>/Dead Zone'

  // Gain: '<Root>/Trq const' incorporates:
  //   Gain: '<Root>/Belt and gear'
  //   Gain: '<Root>/Gain'

  s = ((1.0F / (controlParams.beltRatio * controlParams.gearRatio)) *
       (controlParams.trqGainControl * rtb_FilterCoefficient)) * (1.0F /
    controlParams.trqConstant);

  // Saturate: '<Root>/Saturation'
  if (s > controlParams.maxCurrent) {
    // Outport: '<Root>/curr_ref'
    controlModel_Y.curr_ref = controlParams.maxCurrent;
  } else if (s < (-controlParams.maxCurrent)) {
    // Outport: '<Root>/curr_ref'
    controlModel_Y.curr_ref = -controlParams.maxCurrent;
  } else {
    // Outport: '<Root>/curr_ref'
    controlModel_Y.curr_ref = s;
  }

  // End of Saturate: '<Root>/Saturation'

  // Outport: '<Root>/user_data' incorporates:
  //   Constant: '<Root>/Constant4'
  //   Constant: '<Root>/Constant5'
  //   Constant: '<Root>/Constant6'
  //   MATLABSystem: '<Root>/Lowpass Filter'

  controlModel_Y.user_data[0] = rtb_Sum_h;
  controlModel_Y.user_data[1] = 0.0F;
  controlModel_Y.user_data[2] = 0.0F;
  controlModel_Y.user_data[3] = 0.0F;

  // Sum: '<Root>/Sum' incorporates:
  //   Gain: '<Root>/Gain1'
  //   Inport: '<Root>/ref_inputs'
  //   Inport: '<Root>/speed'

  rtb_Sum_h = (controlParams.maxSpeed * controlModel_U.ref_inputs[1]) -
    controlModel_U.speed;

  // Gain: '<S44>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S36>/Filter'
  //   Gain: '<S35>/Derivative Gain'
  //   Sum: '<S36>/SumD'

  rtb_FilterCoefficient = ((controlParams.derTimeSpeed * rtb_Sum_h) -
    controlModel_DW.Filter_DSTATE) * controlParams.filterSpeed;

  // Gain: '<S39>/Proportional Gain' incorporates:
  //   DiscreteIntegrator: '<S41>/Integrator'
  //   Sum: '<S50>/Sum'

  s = ((rtb_Sum_h + controlModel_DW.Integrator_DSTATE) + rtb_FilterCoefficient) *
    controlParams.propGainSpeed;

  // Saturate: '<S48>/Saturation'
  if (s > 1.0F) {
    // Outport: '<Root>/throttle_ref'
    controlModel_Y.throttle_ref = 1.0F;
  } else if (s < 0.0F) {
    // Outport: '<Root>/throttle_ref'
    controlModel_Y.throttle_ref = 0.0F;
  } else {
    // Outport: '<Root>/throttle_ref'
    controlModel_Y.throttle_ref = s;
  }

  // End of Saturate: '<S48>/Saturation'

  // MATLAB Function: '<Root>/Q and R'
  K[0] = controlParams.Qphi;
  K[1] = controlParams.Qomx;
  rtb_Q[1] = 0.0F;
  rtb_Q[2] = 0.0F;
  rtb_Q[0] = controlParams.Qphi;
  rtb_Q[3] = controlParams.Qomx;

  // Outputs for Enabled SubSystem: '<S2>/Correct1' incorporates:
  //   EnablePort: '<S58>/Enable'

  // MATLAB Function: '<S58>/Correct' incorporates:
  //   Constant: '<S2>/BlockOrdering'
  //   DataStoreRead: '<S58>/Data Store ReadX'
  //   DataStoreWrite: '<S58>/Data Store WriteP'
  //   Inport: '<Root>/gyros'
  //   MATLAB Function: '<Root>/Q and R'

  controlModel_DW.blockOrdering = true;

  //  ekfCorrect Correction step for EKF
  //
  //    Copyright 2016-2021 The MathWorks, Inc.
  //  If measurement noise is time-varying then compute square-root
  //  factorization.
  if (static_cast<boolean_T>(static_cast<int32_T>(((static_cast<boolean_T>(
           static_cast<int32_T>((rtIsInfF(controlParams.Romx) ?
             (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) ^ 1))) ? (
          static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) & ((static_cast<
          boolean_T>(static_cast<int32_T>((rtIsNaNF(controlParams.Romx) ? (
              static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) ^ 1))) ? (
          static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) {
    s = controlParams.Romx;
    Vf = 1.0F;
    if (controlParams.Romx != 0.0F) {
      s = std::abs(controlParams.Romx);
    }

    if (s < 0.0F) {
      s = -s;
      Vf = -1.0F;
    }
  } else {
    s = (rtNaNF);
    Vf = (rtNaNF);
  }

  //  Construct the function handle for measurement fcn
  //  Construct the function handle for measurement Jacobian fcn
  //  Handle (optional) extra input arguments of the measurement & jacobian fcns 
  //  Construct the corrector, perform the update
  //  Check if dimensions and type of Measurement and Jacobian are correct
  //  Additive noise
  //  MeasurementFcn
  rollEKF_measurementModel(controlModel_DW.x, &unusedExpr);

  //  MeasurementJacobianFcn
  rollEKF_measurementJac(controlModel_DW.x, K);

  //  Measurement wrapping
  EKFCorrectorAdditive_getMeasure(Vf * std::sqrt(s), controlModel_DW.x,
    controlModel_DW.P, &zEstimated, K, &unusedExpr, s_0, &c_b);
  s = controlModel_U.gyros[0] - zEstimated;
  C[0] = K[0];
  C[1] = K[1];
  trisolve_qLD0w0V1(unusedExpr, C);
  K[0] = C[0];
  K[1] = C[1];
  trisolve_qLD0w0V1(unusedExpr, K);
  A[0] = (-K[0]) * s_0[0];
  A[1] = (-K[1]) * s_0[0];
  A[2] = (-K[0]) * s_0[1];
  A[3] = (-K[1]) * s_0[1];
  C[0] = K[0] * c_b;
  A[0]++;
  C[1] = K[1] * c_b;
  A[3]++;
  qrFactor_vw3S8N7t(A, controlModel_DW.P, C);

  // DataStoreWrite: '<S58>/Data Store WriteX' incorporates:
  //   DataStoreRead: '<S58>/Data Store ReadX'
  //   MATLAB Function: '<S58>/Correct'

  //  Get back Covariance from Square-root Covariance
  controlModel_DW.x[0] += K[0] * s;

  // End of Outputs for SubSystem: '<S2>/Correct1'

  // Outputs for Atomic SubSystem: '<S2>/Predict'
  // MATLAB Function: '<S60>/Predict' incorporates:
  //   DataStoreRead: '<S60>/Data Store ReadX'

  K[0] = controlModel_DW.x[0];

  // End of Outputs for SubSystem: '<S2>/Predict'

  // Outputs for Enabled SubSystem: '<S2>/Correct1' incorporates:
  //   EnablePort: '<S58>/Enable'

  // DataStoreWrite: '<S58>/Data Store WriteX' incorporates:
  //   DataStoreRead: '<S58>/Data Store ReadX'
  //   MATLAB Function: '<S58>/Correct'

  controlModel_DW.x[1] += K[1] * s;

  // End of Outputs for SubSystem: '<S2>/Correct1'

  // Outputs for Atomic SubSystem: '<S2>/Predict'
  // MATLAB Function: '<S60>/Predict' incorporates:
  //   DataStoreRead: '<S60>/Data Store ReadX'

  K[1] = controlModel_DW.x[1];

  // End of Outputs for SubSystem: '<S2>/Predict'

  // Outport: '<Root>/roll_est' incorporates:
  //   DataStoreRead: '<S59>/Data Store Read'

  controlModel_Y.roll_est = controlModel_DW.x[0];

  // Outputs for Atomic SubSystem: '<S2>/Predict'
  // MATLAB Function: '<S60>/Predict' incorporates:
  //   DataStoreRead: '<S60>/Data Store ReadX'
  //   DataStoreWrite: '<S60>/Data Store WriteP'
  //   MATLAB Function: '<Root>/Q and R'

  //  ekfCorrect Prediction step for EKF
  //
  //    Copyright 2016-2021 The MathWorks, Inc.
  //  If process noise is time-varying then compute square-root
  //  factorization.
  p = true;
  if (static_cast<boolean_T>(static_cast<int32_T>((rtIsInfF(controlParams.Qphi) ?
         (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) | (rtIsNaNF
         (controlParams.Qphi) ? (static_cast<int32_T>(1)) : (static_cast<int32_T>
          (0)))))) {
    p = false;
  }

  if (p) {
    if (static_cast<boolean_T>(static_cast<int32_T>((rtIsInfF(controlParams.Qomx)
           ? (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) | (rtIsNaNF
           (controlParams.Qomx) ? (static_cast<int32_T>(1)) :
           (static_cast<int32_T>(0)))))) {
      p = false;
    }
  }

  if (p) {
    svd_GjfntRyt(rtb_Q, Ss, s_0, A);
  } else {
    s_0[0] = (rtNaNF);
    s_0[1] = (rtNaNF);
    A[0] = (rtNaNF);
    A[1] = (rtNaNF);
    A[2] = (rtNaNF);
    A[3] = (rtNaNF);
  }

  Ss[0] = std::sqrt(s_0[0]);
  Ss[1] = 0.0F;
  Ss[2] = 0.0F;
  Ss[3] = std::sqrt(s_0[1]);

  //  Construct fcn handles
  //  Check if dimensions and type of State and Jacobian are correct
  //  Additive noise
  //  StateTransitionFcn
  rollEKF_stateTransitionModel(controlModel_DW.x, s_0);

  //  Jacobian
  rollEKF_stateTransitionJac(controlModel_DW.x, rtb_Q);

  //  F needs to be square
  for (n = 0; n < 2; n++) {
    int32_T A_tmp;
    A_tmp = (n << 1ULL);
    rtb_Q[A_tmp] = 0.0F;
    s = Ss[A_tmp];
    rtb_Q[A_tmp] += s * A[0];
    Vf = Ss[A_tmp + 1];
    rtb_Q[A_tmp] += Vf * A[2];
    rtb_Q[A_tmp + 1] = 0.0F;
    rtb_Q[A_tmp + 1] += s * A[1];
    rtb_Q[A_tmp + 1] += Vf * A[3];
  }

  co_EKFPredictorAdditive_predict(rtb_Q, K, controlModel_DW.P);

  // End of Outputs for SubSystem: '<S2>/Predict'

  // Outport: '<Root>/yaw_est' incorporates:
  //   Inport: '<Root>/mags'
  //   Trigonometry: '<Root>/Atan2'

  controlModel_Y.yaw_est = rt_atan2f_snf(controlModel_U.mags[1],
    controlModel_U.mags[0]);

  // Outputs for Atomic SubSystem: '<S2>/Predict'
  // DataStoreWrite: '<S60>/Data Store WriteX' incorporates:
  //   MATLAB Function: '<S60>/Predict'

  controlModel_DW.x[0] = K[0];

  // End of Outputs for SubSystem: '<S2>/Predict'

  // Outport: '<Root>/pos_est' incorporates:
  //   Constant: '<Root>/Constant3'

  controlModel_Y.pos_est[0] = 0.0F;

  // Outputs for Atomic SubSystem: '<S2>/Predict'
  // DataStoreWrite: '<S60>/Data Store WriteX' incorporates:
  //   MATLAB Function: '<S60>/Predict'

  controlModel_DW.x[1] = K[1];

  // End of Outputs for SubSystem: '<S2>/Predict'

  // Outport: '<Root>/pos_est' incorporates:
  //   Constant: '<Root>/Constant3'

  controlModel_Y.pos_est[1] = 0.0F;

  // Outport: '<Root>/error_state_out' incorporates:
  //   UnitDelay: '<Root>/Unit Delay'

  controlModel_Y.error_state_out = controlModel_DW.error_state;

  // Update for DiscreteIntegrator: '<S41>/Integrator' incorporates:
  //   Gain: '<S38>/Integral Gain'

  controlModel_DW.Integrator_DSTATE += (controlParams.intTimeSpeed * rtb_Sum_h) *
    0.001F;

  // Update for DiscreteIntegrator: '<S36>/Filter'
  controlModel_DW.Filter_DSTATE += 0.001F * rtb_FilterCoefficient;

  // Update for UnitDelay: '<Root>/Unit Delay' incorporates:
  //   Inport: '<Root>/error_state_in'

  controlModel_DW.error_state = controlModel_U.error_state_in;
}

// Model initialize function
void ControlClass::begin()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  {
    b_dspcodegen_FIRFilter_contro_T *iobj_0;
    static const real32_T tmp[21] = { -0.000803169096F, -0.00341077754F,
      -0.00823236164F, -0.0131849619F, -0.0126657868F, 0.00105571444F,
      0.0335894823F, 0.0833384693F, 0.139194697F, 0.183665663F, 0.200662464F,
      0.183665663F, 0.139194697F, 0.0833384693F, 0.0335894823F, 0.00105571444F,
      -0.0126657868F, -0.0131849619F, -0.00823236164F, -0.00341077754F,
      -0.000803169096F };

    // Start for DataStoreMemory: '<S2>/DataStoreMemory - P'
    controlModel_DW.P[0] = 0.0316227786F;
    controlModel_DW.P[1] = 0.0F;
    controlModel_DW.P[2] = 0.0F;
    controlModel_DW.P[3] = 0.0316227786F;

    // InitializeConditions for UnitDelay: '<Root>/Unit Delay'
    controlModel_DW.error_state = 1U;

    // Start for MATLABSystem: '<Root>/Lowpass Filter'
    controlModel_DW.obj._pobj0.matlabCodegenIsDeleted = true;
    controlModel_DW.obj.matlabCodegenIsDeleted = true;
    controlModel_DW.obj.isInitialized = 0;
    controlModel_DW.obj.NumChannels = -1;
    controlModel_DW.obj.matlabCodegenIsDeleted = false;
    controlModel_DW.obj.isSetupComplete = false;
    controlModel_DW.obj.isInitialized = 1;
    iobj_0 = &controlModel_DW.obj._pobj0;
    iobj_0->isInitialized = 0;
    iobj_0->isInitialized = 0;

    // System object Constructor function: dsp.FIRFilter
    iobj_0->cSFunObject.P0_InitialStates = 0.0F;
    for (int32_T i = 0; i < 21; i++) {
      iobj_0->cSFunObject.P1_Coefficients[i] = tmp[i];
    }

    iobj_0->matlabCodegenIsDeleted = false;
    controlModel_DW.obj.FilterObj = iobj_0;
    controlModel_DW.obj.NumChannels = 1;
    controlModel_DW.obj.isSetupComplete = true;

    // End of Start for MATLABSystem: '<Root>/Lowpass Filter'

    // InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter'
    iobj_0 = controlModel_DW.obj.FilterObj;
    if (iobj_0->isInitialized == 1) {
      // System object Initialization function: dsp.FIRFilter
      for (int32_T i = 0; i < 20; i++) {
        iobj_0->cSFunObject.W0_states[i] = iobj_0->cSFunObject.P0_InitialStates;
      }
    }

    // End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter'
  }
}

// Model terminate function
void ControlClass::stop()
{
  b_dspcodegen_FIRFilter_contro_T *obj;

  // Terminate for MATLABSystem: '<Root>/Lowpass Filter'
  if (static_cast<boolean_T>(static_cast<int32_T>
       ((controlModel_DW.obj.matlabCodegenIsDeleted ? (static_cast<int32_T>(1)) :
         (static_cast<int32_T>(0))) ^ 1))) {
    controlModel_DW.obj.matlabCodegenIsDeleted = true;
    if ((controlModel_DW.obj.isInitialized == 1) &&
        (controlModel_DW.obj.isSetupComplete)) {
      obj = controlModel_DW.obj.FilterObj;
      if (obj->isInitialized == 1) {
        obj->isInitialized = 2;
      }

      controlModel_DW.obj.NumChannels = -1;
    }
  }

  obj = &controlModel_DW.obj._pobj0;
  if (static_cast<boolean_T>(static_cast<int32_T>((obj->matlabCodegenIsDeleted ?
         (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) ^ 1))) {
    obj->matlabCodegenIsDeleted = true;
    if (obj->isInitialized == 1) {
      obj->isInitialized = 2;
    }
  }

  // End of Terminate for MATLABSystem: '<Root>/Lowpass Filter'
}

// Constructor
ControlClass::ControlClass():
  controlModel_U(),
  controlModel_Y(),
  controlModel_DW()
{
  // Currently there is no constructor body generated.
}

// Destructor
ControlClass::~ControlClass()
{
  // Currently there is no destructor body generated.
}

//
// File trailer for generated code.
//
// [EOF]
//
