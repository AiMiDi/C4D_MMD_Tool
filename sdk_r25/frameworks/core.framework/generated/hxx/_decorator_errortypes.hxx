// This file contains decorator implementations for the interfaces of errortypes.h. They are intended for copy&paste usage only.

class UnsupportedArgumentErrorDecoratorImpl : public maxon::Component<UnsupportedArgumentErrorDecoratorImpl, UnsupportedArgumentErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class UnresolvedErrorDecoratorImpl : public maxon::Component<UnresolvedErrorDecoratorImpl, UnresolvedErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class UnknownErrorDecoratorImpl : public maxon::Component<UnknownErrorDecoratorImpl, UnknownErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class UnsupportedOperationErrorDecoratorImpl : public maxon::Component<UnsupportedOperationErrorDecoratorImpl, UnsupportedOperationErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class ShutdownErrorDecoratorImpl : public maxon::Component<ShutdownErrorDecoratorImpl, ShutdownErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class DisabledErrorDecoratorImpl : public maxon::Component<DisabledErrorDecoratorImpl, DisabledErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class ErrnoErrorDecoratorImpl : public maxon::Component<ErrnoErrorDecoratorImpl, ErrnoErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};
