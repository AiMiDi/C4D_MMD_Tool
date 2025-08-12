// This file contains decorator implementations for the interfaces of gfx_image_storage.h. They are intended for copy&paste usage only.

class ImagePixelStorageDecoratorImpl : public maxon::Component<ImagePixelStorageDecoratorImpl, ImagePixelStorageInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor)
	{
		return maxon::Cast<ImagePixelStorage>(self.GetDecoratedObject()).Init(width, height, format, defaultColor);
	}

	MAXON_METHOD Int GetWidth() const
	{
		return maxon::Cast<ImagePixelStorage>(self.GetDecoratedObject()).GetWidth();
	}

	MAXON_METHOD Int GetHeight() const
	{
		return maxon::Cast<ImagePixelStorage>(self.GetDecoratedObject()).GetHeight();
	}

	MAXON_METHOD Int GetChannelCount() const
	{
		return maxon::Cast<ImagePixelStorage>(self.GetDecoratedObject()).GetChannelCount();
	}

	MAXON_METHOD PixelFormat GetPixelFormat() const
	{
		return maxon::Cast<ImagePixelStorage>(self.GetDecoratedObject()).GetPixelFormat();
	}

	MAXON_METHOD Result<GetPixelHandlerStruct> GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) const
	{
		return maxon::Cast<ImagePixelStorage>(self.GetDecoratedObject()).GetPixelHandler(dstFormat, channelOffsets, srcColorProfile, dstColorProfile, flags);
	}

	MAXON_METHOD Result<SetPixelHandlerStruct> SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification)
	{
		return maxon::Cast<ImagePixelStorage>(self.GetDecoratedObject()).SetPixelHandler(srcFormat, channelOffsets, srcColorProfile, dstColorProfile, flags, updateRegionNotification);
	}

	MAXON_METHOD void FreePixelHandler(GetPixelHandlerStruct& pixel) const
	{
		return maxon::Cast<ImagePixelStorage>(self.GetDecoratedObject()).FreePixelHandler(pixel);
	}

	MAXON_METHOD void FreePixelHandler(SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const
	{
		return maxon::Cast<ImagePixelStorage>(self.GetDecoratedObject()).FreePixelHandler(pixel, updateRegionNotification);
	}

	MAXON_METHOD Result<void> GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const
	{
		return maxon::Cast<ImagePixelStorage>(self.GetDecoratedObject()).GetComponent(component, pos, data, inc, flags);
	}

	MAXON_METHOD Result<void> SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags)
	{
		return maxon::Cast<ImagePixelStorage>(self.GetDecoratedObject()).SetComponent(component, pos, data, inc, flags);
	}

};
