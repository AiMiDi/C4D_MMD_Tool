#include "lib_collider.h"

static ColliderCacheLib *library_cache = nullptr;

static ColliderCacheLib *CheckLibCache(Int32 offset)
{
	return (ColliderCacheLib*)CheckLib(LIB_COLLIDERCACHE, offset, (C4DLibrary**)&library_cache);
}

GeColliderCache::GeColliderCache()
{
}

GeColliderCache* GeColliderCache::Alloc()
{
	ColliderCacheLib *lib = CheckLibCache(LIBOFFSET(ColliderCacheLib, Alloc)); if (!lib || !lib->Alloc) return nullptr;
	return lib->Alloc();
}

void GeColliderCache::Free(GeColliderCache *&data)
{
	ColliderCacheLib *lib = CheckLibCache(LIBOFFSET(ColliderCacheLib, Free)); if (!lib || !lib->Free) return;
	lib->Free(data);
}

Bool GeColliderCache::CopyTo(GeColliderCache *dest)
{
	ColliderCacheLib *lib = CheckLibCache(LIBOFFSET(ColliderCacheLib, CopyTo)); if (!lib || !lib->CopyTo) return false;
	return (this->*lib->CopyTo)(dest);
}

Int32 GeColliderCache::BeginInput(Int32 cnt_tris)
{
	ColliderCacheLib *lib = CheckLibCache(LIBOFFSET(ColliderCacheLib, BeginInput)); if (!lib || !lib->BeginInput) return false;
	return (this->*lib->BeginInput)(cnt_tris);
}

Int32 GeColliderCache::AddTriangle(const Vector& p1, const Vector& p2, const Vector& p3, Int32 id)
{
	ColliderCacheLib *lib = CheckLibCache(LIBOFFSET(ColliderCacheLib, AddTriangle)); if (!lib || !lib->AddTriangle) return false;
	return (this->*lib->AddTriangle)(p1, p2, p3, id);
}

Int32 GeColliderCache::EndInput()
{
	ColliderCacheLib *lib = CheckLibCache(LIBOFFSET(ColliderCacheLib, EndInput)); if (!lib || !lib->EndInput) return false;
	return (this->*lib->EndInput)();
}



//////////////////////////////////////////////////////


#undef LIB_COLLIDERCACHE_ID
#undef ColliderCacheLib

#define LIB_COLLIDERCACHE_ID			LIB_COLLIDERENGINE
#define ColliderCacheLib				ColliderEngineLib

static ColliderCacheLib *library_engine = nullptr;


static ColliderCacheLib *CheckLibEngine(Int32 offset)
{
	return (ColliderCacheLib*)CheckLib(LIB_COLLIDERCACHE_ID, offset, (C4DLibrary**)&library_engine);
}

GeColliderEngine::GeColliderEngine()
{
}

GeColliderEngine* GeColliderEngine::Alloc()
{
	ColliderCacheLib *lib = CheckLibEngine(LIBOFFSET(ColliderCacheLib, Alloc)); if (!lib || !lib->Alloc) return nullptr;
	return lib->Alloc();
}

void GeColliderEngine::Free(GeColliderEngine *&data)
{
	ColliderCacheLib *lib = CheckLibEngine(LIBOFFSET(ColliderCacheLib, Free)); if (!lib || !lib->Free) return;
	lib->Free(data);
}

Int32 GeColliderEngine::DoCollide(const Matrix& M1, GeColliderCache *o1, const Matrix& M2, GeColliderCache *o2, Int32 flag)
{
	ColliderCacheLib *lib = CheckLibEngine(LIBOFFSET(ColliderCacheLib, DoCollide)); if (!lib || !lib->DoCollide) return false;
	return (this->*lib->DoCollide)(M1, o1, M2, o2, flag);
}

Int32 GeColliderEngine::DoPolyPairs(const Matrix& M1, GeColliderCache *o1, const Matrix& M2, GeColliderCache *o2, Float tolerance)
{
	ColliderCacheLib *lib = CheckLibEngine(LIBOFFSET(ColliderCacheLib, DoPolyPairs)); if (!lib || !lib->DoPolyPairs) return false;
	return (this->*lib->DoPolyPairs)(M1, o1, M2, o2, tolerance);
}

Int32 GeColliderEngine::DoTolerance(const Matrix& M1, GeColliderCache *o1, const Matrix& M2, GeColliderCache *o2, Float tolerance)
{
	ColliderCacheLib *lib = CheckLibEngine(LIBOFFSET(ColliderCacheLib, DoTolerance)); if (!lib || !lib->DoTolerance) return false;
	return (this->*lib->DoTolerance)(M1, o1, M2, o2, tolerance);
}

Int32 GeColliderEngine::DoDistance(const Matrix& M1, GeColliderCache *o1, const Matrix& M2, GeColliderCache *o2, Float rel_err, Float abs_err)
{
	ColliderCacheLib *lib = CheckLibEngine(LIBOFFSET(ColliderCacheLib, DoDistance)); if (!lib || !lib->DoDistance) return false;
	return (this->*lib->DoDistance)(M1, o1, M2, o2, rel_err, abs_err);
}

Int32 GeColliderEngine::DoRayCollide(GeColliderCache *o1, const Vector &ray_p, const Vector &ray_dir, Float ray_length)
{
	ColliderCacheLib *lib = CheckLibEngine(LIBOFFSET(ColliderCacheLib, DoRayCollide)); if (!lib || !lib->DoRayCollide) return false;
	return (this->*lib->DoRayCollide)(o1, ray_p, ray_dir, ray_length);
}

void GeColliderEngine::FreePairsList()
{
	ColliderCacheLib *lib = CheckLibEngine(LIBOFFSET(ColliderCacheLib, FreePairsList)); if (!lib || !lib->FreePairsList) return;
	(this->*lib->FreePairsList)();
}

Int32 GeColliderEngine::GetNumPairs()
{
	ColliderCacheLib *lib = CheckLibEngine(LIBOFFSET(ColliderCacheLib, GetNumPairs)); if (!lib || !lib->GetNumPairs) return false;
	return (this->*lib->GetNumPairs)();
}

Int32 GeColliderEngine::GetId1(Int32 k)
{
	ColliderCacheLib *lib = CheckLibEngine(LIBOFFSET(ColliderCacheLib, GetId1)); if (!lib || !lib->GetId1) return false;
	return (this->*lib->GetId1)(k);
}

Int32 GeColliderEngine::GetId2(Int32 k)
{
	ColliderCacheLib *lib = CheckLibEngine(LIBOFFSET(ColliderCacheLib, GetId2)); if (!lib || !lib->GetId2) return false;
	return (this->*lib->GetId2)(k);
}

Bool GeColliderEngine::IsCloser()
{
	ColliderCacheLib *lib = CheckLibEngine(LIBOFFSET(ColliderCacheLib, IsCloser)); if (!lib || !lib->IsCloser) return false;
	return (this->*lib->IsCloser)();
}

Float GeColliderEngine::GetDistance()
{
	ColliderCacheLib *lib = CheckLibEngine(LIBOFFSET(ColliderCacheLib, GetDistance)); if (!lib || !lib->GetDistance) return false;
	return (this->*lib->GetDistance)();
}

static Vector colliderDummy;

const Vector& GeColliderEngine::GetP1()
{
	ColliderCacheLib *lib = CheckLibEngine(LIBOFFSET(ColliderCacheLib, GetP1)); if (!lib || !lib->GetP1) return colliderDummy;
	return (this->*lib->GetP1)();
}

const Vector& GeColliderEngine::GetP2()
{
	ColliderCacheLib *lib = CheckLibEngine(LIBOFFSET(ColliderCacheLib, GetP2)); if (!lib || !lib->GetP2) return colliderDummy;
	return (this->*lib->GetP2)();
}


//////////////////////////////////////////////////////


#undef LIB_COLLIDERCACHE_ID
#undef ColliderCacheLib

#define LIB_COLLIDERCACHE_ID			LIB_RAYCOLLIDER
#define ColliderCacheLib				RayColliderLib

static ColliderCacheLib *library_ray = nullptr;


static ColliderCacheLib *CheckLibRay(Int32 offset)
{
	return (ColliderCacheLib*)CheckLib(LIB_COLLIDERCACHE_ID, offset, (C4DLibrary**)&library_ray);
}

GeRayCollider::GeRayCollider()
{
}

GeRayCollider* GeRayCollider::Alloc()
{
	ColliderCacheLib *lib = CheckLibRay(LIBOFFSET(ColliderCacheLib, Alloc)); if (!lib || !lib->Alloc) return nullptr;
	return lib->Alloc();
}

void GeRayCollider::Free(GeRayCollider *&data)
{
	ColliderCacheLib *lib = CheckLibRay(LIBOFFSET(ColliderCacheLib, Free)); if (!lib || !lib->Free) return;
	lib->Free(data);
}
Bool GeRayCollider::Init(BaseObject *object, Bool force)
{
	ColliderCacheLib *lib = CheckLibRay(LIBOFFSET(ColliderCacheLib, Init)); if (!lib || !lib->Init) return false;
	return (this->*lib->Init)(object, force);
}

Bool GeRayCollider::Intersect(const Vector &ray_p, const Vector &ray_dir, Float ray_length, Bool only_test)
{
	ColliderCacheLib *lib = CheckLibRay(LIBOFFSET(ColliderCacheLib, Intersect)); if (!lib || !lib->Intersect) return false;
	return (this->*lib->Intersect)(ray_p, ray_dir, ray_length, only_test);
}

Int32 GeRayCollider::GetIntersectionCount()
{
	ColliderCacheLib *lib = CheckLibRay(LIBOFFSET(ColliderCacheLib, GetIntersectionCount)); if (!lib || !lib->GetIntersectionCount) return 0;
	return (this->*lib->GetIntersectionCount)();
}

Bool GeRayCollider::GetIntersection(Int32 n, GeRayColResult *result)
{
	ColliderCacheLib *lib = CheckLibRay(LIBOFFSET(ColliderCacheLib, GetIntersection)); if (!lib || !lib->GetIntersection) return false;
	return (this->*lib->GetIntersection)(n, result);
}

Bool GeRayCollider::GetNearestIntersection(GeRayColResult *result)
{
	ColliderCacheLib *lib = CheckLibRay(LIBOFFSET(ColliderCacheLib, GetNearestIntersection)); if (!lib || !lib->GetNearestIntersection) return false;
	return (this->*lib->GetNearestIntersection)(result);
}
