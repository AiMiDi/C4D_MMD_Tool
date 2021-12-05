// This file contains default implementations for the interfaces of factory.h. They are intended for copy&paste usage only.

class MyFactoryImpl : public maxon::Component<MyFactoryImpl, FactoryInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const DelegateBase* PrivateGetDelegate() const
	{
		return nullptr;
	}

};
