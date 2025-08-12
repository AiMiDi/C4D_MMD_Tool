// This file contains default implementations for the interfaces of mediasession_stream.h. They are intended for copy&paste usage only.

class MyMediaStreamImpl : public maxon::Component<MyMediaStreamImpl, MediaStreamInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<BaseArray<Data>> GetFormats() const
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD MediaStreamFormat GetFormat(const Data& formatId) const
	{
		return HXXRET3(NULLIMPL, MediaStreamFormat);
	}

	MAXON_METHOD const Data& GetSelectedFormat() const
	{
		return HXXRET3(NULLIMPL, const Data&);
	}

	MAXON_METHOD Result<void> SetSelectedFormat(const Data& formatId)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> AddFormat(const Data& formatId, const MediaStreamFormat& ref)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> SubscribeStream(const Data& formatId)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> UnsubscribeStream()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Bool IsSubscribed() const
	{
		return maxon::PrivateLogNullptrError(false);
	}

};

class MyMediaStreamExifDataImpl : public maxon::Component<MyMediaStreamExifDataImpl, MediaStreamExifDataInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetCallbackHandler(const ExifDataHandler& handleExifData)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> HandleExifData(const ExifRef& exifData)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> FinishStream(const MediaStreamProperties& props)
	{
		return HXXRET1(NULLIMPL);
	}

};

class MyMediaStreamImageBaseImpl : public maxon::Component<MyMediaStreamImageBaseImpl, MediaStreamImageBaseInterface>
{
	MAXON_COMPONENT();

public:
};

class MyMediaStreamImageDataImportImpl : public maxon::Component<MyMediaStreamImageDataImportImpl, MediaStreamImageDataImportInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetCallbackHandler(const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> InitStream(const MediaStreamProperties& props)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<SetPixelHandlerStruct> SetPixelStream(const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> FinishStream(const MediaStreamProperties& props)
	{
		return HXXRET1(NULLIMPL);
	}

};

class MyMediaStreamImageDataExportImpl : public maxon::Component<MyMediaStreamImageDataExportImpl, MediaStreamImageDataExportInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetCallbackHandler(const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> InitStream(MediaStreamProperties& props)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<GetPixelHandlerStruct> GetPixelStream(const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> FinishStream(const MediaStreamProperties& props)
	{
		return HXXRET1(NULLIMPL);
	}

};

class MyMediaStreamImageDataForwardImportImpl : public maxon::Component<MyMediaStreamImageDataForwardImportImpl, MediaStreamImageDataForwardImportInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetSourceStream(const MediaStreamImageDataImportRef& sourceStream)
	{
		return HXXRET1(NULLIMPL);
	}

};

class MyMediaStreamAudioDataImportImpl : public maxon::Component<MyMediaStreamAudioDataImportImpl, MediaStreamAudioDataImportInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetCallbackHandler(const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> InitStream(MediaStreamProperties& props)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<SetAudioDataCallbackType> SetAudioDataCallback(MediaStreamProperties& props)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> FinishStream(const MediaStreamProperties& props)
	{
		return HXXRET1(NULLIMPL);
	}

};
