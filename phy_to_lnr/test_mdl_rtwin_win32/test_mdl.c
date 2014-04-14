/*
 * test_mdl.c
 *
 * Code generation for model "test_mdl".
 *
 * Model version              : 1.3
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Mon Apr 14 15:47:13 2014
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "test_mdl.h"
#include "test_mdl_private.h"
#include "test_mdl_dt.h"

/* list of Real-Time Windows Target timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.2, 0.0,
};

/* Block signals (auto storage) */
B_test_mdl_T test_mdl_B;

/* Block states (auto storage) */
DW_test_mdl_T test_mdl_DW;

/* Real-time model */
RT_MODEL_test_mdl_T test_mdl_M_;
RT_MODEL_test_mdl_T *const test_mdl_M = &test_mdl_M_;

/* Model output function */
void test_mdl_output(void)
{
  /* Sin: '<Root>/Sine Wave' */
  test_mdl_B.SineWave = sin(test_mdl_P.SineWave_Freq * test_mdl_M->Timing.t[0] +
    test_mdl_P.SineWave_Phase) * test_mdl_P.SineWave_Amp +
    test_mdl_P.SineWave_Bias;

  /* Level2 S-Function Block: '<Root>/S-Function' (phy_to_lnr) */
  {
    SimStruct *rts = test_mdl_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }
}

/* Model update function */
void test_mdl_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++test_mdl_M->Timing.clockTick0)) {
    ++test_mdl_M->Timing.clockTickH0;
  }

  test_mdl_M->Timing.t[0] = test_mdl_M->Timing.clockTick0 *
    test_mdl_M->Timing.stepSize0 + test_mdl_M->Timing.clockTickH0 *
    test_mdl_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.2s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++test_mdl_M->Timing.clockTick1)) {
      ++test_mdl_M->Timing.clockTickH1;
    }

    test_mdl_M->Timing.t[1] = test_mdl_M->Timing.clockTick1 *
      test_mdl_M->Timing.stepSize1 + test_mdl_M->Timing.clockTickH1 *
      test_mdl_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void test_mdl_initialize(void)
{
  /* Level2 S-Function Block: '<Root>/S-Function' (phy_to_lnr) */
  {
    SimStruct *rts = test_mdl_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void test_mdl_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/S-Function' (phy_to_lnr) */
  {
    SimStruct *rts = test_mdl_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  test_mdl_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  test_mdl_update();
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
  test_mdl_initialize();
}

void MdlTerminate(void)
{
  test_mdl_terminate();
}

/* Registration function */
RT_MODEL_test_mdl_T *test_mdl(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)test_mdl_M, 0,
                sizeof(RT_MODEL_test_mdl_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&test_mdl_M->solverInfo,
                          &test_mdl_M->Timing.simTimeStep);
    rtsiSetTPtr(&test_mdl_M->solverInfo, &rtmGetTPtr(test_mdl_M));
    rtsiSetStepSizePtr(&test_mdl_M->solverInfo, &test_mdl_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&test_mdl_M->solverInfo, (&rtmGetErrorStatus
      (test_mdl_M)));
    rtsiSetRTModelPtr(&test_mdl_M->solverInfo, test_mdl_M);
  }

  rtsiSetSimTimeStep(&test_mdl_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&test_mdl_M->solverInfo,"FixedStepDiscrete");
  test_mdl_M->solverInfoPtr = (&test_mdl_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = test_mdl_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    test_mdl_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    test_mdl_M->Timing.sampleTimes = (&test_mdl_M->Timing.sampleTimesArray[0]);
    test_mdl_M->Timing.offsetTimes = (&test_mdl_M->Timing.offsetTimesArray[0]);

    /* task periods */
    test_mdl_M->Timing.sampleTimes[0] = (0.0);
    test_mdl_M->Timing.sampleTimes[1] = (0.2);

    /* task offsets */
    test_mdl_M->Timing.offsetTimes[0] = (0.0);
    test_mdl_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(test_mdl_M, &test_mdl_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = test_mdl_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    test_mdl_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(test_mdl_M, 10.0);
  test_mdl_M->Timing.stepSize0 = 0.2;
  test_mdl_M->Timing.stepSize1 = 0.2;

  /* External mode info */
  test_mdl_M->Sizes.checksums[0] = (2069225561U);
  test_mdl_M->Sizes.checksums[1] = (668492855U);
  test_mdl_M->Sizes.checksums[2] = (2613391448U);
  test_mdl_M->Sizes.checksums[3] = (2915687380U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    test_mdl_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(test_mdl_M->extModeInfo,
      &test_mdl_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(test_mdl_M->extModeInfo, test_mdl_M->Sizes.checksums);
    rteiSetTPtr(test_mdl_M->extModeInfo, rtmGetTPtr(test_mdl_M));
  }

  test_mdl_M->solverInfoPtr = (&test_mdl_M->solverInfo);
  test_mdl_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&test_mdl_M->solverInfo, 0.2);
  rtsiSetSolverMode(&test_mdl_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  test_mdl_M->ModelData.blockIO = ((void *) &test_mdl_B);
  (void) memset(((void *) &test_mdl_B), 0,
                sizeof(B_test_mdl_T));

  /* parameters */
  test_mdl_M->ModelData.defaultParam = ((real_T *)&test_mdl_P);

  /* states (dwork) */
  test_mdl_M->ModelData.dwork = ((void *) &test_mdl_DW);
  (void) memset((void *)&test_mdl_DW, 0,
                sizeof(DW_test_mdl_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    test_mdl_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &test_mdl_M->NonInlinedSFcns.sfcnInfo;
    test_mdl_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(test_mdl_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &test_mdl_M->Sizes.numSampTimes);
    test_mdl_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(test_mdl_M)[0]);
    test_mdl_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(test_mdl_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,test_mdl_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(test_mdl_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(test_mdl_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(test_mdl_M));
    rtssSetStepSizePtr(sfcnInfo, &test_mdl_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(test_mdl_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &test_mdl_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &test_mdl_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &test_mdl_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &test_mdl_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &test_mdl_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &test_mdl_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &test_mdl_M->solverInfoPtr);
  }

  test_mdl_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&test_mdl_M->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    test_mdl_M->childSfunctions =
      (&test_mdl_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    test_mdl_M->childSfunctions[0] =
      (&test_mdl_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: test_mdl/<Root>/S-Function (phy_to_lnr) */
    {
      SimStruct *rts = test_mdl_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = test_mdl_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = test_mdl_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = test_mdl_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &test_mdl_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, test_mdl_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &test_mdl_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &test_mdl_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &test_mdl_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &test_mdl_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &test_mdl_B.SineWave);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &test_mdl_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &test_mdl_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "test_mdl/S-Function");
      ssSetRTModel(rts,test_mdl_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      phy_to_lnr(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

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
  test_mdl_M->Sizes.numContStates = (0);/* Number of continuous states */
  test_mdl_M->Sizes.numY = (0);        /* Number of model outputs */
  test_mdl_M->Sizes.numU = (0);        /* Number of model inputs */
  test_mdl_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  test_mdl_M->Sizes.numSampTimes = (2);/* Number of sample times */
  test_mdl_M->Sizes.numBlocks = (3);   /* Number of blocks */
  test_mdl_M->Sizes.numBlockIO = (2);  /* Number of block outputs */
  test_mdl_M->Sizes.numBlockPrms = (4);/* Sum of parameter "widths" */
  return test_mdl_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
