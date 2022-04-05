//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controlModel.h
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 3.2
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Tue Apr  5 11:38:24 2022
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
#include "rt_defines.h"

extern "C" {

#include "rt_nonfinite.h"

}
// Type definition for custom storage class: Struct
  struct controlParams_type
{
  real32_T derGainSpeed;               // Referenced by: '<Root>/Constant2'
  real32_T intGainSpeed;               // Referenced by: '<Root>/Constant1'
  real32_T wheelInertia;               // Referenced by:
                                          //  '<S6>/MATLAB Function'
                                          //  '<S7>/MATLAB Function'

  real32_T rollInertia;                // Referenced by:
                                          //  '<S6>/MATLAB Function'
                                          //  '<S7>/MATLAB Function'

  real32_T propGainSpeed;              // Referenced by: '<Root>/Constant'
  real32_T Qomx;                       // Referenced by: '<Root>/Q and R'
  real32_T Qphi;                       // Referenced by: '<Root>/Q and R'
  real32_T Romx;                       // Referenced by: '<Root>/Q and R'
  real32_T riderTrqTreshold;           // Referenced by: '<Root>/Dead Zone'
  real32_T maxSpeed;                   // Referenced by: '<Root>/Gain1'
  real32_T gravity;                    // Referenced by:
                                          //  '<S6>/MATLAB Function'
                                          //  '<S7>/MATLAB Function'

  real32_T COGheight;                  // Referenced by:
                                          //  '<S6>/MATLAB Function'
                                          //  '<S7>/MATLAB Function'

  real32_T maxCurrent;                 // Referenced by: '<Root>/Saturation'
  real32_T trqGainControl;             // Referenced by: '<Root>/Gain'
  real32_T trqConstant;                // Referenced by: '<Root>/Trq const'
  real32_T bikeMass;                   // Referenced by:
                                          //  '<S6>/MATLAB Function'
                                          //  '<S7>/MATLAB Function'

  real32_T torusRadius;                // Referenced by:
                                          //  '<S6>/MATLAB Function'
                                          //  '<S7>/MATLAB Function'

  real32_T rollingRadius;              // Referenced by:
                                          //  '<S6>/MATLAB Function'
                                          //  '<S7>/MATLAB Function'

  real32_T beltRatio;                  // Referenced by: '<Root>/Belt and gear'
  real32_T gearRatio;                  // Referenced by: '<Root>/Belt and gear'
}

;

// Exported data declaration

// Declaration for custom storage class: Struct
extern controlParams_type controlParams;

// Class declaration for model controlModel
class ControlClass
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<Root>'
  struct DW_controlModel_T {
    dsp_simulink_LowpassFilter_co_T obj;// '<Root>/Lowpass Filter'
    real32_T P[4];                     // '<S2>/DataStoreMemory - P'
    real32_T x[2];                     // '<S2>/DataStoreMemory - x'
    real32_T Integrator_DSTATE;        // '<S43>/Integrator'
    real32_T UD_DSTATE;                // '<S36>/UD'
    uint8_T error_state;               // '<Root>/Unit Delay'
    boolean_T blockOrdering;           // '<S60>/Correct'
    boolean_T isInitialized;           // '<Root>/Lowpass Filter'
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

  // model event function
  void reset();

  // model terminate function
  void stop();

  // Constructor
  ControlClass();

  // Destructor
  ~ControlClass();

  // private data and function members
 private:
  // Block states
  DW_controlModel_T controlModel_DW;

  // private member function(s) for subsystem '<Root>/Simulink Function'
  void rollEKF_stateTransitionModel(const real32_T rtu_x[2], real32_T rty_xNext
    [2]);

  // private member function(s) for subsystem '<Root>/Simulink Function1'
  void rollEKF_stateTransitionJac(const real32_T rtu_x[2], real32_T rty_F[4]);

  // private member function(s) for subsystem '<Root>/Simulink Function2'
  void rollEKF_measurementModel(const real32_T rtu_x[2], real32_T *rty_y);

  // private member function(s) for subsystem '<Root>/Simulink Function3'
  void rollEKF_measurementJac(const real32_T rtu_x[2], real32_T rty_H[2]);

  // private member function(s) for subsystem '<Root>'
  void EKFCorrectorAdditive_getMeasure(real32_T Rs, const real32_T x[2], const
    real32_T S[4], real32_T *zEstimated, real32_T Pxy[2], real32_T *Sy, real32_T
    dHdx[2], real32_T *Rsqrt);
  void co_EKFPredictorAdditive_predict(const real32_T Qs[4], real32_T x[2],
    real32_T S[4]);
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S36>/DTDup' : Unused code path elimination
//  Block '<S60>/RegisterSimulinkFcn' : Unused code path elimination
//  Block '<S62>/RegisterSimulinkFcn' : Unused code path elimination
//  Block '<S2>/checkMeasurementFcn1Signals' : Unused code path elimination
//  Block '<S2>/checkStateTransitionFcnSignals' : Unused code path elimination
//  Block '<Root>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S2>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
//  Block '<S2>/DataTypeConversion_Q' : Eliminate redundant data type conversion
//  Block '<S2>/DataTypeConversion_R1' : Eliminate redundant data type conversion
//  Block '<S2>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
//  Block '<S2>/DataTypeConversion_uState' : Eliminate redundant data type conversion
//  Block '<S2>/DataTypeConversion_y1' : Eliminate redundant data type conversion


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
//  '<S1>'   : 'controlModel/Discrete PID Controller'
//  '<S2>'   : 'controlModel/EKF'
//  '<S3>'   : 'controlModel/Initialize Function'
//  '<S4>'   : 'controlModel/Q and R'
//  '<S5>'   : 'controlModel/Reset Function'
//  '<S6>'   : 'controlModel/Simulink Function'
//  '<S7>'   : 'controlModel/Simulink Function1'
//  '<S8>'   : 'controlModel/Simulink Function2'
//  '<S9>'   : 'controlModel/Simulink Function3'
//  '<S10>'  : 'controlModel/Discrete PID Controller/Anti-windup'
//  '<S11>'  : 'controlModel/Discrete PID Controller/D Gain'
//  '<S12>'  : 'controlModel/Discrete PID Controller/Filter'
//  '<S13>'  : 'controlModel/Discrete PID Controller/Filter ICs'
//  '<S14>'  : 'controlModel/Discrete PID Controller/I Gain'
//  '<S15>'  : 'controlModel/Discrete PID Controller/Ideal P Gain'
//  '<S16>'  : 'controlModel/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S17>'  : 'controlModel/Discrete PID Controller/Integrator'
//  '<S18>'  : 'controlModel/Discrete PID Controller/Integrator ICs'
//  '<S19>'  : 'controlModel/Discrete PID Controller/N Copy'
//  '<S20>'  : 'controlModel/Discrete PID Controller/N Gain'
//  '<S21>'  : 'controlModel/Discrete PID Controller/P Copy'
//  '<S22>'  : 'controlModel/Discrete PID Controller/Parallel P Gain'
//  '<S23>'  : 'controlModel/Discrete PID Controller/Reset Signal'
//  '<S24>'  : 'controlModel/Discrete PID Controller/Saturation'
//  '<S25>'  : 'controlModel/Discrete PID Controller/Saturation Fdbk'
//  '<S26>'  : 'controlModel/Discrete PID Controller/Sum'
//  '<S27>'  : 'controlModel/Discrete PID Controller/Sum Fdbk'
//  '<S28>'  : 'controlModel/Discrete PID Controller/Tracking Mode'
//  '<S29>'  : 'controlModel/Discrete PID Controller/Tracking Mode Sum'
//  '<S30>'  : 'controlModel/Discrete PID Controller/Tsamp - Integral'
//  '<S31>'  : 'controlModel/Discrete PID Controller/Tsamp - Ngain'
//  '<S32>'  : 'controlModel/Discrete PID Controller/postSat Signal'
//  '<S33>'  : 'controlModel/Discrete PID Controller/preSat Signal'
//  '<S34>'  : 'controlModel/Discrete PID Controller/Anti-windup/Passthrough'
//  '<S35>'  : 'controlModel/Discrete PID Controller/D Gain/External Parameters'
//  '<S36>'  : 'controlModel/Discrete PID Controller/Filter/Differentiator'
//  '<S37>'  : 'controlModel/Discrete PID Controller/Filter/Differentiator/Tsamp'
//  '<S38>'  : 'controlModel/Discrete PID Controller/Filter/Differentiator/Tsamp/Internal Ts'
//  '<S39>'  : 'controlModel/Discrete PID Controller/Filter ICs/Internal IC - Differentiator'
//  '<S40>'  : 'controlModel/Discrete PID Controller/I Gain/External Parameters'
//  '<S41>'  : 'controlModel/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S42>'  : 'controlModel/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S43>'  : 'controlModel/Discrete PID Controller/Integrator/Discrete'
//  '<S44>'  : 'controlModel/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S45>'  : 'controlModel/Discrete PID Controller/N Copy/Disabled wSignal Specification'
//  '<S46>'  : 'controlModel/Discrete PID Controller/N Gain/Passthrough'
//  '<S47>'  : 'controlModel/Discrete PID Controller/P Copy/Disabled'
//  '<S48>'  : 'controlModel/Discrete PID Controller/Parallel P Gain/External Parameters'
//  '<S49>'  : 'controlModel/Discrete PID Controller/Reset Signal/Disabled'
//  '<S50>'  : 'controlModel/Discrete PID Controller/Saturation/Enabled'
//  '<S51>'  : 'controlModel/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S52>'  : 'controlModel/Discrete PID Controller/Sum/Sum_PID'
//  '<S53>'  : 'controlModel/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S54>'  : 'controlModel/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S55>'  : 'controlModel/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S56>'  : 'controlModel/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S57>'  : 'controlModel/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S58>'  : 'controlModel/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S59>'  : 'controlModel/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S60>'  : 'controlModel/EKF/Correct1'
//  '<S61>'  : 'controlModel/EKF/Output'
//  '<S62>'  : 'controlModel/EKF/Predict'
//  '<S63>'  : 'controlModel/EKF/Correct1/Correct'
//  '<S64>'  : 'controlModel/EKF/Output/MATLAB Function'
//  '<S65>'  : 'controlModel/EKF/Predict/Predict'
//  '<S66>'  : 'controlModel/Simulink Function/MATLAB Function'
//  '<S67>'  : 'controlModel/Simulink Function1/MATLAB Function'

#endif                                 // RTW_HEADER_controlModel_h_

//
// File trailer for generated code.
//
// [EOF]
//
