// This file contains default implementations for the interfaces of descriptionmessagecallback.h. They are intended for copy&paste usage only.

class MyDescriptionMessageCallbackImpl : public maxon::Component<MyDescriptionMessageCallbackImpl, DescriptionMessageCallbackInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Tuple<Bool, Bool>> DescriptionMessage(const InternedId& id, const Id& cmdId, Int32 type, void* data)
	{
		return HXXRET1(NULLIMPL);
	}

};
