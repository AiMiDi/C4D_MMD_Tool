// This file contains default implementations for the interfaces of errorbase.h. They are intended for copy&paste usage only.

class MyOutOfMemoryErrorImpl : public maxon::Component<MyOutOfMemoryErrorImpl, OutOfMemoryErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyFunctionNotImplementedErrorImpl : public maxon::Component<MyFunctionNotImplementedErrorImpl, FunctionNotImplementedErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyUnresolvedErrorImpl : public maxon::Component<MyUnresolvedErrorImpl, UnresolvedErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyUnsupportedOperationErrorImpl : public maxon::Component<MyUnsupportedOperationErrorImpl, UnsupportedOperationErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyThreadCancelledErrorImpl : public maxon::Component<MyThreadCancelledErrorImpl, ThreadCancelledErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyIllegalArgumentErrorImpl : public maxon::Component<MyIllegalArgumentErrorImpl, IllegalArgumentErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyUnsupportedArgumentErrorImpl : public maxon::Component<MyUnsupportedArgumentErrorImpl, UnsupportedArgumentErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyNullptrErrorImpl : public maxon::Component<MyNullptrErrorImpl, NullptrErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyIllegalStateErrorImpl : public maxon::Component<MyIllegalStateErrorImpl, IllegalStateErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyUnknownErrorImpl : public maxon::Component<MyUnknownErrorImpl, UnknownErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyShutdownErrorImpl : public maxon::Component<MyShutdownErrorImpl, ShutdownErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyUnexpectedErrorImpl : public maxon::Component<MyUnexpectedErrorImpl, UnexpectedErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyDisabledErrorImpl : public maxon::Component<MyDisabledErrorImpl, DisabledErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyErrnoErrorImpl : public maxon::Component<MyErrnoErrorImpl, ErrnoErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyUnregisteredDataTypeErrorImpl : public maxon::Component<MyUnregisteredDataTypeErrorImpl, UnregisteredDataTypeErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyAggregatedErrorImpl : public maxon::Component<MyAggregatedErrorImpl, AggregatedErrorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Bool AddError(const Error& error)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool AddError(Error&& error)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Int GetCount() const
	{
		return 0;
	}

	MAXON_METHOD const Error& GetError(Int index) const
	{
		return maxon::PrivateIncompleteNullReturnValue<const Error&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};
