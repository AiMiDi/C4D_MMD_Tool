// This file contains default implementations for the interfaces of gfx_image_storage.h. They are intended for copy&paste usage only.

class MyImagePixelStorageImpl : public maxon::Component<MyImagePixelStorageImpl, ImagePixelStorageInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(Int width, Int height, const PixelFormat& format, const Block<Pix>* defaultColor)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Int GetWidth() const
	{
		return 0;
	}

	MAXON_METHOD Int GetHeight() const
	{
		return 0;
	}

	MAXON_METHOD Int GetChannelCount() const
	{
		return 0;
	}

	MAXON_METHOD PixelFormat GetPixelFormat() const
	{
		return maxon::PrivateIncompleteNullReturnValue<PixelFormat>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<GetPixelHandlerStruct> GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<SetPixelHandlerStruct> SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, const ColorProfile& dstColorProfile, SETPIXELHANDLERFLAGS flags, const Delegate<void(const UpdateRegion&)>& updateRegionNotification)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD void FreePixelHandler(GetPixelHandlerStruct& pixel) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void FreePixelHandler(SetPixelHandlerStruct& pixel, const Delegate<void(const UpdateRegion&)>& updateRegionNotification) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Result<void> GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
