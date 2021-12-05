/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef C4D_CTRACKPLUGIN_H__
#define C4D_CTRACKPLUGIN_H__

#include "ge_math.h"
#include "c4d_ctrackdata.h"
#include "c4d_nodeplugin.h"

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct CTRACKPLUGIN : public NODEPLUGIN
{
	Bool	(CTrackData::*Animate)(CTrack* track, const CAnimInfo* info, Bool* chg, void* data);
	Int32	(CTrackData::*GuiMessage)(CTrack* track, const BaseContainer& msg, BaseContainer& result);
	Bool	(CTrackData::*Draw)(CTrack* track, GeClipMap* map, const BaseTime& clip_left, const BaseTime& clip_right);
	Int32	(CTrackData::*GetHeight)(CTrack* track);
	Bool	(CTrackData::*FillKey)(CTrack* track, BaseDocument* doc, BaseList2D* bl, CKey* key);
	Bool	(CTrackData::*TrackInformation)(CTrack* track, BaseDocument* doc, CKey* key, maxon::String* str, Bool set);

	Bool	(CTrackData::*KeyMessage)(CTrack* track, CKey* node, Int32 type, void* data);
	Bool	(CTrackData::*KeyGetDDescription)(CTrack* track, CKey* node, Description* description, DESCFLAGS_DESC& flags);
	Bool	(CTrackData::*KeyGetDParameter)(CTrack* track, CKey* node, const DescID& id, GeData& t_data, DESCFLAGS_GET& flags);
	Bool	(CTrackData::*KeyGetDEnabling)(CTrack* track, CKey* node, const DescID& id, const GeData& t_data, DESCFLAGS_ENABLE flags, const BaseContainer* itemdesc);
	Bool	(CTrackData::*KeySetDParameter)(CTrack* track, CKey* node, const DescID& id, const GeData& t_data, DESCFLAGS_SET& flags);

	void* reserved[(32 - 11) * C4DPL_MEMBERMULTIPLIER];
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // C4D_CTRACKPLUGIN_H__
