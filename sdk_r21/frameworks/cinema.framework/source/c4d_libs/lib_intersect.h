/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_INTERSECT_H__
#define LIB_INTERSECT_H__

#include <stdarg.h>

#include "c4d_library.h"

/// @addtogroup group_intersectlibrary Intersect
/// @ingroup group_library
/// @{

/// Intersect library ID.
#define LIBRARY_INTERSECT	1029406


/// @addtogroup INTERSECTTYPE
/// @ingroup group_enumeration
/// @{
enum class INTERSECTTYPE
{
	BVH			///< BVH.
} MAXON_ENUM_LIST(INTERSECTTYPE);
/// @}

//----------------------------------------------------------------------------------------
/// Intersection hit data structure for:
/// - Bool IIntersect::Hit(BaseDraw* bd, Float mx, Float my, Bool backfaces, IntersectHitData &hitData)
/// - Bool IIntersect::Hit(const Vector &rayp, const Vector &rayv, Bool backfaces, IntersectHitData &hitData)
//----------------------------------------------------------------------------------------
struct IntersectHitData
{
	Vector localHitPoint;					///< The location of the hit point on the surface of the object in the object's local coordinate system.
	Vector32 localHitNormal;			///< The normal of the hit point on the surface of the object in the object's local coordinate system.
	Int32 selectedPolygon;				///< The polygon that was hit.
	Float distance;								///< The distance from the ray starting position in object space.
	Bool backface;								///< @trueIfOtherwiseFalse{the hit polygon is a backfacing polygon}
	PolygonObject *pObject;				///< The polygon object that was hit.
};


//----------------------------------------------------------------------------------------
/// Intersect interface.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class IIntersect
{
private:
	IIntersect();
	~IIntersect();

public:

	/// @name Alloc/Free
	/// @{

	//----------------------------------------------------------------------------------------
	/// @allocatesAN{intersect interface}
	/// @param[in] type								The intersect type: @enumerateEnum{INTERSECTTYPE}
	/// @return												@allocReturn{intersect interface}
	//----------------------------------------------------------------------------------------
	static IIntersect *Alloc(INTERSECTTYPE type);

	//----------------------------------------------------------------------------------------
	/// @destructsAlloc{intersect interfaces}
	/// @param[in,out] isect					@theToDestruct{intersect interface}
	//----------------------------------------------------------------------------------------
	static void Free(IIntersect*& isect);

	/// @}

	/// @name Miscellaneous
	/// @{

	//----------------------------------------------------------------------------------------
	/// Adds the PolygonObject @formatParam{pObject} to the data structure for intersection testing against the triangles.
	/// @note Internally this calls Clear() before.
	/// @param[in] pObject						The polygon object to set. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{successful} (Due to not enough memory.)
	//----------------------------------------------------------------------------------------
	Bool Init(PolygonObject *pObject);

	//----------------------------------------------------------------------------------------
	/// Adds another polygon object object.
	/// @param[in] pObject						The polygon object to set. @callerOwnsPointed{object}
	/// @return												@trueIfOtherwiseFalse{successful} (Due to not enough memory.)
	//----------------------------------------------------------------------------------------
	Bool AddObject(PolygonObject *pObject);

	//----------------------------------------------------------------------------------------
	/// Clears all the data.
	//----------------------------------------------------------------------------------------
	void Clear();

	/// @}

	/// @name Hit
	/// @{

	//----------------------------------------------------------------------------------------
	/// From a viewport cast a ray, in screen space, onto the object(s) and return any data if there was a hit.\n
	/// Returns the closest hit point if multiple intersections are found.
	/// @param[in] bd									The view that the user is casting the ray from. @callerOwnsPointed{view}
	/// @param[in] mx									The X coordinate (mouse coordinate) in screen space.
	/// @param[in] my									The Y coordinate (mouse coordinate) in screen space.
	/// @param[in] backfaces					@formatConstant{true} to allow back facing polygons to be hit tested.\n
	/// 															If enabled and the back facing hit point is closer than the front hit point, then it is returned.
	/// @param[out] hitData						Filled with the intersection data if there was a hit.
	/// @return												@trueIfOtherwiseFalse{there was a hit}
	//----------------------------------------------------------------------------------------
	Bool Hit(BaseDraw* bd, Float mx, Float my, Bool backfaces, IntersectHitData &hitData);

	//----------------------------------------------------------------------------------------
	/// Given a ray in object space do a hit intersection against the object(s) and return any data if there was a hit.\n
	/// Return the closest hit point if multiple intersections are found.
	/// @param[in] rayp								The starting position of the ray in object space.
	/// @param[in] rayv								The direction the ray is pointing.
	/// @param[in] backfaces					@formatConstant{true} to allow back facing polygons to be hit tested.\n
	/// 															If enabled and the back facing hit point is closer than the front hit point, then it is returned.
	/// @param[out] hitData						Filled with the intersection data if there was a hit.
	/// @return												@trueIfOtherwiseFalse{there was a hit}
	//----------------------------------------------------------------------------------------
	Bool Hit(const Vector &rayp, const Vector &rayv, Bool backfaces, IntersectHitData &hitData);

	/// @}
};

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct IntersectLibrary : public C4DLibrary
{
	IIntersect*		(*intersectAlloc)(INTERSECTTYPE type);
	void					(*intersectFree)(IIntersect *&isect);
	Bool					(*intersectInit)(IIntersect *isect, PolygonObject *pPoly);
	Bool					(*intersectAddObject)(IIntersect *isect, PolygonObject *pPoly);
	void					(*intersectClear)(IIntersect *isect);
	Bool					(*intersectHitScreen)(IIntersect *isect, BaseDraw* bd, Float mx, Float my, Bool backfaces, IntersectHitData &hitData);
	Bool					(*intersectHitObject)(IIntersect *isect, const Vector &rayp, const Vector &rayv, Bool backfaces, IntersectHitData &hitData);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_INTERSECT_H__
