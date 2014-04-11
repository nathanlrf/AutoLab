#include "__cf_sfbuilder_bususage.h"
#ifndef RTW_HEADER_sfbuilder_bususage_h_
#define RTW_HEADER_sfbuilder_bususage_h_
#ifndef sfbuilder_bususage_COMMON_INCLUDES_
#define sfbuilder_bususage_COMMON_INCLUDES_
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif
#include "sfbuilder_bususage_types.h"
#define MODEL_NAME sfbuilder_bususage
#define NSAMPLE_TIMES (1) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (11) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (0)   
#elif NCSTATES != 0
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (NULL)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val)
#endif
typedef struct { SFB_COUNTERBUS mgh3qnxhyz ; SFB_COUNTERBUS mcjeqk0nwc ;
int32_T prfbtakhlk ; int32_T hgk2wr3t3t ; int32_T le3xux3qmq ; int32_T
prfbtakhlkt ; int32_T hgk2wr3t3tb ; int32_T le3xux3qmqz ; int32_T pzhuempihi
; int32_T miy0z4ys2p ; int32_T hwkbrqxmw1 ; } B ; typedef struct {
SFB_COUNTERBUS hww2eyqm53 ; SFB_COUNTERBUS hrkcp5vgmj ; struct { void *
LoggedData ; } foktjz5owm ; struct { void * LoggedData ; } p52cje0oxb ;
int32_T cki0ip52gw ; int32_T j0laejk5mi ; int32_T cs5yjh1cu3 ; } DW ; struct
P_ { real_T PulseGenerator1_Period ; real_T PulseGenerator1_Duty ; real_T
PulseGenerator1_PhaseDelay ; int32_T UnitDelay_InitialCondition ; int32_T
PreviousOutput_InitialCondition ; int32_T PulseGenerator1_Amp ; int32_T
upper_saturation_limit1_Value ; int32_T lower_saturation_limit1_Value ; } ;
extern P rtP ; extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB
; extern DW rtDW ; extern SimStruct * const rtS ; extern const int_T
gblNumToFiles ; extern const int_T gblNumFrFiles ; extern const int_T
gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ; extern const
char * gblInportFileName ; extern const int_T gblNumRootInportBlks ; extern
const int_T gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ;
extern const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [
] ; extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ;
#endif
