/*
 * sfuntmpl_basic.c: Basic 'C' template for a level 2 S-function.
 *
 * Copyright 1990-2013 The MathWorks, Inc.
 */
//=================================
//I just copy the code from paper||
//=================================

#define S_FUNCTION_NAME  driver_pci2013_v1_1
#define S_FUNCTION_LEVEL 2

#include "simstruc.h"
#include "pci_tool.h"

// #define NUMBER_OF_ARGS (5) 
// NUMBER_OF_ARGS has been changed on 2014/4/1
#define NUMBER_OF_ARGS (4)

#define CHANNEL_ARG ssGetSFcnParam(S,0)
#define RANGE_ARG ssGetSFcnParam(S,1)
#define COUPLING_ARG ssGetSFcnParam(S,2)
#define SAMP_TIME_ARG ssGetSFcnParam(S,3)
// #define SLOT_ARG ssGetSFcnParam(S,4)

#define NO_I_WORKS (2)	//int work vector numbers
#define CHANNELS_I_IND (0)  //channel vector index
#define BASE_ADDR_I_IND (1) //base address vector index
#define NO_R_WORKS (1)  //double work vector numbers
#define GAIN_R_IND (0)  //A/D calculation index

/* Error handling
 * --------------
 *
 * You should use the following technique to report errors encountered within
 * an S-function:
 *
 *       ssSetErrorStatus(S,"Error encountered due to ...");
 *       return;
 *
 * Note that the 2nd argument to ssSetErrorStatus must be persistent memory.
 * It cannot be a local variable. For example the following will cause
 * unpredictable errors:
 *
 *      mdlOutputs()
 *      {
 *         char msg[256];         {ILLEGAL: to fix use "static char msg[256];"}
 *         sprintf(msg,"Error due to %s", string);
 *         ssSetErrorStatus(S,msg);
 *         return;
 *      }
 *
 */

static void mdlInitializeSizes(SimStruct *S)
{
    int i,nChannels;
    static char msg[256];
    ssSetNumSFcnParams(S, NUMBER_OF_ARGS);  /* Number of expected parameters */
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        /* Return if number of expected != number of actual parameters */
        sprintf(msg,"Wrong Number of input arguments passed.\n%d arguments are expected\n",NUMBER_OF_ARGS);
        ssSetErrorStatus(S,msg);
        return;
    }

    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);
    
    ssSetNumInputPorts(S, 0);//there is no input 
    //if (!ssSetNumInputPorts(S, 1)) return;
    
    nChannels=(uint_T)mxGetN(CHANNEL_ARG);
   
    //if (!ssSetNumOutputPorts(S, 1)) return;
    ssSetNumOutputPorts(S,nChannels);//set number of outputs ports
    for(i=0;i<nChannels;i++)
    {
        ssSetOutputPortWidth(S, i, 1);//set width of each port to 1    
    }
    
    ssSetInputPortWidth(S, 0, 1);
    ssSetInputPortRequiredContiguous(S, 0, true); /*direct input signal access*/
    /*
     * Set direct feed through flag (1=yes, 0=no).
     * A port has direct feed through if the input is used in either
     * the mdlOutputs or mdlGetTimeOfNextVarHit functions.
     */
    ssSetInputPortDirectFeedThrough(S, 0, 1);

   

    ssSetNumSampleTimes(S, 1);//set number of sample time to 1,which means all input ports share same Ts
    
    ssSetNumRWork(S, NO_R_WORKS);//number of float in work vector
    ssSetNumIWork(S, NO_I_WORKS);//number of int in work vector
    ssSetNumPWork(S, 0);//number of pointer in work vector
    
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);//no need for pass-zero check 
    
    ssSetSFcnParamNotTunable(S,0);
    ssSetSFcnParamNotTunable(S,1);
    ssSetSFcnParamNotTunable(S,2);
    ssSetSFcnParamNotTunable(S,3);
    ssSetSFcnParamNotTunable(S,4);
    
    ssSetOptions(S,SS_OPTION_EXCEPTION_FREE_CODE|SS_OPTION_PLACE_ASAP);
    /* Specify the sim state compliance to be same as a built-in block */
    ssSetSimStateCompliance(S, USE_DEFAULT_SIM_STATE);
}

static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, mxGetPr(SAMP_TIME_ARG)[0]);
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
        int_T nChannels,range,i,channel;
        const uint_T base=0x976f7000;
        volatile uint32_T *ioaddress;
        
        //
        //These part is omitted.
        //
        ssSetIWorkValue(S,BASE_ADDR_I_IND,base);
        nChannels=(int_T)mxGetN(CHANNEL_ARG);
        ssSetIWorkValue(S,CHANNELS_I_IND,nChannels);
        range=(int_T)mxGetPr(RANGE_ARG)[0];
        switch(range){
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
        //write the channel number into corresponding register (ADCNTL0)
        for(i=0;i<nChannels;i++)
        {
            channel=(int_T)mxGetPr(CHANNEL_ARG)[i]-1;
            ioaddress=(void *)(base+0x200+(i*0x4));
            ioaddress[0]=channel;
            delay(16e-6);
        }
        
        //set the number of channels (ADCNTL2)
        ioaddress=(void *)(base+0x290);
        ioaddress[0]=nChannels-1;
        delay(16e-16);
        
        //set the frequency of A/D sampling (ADCNTL1)
        ioaddress=(void *)(base+0x280);
        ioaddress[0]=0xFF;
        delay(16e-6);
        
        //clear FIFO (ADCNTL7)
        ioaddress=(void *)(base+0x2E0);
        ioaddress[0]=0;
        delay(16e-6);
        
        //disallow A\D interrupt
        ioaddress=(void *)(base+0x2D0);
        ioaddress[0]=0;
        delay(16e-16);
        
    #endif
  }
#endif /*  MDL_START */


static void mdlOutputs(SimStruct *S, int_T tid)
{
    #ifndef MATLAB_MEX_FILE
        int_T nChannels=ssGetIWorkValue(S,CHANNELS_I_IND);
        uint_T base=ssGetIWorkValue(S,BASE_ADDR_I_IND);
        
        int_T i,j,channel;
        uint_T tempData;
        real_T *output;
        volatile uint32_T *ioaddress;
        
        //start A/D conversion (ADCNTL5)
        ioaddress=(void *)(base+0x2C0);
        ioaddress[0]=0x1;
        //wait for the start of A/D conversion
        delay(60e-6);
        //wait for the finish of all channels
        delay(nChannels*(120e-6));
        
        //end A/D conversion (ADCNTL5)
        ioaddress=(void *)(base+0x2C0);
        ioaddress[0]=0x0;
        delay(16e-6);
        
        for(i=0;i<nChannels;i++)
        {
            //read data from ADCNTL8
            ioaddress=(void *)(base+0x2F0);
            tempData=ioaddress[0];
            delay(16e-6);
            //get channel number from tempData[13][12]
            channel=(tempData&0xf000)>>12;
            output=ssGetOutputPortSignal(S,channel);
            tempData=tempData&0xfff;
            output[0]=(real_T)(tempData*ssGetRWorkValue(S,GAIN_R_IND)+ssGetRWorkValue(S,OFFSET_R_IND));
        }
        
        //clear data on FIFO (ADCNTL7)
        ioaddress=(void *)(base+0x2E0);
        ioaddress[0]=0xfff;
        delay(16e-6);
    
        //clear FIFO again (read ADCNTL8,there is "752" store in FIFO even after clear FIFO once,only on PCI2013)
        ioaddress=(void *)(base+0x2F0);
        tempData=ioaddress[0];
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
    #ifndef MATALB_MEX_FILE
        volatile uint32_T *ioaddress;
        uint_T base=ssGetIWorkValue(S,BASE_ADDR_I_IND);
        
        //clear device (write sth in ADCNTL7)
        ioaddress=(void *)(base+0x2E0);
        ioaddress[0]=0xfff;
        delay(16e-6);
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
