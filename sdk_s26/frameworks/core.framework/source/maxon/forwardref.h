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
	explicit ForwardRef(const ObjectInterface* ptr) : _value(ptr) {}

	ForwardRef& operator =(const T& t) { _value = t.GetBaseRef(); return *this; }
	ForwardRef& operator =(T&& t) { _value = std::move(t.GetBaseRef()); return *this; }
	ForwardRef& operator =(std::nullptr_t) { _value = nullptr; return *this; }

	// Don't allow conversion from a temporary to an l-value, this would create invalid references for code like "const XRef& x = Func();" when Func returns ForwardRef<XRef>.
	operator T() && { return std::move(reinterpret_cast<T&>(_value)); }

	// Also we can't add this conversion function. GCC tries to use it and complains when a temporary ForwardRef is converted to const T&.
	// operator T&() & { return reinterpret_cast<T&>(_value); }

	explicit operator Bool() const { return _value != nullptr; }

	const T& Get() const { return reinterpret_cast<const T&>(_value); }
	T& Get() { return reinterpret_cast<T&>(_value); }

	HashInt GetHashCode() const
	{
		return _value.GetHashCode();
	}

	Bool operator ==(const ForwardRef& other) const
	{
		return _value == other._value;
	}

	Bool operator !=(const ForwardRef& other) const
	{
		return _value != other._value;
	}

	Bool operator ==(std::nullptr_t) const
	{
		return _value == nullptr;
	}

	Bool operator !=(std::nullptr_t) const
	{
		return _value != nullptr;
	}

	const ObjectInterface* GetPointer() const
	{
		return _value;
	}

private:
	StrongRef<const ObjectInterface> _value;
};

template <typename T> class IsObjectReferenceClass<ForwardRef<T>> : public std::true_type
{
};

template <typename T> class IsObjectReferenceClass<ForwardRef<T>&> : public std::true_type
{
};

template <typename T> class IsObjectReferenceClass<ForwardRef<T>&&> : public std::true_type
{
};

template <typename T> class IsObjectReferenceClass<const ForwardRef<T>&> : public std::true_type
{
};

template <typename T, typename BASE> class ForwardRefWithExtraBase : public ForwardRef<T>
{
public:
	using Super = ForwardRef<T>;

	ForwardRefWithExtraBase() = default;
	MAXON_IMPLICIT ForwardRefWithExtraBase(const T& t) : Super(t) {}
	MAXON_IMPLICIT ForwardRefWithExtraBase(T&& t) : Super(std::move(t)) {}
	explicit ForwardRefWithExtraBase(const ObjectInterface* ptr) : Super(ptr) {}

	MAXON_IMPLICIT ForwardRefWithExtraBase(const Super& t) : Super(t) {}
	MAXON_IMPLICIT ForwardRefWithExtraBase(Super&& t) : Super(std::move(t)) {}

	operator BASE() && { return std::move(reinterpret_cast<BASE&>(*this)); }

	const BASE& GetBase() const { return reinterpret_cast<const BASE&>(*this); }
	BASE& GetBase() { return reinterpret_cast<BASE&>(*this); }
};

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(ForwardRef<T>**, OverloadRank0)
{
	return GetDataType<typename SFINAEHelper<ObjectRef, T>::type>();
}

}

#endif // FORWARDREF_H__
