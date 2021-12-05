// This file contains default implementations for the interfaces of mediasession_audiodata.h. They are intended for copy&paste usage only.

class MyMediaStreamAudioDataExportImpl : public maxon::Component<MyMediaStreamAudioDataExportImpl, MediaStreamAudioDataExportInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> InitWithAudioData(const AudioObjectRef& audioData)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD AudioObjectRef GetAudioObject() const
	{
		return maxon::PrivateIncompleteNullReturnValue<AudioObjectRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<void> SetCallbackHandler()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InitStream(MediaStreamProperties& props)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> FinishStream(const MediaStreamProperties& props)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
