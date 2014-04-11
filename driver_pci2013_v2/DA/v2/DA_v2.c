/*
 * sfuntmpl_basic.c: Basic 'C' template for a level 2 S-function.
 *
 * Copyright 1990-2013 The MathWorks, Inc.
 */


/*
 * You must specify the S_FUNCTION_NAME as the name of your S-function
 * (i.e. replace sfuntmpl_basic with the name of your S-function).
 */

#define S_FUNCTION_NAME  DA_v2
#define S_FUNCTION_LEVEL 2

#define NUMBER_OF_ARGS 4//channel,Ts,volt,range

#define CHANNEL_INDEX 0
#define CHANNEL_ARG(S) ssGetSFcnParam(S,CHANNEL_INDEX)

#define SAMPLE_TIME_INDEX 1
#define SAMPLE_TIME_ARG(S) ssGetSFcnParam(S,SAMPLE_TIME_INDEX)

#define VOLT_VALUE_INDEX 2
#define VOLT_VALUE_ARG(S) ssGetSFcnParam(S,VOLT_VALUE_INDEX)

#define RANGE_INDEX 3
#define RANGE_ARG(S) ssGetSFcnParam(S,RANGE_INDEX)


#define NO_I_WORKS 2		//int work vector numbers
#define nDAData_I_IND 0  	//nDAData,16bits
#define LNR_BASE_I_IND 1 	//lnr_base

#include "simstruc.h"
#include "c_tool.c"

static char msg[256];

static uint32_T reset_port[2]={0x520,0x560};
static uint32_T data_port[2]={0x500,0x540};

static void mdlInitializeSizes(SimStruct *S)
{
	int_T i;
	
    ssSetNumSFcnParams(S, NUMBER_OF_ARGS);  /* Number of expected parameters */
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        /* Return if number of expected != number of actual parameters */
        return;
    }

    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

	// DA only has input ports,only one channel at a time
	if (!ssSetNumInputPorts(S,1)) return;
	
	ssSetInputPortWidth(S,0,1);
	
    ssSetNumSampleTimes(S, 1);
    ssSetInputPortRequiredContiguous(S, 0, true); /*direct input signal access*/
    /*
     * Set direct feedthrough flag (1=yes, 0=no).
     * A port has direct feedthrough if the input is used in either
     * the mdlOutputs or mdlGetTimeOfNextVarHit functions.
     */
    ssSetInputPortDirectFeedThrough(S, 0, 1);
	
	//DA has no output
    if (!ssSetNumOutputPorts(S, 0)) return;
    // ssSetOutputPortWidth(S, 0, 1);

    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
	
    ssSetNumIWork(S, NO_I_WORKS);
    
	ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    /* Specify the sim state compliance to be same as a built-in block */
    ssSetSimStateCompliance(S, USE_DEFAULT_SIM_STATE);

    ssSetOptions(S, SS_OPTION_PLACE_ASAP);
}



/* Function: mdlInitializeSampleTimes =========================================
 * Abstract:
 *    This function is used to specify the sample time(s) for your
 *    S-function. You must register the same number of sample times as
 *    specified in ssSetNumSampleTimes.
 */
static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, *mxGetPr(SAMPLE_TIME_ARG(S)));
    ssSetOffsetTime(S, 0, 0.0);

}




#define MDL_START  /* Change to #undef to remove function */
#if defined(MDL_START) 
  /* Function: mdlStart =======================================================
   * Abstract:
   *    This function is called once at start of model execution. If you
   *    have states that should be initialized once, this is the place
   *    to do it.
   */
  static void mdlStart(SimStruct *S)
  {
#ifndef MATLAB_MEX_FILE
	uint32_T lnr_base=0x929d5000;//0x921d5000,0x923d5000,0x925d5000,0x927d5000,0x929d5000,change after restarted
	real_T volt=*mxGetPr(VOLT_VALUE_ARG(S));//voltage we want
	
	volatile uint32_T *destiny_addr;
	
	int_T sign=1;
	int32_T nDAData,range;//nDAData is original code write to DA board
	
	// uint_T nChannels=ssGetIWorkValue(S,CHANNELS_I_IND);
    uint_T channel,i;
	channel = *mxGetPr(CHANNEL_ARG(S));
	range = *mxGetPr(RANGE_ARG(S));
	
	// ssSetIWorkValue(S,LNR_BASE_I_IND,lnr_base);
	
	printf("Channel selected is %d\n",channel);
	printf("Input value is %fV\n",volt);
	printf("Range is %d\n",range);
	if(volt<0)
	{
		sign=-1;
		volt = volt*(-1);
	}
	volt = volt*1000;//nDAData deal with mV,input volt is V
	switch(range)
	{
		case 1://+/-5
			nDAData=((int32_T)(volt/(10000.00/4096)))*sign+2048;
			break;
		case 2://+/-10
			nDAData=((int32_T)(volt/(20000.00/4096)))*sign+2048;
			break;
		case 3://0~5
			nDAData=(int32_T)(volt/(5000.00/4096));
			break;
		case 4://0~10
			nDAData=(int32_T)(volt/(10000.00/4096));
			break;
		default:
			sprintf(msg,"Range must be 1 or 2!");
			ssSetErrorStatus(S,msg);
	}
	nDAData=(nDAData>4095)?4095:nDAData;
	nDAData=(nDAData<0)?0:nDAData;
	
	// ssSetIWorkValue(S,nDAData_I_IND,nDAData);
	printf("nDAData is 0x%x\n",nDAData);
	
	// for(i=0;i<nChannels;i++)
	// {
		// channel=*(mxGetPr(CHANNEL_ARG(S))+i)-1;
		// destiny_addr=(uint32_T *)(lnr_base+reset_port[channel]);
		// printf("channel selected is %d\n",channel);
		// printf("destiny_addr in mdlstart is 0x%x\n",destiny_addr);
		// *destiny_addr=0x1;//reset DA FIFO
		// delay(16e-6);
		// delay(60e-6);
		
	// }
	
	
	
	
	
#endif 
  }
#endif /*  MDL_START */



/* Function: mdlOutputs =======================================================
 * Abstract:
 *    In this function, you compute the outputs of your S-function
 *    block.
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
#ifndef MATLAB_MEX_FILE

	// uint32_T lnr_base = ssGetIWorkValue(S,LNR_BASE_I_IND);;//change after restarted
	// int32_T nDAData = ssGetIWorkValue(S,nDAData_I_IND);
	// uint_T nChannels=ssGetIWorkValue(S,CHANNELS_I_IND);
	// volatile uint32_T *destiny_addr;
	// int_T i,channel;
	

	// for(i=0;i<nChannels;i++)
	// {
		// channel=*(mxGetPr(CHANNEL_ARG(S))+i)-1;
		// destiny_addr=(uint32_T *)(lnr_base+data_port[channel]);
		// printf("lnr_base+data_port in mdlOutputs is 0x%x\n",destiny_addr);
		// *destiny_addr=nDAData;
		// delay(16e-6);
		// delay(60e-6);
	// }
	
	// printf("nDAData in mdlOutputs is 0x%x\n",nDAData);
	// printf("lnr_base+data_port=0x%x\n",lnr_base+data_port);
	
	// printf("Simulating...\n");
#endif	
}



/* Function: mdlTerminate =====================================================
 * Abstract:
 *    In this function, you should perform any actions that are necessary
 *    at the termination of a simulation.  For example, if memory was
 *    allocated in mdlStart, this is the place to free it.
 */
static void mdlTerminate(SimStruct *S)
{
#ifndef MATLAB_MEX_FILE

	// uint32_T lnr_base = ssGetIWorkValue(S,LNR_BASE_I_IND);//change after restarted
	// volatile uint32_T *destiny_addr;
	// uint_T nChannels = ssGetIWorkValue(S,CHANNELS_I_IND);
	
	// int_T i,channel;
	
	// for(i=0;i<nChannels;i++)
	// {
		// channel=*(mxGetPr(CHANNEL_ARG(S))+i)-1;
		// destiny_addr=(uint32_T *)(lnr_base+reset_port[channel]);
		// printf("lnr_base+reset_port in mdlTerminate is 0x%x\n",destiny_addr);
		// *destiny_addr=0x1;//reset DA FIFO
		// delay(16e-6);
		// delay(60e-6);
	// }
	// printf("lnr_base+reset_port in mdlTerminate is 0x%x\n",lnr_base+reset_port);
	
	printf("Simulation Ends!\n");
#endif	
}


/*=============================*
 * Required S-function trailer *
 *=============================*/

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
