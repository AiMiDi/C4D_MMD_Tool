// This file contains decorator implementations for the interfaces of interpolation.h. They are intended for copy&paste usage only.

class InterpolateTypeDecoratorImpl : public maxon::Component<InterpolateTypeDecoratorImpl, InterpolateTypeInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const DataType& GetInterpolateDataType() const
	{
		return maxon::Cast<InterpolateType>(self.GetDecoratedObject()).GetInterpolateDataType();
	}

	MAXON_METHOD void InterpolateLinear(void* data1, const void* data2, Float blend) const
	{
		return maxon::Cast<InterpolateType>(self.GetDecoratedObject()).InterpolateLinear(data1, data2, blend);
	}

	MAXON_METHOD void InterpolateInOutline(void* data, const Block<void*>& outline, const Block<Float>& weights) const
	{
		return maxon::Cast<InterpolateType>(self.GetDecoratedObject()).InterpolateInOutline(data, outline, weights);
	}

	MAXON_METHOD void Average(void* data, const Block<const void*>& dataSet) const
	{
		return maxon::Cast<InterpolateType>(self.GetDecoratedObject()).Average(data, dataSet);
	}

};
