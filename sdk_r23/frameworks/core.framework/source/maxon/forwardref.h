#ifndef FORWARDREF_H__
#define FORWARDREF_H__

#include "maxon/objectbase.h"

namespace maxon
{

template <typename T> class ForwardRef
{
public:
	using IsForwardRef = T;

	ForwardRef() = default;
	MAXON_IMPLICIT ForwardRef(const T& t) : _value(t.GetBaseRef()) {}
	MAXON_IMPLICIT ForwardRef(T&& t) : _value(std::move(t.GetBaseRef())) {}

	ForwardRef& operator = (const T& t) { _value = t.GetBaseRef(); return *this; }
	ForwardRef& operator = (T&& t) { _value = std::move(t.GetBaseRef()); return *this; }
	ForwardRef& operator = (std::nullptr_t) { _value = nullptr; return *this; }

	operator const T& () const { return (const T&)_value; }
	operator T& () { return (T&)_value; }

	explicit operator Bool() const { return _value != nullptr; }

	const T& Get() const { return (const T&)_value; }
	T& Get() { return (T&)_value; }

private:
	StrongRef<const ObjectInterface> _value;
};

}

#endif // FORWARDREF_H__
