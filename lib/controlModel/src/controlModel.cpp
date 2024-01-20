//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controlModel.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 4.99
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Sat Jan 20 19:19:11 2024
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
#include "rtwtypes.h"
#include <cmath>
#include "controlModel_private.h"

extern "C"
{

#include "rt_nonfinite.h"

}

#include "rt_defines.h"
#include "zero_crossing_types.h"

// Named constants for Chart: '<Root>/Chart'
const uint8_T controlModel_IN_CHECKSTEER = 1U;
const uint8_T controlModel_IN_UPDATEERR = 2U;

// Named constants for Chart: '<Root>/Chart1'
const uint8_T controlModel_IN_IDLE = 1U;
const uint8_T controlModel_IN_SETCURR = 2U;

// Exported data definition

// Definition for custom storage class: Struct
controlParams_type controlParams = {
  // gravity
  9.806F,

  // maxCurrent
  10.0F,

  // maxSteer
  0.34906584F,

  // rollSaturation
  0.5F,

  // speedMinCtrl
  1.0F
};

//
// Output and update for atomic system:
//    '<S108>/SqrtUsedFcn'
//    '<S160>/SqrtUsedFcn'
//
void ControlClass::controlModel_SqrtUsedFcn(const real32_T rtu_u[9], boolean_T
  rtu_isSqrtUsed, real32_T rty_P[9])
{
  //  Determine if the Square-Root algorithm was used
  if (rtu_isSqrtUsed) {
    for (int32_T i = 0; i < 3; i++) {
      for (int32_T i_0 = 0; i_0 < 3; i_0++) {
        rty_P[i + (3 * i_0)] = ((rtu_u[i + 3] * rtu_u[i_0 + 3]) + (rtu_u[i] *
          rtu_u[i_0])) + (rtu_u[i + 6] * rtu_u[i_0 + 6]);
      }
    }
  } else {
    for (int32_T i = 0; i < 3; i++) {
      for (int32_T i_0 = 0; i_0 < 3; i_0++) {
        rty_P[i + (3 * i_0)] = rtu_u[(3 * i_0) + i];
      }
    }
  }
}

//
// Disable for enable system:
//    '<S81>/MeasurementUpdate'
//    '<S133>/MeasurementUpdate'
//
void ControlClass::contr_MeasurementUpdate_Disable(real32_T rty_Lykyhatkk1[3],
  DW_MeasurementUpdate_controlM_T *localDW)
{
  // Outputs for Enabled SubSystem: '<S81>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S110>/Enable'

  // Disable for Outport: '<S110>/L*(y[k]-yhat[k|k-1])'
  rty_Lykyhatkk1[0] = 0.0F;
  rty_Lykyhatkk1[1] = 0.0F;
  rty_Lykyhatkk1[2] = 0.0F;

  // End of Outputs for SubSystem: '<S81>/MeasurementUpdate'
  localDW->MeasurementUpdate_MODE = false;
}

//
// Output and update for enable system:
//    '<S81>/MeasurementUpdate'
//    '<S133>/MeasurementUpdate'
//
void ControlClass::controlModel_MeasurementUpdate(boolean_T rtu_Enable, const
  real32_T rtu_Lk[6], const real32_T rtu_yk[2], const real32_T rtu_Ck[6], const
  real32_T rtu_xhatkk1[3], const real32_T rtu_Dk[2], real32_T rtu_uk, real32_T
  rty_Lykyhatkk1[3], DW_MeasurementUpdate_controlM_T *localDW)
{
  real32_T rtu_yk_0[2];

  // Outputs for Enabled SubSystem: '<S81>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S110>/Enable'

  if (rtu_Enable) {
    localDW->MeasurementUpdate_MODE = true;
    for (int32_T i = 0; i < 2; i++) {
      // Sum: '<S110>/Sum' incorporates:
      //   Product: '<S110>/C[k]*xhat[k|k-1]'
      //   Product: '<S110>/D[k]*u[k]'
      //   Sum: '<S110>/Add1'

      rtu_yk_0[i] = rtu_yk[i] - ((((rtu_Ck[i + 2] * rtu_xhatkk1[1]) + (rtu_Ck[i]
        * rtu_xhatkk1[0])) + (rtu_Ck[i + 4] * rtu_xhatkk1[2])) + (rtu_Dk[i] *
        rtu_uk));
    }

    // Product: '<S110>/Product3'
    for (int32_T i = 0; i < 3; i++) {
      rty_Lykyhatkk1[i] = 0.0F;
      rty_Lykyhatkk1[i] += rtu_Lk[i] * rtu_yk_0[0];
      rty_Lykyhatkk1[i] += rtu_Lk[i + 3] * rtu_yk_0[1];
    }

    // End of Product: '<S110>/Product3'
  } else if (localDW->MeasurementUpdate_MODE) {
    contr_MeasurementUpdate_Disable(rty_Lykyhatkk1, localDW);
  } else {
    // no actions
  }

  // End of Outputs for SubSystem: '<S81>/MeasurementUpdate'
}

//
// Disable for enable system:
//    '<S87>/Enabled Subsystem'
//    '<S139>/Enabled Subsystem'
//
void ControlClass::contro_EnabledSubsystem_Disable(real32_T rty_deltax[3],
  DW_EnabledSubsystem_controlMo_T *localDW)
{
  // Outputs for Enabled SubSystem: '<S87>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S112>/Enable'

  // Disable for Outport: '<S112>/deltax'
  rty_deltax[0] = 0.0F;
  rty_deltax[1] = 0.0F;
  rty_deltax[2] = 0.0F;

  // End of Outputs for SubSystem: '<S87>/Enabled Subsystem'
  localDW->EnabledSubsystem_MODE = false;
}

//
// Output and update for enable system:
//    '<S87>/Enabled Subsystem'
//    '<S139>/Enabled Subsystem'
//
void ControlClass::controlModel_EnabledSubsystem(boolean_T rtu_Enable, const
  real32_T rtu_Mk[6], const real32_T rtu_Ck[6], const real32_T rtu_yk[2], const
  real32_T rtu_xhatkk1[3], real32_T rty_deltax[3],
  DW_EnabledSubsystem_controlMo_T *localDW)
{
  real32_T rtu_yk_0[2];

  // Outputs for Enabled SubSystem: '<S87>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S112>/Enable'

  if (rtu_Enable) {
    localDW->EnabledSubsystem_MODE = true;

    // Sum: '<S112>/Add1' incorporates:
    //   Product: '<S112>/Product'

    for (int32_T i = 0; i < 2; i++) {
      rtu_yk_0[i] = rtu_yk[i] - (((rtu_Ck[i + 2] * rtu_xhatkk1[1]) + (rtu_Ck[i] *
        rtu_xhatkk1[0])) + (rtu_Ck[i + 4] * rtu_xhatkk1[2]));
    }

    // End of Sum: '<S112>/Add1'

    // Product: '<S112>/Product2'
    for (int32_T i = 0; i < 3; i++) {
      rty_deltax[i] = 0.0F;
      rty_deltax[i] += rtu_Mk[i] * rtu_yk_0[0];
      rty_deltax[i] += rtu_Mk[i + 3] * rtu_yk_0[1];
    }

    // End of Product: '<S112>/Product2'
  } else if (localDW->EnabledSubsystem_MODE) {
    contro_EnabledSubsystem_Disable(rty_deltax, localDW);
  } else {
    // no actions
  }

  // End of Outputs for SubSystem: '<S87>/Enabled Subsystem'
}

real32_T rt_atan2f_snf(real32_T u0, real32_T u1)
{
  real32_T y;
  if (static_cast<boolean_T>(static_cast<int32_T>((rtIsNaNF(u0) ?
         (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) | (rtIsNaNF(u1) ?
         (static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) {
    y = (rtNaNF);
  } else if (static_cast<boolean_T>(static_cast<int32_T>((rtIsInfF(u0) ? (
      static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) & (rtIsInfF(u1) ? (
      static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))))) {
    int32_T tmp;
    int32_T tmp_0;
    if (u0 > 0.0F) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u1 > 0.0F) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = std::atan2(static_cast<real32_T>(tmp), static_cast<real32_T>(tmp_0));
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

// Model step function
void ControlClass::update()
{
  real32_T rtb_P_b[9];
  real32_T tmp[3];
  real32_T tmp_0[3];
  real32_T rtb_Reshapey[2];
  real32_T Product3_a_idx_0;
  real32_T rtb_Exp;
  real32_T rtb_Product5;
  real32_T rtb_Sum;
  real32_T tmp_1;
  real32_T tmp_2;
  boolean_T rtb_Compare;

  // Reshape: '<S6>/Reshapey' incorporates:
  //   Inport: '<Root>/dist'
  //   Inport: '<Root>/speed'

  rtb_Reshapey[0] = controlModel_U.dist;
  rtb_Reshapey[1] = controlModel_U.speed;

  // Delay: '<S6>/MemoryX' incorporates:
  //   Constant: '<S6>/X0'

  if (controlModel_DW.icLoad) {
    controlModel_DW.MemoryX_DSTATE[0] = 0.0F;
    controlModel_DW.MemoryX_DSTATE[1] = 0.0F;
    controlModel_DW.MemoryX_DSTATE[2] = 0.0F;
  }

  // Outputs for Enabled SubSystem: '<S87>/Enabled Subsystem'
  // Constant: '<S6>/Enable' incorporates:
  //   Constant: '<S6>/C'
  //   Constant: '<S6>/D'
  //   Delay: '<S6>/MemoryX'
  //   Inport: '<Root>/speed'

  controlModel_EnabledSubsystem(true, controlModel_ConstB.Conversion_l,
    controlModel_ConstP.pooled5, rtb_Reshapey, controlModel_DW.MemoryX_DSTATE,
    controlModel_DW.Product2_c, &controlModel_DW.EnabledSubsystem_p);

  // End of Outputs for SubSystem: '<S87>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S81>/MeasurementUpdate'
  controlModel_MeasurementUpdate(true, controlModel_ConstB.Conversion_b,
    rtb_Reshapey, controlModel_ConstP.pooled5, controlModel_DW.MemoryX_DSTATE,
    controlModel_ConstP.pooled7, controlModel_U.speed,
    controlModel_DW.Product3_p, &controlModel_DW.MeasurementUpdate_p);

  // End of Outputs for SubSystem: '<S81>/MeasurementUpdate'

  // Sum: '<S87>/Add' incorporates:
  //   Delay: '<S6>/MemoryX'

  rtb_Product5 = controlModel_DW.Product2_c[0] + controlModel_DW.MemoryX_DSTATE
    [0];
  tmp_1 = controlModel_DW.Product2_c[1] + controlModel_DW.MemoryX_DSTATE[1];
  tmp_2 = controlModel_DW.Product2_c[2] + controlModel_DW.MemoryX_DSTATE[2];

  // Product: '<S62>/Product' incorporates:
  //   Constant: '<S6>/C'

  for (int32_T i = 0; i < 2; i++) {
    rtb_Reshapey[i] = ((controlModel_ConstP.pooled5[i + 2] * tmp_1) +
                       (controlModel_ConstP.pooled5[i] * rtb_Product5)) +
      (controlModel_ConstP.pooled5[i + 4] * tmp_2);
  }

  // End of Product: '<S62>/Product'

  // Outport: '<Root>/dist_est'
  controlModel_Y.dist_est = rtb_Reshapey[0];

  // Outport: '<Root>/speed_est'
  controlModel_Y.speed_est = rtb_Reshapey[1];

  // Delay: '<S4>/MemoryX' incorporates:
  //   Constant: '<S4>/X0'

  if (controlModel_DW.icLoad_d) {
    controlModel_DW.MemoryX_DSTATE_g[0] = 0.0F;
    controlModel_DW.MemoryX_DSTATE_g[1] = 0.0F;
  }

  // Math: '<S7>/Exp' incorporates:
  //   Gain: '<S7>/Gain'
  //   Math: '<S7>/Square'
  //
  //  About '<S7>/Exp':
  //   Operator: exp

  rtb_Exp = std::exp((rtb_Reshapey[1] * rtb_Reshapey[1]) * -99.9999924F);

  // Product: '<Root>/Product5' incorporates:
  //   Inport: '<Root>/accs'
  //   Trigonometry: '<Root>/Atan1'

  rtb_Product5 = rt_atan2f_snf(controlModel_U.accs[1], controlModel_U.accs[2]) *
    rtb_Exp;

  // Sum: '<S7>/Sum' incorporates:
  //   Constant: '<S7>/Constant'

  rtb_Sum = 1.0F - rtb_Exp;

  // UnitDelay: '<Root>/Unit Delay'
  rtb_Exp = controlModel_DW.UnitDelay_DSTATE;

  // Math: '<S5>/Exp' incorporates:
  //   Gain: '<S5>/Gain'
  //   Math: '<S5>/Square'
  //
  //  About '<S5>/Exp':
  //   Operator: exp

  rtb_Exp = std::exp((rtb_Exp * rtb_Exp) * -99.9999924F);

  // Product: '<Root>/Divide' incorporates:
  //   Inport: '<Root>/gyros'
  //   Math: '<Root>/Square'
  //   Math: '<Root>/Square1'
  //   Sqrt: '<Root>/Square Root'
  //   Sum: '<Root>/Sum3'

  tmp_1 = (1.0F / std::sqrt((controlModel_U.gyros[2] * controlModel_U.gyros[2])
            + (controlModel_U.gyros[1] * controlModel_U.gyros[1]))) *
    controlModel_U.gyros[1];

  // Signum: '<Root>/Sign' incorporates:
  //   Inport: '<Root>/gyros'

  if (rtIsNaNF(controlModel_U.gyros[2])) {
    Product3_a_idx_0 = (rtNaNF);
  } else if (controlModel_U.gyros[2] < 0.0F) {
    Product3_a_idx_0 = -1.0F;
  } else {
    Product3_a_idx_0 = static_cast<real32_T>((controlModel_U.gyros[2] > 0.0F) ?
      (static_cast<int32_T>(1)) : (static_cast<int32_T>(0)));
  }

  // Trigonometry: '<Root>/Asin'
  if (tmp_1 > 1.0F) {
    tmp_1 = 1.0F;
  } else if (tmp_1 < -1.0F) {
    tmp_1 = -1.0F;
  } else {
    // no actions
  }

  // Product: '<Root>/Product4' incorporates:
  //   Signum: '<Root>/Sign'
  //   Trigonometry: '<Root>/Asin'

  tmp_1 = Product3_a_idx_0 * std::asin(tmp_1);

  // Saturate: '<Root>/Saturation1'
  if (tmp_1 > controlParams.rollSaturation) {
    tmp_1 = controlParams.rollSaturation;
  } else if (tmp_1 < (-controlParams.rollSaturation)) {
    tmp_1 = -controlParams.rollSaturation;
  } else {
    // no actions
  }

  // Sum: '<Root>/Sum2' incorporates:
  //   Constant: '<S5>/Constant'
  //   Gain: '<Root>/Gain'
  //   Inport: '<Root>/gyros'
  //   Product: '<Root>/Product'
  //   Product: '<Root>/Product1'
  //   Product: '<Root>/Product2'
  //   Product: '<Root>/Product3'
  //   Saturate: '<Root>/Saturation1'
  //   Sum: '<Root>/Sum1'
  //   Sum: '<S5>/Sum'
  //   Trigonometry: '<Root>/Atan'

  rtb_Exp = (((std::atan((1.0F / controlParams.gravity) * (rtb_Reshapey[1] *
    controlModel_U.gyros[2])) * rtb_Exp) + ((1.0F - rtb_Exp) * tmp_1)) * rtb_Sum)
    + rtb_Product5;

  // Outputs for Enabled SubSystem: '<S35>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S60>/Enable'

  // Outputs for Enabled SubSystem: '<S29>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S58>/Enable'

  // Product: '<S58>/C[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S4>/C'
  //   Delay: '<S4>/MemoryX'
  //   Product: '<S60>/Product'

  tmp_1 = (0.0F * controlModel_DW.MemoryX_DSTATE_g[1]) +
    controlModel_DW.MemoryX_DSTATE_g[0];

  // End of Outputs for SubSystem: '<S35>/Enabled Subsystem'

  // Sum: '<S58>/Sum' incorporates:
  //   Constant: '<S4>/D'
  //   Inport: '<Root>/gyros'
  //   Product: '<S58>/C[k]*xhat[k|k-1]'
  //   Product: '<S58>/D[k]*u[k]'
  //   Sum: '<S58>/Add1'

  rtb_Product5 = rtb_Exp - ((0.0F * controlModel_U.gyros[0]) + tmp_1);

  // Product: '<S58>/Product3' incorporates:
  //   DataTypeConversion: '<S51>/Conversion'

  Product3_a_idx_0 = controlModel_ConstB.Conversion[0] * rtb_Product5;
  rtb_Sum = controlModel_ConstB.Conversion[1] * rtb_Product5;

  // End of Outputs for SubSystem: '<S29>/MeasurementUpdate'

  // Outputs for Enabled SubSystem: '<S35>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S60>/Enable'

  // Sum: '<S60>/Add1'
  rtb_Product5 = rtb_Exp - tmp_1;

  // Product: '<S10>/Product' incorporates:
  //   Constant: '<S4>/C'
  //   DataTypeConversion: '<S52>/Conversion'
  //   Delay: '<S4>/MemoryX'
  //   Product: '<S60>/Product2'
  //   Sum: '<S35>/Add'

  rtb_Exp = (((controlModel_ConstB.Conversion_i[1] * rtb_Product5) +
              controlModel_DW.MemoryX_DSTATE_g[1]) * 0.0F) +
    ((controlModel_ConstB.Conversion_i[0] * rtb_Product5) +
     controlModel_DW.MemoryX_DSTATE_g[0]);

  // End of Outputs for SubSystem: '<S35>/Enabled Subsystem'

  // Outport: '<Root>/roll_est' incorporates:
  //   Product: '<S10>/Product'

  controlModel_Y.roll_est = rtb_Exp;

  // RelationalOperator: '<S3>/Compare' incorporates:
  //   Constant: '<S3>/Constant'

  rtb_Compare = (rtb_Reshapey[1] >= controlParams.speedMinCtrl);

  // DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn'
  if (static_cast<boolean_T>(static_cast<int32_T>(((((static_cast<uint32_T>
            (controlModel_PrevZCX.DiscreteTransferFcn_Reset_ZCE)) == POS_ZCSIG)
          != rtb_Compare) ? (static_cast<int32_T>(1)) : (static_cast<int32_T>(0)))
        & (((static_cast<uint32_T>
             (controlModel_PrevZCX.DiscreteTransferFcn_Reset_ZCE)) !=
            UNINITIALIZED_ZCSIG) ? (static_cast<int32_T>(1)) :
           (static_cast<int32_T>(0)))))) {
    controlModel_DW.DiscreteTransferFcn_states = 0.0F;
  }

  controlModel_PrevZCX.DiscreteTransferFcn_Reset_ZCE = rtb_Compare ? (
    static_cast<ZCSigState>(1)) : (static_cast<ZCSigState>(0));

  // Product: '<Root>/Product6' incorporates:
  //   DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn'

  rtb_Product5 = (4.29489565F * controlModel_DW.DiscreteTransferFcn_states) * (
    static_cast<real32_T>(rtb_Compare ? 1.0F : 0.0F));

  // Saturate: '<Root>/Saturation'
  if (rtb_Product5 > controlParams.maxCurrent) {
    rtb_Product5 = controlParams.maxCurrent;
  } else if (rtb_Product5 < (-controlParams.maxCurrent)) {
    rtb_Product5 = -controlParams.maxCurrent;
  } else {
    // no actions
  }

  // End of Saturate: '<Root>/Saturation'

  // Chart: '<Root>/Chart' incorporates:
  //   Inport: '<Root>/error_state_in'
  //   Inport: '<Root>/steer'
  //   Outport: '<Root>/error_state_out'

  if ((static_cast<uint32_T>(controlModel_DW.is_active_c3_controlModel)) == 0U)
  {
    controlModel_DW.is_active_c3_controlModel = 1U;
    controlModel_DW.is_c3_controlModel = controlModel_IN_UPDATEERR;

    // Outport: '<Root>/error_state_out' incorporates:
    //   Inport: '<Root>/error_state_in'

    controlModel_Y.error_state_out = controlModel_U.error_state_in;
  } else if ((static_cast<uint32_T>(controlModel_DW.is_c3_controlModel)) ==
             controlModel_IN_CHECKSTEER) {
    // Outport: '<Root>/error_state_out'
    controlModel_Y.error_state_out = 1U;

    // case IN_UPDATEERR:
  } else if (controlModel_Y.error_state_out == 0ULL) {
    if (std::abs(controlModel_U.steer[0]) > controlParams.maxSteer) {
      controlModel_DW.is_c3_controlModel = controlModel_IN_CHECKSTEER;
      controlModel_Y.error_state_out = 1U;
    } else {
      controlModel_DW.is_c3_controlModel = controlModel_IN_UPDATEERR;
      controlModel_Y.error_state_out = controlModel_U.error_state_in;
    }
  } else {
    controlModel_Y.error_state_out = controlModel_U.error_state_in;
  }

  // End of Chart: '<Root>/Chart'

  // Chart: '<Root>/Chart1' incorporates:
  //   Outport: '<Root>/error_state_out'

  if ((static_cast<uint32_T>(controlModel_DW.is_active_c1_controlModel)) == 0U)
  {
    controlModel_DW.is_active_c1_controlModel = 1U;
    controlModel_DW.is_c1_controlModel = controlModel_IN_SETCURR;

    // Outport: '<Root>/curr_ref'
    controlModel_Y.curr_ref = rtb_Product5;
  } else if ((static_cast<uint32_T>(controlModel_DW.is_c1_controlModel)) ==
             controlModel_IN_IDLE) {
    // Outport: '<Root>/curr_ref'
    controlModel_Y.curr_ref = 0.0F;

    // case IN_SETCURR:
  } else if (controlModel_Y.error_state_out > 0ULL) {
    controlModel_DW.is_c1_controlModel = controlModel_IN_IDLE;

    // Outport: '<Root>/curr_ref'
    controlModel_Y.curr_ref = 0.0F;
  } else {
    controlModel_DW.is_c1_controlModel = controlModel_IN_SETCURR;

    // Outport: '<Root>/curr_ref'
    controlModel_Y.curr_ref = rtb_Product5;
  }

  // End of Chart: '<Root>/Chart1'

  // Outport: '<Root>/user_data' incorporates:
  //   Constant: '<Root>/Constant3'
  //   Constant: '<Root>/Constant5'
  //   Constant: '<Root>/Constant6'
  //   DataTypeConversion: '<Root>/Data Type Conversion'
  //   Outport: '<Root>/error_state_out'

  controlModel_Y.user_data[0] = 0.0F;
  controlModel_Y.user_data[1] = 0.0F;
  controlModel_Y.user_data[2] = static_cast<real32_T>
    (controlModel_Y.error_state_out);
  controlModel_Y.user_data[3] = 0.0F;

  // MATLAB Function: '<S108>/SqrtUsedFcn' incorporates:
  //   Constant: '<S108>/isSqrtUsed'

  controlModel_SqrtUsedFcn(controlModel_ConstB.Conversion_m, false, rtb_P_b);

  // Delay: '<S8>/MemoryX' incorporates:
  //   Constant: '<S8>/X0'

  if (controlModel_DW.icLoad_a) {
    controlModel_DW.MemoryX_DSTATE_o[0] = 0.0F;
    controlModel_DW.MemoryX_DSTATE_o[1] = 0.0F;
    controlModel_DW.MemoryX_DSTATE_o[2] = 0.0F;
  }

  // Outputs for Enabled SubSystem: '<S139>/Enabled Subsystem'
  // Constant: '<S8>/Enable' incorporates:
  //   Constant: '<S8>/C'
  //   Constant: '<S8>/D'
  //   Delay: '<S8>/MemoryX'
  //   Inport: '<Root>/steer'

  controlModel_EnabledSubsystem(true, controlModel_ConstB.Conversion_k,
    controlModel_ConstP.pooled5, controlModel_U.steer,
    controlModel_DW.MemoryX_DSTATE_o, controlModel_DW.Product2,
    &controlModel_DW.EnabledSubsystem_d);

  // End of Outputs for SubSystem: '<S139>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S133>/MeasurementUpdate'
  controlModel_MeasurementUpdate(true, controlModel_ConstB.Conversion_h,
    controlModel_U.steer, controlModel_ConstP.pooled5,
    controlModel_DW.MemoryX_DSTATE_o, controlModel_ConstP.pooled7,
    controlModel_U.steer[1], controlModel_DW.Product3,
    &controlModel_DW.MeasurementUpdate_c);

  // End of Outputs for SubSystem: '<S133>/MeasurementUpdate'

  // Sum: '<S139>/Add' incorporates:
  //   Delay: '<S8>/MemoryX'

  rtb_Product5 = controlModel_DW.Product2[0] + controlModel_DW.MemoryX_DSTATE_o
    [0];
  tmp_1 = controlModel_DW.Product2[1] + controlModel_DW.MemoryX_DSTATE_o[1];
  tmp_2 = controlModel_DW.Product2[2] + controlModel_DW.MemoryX_DSTATE_o[2];

  // Outport: '<Root>/steer_est' incorporates:
  //   Constant: '<S8>/C'
  //   Product: '<S114>/Product'

  for (int32_T i = 0; i < 2; i++) {
    controlModel_Y.steer_est[i] = 0.0F;
    controlModel_Y.steer_est[i] += controlModel_ConstP.pooled5[i] * rtb_Product5;
    controlModel_Y.steer_est[i] += controlModel_ConstP.pooled5[i + 2] * tmp_1;
    controlModel_Y.steer_est[i] += controlModel_ConstP.pooled5[i + 4] * tmp_2;
  }

  // End of Outport: '<Root>/steer_est'

  // MATLAB Function: '<S160>/SqrtUsedFcn' incorporates:
  //   Constant: '<S160>/isSqrtUsed'

  controlModel_SqrtUsedFcn(controlModel_ConstB.Conversion_n, false, rtb_P_b);

  // Outport: '<Root>/pos_est' incorporates:
  //   Constant: '<Root>/Constant2'

  //  Determine if the Square-Root algorithm was used
  controlModel_Y.pos_est[0] = 0.0F;
  controlModel_Y.pos_est[1] = 0.0F;

  // Outport: '<Root>/throttle_ref' incorporates:
  //   Constant: '<Root>/Constant4'

  controlModel_Y.throttle_ref = 0.0F;

  // Outport: '<Root>/yaw_est' incorporates:
  //   Constant: '<Root>/Constant1'

  controlModel_Y.yaw_est = 0.0F;

  // Update for Delay: '<S6>/MemoryX'
  controlModel_DW.icLoad = false;

  // Update for Delay: '<S4>/MemoryX'
  controlModel_DW.icLoad_d = false;

  // Product: '<S29>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S4>/A'
  //   Delay: '<S4>/MemoryX'

  rtb_Product5 = (-0.001F * controlModel_DW.MemoryX_DSTATE_g[1]) +
    controlModel_DW.MemoryX_DSTATE_g[0];
  tmp_1 = (0.0F * controlModel_DW.MemoryX_DSTATE_g[0]) +
    controlModel_DW.MemoryX_DSTATE_g[1];

  // Update for Delay: '<S4>/MemoryX' incorporates:
  //   Constant: '<S4>/B'
  //   Inport: '<Root>/gyros'
  //   Product: '<S29>/B[k]*u[k]'
  //   Product: '<S58>/Product3'
  //   Sum: '<S29>/Add'

  controlModel_DW.MemoryX_DSTATE_g[0] = ((0.001F * controlModel_U.gyros[0]) +
    rtb_Product5) + Product3_a_idx_0;
  controlModel_DW.MemoryX_DSTATE_g[1] = ((0.0F * controlModel_U.gyros[0]) +
    tmp_1) + rtb_Sum;

  // Update for UnitDelay: '<Root>/Unit Delay' incorporates:
  //   Product: '<S10>/Product'

  controlModel_DW.UnitDelay_DSTATE = rtb_Exp;

  // Update for DiscreteTransferFcn: '<Root>/Discrete Transfer Fcn' incorporates:
  //   Inport: '<Root>/gyros'

  controlModel_DW.DiscreteTransferFcn_states = controlModel_U.gyros[0] -
    (-0.828204155F * controlModel_DW.DiscreteTransferFcn_states);

  // Update for Delay: '<S8>/MemoryX'
  controlModel_DW.icLoad_a = false;
  for (int32_T i = 0; i < 3; i++) {
    // Product: '<S81>/A[k]*xhat[k|k-1]' incorporates:
    //   Constant: '<S6>/A'
    //   Constant: '<S8>/A'
    //   Delay: '<S6>/MemoryX'
    //   Product: '<S133>/A[k]*xhat[k|k-1]'

    Product3_a_idx_0 = controlModel_ConstP.pooled3[i + 3];
    rtb_Exp = controlModel_ConstP.pooled3[i + 6];
    tmp[i] = ((Product3_a_idx_0 * controlModel_DW.MemoryX_DSTATE[1]) +
              (controlModel_ConstP.pooled3[i] * controlModel_DW.MemoryX_DSTATE[0]))
      + (rtb_Exp * controlModel_DW.MemoryX_DSTATE[2]);

    // Product: '<S133>/A[k]*xhat[k|k-1]' incorporates:
    //   Constant: '<S8>/A'
    //   Delay: '<S8>/MemoryX'

    tmp_0[i] = ((Product3_a_idx_0 * controlModel_DW.MemoryX_DSTATE_o[1]) +
                (controlModel_ConstP.pooled3[i] *
                 controlModel_DW.MemoryX_DSTATE_o[0])) + (rtb_Exp *
      controlModel_DW.MemoryX_DSTATE_o[2]);
  }

  // Update for Delay: '<S6>/MemoryX' incorporates:
  //   Constant: '<S6>/B'
  //   Inport: '<Root>/speed'
  //   Product: '<S110>/Product3'
  //   Product: '<S81>/B[k]*u[k]'
  //   Sum: '<S81>/Add'

  controlModel_DW.MemoryX_DSTATE[0] = ((0.0F * controlModel_U.speed) + tmp[0]) +
    controlModel_DW.Product3_p[0];
  controlModel_DW.MemoryX_DSTATE[1] = ((0.0F * controlModel_U.speed) + tmp[1]) +
    controlModel_DW.Product3_p[1];
  controlModel_DW.MemoryX_DSTATE[2] = ((0.0F * controlModel_U.speed) + tmp[2]) +
    controlModel_DW.Product3_p[2];

  // Update for Delay: '<S8>/MemoryX' incorporates:
  //   Constant: '<S8>/B'
  //   Inport: '<Root>/steer'
  //   Product: '<S133>/B[k]*u[k]'
  //   Product: '<S162>/Product3'
  //   Sum: '<S133>/Add'

  controlModel_DW.MemoryX_DSTATE_o[0] = ((0.0F * controlModel_U.steer[1]) +
    tmp_0[0]) + controlModel_DW.Product3[0];
  controlModel_DW.MemoryX_DSTATE_o[1] = ((0.0F * controlModel_U.steer[1]) +
    tmp_0[1]) + controlModel_DW.Product3[1];
  controlModel_DW.MemoryX_DSTATE_o[2] = ((0.0F * controlModel_U.steer[1]) +
    tmp_0[2]) + controlModel_DW.Product3[2];
}

// Model initialize function
void ControlClass::begin()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
  controlModel_PrevZCX.DiscreteTransferFcn_Reset_ZCE = UNINITIALIZED_ZCSIG;

  // InitializeConditions for Delay: '<S6>/MemoryX'
  controlModel_DW.icLoad = true;

  // InitializeConditions for Delay: '<S4>/MemoryX'
  controlModel_DW.icLoad_d = true;

  // InitializeConditions for Delay: '<S8>/MemoryX'
  controlModel_DW.icLoad_a = true;
}

// Model terminate function
void ControlClass::stop()
{
  // (no terminate code required)
}

// Constructor
ControlClass::ControlClass():
  controlModel_U(),
  controlModel_Y(),
  controlModel_DW(),
  controlModel_PrevZCX()
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
