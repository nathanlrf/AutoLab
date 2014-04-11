/*
 * DI_model.c
 *
 * Code generation for model "DI_model".
 *
 * Model version              : 1.3
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Wed Apr 09 15:33:14 2014
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "DI_model.h"
#include "DI_model_private.h"
#include "DI_model_dt.h"

/* list of Real-Time Windows Target timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.01, 0.0,
};

const real_T DI_model_RGND = 0.0;      /* real_T ground */

/* Real-time model */
RT_MODEL_DI_model_T DI_model_M_;
RT_MODEL_DI_model_T *const DI_model_M = &DI_model_M_;

/* Model output function */
void DI_model_output(void)
{
  /* Level2 S-Function Block: '<Root>/S-Function' (DI_v1) */
  {
    SimStruct *rts = DI_model_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }
}

/* Model update function */
void DI_model_update(void)
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
  if (!(++DI_model_M->Timing.clockTick0)) {
    ++DI_model_M->Timing.clockTickH0;
  }

  DI_model_M->Timing.t[0] = DI_model_M->Timing.clockTick0 *
    DI_model_M->Timing.stepSize0 + DI_model_M->Timing.clockTickH0 *
    DI_model_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++DI_model_M->Timing.clockTick1)) {
      ++DI_model_M->Timing.clockTickH1;
    }

    DI_model_M->Timing.t[1] = DI_model_M->Timing.clockTick1 *
      DI_model_M->Timing.stepSize1 + DI_model_M->Timing.clockTickH1 *
      DI_model_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void DI_model_initialize(void)
{
  /* Level2 S-Function Block: '<Root>/S-Function' (DI_v1) */
  {
    SimStruct *rts = DI_model_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void DI_model_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/S-Function' (DI_v1) */
  {
    SimStruct *rts = DI_model_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  DI_model_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  DI_model_update();
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
  DI_model_initialize();
}

void MdlTerminate(void)
{
  DI_model_terminate();
}

/* Registration function */
RT_MODEL_DI_model_T *DI_model(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)DI_model_M, 0,
                sizeof(RT_MODEL_DI_model_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&DI_model_M->solverInfo,
                          &DI_model_M->Timing.simTimeStep);
    rtsiSetTPtr(&DI_model_M->solverInfo, &rtmGetTPtr(DI_model_M));
    rtsiSetStepSizePtr(&DI_model_M->solverInfo, &DI_model_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&DI_model_M->solverInfo, (&rtmGetErrorStatus
      (DI_model_M)));
    rtsiSetRTModelPtr(&DI_model_M->solverInfo, DI_model_M);
  }

  rtsiSetSimTimeStep(&DI_model_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&DI_model_M->solverInfo,"FixedStepDiscrete");
  DI_model_M->solverInfoPtr = (&DI_model_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = DI_model_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    DI_model_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    DI_model_M->Timing.sampleTimes = (&DI_model_M->Timing.sampleTimesArray[0]);
    DI_model_M->Timing.offsetTimes = (&DI_model_M->Timing.offsetTimesArray[0]);

    /* task periods */
    DI_model_M->Timing.sampleTimes[0] = (0.0);
    DI_model_M->Timing.sampleTimes[1] = (0.01);

    /* task offsets */
    DI_model_M->Timing.offsetTimes[0] = (0.0);
    DI_model_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(DI_model_M, &DI_model_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = DI_model_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    DI_model_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(DI_model_M, 30.0);
  DI_model_M->Timing.stepSize0 = 0.01;
  DI_model_M->Timing.stepSize1 = 0.01;

  /* External mode info */
  DI_model_M->Sizes.checksums[0] = (943881189U);
  DI_model_M->Sizes.checksums[1] = (2376373844U);
  DI_model_M->Sizes.checksums[2] = (1356612486U);
  DI_model_M->Sizes.checksums[3] = (687118842U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    DI_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DI_model_M->extModeInfo,
      &DI_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DI_model_M->extModeInfo, DI_model_M->Sizes.checksums);
    rteiSetTPtr(DI_model_M->extModeInfo, rtmGetTPtr(DI_model_M));
  }

  DI_model_M->solverInfoPtr = (&DI_model_M->solverInfo);
  DI_model_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&DI_model_M->solverInfo, 0.01);
  rtsiSetSolverMode(&DI_model_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    DI_model_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 14;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];
  }

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &DI_model_M->NonInlinedSFcns.sfcnInfo;
    DI_model_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(DI_model_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &DI_model_M->Sizes.numSampTimes);
    DI_model_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(DI_model_M)[0]);
    DI_model_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(DI_model_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,DI_model_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(DI_model_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(DI_model_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(DI_model_M));
    rtssSetStepSizePtr(sfcnInfo, &DI_model_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(DI_model_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &DI_model_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &DI_model_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &DI_model_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &DI_model_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &DI_model_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &DI_model_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &DI_model_M->solverInfoPtr);
  }

  DI_model_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&DI_model_M->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    DI_model_M->childSfunctions =
      (&DI_model_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    DI_model_M->childSfunctions[0] =
      (&DI_model_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: DI_model/<Root>/S-Function (DI_v1) */
    {
      SimStruct *rts = DI_model_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = DI_model_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = DI_model_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = DI_model_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &DI_model_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, DI_model_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &DI_model_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &DI_model_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &DI_model_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &DI_model_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, (real_T*)&DI_model_RGND);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "DI_model/S-Function");
      ssSetRTModel(rts,DI_model_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      DI_v1(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }
  }

  /* Initialize Sizes */
  DI_model_M->Sizes.numContStates = (0);/* Number of continuous states */
  DI_model_M->Sizes.numY = (0);        /* Number of model outputs */
  DI_model_M->Sizes.numU = (0);        /* Number of model inputs */
  DI_model_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  DI_model_M->Sizes.numSampTimes = (2);/* Number of sample times */
  DI_model_M->Sizes.numBlocks = (1);   /* Number of blocks */
  return DI_model_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
