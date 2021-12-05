#include "lib_modeling.h"
#include "maxon/sort.h"

//////////////////////////////////////////////////////////////////////////

ModelingLib *lib_modeling = nullptr;

static ModelingLib *CheckModelingLib(Int32 offset)
{
	return (ModelingLib*)CheckLib(LIBRARY_MODELLING, offset, (C4DLibrary**)&lib_modeling);
}

#define ModelingLibCall(b) 		ModelingLib *lib = CheckModelingLib(LIBOFFSET(ModelingLib, b)); \
															if (!lib || !lib->b) return; \
															(((iModeling*)this)->*lib->b)

#define ModelingLibCallR(a, b)  ModelingLib *lib = CheckModelingLib(LIBOFFSET(ModelingLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iModeling*)this)->*lib->b)

Modeling* Modeling::Alloc()
{
	ModelingLib *lib = CheckModelingLib(LIBOFFSET(ModelingLib, Alloc)); if (!lib) return nullptr;
	return (Modeling*)lib->Alloc();
}

void Modeling::Free(Modeling *&p)
{
	if (!p) return;
	ModelingLib *lib = CheckModelingLib(LIBOFFSET(ModelingLib, Free)); if (!lib) return;
	iModeling* i = (iModeling*)p;
	lib->Free(i);
	p = nullptr;
}

//////////////////////////////////////////////////////////////////////////

Bool Modeling::InitArray(AtomArray *objs, Int32 flags)
{
	ModelingLibCallR(false, InitArray)(objs, flags);
}

Bool Modeling::InitObject(C4DAtom *op, Int32 flags)
{
	ModelingLibCallR(false, InitObject)(op, flags);
}

Bool Modeling::Commit(C4DAtom *op, Int32 flags, BaseObject* cobj)
{
	ModelingLibCallR(false, Commit)(op, flags, cobj);
}

void Modeling::Release()
{
	ModelingLibCall(Release)();
}

void  Modeling::ReleaseObject(C4DAtom *op)
{
	ModelingLibCall(ReleaseObject)(op);
}

Int32 Modeling::AddPoint(C4DAtom *op, const Vector &p)
{
	ModelingLibCallR(0, AddPoint)(op, p);
}

Int32 Modeling::ClonePoint(C4DAtom *op, Int32 index)
{
	ModelingLibCallR(0, ClonePoint)(op, index);
}

Bool Modeling::DeletePoint(C4DAtom *op, Int32 index)
{
	ModelingLibCallR(false, DeletePoint)(op, index);
}

Bool Modeling::GetPoint(C4DAtom *op, Int32 index, Vector *p)
{
	ModelingLibCallR(false, GetPoint)(op, index, p);
}

Bool Modeling::SetPoint(C4DAtom *op, Int32 index, const Vector &p, Int32 flags)
{
	ModelingLibCallR(false, SetPoint)(op, index, p, flags);
}

Bool Modeling::SetEdgePoint(C4DAtom *op, Int32 index, Float l, Int32 flags)
{
	ModelingLibCallR(false, SetEdgePoint)(op, index, l, flags);
}

Int32 Modeling::NewNgon(C4DAtom *op, Int32 flags)
{
	ModelingLibCallR(0, NewNgon)(op, flags);
}

Int32 Modeling::AddNgon(C4DAtom *op, const Ngon &ngon, Int32 flags)
{
	ModelingLibCallR(0, AddNgon)(op, ngon, flags);
}

Int32 Modeling::CreateNgon(C4DAtom *op, Int32 *padr, Int32 cnt, Int32 flags)
{
	ModelingLibCallR(0, CreateNgon)(op, padr, cnt, flags);
}

Bool Modeling::DeleteNgon(C4DAtom *op, Int32 index, Bool points)
{
	ModelingLibCallR(false, DeleteNgon)(op, index, points);
}

Int32 Modeling::CloneNgon(C4DAtom *op, Int32 index, Int32 flags)
{
	ModelingLibCallR(0, CloneNgon)(op, index, flags);
}

Bool Modeling::GetNgon(C4DAtom *op, Int32 index, Ngon *ngon, Int32 flags)
{
	ModelingLibCallR(false, GetNgon)(op, index, ngon, flags);
}

Bool Modeling::SetNgon(C4DAtom *op, Int32 index, Ngon &ngon, Int32 flags)
{
	ModelingLibCallR(false, SetNgon)(op, index, ngon, flags);
}

Int32 Modeling::SplitEdge(C4DAtom *op, Int32 p1, Int32 p2, Float l)
{
	ModelingLibCallR(0, SplitEdge)(op, p1, p2, l);
}

Bool Modeling::DeleteEdge(C4DAtom *op, Int32 index, Int32 p1, Int32 p2)
{
	ModelingLibCallR(false, DeleteEdge)(op, index, p1, p2);
}

Bool Modeling::MeltEdgeBetween(C4DAtom *op, Int32 pa, Int32 pb, Int32 p1, Int32 p2)
{
	ModelingLibCallR(false, MeltEdgeBetween)(op, pa, pb, p1, p2);
}

Bool Modeling::MeltEdge(C4DAtom *op, Int32 pa, Int32 p1, Int32 p2)
{
	ModelingLibCallR(false, MeltEdge)(op, pa, p1, p2);
}

Bool Modeling::MeltPoint(C4DAtom *op, Int32 p)
{
	ModelingLibCallR(false, MeltPoint)(op, p);
}

Int32 Modeling::SplitPolygon(C4DAtom *op, Int32 index, Int32 p1, Int32 p2)
{
	ModelingLibCallR(0, SplitPolygon)(op, index, p1, p2);
}

Bool Modeling::MergePolygons(C4DAtom *op, Int32 pa, Int32 pb)
{
	ModelingLibCallR(false, MergePolygons)(op, pa, pb);
}

Bool Modeling::IsValidEdge(C4DAtom *op, Int32 index, Int32 p1, Int32 p2)
{
	ModelingLibCallR(false, IsValidEdge)(op, index, p1, p2);
}

Bool Modeling::IsValidNgon(C4DAtom *op, Int32 index)
{
	ModelingLibCallR(false, IsValidNgon)(op, index);
}

Bool Modeling::IsValidPoint(C4DAtom *op, Int32 index)
{
	ModelingLibCallR(false, IsValidPoint)(op, index);
}

Int32 *Modeling::GetEdgeNgons(C4DAtom *op, Int32 p1, Int32 p2, Int32 &pcnt)
{
	ModelingLibCallR(nullptr, GetEdgeNgons)(op, p1, p2, pcnt);
}

Int32 *Modeling::GetPointNgons(C4DAtom *op, Int32 p, Int32 &pcnt, Bool clone)
{
	ModelingLibCallR(nullptr, GetPointNgons)(op, p, pcnt, clone);
}

Int32 *Modeling::GetNeighborNgons(C4DAtom *op, Int32 index, Int32 &pcnt)
{
	ModelingLibCallR(nullptr, GetNeighborNgons)(op, index, pcnt);
}

Int32 *Modeling::GetPointEdges(C4DAtom *op, Int32 p, Int32 &ecnt)
{
	ModelingLibCallR(nullptr, GetPointEdges)(op, p, ecnt);
}

Bool Modeling::GetOriginalEdgePoints(C4DAtom *op, Int32 edge, Int32 &p1, Int32 &p2)
{
	ModelingLibCallR(false, GetOriginalEdgePoints)(op, edge, p1, p2);
}

Bool Modeling::IsEdgeDeleted(C4DAtom *op, Int32 p1, Int32 p2)
{
	ModelingLibCallR(false, IsEdgeDeleted)(op, p1, p2);
}

Int32 Modeling::TranslateNgonIndex(C4DAtom *op, Int32 index, Bool tovirtual)
{
	ModelingLibCallR(false, TranslateNgonIndex)(op, index, tovirtual);
}

Int32 Modeling::TranslatePointIndex(C4DAtom *op, Int32 index, Bool tovirtual)
{
	ModelingLibCallR(false, TranslatePointIndex)(op, index, tovirtual);
}

Bool Modeling::GetPointMap(C4DAtom *op, Int32 **map, Int32 *count)
{
	ModelingLibCallR(false, GetPointMap)(op, map, count);
}

Bool Modeling::GetNgonMap(C4DAtom *op, Int32 **map, Int32 *count)
{
	ModelingLibCallR(false, GetNgonMap)(op, map, count);
}

Bool Modeling::ReleaseMap(C4DAtom *op, Int32 *map)
{
	ModelingLibCallR(false, ReleaseMap)(op, map);
}

Bool Modeling::FreeMap(C4DAtom *op, Int32 *map)
{
	ModelingLibCallR(false, FreeMap)(op, map);
}

Bool Modeling::GetNgonNormal(C4DAtom *op, Int32 index, Vector *n)
{
	ModelingLibCallR(false, GetNgonNormal)(op, index, n);
}

Bool Modeling::FlipNgonNormal(C4DAtom *op, Int32 index)
{
	ModelingLibCallR(false, FlipNgonNormal)(op, index);
}

Bool Modeling::SetPoints(C4DAtom *op, PointMove *pnts, Int32 cnt, Bool commit, Int32 flags)
{
	ModelingLibCallR(false, SetPoints)(op, pnts, cnt, commit, flags);
}

Int32 Modeling::GetLastError(C4DAtom *op)
{
	ModelingLibCallR(false, GetLastError)(op);
}

Bool Modeling::IsModified(C4DAtom *op)
{
	ModelingLibCallR(false, IsModified)(op);
}

Bool Modeling::GetPointInfo(C4DAtom *op, Int32 index, Int32 &ia, Int32 &ib, Float &t)
{
	ModelingLibCallR(false, GetPointInfo)(op, index, ia, ib, t);
}

Bool Modeling::GetOriginPoint(C4DAtom *op, Int32 index, Int32 &ci)
{
	ModelingLibCallR(false, GetOriginPoint)(op, index, ci);
}

Bool Modeling::GetOriginNgon(C4DAtom *op, Int32 index, Int32 &ci)
{
	ModelingLibCallR(false, GetOriginNgon)(op, index, ci);
}

Bool Modeling::FindNgon(C4DAtom *op, Int32 p1, Int32 p2, Int32 &index)
{
	ModelingLibCallR(false, FindNgon)(op, p1, p2, index);
}

Bool Modeling::SetOriginNgon(C4DAtom *op, Int32 index, Int32 ci)
{
	ModelingLibCallR(false, SetOriginNgon)(op, index, ci);
}

Int32 Modeling::GetNgonFlags(C4DAtom *op, Int32 index)
{
	ModelingLibCallR(false, GetNgonFlags)(op, index);
}

Int32 Modeling::SetNgonFlags(C4DAtom *op, Int32 index, Int32 flags)
{
	ModelingLibCallR(false, SetNgonFlags)(op, index, flags);
}

Bool Modeling::SetPointInfo(C4DAtom *op, Int32 index, Int32 ia, Int32 ib, Float t)
{
	ModelingLibCallR(false, SetPointInfo)(op, index, ia, ib, t);
}

Bool Modeling::SetOriginPoint(C4DAtom *op, Int32 index, Int32 ci)
{
	ModelingLibCallR(false, SetOriginPoint)(op, index, ci);
}

Int32 Modeling::GetPointFlags(C4DAtom *op, Int32 index)
{
	ModelingLibCallR(false, GetPointFlags)(op, index);
}

Int32 Modeling::SetPointFlags(C4DAtom *op, Int32 index, Int32 flags)
{
	ModelingLibCallR(false, SetPointFlags)(op, index, flags);
}

Bool Modeling::GetPointOrigin(C4DAtom *op, Int32 index, Vector &opnt)
{
	ModelingLibCallR(false, GetPointOrigin)(op, index, opnt);
}

Bool Modeling::SetPointOrigin(C4DAtom *op, Int32 index, Vector opnt, Int32 flags)
{
	ModelingLibCallR(false, SetPointOrigin)(op, index, opnt, flags);
}

Bool Modeling::SetInterPoint(C4DAtom *op, Int32 index, Vector npnt, Float t, Int32 flags)
{
	ModelingLibCallR(false, SetInterPointBetween)(op, index, npnt, t, flags);
}

Bool Modeling::WeldPoints(C4DAtom *op, Int32 source, Int32 dest)
{
	ModelingLibCallR(false, WeldPoints)(op, source, dest);
}

Bool Modeling::MeltNgon(C4DAtom *op, Int32 pa)
{
	ModelingLibCallR(false, MeltNgon)(op, pa);
}

Bool Modeling::GetFaceSelection(C4DAtom *op, BaseSelect *select, BaseSelect *faceselect, BaseSelect *hidden)
{
	ModelingLibCallR(false, GetFaceSelection)(op, select, faceselect, hidden);
}

Bool Modeling::IsPointDeleted(C4DAtom *op, Int32 index)
{
	ModelingLibCallR(false, IsPointDeleted)(op, index);
}

Bool Modeling::IsFaceDeleted(C4DAtom *op, Int32 index)
{
	ModelingLibCallR(false, IsFaceDeleted)(op, index);
}

Bool Modeling::SetInterPoint(C4DAtom *op, Int32 index, const Vector &move, const Vector &offset, Int32 flags)
{
	ModelingLibCallR(false, SetInterPointMove)(op, index, move, offset, flags);
}

Bool Modeling::GetEdgeSelection(C4DAtom *op, BaseSelect *select, BaseSelect *edgeselect, BaseSelect *hidden)
{
	ModelingLibCallR(false, GetFaceSelection)(op, select, edgeselect, hidden);
}

Int32 *Modeling::GetEdgeSelectionArray(C4DAtom *op, BaseSelect *select, Int32 &ecnt, BaseSelect *hidden, Bool tovirtual)
{
	ModelingLibCallR(nullptr, GetEdgeSelectionArray)(op, select, ecnt, hidden, tovirtual);
}

Bool Modeling::InsertFacePoint(C4DAtom *op, Int32 pa, Int32 p1)
{
	ModelingLibCallR(false, InsertFacePoint)(op, pa, p1);
}

Bool Modeling::CreateHole(C4DAtom *op, Int32 index, const Ngon &ngon)
{
	ModelingLibCallR(false, CreateHole)(op, index, ngon);
}

Bool Modeling::CreateHole(C4DAtom *op, Int32 index, Int32 *pnts, Int32 pcnt)
{
	ModelingLibCallR(false, CreateHoleFromPoints)(op, index, pnts, pcnt);
}

Bool Modeling::ResizeNgon(C4DAtom *op, Int32 index, Int32 pcnt, Int32 scnt)
{
	ModelingLibCallR(false, ResizeNgon)(op, index, pcnt, scnt);
}

Bool Modeling::GetEdgeSegment(C4DAtom *op, Int32 pa, Int32 p1, Int32 p2, Int32 *seg, Int32 *s1, Int32 *s2, Bool rel)
{
	ModelingLibCallR(false, GetEdgeSegment)(op, pa, p1, p2, seg, s1, s2, rel);
}

void Modeling::FreeTable(C4DAtom *op, void *table)
{
	ModelingLibCall(FreeTable)(table);
}

Bool Modeling::PointInFace(C4DAtom *op, Int32 index, const Vector &p)
{
	ModelingLibCallR(false, PointInFace)(op, index, p);
}

Bool Modeling::PointInFace(C4DAtom *op, const Ngon &ngon, const Vector &p)
{
	ModelingLibCallR(false, PointInFaceNgon)(op, ngon, p);
}

Bool Modeling::LineFaceIntersection(C4DAtom *op, Int32 index, const Vector &p1, const Vector &p2)
{
	ModelingLibCallR(false, LineFaceIntersection)(op, index, p1, p2);
}

Bool Modeling::LineFaceIntersection(C4DAtom *op, const Ngon &ngon, const Vector &p1, const Vector &p2)
{
	ModelingLibCallR(false, LineFaceIntersectionNgon)(op, ngon, p1, p2);
}

void Modeling::SetTriangulateHook(C4DAtom *op, TriangulateHook pHook, void *pData)
{
	ModelingLibCall(SetTriangulateHook)(op, pHook, pData);
}

void Modeling::GetTriangulateHook(C4DAtom *op, TriangulateHook *ppHook, void **ppData)
{
	ModelingLibCall(GetTriangulateHook)(op, ppHook, ppData);
}

//////////////////////////////////////////////////////////////////////////

class TranslationMapSearch : public maxon::BaseSort<TranslationMapSearch>
{
public:
	static Bool LessThan(const TransIndexMapData& a, const TransIndexMapData& b)
	{
		return a.oIndex < b.oIndex;
	}

	static Bool IsEqual(const TransIndexMapData& a, const TransIndexMapData& b)
	{
		return a.oIndex == b.oIndex;
	}
};

class TranslationMapSearchN : public maxon::BaseSort<TranslationMapSearchN>
{
public:
	static Bool LessThan(const TransIndexMapData& a, const TransIndexMapData& b)
	{
		return a.nIndex < b.nIndex;
	}

	static Bool IsEqual(const TransIndexMapData& a, const TransIndexMapData& b)
	{
		return a.nIndex == b.nIndex;
	}
};

class TranslationMapNewSearch : public maxon::BaseSort<TranslationMapNewSearch>
{
public:
	static Bool LessThan(const TransMapNewData& a, const TransMapNewData& b)
	{
		return a.nIndex < b.nIndex;
	}

	static Bool IsEqual(const TransMapNewData& a, const TransMapNewData& b)
	{
		return a.nIndex == b.nIndex;
	}
};

Int32 TranslationMaps::FindOriginalPoint(Int32 index)
{
	if (!m_pPointMap) return NOTOK;

	TranslationMapSearch search;
	TransMapData key(index);

	TransMapData *found = search.Find(key, m_pPointMap, m_mPointCount);
	if (!found) return NOTOK;
	return Int32(found-m_pPointMap);
}

Int32 TranslationMaps::FindOriginalPolygon(Int32 index)
{
	if (!m_pPolygonMap) return NOTOK;

	TranslationMapSearch search;
	TransMapData key(index);

	TransMapData *found = search.Find(key, m_pPolygonMap, m_mPolygonCount);
	if (!found) return NOTOK;
	return Int32(found-m_pPolygonMap);
}

Int32 TranslationMaps::FindOriginalPgon(Int32 index)
{
	if (!m_pPgonMap) return NOTOK;

	TranslationMapSearch search;
	TransMapData key(index);

	TransMapData *found = search.Find(key, m_pPgonMap, m_mPgonCount);
	if (!found) return NOTOK;
	return Int32(found-m_pPgonMap);
}

Int32 TranslationMaps::FindOriginalSegment(Int32 index)
{
	if (!m_pSegmentMap) return NOTOK;

	TranslationMapSearch search;
	TransMapData key(index);

	TransMapData *found = search.Find(key, m_pSegmentMap, m_mSegmentCount);
	if (!found) return NOTOK;
	return Int32(found-m_pSegmentMap);
}

Int32 TranslationMaps::FindNewPoint(Int32 index)
{
	if (!m_pNewPointMap) return NOTOK;

	TranslationMapNewSearch search;
	TransMapNewData key(index);

	TransMapNewData *found = search.Find(key, m_pNewPointMap, m_mPointCount);
	if (!found) return NOTOK;
	return Int32(found-m_pNewPointMap);
}

Int32 TranslationMaps::FindNewPolygon(Int32 index)
{
	if (!m_pNewPolygonMap) return NOTOK;

	TranslationMapNewSearch search;
	TransMapNewData key(index);

	TransMapNewData *found = search.Find(key, m_pNewPolygonMap, m_mPolygonCount);
	if (!found) return NOTOK;
	return Int32(found-m_pNewPolygonMap);
}

Int32 TranslationMaps::FindNewPgon(Int32 index)
{
	if (!m_pNewPgonMap) return NOTOK;

	TranslationMapNewSearch search;
	TransMapNewData key(index);

	TransMapNewData *found = search.Find(key, m_pNewPgonMap, m_mPgonCount);
	if (!found) return NOTOK;
	return Int32(found-m_pNewPgonMap);
}

Int32 TranslationMaps::FindNewSegment(Int32 index)
{
	if (!m_pNewSegmentMap) return NOTOK;

	TranslationMapNewSearch search;
	TransMapNewData key(index);

	TransMapNewData *found = search.Find(key, m_pNewSegmentMap, m_mSegmentCount);
	if (!found) return NOTOK;
	return Int32(found-m_pNewSegmentMap);
}

Int32 TranslationMaps::FindWeldPoint(Int32 index)
{
	if (!m_pWeldMap) return NOTOK;

	TranslationMapSearchN search;
	TransIndexMapData key(-1, index);

	TransIndexMapData *found = search.Find(key, m_pWeldMap, m_mWeldCount);
	if (!found) return NOTOK;
	return Int32(found-m_pWeldMap);
}

Int32 TranslationMaps::FindMeltPolygon(Int32 index)
{
	if (!m_pMeltMap) return NOTOK;

	TranslationMapSearchN search;
	TransIndexMapData key(-1, index);

	TransIndexMapData *found = search.Find(key, m_pMeltMap, m_mMeltCount);
	if (!found) return NOTOK;
	return Int32(found-m_pMeltMap);
}
