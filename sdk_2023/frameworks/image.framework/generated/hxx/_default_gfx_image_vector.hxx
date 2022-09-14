// This file contains default implementations for the interfaces of gfx_image_vector.h. They are intended for copy&paste usage only.

class MyVectorImageImpl : public maxon::Component<MyVectorImageImpl, VectorImageInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const Url& url)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Init(const SVGDocument& svgDocument)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD const Url& GetUrl() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<ForwardRef<SVGDocument>> GetSVGDocument() const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
