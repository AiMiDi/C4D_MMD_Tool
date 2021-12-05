#ifndef TUPLE_H__
#define TUPLE_H__

#include "maxon/apibase.h"

namespace maxon
{


//----------------------------------------------------------------------------------------
/// The constructor of ForEach allows to iterate over the values of a variadic parameter. The iteration
/// will happen in the correct order. Example:
/// @code
/// template <typename... T> T Sum(T... values)
/// {
///		T s = T();
///   ForEach{s += values...};
///   return s;
/// }
/// @endcode
/// @warning MSVC bug: the evaluation of an initializer list shall be in the correct order (8.5.4.4 List-initialization), but MSVC doesn't stick with this.
/// Therefore, the order of the iteration is unspecified when using MSVC.
//----------------------------------------------------------------------------------------
class ForEach
{
public:
	template <typename... ARGS> explicit ForEach(ARGS&&...)
	{
	}
};


// Forward declarations -----------------------------------------------


namespace details
{
template <UInt32 INDEX, UInt32 PRE_OFFSET, UInt32 PRE_MAX_ALIGN, UInt64... SZ_ALIGN> class TupleStorageLayout;

template <UInt32 INDEX, UInt32 PRE_OFFSET, UInt32 PRE_MAX_ALIGN> class TupleStorageLayout<INDEX, PRE_OFFSET, PRE_MAX_ALIGN>
{
public:
	//----------------------------------------------------------------------------------------
	/// Constant element count of this tuple.
	//----------------------------------------------------------------------------------------
	static const Int COUNT = INDEX;

protected:
	static Generic& GetMember();

	static const Int SIZE = Align(Max(PRE_OFFSET, UInt32(1)), PRE_MAX_ALIGN);
	static const Int ALIGN = PRE_MAX_ALIGN;

	AlignedStorage<SIZE, ALIGN> _bytes;
};

#if defined(MAXON_COMPILER_MSVC)
	#pragma warning(disable:4615) // unknown user warning type, otherwise MSVC claims that it doesn't know 4310
	#pragma warning(disable:4310) // cast truncates constant value
#endif

template <UInt32 INDEX, UInt32 PRE_OFFSET, UInt32 PRE_MAX_ALIGN, UInt64 SZ_ALIGN, UInt64... REST> class TupleStorageLayout<INDEX, PRE_OFFSET, PRE_MAX_ALIGN, SZ_ALIGN, REST...> : public TupleStorageLayout<INDEX + 1, UInt32(Align(PRE_OFFSET, UInt32(SZ_ALIGN >> 33))) + UInt32(SZ_ALIGN), Max(PRE_MAX_ALIGN, UInt32(SZ_ALIGN >> 33)), REST...>
{
public:
	static Int GetOffset(typename std::integral_constant<UInt32, INDEX>::type*)
	{
		static_assert(SIZEOF(TupleStorageLayout) == TupleStorageLayout::SIZE, "Wrong size.");
		static_assert(alignof(TupleStorageLayout) == TupleStorageLayout::ALIGN, "Wrong alignment.");
		return Align(PRE_OFFSET, UInt32(SZ_ALIGN >> 33));
	}

protected:
	using TupleStorageLayout<INDEX + 1, Align(PRE_OFFSET, UInt32(SZ_ALIGN >> 33)) + UInt32(SZ_ALIGN), Max(PRE_MAX_ALIGN, UInt32(SZ_ALIGN >> 33)), REST...>::GetMember;

	Generic& GetMember(typename std::integral_constant<UInt32, INDEX>::type* x)
	{
		Generic* ptr = (Generic*) ((Char*) this + GetOffset(x));
		return *((SZ_ALIGN & (UInt64(1) << 32)) ? *(Generic**) ptr : ptr);
	}

	Generic& GetMember(typename std::integral_constant<UInt32, INDEX>::type* x, Bool)
	{
		Generic* ptr = (Generic*) ((Char*) this + GetOffset(x));
		return *ptr;
	}

	template <typename TUPLE, size_t... I> friend void TupleDestruct(TUPLE& tuple, std::index_sequence<I...>*);
};

#if defined(MAXON_COMPILER_MSVC)
	#pragma warning(enable:4310) // cast truncates constant value
	#pragma warning(enable:4615) // unknown user warning type
#endif

template <typename T> constexpr inline UInt64 GetSizeAndAlignment()
{
	using TT = typename std::conditional<std::is_reference<T>::value, void*, T>::type;
	return UInt64(sizeof(TT)) + ((UInt64(alignof(TT) * 2 + std::is_reference<T>::value)) << 32);
}

template <typename X> inline Bool TupleDestructMember(Generic& x, SFINAEHelper<X>*)
{
	reinterpret_cast<X&>(x).~X();
	return false;
}

template <typename X> inline Bool TupleDestructMember(Generic& x, SFINAEHelper<X&>*)
{
	return false;
}

template <typename TUPLE, size_t... I> inline void TupleDestruct(TUPLE& tuple, std::index_sequence<I...>*)
{
	// Use reversed order (COUNT-1-I) for destruction.
	ForEach{TupleDestructMember(tuple.GetMember((typename std::integral_constant<UInt32, TUPLE::COUNT-1-I>::type*) nullptr), (SFINAEHelper<typename TUPLE::Pack::template At<TUPLE::COUNT-1-I>::type>*) nullptr)...};
}

template <Bool DEFAULT_CONSTRUCTIBLE, Bool TRIVIALLY_DESTRUCTIBLE, typename... T> class TupleStorageBase : public TupleStorageLayout<0, 0, 1, GetSizeAndAlignment<T>()...>
{
public:
	using Pack = ParameterPack<T...>;

	TupleStorageBase() = delete;

	~TupleStorageBase()
	{
		TupleDestruct(*this, (IndexSequence*) nullptr);
	}

protected:
	explicit TupleStorageBase(ENUM_DONT_INITIALIZE)
	{
	}

private:
	using IndexSequence = std::index_sequence_for<T...>;
};

template <typename... T> class TupleStorageBase<false, true, T...> : public TupleStorageLayout<0, 0, 1, GetSizeAndAlignment<T>()...>
{
public:
	TupleStorageBase() = delete;

protected:
	explicit TupleStorageBase(ENUM_DONT_INITIALIZE)
	{
	}
};

template <typename... T> class TupleStorageBase<true, false, T...> : public TupleStorageLayout<0, 0, 1, GetSizeAndAlignment<T>()...>
{
public:
	using Pack = ParameterPack<T...>;

	TupleStorageBase()
	{
		DefaultConstruct((IndexSequence*) nullptr);
	}

	~TupleStorageBase()
	{
		TupleDestruct(*this, (IndexSequence*) nullptr);
	}

protected:
	explicit TupleStorageBase(ENUM_DONT_INITIALIZE)
	{
	}

private:
	using IndexSequence = std::index_sequence_for<T...>;

	template <size_t... I> void DefaultConstruct(std::index_sequence<I...>*)
	{
		ForEach{new (&this->GetMember((typename std::integral_constant<UInt32, I>::type*) nullptr, false)) T()...};
	}
};

template <typename... T> class TupleStorageBase<true, true, T...> : public TupleStorageLayout<0, 0, 1, GetSizeAndAlignment<T>()...>
{
public:
	using Pack = ParameterPack<T...>;

	TupleStorageBase()
	{
		DefaultConstruct((IndexSequence*) nullptr);
	}

protected:
	explicit TupleStorageBase(ENUM_DONT_INITIALIZE)
	{
	}

private:
	using IndexSequence = std::index_sequence_for<T...>;

	template <size_t... I> void DefaultConstruct(std::index_sequence<I...>*)
	{
		ForEach{new (&this->GetMember((typename std::integral_constant<UInt32, I>::type*) nullptr, false)) T()...};
	}
};

template <typename T> struct TupleRefWrapper
{
	using type = T;
};

template <typename T> struct TupleRefWrapper<T&>
{
	using type = TupleRefWrapper;

	explicit TupleRefWrapper(T& r) : ref(&r)
	{
	}

	explicit TupleRefWrapper(T&& r) : ref(&r)
	{
	}

	T* ref;
};

template <typename... T> class TupleStorage : public TupleStorageBase<And<std::is_default_constructible<T>::value...>::value, And<std::is_trivially_destructible<T>::value...>::value, T...>
{
	using Super = TupleStorageBase<And<std::is_default_constructible<T>::value...>::value, And<std::is_trivially_destructible<T>::value...>::value, T...>;
	using IndexSequence = std::index_sequence_for<T...>;
	static const Bool COPY_CONSTRUCTIBLE = And<std::is_copy_constructible<T>::value...>::value;
	static const Bool COPY_ASSIGNABLE = And<std::is_copy_assignable<T>::value...>::value;
	static const Bool MOVE_CONSTRUCTIBLE = And<std::is_move_constructible<T>::value...>::value;
	static const Bool MOVE_ASSIGNABLE = And<std::is_move_assignable<T>::value...>::value;

public:
	TupleStorage() = default;

	template <size_t... I, typename... ARGS> explicit TupleStorage(std::index_sequence<I...>*, ARGS&&... args) : Super(DONT_INITIALIZE)
	{
		ForEach{new (&this->GetMember((typename std::integral_constant<UInt32, I>::type*) nullptr, false)) typename TupleRefWrapper<T>::type{std::forward<ARGS>(args)}...};
	}

	MAXON_DECLARE_CONDITIONAL_COPY_CONSTRUCTOR(TupleStorage, COPY_CONSTRUCTIBLE) : Super(DONT_INITIALIZE)
	{
		CopyConstruct((IndexSequence*) nullptr, src);
	}

	MAXON_DECLARE_CONDITIONAL_COPY_ASSIGNMENT(TupleStorage, COPY_ASSIGNABLE)
	{
		CopyAssign((IndexSequence*) nullptr, src);
		return *this;
	}

	MAXON_DECLARE_CONDITIONAL_MOVE_CONSTRUCTOR(TupleStorage, MOVE_CONSTRUCTIBLE) : Super(DONT_INITIALIZE)
	{
		MoveConstruct((IndexSequence*) nullptr, std::move(src));
	}

	MAXON_DECLARE_CONDITIONAL_MOVE_ASSIGNMENT(TupleStorage, MOVE_ASSIGNABLE)
	{
		MoveAssign((IndexSequence*) nullptr, std::move(src));
		return *this;
	}

private:
	template <size_t... I> void CopyConstruct(std::index_sequence<I...>*, const TupleStorage& src)
	{
		ForEach{new (&this->GetMember((typename std::integral_constant<UInt32, I>::type*) nullptr, false)) typename TupleRefWrapper<T>::type{reinterpret_cast<const T&>(const_cast<TupleStorage&>(src).GetMember((typename std::integral_constant<UInt32, I>::type*) nullptr))}...};
	}

	template <size_t... I> void CopyAssign(std::index_sequence<I...>*, const TupleStorage& src)
	{
		ForEach{reinterpret_cast<T&>(this->GetMember((typename std::integral_constant<UInt32, I>::type*) nullptr)) = reinterpret_cast<const T&>(const_cast<TupleStorage&>(src).GetMember((typename std::integral_constant<UInt32, I>::type*) nullptr))...};
	}

	template <size_t... I> void MoveConstruct(std::index_sequence<I...>*, TupleStorage&& src)
	{
		ForEach{new (&this->GetMember((typename std::integral_constant<UInt32, I>::type*) nullptr, false)) typename TupleRefWrapper<T>::type{std::move(reinterpret_cast<T&>(src.GetMember((typename std::integral_constant<UInt32, I>::type*) nullptr)))}...};
	}

	template <size_t... I> void MoveAssign(std::index_sequence<I...>*, TupleStorage&& src)
	{
		ForEach{reinterpret_cast<T&>(this->GetMember((typename std::integral_constant<UInt32, I>::type*) nullptr)) = std::move(reinterpret_cast<T&>(src.GetMember((typename std::integral_constant<UInt32, I>::type*) nullptr)))...};
	}
};

template <typename T1> class TupleStorage<T1>
{
public:
	static const Int COUNT = 1;

	TupleStorage() : first()
	{
	}

	template <typename A1> TupleStorage(std::index_sequence<0>*, A1&& a1) : first(std::forward<A1>(a1))
	{
	}

	T1 first;

	static Int GetOffset(typename std::integral_constant<UInt32, 0>::type*) { return 0; }

protected:
	T1& GetMember(std::integral_constant<UInt32, 0>::type*) { return first; }
};

template <typename T1, typename T2> class TupleStorage<T1, T2>
{
public:
	static const Int COUNT = 2;

	TupleStorage() : first(), second()
	{
	}

	template <typename A1, typename A2> TupleStorage(std::index_sequence<0, 1>*, A1&& a1, A2&& a2) : first(std::forward<A1>(a1)), second(std::forward<A2>(a2))
	{
	}

	T1 first;
	T2 second;

	static_assert(!std::is_same<typename std::decay<T2>::type, UnitType>::value, "The UnitType specialization of Tuple should be used.");

	using FirstType = T1;
	using SecondType = T2;
	using KeyType = T1;
	using ValueType = T2;

	//----------------------------------------------------------------------------------------
	/// Returns the first element of this tuple.
	//----------------------------------------------------------------------------------------
	T1& GetFirst() { return first; }
	const T1& GetFirst() const { return first; }

	//----------------------------------------------------------------------------------------
	/// Returns the second element of this tuple.
	//----------------------------------------------------------------------------------------
	T2& GetSecond() { return second; }
	const T2& GetSecond() const { return second; }

	//----------------------------------------------------------------------------------------
	/// Returns the first element of this tuple (map compatibility).
	//----------------------------------------------------------------------------------------
	const T1& GetKey() const { return first; }

	//----------------------------------------------------------------------------------------
	/// Returns the second element of this tuple (map compatibility).
	//----------------------------------------------------------------------------------------
	T2& GetValue() { return second; }
	const T2& GetValue() const { return second; }

	static Int GetOffset(typename std::integral_constant<UInt32, 0>::type*) { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(TupleStorage, first); }
	static Int GetOffset(typename std::integral_constant<UInt32, 1>::type*) { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(TupleStorage, second); }

protected:
	T1& GetMember(std::integral_constant<UInt32, 0>::type*) { return first; }
	T2& GetMember(std::integral_constant<UInt32, 1>::type*) { return second; }
};

template <typename T1, typename T2, typename T3> class TupleStorage<T1, T2, T3>
{
public:
	static const Int COUNT = 3;

	TupleStorage() : first(), second(), third()
	{
	}

	template <typename A1, typename A2, typename A3> TupleStorage(std::index_sequence<0, 1, 2>*, A1&& a1, A2&& a2, A3&& a3) : first(std::forward<A1>(a1)), second(std::forward<A2>(a2)), third(std::forward<A3>(a3))
	{
	}

	T1 first;
	T2 second;
	T3 third;

	static Int GetOffset(typename std::integral_constant<UInt32, 0>::type*) { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(TupleStorage, first); }
	static Int GetOffset(typename std::integral_constant<UInt32, 1>::type*) { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(TupleStorage, second); }
	static Int GetOffset(typename std::integral_constant<UInt32, 2>::type*) { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(TupleStorage, third); }

protected:
	T1& GetMember(std::integral_constant<UInt32, 0>::type*) { return first; }
	T2& GetMember(std::integral_constant<UInt32, 1>::type*) { return second; }
	T3& GetMember(std::integral_constant<UInt32, 2>::type*) { return third; }
};

template <typename T1, typename T2, typename T3, typename T4> class TupleStorage<T1, T2, T3, T4>
{
public:
	static const Int COUNT = 4;

	TupleStorage() : first(), second(), third(), fourth()
	{
	}

	template <typename A1, typename A2, typename A3, typename A4> TupleStorage(std::index_sequence<0, 1, 2, 3>*, A1&& a1, A2&& a2, A3&& a3, A4&& a4) : first(std::forward<A1>(a1)), second(std::forward<A2>(a2)), third(std::forward<A3>(a3)), fourth(std::forward<A4>(a4))
	{
	}

	T1 first;
	T2 second;
	T3 third;
	T4 fourth;

	static Int GetOffset(typename std::integral_constant<UInt32, 0>::type*) { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(TupleStorage, first); }
	static Int GetOffset(typename std::integral_constant<UInt32, 1>::type*) { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(TupleStorage, second); }
	static Int GetOffset(typename std::integral_constant<UInt32, 2>::type*) { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(TupleStorage, third); }
	static Int GetOffset(typename std::integral_constant<UInt32, 3>::type*) { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(TupleStorage, fourth); }

protected:
	T1& GetMember(std::integral_constant<UInt32, 0>::type*) { return first; }
	T2& GetMember(std::integral_constant<UInt32, 1>::type*) { return second; }
	T3& GetMember(std::integral_constant<UInt32, 2>::type*) { return third; }
	T4& GetMember(std::integral_constant<UInt32, 3>::type*) { return fourth; }
};

template <typename T1, typename T2, typename T3, typename T4, typename T5> class TupleStorage<T1, T2, T3, T4, T5>
{
public:
	static const Int COUNT = 5;

	TupleStorage() : first(), second(), third(), fourth(), fifth()
	{
	}

	template <typename A1, typename A2, typename A3, typename A4, typename A5> TupleStorage(std::index_sequence<0, 1, 2, 3, 4>*, A1&& a1, A2&& a2, A3&& a3, A4&& a4, A5&& a5) : first(std::forward<A1>(a1)), second(std::forward<A2>(a2)), third(std::forward<A3>(a3)), fourth(std::forward<A4>(a4)), fifth(std::forward<A5>(a5))
	{
	}

	T1 first;
	T2 second;
	T3 third;
	T4 fourth;
	T5 fifth;

	static Int GetOffset(typename std::integral_constant<UInt32, 0>::type*) { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(TupleStorage, first); }
	static Int GetOffset(typename std::integral_constant<UInt32, 1>::type*) { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(TupleStorage, second); }
	static Int GetOffset(typename std::integral_constant<UInt32, 2>::type*) { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(TupleStorage, third); }
	static Int GetOffset(typename std::integral_constant<UInt32, 3>::type*) { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(TupleStorage, fourth); }
	static Int GetOffset(typename std::integral_constant<UInt32, 4>::type*) { return MAXON_OFFSETOF_NON_STANDARD_LAYOUT(TupleStorage, fifth); }

protected:
	T1& GetMember(std::integral_constant<UInt32, 0>::type*) { return first; }
	T2& GetMember(std::integral_constant<UInt32, 1>::type*) { return second; }
	T3& GetMember(std::integral_constant<UInt32, 2>::type*) { return third; }
	T4& GetMember(std::integral_constant<UInt32, 3>::type*) { return fourth; }
	T5& GetMember(std::integral_constant<UInt32, 4>::type*) { return fifth; }
};

template <typename T1> class TupleStorage<T1, UnitType>
{
public:
	static const Int COUNT = 2;

	TupleStorage() : first()
	{
	}

	template <typename A1, typename A2> TupleStorage(std::index_sequence<0, 1>*, A1&& a1, A2&& a2) : first(std::forward<A1>(a1))
	{
	}

	T1 first;

	using FirstType = T1;
	using SecondType = UnitType;
	using KeyType = T1;
	using ValueType = UnitType;

	//----------------------------------------------------------------------------------------
	/// Returns the first element of this tuple.
	//----------------------------------------------------------------------------------------
	T1& GetFirst() { return first; }
	const T1& GetFirst() const { return first; }

	//----------------------------------------------------------------------------------------
	/// Returns the second element of this tuple.
	//----------------------------------------------------------------------------------------
	UnitType& GetSecond() { return reinterpret_cast<UnitType&>(first); }
	const UnitType& GetSecond() const { return reinterpret_cast<const UnitType&>(first); }

	//----------------------------------------------------------------------------------------
	/// Returns the first element of this tuple (map compatibility).
	//----------------------------------------------------------------------------------------
	const T1& GetKey() const { return first; }

	//----------------------------------------------------------------------------------------
	/// Returns the second element of this tuple (map compatibility).
	//----------------------------------------------------------------------------------------
	UnitType& GetValue() { return reinterpret_cast<UnitType&>(first); }
	const UnitType& GetValue() const { return reinterpret_cast<const UnitType&>(first); }

	static Int GetOffset(typename std::integral_constant<UInt32, 0>::type*) { return 0; }
	static Int GetOffset(typename std::integral_constant<UInt32, 1>::type*) { return 0; }

protected:
	T1& GetMember(std::integral_constant<UInt32, 0>::type*) { return first; }
	UnitType& GetMember(std::integral_constant<UInt32, 1>::type*) { return reinterpret_cast<UnitType&>(first); }
};

inline ResultOk<void> TupleCopyFrom()
{
	return OK;
}

template <typename T1, typename... T> inline Result<void> TupleCopyFrom(const T1& a1, const T&... rest)
{
	iferr_scope;
	AssignCopy(a1.first, a1.second) iferr_return;
	return TupleCopyFrom(rest...);
}

inline UInt TupleGetHashCode()
{
	return 0;
}

template <typename T1, typename... T> inline UInt TupleGetHashCode(const T1& a1, const T&... rest)
{
	// For this code it is necessary that the arguments are passed in reversed order.
	return 31 * TupleGetHashCode(rest...) + DefaultCompare::GetHashCode(a1);
}

inline const String& TupleToString(const FormatStatement* fs)
{
	return GetPtrSizedZeroRef<String>();
}

template <typename T1, typename... T> inline typename SFINAEHelper<String, T1>::type TupleToString(const FormatStatement* fs, const T1& a1, const T&... rest)
{
	if (sizeof...(T) == 0)
	{
		return GlobalToString(a1, fs);
	}
	else
	{
		return GlobalToString(a1, fs) + "/"_s + TupleToString(fs, rest...);
	}
}

inline Bool TupleEquals()
{
	return true;
}

template <typename T1, typename... T> inline Bool TupleEquals(const T1& a1, const T&... rest)
{
	return DefaultCompare::IsEqual(a1.first, a1.second) && TupleEquals(rest...);
}

inline Bool TupleLessThan()
{
	return false;
}

template <typename T1, typename... T> inline Bool TupleLessThan(const T1& a1, const T&... rest)
{
	return CompareTemplate<true>::LessThan(a1.first, a1.second) || (sizeof...(T) > 0 && DefaultCompare::IsEqual(a1.first, a1.second) && TupleLessThan(rest...));
}

template <typename T1, typename T2> inline TupleStorage<T1&, const T2&> TuplePair(T1& t1, const T2& t2)
{
	return {(std::index_sequence<0, 1>*) nullptr, t1, t2};
}

} // namespace maxon::details

// Public API -----------------------------------------------

template <typename... T> class Tuple;

//----------------------------------------------------------------------------------------
/// A class that can be used to find the index of a unique element type in a tuple.
/// If no match was found or the type was not unique, a negative value is used.
/// Unique means there is exactly one element with the given type. Works at compile time.
///
/// Example:
/// @code
/// static const Int index = FindTupleIndex<String, Tuple<Int, String, String>>::value;
/// // index is negative, because String occurs twice
/// static_assert(index < 0, "type not found");
/// @endcode
///
/// ::value contains the index of the type if it was found exactly once, or a negative value otherwise.
///
/// @tparam SEARCHTYPE						Type to search for.
/// @tparam TUPLETYPE							Type of the tuple that is searched in.
//----------------------------------------------------------------------------------------
template <typename SEARCHTYPE, typename TUPLETYPE> struct FindUniqueTupleIndex;

template <typename SEARCHTYPE, typename... TYPES> struct FindUniqueTupleIndex<SEARCHTYPE, Tuple<TYPES...>>
{
	static const Int value = ParameterPack<TYPES...>::template IndexOf<SEARCHTYPE>::value;
};


//----------------------------------------------------------------------------------------
/// Tuple provides in-place static storage for elements of arbitrary types.
/// It is similar to a pair, but supports a variable number of elements.
/// The memory layout is identical to a struct with the same member types:
/// @code
/// Tuple<T1, T2, T3> t;
/// // ... same size and layout as ...
/// struct MyType { T1 a; T2 b; T3 c; };
/// MyType t;
/// @endcode
///
/// Tuples allow to create generic classes which store a variable number
/// of member-like types that can be initialized from a parameter pack. Example:
/// @code
/// template <typename ... Ts> class MyGenericClass
/// {
/// 	Tuple<Ts ...> storedArgs;
///   // Similar to T1 m1; T2 m2; ... TN mN
///
/// 	MyGenericClass(Ts ... args) : storedArgs(args) { }
///   // Similar to m1(a1), m2(a2), ... mN(aN)
/// };
/// @endcode
///
/// Tuples can also reduce the amount of boilerplate code when storing struct-like entries
/// in containers like BaseArray, because they already come with the full range of
/// constructors, assignment operators and comparison operators defined.
///
/// Another use case is simplifying multiple return values from a function by wrapping them in a tuple
/// and using Tie to map them to variables:
/// @code
/// A a; B b; C c;
/// Tie(a, b, c) = FuncThatReturnsTupleOfABC();
/// @endcode
///
/// Since tuple elements are unnamed and can only be accessed by index or unique type, when using
/// them in interfaces you should always consider whether using a struct with named elements would
/// make things more obvious.
///
/// @tparam T											Element types.
//----------------------------------------------------------------------------------------
template <typename... T> class Tuple : public maxon::details::TupleStorage<T...>
{
	using Super = maxon::details::TupleStorage<T...>;
	using IndexSequence = std::index_sequence_for<T...>;

	static const Bool COPYABLE = And<std::is_copy_constructible<T>::value...>::value;

public:
	using Pack = ParameterPack<T...>;

	Tuple() = default;

	//----------------------------------------------------------------------------------------
	/// Converting copy constructor.
	///
	/// Constructs Tuple<T...> from Tuple<U...> by doing an element-wise copy.
	/// Participates in overload resolution only if Ti is constructible from const Ui&.
	//----------------------------------------------------------------------------------------
	template
	<
		typename... U,
		typename = typename std::enable_if<And<std::is_constructible<T, const U&>::value...>::value>::type
	>
	Tuple(const Tuple<U...>& src) : Tuple((IndexSequence*) nullptr, src)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Converting move constructor.
	///
	/// Constructs Tuple<T...> from Tuple<U...> by doing an element-wise forward.
	/// Participates in overload resolution only if Ti is constructible from Ui&&.
	/// This also covers the default move constructor.
	//----------------------------------------------------------------------------------------
	template
	<
		typename... U,
		typename = typename std::enable_if<And<std::is_constructible<T, U&&>::value...>::value>::type
	>
	Tuple(Tuple<U...>&& src) : Tuple((IndexSequence*) nullptr, std::move(src))
	{
	}

	//----------------------------------------------------------------------------------------
	/// Copy-from-value constructor.
	///
	/// Initializes elements with values.
	///
	/// @param[in] x									Values.
	//----------------------------------------------------------------------------------------
	MAXON_IMPLICIT Tuple(const typename std::conditional<COPYABLE, T, volatile DummyParamType>::type&... x) : Super((IndexSequence*) nullptr, x...)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Forward-and-convert-from-value constructor.
	///
	/// Initializes elements with forwarded values.
	/// Participates in overload resolution only if Ti is constructible from Ui&&.
	///
	/// @param[in] x									Values.
	//----------------------------------------------------------------------------------------
	template
	<
		typename... U,
		typename = typename std::enable_if<And<std::is_constructible<T, U&&>::value...>::value>::type
	>
	MAXON_IMPLICIT Tuple(U&&... x) : Super((IndexSequence*) nullptr, std::forward<U>(x)...)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Converting copy assignment. Does an element-wise copy assignment.
	//----------------------------------------------------------------------------------------
	template <typename... U> Tuple& operator =(const Tuple<U...>& src)
	{
		CopyAssign((IndexSequence*) nullptr, src);
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Converting move assignment. Does an element-wise perfect-forwarded assignment.
	//----------------------------------------------------------------------------------------
	template <typename... U> Tuple& operator =(Tuple<U...>&& src)
	{
		MoveAssign((IndexSequence*) nullptr, std::move(src));
		return *this;
	}

	//----------------------------------------------------------------------------------------
	/// Copies one tuple to another with an element-wise AssignCopy. Use this instead of regular
	/// assignment if copying an element may result in an error and is thus not supported with a regular
	/// copy assignment.
	//----------------------------------------------------------------------------------------
	Result<void> CopyFrom(const typename std::conditional<COPYABLE, DummyParamType, Tuple>::type& src)
	{
		return CopyFromImpl((IndexSequence*) nullptr, src);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a formated string representation for this tuple.
	//----------------------------------------------------------------------------------------
	typename SFINAEHelper<String, T...>::type ToString(const FormatStatement* format) const
	{
		return ToStringImpl((IndexSequence*) nullptr, format);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the hash code generated from the elements of this tuple.
	//----------------------------------------------------------------------------------------
	UInt GetHashCode() const
	{
		return GetHashCodeImpl((IndexSequence*) nullptr);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the element at index I. Equivalent to TupleGet<I>(*this).
	//----------------------------------------------------------------------------------------
	template <Int I> typename std::add_const<typename Pack::template At<I>::type>::type& Get() const
	{
		return reinterpret_cast<typename std::add_const<typename Pack::template At<I>::type>::type&>(const_cast<Tuple*>(this)->GetMember((typename std::integral_constant<UInt32, I>::type*) nullptr));
	}

	template <Int I> typename Pack::template At<I>::type& Get()
	{
		return reinterpret_cast<typename Pack::template At<I>::type&>(this->GetMember((typename std::integral_constant<UInt32, I>::type*) nullptr));
	}

	//----------------------------------------------------------------------------------------
	/// Returns element with type ELEMENTTYPE. Equivalent to TupleGet<ELEMENTTYPE>(*this).
	//----------------------------------------------------------------------------------------
	template <typename ELEMENTTYPE> auto Get() const -> const ELEMENTTYPE&
	{
		static const Int index = FindUniqueTupleIndex<ELEMENTTYPE, Tuple>::value;
		static_assert(index >= 0, "ELEMENTTYPE must occur exactly once in given tuple.");

		return Get<index>();
	}

	template <typename ELEMENTTYPE> auto Get() -> ELEMENTTYPE&
	{
		static const Int index = FindUniqueTupleIndex<ELEMENTTYPE, Tuple>::value;
		static_assert(index >= 0, "ELEMENTTYPE must occur exactly once in given tuple.");

		return Get<index>();
	}

	//----------------------------------------------------------------------------------------
	/// Element-wise comparison for equality.
	///
	/// Returns true, if myElem[i] == src.elem[i] for all i = 0 .. N.
	//----------------------------------------------------------------------------------------
	Bool operator ==(const Tuple& other) const
	{
		return EqualsImpl((IndexSequence*) nullptr, other);
	}

	//----------------------------------------------------------------------------------------
	/// Element-wise less-than from left to right.
	///
	/// Returns true,  if myElem[i] < src.elem[i].
	/// Returns false, if myElem[i] > src.elem[i].
	/// Otherwise, if there exist elements at i+1, they are compared by the same rules.
	/// Otherwise, returns false.
	//----------------------------------------------------------------------------------------
	Bool operator <(const Tuple& other) const
	{
		return LessThanImpl((IndexSequence*) nullptr, other);
	}

	MAXON_OPERATOR_COMPARISON(Tuple);

private:
	template <typename... U, size_t... I> Tuple(std::index_sequence<I...>* seq, const Tuple<U...>& src) : Super(seq, src.template Get<I>()...)
	{
	}

	template <typename... U, size_t... I> Tuple(std::index_sequence<I...>* seq, Tuple<U...>&& src) : Super(seq, std::forward<U>(src.template Get<I>())...)
	{
	}

	template <typename... U, size_t... I> void CopyAssign(std::index_sequence<I...>*, const Tuple<U...>& src)
	{
		ForEach{(Get<I>() = src.template Get<I>())...};
	}

	template <typename... U, size_t... I> void MoveAssign(std::index_sequence<I...>*, Tuple<U...>&& src)
	{
		ForEach{(Get<I>() = std::move(src.template Get<I>()))...};
	}

	template <size_t... I> Result<void> CopyFromImpl(std::index_sequence<I...>*, const Tuple& src)
	{
		return maxon::details::TupleCopyFrom(maxon::details::TuplePair(Get<I>(), src.Get<I>())...);
	}

	template <size_t... I> typename SFINAEHelper<String, T...>::type ToStringImpl(std::index_sequence<I...>*, const FormatStatement* format) const
	{
		return maxon::details::TupleToString(format, Get<I>()...);
	}

	template <size_t... I> UInt GetHashCodeImpl(std::index_sequence<I...>*) const
	{
		// Reverse the order of arguments.
		return maxon::details::TupleGetHashCode(Get<sizeof...(T)-1-I>()...);
	}

	template <size_t... I> Bool EqualsImpl(std::index_sequence<I...>*, const Tuple& other) const
	{
		return maxon::details::TupleEquals(maxon::details::TuplePair(Get<I>(), other.Get<I>())...);
	}

	template <size_t... I> Bool LessThanImpl(std::index_sequence<I...>*, const Tuple& other) const
	{
		return maxon::details::TupleLessThan(maxon::details::TuplePair(Get<I>(), other.Get<I>())...);
	}
};


//----------------------------------------------------------------------------------------
/// Specialization for a Tuple without any elements.
//----------------------------------------------------------------------------------------
template <> class Tuple<>
{
public:
	using Pack = ParameterPack<>;
	static const Int COUNT = 0;

	//----------------------------------------------------------------------------------------
	/// Formats an empty tuple as a string.
	/// @return												Always "()"_s.
	//----------------------------------------------------------------------------------------
	const String& ToString(const FormatStatement*) const { return "()"_s; }

	//----------------------------------------------------------------------------------------
	/// Calculates hash code of an empty tuple.
	/// @return												Always 0.
	//----------------------------------------------------------------------------------------
	UInt GetHashCode() const { return 0; }

	Bool operator ==(const Tuple& other) const { return true; }

	Bool operator <(const Tuple& other) const { return false; }

	MAXON_OPERATOR_COMPARISON(Tuple);
};


//----------------------------------------------------------------------------------------
/// TupleGet is the equivalent of std::get. It returns the element at index I.
///
/// Example:
/// @code
/// Tuple<Int, String> tup(1, "Hello"_s);
/// Int     i = TupleGet<0>(tup);
/// CString s = TupleGet<1>(tup);
/// @endcode
///
/// Note that the index must be a compile-time constant.
///
/// If tup is bound to a const&, the element will be returned by const&.
/// If tup is bound to a &, the element will be returned by &.
/// If tup is bound to a &&, the element will be returned by &&.
///
/// @tparam I											The index of the element that should be returned.
/// @param[in] tup								The tuple from which to get the element.
/// @return												The returned element.
//----------------------------------------------------------------------------------------

// Const lvalue ref
template <Int I, typename ... TYPES> inline auto TupleGet(const Tuple<TYPES ...>& tup) -> const typename ParameterPack<TYPES...>::template At<I>::type&
{
	return tup.template Get<I>();
}

// Lvalue ref
template <Int I, typename ... TYPES> inline auto TupleGet(Tuple<TYPES ...>& tup) -> typename ParameterPack<TYPES...>::template At<I>::type&
{
	return tup.template Get<I>();
}

// Rvalue ref
template <Int I, typename ... TYPES> inline auto TupleGet(Tuple<TYPES ...>&& tup) -> typename ParameterPack<TYPES...>::template At<I>::type&&
{
	return std::move(tup.template Get<I>());
}

//----------------------------------------------------------------------------------------
/// A TupleGet overload that uses a type to select a unique element.
/// The type must be unique in the given tuple, otherwise a compile-time error will occur.
///
/// Example:
/// @code
/// Tuple<Int, String> tup(1, "Hello"_s);
/// Int     i = TupleGet<Int>(tup);
/// CString s = TupleGet<String>(tup);
/// @endcode
///
/// Note that the index must be a compile-time constant.
///
/// If tup is bound to a const&, the element will be returned by const&.
/// If tup is bound to a &, the element will be returned by &.
/// If tup is bound to a &&, the element will be returned by &&.
///
/// @tparam ELEMENTTYPE						The type of the element that should be returned (must be unique in the tuple).
/// @param[in] tup								The tuple from which to get the element.
/// @return												The returned element.
//----------------------------------------------------------------------------------------

// Const lvalue ref
template <typename ELEMENTTYPE, typename ... TYPES> inline auto TupleGet(const Tuple<TYPES ...>& tup) -> const ELEMENTTYPE&
{
	static const Int index = FindUniqueTupleIndex<ELEMENTTYPE, Tuple<TYPES ...>>::value;
	static_assert(index >= 0, "ELEMENTTYPE must occur exactly once in given tuple.");

	return TupleGet<index>(tup);
}

// Lvalue ref
template <typename ELEMENTTYPE, typename ... TYPES> inline auto TupleGet(Tuple<TYPES ...>& tup) -> ELEMENTTYPE&
{
	static const Int index = FindUniqueTupleIndex<ELEMENTTYPE, Tuple<TYPES ...>>::value;
	static_assert(index >= 0, "ELEMENTTYPE must occur exactly once in given tuple.");

	return TupleGet<index>(tup);
}

// Rvalue ref
template <typename ELEMENTTYPE, typename ... TYPES> inline auto TupleGet(Tuple<TYPES ...>&& tup) -> ELEMENTTYPE&&
{
	static const Int index = FindUniqueTupleIndex<ELEMENTTYPE, Tuple<TYPES ...>>::value;
	static_assert(index >= 0, "ELEMENTTYPE must occur exactly once in given tuple.");

	return TupleGet<index>(std::move(tup));
}

namespace details
{
//-----------------------------------------------

template <typename TUP, typename F, size_t ... INDICES> inline auto ExpandSeqHelperConst(const TUP& tup, F&& func, std::index_sequence<INDICES ...>)
	-> decltype(func(TupleGet<INDICES>(tup) ...))
{
	return func(TupleGet<INDICES>(tup) ...);
}

template <typename TUP, typename F, size_t ... INDICES> inline auto ExpandSeqHelper(TUP&& tup, F&& func, std::index_sequence<INDICES ...>)
	-> decltype(func(TupleGet<INDICES>(std::forward<TUP>(tup)) ...))
{
	return func(TupleGet<INDICES>(std::forward<TUP>(tup)) ...);
}

//-----------------------------------------------
// Automatically decay UnitType for use in Pair.
//-----------------------------------------------
template <typename T1, typename T2, typename DECAYED_T2 = typename std::decay<T2>::type> struct PairSelector
{
	using type = Tuple<T1, T2>;
};

template <typename T1, typename T2> struct PairSelector<T1, T2, UnitType>
{
	using type = Tuple<T1, UnitType>;
};

//-----------------------------------------------
template <Int N, typename T, typename ... TYPES> struct HomogenousTupleTypeHelper
	: public HomogenousTupleTypeHelper<N - 1, T, T, TYPES ...>
{ };

template <typename T, typename ... TYPES> struct HomogenousTupleTypeHelper<0, T, TYPES ...>
{
	using type = Tuple<TYPES ...>;
};

//-----------------------------------------------
template <Int I, Int N> struct TupleRecHelper
{
	// ForEach
	template <typename TUP, typename F> static MAXON_ATTRIBUTE_FORCE_INLINE void ForEach(const TUP& tup, F&& func)
	{
		func(TupleGet<I>(tup));
		TupleRecHelper<I + 1, N - 1>::ForEach(tup, std::forward<F>(func));
	}

	template <typename TUP, typename F> static MAXON_ATTRIBUTE_FORCE_INLINE void ForEach(TUP&& tup, F&& func)
	{
		func(TupleGet<I>(tup));
		TupleRecHelper<I + 1, N - 1>::ForEach(std::forward<TUP>(tup), std::forward<F>(func));
	}

	// FoldLeft
	template <typename RET, typename TUP, typename F>
	static MAXON_ATTRIBUTE_FORCE_INLINE RET FoldLeft(const TUP& tup, const RET& v, F&& func)
	{
		return TupleRecHelper<I + 1, N - 1>::FoldLeft(tup, func(TupleGet<I>(tup)), std::forward<F>(func));
	}

	template <typename RET, typename TUP, typename F>
	static MAXON_ATTRIBUTE_FORCE_INLINE RET FoldLeft(TUP&& tup, const RET& v, F&& func)
	{
		return TupleRecHelper<I + 1, N - 1>::FoldLeft(std::forward<TUP>(tup), func(v, TupleGet<I>(tup)), std::forward<F>(func));
	}
};

template <Int I> struct TupleRecHelper<I, 1>
{
	template <typename TUP, typename F>
	static MAXON_ATTRIBUTE_FORCE_INLINE void ForEach(const TUP& tup, F&& func)
	{
		func(TupleGet<I>(tup));
	}

	template <typename TUP, typename F>
	static MAXON_ATTRIBUTE_FORCE_INLINE void ForEach(TUP&& tup, F&& func)
	{
		func(TupleGet<I>(std::forward<TUP>(tup)));
	}

	template <typename RET, typename TUP, typename F>
	static MAXON_ATTRIBUTE_FORCE_INLINE RET FoldLeft(const TUP& tup, const RET& v, F&& func)
	{
		return func(v, TupleGet<I>(tup));
	}

	template <typename RET, typename TUP, typename F>
	static MAXON_ATTRIBUTE_FORCE_INLINE RET FoldLeft(TUP&& tup, const RET& v, F&& func)
	{
		return func(v, TupleGet<I>(std::forward<TUP>(tup)));
	}
};

template <Int I> struct TupleRecHelper<I, 0>
{
	template <typename TUP, typename F>
	static MAXON_ATTRIBUTE_FORCE_INLINE void ForEach(const TUP& tup, F&& func) { }

	template <typename TUP, typename F>
	static MAXON_ATTRIBUTE_FORCE_INLINE void ForEach(TUP&& tup, F&& func) { }

	template <typename RET, typename TUP, typename F>
	static MAXON_ATTRIBUTE_FORCE_INLINE RET FoldLeft(const TUP& tup, const RET& v, F&& func) { return v; }

	template <typename RET, typename TUP, typename F>
	static MAXON_ATTRIBUTE_FORCE_INLINE RET FoldLeft(TUP&& tup, const RET& v, F&& func) { return v; }
};

}


//----------------------------------------------------------------------------------------
/// TupleExpand unpacks values from a tuple and passes them as arguments to a function, i.e.
/// a function F(TYPES ...) is called with the elements of a Tuple<TYPES ...>.
///
/// If tup is bound to a const&, it's elements will be passed by const&.
/// If tup is bound to a &, it's elements will be passed by &.
/// If tup is bound to a &&, it's elements will be passed by &&.
///
/// @param[in] tup								The expanded tuple.
/// @param[in] func								The function accepting the tuple elements as arguments.
/// @return												The return value of the called function.
//----------------------------------------------------------------------------------------

// Const lvalue ref
template <typename F, typename ... TYPES> inline auto TupleExpand(const Tuple<TYPES ...>& tup, F&& func)
	-> decltype(maxon::details::ExpandSeqHelperConst(tup, std::forward<F>(func), std::make_index_sequence<sizeof...(TYPES)>()))
{
	return maxon::details::ExpandSeqHelperConst(tup, std::forward<F>(func), std::make_index_sequence<sizeof...(TYPES)>());
}

// Lvalue ref
template <typename F, typename ... TYPES> inline auto TupleExpand(Tuple<TYPES ...>& tup, F&& func)
	-> decltype(maxon::details::ExpandSeqHelper(tup, std::forward<F>(func), std::make_index_sequence<sizeof...(TYPES)>()))
{
	return maxon::details::ExpandSeqHelper(tup, std::forward<F>(func), std::make_index_sequence<sizeof...(TYPES)>());
}

// Rvalue ref
template <typename F, typename ... TYPES> inline auto TupleExpand(Tuple<TYPES ...>&& tup, F&& func)
	-> decltype(maxon::details::ExpandSeqHelper(std::move(tup), std::forward<F>(func), std::make_index_sequence<sizeof...(TYPES)>()))
{
	return maxon::details::ExpandSeqHelper(std::move(tup), std::forward<F>(func), std::make_index_sequence<sizeof...(TYPES)>());
}

//----------------------------------------------------------------------------------------
/// A placeholder that can be assigned any value without having any effect.
/// This is useful in conjunction with Tie:
/// @code
/// Int x;
/// Tie(Ignore, x, Ignore) = FunctionReturningTupleOf3();
/// // We were only interested in the second element.
/// @endcode
///
/// Ignore is the equivalent of std::ignore.
//----------------------------------------------------------------------------------------
class IgnoredPlaceholder
{
public:
	IgnoredPlaceholder() { }

	template <typename T>
	void operator =(const T&) const	{ }
};

static const IgnoredPlaceholder Ignore;

//----------------------------------------------------------------------------------------
/// ToTuple is a helper function that takes a variable number of arguments and returns them as a tuple.
/// This function is decaying, so any const or reference modifiers will be stripped from the arguments,
/// i.e. if a const T& is passed in, it will be stored as a plain T.
/// ToTuple is the equivalent of std::make_tuple for std::tuple.
///
/// @param[in] args								Elements of the created tuple.
/// @return												A tuple containing args ... .
//----------------------------------------------------------------------------------------
template <typename ... TYPES> inline auto ToTuple(TYPES&& ... args) -> Tuple<typename std::decay<TYPES>::type ...>
{
	return Tuple<typename std::decay<TYPES>::type ...>(std::forward<TYPES>(args) ...);
}

//----------------------------------------------------------------------------------------
/// Tie takes a variable number of references and returns them packed as tuple of references.
/// This allows to leverage useful tuple operations, i.e. element-wise converting assignment.
/// Tie is the equivalent of std::tie for std::tuple.
///
/// The following example shows how to return a tuple of values from a function and use
/// Tie to simplify the unpacking:
/// @code
/// Int a; Int b;
/// Tie(a, b) = FunctionReturningTuple(x, y, z);
/// // ... is equivalent to ...
/// Int a; Int b;
/// Tuple<Int, Int> result = FunctionReturningTuple(x, y, z);
/// a = result.first;
/// b = result.second;
/// // ... is equivalent to ...
/// Int a; Int b;
/// FunctionWithRefOutArgs(x, y, z, a, b); // pass a, b as ref out arguments
/// @endcode
///
/// @param[in] args								A variable number of references.
/// @return												A tuple containing args& ... .
//----------------------------------------------------------------------------------------
template <typename... TYPES> inline auto Tie(TYPES& ... args) -> Tuple<TYPES& ...>
{
	return Tuple<TYPES& ...>(args ...);
}

//----------------------------------------------------------------------------------------
/// ToForwardTuple is similar to Tie, but instead of binding arguments to an lvalue reference,
/// it forwards them. This is useful when forwarding arguments into a function that accepts a tuple.
/// Tie is the equivalent of std::forward_as_tuple for std::tuple.
///
/// @param[in] args								A variable number of references.
/// @return												A tuple containing args&& ... .
//----------------------------------------------------------------------------------------
template <typename... TYPES> inline auto ToForwardTuple(TYPES&& ... args) -> Tuple<TYPES&& ...>
{
	return Tuple<TYPES&& ...>(std::forward<TYPES>(args) ...);
}

//----------------------------------------------------------------------------------------
/// TupleForEach applies the given function to all elements of the tuple. This means F must be
/// callable with all element types. This can be accomplished with a function template,
/// or a function object with several overloads.
///
/// @param[in] tup								The iterated tuple.
/// @param[in] func								A callable object, accepting each tuple element as argument.
//----------------------------------------------------------------------------------------
// Const lvalue ref
template <typename F, typename ... TYPES> inline void TupleForEach(const Tuple<TYPES ...>& tup, F&& func)
{
	return maxon::details::TupleRecHelper<0, sizeof...(TYPES)>::ForEach(tup, std::forward<F>(func));
}

// Lvalue ref
template <typename F, typename ... TYPES> inline void TupleForEach(Tuple<TYPES ...>& tup, F&& func)
{
	return maxon::details::TupleRecHelper<0, sizeof...(TYPES)>::ForEach(tup, std::forward<F>(func));
}

// Rvalue ref
template <typename F, typename ... TYPES> inline void TupleForEach(Tuple<TYPES ...>&& tup, F&& func)
{
	return maxon::details::TupleRecHelper<0, sizeof...(TYPES)>::ForEach(std::move(tup), std::forward<F>(func));
}

//----------------------------------------------------------------------------------------
/// TupleFold works similar to std::accumulate. It applies a binary function to an initial value and
/// the first element of the tuple, then repeats that for the result and the next element, and so on.
/// The last result is returned by the function.
/// Example:
/// @code
/// Tuple<Int, Int, Int> tup1(1, 10, 100);
/// Int res1 = TupleFold<Int>(t1, 1000, [] (Int a, Int b) { return a + b; });
/// // res1 is 1000 + 1 + 10 + 100
/// Tuple<String, String> tup2("Hello"_s, "World"_s);
/// Int res2 = TupleFold(t2, "Result:"_s, [] (String a, String b) { return a.Append(b); });
/// // res2 is "Result: Hello World"
/// @endcode
///
/// @param[in] tup								The folded tuple.
/// @param[in] initialValue				The initial value.
/// @param[in] func								A function accepting each tuple element as arguments.
/// @return												The folded result value.
//----------------------------------------------------------------------------------------
// Const lvalue ref
template <typename V, typename F, typename ... TYPES>
inline auto TupleFold(const Tuple<TYPES ...>& tup, const V& initialValue, F&& func) -> V
{
	return maxon::details::TupleRecHelper<0, sizeof...(TYPES)>::FoldLeft(tup, initialValue, std::forward<F>(func));
}

// Lvalue ref
template <typename V, typename F, typename ... TYPES>
inline auto TupleFold(Tuple<TYPES ...>& tup, const V& initialValue, F&& func) -> V
{
	return maxon::details::TupleRecHelper<0, sizeof...(TYPES)>::FoldLeft(tup, initialValue, std::forward<F>(func));
}

// Rvalue ref
template <typename V, typename F, typename ... TYPES>
inline auto TupleFold(Tuple<TYPES ...>&& tup, const V& initialValue, F&& func) -> V
{
	return maxon::details::TupleRecHelper<0, sizeof...(TYPES)>::FoldLeft(std::move(tup), initialValue, std::forward<F>(func));
}

//----------------------------------------------------------------------------------------
/// Pair<T1, T2> is an alias for Tuple<T1, T2>.
//----------------------------------------------------------------------------------------
template <typename T1, typename T2> using Pair = typename maxon::details::PairSelector<T1, T2>::type;

//----------------------------------------------------------------------------------------
/// Type alias to generate a tuple containing N times type T, i.e.
/// HomogenousTupleType<3, Int> is Tuple<Int, Int, Int>.
//----------------------------------------------------------------------------------------
template <Int N, typename T> using HomogenousTupleType = typename maxon::details::HomogenousTupleTypeHelper<N, T>::type;

//----------------------------------------------------------------------------------------
/// A utility class to generate a binary compare function that can be used to test if a specific tuple element equals another value.
/// Example:
/// @code
/// BaseArray<Tuple<String, Int>> data;
/// auto match1 = Find(data, ByValue(42, TupleElementEquals::ByIndex<1>()));
/// auto match2 = Find(data, ByValue("Hello"_s, TupleElementEquals::ByType<String>()));
/// @endcode
//----------------------------------------------------------------------------------------
struct TupleElementEquals
{
	/// Functor that takes a tuple t and a value v as arguments and returns t.Get<INDEX> == v.
	template <Int INDEX> struct ByIndex
	{
		template <typename TUP, typename VALUE>
		Bool operator ()(const TUP& tup, const VALUE& val) const { return TupleGet<INDEX>(tup) == val; }
	};

	/// Functor that takes a tuple t and a value v as arguments and returns t.Get<ELEMENTTYPE> == v.
	template <typename ELEMENTTYPE> struct ByType
	{
		template <typename TUP, typename VALUE>
		Bool operator ()(const TUP& tup, const VALUE& val) const { return TupleGet<ELEMENTTYPE>(tup) == val; }
	};
};

//----------------------------------------------------------------------------------------
/// A utility class to generate a binary compare function that can be used to test if a specific tuple element is less than another value.
/// Example:
/// @code
/// BaseArray<Tuple<String, Int>> data;
/// auto match1 = Find(data, ByValue(42, TupleElementLessThan::ByIndex<1>()));
/// auto match2 = Find(data, ByValue(43, TupleElementLessThan::ByType<Int>()));
/// @endcode
//----------------------------------------------------------------------------------------
struct TupleElementLessThan
{
	/// Functor that takes a tuple t and a value v as arguments and returns t.Get<INDEX> < v.
	template <Int INDEX> struct ByIndex
	{
		template <typename TUP, typename VALUE>
		Bool operator ()(const TUP& tup, const VALUE& val) const { return TupleGet<INDEX>(tup) < val; }
	};

	/// Functor that takes a tuple t and a value v as arguments and returns t.Get<INDEX> < v.
	template <typename ELEMENTTYPE> struct ByType
	{
		template <typename TUP, typename VALUE>
		Bool operator ()(const TUP& tup, const VALUE& val) const { return TupleGet<ELEMENTTYPE>(tup) < val; }
	};
};

//----------------------------------------------------------------------------------------
/// A compare class that provides element-wise LessThan and IsEqual functions for tuples.
/// Elements are selected by index or by type.
/// Example:
/// @code
/// BaseArray<Tuple<String, Int>> data;
/// SimpleSort<TupleElementCompare::ByIndex<1>()> s1;
/// SimpleSort<TupleElementCompare::ByType<String>()> s2;
/// s1.Sort(data); // Sort by second attribute
/// s2.Sort(data); // Sort by first attribute
/// @endcode
//----------------------------------------------------------------------------------------
struct TupleElementCompare
{
	template <Int INDEX> struct ByIndex
	{
		template <typename T1, typename T2> static Bool LessThan(const T1& a, const T2& b)
		{
			return TupleGet<INDEX>(a) < TupleGet<INDEX>(b);
		}

		template <typename T1, typename T2> static Bool LessThanOrEqual(const T1& a, const T2& b)
		{
			return TupleGet<INDEX>(a) <= TupleGet<INDEX>(b);
		}

		template <typename T1, typename T2> static Bool IsEqual(const T1& a, const T2& b)
		{
			return TupleGet<INDEX>(a) == TupleGet<INDEX>(b);
		}
	};

	template <typename ELEMENTTYPE> struct ByType
	{
		template <typename T1, typename T2> static Bool LessThan(const T1& a, const T2& b)
		{
			return TupleGet<ELEMENTTYPE>(a) < TupleGet<ELEMENTTYPE>(b);
		}

		template <typename T1, typename T2> static Bool LessThanOrEqual(const T1& a, const T2& b)
		{
			return TupleGet<ELEMENTTYPE>(a) <= TupleGet<ELEMENTTYPE>(b);
		}

		template <typename T1, typename T2> static Bool IsEqual(const T1& a, const T2& b)
		{
			return TupleGet<ELEMENTTYPE>(a) == TupleGet<ELEMENTTYPE>(b);
		}
	};
};

} // namespace maxon

#endif // TUPLE_H__
