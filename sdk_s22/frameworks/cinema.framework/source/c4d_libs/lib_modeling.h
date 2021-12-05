/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_MODELING_H__
#define LIB_MODELING_H__

#include "c4d_library.h"
#include "c4d_memory.h"

class iModeling;
class ModelingBase;
class ModelingKernel;
class Ngon;

/// @addtogroup group_modelinglibrary Modeling
/// @ingroup group_library
/// @{

#ifndef NOTINDEX
#define NOTINDEX				(LIMIT<Int32>::MAX)			///< Invalid index.
#endif

struct PointMove
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @param[in] index							The index of the point to move.
	//----------------------------------------------------------------------------------------
	explicit PointMove(Int32 index) { i = index; }

	Int32		i;			///< Index of the point to move.
	Vector	p;			///< New coordinate of the point to move.
};

/// @addtogroup TRANSMAP_FLAG
/// @ingroup group_enumeration
/// @{
#define TRANSMAP_FLAG_NEW			(1 << 0)			///< New.
#define TRANSMAP_FLAG_CLONE		(1 << 1)			///< Clone.
#define TRANSMAP_FLAG_MOVED		(1 << 2)			///< Moved.
#define TRANSMAP_FLAG_DELETED	(1 << 3)			///< Deleted.
#define TRANSMAP_FLAG_UNION		(1 << 4)			///< Union.
/// @}

/// @addtogroup TRANSMAP_PNTFLAG
/// @ingroup group_enumeration
/// @{
#define TRANSMAP_PNTFLAG_INTER	(1 << 20)			///< Interpolated.
#define TRANSMAP_PNTFLAG_DELTA	(1 << 21)			///< Delta transformation.
#define TRANSMAP_PNTFLAG_WELDED	(1 << 22)			///< Welded.
/// @}

/// @addtogroup TRANSMAP_PLYFLAG
/// @ingroup group_enumeration
/// @{
#define TRANSMAP_PLYFLAG_MELTED	(1 << 20)			///< Melted.
#define TRANSMAP_PLYFLAG_PGON		(1 << 21)			///< Pgon.
/// @}

struct TransIndexMapData
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @param[in] oindex							The old index.
	//----------------------------------------------------------------------------------------
	explicit TransIndexMapData(Int32 oindex) { oIndex = oindex; }

	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @param[in] oindex							The old index.
	/// @param[in] nindex							The new index.
	//----------------------------------------------------------------------------------------
	TransIndexMapData(Int32 oindex, Int32 nindex) { oIndex = oindex; nIndex = nindex; }

	Int32	oIndex;			///< Old index.
	Int32	nIndex;			///< New index.
};

struct TransMapData : public TransIndexMapData
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @param[in] oindex							The old index.
	//----------------------------------------------------------------------------------------
	explicit TransMapData(Int32 oindex) : TransIndexMapData(oindex) { }

	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @param[in] oindex							The old index.
	/// @param[in] nindex							The new index.
	//----------------------------------------------------------------------------------------
	TransMapData(Int32 oindex, Int32 nindex) : TransIndexMapData(oindex, nindex)  { }

	Int32	lFlags;			///< General flags: @enumerateEnum{TRANSMAP_FLAG}\n
										///< For points: @enumerateEnum{TRANSMAP_PNTFLAG}\n
										///< For polygons: @enumerateEnum{TRANSMAP_PLYFLAG}
	Int32	mIndex;			///< Mapped index.
};

struct TransMapNewData
{
	//----------------------------------------------------------------------------------------
	/// Constructor.
	/// @param[in] nindex							The new index.
	//----------------------------------------------------------------------------------------
	explicit TransMapNewData(Int32 nindex) { nIndex = nindex; }

	Int32	nIndex;			///< New index.
	Int32	mIndex;			///< Mapped index.
};

struct TransPointInterData
{
	Int32	p1;			///< First point.
	Int32	p2;			///< Second point.
	Float	t;			///< Interpolation parameter.
};

struct TransPointDeltaData
{
	Vector	opnt;			///< Original point.
	Vector	dlt;			///< Delta vector.
};

//----------------------------------------------------------------------------------------
/// With previous versions of @C4D it was a hard to update plugin tags after modeling operations. They all had to be done manually per tool (at least in theory, not many plugins bothered!).
///
/// A solution to this problem are the tag translation messages. During Modeling::Commit() there are two points at which translations of tags can be done:
/// - PRETRANSLATE: This is done before any changes to the object happen. It can be useful to use the old tag/polygon data to translate or to store this info for the translate;\n
///										e.g. edge selections and UVs both need to store old tag data and polygon data ready for the translation after the object is changed.
/// - TRANSLATE: This is done after the object is changed.
///
/// @note If Modeling::Commit() fails then TRANSLATE is called with @formatConstant{nullptr} so that any data stored from PRETRANSLATE can be released.
///
/// The TranslationMaps pointer is passed for the translation message @c data.\n
/// A simple example is the vertex map tag. Points are the easiest to translate. Polygons are pretty much the same too. Edges are much harder since they do not have any representation.\n
/// In the modeling library they are handled by storing (in PRETRANSLATE) information about the points/polygons that form the edges and use this in TRANSLATE to match up any edge changes.
/// @code
/// Bool VertexMapTag::Message(Int32 type, void *data)
/// 	{
/// 		switch (type)
/// 		{
/// 			...
/// 		case MSG_TRANSLATE_POINTS:
/// 			RemapVertexMap((Float*)t_data,(TranslationMaps*)data);
/// 			break;
/// 		}
/// 		return SUPER::Message(type,data);
/// 	}
///
/// 	static void RemapVertexMap(Float *vmap, TranslationMaps *map)
/// 	{
/// 		if (map && map->m_pPointMap && map->m_nPointCount && vmap)
/// 		{
/// 			Int32 i,l,s;
/// 			TransPointInterData *ipnt;
///
/// 			// Processed any interpolated points
///
/// 			for (i=0;i<map->m_mPointCount;i++)
/// 			{
/// 				if (!(map->m_pPointMap[i].lFlags & TRANSMAP_PNTFLAG_INTER)) continue;
/// 				ipnt=&map->m_pInterpolatedPoints[map->m_pPointMap[i].mIndex];
/// 				vmap[map->m_pPointMap[i].nIndex]=Mix(vmap[ipnt->p1],vmap[ipnt->p2],ipnt->t);
/// 			}
///
/// 			// Merge any welds
///
/// 			for (i=0;i<map->m_mWeldCount;)
/// 			{
/// 				l=map->m_pWeldMap[i].nIndex; s=0;
///
/// 				Float sum=0.0;
///
/// 				while (i<map->m_mWeldCount && map->m_pWeldMap[i].nIndex==l)
/// 				{
/// 					if (map->m_pWeldMap[i].oIndex>=0)
/// 					{
/// 						sum+=vmap[map->m_pWeldMap[i].oIndex];
/// 						s++;
/// 					}
///
/// 					i++;
/// 				}
///
/// 				if (s>0) sum=sum/Float(s);
///
/// 				vmap[l]=sum;
/// 			}
///
/// 			// Remap any changes
///
/// 			for (i=0;i<map->m_mPointCount;i++)
/// 			{
/// 				if (map->m_pPointMap[i].lFlags & (TRANSMAP_PNTFLAG_INTER|TRANSMAP_FLAG_DELETED)) continue;
///
/// 				if (map->m_pPointMap[i].lFlags & TRANSMAP_FLAG_NEW)
/// 					vmap[map->m_pPointMap[i].nIndex]=0.0;
/// 				else if (map->m_pPointMap[i].nIndex!=map->m_pPointMap[i].oIndex)
/// 					vmap[map->m_pPointMap[i].nIndex]=vmap[map->m_pPointMap[i].oIndex];
/// 			}
/// 		}
/// 	}
/// @endcode
//----------------------------------------------------------------------------------------
class TranslationMaps
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructor.
	//----------------------------------------------------------------------------------------
	TranslationMaps()
	{
		ClearMem(this, sizeof(TranslationMaps), 0);
	}

	//----------------------------------------------------------------------------------------
	/// Searches for the original (i.e old) index based on the new @formatParam{index}. (A pure helper. The source for this function is available in @em lib_modeling.cpp.)
	/// @param[in] index							The new index.
	/// @return												The old index.
	//----------------------------------------------------------------------------------------
	Int32 FindOriginalPoint(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Searches for the original (i.e old) index based on the new @formatParam{index}. (A pure helper. The source for this function is available in @em lib_modeling.cpp.)
	/// @param[in] index							The new index.
	/// @return												The old index.
	//----------------------------------------------------------------------------------------
	Int32 FindOriginalPolygon(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Searches for the original (i.e old) index based on the new @formatParam{index}. (A pure helper. The source for this function is available in @em lib_modeling.cpp.)
	/// @param[in] index							The new index.
	/// @return												The old index.
	//----------------------------------------------------------------------------------------
	Int32 FindOriginalPgon(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Searches for the original (i.e old) index based on the new @formatParam{index}. (A pure helper. The source for this function is available in @em lib_modeling.cpp.)
	/// @param[in] index							The new index.
	/// @return												The old index.
	//----------------------------------------------------------------------------------------
	Int32 FindOriginalSegment(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Searches for the new index based on the original @formatParam{index}. (A pure helper. The source for this function is available in @em lib_modeling.cpp.)
	/// @param[in] index							The old index.
	/// @return												The new index.
	//----------------------------------------------------------------------------------------
	Int32 FindNewPoint(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Searches for the new index based on the original @formatParam{index}. (A pure helper. The source for this function is available in @em lib_modeling.cpp.)
	/// @param[in] index							The old index.
	/// @return												The new index.
	//----------------------------------------------------------------------------------------
	Int32 FindNewPolygon(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Searches for the new index based on the original @formatParam{index}. (A pure helper. The source for this function is available in @em lib_modeling.cpp.)
	/// @param[in] index							The old index.
	/// @return												The new index.
	//----------------------------------------------------------------------------------------
	Int32 FindNewPgon(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Searches for the new index based on the original @formatParam{index}. (A pure helper. The source for this function is available in @em lib_modeling.cpp.)
	/// @param[in] index							The old index.
	/// @return												The new index.
	//----------------------------------------------------------------------------------------
	Int32 FindNewSegment(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Searches for the new index based on the original @formatParam{index}. (A pure helper. The source for this function is available in @em lib_modeling.cpp.)
	/// @param[in] index							The old index.
	/// @return												The new index.
	//----------------------------------------------------------------------------------------
	Int32 FindWeldPoint(Int32 index);

	//----------------------------------------------------------------------------------------
	/// Searches for the new index based on the original @formatParam{index}. (A pure helper. The source for this function is available in @em lib_modeling.cpp.)
	/// @param[in] index							The old index.
	/// @return												The new index.
	//----------------------------------------------------------------------------------------
	Int32 FindMeltPolygon(Int32 index);

	Int32 m_oPointCount;				///< Original point count.
	Int32 m_oPolygonCount;			///< Original polygon count.
	Int32 m_oPgonCount;					///< Original Pgon count.
	Int32 m_oSegmentCount;			///< Original segment count.

	Int32 m_nPointCount;				///< New point count.
	Int32 m_nPolygonCount;			///< New polygon count.
	Int32 m_nPgonCount;					///< New Pgon count.
	Int32 m_nSegmentCount;			///< New segment count.

	Int32 m_mPointCount;				///< Map point count.
	Int32 m_mPolygonCount;			///< Map polygon count.
	Int32 m_mPgonCount;					///< Map Pgon count.
	Int32 m_mSegmentCount;			///< Map segment count.

	Int32 m_mWeldCount;					///< Map weld count.
	Int32 m_mMeltCount;					///< Map melt count.

	TransMapData *m_pPointMap;				///< Point translation map.
	TransMapData *m_pPolygonMap;			///< Polygon translation map.
	TransMapData *m_pPgonMap;					///< Pgon translation map.
	TransMapData *m_pSegmentMap;			///< Segment translation map.

	TransIndexMapData *m_pWeldMap;			///< Weld index translation map.
	TransIndexMapData *m_pMeltMap;			///< Melt index translation map.

	TransMapNewData *m_pNewPointMap;				///< New point translation map.
	TransMapNewData *m_pNewPolygonMap;			///< New polygon translation map.
	TransMapNewData *m_pNewPgonMap;					///< New Pgon translation map.
	TransMapNewData *m_pNewSegmentMap;			///< New segment translation map.

	TransPointInterData *m_pInterpolatedPoints;			///< Interpolation map.
	TransPointDeltaData *m_pDeltaPoints;						///< Delta map.
};

/// @addtogroup MODELING_ERROR
/// @ingroup group_enumeration
/// @{
#define MODELING_ERROR_UNKNOWN				(-1)			///< Unknown error.
#define MODELING_ERROR_NONE						(0)				///< No error.
#define MODELING_ERROR_FAILED					(1)				///< Operation failed.
#define MODELING_ERROR_NOMEMORY				(2)				///< No memory.
#define MODELING_ERROR_NOTFOUND				(3)				///< Not found.
#define MODELING_ERROR_INVALIDOP			(4)				///< Invalid operation.
#define MODELING_ERROR_FATAL					(5)				///< Fatal error!
#define MODELING_ERROR_INVALIDOBJECT	(6)				///< Invalid object.
#define MODELING_ERROR_ILLEGAL				(7)				///< Illegal operation.
#define MODELING_ERROR_TRIANGULATION	(8)				///< Triangulation error.
#define MODELING_ERROR_INVALIDKERNEL	(9)				///< Invalid kernel.
#define MODELING_ERROR_INTERNAL				(10)			///< Internal error.
#define MODELING_ERROR_BADARGS				(11)			///< Bad arguments.
#define MODELING_ERROR_CORRUPTOBJECT	(12)			///< Corrupt object.
#define MODELING_ERROR_MSGFAIL				(13)			///< Message failure.
/// @}

/// @addtogroup MODELING_COMMIT
/// @ingroup group_enumeration
/// @{
#define MODELING_COMMIT_NONE					0				///< No flags.
#define MODELING_COMMIT_UPDATE				1				///< Commit updates its internal data so that further editing can be done without having to re-init the kernel.\n
																							///< This only applies if the committed object is the same as the original; it is possible to commit the changes to another (clone) object without having to re-init.
#define MODELING_COMMIT_CREATEMAP			2				///< Creates a map where points are mapped from/to, accessible with Modeling::GetPointMap().
																							///< @note Translation maps for tags etc. (TranslationMaps) are not affected. They are always generated when needed.
#define MODELING_COMMIT_REFRESH				4				///< Tell the kernel to throw away internal data and start fresh.
#define MODELING_COMMIT_TRINGONS			8				///< Force the kernel to make all changed (dirty) N-gons into their polygons (triangulated).\n
																							///< For example, an easy way to triangulate would be to just fetch the polygon selection into the kernel (Modeling::GetNgon() and Modeling::SetNgon()), then commit with this flag.
#define MODELING_COMMIT_RESTORE				16			///< Force the kernel to keep a duplicate of the original object and then restore the data and tags on the next Commit() call.\n
																							///< Use instead of @ref MODELING_COMMIT_UPDATE for any changes that are required to be updated from the original state (e.g. for tags).
#define MODELING_COMMIT_ADDUNDO				32			///< Commit will add the document undo when the object is about to be changed. It will also remove it, should the commit fail.
#define MODELING_COMMIT_QUADS					64			///< Same as @ref MODELING_COMMIT_TRINGONS except it will try to create quads.
#define MODELING_COMMIT_NOVALIDATION	128			///< The Modeling::Commit() function in has a pre-processing call that checks if the N-gons are valid, otherwise it can lead to really bad (or failed) triangulation.\n
																							///< This flag prevents this call from happening. It is used by the Add Point tool to allow it to add a single point into a hole of an N-gon.\n
#define MODELING_COMMIT_QUADLIMIT			256			///< Used by the Delete tool to specify that the minimum allowed points in an N-gon is @em 4. Anything lower is ignored (not created). Without this flag the limit is @em 3.
#define MODELING_COMMIT_NO_NGONS			(MODELING_COMMIT_TRINGONS | MODELING_COMMIT_QUADS)			///< A combination of @ref MODELING_COMMIT_TRINGONS and @ref MODELING_COMMIT_QUADS, so that no N-gons are created.
/// @}

/// @addtogroup MODELING_SETPOINT_FLAG
/// @ingroup group_enumeration
/// @{
#define MODELING_SETPOINT_FLAG_EMPTY		0			///< No flags.
#define MODELING_SETPOINT_FLAG_NODIRTY	1			///< The kernel does not set the associated N-gons to "dirty". This prevents re-triangulation (faster commit).\n
																							///< It only applies to already existing data; any new N-gons are already dirty since they need their polygons created.
#define MODELING_SETPOINT_FLAG_UNION		2			///< Mark the point for tag translation to use the same data as the origin point.
/// @}

/// @addtogroup MODELING_SETNGON_FLAG
/// @ingroup group_enumeration
/// @{
#define MODELING_SETNGON_FLAG_EMPTY				0				///< No flags.
#define MODELING_SETNGON_FLAG_TRIANGULATE	1				///< Force the N-gon to be created as its polygons (similar to the @ref MODELING_COMMIT_TRINGONS but for a single N-gon).
#define MODELING_SETNGON_FLAG_FIXEDQUADS	2				///< Similar to @ref MODELING_SETNGON_FLAG_TRIANGULATE but force the N-gon to create a fixed set of quads. Used for extrude (faster than triangulation).
#define MODELING_SETNGON_FLAG_NGONQUADS		4				///< Similar to @ref MODELING_SETNGON_FLAG_FIXEDQUADS except the quads are used to form the N-gon. Used for extrude.
#define MODELING_SETNGON_FLAG_QUADS				8				///< As with the @ref MODELING_SETNGON_FLAG_TRIANGULATE but tries to create quads.
#define MODELING_SETNGON_FLAG_UNION				16			///< Mark the N-gon to use the same data during tag translation as the origin N-gon.
#define MODELING_SETNGON_FLAG_NOROTATE		32			///< Skips an internal convex check (and rotate) so that quads remain in the same order.
/// @}

/// @addtogroup MODELING_GETNGON_FLAG
/// @ingroup group_enumeration
/// @{
#define MODELING_GETNGON_FLAG_EMPTY			0			///< No flags.
#define MODELING_GETNGON_FLAG_READONLY	1			///< Does not copy the internal data to the N-gon passed but sets the direct points.\n
																							///< Modeling::Release() must be called afterwards so that the pointers are not freed!
/// @}

struct CPolygon;

//----------------------------------------------------------------------------------------
/// Called to triangulate the N-gon in @formatParam{ngon}, returning the result in @formatParam{pPolys}.\n
/// Here is part of a trivial example of a triangulation algorithm that preserves quads:
/// @code
/// #define AllocPolys(_p) lPolyCount = (_p); pPolys = (CPolygon*)NewMemClear((_p) * sizeof(CPolygon)); if (!pPolys) return false;
///
/// Bool MyTriangulate(BaseObject *pObj, Int32 lNgonID, Ngon *ngon, Vector *pvPoints, Int32 lPointCount, CPolygon *&pPolys, Int32 &lPolyCount, Bool &bTriang, void *pData)
/// {
/// 	if (ngon->count == 3)
/// 	{
/// 		AllocPolys(1);
/// 		pPolys[0] = CPolygon(0, 1, 2, 2);
/// 		bTriang = true;
/// 		return true;
/// 	}
/// 	else if (ngon->count == 4)
/// 	{
/// 		AllocPolys(1);
/// 		pPolys[0] = CPolygon(0, 1, 2, 3);
/// 		bTriang = true;
/// 		return true;
/// 	}
/// 	else
/// 	{
/// 		...
/// 	}
/// }
/// @endcode
/// @param[in] pObj								An initialized object.
/// @param[in] lNgonID						The N-gon ID of @formatParam{ngon}.
/// @param[in] ngon								The N-gon to triangulate.
/// @param[in] pvPoints						The points of @formatParam{pObj}.
/// @param[in] lPointCount				The array size of @formatParam{pvPoints}.
/// @param[out] pPolys						Always @formatConstant{nullptr} in the call. Assign the resulting triangulated polygon array here.\n
/// 															It should be an array of CPolygon, allocated with NewMemClear(). The caller takes over the ownership of the pointed array.
/// @param[out] lPolyCount				Assign the size of @formatParam{pPolys} here.
/// @param[in] bTriang						Assign @trueIfOtherwiseFalse{@formatParam{ngon} was triangulated}
/// @param[in] pData							The private hook data, passed from Modeling::SetTriangulateHook().
/// @return												@trueIfOtherwiseFalse{successful}
//----------------------------------------------------------------------------------------
typedef Bool (*TriangulateHook)(BaseObject *pObj, Int32 lNgonID, Ngon *ngon, const Vector *pvPoints, Int32 lPointCount, CPolygon *&pPolys, Int32 &lPolyCount, Bool &bTriang, void *pData);

//----------------------------------------------------------------------------------------
/// Modeling engine.
//----------------------------------------------------------------------------------------
class Modeling
{
private:
	Modeling();
	~Modeling();

	ModelingBase		*m_pBase;
	ModelingKernel	*m_pKernelCache;
	C4DAtom					*m_pObjectCache;

public:
	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesA{modeling engine}
	/// @return												@allocReturn{modeling engine}
	//----------------------------------------------------------------------------------------
	static Modeling *Alloc();

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{modeling engines}
	/// @param[in,out] p							@theToDestruct{modeling engine}
	//----------------------------------------------------------------------------------------
	static void Free(Modeling *&p);

	/// @}

	/// @name Init/Commit/Release
	/// @{

	//----------------------------------------------------------------------------------------
	/// Initializes the modeling engine with the objects in @formatParam{objs}.
	/// @param[in] objs								An atom array with the objects to perform the modeling on. @callerOwnsPointed{objects array}
	/// @param[in] flags							Not used.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool InitArray(AtomArray *objs, Int32 flags = 0);

	//----------------------------------------------------------------------------------------
	/// Initialize the modeling engine with the object @formatParam{op}.
	/// @param[in] op									The object to perform the modeling on. @callerOwnsPointed{object}
	/// @param[in] flags							Not used.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool InitObject(C4DAtom *op, Int32 flags = 0);

	//----------------------------------------------------------------------------------------
	/// Commits the modeling transformation.
	/// @param[in] op									The pointer of the initialized object to use for the commit, or @formatConstant{nullptr} to commit all initialized objects.
	/// @param[in] flags							The commit flags: @enumerateEnum{MODELING_COMMIT}
	/// @param[in] cobj								The object to commit the changes to, or @formatConstant{nullptr} to use the initialized object.\n
	/// 															Setting @formatParam{cobj} is only valid when committing a single object. The object must match the original.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool Commit(C4DAtom *op = nullptr, Int32 flags = 0 , BaseObject* cobj = nullptr);

	//----------------------------------------------------------------------------------------
	/// Frees all data for all initialized objects.
	//----------------------------------------------------------------------------------------
	void Release();

	//----------------------------------------------------------------------------------------
	/// Frees the data for @formatParam{op}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	//----------------------------------------------------------------------------------------
	void ReleaseObject(C4DAtom *op);

	/// @}

	/// @name Map
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves a table of where the old/new points were set in the changed object after a Modeling::Commit().\n
	/// The table is interleaved with virtual indices at <tt>(*map)[2*n]</tt> and real indices at <tt>(*map)[2*n+1]</tt>, where @c n goes from @em 0 to @formatParam{count} - @em 1.
	/// @note Set @ref MODELING_COMMIT_CREATEMAP flag in Modeling::Commit() for this function to work.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[out] map								Assigned a pointer to the map array. @theOwnsPointed{modeling engine,array}
	/// @param[out] count							Assigned the number of points. The array size is @em 2 * @formatParam{count}.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetPointMap(C4DAtom *op, Int32 **map, Int32 *count);

	//----------------------------------------------------------------------------------------
	/// Not implemented.
	//----------------------------------------------------------------------------------------
	Bool GetNgonMap(C4DAtom *op, Int32 **map, Int32 *count);

	//----------------------------------------------------------------------------------------
	/// Call this function to keep the table @formatParam{map} for later use. When finished use FreeMap().
	/// @note Memory allocated with the modeling library (as with the N-gon library) does not use the usual @C4D memory manager but has its own system.\n
	///				So all memory must be freed through the correct library.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[out] map								The map pointer to release.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool ReleaseMap(C4DAtom *op, Int32 *map);

	//----------------------------------------------------------------------------------------
	/// Frees a @formatParam{map} table released by ReleaseMap().
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[out] map								The map pointer to free.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool FreeMap(C4DAtom *op, Int32 *map);

	/// @}

	/// @name Point
	/// @{

	//----------------------------------------------------------------------------------------
	/// Adds a new point to the object.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] p									The position of the point to add.
	/// @return												The virtual index of the added point, or @em 0 if an error occurred.
	//----------------------------------------------------------------------------------------
	Int32 AddPoint(C4DAtom *op, const Vector &p);

	//----------------------------------------------------------------------------------------
	/// Clones the point at @formatParam{index}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the point to clone. Can be an old index (positive) or a virtual index (negative).
	/// @return												The virtual index of the new point, or @em 0 if an error occurred.
	//----------------------------------------------------------------------------------------
	Int32 ClonePoint(C4DAtom *op, Int32 index);

	//----------------------------------------------------------------------------------------
	/// Deletes the point at @formatParam{index}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the point to delete. Can be an old index (positive) or a virtual index (negative).
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool DeletePoint(C4DAtom *op, Int32 index);

	//----------------------------------------------------------------------------------------
	/// Retrieves the position vector for a point at @formatParam{index} in @formatParam{p}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the point to get. Can be an old index (positive) or a virtual index (negative).
	/// @param[out] p									Assigned the point position.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetPoint(C4DAtom *op, Int32 index, Vector *p);

	//----------------------------------------------------------------------------------------
	/// Sets the position vector for a point at @formatParam{index} to @formatParam{p}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the point to set. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] p									The point position to set.
	/// @param[in] flags							The flags: @enumerateEnum{MODELING_SETPOINT_FLAG}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetPoint(C4DAtom *op, Int32 index, const Vector &p, Int32 flags = MODELING_SETPOINT_FLAG_EMPTY);

	//----------------------------------------------------------------------------------------
	/// Sets position vector for an edge point at @formatParam{index} to @formatParam{p}.
	/// An edge point is a point that has been inserted between 2 other points with the library (along an edge).\n
	/// This information is kept internal and can adjust the point along this edge with @formatParam{l}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the edge point to set.
	/// @param[in] l									The edge coordinate, between @em 0 and @em 1.
	/// @param[in] flags							The flags: @enumerateEnum{MODELING_SETPOINT_FLAG}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetEdgePoint(C4DAtom *op, Int32 index, Float l, Int32 flags = MODELING_SETPOINT_FLAG_EMPTY);

	//----------------------------------------------------------------------------------------
	/// Sets many points in one call using an array of PointMove.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] pnts								An array with instructions how to move the points. @callerOwnsPointed{array}
	/// @param[in] cnt								The size of the @formatParam{pnts} array.
	/// @param[in] commit							If @formatConstant{true} the move triggers a Commit().
	/// @param[in] flags							The flags: @enumerateEnum{MODELING_SETPOINT_FLAG}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetPoints(C4DAtom *op, PointMove *pnts, Int32 cnt, Bool commit = false, Int32 flags = MODELING_SETPOINT_FLAG_EMPTY);

	//----------------------------------------------------------------------------------------
	/// Retrieves the information for a point that was inserted along an edge.\n
	/// If the point was not an edge point then the indexes will be assigned @ref NOTINDEX.\n
	/// This can also be used to check if a point was a clone, as cloned points would return @formatParam{ia} == @formatParam{ib}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the edge point to get information for.
	/// @param[out] ia								Assigned the index of the first point of the original edge.
	/// @param[out] ib								Assigned the index of the second point of the original edge.
	/// @param[out] t									Assigned the position along the edge.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetPointInfo(C4DAtom *op, Int32 index, Int32 &ia, Int32 &ib, Float &t);

	//----------------------------------------------------------------------------------------
	/// Retrieves the original point for a cloned point.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the cloned point.
	/// @param[out] ci								Assigned the cloned index.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetOriginPoint(C4DAtom *op, Int32 index, Int32 &ci);

	//----------------------------------------------------------------------------------------
	/// Sets the edge/clone information for a point. For a clone @formatParam{ia} == @formatParam{ib} and @formatParam{t} is @em 0.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the point to set.
	/// @param[in] ia									The first point of the original edge.
	/// @param[in] ib									The second point of the original edge.
	/// @param[in] t									The position along the edge.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetPointInfo(C4DAtom *op, Int32 index, Int32 ia, Int32 ib, Float t);

	//----------------------------------------------------------------------------------------
	/// Sets the original index for a point, making it a clone of that point.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the point to set.
	/// @param[in] ci									The index of the original point. Can be an old index (positive) or a virtual index (negative).
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetOriginPoint(C4DAtom *op, Int32 index, Int32 ci);

	//----------------------------------------------------------------------------------------
	/// Gets the flags for a point.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the point to get the flags for. Can be an old index (positive) or a virtual index (negative).
	/// @return												The point flags: @enumerateEnum{MODELING_SETPOINT_FLAG}
	//----------------------------------------------------------------------------------------
	Int32 GetPointFlags(C4DAtom *op, Int32 index);

	//----------------------------------------------------------------------------------------
	/// Sets the flags for a point.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the point to set the flags for. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] flags							The new point flags: @enumerateEnum{MODELING_SETPOINT_FLAG}
	/// @return												The old point flags.
	//----------------------------------------------------------------------------------------
	Int32 SetPointFlags(C4DAtom *op, Int32 index, Int32 flags);

	//----------------------------------------------------------------------------------------
	/// Gets the original position of a cloned point.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the point to get the original position for.
	/// @param[out] opnt							Assigned the original point position.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetPointOrigin(C4DAtom *op, Int32 index, Vector &opnt);

	//----------------------------------------------------------------------------------------
	/// Sets the original position of a cloned point.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the point to set the original position for.
	/// @param[in] opnt								The new original point position.
	/// @param[in] flags							The point flags: @enumerateEnum{MODELING_SETPOINT_FLAG}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetPointOrigin(C4DAtom *op, Int32 index, Vector opnt, Int32 flags);

	//----------------------------------------------------------------------------------------
	/// Sets an interpolated point @formatParam{npnt} on the position @formatParam{t} along its edge.\n
	/// The point along an edge must have been previoulsy created e.g. with SplitEdge(), so that the modeling engine knows which @em 2 points it was created between.\n
	/// Then use this function to give it a new position along the edge.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the point to set the interpolation information for.
	/// @param[in] npnt								The new position for the point. It is supposed to be along its edge, but it can actually be anywhere. The main aim here is to get the UVs along the edge.
	/// @param[in] t									The new position along the edge for the interpolation. This information is used to update tags, e.g. finding the UVs within a polygon.
	/// @param[in] flags							The point flags: @enumerateEnum{MODELING_SETPOINT_FLAG}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetInterPoint(C4DAtom *op, Int32 index, Vector npnt, Float t, Int32 flags = MODELING_SETPOINT_FLAG_EMPTY);

	//----------------------------------------------------------------------------------------
	/// For N-gon interpolation.
	/// The @formatParam{move} vector should be within the N-gon, e.g. something like extrude inner, while @formatParam{offset} is just added to the point and not used for the interpolation within the N-gon.\n
	/// The information set is used to update tags, e.g. finding the UVs within a polygon.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the point to set the interpolation information for.
	/// @param[in] move								The move vector within the N-gon.
	/// @param[in] offset							The offset vector for the point.
	/// @param[in] flags							The point flags: @enumerateEnum{MODELING_SETPOINT_FLAG}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetInterPoint(C4DAtom *op, Int32 index, const Vector &move, const Vector &offset, Int32 flags = MODELING_SETPOINT_FLAG_EMPTY);

	/// @}

	/// @name Polygon/Ngon
	/// @{

	//----------------------------------------------------------------------------------------
	/// Creates an empty N-gon.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] flags							The flags: @enumerateEnum{MODELING_SETNGON_FLAG}
	/// @return												The virtual index of the new N-gon, or @em 0 if an error occurred.
	//----------------------------------------------------------------------------------------
	Int32 NewNgon(C4DAtom *op, Int32 flags = MODELING_SETNGON_FLAG_EMPTY);

	//----------------------------------------------------------------------------------------
	/// Creates an N-gon based on the passed Ngon data.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] ngon								The N-gon to add.
	/// @param[in] flags							The flags: @enumerateEnum{MODELING_SETNGON_FLAG}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Int32 AddNgon(C4DAtom *op, const Ngon &ngon, Int32 flags = MODELING_SETNGON_FLAG_EMPTY);

	//----------------------------------------------------------------------------------------
	/// Creates an N-gon based on an array of point indices in @formatParam{padr}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] padr								The array with indices for the points of the N-gon to create. @callerOwnsPointed{array}
	/// @param[in] cnt								The size of the @formatParam{padr} array.
	/// @param[in] flags							The flags: @enumerateEnum{MODELING_SETNGON_FLAG}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Int32 CreateNgon(C4DAtom *op, Int32 *padr, Int32 cnt, Int32 flags = MODELING_SETNGON_FLAG_EMPTY);

	//----------------------------------------------------------------------------------------
	/// Removes an N-gon.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to delete. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] points							If @formatConstant{true} the points of the N-gon are checked and removed if they are not used by other N-gons.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool DeleteNgon(C4DAtom *op, Int32 index, Bool points);

	//----------------------------------------------------------------------------------------
	/// Create an N-gon based on another N-gon at @formatParam{index}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to clone. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] flags							The flags: @enumerateEnum{MODELING_SETNGON_FLAG}
	/// @return												The virtual index of the new N-gon, or @em 0 if an error occurred.
	//----------------------------------------------------------------------------------------
	Int32 CloneNgon(C4DAtom *op, Int32 index, Int32 flags = MODELING_SETNGON_FLAG_EMPTY);

	//----------------------------------------------------------------------------------------
	/// Retrieves an N-gon.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to get. Can be an old index (positive) or a virtual index (negative).
	/// @param[out] ngon							The structure to fill with the N-gon information. @callerOwnsPointed{structure}
	/// @param[in] flags							The flags: @enumerateEnum{MODELING_SETNGON_FLAG}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetNgon(C4DAtom *op, Int32 index, Ngon *ngon, Int32 flags = MODELING_GETNGON_FLAG_EMPTY);

	//----------------------------------------------------------------------------------------
	/// Sets an N-gon.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to set. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] ngon								The N-gon structure to set.
	/// @param[in] flags							The flags: @enumerateEnum{MODELING_SETNGON_FLAG}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetNgon(C4DAtom *op, Int32 index, Ngon &ngon, Int32 flags = MODELING_SETNGON_FLAG_EMPTY);

	//----------------------------------------------------------------------------------------
	/// Calculates the normal for an N-gon.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to get the normal for. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] n									Assigned the normal vector. @callerOwnsPointed{vector}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetNgonNormal(C4DAtom *op, Int32 index, Vector *n);

	//----------------------------------------------------------------------------------------
	/// Reverses the normal of an N-gon.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to reverse the normal of. Can be an old index (positive) or a virtual index (negative).
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool FlipNgonNormal(C4DAtom *op, Int32 index);

	//----------------------------------------------------------------------------------------
	/// Gets the original index of an N-gon.\n
	/// This index is used when updating tags so the tag translation knows where any N-gon clones originated from.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the cloned N-gon.
	/// @param[in] ci									Assigned the original index.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetOriginNgon(C4DAtom *op, Int32 index, Int32 &ci);

	//----------------------------------------------------------------------------------------
	/// Sets the original index of a cloned N-gon.\n
	/// This index is used when updating tags so the tag translation knows where any N-gon clones originated from.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to set the original index for.
	/// @param[in] ci									The original index.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool SetOriginNgon(C4DAtom *op, Int32 index, Int32 ci);

	//----------------------------------------------------------------------------------------
	/// Gets the flags for an N-gon.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to get the flags for. Can be an old index (positive) or a virtual index (negative).
	/// @return												The flags: @enumerateEnum{MODELING_SETNGON_FLAG}
	//----------------------------------------------------------------------------------------
	Int32 GetNgonFlags(C4DAtom *op, Int32 index);

	//----------------------------------------------------------------------------------------
	/// Sets the flags for an N-gon.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to set the flags for. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] flags							The new flags: @enumerateEnum{MODELING_SETNGON_FLAG}
	/// @return												The old flags.
	//----------------------------------------------------------------------------------------
	Int32 SetNgonFlags(C4DAtom *op, Int32 index, Int32 flags);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool ResizeNgon(C4DAtom *op, Int32 index, Int32 pcnt, Int32 scnt);

	/// @}

	/// @name Operations
	/// @{

	//----------------------------------------------------------------------------------------
	/// Welds the source point @formatParam{index} to @formatParam{dest}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] source							The index of the source point. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] dest								The index of the destination point. Can be an old index (positive) or a virtual index (negative).
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool WeldPoints(C4DAtom *op, Int32 source, Int32 dest);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool InsertFacePoint(C4DAtom *op, Int32 pa, Int32 p1);

	//----------------------------------------------------------------------------------------
	/// Adds the hole in @formatParam{ngon} into the N-gon at @formatParam{index}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to add the hole to. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] ngon								The hole N-gon.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CreateHole(C4DAtom *op, Int32 index, const Ngon &ngon);

	//----------------------------------------------------------------------------------------
	/// Adds the hole with points in @formatParam{pnts} into the N-gon at @formatParam{index}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to add the hole to. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] pnts								An array with the hole N-gon points.
	/// @param[in] pcnt								The size of the @formatParam{pnts} array.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool CreateHole(C4DAtom *op, Int32 index, Int32 *pnts, Int32 pcnt);

	//----------------------------------------------------------------------------------------
	/// Splits an edge (defined by the point indices @formatParam{p1} to @formatParam{p2}) at @formatParam{l} (@em 0 to @em 1) creating a new edge point with the index returned.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] p1									The index of the first point of the edge. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] p2									The index of the second point of the edge. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] l									The position along the edge, between @em 0 and @em 1.
	/// @return												The virtual index of the new edge point, or @em 0 if an error occurred.
	//----------------------------------------------------------------------------------------
	Int32 SplitEdge(C4DAtom *op, Int32 p1, Int32 p2, Float l);

	//----------------------------------------------------------------------------------------
	/// Deletes an edge defined by @formatParam{p1} and @formatParam{p2}. If this results in an N-gon with less than @em 3 points then the N-gon will be removed.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] p1									The index of the first point of the edge to remove. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] p2									The index of the second point of the edge to remove. Can be an old index (positive) or a virtual index (negative).
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool DeleteEdge(C4DAtom *op, Int32 index, Int32 p1, Int32 p2);

	//----------------------------------------------------------------------------------------
	/// Melts an edge between the 2 n-gons at @formatParam{pa} and @formatParam{pb}. The edge is defined by the points @formatParam{p1} and @formatParam{p2}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] pa									The index of the first N-gon. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] pb									The index of the second N-gon. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] p1									The index of the first point of the edge. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] p2									The index of the second point of the edge. Can be an old index (positive) or a virtual index (negative).
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool MeltEdgeBetween(C4DAtom *op, Int32 pa, Int32 pb, Int32 p1, Int32 p2);

	//----------------------------------------------------------------------------------------
	/// Melt the edge (@formatParam{p1} to @formatParam{p2}) of N-gon @formatParam{pa}.
	/// @note MeltEdge() accepts @ref NOTINDEX for the N-gon index @formatParam{pa}, in which case it takes the first index for the edge it finds.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] pa									The index of the N-gon. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] p1									The index of the first point of the edge to melt. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] p2									The index of the second point of the edge to melt. Can be an old index (positive) or a virtual index (negative).
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool MeltEdge(C4DAtom *op, Int32 pa, Int32 p1, Int32 p2);

	//----------------------------------------------------------------------------------------
	/// Melts the N-gons around point @formatParam{p}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] p									The index of the point, the N-gons around which are to be melted. Can be an old index (positive) or a virtual index (negative).
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool MeltPoint(C4DAtom *op, Int32 p);

	//----------------------------------------------------------------------------------------
	/// Melts the N-gon @formatParam{pa} into its surrounding N-gons.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] pa									The index of the N-gon to melt. Can be an old index (positive) or a virtual index (negative).
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool MeltNgon(C4DAtom *op, Int32 pa);

	//----------------------------------------------------------------------------------------
	/// Cuts the N-gon at @formatParam{index} between points @formatParam{p1} and @formatParam{p2}, returning the newly created N-gon index.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to split. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] p1									The index of the first point of the split. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] p2									The index of the second point of the split. Can be an old index (positive) or a virtual index (negative).
	/// @return												The newly created N-gon index or the passed index for no change, otherwise @ref NOTINDEX for fail.
	//----------------------------------------------------------------------------------------
	Int32 SplitPolygon(C4DAtom *op, Int32 index, Int32 p1, Int32 p2);

	//----------------------------------------------------------------------------------------
	/// Merges the points of @formatParam{pb} into @formatParam{pa} making them into holes of @formatParam{pa}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] pa									The index of the first N-gon. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] pb									The index of the second N-gon. Can be an old index (positive) or a virtual index (negative).
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool MergePolygons(C4DAtom *op, Int32 pa, Int32 pb);

	//----------------------------------------------------------------------------------------
	/// Checks if the edge (@formatParam{p1} to @formatParam{p2}) of the N-gon at @formatParam{index} is valid (exists).
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to check. Can be an old index (positive) or a virtual index (negative).\n
	/// 															Pass @ref NOTINDEX to check that the edge (@formatParam{p1},@formatParam{p2}) exists and is an N-gon edge.
	/// @param[in] p1									The index of the first point of the edge to check. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] p2									The index of the second point of the edge to check. Can be an old index (positive) or a virtual index (negative).
	/// @return												@trueIfOtherwiseFalse{the edge is valid}
	//----------------------------------------------------------------------------------------
	Bool IsValidEdge(C4DAtom *op, Int32 index, Int32 p1, Int32 p2);

	//----------------------------------------------------------------------------------------
	/// Check if the N-gon at @formatParam{index} is valid (exists).
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to check. Can be an old index (positive) or a virtual index (negative).
	/// @return												@trueIfOtherwiseFalse{the N-gon is valid}
	//----------------------------------------------------------------------------------------
	Bool IsValidNgon(C4DAtom *op, Int32 index);

	//----------------------------------------------------------------------------------------
	/// Check if the point at @formatParam{index} exists.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the point to check. Can be an old index (positive) or a virtual index (negative).
	/// @return												@trueIfOtherwiseFalse{the point is valid}
	//----------------------------------------------------------------------------------------
	Bool IsValidPoint(C4DAtom *op, Int32 index);

	//----------------------------------------------------------------------------------------
	/// Retrieves an array with the N-gons that share the edge between @formatParam{p1} and @formatParam{p2}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] p1									The index of the first point of the edge to check. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] p2									The index of the second point of the edge to check. Can be an old index (positive) or a virtual index (negative).
	/// @param[out] pcnt							Assigned the number of N-gons found.
	/// @return												The array of N-gon indices. The size is given by @formatParam{pcnt}. @callerOwnsPointed{array}\n
	/// 															Use the modeling library FreeTable() function to free the data afterwards.
	//----------------------------------------------------------------------------------------
	Int32 *GetEdgeNgons(C4DAtom *op, Int32 p1, Int32 p2, Int32 &pcnt);

	//----------------------------------------------------------------------------------------
	/// Retrieves a table of the N-gons that share the point at @formatParam{p}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] p									The index of the point to check. Can be an old index (positive) or a virtual index (negative).
	/// @param[out] pcnt							Assigned the number of N-gons found.
	/// @param[in] clone							If @formatConstant{false} a pointer to an internal array is returned. Then it is not need to use FreeTable().
	/// @return												The array of N-gon indices. The size is given by @formatParam{pcnt}. @callerOwnsPointed{array}\n
	/// 															Use the modeling library FreeTable() function to free the data afterwards if clone was @formatConstant{true}.
	//----------------------------------------------------------------------------------------
	Int32 *GetPointNgons(C4DAtom *op, Int32 p, Int32 &pcnt, Bool clone = true);

	//----------------------------------------------------------------------------------------
	/// Retrieves the N-gons that neighbour the N-gon at index.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to check. Can be an old index (positive) or a virtual index (negative).
	/// @param[out] pcnt							Assigned the number of N-gons found.
	/// @return												The array of N-gon indices. The size is given by @formatParam{pcnt}. @callerOwnsPointed{array}\n
	/// 															Use the modeling library FreeTable() function to free the data afterwards.
	//----------------------------------------------------------------------------------------
	Int32 *GetNeighborNgons(C4DAtom *op, Int32 index, Int32 &pcnt);

	//----------------------------------------------------------------------------------------
	/// Retrieves all the edges that use the point @formatParam{p}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] p									The index of the point to check. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] ecnt								Assigned the number of edges found.
	/// @return												The array of edge indices. The size is given by @formatParam{ecnt}.
	//----------------------------------------------------------------------------------------
	Int32 *GetPointEdges(C4DAtom *op, Int32 p, Int32 &ecnt);

	//----------------------------------------------------------------------------------------
	/// Finds any N-gon with the edge @formatParam{p1} to @formatParam{p2}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] p1									The index of the first point of the edge to search for. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] p2									The index of the second point of the edge to search for. Can be an old index (positive) or a virtual index (negative).
	/// @param[out] index							Assigned the index of the found N-gon.
	/// @return												@trueIfOtherwiseFalse{the N-gon was found}
	//----------------------------------------------------------------------------------------
	Bool FindNgon(C4DAtom *op, Int32 p1, Int32 p2, Int32 &index);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	Bool GetEdgeSegment(C4DAtom *op, Int32 pa, Int32 p1, Int32 p2, Int32 *seg, Int32 *s1, Int32 *s2, Bool rel);

	//----------------------------------------------------------------------------------------
	/// Gets the original points from @formatParam{edge}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] edge								The index of the edge to get the points for. Can be an old index (positive) or a virtual index (negative).
	/// @param[out] p1								Assigned the index of the first point of the edge.
	/// @param[out] p2								Assigned the index of the second point of the edge.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetOriginalEdgePoints(C4DAtom *op, Int32 edge, Int32 &p1, Int32 &p2);

	//----------------------------------------------------------------------------------------
	/// Checks if the edge between @formatParam{p1} and @formatParam{p2} has been deleted.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] p1									The index of the first point of the edge to check. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] p2									The index of the second point of the edge to check. Can be an old index (positive) or a virtual index (negative).
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool IsEdgeDeleted(C4DAtom *op, Int32 p1, Int32 p2);

	//----------------------------------------------------------------------------------------
	/// Checks if the point at @formatParam{index} has been deleted.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the point to check. Can be an old index (positive) or a virtual index (negative).
	/// @return												@trueIfOtherwiseFalse{the point has been deleted}
	//----------------------------------------------------------------------------------------
	Bool IsPointDeleted(C4DAtom *op, Int32 index);

	//----------------------------------------------------------------------------------------
	/// Checks if the N-gon at @formatParam{index} has been deleted.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to check. Can be an old index (positive) or a virtual index (negative).
	/// @return												@trueIfOtherwiseFalse{the face has been deleted}
	//----------------------------------------------------------------------------------------
	Bool IsFaceDeleted(C4DAtom *op, Int32 index);

	//----------------------------------------------------------------------------------------
	/// Translates an N-gon index. Once an N-gon is accessed then a virtual clone is created for it, using these functions translate between the real index and its virtual index.
	/// @note This is not normally needed, all functions manage translations.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The original N-gon index.
	/// @param[in] tovirtual					If @formatConstant{true} the conversion is done from real to virtual, otherwise from virtual to real.
	/// @return												The translated N-gon index.
	//----------------------------------------------------------------------------------------
	Int32 TranslateNgonIndex(C4DAtom *op, Int32 index, Bool tovirtual = false);

	//----------------------------------------------------------------------------------------
	/// Translates a point index. Once an point is accessed then a virtual clone is created for it, using these functions you can translate between the real index and its virtual index.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The original point index.
	/// @param[in] tovirtual					If @formatConstant{true} the conversion is done from real to virtual, otherwise from virtual to real.
	/// @return												The translated point index.
	//----------------------------------------------------------------------------------------
	Int32 TranslatePointIndex(C4DAtom *op, Int32 index, Bool tovirtual = false);

	//----------------------------------------------------------------------------------------
	/// Converts a regular selection of polygons into the indices <tt>[polygons][ngons]</tt> used within the modeling kernel.
	/// @note This is not normally needed, all functions manage translations.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] select							A regular polygon selection. @callerOwnsPointed{selection}
	/// @param[out] faceselect				Filled with the translated polygon selection. @callerOwnsPointed{selection}
	/// @param[out] hidden						Optionally filled with the hidden selection. @callerOwnsPointed{selection}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetFaceSelection(C4DAtom *op, BaseSelect *select, BaseSelect *faceselect, BaseSelect *hidden = nullptr);

	//----------------------------------------------------------------------------------------
	/// Converts a regular selection of edges into the indices used within the modeling kernel.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] select							A regular edge selection. @callerOwnsPointed{selection}
	/// @param[out] edgeselect				Filled with the translated edge selection. @callerOwnsPointed{selection}
	/// @param[out] hidden						Optionally filled with the hidden selection. @callerOwnsPointed{selection}
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetEdgeSelection(C4DAtom *op, BaseSelect *select, BaseSelect *edgeselect, BaseSelect *hidden = nullptr);

	//----------------------------------------------------------------------------------------
	/// Converts a regular selection of edges into an array of the indices used within the modeling kernel.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] select							A regular edge selection. @callerOwnsPointed{selection}
	/// @param[out] ecnt							Assigned the size of the returned edge index array.
	/// @param[out] hidden						Optionally filled with the hidden selection. @callerOwnsPointed{selection}
	/// @param[in] tovirtual					If @formatConstant{true} conversion is done from real to virtual, otherwise from virtual to real.
	/// @return												The array of edge indices. The size is given by @formatParam{ecnt}. @callerOwnsPointed{array}\n
	/// 															Use the modeling library FreeTable() function to free the data afterwards.
	//----------------------------------------------------------------------------------------
	Int32 *GetEdgeSelectionArray(C4DAtom *op, BaseSelect *select, Int32 &ecnt, BaseSelect *hidden = nullptr, Bool tovirtual = true);

	/// @}

	/// @name Information
	/// @{

	//----------------------------------------------------------------------------------------
	/// Retrieves the last error code from the modeling engine.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @return												The error code: @enumerateEnum{MODELING_ERROR}
	//----------------------------------------------------------------------------------------
	Int32 GetLastError(C4DAtom *op);

	//----------------------------------------------------------------------------------------
	/// Checks if any editing has been done to the object (virtually).
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{@formatParam{op} is modified}
	//----------------------------------------------------------------------------------------
	Bool IsModified(C4DAtom *op);

	/// @}

	/// @name Free Table
	/// @{

	//----------------------------------------------------------------------------------------
	/// Frees tables created by the modeling engine.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[out] table							The table to free.
	//----------------------------------------------------------------------------------------
	void FreeTable(C4DAtom *op, void *table);

	/// @}

	/// @name Helpers
	/// @{

	//----------------------------------------------------------------------------------------
	/// Check if the point at @formatParam{p} is within the boundaries of the N-gon at @formatParam{index}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the point to check. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] p									The point position.
	/// @return												@trueIfOtherwiseFalse{@formatParam{p} is in the N-gon}
	//----------------------------------------------------------------------------------------
	Bool PointInFace(C4DAtom *op, Int32 index, const Vector &p);

	//----------------------------------------------------------------------------------------
	/// Check if the point at @formatParam{p} is within the boundaries of the N-gon in @formatParam{ngon}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] ngon								The N-gon to check.
	/// @param[in] p									The point position.
	/// @return												@trueIfOtherwiseFalse{@formatParam{p} is in the N-gon}
	//----------------------------------------------------------------------------------------
	Bool PointInFace(C4DAtom *op, const Ngon &ngon, const Vector &p);

	//----------------------------------------------------------------------------------------
	/// Checks if the line from @formatParam{p1} to @formatParam{p2} intersects the N-gon at @formatParam{index}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] index							The index of the N-gon to check. Can be an old index (positive) or a virtual index (negative).
	/// @param[in] p1									The first point of the line.
	/// @param[in] p2									The second point of the line.
	/// @return												@trueIfOtherwiseFalse{the line intersects the face at @formatParam{index}}
	//----------------------------------------------------------------------------------------
	Bool LineFaceIntersection(C4DAtom *op, Int32 index, const Vector &p1, const Vector &p2);

	//----------------------------------------------------------------------------------------
	/// Check if the line from @formatParam{p1} to @formatParam{p2} intersects the N-gon in @formatParam{ngon}.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] ngon								The N-gon to check.
	/// @param[in] p1									The first point of the line.
	/// @param[in] p2									The second point of the line.
	/// @return												@trueIfOtherwiseFalse{the line intersects the face in @formatParam{ngon}}
	//----------------------------------------------------------------------------------------
	Bool LineFaceIntersection(C4DAtom *op, const Ngon &ngon, const Vector &p1, const Vector &p2);

	/// @}

	/// @name Triangulate Hook
	/// @{

	//----------------------------------------------------------------------------------------
	/// Sets a triangulation function to be used instead of the internal one.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[in] pHook							The new triangulation hook.
	/// @param[in] pData							The private data, passed to the hook.
	//----------------------------------------------------------------------------------------
	void SetTriangulateHook(C4DAtom *op, TriangulateHook pHook, void *pData);

	//----------------------------------------------------------------------------------------
	/// Gets the current custom triangulation hook.
	/// @param[in] op									An initialized object. @callerOwnsPointed{object}
	/// @param[out] ppHook						Assigned the triangulation hook.
	/// @param[out] ppData						Assigned the hook private data.
	//----------------------------------------------------------------------------------------
	void GetTriangulateHook(C4DAtom *op, TriangulateHook *ppHook, void **ppData);

	/// @}
};

/// Modeling library ID.
#define LIBRARY_MODELLING 1015814

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct ModelingLib : public C4DLibrary
{
	iModeling *(*Alloc)();
	void (*Free)(iModeling *&p);

	Bool (iModeling::*InitArray)(AtomArray *objs, Int32 flags);
	Bool (iModeling::*InitObject)(C4DAtom *op, Int32 flags);
	Bool (iModeling::*Commit)(C4DAtom *op, Int32 flags, BaseObject* cobj);
	void (iModeling::*Release)();
	void (iModeling::*ReleaseObject)(C4DAtom *op);

	Int32 (iModeling::*AddPoint)(C4DAtom *op, const Vector &p);
	Int32 (iModeling::*ClonePoint)(C4DAtom *op, Int32 index);
	Bool (iModeling::*DeletePoint)(C4DAtom *op, Int32 index);
	Bool (iModeling::*GetPoint)(C4DAtom *op, Int32 index, Vector *p);
	Bool (iModeling::*SetPoint)(C4DAtom *op, Int32 index, const Vector &p, Int32 flags);
	Bool (iModeling::*SetEdgePoint)(C4DAtom *op, Int32 index, Float l, Int32 flags);
	Bool (iModeling::*SetPoints)(C4DAtom *op, PointMove *pnts, Int32 cnt, Bool commit, Int32 flags);

	Int32 (iModeling::*NewNgon)(C4DAtom *op, Int32 flags);
	Int32 (iModeling::*AddNgon)(C4DAtom *op, const Ngon &ngon, Int32 flags);
	Int32 (iModeling::*CreateNgon)(C4DAtom *op, Int32 *padr, Int32 cnt, Int32 flags);
	Bool (iModeling::*DeleteNgon)(C4DAtom *op, Int32 index, Bool points);
	Int32 (iModeling::*CloneNgon)(C4DAtom *op, Int32 index, Int32 flags);
	Bool (iModeling::*GetNgon)(C4DAtom *op, Int32 index, Ngon *ngon, Int32 flags);
	Bool (iModeling::*SetNgon)(C4DAtom *op, Int32 index, Ngon &ngon, Int32 flags);
	Bool (iModeling::*GetNgonNormal)(C4DAtom *op, Int32 index, Vector *n);
	Bool (iModeling::*FlipNgonNormal)(C4DAtom *op, Int32 index);

	Int32 (iModeling::*SplitEdge)(C4DAtom *op, Int32 p1, Int32 p2, Float l);
	Bool (iModeling::*DeleteEdge)(C4DAtom *op, Int32 index, Int32 p1, Int32 p2);

	Bool (iModeling::*MeltEdgeBetween)(C4DAtom *op, Int32 pa, Int32 pb, Int32 p1, Int32 p2);
	Bool (iModeling::*MeltEdge)(C4DAtom *op, Int32 pa, Int32 p1, Int32 p2);
	Bool (iModeling::*MeltPoint)(C4DAtom *op, Int32 p);

	Int32 (iModeling::*SplitPolygon)(C4DAtom *op, Int32 index, Int32 p1, Int32 p2);
	Bool (iModeling::*MergePolygons)(C4DAtom *op, Int32 pa, Int32 pb);

	Bool (iModeling::*IsValidEdge)(C4DAtom *op, Int32 index, Int32 p1, Int32 p2);
	Bool (iModeling::*IsValidNgon)(C4DAtom *op, Int32 index);
	Bool (iModeling::*IsValidPoint)(C4DAtom *op, Int32 index);

	Int32 *(iModeling::*GetEdgeNgons)(C4DAtom *op, Int32 p1, Int32 p2, Int32 &pcnt);
	Int32 *(iModeling::*GetPointNgons)(C4DAtom *op, Int32 p, Int32 &pcnt, Bool clone);
	Int32 *(iModeling::*GetNeighborNgons)(C4DAtom *op, Int32 index, Int32 &pcnt);
	Int32 *(iModeling::*GetPointEdges)(C4DAtom *op, Int32 p, Int32 &ecnt);
	Bool (iModeling::*FindNgon)(C4DAtom *op, Int32 p1, Int32 p2, Int32 &index);

	Bool (iModeling::*GetOriginalEdgePoints)(C4DAtom *op, Int32 edge, Int32 &p1, Int32 &p2);
	Bool (iModeling::*IsEdgeDeleted)(C4DAtom *op, Int32 p1, Int32 p2);

	Int32 (iModeling::*TranslateNgonIndex)(C4DAtom *op, Int32 index, Bool tovirtual);
	Int32 (iModeling::*TranslatePointIndex)(C4DAtom *op, Int32 index, Bool tovirtual);

	Bool (iModeling::*GetPointMap)(C4DAtom *op, Int32 **map, Int32 *count);
	Bool (iModeling::*GetNgonMap)(C4DAtom *op, Int32 **map, Int32 *count);
	Bool (iModeling::*ReleaseMap)(C4DAtom *op, Int32 *map);
	Bool (iModeling::*FreeMap)(C4DAtom *op, Int32 *map);

	Int32 (iModeling::*GetLastError)(C4DAtom *op);
	Bool (iModeling::*IsModified)(C4DAtom *op);

	Bool (iModeling::*GetPointInfo)(C4DAtom *op, Int32 index, Int32 &ia, Int32 &ib, Float &t);
	Bool (iModeling::*GetOriginPoint)(C4DAtom *op, Int32 index, Int32 &ci);
	Bool (iModeling::*GetOriginNgon)(C4DAtom *op, Int32 index, Int32 &ci);

	Bool (iModeling::*SetOriginNgon)(C4DAtom *op, Int32 index, Int32 ci);
	Int32 (iModeling::*GetNgonFlags)(C4DAtom *op, Int32 index);
	Int32 (iModeling::*SetNgonFlags)(C4DAtom *op, Int32 index, Int32 flags);

	Bool (iModeling::*SetPointInfo)(C4DAtom *op, Int32 index, Int32 ia, Int32 ib, Float t);
	Bool (iModeling::*SetOriginPoint)(C4DAtom *op, Int32 index, Int32 ci);
	Int32 (iModeling::*GetPointFlags)(C4DAtom *op, Int32 index);
	Int32 (iModeling::*SetPointFlags)(C4DAtom *op, Int32 index, Int32 flags);

	Bool (iModeling::*GetPointOrigin)(C4DAtom *op, Int32 index, Vector &opnt);
	Bool (iModeling::*SetPointOrigin)(C4DAtom *op, Int32 index, Vector opnt, Int32 flags);
	Bool (iModeling::*SetInterPointBetween)(C4DAtom *op, Int32 index, Vector npnt, Float t, Int32 flags);
	Bool (iModeling::*WeldPoints)(C4DAtom *op, Int32 source, Int32 dest);
	Bool (iModeling::*MeltNgon)(C4DAtom *op, Int32 pa);

	Bool (iModeling::*IsPointDeleted)(C4DAtom *op, Int32 index);
	Bool (iModeling::*IsFaceDeleted)(C4DAtom *op, Int32 index);

	Bool (iModeling::*SetInterPointMove)(C4DAtom *op, Int32 index, const Vector &move, const Vector &offset, Int32 flags);

	Bool (iModeling::*GetFaceSelection)(C4DAtom *op, BaseSelect *select, BaseSelect *faceselect, BaseSelect *hidden);
	Bool (iModeling::*GetEdgeSelection)(C4DAtom *op, BaseSelect *select, BaseSelect *edgeselect, BaseSelect *hidden);
	Int32 *(iModeling::*GetEdgeSelectionArray)(C4DAtom *op, BaseSelect *select, Int32 &ecnt, BaseSelect *hidden, Bool tovirtual);
	Bool (iModeling::*InsertFacePoint)(C4DAtom *op, Int32 pa, Int32 p1);
	Bool (iModeling::*CreateHole)(C4DAtom *op, Int32 index, const Ngon &ngon);
	Bool (iModeling::*CreateHoleFromPoints)(C4DAtom *op, Int32 index, Int32 *pnts, Int32 pcnt);
	Bool (iModeling::*ResizeNgon)(C4DAtom *op, Int32 index, Int32 pcnt, Int32 scnt);
	Bool (iModeling::*GetEdgeSegment)(C4DAtom *op, Int32 pa, Int32 p1, Int32 p2, Int32 *seg, Int32 *s1, Int32 *s2, Bool rel);

	void (iModeling::*FreeTable)(void *table);

	Bool (iModeling::*PointInFace)(C4DAtom *op, Int32 index, const Vector &p);
	Bool (iModeling::*PointInFaceNgon)(C4DAtom *op, const Ngon &ngon, const Vector &p);
	Bool (iModeling::*LineFaceIntersection)(C4DAtom *op, Int32 index, const Vector &p1, const Vector &p2);
	Bool (iModeling::*LineFaceIntersectionNgon)(C4DAtom *op, const Ngon &ngon, const Vector &p1, const Vector &p2);

	void (iModeling::*SetTriangulateHook)(C4DAtom *op, TriangulateHook pHook, void *pData);
	void (iModeling::*GetTriangulateHook)(C4DAtom *op, TriangulateHook *ppHook, void **ppData);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_MODELING_H__
