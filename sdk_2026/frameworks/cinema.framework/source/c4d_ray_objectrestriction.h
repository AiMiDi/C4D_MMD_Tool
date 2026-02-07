/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef __C4D_RAY_OBJECTRESTRICTION__
#define __C4D_RAY_OBJECTRESTRICTION__


#include "ge_math.h"

namespace cinema
{

struct ObjectRestriction
{
	//----------------------------------------------------------------------------------------
	/// Default constructor.
	/// @since R17.032
	//----------------------------------------------------------------------------------------
	ObjectRestriction()
		: object(nullptr), object_cnt(0)
	{
	}

	UChar* object;		///< An array of @ref object_cnt flags, one for each object.\n
										///< For light restriction these are the flags: @enumerateEnum{LIGHTRESTRICTION}\n
										///< For object restriction these are the flags: @enumerateEnum{OBJECTRESTRICTION}
	Int32 object_cnt; ///< The number of objects.
};


} // namespace cinema


#endif // __C4D_RAY_OBJECTRESTRICTION__
