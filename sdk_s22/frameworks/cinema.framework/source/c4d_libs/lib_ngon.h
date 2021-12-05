/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_NGON_H__
#define LIB_NGON_H__

#include "c4d_library.h"

class iNgonBase;
class NgonCache;
class HyperFile;
struct VariableChanged;
class PolygonObject;

/// @addtogroup group_ngonlibrary Ngon
/// @ingroup group_library
/// @{

class Ngon
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	Ngon();

	//----------------------------------------------------------------------------------------
	/// Destructor.
	//----------------------------------------------------------------------------------------
	~Ngon();

	//----------------------------------------------------------------------------------------
	/// Constructor from polygon in @formatParam{ply}.
	/// @param[in] ply								A polygon.
	//----------------------------------------------------------------------------------------
	explicit Ngon(const CPolygon &ply);

	//----------------------------------------------------------------------------------------
	/// Copy constructor from another N-gon in @formatParam{src}.
	/// @param[in] src								Another N-gon.
	//----------------------------------------------------------------------------------------
	Ngon(const Ngon &src);

	//----------------------------------------------------------------------------------------
	/// Assignment operator.
	/// @param[in] src								Another N-gon.
	/// @return												The assigned N-gon.
	//----------------------------------------------------------------------------------------
	Ngon &operator =(const Ngon &src);

	//----------------------------------------------------------------------------------------
	/// Allocates data for @formatParam{cnt} points and @formatParam{scnt} segments.
	/// @param[in] cnt								The point count.
	/// @param[in] scnt								The segment count.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Alloc(Int32 cnt, Int32 scnt);

	//----------------------------------------------------------------------------------------
	/// Frees the internal data.
	//----------------------------------------------------------------------------------------
	void Free();

	//----------------------------------------------------------------------------------------
	/// Copies data from @formatParam{src}.
	/// @param[in] src								The source N-gon.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CopyFrom(const Ngon *src);

	//----------------------------------------------------------------------------------------
	/// Copies data from the passed arrays.
	/// @param[in] cnt								The point count.
	/// @param[in] scnt								The segment count.
	/// @param[in] pts								The points array. @callerOwnsPointed{array}
	/// @param[in] segs								The segments array. @callerOwnsPointed{array}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CopyFrom(Int32 cnt, Int32 scnt, Int32* pts, Int32* segs);

	//----------------------------------------------------------------------------------------
	/// Releases the internal arrays, i.e. so that they are not freed by the destructor.
	//----------------------------------------------------------------------------------------
	void Release();

	//----------------------------------------------------------------------------------------
	/// Calculates the N-gon area.
	/// @param[in] seg								The segment.
	/// @param[in] p									The points array.
	/// @param[in] m									The projection matrix.
	/// @return												The calculated area.
	//----------------------------------------------------------------------------------------
	Float CalcArea(Int32 seg, const Vector* p, Matrix& m);

	Int32	*points;				///< Point array.
	Int32	*segments;			///< Segments array.
	Int32	count;					///< Point count.
	Int32	segcount;				///< Segment count.
};

#ifndef NOTINDEX
#define NOTINDEX				(LIMIT<Int32>::MAX)			///< Invalid index.
#endif

/// @addtogroup PGONEDGE
/// @ingroup group_enumeration
/// @{
#define PGONEDGE_REPEAT				(0x80000000)			///< Repeat. @markPrivate Use the convenience functions in PgonEdge.
#define PGONEDGE_RESET				(0x7FFFFFFF)			///< Reset. @markPrivate Use the convenience functions in PgonEdge.
#define PGONEDGE_NOEDGES			(0x40000000)			///< No edges on any of the N-gon edges. @markPrivate Use the convenience functions in PgonEdge.
#define PGONEDGE_EDGEINDEX		(0x1FFFFFFF)			///< Edge index mask. @markPrivate Use the convenience functions in PgonEdge.
#define PGONEDGE_ENDSEGMENT		(0x20000000)			///< End segment. @markPrivate Use the convenience functions in PgonEdge.
/// @}

class PgonEdge
{
public:
	//----------------------------------------------------------------------------------------
	/// Checks if the polygon ID is the first occurrence in the array. This is useful to know which polygons form the N-gon.
	/// @return												@trueIfOtherwiseFalse{the polygon ID is the first occurrence in the array}
	//----------------------------------------------------------------------------------------
	inline Bool IsFirst()
	{
		return !(edge_index&PGONEDGE_REPEAT);
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the edge is the last in a segment.
	/// @return												@trueIfOtherwiseFalse{the edge is the last in a segment}
	//----------------------------------------------------------------------------------------
	inline Bool IsSegmentEnd()
	{
		return (edge_index&PGONEDGE_ENDSEGMENT) != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the polygon ID.
	/// @return												The polygon ID.
	//----------------------------------------------------------------------------------------
	inline Int32 ID()
	{
		return (edge_index&PGONEDGE_EDGEINDEX)/4;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the edge state.
	/// @return												The edge as a bit, or @em 0 if the polygon has no edge on the outer/inner of the N-gon.
	//----------------------------------------------------------------------------------------
	inline Int32 State()
	{
		Int32 edge = Edge();
		if (edge == NOTOK) return 0;
		return 1 << edge;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the edge for the polygon.
	/// @return												The edge of the polygon, or @ref NOTOK for no edge.
	//----------------------------------------------------------------------------------------
	inline Int32 Edge()
	{
		if (edge_index&PGONEDGE_NOEDGES) return NOTOK;
		return (edge_index&PGONEDGE_EDGEINDEX)%4;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the edge index.
	/// @return												The edge index: @em 4 * polygon ID + edge.
	//----------------------------------------------------------------------------------------
	inline Int32 EdgeIndex()
	{
		if (edge_index&PGONEDGE_NOEDGES) return NOTOK;
		return edge_index&PGONEDGE_EDGEINDEX;
	}

	//----------------------------------------------------------------------------------------
	/// Retrieves in @formatParam{p1} and @formatParam{p2} the point IDs for the edge or @ref NOTINDEX if it is not an N-gon edge.
	/// @param[in] vadr								The polygon array. @callerOwnsPointed{array}
	/// @param[out] p1								Assigned the first point ID.
	/// @param[out] p2								Assigned the second point ID.
	//----------------------------------------------------------------------------------------
	void GetEdge(const CPolygon *vadr, Int32 &p1, Int32 &p2);

	//----------------------------------------------------------------------------------------
	/// Sets the polygon ID and edge ID for the edge. Pass @ref NOTINDEX to make no change.
	/// @param[in] new_poly						The new polygon ID.
	/// @param[in] new_edge						The new edge ID.
	//----------------------------------------------------------------------------------------
	void RemapPolygon(Int32 new_poly, Int32 new_edge);

	UInt32	edge_index;			///< Edge index.
};

#ifndef NGONBASE_H__
class Pgon
{
public:

	//----------------------------------------------------------------------------------------
	/// Calculates the normal for the N-gon.
	/// @param[in] padr								The point array. @callerOwnsPointed{array}
	/// @param[in] polys							The polygons array. @callerOwnsPointed{array}
	/// @return												The calculated normal.
	//----------------------------------------------------------------------------------------
	Vector CalcNormal(const Vector* padr, const CPolygon* polys) const;

	//----------------------------------------------------------------------------------------
	/// Get the bounds of the N-gon.
	/// @param[in] padr								The point array. @callerOwnsPointed{array}
	/// @param[in] polys							The polygons array. @callerOwnsPointed{array}
	/// @param[out] mp								Assigned the calculated mid-point.
	/// @param[out] rad								Assigned the calculated bounding box vector.
	//----------------------------------------------------------------------------------------
	void GetMpRad(const Vector* padr, const CPolygon* polys, Vector &mp, Vector &rad) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of elements in the array (all PgonEdge edges in all segments).
	/// @note This is not the same as all N-gon edges since some elements may be from internal polygons with no outer/inner N-gon edge.
	/// @return												The number of elements in the array.
	//----------------------------------------------------------------------------------------
	inline Int32 GetCount() const { return m_Count; }

	//----------------------------------------------------------------------------------------
	/// Gets access directly to a PgonEdge. Normally the helper functions below should be used.
	/// @param[in] i									An edge index.
	/// @return												The edge.
	//----------------------------------------------------------------------------------------
	inline PgonEdge *GetEdge(Int32 i) { if (m_Edge) return &m_Edge[i]; else return nullptr; }

	//----------------------------------------------------------------------------------------
	/// Retrieves the PgonEdge::ID() of the edge at index @formatParam{i}.
	/// @param[in] i									An edge index.
	/// @return												The edge polygon ID.
	//----------------------------------------------------------------------------------------
	inline Int32 ID(Int32 i) const { return m_Edge[i].ID(); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the PgonEdge::State() of the edge at index @formatParam{i}.
	/// @param[in] i									An edge index.
	/// @return												The edge state.
	//----------------------------------------------------------------------------------------
	inline Int32 State(Int32 i) const { return m_Edge[i].State(); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the PgonEdge::Edge() of the edge at index @formatParam{i}.
	/// @param[in] i									An edge index.
	/// @return												The edge.
	//----------------------------------------------------------------------------------------
	inline Int32 Edge(Int32 i) const { return m_Edge[i].Edge(); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the PgonEdge::EdgeIndex() of the edge at index @formatParam{i}.
	/// @param[in] i									An edge index.
	/// @return												The edge index.
	//----------------------------------------------------------------------------------------
	inline Int32 EdgeIndex(Int32 i) const { return m_Edge[i].EdgeIndex(); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the PgonEdge::IsFirst() state of the edge at index @formatParam{i}.
	/// @param[in] i									An edge index.
	/// @return												The edge first state.
	//----------------------------------------------------------------------------------------
	inline Int32 IsFirst(Int32 i) const { return m_Edge[i].IsFirst(); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the PgonEdge::IsSegmentEnd() state of the edge at index @formatParam{i}.
	/// @param[in] i									An edge index.
	/// @return												The edge segment end state.
	//----------------------------------------------------------------------------------------
	inline Int32 IsSegmentEnd(Int32 i) const { return m_Edge[i].IsSegmentEnd(); }

	//----------------------------------------------------------------------------------------
	/// Retrieves the first polygon ID in the array, useful as a marker (identity) for the N-gon giving a polygon ID that is within the N-gon.
	/// @return												The first polygon ID.
	//----------------------------------------------------------------------------------------
	inline Int32 GetIdentity() const { return (m_Count > 0)?m_Edge[0].ID():NOTOK; }

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of segments in the N-gon.
	/// @return												The segment count.
	//----------------------------------------------------------------------------------------
	Int32 GetSegmentCount() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of elements in the segment starting from the index @formatParam{startedge}. This includes any PgonEdge edges that are internal (NOEDGE).
	/// @param[in] startedge					An edge index.
	/// @return												The number of elements in the segment starting from @formatParam{startedge}.
	//----------------------------------------------------------------------------------------
	Int32 GetSegmentLen(Int32 startedge) const;

	//----------------------------------------------------------------------------------------
	/// Maps to the function PgonEdge::GetEdge() of the edge at index @formatParam{i}.
	/// @param[in] i									An edge index.
	/// @param[in] vadr								The polygon array. @callerOwnsPointed{array}
	/// @param[out] p1								Assigned the first point index.
	/// @param[out] p2								Assigned the second point index.
	//----------------------------------------------------------------------------------------
	void GetEdge(Int32 i, const CPolygon *vadr, Int32 &p1, Int32 &p2) { m_Edge[i].GetEdge(vadr, p1, p2); }

	//----------------------------------------------------------------------------------------
	/// Does a search to see if the polygon index @formatParam{id} exists within the N-gon; the look up uses tables so it is pretty fast.
	/// @param[in] id									A polygon ID to search for.
	/// @return												The index of the first edge found with the specified polygon @formatParam{id}, or @ref NOTOK if no edge was found.
	//----------------------------------------------------------------------------------------
	Int32 FindPolygon(Int32 id) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the edges (bits) for polygon @formatParam{id} that form any edge/s around the N-gon.
	/// @param[in] id									Combined edge bits for all edges with polygon ID matching @formatParam{id}: @enumerateEnum{PGONEDGE}
	/// @return												A polygon ID.
	//----------------------------------------------------------------------------------------
	UChar GetEdgeState(Int32 id) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of points that form the N-gon.
	/// @return												The point count.
	//----------------------------------------------------------------------------------------
	Int32 GetPointCount() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of polygons that form the N-gon.
	/// @return												The polygon count.
	//----------------------------------------------------------------------------------------
	Int32 GetPolygonCount() const;

	//----------------------------------------------------------------------------------------
	/// If any changes are done to the PgonEdges this must be called when completed to update the REPEAT markers of the PgonEdges.\n
	/// Also note that any changes must correct set/change any of the marker bits (such as the segment end, or no edges markers).
	//----------------------------------------------------------------------------------------
	void UpdateStates();

private:

	PgonEdge	*m_Edge;
	Int32			m_Count;
	UInt32		m_CRC;
};
#endif

/// @addtogroup NGON_TOSELECTION
/// @ingroup group_enumeration
/// @{
#define NGON_TOSELECTION_POLYGONS		1			///< A polygon selection of all polygons within the N-gons.
#define NGON_TOSELECTION_OUTLINE		2			///< An edge selection of all polygon edges that form the outer edge of the N-gon (no holes).
#define NGON_TOSELECTION_OUTEREDGES	3			///< An edge selection of all polygon edges that form the N-gon.
#define NGON_TOSELECTION_INNEREDGES	4			///< An edge selection of all polygon edges that are internal within the N-gon.
#define NGON_TOSELECTION_HOLES			5			///< An edge selection of all polygon edges that form any holes.
/// @}

/// @addtogroup NGON_FLAG
/// @ingroup group_enumeration
/// @{

/// Forces the N-gon manager to ignore any validation checks when a changed message is sent to the polygon object.\n
/// The flag is reset on the next changed message that the N-gons get from the polygon object.
#define NGON_FLAG_NOVALIDATION	(1 << 0)

/// Forces the N-gon manager to ignore any validation checks when a changed message is sent to the polygon object.\n
/// This is not reset and must be removed manually once any N-gon changes are completed.
#define NGON_FLAG_NOCHANGE			(1 << 1)

/// Stops the N-gon manager from doing a translation of the polygon indexes/internal data when the polygons are changed (i.e. when the polygon object receives @ref MSG_POLYGONS_CHANGED).
/// This can be used to prevent the N-gons getting changed when making changes to an object.\n
/// For example, in the HyperNURBS object the object needs to be resized; doing this sends the @ref MSG_POLYGONS_CHANGED message and hence changes the N-gons too.\n
/// But the HyperNURBS object needs the N-gon data unchanged (i.e. to prevent pointers changing, indexes changing).
#define NGON_FLAG_NOTRANSLATE		(1 << 2)

/// Block N-gons from validating completely but let them update their validation data.\n
/// Set ONLY if the polygon indices might have changed but are known to be valid N-gons.\n
/// The flag is auto removed once used.
#define NGON_FLAG_SETASVALID		(1 << 3)

/// @}

/// @addtogroup NGON_VERIFY_FLAG
/// @ingroup group_enumeration
/// @{
#define NGON_VERIFY_FLAG_REPAIR	(1 << 0)			///< Repairs any illegal N-gons (removes them).
/// @}

class NgonBase
{
	friend class ModelingKernelBase;

private:

	NgonBase();
	~NgonBase();

	NgonCache *m_pNgonBase;

public:

	//----------------------------------------------------------------------------------------
	/// @allocatesA{N-gon base instance}
	/// @note Normally this function is not needed, since the PolygonObject manages its own NgonBase.
	/// @return												@allocReturn{N-gon base instance}
	//----------------------------------------------------------------------------------------
	static NgonBase *Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{N-gon base instances}
	/// @param[in,out] p							@theToDestruct{N-gon base instance}
	//----------------------------------------------------------------------------------------
	static void Free(NgonBase *&p);

	//----------------------------------------------------------------------------------------
	/// Copies the N-gon data to another NgonBase.
	/// @param[in] dst								The destination N-gon base.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CopyTo(NgonBase *dst);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool Write(HyperFile *hf);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool Read(HyperFile *hf, Int32 id, Int32 level);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool Translate(VariableChanged *vc);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool Changed(PolygonObject *op);

	//----------------------------------------------------------------------------------------
	/// Retrieves the edge states for the polygon @formatParam{id}.\n
	// If the bit is set then the edge forms an edge around the N-gon (outer/inner).
	//----------------------------------------------------------------------------------------
	/// @param[in] id									A polygon ID.
	/// @return												The edge state flags: @enumerateEnum{PGONEDGE}
	//----------------------------------------------------------------------------------------
	UChar GetEdgeStates(Int32 id) const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the number of N-gons.
	/// @return												The N-gon count.
	//----------------------------------------------------------------------------------------
	Int32 GetCount() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the array of Pgon data.
	/// @return												The N-gon array.
	//----------------------------------------------------------------------------------------
	Pgon *GetNgons();

	//----------------------------------------------------------------------------------------
	/// Resizes the Pgon data array.
	/// @param[in] cnt								The new N-gon count.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Resize(Int32 cnt);

	//----------------------------------------------------------------------------------------
	/// Searches for polygon index @formatParam{id} in all N-gons.
	/// @param[in] id									A polygon ID.
	/// @param[in] l									@markPrivate
	/// @return												The found N-gon id, or @ref NOTOK if the polygon was not found in any N-gon.
	//----------------------------------------------------------------------------------------
	Int32 FindPolygon(Int32 id, Int32 l = -1) const;

	//----------------------------------------------------------------------------------------
	/// Compacts the Pgon array, removing any dead (empty) Pgon.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CompactPgons();

	//----------------------------------------------------------------------------------------
	/// Checks the point of polygon object @formatParam{op} to see if any N-gons need updating, e.g. if the point coordinates were changed from any N-gon.\n
	/// Usually this should be managed manually. This function is normally used for backwards compatibility with older code that does not change N-gons (e.g. XL7, R8 plugins).
	/// @see UpdateNgons() because this can change the object if an update is needed.
	/// @param[in] op									A polygon object. @callerOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	void CheckPoints(PolygonObject *op);

	//----------------------------------------------------------------------------------------
	/// Updates any dirty N-gons.\n
	/// This changes the polygon object and retriangulates any N-gons that need updating. If CheckPoints() is called then this does not need to be called, since it is called if any changes were made.
	/// @param[in] op									A polygon object. @callerOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	void UpdateNgons(PolygonObject *op);

	//----------------------------------------------------------------------------------------
	/// Resets the internal tracking data for the N-gons for the current point coordinates.
	/// @param[in] op									A polygon object. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ResetPoints(PolygonObject *op);

	//----------------------------------------------------------------------------------------
	/// Sets the flags.
	/// @note Generally the forced "ignore" for the internal checks are used if modifying the N-gon data and needing to call functions that send changed messages to the object, such as adding a tag or resizing the object.\n
	/// They are mainly a time saver since running N-gon checks takes time.
	/// @param[in] flgs								The new flags: @enumerateEnum{NGON_FLAG}
	//----------------------------------------------------------------------------------------
	void SetFlags(Int32 flgs);

	//----------------------------------------------------------------------------------------
	/// Gets the flags.
	/// @return												The current flags: @enumerateEnum{NGON_FLAG}
	//----------------------------------------------------------------------------------------
	Int32 GetFlags() const;

	//----------------------------------------------------------------------------------------
	/// Retrieves the dirty count.
	/// @return												The dirty count.
	//----------------------------------------------------------------------------------------
	Int32 GetDirtyCount() const;

	//----------------------------------------------------------------------------------------
	/// Makes the internal N-gon tables dirty. Usually this is not needed and InitMap() should be called once changes are completed to update the N-gon tables.
	//----------------------------------------------------------------------------------------
	void Dirty();

	//----------------------------------------------------------------------------------------
	/// Forces the internal N-gon table data to be rebuilt. This must be called if any changes are made to the N-gon data.\n
	/// This should always be called before any update message is sent to the polygon object when changes are completed.
	//----------------------------------------------------------------------------------------
	void InitMap();

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	void FreeMap();

	//----------------------------------------------------------------------------------------
	/// Removes the n-gon @formatParam{id} from the array.
	/// @param[in] id									The ID of the N-gon to remove.
	/// @param[in] force							If @formatConstant{true} then CompactPgons() is called. Usually it is faster to remove the N-gons then compact the array at the end.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Remove(Int32 id, Bool force);

	//----------------------------------------------------------------------------------------
	/// Generates a BaseSelect containing information about the N-gons.
	/// @param[out] pSelect						The selection to fill. @callerOwnsPointed{selection}
	/// @param[in] mode								The mode: @enumerateEnum{NGON_TOSELECTION}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ToSelect(BaseSelect *pSelect, Int32 mode);

	//----------------------------------------------------------------------------------------
	/// Gets the center of the N-gon @formatParam{id}.
	/// @param[in] id									An N-gon ID.
	/// @param[in] vadr								The polygons array. @callerOwnsPointed{array}
	/// @param[in] padr								The points array. @callerOwnsPointed{array}
	/// @param[out] ip								Assigned the center point.
	/// @param[out] in								Assigned the normal vector.
	//----------------------------------------------------------------------------------------
	void GetCenter(Int32 id, const CPolygon *vadr, const Vector *padr, Vector *ip, Vector *in);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool RemapEdge(Int32 oedge, Int32 *nedges, Int32 ncnt);

	//----------------------------------------------------------------------------------------
	/// Create a new N-gon (appends to the N-gon array) from the edge array passed. Set the marker bits for the segment end and no edges.
	/// @param[in] nedges							The new edge array. @callerOwnsPointed{array}
	/// @param[in] ncnt								The edge array size.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Create(UInt32 *nedges, Int32 ncnt);

	//----------------------------------------------------------------------------------------
	/// Searches the N-gons for @formatParam{oply} and remaps this to @formatParam{nply}.
	/// @param[in] oply								The old polygon ID.
	/// @param[in] nply								The new polygon ID.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool RemapPolygon(Int32 oply, Int32 nply);

	//----------------------------------------------------------------------------------------
	/// Copes a Pgon.
	/// @note The memory allocation for the Pgon objects uses its own internal memory manager and cannot be allocated using the @C4D memory allocation calls.
	///				The function will fail if @formatParam{dst} is not within the allocated space of the NgonBase.
	/// @param[in] src								The source Pgon. @callerOwnsPointed{Pgon}
	/// @param[in] dst								The destination Pgon. @callerOwnsPointed{Pgon}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Copy(Pgon *src, Pgon *dst);

	//----------------------------------------------------------------------------------------
	/// Checks if the N-gons are valid. If they are not then any invalid ones are removed.\n
	/// @note Usually not needed. This function is used internally to check for N-gons that get damaged if the polygons are modified without updating the N-gons.
	/// @param[in] op									A polygon object. @callerOwnsPointed{polygon object}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Validate(PolygonObject *op);

	//----------------------------------------------------------------------------------------
	/// Runs a simple sanity check on the N-gon passed to check if its points link together consistently.
	/// @param[in] pgon								The polygon array. @callerOwnsPointed{array}
	/// @param[in] vadr								The points array. @callerOwnsPointed{array}
	/// @return												The N-gon to validate.
	//----------------------------------------------------------------------------------------
	Bool IsValidNgon(Pgon *pgon, const CPolygon *vadr);

	//----------------------------------------------------------------------------------------
	/// Helper function to build an N-gon from a list of edges.\n
	/// The arrays @formatParam{inner} and @formatParam{outer} can be @formatConstant{nullptr}, but not both of them at the same time.
	/// @param[in] inner							An array of internal (hidden) edges indices. @callerOwnsPointed{array}\n
	/// 															If only this is specified the function finds the main outline itself based on the hidden edges, this will also include any holes in the N-gon.
	/// @param[in] outer							An array of the outline of the N-gon. Use the internal mark (@ref PGONEDGE_ENDSEGMENT) to mark segments in the N-gon outline. @callerOwnsPointed{array}
	/// @param[in] icnt								The size of the @formatParam{inner} array.
	/// @param[in] ocnt								The size of the @formatParam{outer} array.
	/// @param[out] vadr							The polygons array. @callerOwnsPointed{array}
	/// @param[out] padr							The points array. @callerOwnsPointed{array}
	/// @return												The index of the added N-gon, or @ref NOTOK if the operation failed.
	//----------------------------------------------------------------------------------------
	Int32 BuildNgon(Int32 *inner, Int32 *outer, Int32 icnt, Int32 ocnt, const CPolygon *vadr, const Vector *padr);

	//----------------------------------------------------------------------------------------
	/// Helper function to build an N-gon from a list of polygons and outer edges.
	/// @param[in] polys							An array of polygons that form the N-gon.
	/// @param[in] outer							An array of the outline of the N-gon.  @callerOwnsPointed{array}\n
	/// 															Use the internal mark (@ref PGONEDGE_ENDSEGMENT) to mark segments in the N-gon outline.
	/// @param[in] pcnt								The size of the @formatParam{polys} array.
	/// @param[in] ocnt								The size of the @formatParam{outer} array.
	/// @param[in] vadr								The polygons array. @callerOwnsPointed{array}
	/// @param[in] padr								The points array. @callerOwnsPointed{array}
	/// @return												The index of the added N-gon, or @ref NOTOK if the operation failed.
	//----------------------------------------------------------------------------------------
	Int32 BuildNgonFromPolys(Int32 *polys, Int32 *outer, Int32 pcnt, Int32 ocnt, const CPolygon *vadr, const Vector *padr);

	//----------------------------------------------------------------------------------------
	/// Verifies N-gons.
	/// @param[in] vadr								A pointer to the polygon array. This can be obtained with PolygonObject::GetPolygonR(). @callerOwnsPointed{array}
	/// @param[in] vcnt								The total number of polygons in the polygon array. This can be obtained with PolygonObject::GetPolygonCount().
	/// @param[in] flags							The flags: @enumerateEnum{NGON_VERIFY_FLAG}
	/// @param[in] pgon								A pointer to a N-gon to verify it or @formatConstant{nullptr} to verify all N-gons.
	/// @return												@formatConstant{true} if N-gons are valid, @formatConstant{false} if there are illegal N-gons.
	//----------------------------------------------------------------------------------------
	Bool Verify(const CPolygon *vadr, Int32 vcnt, UInt32 flags, Pgon *pgon = nullptr);

	//----------------------------------------------------------------------------------------
	/// Allocates an N-gon. Destroy the allocated N-gon with FreeNgon().
	/// @param[in] edge_cnt						The number of edges of the N-gon.
	/// @return												@allocReturn{N-gon}
	//----------------------------------------------------------------------------------------
	Pgon *AllocNgon(Int32 edge_cnt);

	//----------------------------------------------------------------------------------------
	/// Destructs N-gons allocated with AllocNgon().
	/// @param[in,out] pgon						@theToDestruct{N-gon}
	//----------------------------------------------------------------------------------------
	void FreeNgon(Pgon *&pgon);

	//----------------------------------------------------------------------------------------
	/// Sets the N-gon specified by @formatParam{index} to @formatParam{src}.
	/// @param[in] index							The index of the N-gon to set.
	/// @param[in] src								The new N-gon data.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetNgon(Int32 index, Pgon *src);

	//----------------------------------------------------------------------------------------
	/// Sets the N-gon specified by @formatParam{index} and the edge array @formatParam{edges}.
	/// @param[in] index							The index of the N-gon to set.
	/// @param[in] edges							The pointer to the edges array. @callerOwnsPointed{array}
	/// @param[in] edge_cnt						The number of edges, size of the @formatParam{edges} array.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetNgon(Int32 index, UInt32 *edges, Int32 edge_cnt);
};

/// Ngon library ID.
#define LIBRARY_NGON 1015903

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct NgonBaseLib : public C4DLibrary
{
	iNgonBase *(*Alloc)();
	void (*Free)(iNgonBase *&p);

	Bool (iNgonBase::*CopyTo)(iNgonBase *dst);
	Bool (iNgonBase::*Write)(HyperFile *hf);
	Bool (iNgonBase::*Read)(HyperFile *hf, Int32 id, Int32 level);
	Bool (iNgonBase::*Translate)(VariableChanged *vc);
	Bool (iNgonBase::*Changed)(PolygonObject *op);

	UChar (iNgonBase::*GetEdgeStates)(Int32 id) const;
	Int32 (iNgonBase::*GetCount)() const;
	Pgon *(iNgonBase::*GetNgons)();

	Bool (iNgonBase::*Resize)(Int32 cnt);
	Int32 (iNgonBase::*FindPolygon)(Int32 id, Int32 l) const;
	Bool (iNgonBase::*CompactPgons)();
	void (iNgonBase::*CheckPoints)(PolygonObject *op);
	void (iNgonBase::*UpdateNgons)(PolygonObject *op);

	Bool (iNgonBase::*ResetPoints)(PolygonObject *op);
	void (iNgonBase::*SetFlags)(Int32 flgs);
	Int32 (iNgonBase::*GetFlags)() const;
	Int32 (iNgonBase::*GetDirtyCount)() const;

	void (iNgonBase::*Dirty)();

	void (iNgonBase::*InitMap)();
	void (iNgonBase::*FreeMap)();

	Bool (iNgonBase::*Remove)(Int32 id, Bool force);
	Bool (iNgonBase::*ToSelect)(BaseSelect *pSelect, Int32 mode);
	void (iNgonBase::*GetCenter)(Int32 id, const CPolygon *vadr, const Vector *padr, Vector *ip, Vector *in);
	Bool (iNgonBase::*RemapEdge)(Int32 oedge, Int32 *nedges, Int32 ncnt);
	Bool (iNgonBase::*Create)(UInt32 *nedges, Int32 ncnt);
	Bool (iNgonBase::*RemapPolygon)(Int32 oply, Int32 nply);
	Bool (iNgonBase::*Copy)(Pgon *src, Pgon *dst);

	Bool (iNgonBase::*Validate)(PolygonObject *op);
	Bool (iNgonBase::*IsValidNgon)(Pgon *pgon, const CPolygon *vadr);

	Int32 (iNgonBase::*BuildNgon)(Int32 *inner, Int32 *outer, Int32 icnt, Int32 ocnt, const CPolygon *vadr, const Vector *padr);
	Int32 (iNgonBase::*BuildNgonFromPolys)(Int32 *polys, Int32 *outer, Int32 pcnt, Int32 ocnt, const CPolygon *vadr, const Vector *padr);

	Bool (iNgonBase::*Verify)(const CPolygon *vadr, Int32 vcnt, UInt32 flags, Pgon *pgon);

	Pgon *(iNgonBase::*AllocNgon)(Int32 edge_cnt);
	void (iNgonBase::*FreeNgon)(Pgon *&pgon);
	Bool (iNgonBase::*SetNgon)(Int32 index, Pgon *src);
	Bool (iNgonBase::*SetNgonE)(Int32 index, UInt32 *edges, Int32 edge_cnt);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_NGON_H__
