// This file contains decorator implementations for the interfaces of descriptionmessagecallback.h. They are intended for copy&paste usage only.

class DescriptionMessageCallbackDecoratorImpl : public maxon::Component<DescriptionMessageCallbackDecoratorImpl, DescriptionMessageCallbackInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<Tuple<Bool, Bool>> DescriptionMessage(const InternedId& id, const Id& cmdId, Int32 type, void* data)
	{
		return maxon::Cast<DescriptionMessageCallbackRef>(self.GetDecoratedObject()).DescriptionMessage(id, cmdId, type, data);
	}

};
