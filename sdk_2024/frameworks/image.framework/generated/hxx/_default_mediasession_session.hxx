// This file contains default implementations for the interfaces of mediasession_session.h. They are intended for copy&paste usage only.

class MyMediaSessionImpl : public maxon::Component<MyMediaSessionImpl, MediaSessionInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD Result<void> Close()
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD ProgressRef GetProgress() const
	{
		return HXXRET3(NULLIMPL, ProgressRef);
	}

};
