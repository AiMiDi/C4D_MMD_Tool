#include "lib_sds.h"

//////////////////////////////////////////////////////////////////////////

SDSObjectLib *lib_sds = nullptr;

static SDSObjectLib *CheckSDSObjectLib(Int32 offset)
{
	return (SDSObjectLib*)CheckLib(LIBRARY_SDS, offset, (C4DLibrary**)&lib_sds);
}

#define SDSObjectLibCall(b) 		SDSObjectLib *lib = CheckSDSObjectLib(LIBOFFSET(SDSObjectLib, b)); \
															if (!lib || !lib->b) return; \
															(lib->b)

#define SDSObjectLibCallR(a, b)  SDSObjectLib *lib = CheckSDSObjectLib(LIBOFFSET(SDSObjectLib, b)); \
															if (!lib || !lib->b) return a; \
															return (lib->b)

//////////////////////////////////////////////////////////////////////////

Int32 SDSObject::GetDivision(BaseObject *op)
{
	SDSObjectLibCallR(NOTOK, GetDivision)(this, op);
}

PolygonObject *SDSObject::GetSDSMesh(BaseObject *op)
{
	SDSObjectLibCallR(nullptr, GetSDSMesh)(this, op);
}

Bool SDSObject::TransformPoint(BaseObject *op, Int32 ply, Float &s, Float &t, Vector *p)
{
	SDSObjectLibCallR(false, TransformPoint)(this, op, ply, s, t, p);
}

Bool SDSObject::GetNormal(BaseObject *op, Int32 ply, Vector *p, Vector *n)
{
	SDSObjectLibCallR(false, GetNormal)(this, op, ply, p, n);
}

Float32 *SDSObject::GetPointWeights(BaseTag *pTag)
{
	SDSObjectLibCallR(nullptr, GetPointWeights)(pTag);
}

PolyWeight *SDSObject::GetEdgeWeights(BaseTag *pTag)
{
	SDSObjectLibCallR(nullptr, GetEdgeWeights)(pTag);
}

SDSSubdivisionMask* SDSObject::GetSubdivisionMask(BaseObject *op, Int32 &maskcnt, Int32 *&polymap, Bool &ngonsubdiv)
{
	SDSObjectLibCallR(nullptr, GetSubdivisionMask)(this, op, maskcnt, polymap, ngonsubdiv);
}

void *SDSObject::GetCreationData(BaseObject *op)
{
	SDSObjectLibCallR(nullptr, GetCreationData)(this, op);
}
