/*
 * auto4exp.c
 *
 * Code generation for model "auto4exp".
 *
 * Model version              : 1.5
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Mon Mar 17 16:16:30 2014
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "auto4exp.h"
#include "auto4exp_private.h"

/* Block signals (auto storage) */
B_auto4exp_T auto4exp_B;

/* Continuous states */
X_auto4exp_T auto4exp_X;

/* Block states (auto storage) */
DW_auto4exp_T auto4exp_DW;

/* Real-time model */
RT_MODEL_auto4exp_T auto4exp_M_;
RT_MODEL_auto4exp_T *const auto4exp_M = &auto4exp_M_;

/*
 * This function updates continuous states using the ODE4 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T t = rtsiGetT(si);
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE4_IntgData *id = (ODE4_IntgData *)rtsiGetSolverData(si);
  real_T *y = id->y;
  real_T *f0 = id->f[0];
  real_T *f1 = id->f[1];
  real_T *f2 = id->f[2];
  real_T *f3 = id->f[3];
  real_T temp;
  int_T i;
  int_T nXc = 2;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);

  /* Save the state values at time t in y, we'll use x as ynew. */
  (void) memcpy(y, x,
                (uint_T)nXc*sizeof(real_T));

  /* Assumes that rtsiSetT and ModelOutputs are up-to-date */
  /* f0 = f(t,y) */
  rtsiSetdX(si, f0);
  auto4exp_derivatives();

  /* f1 = f(t + (h/2), y + (h/2)*f0) */
  temp = 0.5 * h;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f0[i]);
  }

  rtsiSetT(si, t + temp);
  rtsiSetdX(si, f1);
  auto4exp_step();
  auto4exp_derivatives();

  /* f2 = f(t + (h/2), y + (h/2)*f1) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (temp*f1[i]);
  }

  rtsiSetdX(si, f2);
  auto4exp_step();
  auto4exp_derivatives();

  /* f3 = f(t + h, y + h*f2) */
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + (h*f2[i]);
  }

  rtsiSetT(si, tnew);
  rtsiSetdX(si, f3);
  auto4exp_step();
  auto4exp_derivatives();

  /* tnew = t + h
     ynew = y + (h/6)*(f0 + 2*f1 + 2*f2 + 2*f3) */
  temp = h / 6.0;
  for (i = 0; i < nXc; i++) {
    x[i] = y[i] + temp*(f0[i] + 2.0*f1[i] + 2.0*f2[i] + f3[i]);
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model step function */
void auto4exp_step(void)
{
  real_T currentTime;
  if (rtmIsMajorTimeStep(auto4exp_M)) {
    /* set solver stop time */
    if (!(auto4exp_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&auto4exp_M->solverInfo,
                            ((auto4exp_M->Timing.clockTickH0 + 1) *
        auto4exp_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&auto4exp_M->solverInfo,
                            ((auto4exp_M->Timing.clockTick0 + 1) *
        auto4exp_M->Timing.stepSize0 + auto4exp_M->Timing.clockTickH0 *
        auto4exp_M->Timing.stepSize0 * 4294967296.0));
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(auto4exp_M)) {
    auto4exp_M->Timing.t[0] = rtsiGetT(&auto4exp_M->solverInfo);
  }

  /* Switch: '<S1>/Environment Switch' incorporates:
   *  Constant: '<S1>/Switch Control'
   *  Integrator: '<Root>/Integrator'
   */
  if (auto4exp_P.SwitchControl_Value) {
    auto4exp_B.EnvironmentSwitch = auto4exp_X.Integrator_CSTATE;
  } else {
    auto4exp_B.EnvironmentSwitch = 0.0;
  }

  /* End of Switch: '<S1>/Environment Switch' */
  if (rtmIsMajorTimeStep(auto4exp_M)) {
  }

  /* Step: '<Root>/Step' */
  currentTime = auto4exp_M->Timing.t[0];
  if (currentTime < auto4exp_P.Step_Time) {
    currentTime = auto4exp_P.Step_Y0;
  } else {
    currentTime = auto4exp_P.Step_YFinal;
  }

  /* End of Step: '<Root>/Step' */

  /* Sum: '<Root>/Sum' */
  currentTime += auto4exp_B.EnvironmentSwitch;

  /* Signum: '<S2>/Sign' */
  if (currentTime < 0.0) {
    auto4exp_B.Sign = -1.0;
  } else if (currentTime > 0.0) {
    auto4exp_B.Sign = 1.0;
  } else if (currentTime == 0.0) {
    auto4exp_B.Sign = 0.0;
  } else {
    auto4exp_B.Sign = currentTime;
  }

  /* End of Signum: '<S2>/Sign' */

  /* TransferFcn: '<Root>/Transfer Fcn' */
  auto4exp_B.TransferFcn = 0.0;
  auto4exp_B.TransferFcn += auto4exp_P.TransferFcn_C *
    auto4exp_X.TransferFcn_CSTATE;
  if (rtmIsMajorTimeStep(auto4exp_M)) {
    /* Matfile logging */
    rt_UpdateTXYLogVars(auto4exp_M->rtwLogInfo, (auto4exp_M->Timing.t));
  }                                    /* end MajorTimeStep */

  if (rtmIsMajorTimeStep(auto4exp_M)) {
    /* signal main to stop simulation */
    {                                  /* Sample time: [0.0s, 0.0s] */
      if ((rtmGetTFinal(auto4exp_M)!=-1) &&
          !((rtmGetTFinal(auto4exp_M)-(((auto4exp_M->Timing.clockTick1+
               auto4exp_M->Timing.clockTickH1* 4294967296.0)) * 0.2)) >
            (((auto4exp_M->Timing.clockTick1+auto4exp_M->Timing.clockTickH1*
               4294967296.0)) * 0.2) * (DBL_EPSILON))) {
        rtmSetErrorStatus(auto4exp_M, "Simulation finished");
      }
    }

    rt_ertODEUpdateContinuousStates(&auto4exp_M->solverInfo);

    /* Update absolute time for base rate */
    /* The "clockTick0" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick0"
     * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick0 and the high bits
     * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++auto4exp_M->Timing.clockTick0)) {
      ++auto4exp_M->Timing.clockTickH0;
    }

    auto4exp_M->Timing.t[0] = rtsiGetSolverStopTime(&auto4exp_M->solverInfo);

    {
      /* Update absolute timer for sample time: [0.2s, 0.0s] */
      /* The "clockTick1" counts the number of times the code of this task has
       * been executed. The resolution of this integer timer is 0.2, which is the step size
       * of the task. Size of "clockTick1" ensures timer will not overflow during the
       * application lifespan selected.
       * Timer of this task consists of two 32 bit unsigned integers.
       * The two integers represent the low bits Timing.clockTick1 and the high bits
       * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
       */
      auto4exp_M->Timing.clockTick1++;
      if (!auto4exp_M->Timing.clockTick1) {
        auto4exp_M->Timing.clockTickH1++;
      }
    }
  }                                    /* end MajorTimeStep */
}

/* Derivatives for root system: '<Root>' */
void auto4exp_derivatives(void)
{
  XDot_auto4exp_T *_rtXdot;
  _rtXdot = ((XDot_auto4exp_T *) auto4exp_M->ModelData.derivs);

  /* Derivatives for Integrator: '<Root>/Integrator' */
  _rtXdot->Integrator_CSTATE = auto4exp_B.TransferFcn;

  /* Derivatives for TransferFcn: '<Root>/Transfer Fcn' */
  _rtXdot->TransferFcn_CSTATE = 0.0;
  _rtXdot->TransferFcn_CSTATE += auto4exp_P.TransferFcn_A *
    auto4exp_X.TransferFcn_CSTATE;
  _rtXdot->TransferFcn_CSTATE += auto4exp_B.Sign;
}

/* Model initialize function */
void auto4exp_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)auto4exp_M, 0,
                sizeof(RT_MODEL_auto4exp_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&auto4exp_M->solverInfo,
                          &auto4exp_M->Timing.simTimeStep);
    rtsiSetTPtr(&auto4exp_M->solverInfo, &rtmGetTPtr(auto4exp_M));
    rtsiSetStepSizePtr(&auto4exp_M->solverInfo, &auto4exp_M->Timing.stepSize0);
    rtsiSetdXPtr(&auto4exp_M->solverInfo, &auto4exp_M->ModelData.derivs);
    rtsiSetContStatesPtr(&auto4exp_M->solverInfo, (real_T **)
                         &auto4exp_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&auto4exp_M->solverInfo,
      &auto4exp_M->Sizes.numContStates);
    rtsiSetErrorStatusPtr(&auto4exp_M->solverInfo, (&rtmGetErrorStatus
      (auto4exp_M)));
    rtsiSetRTModelPtr(&auto4exp_M->solverInfo, auto4exp_M);
  }

  rtsiSetSimTimeStep(&auto4exp_M->solverInfo, MAJOR_TIME_STEP);
  auto4exp_M->ModelData.intgData.y = auto4exp_M->ModelData.odeY;
  auto4exp_M->ModelData.intgData.f[0] = auto4exp_M->ModelData.odeF[0];
  auto4exp_M->ModelData.intgData.f[1] = auto4exp_M->ModelData.odeF[1];
  auto4exp_M->ModelData.intgData.f[2] = auto4exp_M->ModelData.odeF[2];
  auto4exp_M->ModelData.intgData.f[3] = auto4exp_M->ModelData.odeF[3];
  auto4exp_M->ModelData.contStates = ((X_auto4exp_T *) &auto4exp_X);
  rtsiSetSolverData(&auto4exp_M->solverInfo, (void *)
                    &auto4exp_M->ModelData.intgData);
  rtsiSetSolverName(&auto4exp_M->solverInfo,"ode4");
  rtmSetTPtr(auto4exp_M, &auto4exp_M->Timing.tArray[0]);
  rtmSetTFinal(auto4exp_M, 10.0);
  auto4exp_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    auto4exp_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(auto4exp_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(auto4exp_M->rtwLogInfo, (NULL));
    rtliSetLogT(auto4exp_M->rtwLogInfo, "tout");
    rtliSetLogX(auto4exp_M->rtwLogInfo, "");
    rtliSetLogXFinal(auto4exp_M->rtwLogInfo, "");
    rtliSetSigLog(auto4exp_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(auto4exp_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(auto4exp_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(auto4exp_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(auto4exp_M->rtwLogInfo, 1);
    rtliSetLogY(auto4exp_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(auto4exp_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(auto4exp_M->rtwLogInfo, (NULL));
  }

  /* block I/O */
  (void) memset(((void *) &auto4exp_B), 0,
                sizeof(B_auto4exp_T));

  /* states (continuous) */
  {
    (void) memset((void *)&auto4exp_X, 0,
                  sizeof(X_auto4exp_T));
  }

  /* states (dwork) */
  (void) memset((void *)&auto4exp_DW, 0,
                sizeof(DW_auto4exp_T));

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(auto4exp_M->rtwLogInfo, 0.0, rtmGetTFinal
    (auto4exp_M), auto4exp_M->Timing.stepSize0, (&rtmGetErrorStatus(auto4exp_M)));

  /* InitializeConditions for Integrator: '<Root>/Integrator' */
  auto4exp_X.Integrator_CSTATE = auto4exp_P.Integrator_IC;

  /* InitializeConditions for TransferFcn: '<Root>/Transfer Fcn' */
  auto4exp_X.TransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void auto4exp_terminate(void)
{
  /* (no terminate code required) */
}
