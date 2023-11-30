// This file contains default implementations for the interfaces of mediasession_base.h. They are intended for copy&paste usage only.

class MyMediaBaseImpl : public maxon::Component<MyMediaBaseImpl, MediaBaseInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ConnectToSession(const MediaSessionRef& session)
	{
		return HXXRET1(NULLIMPL);
	}

	MAXON_METHOD MediaSessionRef GetSession() const
	{
		return HXXRET3(NULLIMPL, MediaSessionRef);
	}

};
