// This file contains decorator implementations for the interfaces of mediasession_audiodata.h. They are intended for copy&paste usage only.

class MediaStreamAudioDataExportDecoratorImpl : public maxon::Component<MediaStreamAudioDataExportDecoratorImpl, MediaStreamAudioDataExportInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InitWithAudioData(const AudioObjectRef& audioData)
	{
		return maxon::Cast<MediaStreamAudioDataExportRef>(self.GetDecoratedObject()).InitWithAudioData(audioData);
	}

	MAXON_METHOD AudioObjectRef GetAudioObject() const
	{
		return maxon::Cast<MediaStreamAudioDataExportRef>(self.GetDecoratedObject()).GetAudioObject();
	}

	MAXON_METHOD Result<void> SetCallbackHandler()
	{
		return maxon::Cast<MediaStreamAudioDataExportRef>(self.GetDecoratedObject()).SetCallbackHandler();
	}

	MAXON_METHOD Result<void> InitStream(MediaStreamProperties& props)
	{
		return maxon::Cast<MediaStreamAudioDataExportRef>(self.GetDecoratedObject()).InitStream(props);
	}

	MAXON_METHOD Result<void> FinishStream(const MediaStreamProperties& props)
	{
		return maxon::Cast<MediaStreamAudioDataExportRef>(self.GetDecoratedObject()).FinishStream(props);
	}

};
