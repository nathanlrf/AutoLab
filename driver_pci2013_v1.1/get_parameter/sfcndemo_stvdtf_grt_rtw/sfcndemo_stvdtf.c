/*
 * sfcndemo_stvdtf.c
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

/* Block signals (auto storage) */
B_sfcndemo_stvdtf_T sfcndemo_stvdtf_B;

/* Block states (auto storage) */
DW_sfcndemo_stvdtf_T sfcndemo_stvdtf_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_sfcndemo_stvdtf_T sfcndemo_stvdtf_Y;

/* Real-time model */
RT_MODEL_sfcndemo_stvdtf_T sfcndemo_stvdtf_M_;
RT_MODEL_sfcndemo_stvdtf_T *const sfcndemo_stvdtf_M = &sfcndemo_stvdtf_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (sfcndemo_stvdtf_M->Timing.TaskCounters.TID[2])++;
  if ((sfcndemo_stvdtf_M->Timing.TaskCounters.TID[2]) > 19) {/* Sample time: [0.2s, 0.0s] */
    sfcndemo_stvdtf_M->Timing.TaskCounters.TID[2] = 0;
  }

  sfcndemo_stvdtf_M->Timing.sampleHits[2] =
    (sfcndemo_stvdtf_M->Timing.TaskCounters.TID[2] == 0);
  (sfcndemo_stvdtf_M->Timing.TaskCounters.TID[3])++;
  if ((sfcndemo_stvdtf_M->Timing.TaskCounters.TID[3]) > 99) {/* Sample time: [1.0s, 0.0s] */
    sfcndemo_stvdtf_M->Timing.TaskCounters.TID[3] = 0;
  }

  sfcndemo_stvdtf_M->Timing.sampleHits[3] =
    (sfcndemo_stvdtf_M->Timing.TaskCounters.TID[3] == 0);
}

/* Model output function */
static void sfcndemo_stvdtf_output(void)
{
  real_T tmp;
  int32_T i;

  /* Sin: '<Root>/Sine Wave' */
  tmp = sin(sfcndemo_stvdtf_P.SineWave_Freq * sfcndemo_stvdtf_M->Timing.t[0] +
            sfcndemo_stvdtf_P.SineWave_Phase);
  for (i = 0; i < 9; i++) {
    sfcndemo_stvdtf_B.SineWave[i] = tmp * sfcndemo_stvdtf_P.SineWave_Amp[i] +
      sfcndemo_stvdtf_P.SineWave_Bias;
  }

  /* End of Sin: '<Root>/Sine Wave' */

  /* Level2 S-Function Block: '<Root>/Time Varying Discrete Transfer Function S-Function' (stvdtf) */
  {
    SimStruct *rts = sfcndemo_stvdtf_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }

  if (sfcndemo_stvdtf_M->Timing.TaskCounters.TID[2] == 0) {
    /* Outport: '<Root>/Out' */
    sfcndemo_stvdtf_Y.Out = sfcndemo_stvdtf_B.TimeVaryingDiscreteTransferFunc;
  }
}

/* Model update function */
static void sfcndemo_stvdtf_update(void)
{
  /* Level2 S-Function Block: '<Root>/Time Varying Discrete Transfer Function S-Function' (stvdtf) */
  {
    SimStruct *rts = sfcndemo_stvdtf_M->childSfunctions[0];
    sfcnUpdate(rts, 0);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
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
  if (!(++sfcndemo_stvdtf_M->Timing.clockTick0)) {
    ++sfcndemo_stvdtf_M->Timing.clockTickH0;
  }

  sfcndemo_stvdtf_M->Timing.t[0] = sfcndemo_stvdtf_M->Timing.clockTick0 *
    sfcndemo_stvdtf_M->Timing.stepSize0 + sfcndemo_stvdtf_M->Timing.clockTickH0 *
    sfcndemo_stvdtf_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.01s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++sfcndemo_stvdtf_M->Timing.clockTick1)) {
      ++sfcndemo_stvdtf_M->Timing.clockTickH1;
    }

    sfcndemo_stvdtf_M->Timing.t[1] = sfcndemo_stvdtf_M->Timing.clockTick1 *
      sfcndemo_stvdtf_M->Timing.stepSize1 +
      sfcndemo_stvdtf_M->Timing.clockTickH1 *
      sfcndemo_stvdtf_M->Timing.stepSize1 * 4294967296.0;
  }

  if (sfcndemo_stvdtf_M->Timing.TaskCounters.TID[2] == 0) {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick2" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick2"
     * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick2 and the high bits
     * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++sfcndemo_stvdtf_M->Timing.clockTick2)) {
      ++sfcndemo_stvdtf_M->Timing.clockTickH2;
    }

    sfcndemo_stvdtf_M->Timing.t[2] = sfcndemo_stvdtf_M->Timing.clockTick2 *
      sfcndemo_stvdtf_M->Timing.stepSize2 +
      sfcndemo_stvdtf_M->Timing.clockTickH2 *
      sfcndemo_stvdtf_M->Timing.stepSize2 * 4294967296.0;
  }

  if (sfcndemo_stvdtf_M->Timing.TaskCounters.TID[3] == 0) {
    /* Update absolute timer for sample time: [1.0s, 0.0s] */
    /* The "clockTick3" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick3"
     * and "Timing.stepSize3". Size of "clockTick3" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick3 and the high bits
     * Timing.clockTickH3. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++sfcndemo_stvdtf_M->Timing.clockTick3)) {
      ++sfcndemo_stvdtf_M->Timing.clockTickH3;
    }

    sfcndemo_stvdtf_M->Timing.t[3] = sfcndemo_stvdtf_M->Timing.clockTick3 *
      sfcndemo_stvdtf_M->Timing.stepSize3 +
      sfcndemo_stvdtf_M->Timing.clockTickH3 *
      sfcndemo_stvdtf_M->Timing.stepSize3 * 4294967296.0;
  }

  rate_scheduler();
}

/* Model initialize function */
void sfcndemo_stvdtf_initialize(void)
{
  /* Level2 S-Function Block: '<Root>/Time Varying Discrete Transfer Function S-Function' (stvdtf) */
  {
    SimStruct *rts = sfcndemo_stvdtf_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void sfcndemo_stvdtf_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/Time Varying Discrete Transfer Function S-Function' (stvdtf) */
  {
    SimStruct *rts = sfcndemo_stvdtf_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  sfcndemo_stvdtf_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  sfcndemo_stvdtf_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  sfcndemo_stvdtf_initialize();
}

void MdlTerminate(void)
{
  sfcndemo_stvdtf_terminate();
}

/* Registration function */
RT_MODEL_sfcndemo_stvdtf_T *sfcndemo_stvdtf(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)sfcndemo_stvdtf_M, 0,
                sizeof(RT_MODEL_sfcndemo_stvdtf_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&sfcndemo_stvdtf_M->solverInfo,
                          &sfcndemo_stvdtf_M->Timing.simTimeStep);
    rtsiSetTPtr(&sfcndemo_stvdtf_M->solverInfo, &rtmGetTPtr(sfcndemo_stvdtf_M));
    rtsiSetStepSizePtr(&sfcndemo_stvdtf_M->solverInfo,
                       &sfcndemo_stvdtf_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&sfcndemo_stvdtf_M->solverInfo, (&rtmGetErrorStatus
      (sfcndemo_stvdtf_M)));
    rtsiSetRTModelPtr(&sfcndemo_stvdtf_M->solverInfo, sfcndemo_stvdtf_M);
  }

  rtsiSetSimTimeStep(&sfcndemo_stvdtf_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&sfcndemo_stvdtf_M->solverInfo,"FixedStepDiscrete");
  sfcndemo_stvdtf_M->solverInfoPtr = (&sfcndemo_stvdtf_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = sfcndemo_stvdtf_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    mdlTsMap[3] = 3;
    sfcndemo_stvdtf_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    sfcndemo_stvdtf_M->Timing.sampleTimes =
      (&sfcndemo_stvdtf_M->Timing.sampleTimesArray[0]);
    sfcndemo_stvdtf_M->Timing.offsetTimes =
      (&sfcndemo_stvdtf_M->Timing.offsetTimesArray[0]);

    /* task periods */
    sfcndemo_stvdtf_M->Timing.sampleTimes[0] = (0.0);
    sfcndemo_stvdtf_M->Timing.sampleTimes[1] = (0.01);
    sfcndemo_stvdtf_M->Timing.sampleTimes[2] = (0.2);
    sfcndemo_stvdtf_M->Timing.sampleTimes[3] = (1.0);

    /* task offsets */
    sfcndemo_stvdtf_M->Timing.offsetTimes[0] = (0.0);
    sfcndemo_stvdtf_M->Timing.offsetTimes[1] = (0.0);
    sfcndemo_stvdtf_M->Timing.offsetTimes[2] = (0.0);
    sfcndemo_stvdtf_M->Timing.offsetTimes[3] = (0.0);
  }

  rtmSetTPtr(sfcndemo_stvdtf_M, &sfcndemo_stvdtf_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = sfcndemo_stvdtf_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    mdlSampleHits[2] = 1;
    mdlSampleHits[3] = 1;
    sfcndemo_stvdtf_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(sfcndemo_stvdtf_M, 10.0);
  sfcndemo_stvdtf_M->Timing.stepSize0 = 0.01;
  sfcndemo_stvdtf_M->Timing.stepSize1 = 0.01;
  sfcndemo_stvdtf_M->Timing.stepSize2 = 0.2;
  sfcndemo_stvdtf_M->Timing.stepSize3 = 1.0;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    sfcndemo_stvdtf_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(sfcndemo_stvdtf_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(sfcndemo_stvdtf_M->rtwLogInfo, (NULL));
    rtliSetLogT(sfcndemo_stvdtf_M->rtwLogInfo, "tout");
    rtliSetLogX(sfcndemo_stvdtf_M->rtwLogInfo, "");
    rtliSetLogXFinal(sfcndemo_stvdtf_M->rtwLogInfo, "");
    rtliSetSigLog(sfcndemo_stvdtf_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(sfcndemo_stvdtf_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(sfcndemo_stvdtf_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(sfcndemo_stvdtf_M->rtwLogInfo, 0);
    rtliSetLogDecimation(sfcndemo_stvdtf_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &sfcndemo_stvdtf_Y.Out
      };

      rtliSetLogYSignalPtrs(sfcndemo_stvdtf_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "sfcndemo_stvdtf/Out" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          1,
          rt_LoggedOutputWidths,
          rt_LoggedOutputNumDimensions,
          rt_LoggedOutputDimensions,
          rt_LoggedOutputIsVarDims,
          rt_LoggedCurrentSignalDimensions,
          rt_LoggedCurrentSignalDimensionsSize,
          rt_LoggedOutputDataTypeIds,
          rt_LoggedOutputComplexSignals,
          (NULL),

          { rt_LoggedOutputLabels },
          (NULL),
          (NULL),
          (NULL),

          { rt_LoggedOutputBlockNames },

          { (NULL) },
          (NULL),
          rt_RTWLogDataTypeConvert
        }
      };

      rtliSetLogYSignalInfo(sfcndemo_stvdtf_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
    }

    rtliSetLogY(sfcndemo_stvdtf_M->rtwLogInfo, "yout");
  }

  sfcndemo_stvdtf_M->solverInfoPtr = (&sfcndemo_stvdtf_M->solverInfo);
  sfcndemo_stvdtf_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&sfcndemo_stvdtf_M->solverInfo, 0.01);
  rtsiSetSolverMode(&sfcndemo_stvdtf_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  sfcndemo_stvdtf_M->ModelData.blockIO = ((void *) &sfcndemo_stvdtf_B);

  {
    int_T i;
    for (i = 0; i < 9; i++) {
      sfcndemo_stvdtf_B.SineWave[i] = 0.0;
    }

    sfcndemo_stvdtf_B.TimeVaryingDiscreteTransferFunc = 0.0;
  }

  /* parameters */
  sfcndemo_stvdtf_M->ModelData.defaultParam = ((real_T *)&sfcndemo_stvdtf_P);

  /* states (dwork) */
  sfcndemo_stvdtf_M->ModelData.dwork = ((void *) &sfcndemo_stvdtf_DW);
  sfcndemo_stvdtf_DW.TimeVaryingDiscreteTransferFunc[0] = 0.0;
  sfcndemo_stvdtf_DW.TimeVaryingDiscreteTransferFunc[1] = 0.0;
  sfcndemo_stvdtf_DW.TimeVaryingDiscreteTransferFunc[2] = 0.0;

  {
    int_T i;
    for (i = 0; i < 8; i++) {
      sfcndemo_stvdtf_DW.TimeVaryingDiscreteTransferFu_f[i] = 0.0;
    }
  }

  /* external outputs */
  sfcndemo_stvdtf_M->ModelData.outputs = (&sfcndemo_stvdtf_Y);
  sfcndemo_stvdtf_Y.Out = 0.0;

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &sfcndemo_stvdtf_M->NonInlinedSFcns.sfcnInfo;
    sfcndemo_stvdtf_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(sfcndemo_stvdtf_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &sfcndemo_stvdtf_M->Sizes.numSampTimes);
    sfcndemo_stvdtf_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (sfcndemo_stvdtf_M)[0]);
    sfcndemo_stvdtf_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (sfcndemo_stvdtf_M)[1]);
    sfcndemo_stvdtf_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr
      (sfcndemo_stvdtf_M)[2]);
    sfcndemo_stvdtf_M->NonInlinedSFcns.taskTimePtrs[3] = &(rtmGetTPtr
      (sfcndemo_stvdtf_M)[3]);
    rtssSetTPtrPtr(sfcnInfo,sfcndemo_stvdtf_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(sfcndemo_stvdtf_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(sfcndemo_stvdtf_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (sfcndemo_stvdtf_M));
    rtssSetStepSizePtr(sfcnInfo, &sfcndemo_stvdtf_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(sfcndemo_stvdtf_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &sfcndemo_stvdtf_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &sfcndemo_stvdtf_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo,
      &sfcndemo_stvdtf_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &sfcndemo_stvdtf_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &sfcndemo_stvdtf_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &sfcndemo_stvdtf_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &sfcndemo_stvdtf_M->solverInfoPtr);
  }

  sfcndemo_stvdtf_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&sfcndemo_stvdtf_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  1*sizeof(SimStruct));
    sfcndemo_stvdtf_M->childSfunctions =
      (&sfcndemo_stvdtf_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    sfcndemo_stvdtf_M->childSfunctions[0] =
      (&sfcndemo_stvdtf_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: sfcndemo_stvdtf/<Root>/Time Varying Discrete Transfer Function S-Function (stvdtf) */
    {
      SimStruct *rts = sfcndemo_stvdtf_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = sfcndemo_stvdtf_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = sfcndemo_stvdtf_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = sfcndemo_stvdtf_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*2);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*2);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &sfcndemo_stvdtf_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, sfcndemo_stvdtf_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &sfcndemo_stvdtf_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &sfcndemo_stvdtf_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &sfcndemo_stvdtf_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &sfcndemo_stvdtf_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &sfcndemo_stvdtf_M->NonInlinedSFcns.Sfcn0.UPtrs0;

          {
            int_T i1;
            const real_T *u0 = sfcndemo_stvdtf_B.SineWave;
            for (i1=0; i1 < 9; i1++) {
              sfcnUPtrs[i1] = &u0[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 9);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &sfcndemo_stvdtf_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &sfcndemo_stvdtf_B.TimeVaryingDiscreteTransferFunc));
        }
      }

      /* states */
      ssSetDiscStates(rts, (real_T *)
                      &sfcndemo_stvdtf_DW.TimeVaryingDiscreteTransferFunc[0]);

      /* path info */
      ssSetModelName(rts, "Time Varying Discrete\nTransfer Function\nS-Function");
      ssSetPath(rts,
                "sfcndemo_stvdtf/Time Varying Discrete Transfer Function S-Function");
      ssSetRTModel(rts,sfcndemo_stvdtf_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &sfcndemo_stvdtf_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       sfcndemo_stvdtf_P.TimeVaryingDiscreteTransferFunc);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       sfcndemo_stvdtf_P.TimeVaryingDiscreteTransferFu_d);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       sfcndemo_stvdtf_P.TimeVaryingDiscreteTransferF_ce);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       sfcndemo_stvdtf_P.TimeVaryingDiscreteTransferF_oz);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *)
                 &sfcndemo_stvdtf_DW.TimeVaryingDiscreteTransferFu_f[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &sfcndemo_stvdtf_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &sfcndemo_stvdtf_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 8);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &sfcndemo_stvdtf_DW.TimeVaryingDiscreteTransferFu_f[0]);

        /* DSTATE */
        ssSetDWorkWidth(rts, 1, 3);
        ssSetDWorkDataType(rts, 1,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWorkUsedAsDState(rts, 1, 1);
        ssSetDWork(rts, 1, &sfcndemo_stvdtf_DW.TimeVaryingDiscreteTransferFunc[0]);
      }

      /* registration */
      stvdtf(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.2);
      ssSetOffsetTime(rts, 0, 0.0);
      ssSetSampleTime(rts, 1, 1.0);
      ssSetOffsetTime(rts, 1, 0.0);
      sfcnTsMap[0] = 2;
      sfcnTsMap[1] = 3;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  sfcndemo_stvdtf_M->Sizes.numContStates = (0);/* Number of continuous states */
  sfcndemo_stvdtf_M->Sizes.numY = (1); /* Number of model outputs */
  sfcndemo_stvdtf_M->Sizes.numU = (0); /* Number of model inputs */
  sfcndemo_stvdtf_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  sfcndemo_stvdtf_M->Sizes.numSampTimes = (4);/* Number of sample times */
  sfcndemo_stvdtf_M->Sizes.numBlocks = (3);/* Number of blocks */
  sfcndemo_stvdtf_M->Sizes.numBlockIO = (2);/* Number of block outputs */
  sfcndemo_stvdtf_M->Sizes.numBlockPrms = (30);/* Sum of parameter "widths" */
  return sfcndemo_stvdtf_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
