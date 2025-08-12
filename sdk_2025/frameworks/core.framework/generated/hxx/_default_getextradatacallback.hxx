// This file contains default implementations for the interfaces of getextradatacallback.h. They are intended for copy&paste usage only.

class MyGetExtraDataCallbackImpl : public maxon::Component<MyGetExtraDataCallbackImpl, GetExtraDataCallbackInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<DelegateBase> GetExtraDataMessage(const Id& cmdId)
	{
		return HXXRET1(NULLIMPL);
	}

};
