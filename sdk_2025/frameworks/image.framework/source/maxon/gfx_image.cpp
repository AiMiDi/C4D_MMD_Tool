#include "maxon/gfx_image.h"
#include "maxon/mediasession_output.h"
#include "maxon/gfx_image_storage.h"


namespace maxon
{

const Class<ImagePixelStorage>& GetNormalPixelStorageClass()
{
	return ImagePixelStorageClasses::Normal();
}

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

Result<void> ConvertImageSequence(const Url& sourceUrl, const Url& destPath, const String& destFilePatern,
	const Class<MediaOutputUrlRef>& exportClass, const ValueReceiver<const Url&>& resultFiles)
{
	iferr_scope;

	ImageTextureRef splashImage = ImageTextureClasses::TEXTURE().Create() iferr_return;
	MediaSessionRef mediaSessionRef = splashImage.Load(sourceUrl, TimeValue(), MEDIASESSIONFLAGS::NONE) iferr_return;
	const Float			fps = splashImage.Get(IMAGEPROPERTIES::IMAGE::FPS) iferr_return;

	Int idx = 0;
	while (true)
	{
		Url saveUrl = destPath;
		saveUrl.Append(FormatString(destFilePatern, idx)) iferr_return;

		MediaOutputUrlRef saveClass = exportClass.Create() iferr_return;
		splashImage.Save(saveUrl, saveClass, MEDIASESSIONFLAGS::NONE) iferr_return;

		if (resultFiles)
		{
			resultFiles(saveUrl) iferr_return;
		}

		idx++;

		iferr (mediaSessionRef.Convert(TimeValue(idx, fps), MEDIASESSIONFLAGS::NONE))
			break;
	}
	return OK;
}

Result<void> CopyImageData(const ImageBaseRef& source, const ImageRef& dest, Bool allowDifferentSize)
{
	iferr_scope;

	if (source.IsEmpty())
		return IllegalArgumentError(MAXON_SOURCE_LOCATION);

	PixelFormat rgbFormat = source.GetPixelFormat();

	if (dest.IsEmpty())
	{
		auto storageType = ImagePixelStorageClasses::Normal();
		dest.Init(source.GetWidth(), source.GetHeight(), storageType, rgbFormat) iferr_return;
	}

	if (!allowDifferentSize)
	{
		if (source.GetWidth() != dest.GetWidth())
			return IllegalStateError(MAXON_SOURCE_LOCATION);

		if (source.GetHeight() != dest.GetHeight())
			return IllegalStateError(MAXON_SOURCE_LOCATION);
	}

	Int width = Min(source.GetWidth(), dest.GetWidth());
	Int height = Min(source.GetHeight(), dest.GetHeight());

	// read data
	PixelFormat format = rgbFormat;
	auto off = format.GetChannelOffsets();
	GetPixelHandlerStruct read = source.GetPixelHandler(format, off, ColorProfile(), GETPIXELHANDLERFLAGS::NONE, nullptr) iferr_return;

	// prepare buffer
	Int size = width * format.GetChannelCount();
	BaseArray<UChar> data;
	data.Resize(size) iferr_return;

	// load data into buffer
	BITS bitsPerPixel = format.GetBitsPerPixel(); // size per pixel
	PixelMutableBuffer buffer(data.GetFirst(), bitsPerPixel);	 // pixel data

	// get handler to fill image
	SetPixelHandlerStruct destHandler = dest.SetPixelHandler(format, off, ColorProfile(), SETPIXELHANDLERFLAGS::NONE) iferr_return;

	for (Int y = 0; y < height; ++y)
	{
		ImagePos pos(0, y, width);
		read.GetPixel(pos, buffer, GETPIXELFLAGS::NONE) iferr_return;
		destHandler.SetPixel(pos, buffer, SETPIXELFLAGS::NONE) iferr_return;
	}

	return OK;
}

}
