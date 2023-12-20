//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controlModel.cpp
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 4.92
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Thu Sep  7 10:30:43 2023
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

extern "C"
{

#include "rt_nonfinite.h"

}

#include "controlModel_private.h"
#include "controlModel_types.h"
#include "rt_defines.h"

// Named constants for Chart: '<Root>/Chart'
const uint8_T controlModel_IN_CHECKSTEER = 1U;
const uint8_T controlModel_IN_CHECKSTEERDEV = 2U;
const uint8_T controlModel_IN_UPDATEERR = 3U;

// Named constants for Chart: '<Root>/Chart1'
const uint8_T controlModel_IN_IDLE = 1U;
const uint8_T controlModel_IN_SETCURR = 2U;

// Named constants for Chart: '<Root>/Reset lat0 & long0'
const uint8_T controlModel_IN_CHECK = 1U;
const uint8_T controlModel_IN_SET_LAT_LONG = 2U;
const uint8_T controlModel_IN_STOP = 3U;

// Exported data definition

// Definition for custom storage class: Struct
controlParams_type controlParams = {
  // derGainSteerCtrl
  0.0F,

  // intGainSteerCtrl
  50.0F,

  // filtGainSteerCtrl
  100.0F,

  // propGainSteerCtrl
  200.0F,

  // deltaRefGain
  0.0872664601F,

  // gravity
  9.806F,

  // maxCurrent
  10.0F,

  // maxSteer
  0.34906584F,

  // rollSaturation
  0.5F
};

//
// Output and update for atomic system:
//    '<S109>/SqrtUsedFcn'
//    '<S265>/SqrtUsedFcn'
//    '<S317>/SqrtUsedFcn'
//    '<S369>/SqrtUsedFcn'
//
void ControlClass::controlModel_SqrtUsedFcn(const real32_T rtu_u[4], boolean_T
  rtu_isSqrtUsed, real32_T rty_P[4])
{
  //  Determine if the Square-Root algorithm was used
  if (rtu_isSqrtUsed) {
    for (int32_T i = 0; i < 2; i++) {
      real32_T tmp;
      tmp = rtu_u[i + 2];
      rty_P[i] = (tmp * rtu_u[2]) + (rtu_u[i] * rtu_u[0]);
      rty_P[i + 2] = (tmp * rtu_u[3]) + (rtu_u[i] * rtu_u[1]);
    }
  } else {
    for (int32_T i = 0; i < 2; i++) {
      rty_P[i] = rtu_u[i];
      rty_P[i + 2] = rtu_u[i + 2];
    }
  }
}

//
// Disable for enable system:
//    '<S82>/MeasurementUpdate'
//    '<S238>/MeasurementUpdate'
//    '<S290>/MeasurementUpdate'
//    '<S342>/MeasurementUpdate'
//
void ControlClass::contr_MeasurementUpdate_Disable(real32_T rty_Lykyhatkk1[2],
  DW_MeasurementUpdate_controlM_T *localDW)
{
  // Outputs for Enabled SubSystem: '<S82>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S111>/Enable'

  // Disable for Outport: '<S111>/L*(y[k]-yhat[k|k-1])'
  rty_Lykyhatkk1[0] = 0.0F;
  rty_Lykyhatkk1[1] = 0.0F;

  // End of Outputs for SubSystem: '<S82>/MeasurementUpdate'
  localDW->MeasurementUpdate_MODE = false;
}

//
// Output and update for enable system:
//    '<S82>/MeasurementUpdate'
//    '<S238>/MeasurementUpdate'
//    '<S290>/MeasurementUpdate'
//    '<S342>/MeasurementUpdate'
//
void ControlClass::controlModel_MeasurementUpdate(boolean_T rtu_Enable, const
  real32_T rtu_Lk[2], real32_T rtu_yk, const real32_T rtu_Ck[2], const real32_T
  rtu_xhatkk1[2], real32_T rtu_Dk, real32_T rtu_uk, real32_T rty_Lykyhatkk1[2],
  DW_MeasurementUpdate_controlM_T *localDW)
{
  // Outputs for Enabled SubSystem: '<S82>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S111>/Enable'

  if (rtu_Enable) {
    real32_T rtb_Sum_jg;
    localDW->MeasurementUpdate_MODE = true;

    // Sum: '<S111>/Sum' incorporates:
    //   Product: '<S111>/C[k]*xhat[k|k-1]'
    //   Product: '<S111>/D[k]*u[k]'
    //   Sum: '<S111>/Add1'

    rtb_Sum_jg = rtu_yk - (((rtu_Ck[0] * rtu_xhatkk1[0]) + (rtu_Ck[1] *
      rtu_xhatkk1[1])) + (rtu_Dk * rtu_uk));

    // Product: '<S111>/Product3'
    rty_Lykyhatkk1[0] = rtu_Lk[0] * rtb_Sum_jg;
    rty_Lykyhatkk1[1] = rtu_Lk[1] * rtb_Sum_jg;
  } else if (localDW->MeasurementUpdate_MODE) {
    contr_MeasurementUpdate_Disable(rty_Lykyhatkk1, localDW);
  } else {
    // no actions
  }

  // End of Outputs for SubSystem: '<S82>/MeasurementUpdate'
}

//
// Disable for enable system:
//    '<S88>/Enabled Subsystem'
//    '<S244>/Enabled Subsystem'
//    '<S296>/Enabled Subsystem'
//    '<S348>/Enabled Subsystem'
//
void ControlClass::contro_EnabledSubsystem_Disable(real32_T rty_deltax[2],
  DW_EnabledSubsystem_controlMo_T *localDW)
{
  // Outputs for Enabled SubSystem: '<S88>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S113>/Enable'

  // Disable for Outport: '<S113>/deltax'
  rty_deltax[0] = 0.0F;
  rty_deltax[1] = 0.0F;

  // End of Outputs for SubSystem: '<S88>/Enabled Subsystem'
  localDW->EnabledSubsystem_MODE = false;
}

//
// Output and update for enable system:
//    '<S88>/Enabled Subsystem'
//    '<S244>/Enabled Subsystem'
//    '<S296>/Enabled Subsystem'
//    '<S348>/Enabled Subsystem'
//
void ControlClass::controlModel_EnabledSubsystem(boolean_T rtu_Enable, const
  real32_T rtu_Mk[2], const real32_T rtu_Ck[2], real32_T rtu_yk, const real32_T
  rtu_xhatkk1[2], real32_T rty_deltax[2], DW_EnabledSubsystem_controlMo_T
  *localDW)
{
  // Outputs for Enabled SubSystem: '<S88>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S113>/Enable'

  if (rtu_Enable) {
    real32_T rtb_Add1;
    localDW->EnabledSubsystem_MODE = true;

    // Sum: '<S113>/Add1' incorporates:
    //   Product: '<S113>/Product'

    rtb_Add1 = rtu_yk - ((rtu_Ck[0] * rtu_xhatkk1[0]) + (rtu_Ck[1] *
      rtu_xhatkk1[1]));

    // Product: '<S113>/Product2'
    rty_deltax[0] = rtu_Mk[0] * rtb_Add1;
    rty_deltax[1] = rtu_Mk[1] * rtb_Add1;
  } else if (localDW->EnabledSubsystem_MODE) {
    contro_EnabledSubsystem_Disable(rty_deltax, localDW);
  } else {
    // no actions
  }

  // End of Outputs for SubSystem: '<S88>/Enabled Subsystem'
}

//
// Output and update for atomic system:
//    '<S161>/SqrtUsedFcn'
//    '<S213>/SqrtUsedFcn'
//
void ControlClass::controlModel_SqrtUsedFcn_c(const real32_T rtu_u[9], boolean_T
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
//    '<S134>/MeasurementUpdate'
//    '<S186>/MeasurementUpdate'
//
void ControlClass::con_MeasurementUpdate_b_Disable(real32_T rty_Lykyhatkk1[3],
  DW_MeasurementUpdate_contro_l_T *localDW)
{
  // Outputs for Enabled SubSystem: '<S134>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S163>/Enable'

  // Disable for Outport: '<S163>/L*(y[k]-yhat[k|k-1])'
  rty_Lykyhatkk1[0] = 0.0F;
  rty_Lykyhatkk1[1] = 0.0F;
  rty_Lykyhatkk1[2] = 0.0F;

  // End of Outputs for SubSystem: '<S134>/MeasurementUpdate'
  localDW->MeasurementUpdate_MODE = false;
}

//
// Output and update for enable system:
//    '<S134>/MeasurementUpdate'
//    '<S186>/MeasurementUpdate'
//
void ControlClass::controlMode_MeasurementUpdate_p(boolean_T rtu_Enable, const
  real32_T rtu_Lk[6], const real32_T rtu_yk[2], const real32_T rtu_Ck[6], const
  real32_T rtu_xhatkk1[3], const real32_T rtu_Dk[2], real32_T rtu_uk, real32_T
  rty_Lykyhatkk1[3], DW_MeasurementUpdate_contro_l_T *localDW)
{
  real32_T rtu_yk_0[2];

  // Outputs for Enabled SubSystem: '<S134>/MeasurementUpdate' incorporates:
  //   EnablePort: '<S163>/Enable'

  if (rtu_Enable) {
    localDW->MeasurementUpdate_MODE = true;
    for (int32_T i = 0; i < 2; i++) {
      // Sum: '<S163>/Sum' incorporates:
      //   Product: '<S163>/C[k]*xhat[k|k-1]'
      //   Product: '<S163>/D[k]*u[k]'
      //   Sum: '<S163>/Add1'

      rtu_yk_0[i] = rtu_yk[i] - ((((rtu_Ck[i + 2] * rtu_xhatkk1[1]) + (rtu_Ck[i]
        * rtu_xhatkk1[0])) + (rtu_Ck[i + 4] * rtu_xhatkk1[2])) + (rtu_Dk[i] *
        rtu_uk));
    }

    // Product: '<S163>/Product3'
    for (int32_T i = 0; i < 3; i++) {
      rty_Lykyhatkk1[i] = 0.0F;
      rty_Lykyhatkk1[i] += rtu_Lk[i] * rtu_yk_0[0];
      rty_Lykyhatkk1[i] += rtu_Lk[i + 3] * rtu_yk_0[1];
    }

    // End of Product: '<S163>/Product3'
  } else if (localDW->MeasurementUpdate_MODE) {
    con_MeasurementUpdate_b_Disable(rty_Lykyhatkk1, localDW);
  } else {
    // no actions
  }

  // End of Outputs for SubSystem: '<S134>/MeasurementUpdate'
}

//
// Disable for enable system:
//    '<S140>/Enabled Subsystem'
//    '<S192>/Enabled Subsystem'
//
void ControlClass::cont_EnabledSubsystem_l_Disable(real32_T rty_deltax[3],
  DW_EnabledSubsystem_control_p_T *localDW)
{
  // Outputs for Enabled SubSystem: '<S140>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S165>/Enable'

  // Disable for Outport: '<S165>/deltax'
  rty_deltax[0] = 0.0F;
  rty_deltax[1] = 0.0F;
  rty_deltax[2] = 0.0F;

  // End of Outputs for SubSystem: '<S140>/Enabled Subsystem'
  localDW->EnabledSubsystem_MODE = false;
}

//
// Output and update for enable system:
//    '<S140>/Enabled Subsystem'
//    '<S192>/Enabled Subsystem'
//
void ControlClass::controlModel_EnabledSubsystem_p(boolean_T rtu_Enable, const
  real32_T rtu_Mk[6], const real32_T rtu_Ck[6], const real32_T rtu_yk[2], const
  real32_T rtu_xhatkk1[3], real32_T rty_deltax[3],
  DW_EnabledSubsystem_control_p_T *localDW)
{
  real32_T rtu_yk_0[2];

  // Outputs for Enabled SubSystem: '<S140>/Enabled Subsystem' incorporates:
  //   EnablePort: '<S165>/Enable'

  if (rtu_Enable) {
    localDW->EnabledSubsystem_MODE = true;

    // Sum: '<S165>/Add1' incorporates:
    //   Product: '<S165>/Product'

    for (int32_T i = 0; i < 2; i++) {
      rtu_yk_0[i] = rtu_yk[i] - (((rtu_Ck[i + 2] * rtu_xhatkk1[1]) + (rtu_Ck[i] *
        rtu_xhatkk1[0])) + (rtu_Ck[i + 4] * rtu_xhatkk1[2]));
    }

    // End of Sum: '<S165>/Add1'

    // Product: '<S165>/Product2'
    for (int32_T i = 0; i < 3; i++) {
      rty_deltax[i] = 0.0F;
      rty_deltax[i] += rtu_Mk[i] * rtu_yk_0[0];
      rty_deltax[i] += rtu_Mk[i + 3] * rtu_yk_0[1];
    }

    // End of Product: '<S165>/Product2'
  } else if (localDW->EnabledSubsystem_MODE) {
    cont_EnabledSubsystem_l_Disable(rty_deltax, localDW);
  } else {
    // no actions
  }

  // End of Outputs for SubSystem: '<S140>/Enabled Subsystem'
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
  b_dsp_FIRFilter_0_controlMode_T *obj_0;
  b_dspcodegen_FIRFilter_contro_T *obj;
  real32_T rtb_P_i[9];
  real32_T rtb_P_d[4];
  real32_T tmp[3];
  real32_T tmp_0[3];
  real32_T rtb_Add_be[2];
  real32_T rtb_Atan2;
  real32_T rtb_FilterCoefficient;
  real32_T rtb_Gain2;
  real32_T rtb_Product_f_0;
  real32_T rtb_Product_k;
  real32_T rtb_Saturation;
  real32_T rtb_Saturation1;
  real32_T rtb_Sum2;
  real32_T rtb_err_delta;
  real32_T rtb_x;
  real32_T rtb_y;
  real32_T tmp_1;

  // Delay: '<S10>/MemoryX' incorporates:
  //   Constant: '<S10>/X0'

  if (controlModel_DW.icLoad) {
    controlModel_DW.MemoryX_DSTATE[0] = 0.0F;
    controlModel_DW.MemoryX_DSTATE[1] = 0.0F;
    controlModel_DW.MemoryX_DSTATE[2] = 0.0F;
  }

  // Outputs for Enabled SubSystem: '<S192>/Enabled Subsystem'
  // Constant: '<S10>/Enable' incorporates:
  //   Constant: '<S10>/C'
  //   Constant: '<S10>/D'
  //   Delay: '<S10>/MemoryX'
  //   Inport: '<Root>/steer'

  controlModel_EnabledSubsystem_p(true, controlModel_ConstB.Conversion_k,
    controlModel_ConstP.pooled10, controlModel_U.steer,
    controlModel_DW.MemoryX_DSTATE, controlModel_DW.Product2_ba,
    &controlModel_DW.EnabledSubsystem_d);

  // End of Outputs for SubSystem: '<S192>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S186>/MeasurementUpdate'
  controlMode_MeasurementUpdate_p(true, controlModel_ConstB.Conversion,
    controlModel_U.steer, controlModel_ConstP.pooled10,
    controlModel_DW.MemoryX_DSTATE, controlModel_ConstP.pooled11,
    controlModel_U.steer[1], controlModel_DW.Product3_bz,
    &controlModel_DW.MeasurementUpdate_c);

  // End of Outputs for SubSystem: '<S186>/MeasurementUpdate'

  // Sum: '<S192>/Add' incorporates:
  //   Delay: '<S10>/MemoryX'

  rtb_Sum2 = controlModel_DW.Product2_ba[0] + controlModel_DW.MemoryX_DSTATE[0];
  tmp_1 = controlModel_DW.Product2_ba[1] + controlModel_DW.MemoryX_DSTATE[1];
  rtb_Saturation1 = controlModel_DW.Product2_ba[2] +
    controlModel_DW.MemoryX_DSTATE[2];
  for (int32_T i = 0; i < 2; i++) {
    // Product: '<S167>/Product' incorporates:
    //   Constant: '<S10>/C'

    rtb_err_delta = ((controlModel_ConstP.pooled10[i + 2] * tmp_1) +
                     (controlModel_ConstP.pooled10[i] * rtb_Sum2)) +
      (controlModel_ConstP.pooled10[i + 4] * rtb_Saturation1);

    // Outport: '<Root>/steer_est'
    controlModel_Y.steer_est[i] = rtb_err_delta;

    // Product: '<S167>/Product' incorporates:
    //   Constant: '<S10>/C'

    rtb_Add_be[i] = rtb_err_delta;
  }

  // Sum: '<Root>/Sum' incorporates:
  //   Gain: '<Root>/Gain1'
  //   Inport: '<Root>/ref_inputs'

  rtb_err_delta = (controlParams.deltaRefGain * controlModel_U.ref_inputs[1]) -
    rtb_Add_be[0];

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
  } else {
    switch (controlModel_DW.is_c3_controlModel) {
     case controlModel_IN_CHECKSTEER:
      controlModel_DW.is_c3_controlModel = controlModel_IN_CHECKSTEER;

      // Outport: '<Root>/error_state_out'
      controlModel_Y.error_state_out = 1U;
      break;

     case controlModel_IN_CHECKSTEERDEV:
      controlModel_DW.is_c3_controlModel = controlModel_IN_CHECKSTEERDEV;

      // Outport: '<Root>/error_state_out'
      controlModel_Y.error_state_out = 2U;
      break;

     default:
      // case IN_UPDATEERR:
      if (controlModel_Y.error_state_out == 0ULL) {
        if (std::abs(controlModel_U.steer[0]) > controlParams.maxSteer) {
          controlModel_DW.is_c3_controlModel = controlModel_IN_CHECKSTEER;
          controlModel_Y.error_state_out = 1U;
        } else if ((static_cast<real_T>(std::abs(rtb_err_delta))) >
                   0.3490658503988659) {
          controlModel_DW.is_c3_controlModel = controlModel_IN_CHECKSTEERDEV;
          controlModel_Y.error_state_out = 2U;
        } else {
          controlModel_DW.is_c3_controlModel = controlModel_IN_UPDATEERR;
          controlModel_Y.error_state_out = controlModel_U.error_state_in;
        }
      } else {
        controlModel_Y.error_state_out = controlModel_U.error_state_in;
      }
      break;
    }
  }

  // End of Chart: '<Root>/Chart'

  // Outport: '<Root>/user_data' incorporates:
  //   Constant: '<Root>/Constant6'
  //   DataTypeConversion: '<Root>/Data Type Conversion'
  //   Outport: '<Root>/error_state_out'

  controlModel_Y.user_data[0] = 0.0F;
  controlModel_Y.user_data[1] = 0.0F;
  controlModel_Y.user_data[2] = static_cast<real32_T>
    (controlModel_Y.error_state_out);
  controlModel_Y.user_data[3] = 0.0F;

  // Gain: '<S48>/Filter Coefficient' incorporates:
  //   DiscreteIntegrator: '<S40>/Filter'
  //   Gain: '<S39>/Derivative Gain'
  //   Sum: '<S40>/SumD'

  rtb_FilterCoefficient = ((controlParams.derGainSteerCtrl * rtb_err_delta) -
    controlModel_DW.Filter_DSTATE) * controlParams.filtGainSteerCtrl;

  // Sum: '<S54>/Sum' incorporates:
  //   DiscreteIntegrator: '<S45>/Integrator'
  //   Gain: '<S50>/Proportional Gain'

  rtb_Saturation1 = ((controlParams.propGainSteerCtrl * rtb_err_delta) +
                     controlModel_DW.Integrator_DSTATE) + rtb_FilterCoefficient;

  // Saturate: '<S52>/Saturation'
  if (rtb_Saturation1 > controlParams.maxCurrent) {
    rtb_Product_k = controlParams.maxCurrent;
  } else if (rtb_Saturation1 < -10.0F) {
    rtb_Product_k = -10.0F;
  } else {
    rtb_Product_k = rtb_Saturation1;
  }

  // End of Saturate: '<S52>/Saturation'

  // Saturate: '<Root>/Saturation'
  if (rtb_Product_k > controlParams.maxCurrent) {
    rtb_Saturation = controlParams.maxCurrent;
  } else if (rtb_Product_k < (-controlParams.maxCurrent)) {
    rtb_Saturation = -controlParams.maxCurrent;
  } else {
    rtb_Saturation = rtb_Product_k;
  }

  // End of Saturate: '<Root>/Saturation'

  // Chart: '<Root>/Chart1' incorporates:
  //   Outport: '<Root>/error_state_out'

  if ((static_cast<uint32_T>(controlModel_DW.is_active_c1_controlModel)) == 0U)
  {
    controlModel_DW.is_active_c1_controlModel = 1U;
    controlModel_DW.is_c1_controlModel = controlModel_IN_SETCURR;

    // Outport: '<Root>/curr_ref'
    controlModel_Y.curr_ref = rtb_Saturation;
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
    controlModel_Y.curr_ref = rtb_Saturation;
  }

  // End of Chart: '<Root>/Chart1'

  // Sum: '<S38>/SumI2'
  rtb_Saturation = rtb_Product_k - rtb_Saturation1;

  // MATLAB Function: '<S213>/SqrtUsedFcn' incorporates:
  //   Constant: '<S213>/isSqrtUsed'

  controlModel_SqrtUsedFcn_c(controlModel_ConstB.Conversion_n, false, rtb_P_i);

  // Reshape: '<S8>/Reshapey' incorporates:
  //   Inport: '<Root>/dist'
  //   Inport: '<Root>/speed'

  rtb_Add_be[0] = controlModel_U.dist;
  rtb_Add_be[1] = controlModel_U.speed;

  // Delay: '<S8>/MemoryX' incorporates:
  //   Constant: '<S8>/X0'

  if (controlModel_DW.icLoad_i) {
    controlModel_DW.MemoryX_DSTATE_k[0] = 0.0F;
    controlModel_DW.MemoryX_DSTATE_k[1] = 0.0F;
    controlModel_DW.MemoryX_DSTATE_k[2] = 0.0F;
  }

  // Outputs for Enabled SubSystem: '<S140>/Enabled Subsystem'
  // Constant: '<S8>/Enable' incorporates:
  //   Constant: '<S8>/C'
  //   Constant: '<S8>/D'
  //   Delay: '<S8>/MemoryX'
  //   Inport: '<Root>/speed'

  controlModel_EnabledSubsystem_p(true, controlModel_ConstB.Conversion_l,
    controlModel_ConstP.pooled10, rtb_Add_be, controlModel_DW.MemoryX_DSTATE_k,
    controlModel_DW.Product2_c, &controlModel_DW.EnabledSubsystem_p);

  // End of Outputs for SubSystem: '<S140>/Enabled Subsystem'

  // Outputs for Enabled SubSystem: '<S134>/MeasurementUpdate'
  controlMode_MeasurementUpdate_p(true, controlModel_ConstB.Conversion_b,
    rtb_Add_be, controlModel_ConstP.pooled10, controlModel_DW.MemoryX_DSTATE_k,
    controlModel_ConstP.pooled11, controlModel_U.speed,
    controlModel_DW.Product3_p, &controlModel_DW.MeasurementUpdate_p);

  // End of Outputs for SubSystem: '<S134>/MeasurementUpdate'

  // Sum: '<S140>/Add' incorporates:
  //   Delay: '<S8>/MemoryX'

  rtb_Sum2 = controlModel_DW.Product2_c[0] + controlModel_DW.MemoryX_DSTATE_k[0];
  tmp_1 = controlModel_DW.Product2_c[1] + controlModel_DW.MemoryX_DSTATE_k[1];
  rtb_Saturation1 = controlModel_DW.Product2_c[2] +
    controlModel_DW.MemoryX_DSTATE_k[2];

  // Product: '<S115>/Product' incorporates:
  //   Constant: '<S8>/C'

  for (int32_T i = 0; i < 2; i++) {
    rtb_Add_be[i] = ((controlModel_ConstP.pooled10[i + 2] * tmp_1) +
                     (controlModel_ConstP.pooled10[i] * rtb_Sum2)) +
      (controlModel_ConstP.pooled10[i + 4] * rtb_Saturation1);
  }

  // End of Product: '<S115>/Product'

  // Outport: '<Root>/dist_est'
  controlModel_Y.dist_est = rtb_Add_be[0];

  // Outport: '<Root>/speed_est'
  controlModel_Y.speed_est = rtb_Add_be[1];

  // Delay: '<S13>/MemoryX' incorporates:
  //   Constant: '<S13>/X0'

  if (controlModel_DW.icLoad_e) {
    controlModel_DW.MemoryX_DSTATE_p[0] = 0.0F;
    controlModel_DW.MemoryX_DSTATE_p[1] = 0.0F;
  }

  // Delay: '<S11>/MemoryX' incorporates:
  //   Constant: '<S11>/X0'

  if (controlModel_DW.icLoad_l) {
    controlModel_DW.MemoryX_DSTATE_d[0] = 0.0F;
    controlModel_DW.MemoryX_DSTATE_d[1] = 0.0F;
  }

  // Delay: '<S6>/MemoryX' incorporates:
  //   Constant: '<S6>/X0'

  if (controlModel_DW.icLoad_d) {
    controlModel_DW.MemoryX_DSTATE_g[0] = 0.0F;
    controlModel_DW.MemoryX_DSTATE_g[1] = 0.0F;
  }

  // Math: '<S9>/Exp' incorporates:
  //   Gain: '<S9>/Gain'
  //   Math: '<S9>/Square'
  //
  //  About '<S9>/Exp':
  //   Operator: exp

  rtb_Saturation1 = std::exp((rtb_Add_be[1] * rtb_Add_be[1]) * -99.9999924F);

  // UnitDelay: '<Root>/Unit Delay'
  rtb_Product_k = controlModel_DW.UnitDelay_DSTATE;

  // Math: '<S7>/Exp' incorporates:
  //   Gain: '<S7>/Gain'
  //   Math: '<S7>/Square'
  //
  //  About '<S7>/Exp':
  //   Operator: exp

  rtb_Product_k = std::exp((rtb_Product_k * rtb_Product_k) * -99.9999924F);

  // Product: '<Root>/Divide' incorporates:
  //   Inport: '<Root>/gyros'
  //   Math: '<Root>/Square'
  //   Math: '<Root>/Square1'
  //   Sqrt: '<Root>/Square Root'
  //   Sum: '<Root>/Sum3'

  rtb_Gain2 = (1.0F / std::sqrt((controlModel_U.gyros[2] * controlModel_U.gyros
    [2]) + (controlModel_U.gyros[1] * controlModel_U.gyros[1]))) *
    controlModel_U.gyros[1];

  // Signum: '<Root>/Sign' incorporates:
  //   Inport: '<Root>/gyros'

  if (rtIsNaNF(controlModel_U.gyros[2])) {
    rtb_Sum2 = (rtNaNF);
  } else if (controlModel_U.gyros[2] < 0.0F) {
    rtb_Sum2 = -1.0F;
  } else {
    rtb_Sum2 = static_cast<real32_T>((controlModel_U.gyros[2] > 0.0F) ? (
      static_cast<int32_T>(1)) : (static_cast<int32_T>(0)));
  }

  // Trigonometry: '<Root>/Asin'
  if (rtb_Gain2 > 1.0F) {
    rtb_Gain2 = 1.0F;
  } else if (rtb_Gain2 < -1.0F) {
    rtb_Gain2 = -1.0F;
  } else {
    // no actions
  }

  // Product: '<Root>/Product4' incorporates:
  //   Signum: '<Root>/Sign'
  //   Trigonometry: '<Root>/Asin'

  rtb_Gain2 = rtb_Sum2 * std::asin(rtb_Gain2);

  // Saturate: '<Root>/Saturation1'
  if (rtb_Gain2 > controlParams.rollSaturation) {
    rtb_Gain2 = controlParams.rollSaturation;
  } else if (rtb_Gain2 < (-controlParams.rollSaturation)) {
    rtb_Gain2 = -controlParams.rollSaturation;
  } else {
    // no actions
  }

  // Sum: '<Root>/Sum2' incorporates:
  //   Constant: '<S7>/Constant'
  //   Constant: '<S9>/Constant'
  //   Gain: '<Root>/Gain'
  //   Inport: '<Root>/accs'
  //   Inport: '<Root>/gyros'
  //   Product: '<Root>/Product'
  //   Product: '<Root>/Product1'
  //   Product: '<Root>/Product2'
  //   Product: '<Root>/Product3'
  //   Product: '<Root>/Product5'
  //   Saturate: '<Root>/Saturation1'
  //   Sum: '<Root>/Sum1'
  //   Sum: '<S7>/Sum'
  //   Sum: '<S9>/Sum'
  //   Trigonometry: '<Root>/Atan'
  //   Trigonometry: '<Root>/Atan1'

  rtb_Sum2 = (((std::atan((1.0F / controlParams.gravity) * (rtb_Add_be[1] *
    controlModel_U.gyros[2])) * rtb_Product_k) + ((1.0F - rtb_Product_k) *
    rtb_Gain2)) * (1.0F - rtb_Saturation1)) + (rt_atan2f_snf
    (controlModel_U.accs[1], controlModel_U.accs[2]) * rtb_Saturation1);

  // Outputs for Enabled SubSystem: '<S88>/Enabled Subsystem'
  // Constant: '<S6>/Enable' incorporates:
  //   Constant: '<S6>/C'
  //   Delay: '<S6>/MemoryX'

  controlModel_EnabledSubsystem(true, controlModel_ConstB.Conversion_i,
    controlModel_ConstP.pooled14, rtb_Sum2, controlModel_DW.MemoryX_DSTATE_g,
    controlModel_DW.Product2_d4, &controlModel_DW.EnabledSubsystem);

  // End of Outputs for SubSystem: '<S88>/Enabled Subsystem'

  // Product: '<S63>/Product' incorporates:
  //   Constant: '<S6>/C'
  //   Delay: '<S6>/MemoryX'
  //   Sum: '<S88>/Add'

  rtb_Saturation1 = ((controlModel_DW.Product2_d4[1] +
                      controlModel_DW.MemoryX_DSTATE_g[1]) * 0.0F) +
    (controlModel_DW.Product2_d4[0] + controlModel_DW.MemoryX_DSTATE_g[0]);

  // Trigonometry: '<Root>/Cos1' incorporates:
  //   Product: '<S63>/Product'
  //   Trigonometry: '<Root>/Sin'

  rtb_Gain2 = std::sin(rtb_Saturation1);

  // Trigonometry: '<Root>/Sin1' incorporates:
  //   Product: '<S63>/Product'
  //   Trigonometry: '<Root>/Cos'

  tmp_1 = std::cos(rtb_Saturation1);

  // Trigonometry: '<Root>/Atan2' incorporates:
  //   Inport: '<Root>/mags'
  //   Product: '<Root>/Product8'
  //   Product: '<Root>/Product9'
  //   Sum: '<Root>/Sum5'
  //   Trigonometry: '<Root>/Cos1'
  //   Trigonometry: '<Root>/Sin1'

  rtb_Atan2 = rt_atan2f_snf(controlModel_U.mags[0], (controlModel_U.mags[1] *
    tmp_1) - (rtb_Gain2 * controlModel_U.mags[2]));

  // Outputs for Enabled SubSystem: '<S244>/Enabled Subsystem'
  // Constant: '<S11>/Enable' incorporates:
  //   Constant: '<S11>/C'
  //   Delay: '<S11>/MemoryX'

  controlModel_EnabledSubsystem(true, controlModel_ConstB.Conversion_g,
    controlModel_ConstP.pooled14, rtb_Atan2, controlModel_DW.MemoryX_DSTATE_d,
    controlModel_DW.Product2_b, &controlModel_DW.EnabledSubsystem_e);

  // End of Outputs for SubSystem: '<S244>/Enabled Subsystem'

  // Product: '<S219>/Product' incorporates:
  //   Constant: '<S11>/C'
  //   Delay: '<S11>/MemoryX'
  //   Sum: '<S244>/Add'

  rtb_Product_f_0 = ((controlModel_DW.Product2_b[1] +
                      controlModel_DW.MemoryX_DSTATE_d[1]) * 0.0F) +
    (controlModel_DW.Product2_b[0] + controlModel_DW.MemoryX_DSTATE_d[0]);

  // Product: '<Root>/Product11' incorporates:
  //   Product: '<S219>/Product'
  //   Trigonometry: '<Root>/Cos2'

  rtb_Product_k = rtb_Add_be[1] * std::cos(rtb_Product_f_0);

  // Chart: '<Root>/Reset lat0 & long0' incorporates:
  //   Inport: '<Root>/gps'

  if ((static_cast<uint32_T>(controlModel_DW.is_active_c4_controlModel)) == 0U)
  {
    controlModel_DW.is_active_c4_controlModel = 1U;
    controlModel_DW.is_c4_controlModel = controlModel_IN_CHECK;
    controlModel_DW.lat0 = controlModel_U.gps[0];
    controlModel_DW.long0 = controlModel_U.gps[1];
  } else {
    switch (controlModel_DW.is_c4_controlModel) {
     case controlModel_IN_CHECK:
      if (static_cast<boolean_T>(static_cast<int32_T>(((controlModel_U.gps[0] !=
              0.0F) ? (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) &
            ((controlModel_U.gps[1] != 0.0F) ? (static_cast<int32_T>(1)) : (
              static_cast<int32_T>(0)))))) {
        controlModel_DW.is_c4_controlModel = controlModel_IN_SET_LAT_LONG;

        // set lat0 & long0
        controlModel_DW.lat0 = controlModel_U.gps[0];
        controlModel_DW.long0 = controlModel_U.gps[1];
      } else {
        controlModel_DW.lat0 = controlModel_U.gps[0];
        controlModel_DW.long0 = controlModel_U.gps[1];
      }
      break;

     case controlModel_IN_SET_LAT_LONG:
      controlModel_DW.is_c4_controlModel = controlModel_IN_STOP;

      // Nothing to do
      break;

     default:
      // case IN_STOP:
      if (static_cast<boolean_T>(static_cast<int32_T>(((controlModel_U.gps[0] ==
              0.0F) ? (static_cast<int32_T>(1)) : (static_cast<int32_T>(0))) &
            ((controlModel_U.gps[1] == 0.0F) ? (static_cast<int32_T>(1)) : (
              static_cast<int32_T>(0)))))) {
        controlModel_DW.is_c4_controlModel = controlModel_IN_CHECK;
        controlModel_DW.lat0 = controlModel_U.gps[0];
        controlModel_DW.long0 = controlModel_U.gps[1];
      } else {
        // Nothing to do
      }
      break;
    }
  }

  // End of Chart: '<Root>/Reset lat0 & long0'

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   Inport: '<Root>/gps'

  //  lat0 = 45.713470458984375;
  //  long0 = 11.377158164978027;
  rtb_x = ((((controlModel_U.gps[1] - controlModel_DW.long0) * 6.371E+6F) /
            180.0F) * 3.14159274F) * std::cos((controlModel_DW.lat0 / 180.0F) *
    3.14159274F);
  rtb_y = (((controlModel_U.gps[0] - controlModel_DW.lat0) * 6.371E+6F) / 180.0F)
    * 3.14159274F;

  // Outputs for Enabled SubSystem: '<S342>/MeasurementUpdate'
  // Constant: '<S13>/Enable' incorporates:
  //   Constant: '<S13>/C'
  //   Constant: '<S13>/D'
  //   Delay: '<S13>/MemoryX'

  controlModel_MeasurementUpdate(true, controlModel_ConstB.Conversion_f, rtb_y,
    controlModel_ConstP.pooled14, controlModel_DW.MemoryX_DSTATE_p, 0.0F,
    rtb_Product_k, controlModel_DW.Product3,
    &controlModel_DW.MeasurementUpdate_a);

  // End of Outputs for SubSystem: '<S342>/MeasurementUpdate'

  // Outputs for Enabled SubSystem: '<S348>/Enabled Subsystem'
  controlModel_EnabledSubsystem(true, controlModel_ConstB.Conversion_gp,
    controlModel_ConstP.pooled14, rtb_y, controlModel_DW.MemoryX_DSTATE_p,
    controlModel_DW.Product2, &controlModel_DW.EnabledSubsystem_g);

  // End of Outputs for SubSystem: '<S348>/Enabled Subsystem'

  // Delay: '<S12>/MemoryX' incorporates:
  //   Constant: '<S12>/X0'

  if (controlModel_DW.icLoad_ib) {
    controlModel_DW.MemoryX_DSTATE_l[0] = 0.0F;
    controlModel_DW.MemoryX_DSTATE_l[1] = 0.0F;
  }

  // Outputs for Enabled SubSystem: '<S296>/Enabled Subsystem'
  // Constant: '<S12>/Enable' incorporates:
  //   Constant: '<S12>/C'
  //   Delay: '<S12>/MemoryX'

  controlModel_EnabledSubsystem(true, controlModel_ConstB.Conversion_ma,
    controlModel_ConstP.pooled14, rtb_x, controlModel_DW.MemoryX_DSTATE_l,
    controlModel_DW.Product2_d, &controlModel_DW.EnabledSubsystem_pd);

  // End of Outputs for SubSystem: '<S296>/Enabled Subsystem'

  // Product: '<Root>/Product10' incorporates:
  //   Gain: '<Root>/Gain3'
  //   Product: '<S219>/Product'
  //   Trigonometry: '<Root>/Sin2'

  rtb_y = rtb_Add_be[1] * (-std::sin(rtb_Product_f_0));

  // Outputs for Enabled SubSystem: '<S290>/MeasurementUpdate'
  // Constant: '<S12>/Enable' incorporates:
  //   Constant: '<S12>/C'
  //   Constant: '<S12>/D'
  //   Delay: '<S12>/MemoryX'

  controlModel_MeasurementUpdate(true, controlModel_ConstB.Conversion_iu, rtb_x,
    controlModel_ConstP.pooled14, controlModel_DW.MemoryX_DSTATE_l, 0.0F, rtb_y,
    controlModel_DW.Product3_o, &controlModel_DW.MeasurementUpdate_i);

  // End of Outputs for SubSystem: '<S290>/MeasurementUpdate'

  // Gain: '<Root>/Gain2' incorporates:
  //   Inport: '<Root>/gyros'
  //   Product: '<Root>/Product6'
  //   Product: '<Root>/Product7'
  //   Sum: '<Root>/Sum4'

  rtb_Gain2 = -((controlModel_U.gyros[1] * rtb_Gain2) + (tmp_1 *
    controlModel_U.gyros[2]));

  // Outputs for Enabled SubSystem: '<S238>/MeasurementUpdate'
  // Constant: '<S11>/Enable' incorporates:
  //   Constant: '<S11>/C'
  //   Constant: '<S11>/D'
  //   Delay: '<S11>/MemoryX'

  controlModel_MeasurementUpdate(true, controlModel_ConstB.Conversion_p,
    rtb_Atan2, controlModel_ConstP.pooled14, controlModel_DW.MemoryX_DSTATE_d,
    0.0F, rtb_Gain2, controlModel_DW.Product3_b,
    &controlModel_DW.MeasurementUpdate_cv);

  // End of Outputs for SubSystem: '<S238>/MeasurementUpdate'

  // Outputs for Enabled SubSystem: '<S82>/MeasurementUpdate'
  // Constant: '<S6>/Enable' incorporates:
  //   Constant: '<S6>/C'
  //   Constant: '<S6>/D'
  //   Delay: '<S6>/MemoryX'
  //   Inport: '<Root>/gyros'

  controlModel_MeasurementUpdate(true, controlModel_ConstB.Conversion_ni,
    rtb_Sum2, controlModel_ConstP.pooled14, controlModel_DW.MemoryX_DSTATE_g,
    0.0F, controlModel_U.gyros[0], controlModel_DW.Product3_a,
    &controlModel_DW.MeasurementUpdate);

  // End of Outputs for SubSystem: '<S82>/MeasurementUpdate'

  // Outport: '<Root>/pos_est' incorporates:
  //   Constant: '<S12>/C'
  //   Constant: '<S13>/C'
  //   Delay: '<S12>/MemoryX'
  //   Delay: '<S13>/MemoryX'
  //   Product: '<S271>/Product'
  //   Product: '<S323>/Product'
  //   Sum: '<S296>/Add'
  //   Sum: '<S348>/Add'

  controlModel_Y.pos_est[0] = ((controlModel_DW.Product2_d[1] +
    controlModel_DW.MemoryX_DSTATE_l[1]) * 0.0F) + (controlModel_DW.Product2_d[0]
    + controlModel_DW.MemoryX_DSTATE_l[0]);
  controlModel_Y.pos_est[1] = ((controlModel_DW.Product2[1] +
    controlModel_DW.MemoryX_DSTATE_p[1]) * 0.0F) + (controlModel_DW.Product2[0]
    + controlModel_DW.MemoryX_DSTATE_p[0]);

  // Outport: '<Root>/yaw_est' incorporates:
  //   Product: '<S219>/Product'

  controlModel_Y.yaw_est = rtb_Product_f_0;

  // Outport: '<Root>/roll_est' incorporates:
  //   Product: '<S63>/Product'

  controlModel_Y.roll_est = rtb_Saturation1;

  // MATLAB Function: '<S161>/SqrtUsedFcn' incorporates:
  //   Constant: '<S161>/isSqrtUsed'

  controlModel_SqrtUsedFcn_c(controlModel_ConstB.Conversion_m, false, rtb_P_i);

  // MATLAB Function: '<S109>/SqrtUsedFcn' incorporates:
  //   Constant: '<S109>/isSqrtUsed'

  controlModel_SqrtUsedFcn(controlModel_ConstB.Conversion_c, false, rtb_P_d);

  // MATLAB Function: '<S265>/SqrtUsedFcn' incorporates:
  //   Constant: '<S265>/isSqrtUsed'

  controlModel_SqrtUsedFcn(controlModel_ConstB.Conversion_e, false, rtb_P_d);

  // MATLAB Function: '<S317>/SqrtUsedFcn' incorporates:
  //   Constant: '<S317>/isSqrtUsed'

  controlModel_SqrtUsedFcn(controlModel_ConstB.Conversion_j, false, rtb_P_d);

  // MATLAB Function: '<S369>/SqrtUsedFcn' incorporates:
  //   Constant: '<S369>/isSqrtUsed'

  controlModel_SqrtUsedFcn(controlModel_ConstB.Conversion_a, false, rtb_P_d);

  // Outport: '<Root>/throttle_ref' incorporates:
  //   Constant: '<Root>/Constant4'

  controlModel_Y.throttle_ref = 0.0F;

  // MATLABSystem: '<Root>/Lowpass Filter' incorporates:
  //   Inport: '<Root>/torque'

  obj = controlModel_DW.obj.FilterObj;
  if (obj->isInitialized != 1) {
    obj->isSetupComplete = false;
    obj->isInitialized = 1;
    obj->isSetupComplete = true;

    // System object Initialization function: dsp.FIRFilter
    for (int32_T i = 0; i < 20; i++) {
      obj->cSFunObject.W0_states[i] = obj->cSFunObject.P0_InitialStates;
    }
  }

  obj_0 = &obj->cSFunObject;

  // System object Outputs function: dsp.FIRFilter
  rtb_Atan2 = controlModel_U.torque;

  // load input sample
  for (int32_T i = 0; i < 20; i++) {
    // shift state
    rtb_Product_f_0 = rtb_Atan2;
    rtb_Atan2 = obj_0->W0_states[i];
    obj_0->W0_states[i] = rtb_Product_f_0;

    // compute one tap
  }

  // End of MATLABSystem: '<Root>/Lowpass Filter'

  // Update for Delay: '<S10>/MemoryX'
  // compute last tap
  // store output sample
  controlModel_DW.icLoad = false;

  // Product: '<S186>/B[k]*u[k]' incorporates:
  //   Inport: '<Root>/steer'

  rtb_Sum2 = controlModel_U.steer[1];

  // Product: '<S186>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S10>/A'
  //   Delay: '<S10>/MemoryX'

  for (int32_T i = 0; i < 3; i++) {
    tmp[i] = ((controlModel_ConstP.pooled8[i + 3] *
               controlModel_DW.MemoryX_DSTATE[1]) +
              (controlModel_ConstP.pooled8[i] * controlModel_DW.MemoryX_DSTATE[0]))
      + (controlModel_ConstP.pooled8[i + 6] * controlModel_DW.MemoryX_DSTATE[2]);
  }

  // End of Product: '<S186>/A[k]*xhat[k|k-1]'

  // Update for DiscreteIntegrator: '<S45>/Integrator' incorporates:
  //   Gain: '<S42>/Integral Gain'
  //   Sum: '<S38>/SumI4'

  controlModel_DW.Integrator_DSTATE += ((controlParams.intGainSteerCtrl *
    rtb_err_delta) + rtb_Saturation) * 0.001F;

  // Update for DiscreteIntegrator: '<S40>/Filter'
  controlModel_DW.Filter_DSTATE += 0.001F * rtb_FilterCoefficient;

  // Update for Delay: '<S8>/MemoryX'
  controlModel_DW.icLoad_i = false;
  for (int32_T i = 0; i < 3; i++) {
    // Update for Delay: '<S10>/MemoryX' incorporates:
    //   Constant: '<S10>/B'
    //   Product: '<S186>/B[k]*u[k]'
    //   Product: '<S215>/Product3'
    //   Sum: '<S186>/Add'

    controlModel_DW.MemoryX_DSTATE[i] = ((0.0F * rtb_Sum2) + tmp[i]) +
      controlModel_DW.Product3_bz[i];

    // Product: '<S134>/A[k]*xhat[k|k-1]' incorporates:
    //   Constant: '<S8>/A'
    //   Delay: '<S8>/MemoryX'

    tmp_0[i] = ((controlModel_ConstP.pooled8[i + 3] *
                 controlModel_DW.MemoryX_DSTATE_k[1]) +
                (controlModel_ConstP.pooled8[i] *
                 controlModel_DW.MemoryX_DSTATE_k[0])) +
      (controlModel_ConstP.pooled8[i + 6] * controlModel_DW.MemoryX_DSTATE_k[2]);
  }

  // Update for Delay: '<S8>/MemoryX' incorporates:
  //   Constant: '<S8>/B'
  //   Inport: '<Root>/speed'
  //   Product: '<S134>/B[k]*u[k]'
  //   Product: '<S163>/Product3'
  //   Sum: '<S134>/Add'

  controlModel_DW.MemoryX_DSTATE_k[0] = ((0.0F * controlModel_U.speed) + tmp_0[0])
    + controlModel_DW.Product3_p[0];
  controlModel_DW.MemoryX_DSTATE_k[1] = ((0.0F * controlModel_U.speed) + tmp_0[1])
    + controlModel_DW.Product3_p[1];
  controlModel_DW.MemoryX_DSTATE_k[2] = ((0.0F * controlModel_U.speed) + tmp_0[2])
    + controlModel_DW.Product3_p[2];

  // Update for Delay: '<S13>/MemoryX'
  controlModel_DW.icLoad_e = false;

  // Product: '<S342>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S13>/A'
  //   Delay: '<S13>/MemoryX'

  rtb_Sum2 = (-0.001F * controlModel_DW.MemoryX_DSTATE_p[1]) +
    controlModel_DW.MemoryX_DSTATE_p[0];
  tmp_1 = (0.0F * controlModel_DW.MemoryX_DSTATE_p[0]) +
    controlModel_DW.MemoryX_DSTATE_p[1];

  // Update for Delay: '<S11>/MemoryX'
  controlModel_DW.icLoad_l = false;

  // Update for Delay: '<S13>/MemoryX' incorporates:
  //   Constant: '<S13>/B'
  //   Product: '<S342>/B[k]*u[k]'
  //   Product: '<S371>/Product3'
  //   Sum: '<S342>/Add'

  controlModel_DW.MemoryX_DSTATE_p[0] = ((0.001F * rtb_Product_k) + rtb_Sum2) +
    controlModel_DW.Product3[0];

  // Product: '<S238>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S11>/A'
  //   Delay: '<S11>/MemoryX'

  rtb_Sum2 = (-0.001F * controlModel_DW.MemoryX_DSTATE_d[1]) +
    controlModel_DW.MemoryX_DSTATE_d[0];

  // Update for Delay: '<S13>/MemoryX' incorporates:
  //   Constant: '<S13>/B'
  //   Product: '<S342>/B[k]*u[k]'
  //   Product: '<S371>/Product3'
  //   Sum: '<S342>/Add'

  controlModel_DW.MemoryX_DSTATE_p[1] = ((0.0F * rtb_Product_k) + tmp_1) +
    controlModel_DW.Product3[1];

  // Product: '<S238>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S11>/A'
  //   Delay: '<S11>/MemoryX'

  tmp_1 = (0.0F * controlModel_DW.MemoryX_DSTATE_d[0]) +
    controlModel_DW.MemoryX_DSTATE_d[1];

  // Update for Delay: '<S6>/MemoryX'
  controlModel_DW.icLoad_d = false;

  // Update for Delay: '<S11>/MemoryX' incorporates:
  //   Constant: '<S11>/B'
  //   Product: '<S238>/B[k]*u[k]'
  //   Product: '<S267>/Product3'
  //   Sum: '<S238>/Add'

  controlModel_DW.MemoryX_DSTATE_d[0] = ((0.001F * rtb_Gain2) + rtb_Sum2) +
    controlModel_DW.Product3_b[0];

  // Product: '<S82>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S6>/A'
  //   Delay: '<S6>/MemoryX'

  rtb_Sum2 = (-0.001F * controlModel_DW.MemoryX_DSTATE_g[1]) +
    controlModel_DW.MemoryX_DSTATE_g[0];

  // Update for Delay: '<S11>/MemoryX' incorporates:
  //   Constant: '<S11>/B'
  //   Product: '<S238>/B[k]*u[k]'
  //   Product: '<S267>/Product3'
  //   Sum: '<S238>/Add'

  controlModel_DW.MemoryX_DSTATE_d[1] = ((0.0F * rtb_Gain2) + tmp_1) +
    controlModel_DW.Product3_b[1];

  // Product: '<S82>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S6>/A'
  //   Delay: '<S6>/MemoryX'

  tmp_1 = (0.0F * controlModel_DW.MemoryX_DSTATE_g[0]) +
    controlModel_DW.MemoryX_DSTATE_g[1];

  // Update for UnitDelay: '<Root>/Unit Delay' incorporates:
  //   Product: '<S63>/Product'

  controlModel_DW.UnitDelay_DSTATE = rtb_Saturation1;

  // Update for Delay: '<S12>/MemoryX'
  controlModel_DW.icLoad_ib = false;

  // Update for Delay: '<S6>/MemoryX' incorporates:
  //   Constant: '<S6>/B'
  //   Inport: '<Root>/gyros'
  //   Product: '<S111>/Product3'
  //   Product: '<S82>/B[k]*u[k]'
  //   Sum: '<S82>/Add'

  controlModel_DW.MemoryX_DSTATE_g[0] = ((0.001F * controlModel_U.gyros[0]) +
    rtb_Sum2) + controlModel_DW.Product3_a[0];

  // Product: '<S290>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S12>/A'
  //   Delay: '<S12>/MemoryX'

  rtb_Sum2 = (-0.001F * controlModel_DW.MemoryX_DSTATE_l[1]) +
    controlModel_DW.MemoryX_DSTATE_l[0];

  // Update for Delay: '<S6>/MemoryX' incorporates:
  //   Constant: '<S6>/B'
  //   Inport: '<Root>/gyros'
  //   Product: '<S111>/Product3'
  //   Product: '<S82>/B[k]*u[k]'
  //   Sum: '<S82>/Add'

  controlModel_DW.MemoryX_DSTATE_g[1] = ((0.0F * controlModel_U.gyros[0]) +
    tmp_1) + controlModel_DW.Product3_a[1];

  // Product: '<S290>/A[k]*xhat[k|k-1]' incorporates:
  //   Constant: '<S12>/A'
  //   Delay: '<S12>/MemoryX'

  tmp_1 = (0.0F * controlModel_DW.MemoryX_DSTATE_l[0]) +
    controlModel_DW.MemoryX_DSTATE_l[1];

  // Update for Delay: '<S12>/MemoryX' incorporates:
  //   Constant: '<S12>/B'
  //   Product: '<S290>/B[k]*u[k]'
  //   Product: '<S319>/Product3'
  //   Sum: '<S290>/Add'

  controlModel_DW.MemoryX_DSTATE_l[0] = ((0.001F * rtb_y) + rtb_Sum2) +
    controlModel_DW.Product3_o[0];
  controlModel_DW.MemoryX_DSTATE_l[1] = ((0.0F * rtb_y) + tmp_1) +
    controlModel_DW.Product3_o[1];
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

    // InitializeConditions for Delay: '<S10>/MemoryX'
    controlModel_DW.icLoad = true;

    // InitializeConditions for Delay: '<S8>/MemoryX'
    controlModel_DW.icLoad_i = true;

    // InitializeConditions for Delay: '<S13>/MemoryX'
    controlModel_DW.icLoad_e = true;

    // InitializeConditions for Delay: '<S11>/MemoryX'
    controlModel_DW.icLoad_l = true;

    // InitializeConditions for Delay: '<S6>/MemoryX'
    controlModel_DW.icLoad_d = true;

    // InitializeConditions for Delay: '<S12>/MemoryX'
    controlModel_DW.icLoad_ib = true;

    // Start for MATLABSystem: '<Root>/Lowpass Filter'
    controlModel_DW.obj._pobj0.matlabCodegenIsDeleted = true;
    controlModel_DW.obj.NumChannels = -1;
    controlModel_DW.obj.matlabCodegenIsDeleted = false;
    controlModel_DW.obj.isInitialized = 1;
    if (controlModel_DW.obj.NumChannels == -1) {
      controlModel_DW.obj.NumChannels = 1;
    }

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
