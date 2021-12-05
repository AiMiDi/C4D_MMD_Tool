// This file contains default implementations for the interfaces of blend_function.h. They are intended for copy&paste usage only.

class MyBlendFunctionImpl : public maxon::Component<MyBlendFunctionImpl, BlendFunctionInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Data> MapValue(Float x, const Data& startValue, const Data& endValue)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
