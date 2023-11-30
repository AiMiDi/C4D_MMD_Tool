// This file contains decorator implementations for the interfaces of mediasession_stream.h. They are intended for copy&paste usage only.

class MediaStreamDecoratorImpl : public maxon::Component<MediaStreamDecoratorImpl, MediaStreamInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<BaseArray<Data>> GetFormats() const
	{
		return maxon::Cast<MediaStreamRef>(self.GetDecoratedObject()).GetFormats();
	}

	MAXON_METHOD MediaStreamFormat GetFormat(const Data& formatId) const
	{
		return maxon::Cast<MediaStreamRef>(self.GetDecoratedObject()).GetFormat(formatId);
	}

	MAXON_METHOD const Data& GetSelectedFormat() const
	{
		return maxon::Cast<MediaStreamRef>(self.GetDecoratedObject()).GetSelectedFormat();
	}

	MAXON_METHOD Result<void> SetSelectedFormat(const Data& formatId)
	{
		return maxon::Cast<MediaStreamRef>(self.GetDecoratedObject()).SetSelectedFormat(formatId);
	}

	MAXON_METHOD Result<void> AddFormat(const Data& formatId, const MediaStreamFormat& ref)
	{
		return maxon::Cast<MediaStreamRef>(self.GetDecoratedObject()).AddFormat(formatId, ref);
	}

	MAXON_METHOD Result<void> SubscribeStream(const Data& formatId)
	{
		return maxon::Cast<MediaStreamRef>(self.GetDecoratedObject()).SubscribeStream(formatId);
	}

	MAXON_METHOD Result<void> UnsubscribeStream()
	{
		return maxon::Cast<MediaStreamRef>(self.GetDecoratedObject()).UnsubscribeStream();
	}

	MAXON_METHOD Bool IsSubscribed() const
	{
		return maxon::Cast<MediaStreamRef>(self.GetDecoratedObject()).IsSubscribed();
	}

};

class MediaStreamExifDataDecoratorImpl : public maxon::Component<MediaStreamExifDataDecoratorImpl, MediaStreamExifDataInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetCallbackHandler(const ExifDataHandler& handleExifData)
	{
		return maxon::Cast<MediaStreamExifDataRef>(self.GetDecoratedObject()).SetCallbackHandler(handleExifData);
	}

	MAXON_METHOD Result<void> HandleExifData(const ExifRef& exifData)
	{
		return maxon::Cast<MediaStreamExifDataRef>(self.GetDecoratedObject()).HandleExifData(exifData);
	}

	MAXON_METHOD Result<void> FinishStream(const MediaStreamProperties& props)
	{
		return maxon::Cast<MediaStreamExifDataRef>(self.GetDecoratedObject()).FinishStream(props);
	}

};

class MediaStreamImageBaseDecoratorImpl : public maxon::Component<MediaStreamImageBaseDecoratorImpl, MediaStreamImageBaseInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class MediaStreamImageDataImportDecoratorImpl : public maxon::Component<MediaStreamImageDataImportDecoratorImpl, MediaStreamImageDataImportInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetCallbackHandler(const InitHandler& initHandler, const SetPixelHandler& setPixelHandler, const FinishHandler& finishHandler)
	{
		return maxon::Cast<MediaStreamImageDataImportRef>(self.GetDecoratedObject()).SetCallbackHandler(initHandler, setPixelHandler, finishHandler);
	}

	MAXON_METHOD Result<void> InitStream(const MediaStreamProperties& props)
	{
		return maxon::Cast<MediaStreamImageDataImportRef>(self.GetDecoratedObject()).InitStream(props);
	}

	MAXON_METHOD Result<SetPixelHandlerStruct> SetPixelStream(const MediaStreamProperties& props, const ChannelOffsets& srcChannelOffsets, SETPIXELHANDLERFLAGS setPixelFlags)
	{
		return maxon::Cast<MediaStreamImageDataImportRef>(self.GetDecoratedObject()).SetPixelStream(props, srcChannelOffsets, setPixelFlags);
	}

	MAXON_METHOD Result<void> FinishStream(const MediaStreamProperties& props)
	{
		return maxon::Cast<MediaStreamImageDataImportRef>(self.GetDecoratedObject()).FinishStream(props);
	}

};

class MediaStreamImageDataExportDecoratorImpl : public maxon::Component<MediaStreamImageDataExportDecoratorImpl, MediaStreamImageDataExportInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetCallbackHandler(const InitHandler& initHandler, const GetPixelHandler& getPixelHandler, const FinishHandler& finishHandler)
	{
		return maxon::Cast<MediaStreamImageDataExportRef>(self.GetDecoratedObject()).SetCallbackHandler(initHandler, getPixelHandler, finishHandler);
	}

	MAXON_METHOD Result<void> InitStream(MediaStreamProperties& props)
	{
		return maxon::Cast<MediaStreamImageDataExportRef>(self.GetDecoratedObject()).InitStream(props);
	}

	MAXON_METHOD Result<GetPixelHandlerStruct> GetPixelStream(const MediaStreamProperties& props, const PixelFormat& dstFormat, const ChannelOffsets& channelOffsets, const ColorProfile& dstColorProfile, GETPIXELHANDLERFLAGS flags)
	{
		return maxon::Cast<MediaStreamImageDataExportRef>(self.GetDecoratedObject()).GetPixelStream(props, dstFormat, channelOffsets, dstColorProfile, flags);
	}

	MAXON_METHOD Result<void> FinishStream(const MediaStreamProperties& props)
	{
		return maxon::Cast<MediaStreamImageDataExportRef>(self.GetDecoratedObject()).FinishStream(props);
	}

};

class MediaStreamImageDataForwardImportDecoratorImpl : public maxon::Component<MediaStreamImageDataForwardImportDecoratorImpl, MediaStreamImageDataForwardImportInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetSourceStream(const MediaStreamImageDataImportRef& sourceStream)
	{
		return maxon::Cast<MediaStreamImageDataForwardImportRef>(self.GetDecoratedObject()).SetSourceStream(sourceStream);
	}

};

class MediaStreamAudioDataImportDecoratorImpl : public maxon::Component<MediaStreamAudioDataImportDecoratorImpl, MediaStreamAudioDataImportInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> SetCallbackHandler(const InitHandler& initHandler, const SetAudioDataHandler& getAudioDataHandler, const FinishHandler& finishHandler)
	{
		return maxon::Cast<MediaStreamAudioDataImportRef>(self.GetDecoratedObject()).SetCallbackHandler(initHandler, getAudioDataHandler, finishHandler);
	}

	MAXON_METHOD Result<void> InitStream(MediaStreamProperties& props)
	{
		return maxon::Cast<MediaStreamAudioDataImportRef>(self.GetDecoratedObject()).InitStream(props);
	}

	MAXON_METHOD Result<SetAudioDataCallbackType> SetAudioDataCallback(MediaStreamProperties& props)
	{
		return maxon::Cast<MediaStreamAudioDataImportRef>(self.GetDecoratedObject()).SetAudioDataCallback(props);
	}

	MAXON_METHOD Result<void> FinishStream(const MediaStreamProperties& props)
	{
		return maxon::Cast<MediaStreamAudioDataImportRef>(self.GetDecoratedObject()).FinishStream(props);
	}

};
