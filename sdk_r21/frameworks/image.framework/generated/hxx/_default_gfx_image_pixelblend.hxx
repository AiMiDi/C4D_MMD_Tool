// This file contains default implementations for the interfaces of gfx_image_pixelblend.h. They are intended for copy&paste usage only.

class MyImagePixelBlendImpl : public maxon::Component<MyImagePixelBlendImpl, ImagePixelBlendInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<BlendPixelHandlerStruct> GetBlendPixelHandler(const PixelFormat& bgFormat, const ChannelOffsets& bgChannelOffsets, const PixelFormat& fgFormat, const ChannelOffsets& fgChannelOffsets, Float opacity) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
