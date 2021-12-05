// This file contains default implementations for the interfaces of mediasession_session.h. They are intended for copy&paste usage only.

class MyMediaSessionImpl : public maxon::Component<MyMediaSessionImpl, MediaSessionInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> Close()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD MediaSessionProgressRef GetProgress() const
	{
		return maxon::PrivateIncompleteNullReturnValue<MediaSessionProgressRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};
