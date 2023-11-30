// This file contains default implementations for the interfaces of gfx_image_vector.h. They are intended for copy&paste usage only.

class MyVectorImageImpl : public maxon::Component<MyVectorImageImpl, VectorImageInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const Url& url)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Init(const SVGDocument& svgDocument)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD const Url& GetUrl() const
	{
		return HXXRET3(NULLIMPL, const Url&);
	}

	MAXON_METHOD Result<ForwardRef<SVGDocument>> GetSVGDocument() const
	{
		return HXXRET1(NULLIMPL);
	}

};
