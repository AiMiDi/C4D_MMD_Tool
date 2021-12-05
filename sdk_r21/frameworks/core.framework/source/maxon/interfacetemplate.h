#ifndef INTERFACETEMPLATE_H__
#define INTERFACETEMPLATE_H__

#include "maxon/iostreams.h"

namespace maxon
{

template <typename INTERFACE> class GenericRef;

class NumberBaseInterface;
template <typename K = GenericRef<NumberBaseInterface>, Bool B = false> class NumberBaseRef;

template <typename TO, typename FROM> struct SpecialOut
{
	static const Bool value = std::is_constructible<TO, FROM>::value;
};

template <typename TO, typename FROM> struct SpecialOut<GenericRef<TO>, FROM>
{
	static const Bool value = true;
};

class NumberBaseInterface : MAXON_INTERFACE_BASES(ObjectInterface)
{
	MAXON_INTERFACE(NumberBaseInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.numberbase");
	MAXON_GENERIC((SpecialOut) typename K = GenericRef<NumberBaseInterface>);
	MAXON_GENERIC(Bool B = false);

public:
	template <typename K> MAXON_FUNCTION K Mul(const K& x) const
	{
		return AssertCast<K>(GenericMul(x));
	}

protected:
	MAXON_METHOD NumberBaseRef<> GenericMul(const NumberBaseRef<>& x) const;
};

template <typename T, Int X> class NumberInterface;
template <typename T, Int X, typename K = GenericRef<NumberInterface<T, X>>> class NumberRef;

template <typename T, Int X> class NumberInterface : MAXON_INTERFACE_BASES(NumberBaseInterface<K, false>, ErrorInterface)
{
	MAXON_INTERFACE(NumberInterface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.number");
	MAXON_GENERIC((SpecialOut) typename K = GenericRef<NumberInterface>);
	MAXON_INTERFACE_SINGLE_IMPLEMENTATION;

public:
	MAXON_METHOD T Get1() const;

	static MAXON_METHOD Result<NumberRef<T, X>> Create(T a, typename IntType<X>::type number);

	MAXON_METHOD void Set(typename IntType<X>::type number, const T& v);
};

template <typename T> class Number2Interface : MAXON_INTERFACE_BASES(NumberInterface<T, 4, T>, NumberBaseInterface<T>)
{
	MAXON_INTERFACE(Number2Interface, MAXON_REFERENCE_NORMAL, "net.maxon.interface.number2");
	MAXON_INTERFACE_SINGLE_IMPLEMENTATION;
public:
	static MAXON_METHOD Result<Int> Func(T a);

	MAXON_METHOD T Get2() const;
};

#include "interfacetemplate1.hxx"

MAXON_INTERFACE_INSTANTIATION(NumberInterface<Int, 4>, "int");
MAXON_INTERFACE_INSTANTIATION(Number2Interface<Int>, "int");

MAXON_DECLARATION(MAXON_MACROARG_TYPE(Class<NumberRef<Int, 4>>), IntNumberClass, "net.maxon.class.number.int");

#include "interfacetemplate2.hxx"

} // namespace maxon



#endif // INTERFACETEMPLATE_H__
