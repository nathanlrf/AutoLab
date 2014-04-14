/*
 * DA_model_v2.c
 *
 * Code generation for model "DA_model_v2".
 *
 * Model version              : 1.9
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Mon Apr 14 15:35:41 2014
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "DA_model_v2.h"
#include "DA_model_v2_private.h"
#include "DA_model_v2_dt.h"

/* list of Real-Time Windows Target timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.2, 0.0,
};

const real_T DA_model_v2_RGND = 0.0;   /* real_T ground */

/* Block states (auto storage) */
DW_DA_model_v2_T DA_model_v2_DW;

/* Real-time model */
RT_MODEL_DA_model_v2_T DA_model_v2_M_;
RT_MODEL_DA_model_v2_T *const DA_model_v2_M = &DA_model_v2_M_;

/* Model output function */
void DA_model_v2_output(void)
{
  /* Level2 S-Function Block: '<Root>/S-Function' (DA_v2) */
  {
    SimStruct *rts = DA_model_v2_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }
}

/* Model update function */
void DA_model_v2_update(void)
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
  if (!(++DA_model_v2_M->Timing.clockTick0)) {
    ++DA_model_v2_M->Timing.clockTickH0;
  }

  DA_model_v2_M->Timing.t[0] = DA_model_v2_M->Timing.clockTick0 *
    DA_model_v2_M->Timing.stepSize0 + DA_model_v2_M->Timing.clockTickH0 *
    DA_model_v2_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void DA_model_v2_initialize(void)
{
  /* Level2 S-Function Block: '<Root>/S-Function' (DA_v2) */
  {
    SimStruct *rts = DA_model_v2_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void DA_model_v2_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/S-Function' (DA_v2) */
  {
    SimStruct *rts = DA_model_v2_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  DA_model_v2_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  DA_model_v2_update();
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
  DA_model_v2_initialize();
}

void MdlTerminate(void)
{
  DA_model_v2_terminate();
}

/* Registration function */
RT_MODEL_DA_model_v2_T *DA_model_v2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)DA_model_v2_M, 0,
                sizeof(RT_MODEL_DA_model_v2_T));
  rtsiSetSolverName(&DA_model_v2_M->solverInfo,"FixedStepDiscrete");
  DA_model_v2_M->solverInfoPtr = (&DA_model_v2_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = DA_model_v2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    DA_model_v2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    DA_model_v2_M->Timing.sampleTimes = (&DA_model_v2_M->
      Timing.sampleTimesArray[0]);
    DA_model_v2_M->Timing.offsetTimes = (&DA_model_v2_M->
      Timing.offsetTimesArray[0]);

    /* task periods */
    DA_model_v2_M->Timing.sampleTimes[0] = (0.2);

    /* task offsets */
    DA_model_v2_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(DA_model_v2_M, &DA_model_v2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = DA_model_v2_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    DA_model_v2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(DA_model_v2_M, 10.0);
  DA_model_v2_M->Timing.stepSize0 = 0.2;

  /* External mode info */
  DA_model_v2_M->Sizes.checksums[0] = (2369768211U);
  DA_model_v2_M->Sizes.checksums[1] = (3156585514U);
  DA_model_v2_M->Sizes.checksums[2] = (937055251U);
  DA_model_v2_M->Sizes.checksums[3] = (1829507898U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    DA_model_v2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(DA_model_v2_M->extModeInfo,
      &DA_model_v2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(DA_model_v2_M->extModeInfo,
                        DA_model_v2_M->Sizes.checksums);
    rteiSetTPtr(DA_model_v2_M->extModeInfo, rtmGetTPtr(DA_model_v2_M));
  }

  DA_model_v2_M->solverInfoPtr = (&DA_model_v2_M->solverInfo);
  DA_model_v2_M->Timing.stepSize = (0.2);
  rtsiSetFixedStepSize(&DA_model_v2_M->solverInfo, 0.2);
  rtsiSetSolverMode(&DA_model_v2_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* parameters */
  DA_model_v2_M->ModelData.defaultParam = ((real_T *)&DA_model_v2_P);

  /* states (dwork) */
  DA_model_v2_M->ModelData.dwork = ((void *) &DA_model_v2_DW);
  (void) memset((void *)&DA_model_v2_DW, 0,
                sizeof(DW_DA_model_v2_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    DA_model_v2_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &DA_model_v2_M->NonInlinedSFcns.sfcnInfo;
    DA_model_v2_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(DA_model_v2_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &DA_model_v2_M->Sizes.numSampTimes);
    DA_model_v2_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(DA_model_v2_M)
      [0]);
    rtssSetTPtrPtr(sfcnInfo,DA_model_v2_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(DA_model_v2_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(DA_model_v2_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(DA_model_v2_M));
    rtssSetStepSizePtr(sfcnInfo, &DA_model_v2_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(DA_model_v2_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &DA_model_v2_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &DA_model_v2_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &DA_model_v2_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &DA_model_v2_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &DA_model_v2_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &DA_model_v2_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &DA_model_v2_M->solverInfoPtr);
  }

  DA_model_v2_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&DA_model_v2_M->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    DA_model_v2_M->childSfunctions =
      (&DA_model_v2_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    DA_model_v2_M->childSfunctions[0] =
      (&DA_model_v2_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: DA_model_v2/<Root>/S-Function (DA_v2) */
    {
      SimStruct *rts = DA_model_v2_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = DA_model_v2_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = DA_model_v2_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = DA_model_v2_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &DA_model_v2_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, DA_model_v2_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &DA_model_v2_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &DA_model_v2_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &DA_model_v2_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &DA_model_v2_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, (real_T*)&DA_model_v2_RGND);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "DA_model_v2/S-Function");
      ssSetRTModel(rts,DA_model_v2_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &DA_model_v2_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 4);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)DA_model_v2_P.SFunction_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)DA_model_v2_P.SFunction_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)DA_model_v2_P.SFunction_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)DA_model_v2_P.SFunction_P4_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &DA_model_v2_DW.SFunction_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &DA_model_v2_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &DA_model_v2_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &DA_model_v2_DW.SFunction_IWORK[0]);
      }

      /* registration */
      DA_v2(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.2);
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
  DA_model_v2_M->Sizes.numContStates = (0);/* Number of continuous states */
  DA_model_v2_M->Sizes.numY = (0);     /* Number of model outputs */
  DA_model_v2_M->Sizes.numU = (0);     /* Number of model inputs */
  DA_model_v2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  DA_model_v2_M->Sizes.numSampTimes = (1);/* Number of sample times */
  DA_model_v2_M->Sizes.numBlocks = (1);/* Number of blocks */
  DA_model_v2_M->Sizes.numBlockPrms = (12);/* Sum of parameter "widths" */
  return DA_model_v2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
