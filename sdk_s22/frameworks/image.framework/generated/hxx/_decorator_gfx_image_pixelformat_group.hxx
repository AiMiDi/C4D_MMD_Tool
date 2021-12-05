// This file contains decorator implementations for the interfaces of gfx_image_pixelformat_group.h. They are intended for copy&paste usage only.

class PixelFormatGroupDecoratorImpl : public maxon::Component<PixelFormatGroupDecoratorImpl, PixelFormatGroupInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD PixelFormatIterator GetEntries() const
	{
		return maxon::Cast<PixelFormatGroup>(self.GetDecoratedObject()).GetEntries();
	}

};
