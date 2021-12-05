/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_TAGPLUGIN_H__
#define C4D_TAGPLUGIN_H__

#include "ge_math.h"
#include "c4d_tagdata.h"
#include "c4d_nodeplugin.h"

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct TAGPLUGIN : public NODEPLUGIN
{
	Bool						(TagData::*Draw								)(BaseTag *tag, BaseObject *op, BaseDraw *bd, BaseDrawHelp *bh);
	EXECUTIONRESULT	(TagData::*Execute						)(BaseTag *tag, BaseDocument *doc, BaseObject *op, BaseThread *bt, Int32 priority, EXECUTIONFLAGS flags);
	Bool						(TagData::*AddToExecution			)(BaseTag *tag, PriorityList *list);
	Bool						(TagData::*GetModifiedObjects	)(BaseTag *tag, BaseDocument *doc, BaseObject *&op, Bool &pluginownedop, const Matrix &op_mg, Float lod, Int32 flags, BaseThread *thread);

	void* reserved[(32-4)*C4DPL_MEMBERMULTIPLIER-0];
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

void FillTagPlugin(TAGPLUGIN* np, DataAllocator* npalloc, Int32 info, Int32 disklevel, BaseBitmap* icon);

#endif // C4D_TAGPLUGIN_H__
