// This file contains decorator implementations for the interfaces of gfx_image_imagechannel.h. They are intended for copy&paste usage only.

class ImageChannelTypeDecoratorImpl : public maxon::Component<ImageChannelTypeDecoratorImpl, ImageChannelTypeInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Pix8u GetDefaultFillValue() const
	{
		return maxon::Cast<ImageChannelType>(self.GetDecoratedObject()).GetDefaultFillValue();
	}

	MAXON_METHOD ColorSpace GetColorSpace() const
	{
		return maxon::Cast<ImageChannelType>(self.GetDecoratedObject()).GetColorSpace();
	}

	MAXON_METHOD ImageChannel GetChannel(const DataType& pixelType) const
	{
		return maxon::Cast<ImageChannelType>(self.GetDecoratedObject()).GetChannel(pixelType);
	}

};

class ImageChannelDecoratorImpl : public maxon::Component<ImageChannelDecoratorImpl, ImageChannelInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD BITS GetChannelBits() const
	{
		return maxon::Cast<ImageChannel>(self.GetDecoratedObject()).GetChannelBits();
	}

	MAXON_METHOD ImageChannelType GetChannelType() const
	{
		return maxon::Cast<ImageChannel>(self.GetDecoratedObject()).GetChannelType();
	}

	MAXON_METHOD const DataType& GetDataType() const
	{
		return maxon::Cast<ImageChannel>(self.GetDecoratedObject()).GetDataType();
	}

	MAXON_METHOD Bool IsIdenticalComponent(const void* a, const void* b, Int oneTolerance) const
	{
		return maxon::Cast<ImageChannel>(self.GetDecoratedObject()).IsIdenticalComponent(a, b, oneTolerance);
	}

};
