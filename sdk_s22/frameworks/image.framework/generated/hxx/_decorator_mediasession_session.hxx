// This file contains decorator implementations for the interfaces of mediasession_session.h. They are intended for copy&paste usage only.

class MediaSessionDecoratorImpl : public maxon::Component<MediaSessionDecoratorImpl, MediaSessionInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output)
	{
		return maxon::Cast<MediaSessionRef>(self.GetDecoratedObject()).ConnectMediaConverter(input, output);
	}

	MAXON_METHOD Result<void> Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags)
	{
		return maxon::Cast<MediaSessionRef>(self.GetDecoratedObject()).Convert(targetTime, flags);
	}

	MAXON_METHOD Result<void> Close()
	{
		return maxon::Cast<MediaSessionRef>(self.GetDecoratedObject()).Close();
	}

	MAXON_METHOD MediaSessionProgressRef GetProgress() const
	{
		return maxon::Cast<MediaSessionRef>(self.GetDecoratedObject()).GetProgress();
	}

};
