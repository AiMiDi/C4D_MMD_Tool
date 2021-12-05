// This file contains default implementations for the interfaces of gfx_image_colorspace.h. They are intended for copy&paste usage only.

class MyColorSpaceImpl : public maxon::Component<MyColorSpaceImpl, ColorSpaceInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const ColorProfile& GetDefaultNonlinearColorProfile() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const ColorProfile&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD const ColorProfile& GetDefaultLinearColorProfile() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const ColorProfile&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};
