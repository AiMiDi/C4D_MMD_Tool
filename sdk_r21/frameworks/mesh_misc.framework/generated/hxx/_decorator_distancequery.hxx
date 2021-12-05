// This file contains decorator implementations for the interfaces of distancequery.h. They are intended for copy&paste usage only.

class DistanceQueryDecoratorImpl : public maxon::Component<DistanceQueryDecoratorImpl, DistanceQueryInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(PolygonObject* mesh, Bool initVoxelization)
	{
		return maxon::Cast<DistanceQueryRef>(self.GetDecoratedObject()).Init(mesh, initVoxelization);
	}

	MAXON_METHOD Result<void> Init(SplineObject* spline)
	{
		return maxon::Cast<DistanceQueryRef>(self.GetDecoratedObject()).Init(spline);
	}

	MAXON_METHOD Result<void> Init(LineObject* line)
	{
		return maxon::Cast<DistanceQueryRef>(self.GetDecoratedObject()).Init(line);
	}

	MAXON_METHOD void Reset()
	{
		return maxon::Cast<DistanceQueryRef>(self.GetDecoratedObject()).Reset();
	}

	MAXON_METHOD Float GetClosestMeshPrimitive(const Vector& pos, PrimitiveInformation& primInfo, const BaseBitSet<>* polyFilter) const
	{
		return maxon::Cast<DistanceQueryRef>(self.GetDecoratedObject()).GetClosestMeshPrimitive(pos, primInfo, polyFilter);
	}

	MAXON_METHOD void GetDistanceToMesh(const Vector& pos, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const
	{
		return maxon::Cast<DistanceQueryRef>(self.GetDecoratedObject()).GetDistanceToMesh(pos, distInfo, polyFilter, onlyPolyPrimitives);
	}

	MAXON_METHOD void GetDistanceToMeshMaxAngleToDirection(const Vector& pos, const Vector& direction, const Float angle, MeshDistanceData& distInfo, const BaseBitSet<>* polyFilter, Bool onlyPolyPrimitives) const
	{
		return maxon::Cast<DistanceQueryRef>(self.GetDecoratedObject()).GetDistanceToMeshMaxAngleToDirection(pos, direction, angle, distInfo, polyFilter, onlyPolyPrimitives);
	}

	MAXON_METHOD void GetDistanceToSpline(const Vector& pos, SplineDistanceData& distInfo) const
	{
		return maxon::Cast<DistanceQueryRef>(self.GetDecoratedObject()).GetDistanceToSpline(pos, distInfo);
	}

	MAXON_METHOD Bool IsInitialized() const
	{
		return maxon::Cast<DistanceQueryRef>(self.GetDecoratedObject()).IsInitialized();
	}

	MAXON_METHOD void SetThreading(Int32 threads)
	{
		return maxon::Cast<DistanceQueryRef>(self.GetDecoratedObject()).SetThreading(threads);
	}

};
