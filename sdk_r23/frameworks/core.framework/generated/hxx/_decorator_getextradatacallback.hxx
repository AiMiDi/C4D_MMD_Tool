// This file contains decorator implementations for the interfaces of getextradatacallback.h. They are intended for copy&paste usage only.

class GetExtraDataCallbackDecoratorImpl : public maxon::Component<GetExtraDataCallbackDecoratorImpl, GetExtraDataCallbackInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<DelegateBase> GetExtraDataMessage(const Id& cmdId)
	{
		return maxon::Cast<GetExtraDataCallbackRef>(self.GetDecoratedObject()).GetExtraDataMessage(cmdId);
	}

};
