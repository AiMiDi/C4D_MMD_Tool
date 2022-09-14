// This file contains default implementations for the interfaces of gfx_image_pixelformat_dynamic.h. They are intended for copy&paste usage only.

class MyPixelFormatDynamicImpl : public maxon::Component<MyPixelFormatDynamicImpl, PixelFormatDynamicInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Int> AddChannel(const ImageChannel& channel)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
