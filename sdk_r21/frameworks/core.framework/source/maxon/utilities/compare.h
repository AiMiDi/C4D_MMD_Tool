#ifndef COMPARE_H__
#define COMPARE_H__

#ifndef APIBASE_H__
	#error "Do not include this file directly"
#endif

/// @file
/// Helper classes and functions for comparisons.

namespace maxon
{

/// @addtogroup DATATYPE
/// @{

//----------------------------------------------------------------------------------------
/// Data type for comparison results.
//----------------------------------------------------------------------------------------
enum class COMPARERESULT
{
	LESS				 = -1,	///< result is less than
	EQUAL				 =  0,	///< result is equal
	GREATER			 =  1,	///< result is greater than
	INCOMPARABLE = -2		///< values are incomparable (either a compare function doesn't exist, or we have a partial order)
} MAXON_ENUM_ORDERED_LIST(COMPARERESULT, "net.maxon.datatype.enum.compareresult", EARLY);


//----------------------------------------------------------------------------------------
/// EQUALITY is used for the second parameter of the IsEqual-function of collections.
/// It controls whether the collection shall do the equality check on its values using == or IsEqual.
//----------------------------------------------------------------------------------------
enum class EQUALITY
{
	SHALLOW,	///< A shallow equality-test shall be done. For pointers or (non-copy-on-write) references the object identity (pointer value) is used.
	DEEP			///< A deep equality-test shall be done. For pointers or (non-copy-on-write) references the referenced objects are compared for equality.
} MAXON_ENUM_LIST(EQUALITY, "net.maxon.datatype.enum.equality", EARLY);


class StrongRefHandler;
class PointerHandler;

namespace details
{
extern const COMPARERESULT g_compareResultIncomparable;
}

//----------------------------------------------------------------------------------------
/// This class implements default compare and hash functions. They are used at various places such as DataType or HashMap.
/// The class defines IsEqual and GetHashCode for the following cases:
///  - arithmetic and enumeration values
///  - pointers (where different pointers are assumed to be different keys, so only the address is considered, not the content)
///  - strong non-copy-on-write references (using their pointer)
///  - objects whose type has a GetHashCode member function and which can be compared with ==
/// The class defines Compare for the following cases:
///  - arithmetic values
///
/// For any other case you can specialize the template functions of DefaultCompare,
/// or you have to define your own comparison and hash function class, see CStringCompare for the case of C-strings.
///
/// Note that hashes are not meant to be stored in files as they are only valid during runtime. The datatype for hashes is UInt which is variable in width.
//----------------------------------------------------------------------------------------
template <Bool ALLOW_UNDEFINED, EQUALITY EQ = EQUALITY::SHALLOW, typename OPERATOR_RANK = OverloadRank5> class CompareTemplate
{
public:
	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE COMPARERESULT Compare(const T1& a, const T2& b)
	{
		return CompareHelper(reinterpret_cast<const UnderlyingType<T1>&>(a), reinterpret_cast<const UnderlyingType<T2>&>(b), OVERLOAD_MAX_RANK);
	}

#ifdef MAXON_TARGET_64BIT
	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(UInt32 i)
	{
		// From Sun's implementation of java.util.HashMap:
		// Applies a supplemental hash function to a given hashCode, which defends against poor quality hash functions.
		// This is critical because HashMap uses power-of-two length hash tables, that otherwise encounter collisions
		// for hashCodes that do not differ in lower bits. Note: Null keys always map to hash 0, thus index 0.
		UInt h = i;
		h ^= (h >> 20) ^ (h >> 12);
		return h ^ (h >> 7) ^ (h >> 4);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(UInt64 h)
	{
		h ^= h >> 32;
		h ^= (h >> 20) ^ (h >> 12);
		return h ^ (h >> 7) ^ (h >> 4);
	}
#else
	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(UInt32 h)
	{
		h ^= (h >> 20) ^ (h >> 12);
		return h ^ (h >> 7) ^ (h >> 4);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(UInt64 h)
	{
		return GetHashCode((UInt32) (h ^ (h >> 32)));
	}
#endif
	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(Bool i)
	{
		return GetHashCode((UInt32) i);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(Char i)
	{
		return GetHashCode((UInt32) i);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(UChar i)
	{
		return GetHashCode((UInt32) i);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(Int16 i)
	{
		return GetHashCode((UInt32) i);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(UInt16 i)
	{
		return GetHashCode((UInt32) i);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(Int32 h)
	{
		return GetHashCode((UInt32) h);
	}

	static UInt GetHashCode(Utf16Char i)
	{
		return GetHashCode((UInt16)i);
	}

	static UInt GetHashCode(Utf32Char i)
	{
		return GetHashCode((UInt32)i);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(Int64 h)
	{
		return GetHashCode((UInt64) h);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(Float32 h)
	{
		return GetHashCode(*(UInt32*) &h);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(Float64 h)
	{
		return GetHashCode(*(UInt64*) &h);
	}

	template <typename T> static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(const T* key)
	{
		return GetHashCode((UInt) key);
	}

	template <typename T> static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(T* key)
	{
		return GetHashCode((UInt) key);
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(std::nullptr_t)
	{
		return GetHashCode((void*) nullptr);
	}

	template <typename E> static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(const maxon::details::EnumWrapper<E>& key)
	{
		return GetHashCode(typename std::underlying_type<E>::type(key.value));
	}

	template <typename K> static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(const K& key)
	{
		return GetHashCodeHelper<K>(key, OVERLOAD_MAX_RANK);
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE Bool IsEqual(const T1& a, const T2& b)
	{
		return IsEqualHelper(reinterpret_cast<const UnderlyingType<T1>&>(a), reinterpret_cast<const UnderlyingType<T2>&>(b), OVERLOAD_MAX_RANK);
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE Bool LessThan(const T1& a, const T2& b)
	{
		return LessThanHelper(reinterpret_cast<const UnderlyingType<T1>&>(a), reinterpret_cast<const UnderlyingType<T2>&>(b), OVERLOAD_MAX_RANK);
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE Bool LessThanOrEqual(const T1& a, const T2& b)
	{
		return LessThanOrEqualHelper(reinterpret_cast<const UnderlyingType<T1>&>(a), reinterpret_cast<const UnderlyingType<T2>&>(b), OVERLOAD_MAX_RANK);
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE const COMPARERESULT& CompareHelper(const T1& a, const T2& b, OverloadRank0)
	{
		// We use the return type "const COMPARERESULT&" in DefaultDataTypeFunctionsFlags to detect this overload.
		static_assert(ALLOW_UNDEFINED, "Compare not defined.");
		CriticalStop();
		return maxon::details::g_compareResultIncomparable;
	}

#ifdef MAXON_TARGET_WINDOWS
	static COMPARERESULT DecltypeCompareHelper(Bool);
#endif

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE auto CompareHelper(const T1& a, const T2& b, OverloadRank1) ->
#ifdef MAXON_TARGET_WINDOWS
		decltype(DecltypeCompareHelper(a < b)) // TODO: (Ole) remove hack when MSVC supports decltype properly
#else
		decltype((a < b) ? COMPARERESULT::LESS : COMPARERESULT::EQUAL)
		// It is important that the result of a < b is used in decltype: This avoids that the private comparison functions
		// of RefBaseFunctions enable this overload. These functions return void, which cannot be used as first operand of ?:.
#endif
	{
		return (a < b) ? COMPARERESULT::LESS : (b < a) ? COMPARERESULT::GREATER : COMPARERESULT::EQUAL;
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE auto CompareHelper(const T1& a, const T2& b, OverloadRank2) -> decltype(a.Compare(b))
	{
		return a.Compare(b);
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE typename SFINAEHelper<COMPARERESULT, typename T1::PartiallyOrdered>::type CompareHelper(const T1& a, const T2& b, OverloadRank3)
	{
		return LessThanHelper(a, b, OVERLOAD_MAX_RANK) ? COMPARERESULT::LESS : LessThanHelper(b, a, OVERLOAD_MAX_RANK) ? COMPARERESULT::GREATER : IsEqualHelper(a, b, OVERLOAD_MAX_RANK) ? COMPARERESULT::EQUAL : COMPARERESULT::INCOMPARABLE;
	}

private:
	template <typename T> friend struct DefaultDataTypeFunctionsCapabilityFlags;

	template <typename K1, typename K2> static MAXON_ATTRIBUTE_FORCE_INLINE Bool IsEqualHelper(const K1& a, const K2& b, OverloadRank0)
	{
		static_assert(ALLOW_UNDEFINED, "IsEqual not defined.");
		CriticalStop();
		return false;
	}

	static Bool DecltypeIsEqualHelper(COMPARERESULT);

	template <typename K1, typename K2> static MAXON_ATTRIBUTE_FORCE_INLINE auto IsEqualHelper(const K1& a, const K2& b, OverloadRank2) -> decltype(DecltypeIsEqualHelper(a.Compare(b)))
	{
		return a.Compare(b) == COMPARERESULT::EQUAL;
	}

	template <typename K1, typename K2> static MAXON_ATTRIBUTE_FORCE_INLINE auto IsEqualHelper(const K1& a, const K2& b, OverloadRank3) -> decltype(a.IsEqual(b))
	{
		return a.IsEqual(b);
	}

	template <typename K1, typename K2> static MAXON_ATTRIBUTE_FORCE_INLINE auto IsEqualHelper(const K1& a, const K2& b, OverloadRank4) -> decltype(a.IsEqual(b, EQ))
	{
		return a.IsEqual(b, EQ);
	}

	template <typename K1, typename K2> static MAXON_ATTRIBUTE_FORCE_INLINE auto IsEqualHelper(const K1& a, const K2& b, OPERATOR_RANK) -> decltype(a == b)
	{
		return a == b;
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE Bool LessThanOrEqualHelper(const T1& a, const T2& b, OverloadRank0)
	{
		static_assert(ALLOW_UNDEFINED, "LessThanOrEqual not defined.");
		CriticalStop();
		return false;
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE auto LessThanOrEqualHelper(const T1& a, const T2& b, OverloadRank1) -> decltype(a.LessThan(b))
	{
		return a.IsEqual(b) || a.LessThan(b);
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE auto LessThanOrEqualHelper(const T1& a, const T2& b, OverloadRank2) -> decltype(a.LessThanOrEqual(b))
	{
		return a.LessThanOrEqual(b);
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE auto LessThanOrEqualHelper(const T1& a, const T2& b, OverloadRank3) -> decltype(a <= b)
	{
		return a <= b;
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE Bool LessThanHelper(const T1& a, const T2& b, OverloadRank0)
	{
		static_assert(ALLOW_UNDEFINED, "LessThan not defined.");
		CriticalStop();
		return false;
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE auto LessThanHelper(const T1& a, const T2& b, OverloadRank1) -> decltype(a.LessThan(b))
	{
		return a.LessThan(b);
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE auto LessThanHelper(const T1& a, const T2& b, OverloadRank2) -> decltype(a < b)
	{
		return a < b;
	}

	template <typename K> static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCodeHelper(const K& key, OverloadRank0)
	{
		static_assert(ALLOW_UNDEFINED, "GetHashCode not defined.");
		CriticalStop();
		return 0;
	}

	template <typename K> static MAXON_ATTRIBUTE_FORCE_INLINE auto GetHashCodeHelper(const K& key, OverloadRank1) -> decltype(key.GetHashCode())
	{
		return key.GetHashCode();
	}

	template <typename K> static MAXON_ATTRIBUTE_FORCE_INLINE typename std::enable_if<std::is_enum<K>::value, UInt>::type GetHashCodeHelper(const K& key, OverloadRank2)
	{
		return GetHashCode(typename std::underlying_type<K>::type(key));
	}
};

class DefaultCompare : public CompareTemplate<false>
{
};

class EqualityCompare : public CompareTemplate<false, EQUALITY::DEEP, OverloadRank1>
{
};

/// This class can be used as template argument for a HashMap if the HashMap shall use C-string keys.
class CStringCompare
{
public:
	static UInt GetHashCode(const Char* key)
	{
		UInt hash = 0;
		if (key)
		{
			while (*key)
			{
				hash = 31 * hash + UChar(*key);
				++key;
			}
		}
		return hash;
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE Bool IsEqual(const Char* a, const Char* b)
	{
		return (a == b) || (a && b && (strcmp(a, b) == 0));
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE COMPARERESULT Compare(const Char* a, const Char* b)
	{
		int res = strcmp(a, b);
		return (res < 0) ? COMPARERESULT::LESS : (res > 0) ? COMPARERESULT::GREATER : COMPARERESULT::EQUAL;
	}
};


template <Bool COW, Bool IS_INTERFACE> class RefCompare
{
public:
	template <typename K> static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(const K& key)
	{
		return DefaultCompare::GetHashCode(Dereference<K>::GetPointer(key));
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE Bool IsEqual(const T1& a, const T2& b)
	{
		return Dereference<T1>::GetPointer(a) == Dereference<T2>::GetPointer(b);
	}
};

template <> class RefCompare<true, false>
{
public:
	template <typename K> static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(const K& key)
	{
		const auto* a = Dereference<K>::GetPointer(key);
		if (!a)
			a = &NullValue<const typename std::remove_pointer<K>::type&>();
		return DefaultCompare::GetHashCode(*a);
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE Bool IsEqual(const T1& a, const T2& b)
	{
		static_assert(!std::is_same<T1, std::nullptr_t>::value && !std::is_same<T2, std::nullptr_t>::value, "Comparison with nullptr is not supported for copy-on-write references.");
		return IsEqualHelper(Dereference<T1>::GetPointer(a), Dereference<T2>::GetPointer(b), OVERLOAD_MAX_RANK);
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE Bool LessThan(const T1& a, const T2& b)
	{
		static_assert(!std::is_same<T1, std::nullptr_t>::value && !std::is_same<T2, std::nullptr_t>::value, "Comparison with nullptr is not supported for copy-on-write references.");
		return LessThanHelper(Dereference<T1>::GetPointer(a), Dereference<T2>::GetPointer(b), OVERLOAD_MAX_RANK);
	}

	template <typename T> static Bool IsEqualHelper(const T* a, const T* b, OverloadRank0)
	{
		if (a == b)
			return true;
		if (!a)
			a = &NullValue<const T&>();
		if (!b)
			b = &NullValue<const T&>();
		return *a == *b;
	}

	template <typename T> static auto IsEqualHelper(const T* a, const T* b, OverloadRank1) -> decltype(a->IsEqual(*b))
	{
		if (a == b)
			return true;
		if (!a)
			a = &NullValue<const T&>();
		if (!b)
			b = &NullValue<const T&>();
		return a->IsEqual(*b);
	}

	template <typename T> static auto IsEqualHelper(const T* a, const T* b, OverloadRank2) -> decltype(a->IsEqual(*b, EQUALITY::SHALLOW))
	{
		if (a == b)
			return true;
		if (!a)
			a = &NullValue<const T&>();
		if (!b)
			b = &NullValue<const T&>();
		return a->IsEqual(*b, EQUALITY::SHALLOW);
	}

	template <typename T> static Bool LessThanHelper(const T* a, const T* b, OverloadRank0)
	{
		if (a == b)
			return false;
		if (!a)
			a = &NullValue<const T&>();
		if (!b)
			b = &NullValue<const T&>();
		return a->Compare(*b) == COMPARERESULT::LESS;
	}

	template <typename T> static auto LessThanHelper(const T* a, const T* b, OverloadRank1) -> decltype(a->LessThan(*b))
	{
		if (a == b)
			return false;
		if (!a)
			a = &NullValue<const T&>();
		if (!b)
			b = &NullValue<const T&>();
		return a->LessThan(*b);
	}
};

template <> class RefCompare<true, true>
{
public:
	template <typename K> static MAXON_ATTRIBUTE_FORCE_INLINE UInt GetHashCode(const K& key)
	{
		const auto* a = Dereference<K>::GetPointer(key);
		if (!a)
		{
			a = std::remove_pointer<K>::type::NullValuePtr();
			if (!a)
				return 0;
		}
		return DefaultCompare::GetHashCode(*a);
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE Bool IsEqual(const T1& a, const T2& b)
	{
		static_assert(!std::is_same<T1, std::nullptr_t>::value && !std::is_same<T2, std::nullptr_t>::value, "Comparison with nullptr is not supported for copy-on-write references.");
		return IsEqualHelper(Dereference<T1>::GetPointer(a), Dereference<T2>::GetPointer(b), OVERLOAD_MAX_RANK);
	}

	template <typename T1, typename T2> static MAXON_ATTRIBUTE_FORCE_INLINE Bool LessThan(const T1& a, const T2& b)
	{
		static_assert(!std::is_same<T1, std::nullptr_t>::value && !std::is_same<T2, std::nullptr_t>::value, "Comparison with nullptr is not supported for copy-on-write references.");
		return LessThanHelper(Dereference<T1>::GetPointer(a), Dereference<T2>::GetPointer(b), OVERLOAD_MAX_RANK);
	}

	template <typename T> static Bool IsEqualHelper(const T* a, const T* b, OverloadRank0)
	{
		if (a == b)
			return true;
		if (!a)
		{
			a = T::NullValuePtr();
			if (!a)
				return false;
		}
		return a->Compare(b) == COMPARERESULT::EQUAL;
	}

	template <typename T> static auto IsEqualHelper(const T* a, const T* b, OverloadRank1) -> decltype(a->IsEqual(b))
	{
		if (a == b)
			return true;
		if (!a)
		{
			a = T::NullValuePtr();
			if (!a)
				return false;
		}
		return a->IsEqual(b);
	}

	template <typename T> static auto IsEqualHelper(const T* a, const T* b, OverloadRank2) -> decltype(a->IsEqual(b, EQUALITY::SHALLOW))
	{
		if (a == b)
			return true;
		if (!a)
		{
			a = T::NullValuePtr();
			if (!a)
				return false;
		}
		return a->IsEqual(b, EQUALITY::SHALLOW);
	}

	template <typename T> static Bool LessThanHelper(const T* a, const T* b, OverloadRank0)
	{
		if (a == b)
			return false;
		if (!a)
		{
			a = T::NullValuePtr();
			if (!a)
				return true;
		}
		return a->Compare(b) == COMPARERESULT::LESS;
	}

	template <typename T> static auto LessThanHelper(const T* a, const T* b, OverloadRank1) -> decltype(a->LessThan(b))
	{
		if (a == b)
			return false;
		if (!a)
		{
			a = T::NullValuePtr();
			if (!a)
				return true;
		}
		return a->LessThan(b);
	}
};


template <Bool ALLOW_UNDEFINED = false> inline Bool LexicographicalGreaterThan()
{
	return false;
}

//----------------------------------------------------------------------------------------
/// Lexicographically compares the tuple (a1, a2, ...) against (b1, b2, ...).
/// (a1, a2) is greater than (b1, b2) if a1 > b1, or if a1 == b1 and a2 > b2 (and so forth for the remaining tuple elements). In other words,
/// the first pair ai, bi which is not equal determines the relationship between the tuples.
/// @param[in] a1									First value of first tuple.
/// @param[in] b1									First value of second tuple.
/// @param[in] ab									The remaining values of the tuples (in the order a2, b2, a3, b3, ...).
/// @return												True if (a1, a2, ...) is lexicographically greater than (b1, b2, ...).
//----------------------------------------------------------------------------------------
template <Bool ALLOW_UNDEFINED = false, typename T1, typename... TN> inline Bool LexicographicalGreaterThan(const T1& a1, const T1& b1, const TN&... ab)
{
	COMPARERESULT cmp = CompareTemplate<ALLOW_UNDEFINED>::Compare(a1, b1);
	return (cmp == COMPARERESULT::GREATER) || ((cmp == COMPARERESULT::EQUAL) && LexicographicalGreaterThan<ALLOW_UNDEFINED>(ab...));
}


template <Bool ALLOW_UNDEFINED = false> inline Bool LexicographicalLessThan()
{
	return false;
}

//----------------------------------------------------------------------------------------
/// Lexicographically compares the tuple (a1, a2, ...) against (b1, b2, ...).
/// (a1, a2) is less than (b1, b2) if a1 < b1, or if a1 == b1 and a2 < b2 (and so forth for the remaining tuple elements). In other words,
/// the first pair ai, bi which is not equal determines the relationship between the tuples.
/// @param[in] a1									First value of first tuple.
/// @param[in] b1									First value of second tuple.
/// @param[in] ab									The remaining values of the tuples (in the order a2, b2, a3, b3, ...).
/// @return												True if (a1, a2, ...) is lexicographically less than (b1, b2, ...).
//----------------------------------------------------------------------------------------
template <Bool ALLOW_UNDEFINED = false, typename T1, typename... TN> inline Bool LexicographicalLessThan(const T1& a1, const T1& b1, const TN&... ab)
{
	COMPARERESULT cmp = CompareTemplate<ALLOW_UNDEFINED>::Compare(a1, b1);
	return (cmp == COMPARERESULT::LESS) || ((cmp == COMPARERESULT::EQUAL) && LexicographicalLessThan<ALLOW_UNDEFINED>(ab...));
}


template <Bool ALLOW_UNDEFINED = false> inline COMPARERESULT LexicographicalCompare()
{
	return COMPARERESULT::EQUAL;
}

//----------------------------------------------------------------------------------------
/// Lexicographically compares the tuple (a1, a2, ...) against (b1, b2, ...). For the lexicographic order,
/// (a1, a2) is greater than (b1, b2) if a1 > b1, or if a1 == b1 and a2 > b2 (and so forth for the remaining tuple elements). If all values
/// are equal, the tuples are equal, in the remaining cases (a1, a2) is less than (b1, b2). In other words,
/// the first pair ai, bi which is not equal determines the relationship between the tuples.
/// @param[in] a1									First value of first tuple.
/// @param[in] b1									First value of second tuple.
/// @param[in] ab									The remaining values of the tuples (in the order a2, b2, a3, b3, ...).
/// @return												Lexicographic comparison of the tuples (a1, a2, ...), (b1, b2, ...).
//----------------------------------------------------------------------------------------
template <Bool ALLOW_UNDEFINED = false, typename T1, typename... TN> inline COMPARERESULT LexicographicalCompare(const T1& a1, const T1& b1, const TN&... ab)
{
	COMPARERESULT cmp = CompareTemplate<ALLOW_UNDEFINED>::Compare(a1, b1);
	return (cmp != COMPARERESULT::EQUAL) ? cmp : LexicographicalCompare<ALLOW_UNDEFINED>(ab...);
}

/// @}

}

#endif // COMPARE_H__
