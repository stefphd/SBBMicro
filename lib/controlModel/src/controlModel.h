//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controlModel.h
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 4.103
// Simulink Coder version         : 9.8 (R2022b) 13-May-2022
// C/C++ source code generated on : Mon Jan 22 10:43:19 2024
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
#ifndef RTW_HEADER_controlModel_h_
#define RTW_HEADER_controlModel_h_
#include "rtwtypes.h"
#include "controlModel_types.h"
#include <cstring>

extern "C"
{

#include "rt_nonfinite.h"

}

extern "C"
{

#include "rtGetInf.h"

}

// Type definition for custom storage class: Struct
struct controlParams_type {
  real32_T controlTuningGain;          // Referenced by: '<Root>/Gain1'
  real32_T gravity;                    // Referenced by: '<Root>/Gain'
  real32_T maxCurrent;                 // Referenced by: '<Root>/Saturation'
  real32_T maxSteer;                   // Referenced by: '<Root>/Chart'
  real32_T rollSaturation;             // Referenced by: '<Root>/Saturation1'
  real32_T speedMinCtrl;               // Referenced by: '<S3>/Constant'
};

// Exported data declaration

// Declaration for custom storage class: Struct
extern controlParams_type controlParams;

// Class declaration for model controlModel
class ControlClass
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<S81>/MeasurementUpdate' 
  struct DW_MeasurementUpdate_controlM_T {
    boolean_T MeasurementUpdate_MODE;  // '<S81>/MeasurementUpdate'
  };

  // Block signals and states (default storage) for system '<S87>/Enabled Subsystem' 
  struct DW_EnabledSubsystem_controlMo_T {
    boolean_T EnabledSubsystem_MODE;   // '<S87>/Enabled Subsystem'
  };

  // Block signals and states (default storage) for system '<Root>'
  struct DW_controlModel_T {
    DW_EnabledSubsystem_controlMo_T EnabledSubsystem_d;// '<S139>/Enabled Subsystem' 
    DW_MeasurementUpdate_controlM_T MeasurementUpdate_c;// '<S133>/MeasurementUpdate' 
    DW_EnabledSubsystem_controlMo_T EnabledSubsystem_p;// '<S87>/Enabled Subsystem' 
    DW_MeasurementUpdate_controlM_T MeasurementUpdate_p;// '<S81>/MeasurementUpdate' 
    real32_T Product2[3];              // '<S164>/Product2'
    real32_T Product3[3];              // '<S162>/Product3'
    real32_T Product2_c[3];            // '<S112>/Product2'
    real32_T Product3_p[3];            // '<S110>/Product3'
    real32_T MemoryX_DSTATE[3];        // '<S6>/MemoryX'
    real32_T MemoryX_DSTATE_g[2];      // '<S4>/MemoryX'
    real32_T MemoryX_DSTATE_o[3];      // '<S8>/MemoryX'
    real32_T UnitDelay_DSTATE;         // '<Root>/Unit Delay'
    real32_T DiscreteStateSpace_DSTATE;// '<Root>/Discrete State-Space'
    uint8_T is_c1_controlModel;        // '<Root>/Chart1'
    uint8_T is_active_c1_controlModel; // '<Root>/Chart1'
    uint8_T is_c3_controlModel;        // '<Root>/Chart'
    uint8_T is_active_c3_controlModel; // '<Root>/Chart'
    boolean_T icLoad;                  // '<S6>/MemoryX'
    boolean_T icLoad_d;                // '<S4>/MemoryX'
    boolean_T icLoad_a;                // '<S8>/MemoryX'
  };

  // Invariant block signals (default storage)
  struct ConstB_controlModel_T {
    real32_T Conversion[2];            // '<S51>/Conversion'
    real32_T Conversion_i[2];          // '<S52>/Conversion'
    real32_T Conversion_c[4];          // '<S54>/Conversion'
    real32_T Conversion_b[6];          // '<S103>/Conversion'
    real32_T Conversion_l[6];          // '<S104>/Conversion'
    real32_T Conversion_m[9];          // '<S106>/Conversion'
    real32_T Conversion_h[6];          // '<S155>/Conversion'
    real32_T Conversion_k[6];          // '<S156>/Conversion'
    real32_T Conversion_n[9];          // '<S158>/Conversion'
  };

  // Constant parameters (default storage)
  struct ConstP_controlModel_T {
    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S6>/A'
    //    '<S8>/A'

    real32_T pooled3[9];

    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S6>/C'
    //    '<S8>/C'

    real32_T pooled5[6];

    // Pooled Parameter (Mixed Expressions)
    //  Referenced by:
    //    '<Root>/Constant2'
    //    '<S4>/X0'
    //    '<S6>/D'
    //    '<S8>/D'

    real32_T pooled7[2];
  };

  // External inputs (root inport signals with default storage)
  struct ExtU_controlModel_T {
    real32_T speed;                    // '<Root>/speed'
    real32_T dist;                     // '<Root>/dist'
    real32_T accs[3];                  // '<Root>/accs'
    real32_T gyros[3];                 // '<Root>/gyros'
    real32_T mags[3];                  // '<Root>/mags'
    real32_T gps[3];                   // '<Root>/gps'
    real32_T steer[2];                 // '<Root>/steer'
    real32_T forkdisp;                 // '<Root>/forkdisp'
    real32_T curr;                     // '<Root>/curr'
    real32_T torque;                   // '<Root>/torque'
    real32_T CPUTemp;                  // '<Root>/CPUTemp'
    real32_T voltage;                  // '<Root>/voltage'
    real32_T ref_inputs[2];            // '<Root>/ref_inputs'
    uint8_T error_state_in;            // '<Root>/error_state_in'
  };

  // External outputs (root outports fed by signals with default storage)
  struct ExtY_controlModel_T {
    real32_T curr_ref;                 // '<Root>/curr_ref'
    real32_T throttle_ref;             // '<Root>/throttle_ref'
    real32_T roll_est;                 // '<Root>/roll_est'
    real32_T yaw_est;                  // '<Root>/yaw_est'
    real32_T pos_est[2];               // '<Root>/pos_est'
    real32_T dist_est;                 // '<Root>/dist_est'
    real32_T speed_est;                // '<Root>/speed_est'
    real32_T steer_est[2];             // '<Root>/steer_est'
    uint8_T error_state_out;           // '<Root>/error_state_out'
    real32_T user_data[4];             // '<Root>/user_data'
  };

  // External inputs
  ExtU_controlModel_T controlModel_U;

  // External outputs
  ExtY_controlModel_T controlModel_Y;

  // Root inports set method
  void setExternalInputs(const ExtU_controlModel_T *pExtU_controlModel_T)
  {
    controlModel_U = *pExtU_controlModel_T;
  }

  // Root outports get method
  const ExtY_controlModel_T &getExternalOutputs() const
  {
    return controlModel_Y;
  }

  // model initialize function
  void begin();

  // model step function
  void update();

  // model terminate function
  static void stop();

  // Constructor
  ControlClass();

  // Destructor
  ~ControlClass();

  // private data and function members
 private:
  // Block states
  DW_controlModel_T controlModel_DW;

  // private member function(s) for subsystem '<S108>/SqrtUsedFcn'
  static void controlModel_SqrtUsedFcn(const real32_T rtu_u[9], boolean_T
    rtu_isSqrtUsed, real32_T rty_P[9]);

  // private member function(s) for subsystem '<S81>/MeasurementUpdate'
  static void contr_MeasurementUpdate_Disable(real32_T rty_Lykyhatkk1[3],
    DW_MeasurementUpdate_controlM_T *localDW);
  void controlModel_MeasurementUpdate(boolean_T rtu_Enable, const real32_T
    rtu_Lk[6], const real32_T rtu_yk[2], const real32_T rtu_Ck[6], const
    real32_T rtu_xhatkk1[3], const real32_T rtu_Dk[2], real32_T rtu_uk, real32_T
    rty_Lykyhatkk1[3], DW_MeasurementUpdate_controlM_T *localDW);

  // private member function(s) for subsystem '<S87>/Enabled Subsystem'
  static void contro_EnabledSubsystem_Disable(real32_T rty_deltax[3],
    DW_EnabledSubsystem_controlMo_T *localDW);
  void controlModel_EnabledSubsystem(boolean_T rtu_Enable, const real32_T
    rtu_Mk[6], const real32_T rtu_Ck[6], const real32_T rtu_yk[2], const
    real32_T rtu_xhatkk1[3], real32_T rty_deltax[3],
    DW_EnabledSubsystem_controlMo_T *localDW);
};

extern const ControlClass::ConstB_controlModel_T controlModel_ConstB;// constant block i/o 

// Constant parameters (default storage)
extern const ControlClass::ConstP_controlModel_T controlModel_ConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S51>/Data Type Duplicate' : Unused code path elimination
//  Block '<S52>/Data Type Duplicate' : Unused code path elimination
//  Block '<S53>/Conversion' : Unused code path elimination
//  Block '<S53>/Data Type Duplicate' : Unused code path elimination
//  Block '<S54>/Data Type Duplicate' : Unused code path elimination
//  Block '<S12>/Data Type Duplicate' : Unused code path elimination
//  Block '<S13>/Data Type Duplicate' : Unused code path elimination
//  Block '<S14>/Data Type Duplicate' : Unused code path elimination
//  Block '<S15>/Data Type Duplicate' : Unused code path elimination
//  Block '<S17>/Data Type Duplicate' : Unused code path elimination
//  Block '<S18>/Data Type Duplicate' : Unused code path elimination
//  Block '<S19>/Data Type Duplicate' : Unused code path elimination
//  Block '<S20>/Conversion' : Unused code path elimination
//  Block '<S20>/Data Type Duplicate' : Unused code path elimination
//  Block '<S21>/Data Type Duplicate' : Unused code path elimination
//  Block '<S22>/Data Type Duplicate' : Unused code path elimination
//  Block '<S23>/Data Type Duplicate' : Unused code path elimination
//  Block '<S25>/Data Type Duplicate' : Unused code path elimination
//  Block '<S26>/Data Type Duplicate' : Unused code path elimination
//  Block '<S4>/G' : Unused code path elimination
//  Block '<S4>/H' : Unused code path elimination
//  Block '<S4>/N' : Unused code path elimination
//  Block '<S4>/P0' : Unused code path elimination
//  Block '<S4>/Q' : Unused code path elimination
//  Block '<S4>/R' : Unused code path elimination
//  Block '<S4>/Reshapexhat' : Unused code path elimination
//  Block '<S49>/CheckSignalProperties' : Unused code path elimination
//  Block '<S50>/CheckSignalProperties' : Unused code path elimination
//  Block '<S103>/Data Type Duplicate' : Unused code path elimination
//  Block '<S104>/Data Type Duplicate' : Unused code path elimination
//  Block '<S105>/Conversion' : Unused code path elimination
//  Block '<S105>/Data Type Duplicate' : Unused code path elimination
//  Block '<S106>/Data Type Duplicate' : Unused code path elimination
//  Block '<S64>/Data Type Duplicate' : Unused code path elimination
//  Block '<S65>/Data Type Duplicate' : Unused code path elimination
//  Block '<S66>/Data Type Duplicate' : Unused code path elimination
//  Block '<S67>/Data Type Duplicate' : Unused code path elimination
//  Block '<S69>/Data Type Duplicate' : Unused code path elimination
//  Block '<S70>/Data Type Duplicate' : Unused code path elimination
//  Block '<S71>/Data Type Duplicate' : Unused code path elimination
//  Block '<S72>/Conversion' : Unused code path elimination
//  Block '<S72>/Data Type Duplicate' : Unused code path elimination
//  Block '<S73>/Data Type Duplicate' : Unused code path elimination
//  Block '<S74>/Data Type Duplicate' : Unused code path elimination
//  Block '<S75>/Data Type Duplicate' : Unused code path elimination
//  Block '<S77>/Data Type Duplicate' : Unused code path elimination
//  Block '<S78>/Data Type Duplicate' : Unused code path elimination
//  Block '<S6>/G' : Unused code path elimination
//  Block '<S6>/H' : Unused code path elimination
//  Block '<S6>/N' : Unused code path elimination
//  Block '<S6>/P0' : Unused code path elimination
//  Block '<S6>/Q' : Unused code path elimination
//  Block '<S6>/R' : Unused code path elimination
//  Block '<S6>/Reshapexhat' : Unused code path elimination
//  Block '<S101>/CheckSignalProperties' : Unused code path elimination
//  Block '<S102>/CheckSignalProperties' : Unused code path elimination
//  Block '<S155>/Data Type Duplicate' : Unused code path elimination
//  Block '<S156>/Data Type Duplicate' : Unused code path elimination
//  Block '<S157>/Conversion' : Unused code path elimination
//  Block '<S157>/Data Type Duplicate' : Unused code path elimination
//  Block '<S158>/Data Type Duplicate' : Unused code path elimination
//  Block '<S116>/Data Type Duplicate' : Unused code path elimination
//  Block '<S117>/Data Type Duplicate' : Unused code path elimination
//  Block '<S118>/Data Type Duplicate' : Unused code path elimination
//  Block '<S119>/Data Type Duplicate' : Unused code path elimination
//  Block '<S121>/Data Type Duplicate' : Unused code path elimination
//  Block '<S122>/Data Type Duplicate' : Unused code path elimination
//  Block '<S123>/Data Type Duplicate' : Unused code path elimination
//  Block '<S124>/Conversion' : Unused code path elimination
//  Block '<S124>/Data Type Duplicate' : Unused code path elimination
//  Block '<S125>/Data Type Duplicate' : Unused code path elimination
//  Block '<S126>/Data Type Duplicate' : Unused code path elimination
//  Block '<S127>/Data Type Duplicate' : Unused code path elimination
//  Block '<S129>/Data Type Duplicate' : Unused code path elimination
//  Block '<S130>/Data Type Duplicate' : Unused code path elimination
//  Block '<S8>/G' : Unused code path elimination
//  Block '<S8>/H' : Unused code path elimination
//  Block '<S8>/N' : Unused code path elimination
//  Block '<S8>/P0' : Unused code path elimination
//  Block '<S8>/Q' : Unused code path elimination
//  Block '<S8>/R' : Unused code path elimination
//  Block '<S8>/Reshapexhat' : Unused code path elimination
//  Block '<S153>/CheckSignalProperties' : Unused code path elimination
//  Block '<S154>/CheckSignalProperties' : Unused code path elimination
//  Block '<S25>/Conversion' : Eliminate redundant data type conversion
//  Block '<S29>/Reshape' : Reshape block reduction
//  Block '<S4>/ReshapeX0' : Reshape block reduction
//  Block '<S4>/Reshapeu' : Reshape block reduction
//  Block '<S4>/Reshapey' : Reshape block reduction
//  Block '<S4>/Reshapeyhat' : Reshape block reduction
//  Block '<S77>/Conversion' : Eliminate redundant data type conversion
//  Block '<S81>/Reshape' : Reshape block reduction
//  Block '<S6>/ReshapeX0' : Reshape block reduction
//  Block '<S6>/Reshapeu' : Reshape block reduction
//  Block '<S6>/Reshapeyhat' : Reshape block reduction
//  Block '<S129>/Conversion' : Eliminate redundant data type conversion
//  Block '<S133>/Reshape' : Reshape block reduction
//  Block '<S8>/ReshapeX0' : Reshape block reduction
//  Block '<S8>/Reshapeu' : Reshape block reduction
//  Block '<S8>/Reshapey' : Reshape block reduction
//  Block '<S8>/Reshapeyhat' : Reshape block reduction


//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'controlModel'
//  '<S1>'   : 'controlModel/Chart'
//  '<S2>'   : 'controlModel/Chart1'
//  '<S3>'   : 'controlModel/Compare To Constant'
//  '<S4>'   : 'controlModel/Roll kalman'
//  '<S5>'   : 'controlModel/Roll weighting'
//  '<S6>'   : 'controlModel/Speed estimator'
//  '<S7>'   : 'controlModel/Speed weighting'
//  '<S8>'   : 'controlModel/Steer estimator'
//  '<S9>'   : 'controlModel/Roll kalman/CalculatePL'
//  '<S10>'  : 'controlModel/Roll kalman/CalculateYhat'
//  '<S11>'  : 'controlModel/Roll kalman/CovarianceOutputConfigurator'
//  '<S12>'  : 'controlModel/Roll kalman/DataTypeConversionA'
//  '<S13>'  : 'controlModel/Roll kalman/DataTypeConversionB'
//  '<S14>'  : 'controlModel/Roll kalman/DataTypeConversionC'
//  '<S15>'  : 'controlModel/Roll kalman/DataTypeConversionD'
//  '<S16>'  : 'controlModel/Roll kalman/DataTypeConversionEnable'
//  '<S17>'  : 'controlModel/Roll kalman/DataTypeConversionG'
//  '<S18>'  : 'controlModel/Roll kalman/DataTypeConversionH'
//  '<S19>'  : 'controlModel/Roll kalman/DataTypeConversionN'
//  '<S20>'  : 'controlModel/Roll kalman/DataTypeConversionP'
//  '<S21>'  : 'controlModel/Roll kalman/DataTypeConversionP0'
//  '<S22>'  : 'controlModel/Roll kalman/DataTypeConversionQ'
//  '<S23>'  : 'controlModel/Roll kalman/DataTypeConversionR'
//  '<S24>'  : 'controlModel/Roll kalman/DataTypeConversionReset'
//  '<S25>'  : 'controlModel/Roll kalman/DataTypeConversionX'
//  '<S26>'  : 'controlModel/Roll kalman/DataTypeConversionX0'
//  '<S27>'  : 'controlModel/Roll kalman/DataTypeConversionu'
//  '<S28>'  : 'controlModel/Roll kalman/MemoryP'
//  '<S29>'  : 'controlModel/Roll kalman/Observer'
//  '<S30>'  : 'controlModel/Roll kalman/ReducedQRN'
//  '<S31>'  : 'controlModel/Roll kalman/Reset'
//  '<S32>'  : 'controlModel/Roll kalman/ScalarExpansionP0'
//  '<S33>'  : 'controlModel/Roll kalman/ScalarExpansionQ'
//  '<S34>'  : 'controlModel/Roll kalman/ScalarExpansionR'
//  '<S35>'  : 'controlModel/Roll kalman/UseCurrentEstimator'
//  '<S36>'  : 'controlModel/Roll kalman/checkA'
//  '<S37>'  : 'controlModel/Roll kalman/checkB'
//  '<S38>'  : 'controlModel/Roll kalman/checkC'
//  '<S39>'  : 'controlModel/Roll kalman/checkD'
//  '<S40>'  : 'controlModel/Roll kalman/checkEnable'
//  '<S41>'  : 'controlModel/Roll kalman/checkG'
//  '<S42>'  : 'controlModel/Roll kalman/checkH'
//  '<S43>'  : 'controlModel/Roll kalman/checkN'
//  '<S44>'  : 'controlModel/Roll kalman/checkP0'
//  '<S45>'  : 'controlModel/Roll kalman/checkQ'
//  '<S46>'  : 'controlModel/Roll kalman/checkR'
//  '<S47>'  : 'controlModel/Roll kalman/checkReset'
//  '<S48>'  : 'controlModel/Roll kalman/checkX0'
//  '<S49>'  : 'controlModel/Roll kalman/checku'
//  '<S50>'  : 'controlModel/Roll kalman/checky'
//  '<S51>'  : 'controlModel/Roll kalman/CalculatePL/DataTypeConversionL'
//  '<S52>'  : 'controlModel/Roll kalman/CalculatePL/DataTypeConversionM'
//  '<S53>'  : 'controlModel/Roll kalman/CalculatePL/DataTypeConversionP'
//  '<S54>'  : 'controlModel/Roll kalman/CalculatePL/DataTypeConversionZ'
//  '<S55>'  : 'controlModel/Roll kalman/CalculatePL/Ground'
//  '<S56>'  : 'controlModel/Roll kalman/CovarianceOutputConfigurator/decideOutput'
//  '<S57>'  : 'controlModel/Roll kalman/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S58>'  : 'controlModel/Roll kalman/Observer/MeasurementUpdate'
//  '<S59>'  : 'controlModel/Roll kalman/ReducedQRN/Ground'
//  '<S60>'  : 'controlModel/Roll kalman/UseCurrentEstimator/Enabled Subsystem'
//  '<S61>'  : 'controlModel/Speed estimator/CalculatePL'
//  '<S62>'  : 'controlModel/Speed estimator/CalculateYhat'
//  '<S63>'  : 'controlModel/Speed estimator/CovarianceOutputConfigurator'
//  '<S64>'  : 'controlModel/Speed estimator/DataTypeConversionA'
//  '<S65>'  : 'controlModel/Speed estimator/DataTypeConversionB'
//  '<S66>'  : 'controlModel/Speed estimator/DataTypeConversionC'
//  '<S67>'  : 'controlModel/Speed estimator/DataTypeConversionD'
//  '<S68>'  : 'controlModel/Speed estimator/DataTypeConversionEnable'
//  '<S69>'  : 'controlModel/Speed estimator/DataTypeConversionG'
//  '<S70>'  : 'controlModel/Speed estimator/DataTypeConversionH'
//  '<S71>'  : 'controlModel/Speed estimator/DataTypeConversionN'
//  '<S72>'  : 'controlModel/Speed estimator/DataTypeConversionP'
//  '<S73>'  : 'controlModel/Speed estimator/DataTypeConversionP0'
//  '<S74>'  : 'controlModel/Speed estimator/DataTypeConversionQ'
//  '<S75>'  : 'controlModel/Speed estimator/DataTypeConversionR'
//  '<S76>'  : 'controlModel/Speed estimator/DataTypeConversionReset'
//  '<S77>'  : 'controlModel/Speed estimator/DataTypeConversionX'
//  '<S78>'  : 'controlModel/Speed estimator/DataTypeConversionX0'
//  '<S79>'  : 'controlModel/Speed estimator/DataTypeConversionu'
//  '<S80>'  : 'controlModel/Speed estimator/MemoryP'
//  '<S81>'  : 'controlModel/Speed estimator/Observer'
//  '<S82>'  : 'controlModel/Speed estimator/ReducedQRN'
//  '<S83>'  : 'controlModel/Speed estimator/Reset'
//  '<S84>'  : 'controlModel/Speed estimator/ScalarExpansionP0'
//  '<S85>'  : 'controlModel/Speed estimator/ScalarExpansionQ'
//  '<S86>'  : 'controlModel/Speed estimator/ScalarExpansionR'
//  '<S87>'  : 'controlModel/Speed estimator/UseCurrentEstimator'
//  '<S88>'  : 'controlModel/Speed estimator/checkA'
//  '<S89>'  : 'controlModel/Speed estimator/checkB'
//  '<S90>'  : 'controlModel/Speed estimator/checkC'
//  '<S91>'  : 'controlModel/Speed estimator/checkD'
//  '<S92>'  : 'controlModel/Speed estimator/checkEnable'
//  '<S93>'  : 'controlModel/Speed estimator/checkG'
//  '<S94>'  : 'controlModel/Speed estimator/checkH'
//  '<S95>'  : 'controlModel/Speed estimator/checkN'
//  '<S96>'  : 'controlModel/Speed estimator/checkP0'
//  '<S97>'  : 'controlModel/Speed estimator/checkQ'
//  '<S98>'  : 'controlModel/Speed estimator/checkR'
//  '<S99>'  : 'controlModel/Speed estimator/checkReset'
//  '<S100>' : 'controlModel/Speed estimator/checkX0'
//  '<S101>' : 'controlModel/Speed estimator/checku'
//  '<S102>' : 'controlModel/Speed estimator/checky'
//  '<S103>' : 'controlModel/Speed estimator/CalculatePL/DataTypeConversionL'
//  '<S104>' : 'controlModel/Speed estimator/CalculatePL/DataTypeConversionM'
//  '<S105>' : 'controlModel/Speed estimator/CalculatePL/DataTypeConversionP'
//  '<S106>' : 'controlModel/Speed estimator/CalculatePL/DataTypeConversionZ'
//  '<S107>' : 'controlModel/Speed estimator/CalculatePL/Ground'
//  '<S108>' : 'controlModel/Speed estimator/CovarianceOutputConfigurator/decideOutput'
//  '<S109>' : 'controlModel/Speed estimator/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S110>' : 'controlModel/Speed estimator/Observer/MeasurementUpdate'
//  '<S111>' : 'controlModel/Speed estimator/ReducedQRN/Ground'
//  '<S112>' : 'controlModel/Speed estimator/UseCurrentEstimator/Enabled Subsystem'
//  '<S113>' : 'controlModel/Steer estimator/CalculatePL'
//  '<S114>' : 'controlModel/Steer estimator/CalculateYhat'
//  '<S115>' : 'controlModel/Steer estimator/CovarianceOutputConfigurator'
//  '<S116>' : 'controlModel/Steer estimator/DataTypeConversionA'
//  '<S117>' : 'controlModel/Steer estimator/DataTypeConversionB'
//  '<S118>' : 'controlModel/Steer estimator/DataTypeConversionC'
//  '<S119>' : 'controlModel/Steer estimator/DataTypeConversionD'
//  '<S120>' : 'controlModel/Steer estimator/DataTypeConversionEnable'
//  '<S121>' : 'controlModel/Steer estimator/DataTypeConversionG'
//  '<S122>' : 'controlModel/Steer estimator/DataTypeConversionH'
//  '<S123>' : 'controlModel/Steer estimator/DataTypeConversionN'
//  '<S124>' : 'controlModel/Steer estimator/DataTypeConversionP'
//  '<S125>' : 'controlModel/Steer estimator/DataTypeConversionP0'
//  '<S126>' : 'controlModel/Steer estimator/DataTypeConversionQ'
//  '<S127>' : 'controlModel/Steer estimator/DataTypeConversionR'
//  '<S128>' : 'controlModel/Steer estimator/DataTypeConversionReset'
//  '<S129>' : 'controlModel/Steer estimator/DataTypeConversionX'
//  '<S130>' : 'controlModel/Steer estimator/DataTypeConversionX0'
//  '<S131>' : 'controlModel/Steer estimator/DataTypeConversionu'
//  '<S132>' : 'controlModel/Steer estimator/MemoryP'
//  '<S133>' : 'controlModel/Steer estimator/Observer'
//  '<S134>' : 'controlModel/Steer estimator/ReducedQRN'
//  '<S135>' : 'controlModel/Steer estimator/Reset'
//  '<S136>' : 'controlModel/Steer estimator/ScalarExpansionP0'
//  '<S137>' : 'controlModel/Steer estimator/ScalarExpansionQ'
//  '<S138>' : 'controlModel/Steer estimator/ScalarExpansionR'
//  '<S139>' : 'controlModel/Steer estimator/UseCurrentEstimator'
//  '<S140>' : 'controlModel/Steer estimator/checkA'
//  '<S141>' : 'controlModel/Steer estimator/checkB'
//  '<S142>' : 'controlModel/Steer estimator/checkC'
//  '<S143>' : 'controlModel/Steer estimator/checkD'
//  '<S144>' : 'controlModel/Steer estimator/checkEnable'
//  '<S145>' : 'controlModel/Steer estimator/checkG'
//  '<S146>' : 'controlModel/Steer estimator/checkH'
//  '<S147>' : 'controlModel/Steer estimator/checkN'
//  '<S148>' : 'controlModel/Steer estimator/checkP0'
//  '<S149>' : 'controlModel/Steer estimator/checkQ'
//  '<S150>' : 'controlModel/Steer estimator/checkR'
//  '<S151>' : 'controlModel/Steer estimator/checkReset'
//  '<S152>' : 'controlModel/Steer estimator/checkX0'
//  '<S153>' : 'controlModel/Steer estimator/checku'
//  '<S154>' : 'controlModel/Steer estimator/checky'
//  '<S155>' : 'controlModel/Steer estimator/CalculatePL/DataTypeConversionL'
//  '<S156>' : 'controlModel/Steer estimator/CalculatePL/DataTypeConversionM'
//  '<S157>' : 'controlModel/Steer estimator/CalculatePL/DataTypeConversionP'
//  '<S158>' : 'controlModel/Steer estimator/CalculatePL/DataTypeConversionZ'
//  '<S159>' : 'controlModel/Steer estimator/CalculatePL/Ground'
//  '<S160>' : 'controlModel/Steer estimator/CovarianceOutputConfigurator/decideOutput'
//  '<S161>' : 'controlModel/Steer estimator/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S162>' : 'controlModel/Steer estimator/Observer/MeasurementUpdate'
//  '<S163>' : 'controlModel/Steer estimator/ReducedQRN/Ground'
//  '<S164>' : 'controlModel/Steer estimator/UseCurrentEstimator/Enabled Subsystem'

#endif                                 // RTW_HEADER_controlModel_h_

//
// File trailer for generated code.
//
// [EOF]
//
