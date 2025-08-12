// This file contains decorator implementations for the interfaces of blend_function.h. They are intended for copy&paste usage only.

class BlendFunctionDecoratorImpl : public maxon::Component<BlendFunctionDecoratorImpl, BlendFunctionInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Data> MapValue(Float x, const Data& startValue, const Data& endValue)
	{
		return maxon::Cast<BlendFunctionRef>(self.GetDecoratedObject()).MapValue(x, startValue, endValue);
	}

};
