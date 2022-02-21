//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controlModel.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 1.137
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Mon Feb 21 09:04:27 2022
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
#include "controlModel.h"
#include "controlModel_private.h"

// Includes for objects with custom storage classes.
#include "controlModel.h"
#include "qrFactor_rz4DISpF.h"
#include "rt_hypotf_snf.h"
#include "rt_powf_snf.h"
#include "svd_RbbuN3t6.h"
#include "trisolve_OvFIvCwp.h"
#include "xgemv_9zu7RVJg.h"
#include "xgerc_CH56O7Zi.h"
#include "xnrm2_G7tX9tbl.h"
#include "xnrm2_PWt4zgS1.h"

// Exported data definition

// Definition for custom storage class: Struct
controlParams_type controlParams = {
  // wheelInertia
  0.3F,

  // rollInertia
  10.0F,

  // Qomx
  0.001F,

  // Qphi
  0.001F,

  // Romx
  0.001F,

  // riderTrqTreshold
  0.5F,

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
  // StateWriter: '<S4>/State Writer' incorporates:
  //   Constant: '<S4>/Constant'

  controlModel_DW.blockOrdering = false;

  // CCaller: '<S4>/C Caller'
  //initTimer();

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

  // SignalConversion generated from: '<S5>/x'
  rtb_TmpSignalConversionAtxOut_0 = rtu_x[0];
  rtb_TmpSignalConversionAtxOut_1 = rtu_x[1];

  // MATLAB Function: '<S5>/MATLAB Function' incorporates:
  //   SignalConversion generated from: '<S5>/x'

  // states
  // inputs
  //  omegaz = u(1);
  //  V = u(2);
  // ssmodel xdot=f(x,u) -> x(k+1) = x(k) + Ts*f(x(k),u(k))
  a_tmp = std::cos(rtb_TmpSignalConversionAtxOut_0);

  // SignalConversion generated from: '<S5>/xNext' incorporates:
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   SignalConversion generated from: '<S5>/x'

  rty_xNext[0] = (rtb_TmpSignalConversionAtxOut_1 * 0.001F) +
    rtb_TmpSignalConversionAtxOut_0;

  // MATLAB Function: '<S5>/MATLAB Function' incorporates:
  //   SignalConversion generated from: '<S5>/x'

  rtb_TmpSignalConversionAtxOut_0 = std::sin(rtb_TmpSignalConversionAtxOut_0);
  tmp = controlParams.COGheight * controlParams.bikeMass;

  // SignalConversion generated from: '<S5>/xNext' incorporates:
  //   Inport: '<Root>/gyros'
  //   Inport: '<Root>/speed'
  //   MATLAB Function: '<S5>/MATLAB Function'
  //   SignalConversion generated from: '<S5>/omz'
  //   SignalConversion generated from: '<S5>/x'

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
    controlModel_U.gyros[2]))) + ((((tmp * (controlModel_U.gyros[2] *
    controlModel_U.gyros[2])) * rtb_TmpSignalConversionAtxOut_0) *
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

  // MATLAB Function: '<S6>/MATLAB Function' incorporates:
  //   SignalConversion generated from: '<S6>/x'

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

  // SignalConversion generated from: '<S6>/F' incorporates:
  //   MATLAB Function: '<S6>/MATLAB Function'

  rty_F[0] = 1.0F;

  // MATLAB Function: '<S6>/MATLAB Function' incorporates:
  //   Inport: '<Root>/gyros'
  //   Inport: '<Root>/speed'
  //   SignalConversion generated from: '<S6>/omz'
  //   SignalConversion generated from: '<S6>/x'

  tmp = a_tmp_tmp * a_tmp_tmp;
  tmp_0 = controlModel_U.gyros[2] * controlModel_U.gyros[2];
  tmp_1 = b_a_tmp * b_a_tmp;
  tmp_2 = rtu_x[1] * rtu_x[1];
  tmp_3 = (controlModel_U.gyros[2] * controlParams.torusRadius) *
    controlModel_U.speed;
  tmp_4 = controlParams.wheelInertia * controlModel_U.gyros[2];
  tmp_5 = (controlParams.COGheight * controlParams.bikeMass) * tmp_0;
  tmp_6 = (controlParams.COGheight * a_tmp_tmp) + controlParams.torusRadius;

  // SignalConversion generated from: '<S6>/F' incorporates:
  //   Inport: '<Root>/gyros'
  //   Inport: '<Root>/speed'
  //   MATLAB Function: '<S6>/MATLAB Function'
  //   SignalConversion generated from: '<S6>/omz'
  //   SignalConversion generated from: '<S6>/x'

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
  // SignalConversion generated from: '<S7>/xNext' incorporates:
  //   SignalConversion generated from: '<S7>/x'

  *rty_y = rtu_x[1];
}

// Output and update for Simulink Function: '<Root>/Simulink Function3'
void ControlClass::rollEKF_measurementJac(const real32_T rtu_x[2], real32_T
  rty_H[2])
{
  UNUSED_PARAMETER(rtu_x);

  // SignalConversion generated from: '<S8>/xNext'
  rty_H[0] = 0.0F;
  rty_H[1] = 1.0F;
}

// Function for MATLAB Function: '<S9>/Correct'
void ControlClass::EKFCorrectorAdditive_getMeasure(real32_T Rs, const real32_T
  x[2], const real32_T S[4], real32_T *zEstimated, real32_T Pxy[2], real32_T *Sy,
  real32_T dHdx[2], real32_T *Rsqrt)
{
  int32_T aoffset;
  int32_T knt;
  real32_T S_0[4];
  real32_T A[3];
  real32_T Pxy_0;
  real32_T xnorm;
  rollEKF_measurementJac(x, dHdx);
  rollEKF_measurementModel(x, zEstimated);
  *Rsqrt = Rs;
  for (knt = 0; knt < 2; knt++) {
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
  xnorm = xnrm2_G7tX9tbl(2, A, 2);
  if (xnorm != 0.0F) {
    xnorm = rt_hypotf_snf(A[0], xnorm);
    if (A[0] >= 0.0F) {
      xnorm = -xnorm;
    }

    if (std::abs(xnorm) < 9.86076132E-32F) {
      knt = -1;
      do {
        knt++;
        for (aoffset = 1; aoffset < 3; aoffset++) {
          A[aoffset] *= 1.01412048E+31F;
        }

        xnorm *= 1.01412048E+31F;
        *Sy *= 1.01412048E+31F;
      } while (static_cast<boolean_T>(static_cast<int32_T>(((std::abs(xnorm) >=
                   9.86076132E-32F) ? (static_cast<int32_T>(1)) :
                  (static_cast<int32_T>(0))) ^ 1)));

      xnorm = rt_hypotf_snf(*Sy, xnrm2_G7tX9tbl(2, A, 2));
      if ((*Sy) >= 0.0F) {
        xnorm = -xnorm;
      }

      for (aoffset = 0; aoffset <= knt; aoffset++) {
        xnorm *= 9.86076132E-32F;
      }

      *Sy = xnorm;
    } else {
      *Sy = xnorm;
    }
  }
}

// Function for MATLAB Function: '<S11>/Predict'
void ControlClass::co_EKFPredictorAdditive_predict(const real32_T Qs[4],
  real32_T x[2], real32_T S[4])
{
  int32_T aoffset;
  int32_T coffset;
  int32_T exitg1;
  int32_T knt;
  real32_T A[8];
  real32_T Jacobian[4];
  real32_T y[4];
  real32_T work[2];
  real32_T x_0[2];
  real32_T beta1;
  real32_T s;
  real32_T tau_idx_0;
  rollEKF_stateTransitionJac(x, Jacobian);
  for (knt = 0; knt < 2; knt++) {
    x_0[knt] = x[knt];
  }

  rollEKF_stateTransitionModel(x_0, x);
  for (knt = 0; knt < 2; knt++) {
    coffset = (knt << 1ULL);
    s = Jacobian[knt + 2];
    y[coffset] = (s * S[1]) + (S[0] * Jacobian[knt]);
    y[coffset + 1] = (s * S[3]) + (S[2] * Jacobian[knt]);
  }

  A[0] = y[0];
  A[2] = Qs[0];
  A[1] = y[1];
  A[3] = Qs[2];
  work[0] = 0.0F;
  A[4] = y[2];
  A[6] = Qs[1];
  A[5] = y[3];
  A[7] = Qs[3];
  work[1] = 0.0F;
  s = y[0];
  tau_idx_0 = 0.0F;
  beta1 = xnrm2_PWt4zgS1(3, A, 2);
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
        for (aoffset = 1; aoffset < 4; aoffset++) {
          A[aoffset] *= 1.01412048E+31F;
        }

        beta1 *= 1.01412048E+31F;
        s *= 1.01412048E+31F;
      } while (static_cast<boolean_T>(static_cast<int32_T>(((std::abs(beta1) >=
                   9.86076132E-32F) ? (static_cast<int32_T>(1)) :
                  (static_cast<int32_T>(0))) ^ 1)));

      beta1 = rt_hypotf_snf(s, xnrm2_PWt4zgS1(3, A, 2));
      if (s >= 0.0F) {
        beta1 = -beta1;
      }

      tau_idx_0 = (beta1 - s) / beta1;
      s = 1.0F / (s - beta1);
      for (aoffset = 1; aoffset < 4; aoffset++) {
        A[aoffset] *= s;
      }

      while (coffset <= knt) {
        beta1 *= 9.86076132E-32F;
        coffset++;
      }

      s = beta1;
    } else {
      tau_idx_0 = (beta1 - y[0]) / beta1;
      s = 1.0F / (y[0] - beta1);
      for (coffset = 1; coffset < 4; coffset++) {
        A[coffset] *= s;
      }

      s = beta1;
    }
  }

  A[0] = 1.0F;
  if (tau_idx_0 != 0.0F) {
    knt = 4;
    coffset = 3;
    while ((knt > 0) && (A[coffset] == 0.0F)) {
      knt--;
      coffset--;
    }

    coffset = 1;
    aoffset = 0;
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
    xgemv_9zu7RVJg(knt, coffset, A, 5, A, 1, work);
    xgerc_CH56O7Zi(knt, coffset, -tau_idx_0, 1, work, A, 5);
  }

  A[0] = s;
  s = A[5];
  beta1 = xnrm2_PWt4zgS1(2, A, 7);
  if (beta1 != 0.0F) {
    beta1 = rt_hypotf_snf(A[5], beta1);
    if (A[5] >= 0.0F) {
      beta1 = -beta1;
    }

    if (std::abs(beta1) < 9.86076132E-32F) {
      knt = -1;
      do {
        knt++;
        for (aoffset = 6; aoffset < 8; aoffset++) {
          A[aoffset] *= 1.01412048E+31F;
        }

        beta1 *= 1.01412048E+31F;
        s *= 1.01412048E+31F;
      } while (static_cast<boolean_T>(static_cast<int32_T>(((std::abs(beta1) >=
                   9.86076132E-32F) ? (static_cast<int32_T>(1)) :
                  (static_cast<int32_T>(0))) ^ 1)));

      beta1 = rt_hypotf_snf(s, xnrm2_PWt4zgS1(2, A, 7));
      if (s >= 0.0F) {
        beta1 = -beta1;
      }

      s = 1.0F / (s - beta1);
      for (aoffset = 6; aoffset < 8; aoffset++) {
        A[aoffset] *= s;
      }

      for (coffset = 0; coffset <= knt; coffset++) {
        beta1 *= 9.86076132E-32F;
      }

      s = beta1;
    } else {
      s = 1.0F / (A[5] - beta1);
      for (coffset = 6; coffset < 8; coffset++) {
        A[coffset] *= s;
      }

      s = beta1;
    }
  }

  A[5] = s;
  Jacobian[0] = A[0];
  for (knt = 0; knt < 2; knt++) {
    Jacobian[knt + 2] = A[knt + 4];
  }

  S[0] = Jacobian[0];
  S[1] = Jacobian[2];
  S[2] = 0.0F;
  S[3] = Jacobian[3];
}

// Model step function
void ControlClass::update()
{
  b_dsp_FIRFilter_0_controlMode_T *obj_0;
  b_dspcodegen_FIRFilter_contro_T *obj;
  int32_T A_tmp;
  int32_T n;
  real32_T A[4];
  real32_T Ss[4];
  real32_T rtb_Q[4];
  real32_T C[2];
  real32_T K[2];
  real32_T s[2];
  real32_T Rsqrt;
  real32_T b_s;
  real32_T rtb_CCaller;
  real32_T unusedExpr;
  real32_T zEstimated;
  boolean_T guard1 = false;

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
  b_s = controlModel_U.torque;
  rtb_CCaller = 0.0F;

  // load input sample
  for (n = 0; n < 20; n++) {
    // shift state
    unusedExpr = b_s;
    b_s = obj_0->W0_states[n];
    obj_0->W0_states[n] = unusedExpr;

    // compute one tap
    unusedExpr *= obj_0->P1_Coefficients[n];
    rtb_CCaller += unusedExpr;
  }

  // compute last tap
  unusedExpr = obj->cSFunObject.P1_Coefficients[n] * b_s;

  // store output sample
  b_s = rtb_CCaller + unusedExpr;

  // DeadZone: '<Root>/Dead Zone' incorporates:
  //   MATLABSystem: '<Root>/Lowpass Filter'

  if (b_s > controlParams.riderTrqTreshold) {
    rtb_CCaller = b_s - controlParams.riderTrqTreshold;
  } else if (b_s >= (-controlParams.riderTrqTreshold)) {
    rtb_CCaller = 0.0F;
  } else {
    rtb_CCaller = b_s - (-controlParams.riderTrqTreshold);
  }

  // End of DeadZone: '<Root>/Dead Zone'

  // Gain: '<Root>/Trq const' incorporates:
  //   Gain: '<Root>/Belt and gear'
  //   Gain: '<Root>/Gain'

  rtb_CCaller = ((1.0F / (controlParams.beltRatio * controlParams.gearRatio)) *
                 (controlParams.trqGainControl * rtb_CCaller)) * (1.0F /
    controlParams.trqConstant);

  // Saturate: '<Root>/Saturation'
  if (rtb_CCaller > controlParams.maxCurrent) {
    // Outport: '<Root>/curr_ref'
    controlModel_Y.curr_ref = controlParams.maxCurrent;
  } else if (rtb_CCaller < (-controlParams.maxCurrent)) {
    // Outport: '<Root>/curr_ref'
    controlModel_Y.curr_ref = -controlParams.maxCurrent;
  } else {
    // Outport: '<Root>/curr_ref'
    controlModel_Y.curr_ref = rtb_CCaller;
  }

  // End of Saturate: '<Root>/Saturation'

  // Outport: '<Root>/user_data' incorporates:
  //   CCaller: '<Root>/C Caller'
  //   Constant: '<Root>/Constant4'
  //   Constant: '<Root>/Constant6'
  //   MATLABSystem: '<Root>/Lowpass Filter'

  controlModel_Y.user_data[1] = 0; //getTimer();
  controlModel_Y.user_data[0] = b_s;
  controlModel_Y.user_data[2] = 0.0F;
  controlModel_Y.user_data[3] = 0.0F;

  // Outport: '<Root>/throttle_ref' incorporates:
  //   Constant: '<Root>/Constant1'

  controlModel_Y.throttle_ref = 0.0F;

  // MATLAB Function: '<Root>/Q and R'
  K[0] = controlParams.Qphi;
  K[1] = controlParams.Qomx;
  rtb_Q[1] = 0.0F;
  rtb_Q[2] = 0.0F;
  rtb_Q[0] = controlParams.Qphi;
  rtb_Q[3] = controlParams.Qomx;

  // Outputs for Enabled SubSystem: '<S1>/Correct1' incorporates:
  //   EnablePort: '<S9>/Enable'

  // MATLAB Function: '<S9>/Correct' incorporates:
  //   Constant: '<S1>/BlockOrdering'
  //   DataStoreRead: '<S9>/Data Store ReadX'
  //   DataStoreWrite: '<S9>/Data Store WriteP'
  //   Inport: '<Root>/gyros'
  //   MATLAB Function: '<Root>/Q and R'

  controlModel_DW.blockOrdering = true;

  //  ekfCorrect Correction step for EKF
  //
  //    Copyright 2016-2018 The MathWorks, Inc.
  //  If measurement noise is time-varying then compute square-root
  //  factorization.
  if (static_cast<boolean_T>(static_cast<int32_T>(((static_cast<boolean_T>(
           static_cast<int32_T>((rtIsInfF(controlParams.Romx) ?
             (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) ^ 1))) ? (
          static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) & ((static_cast<
          boolean_T>(static_cast<int32_T>((rtIsNaNF(controlParams.Romx) ? (
              static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) ^ 1))) ? (
          static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) {
    b_s = controlParams.Romx;
    rtb_CCaller = 1.0F;
    if (controlParams.Romx != 0.0F) {
      b_s = std::abs(controlParams.Romx);
    }

    if (b_s < 0.0F) {
      b_s = -b_s;
      rtb_CCaller = -1.0F;
    }
  } else {
    b_s = (rtNaNF);
    rtb_CCaller = (rtNaNF);
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
  EKFCorrectorAdditive_getMeasure(rtb_CCaller * std::sqrt(b_s),
    controlModel_DW.x, controlModel_DW.P, &zEstimated, K, &unusedExpr, s, &Rsqrt);
  b_s = controlModel_U.gyros[0] - zEstimated;
  C[0] = K[0];
  C[1] = K[1];
  trisolve_OvFIvCwp(unusedExpr, C);
  K[0] = C[0];
  K[1] = C[1];
  trisolve_OvFIvCwp(unusedExpr, K);
  A[0] = (-K[0]) * s[0];
  A[1] = (-K[1]) * s[0];
  A[2] = (-K[0]) * s[1];
  A[3] = (-K[1]) * s[1];
  C[0] = K[0] * Rsqrt;
  A[0]++;
  C[1] = K[1] * Rsqrt;
  A[3]++;
  qrFactor_rz4DISpF(A, controlModel_DW.P, C);

  // DataStoreWrite: '<S9>/Data Store WriteX' incorporates:
  //   DataStoreRead: '<S9>/Data Store ReadX'
  //   MATLAB Function: '<S9>/Correct'

  //  Get back Covariance from Square-root Covariance
  controlModel_DW.x[0] += K[0] * b_s;

  // End of Outputs for SubSystem: '<S1>/Correct1'

  // Outputs for Atomic SubSystem: '<S1>/Predict'
  // MATLAB Function: '<S11>/Predict' incorporates:
  //   DataStoreRead: '<S11>/Data Store ReadX'

  K[0] = controlModel_DW.x[0];

  // End of Outputs for SubSystem: '<S1>/Predict'

  // Outputs for Enabled SubSystem: '<S1>/Correct1' incorporates:
  //   EnablePort: '<S9>/Enable'

  // DataStoreWrite: '<S9>/Data Store WriteX' incorporates:
  //   DataStoreRead: '<S9>/Data Store ReadX'
  //   MATLAB Function: '<S9>/Correct'

  controlModel_DW.x[1] += K[1] * b_s;

  // End of Outputs for SubSystem: '<S1>/Correct1'

  // Outputs for Atomic SubSystem: '<S1>/Predict'
  // MATLAB Function: '<S11>/Predict' incorporates:
  //   DataStoreRead: '<S11>/Data Store ReadX'

  K[1] = controlModel_DW.x[1];

  // End of Outputs for SubSystem: '<S1>/Predict'

  // Outport: '<Root>/roll_est' incorporates:
  //   DataStoreRead: '<S10>/Data Store Read'

  controlModel_Y.roll_est = controlModel_DW.x[0];

  // Outputs for Atomic SubSystem: '<S1>/Predict'
  // MATLAB Function: '<S11>/Predict' incorporates:
  //   DataStoreRead: '<S11>/Data Store ReadX'
  //   DataStoreWrite: '<S11>/Data Store WriteP'
  //   MATLAB Function: '<Root>/Q and R'

  //  ekfCorrect Prediction step for EKF
  //
  //    Copyright 2016-2017 The MathWorks, Inc.
  //  If process noise is time-varying then compute square-root
  //  factorization.
  guard1 = false;
  if (static_cast<boolean_T>(static_cast<int32_T>(((static_cast<boolean_T>(
           static_cast<int32_T>((rtIsInfF(controlParams.Qphi) ?
             (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) ^ 1))) ? (
          static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) & ((static_cast<
          boolean_T>(static_cast<int32_T>((rtIsNaNF(controlParams.Qphi) ? (
              static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) ^ 1))) ? (
          static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) {
    if (static_cast<boolean_T>(static_cast<int32_T>(((static_cast<boolean_T>(
             static_cast<int32_T>((rtIsInfF(controlParams.Qomx) ? (static_cast<
                int32_T>(1)) : (static_cast<int32_T>(0))) ^ 1))) ? (static_cast<
            int32_T>(1)) : (static_cast<int32_T>(0))) & ((static_cast<boolean_T>
            (static_cast<int32_T>((rtIsNaNF(controlParams.Qomx) ?
               (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) ^ 1))) ? (
            static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) {
      svd_RbbuN3t6(rtb_Q, Ss, s, A);
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1) {
    s[0] = (rtNaNF);
    s[1] = (rtNaNF);
    A[0] = (rtNaNF);
    A[1] = (rtNaNF);
    A[2] = (rtNaNF);
    A[3] = (rtNaNF);
  }

  Ss[0] = std::sqrt(s[0]);
  Ss[1] = 0.0F;
  Ss[2] = 0.0F;
  Ss[3] = std::sqrt(s[1]);

  //  Construct fcn handles
  //  Check if dimensions and type of State and Jacobian are correct
  //  Additive noise
  //  StateTransitionFcn
  rollEKF_stateTransitionModel(controlModel_DW.x, s);

  //  Jacobian
  rollEKF_stateTransitionJac(controlModel_DW.x, rtb_Q);

  //  F needs to be square
  for (n = 0; n < 2; n++) {
    A_tmp = (n << 1ULL);
    rtb_Q[A_tmp] = 0.0F;
    b_s = Ss[A_tmp];
    rtb_Q[A_tmp] += b_s * A[0];
    rtb_CCaller = Ss[A_tmp + 1];
    rtb_Q[A_tmp] += rtb_CCaller * A[2];
    rtb_Q[A_tmp + 1] = 0.0F;
    rtb_Q[A_tmp + 1] += b_s * A[1];
    rtb_Q[A_tmp + 1] += rtb_CCaller * A[3];
  }

  co_EKFPredictorAdditive_predict(rtb_Q, K, controlModel_DW.P);

  // End of Outputs for SubSystem: '<S1>/Predict'

  // Outport: '<Root>/yaw_est' incorporates:
  //   Constant: '<Root>/Constant2'

  controlModel_Y.yaw_est = 0.0F;

  // Outputs for Atomic SubSystem: '<S1>/Predict'
  // DataStoreWrite: '<S11>/Data Store WriteX' incorporates:
  //   MATLAB Function: '<S11>/Predict'

  controlModel_DW.x[0] = K[0];

  // End of Outputs for SubSystem: '<S1>/Predict'

  // Outport: '<Root>/pos_est'
  controlModel_Y.pos_est[0] = 0.0F;

  // Outputs for Atomic SubSystem: '<S1>/Predict'
  // DataStoreWrite: '<S11>/Data Store WriteX' incorporates:
  //   MATLAB Function: '<S11>/Predict'

  controlModel_DW.x[1] = K[1];

  // End of Outputs for SubSystem: '<S1>/Predict'

  // Outport: '<Root>/pos_est'
  controlModel_Y.pos_est[1] = 0.0F;

  // Outport: '<Root>/error_state_out' incorporates:
  //   UnitDelay: '<Root>/Unit Delay'

  controlModel_Y.error_state_out = controlModel_DW.error_state;

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
    int32_T i;
    static const real32_T tmp[21] = { -0.000803169096F, -0.00341077754F,
      -0.00823236164F, -0.0131849619F, -0.0126657868F, 0.00105571444F,
      0.0335894823F, 0.0833384693F, 0.139194697F, 0.183665663F, 0.200662464F,
      0.183665663F, 0.139194697F, 0.0833384693F, 0.0335894823F, 0.00105571444F,
      -0.0126657868F, -0.0131849619F, -0.00823236164F, -0.00341077754F,
      -0.000803169096F };

    // Start for DataStoreMemory: '<S1>/DataStoreMemory - P'
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

    // System object Constructor function: dsp.FIRFilter
    iobj_0->cSFunObject.P0_InitialStates = 0.0F;
    for (i = 0; i < 21; i++) {
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
      for (i = 0; i < 20; i++) {
        iobj_0->cSFunObject.W0_states[i] = iobj_0->cSFunObject.P0_InitialStates;
      }
    }

    // End of InitializeConditions for MATLABSystem: '<Root>/Lowpass Filter'

    // Outputs for Atomic SubSystem: '<Root>/Initialize Function'
    // CCaller: '<S2>/C Caller'
    //initTimer();

    // End of Outputs for SubSystem: '<Root>/Initialize Function'
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
ControlClass::ControlClass() :
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
