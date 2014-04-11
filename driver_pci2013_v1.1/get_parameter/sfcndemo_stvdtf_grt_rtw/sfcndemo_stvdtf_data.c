/*
 * sfcndemo_stvdtf_data.c
 *
 * Code generation for model "sfcndemo_stvdtf".
 *
 * Model version              : 1.17
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Tue Apr 01 10:33:27 2014
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "sfcndemo_stvdtf.h"
#include "sfcndemo_stvdtf_private.h"

/* Block parameters (auto storage) */
P_sfcndemo_stvdtf_T sfcndemo_stvdtf_P = {
  /*  Expression: [1 2 3 4 5 4 3 2 1]
   * Referenced by: '<Root>/Sine Wave'
   */
  { 1.0, 2.0, 3.0, 4.0, 5.0, 4.0, 3.0, 2.0, 1.0 },
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  1.0,                                 /* Expression: 1
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  0.0,                                 /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */

  /*  Computed Parameter: TimeVaryingDiscreteTransferFunc
   * Referenced by: '<Root>/Time Varying Discrete Transfer Function S-Function'
   */
  { 1.0, 4.0 },

  /*  Expression: num
   * Referenced by: '<Root>/Time Varying Discrete Transfer Function S-Function'
   */
  { 0.0, 0.0, 0.0, 1.1909 },

  /*  Computed Parameter: TimeVaryingDiscreteTransferFu_d
   * Referenced by: '<Root>/Time Varying Discrete Transfer Function S-Function'
   */
  { 1.0, 4.0 },

  /*  Expression: den
   * Referenced by: '<Root>/Time Varying Discrete Transfer Function S-Function'
   */
  { 1.0, 1.6154, 1.1551, 0.236 },

  /*  Computed Parameter: TimeVaryingDiscreteTransferF_ce
   * Referenced by: '<Root>/Time Varying Discrete Transfer Function S-Function'
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: param_ts
                                        * Referenced by: '<Root>/Time Varying Discrete Transfer Function S-Function'
                                        */

  /*  Computed Parameter: TimeVaryingDiscreteTransferF_oz
   * Referenced by: '<Root>/Time Varying Discrete Transfer Function S-Function'
   */
  { 1.0, 1.0 },
  0.2                                  /* Expression: ts
                                        * Referenced by: '<Root>/Time Varying Discrete Transfer Function S-Function'
                                        */
};
