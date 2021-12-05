#ifndef COLLECTION_H__
#define COLLECTION_H__

#include "maxon/foreach.h"
#include "maxon/delegate.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{


template <typename C> inline Int PrivateGetCount(const C& collection, OverloadRank0)
{
	return -1;
}

template <typename T, Int N> inline Int PrivateGetCount(T (&array)[N], OverloadRank1)
{
	return N;
}

template <typename C> inline typename SFINAEHelper<Int, typename C::IsCollection>::type PrivateGetCount(const C& collection, OverloadRank2)
{
	return collection.GetCount();
}


//----------------------------------------------------------------------------------------
/// Returns the number of elements of @p iterable. If the iterable is
/// a collection or a C++ array, the true number of
/// elements is returned, otherwise (e.g., for an iterator) -1.
/// @param[in] iterable						Some @ref iterables_predicates "iterable object".
/// @return												Element count of the iterable object, or -1 if the count is unknown.
//----------------------------------------------------------------------------------------
template <typename ITERABLE> inline Int GetCount(const ITERABLE& iterable)
{
	return PrivateGetCount(iterable, OVERLOAD_MAX_RANK);
}


template <typename SET, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE Bool PrivateContains(const SET& set, const KEY& key, OverloadRank0)
{
	return set(key);
}

template <typename T, Int N, typename KEY> inline Bool PrivateContains(T (&array)[N], const KEY& key, OverloadRank1)
{
	for (const T& x : array)
	{
		if (x == key)
			return true;
	}
	return false;
}

template <typename SET, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE auto PrivateContains(const SET& set, const KEY& key, OverloadRank1) -> decltype(set.Contains(key))
{
	return set.Contains(key);
}

template <typename SET, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE typename SFINAEHelper<Bool, typename SET::IsCollection>::type PrivateContains(const SET& set, const KEY& key, OverloadRank2)
{
	return set.Contains(key);
}


//----------------------------------------------------------------------------------------
/// Checks if @p key is contained in the set defined by @p predicate. @p predicate has to be of a @ref iterables_predicates "predicate type", i.e., either
/// a collection, a C++ array, an object with @c Contains function or a Bool-valued unary function object.
/// @param[in] predicate					Some predicate object.
/// @param[in] key								Key to look up in the predicate object.
/// @return												True if @p key is contained in @p predicate.
//----------------------------------------------------------------------------------------
template <typename PREDICATE, typename KEY> MAXON_ATTRIBUTE_FORCE_INLINE Bool Contains(const PREDICATE& predicate, const KEY& key)
{
	return PrivateContains(predicate, key, OVERLOAD_MAX_RANK);
}



template <typename COMPARE, typename T1, typename T2> MAXON_ATTRIBUTE_FORCE_INLINE Bool PrivateIsEqual(COMPARE&& cmp, const T1& a, const T2& b, OverloadRank0)
{
	return cmp(a, b);
}

template <typename COMPARE, typename T1, typename T2> MAXON_ATTRIBUTE_FORCE_INLINE auto PrivateIsEqual(COMPARE&& cmp, const T1& a, const T2& b, OverloadRank1) -> decltype(cmp.IsEqual(a, b))
{
	return cmp.IsEqual(a, b);
}

//----------------------------------------------------------------------------------------
/// Checks if #a and #b are equal according to the given #predicate. The #predicate has to be
/// either an object callable with two parameters (such as a lambda), or an object with a function
/// IsEqual with two parameters.
/// @param[in] predicate					Some predicate object.
/// @param[in] a									First value to compare for equality.
/// @param[in] b									Second value to compare for equality.
/// @return												True if #a and #b are equal according to #predicate.
//----------------------------------------------------------------------------------------
template <typename PREDICATE, typename T1, typename T2> MAXON_ATTRIBUTE_FORCE_INLINE Bool IsEqual(PREDICATE&& predicate, const T1& a, const T2& b)
{
	return PrivateIsEqual(predicate, a, b, OVERLOAD_MAX_RANK);
}


MAXON_MEMBERTYPE_DETECTOR(IsCollection, IsCollection, std::false_type);

class PrivateGetMapKeyHelper
{
public:
	template <typename KEY> static const KEY& GetMapKey(const KEY& key)
	{
		return key;
	}
};

template <typename C> class PrivateGetMapKey : public std::conditional<IsCollection<C>::value, typename std::decay<C>::type, PrivateGetMapKeyHelper>::type
{
};


/// Flags for Resize(). Depending on the type of collection the flags might be ignored (except for ON_GROW_UNINITIALIZED).
enum class COLLECTION_RESIZE_FLAGS
{
	NONE										= 0,

	ON_SHRINK_KEEP_CAPACITY	= 0,				///< Don't change capacity.
	ON_SHRINK_FIT_TO_SIZE		= (1 << 0),	///< Copy the array to a new memory block that is as small as possible to hold the data.

	ON_GROW_RESERVE_CAPACITY	= 0,			///< Allocate some extra capacity (based on ComputeArraySize()).
	ON_GROW_FIT_TO_SIZE			= (1 << 1),	///< Grow the array exactly to the requested size.

	ON_GROW_UNINITIALIZED		= (1 << 2),	///< Do not initialize added elements (usually PODs) when resizing the array (is supported by all collections).

	FIT_TO_SIZE							= ON_SHRINK_FIT_TO_SIZE | ON_GROW_FIT_TO_SIZE,	///< Fits the array to the requested size for growing and shrinking.
	DEFAULT									= ON_SHRINK_KEEP_CAPACITY | ON_GROW_FIT_TO_SIZE,	///< The default is to keep capacity on shrink and fit to size when growing the array.
	POD_UNINITIALIZED				= DEFAULT | ON_GROW_UNINITIALIZED
} MAXON_ENUM_FLAGS(COLLECTION_RESIZE_FLAGS, "net.maxon.datatype.enum.collection_resize_flags", EARLY);


template <typename COLLECTION> class GetCollectionKind<COLLECTION, typename SFINAEHelper<void, typename std::decay<COLLECTION>::type::IsCollection>::type>
{
public:
	static const COLLECTION_KIND value = std::decay<COLLECTION>::type::KIND;
};



//----------------------------------------------------------------------------------------
/// This helper functions serves a similar purpose as std::forward<X>(x). But in ValueForward<COLLECTION>(x),
/// COLLECTION need not be the type of x itself, but can be an arbitrary type. If COLLECTION a collection type (but not a reference type to a collection type),
/// x is forwarded as r-value reference, otherwise as l-value reference. The typical usage is in a function
/// template which receives some collection via a parameter <tt>COLLECTION&& collection</tt> (with COLLECTION being a template parameter),
/// and where the values of the collection shall be forwarded to another function. If a collection is passed
/// as r-value to the function, its values should passed as r-values, too, to the other function. Example:
/// @code
/// template <typename COLLECTION> Result<void> AppendAllImpl(COLLECTION&& other)
/// {
///		iferr_scope;
///		for (auto&& i : std::forward<COLLECTION>(other))
/// 	{
/// 		this->Append(ValueForward<COLLECTION>(i)) iferr_return;
/// 	}
///		return OK;
/// }
/// @endcode
/// @param[in] x									The value to forward.
/// @tparam COLLECTION						A type to determine if x shall be forwarded as r-value (COLLECTION is a collection type, but not a reference type) or l-value (otherwise).
/// @return												The forwarded value.
//----------------------------------------------------------------------------------------
template <typename COLLECTION, typename T> inline typename std::conditional<!std::is_reference<COLLECTION>::value && (GetCollectionKind<COLLECTION>::value != COLLECTION_KIND::NONE), T&&, T&>::type ValueForward(T& x)
{
	return static_cast<typename std::conditional<!std::is_reference<COLLECTION>::value && (GetCollectionKind<COLLECTION>::value != COLLECTION_KIND::NONE), T&&, T&>::type>(x);
};


//----------------------------------------------------------------------------------------
/// This helper functions serves a similar purpose as std::forward<X>(x). It receives a
/// Block and returns the same block: Either as it is, or cast to a MoveBlock. The latter
/// case happens when COLLECTION is a collection type (but not a reference type to a collection type). The typical usage is in a function
/// template which receives some collection via a parameter <tt>COLLECTION&& collection</tt> (with COLLECTION being a template parameter),
/// and where blocks of values of the collection shall be forwarded to another function. If a collection is passed
/// as r-value to the function, its blocks should passed as MoveBlocks to the other function.
/// @see ValueForward
/// @param[in] block							The block to forward.
/// @tparam COLLECTION						A type to determine if x shall be forwarded as r-value (COLLECTION is a collection type, but not a reference type) or l-value (otherwise).
/// @return												The forwarded block.
//----------------------------------------------------------------------------------------
template <typename COLLECTION, typename T, Bool STRIDED> inline const Block<T, STRIDED, !std::is_reference<COLLECTION>::value && (GetCollectionKind<COLLECTION>::value != COLLECTION_KIND::NONE)>& BlockForward(const Block<T, STRIDED>& block)
{
	return reinterpret_cast<const Block<T, STRIDED, !std::is_reference<COLLECTION>::value && (GetCollectionKind<COLLECTION>::value != COLLECTION_KIND::NONE)>&>(block);
};


//----------------------------------------------------------------------------------------
/// BaseCollection is a helper template to be used as base class for collections which have Begin()/End() functions returning iterators, and a GetCount() function.
/// It will then add iterator-based utility functions such as ToString.
/// @tparam COLLECTION						The actual collection class, this has to have BaseCollection as (direct or indirect) base class.
/// @tparam SUPER									The class to be used as base class for BaseCollection.
/// @see @$ref collections
//----------------------------------------------------------------------------------------
template <typename COLLECTION, typename SUPER> class BaseCollection : public SUPER
{
public:
	template <typename... ARGS> MAXON_ATTRIBUTE_FORCE_INLINE explicit BaseCollection(ARGS&&... args) : SUPER(std::forward<ARGS>(args)...) { }

	using IsCollection = std::true_type;

	template <typename COLLECTION2> MAXON_ATTRIBUTE_FORCE_INLINE typename std::enable_if<maxon::IsCollection<COLLECTION2>::value, Bool>::type operator ==(const COLLECTION2& other) const
	{
		static_assert(COLLECTION::KIND == COLLECTION2::KIND, "Can't check collections of different kinds for equality.");
		return static_cast<const COLLECTION*>(this)->IsEqualImpl(other, DefaultCompare(), OVERLOAD_MAX_RANK);
	}

	template <typename COLLECTION2> MAXON_ATTRIBUTE_FORCE_INLINE typename std::enable_if<maxon::IsCollection<COLLECTION2>::value, Bool>::type operator !=(const COLLECTION2& other) const
	{
		static_assert(COLLECTION::KIND == COLLECTION2::KIND, "Can't check collections of different kinds for equality.");
		return !static_cast<const COLLECTION*>(this)->IsEqualImpl(other, DefaultCompare(), OVERLOAD_MAX_RANK);
	}

	template <typename COMPARE = EqualityCompare, typename COLLECTION2> MAXON_ATTRIBUTE_FORCE_INLINE typename std::enable_if<maxon::IsCollection<COLLECTION2>::value && !std::is_same<typename std::decay<COMPARE>::type, EQUALITY>::value, Bool>::type IsEqual(const COLLECTION2& other, COMPARE&& cmp = COMPARE()) const
	{
		static_assert(COLLECTION::KIND == COLLECTION2::KIND, "Can't check collections of different kinds for equality.");
		return static_cast<const COLLECTION*>(this)->IsEqualImpl(other, cmp, OVERLOAD_MAX_RANK);
	}

	//----------------------------------------------------------------------------------------
	/// Appends all elements from another collection @p other to this collection.
	/// If this doesn't succeed for all entries, the collection will be left in a valid, but intermediate state with only some entries from @p other added.
	/// @param[in] other							Another collection, may be any @ref iterables_predicates "iterable object".
	/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> AppendAll(COLLECTION2&& other, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY)
	{
		return static_cast<COLLECTION*>(this)->AppendAllImpl(std::forward<COLLECTION2>(other), resizeFlags, true, OVERLOAD_MAX_RANK);
	}

	//----------------------------------------------------------------------------------------
	/// Makes this collection a copy of @p other.
	/// If copying doesn't succeed for all entries, the collection will be left in a valid, but intermediate state with only some entries from @p other added.
	/// @param[in] other							Another collection, may be any @ref iterables_predicates "iterable object".
	/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> CopyFrom(COLLECTION2&& other, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE)
	{
		if (this == (const void*) &other)
			return OK;
		return static_cast<COLLECTION*>(this)->CopyFromImpl(std::forward<COLLECTION2>(other), resizeFlags, OVERLOAD_MAX_RANK);
	}

	//----------------------------------------------------------------------------------------
	/// Removes all elements of another collection @p other from this collection. Elements of this
	/// collection which are not part of @p other are kept. For a map, only the keys are considered, i.e.,
	/// an entry is removed from this map if its key is contained in @p other, regardless of the corresponding values.
	/// @param[in] other							Another collection, may be any @ref iterables_predicates "iterable object".
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> Subtract(COLLECTION2&& other)
	{
		return static_cast<COLLECTION*>(this)->SubtractImpl(std::forward<COLLECTION2>(other), OVERLOAD_MAX_RANK);
	}

	//----------------------------------------------------------------------------------------
	/// Intersects this collection with the @p other collection. I.e., elements which are not contained in
	/// @p other are removed. For a map, only the keys are considered, i.e.,
	/// an entry is kept in this map if its key is contained in @p other, regardless of the corresponding values.
	/// @param[in] other							Another collection, may be any @ref iterables_predicates "predicate object".
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> Intersect(const COLLECTION2& other)
	{
		return static_cast<COLLECTION*>(this)->IntersectImpl(other, OVERLOAD_MAX_RANK);
	}

	template <typename COLLECTION2> Bool Intersects(const COLLECTION2& other) const
	{
		if (static_cast<const COLLECTION*>(this)->GetCount() < other.GetCount())
		{
			for (AutoIterator<const COLLECTION> i(*static_cast<const COLLECTION*>(this)); i; ++i)
			{
				if (maxon::Contains(other, COLLECTION::GetMapKey(*i)))
					return true;
			}
		}
		else
		{
			for (auto&& i : other)
			{
				if (static_cast<const COLLECTION*>(this)->Contains(COLLECTION2::GetMapKey(i)))
					return true;
			}
		}
		return false;
	}

	template <typename COLLECTION2> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> CopyFromImpl(COLLECTION2&& other, COLLECTION_RESIZE_FLAGS resizeFlags, OverloadRank0)
	{
		static_cast<COLLECTION*>(this)->Flush();
		return static_cast<COLLECTION*>(this)->AppendAllImpl(std::forward<COLLECTION2>(other), resizeFlags, false, OVERLOAD_MAX_RANK);
	}

	template <typename COLLECTION2> Result<void> AppendAllImpl(COLLECTION2&& other, COLLECTION_RESIZE_FLAGS resizeFlags, Bool overwrite, OverloadRank0)
	{
		iferr_scope;
		Int cnt = maxon::GetCount(other);
		cnt = Max(static_cast<COLLECTION*>(this)->GetCount(), cnt);
		static_cast<COLLECTION*>(this)->SetCapacityHint(cnt, resizeFlags) iferr_return;
		for (auto&& i : std::forward<COLLECTION2>(other))
		{
			static_cast<COLLECTION*>(this)->Append(ValueForward<COLLECTION2>(i)) iferr_return;
		}
		return OK;
	}

	template <typename COLLECTION2> Result<void> IntersectImpl(COLLECTION2&& other, OverloadRank0)
	{
		for (AutoIterator<COLLECTION> i(*static_cast<COLLECTION*>(this)); i; )
		{
			if (!maxon::Contains(std::forward<COLLECTION2>(other), COLLECTION::GetMapKey(*i)))
				i.Erase(*static_cast<COLLECTION*>(this));
			else
				++i;
		}
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the collection is empty. This is the same as <tt>GetCount() == 0</tt>
	/// @return												True if the collection does not contain any elements.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Bool IsEmpty() const
	{
		return static_cast<const COLLECTION*>(this)->GetCount() == 0;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the collection is populated. This is the same as <tt>GetCount() != 0</tt>
	/// @return												True if the collection contains any elements.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Bool IsPopulated() const
	{
		return static_cast<const COLLECTION*>(this)->GetCount() != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Returns a string representation of this collection as a list of all contained elements.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction.
	/// @return												List of all elements as a String.
	//----------------------------------------------------------------------------------------
	inline String ToString(const FormatStatement* formatStatement) const;

	//----------------------------------------------------------------------------------------
	/// Returns true if this collection contains all elements from another collection.
	/// @param[in] other							Another collection, may be any @ref iterables_predicates "iterable object".
	/// @return												True if this collection contains all elements from @p other, false otherwise.
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> MAXON_ATTRIBUTE_FORCE_INLINE Bool ContainsAll(COLLECTION2&& other) const
	{
		return static_cast<const COLLECTION*>(this)->ContainsAllImpl(std::forward<COLLECTION2>(other), OVERLOAD_MAX_RANK);
	}

	template <typename COLLECTION2> Bool ContainsAllImpl(COLLECTION2&& other, OverloadRank0) const
	{
		if (this == (const void*) &other)
		{
			return true;
		}
		for (const auto& i : std::forward<COLLECTION2>(other))
		{
			if (!static_cast<const COLLECTION*>(this)->Contains(i))
			{
				return false;
			}
		}
		return true;
	}
};


//----------------------------------------------------------------------------------------
/// Collection is a helper template to be used as base class for set-, array- or list-like collections.
/// It will add iterator-based utility functions such as ToString, Find or AppendAll.
/// @tparam COLLECTION						The actual collection class, this has to have Collection as (direct or indirect) base class.
/// @tparam VALUETYPE							The type of values stored in the collection.
/// @tparam SUPER									The class to be used as base class for Collection.
/// @see @$ref collections
//----------------------------------------------------------------------------------------
template <typename COLLECTION, typename VALUETYPE, typename SUPER> class Collection : public BaseCollection<COLLECTION, SUPER>
{
public:
	using Super = BaseCollection<COLLECTION, SUPER>;
	template <typename... ARGS> MAXON_ATTRIBUTE_FORCE_INLINE explicit Collection(ARGS&&... args) : Super(std::forward<ARGS>(args)...) { }

	using ValueType = VALUETYPE;

	ResultOk<void> VariadicAppend()
	{
		return OK;
	}

	template <typename V, typename... VALUES> Result<void> VariadicAppend(V&& value, VALUES&&... rest)
	{
		iferr_scope;
		static_cast<COLLECTION*>(this)->Append(std::forward<V>(value)) iferr_return;
		return VariadicAppend(std::forward<VALUES>(value)...);
	}

	operator ValueReceiver<const VALUETYPE&>()
	{
		return [this] (const VALUETYPE& v) -> Result<Bool>
		{
			iferr_scope;
			static_cast<COLLECTION*>(this)->Append(v) iferr_return;
			return true;
		};
	}

	operator ValueReceiver<VALUETYPE&&>()
	{
		return [this] (VALUETYPE&& v) -> Result<Bool>
		{
			iferr_scope;
			static_cast<COLLECTION*>(this)->Append(std::move(v)) iferr_return;
			return true;
		};
	}

	// This operator might also be useful for non-scalar types, but if they have special alignment requirements this results in an MSVC compiler error
	// because such types can't be passed by value. We also can't check alignof(VALUETYPE) because VALUETYPE might be incomplete at this point.
	operator ValueReceiver<typename std::conditional<std::is_scalar<VALUETYPE>::value, VALUETYPE, DummyParamType&>::type>()
	{
		return [this] (VALUETYPE&& v) -> Result<Bool>
		{
			iferr_scope;
			static_cast<COLLECTION*>(this)->Append(std::move(v)) iferr_return;
			return true;
		};
	}

// 	using PrivateValueReceiverType = typename std::conditional<IsComplete<VALUETYPE, __COUNTER__>::value, VALUETYPE, Int>::type;
//
// 	operator ValueReceiver<typename std::conditional<alignof(PrivateValueReceiverType) <= alignof(void*) && !std::is_abstract<PrivateValueReceiverType>::value, typename std::remove_const<VALUETYPE>::type, EmptyClass>::type>()
// 	{
// 		return [this] (typename std::remove_const<VALUETYPE>::type v) -> Result<Bool>
// 		{
// 			iferr_scope;
// 			static_cast<COLLECTION*>(this)->Append(std::move(v)) iferr_return;
// 			return true;
// 		};
// 	}

	template <typename FN> Result<Bool> ForEach(FN&& callback)
	{
		yield_scope;
		auto it = static_cast<COLLECTION*>(this)->Begin(), end = static_cast<COLLECTION*>(this)->End();
		while (it != end)
		{
			callback(*it) yield_return;
			++it;
		}
		return true;
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first occurrence of @p v in this collection.
	/// If @p v cannot be found at all, the iterator will point to the end.
	/// @param[in] v									The value to look for.
	/// @return												An iterator pointing to an element which equals @p v, or a null iterator if the element coudn't be found.
	//----------------------------------------------------------------------------------------
	template <typename H = COLLECTION> typename H::Iterator Find(typename ByValueParam<VALUETYPE>::type v)
	{
		auto it = static_cast<COLLECTION*>(this)->Begin(), end = static_cast<COLLECTION*>(this)->End();
		while (it != end)
		{
			if (*it == v)
				return it;
			++it;
		}
		return typename COLLECTION::Iterator();
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first occurrence of @p v in this collection.
	/// If @p v cannot be found at all, the iterator will point to the end.
	/// @param[in] v									The value to look for.
	/// @return												An iterator pointing to an element which equals @p v, or a null iterator if the element coudn't be found.
	//----------------------------------------------------------------------------------------
	template <typename H = COLLECTION> typename H::ConstIterator Find(typename ByValueParam<VALUETYPE>::type v) const
	{
		auto it = static_cast<const COLLECTION*>(this)->Begin(), end = static_cast<const COLLECTION*>(this)->End();
		while (it != end)
		{
			if (*it == v)
				return it;
			++it;
		}
		return typename COLLECTION::ConstIterator();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the index of the first occurrence of @p v in this collection.
	/// If @p v cannot be found at all, a negative value will be returned.
	/// @param[in] v									The value to look for.
	/// @return												Index of the first element which equals @p v, or a negative value if no such element exists.
	//----------------------------------------------------------------------------------------
	Int FindIndex(typename ByValueParam<VALUETYPE>::type v) const
	{
		auto it = static_cast<const COLLECTION*>(this)->Begin();
		auto end = static_cast<const COLLECTION*>(this)->End();
		Int index = 0;
		for (; it != end; ++it, ++index)
		{
			if (*it == v)
			{
				return index;
			}
		}
		return -1;
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if @p v is contained in this collection.
	/// @param[in] v									The value to look for.
	/// @return												True if this collection has an element which equals @p v, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Bool Contains(typename ByValueParam<VALUETYPE>::type v) const
	{
		return static_cast<const COLLECTION*>(this)->FindIndex(v) >= 0;
	}

	static const VALUETYPE& GetMapKey(const VALUETYPE& key)
	{
		return key;
	}
};


//----------------------------------------------------------------------------------------
/// ForEachIterator-based class which iterates over the memory blocks of a collection. For
/// a BaseArray you have just one Block, for the BlockArray as many as have been allocated
/// and for a BaseList or PointerArray each element has its own Block.
//----------------------------------------------------------------------------------------
template <typename COLLECTION, typename VALUETYPE, Bool CONSTITERATOR, Bool STRIDED> class BlockIterator : public ForEachIterator<BlockIterator<COLLECTION, VALUETYPE, CONSTITERATOR, STRIDED>>
{
public:
	using CollectionType = typename ConstIf<COLLECTION, CONSTITERATOR>::type;
	using ElementType = typename ConstIf<VALUETYPE, CONSTITERATOR>::type;
	using ValueType = Block<ElementType, STRIDED>;

	BlockIterator() : _array(nullptr), _index(0) { }
	BlockIterator(const BlockIterator&) = default;
	BlockIterator& operator =(const BlockIterator&) = default;

	MAXON_IMPLICIT BlockIterator(CollectionType* array) : _array(array), _index(0)
	{
		if (array->GetCount() != 0)
		{
			_index = array->GetBlock(0, _block);
			DebugAssert(_index == 0);
		}
	}

	ValueType& operator *()
	{
		return _block;
	}

	ValueType* operator ->()
	{
		return &_block;
	}

	explicit operator Bool() const
	{
		return Bool(_block.GetCount() != 0);
	}

	BlockIterator& operator ++()
	{
		Int i = _index + _block.GetCount();
		if (i >= _array->GetCount())
		{
			_block.Reset();
		}
		else
		{
			_index = _array->GetBlock(i, _block);
			DebugAssert(i == _index);
		}
		return *this;
	}

	void operator ++(int)
	{
		this->operator ++();
	}

private:
	ValueType _block;
	CollectionType* _array;
	Int _index;
};


//----------------------------------------------------------------------------------------
/// Intermediate class.
//----------------------------------------------------------------------------------------
template <typename COLLECTION, typename VALUETYPE, typename SUPER, typename HASH> class ArrayBase0 : public Collection<COLLECTION, VALUETYPE, SUPER>
{
private:
	using Super = Collection<COLLECTION, VALUETYPE, SUPER>;
public:
	static const COLLECTION_KIND KIND = COLLECTION_KIND::ARRAY;

	template <typename... ARGS> MAXON_ATTRIBUTE_FORCE_INLINE explicit ArrayBase0(ARGS&&... args) : Super(std::forward<ARGS>(args)...) { }

	using Super::FindIndex;

	//----------------------------------------------------------------------------------------
	/// Returns true if the given index is within the array boundaries.
	//----------------------------------------------------------------------------------------
	Bool IsValidIndex(Int index) const
	{
		return UInt(index) < UInt(static_cast<const COLLECTION*>(this)->GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Returns an error if the given index is not within the array boundaries.
	//----------------------------------------------------------------------------------------
	Result<void> CheckValidIndex(Int index) const
	{
		if (IsValidIndex(index))
			return OK;
		return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::ILLEGAL_ARGUMENT);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the index of the first occurrence of @p v in this collection.
	/// If @p v cannot be found at all, a negative value will be returned.
	/// @param[in] v									The value to look for.
	/// @param[in] start							The start index. 0 by default.
	/// @return												Index of the first element which equals @p v, or a negative value if no such element exists.
	//----------------------------------------------------------------------------------------
	Int FindIndex(typename ByValueParam<VALUETYPE>::type v, Int start) const
	{
		if (!IsValidIndex(start))
			return -1;
		auto it = static_cast<const COLLECTION*>(this)->Begin() + start;
		auto end = static_cast<const COLLECTION*>(this)->End();
		Int index = start;
		for (; it != end; ++it, ++index)
		{
			if (*it == v)
			{
				return index;
			}
		}
		return -1;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the index of the last occurrence of @p v in this collection.
	/// If @p v cannot be found at all, a negative value will be returned.
	/// @param[in] v									The value to look for.
	/// @return												Index of the last element which equals @p v, or a negative value if no such element exists.
	//----------------------------------------------------------------------------------------
	Int FindLastIndex(typename ByValueParam<VALUETYPE>::type v) const
	{
		Int index = static_cast<const COLLECTION*>(this)->GetCount();
		auto it = static_cast<const COLLECTION*>(this)->End();
		auto begin = static_cast<const COLLECTION*>(this)->Begin();
		while (it != begin)
		{
			--it;
			--index;
			if (*it == v)
			{
				return index;
			}
		}
		return -1;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the index of the last occurrence of @p v in this collection.
	/// If @p v cannot be found at all, a negative value will be returned.
	/// @param[in] v									The value to look for.
	/// @param[in] start							The start index. 0 by default.
	/// @return												Index of the last element which equals @p v, or a negative value if no such element exists.
	//----------------------------------------------------------------------------------------
	Int FindLastIndex(typename ByValueParam<VALUETYPE>::type v, Int start) const
	{
		if (!IsValidIndex(start))
			return -1;
		Int index = start + 1;
		auto it = static_cast<const COLLECTION*>(this)->Begin() + index;
		auto begin = static_cast<const COLLECTION*>(this)->Begin();
		while (it != begin)
		{
			--it;
			--index;
			if (*it == v)
			{
				return index;
			}
		}
		return -1;
	}

	//----------------------------------------------------------------------------------------
	/// Removes the first occurrence of @p v from this collection.
	/// @param[in] v									The value to remove.
	/// @return												True if the value could be found (then it has been removed), false otherwise.
	//----------------------------------------------------------------------------------------
	Bool EraseFirst(typename ByValueParam<VALUETYPE>::type v)
	{
		AutoIterator<COLLECTION> i(*static_cast<COLLECTION*>(this));
		for (; i; ++i)
		{
			if (*i == v)
			{
				if (!static_cast<COLLECTION*>(this)->Erase(i.GetIterator()))
					DebugStop("This cannot happen.");

				return true;
			}
		}
		return false;
	}

	//----------------------------------------------------------------------------------------
	/// Removes all occurrences of @p v from this collection.
	/// @param[in] v									The value to remove.
	/// @return												Number of removed occurrences.
	//----------------------------------------------------------------------------------------
	Int EraseAll(typename ByValueParam<VALUETYPE>::type v)
	{
		Int cnt = 0;
		for (AutoIterator<COLLECTION> i(*static_cast<COLLECTION*>(this)); i; )
		{
			if (*i == v)
			{
				i.Erase(*static_cast<COLLECTION*>(this));
				++cnt;
			}
			else
			{
				++i;
			}
		}
		return cnt;
	}

	template <typename COLLECTION2> Result<void> AppendAllImpl(COLLECTION2&& other, COLLECTION_RESIZE_FLAGS resizeFlags, Bool overwrite, OverloadRank0)
	{
		return InsertAll(static_cast<COLLECTION*>(this)->GetCount(), std::forward<COLLECTION2>(other), resizeFlags);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts all elements from another collection @p other to this collection starting at the given @p index.
	/// @param[in] index							Index for insertion (the array size will increase and the existing elements are moved).
	/// @param[in] other							Another collection, may be any @ref iterables_predicates "iterable object".
	/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> Result<void> InsertAll(Int index, COLLECTION2&& other, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY)
	{
		iferr_scope;
		Int cnt = maxon::GetCount(other);
		if (cnt < 0)
		{
			for (auto&& i : std::forward<COLLECTION2>(other))
			{
				static_cast<COLLECTION*>(this)->Insert(index++, ValueForward<COLLECTION2>(i)) iferr_return;
			}
		}
		else
		{
			const Bool IS_ARRAY = GetCollectionKind<COLLECTION2>::value == COLLECTION_KIND::ARRAY;
			using ARRAY2 = typename std::conditional<IS_ARRAY, COLLECTION2, typename Substitute<COLLECTION2, COLLECTION>::type>::type;
			if (IS_ARRAY && std::is_same<const VALUETYPE, const typename std::decay<ARRAY2>::type::ValueType>::value)
			{
				static_cast<COLLECTION*>(this)->SetCapacityHint(static_cast<COLLECTION*>(this)->GetCount() + cnt, resizeFlags) iferr_return;
				for (auto& block : reinterpret_cast<ARRAY2&&>(other).GetBlocks())
				{
					static_cast<COLLECTION*>(this)->Insert(index, BlockForward<COLLECTION2>(block)) iferr_return;
					index += block.GetCount();
				}
			}
			else
			{
				static_cast<COLLECTION*>(this)->Insert(index, Block<const VALUETYPE>(nullptr, cnt)) iferr_return;
				auto it = static_cast<COLLECTION*>(this)->Begin() + index;
				for (auto&& i : std::forward<COLLECTION2>(other))
				{
					Result<void> res = NewCopy<VALUETYPE>(*it, ValueForward<COLLECTION2>(i));
					if (res == FAILED)
					{
						auto end = static_cast<COLLECTION*>(this)->End();
						while (it != end)
						{
							new (&*it) VALUETYPE();
							++it;
						}
						return res;
					}
					++it;
				}
				DebugAssert(it == static_cast<COLLECTION*>(this)->End());
			}
		}
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Appends all elements from another collection @p other which are not yet contained in this array to this array.
	/// If this doesn't succeed for all entries, the array will be left in a valid, but intermediate state with only some entries from @p other added.
	/// @param[in] other							Another collection, may be any @ref iterables_predicates "iterable object".
	/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> Result<void> Add(COLLECTION2&& other, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY)
	{
		iferr_scope;
		for (const auto& i : std::forward<COLLECTION2>(other))
		{
			if (!static_cast<COLLECTION*>(this)->Contains(i))
			{
				static_cast<COLLECTION*>(this)->Append(i) iferr_return;
			}
		}
		return OK;
	}

	template <typename COLLECTION2> Result<void> SubtractImpl(COLLECTION2&& other, OverloadRank0)
	{
		for (const auto& i : std::forward<COLLECTION2>(other))
		{
			static_cast<COLLECTION*>(this)->EraseAll(PrivateGetMapKey<COLLECTION2>::GetMapKey(i));
		}
		return OK;
	}

	template <typename COLLECTION2, typename COMPARE> Bool IsEqualImpl(const COLLECTION2& other, COMPARE&& cmp, OverloadRank0) const
	{
		if (this == (const void*) &other)
		{
			return true;
		}
		if (static_cast<const COLLECTION*>(this)->GetCount() != other.GetCount())
		{
			return false;
		}
		AutoIterator<const COLLECTION> it1(*static_cast<const COLLECTION*>(this));
		for (AutoIterator<const COLLECTION2> it2(other); it1 && it2; ++it1, ++it2)
		{
			if (!maxon::IsEqual(cmp, *it1, *it2))
			{
				return false;
			}
		}
		return true;
	}

	UInt GetHashCode() const
	{
		UInt hash = 0;
		for (AutoIterator<const COLLECTION> i(*static_cast<const COLLECTION*>(this)); i; ++i)
		{
			hash = 31 * hash + HASH::GetHashCode(*i);
		}
		return hash;
	}

	//----------------------------------------------------------------------------------------
	/// Returns an AutoIterator which iterates over all elements from the given @p start index up to the end of the array.
	/// @param[in] start							Start index for the iteration.
	/// @return												AutoIterator iterating over elements from @p start up to the end.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator<COLLECTION> Slice(Int start)
	{
		return AutoIterator<COLLECTION>(static_cast<COLLECTION*>(this)->Begin() + start, static_cast<COLLECTION*>(this)->End());
	}

	//----------------------------------------------------------------------------------------
	/// Returns an AutoIterator which iterates over all elements from the given @p start index up to the end of the array.
	/// @param[in] start							Start index for the iteration.
	/// @return												AutoIterator iterating over elements from @p start up to the end.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator<const COLLECTION> Slice(Int start) const
	{
		return AutoIterator<const COLLECTION>(static_cast<const COLLECTION*>(this)->Begin() + start, static_cast<const COLLECTION*>(this)->End());
	}

	//----------------------------------------------------------------------------------------
	/// Returns an AutoIterator which iterates over all elements from the given @p start index up to but not including the given @p end index.
	/// @param[in] start							Start index for the iteration.
	/// @param[in] end								End index for the iteration, the iteration does not include the end itself.
	/// @return												AutoIterator iterating over elements from @p start up to but not including @p end.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator<COLLECTION> Slice(Int start, Int end)
	{
		return AutoIterator<COLLECTION>(static_cast<COLLECTION*>(this)->Begin() + start, static_cast<COLLECTION*>(this)->Begin() + end);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an AutoIterator which iterates over all elements from the given @p start index up to but not including the given @p end index.
	/// @param[in] start							Start index for the iteration.
	/// @param[in] end								End index for the iteration, the iteration does not include the end itself.
	/// @return												AutoIterator iterating over elements from @p start up to but not including @p end.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator<const COLLECTION> Slice(Int start, Int end) const
	{
		return AutoIterator<const COLLECTION>(static_cast<const COLLECTION*>(this)->Begin() + start, static_cast<const COLLECTION*>(this)->Begin() + end);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a ForEachIterator which can be used to iterate over the Blocks of the collection.
	/// Typical usage is:
	/// @code
	/// for (Block<ValueType>& block : array.GetBlocks())
	/// {
	///    // ... do something with block (call GetFirst(), GetCount() ...)
	/// }
	/// @endcode
	//----------------------------------------------------------------------------------------
	BlockIterator<COLLECTION, VALUETYPE, false, false> GetBlocks()
	{
		return static_cast<COLLECTION*>(this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a ForEachIterator which can be used to iterate over the Blocks of the collection.
	/// Typical usage is:
	/// @code
	/// for (const Block<const ValueType>& block : array.GetBlocks())
	/// {
	///    // ... do something with block (call GetFirst(), GetCount() ...)
	/// }
	/// @endcode
	//----------------------------------------------------------------------------------------
	BlockIterator<COLLECTION, VALUETYPE, true, false> GetBlocks() const
	{
		return static_cast<const COLLECTION*>(this);
	}

	BlockIterator<COLLECTION, VALUETYPE, false, true> GetStridedBlocks()
	{
		return static_cast<COLLECTION*>(this);
	}

	BlockIterator<COLLECTION, VALUETYPE, true, true> GetStridedBlocks() const
	{
		return static_cast<const COLLECTION*>(this);
	}
};


template <typename ARRAY> class ArrayImpl;

//----------------------------------------------------------------------------------------
/// ArrayBase is a helper template to be used as base class for array- or list-like collections.
/// It will add iterator-based utility functions such as ToString, Find, AppendAll or EraseFirst.
/// @tparam COLLECTION						The actual collection class, this has to have Collection as (direct or indirect) base class.
/// @tparam VALUETYPE							The type of values stored in the collection.
/// @tparam SUPER									The class to be used as base class for Collection.
/// @tparam HASH									The hash class to be used for elements of the collection.
/// @see @$ref arrays
//----------------------------------------------------------------------------------------
template <typename COLLECTION, typename VALUETYPE, typename SUPER, typename HASH> class ArrayBase : public ArrayBase0<COLLECTION, VALUETYPE, SUPER, HASH>
{
private:
	using Super = ArrayBase0<COLLECTION, VALUETYPE, SUPER, HASH>;
public:
	template <typename... ARGS> MAXON_ATTRIBUTE_FORCE_INLINE explicit ArrayBase(ARGS&&... args) : Super(std::forward<ARGS>(args)...) { }

	ArrayImpl<COLLECTION&> ToArray();
	ArrayImpl<const COLLECTION&> ToArray() const;

	MAXON_ATTRIBUTE_FORCE_INLINE operator ArrayImpl<COLLECTION&>() { return ToArray(); }
	MAXON_ATTRIBUTE_FORCE_INLINE operator ArrayImpl<const COLLECTION&>() const { return ToArray(); }
};

template <typename COLLECTION> inline COLLECTION&& PrivateGetMap(COLLECTION&& c, OverloadRank0)
{
	return std::forward<COLLECTION>(c);
}

template <typename COLLECTION> inline typename Substitute<COLLECTION&&, typename std::remove_reference<COLLECTION>::type::MapType>::type PrivateGetMap(COLLECTION&& c, OverloadRank1)
{
	return static_cast<typename Substitute<COLLECTION&&, typename std::remove_reference<COLLECTION>::type::MapType>::type>(c.GetMap());
}

template <typename COLLECTION, typename VALUETYPE, typename SUPER, typename HASH> class SetBase0 : public Collection<COLLECTION, VALUETYPE, SUPER>
{
private:
	using Super = Collection<COLLECTION, VALUETYPE, SUPER>;
public:
	static const COLLECTION_KIND KIND = COLLECTION_KIND::SET;
	using SetType = COLLECTION;

	template <typename... ARGS> MAXON_ATTRIBUTE_FORCE_INLINE explicit SetBase0(ARGS&&... args) : Super(std::forward<ARGS>(args)...) { }

	//----------------------------------------------------------------------------------------
	/// Adds @p v to this set. This forwards to the Insert function of the collection.
	/// It unifies the addition of elements to array- and set-like collections as the former
	/// already have an Append function, while the latter only have an Insert function.
	/// @param[in] v									The value to add to this collection.
	/// @return												Pointer to the value in the set, or nullptr if the element had to be added, but the allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<const VALUETYPE> Append(typename ByValueParam<VALUETYPE>::type v)
	{
		return static_cast<COLLECTION*>(this)->InsertKey(v);
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if this collection contains all elements from another collection @p other, i.e., if this
	/// collection is a superset of @p other.
	/// @param[in] other							Another collection, may be any @ref iterables_predicates "iterable object".
	/// @return												True if this collection contains all elements from @p other, false otherwise.
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> Bool ContainsAllImpl(COLLECTION2&& other, OverloadRank0) const
	{
		if (this == (const void*) &other)
		{
			return true;
		}
		if (static_cast<const COLLECTION*>(this)->GetCount() < maxon::GetCount(other))
		{
			return false;
		}
		for (const auto& i : std::forward<COLLECTION2>(other))
		{
			if (!static_cast<const COLLECTION*>(this)->Contains(i))
			{
				return false;
			}
		}
		return true;
	}

	//----------------------------------------------------------------------------------------
	/// Adds all elements from another collection @p other to this set.
	/// If this doesn't succeed for all entries, the set will be left in a valid, but intermediate state with only some entries from @p other added.
	/// @param[in] other							Another collection, may be any @ref iterables_predicates "iterable object".
	/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> Add(COLLECTION2&& other, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY)
	{
		return static_cast<COLLECTION*>(this)->GetMap().AppendAllImpl(PrivateGetMap(std::forward<COLLECTION2>(other), OVERLOAD_MAX_RANK), resizeFlags, false, OVERLOAD_MAX_RANK);
	}

	//----------------------------------------------------------------------------------------
	/// Adds all elements from another collection @p other to this set.
	/// If this doesn't succeed for all entries, the set will be left in a valid, but intermediate state with only some entries from @p other added.
	/// @param[in] other							Another collection, may be any @ref iterables_predicates "iterable object".
	/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> AppendAll(COLLECTION2&& other, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY)
	{
		return static_cast<COLLECTION*>(this)->GetMap().AppendAllImpl(PrivateGetMap(std::forward<COLLECTION2>(other), OVERLOAD_MAX_RANK), resizeFlags, true, OVERLOAD_MAX_RANK);
	}

	//----------------------------------------------------------------------------------------
	/// Makes this set a copy of @p other.
	/// If copying doesn't succeed for all entries, the set will be left in a valid, but intermediate state with only some entries from @p other added.
	/// @param[in] other							Another collection, may be any @ref iterables_predicates "iterable object".
	/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> MAXON_ATTRIBUTE_FORCE_INLINE Result<void> CopyFrom(COLLECTION2&& other, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE)
	{
		if (this == (const void*) &other)
			return OK;
		return static_cast<COLLECTION*>(this)->GetMap().CopyFromImpl(PrivateGetMap(std::forward<COLLECTION2>(other), OVERLOAD_MAX_RANK), resizeFlags, OVERLOAD_MAX_RANK);
	}

	template <typename COLLECTION2> Result<void> SubtractImpl(COLLECTION2&& other, OverloadRank0)
	{
		for (const auto& i : std::forward<COLLECTION2>(other))
		{
			Result<Bool> res = static_cast<COLLECTION*>(this)->Erase(PrivateGetMapKey<COLLECTION2>::GetMapKey(i));
			if (res == FAILED)
				return res;
		}
		return OK;
	}

	template <typename COLLECTION2, typename COMPARE> Bool IsEqualImpl(const COLLECTION2& other, COMPARE&& cmp, OverloadRank0) const
	{
		// CriticalAssert((std::is_same<typename std::decay<COMPARE>::type, DefaultCompare>::value), "Currently only DefaultCompare is supported.");
		if (this == (const void*) &other)
		{
			return true;
		}
		Int tc = static_cast<const COLLECTION*>(this)->GetCount();
		Int oc = other.GetCount();
		if (tc != oc)
		{
			return false;
		}
		return (other.GetOperationCountForSearch() < static_cast<const COLLECTION*>(this)->GetOperationCountForSearch())
			? other.ContainsAll(*static_cast<const COLLECTION*>(this))
			: static_cast<const COLLECTION*>(this)->ContainsAll(other);
	}

	UInt GetHashCode() const
	{
		UInt hash = 0;
		for (AutoIterator<const COLLECTION> i(*static_cast<const COLLECTION*>(this)); i; ++i)
		{
			hash += HASH::GetHashCode(*i);
		}
		return hash;
	}
};


template <typename SET> class SetImpl;

//----------------------------------------------------------------------------------------
/// SetBase is a helper template to be used as base class set-like collections.
/// It will add iterator-based utility functions such as ToString, Find or AppendAll.
/// @tparam COLLECTION						The actual collection class, this has to have Collection as (direct or indirect) base class.
/// @tparam VALUETYPE							The type of values stored in the collection.
/// @tparam SUPER									The class to be used as base class for Collection.
/// @tparam HASH									The hash class to be used for elements of the collection.
/// @see @$ref sets
//----------------------------------------------------------------------------------------
template <typename COLLECTION, typename VALUETYPE, typename SUPER, typename HASH> class SetBase : public SetBase0<COLLECTION, VALUETYPE, SUPER, HASH>
{
private:
	using Super = SetBase0<COLLECTION, VALUETYPE, SUPER, HASH>;
public:
	template <typename... ARGS> MAXON_ATTRIBUTE_FORCE_INLINE explicit SetBase(ARGS&&... args) : Super(std::forward<ARGS>(args)...) { }

	SetImpl<COLLECTION&> ToSet();
	SetImpl<const COLLECTION&> ToSet() const;

	MAXON_ATTRIBUTE_FORCE_INLINE operator SetImpl<COLLECTION&>() { return ToSet(); }
	MAXON_ATTRIBUTE_FORCE_INLINE operator SetImpl<const COLLECTION&>() const { return ToSet(); }
};

template <typename COLLECTION, typename KEYTYPE, typename VALUETYPE, typename SUPER, typename HASH> class MapBase0 : public BaseCollection<COLLECTION, SUPER>
{
public:
	static const COLLECTION_KIND KIND = COLLECTION_KIND::MAP;
	using MapType = COLLECTION;
	using Super = BaseCollection<COLLECTION, SUPER>;

	template <typename... ARGS> MAXON_ATTRIBUTE_FORCE_INLINE explicit MapBase0(ARGS&&... args) : Super(std::forward<ARGS>(args)...) { }

	using KeyType = KEYTYPE;
	using ValueType = VALUETYPE;

	//----------------------------------------------------------------------------------------
	/// Returns true if @p key is contained in this map.
	/// @param[in] key								The key to look for.
	/// @return												True if this map has an enty whose key equals @p key, false otherwise.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Bool Contains(typename ByValueParam<KEYTYPE>::type key) const
	{
		return static_cast<const COLLECTION*>(this)->FindValue(key) != nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if the key of @p pair is mapped to the value of @p pair in this map.
	/// @param[in] pair								The key-value-pair to look for.
	/// @return												True if this map has an enty which matches @p pair, false otherwise.
	//----------------------------------------------------------------------------------------
	template <typename PAIR> MAXON_ATTRIBUTE_FORCE_INLINE typename SFINAEHelper<Bool, typename PAIR::KeyType>::type Contains(const PAIR& pair) const
	{
		const auto* value = static_cast<const COLLECTION*>(this)->FindValue(pair.GetKey());
		return value && (*value == pair.GetValue());
	}

	static const KEYTYPE& GetMapKey(const KEYTYPE& key)
	{
		return key;
	}

	template <typename PAIR> static const KEYTYPE& GetMapKey(const PAIR& pair)
	{
		return pair.GetKey();
	}

	ResultRef<VALUETYPE> Append(const KEYTYPE& key)
	{
		Bool created;
		return static_cast<COLLECTION*>(this)->InsertKey(key, created);
	}

	template <typename PAIR> typename SFINAEHelper<ResultRef<VALUETYPE>, typename PAIR::KeyType>::type Append(const PAIR& pair)
	{
		Bool created;
		ResultRef<VALUETYPE> v = static_cast<COLLECTION*>(this)->InsertKey(pair.GetKey(), created);
		if ((v == OK) && (AssignCopy<VALUETYPE>(v.GetValue(), pair.GetValue()) == FAILED))
		{
			v = nullptr;
		}
		return v;
	}

	//----------------------------------------------------------------------------------------
	/// Adds all key-value-mappings from other to this map. Existing entries will be kept, even those with a key contained in other.
	/// other has to be a data structure supported by AutoIterator (such as a HashMap or one of the array classes),
	/// and its values have to have GetKey() and GetValue() functions.
	/// If adding doesn't succeed for all entries, the map will be left in a valid, but intermediate state with only some entries from src added.
	/// @param[in] other							Source from which the entries are taken.
	/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
	/// @return												True if adding succeeded.
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> Result<void> Add(COLLECTION2&& other, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY)
	{
		return static_cast<COLLECTION*>(this)->AppendAllImpl(std::forward<COLLECTION2>(other), resizeFlags, false, OVERLOAD_MAX_RANK);
	}

	//----------------------------------------------------------------------------------------
	/// Adds all key-value-mappings from other to this map. Existing entries will be overwritten if other
	/// has an entry with equal key.
	/// other has to be a data structure supported by AutoIterator (such as a HashMap or one of the array classes),
	/// and its values have to have GetKey() and GetValue() functions.
	/// If adding doesn't succeed for all entries, the map will be left in a valid, but intermediate state with only some entries from src added.
	/// @param[in] other							Source from which the entries are taken.
	/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
	/// @return												True if adding succeeded.
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> Result<void> AppendAll(COLLECTION2&& other, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY)
	{
		return static_cast<COLLECTION*>(this)->AppendAllImpl(std::forward<COLLECTION2>(other), resizeFlags, true, OVERLOAD_MAX_RANK);
	}

	//----------------------------------------------------------------------------------------
	/// Adds the inverse of all key-value-mappings from other to this map, i.e., the values will be used as keys
	/// and vice versa. Existing entries will be overwritten if other has values which equal existing keys.
	/// other has to be an iterable object where the values have GetKey() and GetValue() functions.
	/// If adding doesn't succeed for all entries, the map will be left in a valid, but intermediate state with only some entries from src added.
	/// @param[in] other							Source from which the entries are taken.
	/// @return												True if adding succeeded.
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> Result<void> AppendAllInverse(COLLECTION2&& other)
	{
		iferr_scope;
		Bool created;
		for (const auto& i : std::forward<COLLECTION2>(other))
		{
			static_cast<COLLECTION*>(this)->Insert(i.GetValue(), i.GetKey(), created) iferr_return;
		}
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Returns true if this collection contains all elements from another collection @p other, i.e., if this
	/// collection is a superset of @p other.
	/// @param[in] other							Another collection, may be a foreach iterator over which it will be iterated.
	/// @return												True if this collection contains all elements from @p other, false otherwise.
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> Bool ContainsAllImpl(COLLECTION2&& other, OverloadRank0) const
	{
		if (this == (const void*) &other)
		{
			return true;
		}
		if (static_cast<const COLLECTION*>(this)->GetCount() < maxon::GetCount(other))
		{
			return false;
		}
		for (const auto& i : std::forward<COLLECTION2>(other))
		{
			if (!static_cast<const COLLECTION*>(this)->Contains(i))
			{
				return false;
			}
		}
		return true;
	}

	template <typename COLLECTION2> Result<void> SubtractImpl(COLLECTION2&& other, OverloadRank0)
	{
		for (const auto& i : std::forward<COLLECTION2>(other))
		{
			Result<Bool> res = static_cast<COLLECTION*>(this)->Erase(PrivateGetMapKey<COLLECTION2>::GetMapKey(i));
			if (res == FAILED)
				return res;
		}
		return OK;
	}

	template <typename COLLECTION2, typename COMPARE> Bool IsEqualImpl(const COLLECTION2& other, COMPARE&& cmp, OverloadRank0) const
	{
		// CriticalAssert((std::is_same<typename std::decay<COMPARE>::type, DefaultCompare>::value), "Currently only DefaultCompare is supported.");
		if (this == (const void*) &other)
		{
			return true;
		}
		Int tc = static_cast<const COLLECTION*>(this)->GetCount();
		Int oc = other.GetCount();
		if (tc != oc)
		{
			return false;
		}
		return (other.GetOperationCountForSearch() < static_cast<const COLLECTION*>(this)->GetOperationCountForSearch())
			? other.ContainsAll(*static_cast<const COLLECTION*>(this))
			: static_cast<const COLLECTION*>(this)->ContainsAll(other);
	}

	UInt GetHashCode() const
	{
		UInt hash = 0;
		for (AutoIterator<const COLLECTION> i(*static_cast<const COLLECTION*>(this)); i; ++i)
		{
			hash += 31 * HASH::GetHashCode((*i).GetKey()) + HASH::GetHashCode((*i).GetValue());
		}
		return hash;
	}
};

template <typename SET> class MapImpl;

//----------------------------------------------------------------------------------------
/// MapBase is a helper template to be used as base class for map-like collections.
/// It will add iterator-based utility functions such as ToString, Find or AppendAll.
/// @tparam COLLECTION						The actual collection class, this has to have Collection as (direct or indirect) base class.
/// @tparam VALUETYPE							The type of values stored in the collection.
/// @tparam SUPER									The class to be used as base class for Collection.
/// @tparam HASH									The hash class to be used for elements of the collection.
/// @see @$ref maps
//----------------------------------------------------------------------------------------
template <typename COLLECTION, typename KEYTYPE, typename VALUETYPE, typename SUPER, typename HASH> class MapBase : public MapBase0<COLLECTION, KEYTYPE, VALUETYPE, SUPER, HASH>
{
private:
	using Super = MapBase0<COLLECTION, KEYTYPE, VALUETYPE, SUPER, HASH>;
public:
	template <typename... ARGS> MAXON_ATTRIBUTE_FORCE_INLINE explicit MapBase(ARGS&&... args) : Super(std::forward<ARGS>(args)...) { }

	MapImpl<COLLECTION&> ToMap();
	MapImpl<const COLLECTION&> ToMap() const;

	MAXON_ATTRIBUTE_FORCE_INLINE operator MapImpl<COLLECTION&>() { return ToMap(); }
	MAXON_ATTRIBUTE_FORCE_INLINE operator MapImpl<const COLLECTION&>() const { return ToMap(); }
};

/// @}

} // namespace maxon

#endif // COLLECTION_H__
