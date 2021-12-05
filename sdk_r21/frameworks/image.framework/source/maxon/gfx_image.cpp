#include "maxon/gfx_image.h"
#include "maxon/mediasession_output.h"


namespace maxon
{

Result<void> ImageTextureInterface::Save(const Url& fileName, const MediaOutputUrlRef& fileFormat, MEDIASESSIONFLAGS flags, MediaSessionRef* returnOpenSession) const
{
	iferr_scope;
	fileFormat.SetOutputUrl(fileName) iferr_return;
	return Save(fileFormat, flags, returnOpenSession);
}

ImageRef GetImageOf(const ImageBaseRef& bmp)
{
	// check if the image has an separate alpha.
	IMAGEPROPERTIES::ITYPE type = bmp.Get(IMAGEPROPERTIES::TYPE, IMAGEPROPERTIES::ITYPE::UNDEFINED);
	ImageBaseRef image;
	switch (type)
	{
		case IMAGEPROPERTIES::ITYPE::TEXTURE:
			image = bmp.GetFirstChild(ConstDataPtr(IMAGEHIERARCHY::IMAGE));
			break;

		case IMAGEPROPERTIES::ITYPE::IMAGE:
			image = bmp;
			break;
	}
	return Cast<ImageRef>(image);
}

ImageLayerRef GetFirstAlphaOf(const ImageBaseRef& bmp)
{
	ImageRef image = GetImageOf(bmp);
	bmp.GetChildren().GetValue().GetFirst();

	ImageBaseRef alphaChannel = image.GetFirstChild(ConstDataPtr(IMAGEHIERARCHY::ALPHA));
	return Cast<ImageLayerRef>(alphaChannel);
}

}
