// This file contains default implementations for the interfaces of interpolation.h. They are intended for copy&paste usage only.

class MyInterpolateTypeImpl : public maxon::Component<MyInterpolateTypeImpl, InterpolateTypeInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const DataType& GetInterpolateDataType() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void InterpolateLinear(void* data1, const void* data2, Float blend) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void Average(void* data, const Block<const void*>& dataSet) const
	{
		return maxon::PrivateLogNullptrError();
	}

};
