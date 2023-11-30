// This file contains decorator implementations for the interfaces of gfx_image.h. They are intended for copy&paste usage only.

class ImageBaseDecoratorImpl : public maxon::Component<ImageBaseDecoratorImpl, ImageBaseInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InitBase(Int width, Int height, const PixelFormat& pixelFormat, IMAGEPROPERTIES::ITYPE type)
	{
		return maxon::Cast<ImageBaseRef>(self.GetDecoratedObject()).InitBase(width, height, pixelFormat, type);
	}

	MAXON_METHOD Result<void> AddChildren(IMAGEHIERARCHY hierarchy, const ImageBaseRef& newChildren, const ImageBaseRef& insertBefore)
	{
		return maxon::Cast<ImageBaseRef>(self.GetDecoratedObject()).AddChildren(hierarchy, newChildren, insertBefore);
	}

	MAXON_METHOD Int GetWidth() const
	{
		return maxon::Cast<ImageBaseRef>(self.GetDecoratedObject()).GetWidth();
	}

	MAXON_METHOD Int GetHeight() const
	{
		return maxon::Cast<ImageBaseRef>(self.GetDecoratedObject()).GetHeight();
	}

	MAXON_METHOD Int GetChannelCount() const
	{
		return maxon::Cast<ImageBaseRef>(self.GetDecoratedObject()).GetChannelCount();
	}

	MAXON_METHOD PixelFormat GetPixelFormat() const
	{
		return maxon::Cast<ImageBaseRef>(self.GetDecoratedObject()).GetPixelFormat();
	}

	MAXON_METHOD Result<GetPixelHandlerStruct> GetPixelHandler(const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags, const LayerSetInterface* layerSet) const
	{
		return maxon::Cast<ImageBaseRef>(self.GetDecoratedObject()).GetPixelHandler(dstFormat, channelOffsets, dstColorProfile, flags, layerSet);
	}

	MAXON_METHOD Result<SetPixelHandlerStruct> SetPixelHandler(const PixelFormat& srcFormat, const ChannelOffsets& channelOffsets, const ColorProfile& srcColorProfile, SETPIXELHANDLERFLAGS flags)
	{
		return maxon::Cast<ImageBaseRef>(self.GetDecoratedObject()).SetPixelHandler(srcFormat, channelOffsets, srcColorProfile, flags);
	}

	MAXON_METHOD void FreePixelHandler(GetPixelHandlerStruct& pixel) const
	{
		return maxon::Cast<ImageBaseRef>(self.GetDecoratedObject()).FreePixelHandler(pixel);
	}

	MAXON_METHOD void FreePixelHandler(SetPixelHandlerStruct& pixel) const
	{
		return maxon::Cast<ImageBaseRef>(self.GetDecoratedObject()).FreePixelHandler(pixel);
	}

	MAXON_METHOD Result<void> GetComponent(Int component, const ImagePos& pos, Pix* data, Int inc, GETPIXELFLAGS flags) const
	{
		return maxon::Cast<ImageBaseRef>(self.GetDecoratedObject()).GetComponent(component, pos, data, inc, flags);
	}

	MAXON_METHOD Result<void> SetComponent(Int component, const ImagePos& pos, const Pix* data, Int inc, SETPIXELFLAGS flags)
	{
		return maxon::Cast<ImageBaseRef>(self.GetDecoratedObject()).SetComponent(component, pos, data, inc, flags);
	}

	MAXON_METHOD Result<ImageBaseRef> CreateSubImagePart(const DrawRectInt& rect) const
	{
		return maxon::Cast<ImageBaseRef>(self.GetDecoratedObject()).CreateSubImagePart(rect);
	}

	MAXON_METHOD Result<ImageBaseRef> TransformColors(const ColorProfile& srcProfile, const ColorProfile& dstProfile, TRANSFORM_COLORS_FLAGS flags)
	{
		return maxon::Cast<ImageBaseRef>(self.GetDecoratedObject()).TransformColors(srcProfile, dstProfile, flags);
	}

	MAXON_METHOD maxon::ObservableRef<ObservableRegionChangedDelegate> ObservableRegionChanged(Bool create) const
	{
		return maxon::Cast<ImageBaseRef>(self.GetDecoratedObject()).ObservableRegionChanged(create);
	}

};

class ImageTextureDecoratorImpl : public maxon::Component<ImageTextureDecoratorImpl, ImageTextureInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<MediaSessionRef> Load(const Url& url, const TimeValue& targetTime, MEDIASESSIONFLAGS flags, const Class<ImagePixelStorage>& pixelStorageClass, const LayerSetInterface* layerSet)
	{
		return maxon::Cast<ImageTextureRef>(self.GetDecoratedObject()).Load(url, targetTime, flags, pixelStorageClass, layerSet);
	}

	MAXON_METHOD Result<void> Save(const MediaOutputRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession) const
	{
		return maxon::Cast<ImageTextureRef>(self.GetDecoratedObject()).Save(fileFormat, flags, returnOpenSession);
	}

};

class ImageDecoratorImpl : public maxon::Component<ImageDecoratorImpl, ImageInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(Int width, Int height, const Class<ImagePixelStorage>& storageFormat, const PixelFormat& pixelFormat, const Block<Pix>* defaultColor)
	{
		return maxon::Cast<ImageRef>(self.GetDecoratedObject()).Init(width, height, storageFormat, pixelFormat, defaultColor);
	}

};

class ImageLayerDecoratorImpl : public maxon::Component<ImageLayerDecoratorImpl, ImageLayerInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};
