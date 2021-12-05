// This file contains default implementations for the interfaces of gfx_image_vector.h. They are intended for copy&paste usage only.

class MyVectorImageImpl : public maxon::Component<MyVectorImageImpl, VectorImageInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const Url& vectorIconUrl)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Init(const SVGDocument& vectorIcon)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<ForwardRef<SVGDocument>> GetVectorIcon() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
