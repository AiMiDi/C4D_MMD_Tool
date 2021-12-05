/////////////////////////////////////////////////////////////
// CINEMA 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_MESSAGEPLUGIN_H__
#define C4D_MESSAGEPLUGIN_H__

#include "ge_math.h"
#include "c4d_messagedata.h"
#include "c4d_baseplugin.h"

/// @see MessageData::GetTimer()
#define MSG_TIMER					112008

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct MESSAGEPLUGIN : public STATICPLUGIN
{
	Int32	(MessageData::*GetTimer			)(void);
	Bool	(MessageData::*CoreMessage	)(Int32 id, const BaseContainer &bc);

	void* reserved[(32-2)*C4DPL_MEMBERMULTIPLIER];
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // C4D_MESSAGEPLUGIN_H__
