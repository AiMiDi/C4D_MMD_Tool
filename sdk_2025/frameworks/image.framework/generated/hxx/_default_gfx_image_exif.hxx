// This file contains default implementations for the interfaces of gfx_image_exif.h. They are intended for copy&paste usage only.

class MyExifImpl : public maxon::Component<MyExifImpl, ExifInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<DataDictionary> GetExifDictionary() const
	{
		return HXXRET1(NULLIMPL);
	}

};
