// This file contains default implementations for the interfaces of mediasession_output.h. They are intended for copy&paste usage only.

class MyMediaOutputImpl : public maxon::Component<MyMediaOutputImpl, MediaOutputInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ResetConverter()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> SetSelectionHandler(const MediaOutputSelectionHandler& selectionHandler)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD const MediaOutputSelectionHandler& GetSelectionHandler() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const MediaOutputSelectionHandler&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<SELECTIONHANDLERRESULT> CallSelectionHandler(const MediaStreamRef& stream, const MediaStreamFormat& props)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};

class MyMediaOutputTextureImpl : public maxon::Component<MyMediaOutputTextureImpl, MediaOutputTextureInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetOutputTexture(const ImageTextureRef& textureRef, const Class<ImagePixelStorage>& pixelStorageClass)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};

class MyMediaOutputUrlImpl : public maxon::Component<MyMediaOutputUrlImpl, MediaOutputUrlInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Url GetOutputUrl() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<void> SetOutputUrl(const Url& url)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD const FileFormat& GetFileFormat() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const FileFormat&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<Bool> EditSystemOptions(DataDictionary& settings, const Delegate<Result<void*>()>& getParentwindowHandle)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<DrawDimensionInt> CheckBitmapSize(const DataDictionary& settings, const DrawDimensionInt& bitmapSize) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
