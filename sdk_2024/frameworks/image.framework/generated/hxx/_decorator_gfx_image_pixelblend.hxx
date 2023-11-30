// This file contains decorator implementations for the interfaces of gfx_image_pixelblend.h. They are intended for copy&paste usage only.

class ImagePixelBlendDecoratorImpl : public maxon::Component<ImagePixelBlendDecoratorImpl, ImagePixelBlendInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<BlendPixelHandlerStruct> GetBlendPixelHandler(const PixelFormat& bgFormat, const ChannelOffsets& bgChannelOffsets, const PixelFormat& fgFormat, const ChannelOffsets& fgChannelOffsets, Float opacity) const
	{
		return maxon::Cast<ImagePixelBlend>(self.GetDecoratedObject()).GetBlendPixelHandler(bgFormat, bgChannelOffsets, fgFormat, fgChannelOffsets, opacity);
	}

};
