// This file contains decorator implementations for the interfaces of gfx_image_exif.h. They are intended for copy&paste usage only.

class ExifDecoratorImpl : public maxon::Component<ExifDecoratorImpl, ExifInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<DataDictionary> GetExifDictionary() const
	{
		return maxon::Cast<ExifRef>(self.GetDecoratedObject()).GetExifDictionary();
	}

};
