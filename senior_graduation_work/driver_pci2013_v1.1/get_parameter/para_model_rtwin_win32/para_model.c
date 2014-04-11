/*
 * para_model.c
 *
 * Code generation for model "para_model".
 *
 * Model version              : 1.20
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Wed Apr 02 14:53:21 2014
 *
 * Target selection: rtwin.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "para_model.h"
#include "para_model_private.h"
#include "para_model_dt.h"

/* list of Real-Time Windows Target timers */
const int RTWinTimerCount = 1;
const double RTWinTimers[2] = {
  0.1, 0.0,
};

/* Block signals (auto storage) */
B_para_model_T para_model_B;

/* Block states (auto storage) */
DW_para_model_T para_model_DW;

/* Real-time model */
RT_MODEL_para_model_T para_model_M_;
RT_MODEL_para_model_T *const para_model_M = &para_model_M_;

/* Model output function */
void para_model_output(void)
{
  /* Level2 S-Function Block: '<Root>/Get_Parameter ' (get_para) */
  {
    SimStruct *rts = para_model_M->childSfunctions[0];
    sfcnOutputs(rts, 0);
  }
}

/* Model update function */
void para_model_update(void)
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
  if (!(++para_model_M->Timing.clockTick0)) {
    ++para_model_M->Timing.clockTickH0;
  }

  para_model_M->Timing.t[0] = para_model_M->Timing.clockTick0 *
    para_model_M->Timing.stepSize0 + para_model_M->Timing.clockTickH0 *
    para_model_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void para_model_initialize(void)
{
  /* Level2 S-Function Block: '<Root>/Get_Parameter ' (get_para) */
  {
    SimStruct *rts = para_model_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Model terminate function */
void para_model_terminate(void)
{
  /* Level2 S-Function Block: '<Root>/Get_Parameter ' (get_para) */
  {
    SimStruct *rts = para_model_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  para_model_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  para_model_update();
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
  para_model_initialize();
}

void MdlTerminate(void)
{
  para_model_terminate();
}

/* Registration function */
RT_MODEL_para_model_T *para_model(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)para_model_M, 0,
                sizeof(RT_MODEL_para_model_T));
  rtsiSetSolverName(&para_model_M->solverInfo,"FixedStepDiscrete");
  para_model_M->solverInfoPtr = (&para_model_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = para_model_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    para_model_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    para_model_M->Timing.sampleTimes = (&para_model_M->Timing.sampleTimesArray[0]);
    para_model_M->Timing.offsetTimes = (&para_model_M->Timing.offsetTimesArray[0]);

    /* task periods */
    para_model_M->Timing.sampleTimes[0] = (0.1);

    /* task offsets */
    para_model_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(para_model_M, &para_model_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = para_model_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    para_model_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(para_model_M, 30.0);
  para_model_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  para_model_M->Sizes.checksums[0] = (986548186U);
  para_model_M->Sizes.checksums[1] = (2593099396U);
  para_model_M->Sizes.checksums[2] = (4051623228U);
  para_model_M->Sizes.checksums[3] = (1517723622U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    para_model_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(para_model_M->extModeInfo,
      &para_model_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(para_model_M->extModeInfo, para_model_M->Sizes.checksums);
    rteiSetTPtr(para_model_M->extModeInfo, rtmGetTPtr(para_model_M));
  }

  para_model_M->solverInfoPtr = (&para_model_M->solverInfo);
  para_model_M->Timing.stepSize = (0.1);
  rtsiSetFixedStepSize(&para_model_M->solverInfo, 0.1);
  rtsiSetSolverMode(&para_model_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  para_model_M->ModelData.blockIO = ((void *) &para_model_B);
  (void) memset(((void *) &para_model_B), 0,
                sizeof(B_para_model_T));

  /* parameters */
  para_model_M->ModelData.defaultParam = ((real_T *)&para_model_P);

  /* states (dwork) */
  para_model_M->ModelData.dwork = ((void *) &para_model_DW);
  (void) memset((void *)&para_model_DW, 0,
                sizeof(DW_para_model_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    para_model_M->SpecialInfo.mappingInfo = (&dtInfo);
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
    RTWSfcnInfo *sfcnInfo = &para_model_M->NonInlinedSFcns.sfcnInfo;
    para_model_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(para_model_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &para_model_M->Sizes.numSampTimes);
    para_model_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(para_model_M)[0]);
    rtssSetTPtrPtr(sfcnInfo,para_model_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(para_model_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(para_model_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(para_model_M));
    rtssSetStepSizePtr(sfcnInfo, &para_model_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(para_model_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &para_model_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &para_model_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &para_model_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &para_model_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &para_model_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &para_model_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &para_model_M->solverInfoPtr);
  }

  para_model_M->Sizes.numSFcns = (1);

  /* register each child */
  {
    (void) memset((void *)&para_model_M->NonInlinedSFcns.childSFunctions[0], 0,
                  1*sizeof(SimStruct));
    para_model_M->childSfunctions =
      (&para_model_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    para_model_M->childSfunctions[0] =
      (&para_model_M->NonInlinedSFcns.childSFunctions[0]);

    /* Level2 S-Function Block: para_model/<Root>/Get_Parameter  (get_para) */
    {
      SimStruct *rts = para_model_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = para_model_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = para_model_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = para_model_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &para_model_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, para_model_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &para_model_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &para_model_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &para_model_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &para_model_M->NonInlinedSFcns.Sfcn0.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &para_model_B.Get_Parameter));
        }
      }

      /* path info */
      ssSetModelName(rts, "Get_Parameter\n");
      ssSetPath(rts, "para_model/Get_Parameter ");
      ssSetRTModel(rts,para_model_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &para_model_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 3);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)para_model_P.Get_Parameter_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)para_model_P.Get_Parameter_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)para_model_P.Get_Parameter_P3_Size);
      }

      /* work vectors */
      ssSetRWork(rts, (real_T *) &para_model_DW.Get_Parameter_RWORK[0]);
      ssSetIWork(rts, (int_T *) &para_model_DW.Get_Parameter_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &para_model_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &para_model_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* RWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_DOUBLE);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &para_model_DW.Get_Parameter_RWORK[0]);

        /* IWORK */
        ssSetDWorkWidth(rts, 1, 2);
        ssSetDWorkDataType(rts, 1,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &para_model_DW.Get_Parameter_IWORK[0]);
      }

      /* registration */
      get_para(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.1);
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
  para_model_M->Sizes.numContStates = (0);/* Number of continuous states */
  para_model_M->Sizes.numY = (0);      /* Number of model outputs */
  para_model_M->Sizes.numU = (0);      /* Number of model inputs */
  para_model_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  para_model_M->Sizes.numSampTimes = (1);/* Number of sample times */
  para_model_M->Sizes.numBlocks = (1); /* Number of blocks */
  para_model_M->Sizes.numBlockIO = (1);/* Number of block outputs */
  para_model_M->Sizes.numBlockPrms = (9);/* Sum of parameter "widths" */
  return para_model_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
