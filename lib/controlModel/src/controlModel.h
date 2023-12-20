//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controlModel.h
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
#ifndef RTW_HEADER_controlModel_h_
#define RTW_HEADER_controlModel_h_
#include "rtwtypes.h"
#include "controlModel_types.h"

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
  real32_T derGainSteerCtrl;          // Referenced by: '<S39>/Derivative Gain'
  real32_T intGainSteerCtrl;           // Referenced by: '<S42>/Integral Gain'
  real32_T filtGainSteerCtrl;      // Referenced by: '<S48>/Filter Coefficient'
  real32_T propGainSteerCtrl;       // Referenced by: '<S50>/Proportional Gain'
  real32_T deltaRefGain;               // Referenced by: '<Root>/Gain1'
  real32_T gravity;                    // Referenced by: '<Root>/Gain'
  real32_T maxCurrent;                 // Referenced by:
                                          //  '<Root>/Saturation'
                                          //  '<S52>/Saturation'

  real32_T maxSteer;                   // Referenced by: '<Root>/Chart'
  real32_T rollSaturation;             // Referenced by: '<Root>/Saturation1'
};

// Exported data declaration

// Declaration for custom storage class: Struct
extern controlParams_type controlParams;

// Class declaration for model controlModel
class ControlClass
{
  // public data and function members
 public:
  // Block signals and states (default storage) for system '<S82>/MeasurementUpdate' 
  struct DW_MeasurementUpdate_controlM_T {
    boolean_T MeasurementUpdate_MODE;  // '<S82>/MeasurementUpdate'
  };

  // Block signals and states (default storage) for system '<S88>/Enabled Subsystem' 
  struct DW_EnabledSubsystem_controlMo_T {
    boolean_T EnabledSubsystem_MODE;   // '<S88>/Enabled Subsystem'
  };

  // Block signals and states (default storage) for system '<S134>/MeasurementUpdate' 
  struct DW_MeasurementUpdate_contro_l_T {
    boolean_T MeasurementUpdate_MODE;  // '<S134>/MeasurementUpdate'
  };

  // Block signals and states (default storage) for system '<S140>/Enabled Subsystem' 
  struct DW_EnabledSubsystem_control_p_T {
    boolean_T EnabledSubsystem_MODE;   // '<S140>/Enabled Subsystem'
  };

  // Block signals and states (default storage) for system '<Root>'
  struct DW_controlModel_T {
    DW_EnabledSubsystem_controlMo_T EnabledSubsystem_g;// '<S348>/Enabled Subsystem' 
    DW_MeasurementUpdate_controlM_T MeasurementUpdate_a;// '<S342>/MeasurementUpdate' 
    DW_EnabledSubsystem_controlMo_T EnabledSubsystem_pd;// '<S296>/Enabled Subsystem' 
    DW_MeasurementUpdate_controlM_T MeasurementUpdate_i;// '<S290>/MeasurementUpdate' 
    DW_EnabledSubsystem_controlMo_T EnabledSubsystem_e;// '<S244>/Enabled Subsystem' 
    DW_MeasurementUpdate_controlM_T MeasurementUpdate_cv;// '<S238>/MeasurementUpdate' 
    DW_EnabledSubsystem_control_p_T EnabledSubsystem_d;// '<S192>/Enabled Subsystem' 
    DW_MeasurementUpdate_contro_l_T MeasurementUpdate_c;// '<S186>/MeasurementUpdate' 
    DW_EnabledSubsystem_control_p_T EnabledSubsystem_p;// '<S140>/Enabled Subsystem' 
    DW_MeasurementUpdate_contro_l_T MeasurementUpdate_p;// '<S134>/MeasurementUpdate' 
    DW_EnabledSubsystem_controlMo_T EnabledSubsystem;// '<S88>/Enabled Subsystem' 
    DW_MeasurementUpdate_controlM_T MeasurementUpdate;// '<S82>/MeasurementUpdate' 
    dsp_simulink_LowpassFilter_co_T obj;// '<Root>/Lowpass Filter'
    real32_T Product2[2];              // '<S373>/Product2'
    real32_T Product3[2];              // '<S371>/Product3'
    real32_T Product2_d[2];            // '<S321>/Product2'
    real32_T Product3_o[2];            // '<S319>/Product3'
    real32_T Product2_b[2];            // '<S269>/Product2'
    real32_T Product3_b[2];            // '<S267>/Product3'
    real32_T Product2_ba[3];           // '<S217>/Product2'
    real32_T Product3_bz[3];           // '<S215>/Product3'
    real32_T Product2_c[3];            // '<S165>/Product2'
    real32_T Product3_p[3];            // '<S163>/Product3'
    real32_T Product2_d4[2];           // '<S113>/Product2'
    real32_T Product3_a[2];            // '<S111>/Product3'
    real32_T MemoryX_DSTATE[3];        // '<S10>/MemoryX'
    real32_T MemoryX_DSTATE_k[3];      // '<S8>/MemoryX'
    real32_T MemoryX_DSTATE_p[2];      // '<S13>/MemoryX'
    real32_T MemoryX_DSTATE_d[2];      // '<S11>/MemoryX'
    real32_T MemoryX_DSTATE_g[2];      // '<S6>/MemoryX'
    real32_T MemoryX_DSTATE_l[2];      // '<S12>/MemoryX'
    real32_T lat0;                     // '<Root>/Reset lat0 & long0'
    real32_T long0;                    // '<Root>/Reset lat0 & long0'
    real32_T Integrator_DSTATE;        // '<S45>/Integrator'
    real32_T Filter_DSTATE;            // '<S40>/Filter'
    real32_T UnitDelay_DSTATE;         // '<Root>/Unit Delay'
    uint8_T is_c4_controlModel;        // '<Root>/Reset lat0 & long0'
    uint8_T is_active_c4_controlModel; // '<Root>/Reset lat0 & long0'
    uint8_T is_c1_controlModel;        // '<Root>/Chart1'
    uint8_T is_active_c1_controlModel; // '<Root>/Chart1'
    uint8_T is_c3_controlModel;        // '<Root>/Chart'
    uint8_T is_active_c3_controlModel; // '<Root>/Chart'
    boolean_T icLoad;                  // '<S10>/MemoryX'
    boolean_T icLoad_i;                // '<S8>/MemoryX'
    boolean_T icLoad_e;                // '<S13>/MemoryX'
    boolean_T icLoad_l;                // '<S11>/MemoryX'
    boolean_T icLoad_d;                // '<S6>/MemoryX'
    boolean_T icLoad_ib;               // '<S12>/MemoryX'
    boolean_T isInitialized;           // '<Root>/Lowpass Filter'
  };

  // Invariant block signals (default storage)
  struct ConstB_controlModel_T {
    real32_T Conversion[6];            // '<S208>/Conversion'
    real32_T Conversion_k[6];          // '<S209>/Conversion'
    real32_T Conversion_n[9];          // '<S211>/Conversion'
    real32_T Conversion_ni[2];         // '<S104>/Conversion'
    real32_T Conversion_i[2];          // '<S105>/Conversion'
    real32_T Conversion_c[4];          // '<S107>/Conversion'
    real32_T Conversion_b[6];          // '<S156>/Conversion'
    real32_T Conversion_l[6];          // '<S157>/Conversion'
    real32_T Conversion_m[9];          // '<S159>/Conversion'
    real32_T Conversion_p[2];          // '<S260>/Conversion'
    real32_T Conversion_g[2];          // '<S261>/Conversion'
    real32_T Conversion_e[4];          // '<S263>/Conversion'
    real32_T Conversion_iu[2];         // '<S312>/Conversion'
    real32_T Conversion_ma[2];         // '<S313>/Conversion'
    real32_T Conversion_j[4];          // '<S315>/Conversion'
    real32_T Conversion_f[2];          // '<S364>/Conversion'
    real32_T Conversion_gp[2];         // '<S365>/Conversion'
    real32_T Conversion_a[4];          // '<S367>/Conversion'
  };

  // Constant parameters (default storage)
  struct ConstP_controlModel_T {
    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S8>/A'
    //    '<S10>/A'

    real32_T pooled8[9];

    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S8>/C'
    //    '<S10>/C'

    real32_T pooled10[6];

    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S6>/X0'
    //    '<S8>/D'
    //    '<S10>/D'
    //    '<S11>/X0'
    //    '<S12>/X0'
    //    '<S13>/X0'

    real32_T pooled11[2];

    // Pooled Parameter (Expression: )
    //  Referenced by:
    //    '<S6>/C'
    //    '<S11>/C'
    //    '<S12>/C'
    //    '<S13>/C'

    real32_T pooled14[2];
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
  void stop();

  // Constructor
  ControlClass();

  // Destructor
  ~ControlClass();

  // private data and function members
 private:
  // Block states
  DW_controlModel_T controlModel_DW;

  // private member function(s) for subsystem '<S109>/SqrtUsedFcn'
  static void controlModel_SqrtUsedFcn(const real32_T rtu_u[4], boolean_T
    rtu_isSqrtUsed, real32_T rty_P[4]);

  // private member function(s) for subsystem '<S82>/MeasurementUpdate'
  static void contr_MeasurementUpdate_Disable(real32_T rty_Lykyhatkk1[2],
    DW_MeasurementUpdate_controlM_T *localDW);
  void controlModel_MeasurementUpdate(boolean_T rtu_Enable, const real32_T
    rtu_Lk[2], real32_T rtu_yk, const real32_T rtu_Ck[2], const real32_T
    rtu_xhatkk1[2], real32_T rtu_Dk, real32_T rtu_uk, real32_T rty_Lykyhatkk1[2],
    DW_MeasurementUpdate_controlM_T *localDW);

  // private member function(s) for subsystem '<S88>/Enabled Subsystem'
  static void contro_EnabledSubsystem_Disable(real32_T rty_deltax[2],
    DW_EnabledSubsystem_controlMo_T *localDW);
  void controlModel_EnabledSubsystem(boolean_T rtu_Enable, const real32_T
    rtu_Mk[2], const real32_T rtu_Ck[2], real32_T rtu_yk, const real32_T
    rtu_xhatkk1[2], real32_T rty_deltax[2], DW_EnabledSubsystem_controlMo_T
    *localDW);

  // private member function(s) for subsystem '<S161>/SqrtUsedFcn'
  static void controlModel_SqrtUsedFcn_c(const real32_T rtu_u[9], boolean_T
    rtu_isSqrtUsed, real32_T rty_P[9]);

  // private member function(s) for subsystem '<S134>/MeasurementUpdate'
  static void con_MeasurementUpdate_b_Disable(real32_T rty_Lykyhatkk1[3],
    DW_MeasurementUpdate_contro_l_T *localDW);
  void controlMode_MeasurementUpdate_p(boolean_T rtu_Enable, const real32_T
    rtu_Lk[6], const real32_T rtu_yk[2], const real32_T rtu_Ck[6], const
    real32_T rtu_xhatkk1[3], const real32_T rtu_Dk[2], real32_T rtu_uk, real32_T
    rty_Lykyhatkk1[3], DW_MeasurementUpdate_contro_l_T *localDW);

  // private member function(s) for subsystem '<S140>/Enabled Subsystem'
  static void cont_EnabledSubsystem_l_Disable(real32_T rty_deltax[3],
    DW_EnabledSubsystem_control_p_T *localDW);
  void controlModel_EnabledSubsystem_p(boolean_T rtu_Enable, const real32_T
    rtu_Mk[6], const real32_T rtu_Ck[6], const real32_T rtu_yk[2], const
    real32_T rtu_xhatkk1[3], real32_T rty_deltax[3],
    DW_EnabledSubsystem_control_p_T *localDW);
};

extern const ControlClass::ConstB_controlModel_T controlModel_ConstB;// constant block i/o 

// Constant parameters (default storage)
extern const ControlClass::ConstP_controlModel_T controlModel_ConstP;

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<S104>/Data Type Duplicate' : Unused code path elimination
//  Block '<S105>/Data Type Duplicate' : Unused code path elimination
//  Block '<S106>/Conversion' : Unused code path elimination
//  Block '<S106>/Data Type Duplicate' : Unused code path elimination
//  Block '<S107>/Data Type Duplicate' : Unused code path elimination
//  Block '<S65>/Data Type Duplicate' : Unused code path elimination
//  Block '<S66>/Data Type Duplicate' : Unused code path elimination
//  Block '<S67>/Data Type Duplicate' : Unused code path elimination
//  Block '<S68>/Data Type Duplicate' : Unused code path elimination
//  Block '<S70>/Data Type Duplicate' : Unused code path elimination
//  Block '<S71>/Data Type Duplicate' : Unused code path elimination
//  Block '<S72>/Data Type Duplicate' : Unused code path elimination
//  Block '<S73>/Conversion' : Unused code path elimination
//  Block '<S73>/Data Type Duplicate' : Unused code path elimination
//  Block '<S74>/Data Type Duplicate' : Unused code path elimination
//  Block '<S75>/Data Type Duplicate' : Unused code path elimination
//  Block '<S76>/Data Type Duplicate' : Unused code path elimination
//  Block '<S78>/Data Type Duplicate' : Unused code path elimination
//  Block '<S79>/Data Type Duplicate' : Unused code path elimination
//  Block '<S6>/G' : Unused code path elimination
//  Block '<S6>/H' : Unused code path elimination
//  Block '<S6>/N' : Unused code path elimination
//  Block '<S6>/P0' : Unused code path elimination
//  Block '<S6>/Q' : Unused code path elimination
//  Block '<S6>/R' : Unused code path elimination
//  Block '<S6>/Reshapexhat' : Unused code path elimination
//  Block '<S102>/CheckSignalProperties' : Unused code path elimination
//  Block '<S103>/CheckSignalProperties' : Unused code path elimination
//  Block '<S156>/Data Type Duplicate' : Unused code path elimination
//  Block '<S157>/Data Type Duplicate' : Unused code path elimination
//  Block '<S158>/Conversion' : Unused code path elimination
//  Block '<S158>/Data Type Duplicate' : Unused code path elimination
//  Block '<S159>/Data Type Duplicate' : Unused code path elimination
//  Block '<S117>/Data Type Duplicate' : Unused code path elimination
//  Block '<S118>/Data Type Duplicate' : Unused code path elimination
//  Block '<S119>/Data Type Duplicate' : Unused code path elimination
//  Block '<S120>/Data Type Duplicate' : Unused code path elimination
//  Block '<S122>/Data Type Duplicate' : Unused code path elimination
//  Block '<S123>/Data Type Duplicate' : Unused code path elimination
//  Block '<S124>/Data Type Duplicate' : Unused code path elimination
//  Block '<S125>/Conversion' : Unused code path elimination
//  Block '<S125>/Data Type Duplicate' : Unused code path elimination
//  Block '<S126>/Data Type Duplicate' : Unused code path elimination
//  Block '<S127>/Data Type Duplicate' : Unused code path elimination
//  Block '<S128>/Data Type Duplicate' : Unused code path elimination
//  Block '<S130>/Data Type Duplicate' : Unused code path elimination
//  Block '<S131>/Data Type Duplicate' : Unused code path elimination
//  Block '<S8>/G' : Unused code path elimination
//  Block '<S8>/H' : Unused code path elimination
//  Block '<S8>/N' : Unused code path elimination
//  Block '<S8>/P0' : Unused code path elimination
//  Block '<S8>/Q' : Unused code path elimination
//  Block '<S8>/R' : Unused code path elimination
//  Block '<S8>/Reshapexhat' : Unused code path elimination
//  Block '<S154>/CheckSignalProperties' : Unused code path elimination
//  Block '<S155>/CheckSignalProperties' : Unused code path elimination
//  Block '<S208>/Data Type Duplicate' : Unused code path elimination
//  Block '<S209>/Data Type Duplicate' : Unused code path elimination
//  Block '<S210>/Conversion' : Unused code path elimination
//  Block '<S210>/Data Type Duplicate' : Unused code path elimination
//  Block '<S211>/Data Type Duplicate' : Unused code path elimination
//  Block '<S169>/Data Type Duplicate' : Unused code path elimination
//  Block '<S170>/Data Type Duplicate' : Unused code path elimination
//  Block '<S171>/Data Type Duplicate' : Unused code path elimination
//  Block '<S172>/Data Type Duplicate' : Unused code path elimination
//  Block '<S174>/Data Type Duplicate' : Unused code path elimination
//  Block '<S175>/Data Type Duplicate' : Unused code path elimination
//  Block '<S176>/Data Type Duplicate' : Unused code path elimination
//  Block '<S177>/Conversion' : Unused code path elimination
//  Block '<S177>/Data Type Duplicate' : Unused code path elimination
//  Block '<S178>/Data Type Duplicate' : Unused code path elimination
//  Block '<S179>/Data Type Duplicate' : Unused code path elimination
//  Block '<S180>/Data Type Duplicate' : Unused code path elimination
//  Block '<S182>/Data Type Duplicate' : Unused code path elimination
//  Block '<S183>/Data Type Duplicate' : Unused code path elimination
//  Block '<S10>/G' : Unused code path elimination
//  Block '<S10>/H' : Unused code path elimination
//  Block '<S10>/N' : Unused code path elimination
//  Block '<S10>/P0' : Unused code path elimination
//  Block '<S10>/Q' : Unused code path elimination
//  Block '<S10>/R' : Unused code path elimination
//  Block '<S10>/Reshapexhat' : Unused code path elimination
//  Block '<S206>/CheckSignalProperties' : Unused code path elimination
//  Block '<S207>/CheckSignalProperties' : Unused code path elimination
//  Block '<S260>/Data Type Duplicate' : Unused code path elimination
//  Block '<S261>/Data Type Duplicate' : Unused code path elimination
//  Block '<S262>/Conversion' : Unused code path elimination
//  Block '<S262>/Data Type Duplicate' : Unused code path elimination
//  Block '<S263>/Data Type Duplicate' : Unused code path elimination
//  Block '<S221>/Data Type Duplicate' : Unused code path elimination
//  Block '<S222>/Data Type Duplicate' : Unused code path elimination
//  Block '<S223>/Data Type Duplicate' : Unused code path elimination
//  Block '<S224>/Data Type Duplicate' : Unused code path elimination
//  Block '<S226>/Data Type Duplicate' : Unused code path elimination
//  Block '<S227>/Data Type Duplicate' : Unused code path elimination
//  Block '<S228>/Data Type Duplicate' : Unused code path elimination
//  Block '<S229>/Conversion' : Unused code path elimination
//  Block '<S229>/Data Type Duplicate' : Unused code path elimination
//  Block '<S230>/Data Type Duplicate' : Unused code path elimination
//  Block '<S231>/Data Type Duplicate' : Unused code path elimination
//  Block '<S232>/Data Type Duplicate' : Unused code path elimination
//  Block '<S234>/Data Type Duplicate' : Unused code path elimination
//  Block '<S235>/Data Type Duplicate' : Unused code path elimination
//  Block '<S11>/G' : Unused code path elimination
//  Block '<S11>/H' : Unused code path elimination
//  Block '<S11>/N' : Unused code path elimination
//  Block '<S11>/P0' : Unused code path elimination
//  Block '<S11>/Q' : Unused code path elimination
//  Block '<S11>/R' : Unused code path elimination
//  Block '<S11>/Reshapexhat' : Unused code path elimination
//  Block '<S258>/CheckSignalProperties' : Unused code path elimination
//  Block '<S259>/CheckSignalProperties' : Unused code path elimination
//  Block '<S312>/Data Type Duplicate' : Unused code path elimination
//  Block '<S313>/Data Type Duplicate' : Unused code path elimination
//  Block '<S314>/Conversion' : Unused code path elimination
//  Block '<S314>/Data Type Duplicate' : Unused code path elimination
//  Block '<S315>/Data Type Duplicate' : Unused code path elimination
//  Block '<S273>/Data Type Duplicate' : Unused code path elimination
//  Block '<S274>/Data Type Duplicate' : Unused code path elimination
//  Block '<S275>/Data Type Duplicate' : Unused code path elimination
//  Block '<S276>/Data Type Duplicate' : Unused code path elimination
//  Block '<S278>/Data Type Duplicate' : Unused code path elimination
//  Block '<S279>/Data Type Duplicate' : Unused code path elimination
//  Block '<S280>/Data Type Duplicate' : Unused code path elimination
//  Block '<S281>/Conversion' : Unused code path elimination
//  Block '<S281>/Data Type Duplicate' : Unused code path elimination
//  Block '<S282>/Data Type Duplicate' : Unused code path elimination
//  Block '<S283>/Data Type Duplicate' : Unused code path elimination
//  Block '<S284>/Data Type Duplicate' : Unused code path elimination
//  Block '<S286>/Data Type Duplicate' : Unused code path elimination
//  Block '<S287>/Data Type Duplicate' : Unused code path elimination
//  Block '<S12>/G' : Unused code path elimination
//  Block '<S12>/H' : Unused code path elimination
//  Block '<S12>/N' : Unused code path elimination
//  Block '<S12>/P0' : Unused code path elimination
//  Block '<S12>/Q' : Unused code path elimination
//  Block '<S12>/R' : Unused code path elimination
//  Block '<S12>/Reshapexhat' : Unused code path elimination
//  Block '<S310>/CheckSignalProperties' : Unused code path elimination
//  Block '<S311>/CheckSignalProperties' : Unused code path elimination
//  Block '<S364>/Data Type Duplicate' : Unused code path elimination
//  Block '<S365>/Data Type Duplicate' : Unused code path elimination
//  Block '<S366>/Conversion' : Unused code path elimination
//  Block '<S366>/Data Type Duplicate' : Unused code path elimination
//  Block '<S367>/Data Type Duplicate' : Unused code path elimination
//  Block '<S325>/Data Type Duplicate' : Unused code path elimination
//  Block '<S326>/Data Type Duplicate' : Unused code path elimination
//  Block '<S327>/Data Type Duplicate' : Unused code path elimination
//  Block '<S328>/Data Type Duplicate' : Unused code path elimination
//  Block '<S330>/Data Type Duplicate' : Unused code path elimination
//  Block '<S331>/Data Type Duplicate' : Unused code path elimination
//  Block '<S332>/Data Type Duplicate' : Unused code path elimination
//  Block '<S333>/Conversion' : Unused code path elimination
//  Block '<S333>/Data Type Duplicate' : Unused code path elimination
//  Block '<S334>/Data Type Duplicate' : Unused code path elimination
//  Block '<S335>/Data Type Duplicate' : Unused code path elimination
//  Block '<S336>/Data Type Duplicate' : Unused code path elimination
//  Block '<S338>/Data Type Duplicate' : Unused code path elimination
//  Block '<S339>/Data Type Duplicate' : Unused code path elimination
//  Block '<S13>/G' : Unused code path elimination
//  Block '<S13>/H' : Unused code path elimination
//  Block '<S13>/N' : Unused code path elimination
//  Block '<S13>/P0' : Unused code path elimination
//  Block '<S13>/Q' : Unused code path elimination
//  Block '<S13>/R' : Unused code path elimination
//  Block '<S13>/Reshapexhat' : Unused code path elimination
//  Block '<S362>/CheckSignalProperties' : Unused code path elimination
//  Block '<S363>/CheckSignalProperties' : Unused code path elimination
//  Block '<S38>/Kb' : Eliminated nontunable gain of 1
//  Block '<S78>/Conversion' : Eliminate redundant data type conversion
//  Block '<S82>/Reshape' : Reshape block reduction
//  Block '<S6>/ReshapeX0' : Reshape block reduction
//  Block '<S6>/Reshapeu' : Reshape block reduction
//  Block '<S6>/Reshapey' : Reshape block reduction
//  Block '<S6>/Reshapeyhat' : Reshape block reduction
//  Block '<S130>/Conversion' : Eliminate redundant data type conversion
//  Block '<S134>/Reshape' : Reshape block reduction
//  Block '<S8>/ReshapeX0' : Reshape block reduction
//  Block '<S8>/Reshapeu' : Reshape block reduction
//  Block '<S8>/Reshapeyhat' : Reshape block reduction
//  Block '<S182>/Conversion' : Eliminate redundant data type conversion
//  Block '<S186>/Reshape' : Reshape block reduction
//  Block '<S10>/ReshapeX0' : Reshape block reduction
//  Block '<S10>/Reshapeu' : Reshape block reduction
//  Block '<S10>/Reshapey' : Reshape block reduction
//  Block '<S10>/Reshapeyhat' : Reshape block reduction
//  Block '<S234>/Conversion' : Eliminate redundant data type conversion
//  Block '<S238>/Reshape' : Reshape block reduction
//  Block '<S11>/ReshapeX0' : Reshape block reduction
//  Block '<S11>/Reshapeu' : Reshape block reduction
//  Block '<S11>/Reshapey' : Reshape block reduction
//  Block '<S11>/Reshapeyhat' : Reshape block reduction
//  Block '<S286>/Conversion' : Eliminate redundant data type conversion
//  Block '<S290>/Reshape' : Reshape block reduction
//  Block '<S12>/ReshapeX0' : Reshape block reduction
//  Block '<S12>/Reshapeu' : Reshape block reduction
//  Block '<S12>/Reshapey' : Reshape block reduction
//  Block '<S12>/Reshapeyhat' : Reshape block reduction
//  Block '<S338>/Conversion' : Eliminate redundant data type conversion
//  Block '<S342>/Reshape' : Reshape block reduction
//  Block '<S13>/ReshapeX0' : Reshape block reduction
//  Block '<S13>/Reshapeu' : Reshape block reduction
//  Block '<S13>/Reshapey' : Reshape block reduction
//  Block '<S13>/Reshapeyhat' : Reshape block reduction


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
//  '<S3>'   : 'controlModel/Discrete PID Controller'
//  '<S4>'   : 'controlModel/MATLAB Function'
//  '<S5>'   : 'controlModel/Reset lat0 & long0'
//  '<S6>'   : 'controlModel/Roll kalman'
//  '<S7>'   : 'controlModel/Roll weighting'
//  '<S8>'   : 'controlModel/Speed estimator'
//  '<S9>'   : 'controlModel/Speed weighting'
//  '<S10>'  : 'controlModel/Steer estimator'
//  '<S11>'  : 'controlModel/Yaw kalman'
//  '<S12>'  : 'controlModel/x pos kalman'
//  '<S13>'  : 'controlModel/y pos kalman'
//  '<S14>'  : 'controlModel/Discrete PID Controller/Anti-windup'
//  '<S15>'  : 'controlModel/Discrete PID Controller/D Gain'
//  '<S16>'  : 'controlModel/Discrete PID Controller/Filter'
//  '<S17>'  : 'controlModel/Discrete PID Controller/Filter ICs'
//  '<S18>'  : 'controlModel/Discrete PID Controller/I Gain'
//  '<S19>'  : 'controlModel/Discrete PID Controller/Ideal P Gain'
//  '<S20>'  : 'controlModel/Discrete PID Controller/Ideal P Gain Fdbk'
//  '<S21>'  : 'controlModel/Discrete PID Controller/Integrator'
//  '<S22>'  : 'controlModel/Discrete PID Controller/Integrator ICs'
//  '<S23>'  : 'controlModel/Discrete PID Controller/N Copy'
//  '<S24>'  : 'controlModel/Discrete PID Controller/N Gain'
//  '<S25>'  : 'controlModel/Discrete PID Controller/P Copy'
//  '<S26>'  : 'controlModel/Discrete PID Controller/Parallel P Gain'
//  '<S27>'  : 'controlModel/Discrete PID Controller/Reset Signal'
//  '<S28>'  : 'controlModel/Discrete PID Controller/Saturation'
//  '<S29>'  : 'controlModel/Discrete PID Controller/Saturation Fdbk'
//  '<S30>'  : 'controlModel/Discrete PID Controller/Sum'
//  '<S31>'  : 'controlModel/Discrete PID Controller/Sum Fdbk'
//  '<S32>'  : 'controlModel/Discrete PID Controller/Tracking Mode'
//  '<S33>'  : 'controlModel/Discrete PID Controller/Tracking Mode Sum'
//  '<S34>'  : 'controlModel/Discrete PID Controller/Tsamp - Integral'
//  '<S35>'  : 'controlModel/Discrete PID Controller/Tsamp - Ngain'
//  '<S36>'  : 'controlModel/Discrete PID Controller/postSat Signal'
//  '<S37>'  : 'controlModel/Discrete PID Controller/preSat Signal'
//  '<S38>'  : 'controlModel/Discrete PID Controller/Anti-windup/Back Calculation'
//  '<S39>'  : 'controlModel/Discrete PID Controller/D Gain/Internal Parameters'
//  '<S40>'  : 'controlModel/Discrete PID Controller/Filter/Disc. Forward Euler Filter'
//  '<S41>'  : 'controlModel/Discrete PID Controller/Filter ICs/Internal IC - Filter'
//  '<S42>'  : 'controlModel/Discrete PID Controller/I Gain/Internal Parameters'
//  '<S43>'  : 'controlModel/Discrete PID Controller/Ideal P Gain/Passthrough'
//  '<S44>'  : 'controlModel/Discrete PID Controller/Ideal P Gain Fdbk/Disabled'
//  '<S45>'  : 'controlModel/Discrete PID Controller/Integrator/Discrete'
//  '<S46>'  : 'controlModel/Discrete PID Controller/Integrator ICs/Internal IC'
//  '<S47>'  : 'controlModel/Discrete PID Controller/N Copy/Disabled'
//  '<S48>'  : 'controlModel/Discrete PID Controller/N Gain/Internal Parameters'
//  '<S49>'  : 'controlModel/Discrete PID Controller/P Copy/Disabled'
//  '<S50>'  : 'controlModel/Discrete PID Controller/Parallel P Gain/Internal Parameters'
//  '<S51>'  : 'controlModel/Discrete PID Controller/Reset Signal/Disabled'
//  '<S52>'  : 'controlModel/Discrete PID Controller/Saturation/Enabled'
//  '<S53>'  : 'controlModel/Discrete PID Controller/Saturation Fdbk/Disabled'
//  '<S54>'  : 'controlModel/Discrete PID Controller/Sum/Sum_PID'
//  '<S55>'  : 'controlModel/Discrete PID Controller/Sum Fdbk/Disabled'
//  '<S56>'  : 'controlModel/Discrete PID Controller/Tracking Mode/Disabled'
//  '<S57>'  : 'controlModel/Discrete PID Controller/Tracking Mode Sum/Passthrough'
//  '<S58>'  : 'controlModel/Discrete PID Controller/Tsamp - Integral/Passthrough'
//  '<S59>'  : 'controlModel/Discrete PID Controller/Tsamp - Ngain/Passthrough'
//  '<S60>'  : 'controlModel/Discrete PID Controller/postSat Signal/Forward_Path'
//  '<S61>'  : 'controlModel/Discrete PID Controller/preSat Signal/Forward_Path'
//  '<S62>'  : 'controlModel/Roll kalman/CalculatePL'
//  '<S63>'  : 'controlModel/Roll kalman/CalculateYhat'
//  '<S64>'  : 'controlModel/Roll kalman/CovarianceOutputConfigurator'
//  '<S65>'  : 'controlModel/Roll kalman/DataTypeConversionA'
//  '<S66>'  : 'controlModel/Roll kalman/DataTypeConversionB'
//  '<S67>'  : 'controlModel/Roll kalman/DataTypeConversionC'
//  '<S68>'  : 'controlModel/Roll kalman/DataTypeConversionD'
//  '<S69>'  : 'controlModel/Roll kalman/DataTypeConversionEnable'
//  '<S70>'  : 'controlModel/Roll kalman/DataTypeConversionG'
//  '<S71>'  : 'controlModel/Roll kalman/DataTypeConversionH'
//  '<S72>'  : 'controlModel/Roll kalman/DataTypeConversionN'
//  '<S73>'  : 'controlModel/Roll kalman/DataTypeConversionP'
//  '<S74>'  : 'controlModel/Roll kalman/DataTypeConversionP0'
//  '<S75>'  : 'controlModel/Roll kalman/DataTypeConversionQ'
//  '<S76>'  : 'controlModel/Roll kalman/DataTypeConversionR'
//  '<S77>'  : 'controlModel/Roll kalman/DataTypeConversionReset'
//  '<S78>'  : 'controlModel/Roll kalman/DataTypeConversionX'
//  '<S79>'  : 'controlModel/Roll kalman/DataTypeConversionX0'
//  '<S80>'  : 'controlModel/Roll kalman/DataTypeConversionu'
//  '<S81>'  : 'controlModel/Roll kalman/MemoryP'
//  '<S82>'  : 'controlModel/Roll kalman/Observer'
//  '<S83>'  : 'controlModel/Roll kalman/ReducedQRN'
//  '<S84>'  : 'controlModel/Roll kalman/Reset'
//  '<S85>'  : 'controlModel/Roll kalman/ScalarExpansionP0'
//  '<S86>'  : 'controlModel/Roll kalman/ScalarExpansionQ'
//  '<S87>'  : 'controlModel/Roll kalman/ScalarExpansionR'
//  '<S88>'  : 'controlModel/Roll kalman/UseCurrentEstimator'
//  '<S89>'  : 'controlModel/Roll kalman/checkA'
//  '<S90>'  : 'controlModel/Roll kalman/checkB'
//  '<S91>'  : 'controlModel/Roll kalman/checkC'
//  '<S92>'  : 'controlModel/Roll kalman/checkD'
//  '<S93>'  : 'controlModel/Roll kalman/checkEnable'
//  '<S94>'  : 'controlModel/Roll kalman/checkG'
//  '<S95>'  : 'controlModel/Roll kalman/checkH'
//  '<S96>'  : 'controlModel/Roll kalman/checkN'
//  '<S97>'  : 'controlModel/Roll kalman/checkP0'
//  '<S98>'  : 'controlModel/Roll kalman/checkQ'
//  '<S99>'  : 'controlModel/Roll kalman/checkR'
//  '<S100>' : 'controlModel/Roll kalman/checkReset'
//  '<S101>' : 'controlModel/Roll kalman/checkX0'
//  '<S102>' : 'controlModel/Roll kalman/checku'
//  '<S103>' : 'controlModel/Roll kalman/checky'
//  '<S104>' : 'controlModel/Roll kalman/CalculatePL/DataTypeConversionL'
//  '<S105>' : 'controlModel/Roll kalman/CalculatePL/DataTypeConversionM'
//  '<S106>' : 'controlModel/Roll kalman/CalculatePL/DataTypeConversionP'
//  '<S107>' : 'controlModel/Roll kalman/CalculatePL/DataTypeConversionZ'
//  '<S108>' : 'controlModel/Roll kalman/CalculatePL/Ground'
//  '<S109>' : 'controlModel/Roll kalman/CovarianceOutputConfigurator/decideOutput'
//  '<S110>' : 'controlModel/Roll kalman/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S111>' : 'controlModel/Roll kalman/Observer/MeasurementUpdate'
//  '<S112>' : 'controlModel/Roll kalman/ReducedQRN/Ground'
//  '<S113>' : 'controlModel/Roll kalman/UseCurrentEstimator/Enabled Subsystem'
//  '<S114>' : 'controlModel/Speed estimator/CalculatePL'
//  '<S115>' : 'controlModel/Speed estimator/CalculateYhat'
//  '<S116>' : 'controlModel/Speed estimator/CovarianceOutputConfigurator'
//  '<S117>' : 'controlModel/Speed estimator/DataTypeConversionA'
//  '<S118>' : 'controlModel/Speed estimator/DataTypeConversionB'
//  '<S119>' : 'controlModel/Speed estimator/DataTypeConversionC'
//  '<S120>' : 'controlModel/Speed estimator/DataTypeConversionD'
//  '<S121>' : 'controlModel/Speed estimator/DataTypeConversionEnable'
//  '<S122>' : 'controlModel/Speed estimator/DataTypeConversionG'
//  '<S123>' : 'controlModel/Speed estimator/DataTypeConversionH'
//  '<S124>' : 'controlModel/Speed estimator/DataTypeConversionN'
//  '<S125>' : 'controlModel/Speed estimator/DataTypeConversionP'
//  '<S126>' : 'controlModel/Speed estimator/DataTypeConversionP0'
//  '<S127>' : 'controlModel/Speed estimator/DataTypeConversionQ'
//  '<S128>' : 'controlModel/Speed estimator/DataTypeConversionR'
//  '<S129>' : 'controlModel/Speed estimator/DataTypeConversionReset'
//  '<S130>' : 'controlModel/Speed estimator/DataTypeConversionX'
//  '<S131>' : 'controlModel/Speed estimator/DataTypeConversionX0'
//  '<S132>' : 'controlModel/Speed estimator/DataTypeConversionu'
//  '<S133>' : 'controlModel/Speed estimator/MemoryP'
//  '<S134>' : 'controlModel/Speed estimator/Observer'
//  '<S135>' : 'controlModel/Speed estimator/ReducedQRN'
//  '<S136>' : 'controlModel/Speed estimator/Reset'
//  '<S137>' : 'controlModel/Speed estimator/ScalarExpansionP0'
//  '<S138>' : 'controlModel/Speed estimator/ScalarExpansionQ'
//  '<S139>' : 'controlModel/Speed estimator/ScalarExpansionR'
//  '<S140>' : 'controlModel/Speed estimator/UseCurrentEstimator'
//  '<S141>' : 'controlModel/Speed estimator/checkA'
//  '<S142>' : 'controlModel/Speed estimator/checkB'
//  '<S143>' : 'controlModel/Speed estimator/checkC'
//  '<S144>' : 'controlModel/Speed estimator/checkD'
//  '<S145>' : 'controlModel/Speed estimator/checkEnable'
//  '<S146>' : 'controlModel/Speed estimator/checkG'
//  '<S147>' : 'controlModel/Speed estimator/checkH'
//  '<S148>' : 'controlModel/Speed estimator/checkN'
//  '<S149>' : 'controlModel/Speed estimator/checkP0'
//  '<S150>' : 'controlModel/Speed estimator/checkQ'
//  '<S151>' : 'controlModel/Speed estimator/checkR'
//  '<S152>' : 'controlModel/Speed estimator/checkReset'
//  '<S153>' : 'controlModel/Speed estimator/checkX0'
//  '<S154>' : 'controlModel/Speed estimator/checku'
//  '<S155>' : 'controlModel/Speed estimator/checky'
//  '<S156>' : 'controlModel/Speed estimator/CalculatePL/DataTypeConversionL'
//  '<S157>' : 'controlModel/Speed estimator/CalculatePL/DataTypeConversionM'
//  '<S158>' : 'controlModel/Speed estimator/CalculatePL/DataTypeConversionP'
//  '<S159>' : 'controlModel/Speed estimator/CalculatePL/DataTypeConversionZ'
//  '<S160>' : 'controlModel/Speed estimator/CalculatePL/Ground'
//  '<S161>' : 'controlModel/Speed estimator/CovarianceOutputConfigurator/decideOutput'
//  '<S162>' : 'controlModel/Speed estimator/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S163>' : 'controlModel/Speed estimator/Observer/MeasurementUpdate'
//  '<S164>' : 'controlModel/Speed estimator/ReducedQRN/Ground'
//  '<S165>' : 'controlModel/Speed estimator/UseCurrentEstimator/Enabled Subsystem'
//  '<S166>' : 'controlModel/Steer estimator/CalculatePL'
//  '<S167>' : 'controlModel/Steer estimator/CalculateYhat'
//  '<S168>' : 'controlModel/Steer estimator/CovarianceOutputConfigurator'
//  '<S169>' : 'controlModel/Steer estimator/DataTypeConversionA'
//  '<S170>' : 'controlModel/Steer estimator/DataTypeConversionB'
//  '<S171>' : 'controlModel/Steer estimator/DataTypeConversionC'
//  '<S172>' : 'controlModel/Steer estimator/DataTypeConversionD'
//  '<S173>' : 'controlModel/Steer estimator/DataTypeConversionEnable'
//  '<S174>' : 'controlModel/Steer estimator/DataTypeConversionG'
//  '<S175>' : 'controlModel/Steer estimator/DataTypeConversionH'
//  '<S176>' : 'controlModel/Steer estimator/DataTypeConversionN'
//  '<S177>' : 'controlModel/Steer estimator/DataTypeConversionP'
//  '<S178>' : 'controlModel/Steer estimator/DataTypeConversionP0'
//  '<S179>' : 'controlModel/Steer estimator/DataTypeConversionQ'
//  '<S180>' : 'controlModel/Steer estimator/DataTypeConversionR'
//  '<S181>' : 'controlModel/Steer estimator/DataTypeConversionReset'
//  '<S182>' : 'controlModel/Steer estimator/DataTypeConversionX'
//  '<S183>' : 'controlModel/Steer estimator/DataTypeConversionX0'
//  '<S184>' : 'controlModel/Steer estimator/DataTypeConversionu'
//  '<S185>' : 'controlModel/Steer estimator/MemoryP'
//  '<S186>' : 'controlModel/Steer estimator/Observer'
//  '<S187>' : 'controlModel/Steer estimator/ReducedQRN'
//  '<S188>' : 'controlModel/Steer estimator/Reset'
//  '<S189>' : 'controlModel/Steer estimator/ScalarExpansionP0'
//  '<S190>' : 'controlModel/Steer estimator/ScalarExpansionQ'
//  '<S191>' : 'controlModel/Steer estimator/ScalarExpansionR'
//  '<S192>' : 'controlModel/Steer estimator/UseCurrentEstimator'
//  '<S193>' : 'controlModel/Steer estimator/checkA'
//  '<S194>' : 'controlModel/Steer estimator/checkB'
//  '<S195>' : 'controlModel/Steer estimator/checkC'
//  '<S196>' : 'controlModel/Steer estimator/checkD'
//  '<S197>' : 'controlModel/Steer estimator/checkEnable'
//  '<S198>' : 'controlModel/Steer estimator/checkG'
//  '<S199>' : 'controlModel/Steer estimator/checkH'
//  '<S200>' : 'controlModel/Steer estimator/checkN'
//  '<S201>' : 'controlModel/Steer estimator/checkP0'
//  '<S202>' : 'controlModel/Steer estimator/checkQ'
//  '<S203>' : 'controlModel/Steer estimator/checkR'
//  '<S204>' : 'controlModel/Steer estimator/checkReset'
//  '<S205>' : 'controlModel/Steer estimator/checkX0'
//  '<S206>' : 'controlModel/Steer estimator/checku'
//  '<S207>' : 'controlModel/Steer estimator/checky'
//  '<S208>' : 'controlModel/Steer estimator/CalculatePL/DataTypeConversionL'
//  '<S209>' : 'controlModel/Steer estimator/CalculatePL/DataTypeConversionM'
//  '<S210>' : 'controlModel/Steer estimator/CalculatePL/DataTypeConversionP'
//  '<S211>' : 'controlModel/Steer estimator/CalculatePL/DataTypeConversionZ'
//  '<S212>' : 'controlModel/Steer estimator/CalculatePL/Ground'
//  '<S213>' : 'controlModel/Steer estimator/CovarianceOutputConfigurator/decideOutput'
//  '<S214>' : 'controlModel/Steer estimator/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S215>' : 'controlModel/Steer estimator/Observer/MeasurementUpdate'
//  '<S216>' : 'controlModel/Steer estimator/ReducedQRN/Ground'
//  '<S217>' : 'controlModel/Steer estimator/UseCurrentEstimator/Enabled Subsystem'
//  '<S218>' : 'controlModel/Yaw kalman/CalculatePL'
//  '<S219>' : 'controlModel/Yaw kalman/CalculateYhat'
//  '<S220>' : 'controlModel/Yaw kalman/CovarianceOutputConfigurator'
//  '<S221>' : 'controlModel/Yaw kalman/DataTypeConversionA'
//  '<S222>' : 'controlModel/Yaw kalman/DataTypeConversionB'
//  '<S223>' : 'controlModel/Yaw kalman/DataTypeConversionC'
//  '<S224>' : 'controlModel/Yaw kalman/DataTypeConversionD'
//  '<S225>' : 'controlModel/Yaw kalman/DataTypeConversionEnable'
//  '<S226>' : 'controlModel/Yaw kalman/DataTypeConversionG'
//  '<S227>' : 'controlModel/Yaw kalman/DataTypeConversionH'
//  '<S228>' : 'controlModel/Yaw kalman/DataTypeConversionN'
//  '<S229>' : 'controlModel/Yaw kalman/DataTypeConversionP'
//  '<S230>' : 'controlModel/Yaw kalman/DataTypeConversionP0'
//  '<S231>' : 'controlModel/Yaw kalman/DataTypeConversionQ'
//  '<S232>' : 'controlModel/Yaw kalman/DataTypeConversionR'
//  '<S233>' : 'controlModel/Yaw kalman/DataTypeConversionReset'
//  '<S234>' : 'controlModel/Yaw kalman/DataTypeConversionX'
//  '<S235>' : 'controlModel/Yaw kalman/DataTypeConversionX0'
//  '<S236>' : 'controlModel/Yaw kalman/DataTypeConversionu'
//  '<S237>' : 'controlModel/Yaw kalman/MemoryP'
//  '<S238>' : 'controlModel/Yaw kalman/Observer'
//  '<S239>' : 'controlModel/Yaw kalman/ReducedQRN'
//  '<S240>' : 'controlModel/Yaw kalman/Reset'
//  '<S241>' : 'controlModel/Yaw kalman/ScalarExpansionP0'
//  '<S242>' : 'controlModel/Yaw kalman/ScalarExpansionQ'
//  '<S243>' : 'controlModel/Yaw kalman/ScalarExpansionR'
//  '<S244>' : 'controlModel/Yaw kalman/UseCurrentEstimator'
//  '<S245>' : 'controlModel/Yaw kalman/checkA'
//  '<S246>' : 'controlModel/Yaw kalman/checkB'
//  '<S247>' : 'controlModel/Yaw kalman/checkC'
//  '<S248>' : 'controlModel/Yaw kalman/checkD'
//  '<S249>' : 'controlModel/Yaw kalman/checkEnable'
//  '<S250>' : 'controlModel/Yaw kalman/checkG'
//  '<S251>' : 'controlModel/Yaw kalman/checkH'
//  '<S252>' : 'controlModel/Yaw kalman/checkN'
//  '<S253>' : 'controlModel/Yaw kalman/checkP0'
//  '<S254>' : 'controlModel/Yaw kalman/checkQ'
//  '<S255>' : 'controlModel/Yaw kalman/checkR'
//  '<S256>' : 'controlModel/Yaw kalman/checkReset'
//  '<S257>' : 'controlModel/Yaw kalman/checkX0'
//  '<S258>' : 'controlModel/Yaw kalman/checku'
//  '<S259>' : 'controlModel/Yaw kalman/checky'
//  '<S260>' : 'controlModel/Yaw kalman/CalculatePL/DataTypeConversionL'
//  '<S261>' : 'controlModel/Yaw kalman/CalculatePL/DataTypeConversionM'
//  '<S262>' : 'controlModel/Yaw kalman/CalculatePL/DataTypeConversionP'
//  '<S263>' : 'controlModel/Yaw kalman/CalculatePL/DataTypeConversionZ'
//  '<S264>' : 'controlModel/Yaw kalman/CalculatePL/Ground'
//  '<S265>' : 'controlModel/Yaw kalman/CovarianceOutputConfigurator/decideOutput'
//  '<S266>' : 'controlModel/Yaw kalman/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S267>' : 'controlModel/Yaw kalman/Observer/MeasurementUpdate'
//  '<S268>' : 'controlModel/Yaw kalman/ReducedQRN/Ground'
//  '<S269>' : 'controlModel/Yaw kalman/UseCurrentEstimator/Enabled Subsystem'
//  '<S270>' : 'controlModel/x pos kalman/CalculatePL'
//  '<S271>' : 'controlModel/x pos kalman/CalculateYhat'
//  '<S272>' : 'controlModel/x pos kalman/CovarianceOutputConfigurator'
//  '<S273>' : 'controlModel/x pos kalman/DataTypeConversionA'
//  '<S274>' : 'controlModel/x pos kalman/DataTypeConversionB'
//  '<S275>' : 'controlModel/x pos kalman/DataTypeConversionC'
//  '<S276>' : 'controlModel/x pos kalman/DataTypeConversionD'
//  '<S277>' : 'controlModel/x pos kalman/DataTypeConversionEnable'
//  '<S278>' : 'controlModel/x pos kalman/DataTypeConversionG'
//  '<S279>' : 'controlModel/x pos kalman/DataTypeConversionH'
//  '<S280>' : 'controlModel/x pos kalman/DataTypeConversionN'
//  '<S281>' : 'controlModel/x pos kalman/DataTypeConversionP'
//  '<S282>' : 'controlModel/x pos kalman/DataTypeConversionP0'
//  '<S283>' : 'controlModel/x pos kalman/DataTypeConversionQ'
//  '<S284>' : 'controlModel/x pos kalman/DataTypeConversionR'
//  '<S285>' : 'controlModel/x pos kalman/DataTypeConversionReset'
//  '<S286>' : 'controlModel/x pos kalman/DataTypeConversionX'
//  '<S287>' : 'controlModel/x pos kalman/DataTypeConversionX0'
//  '<S288>' : 'controlModel/x pos kalman/DataTypeConversionu'
//  '<S289>' : 'controlModel/x pos kalman/MemoryP'
//  '<S290>' : 'controlModel/x pos kalman/Observer'
//  '<S291>' : 'controlModel/x pos kalman/ReducedQRN'
//  '<S292>' : 'controlModel/x pos kalman/Reset'
//  '<S293>' : 'controlModel/x pos kalman/ScalarExpansionP0'
//  '<S294>' : 'controlModel/x pos kalman/ScalarExpansionQ'
//  '<S295>' : 'controlModel/x pos kalman/ScalarExpansionR'
//  '<S296>' : 'controlModel/x pos kalman/UseCurrentEstimator'
//  '<S297>' : 'controlModel/x pos kalman/checkA'
//  '<S298>' : 'controlModel/x pos kalman/checkB'
//  '<S299>' : 'controlModel/x pos kalman/checkC'
//  '<S300>' : 'controlModel/x pos kalman/checkD'
//  '<S301>' : 'controlModel/x pos kalman/checkEnable'
//  '<S302>' : 'controlModel/x pos kalman/checkG'
//  '<S303>' : 'controlModel/x pos kalman/checkH'
//  '<S304>' : 'controlModel/x pos kalman/checkN'
//  '<S305>' : 'controlModel/x pos kalman/checkP0'
//  '<S306>' : 'controlModel/x pos kalman/checkQ'
//  '<S307>' : 'controlModel/x pos kalman/checkR'
//  '<S308>' : 'controlModel/x pos kalman/checkReset'
//  '<S309>' : 'controlModel/x pos kalman/checkX0'
//  '<S310>' : 'controlModel/x pos kalman/checku'
//  '<S311>' : 'controlModel/x pos kalman/checky'
//  '<S312>' : 'controlModel/x pos kalman/CalculatePL/DataTypeConversionL'
//  '<S313>' : 'controlModel/x pos kalman/CalculatePL/DataTypeConversionM'
//  '<S314>' : 'controlModel/x pos kalman/CalculatePL/DataTypeConversionP'
//  '<S315>' : 'controlModel/x pos kalman/CalculatePL/DataTypeConversionZ'
//  '<S316>' : 'controlModel/x pos kalman/CalculatePL/Ground'
//  '<S317>' : 'controlModel/x pos kalman/CovarianceOutputConfigurator/decideOutput'
//  '<S318>' : 'controlModel/x pos kalman/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S319>' : 'controlModel/x pos kalman/Observer/MeasurementUpdate'
//  '<S320>' : 'controlModel/x pos kalman/ReducedQRN/Ground'
//  '<S321>' : 'controlModel/x pos kalman/UseCurrentEstimator/Enabled Subsystem'
//  '<S322>' : 'controlModel/y pos kalman/CalculatePL'
//  '<S323>' : 'controlModel/y pos kalman/CalculateYhat'
//  '<S324>' : 'controlModel/y pos kalman/CovarianceOutputConfigurator'
//  '<S325>' : 'controlModel/y pos kalman/DataTypeConversionA'
//  '<S326>' : 'controlModel/y pos kalman/DataTypeConversionB'
//  '<S327>' : 'controlModel/y pos kalman/DataTypeConversionC'
//  '<S328>' : 'controlModel/y pos kalman/DataTypeConversionD'
//  '<S329>' : 'controlModel/y pos kalman/DataTypeConversionEnable'
//  '<S330>' : 'controlModel/y pos kalman/DataTypeConversionG'
//  '<S331>' : 'controlModel/y pos kalman/DataTypeConversionH'
//  '<S332>' : 'controlModel/y pos kalman/DataTypeConversionN'
//  '<S333>' : 'controlModel/y pos kalman/DataTypeConversionP'
//  '<S334>' : 'controlModel/y pos kalman/DataTypeConversionP0'
//  '<S335>' : 'controlModel/y pos kalman/DataTypeConversionQ'
//  '<S336>' : 'controlModel/y pos kalman/DataTypeConversionR'
//  '<S337>' : 'controlModel/y pos kalman/DataTypeConversionReset'
//  '<S338>' : 'controlModel/y pos kalman/DataTypeConversionX'
//  '<S339>' : 'controlModel/y pos kalman/DataTypeConversionX0'
//  '<S340>' : 'controlModel/y pos kalman/DataTypeConversionu'
//  '<S341>' : 'controlModel/y pos kalman/MemoryP'
//  '<S342>' : 'controlModel/y pos kalman/Observer'
//  '<S343>' : 'controlModel/y pos kalman/ReducedQRN'
//  '<S344>' : 'controlModel/y pos kalman/Reset'
//  '<S345>' : 'controlModel/y pos kalman/ScalarExpansionP0'
//  '<S346>' : 'controlModel/y pos kalman/ScalarExpansionQ'
//  '<S347>' : 'controlModel/y pos kalman/ScalarExpansionR'
//  '<S348>' : 'controlModel/y pos kalman/UseCurrentEstimator'
//  '<S349>' : 'controlModel/y pos kalman/checkA'
//  '<S350>' : 'controlModel/y pos kalman/checkB'
//  '<S351>' : 'controlModel/y pos kalman/checkC'
//  '<S352>' : 'controlModel/y pos kalman/checkD'
//  '<S353>' : 'controlModel/y pos kalman/checkEnable'
//  '<S354>' : 'controlModel/y pos kalman/checkG'
//  '<S355>' : 'controlModel/y pos kalman/checkH'
//  '<S356>' : 'controlModel/y pos kalman/checkN'
//  '<S357>' : 'controlModel/y pos kalman/checkP0'
//  '<S358>' : 'controlModel/y pos kalman/checkQ'
//  '<S359>' : 'controlModel/y pos kalman/checkR'
//  '<S360>' : 'controlModel/y pos kalman/checkReset'
//  '<S361>' : 'controlModel/y pos kalman/checkX0'
//  '<S362>' : 'controlModel/y pos kalman/checku'
//  '<S363>' : 'controlModel/y pos kalman/checky'
//  '<S364>' : 'controlModel/y pos kalman/CalculatePL/DataTypeConversionL'
//  '<S365>' : 'controlModel/y pos kalman/CalculatePL/DataTypeConversionM'
//  '<S366>' : 'controlModel/y pos kalman/CalculatePL/DataTypeConversionP'
//  '<S367>' : 'controlModel/y pos kalman/CalculatePL/DataTypeConversionZ'
//  '<S368>' : 'controlModel/y pos kalman/CalculatePL/Ground'
//  '<S369>' : 'controlModel/y pos kalman/CovarianceOutputConfigurator/decideOutput'
//  '<S370>' : 'controlModel/y pos kalman/CovarianceOutputConfigurator/decideOutput/SqrtUsedFcn'
//  '<S371>' : 'controlModel/y pos kalman/Observer/MeasurementUpdate'
//  '<S372>' : 'controlModel/y pos kalman/ReducedQRN/Ground'
//  '<S373>' : 'controlModel/y pos kalman/UseCurrentEstimator/Enabled Subsystem'

#endif                                 // RTW_HEADER_controlModel_h_

//
// File trailer for generated code.
//
// [EOF]
//
