#define S_FUNCTION_NAME s_basic_tmpl
#define S_FUNCITON_LEVEL 2
#include "simstruct.h"
static void mdlInitializeSizes(Simstruct *S)
{
    
}
//extra s_function code
static void mdlTerminate(Simstruct *S)
{
    
}

#ifdef MATLAB_MEX_FILE
#include "simulink.c"
#else
#include "cg_sfun.c"
#endif