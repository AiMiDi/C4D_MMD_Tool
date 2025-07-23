#ifndef DATADESCRIPTIONDEFINITION_CONVERSION_H__
#define DATADESCRIPTIONDEFINITION_CONVERSION_H__

#include "maxon/apibase.h"



namespace maxon
{

//----------------------------------------------------------------------------------------
/// used in FixDatabaseProps.
//----------------------------------------------------------------------------------------
enum class DBVERSION
{
	R22 = 1,
	R23_CONVERTLIMIT,		 ///< convert limit Bool to enum
	R23_CONVERTENUM,		 ///< convert .enum and .command. to #enum and #command#
	R23_CONVERTENUM2,		 ///< convert .enum and .command. fixes ITEM#328085 [RE] Strings Translation tool deletes already translated strings
	R23_DBVERSIONIDTYPE, ///< removes the old dbversion type
	CURRENT,
} MAXON_ENUM_ORDERED_LIST(DBVERSION);
}


#endif // DATADESCRIPTIONDEFINITION_CONVERSION_H__
