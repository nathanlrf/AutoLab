/*
 * AD_model.c
 *
 * Code generation for model "AD_model".
 *
 * Model version              : 1.33
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Fri Apr 11 17:00:00 2014
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "AD_model.h"
#include "AD_model_private.h"
#include "AD_model_dt.h"

/* list of Real-Time Windows Target timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.02, 0.0,
};

/* Block signals (auto storage) */
B_AD_model_T AD_model_B;

/* Block states (auto storage) */
DW_AD_model_T AD_model_DW;

/* Real-time model */
RT_MODEL_AD_model_T AD_model_M_;
RT_MODEL_AD_model_T *const AD_model_M = &AD_model_M_;

/* Model output function */
void AD_model_output(void)
{
  /* Level2 S-Function Block: '<Root>/Get_Parameter ' (AD_v2) */
  {
    SimStruct *rts = AD_model_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }
}

/* Model update function */
void AD_model_update(void)
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
  if (!(++AD_model_M->Timing.clockTick0)) {
    ++AD_model_M->Timing.clockTickH0;
  }

  AD_model_M->Timing.t[0] = AD_model_M->Timing.clockTick0 *
    AD_model_M->Timing.stepSize0 + AD_model_M->Timing.clockTickH0 *
    AD_model_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void AD_model_initialize(void)
{
  /* Level2 S-Function Block: '<Root>/Get_Parameter ' (AD_v2) */
  {
    SimStruct *rts = AD_model_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void AD_model_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/Get_Parameter ' (AD_v2) */
  {
    SimStruct *rts = AD_model_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  AD_model_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  AD_model_update();
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
  AD_model_initialize();
}

void MdlTerminate(void)
{
  AD_model_terminate();
}

/* Registration function */
RT_MODEL_AD_model_T *AD_model(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)AD_model_M, 0,
                sizeof(RT_MODEL_AD_model_T));
  rtsiSetSolverName(&AD_model_M->solverInfo,"FixedStepDiscrete");
  AD_model_M->solverInfoPtr = (&AD_model_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = AD_model_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    AD_model_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    AD_model_M->Timing.sampleTimes = (&AD_model_M->Timing.sampleTimesArray[0]);
    AD_model_M->Timing.offsetTimes = (&AD_model_M->Timing.offsetTimesArray[0]);

    /* task periods */
    AD_model_M->Timing.sampleTimes[0] = (0.02);

    /* task offsets */
    AD_model_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(AD_model_M, &AD_model_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = AD_model_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    AD_model_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(AD_model_M, 10.0);
  AD_model_M->Timing.stepSize0 = 0.02;

  /* External mode info */
  AD_model_M->Sizes.checksums[0] = (997782705U);
  AD_model_M->Sizes.checksums[1] = (3883225624U);
  AD_model_M->Sizes.checksums[2] = (2680686323U);
  AD_model_M->Sizes.checksums[3] = (2220993960U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    AD_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(AD_model_M->extModeInfo,
      &AD_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(AD_model_M->extModeInfo, AD_model_M->Sizes.checksums);
    rteiSetTPtr(AD_model_M->extModeInfo, rtmGetTPtr(AD_model_M));
  }

  AD_model_M->solverInfoPtr = (&AD_model_M->solverInfo);
  AD_model_M->Timing.stepSize = (0.02);
  rtsiSetFixedStepSize(&AD_model_M->solverInfo, 0.02);
  rtsiSetSolverMode(&AD_model_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  AD_model_M->ModelData.blockIO = ((void *) &AD_model_B);
  (void) memset(((void *) &AD_model_B), 0,
                sizeof(B_AD_model_T));

  /* parameters */
  AD_model_M->ModelData.defaultParam = ((real_T *)&AD_model_P);

  /* states (dwork) */
  AD_model_M->ModelData.dwork = ((void *) &AD_model_DW);
  (void) memset((void *)&AD_model_DW, 0,
                sizeof(DW_AD_model_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    AD_model_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &AD_model_M->NonInlinedSFcns.sfcnInfo;
    AD_model_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(AD_model_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &AD_model_M->Sizes.numSampTimes);
    AD_model_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(AD_model_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,AD_model_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(AD_model_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(AD_model_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(AD_model_M));
    rtssSetStepSizePtr(sfcnInfo, &AD_model_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(AD_model_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &AD_model_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &AD_model_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &AD_model_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &AD_model_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &AD_model_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &AD_model_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &AD_model_M->solverInfoPtr);
  }

  AD_model_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&AD_model_M->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    AD_model_M->childSfunctions =
      (&AD_model_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    AD_model_M->childSfunctions[0] =
      (&AD_model_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: AD_model/<Root>/Get_Parameter  (AD_v2) */
    {
      SimStruct *rts = AD_model_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = AD_model_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = AD_model_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = AD_model_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &AD_model_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, AD_model_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &AD_model_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &AD_model_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &AD_model_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &AD_model_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 3);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &AD_model_B.Get_Parameter_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &AD_model_B.Get_Parameter_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((real_T *) &AD_model_B.Get_Parameter_o3));
        }
      }

      /* path info */
      ssSetModelName(rts, "Get_Parameter\n");
      ssSetPath(rts, "AD_model/Get_Parameter ");
      ssSetRTModel(rts,AD_model_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &AD_model_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)AD_model_P.Get_Parameter_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)AD_model_P.Get_Parameter_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)AD_model_P.Get_Parameter_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &AD_model_DW.Get_Parameter_RWORK[0]);
      ssSetIWork(rts, (int_T *) &AD_model_DW.Get_Parameter_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &AD_model_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &AD_model_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &AD_model_DW.Get_Parameter_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &AD_model_DW.Get_Parameter_IWORK[0]);
      }

      /* registration */
      AD_v2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.02);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 0);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  AD_model_M->Sizes.numContStates = (0);/* Number of continuous states */
  AD_model_M->Sizes.numY = (0);        /* Number of model outputs */
  AD_model_M->Sizes.numU = (0);        /* Number of model inputs */
  AD_model_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  AD_model_M->Sizes.numSampTimes = (1);/* Number of sample times */
  AD_model_M->Sizes.numBlocks = (1);   /* Number of blocks */
  AD_model_M->Sizes.numBlockIO = (3);  /* Number of block outputs */
  AD_model_M->Sizes.numBlockPrms = (11);/* Sum of parameter "widths" */
  return AD_model_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
