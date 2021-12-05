// This file contains default implementations for the interfaces of distancequery.h. They are intended for copy&paste usage only.

class MyDistanceQueryImpl : public maxon::Component<MyDistanceQueryImpl, DistanceQueryInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(PolygonObject* mesh, Bool initVoxelization)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Init(SplineObject* spline)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Init(LineObject* line)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD void Reset()
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Float GetClosestMeshPrimitive(const Vector& pos, PrimitiveInformation& primInfo, const BaseBitSet<>* polyFilter) const
	{
		return 0;
	}

	MAXON_METHOD void GetDistanceToMesh(const Vector& pos, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void GetDistanceToMeshMaxAngleToDirection(const Vector& pos, const Vector& direction, const Float angle, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void GetDistanceToSpline(const Vector& pos, SplineDistanceData& distInfo) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Bool IsInitialized() const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD void SetThreading(Int32 threads)
	{
		return maxon::PrivateLogNullptrError();
	}

};
