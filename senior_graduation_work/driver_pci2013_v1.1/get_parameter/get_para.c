/*
 * sfuntmpl_basic.c: Basic 'C' template for a level 2 S-function.
 *
 * Copyright 1990-2013 The MathWorks, Inc.
 */


/*
 * You must specify the S_FUNCTION_NAME as the name of your S-function
 * (i.e. replace sfuntmpl_basic with the name of your S-function).
 */

#define S_FUNCTION_NAME  get_para
#define S_FUNCTION_LEVEL 2

#define NUMBER_OF_ARGS 3

#define CHANNEL_INDEX 0
#define CHANNEL_ARG(S) ssGetSFcnParam(S,CHANNEL_INDEX)

#define RANGE_INDEX 1
#define RANGE_ARG(S) ssGetSFcnParam(S,RANGE_INDEX)

#define SAMPLE_TIME_INDEX 2
#define SAMPLE_TIME_ARG(S) ssGetSFcnParam(S,SAMPLE_TIME_INDEX)

#define NO_I_WORKS 2	//int work vector numbers
#define CHANNELS_I_IND 0  //channel vector index
#define BASE_ADDR_I_IND 1 //base address vector index

#define NO_R_WORKS 2  //double work vector numbers
#define GAIN_R_IND 0  // A/D gain index
#define OFFSET_R_IND 1	//offset for different range
static char msg[256];
/*
 * Need to include simstruc.h for the definition of the SimStruct and
 * its associated macro definitions.
 */
#include "simstruc.h"
#include "c_tool.c"

static void mdlInitializeSizes(SimStruct *S)
{
	uint_T nChannels;
	int_T i;
    ssSetNumSFcnParams(S, NUMBER_OF_ARGS);  /* Number of expected parameters */
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        /* Return if number of expected != number of actual parameters */
        return;
    }

    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);
	//No INPUT!
	if (!ssSetNumInputPorts(S,0)) return;

	//set output width to 1
	nChannels=(uint_T)mxGetN(CHANNEL_ARG(S));
    if (!ssSetNumOutputPorts(S,nChannels)) return;
	for(i=0;i<nChannels;i++)
	{
		ssSetOutputPortWidth(S, i, 1);
	}
    ssSetNumSampleTimes(S, 1);
	
    ssSetNumRWork(S, NO_R_WORKS);
    ssSetNumIWork(S, NO_I_WORKS);
    ssSetNumPWork(S, 0);
	
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);
	
	for(i=0;i<NUMBER_OF_ARGS;i++)
	{
		ssSetSFcnParamTunable(S, i,SS_PRM_NOT_TUNABLE);
	}
	
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
	int_T nChannels=(uint_T)mxGetN(CHANNEL_ARG(S));
	double Ts=*mxGetPr(SAMPLE_TIME_ARG(S));
	int range =(int_T) *mxGetPr(RANGE_ARG(S));
	const int_T lnr_base=0x925d5000;//0x925d5000,change after restarted;
	volatile uint32_T *destiny_addr;
	int_T i,j,channel;
	
	uint_T result,bus,device;
	const uint_T vendorID=0x11e3;
	const uint_T DeviceID=0x2013;

	PCIInfo content;
	PCIInfo* info=&content;
	
	// unsigned int phscl_addr,lnr_addr;
	
	//phscl_to_lnr
	// unsigned int *pAddr;
    // unsigned int *PageDirectoryEntry;
    // unsigned int *PageTableEntry;
    // unsigned int PDE,PTE;
    // unsigned int lnr_addr=0;
	// unsigned int p_addr;
	
	//specify vendorID and DeviceID here
	
	
	result=searchPCIDevice(vendorID,DeviceID,info);
	printf("%d\n",result);
	
	printf("The PCI device bus number is %d\n",info->bus);
	printf("The PCI device device number is %d\n",info->device);
	
	PhsclBaseAddr(info);
	printf("The physical base addr is 0x%x\n",info->addr[0]);
	
	// phscl_addr=info->addr[0];
	// lnr_addr=phscl_to_lnr(phscl_addr);
	// unsigned int *PDE= (unsigned int *)0xc0300000;
	// printf("0x%x\n",*PDE);
	// printf("The linear base addr is %d\n",lnr_addr);
	
	ssSetIWorkValue(S,CHANNELS_I_IND,nChannels);
	ssSetIWorkValue(S,BASE_ADDR_I_IND,lnr_base);
	
	switch(range)
	{
		case 1://+/-5V
			ssSetRWorkValue(S,GAIN_R_IND,10.0/4096.0);
			ssSetRWorkValue(S,OFFSET_R_IND,-5.0);
			break;
		case 2://+/-10V
			ssSetRWorkValue(S,GAIN_R_IND,20.0/4096.0);
			ssSetRWorkValue(S,OFFSET_R_IND,-10.0);
			break;
		case 3://0-10V
			ssSetRWorkValue(S,GAIN_R_IND,10.0/4096.0);
			ssSetRWorkValue(S,OFFSET_R_IND,0.0);
			break;
		default:
			sprintf(msg,"Range must between 1 to 3");
			ssSetErrorStatus(S,msg);
		return;
                
	}
	
	for(i=0;i<nChannels;i++)
    {
		channel = *(mxGetPr(CHANNEL_ARG(S))+i)-1;
		destiny_addr=(uint32_T *)(lnr_base+0x200+(i*0x4));
		*destiny_addr=channel;
		delay(16e-6);
    }
	
	destiny_addr=(uint32_T *)(lnr_base+0x290);//ADCNTL2
	*destiny_addr=nChannels-1;
	delay(16e-6);
	
	destiny_addr=(uint32_T *)(lnr_base+0x280);//ADCNTL1
	*destiny_addr=0xff;
	delay(16e-6);
	
	destiny_addr=(uint32_T *)(lnr_base+0x2e0);//ADCNTL7
	*destiny_addr=0;
	delay(16e-6);
	
	destiny_addr=(uint32_T *)(lnr_base+0x2d0);//ADCNTL6
	*destiny_addr=0;
	delay(16e-6);
	
	
	printf("channel used:\n");
	for(i=0;i<nChannels;i++)
	{
		channel = *(mxGetPr(CHANNEL_ARG(S))+i)-1;
		printf("%d\t",channel);
	}
	printf("\n");
	printf("Channel Number is %d\n",nChannels);
	printf("Range Selected is %d\n",range);
	printf("Sample Time is %f\n",Ts);
	
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
	int_T nChannels=ssGetIWorkValue(S,CHANNELS_I_IND);
	uint32_T lnr_base=ssGetIWorkValue(S,BASE_ADDR_I_IND);
	
	int_T i,j,channel;
	uint_T tempData;
	real_T *output,gain,offset;
	volatile uint32_T *destiny_addr;
	
	destiny_addr=(uint32_T *)(lnr_base+0x2c0);//ADCNTL5
	*destiny_addr=0x1;//start AD
	delay(60e-6);
	delay(nChannels*(120e-6));
	
	destiny_addr=(uint32_T *)(lnr_base+0x2c0);//ADCNTL5
	*destiny_addr=0x0;//stop
	delay(nChannels*(120e-6));

	for(i=0;i<nChannels;i++)
	{
		printf("%d\n",nChannels);
		destiny_addr=(uint32_T *)(lnr_base+0x2f0);//ADCNTL9
		tempData=*destiny_addr;
		delay(16e-6);
		channel=(tempData&0xf000)>>12;
		// printf("Channel read is %d\n",channel);
		output=ssGetOutputPortSignal(S,channel);
		tempData=tempData&0xfff;
		gain=ssGetRWorkValue(S,GAIN_R_IND);
		offset=ssGetRWorkValue(S,OFFSET_R_IND);
		// printf("%f,%f,%f\n",gain,offset,tempData);
		*output=(real_T)(tempData*gain+offset);
		printf("%f\n",*output);
	}
	
	destiny_addr=(uint32_T *)(lnr_base+0x2e0);//ADCNTL7
	*destiny_addr=0xfff;
	delay(16e-6);
	
	destiny_addr=(uint32_T *)(lnr_base+0x2f0);//ADCNTL8
	tempData=*destiny_addr;
	delay(16e-6);
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
	uint_T lnr_base=ssGetIWorkValue(S,BASE_ADDR_I_IND);
	uint32_T *destiny_addr=(uint32_T *)(lnr_base+0x2e0);
	*destiny_addr=0xfff;
	delay(16e-6);
	printf("base addr is 0x%x\n",lnr_base);
	
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
