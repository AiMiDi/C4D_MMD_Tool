// This file contains default implementations for the interfaces of valuechangedcallback.h. They are intended for copy&paste usage only.

class MyValueChangedCallbackImpl : public maxon::Component<MyValueChangedCallbackImpl, ValueChangedCallbackInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ValueChangedMessage(const InternedId& id)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
