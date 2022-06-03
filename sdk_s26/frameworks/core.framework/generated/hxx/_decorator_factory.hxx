// This file contains decorator implementations for the interfaces of factory.h. They are intended for copy&paste usage only.

class FactoryDecoratorImpl : public maxon::Component<FactoryDecoratorImpl, FactoryInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const DelegateBase* PrivateGetDelegate() const
	{
		return maxon::Cast<GenericFactory>(self.GetDecoratedObject()).PrivateGetDelegate();
	}

};
