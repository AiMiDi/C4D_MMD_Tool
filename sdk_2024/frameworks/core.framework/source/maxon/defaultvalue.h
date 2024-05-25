#ifndef DEFAULTVALUE_H__
#define DEFAULTVALUE_H__

#include "maxon/apibase.h"

/// @file
/// Default value definitions

namespace maxon
{

extern Char g_writableMemory[1024];

template <typename T> struct DefaultDefaultValue
{
	static const T value;
};

#if !defined MAXON_COMPILER_MSVC || MAXON_COMPILER_MSVC >= 1928 //
template <typename T> const T DefaultDefaultValue<T>::value{};
#else
template <typename T> const T DefaultDefaultValue<T>::value;
#endif

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE const T& PrivateConstRefDefaultValue(T*, OverloadRank0)
{
	return IsZeroInitialized<T>::value ? GetZeroRef<T>() : reinterpret_cast<const T&>(DefaultDefaultValue<typename std::conditional<IsZeroInitialized<T>::value, EmptyClass, T>::type>::value);
}

template <typename T> class DefaultValueFunctions
{
public:
	using Default = T;
};


template <typename T, T (*f) ()> class DefaultValueDetector
{
public:
	using type = T;
};

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE const T& PrivateConstRefDefaultValueHelper(OverloadRank0)
{
	return PrivateConstRefDefaultValue((T*) nullptr, OVERLOAD_MAX_RANK); // fallback uses argument-dependent lookup to find matching PrivateConstRefDefaultValue function in T's namespace
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE typename DefaultValueDetector<const T&, &T::DefaultValue>::type PrivateConstRefDefaultValueHelper(OverloadRank1)
{
	return T::DefaultValue();
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE typename DefaultValueDetector<const T&, &T::DefaultValueRef>::type PrivateConstRefDefaultValueHelper(OverloadRank2)
{
	return T::DefaultValueRef();
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE T PrivateDefaultValueHelper(OverloadRank0)
{
	return T();
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE typename DefaultValueDetector<T, &T::DefaultValue>::type PrivateDefaultValueHelper(OverloadRank1)
{
	return T::DefaultValue();
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE typename DefaultValueDetector<const T&, &T::DefaultValue>::type PrivateDefaultValueHelper(OverloadRank1)
{
	return T::DefaultValue();
}

template <typename T> class DefaultValueZeroInitializedHelper
{
public:
	static MAXON_ATTRIBUTE_FORCE_INLINE T Get()
	{
		return T();
	}
};

template <typename T> class DefaultValueZeroInitializedHelper<T&>
{
public:
	static MAXON_ATTRIBUTE_FORCE_INLINE T& Get()
	{
		static_assert(AlwaysFalse<T>::value, "There is no default value for a non-const reference.");
		return const_cast<T&>(GetZeroRef<T>());
	}
};

template <typename T> class DefaultValueZeroInitializedHelper<const T&>
{
public:
	static MAXON_ATTRIBUTE_FORCE_INLINE const T& Get()
	{
		return *(const T*) g_zeroMemory;
	}
};

template <typename T> class DefaultValueTypeHelper
{
public:
	static T Get()
	{
		return PrivateDefaultValueHelper<T>(OVERLOAD_MAX_RANK);
	}

	static T IncompleteGet();
};

template <typename T> class DefaultValueTypeHelper<T&>
{
public:
	static MAXON_ATTRIBUTE_FORCE_INLINE T& Get()
	{
		static_assert(AlwaysFalse<T>::value, "There is no default value for a non-const reference.");
		return const_cast<T&>(GetZeroRef<T>());
	}

	static T& IncompleteGet()
	{
		return Get();
	}
};

template <typename T> class DefaultValueTypeHelper<const T&>
{
public:
	static MAXON_ATTRIBUTE_FORCE_INLINE const T& Get()
	{
		return PrivateConstRefDefaultValueHelper<T>(OVERLOAD_MAX_RANK);
	}

	static const T& IncompleteGet();
};

template <typename T> class DefaultValueFunctionsHelper
{
public:
	static T Get()
	{
		return DefaultValueFunctions<T>::DefaultValue();
	}
};

template <typename T> class DefaultValueFunctionsHelper<T&>
{
public:
	static MAXON_ATTRIBUTE_FORCE_INLINE T& Get()
	{
		static_assert(AlwaysFalse<T>::value, "There is no default value for a non-const reference.");
		return const_cast<T&>(GetZeroRef<T>());
	}
};

template <typename T> class DefaultValueFunctionsHelper<const T&>
{
public:
	static MAXON_ATTRIBUTE_FORCE_INLINE const T& Get()
	{
		return DefaultValueFunctions<T>::DefaultValueRef();
	}
};

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE T PrivateDefaultValueDispatcher(OverloadRank0)
{
	return DefaultValueFunctionsHelper<T>::Get();
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE typename SFINAEHelper<T, typename DefaultValueFunctions<typename std::decay<T>::type>::Default>::type PrivateDefaultValueDispatcher(OverloadRank1)
{
	return DefaultValueTypeHelper<T>::Get();
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE typename std::enable_if<IsZeroInitialized<typename std::decay<T>::type>::value || STD_IS_REPLACEMENT(same, typename std::decay<T>::type, Generic), T>::type PrivateDefaultValueDispatcher(OverloadRank2)
{
	return DefaultValueZeroInitializedHelper<T>::Get();
}


//----------------------------------------------------------------------------------------
/// Returns a default value of type T.
///
/// The default value is defined as follows:
/// - If T is a const reference type const U&:
///  - If U is a scalar type or Generic, the default value is a const reference to a zero-initialized memory.
///  - If there is a specialization of maxon::DefaultValueFunctions for U,
///    the default value is given by the return value of the DefaultValueRef function of that specialization.
///  - Otherwise, if U has or inherits a static member function const U& U::DefaultValueRef() or const U& U::DefaultValue(),
///    the default value is the return value of that function.
///  - Otherwise, the default value is the return value of PrivateConstRefDefaultValue((U*) nullptr, OVERLOAD_MAX_RANK) (which is found using argument-dependent lookup).
///    There is a function template PrivateConstRefDefaultValue<T>(T*, OverloadRank0) in the maxon namespace which returns a reference
///    to a global default-initialized object of type const T.
/// - Otherwise, if T is a non-const reference type U&, a compilation error occurs.
/// - Otherwise T is not a reference type:
///  - If T is a scalar type, the default value is T().
///  - If there is a specialization of maxon::DefaultValueFunctions for T,
///    the default value is given by the return value of the DefaultValue function of that specialization.
///  - Otherwise, if T has or inherits a static member function T T::DefaultValue() or const T& T::DefaultValue(),
///    the default value is the return value of that function.
///  - Otherwise, the default value is T().
///
/// @tparam T											Type of the default value. The cases T, T& and const T& are handled differently.
///
/// @note It is necessary to use the fully-qualified name maxon::DefaultValue if the current scope already
/// contains another DefaultValue declaration, which is the case for interfaces.
/// @return												A default value of type T.
//----------------------------------------------------------------------------------------
template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE T DefaultValue()
{
	return PrivateDefaultValueDispatcher<T>(OVERLOAD_MAX_RANK);
}

template <> MAXON_ATTRIBUTE_FORCE_INLINE void DefaultValue<void>()
{
}


template <typename T> class DefaultValueFunctions<Result<T>>
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
MAXON_ATTRIBUTE_FORCE_INLINE void PrivateLogNullptrError() { }
MAXON_ATTRIBUTE_FORCE_INLINE Bool PrivateLogNullptrError(Bool result) { return result; }
#endif

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE T PrivateDefaultReturnValue(NULL_RETURN_REASON reason, OverloadRank0)
{
	return DefaultValueFunctionsHelper<T>::Get();
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE typename SFINAEHelper<T, typename DefaultValueFunctions<typename std::decay<T>::type>::Default>::type PrivateDefaultReturnValue(NULL_RETURN_REASON reason, OverloadRank1)
{
	return DefaultValueTypeHelper<T>::Get();
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE typename SFINAEHelper<T, typename DefaultValueFunctions<typename std::decay<T>::type>::ResultMarker>::type PrivateDefaultReturnValue(NULL_RETURN_REASON reason, OverloadRank2)
{
	return T(PrivateGetNullReturnError((typename SFINAEHelper<NULL_RETURN_REASON, T>::type) reason));
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE typename std::enable_if<STD_IS_REPLACEMENT(same, Id, typename std::decay<T>::type), T>::type PrivateDefaultReturnValue(NULL_RETURN_REASON reason, OverloadRank3)
{
	return DefaultValueTypeHelper<T>::Get();
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE typename std::enable_if<IsZeroInitialized<typename std::decay<T>::type>::value || STD_IS_REPLACEMENT(same, typename std::decay<T>::type, Generic), T>::type PrivateDefaultReturnValue(NULL_RETURN_REASON reason, OverloadRank4)
{
	return DefaultValueZeroInitializedHelper<T>::Get();
}


template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE T PrivateIncompleteNullReturnValue(NULL_RETURN_REASON reason, OverloadRank0)
{
	return DefaultValueFunctionsHelper<T>::Get();
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE typename SFINAEHelper<T, typename DefaultValueFunctions<typename std::decay<T>::type>::Default>::type PrivateIncompleteNullReturnValue(NULL_RETURN_REASON reason, OverloadRank1)
{
	return DefaultValueTypeHelper<T>::IncompleteGet();
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE typename SFINAEHelper<T, typename DefaultValueFunctions<typename std::decay<T>::type>::ResultMarker>::type PrivateIncompleteNullReturnValue(NULL_RETURN_REASON reason, OverloadRank2)
{
	return T(PrivateGetNullReturnError((typename SFINAEHelper<NULL_RETURN_REASON, T>::type) reason));
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE typename std::enable_if<STD_IS_REPLACEMENT(same, Id, typename std::decay<T>::type), T>::type PrivateIncompleteNullReturnValue(NULL_RETURN_REASON reason, OverloadRank3)
{
	return DefaultValueTypeHelper<T>::Get();
}

template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE typename std::enable_if<IsZeroInitialized<typename std::decay<T>::type>::value, T>::type PrivateIncompleteNullReturnValue(NULL_RETURN_REASON reason, OverloadRank4)
{
	return DefaultValueZeroInitializedHelper<T>::Get();
}

} // namespace maxon

#endif // DEFAULTVALUE_H__
