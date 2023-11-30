/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) 1989-2009 MAXON Computer GmbH, all rights reserved  //
/////////////////////////////////////////////////////////////
#include "lib_tlmarker.h"

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

TLMarkerLibrary* tlmarker_lib_cache = nullptr;

static TLMarkerLibrary* CheckTLMarkerLib(Int32 offset)
{
	return CheckLib<TLMarkerLibrary>(C4D_TLMARKER_LIBRARY_ID, offset, tlmarker_lib_cache);
}

BaseList2D* GetFirstMarker(BaseDocument* doc)
{
	TLMarkerLibrary *lib = CheckTLMarkerLib(LIBOFFSET(TLMarkerLibrary, GetFirstMarker));
	if (!lib || !lib->GetFirstMarker) return nullptr;
	return (BaseList2D*)lib->GetFirstMarker(doc);
}


BaseList2D* AddMarker(BaseDocument* doc, BaseList2D* pPred, BaseTime time, String name, maxon::Color color, BaseTime length, LayerObject* obj)
{
	TLMarkerLibrary *lib = CheckTLMarkerLib(LIBOFFSET(TLMarkerLibrary, AddMarker));
	if (!lib || !lib->AddMarker) return nullptr;
	return lib->AddMarker(doc, pPred, time, name, color, length, obj);
}

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
