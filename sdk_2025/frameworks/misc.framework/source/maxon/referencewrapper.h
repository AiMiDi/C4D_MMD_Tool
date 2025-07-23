#ifndef REFERENCEWRAPPER_H__
#define REFERENCEWRAPPER_H__

#include "maxon/apibase.h"

namespace maxon
{
//----------------------------------------------------------------------------------------
/// Wraps a pointer, but enforces reference semantics for assignment and hence cannot be null. Can be used just like a normal pointer (e.g. operator -> to call methods). However, even if it works, the use of operator * is discouraged and reference semantics should be used instead.
/// Note that a ReferenceWrapper instance can be converted implicitly to a reference or a pointer of the same type (but not the other way around!).
/// Similar in function to std::reference_wrapper<TYPE>.
///
/// @code
/// Float value1 = 5.0;
/// Float value2 = 10.0;
/// 
/// ReferenceWrapper<Float> valueRef;								// Doesn't compile! A reference cannot be null.
/// ReferenceWrapper<Float> valueRef = value1;			// Doesn't compile! To improve readability, implicit conversions are disabled and an explicit call to Ref or CRef functions is enforced (as opposed to std::reference_wrapper<TYPE>).
/// ReferenceWrapper<Float> valueRef = Ref(value1); // valueRef now points to value1
/// ReferenceWrapper<Float> valueRef(Ref(value1));	// valueRef now points to value1 (equivalent to the previous statement)
/// 
/// valueRef = 0.0;					// value1 now equals 0.0
/// valueRef = value2;			// value1 now equals 10.0
/// valueRef = Ref(value2); // valueRef now points to value2
/// valueRef = 0.0;					// value2 now equals 0.0
/// *valueRef = 5.0;				// value2 now equals 5.0. Works, but isn't recommended, because valueRef now looks like a pointer.
/// @endcode 
//----------------------------------------------------------------------------------------
template <typename TYPE> class ReferenceWrapper
{
	// Constructors (private to enforce the use of Ref and CRef functions)
	MAXON_IMPLICIT ReferenceWrapper(TYPE& ref) noexcept : _ptr(std::addressof(ref)) {}
	MAXON_IMPLICIT ReferenceWrapper(TYPE&&) = delete;

public:

	// TODO: (Franz) added a deffault constructor, otherwise HashMap would not compile after the implementation of new copy from.
	// It is needed to have a look with Ole if we can in any ways avoid this problem.
	ReferenceWrapper() = default;

	// Factory methods (used by Ref and CRef functions)
	static ReferenceWrapper<TYPE> Create(TYPE& val) noexcept
	{
		return ReferenceWrapper<TYPE>(val);
	}

	static ReferenceWrapper<const TYPE> CreateConst(TYPE& val) noexcept
	{
		return ReferenceWrapper<const TYPE>(val);
	}

	// Copy and assignment
	ReferenceWrapper(const ReferenceWrapper&) noexcept = default;
	ReferenceWrapper& operator = (const ReferenceWrapper&) noexcept = default;

	//----------------------------------------------------------------------------------------
	/// Used to change the value of the referenced object.
	//----------------------------------------------------------------------------------------
	void operator = (const TYPE& value)
	{
		*_ptr = value;
	}
	
	//----------------------------------------------------------------------------------------
	/// Hash function (for maxon::HashMap compatibility).
	//----------------------------------------------------------------------------------------
	UInt GetHashCode() const
	{
		return maxon::DefaultCompare::GetHashCode(_ptr);
	}

	//----------------------------------------------------------------------------------------
	/// Comparison function (for maxon::HashMap compatibility).
	//----------------------------------------------------------------------------------------
	Bool IsEqual(const ReferenceWrapper& ref) const
	{
		return _ptr == ref._ptr;
	}

	//----------------------------------------------------------------------------------------
	/// Implicit conversion to a raw pointer type. Makes it possible to pass the object directly to functions like @c Function(TYPE* t).
	/// @return												The internal pointer. The AutoAlloc instance owns the pointed object.
	//----------------------------------------------------------------------------------------
	operator TYPE* () const noexcept { return _ptr; }

	//----------------------------------------------------------------------------------------
	/// Implicit conversion to reference type. Makes it possible to pass the object directly to functions like @c Function(TYPE& t).
	/// @return												The dereferenced pointer.
	//----------------------------------------------------------------------------------------
	operator TYPE& () const noexcept { return *_ptr; }

	//----------------------------------------------------------------------------------------
	/// Used for calls like @c referenceWrapper->Function().
	/// @return												The internal pointer.
	//----------------------------------------------------------------------------------------
	TYPE* operator -> () const noexcept { return _ptr; }

	//----------------------------------------------------------------------------------------
	/// Used for expressions like @c &referenceWrapper. Extracts a pointer to the internal pointer.
	/// @note This means that it is impossible to get the address of the actual ReferenceWrapper instance.
	/// @return												A pointer to the internal pointer.
	//----------------------------------------------------------------------------------------
	TYPE** operator & () noexcept { return &_ptr; }

private:
	TYPE* _ptr = nullptr;
};

//----------------------------------------------------------------------------------------
/// Constructs a ReferenceWrapper instance from a reference type.
//----------------------------------------------------------------------------------------
template <typename TYPE> inline ReferenceWrapper<TYPE> Ref(TYPE& val) noexcept
{
	return ReferenceWrapper<TYPE>::Create(val);
}

template <typename TYPE> void Ref(TYPE&& val) = delete;

//----------------------------------------------------------------------------------------
/// Constructs a const ReferenceWrapper instance from a const reference type.
//----------------------------------------------------------------------------------------
template <typename TYPE> inline ReferenceWrapper<const TYPE> CRef(TYPE& val) noexcept
{
	return ReferenceWrapper<const TYPE>::CreateConst(val);
}

template <typename TYPE> void CRef(TYPE&& val) = delete;

} // namespace maxon

#endif // REFERENCEWRAPPER_H__
