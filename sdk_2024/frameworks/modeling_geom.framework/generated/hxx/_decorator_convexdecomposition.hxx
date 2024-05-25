// This file contains decorator implementations for the interfaces of convexdecomposition.h. They are intended for copy&paste usage only.

class ConvexDecompositionDecoratorImpl : public maxon::Component<ConvexDecompositionDecoratorImpl, ConvexDecompositionInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(Float levelOfDetail, UInt32 maxVoxelCount)
	{
		return maxon::Cast<ConvexDecompositionRef>(self.GetDecoratedObject()).Init(levelOfDetail, maxVoxelCount);
	}

	MAXON_METHOD Result<void> Init(const DataDictionary& settings)
	{
		return maxon::Cast<ConvexDecompositionRef>(self.GetDecoratedObject()).Init(settings);
	}

	MAXON_METHOD Result<DataDictionary> GetSettings() const
	{
		return maxon::Cast<ConvexDecompositionRef>(self.GetDecoratedObject()).GetSettings();
	}

	MAXON_METHOD Bool IsReady() const
	{
		return maxon::Cast<ConvexDecompositionRef>(self.GetDecoratedObject()).IsReady();
	}

	MAXON_METHOD Result<UInt16> GetProgress() const
	{
		return maxon::Cast<ConvexDecompositionRef>(self.GetDecoratedObject()).GetProgress();
	}

	MAXON_METHOD Result<void> Compute(const GeometryObject& geometryObject)
	{
		return maxon::Cast<ConvexDecompositionRef>(self.GetDecoratedObject()).Compute(geometryObject);
	}

	MAXON_METHOD Result<Array<GeometryObject>> FetchResults()
	{
		return maxon::Cast<ConvexDecompositionRef>(self.GetDecoratedObject()).FetchResults();
	}

	MAXON_METHOD Result<void> Cancel()
	{
		return maxon::Cast<ConvexDecompositionRef>(self.GetDecoratedObject()).Cancel();
	}

	MAXON_METHOD Result<void> Clear()
	{
		return maxon::Cast<ConvexDecompositionRef>(self.GetDecoratedObject()).Clear();
	}

};
