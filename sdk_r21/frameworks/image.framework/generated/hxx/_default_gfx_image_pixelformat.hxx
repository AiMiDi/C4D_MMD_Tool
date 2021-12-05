// This file contains default implementations for the interfaces of gfx_image_pixelformat.h. They are intended for copy&paste usage only.

class MyPixelFormatGroupImpl : public maxon::Component<MyPixelFormatGroupImpl, PixelFormatGroupInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD PixelFormatIterator GetEntries() const
	{
		return maxon::PrivateIncompleteNullReturnValue<PixelFormatIterator>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};

class MyPixelFormatImpl : public maxon::Component<MyPixelFormatImpl, PixelFormatInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const PixelFormatGroup& group, const Char* shortName)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Block<const ImageChannel> GetChannels() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Block<const ImageChannel>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD const PixelFormatGroup& GetPixelFormatGroup() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const PixelFormatGroup&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<Pix*> CreatePix(Int width, Int height, Int lineAlignment) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Int GetChannelCount() const
	{
		return 0;
	}

	MAXON_METHOD const ChannelOffsets& GetChannelOffsets() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const ChannelOffsets&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD BITS GetBitsPerPixel() const
	{
		return maxon::PrivateIncompleteNullReturnValue<BITS>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
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
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD ColorSpace GetColorSpace() const
	{
		return maxon::PrivateIncompleteNullReturnValue<ColorSpace>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD const ColorProfile& GetDefaultColorProfile() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const ColorProfile&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<CONVERTPIXELFUNC> GetConvertPixelFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, Bool forceColorProfileConversion, Bool& disableCaching) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> ConvertPixelFromSlow(const ImageMutableBuffer& dst, Int count, const ImageConstBuffer& src, const ColorProfile& srcColorProfile, ColorProfile* dstColorProfile, CONVERTPIXELFLAGS cflags, GETPIXELFLAGS flags) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Bool IsIdenticalPixel(const ImageConstBuffer& a, const ImageConstBuffer& b, Int oneTolerance) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD String PixToString(const Pix* src) const
	{
		return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<CONVERTPIXELFUNC> GetConvertPixelFromFunc(const PixelFormat& srcFormatPtr, const ChannelOffsets& srcChannelOffset, const ChannelOffsets& dstChannelOffset, Bool fastSize, Bool& disableCaching) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<CONVERTPIXELFUNC> GetConvertPixelToFunc(const PixelFormat& dstFormatPtr, const ChannelOffsets& dstChannelOffset, const ChannelOffsets& srcChannelOffset, Bool fastSize, Bool& disableCaching) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD const Char* GetShortName() const
	{
		return nullptr;
	}

};

class MyPixelFormatIndexedColorImpl : public maxon::Component<MyPixelFormatIndexedColorImpl, PixelFormatIndexedColorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InitColorTable(Int count, const PixelFormat& srcFormatPtr)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD PixelFormat GetColorTablePixelFormat() const
	{
		return maxon::PrivateIncompleteNullReturnValue<PixelFormat>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Int GetColorTableSize() const
	{
		return 0;
	}

	MAXON_METHOD Result<void> SetIndex(Int idx, const ImageConstBuffer& srcPixelData)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
