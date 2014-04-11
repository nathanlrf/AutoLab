/*
 * para_model_data.c
 *
 * Code generation for model "para_model".
 *
 * Model version              : 1.20
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Wed Apr 02 14:53:21 2014
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "para_model.h"
#include "para_model_private.h"

/* Block parameters (auto storage) */
P_para_model_T para_model_P = {
  /*  Computed Parameter: Get_Parameter_P1_Size
   * Referenced by: '<Root>/Get_Parameter '
   */
  { 1.0, 1.0 },
  1.0,                                 /* Expression: channel
                                        * Referenced by: '<Root>/Get_Parameter '
                                        */

  /*  Computed Parameter: Get_Parameter_P2_Size
   * Referenced by: '<Root>/Get_Parameter '
   */
  { 1.0, 1.0 },
  3.0,                                 /* Expression: range
                                        * Referenced by: '<Root>/Get_Parameter '
                                        */

  /*  Computed Parameter: Get_Parameter_P3_Size
   * Referenced by: '<Root>/Get_Parameter '
   */
  { 1.0, 1.0 },
  0.1                                  /* Expression: Ts
                                        * Referenced by: '<Root>/Get_Parameter '
                                        */
};
