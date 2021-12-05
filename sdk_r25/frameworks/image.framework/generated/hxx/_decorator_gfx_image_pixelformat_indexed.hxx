// This file contains decorator implementations for the interfaces of gfx_image_pixelformat_indexed.h. They are intended for copy&paste usage only.

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
