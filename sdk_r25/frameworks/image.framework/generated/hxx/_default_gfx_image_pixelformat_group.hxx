// This file contains default implementations for the interfaces of gfx_image_pixelformat_group.h. They are intended for copy&paste usage only.

class MyPixelFormatGroupImpl : public maxon::Component<MyPixelFormatGroupImpl, PixelFormatGroupInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD PixelFormatIterator GetEntries() const
	{
		return maxon::PrivateIncompleteNullReturnValue<PixelFormatIterator>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};
