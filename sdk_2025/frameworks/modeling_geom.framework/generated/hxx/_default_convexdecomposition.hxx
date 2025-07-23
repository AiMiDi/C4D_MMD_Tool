// This file contains default implementations for the interfaces of convexdecomposition.h. They are intended for copy&paste usage only.

class MyConvexDecompositionImpl : public maxon::Component<MyConvexDecompositionImpl, ConvexDecompositionInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(Float levelOfDetail, UInt32 maxVoxelCount)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Init(const DataDictionary& settings)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<DataDictionary> GetSettings() const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Bool IsReady() const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Result<UInt16> GetProgress() const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Compute(const GeometryObject& geometryObject)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<Array<GeometryObject>> FetchResults()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Cancel()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Clear()
	{
		return HXXRET1(NULLIMPL);
	}

};
