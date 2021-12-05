// This file contains decorator implementations for the interfaces of gfx_image_colorspace.h. They are intended for copy&paste usage only.

class ColorSpaceDecoratorImpl : public maxon::Component<ColorSpaceDecoratorImpl, ColorSpaceInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const ColorProfile& GetDefaultNonlinearColorProfile() const
	{
		return maxon::Cast<ColorSpace>(self.GetDecoratedObject()).GetDefaultNonlinearColorProfile();
	}

	MAXON_METHOD const ColorProfile& GetDefaultLinearColorProfile() const
	{
		return maxon::Cast<ColorSpace>(self.GetDecoratedObject()).GetDefaultLinearColorProfile();
	}

};
