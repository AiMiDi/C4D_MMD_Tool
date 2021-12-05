// This file contains decorator implementations for the interfaces of errorbase.h. They are intended for copy&paste usage only.

class OutOfMemoryErrorDecoratorImpl : public maxon::Component<OutOfMemoryErrorDecoratorImpl, OutOfMemoryErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class FunctionNotImplementedErrorDecoratorImpl : public maxon::Component<FunctionNotImplementedErrorDecoratorImpl, FunctionNotImplementedErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class UnresolvedErrorDecoratorImpl : public maxon::Component<UnresolvedErrorDecoratorImpl, UnresolvedErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class UnsupportedOperationErrorDecoratorImpl : public maxon::Component<UnsupportedOperationErrorDecoratorImpl, UnsupportedOperationErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class ThreadCancelledErrorDecoratorImpl : public maxon::Component<ThreadCancelledErrorDecoratorImpl, ThreadCancelledErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class IllegalArgumentErrorDecoratorImpl : public maxon::Component<IllegalArgumentErrorDecoratorImpl, IllegalArgumentErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class UnsupportedArgumentErrorDecoratorImpl : public maxon::Component<UnsupportedArgumentErrorDecoratorImpl, UnsupportedArgumentErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class NullptrErrorDecoratorImpl : public maxon::Component<NullptrErrorDecoratorImpl, NullptrErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class IllegalStateErrorDecoratorImpl : public maxon::Component<IllegalStateErrorDecoratorImpl, IllegalStateErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class UnknownErrorDecoratorImpl : public maxon::Component<UnknownErrorDecoratorImpl, UnknownErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class ShutdownErrorDecoratorImpl : public maxon::Component<ShutdownErrorDecoratorImpl, ShutdownErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class UnexpectedErrorDecoratorImpl : public maxon::Component<UnexpectedErrorDecoratorImpl, UnexpectedErrorInterface, maxon::DecoratorInterface>
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

class UnregisteredDataTypeErrorDecoratorImpl : public maxon::Component<UnregisteredDataTypeErrorDecoratorImpl, UnregisteredDataTypeErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class AggregatedErrorDecoratorImpl : public maxon::Component<AggregatedErrorDecoratorImpl, AggregatedErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Bool AddError(const Error& error)
	{
		return maxon::Cast<AggregatedError>(self.GetDecoratedObject()).AddError(error);
	}

	MAXON_METHOD Bool AddError(Error&& error)
	{
		return maxon::Cast<AggregatedError>(self.GetDecoratedObject()).AddError(std::forward<Error>(error));
	}

	MAXON_METHOD Int GetCount() const
	{
		return maxon::Cast<AggregatedError>(self.GetDecoratedObject()).GetCount();
	}

	MAXON_METHOD const Error& GetError(Int index) const
	{
		return maxon::Cast<AggregatedError>(self.GetDecoratedObject()).GetError(index);
	}

};
