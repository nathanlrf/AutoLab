/*
 * s_fun_lesson1.c
 *
 * Code generation for model "s_fun_lesson1".
 *
 * Model version              : 1.0
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Tue Mar 11 15:59:59 2014
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "s_fun_lesson1.h"
#include "s_fun_lesson1_private.h"

/* Block signals (auto storage) */
B_s_fun_lesson1_T s_fun_lesson1_B;

/* Block states (auto storage) */
DW_s_fun_lesson1_T s_fun_lesson1_DW;

/* Real-time model */
RT_MODEL_s_fun_lesson1_T s_fun_lesson1_M_;
RT_MODEL_s_fun_lesson1_T *const s_fun_lesson1_M = &s_fun_lesson1_M_;

/* Model step function */
void s_fun_lesson1_step(void)
{
  /* Sin: '<Root>/Sine Wave' */
  s_fun_lesson1_B.SineWave = sin(s_fun_lesson1_P.SineWave_Freq *
    s_fun_lesson1_M->Timing.t[0] + s_fun_lesson1_P.SineWave_Phase) *
    s_fun_lesson1_P.SineWave_Amp + s_fun_lesson1_P.SineWave_Bias;

  /* Level2 S-Function Block: '<Root>/S-Function' (timestwo) */
  {
    SimStruct *rts = s_fun_lesson1_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  /* Matfile logging */
  rt_UpdateTXYLogVars(s_fun_lesson1_M->rtwLogInfo, (s_fun_lesson1_M->Timing.t));

  /* signal main to stop simulation */
  {                                    /* Sample time: [0.0s, 0.0s] */
    if ((rtmGetTFinal(s_fun_lesson1_M)!=-1) &&
        !((rtmGetTFinal(s_fun_lesson1_M)-s_fun_lesson1_M->Timing.t[0]) >
          s_fun_lesson1_M->Timing.t[0] * (DBL_EPSILON))) {
      rtmSetErrorStatus(s_fun_lesson1_M, "Simulation finished");
    }

    if (rtmGetStopRequested(s_fun_lesson1_M)) {
      rtmSetErrorStatus(s_fun_lesson1_M, "Simulation finished");
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++s_fun_lesson1_M->Timing.clockTick0)) {
    ++s_fun_lesson1_M->Timing.clockTickH0;
  }

  s_fun_lesson1_M->Timing.t[0] = s_fun_lesson1_M->Timing.clockTick0 *
    s_fun_lesson1_M->Timing.stepSize0 + s_fun_lesson1_M->Timing.clockTickH0 *
    s_fun_lesson1_M->Timing.stepSize0 * 4294967296.0;

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
    s_fun_lesson1_M->Timing.clockTick1++;
    if (!s_fun_lesson1_M->Timing.clockTick1) {
      s_fun_lesson1_M->Timing.clockTickH1++;
    }
  }
}

/* Model initialize function */
void s_fun_lesson1_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)s_fun_lesson1_M, 0,
                sizeof(RT_MODEL_s_fun_lesson1_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&s_fun_lesson1_M->solverInfo,
                          &s_fun_lesson1_M->Timing.simTimeStep);
    rtsiSetTPtr(&s_fun_lesson1_M->solverInfo, &rtmGetTPtr(s_fun_lesson1_M));
    rtsiSetStepSizePtr(&s_fun_lesson1_M->solverInfo,
                       &s_fun_lesson1_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&s_fun_lesson1_M->solverInfo, (&rtmGetErrorStatus
      (s_fun_lesson1_M)));
    rtsiSetRTModelPtr(&s_fun_lesson1_M->solverInfo, s_fun_lesson1_M);
  }

  rtsiSetSimTimeStep(&s_fun_lesson1_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&s_fun_lesson1_M->solverInfo,"FixedStepDiscrete");
  s_fun_lesson1_M->solverInfoPtr = (&s_fun_lesson1_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = s_fun_lesson1_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    s_fun_lesson1_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    s_fun_lesson1_M->Timing.sampleTimes =
      (&s_fun_lesson1_M->Timing.sampleTimesArray[0]);
    s_fun_lesson1_M->Timing.offsetTimes =
      (&s_fun_lesson1_M->Timing.offsetTimesArray[0]);

    /* task periods */
    s_fun_lesson1_M->Timing.sampleTimes[0] = (0.0);
    s_fun_lesson1_M->Timing.sampleTimes[1] = (0.2);

    /* task offsets */
    s_fun_lesson1_M->Timing.offsetTimes[0] = (0.0);
    s_fun_lesson1_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(s_fun_lesson1_M, &s_fun_lesson1_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = s_fun_lesson1_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    s_fun_lesson1_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(s_fun_lesson1_M, 10.0);
  s_fun_lesson1_M->Timing.stepSize0 = 0.2;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    s_fun_lesson1_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(s_fun_lesson1_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(s_fun_lesson1_M->rtwLogInfo, (NULL));
    rtliSetLogT(s_fun_lesson1_M->rtwLogInfo, "tout");
    rtliSetLogX(s_fun_lesson1_M->rtwLogInfo, "");
    rtliSetLogXFinal(s_fun_lesson1_M->rtwLogInfo, "");
    rtliSetSigLog(s_fun_lesson1_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(s_fun_lesson1_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(s_fun_lesson1_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(s_fun_lesson1_M->rtwLogInfo, 1000);
    rtliSetLogDecimation(s_fun_lesson1_M->rtwLogInfo, 1);
    rtliSetLogY(s_fun_lesson1_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(s_fun_lesson1_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(s_fun_lesson1_M->rtwLogInfo, (NULL));
  }

  s_fun_lesson1_M->solverInfoPtr = (&s_fun_lesson1_M->solverInfo);
  s_fun_lesson1_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&s_fun_lesson1_M->solverInfo, 0.2);
  rtsiSetSolverMode(&s_fun_lesson1_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  (void) memset(((void *) &s_fun_lesson1_B), 0,
                sizeof(B_s_fun_lesson1_T));

  /* states (dwork) */
  (void) memset((void *)&s_fun_lesson1_DW, 0,
                sizeof(DW_s_fun_lesson1_T));

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &s_fun_lesson1_M->NonInlinedSFcns.sfcnInfo;
    s_fun_lesson1_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(s_fun_lesson1_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &s_fun_lesson1_M->Sizes.numSampTimes);
    s_fun_lesson1_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (s_fun_lesson1_M)[0]);
    s_fun_lesson1_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (s_fun_lesson1_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,s_fun_lesson1_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(s_fun_lesson1_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(s_fun_lesson1_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(s_fun_lesson1_M));
    rtssSetStepSizePtr(sfcnInfo, &s_fun_lesson1_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(s_fun_lesson1_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &s_fun_lesson1_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &s_fun_lesson1_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &s_fun_lesson1_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &s_fun_lesson1_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &s_fun_lesson1_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &s_fun_lesson1_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &s_fun_lesson1_M->solverInfoPtr);
  }

  s_fun_lesson1_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&s_fun_lesson1_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  1*sizeof(SimStruct));
    s_fun_lesson1_M->childSfunctions =
      (&s_fun_lesson1_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    s_fun_lesson1_M->childSfunctions[0] =
      (&s_fun_lesson1_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: s_fun_lesson1/<Root>/S-Function (timestwo) */
    {
      SimStruct *rts = s_fun_lesson1_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = s_fun_lesson1_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = s_fun_lesson1_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = s_fun_lesson1_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &s_fun_lesson1_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, s_fun_lesson1_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &s_fun_lesson1_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &s_fun_lesson1_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &s_fun_lesson1_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &s_fun_lesson1_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &s_fun_lesson1_M->NonInlinedSFcns.Sfcn0.UPtrs0;
          sfcnUPtrs[0] = &s_fun_lesson1_B.SineWave;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &s_fun_lesson1_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &s_fun_lesson1_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "s_fun_lesson1/S-Function");
      ssSetRTModel(rts,s_fun_lesson1_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      timestwo(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1);
      ssSetInputPortDataType(rts, 0, SS_DOUBLE);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetOutputPortWidth(rts, 0, 1);
      ssSetOutputPortDataType(rts, 0, SS_DOUBLE);
      ssSetOutputPortComplexSignal(rts, 0, 0);
      ssSetOutputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Matfile logging */
  rt_StartDataLoggingWithStartTime(s_fun_lesson1_M->rtwLogInfo, 0.0,
    rtmGetTFinal(s_fun_lesson1_M), s_fun_lesson1_M->Timing.stepSize0,
    (&rtmGetErrorStatus(s_fun_lesson1_M)));
}

/* Model terminate function */
void s_fun_lesson1_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/S-Function' (timestwo) */
  {
    SimStruct *rts = s_fun_lesson1_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}
