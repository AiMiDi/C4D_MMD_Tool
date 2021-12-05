/////////////////////////////////////////////////////////////
// Cinema 4D SDK                                           //
/////////////////////////////////////////////////////////////
// (c) MAXON Computer GmbH, all rights reserved            //
/////////////////////////////////////////////////////////////

#ifndef LIB_COLLIDER_H__
#define LIB_COLLIDER_H__

#include "c4d_library.h"

#include "ge_math.h"

/// @addtogroup group_colliderlibrary Collider
/// @ingroup group_library
/// @{

/// @addtogroup COL
/// @ingroup group_enumeration
/// @{
#define COL_OK													 0			///< OK.
#define COL_ERR_OUT_OF_MEMORY						-1			///< Out of memory.
#define COL_ERR_UNPROCESSED_MODEL				-2			///< Unprocessed model.
#define COL_ERR_WRONG_BUILD_ORDER				-3			///< Wrong build order.
#define COL_ERR_EMPTY_OBJECT						-4			///< Empty object.
/// @}

/// @addtogroup COL_CONTACT
/// @ingroup group_enumeration
/// @{
#define COL_ALL_CONTACTS		1			///< All contacts.
#define COL_FIRST_CONTACT		2			///< First contact only.
/// @}

#ifndef _INTERNAL_DEF_COLLIDER_

//----------------------------------------------------------------------------------------
/// Collision cache : stores a set of triangles, each with an ID, for use with the other collision classes.
/// @addAllocFreeAutoAllocNote
///
/// The following function fills a GeColliderCache from a BaseObject:
/// @code
/// Bool FillColliderCache(GeColliderCache& c, BaseObject& obj)
/// {
/// 	// Get polygon object
/// 	ModelingCommandData md1; md1.op = &obj; md1.doc = obj.GetDocument();
/// 	if (!SendModelingCommand(MCOMMAND_CURRENTSTATETOOBJECT, md1))
/// 		return false;
///
/// 	// Triangulate it
/// 	ModelingCommandData md2; md2.op = static_cast<BaseObject*>(md1.result->GetIndex(0));
/// 	if (!SendModelingCommand(MCOMMAND_TRIANGULATE, md2))
/// 		return false;
/// 	AutoAlloc<PolygonObject> poly(static_cast<PolygonObject*>(md2.op));
/// 	if (!poly)
/// 		return false;
///
/// 	// Get the polygon data
/// 	CPolygon* tris = poly->GetPolygon();
/// 	Vector* points = poly->GetPoint();
///
/// 	// Fill the cache
///
/// 	if (c.BeginInput(poly->GetPolygonCount()) != COL_OK)
/// 		return false;
///
/// 	for (int i = 0; i < poly->GetPolygonCount(); ++i)
/// 	{
/// 		if (c.AddTriangle(points[tris[i].a], points[tris[i].b], points[tris[i].c], i) != COL_OK)
/// 			return false;
/// 	}
///
/// 	if (c.EndInput() != COL_OK)
/// 		return false;
///
/// 	return true;
/// }
/// @endcode
//----------------------------------------------------------------------------------------
class GeColliderCache
{
	private:
		GeColliderCache();
		~GeColliderCache();

	public:
		//----------------------------------------------------------------------------------------
		/// @allocatesA{collider cache}
		/// @return												@allocReturn{collider cache}
		//----------------------------------------------------------------------------------------
		static GeColliderCache* Alloc();

		//----------------------------------------------------------------------------------------
		/// @destructsAlloc{collider caches}
		/// @param[in,out] data						@theToDestruct{collider cache}
		//----------------------------------------------------------------------------------------
		static void Free(GeColliderCache *&data);

		//----------------------------------------------------------------------------------------
		/// Copies all triangles to another cache.
		/// @param[in,out] dest						The destination cache. @callerOwnsPointed{collider cache}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool CopyTo(GeColliderCache *dest);

		//----------------------------------------------------------------------------------------
		/// Call this function before storing triangles into the cache. Removes any previous data and allocates space for @formatParam{cnt_tris} number of triangles.
		/// @param[in] cnt_tris						The number of triangles to store.
		/// @return												The result: @enumerateEnum{COL}
		//----------------------------------------------------------------------------------------
		Int32 BeginInput(Int32 cnt_tris);

		//----------------------------------------------------------------------------------------
		/// Adds a triangle to the cache with the specified corners and @formatParam{id}.
		/// @param[in] p1									The first point.
		/// @param[in] p2									The second point.
		/// @param[in] p3									The third point.
		/// @param[in] id									The triangle ID.
		/// @return												The result: @enumerateEnum{COL}
		//----------------------------------------------------------------------------------------
		Int32 AddTriangle(const Vector& p1, const Vector& p2, const Vector& p3, Int32 id);

		//----------------------------------------------------------------------------------------
		/// Call this function after storing triangles into the cache.
		/// @return												The result: @enumerateEnum{COL}
		//----------------------------------------------------------------------------------------
		Int32 EndInput();
};

//----------------------------------------------------------------------------------------
/// Collision engine : contains algorithms for collision detection.
/// @addAllocFreeAutoAllocNote
///
/// @code
/// BaseDocument* doc = GetActiveDocument(); if (!doc) return;
///
/// // Get the first object
/// AutoAlloc<GeColliderCache> o1;
/// if (!o1)
/// 	return;
/// BaseObject* obj1 = doc->GetFirstObject();
/// if (!obj1)
/// 	return;
/// FillColliderCache(*o1, *obj1);
///
/// // Use the next object as second object
/// AutoAlloc<GeColliderCache> o2;
/// if (!o2)
/// 	return;
/// BaseObject* obj2 = obj1->GetNext();
/// if (!obj2)
/// 	return;
/// FillColliderCache(*o2, *obj2);
///
/// // Create the engine
/// AutoAlloc<GeColliderEngine> e;
/// if (!e)
/// 	return;
///
/// // Check for collisions
/// GePrint("DoCollide():");
/// e->DoCollide(obj1->GetMg(), o1, obj2->GetMg(), o2, COL_ALL_CONTACTS);
/// GePrint(" " + String::IntToString(e->GetNumPairs()) + " pairs;");
/// for (int k = 0; k < e->GetNumPairs(); ++k)
/// {
/// 	GePrint("  " + String::IntToString(e->GetId1(k)) + " - " + String::IntToString(e->GetId2(k)));
/// }
/// @endcode
//----------------------------------------------------------------------------------------
class GeColliderEngine
{
	private:
		GeColliderEngine();
		~GeColliderEngine();

	public:
		//----------------------------------------------------------------------------------------
		/// @allocatesA{collider engine}
		/// @return												@allocReturn{collider engine}
		//----------------------------------------------------------------------------------------
		static GeColliderEngine* Alloc();

		//----------------------------------------------------------------------------------------
		/// @destructsAlloc{collider engines}
		/// @param[in,out] data						@theToDestruct{collider engine}
		//----------------------------------------------------------------------------------------
		static void Free(GeColliderEngine *&data);

		//----------------------------------------------------------------------------------------
		/// Checks for intersecting triangles in @formatParam{o1} and @formatParam{o2}.\n
		/// If the function succeeds retrieve a list of colliding triangle pairs with GetNumPairs(), GetId1() and GetId2().
		/// @note The matrices must be orthonormal!
		/// @param[in] M1									The world matrix of first object.
		/// @param[in] o1									The cache for first object.
		/// @param[in] M2									The world matrix of second object.
		/// @param[in] o2									The cache for second object.
		/// @param[in] flag								The method: @enumerateEnum{COL_CONTACT}
		/// @return												The result: @enumerateEnum{COL}
		//----------------------------------------------------------------------------------------
		Int32 DoCollide(const Matrix& M1, GeColliderCache *o1, const Matrix& M2, GeColliderCache *o2, Int32 flag);

		//----------------------------------------------------------------------------------------
		/// Checks for triangles in @formatParam{o1} and @formatParam{o2} that are closer than @formatParam{tolerance} to each other.\n
		/// If the function succeeds retrieve a list of colliding triangle pairs with GetNumPairs(), GetId1() and GetId2().
		/// @note The matrices must be orthonormal!
		/// @param[in] M1									The world matrix of first object.
		/// @param[in] o1									The cache for first object.
		/// @param[in] M2									The world matrix of second object.
		/// @param[in] o2									The cache for second object.
		/// @param[in] tolerance					The tolerance.
		/// @return												The result: @enumerateEnum{COL}
		//----------------------------------------------------------------------------------------
		Int32 DoPolyPairs(const Matrix& M1, GeColliderCache *o1, const Matrix& M2, GeColliderCache *o2, Float tolerance);

		//----------------------------------------------------------------------------------------
		/// Checks if @formatParam{o1} and @formatParam{o2} are closer to each other than @formatParam{tolerance}.\n
		/// If the function succeeds check the result with IsCloser(): if it returns @formatConstant{true}, the proof is in GetDistance(), GetP1() and GetP2().
		/// @note The matrices must be orthonormal!
		/// @param[in] M1									The world matrix of first object.
		/// @param[in] o1									The cache for first object.
		/// @param[in] M2									The world matrix of second object.
		/// @param[in] o2									The cache for second object.
		/// @param[in] tolerance					The tolerance.
		/// @return												The result: @enumerateEnum{COL}
		//----------------------------------------------------------------------------------------
		Int32 DoTolerance(const Matrix& M1, GeColliderCache *o1, const Matrix& M2, GeColliderCache *o2, Float tolerance);

		//----------------------------------------------------------------------------------------
		/// Calculates the minimum distance between @formatParam{o1} and @formatParam{o2} with the accuracy specified by @formatParam{rel_err} and @formatParam{abs_err}.\n
		/// If the function succeeds check the result with GetDistance(). The two closest points can be retrieved with GetP1() and GetP2().
		/// @note The matrices must be orthonormal!
		/// @param[in] M1									The world matrix of first object.
		/// @param[in] o1									The cache for first object.
		/// @param[in] M2									The world matrix of second object.
		/// @param[in] o2									The cache for second object.
		/// @param[in] rel_err						The maximum relative error.
		/// @param[in] abs_err						The maximum absolute error.
		/// @return												The result: @enumerateEnum{COL}
		//----------------------------------------------------------------------------------------
		Int32 DoDistance(const Matrix& M1, GeColliderCache *o1, const Matrix& M2, GeColliderCache *o2, Float rel_err, Float abs_err);

		//----------------------------------------------------------------------------------------
		/// Frees the pairs list.
		//----------------------------------------------------------------------------------------
		void FreePairsList();

		//----------------------------------------------------------------------------------------
		/// Retrieves the number of pairs found by DoCollide() or DoPolyPairs().
		/// @return												The number of pairs.
		//----------------------------------------------------------------------------------------
		Int32 GetNumPairs();

		//----------------------------------------------------------------------------------------
		/// Retrieves the ID of the first triangle in the pair at @formatParam{k} found by DoCollide() or DoPolyPairs().
		/// @param[in] k									The pair index: @em 0 <= @formatParam{k} < GetNumPairs()
		/// @return												The first triangle ID in pair.
		//----------------------------------------------------------------------------------------
		Int32 GetId1(Int32 k);

		//----------------------------------------------------------------------------------------
		/// Retrieves the ID of the second triangle in the pair at @formatParam{k} found by DoCollide() or DoPolyPairs().
		/// @param[in] k									The pair index: @em 0 <= @formatParam{k} < GetNumPairs()
		/// @return												The second triangle ID in pair.
		//----------------------------------------------------------------------------------------
		Int32 GetId2(Int32 k);

		//----------------------------------------------------------------------------------------
		/// Checks the result of the tolerance check done with DoTolerance().
		/// @return												@trueIfOtherwiseFalse{the objects are closer than the tolerance}
		//----------------------------------------------------------------------------------------
		Bool IsCloser();

		//----------------------------------------------------------------------------------------
		/// Retrieves the result of the distance calculation done with DoDistance() or DoTolerance().
		/// @return												The calculated distance.
		//----------------------------------------------------------------------------------------
		Float GetDistance();

		//----------------------------------------------------------------------------------------
		/// Retrieves the closest point found on the first object during the distance calculation done with DoDistance() or DoTolerance().
		/// @return												The closest point on the first object, in object coordinates.
		//----------------------------------------------------------------------------------------
		const Vector& GetP1();

		//----------------------------------------------------------------------------------------
		/// Retrieves the closest point found on the second object during the distance calculation done with DoDistance() or DoTolerance().
		/// @return												The closest point on the second object, in object coordinates.
		//----------------------------------------------------------------------------------------
		const Vector& GetP2();

		//----------------------------------------------------------------------------------------
		/// Checks if the line segment specified by @formatParam{ray_p} to @formatParam{ray_p} + @formatParam{ray_dir}*@formatParam{ray_length} intersects the object.\n
		/// If the function succeeds retrieve the list of intersections with GetNumPairs(), GetId1() and GetId2().
		/// @param[in] o1									The cache for the object.
		/// @param[in] ray_p							The start point of the ray in object coordinates
		/// @param[in] ray_dir						The ray direction in object coordinates.
		/// @param[in] ray_length					The ray length.
		/// @return												The result: @enumerateEnum{COL}
		//----------------------------------------------------------------------------------------
		Int32 DoRayCollide(GeColliderCache *o1, const Vector &ray_p, const Vector &ray_dir, Float ray_length);
};

//----------------------------------------------------------------------------------------
/// Stores the result of calculations with GeRayCollider.
//----------------------------------------------------------------------------------------
struct GeRayColResult
{
		Int32		face_id;					///< The polygon index of the intersection point.
		Int32		tri_face_id;			///< If first half of quad or triangle @ref face_id + @em 1, else -(@ref face_id + @em 1).

		Vector	hitpos;						///< The position of the intersection.
		Float		distance;					///< The distance to the intersection.
		Vector	s_normal;					///< Same as f_normal. (reserved for phong normal at the intersection (Not normalized))
		Vector	f_normal;					///< The face normal. (Not normalized)
		Vector	barrycoords;			///< The barycentric coordinates of the intersection. (x = u, y = v, z = d)
		Bool		backface;					///< @trueIfOtherwiseFalse{the intersected face's normal points away from the camera}
};

//----------------------------------------------------------------------------------------
/// Ray collider engine : evaluates intersections between a ray and a single polygon object.
/// The polygons are split into two triangles each when calculating the intersections, thus affecting the intersection count when the invisible shared edges are hit.
/// The original polygon object remains unmodified.
/// @addAllocFreeAutoAllocNote
//----------------------------------------------------------------------------------------
class GeRayCollider
{
	private:
		GeRayCollider();
		~GeRayCollider();

	public:
		//----------------------------------------------------------------------------------------
		/// @allocatesA{ray collider engine}
		/// @return												@allocReturn{ray collider engine}
		//----------------------------------------------------------------------------------------
		static GeRayCollider* Alloc();

		//----------------------------------------------------------------------------------------
		/// @destructsAlloc{ray collider engines}
		/// @param[in,out] data						@theToDestruct{ray collider engine}
		//----------------------------------------------------------------------------------------
		static void Free(GeRayCollider *&data);

		//----------------------------------------------------------------------------------------
		/// Initializes the ray collider with the object specified by @formatParam{goal}.
		/// @param[in] goal								The object to check for intersections. The pointed object is copied.
		/// @param[in] force							If @formatConstant{false} then @C4D checks if the passed object's @c GetDirty(DIRTYFLAGS::DATA) is unchanged. If yes, it does nothing and returns @formatConstant{true}.\n
		/// 															If @formatConstant{true} it always rebuilds the cache.
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool Init(BaseObject *goal, Bool force = false);

		//----------------------------------------------------------------------------------------
		/// Checks if the line segment specified by @formatParam{ray_p} to @formatParam{ray_p} + @formatParam{ray_dir}*@formatParam{ray_length} intersects the object.\n
		/// If @formatParam{only_test} is @formatConstant{false} the intersections can be evaluated with GetIntersectionCount() and GetIntersection().
		/// @param[in] ray_p							The start point of the ray in object coordinates.
		/// @param[in] ray_dir						The ray direction in object coordinates.
		/// @param[in] ray_length					The ray length.
		/// @param[in] only_test					If @formatConstant{true} no information about the intersections are stored, so only the return value can be used to tell if there were intersections or not.
		/// @return												@trueIfOtherwiseFalse{there was an intersection}
		//----------------------------------------------------------------------------------------
		Bool Intersect(const Vector &ray_p, const Vector &ray_dir, Float ray_length, Bool only_test = false);

		//----------------------------------------------------------------------------------------
		/// Retrieves the number of intersections found by Intersect(), which is in terms of the amount of triangles hit by the ray.
		/// Intersecting a shared edge will result in a value greater than one.
		/// Intersecting a shared edge point will result in a value that varies depending on how the polygon object is split up into triangles.
		/// @return												The number of intersections.
		//----------------------------------------------------------------------------------------
		Int32 GetIntersectionCount();

		//----------------------------------------------------------------------------------------
		/// Retrieves intersections, found with Intersect(), by index.
		/// @param[in] number							The intersection index: @em 0 <= @formatParam{number} < GetIntersectionCount()
		/// @param[out] res								Assigned the intersection information. @callerOwnsPointed{GeRayColResult}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool GetIntersection(Int32 number, GeRayColResult *res);

		//----------------------------------------------------------------------------------------
		/// Retrieves the intersection, found with Intersect(), closest to the start of the ray.
		/// @param[in] res								Assigned the intersection information. @callerOwnsPointed{GeRayColResult}
		/// @return												@trueIfOtherwiseFalse{successful}
		//----------------------------------------------------------------------------------------
		Bool GetNearestIntersection(GeRayColResult *res);
};

#else

#define GeColliderCache GeColliderCacheI
#define GeColliderEngine GeColliderEngineI
#define GeRayCollider GeRayColliderI

#endif

/// Collider cache library ID.
#define LIB_COLLIDERCACHE 1000487

/// Collider engine library ID.
#define LIB_COLLIDERENGINE 1000488

/// Ray collider engine library ID.
#define LIB_RAYCOLLIDER 1000499

/// @}

/// @cond IGNORE

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

struct ColliderCacheLib : public C4DLibrary
{
		GeColliderCache*		(*Alloc														)();
		void								(*Free														)(GeColliderCache *&data);
		Bool								(GeColliderCache::*CopyTo					)(GeColliderCache *dest);
		Int32								(GeColliderCache::*BeginInput			)(Int32 cnt_tris);
		Int32								(GeColliderCache::*AddTriangle		)(const Vector& p1, const Vector& p2, const Vector& p3, Int32 id);
		Int32								(GeColliderCache::*EndInput				)();
};

struct ColliderEngineLib : public C4DLibrary
{
		GeColliderEngine*		(*Alloc														)();
		void								(*Free														)(GeColliderEngine *&data);

		Int32								(GeColliderEngine::*DoCollide			)(const Matrix& M1, GeColliderCache *o1, const Matrix& M2, GeColliderCache *o2, Int32 flag);
		Int32								(GeColliderEngine::*DoPolyPairs		)(const Matrix& M1, GeColliderCache *o1, const Matrix& M2, GeColliderCache *o2, Float tolerance);
		Int32								(GeColliderEngine::*DoTolerance		)(const Matrix& M1, GeColliderCache *o1, const Matrix& M2, GeColliderCache *o2, Float tolerance);
		Int32								(GeColliderEngine::*DoDistance		)(const Matrix& M1, GeColliderCache *o1, const Matrix& M2, GeColliderCache *o2, Float rel_err, Float abs_err);
		void								(GeColliderEngine::*FreePairsList	)();
		Int32								(GeColliderEngine::*GetNumPairs		)();
		Int32								(GeColliderEngine::*GetId1				)(Int32 k);
		Int32								(GeColliderEngine::*GetId2				)(Int32 k);
		Bool								(GeColliderEngine::*IsCloser			)();
		Float								(GeColliderEngine::*GetDistance		)();
		const Vector&				(GeColliderEngine::*GetP1					)();
		const Vector&				(GeColliderEngine::*GetP2					)();
		Int32								(GeColliderEngine::*DoRayCollide	)(GeColliderCache *o1, const Vector &ray_p, const Vector &ray_dir, Float ray_lengt);
};

struct RayColliderLib : public C4DLibrary
{
		GeRayCollider*	(*Alloc																	)();
		void						(*Free																	)(GeRayCollider *&data);

		Bool						(GeRayCollider::*Init										)(BaseObject *goal, Bool force);
		Bool						(GeRayCollider::*Intersect							)(const Vector &ray_p, const Vector &ray_dir, Float ray_length, Bool only_test);
		Int32						(GeRayCollider::*GetIntersectionCount		)();
		Bool						(GeRayCollider::*GetIntersection				)(Int32 number, GeRayColResult *res);
		Bool						(GeRayCollider::*GetNearestIntersection	)(GeRayColResult *res);
};

// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF
// INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF -- INTERNAL STUFF

/// @endcond

#endif // LIB_COLLIDER_H__
