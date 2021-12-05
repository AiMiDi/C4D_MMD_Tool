// This file contains decorator implementations for the interfaces of valuechangedcallback.h. They are intended for copy&paste usage only.

class ValueChangedCallbackDecoratorImpl : public maxon::Component<ValueChangedCallbackDecoratorImpl, ValueChangedCallbackInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> ValueChangedMessage(const InternedId& id)
	{
		return maxon::Cast<ValueChangedCallbackRef>(self.GetDecoratedObject()).ValueChangedMessage(id);
	}

};
