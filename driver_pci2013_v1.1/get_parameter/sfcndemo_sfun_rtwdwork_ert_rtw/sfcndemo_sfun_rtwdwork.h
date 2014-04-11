/*
 * File: sfcndemo_sfun_rtwdwork.h
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

#ifndef RTW_HEADER_sfcndemo_sfun_rtwdwork_h_
#define RTW_HEADER_sfcndemo_sfun_rtwdwork_h_
#ifndef sfcndemo_sfun_rtwdwork_COMMON_INCLUDES_
# define sfcndemo_sfun_rtwdwork_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* sfcndemo_sfun_rtwdwork_COMMON_INCLUDES_ */

#include "sfcndemo_sfun_rtwdwork_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

/* Invariant block signals (auto storage) */
typedef struct {
  const real_T Gain;                   /* '<Root>/Gain' */
} ConstBlockIO_sfcndemo_sfun_rtwd;

/* Real-time Model Data Structure */
struct tag_RTM_sfcndemo_sfun_rtwdwork {
  const char_T * volatile errorStatus;
};

extern const ConstBlockIO_sfcndemo_sfun_rtwd sfcndemo_sfun_rtwdwork_ConstB;/* constant block i/o */

/*
 * Exported Global Signals
 *
 * Note: Exported global signals are block signals with an exported global
 * storage class designation.  Code generation will declare the memory for
 * these signals and export their symbols.
 *
 */
extern real_T A;                       /* '<Root>/S-Function' */
extern real_T B;                       /* '<Root>/S-Function1' */

/*
 * Exported States
 *
 * Note: Exported states are block states with an exported global
 * storage class designation.  Code generation will declare the memory for these
 * states and exports their symbols.
 *
 */
extern real_T X;                       /* '<Root>/S-Function' */
extern volatile real_T Y;              /* '<Root>/S-Function1' */

/* Model entry point functions */
extern void sfcndemo_sfun_rtwdwork_initialize(void);
extern void sfcndemo_sfun_rtwdwork_step(void);
extern void sfcndemo_sfun_rtwdwork_terminate(void);

/* Real-time Model object */
extern RT_MODEL_sfcndemo_sfun_rtwdwork *const sfcndemo_sfun_rtwdwork_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'sfcndemo_sfun_rtwdwork'
 */
#endif                                 /* RTW_HEADER_sfcndemo_sfun_rtwdwork_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
