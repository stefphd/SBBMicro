//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controlModel_types.h
//
// Code generated for Simulink model 'controlModel'.
//
// Model version                  : 1.140
// Simulink Coder version         : 9.5 (R2021a) 14-Nov-2020
// C/C++ source code generated on : Wed Feb 23 12:14:32 2022
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
#ifndef RTW_HEADER_controlModel_types_h_
#define RTW_HEADER_controlModel_types_h_
#include "rtwtypes.h"

// Model Code Variants
#ifndef struct_b_dsp_FIRFilter_0_controlMode_T
#define struct_b_dsp_FIRFilter_0_controlMode_T

struct b_dsp_FIRFilter_0_controlMode_T
{
  int32_T S0_isInitialized;
  real32_T W0_states[20];
  real32_T P0_InitialStates;
  real32_T P1_Coefficients[21];
};

#endif                                // struct_b_dsp_FIRFilter_0_controlMode_T

#ifndef struct_b_dspcodegen_FIRFilter_contro_T
#define struct_b_dspcodegen_FIRFilter_contro_T

struct b_dspcodegen_FIRFilter_contro_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  b_dsp_FIRFilter_0_controlMode_T cSFunObject;
};

#endif                                // struct_b_dspcodegen_FIRFilter_contro_T

#ifndef struct_cell_wrap_controlModel_T
#define struct_cell_wrap_controlModel_T

struct cell_wrap_controlModel_T
{
  uint32_T f1[8];
};

#endif                                 // struct_cell_wrap_controlModel_T

#ifndef struct_dsp_LowpassFilter_controlMode_T
#define struct_dsp_LowpassFilter_controlMode_T

struct dsp_LowpassFilter_controlMode_T
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  cell_wrap_controlModel_T inputVarSize;
  int32_T NumChannels;
  b_dspcodegen_FIRFilter_contro_T *FilterObj;
  b_dspcodegen_FIRFilter_contro_T _pobj0;
};

#endif                                // struct_dsp_LowpassFilter_controlMode_T
#endif                                 // RTW_HEADER_controlModel_types_h_

//
// File trailer for generated code.
//
// [EOF]
//
