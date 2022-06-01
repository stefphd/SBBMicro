//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controlModel.h
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 3.8
// Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
// C/C++ source code generated on : Wed Jun  1 08:18:25 2022
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
  real32_T wheelInertia;               // Referenced by:
                                          //  '<S5>/MATLAB Function'
                                          //  '<S6>/MATLAB Function'

  real32_T rollInertia;                // Referenced by:
                                          //  '<S5>/MATLAB Function'
                                          //  '<S6>/MATLAB Function'

  real32_T Qomx;                       // Referenced by: '<Root>/Q and R'
  real32_T Qphi;                       // Referenced by: '<Root>/Q and R'
  real32_T Romx;                       // Referenced by: '<Root>/Q and R'
  real32_T gravity;                    // Referenced by:
                                          //  '<S5>/MATLAB Function'
                                          //  '<S6>/MATLAB Function'

  real32_T COGheight;                  // Referenced by:
                                          //  '<S5>/MATLAB Function'
                                          //  '<S6>/MATLAB Function'

  real32_T maxCurrent;                 // Referenced by: '<Root>/Gain'
  real32_T bikeMass;                   // Referenced by:
                                          //  '<S5>/MATLAB Function'
                                          //  '<S6>/MATLAB Function'

  real32_T torusRadius;                // Referenced by:
                                          //  '<S5>/MATLAB Function'
                                          //  '<S6>/MATLAB Function'

  real32_T rollingRadius;              // Referenced by:
                                          //  '<S5>/MATLAB Function'
                                          //  '<S6>/MATLAB Function'

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
    real32_T P[4];                     // '<S1>/DataStoreMemory - P'
    real32_T x[2];                     // '<S1>/DataStoreMemory - x'
    uint8_T error_state;               // '<Root>/Unit Delay'
    boolean_T blockOrdering;           // '<S9>/Correct'
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
//  Block '<S9>/RegisterSimulinkFcn' : Unused code path elimination
//  Block '<S11>/RegisterSimulinkFcn' : Unused code path elimination
//  Block '<S1>/checkMeasurementFcn1Signals' : Unused code path elimination
//  Block '<S1>/checkStateTransitionFcnSignals' : Unused code path elimination
//  Block '<Root>/Data Type Conversion3' : Eliminate redundant data type conversion
//  Block '<S1>/DataTypeConversion_Enable1' : Eliminate redundant data type conversion
//  Block '<S1>/DataTypeConversion_Q' : Eliminate redundant data type conversion
//  Block '<S1>/DataTypeConversion_R1' : Eliminate redundant data type conversion
//  Block '<S1>/DataTypeConversion_uMeas1' : Eliminate redundant data type conversion
//  Block '<S1>/DataTypeConversion_uState' : Eliminate redundant data type conversion
//  Block '<S1>/DataTypeConversion_y1' : Eliminate redundant data type conversion


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
//  '<S1>'   : 'controlModel/EKF'
//  '<S2>'   : 'controlModel/Initialize Function'
//  '<S3>'   : 'controlModel/Q and R'
//  '<S4>'   : 'controlModel/Reset Function'
//  '<S5>'   : 'controlModel/Simulink Function'
//  '<S6>'   : 'controlModel/Simulink Function1'
//  '<S7>'   : 'controlModel/Simulink Function2'
//  '<S8>'   : 'controlModel/Simulink Function3'
//  '<S9>'   : 'controlModel/EKF/Correct1'
//  '<S10>'  : 'controlModel/EKF/Output'
//  '<S11>'  : 'controlModel/EKF/Predict'
//  '<S12>'  : 'controlModel/EKF/Correct1/Correct'
//  '<S13>'  : 'controlModel/EKF/Output/MATLAB Function'
//  '<S14>'  : 'controlModel/EKF/Predict/Predict'
//  '<S15>'  : 'controlModel/Simulink Function/MATLAB Function'
//  '<S16>'  : 'controlModel/Simulink Function1/MATLAB Function'

#endif                                 // RTW_HEADER_controlModel_h_

//
// File trailer for generated code.
//
// [EOF]
//
