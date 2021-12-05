// This file contains default implementations for the interfaces of errorbase.h. They are intended for copy&paste usage only.

class MyOutOfMemoryErrorImpl : public Component<MyOutOfMemoryErrorImpl, OutOfMemoryErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyFunctionNotImplementedErrorImpl : public Component<MyFunctionNotImplementedErrorImpl, FunctionNotImplementedErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyUnresolvedErrorImpl : public Component<MyUnresolvedErrorImpl, UnresolvedErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyUnsupportedOperationErrorImpl : public Component<MyUnsupportedOperationErrorImpl, UnsupportedOperationErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyThreadCancelledErrorImpl : public Component<MyThreadCancelledErrorImpl, ThreadCancelledErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyIllegalArgumentErrorImpl : public Component<MyIllegalArgumentErrorImpl, IllegalArgumentErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyUnsupportedArgumentErrorImpl : public Component<MyUnsupportedArgumentErrorImpl, UnsupportedArgumentErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyNullptrErrorImpl : public Component<MyNullptrErrorImpl, NullptrErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyIllegalStateErrorImpl : public Component<MyIllegalStateErrorImpl, IllegalStateErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyUnknownErrorImpl : public Component<MyUnknownErrorImpl, UnknownErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyShutdownErrorImpl : public Component<MyShutdownErrorImpl, ShutdownErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyUnexpectedErrorImpl : public Component<MyUnexpectedErrorImpl, UnexpectedErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyErrnoErrorImpl : public Component<MyErrnoErrorImpl, ErrnoErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyUnregisteredDataTypeErrorImpl : public Component<MyUnregisteredDataTypeErrorImpl, UnregisteredDataTypeErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyAggregatedErrorImpl : public Component<MyAggregatedErrorImpl, AggregatedErrorInterface>
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
