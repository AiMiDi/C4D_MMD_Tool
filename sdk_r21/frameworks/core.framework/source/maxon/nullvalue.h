#ifndef NULLVALUE_H__
#define NULLVALUE_H__

#include "maxon/apibase.h"

/// @file
/// Null value definitions

namespace maxon
{

extern Char g_writableMemory[1024];

template <typename T> struct DefaultNullValue
{
	static const T value;
};

#ifndef MAXON_COMPILER_MSVC //
template <typename T> const T DefaultNullValue<T>::value{};
#else
template <typename T> const T DefaultNullValue<T>::value;
#endif

template <typename T> inline const T& PrivateConstRefNullValue(T*, OverloadRank0)
{
	return IsZeroInitialized<T>::value ? GetZeroRef<T>() : reinterpret_cast<const T&>(DefaultNullValue<typename std::conditional<IsZeroInitialized<T>::value, EmptyClass, T>::type>::value);
}

template <typename T> class NullValueFunctions
{
public:
	using Default = T;
};


template <typename T, T (*f) ()> class NullValueDetector
{
public:
	using type = T;
};

template <typename T> inline const T& PrivateConstRefNullValueHelper(OverloadRank0)
{
	return PrivateConstRefNullValue((T*) nullptr, OVERLOAD_MAX_RANK); // fallback uses argument-dependent lookup to find matching PrivateConstRefNullValue function in T's namespace
}

template <typename T> inline typename NullValueDetector<const T&, &T::NullValue>::type PrivateConstRefNullValueHelper(OverloadRank1)
{
	return T::NullValue();
}

template <typename T> inline typename NullValueDetector<const T&, &T::NullValueRef>::type PrivateConstRefNullValueHelper(OverloadRank2)
{
	return T::NullValueRef();
}

template <typename T> inline T PrivateNullValueHelper(OverloadRank0)
{
	return T();
}

template <typename T> inline typename NullValueDetector<T, &T::NullValue>::type PrivateNullValueHelper(OverloadRank1)
{
	return T::NullValue();
}

template <typename T> inline typename NullValueDetector<const T&, &T::NullValue>::type PrivateNullValueHelper(OverloadRank1)
{
	return T::NullValue();
}

template <typename T> class NullValueZeroInitializedHelper
{
public:
	static T Get()
	{
		return T();
	}
};

template <typename T> class NullValueZeroInitializedHelper<T&>
{
public:
	static T& Get()
	{
		static_assert(AlwaysFalse<T>::value, "There is no null value for a non-const reference.");
		return const_cast<T&>(GetZeroRef<T>());
	}
};

template <typename T> class NullValueZeroInitializedHelper<const T&>
{
public:
	static const T& Get()
	{
		return *(const T*) g_zeroMemory;
	}
};

template <typename T> class NullValueTypeHelper
{
public:
	static T Get()
	{
		return PrivateNullValueHelper<T>(OVERLOAD_MAX_RANK);
	}

	static T IncompleteGet();
};

template <typename T> class NullValueTypeHelper<T&>
{
public:
	static T& Get()
	{
		static_assert(AlwaysFalse<T>::value, "There is no null value for a non-const reference.");
		return const_cast<T&>(GetZeroRef<T>());
	}

	static T& IncompleteGet()
	{
		return Get();
	}
};

template <typename T> class NullValueTypeHelper<const T&>
{
public:
	static const T& Get()
	{
		return PrivateConstRefNullValueHelper<T>(OVERLOAD_MAX_RANK);
	}

	static const T& IncompleteGet();
};

template <typename T> class NullValueFunctionsHelper
{
public:
	static T Get()
	{
		return NullValueFunctions<T>::NullValue();
	}
};

template <typename T> class NullValueFunctionsHelper<T&>
{
public:
	static T& Get()
	{
		static_assert(AlwaysFalse<T>::value, "There is no null value for a non-const reference.");
		return const_cast<T&>(GetZeroRef<T>());
	}
};

template <typename T> class NullValueFunctionsHelper<const T&>
{
public:
	static const T& Get()
	{
		return NullValueFunctions<T>::NullValueRef();
	}
};

template <typename T> inline T PrivateNullValueDispatcher(OverloadRank0)
{
	return NullValueFunctionsHelper<T>::Get();
}

template <typename T> inline typename SFINAEHelper<T, typename NullValueFunctions<typename std::decay<T>::type>::Default>::type PrivateNullValueDispatcher(OverloadRank1)
{
	return NullValueTypeHelper<T>::Get();
}

template <typename T> inline typename std::enable_if<IsZeroInitialized<typename std::decay<T>::type>::value || std::is_same<typename std::decay<T>::type, Generic>::value, T>::type PrivateNullValueDispatcher(OverloadRank2)
{
	return NullValueZeroInitializedHelper<T>::Get();
}


//----------------------------------------------------------------------------------------
/// Returns a null value of type T.
///
/// The null value is defined as follows:
/// - If T is a const reference type const U&:
///  - If U is a scalar type or Generic, the null value is a const reference to a zero-initialized memory.
///  - If there is a specialization of maxon::NullValueFunctions for U,
///    the null value is given by the return value of the NullValueRef function of that specialization.
///  - Otherwise, if U has or inherits a static member function const U& U::NullValueRef() or const U& U::NullValue(),
///    the null value is the return value of that function.
///  - Otherwise, the null value is the return value of PrivateConstRefNullValue((U*) nullptr, OVERLOAD_MAX_RANK) (which is found using argument-dependent lookup).
///    There is a function template PrivateConstRefNullValue<T>(T*, OverloadRank0) in the maxon namespace which returns a reference
///    to a global default-initialized object of type const T.
/// - Otherwise, if T is a non-const reference type U&, a compilation error occurs.
/// - Otherwise T is not a reference type:
///  - If T is a scalar type, the null value is T().
///  - If there is a specialization of maxon::NullValueFunctions for T,
///    the null value is given by the return value of the NullValue function of that specialization.
///  - Otherwise, if T has or inherits a static member function T T::NullValue() or const T& T::NullValue(),
///    the null value is the return value of that function.
///  - Otherwise, the null value is T().
///
/// If you declare a data type T with MAXON_DATATYPE, this will declare helper functions
/// such that NullValue<T>() returns T() and NullValue<const T&>() returns a reference to an object
/// constructed with T().
///
/// @tparam T											Type of the null value. The cases T, T& and const T& are handled differently.
///
/// @note It is necessary to use the fully-qualified name maxon::NullValue if the current scope already
/// contains another NullValue declaration, which is the case for interfaces.
/// @return												A null value of type T.
//----------------------------------------------------------------------------------------
template <typename T> inline T NullValue()
{
	return PrivateNullValueDispatcher<T>(OVERLOAD_MAX_RANK);
}

template <> inline void NullValue<void>()
{
}


template <typename T> class NullValueFunctions<Result<T>>
{
public:
	using ResultMarker = T;
};


enum class NULL_RETURN_REASON
{
	NULLPTR,
	MAKE_WRITABLE_FAILED,
	UNRESOLVED,
	NULLIMPL
} MAXON_ENUM_LIST(NULL_RETURN_REASON);

ThreadReferencedError PrivateGetNullReturnError(NULL_RETURN_REASON reason);

#ifdef MAXON_TARGET_DEBUG
void PrivateLogNullptrError();
Bool PrivateLogNullptrError(Bool result);
#else
inline void PrivateLogNullptrError() { }
inline Bool PrivateLogNullptrError(Bool result) { return result; }
#endif

template <typename T> inline T PrivateNullReturnValue(NULL_RETURN_REASON reason, OverloadRank0)
{
	return NullValueFunctionsHelper<T>::Get();
}

template <typename T> inline typename SFINAEHelper<T, typename NullValueFunctions<typename std::decay<T>::type>::Default>::type PrivateNullReturnValue(NULL_RETURN_REASON reason, OverloadRank1)
{
	return NullValueTypeHelper<T>::Get();
}

template <typename T> inline typename SFINAEHelper<T, typename NullValueFunctions<typename std::decay<T>::type>::ResultMarker>::type PrivateNullReturnValue(NULL_RETURN_REASON reason, OverloadRank2)
{
	return T(PrivateGetNullReturnError((typename SFINAEHelper<NULL_RETURN_REASON, T>::type) reason));
}

template <typename T> inline typename std::enable_if<std::is_same<Id, typename std::decay<T>::type>::value, T>::type PrivateNullReturnValue(NULL_RETURN_REASON reason, OverloadRank3)
{
	return NullValueTypeHelper<T>::Get();
}

template <typename T> inline typename std::enable_if<IsZeroInitialized<typename std::decay<T>::type>::value || std::is_same<typename std::decay<T>::type, Generic>::value, T>::type PrivateNullReturnValue(NULL_RETURN_REASON reason, OverloadRank4)
{
	return NullValueZeroInitializedHelper<T>::Get();
}


template <typename T> inline T PrivateIncompleteNullReturnValue(NULL_RETURN_REASON reason, OverloadRank0)
{
	return NullValueFunctionsHelper<T>::Get();
}

template <typename T> inline typename SFINAEHelper<T, typename NullValueFunctions<typename std::decay<T>::type>::Default>::type PrivateIncompleteNullReturnValue(NULL_RETURN_REASON reason, OverloadRank1)
{
	return NullValueTypeHelper<T>::IncompleteGet();
}

template <typename T> inline typename SFINAEHelper<T, typename NullValueFunctions<typename std::decay<T>::type>::ResultMarker>::type PrivateIncompleteNullReturnValue(NULL_RETURN_REASON reason, OverloadRank2)
{
	return T(PrivateGetNullReturnError((typename SFINAEHelper<NULL_RETURN_REASON, T>::type) reason));
}

template <typename T> inline typename std::enable_if<std::is_same<Id, typename std::decay<T>::type>::value, T>::type PrivateIncompleteNullReturnValue(NULL_RETURN_REASON reason, OverloadRank3)
{
	return NullValueTypeHelper<T>::Get();
}

template <typename T> inline typename std::enable_if<IsZeroInitialized<typename std::decay<T>::type>::value, T>::type PrivateIncompleteNullReturnValue(NULL_RETURN_REASON reason, OverloadRank4)
{
	return NullValueZeroInitializedHelper<T>::Get();
}

} // namespace maxon

#endif // NULLVALUE_H__
