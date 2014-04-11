/*
 * searchPCI.c
 *
 * Code generation for model "searchPCI".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Wed Mar 26 15:22:07 2014
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "searchPCI.h"
#include "searchPCI_private.h"
#include "searchPCI_dt.h"

/* list of Real-Time Windows Target timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.2, 0.0,
};

/* Block signals (auto storage) */
B_searchPCI_T searchPCI_B;

/* Block states (auto storage) */
DW_searchPCI_T searchPCI_DW;

/* Real-time model */
RT_MODEL_searchPCI_T searchPCI_M_;
RT_MODEL_searchPCI_T *const searchPCI_M = &searchPCI_M_;

/* Model output function */
void searchPCI_output(void)
{
  /* Sin: '<Root>/Sine Wave' */
  searchPCI_B.SineWave = sin(searchPCI_P.SineWave_Freq * searchPCI_M->Timing.t[0]
    + searchPCI_P.SineWave_Phase) * searchPCI_P.SineWave_Amp +
    searchPCI_P.SineWave_Bias;

  /* Level2 S-Function Block: '<Root>/S-Function' (search) */
  {
    SimStruct *rts = searchPCI_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }
}

/* Model update function */
void searchPCI_update(void)
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
  if (!(++searchPCI_M->Timing.clockTick0)) {
    ++searchPCI_M->Timing.clockTickH0;
  }

  searchPCI_M->Timing.t[0] = searchPCI_M->Timing.clockTick0 *
    searchPCI_M->Timing.stepSize0 + searchPCI_M->Timing.clockTickH0 *
    searchPCI_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++searchPCI_M->Timing.clockTick1)) {
      ++searchPCI_M->Timing.clockTickH1;
    }

    searchPCI_M->Timing.t[1] = searchPCI_M->Timing.clockTick1 *
      searchPCI_M->Timing.stepSize1 + searchPCI_M->Timing.clockTickH1 *
      searchPCI_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void searchPCI_initialize(void)
{
  /* Level2 S-Function Block: '<Root>/S-Function' (search) */
  {
    SimStruct *rts = searchPCI_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<Root>/S-Function' (search) */
  {
    SimStruct *rts = searchPCI_M->childSfunctions[0];
    sfcnInitializeConditions(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void searchPCI_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/S-Function' (search) */
  {
    SimStruct *rts = searchPCI_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  searchPCI_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  searchPCI_update();
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
  searchPCI_initialize();
}

void MdlTerminate(void)
{
  searchPCI_terminate();
}

/* Registration function */
RT_MODEL_searchPCI_T *searchPCI(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)searchPCI_M, 0,
                sizeof(RT_MODEL_searchPCI_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&searchPCI_M->solverInfo,
                          &searchPCI_M->Timing.simTimeStep);
    rtsiSetTPtr(&searchPCI_M->solverInfo, &rtmGetTPtr(searchPCI_M));
    rtsiSetStepSizePtr(&searchPCI_M->solverInfo, &searchPCI_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&searchPCI_M->solverInfo, (&rtmGetErrorStatus
      (searchPCI_M)));
    rtsiSetRTModelPtr(&searchPCI_M->solverInfo, searchPCI_M);
  }

  rtsiSetSimTimeStep(&searchPCI_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&searchPCI_M->solverInfo,"FixedStepDiscrete");
  searchPCI_M->solverInfoPtr = (&searchPCI_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = searchPCI_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    searchPCI_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    searchPCI_M->Timing.sampleTimes = (&searchPCI_M->Timing.sampleTimesArray[0]);
    searchPCI_M->Timing.offsetTimes = (&searchPCI_M->Timing.offsetTimesArray[0]);

    /* task periods */
    searchPCI_M->Timing.sampleTimes[0] = (0.0);
    searchPCI_M->Timing.sampleTimes[1] = (0.2);

    /* task offsets */
    searchPCI_M->Timing.offsetTimes[0] = (0.0);
    searchPCI_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(searchPCI_M, &searchPCI_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = searchPCI_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    searchPCI_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(searchPCI_M, 10.0);
  searchPCI_M->Timing.stepSize0 = 0.2;
  searchPCI_M->Timing.stepSize1 = 0.2;

  /* External mode info */
  searchPCI_M->Sizes.checksums[0] = (4056054231U);
  searchPCI_M->Sizes.checksums[1] = (1709642261U);
  searchPCI_M->Sizes.checksums[2] = (1097010091U);
  searchPCI_M->Sizes.checksums[3] = (696761011U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    searchPCI_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(searchPCI_M->extModeInfo,
      &searchPCI_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(searchPCI_M->extModeInfo, searchPCI_M->Sizes.checksums);
    rteiSetTPtr(searchPCI_M->extModeInfo, rtmGetTPtr(searchPCI_M));
  }

  searchPCI_M->solverInfoPtr = (&searchPCI_M->solverInfo);
  searchPCI_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&searchPCI_M->solverInfo, 0.2);
  rtsiSetSolverMode(&searchPCI_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  searchPCI_M->ModelData.blockIO = ((void *) &searchPCI_B);
  (void) memset(((void *) &searchPCI_B), 0,
                sizeof(B_searchPCI_T));

  /* parameters */
  searchPCI_M->ModelData.defaultParam = ((real_T *)&searchPCI_P);

  /* states (dwork) */
  searchPCI_M->ModelData.dwork = ((void *) &searchPCI_DW);
  (void) memset((void *)&searchPCI_DW, 0,
                sizeof(DW_searchPCI_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    searchPCI_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &searchPCI_M->NonInlinedSFcns.sfcnInfo;
    searchPCI_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(searchPCI_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &searchPCI_M->Sizes.numSampTimes);
    searchPCI_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(searchPCI_M)[0]);
    searchPCI_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(searchPCI_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,searchPCI_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(searchPCI_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(searchPCI_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(searchPCI_M));
    rtssSetStepSizePtr(sfcnInfo, &searchPCI_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(searchPCI_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &searchPCI_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &searchPCI_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &searchPCI_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &searchPCI_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &searchPCI_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &searchPCI_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &searchPCI_M->solverInfoPtr);
  }

  searchPCI_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&searchPCI_M->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    searchPCI_M->childSfunctions =
      (&searchPCI_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    searchPCI_M->childSfunctions[0] =
      (&searchPCI_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: searchPCI/<Root>/S-Function (search) */
    {
      SimStruct *rts = searchPCI_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = searchPCI_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = searchPCI_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = searchPCI_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &searchPCI_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, searchPCI_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &searchPCI_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &searchPCI_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &searchPCI_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &searchPCI_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &searchPCI_B.SineWave);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &searchPCI_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &searchPCI_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "searchPCI/S-Function");
      ssSetRTModel(rts,searchPCI_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      search(rts);
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
  searchPCI_M->Sizes.numContStates = (0);/* Number of continuous states */
  searchPCI_M->Sizes.numY = (0);       /* Number of model outputs */
  searchPCI_M->Sizes.numU = (0);       /* Number of model inputs */
  searchPCI_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  searchPCI_M->Sizes.numSampTimes = (2);/* Number of sample times */
  searchPCI_M->Sizes.numBlocks = (3);  /* Number of blocks */
  searchPCI_M->Sizes.numBlockIO = (2); /* Number of block outputs */
  searchPCI_M->Sizes.numBlockPrms = (4);/* Sum of parameter "widths" */
  return searchPCI_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
