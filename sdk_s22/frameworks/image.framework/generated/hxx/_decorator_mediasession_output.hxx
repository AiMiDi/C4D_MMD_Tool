// This file contains decorator implementations for the interfaces of mediasession_output.h. They are intended for copy&paste usage only.

class MediaOutputDecoratorImpl : public maxon::Component<MediaOutputDecoratorImpl, MediaOutputInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ResetConverter()
	{
		return maxon::Cast<MediaOutputRef>(self.GetDecoratedObject()).ResetConverter();
	}

	MAXON_METHOD Result<void> SetSelectionHandler(const MediaOutputSelectionHandler& selectionHandler)
	{
		return maxon::Cast<MediaOutputRef>(self.GetDecoratedObject()).SetSelectionHandler(selectionHandler);
	}

	MAXON_METHOD const MediaOutputSelectionHandler& GetSelectionHandler() const
	{
		return maxon::Cast<MediaOutputRef>(self.GetDecoratedObject()).GetSelectionHandler();
	}

	MAXON_METHOD Result<SELECTIONHANDLERRESULT> CallSelectionHandler(const MediaStreamRef& stream, const MediaStreamFormat& props)
	{
		return maxon::Cast<MediaOutputRef>(self.GetDecoratedObject()).CallSelectionHandler(stream, props);
	}

};

class MediaOutputTextureDecoratorImpl : public maxon::Component<MediaOutputTextureDecoratorImpl, MediaOutputTextureInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetOutputTexture(const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass)
	{
		return maxon::Cast<MediaOutputTextureRef>(self.GetDecoratedObject()).SetOutputTexture(textureRef, pixelStorageClass);
	}

};

class MediaOutputUrlDecoratorImpl : public maxon::Component<MediaOutputUrlDecoratorImpl, MediaOutputUrlInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Url GetOutputUrl() const
	{
		return maxon::Cast<MediaOutputUrlRef>(self.GetDecoratedObject()).GetOutputUrl();
	}

	MAXON_METHOD Result<void> SetOutputUrl(const Url& url)
	{
		return maxon::Cast<MediaOutputUrlRef>(self.GetDecoratedObject()).SetOutputUrl(url);
	}

	MAXON_METHOD const FileFormat& GetFileFormat() const
	{
		return maxon::Cast<MediaOutputUrlRef>(self.GetDecoratedObject()).GetFileFormat();
	}

	MAXON_METHOD Result<Bool> EditSystemOptions(DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle)
	{
		return maxon::Cast<MediaOutputUrlRef>(self.GetDecoratedObject()).EditSystemOptions(settings, getParentwindowHandle);
	}

	MAXON_METHOD Result<DrawDimensionInt> CheckBitmapSize(const DataDictionary& settings, const DrawDimensionInt& bitmapSize) const
	{
		return maxon::Cast<MediaOutputUrlRef>(self.GetDecoratedObject()).CheckBitmapSize(settings, bitmapSize);
	}

};
