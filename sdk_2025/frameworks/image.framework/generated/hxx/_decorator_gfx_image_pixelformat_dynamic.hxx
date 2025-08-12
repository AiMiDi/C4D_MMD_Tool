// This file contains decorator implementations for the interfaces of gfx_image_pixelformat_dynamic.h. They are intended for copy&paste usage only.

class PixelFormatDynamicDecoratorImpl : public maxon::Component<PixelFormatDynamicDecoratorImpl, PixelFormatDynamicInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Int> AddChannel(const ImageChannel& channel)
	{
		return maxon::Cast<PixelFormatDynamic>(self.GetDecoratedObject()).AddChannel(channel);
	}

};
