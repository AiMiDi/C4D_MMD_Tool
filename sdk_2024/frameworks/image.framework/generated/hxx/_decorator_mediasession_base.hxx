// This file contains decorator implementations for the interfaces of mediasession_base.h. They are intended for copy&paste usage only.

class MediaBaseDecoratorImpl : public maxon::Component<MediaBaseDecoratorImpl, MediaBaseInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ConnectToSession(const MediaSessionRef& session)
	{
		return maxon::Cast<MediaBaseRef>(self.GetDecoratedObject()).ConnectToSession(session);
	}

	MAXON_METHOD MediaSessionRef GetSession() const
	{
		return maxon::Cast<MediaBaseRef>(self.GetDecoratedObject()).GetSession();
	}

};
