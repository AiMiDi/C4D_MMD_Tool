/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_SDS_H__
#define LIB_SDS_H__

#include "c4d_library.h"
#ifdef __API_INTERN__
#include "baseobject.h"
#else
#include "c4d_baseobject.h"
#include "c4d_basetag.h"
#endif

#ifdef __API_INTERN__
#include "hntag.h"
#endif

namespace cinema
{

class PolygonObject;


/// @addtogroup group_sdslibrary SDS
/// @ingroup group_library
/// @{

//----------------------------------------------------------------------------------------
/// Contains information for subdivided polygons of SDS objects.
/// @see SDSObject::GetSubdivisionMask()
//----------------------------------------------------------------------------------------
struct SDSSubdivisionMask
{
	Int32	p;			///< One of the original polygons.
	Int32	e1,			///< First original edge.
				e2,			///< Second original edge.
				e3,			///< Third original edge.
				e4;			///< Fourth original edge.
};

//----------------------------------------------------------------------------------------
/// Contains extended information for subdivided polygons of SDS objects.
//----------------------------------------------------------------------------------------
struct SDSSubdivisionMappings
{
	static constexpr Int32 INVALID_INDEX = -1;

	SDSSubdivisionMappings() { }
	SDSSubdivisionMappings(const SDSSubdivisionMappings& src) : 
		MAXON_COPY_MEMBERS(ngonSubdivision, maskCount, oldPolygonCount, vertexCount, mask, firstNewPolygon, nextBlock, vertexMap, firstNewVertex)
	{
	}
	SDSSubdivisionMappings(SDSSubdivisionMappings&& src) : 
		MAXON_MOVE_MEMBERS(ngonSubdivision, maskCount, oldPolygonCount, vertexCount, mask, firstNewPolygon, nextBlock, vertexMap, firstNewVertex)
	{
		new (&src) SDSSubdivisionMappings();
	}
	const SDSSubdivisionMappings& operator = (SDSSubdivisionMappings&& src)
	{
		new (this) SDSSubdivisionMappings(std::move(src));
		return *this;
	}
	const SDSSubdivisionMappings& operator = (const SDSSubdivisionMappings& src)
	{
		new (this) SDSSubdivisionMappings(src);
		return *this;
	}

	/// Specifies if Ngon subdivision was active.
	Bool ngonSubdivision = false;
	/// Number of entries in the mask array. This is equal to the number of polygons in the subdivided array.
	Int32 maskCount = 0;
	// Number of entries in firstNewPolygon and nextBlock. This value can be larger than the original polygon count.
	Int32 oldPolygonCount = 0;
	// Number of entries in vertexMap.
	Int32 vertexCount = 0;
	/// Subdivision mask.
	/// There is one entry in this mask for every new polygon.
	const SDSSubdivisionMask* mask = nullptr; 
	/// Polygon map which maps from the original polygon to the first new polygon that was created from this polygon.
	const Int32* firstNewPolygon = nullptr;
	/// If a polygon is split before subdivision, each entry of this block points to an index in firstNewPolygon. This acts like a linked list.
	const Int32* nextBlock = nullptr;
	///  Maps from new vertex to old vertex.
	const Int32* vertexMap = nullptr;
	///  Maps from old vertex to new vertex.
	const Int32* firstNewVertex = nullptr;

	/// Imagine the following scenario:
	/// Object with 4 quads
	/// Polygon 1 is cut by the symmetry object. Polygon 1 becomes a triangle and polygons 4 and 5 will be added.
	///   The symmetry object has created this mapping (new -> old):
	///     0 -> 0
	///     1 -> 1
	///     2 -> 2
	///     3 -> 3
	///     4 -> 1
	///     5 -> 1
	///   For the SDS object this means a polygon map of (nx stands for any index in the subdivided object):
	///     0 -> 0
	///     1 -> n1
	///     2 -> n2
	///     3 -> n3
	///     4 -> n4 This is the first new polygon that was created by the symmetry. We don't need element #5 because it has the same origin like #4.
	///   nextBlock will have these entries:
	///     0 -> INVALID_INDEX
	///     1 -> 4
	///     2 -> INVALID_INDEX
	///     3 -> INVALID_INDEX
	///     4 -> INVALID_INDEX
	///   This means that the new polygon indexes for #1 start at n1 and n4.
	/// Similar scenario, but this time, the symmetry object has deleted polygon 1 after splittin.
	///   The symmetry object has created this mapping (new -> old):
	///     0 -> 0
	///     1 -> 2
	///     2 -> 3
	///     3 -> 1
	///     4 -> 1
	///   And the polygon map for the SDS object. Note, that no further entries are needed since there is just one single block of new
	///     polygons that have their origin in polygon 1.
	///     0 -> 0
	///     1 -> n1 (which is basically the first new polygon which is created from polygon 3 of the symmetry result).
	///     2 -> n2
	///     3 -> n3
	///   nextBlock is not needed and thus nullptr.
};

//----------------------------------------------------------------------------------------
/// The SDS object class of type @ref Osds.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class SDSObject : public BaseObject
{
private:
	SDSObject();
	~SDSObject();
public:
	//----------------------------------------------------------------------------------------
	/// Gets the subdivision of @formatParam{op}.
	/// @param[in] op									A child of the SDS object. @callerOwnsPointed{object}
	/// @return												The subdivision.
	//----------------------------------------------------------------------------------------
	Int32 GetDivision(const BaseObject *op);

	//----------------------------------------------------------------------------------------
	/// Retrieves the subdivided mesh of @formatParam{op}, if it has been generated. (A convenience function to get the cache.)
	/// @param[in] op									A child of the SDS object. @callerOwnsPointed{object}
	/// @return												The subdivided mesh. @cinemaOwnsPointed{polygon object}
	//----------------------------------------------------------------------------------------
	PolygonObject *GetSDSMesh(const BaseObject *op);

	//----------------------------------------------------------------------------------------
	/// #LEGACYCOMPATIBILITY: remove
	/// Dummy function. Always return @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	Bool TransformPoint(const BaseObject *op, Int32 ply, Float &s, Float &t, Vector *p);

	//----------------------------------------------------------------------------------------
	/// Gets the transformed normal of polygon @formatParam{ply} of @formatParam{op}.
	/// @param[in] op									A child of the SDS object. @callerOwnsPointed{object}
	/// @param[in] ply								A polygon index.
	/// @param[out] p									Assigned the origin of the normal (center of the polygon).
	/// @param[out] n									Assigned the normal.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetNormal(const BaseObject *op, Int32 ply, Vector *p, Vector *n);

	//----------------------------------------------------------------------------------------
	/// Gets the number of point weighs that are stored in a @ref Tsds tags.
	/// @param[in] pTag								A @ref Tsds tag. @callerOwnsPointed{tag}
	/// @return												The number of point weights.
	//----------------------------------------------------------------------------------------
	static Int32 GetPointCount(const BaseTag *pTag);

	//----------------------------------------------------------------------------------------
	/// Extracts point weights from @ref Tsds tags.
	/// @param[in] pTag								A @ref Tsds tag. @callerOwnsPointed{tag}
	/// @return												The point weights. @theOwnsPointed{tag,array}
	//----------------------------------------------------------------------------------------
	static Float32 *GetPointWeights(BaseTag *pTag);

	//----------------------------------------------------------------------------------------
	/// Extracts point weights from @ref Tsds tags.
	/// @param[in] pTag								A @ref Tsds tag. @callerOwnsPointed{tag}
	/// @return												The point weights. @theOwnsPointed{tag,array}
	//----------------------------------------------------------------------------------------
	static const Float32 *GetPointWeights(const BaseTag *pTag);

	//----------------------------------------------------------------------------------------
	/// Gets the number of polygon/edge weighs that are stored in a @ref Tsds tags.
	/// @param[in] pTag								A @ref Tsds tag. @callerOwnsPointed{tag}
	/// @return												The number of polyon/edge weights.
	//----------------------------------------------------------------------------------------
	static Int32 GetPolygonCount(const BaseTag *pTag);

	//----------------------------------------------------------------------------------------
	/// Extracts polygon weights from @ref Tsds tags.
	/// @param[in] pTag								A @ref Tsds tag. @callerOwnsPointed{tag}
	/// @return												The polygon weights. @theOwnsPointed{tag,array}
	//----------------------------------------------------------------------------------------
	static PolyWeight *GetEdgeWeights(BaseTag *pTag);

	//----------------------------------------------------------------------------------------
	/// Extracts polygon weights from @ref Tsds tags.
	/// @param[in] pTag								A @ref Tsds tag. @callerOwnsPointed{tag}
	/// @return												The polygon weights. @theOwnsPointed{tag,array}
	//----------------------------------------------------------------------------------------
	static const PolyWeight *GetEdgeWeights(const BaseTag *pTag);

	//----------------------------------------------------------------------------------------
	/// Used to determine the original polygons in the subdivided mesh.
	/// @param[in] op									A child of the SDS object. @callerOwnsPointed{object}
	/// @param[out] maskcnt						Assigned the number of entries in the SDSSubdivisionMask array (should be equal to the polygon count of the subdivided object).
	/// @param[out] polymap						Assigned an array of the first new polygon that was made of a polygon during subdivision.\n
	///																The first polygon made of @c polyindex is <tt>polymap[polyindex]</tt>. @theOwnsPointed{SDS object,array}
	/// @param[out] ngonsubdiv				Assigned @trueIfOtherwiseFalse{an N-gon subdivision algorithm was used}\n
	///																It is only @formatConstant{false} when Catmull-Clark without the N-gons option is used.\n
	///																If an N-gon subdivision algorithm is used, alls polygons that were made out of an N-gon are in a single block in the new object, otherwise they may be spread within the complete object.
	/// @return												The subdivision mask array. @theOwnsPointed{SDS object,array}
	//----------------------------------------------------------------------------------------
	const SDSSubdivisionMask* GetSubdivisionMask(const BaseObject *op, Int32 &maskcnt, const Int32 *&polymap, Bool &ngonsubdiv) const;
	/// #LEGACYCOMPATIBILITY: remove
	[[deprecated("Use the other overload.")]] SDSSubdivisionMask* GetSubdivisionMask(const BaseObject *op, Int32 &maskcnt, Int32 *&polymap, Bool &ngonsubdiv) const;

	//----------------------------------------------------------------------------------------
	/// Used to determine information about how the object was subdivided. 
	/// @param[in] op									A cache item of the SDS object. @callerOwnsPointed{object}
	/// @param[out] mappings					A struct which will be filled with the subdivision data.
	/// @return												True, of subdivision information of the object could be found.
	//----------------------------------------------------------------------------------------
	Bool GetSubdivisionMappings(const BaseObject *op, SDSSubdivisionMappings& mappings) const;

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	const void* GetCreationData(const BaseObject *op);
};

/// SDS library ID.
#define LIBRARY_SDS	1016122

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct SDSObjectLib : public C4DLibrary
{
	Int32 *(*GetEdgeMap)(const BaseObject *sds, const BaseObject *op); // #LEGACYCOMPATIBILITY: remove
	Int32 *(*GetPolygonMap)(const BaseObject *sds, const BaseObject *op); // #LEGACYCOMPATIBILITY: remove
	Int32 (*GetDivision)(const BaseObject *sds, const BaseObject *op);
	PolygonObject *(*GetSDSMesh)(const BaseObject *sds, const BaseObject *op);
	Bool (*TransformPoint)(const BaseObject *sds, const BaseObject *op, Int32 ply, Float &s, Float &t, Vector *p); // #LEGACYCOMPATIBILITY: remove
	Bool (*GetNormal)(const BaseObject *sds, const BaseObject *op, Int32 ply, Vector *p, Vector *n);
	Float32 *(*GetPointWeights)(BaseTag *pTag);
	const Float32 *(*GetPointWeightsC)(const BaseTag *pTag);
	PolyWeight *(*GetEdgeWeights)(BaseTag *pTag);
	const PolyWeight *(*GetEdgeWeightsC)(const BaseTag *pTag);
	const SDSSubdivisionMask* (*GetSubdivisionMask)(const BaseObject *sds, const BaseObject *op, Int32 &maskcnt, const Int32 *&polymap, Bool &ngonsubdiv);
	const void *(*GetCreationData)(const BaseObject *sds, const BaseObject *op);
	Int32 (*GetPointCount)(const BaseTag *pTag);
	Int32 (*GetPolygonCount)(const BaseTag *pTag);
	Bool (*GetSubdivisionMappings)(const BaseObject *sds, const BaseObject *op, SDSSubdivisionMappings& mappings);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

} // namespace cinema

#endif // LIB_SDS_H__
