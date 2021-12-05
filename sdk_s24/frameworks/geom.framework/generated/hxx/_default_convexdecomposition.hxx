// This file contains default implementations for the interfaces of convexdecomposition.h. They are intended for copy&paste usage only.

class MyConvexDecompositionImpl : public maxon::Component<MyConvexDecompositionImpl, ConvexDecompositionInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(Float levelOfDetail, UInt32 maxVoxelCount)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<DataDictionary> GetSettings() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Bool IsReady() const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Result<UInt16> GetProgress() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Compute(const GeometryObject& geometryObject)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<Array<GeometryObject>> FetchResults()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Cancel()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Clear()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
