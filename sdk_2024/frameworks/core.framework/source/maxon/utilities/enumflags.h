#ifndef ENUMFLAGS_H__
#define ENUMFLAGS_H__

#ifndef APIBASE_H__
	#error "Do not include this file directly"
#endif


//----------------------------------------------------------------------------------------
/// EnumInfo contains information about a C++ enum type, including its values.
/// For an enum type E you can get the info by calling GetEnumInfo<E>().
//----------------------------------------------------------------------------------------
struct EnumInfo
{
	const Char* name;					///< The unqualified name of the C++ type.
	Int size;									///< The size of the type in bytes.
	Bool flags;								///< True if the type is registered with one of the MAXON_ENUM_FLAGS macros, false otherwise (the MAXON_ENUM_LIST case).
	const Char* identifiers;	///< The enumerator names in source code order. This is a null-terminated sequence of null-terminated strings.
	const UInt64* values;			///< Pointer to a block of #valuesLength values which holds the enumerator values in source code order.
	Int valuesLength;					///< Number of elements starting at #values.

	const Block<const UInt64>& GetValues() const
	{
		return reinterpret_cast<const Block<const UInt64>&>(values);
	}
};

inline const EnumInfo& PrivateGetEnumInfo(...)
{
	return GetZeroRef<EnumInfo>();
}

//----------------------------------------------------------------------------------------
/// Returns the EnumInfo for enum type E.
/// For an enum type E you can get the info by calling GetEnumInfo<E>().
/// @tparam E											An enum type.
/// @return												The EnumInfo for E.
//----------------------------------------------------------------------------------------
template <typename E> inline const EnumInfo& GetEnumInfo()
{
	static_assert(STD_IS_REPLACEMENT(enum, E), "GetEnumInfo() may only be called for enum types.");
	return PrivateGetEnumInfo(static_cast<E*>(nullptr));
}

enum class ENUM_DONT_INITIALIZE;

//----------------------------------------------------------------------------------------
/// A type alias for the underlying type of T if T is an enumeration type, or T itself.
//----------------------------------------------------------------------------------------
template <typename T> using UnderlyingType = typename std::conditional<STD_IS_REPLACEMENT(enum, T), typename std::underlying_type<typename std::conditional<STD_IS_REPLACEMENT(enum, T), T, ENUM_DONT_INITIALIZE>::type>::type, T>::type;

// For a class-scope enum we have to use an extra argument to enable argument-dependent lookup, otherwise the call in the second friend function wouldn't find the first friend function.
#define PRIVATE_MAXON_ENUM_TYPE0(FRIEND, EXTRA, E, id) \
	FRIEND const maxon::EnumInfo& MAXON_CONCAT(PrivateGetEnumInfo_, MAXON_CONCAT(E, __LINE__))(EXTRA(,void*)); \
	inline FRIEND const maxon::EnumInfo& PrivateGetEnumInfo(E* e) { return MAXON_CONCAT(PrivateGetEnumInfo_, MAXON_CONCAT(E, __LINE__))(EXTRA(,e)); }

#define PRIVATE_MAXON_ENUM_DATATYPE(FRIEND, E, N, id) \
	MAXON_DECLARATION(maxon::DataType, DT_##N, id, static constexpr maxon::EntityBase::TYPE TYPE = maxon::EntityBase::TYPE::DATATYPE;); \
	FRIEND void* PrivateDataTypeMarker(E*); \
	template <maxon::Bool> inline FRIEND maxon::ResultOk<const maxon::DataType&> PrivateGetEnumDataType(E*, maxon::OverloadRank1) { return DT_##N(); } // This has to be a function template so that the dependency on E is only instantiated when needed.

#define PRIVATE_MAXON_ENUM_TYPE1(FRIEND, EXTRA, E, id) \
	PRIVATE_MAXON_ENUM_TYPE0(FRIEND, EXTRA, E, id) \
	PRIVATE_MAXON_ENUM_DATATYPE(FRIEND, E, E, id)

#define PRIVATE_MAXON_ENUM_TYPE2(FRIEND, EXTRA, E, id) \
	PRIVATE_MAXON_ENUM_TYPE0(FRIEND, EXTRA, E, id)

#define MAXON_DATATYPE_EARLY_ENUM(E, id) PRIVATE_MAXON_ENUM_DATATYPE(, E, E, id)


#define PRIVATE_MAXON_ENUM_TYPE_C(nonempty, FRIEND, EXTRA, E, id) MAXON_EXPAND(PRIVATE_MAXON_ENUM_TYPE##nonempty(FRIEND, EXTRA, E, id))
#define PRIVATE_MAXON_ENUM_TYPE_B(nonempty, FRIEND, EXTRA, E, id) PRIVATE_MAXON_ENUM_TYPE_C(nonempty, FRIEND, EXTRA, E, id)
#define PRIVATE_MAXON_ENUM_TYPE_A(nonempty, FRIEND, EXTRA, E, id) PRIVATE_MAXON_ENUM_TYPE_B(nonempty, FRIEND, EXTRA, E, id)

#define PRIVATE_MAXON_ENUM_TYPE(FRIEND, EXTRA, E, ...) PRIVATE_MAXON_ENUM_TYPE_A(MAXON_VA_NARGS(__VA_ARGS__), FRIEND, EXTRA, E, MAXON_FIRSTARG(__VA_ARGS__))


#ifdef MAXON_COMPILER_INTEL
	#define MAXON_ENUM_ORDERED_LIST(E, ...) ; \
		_Pragma("warning disable 1419") \
		PRIVATE_MAXON_ENUM_TYPE(, MAXON_FIRSTARG, E, __VA_ARGS__) \
		_Pragma("warning enable 1419")
	#define MAXON_ENUM_ORDERED_LIST_CLASS(E, ...) ; \
		_Pragma("warning disable 1419 1624") \
		PRIVATE_MAXON_ENUM_TYPE(friend, MAXON_ALLBUTFIRST, E, __VA_ARGS__) \
		_Pragma("warning enable 1419 1624")
#elif defined(MAXON_COMPILER_GCC)
#define MAXON_ENUM_ORDERED_LIST(E, ...) ; \
	PRIVATE_MAXON_ENUM_TYPE(, MAXON_FIRSTARG, E, __VA_ARGS__)
#define MAXON_ENUM_ORDERED_LIST_CLASS(E, ...) ; \
	_Pragma("GCC diagnostic push") \
	_Pragma("GCC diagnostic ignored \"-Wnon-template-friend\"") \
	PRIVATE_MAXON_ENUM_TYPE(friend, MAXON_ALLBUTFIRST, E, __VA_ARGS__) \
	_Pragma("GCC diagnostic pop")
#else
	#define MAXON_ENUM_ORDERED_LIST(E, ...) ; \
		PRIVATE_MAXON_ENUM_TYPE(, MAXON_FIRSTARG, E, __VA_ARGS__)
	#define MAXON_ENUM_ORDERED_LIST_CLASS(E, ...) ; \
		PRIVATE_MAXON_ENUM_TYPE(friend, MAXON_ALLBUTFIRST, E, __VA_ARGS__)
#endif

#if defined(MAXON_COMPILER_CLANG) // Clang bug 41253

	struct IllegalEnumAccess;
	#define PRIVATE_MAXON_ENUM_UNORDERED_LIST(FRIEND, E) \
		FRIEND maxon::IllegalEnumAccess operator <(E s1, E s2); \
		FRIEND maxon::IllegalEnumAccess operator <=(E s1, E s2); \
		FRIEND maxon::IllegalEnumAccess operator >(E s1, E s2); \
		FRIEND maxon::IllegalEnumAccess operator >=(E s1, E s2);
#elif defined(MAXON_COMPILER_GCC)
	struct IllegalEnumAccess;
	#define PRIVATE_MAXON_ENUM_UNORDERED_LIST(FRIEND, E) \
		_Pragma("GCC diagnostic push") \
		_Pragma("GCC diagnostic ignored \"-Wnon-template-friend\"") \
		FRIEND maxon::IllegalEnumAccess operator <(E s1, E s2); \
		FRIEND maxon::IllegalEnumAccess operator <=(E s1, E s2); \
		FRIEND maxon::IllegalEnumAccess operator >(E s1, E s2); \
		FRIEND maxon::IllegalEnumAccess operator >=(E s1, E s2); \
		_Pragma("GCC diagnostic pop")
#elif defined(MAXON_COMPILER_INTEL)
	#define PRIVATE_MAXON_ENUM_UNORDERED_LIST(FRIEND, E) \
		MAXON_ATTRIBUTE_FORCE_INLINE FRIEND maxon::Bool operator <(E s1, E s2) = delete; \
		MAXON_ATTRIBUTE_FORCE_INLINE FRIEND maxon::Bool operator <=(E s1, E s2) = delete; \
		MAXON_ATTRIBUTE_FORCE_INLINE FRIEND maxon::Bool operator >(E s1, E s2) = delete; \
		MAXON_ATTRIBUTE_FORCE_INLINE FRIEND maxon::Bool operator >=(E s1, E s2) = delete
#else
	#define PRIVATE_MAXON_ENUM_UNORDERED_LIST(FRIEND, E) \
		FRIEND maxon::Bool operator <(E s1, E s2) = delete; \
		FRIEND maxon::Bool operator <=(E s1, E s2) = delete; \
		FRIEND maxon::Bool operator >(E s1, E s2) = delete; \
		FRIEND maxon::Bool operator >=(E s1, E s2) = delete
#endif


#ifndef MAXON_ENUM_LIST
#define MAXON_ENUM_LIST(E, ...) ; \
	PRIVATE_MAXON_ENUM_UNORDERED_LIST(, E) \
	MAXON_ENUM_ORDERED_LIST(E, __VA_ARGS__)
#endif

#define MAXON_ENUM_LIST_CLASS(E, ...) ; \
	PRIVATE_MAXON_ENUM_UNORDERED_LIST(friend, E) \
	MAXON_ENUM_ORDERED_LIST_CLASS(E, __VA_ARGS__)

namespace details
{

template <typename ENUMCLASS> struct EnumWrapper
{
	ENUMCLASS value;

	constexpr operator ENUMCLASS() const
	{
		return value;
	}

	explicit constexpr operator Bool() const
	{
		return value != ENUMCLASS();
	}

	explicit constexpr operator typename std::underlying_type<ENUMCLASS>::type() const
	{
		return (typename std::underlying_type<ENUMCLASS>::type) value;
	}
};

}

template <typename E> constexpr inline E ConditionalFlag(Bool condition, E value)
{
	return condition ? value : E::NONE;
}

template <typename E> inline Bool IsAllSet(E flags, E mask)
{
	return (flags & mask) == mask;
}

#define PRIVATE_MAXON_ENUM_FLAGS(FRIEND, E) \
	using PrivateUT##E = maxon::UnderlyingType<E>; \
	MAXON_ATTRIBUTE_FORCE_INLINE FRIEND constexpr E operator |(E a, E b) { return E(PrivateUT##E(a)|PrivateUT##E(b)); } \
	MAXON_ATTRIBUTE_FORCE_INLINE FRIEND constexpr maxon::details::EnumWrapper<E> operator &(E a, E b) { return {E(PrivateUT##E(a)&PrivateUT##E(b))}; } \
	MAXON_ATTRIBUTE_FORCE_INLINE FRIEND constexpr E operator ^(E a, E b) { return E(PrivateUT##E(a)^PrivateUT##E(b)); } \
	MAXON_ATTRIBUTE_FORCE_INLINE FRIEND constexpr E operator ~(E a) { return E(~PrivateUT##E(a)); } \
	MAXON_ATTRIBUTE_FORCE_INLINE FRIEND E& operator |=(E& a, E b) { a = E(PrivateUT##E(a)|PrivateUT##E(b)); return a; } \
	MAXON_ATTRIBUTE_FORCE_INLINE FRIEND E& operator &=(E& a, E b) { a = E(PrivateUT##E(a)&PrivateUT##E(b)); return a; } \
	MAXON_ATTRIBUTE_FORCE_INLINE FRIEND E& operator ^=(E& a, E b) { a = E(PrivateUT##E(a)^PrivateUT##E(b)); return a; }

#ifndef MAXON_ENUM_FLAGS
#define MAXON_ENUM_FLAGS(E, ...) ; \
	PRIVATE_MAXON_ENUM_FLAGS(, E) \
	MAXON_ENUM_LIST(E, __VA_ARGS__)
#endif

#define MAXON_ENUM_ORDERED_FLAGS(E, ...) ; \
	PRIVATE_MAXON_ENUM_FLAGS(, E) \
	MAXON_ENUM_ORDERED_LIST(E, __VA_ARGS__)

#define MAXON_ENUM_FLAGS_CLASS(E, ...) ; \
	PRIVATE_MAXON_ENUM_FLAGS(friend, E) \
	MAXON_ENUM_LIST_CLASS(E, __VA_ARGS__)

#define MAXON_ENUM_ORDERED_FLAGS_CLASS(E, ...) ; \
	PRIVATE_MAXON_ENUM_FLAGS(friend, E) \
	MAXON_ENUM_ORDERED_LIST_CLASS(E, __VA_ARGS__)

//----------------------------------------------------------------------------------------
/// Tests if a specific flag is set in a MAXON enum flag set.
/// @note Helper for MAXON_ENUM_FLAGS.
/// @param[in] flags          Given enum flag set.
/// @param[in] flag           Specific flag.
//----------------------------------------------------------------------------------------
template <typename T, typename E> inline Bool TestFlag(const T flags, const E flag)
{
	return Bool(flags & flag);
}

//----------------------------------------------------------------------------------------
/// Sets a specific flag in a MAXON enum flag set.
/// @note Helper for MAXON_ENUM_FLAGS.
/// @param[in] flags          Given enum flag set.
/// @param[in] flag           Specific flag.
//----------------------------------------------------------------------------------------
template <typename T, typename E> inline void SetFlag(T& flags, const E flag)
{
	flags |= flag;
}

//----------------------------------------------------------------------------------------
/// Deletes a specific flag in a MAXON enum flag set.
/// @note Helper for MAXON_ENUM_FLAGS.
/// @param[in] flags          Given enum flag set.
/// @param[in] flag           Specific flag.
//----------------------------------------------------------------------------------------
template <typename T, typename E> inline void DeleteFlag(T& flags, const E flag)
{
	flags &= ~flag;
}

//----------------------------------------------------------------------------------------
/// Toggles a flag in a MAXON enum flag set
/// @note Helper for MAXON_ENUM_FLAGS.
/// @param[in] flags          Given enum flag set.
/// @param[in] flag           Specific flag.
//----------------------------------------------------------------------------------------
template <typename T, typename E> inline void ToggleFlag(T& flags, const E flag)
{
	flags ^= flag;
}

#endif // ENUMFLAGS_H__

