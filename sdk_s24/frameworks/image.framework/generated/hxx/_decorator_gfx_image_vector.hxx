// This file contains decorator implementations for the interfaces of gfx_image_vector.h. They are intended for copy&paste usage only.

class VectorImageDecoratorImpl : public maxon::Component<VectorImageDecoratorImpl, VectorImageInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const Url& vectorIconUrl)
	{
		return maxon::Cast<VectorImageRef>(self.GetDecoratedObject()).Init(vectorIconUrl);
	}

	MAXON_METHOD Result<void> Init(const SVGDocument& vectorIcon)
	{
		return maxon::Cast<VectorImageRef>(self.GetDecoratedObject()).Init(vectorIcon);
	}

	MAXON_METHOD Result<ForwardRef<SVGDocument>> GetVectorIcon() const
	{
		return maxon::Cast<VectorImageRef>(self.GetDecoratedObject()).GetVectorIcon();
	}

};
