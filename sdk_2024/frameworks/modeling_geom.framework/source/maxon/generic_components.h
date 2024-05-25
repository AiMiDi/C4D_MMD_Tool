#ifndef GENERIC_COMPONENTS_H__
#define GENERIC_COMPONENTS_H__

#include "maxon/apibase.h"
#include "maxon/array.h"
#include "maxon/arraymap.h"
#include "maxon/hybridmap.h"
#include "maxon/hashmap.h"
#include "maxon/blockarray.h"
#include "maxon/simplemesh.h"

namespace maxon
{

//----------------------------------------------------------------------------------------
/// A class that represents a Topology set indices.
/// It is composed by 3 arrays, a linear list of point indices, list of offsets that split the point list in outlines, and a list of the groups outline in complex elements (like a polygon with holes).
/// It can also represents as set of line outlines, in which case the groups array will not be used and the closed array will containe the close status for each outline.
//----------------------------------------------------------------------------------------
class TopologyContainer
{
public:
	
	TopologyContainer() = default;
	TopologyContainer(const Array<Int32>& points, const Array<Int32>& outlines, const Array<Int32>& groups) : _points(points), _outlines(outlines), _groups(groups)
	{
		_closed = nullptr;
	}
	
	TopologyContainer(const Array<Int32>& points, const Array<Int32>& outlines, const Array<Bool>& closed) : _points(points), _outlines(outlines), _closed(closed)
	{
		_groups = nullptr;
	}

	MAXON_OPERATOR_EQUALITY_HASHCODE(TopologyContainer, _points, _outlines, _groups, _closed);

	Result<void> InitPolygons(Int32 pointCount = 0, Int32 segCount = 0, Int32 gorupCount = 0)
	{
		iferr_scope;
		
		_points = ArrayFactory::NewBaseArray<Int32>() iferr_return;
		_outlines = ArrayFactory::NewBaseArray<Int32>() iferr_return;
		_groups = ArrayFactory::NewBaseArray<Int32>() iferr_return;
		
		if (pointCount > 0)
		{
			ArrayInterface<Int32>& points =	_points.MakeWritable() iferr_return;
			points.Resize(pointCount) iferr_return;
		}
		
		if (segCount > 0)
		{
			ArrayInterface<Int32>& segment =	_outlines.MakeWritable() iferr_return;
			segment.Resize(segCount) iferr_return;
		}
		
		if (gorupCount > 0)
		{
			ArrayInterface<Int32>& gruops =	_groups.MakeWritable() iferr_return;
			gruops.Resize(gorupCount) iferr_return;
		}
		
		return OK;
	}
	
	Result<void> InitLines(Int32 pointCount = 0, Int32 segCount = 0)
	{
		iferr_scope;
		
		_points = ArrayFactory::NewBaseArray<Int32>() iferr_return;
		_outlines = ArrayFactory::NewBaseArray<Int32>() iferr_return;
		_closed = ArrayFactory::NewBaseArray<Bool>() iferr_return;
		
		if (pointCount > 0)
		{
			ArrayInterface<Int32>& points =	_points.MakeWritable() iferr_return;
			points.Resize(pointCount) iferr_return;
		}
		
		if (segCount > 0)
		{
			ArrayInterface<Int32>& segment =	_outlines.MakeWritable() iferr_return;
			segment.Resize(segCount) iferr_return;
			ArrayInterface<Bool>& closed =	_closed.MakeWritable() iferr_return;
			closed.Resize(segCount) iferr_return;
		}

		return OK;
	}
	
	inline Bool IsLine() const
	{
		return _groups.GetPointer() == nullptr && _closed.GetPointer() != nullptr;
	}
	
	inline Bool IsPolygon() const
	{
		return _closed.GetPointer() == nullptr;
	}
	
	inline Bool IsPopulated() const
	{
		return _points.GetPointer() &&  _outlines.GetPointer() && _points.IsPopulated() && _outlines.IsPopulated();
	}
	
	inline Bool IsEmpty() const
	{
		return !IsPopulated();
	}
	
	inline Bool HasNgons() const
	{
		Bool hasGroups = HasGroups();
		if (hasGroups)
			return true;
		
		for (Int32 outlinePointCount : _outlines)
		{
			if (outlinePointCount > 4)
				return true;
		}
		
		return false;
	}
	
	inline Bool HasGroups() const
	{
		Bool useGroups = _groups.GetPointer() && _groups.GetCount() > 0;
		if (useGroups)
		{
			for (Int32 groupCount : _groups)
			{
				if (groupCount > 1)
					return true;
			}
		}
		return false;
	}
	
	inline Int GetGroupCount() const
	{
		if (HasGroups())
			return _groups.GetCount();
		
		return _outlines.GetCount();
	}
	
	template <typename FN> inline Result<void> ForEachPolygonInTopology(FN&& fn) const
	{
		iferr_scope;

		// this is an ugly copy, the array we receive can be pages so we can't assume they are single blocks
		BaseArray<Int32> block;
		block.CopyFrom(_points) iferr_return;
		
		BaseArray<Int32> blockOutlines;
		blockOutlines.CopyFrom(_outlines) iferr_return;

		Bool useGroups = HasGroups();
		Int32 polygonIndex = 0;
		Int32 offsetOutline = 0;
		Int32 offsetGroup = 0;
		
		if (useGroups)
		{
			for (Int32 groupCount : _groups)
			{
				if (MAXON_UNLIKELY(offsetGroup + groupCount > blockOutlines.GetCount()))
					return IllegalStateError(MAXON_SOURCE_LOCATION, "Inconsistent topology provided"_s);
				
				Int polygonPointCount = 0;
				for (Int32 outlineIndex = 0; outlineIndex < groupCount; ++outlineIndex)
				{
					polygonPointCount += blockOutlines[outlineIndex + offsetGroup];
				}
				
				if (MAXON_UNLIKELY(offsetOutline + polygonPointCount > block.GetCount()))
					return IllegalStateError(MAXON_SOURCE_LOCATION, "Inconsistent topology provided"_s);
				
				Block<const Int32> points(block.GetFirst() + offsetOutline, polygonPointCount);
				Block<const Int32> seg(blockOutlines.GetFirst() + offsetGroup, groupCount);
				
				if (points.GetCount() < 3)
					return IllegalStateError(MAXON_SOURCE_LOCATION);
				
				fn(polygonIndex, points, seg, offsetOutline, offsetGroup) iferr_return;
				
				polygonIndex++;
				offsetOutline += (Int32)polygonPointCount;
				offsetGroup += groupCount;
			}
		}
		else
		{
			for (Int32 polygonPointCount : _outlines)
			{
				if (MAXON_UNLIKELY(offsetOutline + polygonPointCount > block.GetCount()))
					return IllegalStateError(MAXON_SOURCE_LOCATION, "Inconsistent topology provided"_s);
				
				Block<const Int32> points(block.GetFirst() + offsetOutline, polygonPointCount);
				Block<const Int32> seg(blockOutlines.GetFirst() + offsetGroup, 1 );
				
				if (points.GetCount() < 3)
					return IllegalStateError(MAXON_SOURCE_LOCATION);
				
				fn(polygonIndex, points, seg, offsetOutline, 0) iferr_return;
				
				polygonIndex++;
				offsetOutline += polygonPointCount;
				offsetGroup++;
			}
		}
		
		return OK;
	}

	Array<Int32> _points; 	///<  A linear sequence of indices which represent all user polygon/polyline outlines.
	Array<Int32> _outlines;	///<  An array which contains the point  count of each outline.
	Array<Int32> _groups; ///< Containes groups for polygons
	Array<Bool> _closed; ///< Close status for lines.
};

//----------------------------------------------------------------------------------------
/// A data structire to map complex polygons to tessellation polygons
//----------------------------------------------------------------------------------------
class PolygonToTessellationMap
{
public:
	
	PolygonToTessellationMap() = default;
	
	Result<void> Resize(Int polygonCount, Int tessellationCount)
	{
		iferr_scope;
		_counts.Resize(polygonCount, COLLECTION_RESIZE_FLAGS::ON_SHRINK_KEEP_CAPACITY | COLLECTION_RESIZE_FLAGS::POD_UNINITIALIZED) iferr_return;
		_indices.Resize(tessellationCount, COLLECTION_RESIZE_FLAGS::ON_SHRINK_KEEP_CAPACITY | COLLECTION_RESIZE_FLAGS::POD_UNINITIALIZED) iferr_return;
		return OK;
	}
	
	BaseArray<Int32> _counts; 	///<  For each user polygon, store the tessellation polygon count.
	BaseArray<Int32> _indices;	///<  For each tessellation index store the corresponding user polygon index.
};

//----------------------------------------------------------------------------------------
/// Complex polygon helper class.
//----------------------------------------------------------------------------------------
class GenericPolygon
{
public:
	
	static Bool IsNgon(const Block<const Int32>& points, const Block<const Int32>& segments = Block<Int32>())
	{
		return segments.GetCount() > 1 || points.GetCount() > 4;
	}
	
	static Bool IsNgon(const Block<const Int32>& points, Int32 segmentsCount)
	{
		return segmentsCount > 1 || points.GetCount() > 4;
	}
};

//----------------------------------------------------------------------------------------
/// Class to represent an undirected edge by specifying two vertices.
/// The vertices are sorted, so upon query it is guaranteed that vertexA <= vertexB.
/// Can also store an invalid state if one of the vertices is set to INITVALUE.
//----------------------------------------------------------------------------------------
template <typename T, T INITVALUE>
class EdgePairTeamplate
{
public:
	static_assert(SIZEOF(T) == SIZEOF(UInt32), "Unexpected size.");
	MAXON_IMPLICIT EdgePairTeamplate(T vA = INITVALUE, T vB = INITVALUE) : _vA(Min(vA, vB)), _vB(Max(vA, vB)) { }
	
	HashInt GetHashCode() const
	{
		return *reinterpret_cast<const UInt*>(this);
	}

	static constexpr Bool TriviallyHashable() { return true; }

	UniqueHash GetUniqueHashCode() const
	{
		return UniqueHash::GetUniqueHashCode(ToSingletonBlock(*this));
	}

	String ToString(const FormatStatement* formatStatement = nullptr) const
	{
		return FormatString("{@, @}", _vA, _vB);
	}

	inline Bool operator ==(const EdgePairTeamplate& b) const
	{
		return _vA == b._vA && _vB == b._vB;
	}
	
	inline Bool operator <(const EdgePairTeamplate& b) const
	{
		return LexicographicalLessThan(_vA, b._vA, _vB, b._vB);
	}
	
	//----------------------------------------------------------------------------------------
	/// Returns true if both vertices have a value != NOTOK.
	/// @return												True if the edge is valid.
	//----------------------------------------------------------------------------------------
	inline Bool IsValid() const { return _vA != INITVALUE && _vB != INITVALUE && _vA <= _vB; }

	//----------------------------------------------------------------------------------------
	/// Returns true if the edge is actually a vertex (_vA == _vB).
	/// @return												True if the edge is a vertex.
	//----------------------------------------------------------------------------------------
	inline Bool IsCollapsed() const { return IsValid() && _vA == _vB; }

	MAXON_OPERATOR_COMPARISON(EdgePairTeamplate);
	
	union { T _vA = INITVALUE; T _vertexA; }; ///< First edge vertex, always <= _vB.
	union { T _vB = INITVALUE; T _vertexB; }; 	///< Second edge vertex.
};

using EdgePair = EdgePairTeamplate<Int32, NOTOK>;

//----------------------------------------------------------------------------------------
/// A more efficient way to clamp an index in a quad using bit masking, because we know the
///	size of the quad is 4 = 2^2.
/// @param[in] index	A vertex index of a quad in the range [0, 3].
/// @return						A clamped index of a quad in the range [0, 3].
//----------------------------------------------------------------------------------------
template <typename T, typename U = T, typename = std::enable_if_t<STD_IS_REPLACEMENT(arithmetic, T)>>
MAXON_ATTRIBUTE_FORCE_INLINE constexpr U ClampQuadIndex(const T index)
{
	return static_cast<U>(index & static_cast<T>(3));
}

//----------------------------------------------------------------------------------------
/// @param[in] polyVertices		Polygon vertices.
/// @param[in] edgePair				An edge pair to find the start index of given the direction of vertices in the polygon.
/// @return										The index of the start vertex in the quad.
//----------------------------------------------------------------------------------------
inline Int32 FindDirectedVertexIndexInQuad(const Block<const Int32> polyVertices, const EdgePair edgePair)
{
	DebugAssert(polyVertices.GetCount() == 4, "The object must be a quad"_s);

	const Int32 foundIndex = static_cast<Int32>(polyVertices.FindIndex(edgePair._vA));

	// Get the winding of the current edge to go in the right direction by checking whether the previous vertex is past or before.
	const Int32 prevVertexIndex = ClampQuadIndex(foundIndex - 1);

	// Clockwise ordering of elements, so the edge is already in the correct direction.
	return (polyVertices[prevVertexIndex] == static_cast<Int>(edgePair._vB)) ? prevVertexIndex : foundIndex;
}

//----------------------------------------------------------------------------------------
/// Returns the previous edge in the quad.
/// @param[in] polyVertices		Polygon vertices.
/// @param[in] edgePair				An input edge pair to get the previous edge pair for.
/// @return										The previous edge pair in the quad.
//----------------------------------------------------------------------------------------
inline EdgePair FindPrevEdgeInQuad(const Block<const Int32> polyVertices, const EdgePair edgePair)
{
	DebugAssert(polyVertices.GetCount() == 4, "The object must be a quad"_s);

	const Int foundIndex = polyVertices.FindIndex(edgePair._vA);

	// Get the winding of the current edge to go in the right direction by checking whether the previous vertex is past or before.
	const Int prevVertexIndex = ClampQuadIndex(foundIndex - 1);

	// Clockwise ordering of elements, so the edge is already in the correct direction.
	const Int32 offset = (polyVertices[prevVertexIndex] == static_cast<Int>(edgePair._vB)) ? -2 : -1;

	// Modulo 4 to get the new index in a quad.
	const Int newVertexStartIndex = ClampQuadIndex(foundIndex + offset);
	const Int newVertexEndIndex = ClampQuadIndex(newVertexStartIndex + 1);

	return EdgePair(polyVertices[newVertexStartIndex], polyVertices[newVertexEndIndex]);
}

//----------------------------------------------------------------------------------------
/// Returns the next edge in the quad.
/// @param[in] polyVertices		Polygon vertices.
/// @param[in] edgePair				An input edge pair to get the next edge pair for.
/// @return										The next edge pair in the quad.
//----------------------------------------------------------------------------------------
inline EdgePair FindNextEdgeInQuad(const Block<const Int32> polyVertices, const EdgePair edgePair)
{
	DebugAssert(polyVertices.GetCount() == 4, "The object must be a quad"_s);

	const Int foundIndex = polyVertices.FindIndex(edgePair._vA);

	// Get the winding of the current edge to go in the right direction by checking whether the previous vertex is past or before.
	const Int prevVertexIndex = ClampQuadIndex(foundIndex - 1);
	
	// Modulo 4 to get the new index in a quad.
	const Int newVertexStartIndex = (polyVertices[prevVertexIndex] == static_cast<Int>(edgePair._vB)) ? foundIndex : ClampQuadIndex(foundIndex + 1);
	const Int newVertexEndIndex = ClampQuadIndex(newVertexStartIndex + 1);

	return EdgePair(polyVertices[newVertexStartIndex], polyVertices[newVertexEndIndex]);
}

//----------------------------------------------------------------------------------------
/// @param[in] polyVertices		Polygon vertices.
/// @param[in] edgePair				An input edge pair to get the opposite edge pair of.
/// @return										The opposite edge pair in the quad.
//----------------------------------------------------------------------------------------
inline EdgePair FindOppositeDirectedEdgeInQuad(const Block<const Int32> polyVertices, const EdgePair edgePair)
{
	DebugAssert(polyVertices.GetCount() == 4, "The object must be a quad"_s);

	const Int foundIndex = polyVertices.FindIndex(edgePair._vA);

	// Get the winding of the current edge to go in the right direction by checking whether 
	const Int prevVertexIndex = ClampQuadIndex(foundIndex - 1);

	// Clockwise ordering of elements, so the edge is already in the correct direction.
	const Int32 offset = (polyVertices[prevVertexIndex] == static_cast<Int>(edgePair._vB)) ? 1 : 2;

	// Modulo 4 to get the new index in a quad.
	const Int newVertexStartIndex = ClampQuadIndex(foundIndex + offset);
	const Int newVertexEndIndex = ClampQuadIndex(newVertexStartIndex + 1);

	return EdgePair(polyVertices[newVertexStartIndex], polyVertices[newVertexEndIndex]);
}

template <typename STORAGEINDEX, typename T = void>
struct SelectionWrapper
{
	Bool IsSelected(STORAGEINDEX index) const
	{
		return false;
	}
};

namespace neighbor
{

template <typename STORAGEINDEX>
struct Info
{
	STORAGEINDEX face[4];
	STORAGEINDEX edge[4];
	Char mark[4];
};

template <typename STORAGEINDEX>
static inline Int32 UsesEdge(const SimplePolygon& v, STORAGEINDEX aa, STORAGEINDEX bb)
{
	if ((v.a == aa && v.b == bb) || (v.a == bb && v.b == aa))
		return 0;
	else if ((v.b == aa && v.c == bb) || (v.b == bb && v.c == aa))
		return 1;
	else if ((v.c == aa && v.d == bb) || (v.c == bb && v.d == aa))
		return 2;
	else if ((v.d == aa && v.a == bb) || (v.d == bb && v.a == aa))
		return 3;
	else
		return NOTOK;
}

template <typename STORAGEINDEX>
struct NeighborStorage;

template <typename STORAGEINDEX, typename FILTER = SelectionWrapper<STORAGEINDEX>>
struct InfoStorage
{
	Result<void> Init(Int32 pointCount, const Block<const SimplePolygon>& polygons, const NeighborStorage<STORAGEINDEX>& storage, const FILTER* filter)
	{
		iferr_scope;

		Int32 ldat[5];

		polyCount = polygons.GetCount();
		pntCount	= (Int)pointCount;

		if (polyCount <= 0)
			return IllegalStateError(MAXON_SOURCE_LOCATION);

		info.Resize(polyCount, COLLECTION_RESIZE_FLAGS::ON_GROW_FIT_TO_SIZE) iferr_return;
		Int32 side = 0;

		for (Int32 i = 0; i < polyCount; i++)
		{
			if (filter && !filter->IsSelected(i)) // selection handling
			{
				info[i].mark[0] = info[i].mark[1] = info[i].mark[2] = info[i].mark[3] = true;
				info[i].face[0] = info[i].face[1] = info[i].face[2] = info[i].face[3] = NOTOK;
				info[i].edge[0] = info[i].edge[1] = info[i].edge[2] = info[i].edge[3] = 0;
				continue;
			}

			ldat[0] = ldat[4] = polygons[i].a;
			ldat[1] = polygons[i].b;
			ldat[2] = polygons[i].c;
			ldat[3] = polygons[i].d;

			for (Int32 j = 0; j < 4; j++)
			{
				if (j == 2 && polygons[i].c == polygons[i].d)
				{
					info[i].face[2] = NOTOK;
					info[i].mark[2] = true;
					continue;
				}

				if (info[i].mark[j])
					continue;

				// Fill information about neighbor
				const Int32 face = storage.GetNeighbor(ldat[j], ldat[j+1], i, side, polygons);
				if (face != NOTOK && info[face].mark[side])
				{
					info[i].face[j] = NOTOK;
					info[i].edge[j] = (Int32)edgeCount++;
					continue; // multiple polygons attached to edge; MUST NOT BE inserted as no edges are going to be created!
				}

				info[i].face[j] = face;
				info[i].edge[j] = (Int32)edgeCount;

				// Fill neighbor's structure also
				if (face != NOTOK)
				{
					info[face].face[side] = i;
					info[face].edge[side] = (Int32)edgeCount;
					info[face].mark[side] = true;
				}
				edgeCount++;
			}
		}

		return OK;
	}
	
	BaseArray<Info<STORAGEINDEX>> info;
	Int pntCount = 0;
	Int polyCount= 0;
	Int edgeCount = 0;
};

template <typename STORAGEINDEX>
struct NeighborStorage
{
	using NeighborStorageType = NeighborStorage<STORAGEINDEX>;
	
	// Can we use just blocks and not SimplePolygon?
	Result<void> Init(const Block<const SimplePolygon>& polygons, STORAGEINDEX pointCount)
	{
		iferr_scope;

		if (pointCount == 0)
		{
			polygonCountPerPoint.Reset();
			offsetInPolygonListPerPoint.Reset();
			return OK;
		}
		// resize the arrays to store the count per point, offset.
		polygonCountPerPoint.Resize(pointCount, COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE) iferr_return;
		offsetInPolygonListPerPoint.Resize(pointCount, COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE | COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) iferr_return;

		// for each point, count how many polygons are adjacent to it.
		for (const SimplePolygon& simplePolygon : polygons)
		{
			polygonCountPerPoint[simplePolygon.a]++;
			polygonCountPerPoint[simplePolygon.b]++;
			polygonCountPerPoint[simplePolygon.c]++;
			if (simplePolygon.c != simplePolygon.d)
				polygonCountPerPoint[simplePolygon.d]++;
		}

		// for each point, determine at what position will the polygon list start. polygon list for point 0 will always start at index 0
		offsetInPolygonListPerPoint[0] = 0; // first point always has 0 offset.
		for (Int32 point = 1; point < pointCount; ++point)
		{
			offsetInPolygonListPerPoint[point] = offsetInPolygonListPerPoint[point - 1] + polygonCountPerPoint[point - 1];
		}

		// calculate how many polygon-point pairs we have (basically, the number of corners of polygons)
		STORAGEINDEX polygonPointPairCount = offsetInPolygonListPerPoint[pointCount - 1] + polygonCountPerPoint[pointCount - 1];

		// Build the polygon list.
		polygonList.Resize(polygonPointPairCount, COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE | COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) iferr_return;

		Int32 polygonCount = static_cast<Int32>(polygons.GetCount());
		for (Int32 polygonIdx = 0; polygonIdx < polygonCount; ++polygonIdx)
		{
			const SimplePolygon& simplePolygon = polygons[polygonIdx];
			polygonList[offsetInPolygonListPerPoint[simplePolygon.a]++] = polygonIdx;
			polygonList[offsetInPolygonListPerPoint[simplePolygon.b]++] = polygonIdx;
			polygonList[offsetInPolygonListPerPoint[simplePolygon.c]++] = polygonIdx;
			if (simplePolygon.c != simplePolygon.d)
			{
				polygonList[offsetInPolygonListPerPoint[simplePolygon.d]++] = polygonIdx;
			}
		}

		// rebuild offset again. (this is slighly faster than creating an extra copy to be modified and not touching this one)
		offsetInPolygonListPerPoint[0] = 0; // first point always has 0 offset.
		for (Int32 point = 1; point < pointCount; ++point)
		{
			offsetInPolygonListPerPoint[point] = offsetInPolygonListPerPoint[point - 1] + polygonCountPerPoint[point - 1];
		}

		return OK;
	}

	Int32 GetNeighbor(STORAGEINDEX a, STORAGEINDEX b, STORAGEINDEX mypoly, Int32& side, const Block<const SimplePolygon>& polygons) const
	{
		STORAGEINDEX ind = offsetInPolygonListPerPoint[a];
		STORAGEINDEX cnt = polygonCountPerPoint[a];

		STORAGEINDEX ind2 = offsetInPolygonListPerPoint[b];
		STORAGEINDEX cnt2 = polygonCountPerPoint[b];

		if (cnt2 < cnt) // use smaller valency
		{
			ind = ind2;
			cnt = cnt2;
		}

		for (Int32 i = 0; i < cnt; i++)
		{
			STORAGEINDEX polynr = polygonList[ind + i];
			if (polynr == mypoly)
				continue;
			side = UsesEdge(polygons[polynr], a, b);
			if (side != NOTOK)
				return polynr;
		}

		return NOTOK;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE const Block<const Int32> GetPolygonList(STORAGEINDEX pointIndex) const
	{
		return { polygonList.GetFirst() + offsetInPolygonListPerPoint[pointIndex], polygonCountPerPoint[pointIndex] };
	}

	void Flush()
	{
		polygonCountPerPoint.Flush();
		offsetInPolygonListPerPoint.Flush();
		polygonList.Flush();
	}

	BaseArray<STORAGEINDEX> polygonCountPerPoint;
	BaseArray<STORAGEINDEX> offsetInPolygonListPerPoint;
	BaseArray<STORAGEINDEX> polygonList;
};

template <typename STORAGEINDEX, STORAGEINDEX NONMANIFOLDVALUE, STORAGEINDEX INVALIDVALUE>
struct EdgeNeigborPolygonsTemplate
{
	static_assert(SIZEOF(STORAGEINDEX) == SIZEOF(Int32), "Unexpected size."); // for now works only with 32 bit size
	
	using SmallMapSelector = ArrayMapSelector<false, DefaultCompare, BufferedBaseArraySelector<6>>;
	using Map = BlockArray<HybridMap<STORAGEINDEX, EdgeNeigborPolygonsTemplate, SmallMapSelector, HashMapSelector<>, 20, -1>, 10, BLOCKARRAYFLAGS::NOINSERTERASE>;
	using EdgePolygons = EdgeNeigborPolygonsTemplate<STORAGEINDEX, NONMANIFOLDVALUE, INVALIDVALUE>;
	using NonManifoldStroage = BaseArray<BaseArray<STORAGEINDEX>>;
	static constexpr STORAGEINDEX NONMANIFOLD = NONMANIFOLDVALUE;

	MAXON_OPERATOR_EQUALITY(EdgePolygons, _polyA, _polyB);

	inline Bool IsNonManifold() const
	{
		return _polyA == NONMANIFOLD;
	}

	inline void SetNonManifold(STORAGEINDEX mapEntry)
	{
		_polyA = NONMANIFOLD;
		_polyB = mapEntry;
	}
	
	inline STORAGEINDEX GetNonManifoldIndex() const
	{
		DebugAssert(IsNonManifold());
		return _polyB;
	}

	void Reset()
	{
		_polyA = INVALIDVALUE;
		_polyB = INVALIDVALUE;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE HashInt GetHashCode() const
	{
		static_assert(SIZEOF(EdgeNeigborPolygonsTemplate) == SIZEOF(UInt64), "Unexpected size.");
		return UInt(Int(_polyA) << 32 | _polyB);
	}
	
	template <typename INDEX = STORAGEINDEX, Bool USEMAP>
	static Result<void> StoreSinglePolygon(const Block<const INDEX>& cPolygon, INDEX polygonIndex, const Block<const INDEX>& polygonMap, EdgePolygons::Map& map, NonManifoldStroage& nonManifold)
	{
		iferr_scope;
		Int32 count = (Int32)cPolygon.GetCount();
		for (Int32 pIndex = 0; pIndex < cPolygon.GetCount(); ++pIndex)
		{
			Int32 next = GetSuccessor(pIndex, count);
			Bool created = false;
			STORAGEINDEX a = (STORAGEINDEX)cPolygon[pIndex];
			STORAGEINDEX b = (STORAGEINDEX)cPolygon[next];
			if (a > b)
				Swap(a, b);
			if (a >= map.GetCount())
			{
				map.Resize(a + 1, COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY) iferr_return;
			}
			EdgePolygons& value = map[a].InsertKey(b, created) iferr_return;
			STORAGEINDEX realPolygonIndex = USEMAP ? (STORAGEINDEX)polygonMap[polygonIndex] : (STORAGEINDEX)polygonIndex;
			if (created)
			{
				value._polyA = realPolygonIndex;
			}
			else
			{
				if (value._polyB == INVALIDVALUE)
				{
					value._polyB = realPolygonIndex;
				}
				else
				{
					if (!value.IsNonManifold())
					{
						STORAGEINDEX index = (STORAGEINDEX)nonManifold.GetCount();
						BaseArray<STORAGEINDEX>& array = nonManifold.Append() iferr_return;
						array.Resize(3) iferr_return;
						array[0] = value._polyA;
						array[1] = value._polyB;
						array[2] = realPolygonIndex;
						value.SetNonManifold(index);
					}
					else
					{
						STORAGEINDEX index = value.GetNonManifoldIndex();
						BaseArray<STORAGEINDEX>& array = nonManifold[index];
						array.Append(realPolygonIndex) iferr_return;
					}
				}
			}
		}
		
		return OK;
	}
	
	static const Block<const STORAGEINDEX> GetEdgePolygons(STORAGEINDEX pointA, STORAGEINDEX pointB, const EdgePolygons::Map& map, const NonManifoldStroage& nonManifold)
	{
		if (pointA > pointB)
			Swap(pointA, pointB);
		
		const EdgePolygons* value = (pointA < map.GetCount()) ? map[pointA].FindValue(pointB) : nullptr;
		if (value)
		{
			if (MAXON_UNLIKELY(value->IsNonManifold()))
			{
				const BaseArray<STORAGEINDEX>& array = nonManifold[value->GetNonManifoldIndex()];
				return array;
			}
			
			const Block<const STORAGEINDEX> block(&(value->_polyA), value->_polyB == INVALIDVALUE ? 1 : 2);
			return block;
		}
		return {};
	}
	
	STORAGEINDEX _polyA = INVALIDVALUE;
	STORAGEINDEX _polyB = INVALIDVALUE;
};

} // namespace neighbor

using IndexType = Int32;
using EdgeNeigborPolygons = neighbor::EdgeNeigborPolygonsTemplate<IndexType, LIMIT<IndexType>::MAX, NOTOK>;

} // namespace maxon

#endif // GENERIC_COMPONENTS_H__
