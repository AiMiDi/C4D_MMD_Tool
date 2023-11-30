// This file contains default implementations for the interfaces of voxelization.h. They are intended for copy&paste usage only.

class MyVoxelizationImpl : public maxon::Component<MyVoxelizationImpl, VoxelizationInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Bool> Init(PolygonObject* polyObject, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride, Bool precise)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Bool> Init(PolygonObject* polyObject, BaseArray<Int32>& polyIslands, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Bool> Init(const ConvexHullData* hull, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Bool> Init(const BaseArray<BaseArray<Int32>>& facePoints, const BaseArray<Vector>& points, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> GetClosestPolys(const Vector pos, BaseBitSet<>& voxelPolys, const BaseBitSet<>* polyFilter) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> GetIntersectingIndices(const Range<Vector>& toTestBox, BaseArray<Int32>& indexList) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> GetIntersectingIndicesPrecise(const Range<Vector>& toTestBox, const BaseArray<Range<Vector>>& polyRanges, BaseArray<Int32>& indexList) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Bool> GetIntersectingIndices(const Vector& point, BaseArray<Int32>& indexList) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD const Range<Vector>& GetBoundingBox() const
	{
		return HXXRET3(NULLIMPL, const Range<Vector>&);
	}

	MAXON_METHOD Range<IntVector32> GetVoxelRangesFromBoundingBox(const Range<Vector>& boundingBox) const
	{
		return HXXRET3(NULLIMPL, Range<IntVector32>);
	}

	MAXON_METHOD Bool IsInitialized() const
	{
		return maxon::PrivateLogNullptrError(false);
	}

};
