/*
 * sfcndemo_sfunmem.c
 *
 * Code generation for model "sfcndemo_sfunmem".
 *
 * Model version              : 1.158
 * Simulink Coder version : 8.5 (R2013b) 08-Aug-2013
 * C source code generated on : Sat Mar 15 23:36:35 2014
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#include "sfcndemo_sfunmem.h"
#include "sfcndemo_sfunmem_private.h"

/* Block signals (auto storage) */
B_sfcndemo_sfunmem_T sfcndemo_sfunmem_B;

/* Block states (auto storage) */
DW_sfcndemo_sfunmem_T sfcndemo_sfunmem_DW;

/* External outputs (root outports fed by signals with auto storage) */
ExtY_sfcndemo_sfunmem_T sfcndemo_sfunmem_Y;

/* Real-time model */
RT_MODEL_sfcndemo_sfunmem_T sfcndemo_sfunmem_M_;
RT_MODEL_sfcndemo_sfunmem_T *const sfcndemo_sfunmem_M = &sfcndemo_sfunmem_M_;

/* Model output function */
static void sfcndemo_sfunmem_output(void)
{
  /* S-Function sfunmem Block: <Root>/S-Function1 */
  sfcndemo_sfunmem_Y.Out1 =
    sfcndemo_sfunmem_DW.SFunction1_RWORK.InputAtLastUpdate;

  /* S-Function sfunmem Block: <Root>/S-Function2 */
  sfcndemo_sfunmem_Y.Out2[0] =
    sfcndemo_sfunmem_DW.SFunction2_RWORK.InputAtLastUpdate[0];
  sfcndemo_sfunmem_Y.Out2[1] =
    sfcndemo_sfunmem_DW.SFunction2_RWORK.InputAtLastUpdate[1];

  /* DiscretePulseGenerator: '<Root>/Discrete Pulse Generator' */
  sfcndemo_sfunmem_B.DiscretePulseGenerator =
    (sfcndemo_sfunmem_DW.clockTickCounter <
     sfcndemo_sfunmem_P.DiscretePulseGenerator_Duty) &&
    (sfcndemo_sfunmem_DW.clockTickCounter >= 0) ?
    sfcndemo_sfunmem_P.DiscretePulseGenerator_Amp : 0.0;
  if (sfcndemo_sfunmem_DW.clockTickCounter >=
      sfcndemo_sfunmem_P.DiscretePulseGenerator_Period - 1.0) {
    sfcndemo_sfunmem_DW.clockTickCounter = 0;
  } else {
    sfcndemo_sfunmem_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<Root>/Discrete Pulse Generator' */

  /* Sum: '<Root>/Sum' */
  sfcndemo_sfunmem_B.Sum = (sfcndemo_sfunmem_B.DiscretePulseGenerator +
    sfcndemo_sfunmem_Y.Out2[0]) + sfcndemo_sfunmem_Y.Out2[1];
}

/* Model update function */
static void sfcndemo_sfunmem_update(void)
{
  /* S-Function sfunmem Block: <Root>/S-Function1 */
  sfcndemo_sfunmem_DW.SFunction1_RWORK.InputAtLastUpdate =
    sfcndemo_sfunmem_B.DiscretePulseGenerator;

  /* S-Function sfunmem Block: <Root>/S-Function2 */
  sfcndemo_sfunmem_DW.SFunction2_RWORK.InputAtLastUpdate[0] =
    sfcndemo_sfunmem_B.DiscretePulseGenerator;
  sfcndemo_sfunmem_DW.SFunction2_RWORK.InputAtLastUpdate[1] =
    sfcndemo_sfunmem_B.Sum;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++sfcndemo_sfunmem_M->Timing.clockTick0)) {
    ++sfcndemo_sfunmem_M->Timing.clockTickH0;
  }

  sfcndemo_sfunmem_M->Timing.t[0] = sfcndemo_sfunmem_M->Timing.clockTick0 *
    sfcndemo_sfunmem_M->Timing.stepSize0 +
    sfcndemo_sfunmem_M->Timing.clockTickH0 *
    sfcndemo_sfunmem_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void sfcndemo_sfunmem_initialize(void)
{
  /* Start for DiscretePulseGenerator: '<Root>/Discrete Pulse Generator' */
  sfcndemo_sfunmem_DW.clockTickCounter = 0;
}

/* Model terminate function */
void sfcndemo_sfunmem_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  sfcndemo_sfunmem_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  sfcndemo_sfunmem_update();
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
  sfcndemo_sfunmem_initialize();
}

void MdlTerminate(void)
{
  sfcndemo_sfunmem_terminate();
}

/* Registration function */
RT_MODEL_sfcndemo_sfunmem_T *sfcndemo_sfunmem(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)sfcndemo_sfunmem_M, 0,
                sizeof(RT_MODEL_sfcndemo_sfunmem_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = sfcndemo_sfunmem_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    sfcndemo_sfunmem_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    sfcndemo_sfunmem_M->Timing.sampleTimes =
      (&sfcndemo_sfunmem_M->Timing.sampleTimesArray[0]);
    sfcndemo_sfunmem_M->Timing.offsetTimes =
      (&sfcndemo_sfunmem_M->Timing.offsetTimesArray[0]);

    /* task periods */
    sfcndemo_sfunmem_M->Timing.sampleTimes[0] = (0.01);

    /* task offsets */
    sfcndemo_sfunmem_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(sfcndemo_sfunmem_M, &sfcndemo_sfunmem_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = sfcndemo_sfunmem_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    sfcndemo_sfunmem_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(sfcndemo_sfunmem_M, 0.5);
  sfcndemo_sfunmem_M->Timing.stepSize0 = 0.01;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    sfcndemo_sfunmem_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(sfcndemo_sfunmem_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(sfcndemo_sfunmem_M->rtwLogInfo, (NULL));
    rtliSetLogT(sfcndemo_sfunmem_M->rtwLogInfo, "tout");
    rtliSetLogX(sfcndemo_sfunmem_M->rtwLogInfo, "");
    rtliSetLogXFinal(sfcndemo_sfunmem_M->rtwLogInfo, "");
    rtliSetSigLog(sfcndemo_sfunmem_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(sfcndemo_sfunmem_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(sfcndemo_sfunmem_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(sfcndemo_sfunmem_M->rtwLogInfo, 0);
    rtliSetLogDecimation(sfcndemo_sfunmem_M->rtwLogInfo, 1);

    /*
     * Set pointers to the data and signal info for each output
     */
    {
      static void * rt_LoggedOutputSignalPtrs[] = {
        &sfcndemo_sfunmem_Y.Out1,
        &sfcndemo_sfunmem_Y.Out2[0]
      };

      rtliSetLogYSignalPtrs(sfcndemo_sfunmem_M->rtwLogInfo, ((LogSignalPtrsType)
        rt_LoggedOutputSignalPtrs));
    }

    {
      static int_T rt_LoggedOutputWidths[] = {
        1,
        2
      };

      static int_T rt_LoggedOutputNumDimensions[] = {
        1,
        1
      };

      static int_T rt_LoggedOutputDimensions[] = {
        1,
        2
      };

      static boolean_T rt_LoggedOutputIsVarDims[] = {
        0,
        0
      };

      static void* rt_LoggedCurrentSignalDimensions[] = {
        (NULL),
        (NULL)
      };

      static int_T rt_LoggedCurrentSignalDimensionsSize[] = {
        4,
        4
      };

      static BuiltInDTypeId rt_LoggedOutputDataTypeIds[] = {
        SS_DOUBLE,
        SS_DOUBLE
      };

      static int_T rt_LoggedOutputComplexSignals[] = {
        0,
        0
      };

      static const char_T *rt_LoggedOutputLabels[] = {
        "",
        "" };

      static const char_T *rt_LoggedOutputBlockNames[] = {
        "sfcndemo_sfunmem/Out1",
        "sfcndemo_sfunmem/Out2" };

      static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert[] = {
        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 },

        { 0, SS_DOUBLE, SS_DOUBLE, 0, 0, 0, 1.0, 0, 0.0 }
      };

      static RTWLogSignalInfo rt_LoggedOutputSignalInfo[] = {
        {
          2,
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

      rtliSetLogYSignalInfo(sfcndemo_sfunmem_M->rtwLogInfo,
                            rt_LoggedOutputSignalInfo);

      /* set currSigDims field */
      rt_LoggedCurrentSignalDimensions[0] = &rt_LoggedOutputWidths[0];
      rt_LoggedCurrentSignalDimensions[1] = &rt_LoggedOutputWidths[1];
    }

    rtliSetLogY(sfcndemo_sfunmem_M->rtwLogInfo, "yout");
  }

  sfcndemo_sfunmem_M->solverInfoPtr = (&sfcndemo_sfunmem_M->solverInfo);
  sfcndemo_sfunmem_M->Timing.stepSize = (0.01);
  rtsiSetFixedStepSize(&sfcndemo_sfunmem_M->solverInfo, 0.01);
  rtsiSetSolverMode(&sfcndemo_sfunmem_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  sfcndemo_sfunmem_M->ModelData.blockIO = ((void *) &sfcndemo_sfunmem_B);

  {
    sfcndemo_sfunmem_B.DiscretePulseGenerator = 0.0;
    sfcndemo_sfunmem_B.Sum = 0.0;
  }

  /* parameters */
  sfcndemo_sfunmem_M->ModelData.defaultParam = ((real_T *)&sfcndemo_sfunmem_P);

  /* states (dwork) */
  sfcndemo_sfunmem_M->ModelData.dwork = ((void *) &sfcndemo_sfunmem_DW);
  (void) memset((void *)&sfcndemo_sfunmem_DW, 0,
                sizeof(DW_sfcndemo_sfunmem_T));
  sfcndemo_sfunmem_DW.SFunction1_RWORK.InputAtLastUpdate = 0.0;
  sfcndemo_sfunmem_DW.SFunction2_RWORK.InputAtLastUpdate[0] = 0.0;
  sfcndemo_sfunmem_DW.SFunction2_RWORK.InputAtLastUpdate[1] = 0.0;

  /* external outputs */
  sfcndemo_sfunmem_M->ModelData.outputs = (&sfcndemo_sfunmem_Y);
  sfcndemo_sfunmem_Y.Out1 = 0.0;
  sfcndemo_sfunmem_Y.Out2[0] = 0.0;
  sfcndemo_sfunmem_Y.Out2[1] = 0.0;

  /* Initialize Sizes */
  sfcndemo_sfunmem_M->Sizes.numContStates = (0);/* Number of continuous states */
  sfcndemo_sfunmem_M->Sizes.numY = (3);/* Number of model outputs */
  sfcndemo_sfunmem_M->Sizes.numU = (0);/* Number of model inputs */
  sfcndemo_sfunmem_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  sfcndemo_sfunmem_M->Sizes.numSampTimes = (1);/* Number of sample times */
  sfcndemo_sfunmem_M->Sizes.numBlocks = (7);/* Number of blocks */
  sfcndemo_sfunmem_M->Sizes.numBlockIO = (4);/* Number of block outputs */
  sfcndemo_sfunmem_M->Sizes.numBlockPrms = (4);/* Sum of parameter "widths" */
  return sfcndemo_sfunmem_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
