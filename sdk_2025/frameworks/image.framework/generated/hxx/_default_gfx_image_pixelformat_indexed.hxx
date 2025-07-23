// This file contains default implementations for the interfaces of gfx_image_pixelformat_indexed.h. They are intended for copy&paste usage only.

class MyPixelFormatIndexedColorImpl : public maxon::Component<MyPixelFormatIndexedColorImpl, PixelFormatIndexedColorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InitColorTable(Int count, const PixelFormat& srcFormatPtr)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD PixelFormat GetColorTablePixelFormat() const
	{
		return HXXRET3(NULLIMPL, PixelFormat);
	}

	MAXON_METHOD Int GetColorTableSize() const
	{
		return 0;
	}

	MAXON_METHOD Result<void> SetIndex(Int idx, const ImageConstBuffer& srcPixelData)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> GetIndex(Int idx, const ImageMutableBuffer& dstPixelData) const
	{
		return HXXRET1(NULLIMPL);
	}

};
