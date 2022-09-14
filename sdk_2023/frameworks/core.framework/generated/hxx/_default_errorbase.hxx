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

class MyIllegalArgumentErrorImpl : public maxon::Component<MyIllegalArgumentErrorImpl, IllegalArgumentErrorInterface>
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

class MyUnexpectedErrorImpl : public maxon::Component<MyUnexpectedErrorImpl, UnexpectedErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyOperationCancelledErrorImpl : public maxon::Component<MyOperationCancelledErrorImpl, OperationCancelledErrorInterface>
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
