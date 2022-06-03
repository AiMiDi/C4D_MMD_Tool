// This file contains decorator implementations for the interfaces of gfx_image_vector.h. They are intended for copy&paste usage only.

class VectorImageDecoratorImpl : public maxon::Component<VectorImageDecoratorImpl, VectorImageInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const Url& url)
	{
		return maxon::Cast<VectorImageRef>(self.GetDecoratedObject()).Init(url);
	}

	MAXON_METHOD Result<void> Init(const SVGDocument& svgDocument)
	{
		return maxon::Cast<VectorImageRef>(self.GetDecoratedObject()).Init(svgDocument);
	}

	MAXON_METHOD const Url& GetUrl() const
	{
		return maxon::Cast<VectorImageRef>(self.GetDecoratedObject()).GetUrl();
	}

	MAXON_METHOD Result<ForwardRef<SVGDocument>> GetSVGDocument() const
	{
		return maxon::Cast<VectorImageRef>(self.GetDecoratedObject()).GetSVGDocument();
	}

};
