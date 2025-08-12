// This file contains default implementations for the interfaces of mediasession_output.h. They are intended for copy&paste usage only.

class MyMediaOutputImpl : public maxon::Component<MyMediaOutputImpl, MediaOutputInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ResetConverter()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> SetSelectionHandler(const MediaOutputSelectionHandler& selectionHandler)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD const MediaOutputSelectionHandler& GetSelectionHandler() const
	{
		return HXXRET3(NULLIMPL, const MediaOutputSelectionHandler&);
	}

	MAXON_METHOD Result<SELECTIONHANDLERRESULT> CallSelectionHandler(const MediaStreamRef& stream, const MediaStreamFormat& props)
	{
		return HXXRET1(NULLIMPL);
	}

};

class MyMediaOutputTextureImpl : public maxon::Component<MyMediaOutputTextureImpl, MediaOutputTextureInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetOutputTexture(const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass)
	{
		return HXXRET1(NULLIMPL);
	}

};

class MyMediaOutputUrlImpl : public maxon::Component<MyMediaOutputUrlImpl, MediaOutputUrlInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Url GetOutputUrl() const
	{
		return HXXRET3(NULLIMPL, Url);
	}

	MAXON_METHOD Result<void> SetOutputUrl(const Url& url)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD const FileFormat& GetFileFormat() const
	{
		return HXXRET3(NULLIMPL, const FileFormat&);
	}

	MAXON_METHOD Result<Bool> EditSystemOptions(DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<DrawDimensionInt> CheckBitmapSize(const DataDictionary& settings, const DrawDimensionInt& bitmapSize) const
	{
		return HXXRET1(NULLIMPL);
	}

};
