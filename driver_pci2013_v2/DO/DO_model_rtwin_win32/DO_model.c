/*
 * DO_model.c
 *
 * Code generation for model "DO_model".
 *
 * Model version              : 1.4
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Tue Apr 15 11:27:59 2014
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "DO_model.h"
#include "DO_model_private.h"
#include "DO_model_dt.h"

/* list of Real-Time Windows Target timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.02, 0.0,
};

/* Block signals (auto storage) */
B_DO_model_T DO_model_B;

/* Block states (auto storage) */
DW_DO_model_T DO_model_DW;

/* Real-time model */
RT_MODEL_DO_model_T DO_model_M_;
RT_MODEL_DO_model_T *const DO_model_M = &DO_model_M_;

/* Model output function */
void DO_model_output(void)
{
  /* Level2 S-Function Block: '<Root>/S-Function' (DO_v1) */
  {
    SimStruct *rts = DO_model_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }
}

/* Model update function */
void DO_model_update(void)
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
  if (!(++DO_model_M->Timing.clockTick0)) {
    ++DO_model_M->Timing.clockTickH0;
  }

  DO_model_M->Timing.t[0] = DO_model_M->Timing.clockTick0 *
    DO_model_M->Timing.stepSize0 + DO_model_M->Timing.clockTickH0 *
    DO_model_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++DO_model_M->Timing.clockTick1)) {
      ++DO_model_M->Timing.clockTickH1;
    }

    DO_model_M->Timing.t[1] = DO_model_M->Timing.clockTick1 *
      DO_model_M->Timing.stepSize1 + DO_model_M->Timing.clockTickH1 *
      DO_model_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void DO_model_initialize(void)
{
  /* Level2 S-Function Block: '<Root>/S-Function' (DO_v1) */
  {
    SimStruct *rts = DO_model_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void DO_model_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/S-Function' (DO_v1) */
  {
    SimStruct *rts = DO_model_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  DO_model_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  DO_model_update();
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
  DO_model_initialize();
}

void MdlTerminate(void)
{
  DO_model_terminate();
}

/* Registration function */
RT_MODEL_DO_model_T *DO_model(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)DO_model_M, 0,
                sizeof(RT_MODEL_DO_model_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&DO_model_M->solverInfo,
                          &DO_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&DO_model_M->solverInfo, &rtmGetTPtr(DO_model_M));
    rtsiSetStepSizePtr(&DO_model_M->solverInfo, &DO_model_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&DO_model_M->solverInfo, (&rtmGetErrorStatus
      (DO_model_M)));
    rtsiSetRTModelPtr(&DO_model_M->solverInfo, DO_model_M);
  }

  rtsiSetSimTimeStep(&DO_model_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&DO_model_M->solverInfo,"FixedStepDiscrete");
  DO_model_M->solverInfoPtr = (&DO_model_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = DO_model_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    DO_model_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    DO_model_M->Timing.sampleTimes = (&DO_model_M->Timing.sampleTimesArray[0]);
    DO_model_M->Timing.offsetTimes = (&DO_model_M->Timing.offsetTimesArray[0]);

    /* task periods */
    DO_model_M->Timing.sampleTimes[0] = (0.0);
    DO_model_M->Timing.sampleTimes[1] = (0.02);

    /* task offsets */
    DO_model_M->Timing.offsetTimes[0] = (0.0);
    DO_model_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(DO_model_M, &DO_model_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = DO_model_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    DO_model_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(DO_model_M, 10.0);
  DO_model_M->Timing.stepSize0 = 0.02;
  DO_model_M->Timing.stepSize1 = 0.02;

  /* External mode info */
  DO_model_M->Sizes.checksums[0] = (1233238421U);
  DO_model_M->Sizes.checksums[1] = (25660452U);
  DO_model_M->Sizes.checksums[2] = (2649484807U);
  DO_model_M->Sizes.checksums[3] = (3179384684U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    DO_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DO_model_M->extModeInfo,
      &DO_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DO_model_M->extModeInfo, DO_model_M->Sizes.checksums);
    rteiSetTPtr(DO_model_M->extModeInfo, rtmGetTPtr(DO_model_M));
  }

  DO_model_M->solverInfoPtr = (&DO_model_M->solverInfo);
  DO_model_M->Timing.stepSize = (0.02);
  rtsiSetFixedStepSize(&DO_model_M->solverInfo, 0.02);
  rtsiSetSolverMode(&DO_model_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  DO_model_M->ModelData.blockIO = ((void *) &DO_model_B);
  (void) memset(((void *) &DO_model_B), 0,
                sizeof(B_DO_model_T));

  /* parameters */
  DO_model_M->ModelData.defaultParam = ((real_T *)&DO_model_P);

  /* states (dwork) */
  DO_model_M->ModelData.dwork = ((void *) &DO_model_DW);
  (void) memset((void *)&DO_model_DW, 0,
                sizeof(DW_DO_model_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    DO_model_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &DO_model_M->NonInlinedSFcns.sfcnInfo;
    DO_model_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(DO_model_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &DO_model_M->Sizes.numSampTimes);
    DO_model_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(DO_model_M)[0]);
    DO_model_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(DO_model_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,DO_model_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(DO_model_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(DO_model_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(DO_model_M));
    rtssSetStepSizePtr(sfcnInfo, &DO_model_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(DO_model_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &DO_model_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &DO_model_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &DO_model_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &DO_model_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &DO_model_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &DO_model_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &DO_model_M->solverInfoPtr);
  }

  DO_model_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&DO_model_M->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    DO_model_M->childSfunctions =
      (&DO_model_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    DO_model_M->childSfunctions[0] =
      (&DO_model_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: DO_model/<Root>/S-Function (DO_v1) */
    {
      SimStruct *rts = DO_model_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = DO_model_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = DO_model_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = DO_model_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &DO_model_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, DO_model_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &DO_model_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &DO_model_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &DO_model_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &DO_model_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &DO_model_B.SFunction));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "DO_model/S-Function");
      ssSetRTModel(rts,DO_model_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &DO_model_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 1);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)DO_model_P.SFunction_P1_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &DO_model_DW.SFunction_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &DO_model_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &DO_model_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &DO_model_DW.SFunction_IWORK);
      }

      /* registration */
      DO_v1(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  DO_model_M->Sizes.numContStates = (0);/* Number of continuous states */
  DO_model_M->Sizes.numY = (0);        /* Number of model outputs */
  DO_model_M->Sizes.numU = (0);        /* Number of model inputs */
  DO_model_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  DO_model_M->Sizes.numSampTimes = (2);/* Number of sample times */
  DO_model_M->Sizes.numBlocks = (1);   /* Number of blocks */
  DO_model_M->Sizes.numBlockIO = (1);  /* Number of block outputs */
  DO_model_M->Sizes.numBlockPrms = (3);/* Sum of parameter "widths" */
  return DO_model_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
