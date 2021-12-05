// This file contains decorator implementations for the interfaces of genericfunction.h. They are intended for copy&paste usage only.

class FunctionDecoratorImpl : public maxon::Component<FunctionDecoratorImpl, FunctionInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const FunctionDataType& GetFunctionType() const
	{
		return maxon::Cast<GenericFunction>(self.GetDecoratedObject()).GetFunctionType();
	}

	MAXON_METHOD Result<void> Invoke(GenericSingletonContainerInterface* outputs, GenericSingletonContainerInterface* inputs) const
	{
		return maxon::Cast<GenericFunction>(self.GetDecoratedObject()).Invoke(outputs, inputs);
	}

	MAXON_METHOD Result<void> Invoke(GenericSingletonContainerInterface* outputs, GenericSingletonContainerInterface* inputs, Data& cacheData) const
	{
		return maxon::Cast<GenericFunction>(self.GetDecoratedObject()).Invoke(outputs, inputs, cacheData);
	}

	MAXON_METHOD ConstDataPtr GetConstantValue(const Member& output) const
	{
		return maxon::Cast<GenericFunction>(self.GetDecoratedObject()).GetConstantValue(output);
	}

};
