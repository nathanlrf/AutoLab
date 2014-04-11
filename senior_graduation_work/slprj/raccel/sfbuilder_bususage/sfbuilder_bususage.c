#include "__cf_sfbuilder_bususage.h"
#include <math.h>
#include "sfbuilder_bususage.h"
#include "sfbuilder_bususage_private.h"
#include "sfbuilder_bususage_dt.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
const boolean_T gbl_raccel_isMultitasking = 1 ;
#else
const boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
const boolean_T gbl_raccel_tid01eq = 0 ; const int_T gbl_raccel_NumST = 1 ;
const char_T * gbl_raccel_Version = "8.5 (R2013b) 08-Aug-2013" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#endif
} const char * gblSlvrJacPatternFileName =
"slprj\\raccel\\sfbuilder_bususage\\sfbuilder_bususage_Jpattern.mat" ; const
int_T gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS = &
model_S ; void MdlInitialize ( void ) { rtDW . cki0ip52gw = rtP .
PreviousOutput_InitialCondition ; rtDW . j0laejk5mi = rtP .
UnitDelay_InitialCondition ; } void MdlStart ( void ) { rtDW . cs5yjh1cu3 = 0
; { int_T numCols = 4 ; rtDW . foktjz5owm . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "scopeout1" , SS_DOUBLE , 0 , 0 , 0 , 4 , 1 ,
( int_T * ) & numCols , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.1 , 1
) ; if ( rtDW . foktjz5owm . LoggedData == ( NULL ) ) return ; } { int_T
numCols = 4 ; rtDW . p52cje0oxb . LoggedData = rt_CreateLogVar (
ssGetRTWLogInfo ( rtS ) , ssGetTStart ( rtS ) , ssGetTFinal ( rtS ) , 0.0 , (
& ssGetErrorStatus ( rtS ) ) , "scopeout2" , SS_DOUBLE , 0 , 0 , 0 , 4 , 1 ,
( int_T * ) & numCols , NO_LOGVALDIMS , ( NULL ) , ( NULL ) , 0 , 1 , 0.1 , 1
) ; if ( rtDW . p52cje0oxb . LoggedData == ( NULL ) ) return ; }
MdlInitialize ( ) ; } void MdlOutputs ( int_T tid ) { int32_T ntpa2y15yn ;
boolean_T dbj2y2ufyn ; ntpa2y15yn = ( rtDW . cs5yjh1cu3 < rtP .
PulseGenerator1_Duty ) && ( rtDW . cs5yjh1cu3 >= 0 ) ? rtP .
PulseGenerator1_Amp : 0 ; if ( rtDW . cs5yjh1cu3 >= rtP .
PulseGenerator1_Period - 1.0 ) { rtDW . cs5yjh1cu3 = 0 ; } else { rtDW .
cs5yjh1cu3 ++ ; } rtB . mgh3qnxhyz . inputsignal . input = ntpa2y15yn ; rtB .
mgh3qnxhyz . limits . upper_saturation_limit = rtP .
upper_saturation_limit1_Value ; rtB . mgh3qnxhyz . limits .
lower_saturation_limit = rtP . lower_saturation_limit1_Value ; ntpa2y15yn =
rtB . mgh3qnxhyz . inputsignal . input + rtDW . cki0ip52gw ; dbj2y2ufyn = (
ntpa2y15yn >= rtB . mgh3qnxhyz . limits . lower_saturation_limit ) ; if ( (
rtB . mgh3qnxhyz . limits . upper_saturation_limit >= ntpa2y15yn ) &&
dbj2y2ufyn ) { rtB . pzhuempihi = ntpa2y15yn ; } else if ( dbj2y2ufyn ) { rtB
. pzhuempihi = rtB . mgh3qnxhyz . limits . upper_saturation_limit ; } else {
rtB . pzhuempihi = rtB . mgh3qnxhyz . limits . lower_saturation_limit ; } rtB
. prfbtakhlk = rtB . pzhuempihi ; rtB . hgk2wr3t3t = rtB . mgh3qnxhyz .
limits . upper_saturation_limit ; rtB . le3xux3qmq = rtB . mgh3qnxhyz .
limits . lower_saturation_limit ; if ( ssGetLogOutput ( rtS ) ) { real_T u [
4 ] ; u [ 0 ] = ssGetT ( rtS ) ; u [ 1 ] = rtB . prfbtakhlk ; u [ 2 ] = rtB .
hgk2wr3t3t ; u [ 3 ] = rtB . le3xux3qmq ; rt_UpdateLogVar ( ( LogVar * ) rtDW
. foktjz5owm . LoggedData , u , 0 ) ; } rtB . miy0z4ys2p = rtDW . j0laejk5mi
; sfbuilder_bus_Outputs_wrapper ( & rtB . mgh3qnxhyz , & rtB . miy0z4ys2p , &
rtB . mcjeqk0nwc , & rtB . hwkbrqxmw1 ) ; rtB . prfbtakhlkt = rtB .
mcjeqk0nwc . inputsignal . input ; rtB . hgk2wr3t3tb = rtB . mcjeqk0nwc .
limits . upper_saturation_limit ; rtB . le3xux3qmqz = rtB . mcjeqk0nwc .
limits . lower_saturation_limit ; if ( ssGetLogOutput ( rtS ) ) { real_T u [
4 ] ; u [ 0 ] = ssGetT ( rtS ) ; u [ 1 ] = rtB . prfbtakhlkt ; u [ 2 ] = rtB
. hgk2wr3t3tb ; u [ 3 ] = rtB . le3xux3qmqz ; rt_UpdateLogVar ( ( LogVar * )
rtDW . p52cje0oxb . LoggedData , u , 0 ) ; } UNUSED_PARAMETER ( tid ) ; }
void MdlUpdate ( int_T tid ) { rtDW . cki0ip52gw = rtB . pzhuempihi ; rtDW .
j0laejk5mi = rtB . hwkbrqxmw1 ; UNUSED_PARAMETER ( tid ) ; } void
MdlTerminate ( void ) { } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0
) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS , 1 ) ;
ssSetNumBlocks ( rtS , 26 ) ; ssSetNumBlockIO ( rtS , 11 ) ;
ssSetNumBlockParams ( rtS , 8 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.1 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ; }
void raccel_set_checksum ( SimStruct * rtS ) { ssSetChecksumVal ( rtS , 0 ,
1294116434U ) ; ssSetChecksumVal ( rtS , 1 , 1816037090U ) ; ssSetChecksumVal
( rtS , 2 , 3797566445U ) ; ssSetChecksumVal ( rtS , 3 , 315603288U ) ; }
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } ssSetDefaultParam ( rtS , ( real_T * ) & rtP ) ; { void * dwork =
( void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork
, 0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset
( ( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo (
rtS , & dtInfo ) ; dtInfo . numDataTypes = 17 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . B = & rtBTransTable ; dtInfo . P = & rtPTransTable ; } ssSetRootSS (
rtS , rtS ) ; ssSetVersion ( rtS , SIMSTRUCT_VERSION_LEVEL2 ) ;
ssSetModelName ( rtS , "sfbuilder_bususage" ) ; ssSetPath ( rtS ,
"sfbuilder_bususage" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal ( rtS , 10.0
) ; ssSetStepSize ( rtS , 0.1 ) ; ssSetFixedStepSize ( rtS , 0.1 ) ; { static
RTWLogInfo rt_DataLoggingInfo ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo
) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1 } ; static int_T
rt_LoggedStateNumDimensions [ ] = { 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 } ; static boolean_T
rt_LoggedStateIsVarDims [ ] = { 0 , 0 } ; static BuiltInDTypeId
rt_LoggedStateDataTypeIds [ ] = { SS_INT32 , SS_INT32 } ; static int_T
rt_LoggedStateComplexSignals [ ] = { 0 , 0 } ; static const char_T *
rt_LoggedStateLabels [ ] = { "DSTATE" , "DSTATE" } ; static const char_T *
rt_LoggedStateBlockNames [ ] = {
"sfbuilder_bususage/slCounter/Previous Output" ,
"sfbuilder_bususage/S-function Builder/Unit Delay" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" , "" } ; static boolean_T
rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 } ; static RTWLogDataTypeConvert
rt_RTWLogDataTypeConvert [ ] = { { 0 , SS_INT32 , SS_INT32 , 0 , 0 , 0 , 1.0
, 0 , 0.0 } , { 0 , SS_INT32 , SS_INT32 , 0 , 0 , 0 , 1.0 , 0 , 0.0 } } ;
static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 2 , rt_LoggedStateWidths
, rt_LoggedStateNumDimensions , rt_LoggedStateDimensions ,
rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , { rt_LoggedStateLabels } , ( NULL )
, ( NULL ) , ( NULL ) , { rt_LoggedStateBlockNames } , { rt_LoggedStateNames
} , rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert } ; static void *
rt_LoggedStateSignalPtrs [ 2 ] ; rtliSetLogXSignalPtrs ( ssGetRTWLogInfo (
rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtDW . cki0ip52gw ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtDW . j0laejk5mi ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "tmp_raccel_xout" ) ; rtliSetLogXFinal (
ssGetRTWLogInfo ( rtS ) , "xFinal" ) ; rtliSetSigLog ( ssGetRTWLogInfo ( rtS
) , "" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 1000 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo (
rtS ) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
ssSolverInfo slvrInfo ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "FixedStepDiscrete" ) ; ssSetVariableStepSolver ( rtS
, 0 ) ; ssSetSolverConsistencyChecking ( rtS , 0 ) ;
ssSetSolverAdaptiveZcDetection ( rtS , 0 ) ; ssSetSolverRobustResetMethod (
rtS , 0 ) ; ssSetSolverStateProjection ( rtS , 0 ) ;
ssSetSolverMassMatrixType ( rtS , ( ssMatrixType ) 0 ) ;
ssSetSolverMassMatrixNzMax ( rtS , 0 ) ; ssSetModelOutputs ( rtS , MdlOutputs
) ; ssSetModelLogData ( rtS , rt_UpdateTXYLogVars ) ; ssSetModelUpdate ( rtS
, MdlUpdate ) ; ssSetTNextTid ( rtS , INT_MIN ) ; ssSetTNext ( rtS ,
rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ; ssSetNumNonsampledZCs ( rtS ,
0 ) ; } ssSetChecksumVal ( rtS , 0 , 1294116434U ) ; ssSetChecksumVal ( rtS ,
1 , 1816037090U ) ; ssSetChecksumVal ( rtS , 2 , 3797566445U ) ;
ssSetChecksumVal ( rtS , 3 , 315603288U ) ; { static const sysRanDType
rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo
; static const sysRanDType * systemRan [ 4 ] ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) ,
& ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo
( rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS
) , ssGetTPtr ( rtS ) ) ; } return rtS ; }
