// This file contains decorator implementations for the interfaces of decorator.h. They are intended for copy&paste usage only.

class DecoratorDecoratorImpl : public maxon::Component<DecoratorDecoratorImpl, DecoratorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD ObjectRef PrivateGetDecoratedObject() const
	{
		return maxon::Cast<DecoratorRef>(self.GetDecoratedObject()).PrivateGetDecoratedObject();
	}

};

class EagerDecoratorDecoratorImpl : public maxon::Component<EagerDecoratorDecoratorImpl, EagerDecoratorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD void PrivateSetDecoratedObject(const ObjectRef& object)
	{
		return maxon::Cast<EagerDecoratorRef>(self.GetDecoratedObject()).PrivateSetDecoratedObject(object);
	}

	MAXON_METHOD void PrivateSetDecoratedObject(ObjectRef&& object)
	{
		return maxon::Cast<EagerDecoratorRef>(self.GetDecoratedObject()).PrivateSetDecoratedObject(std::forward<ObjectRef>(object));
	}

};

class WeakDecoratorDecoratorImpl : public maxon::Component<WeakDecoratorDecoratorImpl, WeakDecoratorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD void PrivateSetDecoratedObject(const ObjectRef& object)
	{
		return maxon::Cast<WeakDecoratorRef>(self.GetDecoratedObject()).PrivateSetDecoratedObject(object);
	}

};
