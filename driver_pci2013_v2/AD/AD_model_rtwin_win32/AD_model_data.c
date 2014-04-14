/*
 * AD_model_data.c
 *
 * Code generation for model "AD_model".
 *
 * Model version              : 1.33
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Fri Apr 11 17:00:00 2014
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "AD_model.h"
#include "AD_model_private.h"

/* Block parameters (auto storage) */
P_AD_model_T AD_model_P = {
  /*  Computed Parameter: Get_Parameter_P1_Size
   * Referenced by: '<Root>/Get_Parameter '
   */
  { 1.0, 3.0 },

  /*  Expression: channel
   * Referenced by: '<Root>/Get_Parameter '
   */
  { 5.0, 2.0, 1.0 },

  /*  Computed Parameter: Get_Parameter_P2_Size
   * Referenced by: '<Root>/Get_Parameter '
   */
  { 1.0, 1.0 },
  2.0,                                 /* Expression: range
                                        * Referenced by: '<Root>/Get_Parameter '
                                        */

  /*  Computed Parameter: Get_Parameter_P3_Size
   * Referenced by: '<Root>/Get_Parameter '
   */
  { 1.0, 1.0 },
  0.02                                 /* Expression: Ts
                                        * Referenced by: '<Root>/Get_Parameter '
                                        */
};
