#ifndef ENUMFLAGS_H__
#define ENUMFLAGS_H__

#ifndef APIBASE_H__
	#error "Do not include this file directly"
#endif


enum class ENUM_DONT_INITIALIZE;

//----------------------------------------------------------------------------------------
/// A type alias for the underlying type of T if T is an enumeration type, or T itself.
//----------------------------------------------------------------------------------------
template <typename T> using UnderlyingType = typename std::conditional<std::is_enum<T>::value, typename std::underlying_type<typename std::conditional<std::is_enum<T>::value, T, ENUM_DONT_INITIALIZE>::type>::type, T>::type;

// For a class-scope enum we have to use an extra argument to enable argument-dependent lookup, otherwise the friend function template wouldn't find the friend function.
#define PRIVATE_MAXON_ENUM_TYPE0(FRIEND, DECL, EXTRA, E, id) \
	FRIEND maxon::String MAXON_CONCAT(PrivateToString_, MAXON_CONCAT(E, __LINE__))(maxon::UnderlyingType<E>, const maxon::FormatStatement* EXTRA(,, void*)); \
	template <typename T> inline FRIEND typename maxon::SFINAEHelper<maxon::String, T>::type ToString(E enumvalue, const T* fs, maxon::Bool EXTRA(= false)) { return MAXON_CONCAT(PrivateToString_, MAXON_CONCAT(E, __LINE__))(maxon::UnderlyingType<E>(enumvalue), fs EXTRA(,, (E*) nullptr)); }

#define PRIVATE_MAXON_ENUM_DATATYPE(FRIEND, DECL, E, N, id) \
	DECL(maxon::DataType, DT_##N, id); \
	FRIEND void* PrivateDataTypeMarker(E*); \
	template <maxon::Bool> inline FRIEND maxon::ResultOk<const maxon::DataType&> PrivateGetEnumDataType(E*, maxon::OverloadRank1) { return DT_##N(); } // This has to be a function template so that the dependency on E is only instantiated when needed.

#define PRIVATE_MAXON_ENUM_TYPE1(FRIEND, DECL, EXTRA, E, id) \
	PRIVATE_MAXON_ENUM_TYPE0(FRIEND, DECL, EXTRA, E, id) \
	PRIVATE_MAXON_ENUM_DATATYPE(FRIEND, DECL, E, E, id)

#define PRIVATE_MAXON_ENUM_TYPE2(FRIEND, DECL, EXTRA, E, id) \
	PRIVATE_MAXON_ENUM_TYPE0(FRIEND, DECL, EXTRA, E, id)

#define MAXON_DATATYPE_EARLY_ENUM(E, id) PRIVATE_MAXON_ENUM_DATATYPE(, MAXON_DECLARATION, E, E, id)


#define PRIVATE_MAXON_ENUM_TYPE_C(nonempty, FRIEND, DECL, EXTRA, E, id) MAXON_EXPAND(PRIVATE_MAXON_ENUM_TYPE##nonempty(FRIEND, DECL, EXTRA, E, id))
#define PRIVATE_MAXON_ENUM_TYPE_B(nonempty, FRIEND, DECL, EXTRA, E, id) PRIVATE_MAXON_ENUM_TYPE_C(nonempty, FRIEND, DECL, EXTRA, E, id)
#define PRIVATE_MAXON_ENUM_TYPE_A(nonempty, FRIEND, DECL, EXTRA, E, id) PRIVATE_MAXON_ENUM_TYPE_B(nonempty, FRIEND, DECL, EXTRA, E, id)

#define PRIVATE_MAXON_ENUM_TYPE(FRIEND, DECL, EXTRA, E, ...) PRIVATE_MAXON_ENUM_TYPE_A(MAXON_VA_NARGS(__VA_ARGS__), FRIEND, DECL, EXTRA, E, MAXON_FIRSTARG(__VA_ARGS__))


#ifdef MAXON_COMPILER_INTEL
	#define MAXON_ENUM_ORDERED_LIST(E, ...) ; \
		_Pragma("warning disable 1419") \
		PRIVATE_MAXON_ENUM_TYPE(, MAXON_DECLARATION, MAXON_FIRSTARG, E, __VA_ARGS__) \
		_Pragma("warning enable 1419")
	#define MAXON_ENUM_ORDERED_LIST_CLASS(E, ...) ; \
		_Pragma("warning disable 1419 1624") \
		PRIVATE_MAXON_ENUM_TYPE(friend, MAXON_DECLARATION_CLASS, MAXON_ALLBUTFIRST, E, __VA_ARGS__) \
		template <typename T> inline friend typename maxon::SFINAEHelper<maxon::String, T>::type ToString(E enumvalue, const T* fs) { return MAXON_CONCAT(PrivateToString_, MAXON_CONCAT(E, __LINE__))(maxon::UnderlyingType<E>(enumvalue), fs, (E*) nullptr); } \
		_Pragma("warning enable 1419 1624")
#else
	#define MAXON_ENUM_ORDERED_LIST(E, ...) ; \
		PRIVATE_MAXON_ENUM_TYPE(, MAXON_DECLARATION, MAXON_FIRSTARG, E, __VA_ARGS__)
	#define MAXON_ENUM_ORDERED_LIST_CLASS(E, ...) ; \
		PRIVATE_MAXON_ENUM_TYPE(friend, MAXON_DECLARATION_CLASS, MAXON_ALLBUTFIRST, E, __VA_ARGS__) \
		template <typename T> inline friend typename maxon::SFINAEHelper<maxon::String, T>::type ToString(E enumvalue, const T* fs) { return MAXON_CONCAT(PrivateToString_, MAXON_CONCAT(E, __LINE__))(maxon::UnderlyingType<E>(enumvalue), fs, (E*) nullptr); }
#endif

#if defined(MAXON_COMPILER_GCC) || defined(MAXON_COMPILER_CLANG) // Clang bug 41253
	struct IllegalEnumAccess;
	#define PRIVATE_MAXON_ENUM_UNORDERED_LIST(FRIEND, E) \
		FRIEND maxon::IllegalEnumAccess operator <(E s1, E s2); \
		FRIEND maxon::IllegalEnumAccess operator <=(E s1, E s2); \
		FRIEND maxon::IllegalEnumAccess operator >(E s1, E s2); \
		FRIEND maxon::IllegalEnumAccess operator >=(E s1, E s2)
#elif defined(MAXON_COMPILER_INTEL)
	#define PRIVATE_MAXON_ENUM_UNORDERED_LIST(FRIEND, E) \
		inline FRIEND maxon::Bool operator <(E s1, E s2) = delete; \
		inline FRIEND maxon::Bool operator <=(E s1, E s2) = delete; \
		inline FRIEND maxon::Bool operator >(E s1, E s2) = delete; \
		inline FRIEND maxon::Bool operator >=(E s1, E s2) = delete
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
	inline FRIEND constexpr E operator |(E a, E b) { return E(PrivateUT##E(a)|PrivateUT##E(b)); } \
	inline FRIEND constexpr maxon::details::EnumWrapper<E> operator &(E a, E b) { return {E(PrivateUT##E(a)&PrivateUT##E(b))}; } \
	inline FRIEND constexpr E operator ^(E a, E b) { return E(PrivateUT##E(a)^PrivateUT##E(b)); } \
	inline FRIEND constexpr E operator ~(E a) { return E(~PrivateUT##E(a)); } \
	inline FRIEND E& operator |=(E& a, E b) { a = E(PrivateUT##E(a)|PrivateUT##E(b)); return a; } \
	inline FRIEND E& operator &=(E& a, E b) { a = E(PrivateUT##E(a)&PrivateUT##E(b)); return a; } \
	inline FRIEND E& operator ^=(E& a, E b) { a = E(PrivateUT##E(a)^PrivateUT##E(b)); return a; }

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

#endif // ENUMFLAGS_H__

