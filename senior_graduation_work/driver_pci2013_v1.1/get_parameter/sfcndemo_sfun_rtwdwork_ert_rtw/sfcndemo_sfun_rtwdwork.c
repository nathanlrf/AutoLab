/*
 * File: sfcndemo_sfun_rtwdwork.c
 *
 * Code generated for Simulink model 'sfcndemo_sfun_rtwdwork'.
 *
 * Model version                  : 1.46
 * Simulink Coder version         : 8.5 (R2013b) 08-Aug-2013
 * C/C++ source code generated on : Tue Apr 01 15:51:26 2014
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "sfcndemo_sfun_rtwdwork.h"
#include "sfcndemo_sfun_rtwdwork_private.h"

/* Exported block signals */
real_T A;                              /* '<Root>/S-Function' */
real_T B;                              /* '<Root>/S-Function1' */

/* Exported block states */
real_T X;                              /* '<Root>/S-Function' */
volatile real_T Y;                     /* '<Root>/S-Function1' */

/* Real-time model */
RT_MODEL_sfcndemo_sfun_rtwdwork sfcndemo_sfun_rtwdwork_M_;
RT_MODEL_sfcndemo_sfun_rtwdwork *const sfcndemo_sfun_rtwdwork_M =
  &sfcndemo_sfun_rtwdwork_M_;

/* Model step function */
void sfcndemo_sfun_rtwdwork_step(void)
{
  /* rtwdwork Block: <Root>/S-Function */
  A = X;

  /* rtwdwork Block: <Root>/S-Function1 */
  B = Y;

  /* rtwdwork Block: <Root>/S-Function */
  X = X + 1.0;

  /* rtwdwork Block: <Root>/S-Function1 */
  Y = Y + sfcndemo_sfun_rtwdwork_ConstB.Gain;
}

/* Model initialize function */
void sfcndemo_sfun_rtwdwork_initialize(void)
{
  /* (no initialization code required) */
}

/* Model terminate function */
void sfcndemo_sfun_rtwdwork_terminate(void)
{
  /* (no terminate code required) */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
