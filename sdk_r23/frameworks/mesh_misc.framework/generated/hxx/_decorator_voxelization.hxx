// This file contains decorator implementations for the interfaces of voxelization.h. They are intended for copy&paste usage only.

class VoxelizationDecoratorImpl : public maxon::Component<VoxelizationDecoratorImpl, VoxelizationInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Bool> Init(PolygonObject* polyObject, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride, Bool precise)
	{
		return maxon::Cast<VoxelizationRef>(self.GetDecoratedObject()).Init(polyObject, voxelResolution, minResolution, polyRanges, pointOverride, precise);
	}

	MAXON_METHOD Result<Bool> Init(PolygonObject* polyObject, BaseArray<Int32>& polyIslands, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges, const Vector* pointOverride)
	{
		return maxon::Cast<VoxelizationRef>(self.GetDecoratedObject()).Init(polyObject, polyIslands, voxelResolution, minResolution, polyRanges, pointOverride);
	}

	MAXON_METHOD Result<Bool> Init(const ConvexHullData* hull, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges)
	{
		return maxon::Cast<VoxelizationRef>(self.GetDecoratedObject()).Init(hull, voxelResolution, minResolution, polyRanges);
	}

	MAXON_METHOD Result<Bool> Init(const BaseArray<BaseArray<Int32>>& facePoints, const BaseArray<Vector>& points, Int32 voxelResolution, Int32 minResolution, BaseArray<Range<Vector>>& polyRanges)
	{
		return maxon::Cast<VoxelizationRef>(self.GetDecoratedObject()).Init(facePoints, points, voxelResolution, minResolution, polyRanges);
	}

	MAXON_METHOD Result<void> GetClosestPolys(const Vector pos, BaseBitSet<>& voxelPolys, const BaseBitSet<>* polyFilter) const
	{
		return maxon::Cast<VoxelizationRef>(self.GetDecoratedObject()).GetClosestPolys(std::forward<const Vector>(pos), voxelPolys, polyFilter);
	}

	MAXON_METHOD Result<void> GetIntersectingIndices(const Range<Vector>& toTestBox, BaseArray<Int32>& indexList) const
	{
		return maxon::Cast<VoxelizationRef>(self.GetDecoratedObject()).GetIntersectingIndices(toTestBox, indexList);
	}

	MAXON_METHOD Result<void> GetIntersectingIndicesPrecise(const Range<Vector>& toTestBox, const BaseArray<Range<Vector>>& polyRanges, BaseArray<Int32>& indexList) const
	{
		return maxon::Cast<VoxelizationRef>(self.GetDecoratedObject()).GetIntersectingIndicesPrecise(toTestBox, polyRanges, indexList);
	}

	MAXON_METHOD Result<Bool> GetIntersectingIndices(const Vector& point, BaseArray<Int32>& indexList) const
	{
		return maxon::Cast<VoxelizationRef>(self.GetDecoratedObject()).GetIntersectingIndices(point, indexList);
	}

	MAXON_METHOD const Range<Vector>& GetBoundingBox() const
	{
		return maxon::Cast<VoxelizationRef>(self.GetDecoratedObject()).GetBoundingBox();
	}

	MAXON_METHOD Range<IntVector32> GetVoxelRangesFromBoundingBox(const Range<Vector>& boundingBox) const
	{
		return maxon::Cast<VoxelizationRef>(self.GetDecoratedObject()).GetVoxelRangesFromBoundingBox(boundingBox);
	}

	MAXON_METHOD Bool IsInitialized() const
	{
		return maxon::Cast<VoxelizationRef>(self.GetDecoratedObject()).IsInitialized();
	}

};
