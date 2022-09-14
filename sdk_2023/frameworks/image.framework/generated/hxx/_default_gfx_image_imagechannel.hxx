// This file contains default implementations for the interfaces of gfx_image_imagechannel.h. They are intended for copy&paste usage only.

class MyImageChannelTypeImpl : public maxon::Component<MyImageChannelTypeImpl, ImageChannelTypeInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Pix8u GetDefaultFillValue() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Pix8u>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD ColorSpace GetColorSpace() const
	{
		return maxon::PrivateIncompleteNullReturnValue<ColorSpace>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD ImageChannel GetChannel(const DataType& pixelType) const
	{
		return maxon::PrivateIncompleteNullReturnValue<ImageChannel>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};

class MyImageChannelImpl : public maxon::Component<MyImageChannelImpl, ImageChannelInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD BITS GetChannelBits() const
	{
		return maxon::PrivateIncompleteNullReturnValue<BITS>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD ImageChannelType GetChannelType() const
	{
		return maxon::PrivateIncompleteNullReturnValue<ImageChannelType>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD const DataType& GetDataType() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool IsIdenticalComponent(const void* a, const void* b, Int oneTolerance) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

};
