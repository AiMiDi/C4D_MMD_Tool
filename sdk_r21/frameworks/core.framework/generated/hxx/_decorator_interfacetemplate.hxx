// This file contains decorator implementations for the interfaces of interfacetemplate.h. They are intended for copy&paste usage only.

class NumberBaseDecoratorImpl : public maxon::Component<NumberBaseDecoratorImpl, NumberBaseInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD NumberBaseRef<> GenericMul(const NumberBaseRef<>& x) const
	{
		return maxon::Cast<NumberBaseRef>(self.GetDecoratedObject()).GenericMul(x);
	}

};

class NumberDecoratorImpl : public maxon::Component<NumberDecoratorImpl, NumberInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD T Get1() const
	{
		return maxon::Cast<NumberRef>(self.GetDecoratedObject()).Get1();
	}

	MAXON_METHOD void Set(typename IntType<X>::type number, const T& v)
	{
		return maxon::Cast<NumberRef>(self.GetDecoratedObject()).Set(std::forward<typename IntType<X>::type>(number), v);
	}

};

class Number2DecoratorImpl : public maxon::Component<Number2DecoratorImpl, Number2Interface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD T Get2() const
	{
		return maxon::Cast<Number2Ref>(self.GetDecoratedObject()).Get2();
	}

};
