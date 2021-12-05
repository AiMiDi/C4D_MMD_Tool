#ifdef __API_INTERN__
	#error "Not in the kernel"
#endif

#include "c4d_canimation.h"

#define CaCall(fnc) (this->*C4DOS.CA->fnc)

CTrack* CTrack::Alloc(BaseList2D* bl, const DescID& id)
{
	return C4DOS.CA->CTrackAlloc(bl, id);
}

void CTrack::Free(CTrack*& bl)
{
	C4DOS.Bl->Free(bl);
	bl = nullptr;
}

void CCurve::SetKeyDefault(BaseDocument* doc, Int32 kidx)
{
	C4DOS.Bd->SetKeyDefault(doc, this, kidx);
}

