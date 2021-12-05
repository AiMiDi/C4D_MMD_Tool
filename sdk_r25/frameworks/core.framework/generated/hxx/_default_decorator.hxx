// This file contains default implementations for the interfaces of decorator.h. They are intended for copy&paste usage only.

class MyDecoratorImpl : public maxon::Component<MyDecoratorImpl, DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD ObjectRef PrivateGetDecoratedObject() const
	{
		return maxon::PrivateIncompleteNullReturnValue<ObjectRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};

class MyEagerDecoratorImpl : public maxon::Component<MyEagerDecoratorImpl, EagerDecoratorInterface>
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

class MyWeakDecoratorImpl : public maxon::Component<MyWeakDecoratorImpl, WeakDecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD void PrivateSetDecoratedObject(const ObjectRef& object)
	{
		return maxon::PrivateLogNullptrError();
	}

};
