// This file contains default implementations for the interfaces of gfx_image_imagechannel.h. They are intended for copy&paste usage only.

class MyImageChannelTypeImpl : public maxon::Component<MyImageChannelTypeImpl, ImageChannelTypeInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Pix8u GetDefaultFillValue() const
	{
		return HXXRET3(NULLIMPL, Pix8u);
	}

	MAXON_METHOD ColorSpace GetColorSpace() const
	{
		return HXXRET3(NULLIMPL, ColorSpace);
	}

	MAXON_METHOD ImageChannel GetChannel(const DataType& pixelType) const
	{
		return HXXRET3(NULLIMPL, ImageChannel);
	}

};

class MyImageChannelImpl : public maxon::Component<MyImageChannelImpl, ImageChannelInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD BITS GetChannelBits() const
	{
		return HXXRET3(NULLIMPL, BITS);
	}

	MAXON_METHOD ImageChannelType GetChannelType() const
	{
		return HXXRET3(NULLIMPL, ImageChannelType);
	}

	MAXON_METHOD const DataType& GetDataType() const
	{
		return HXXRET3(NULLIMPL, const DataType&);
	}

	MAXON_METHOD Bool IsIdenticalComponent(const void* a, const void* b, Int oneTolerance) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

};
