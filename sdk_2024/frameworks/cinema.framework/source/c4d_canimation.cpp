#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "c4d_canimation.h"


#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

#define CaCall(fnc) (this->*C4DOS_CA->fnc)

CTrack* CTrack::Alloc(BaseList2D* bl, const DescID& id)
{
	return C4DOS_CA->CTrackAlloc(bl, id);
}

void CTrack::Free(CTrack*& bl)
{
	C4DOS_Bl->Free(bl);
	bl = nullptr;
}

void CCurve::SetKeyDefault(BaseDocument* doc, Int32 kidx)
{
	C4DOS_Bd->SetKeyDefault(doc, this, kidx);
}


#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif
