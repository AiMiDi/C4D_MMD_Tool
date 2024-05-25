// This file contains default implementations for the interfaces of mediasession_audiodata.h. They are intended for copy&paste usage only.

class MyMediaStreamAudioDataExportImpl : public maxon::Component<MyMediaStreamAudioDataExportImpl, MediaStreamAudioDataExportInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InitWithAudioData(const AudioObjectRef& audioData)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD AudioObjectRef GetAudioObject() const
	{
		return HXXRET3(NULLIMPL, AudioObjectRef);
	}

	MAXON_METHOD Result<void> SetCallbackHandler()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> InitStream(MediaStreamProperties& props)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> FinishStream(const MediaStreamProperties& props)
	{
		return HXXRET1(NULLIMPL);
	}

};
