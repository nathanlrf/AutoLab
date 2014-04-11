
#define S_FUNCTION_NAME  search
#define S_FUNCTION_LEVEL 2


#include "simstruc.h"

#include "search_pci.h"


static void mdlInitializeSizes(SimStruct *S)
{
    ssSetNumSFcnParams(S, 0);  /* Number of expected parameters */
    if (ssGetNumSFcnParams(S) != ssGetSFcnParamsCount(S)) {
        /* Return if number of expected != number of actual parameters */
        return;
    }

    ssSetNumContStates(S, 0);
    ssSetNumDiscStates(S, 0);

    if (!ssSetNumInputPorts(S, 0)) return;
    // ssSetInputPortWidth(S, 0, 1);
    ssSetInputPortRequiredContiguous(S, 0, true); /*direct input signal access*/
    /*
     * Set direct feedthrough flag (1=yes, 0=no).
     * A port has direct feedthrough if the input is used in either
     * the mdlOutputs or mdlGetTimeOfNextVarHit functions.
     */
    ssSetInputPortDirectFeedThrough(S, 0, 1);

    if (!ssSetNumOutputPorts(S, 0)) return;
    // ssSetOutputPortWidth(S, 0, 1);

    ssSetNumSampleTimes(S, 1);
    ssSetNumRWork(S, 0);
    ssSetNumIWork(S, 0);
    ssSetNumPWork(S, 0);
    ssSetNumModes(S, 0);
    ssSetNumNonsampledZCs(S, 0);

    /* Specify the sim state compliance to be same as a built-in block */
    ssSetSimStateCompliance(S, USE_DEFAULT_SIM_STATE);

    ssSetOptions(S, 0);
}


static void mdlInitializeSampleTimes(SimStruct *S)
{
    ssSetSampleTime(S, 0, CONTINUOUS_SAMPLE_TIME);
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
 /* we are in RTWin kernel, do board I/O */
	unsigned int vendorID,DeviceID;
	unsigned int result;
	static PCIInfo content;
	static PCIInfo* info=&content;
	int i,j;
	//getBaseAddr
	unsigned int iobase,ioa,temp;
	//phscl_to_lnr
	unsigned int *pAddr;
    unsigned int *PageDirectoryEntry;
    unsigned int *PageTableEntry;
    unsigned int PDE,PTE;
    unsigned int lnr_addr=0;
	unsigned int p_addr;
	
	//specify vendorID and DeviceID here
	vendorID=0x11e3;
	DeviceID=0x2013;
	
	result=searchPCIDevice(vendorID,DeviceID,info);
	printf("%d\n",result);
	
	printf("The PCI device bus number is %d\n",info->bus);
	printf("The PCI device device number is %d\n",info->device);
	
	//To get base address using the bus and device number
    // iobase=0x80000000+(info->bus)*0x10000+((info->device)*8)*0x100;
	// printf("iobase is 0x%x\n",iobase);
    // ioa=iobase+0x10;
	// printf("ioa is 0x%x\n",ioa);
    // for(i=0;i<=5;i++)
    // {
        // _outpd(0xcf8,ioa);
        // temp=_inpd(0xcfc);
		// printf("%x\n",temp);
        // if((temp&0x01)==0)
        // {
            // temp=temp&0xfffffff0;
        // }
        // else
        // {
            // temp=temp&0xfffc;
        // }
        // info->addr[i]=temp;
		// printf("No. %d addr is %x\n",i,info->addr[i]);
        // ioa+=0x4;   
    // }
	
	//physical address to linear address
	// p_addr=info->addr[0];
	// PDE=0xC0300000;
    // PTE=0xC0000000;
    // PageDirectoryEntry=(unsigned int *)PDE;
    // PageTableEntry=(unsigned int *)PTE;
    
    
    // for(i=0;i<100;i++)
    // {
        // if((PageDirectoryEntry[i]&0xFFFFF000)&&(PageDirectoryEntry[i]&0x00000001))//directory last bit is not zero, this directory is used for physical memory
        // {
            // for(j=0;j<100;j++)
            // {
                // pAddr=(unsigned int *)((int)PageTableEntry+i*4096+j*4);
                // if((*pAddr)&0x00000001)//this page is used for physical memory
                // {
					// printf("0x%x\n",(*pAddr)&0xFFFFF000);
                    // if(((*pAddr)&0xFFFFF000)==(p_addr&0xFFFFF000))
                    // {
                        // result=(unsigned int)(((i*4*1024*1024+j*4*1024)&0xFFFFF000)|(p_addr&0x00000FFF));
                        // lnr_addr=result;
                    // }
                // }
                
            // }
            
        // }
    // }

	printf("Target is 0x%x\n",p_addr&0xFFFFF000);
	//lnr_addr=phscl_to_lnr(info->addr[0]);
	printf("physical address is 0x%x\n",p_addr);
	
	printf("linear address is 0x%x\n",lnr_addr);
#else
 /* we are in Simulink, don't do board I/O */
#endif
	
	printf("Simulation Starts....\n");
	
  }
#endif /*  MDL_START */



/* Function: mdlOutputs =======================================================
 * Abstract:
 *    In this function, you compute the outputs of your S-function
 *    block.
 */
static void mdlOutputs(SimStruct *S, int_T tid)
{
    const real_T *u = (const real_T*) ssGetInputPortSignal(S,0);
    real_T       *y = ssGetOutputPortSignal(S,0);
	printf("Simulating...\n");
    y[0] = u[0];
}


static void mdlTerminate(SimStruct *S)
{
	printf("Simulation Ends!\n");
}


/*=============================*
 * Required S-function trailer *
 *=============================*/

#ifdef  MATLAB_MEX_FILE    /* Is this file being compiled as a MEX-file? */
#include "simulink.c"      /* MEX-file interface mechanism */
#else
#include "cg_sfun.h"       /* Code generation registration function */
#endif
