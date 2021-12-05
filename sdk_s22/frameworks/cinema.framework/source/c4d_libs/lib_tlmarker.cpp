/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) 1989-2009 MAXON Computer GmbH, all rights reserved  //
/////////////////////////////////////////////////////////////
#include "lib_tlmarker.h"

TLMarkerLibrary* tlmarker_lib_cache = nullptr;

static TLMarkerLibrary* CheckTLMarkerLib(Int32 offset)
{
	return (TLMarkerLibrary*)CheckLib(C4D_TLMARKER_LIBRARY_ID, offset, (C4DLibrary**)&tlmarker_lib_cache);
}

BaseList2D* GetFirstMarker(BaseDocument* doc)
{
	TLMarkerLibrary *lib = CheckTLMarkerLib(LIBOFFSET(TLMarkerLibrary, GetFirstMarker));
	if (!lib || !lib->GetFirstMarker) return nullptr;
	return (BaseList2D*)lib->GetFirstMarker(doc);
}


BaseList2D* AddMarker(BaseDocument* doc, BaseList2D* pPred, BaseTime time, String name)
{
	TLMarkerLibrary *lib = CheckTLMarkerLib(LIBOFFSET(TLMarkerLibrary, AddMarker));
	if (!lib || !lib->AddMarker) return nullptr;
	return lib->AddMarker(doc, pPred, time, name);
}
