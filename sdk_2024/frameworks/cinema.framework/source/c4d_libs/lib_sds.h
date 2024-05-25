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

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_BEGIN
#endif

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
	Int32 GetDivision(BaseObject *op);

	//----------------------------------------------------------------------------------------
	/// Retrieves the subdivided mesh of @formatParam{op}, if it has been generated. (A convenience function to get the cache.)
	/// @param[in] op									A child of the SDS object. @callerOwnsPointed{object}
	/// @return												The subdivided mesh. @cinemaOwnsPointed{polygon object}
	//----------------------------------------------------------------------------------------
	PolygonObject *GetSDSMesh(BaseObject *op);

	//----------------------------------------------------------------------------------------
	/// Dummy function. Always return @formatConstant{false}.
	//----------------------------------------------------------------------------------------
	Bool TransformPoint(BaseObject *op, Int32 ply, Float &s, Float &t, Vector *p);

	//----------------------------------------------------------------------------------------
	/// Gets the transformed normal of polygon @formatParam{ply} of @formatParam{op}.
	/// @param[in] op									A child of the SDS object. @callerOwnsPointed{object}
	/// @param[in] ply								A polygon index.
	/// @param[out] p									Assigned the origin of the normal (center of the polygon).
	/// @param[out] n									Assigned the normal.
	/// @return												@trueIfOtherwiseFalse{successful}
	//----------------------------------------------------------------------------------------
	Bool GetNormal(BaseObject *op, Int32 ply, Vector *p, Vector *n);

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
	SDSSubdivisionMask* GetSubdivisionMask(BaseObject *op, Int32 &maskcnt, Int32 *&polymap, Bool &ngonsubdiv);

	//----------------------------------------------------------------------------------------
	/// @markPrivate
	//----------------------------------------------------------------------------------------
	void *GetCreationData(BaseObject *op);
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
	Int32 *(*GetEdgeMap)(BaseObject *sds, BaseObject *op);
	Int32 *(*GetPolygonMap)(BaseObject *sds, BaseObject *op);
	Int32 (*GetDivision)(BaseObject *sds, BaseObject *op);
	PolygonObject *(*GetSDSMesh)(BaseObject *sds, BaseObject *op);
	Bool (*TransformPoint)(BaseObject *sds, BaseObject *op, Int32 ply, Float &s, Float &t, Vector *p);
	Bool (*GetNormal)(BaseObject *sds, BaseObject *op, Int32 ply, Vector *p, Vector *n);
	Float32 *(*GetPointWeights)(BaseTag *pTag);
	const Float32 *(*GetPointWeightsC)(const BaseTag *pTag);
	PolyWeight *(*GetEdgeWeights)(BaseTag *pTag);
	const PolyWeight *(*GetEdgeWeightsC)(const BaseTag *pTag);
	SDSSubdivisionMask* (*GetSubdivisionMask)(BaseObject *sds, BaseObject *op, Int32 &maskcnt, Int32 *&polymap, Bool &ngonsubdiv);
	void *(*GetCreationData)(BaseObject *sds, BaseObject *op);
	Int32 (*GetPointCount)(const BaseTag *pTag);
	Int32 (*GetPolygonCount)(const BaseTag *pTag);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
	CINEWARE_NAMESPACE_END
#endif

#endif // LIB_SDS_H__
