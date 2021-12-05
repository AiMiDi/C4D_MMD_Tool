#include "lib_ngon.h"

#ifdef __API_INTERN__
#include "polygonobject.h"
#include "basemath.h"
#else
#include "c4d_baseobject.h"
#include "c4d_tools.h"
#endif

#include "c4d_general.h"

Ngon::Ngon()
{
	points = nullptr;
	segments = nullptr;
	count = 0;
	segcount = 0;
}

Ngon::~Ngon()
{
	Free();
}

Ngon::Ngon(const CPolygon &ply)
{
	points = nullptr;
	segments = nullptr;
	count = 0;
	segcount = 0;

	if (ply.c == ply.d)
	{
		if (!Alloc(3, 1)) return;
		points[0] = ply.a;
		points[1] = ply.b;
		points[2] = ply.c;
		segments[0] = 3;
	}
	else
	{
		if (!Alloc(4, 1)) return;
		points[0] = ply.a;
		points[1] = ply.b;
		points[2] = ply.c;
		points[3] = ply.d;
		segments[0] = 4;
	}
}

Ngon::Ngon(const Ngon &src)
{
	points = nullptr;
	segments = nullptr;
	count = 0;
	segcount = 0;
	CopyFrom(&src);
}

Ngon &Ngon::operator =(const Ngon &src)
{
	CopyFrom(&src);
	return *this;
}

Bool Ngon::Alloc(Int32 cnt, Int32 scnt)
{
	Free();

	if (cnt)
	{
		iferr (points = NewMemClear(Int32, cnt))
			return false;

		if (scnt)
		{
			iferr (segments = NewMemClear(Int32, scnt))
			{
				DeleteMem(points);
				return false;
			}
		}

		count = cnt;
		segcount = scnt;
		return true;
	}

	return false;
}

void Ngon::Free()
{
	DeleteMem(points);
	DeleteMem(segments);
	count = 0;
	segcount = 0;
}

Bool Ngon::CopyFrom(const Ngon *src)
{
	Free();

	if (src && src->points && src->count)
	{
		iferr (points = NewMem(Int32, src->count))
			return false;

		if (src->segments && src->segcount)
		{
			iferr (segments = NewMem(Int32, src->segcount))
			{
				Free();
				return false;
			}
		}

		segcount = src->segcount;
		count = src->count;

		CopyMemType(src->points, points, count);
		if (segments) CopyMemType(src->segments, segments, segcount);
	}

	return true;
}

Bool Ngon::CopyFrom(Int32 cnt, Int32 scnt, Int32* pts, Int32* segs)
{
	Free();

	if (pts && cnt)
	{
		iferr (points = NewMem(Int32, cnt))
			return false;

		if (segs && scnt)
		{
			iferr (segments = NewMem(Int32, scnt))
			{
				Free();
				return false;
			}
			segcount = scnt;
		}
		else
		{
			segcount = 1;
			iferr (segments = NewMem(Int32, segcount))
			{
				Free();
				return false;
			}
		}

		count = cnt;

		CopyMemType(pts, points, count);
		if (segs)
			CopyMemType(segs, segments, segcount);
		else
			segments[0] = cnt;
	}
	return true;
}

void Ngon::Release()
{
	points = nullptr;
	segments = nullptr;
	count = 0;
	segcount = 0;
}

static Float CalcDet(const Vector &v1, const Vector &v2, const Vector &v3)
{
	return v1.x * (v2.y - v3.y) + v2.x * (v3.y - v1.y) + v3.x * (v1.y - v2.y);
}

Float Ngon::CalcArea(Int32 seg, const Vector* p, Matrix& m)
{
	Float a = 0.0f;
	Int32 l, o = 0;
	Vector v1(DC), v2(DC), v3(DC);

	if (segments[seg] < 3)
		return 0.0f;

	if (seg == 0)
	{
		// the matrix m is used to project the ngon onto a plane
		Vector n, prev(DC);

		v1 = p[points[0]];
		prev = p[points[1]] - v1;
		for (l = 2; l < segments[0]; l++)
		{
			v2 = p[points[l]] - v1;
			n += Cross(prev, v2);
			prev = v2;
		}

		m.off = Vector64(0.0);
		m.sqmat.v3 = !n;
		if (Abs(n.x) > Abs(n.y) && Abs(n.x) > Abs(n.z))
		{
			m.sqmat.v1 = Cross(Vector(0.0, 1.0, 0.0), m.sqmat.v3); // x axis
			m.sqmat.v2 = Cross(m.sqmat.v3, m.sqmat.v1); // y axis
		}
		else if (Abs(n.y) > Abs(n.z))
		{
			m.sqmat.v1 = Cross(m.sqmat.v3, Vector(0.0, 0.0, 1.0));
			m.sqmat.v2 = Cross(m.sqmat.v3, m.sqmat.v1);
		}
		else
		{
			m.sqmat.v2 = Cross(m.sqmat.v3, Vector(1.0, 0.0, 0.0));
			m.sqmat.v1 = Cross(m.sqmat.v2, m.sqmat.v3);
		}
		m = ~m;
	}

	for (l = 0; l < seg; l++)
		o += segments[l];

	v1 = m * p[points[o]];
	v2 = m * p[points[o + 1]];
	for (l = 0; l < segments[seg]; l++)
	{
		v3 = m * p[points[o + (l + 2) % segments[seg]]];
		a += CalcDet(v1, v2, v3);
		v1 = v2;
		v2 = v3;
	}

	return a;
}

//////////////////////////////////////////////////////////////////////////

NgonBaseLib *lib_ngonbase = nullptr;

static NgonBaseLib *CheckNgonBaseLib(Int32 offset)
{
	return (NgonBaseLib*)CheckLib(LIBRARY_NGON, offset, (C4DLibrary**)&lib_ngonbase);
}

#define NgonBaseLibCall(b) 		NgonBaseLib *lib = CheckNgonBaseLib(LIBOFFSET(NgonBaseLib, b)); \
															if (!lib || !lib->b) return; \
															(((iNgonBase*)this)->*lib->b)

#define NgonBaseLibCallR(a, b)  NgonBaseLib *lib = CheckNgonBaseLib(LIBOFFSET(NgonBaseLib, b)); \
															if (!lib || !lib->b) return a; \
															return (((iNgonBase*)this)->*lib->b)

NgonBase* NgonBase::Alloc()
{
	NgonBaseLib *lib = CheckNgonBaseLib(LIBOFFSET(NgonBaseLib, Alloc)); if (!lib) return nullptr;
	return (NgonBase*)lib->Alloc();
}

void NgonBase::Free(NgonBase *&p)
{
	if (!p) return;
	NgonBaseLib *lib = CheckNgonBaseLib(LIBOFFSET(NgonBaseLib, Free)); if (!lib) return;
	iNgonBase* i = (iNgonBase*)p;
	lib->Free(i);
	p = nullptr;
}

Bool NgonBase::CopyTo(NgonBase *dst)
{
	NgonBaseLibCallR(false, CopyTo)((iNgonBase*)dst);
}

Bool NgonBase::Write(HyperFile *hf)
{
	NgonBaseLibCallR(false, Write)(hf);
}

Bool NgonBase::Read(HyperFile *hf, Int32 id, Int32 level)
{
	NgonBaseLibCallR(false, Read)(hf, id, level);
}

Bool NgonBase::Translate(VariableChanged *vc)
{
	NgonBaseLibCallR(false, Translate)(vc);
}

Bool NgonBase::Changed(PolygonObject *op)
{
	NgonBaseLibCallR(false, Changed)(op);
}

UChar NgonBase::GetEdgeStates(Int32 id) const
{
	NgonBaseLibCallR(false, GetEdgeStates)(id);
}

Int32 NgonBase::GetCount() const
{
	NgonBaseLibCallR(0, GetCount)();
}

Pgon *NgonBase::GetNgons()
{
	NgonBaseLibCallR(nullptr, GetNgons)();
}

Bool NgonBase::Resize(Int32 cnt)
{
	NgonBaseLibCallR(false, Resize)(cnt);
}

Int32 NgonBase::FindPolygon(Int32 id, Int32 l) const
{
	NgonBaseLibCallR(NOTOK, FindPolygon)(id, l);
}

Bool NgonBase::CompactPgons()
{
	NgonBaseLibCallR(false, CompactPgons)();
}

void NgonBase::CheckPoints(PolygonObject *op)
{
	NgonBaseLibCall(CheckPoints)(op);
}

void NgonBase::UpdateNgons(PolygonObject *op)
{
	NgonBaseLibCall(UpdateNgons)(op);
}

Bool NgonBase::ResetPoints(PolygonObject *op)
{
	NgonBaseLibCallR(false, ResetPoints)(op);
}

void NgonBase::SetFlags(Int32 flgs)
{
	NgonBaseLibCall(SetFlags)(flgs);
}

Int32 NgonBase::GetFlags() const
{
	NgonBaseLibCallR(false, GetFlags)();
}

Int32 NgonBase::GetDirtyCount() const
{
	NgonBaseLibCallR(false, GetDirtyCount)();
}

void NgonBase::Dirty()
{
	NgonBaseLibCall(Dirty)();
}

void NgonBase::InitMap()
{
	NgonBaseLibCall(InitMap)();
}

void NgonBase::FreeMap()
{
	NgonBaseLibCall(FreeMap)();
}

Bool NgonBase::Remove(Int32 id, Bool force)
{
	NgonBaseLibCallR(false, Remove)(id, force);
}

Bool NgonBase::ToSelect(BaseSelect *pSelect, Int32 mode)
{
	NgonBaseLibCallR(false, ToSelect)(pSelect, mode);
}

void NgonBase::GetCenter(Int32 id, const CPolygon *vadr, const Vector *padr, Vector *ip, Vector *in)
{
	NgonBaseLibCall(GetCenter)(id, vadr, padr, ip, in);
}

Bool NgonBase::RemapEdge(Int32 oedge, Int32 *nedges, Int32 ncnt)
{
	NgonBaseLibCallR(false, RemapEdge)(oedge, nedges, ncnt);
}

Bool NgonBase::Create(UInt32 *nedges, Int32 ncnt)
{
	NgonBaseLibCallR(false, Create)(nedges, ncnt);
}

Bool NgonBase::RemapPolygon(Int32 oply, Int32 nply)
{
	NgonBaseLibCallR(false, RemapPolygon)(oply, nply);
}

Bool NgonBase::Copy(Pgon *src, Pgon *dst)
{
	NgonBaseLibCallR(false, Copy)(src, dst);
}

Bool NgonBase::Validate(PolygonObject *op)
{
	NgonBaseLibCallR(false, Validate)(op);
}

Bool NgonBase::IsValidNgon(Pgon *pgon, const CPolygon *vadr)
{
	NgonBaseLibCallR(false, IsValidNgon)(pgon, vadr);
}

Int32 NgonBase::BuildNgon(Int32 *inner, Int32 *outer, Int32 icnt, Int32 ocnt, const CPolygon *vadr, const Vector *padr)
{
	NgonBaseLibCallR(NOTOK, BuildNgon)(inner, outer, icnt, ocnt, vadr, padr);
}

Int32 NgonBase::BuildNgonFromPolys(Int32 *polys, Int32 *outer, Int32 pcnt, Int32 ocnt, const CPolygon *vadr, const Vector *padr)
{
	NgonBaseLibCallR(NOTOK, BuildNgonFromPolys)(polys, outer, pcnt, ocnt, vadr, padr);
}

Bool NgonBase::Verify(const CPolygon *vadr, Int32 vcnt, UInt32 flags, Pgon *pgon)
{
	NgonBaseLibCallR(false, Verify)(vadr, vcnt, flags, pgon);
}

Pgon *NgonBase::AllocNgon(Int32 edge_cnt)
{
	NgonBaseLibCallR(nullptr, AllocNgon)(edge_cnt);
}

void NgonBase::FreeNgon(Pgon *&pgon)
{
	NgonBaseLibCall(FreeNgon)(pgon);
}

Bool NgonBase::SetNgon(Int32 index, Pgon *src)
{
	NgonBaseLibCallR(false, SetNgon)(index, src);
}

Bool NgonBase::SetNgon(Int32 index, UInt32 *edges, Int32 edge_cnt)
{
	NgonBaseLibCallR(false, SetNgonE)(index, edges, edge_cnt);
}

//////////////////////////////////////////////////////////////////////////

Vector Pgon::CalcNormal(const Vector* padr, const CPolygon* polys) const
{
	Vector v;
	Int32 i;
	for (i = 0; i < m_Count; i++)
	{
		if (!m_Edge[i].IsFirst()) continue;

		const CPolygon &p = polys[m_Edge[i].ID()];

		if (p.c == p.d)
			v += Cross((padr[p.b]-padr[p.a]), (padr[p.c]-padr[p.a]));
		else
			v += Cross((padr[p.b]-padr[p.d]), (padr[p.c]-padr[p.a]));
	}
	return !v;
}

void Pgon::GetMpRad(const Vector* padr, const CPolygon* polys, Vector &mp, Vector &rad) const
{
	MinMax mm;
	Int32 i;
	for (i = 0; i < m_Count; i++)
	{
		if (!m_Edge[i].IsFirst()) continue;

		const CPolygon &p = polys[m_Edge[i].ID()];
		mm.AddPoint(padr[p.a]);
		mm.AddPoint(padr[p.b]);
		mm.AddPoint(padr[p.c]);
		if (p.c != p.d)
			mm.AddPoint(padr[p.d]);
	}
	mm.GetMpRad(&mp, &rad);
}

Int32 Pgon::GetSegmentCount() const
{
	Int32 s = 0, e;

	if (m_Count < 1 || !m_Edge) return 0;

	for (e = 0; e < m_Count; e++)
	{
		if (m_Edge[e].IsSegmentEnd()) s++;
	}

	return s;
}

Int32 Pgon::GetSegmentLen(Int32 startedge) const
{
	Int32 e;
	for (e = startedge; e < m_Count; e++)
	{
		if (m_Edge[e].IsSegmentEnd()) return (e-startedge+1);
	}
	return -1;
}

Int32 Pgon::FindPolygon(Int32 id) const
{
	if (id < 0 || !m_Edge) return -1;

	for (Int32 i = 0; i < m_Count; i++)
	{
		if ((m_Edge[i].ID()) == id) return i;
	}

	return -1;
}

UChar Pgon::GetEdgeState(Int32 id) const
{
	UChar state = 0;

	for (Int32 n = 0; n < m_Count; n++)
	{
		if ((m_Edge[n].ID()) == id)
		{
			state = state|(UChar)m_Edge[n].State();
		}
	}

	return ~state;
}

Int32 Pgon::GetPointCount() const
{
	Int32 cnt = 0;

	for (Int32 n = 0; n < m_Count; n++)
	{
		if (m_Edge[n].Edge() != NOTOK) cnt++;
	}

	return cnt;
}

Int32 Pgon::GetPolygonCount() const
{
	Int32 cnt = 0;

	for (Int32 n = 0; n < m_Count; n++)
	{
		if (m_Edge[n].IsFirst()) cnt++;
	}

	return cnt;
}

void Pgon::UpdateStates()
{
	Int32 i, l, id;

	for (i = 0; i < m_Count; i++)
	{
		m_Edge[i].edge_index &= PGONEDGE_RESET;
	}

	for (i = 0; i < m_Count; i++)
	{
		if (!(m_Edge[i].edge_index&PGONEDGE_REPEAT))
		{
			id = m_Edge[i].ID();
			for (l = i+1; l < m_Count; l++)
			{
				if (m_Edge[l].ID() == id)
				{
					m_Edge[l].edge_index |= PGONEDGE_REPEAT;
				}
			}
		}
	}
}

void PgonEdge::GetEdge(const CPolygon *vadr, Int32 &p1, Int32 &p2)
{
	const CPolygon &ply = vadr[ID()];
	switch (Edge())
	{
		case -1: p1 = NOTINDEX; p2 = NOTINDEX; break;
		case 0: p1 = ply.a; p2 = ply.b; break;
		case 1: p1 = ply.b; p2 = ply.c; break;
		case 2: p1 = ply.c; p2 = ply.d; break;
		case 3: p1 = ply.d; p2 = ply.a; break;
	}
}

void PgonEdge::RemapPolygon(Int32 new_poly, Int32 new_edge)
{
	Int32 oldid = ID(), edge = Edge();

	if ((new_poly == oldid || new_poly == NOTINDEX) && (new_edge == edge || new_edge == NOTINDEX)) return;

	if (new_edge != NOTINDEX) edge = new_edge;
	if (new_poly != NOTINDEX) oldid = new_poly;

	if (edge != NOTOK)
		edge_index = (oldid*4+edge)|(edge_index&(PGONEDGE_ENDSEGMENT|PGONEDGE_REPEAT));
	else
		edge_index = (oldid*4)|PGONEDGE_NOEDGES|(edge_index&(PGONEDGE_ENDSEGMENT|PGONEDGE_REPEAT));
}
