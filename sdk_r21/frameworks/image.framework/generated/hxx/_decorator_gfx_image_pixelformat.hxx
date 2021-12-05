// This file contains decorator implementations for the interfaces of gfx_image_pixelformat.h. They are intended for copy&paste usage only.

class PixelFormatGroupDecoratorImpl : public maxon::Component<PixelFormatGroupDecoratorImpl, PixelFormatGroupInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD PixelFormatIterator GetEntries() const
	{
		return maxon::Cast<PixelFormatGroup>(self.GetDecoratedObject()).GetEntries();
	}

};

class PixelFormatDecoratorImpl : public maxon::Component<PixelFormatDecoratorImpl, PixelFormatInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const PixelFormatGroup& group, const Char* shortName)
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).Init(group, shortName);
	}

	MAXON_METHOD Block<const ImageChannel> GetChannels() const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).GetChannels();
	}

	MAXON_METHOD const PixelFormatGroup& GetPixelFormatGroup() const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).GetPixelFormatGroup();
	}

	MAXON_METHOD Result<Pix*> CreatePix(Int width, Int height, Int lineAlignment) const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).CreatePix(width, height, lineAlignment);
	}

	MAXON_METHOD Int GetChannelCount() const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).GetChannelCount();
	}

	MAXON_METHOD const ChannelOffsets& GetChannelOffsets() const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).GetChannelOffsets();
	}

	MAXON_METHOD BITS GetBitsPerPixel() const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).GetBitsPerPixel();
	}

	MAXON_METHOD Int GetBytesPerLine(Int width, Int lineAlignment) const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).GetBytesPerLine(width, lineAlignment);
	}

	MAXON_METHOD Int GetPackedPixelCount() const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).GetPackedPixelCount();
	}

	MAXON_METHOD Bool HasAlpha() const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).HasAlpha();
	}

	MAXON_METHOD Result<Tuple<PixelFormat, Int>> GetAlphaPixelFormat() const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).GetAlphaPixelFormat();
	}

	MAXON_METHOD ColorSpace GetColorSpace() const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).GetColorSpace();
	}

	MAXON_METHOD const ColorProfile& GetDefaultColorProfile() const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).GetDefaultColorProfile();
	}

	MAXON_METHOD Result<CONVERTPIXELFUNC> GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching) const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).GetConvertPixelFunc(srcFormatPtr, srcChannelOffset, dstChannelOffset, srcColorProfile, dstColorProfile, forceColorProfileConversion, disableCaching);
	}

	MAXON_METHOD Result<void> ConvertPixelFromSlow(const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).ConvertPixelFromSlow(dst, count, src, srcColorProfile, dstColorProfile, cflags, flags);
	}

	MAXON_METHOD Bool IsIdenticalPixel(const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).IsIdenticalPixel(a, b, oneTolerance);
	}

	MAXON_METHOD String PixToString(const Pix* src) const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).PixToString(src);
	}

	MAXON_METHOD Result<CONVERTPIXELFUNC> GetConvertPixelFromFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).GetConvertPixelFromFunc(srcFormatPtr, srcChannelOffset, dstChannelOffset, fastSize, disableCaching);
	}

	MAXON_METHOD Result<CONVERTPIXELFUNC> GetConvertPixelToFunc(const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).GetConvertPixelToFunc(dstFormatPtr, dstChannelOffset, srcChannelOffset, fastSize, disableCaching);
	}

	MAXON_METHOD const Char* GetShortName() const
	{
		return maxon::Cast<PixelFormat>(self.GetDecoratedObject()).GetShortName();
	}

};

class PixelFormatIndexedColorDecoratorImpl : public maxon::Component<PixelFormatIndexedColorDecoratorImpl, PixelFormatIndexedColorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InitColorTable(Int count, const PixelFormat& srcFormatPtr)
	{
		return maxon::Cast<PixelFormatIndexedColor>(self.GetDecoratedObject()).InitColorTable(count, srcFormatPtr);
	}

	MAXON_METHOD PixelFormat GetColorTablePixelFormat() const
	{
		return maxon::Cast<PixelFormatIndexedColor>(self.GetDecoratedObject()).GetColorTablePixelFormat();
	}

	MAXON_METHOD Int GetColorTableSize() const
	{
		return maxon::Cast<PixelFormatIndexedColor>(self.GetDecoratedObject()).GetColorTableSize();
	}

	MAXON_METHOD Result<void> SetIndex(Int idx, const ImageConstBuffer& srcPixelData)
	{
		return maxon::Cast<PixelFormatIndexedColor>(self.GetDecoratedObject()).SetIndex(idx, srcPixelData);
	}

	MAXON_METHOD Result<void> GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const
	{
		return maxon::Cast<PixelFormatIndexedColor>(self.GetDecoratedObject()).GetIndex(idx, dstPixelData);
	}

};
