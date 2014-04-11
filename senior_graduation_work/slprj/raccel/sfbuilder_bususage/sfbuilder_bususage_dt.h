#include "__cf_sfbuilder_bususage.h"
#include "ext_types.h"
static uint_T rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T )
, sizeof ( int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof (
uint16_T ) , sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T )
, sizeof ( fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof (
action_T ) , 2 * sizeof ( uint32_T ) , sizeof ( SFB_SIGNALBUS ) , sizeof (
SFB_LIMITBUS ) , sizeof ( SFB_COUNTERBUS ) } ; static const char_T *
rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T" ,
"int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" , "fcn_call_T"
, "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" ,
"SFB_SIGNALBUS" , "SFB_LIMITBUS" , "SFB_COUNTERBUS" } ; static
DataTypeTransition rtBTransitions [ ] = { { ( char_T * ) ( & rtB . mgh3qnxhyz
) , 16 , 0 , 2 } , { ( char_T * ) ( & rtB . prfbtakhlk ) , 6 , 0 , 9 } , { (
char_T * ) ( & rtDW . hww2eyqm53 ) , 16 , 0 , 2 } , { ( char_T * ) ( & rtDW .
foktjz5owm . LoggedData ) , 11 , 0 , 2 } , { ( char_T * ) ( & rtDW .
cki0ip52gw ) , 6 , 0 , 3 } } ; static DataTypeTransitionTable rtBTransTable =
{ 5U , rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { {
( char_T * ) ( & rtP . PulseGenerator1_Period ) , 0 , 0 , 3 } , { ( char_T *
) ( & rtP . UnitDelay_InitialCondition ) , 6 , 0 , 5 } } ; static
DataTypeTransitionTable rtPTransTable = { 2U , rtPTransitions } ;
