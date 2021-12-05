// This file contains default implementations for the interfaces of decorator.h. They are intended for copy&paste usage only.

class MyDecoratorImpl : public Component<MyDecoratorImpl, DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD const ObjectRef& PrivateGetDecoratedObject() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const ObjectRef&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};

class MyEagerDecoratorImpl : public Component<MyEagerDecoratorImpl, EagerDecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD void PrivateSetDecoratedObject(const ObjectRef& object)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void PrivateSetDecoratedObject(ObjectRef&& object)
	{
		return maxon::PrivateLogNullptrError();
	}

};
