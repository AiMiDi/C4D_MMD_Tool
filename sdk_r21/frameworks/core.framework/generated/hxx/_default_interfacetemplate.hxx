// This file contains default implementations for the interfaces of interfacetemplate.h. They are intended for copy&paste usage only.

class MyNumberBaseImpl : public maxon::Component<MyNumberBaseImpl, NumberBaseInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD NumberBaseRef<> GenericMul(const NumberBaseRef<>& x) const
	{
		return maxon::PrivateNullReturnValue<NumberBaseRef<>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};

class MyNumberImpl : public maxon::Component<MyNumberImpl, NumberInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD T Get1() const
	{
		return maxon::PrivateNullReturnValue<T>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void Set(typename IntType<X>::type number, const T& v)
	{
		return maxon::PrivateLogNullptrError();
	}

};

class MyNumber2Impl : public maxon::Component<MyNumber2Impl, Number2Interface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD T Get2() const
	{
		return maxon::PrivateNullReturnValue<T>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};
