// This file contains default implementations for the interfaces of gfx_image_pixelformat.h. They are intended for copy&paste usage only.

class MyPixelFormatImpl : public maxon::Component<MyPixelFormatImpl, PixelFormatInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const PixelFormatGroup& group, const Char* shortName)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Block<const ImageChannel> GetChannels() const
	{
		return HXXRET3(NULLIMPL, Block<const ImageChannel>);
	}

	MAXON_METHOD const PixelFormatGroup& GetPixelFormatGroup() const
	{
		return HXXRET3(NULLIMPL, const PixelFormatGroup&);
	}

	MAXON_METHOD Result<Pix*> CreatePix(Int width, Int height, Int lineAlignment) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Int GetChannelCount() const
	{
		return 0;
	}

	MAXON_METHOD const ChannelOffsets& GetChannelOffsets() const
	{
		return HXXRET3(NULLIMPL, const ChannelOffsets&);
	}

	MAXON_METHOD BITS GetBitsPerPixel() const
	{
		return HXXRET3(NULLIMPL, BITS);
	}

	MAXON_METHOD Int GetBytesPerLine(Int width, Int lineAlignment) const
	{
		return 0;
	}

	MAXON_METHOD Int GetPackedPixelCount() const
	{
		return 0;
	}

	MAXON_METHOD Bool HasAlpha() const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Result<Tuple<PixelFormat, Int>> GetAlphaPixelFormat() const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD ColorSpace GetColorSpace() const
	{
		return HXXRET3(NULLIMPL, ColorSpace);
	}

	MAXON_METHOD const ColorProfile& GetDefaultColorProfile() const
	{
		return HXXRET3(NULLIMPL, const ColorProfile&);
	}

	MAXON_METHOD Result<CONVERTPIXELFUNC> GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<CONVERTPIXELFUNC> GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, COLORCONVERSIONFLAGS colorConversionFlags, Bool& disableCaching) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> ConvertPixelFromSlow(const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Bool IsIdenticalPixel(const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD String PixToString(const Pix* src) const
	{
		return HXXRET3(NULLIMPL, String);
	}

	MAXON_METHOD Result<CONVERTPIXELFUNC> GetConvertPixelFromFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<CONVERTPIXELFUNC> GetConvertPixelToFunc(const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD const Char* GetShortName() const
	{
		return nullptr;
	}

};
