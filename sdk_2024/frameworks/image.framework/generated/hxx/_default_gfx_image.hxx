// This file contains default implementations for the interfaces of gfx_image.h. They are intended for copy&paste usage only.

class MyImageBaseImpl : public maxon::Component<MyImageBaseImpl, ImageBaseInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InitBase(Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> AddChildren(IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore)
	{
		return HXXRET1(NULLIMPL);
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
		return HXXRET3(NULLIMPL, PixelFormat);
	}

	MAXON_METHOD Result<GetPixelHandlerStruct> GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags, const LayerSetInterface* layerSet) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<SetPixelHandlerStruct> SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD void FreePixelHandler(GetPixelHandlerStruct& pixel) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void FreePixelHandler(SetPixelHandlerStruct& pixel) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Result<void> GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<ImageBaseRef> CreateSubImagePart(const DrawRectInt& rect) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<ImageBaseRef> TransformColors(const ColorProfile& srcProfile, const ColorProfile& dstProfile, TRANSFORM_COLORS_FLAGS flags)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD maxon::ObservableRef<ObservableRegionChangedDelegate> ObservableRegionChanged(Bool create) const
	{
		return maxon::ObservableRef<ObservableRegionChangedDelegate>::DefaultValue();
	}

};

class MyImageTextureImpl : public maxon::Component<MyImageTextureImpl, ImageTextureInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<MediaSessionRef> Load(const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Save(const MediaOutputRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession) const
	{
		return HXXRET1(NULLIMPL);
	}

};

class MyImageImpl : public maxon::Component<MyImageImpl, ImageInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor)
	{
		return HXXRET1(NULLIMPL);
	}

};

class MyImageLayerImpl : public maxon::Component<MyImageLayerImpl, ImageLayerInterface>
{
	MAXON_COMPONENT();

public:
};
