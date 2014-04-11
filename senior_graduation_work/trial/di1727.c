#define S_FUNCTION_LEVEL 2
#undef S_FUNCTION_NAME
#define S_FUNCTION_NAME di1727

#include <stddef.h>
#include <stdlib.h>

#include "simstruc.h"

#ifdef MATALB_MEX_FILE
#include "mex.h"
#else
#include <windows.h>
//#include "xpcimports.h"
#endif

#define NUM_PARAMS (2)
#define CHANNEL_ARG (ssGetSFcnParam(S,0))
#define SAMPLE_TIME_PARAM (ssGetSFcnParam(S,1))

#define BASE ((uint_T)mxGetPr(BASE_ADDRESS_ARG)[0])
#define SAMPLE_TIME ((real_T)mxGetPr(SAMPLE_TIME_PARAM)[0])

#define NO_I_WORKS (2)
#define DIN_LOW_I_IND (0)
#define DIN_HIGH_I_INDD (1)

static char_Tmsg[256];

//s_function methods

static void mdlCheckParameters(SimStruct *S)
{
	
}

static void mdlInitializSizes(SimStruct *S)
{
	uint_T i;
	
	#ifndef MATLAB_MEX_FILE
	#include "io_xpcimport.c"
	#endif
	
	ssSetNumSFcnParams(S,NUM_PARAMS);
	if(ssGetNumSFcnParams(S)==ssGetSFcnParamsCount(S))
	{
		mdlCheckParameters(S);
		if(ssGetErrorStatus(S)!= NULL)
		{
			return;
		}
	}
	else
	{
		return;
	}
	
	ssSetNumContStates(S,0);
	ssSetDiscStates(S,0);
	
	if(!ssSetNumInputPorts(S,0))
	{
		return;
	}
	if(!ssSetNumOutputPorts(S,mxGetNumberOfElements(CHANNEL_ARG)))
	{
		return;
	}
	for(i=0;i<mxGetNumberOfElements(CHANNEL_ARG);i++)
	{
		ssSetOutputPortWidth(S,i,1);
	}
	
	ssSetSampleTimes(S,1);
	ssSetNumWork(S,NO_I_WORKS);
	
	ssSetNumModes(S,0);
	ssSetNumNosampledZCs(S,0);
	
	ssSetSFcnParamNotTunable(S,0);
	ssSetSFcnParamNotTunable(S,1);
	ssSetSFcnParamNotTunable(S,2);
	ssSetSFcnParamNotTunable(S,3);
	
	ssSetOptions(S,SS_OPTION_DISALLOW_CONSTANT_SAMPLE_TIME|SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
	ssSetSampleTime(S,0,SAMPLE_TIME);
	ssSetOffsetTime(S,0,SAMPLE_OFFSET);
}

#define MDL_START
static void mdlStart(SimStruct *S)
{
	#ifndef MATLAB_MEX_FILE
	uint_T din_low;
	uint_T din_high;
	PCIDeviceInfo pciinfo;
	char devName[20]="di1727";
	
	if(rl32eGetPCIInfo((unsigned short)Vendor_ID,(unsigned short)Device_ID,&pciinfo))
	{
		sprintf(msg,"%s: board not found",devName);
		ssSetErrorStatus(S,msg);
		return;
	
	}
	
	BASE=(uint_T)pciinfo.BaseAddress[2];
	din_low=BASE+1;
	din_high=BASE+0;
	ssSetIWorkVaules(S,DIN_LOW_I_IND,din_low);
	ssSetIWorkVaules(S,DIN_HIGH_I_IND,din_HIGH);
	#endif
}

static void mdlOutputs(SimStruct *S,int_T tid)
{
	#ifndef MATLAB_MEX_FILE
	uint_T i;
	uint_T baseAddr=BASE;
	real_T *y;
	uint_T tempPortData;
	uint_T din_low;
	uint_T din_high;
	
	din_low=ssGetIWorkValue(S,DIN_LOW_I_IND);
	din_high=ssGetIWorkValue(S,DIN_HIGH_I_IND);
	
	tempPortData=(rl32eInpB((unsigned short)din_high)<<8)|(rl32eInpB((unsigned short)din_low)&0xff);
	for(i=0;i<mxGetNumberOfElements(CHANNEL_ARG);i++)
	{
		y=ssGetOutputPortSignal(S,i);
		y[0]=(tempPortData>>(((short)mxGetPr(CHANNEL_ARG)[i])-1))&0x01;
	}
	#endif
}

static void mdlTerminate(SimStruct *S)
{
	#ifndef MALTAB_MEX_FILE
	#endif
}

//required S_func trailer

#ifdef MATALB_MEX_FILE
#include "simulink.c"
#else
#include "cg_sfun.h"
#endif