#include "lib_intersect.h"

IntersectLibrary *lib_intersect = nullptr;

static IntersectLibrary *CheckIntersectLib(Int32 offset)
{
	return (IntersectLibrary*)CheckLib(LIBRARY_INTERSECT, offset, (C4DLibrary**)&lib_intersect);
}

#define IntersectLibCall(b) 		IntersectLibrary *lib = CheckIntersectLib(LIBOFFSET(IntersectLibrary, b)); \
	if (!lib || !lib->b) return; \
	(lib->b)

#define IntersectLibCallR(a, b)  IntersectLibrary *lib = CheckIntersectLib(LIBOFFSET(IntersectLibrary, b)); \
	if (!lib || !lib->b) return a; \
	return (lib->b)

//==============================================================================

IIntersect*	IIntersect::Alloc(INTERSECTTYPE type) { IntersectLibCallR(nullptr, intersectAlloc)(type); }
void		IIntersect::Free(IIntersect *&isect) { IntersectLibCall(intersectFree)(isect); }
Bool		IIntersect::Init(PolygonObject *pPoly) { IntersectLibCallR(false, intersectInit)(this, pPoly); }
Bool		IIntersect::AddObject(PolygonObject *pPoly) { IntersectLibCallR(false, intersectAddObject)(this, pPoly); }
void		IIntersect::Clear() { IntersectLibCall(intersectClear)(this); }
Bool		IIntersect::Hit(BaseDraw* bd, Float mx, Float my, Bool backfaces, IntersectHitData  &hitData) { IntersectLibCallR(false, intersectHitScreen)(this, bd, mx, my, backfaces, hitData);	}
Bool		IIntersect::Hit(const Vector &rayp, const Vector &rayv, Bool backfaces, IntersectHitData  &hitData) { IntersectLibCallR(false, intersectHitObject)(this, rayp, rayv, backfaces, hitData);	}
