// This file contains default implementations for the interfaces of mediasession_base.h. They are intended for copy&paste usage only.

class MyMediaBaseImpl : public maxon::Component<MyMediaBaseImpl, MediaBaseInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ConnectToSession(const MediaSessionRef& session)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD MediaSessionRef GetSession() const
	{
		return maxon::PrivateIncompleteNullReturnValue<MediaSessionRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};
