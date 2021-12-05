// This file contains default implementations for the interfaces of ask_password.h. They are intended for copy&paste usage only.

class MyAskPasswordImpl : public Component<MyAskPasswordImpl, AskPasswordInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<String> AskPasswordFromUser(const String& text) const
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
