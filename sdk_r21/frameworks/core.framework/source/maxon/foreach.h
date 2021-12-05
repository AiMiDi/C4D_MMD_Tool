#ifndef FOREACH_H__
#define FOREACH_H__

#include "maxon/apibase.h"
#include "maxon/tuple.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

MAXON_MEMBERTYPE_DETECTOR(GetNonConstIteratorType, Iterator, std::false_type);
MAXON_MEMBERTYPE_DETECTOR(GetConstIteratorType, ConstIterator, std::false_type);
MAXON_MEMBERTYPE_DETECTOR(GetCollectionType, CollectionType, T);
MAXON_MEMBERTYPE_DETECTOR(IsForEachIterator, IsForEachIterator, std::false_type);

template <typename C> struct GetIteratorType
{
	using type = typename std::conditional<std::is_const<C>::value, typename GetConstIteratorType<C>::type, typename GetNonConstIteratorType<C>::type>::type;
};

template <typename T, Int N> struct GetIteratorType<T[N]>
{
	using type = T*;
};

namespace details
{

template <typename I> struct IterableBeginHelper
{
	using Iterator = typename GetIteratorType<typename std::remove_reference<I>::type>::type;

	static Iterator Begin(I&& iterable)
	{
		return std::forward<I>(iterable).Begin();
	}

	static Iterator End(I&& iterable)
	{
		return std::forward<I>(iterable).End();
	}
};

template <typename T, Int N> struct IterableBeginHelper<T[N]>
{
	using Iterator = T*;

	static Iterator Begin(T (&&iterable)[N])
	{
		return iterable;
	}

	static Iterator End(T (&&iterable)[N])
	{
		return iterable + N;
	}
};

template <typename T, Int N> struct IterableBeginHelper<T(&)[N]>
{
	using Iterator = T*;

	static Iterator Begin(T (&iterable)[N])
	{
		return iterable;
	}

	static Iterator End(T (&iterable)[N])
	{
		return iterable + N;
	}
};

// Needed for Iterable::Reverse. This is only meant to be used within a range-based for loop.
template <typename I> struct ReverseIterable
{
	I iterable;

	struct Iterator
	{
		using BaseIterator = typename GetIteratorType<typename std::remove_reference<I>::type>::type;
		BaseIterator it;

		Bool operator !=(const Iterator& other) const
		{
			return it != other.it;
		}

		void operator ++()
		{
			// Do nothing here, the decrement will be done in operator * instead.
		}

		decltype(*std::declval<BaseIterator>()) operator *()
		{
			// Move the iterator backwards here. The C++ standard guarantees that operator * is called exactly
			// once within the body of a range-based for loop.
			--it;
			return *it;
		}
	};

	Iterator begin()
	{
		return {IterableBeginHelper<I>::End(std::forward<I>(iterable))};
	}

	Iterator end()
	{
		return {IterableBeginHelper<I>::Begin(std::forward<I>(iterable))};
	}
};

}


template <typename IT> class ReverseIterator
{
public:
	ReverseIterator() = default;
	explicit ReverseIterator(const IT& it) : _it(it) { }
	explicit ReverseIterator(IT&& it) : _it(std::move(it)) { }

	decltype(*std::declval<IT>()) operator *() const
	{
		return *(_it-1);
	}

	decltype(&*std::declval<IT>()) operator ->() const
	{
		return &*(_it-1);
	}

	ReverseIterator& operator ++()
	{
		--_it;
		return *this;
	}

	ReverseIterator& operator +=(Int i)
	{
		_it -= i;
		return *this;
	}

	ReverseIterator operator ++(int)
	{
		ReverseIterator tmp = *this;
		--_it;
		return tmp;
	}

	ReverseIterator operator +(Int i)
	{
		return _it - i;
	}

	ReverseIterator& operator --()
	{
		++_it;
		return *this;
	}

	ReverseIterator& operator -=(Int i)
	{
		_it += i;
		return *this;
	}

	ReverseIterator operator --(int)
	{
		ReverseIterator tmp = *this;
		++_it;
		return tmp;
	}

	ReverseIterator operator -(Int i)
	{
		return _it + i;
	}

	Int operator -(const ReverseIterator& other) const
	{
		return other._it - _it;
	}

	Bool operator ==(const ReverseIterator& other) const
	{
		return _it == other._it;
	}

	Bool operator <(const ReverseIterator& other) const
	{
		return _it > other._it;
	}

	MAXON_OPERATOR_COMPARISON(ReverseIterator);

private:
	IT _it;
};

template <typename I> inline ReverseIterator<typename GetIteratorType<typename std::remove_reference<I>::type>::type> RBegin(I&& iterable)
{
	return ReverseIterator<typename GetIteratorType<typename std::remove_reference<I>::type>::type>(maxon::details::IterableBeginHelper<I>::End(std::forward<I>(iterable)));
}

template <typename I> inline ReverseIterator<typename GetIteratorType<typename std::remove_reference<I>::type>::type> REnd(I&& iterable)
{
	return ReverseIterator<typename GetIteratorType<typename std::remove_reference<I>::type>::type>(maxon::details::IterableBeginHelper<I>::Begin(std::forward<I>(iterable)));
}


//----------------------------------------------------------------------------------------
/// ForEachIterator is a helper template for the implementation of a foreach iterator
/// (see maxon::Iterable). You can use it as public base class for your foreach iterator class with the
/// template argument ITERATOR being your class as in
/// @code
/// class MyForEachIterator : public ForEachIterator<MyForEachIterator>
/// {
/// public:
///   void operator ++();
///   explicit operator Bool() const;
///   String& operator *() const;
///   String* operator ->() const;
/// };
/// @endcode
/// This relieves you from the need to declare a IsForEachIterator type alias, and it adds
/// some functions such as ToString and Contains. However note that these functions
/// are non-const, i.e., they use the current iterator for the iteration so that it will
/// point to another iteration value after function completion.
///
/// @see maxon::Iterable
/// @see @$ref foreach
///
/// @tparam ITERATOR							The class which implements the foreach protocol, ForEachIterator should be its base class.
/// @tparam SUPER									This is used as base class of ForEachIterator.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SUPER = EmptyClass> class ForEachIterator : public SUPER
{
public:
	/// This marker indicates that this ForEachIterator supports the foreach protocol (see Iterable).
	using IsForEachIterator = std::true_type;

	template <typename... ARGS> MAXON_ATTRIBUTE_FORCE_INLINE explicit ForEachIterator(ARGS&&... args) : SUPER(std::forward<ARGS>(args)...) { }

	//----------------------------------------------------------------------------------------
	/// Iterates over this foreach iterator and returns a string with a list of all visited iteration values.
	/// @param[in] formatStatement		Nullptr or additional formatting instruction.
	/// @return												List of all iteration values as a String.
	///
	/// @warning This is a non-const function which uses this iterator for the iteration. I.e., after function
	/// completion this iterator will point to the end.
	//----------------------------------------------------------------------------------------
	inline String ToString(const FormatStatement* formatStatement);

	//----------------------------------------------------------------------------------------
	/// Iterates over this foreach iterator until an iteration value is found which equals v.
	/// The function advances this iterator. Example:
	/// @code
	/// MyForEachIterator it = ...;
	/// while (it.Find(value))
	/// {
	///   ... do something with *it (which equals value) ...;
	/// }
	/// @endcode
	/// @param[in] v									Value for comparison.
	/// @return												This iterator, either pointing to an iteration value which equals v, or to the end.
	//----------------------------------------------------------------------------------------
	template <typename T> ITERATOR& Find(const T& v)
	{
		while (*static_cast<ITERATOR*>(this))
		{
			if (**static_cast<ITERATOR*>(this) == v)
			{
				break;
			}
		}
		return *static_cast<ITERATOR*>(this);
	}

	//----------------------------------------------------------------------------------------
	/// Iterates over this foreach iterator until an iteration value is found which equals v,
	/// and returns the number of needed iterations or a negative value if v couldn't be found.
	/// @param[in] v									Value for comparison.
	/// @return												Number of iterations to reach an iteration value which equals v, or a negative value if no such value could be found.
	///
	/// @warning This is a non-const function which uses this iterator for the iteration.
	//----------------------------------------------------------------------------------------
	template <typename T> Int FindIndex(const T& v)
	{
		Int index = 0;
		while (*static_cast<ITERATOR*>(this))
		{
			if (**static_cast<ITERATOR*>(this) == v)
			{
				return index;
			}
			++index;
		}
		return -1;
	}

	//----------------------------------------------------------------------------------------
	/// Iterates over this foreach iterator until an iteration value is found which equals v and returns true
	/// on success, or false if v couldn't be found.
	/// @param[in] v									Value for comparison.
	/// @return												True if v could be found as iteration value of this iterator.
	///
	/// @warning This is a non-const function which uses this iterator for the iteration.
	//----------------------------------------------------------------------------------------
	template <typename T> MAXON_ATTRIBUTE_FORCE_INLINE Bool Contains(const T& v)
	{
		return static_cast<ITERATOR*>(this)->FindIndex(v) >= 0;
	}

	class Wrapper
	{
	public:
		MAXON_ATTRIBUTE_FORCE_INLINE explicit Wrapper(ITERATOR* it = nullptr) : _it(it) { }

		MAXON_ATTRIBUTE_FORCE_INLINE Bool operator !=(const PRIVATE_MAXON_RBF_SENTINEL(Wrapper)&) const { return (Bool) *_it; }

		MAXON_ATTRIBUTE_FORCE_INLINE void operator ++()
		{
			_it->operator ++();
		}

		MAXON_ATTRIBUTE_FORCE_INLINE decltype(std::declval<ITERATOR*>()->operator *()) operator *() const
		{
			return _it->operator *();
		}

	private:
		Bool operator ==(const Wrapper&) const; // shouldn't be needed as Wrapper is only meant to be used within range-based for loops which need just !=
		ITERATOR* _it;
	};

	MAXON_ATTRIBUTE_FORCE_INLINE Wrapper begin()
	{
		return Wrapper(static_cast<ITERATOR*>(this));
	}

	static MAXON_ATTRIBUTE_FORCE_INLINE PRIVATE_MAXON_RBF_SENTINEL(Wrapper) end()
	{
		return PRIVATE_MAXON_RBF_SENTINEL(Wrapper)();
	}
};

// The following two template functions are needed for range-based for loops.
// They map from the uppercase Begin/End functions of the MAXON API to global lowercase begin/end functions
// which are recognized by range-based for loops.
template <typename COLLECTION> MAXON_ATTRIBUTE_FORCE_INLINE auto begin(COLLECTION&& c) -> decltype(c.Begin())
{
	return c.Begin();
}

template <typename COLLECTION> MAXON_ATTRIBUTE_FORCE_INLINE auto end(COLLECTION&& c) -> decltype(c.End())
{
	return c.End();
}

//----------------------------------------------------------------------------------------
/// AutoIterator implements a foreach iterator based on two normal iterators.
/// one for the current position and a constant one for the end.
/// This simplifies cases like iterating over a whole array or list. Typical
/// usage is:
/// @code
/// for (AutoIterator<ARRAYTYPE> it(array); it; ++it)
/// {
///    // ... do something with *it or it->
/// }
/// @endcode
///
/// You can specify the current and end iterator explicitly as in
/// @code
/// for (AutoIterator<ARRAYTYPE> it(array.Begin() + 1, array.End()); it; ++it)
/// {
///    // ... do something with *it or it->
/// }
/// @endcode
/// In addition to the basic foreach protocol, AutoIterator also supports the
/// iterator arithmetic of the underlying iterator, but only in forward direction:
/// @code
/// it++;								// go to the next element
/// it += 5;						// advance by 5 elements
/// cnt = itB - itA;		// number of elements from itA to itB
/// @endcode
///
/// @tparam C											Either a collection class with a valid Iterator, or the Iterator class itself.
//----------------------------------------------------------------------------------------
template <typename C> class AutoIterator : public ForEachIterator<AutoIterator<C>>
{
public:
	using Iterator = typename GetIteratorType<C>::type;
	using CollectionType = typename GetCollectionType<C>::type;
	using ValueType = decltype(*std::declval<Iterator>());

	/// Use this constructor if you want to iterate over all elements of a collection.
	/// Please note that the end iterator of the AutoIterator is a constant. When you modify an array
	/// (via Insert(), Append() or Erase()) the value of its End() iterator will most likely change
	/// and trying to iterate over such an array with an AutoIterator while modifying it would crash.
	/// To safely erase the current element, use <tt>iterator.Erase(collection)</tt>.
	MAXON_ATTRIBUTE_FORCE_INLINE explicit AutoIterator(CollectionType& collection) : _it(collection.Begin()), _end(collection.End())
	{
	}

	/// use this constructor if you want to iterate from s until e (excluding e)
	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator(const Iterator& s, const Iterator& e) : _it(s), _end(e)
	{
	}

	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator(CollectionType& collection, Int s, Int e = InvalidArrayIndex) : _it(collection.Begin() + s), _end(e == InvalidArrayIndex ? collection.End() : collection.Begin() + e)
	{
	}

	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator(AutoIterator&& src) : MAXON_MOVE_MEMBERS(_it, _end)
	{
	}
	MAXON_OPERATOR_MOVE_ASSIGNMENT(AutoIterator);

	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator(const AutoIterator& src) : _it(src._it), _end(src._end)
	{
	}
	MAXON_OPERATOR_COPY_ASSIGNMENT(AutoIterator);

	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator() : _it(), _end()
	{
	}

	//----------------------------------------------------------------------------------------
	/// Operator that returns false when the end of the array has been reached.
	/// explicit operator bool() would be ambiguous because it can be used for integer arithmetic.
	/// For C++11 we use explicit bool to avoid that implicit conversion, for older
	/// compilers void* is returned because you can't do arithmetic with it.
	/// @return												False when the end of the array has been reached.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE explicit operator Bool() const
	{
		return Bool(_it != _end);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE ValueType operator *() const
	{
		return *_it;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE typename std::remove_reference<ValueType>::type* operator ->() const
	{
		return _it.operator ->();
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator ==(const AutoIterator& b) const
	{
		return _it == b._it;
	}
	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator <(const AutoIterator& b) const
	{
		return _it < b._it;
	}
	MAXON_OPERATOR_COMPARISON(AutoIterator);

	// add comparison operators for the AutoIterator with inverted constness
	using InvConstAutoIterator = AutoIterator<typename ConstIf<typename std::remove_const<C>::type, !std::is_const<C>::value>::type>;

	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator ==(const InvConstAutoIterator& b) const
	{
		static_assert(SIZEOF(AutoIterator) == SIZEOF(InvConstAutoIterator), "Size mismatch.");
		return _it == reinterpret_cast<const AutoIterator&>(b)._it;
	}
	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator <(const InvConstAutoIterator& b) const
	{
		static_assert(SIZEOF(AutoIterator) == SIZEOF(InvConstAutoIterator), "Size mismatch.");
		return _it < reinterpret_cast<const AutoIterator&>(b)._it;
	}
	MAXON_OPERATOR_COMPARISON(InvConstAutoIterator);


	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator& operator ++()																// prefix operator ++ (increment and fetch)
	{
		++_it;
		return *this;
	}
	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator operator ++(int)												// postfix operator ++ (fetch and increment)
	{
		Iterator tmp = _it;
		++_it;
		return AutoIterator(tmp, _end);											// use RVO
	}
	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator& operator +=(Int i)													// operator +=
	{
		_it += i;
		return *this;
	}
	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator operator +(Int i) const											// + operator
	{
		return AutoIterator(_it + i, _end);											// use RVO
	}
	MAXON_ATTRIBUTE_FORCE_INLINE Int operator -(const AutoIterator& b) const
	{
		return _it - b._it;
	}
	MAXON_ATTRIBUTE_FORCE_INLINE Int operator -(const Iterator& b) const
	{
		return _it - b;
	}

	//----------------------------------------------------------------------------------------
	/// Removes the current iteration value from the underlying collection. The AutoIterator
	/// will point to the element behind the removed one afterwards.
	/// Example:
	/// @code
	/// for (AutoIterator<COLLECTION> i(coll); i; )
	/// {
	///   if (*i == valueToErase)
	///     i.Erase(coll);
	///   else
	///     ++i;
	/// }
	/// @endcode
	/// @param[in] collection					The collection to remove the value from. This has to be the collection which was used to construct this AutoIterator.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void Erase(CollectionType& collection)
	{
		_it = collection.Erase(_it);
		_end = collection.End();
	}

	MAXON_ATTRIBUTE_FORCE_INLINE operator Iterator&()
	{
		return _it;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Iterator& GetIterator()
	{
		return _it;
	}

protected:
	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator(const Iterator& s, const Iterator& e, Bool removed) : _it(s), _end(e)
	{
	}

	Iterator _it;
	Iterator _end;
};

// specialization for C++ arrays
template <typename T, Int N> class AutoIterator<T[N]> : public ForEachIterator<AutoIterator<T[N]>>
{
public:
	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator(T* array, Int count) : _it(array), _end(array + Max<Int>(count, 0))
	{
	}

	MAXON_ATTRIBUTE_FORCE_INLINE explicit AutoIterator(T (&array)[N]) : _it(array), _end(array + N)
	{
	}

	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator(const AutoIterator& src) : _it(src._it), _end(src._end)
	{
	}
	MAXON_OPERATOR_COPY_ASSIGNMENT(AutoIterator);

	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator() : _it(), _end()
	{
	}

	MAXON_ATTRIBUTE_FORCE_INLINE explicit operator Bool() const
	{
		return Bool(_it != _end);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE T& operator *() const
	{
		return *_it;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE T* operator ->() const
	{
		return _it;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator ==(const AutoIterator& b) const
	{
		return _it == b._it;
	}
	MAXON_ATTRIBUTE_FORCE_INLINE Bool operator <(const AutoIterator& b) const
	{
		return _it < b._it;
	}
	MAXON_OPERATOR_COMPARISON(AutoIterator);

	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator& operator ++()																// prefix operator ++ (increment and fetch)
	{
		++_it;
		return *this;
	}
	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator operator ++(int)												// postfix operator ++ (fetch and increment)
	{
		T* tmp = _it;
		++_it;
		return AutoIterator(tmp, _end);											// use RVO
	}
	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator& operator +=(Int i)													// operator +=
	{
		_it += i;
		return *this;
	}
	MAXON_ATTRIBUTE_FORCE_INLINE AutoIterator operator +(Int i) const											// + operator
	{
		return AutoIterator(_it + i, _end);											// use RVO
	}
	MAXON_ATTRIBUTE_FORCE_INLINE Int operator -(const AutoIterator& b) const
	{
		return _it - b._it;
	}

protected:
	T* _it;
	T* _end;
};


template <typename I1, typename I2> class NestedForEachIterator : public ForEachIterator<NestedForEachIterator<I1, I2>>
{
public:
	using Outer = I1;
	using Inner = I2;
	using ValueType = decltype(*std::declval<I2>());

	MAXON_ATTRIBUTE_FORCE_INLINE explicit NestedForEachIterator(I1&& it) : _outerIterator(std::move(it))
	{
		if (_outerIterator)
		{
			_valid = true;
			new (_innerIterator) I2(*_outerIterator);
			MoveToValid();
		}
		else
		{
			_valid = false;
		}
	}

	MAXON_ATTRIBUTE_FORCE_INLINE ~NestedForEachIterator()
	{
		if (_valid)
		{
			((I2*) _innerIterator)->~I2();
		}
	}

	MAXON_ATTRIBUTE_FORCE_INLINE explicit operator Bool() const
	{
		return Bool(_valid && *(I2*) _innerIterator);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE void operator ++()
	{
		if (_valid)
		{
			++*(I2*) _innerIterator;
			MoveToValid();
		}
	}

	MAXON_ATTRIBUTE_FORCE_INLINE ValueType operator *() const
	{
		return *operator ->();
	}

	MAXON_ATTRIBUTE_FORCE_INLINE typename std::remove_reference<ValueType>::type* operator ->() const
	{
		return ((I2*) _innerIterator)->operator ->();
	}

private:
	void MoveToValid()
	{
		while (!*(I2*) _innerIterator)
		{
			((I2*) _innerIterator)->~I2();
			++_outerIterator;
			if (!_outerIterator)
			{
				_valid = false;
				return;
			}
			new (_innerIterator) I2(*_outerIterator);
		}
	}

	I1 _outerIterator;
	union
	{
		Char _innerIterator[SIZEOF(I2)]; // TODO: (Ole) replace by I2 when the compilers support such a union
		void* _alignmentDummy;
	};
	Bool _valid;
};


template <typename T, typename I1, typename I2> class CommonIteratorTypes
{
public:
	using ValueType = typename CommonLValue<T, decltype(*std::declval<I1>()), decltype(*std::declval<I2>())>::type;
	using ValueTypeNoRef = typename std::remove_reference<ValueType>::type;
};

template <typename I1, typename I2> class CommonIteratorTypes<void, I1, I2>
{
public:
	using ValueType = typename CommonType<decltype(*std::declval<I1>()), decltype(*std::declval<I2>())>::type;
	using ValueTypeNoRef = typename std::remove_reference<ValueType>::type;
};


//----------------------------------------------------------------------------------------
/// ConcatForEachIterator implements the foreach-protocol such that it iterates
/// completely over a first foreach iterator and afterwards completely over a second foreach iterator.
/// @tparam T											The type of values to iterate over.
/// @tparam I1										The type of the first iterator.
/// @tparam I2										The type of the second iterator.
/// @see Iterable
//----------------------------------------------------------------------------------------
template <typename T, typename I1, typename I2> class ConcatForEachIterator : public ForEachIterator<ConcatForEachIterator<T, I1, I2>>
{
public:
	using First = I1;
	using Second = I2;
	using Types = CommonIteratorTypes<T, I1, I2>;
	using ValueType = typename Types::ValueType;

	ConcatForEachIterator(I1&& it1, I2&& it2) : _first(std::move(it1)), _second(std::move(it2)) { }

	ConcatForEachIterator(const I1& it1, I2&& it2) : _first(it1), _second(std::move(it2)) { }

	ConcatForEachIterator(I1&& it1, const I2& it2) : _first(std::move(it1)), _second(it2) { }

	ConcatForEachIterator(const I1& it1, const I2& it2) : _first(it1), _second(it2) { }

	MAXON_ATTRIBUTE_FORCE_INLINE ConcatForEachIterator(ConcatForEachIterator&& src) : MAXON_MOVE_MEMBERS(_first, _second) { }
	ConcatForEachIterator(const ConcatForEachIterator& src) = default;

	MAXON_ATTRIBUTE_FORCE_INLINE explicit operator Bool() const
	{
		return Bool(_first || _second);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE void operator ++()
	{
		if (_first)
		{
			++_first;
		}
		else
		{
			++_second;
		}
	}

	MAXON_ATTRIBUTE_FORCE_INLINE ValueType operator *() const
	{
		return _first ? (ValueType) _first.operator *() : (ValueType) _second.operator *();
	}

	MAXON_ATTRIBUTE_FORCE_INLINE typename Types::ValueTypeNoRef* operator ->() const
	{
		return _first ? static_cast<typename Types::ValueTypeNoRef*>(_first.operator ->()) : static_cast<typename Types::ValueTypeNoRef*>(_second.operator ->());
	}

private:
	I1 _first;
	I2 _second;
};


//----------------------------------------------------------------------------------------
/// ConditionalForEachIterator implements the foreach-protocol such that it iterates
/// either completely over a first foreach iterator or completely over a second foreach iterator, depending on a Bool value.
/// @tparam T											The type of values to iterate over.
/// @tparam I1										The type of the first iterator.
/// @tparam I2										The type of the second iterator.
/// @see Iterable
//----------------------------------------------------------------------------------------
template <typename T, typename I1, typename I2> class ConditionalForEachIterator : public ForEachIterator<ConditionalForEachIterator<T, I1, I2>>
{
public:
	using First = I1;
	using Second = I2;
	using Types = CommonIteratorTypes<T, I1, I2>;
	using ValueType = typename Types::ValueType;

	ConditionalForEachIterator(Bool sel, I1&& it1, I2&& it2) : _select(sel), _first(std::move(it1)), _second(std::move(it2)) { }

	ConditionalForEachIterator(Bool sel, const I1& it1, I2&& it2) : _select(sel), _first(it1), _second(std::move(it2)) { }

	ConditionalForEachIterator(Bool sel, I1&& it1, const I2& it2) : _select(sel), _first(std::move(it1)), _second(it2) { }

	ConditionalForEachIterator(Bool sel, const I1& it1, const I2& it2) : _select(sel), _first(it1), _second(it2) { }

	MAXON_ATTRIBUTE_FORCE_INLINE ConditionalForEachIterator(ConditionalForEachIterator&& src) : MAXON_MOVE_MEMBERS(_select, _first, _second) { }
	ConditionalForEachIterator(const ConditionalForEachIterator& src) = default;

	MAXON_ATTRIBUTE_FORCE_INLINE explicit operator Bool() const
	{
		return _select ? Bool(_first) : Bool(_second);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE void operator ++()
	{
		if (_select)
		{
			++_first;
		}
		else
		{
			++_second;
		}
	}

	MAXON_ATTRIBUTE_FORCE_INLINE ValueType operator *() const
	{
		return _select ? (ValueType) _first.operator *() : (ValueType) _second.operator *();
	}

	MAXON_ATTRIBUTE_FORCE_INLINE typename Types::ValueTypeNoRef* operator ->() const
	{
		return _select ? static_cast<typename Types::ValueTypeNoRef*>(_first.operator ->()) : static_cast<typename Types::ValueTypeNoRef*>(_second.operator ->());
	}

	I1& GetFirst()
	{
		return _first;
	}

	I2& GetSecond()
	{
		return _second;
	}

private:
	const Bool _select;
	I1 _first;
	I2 _second;
};


template <typename MAP, typename I> class MapForEachIterator : public ForEachIterator<MapForEachIterator<MAP, I>>
{
public:
	using ValueType = decltype(std::declval<MAP>()(*std::declval<I>()));
	using Iterator = I;

	MAXON_ATTRIBUTE_FORCE_INLINE MapForEachIterator(I&& it, MAP&& map) : _iterator(std::move(it)), _map(std::forward<MAP>(map)) { }

	MAXON_ATTRIBUTE_FORCE_INLINE MapForEachIterator(const I& it, MAP&& map) : _iterator(it), _map(std::forward<MAP>(map)) { }

	MAXON_ATTRIBUTE_FORCE_INLINE MapForEachIterator(MapForEachIterator&& src) : MAXON_MOVE_MEMBERS(_iterator, _map) { }
	MapForEachIterator(const MapForEachIterator& src) = default;

	MAXON_ATTRIBUTE_FORCE_INLINE explicit operator Bool() const
	{
		return Bool(_iterator);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE void operator ++()
	{
		++_iterator;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE ValueType operator *() const
	{
		return _map(*_iterator);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE typename std::remove_reference<ValueType>::type* operator ->() const
	{
		static_assert(std::is_reference<ValueType>::value, "Can't use -> where ValueType it not a reference type.");
		return &_map(*_iterator);
	}

private:
	I _iterator;
	MAP _map;
};


template <typename FILTER, typename I> class FilterForEachIterator : public ForEachIterator<FilterForEachIterator<FILTER, I>>
{
public:
	using ValueType = decltype(*std::declval<I>());
	using Iterator = I;

	MAXON_ATTRIBUTE_FORCE_INLINE FilterForEachIterator(I&& it, FILTER&& filter) : _iterator(std::move(it)), _filter(std::forward<FILTER>(filter))
	{
		Validate();
	}

	MAXON_ATTRIBUTE_FORCE_INLINE FilterForEachIterator(const I& it, FILTER&& filter) : _iterator(it), _filter(std::forward<FILTER>(filter))
	{
		Validate();
	}

	MAXON_ATTRIBUTE_FORCE_INLINE FilterForEachIterator(FilterForEachIterator&& src) : MAXON_MOVE_MEMBERS(_iterator, _filter) { }
	FilterForEachIterator(const FilterForEachIterator& src) = default;

	MAXON_ATTRIBUTE_FORCE_INLINE explicit operator Bool() const
	{
		return Bool(_iterator);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE void operator ++()
	{
		++_iterator;
		Validate();
	}

	MAXON_ATTRIBUTE_FORCE_INLINE ValueType operator *() const
	{
		return *_iterator;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE typename std::remove_reference<ValueType>::type* operator ->() const
	{
		static_assert(std::is_reference<ValueType>::value, "Can't use -> where ValueType it not a reference type.");
		return &(*_iterator);
	}

private:
	void Validate()
	{
		while (_iterator && !_filter(*_iterator))
		{
			++_iterator;
		}
	}

	I _iterator;
	FILTER _filter;
};


template <typename I1, typename I2> class ZipForEachIterator : public ForEachIterator<ZipForEachIterator<I1, I2>>
{
public:
	using First = I1;
	using Second = I2;
	using ValueType = Pair<decltype(*std::declval<I1>()), decltype(*std::declval<I2>())>;

	ZipForEachIterator(I1&& it1, I2&& it2) : _first(std::move(it1)), _second(std::move(it2)) { }

	ZipForEachIterator(const I1& it1, I2&& it2) : _first(it1), _second(std::move(it2)) { }

	ZipForEachIterator(I1&& it1, const I2& it2) : _first(std::move(it1)), _second(it2) { }

	ZipForEachIterator(const I1& it1, const I2& it2) : _first(it1), _second(it2) { }

	ZipForEachIterator(ZipForEachIterator&& src) : MAXON_MOVE_MEMBERS(_first, _second) { }
	ZipForEachIterator(const ZipForEachIterator& src) = default;

	MAXON_ATTRIBUTE_FORCE_INLINE explicit operator Bool() const
	{
		return Bool(_first && _second);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE void operator ++()
	{
		++_first;
		++_second;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE ValueType operator *() const
	{
		return ValueType(*_first, *_second);
	}

private:
	I1 _first;
	I2 _second;
};


template <typename I> class IndexForEachIterator : public ForEachIterator<IndexForEachIterator<I>>
{
public:
	using ValueType = decltype(*std::declval<I>());
	using Iterator = I;


	explicit IndexForEachIterator(I&& it) : _iterator(std::move(it)), _index(0) { }

	explicit IndexForEachIterator(const I& it) : _iterator(it), _index(0) { }

	IndexForEachIterator(IndexForEachIterator&& src) : MAXON_MOVE_MEMBERS(_iterator, _index) { }
	IndexForEachIterator(const IndexForEachIterator& src) = default;

	MAXON_ATTRIBUTE_FORCE_INLINE explicit operator Bool() const
	{
		return Bool(_iterator);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE void operator ++()
	{
		++_iterator;
		++_index;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE ValueType operator *() const
	{
		return *_iterator;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE typename std::remove_reference<ValueType>::type* operator ->() const
	{
		static_assert(std::is_reference<ValueType>::value, "Can't use -> where ValueType it not a reference type.");
		return &(*_iterator);
	}

	Int GetIndex() const
	{
		return _index;
	}

private:
	I _iterator;
	Int _index;
};


//----------------------------------------------------------------------------------------
/// SingletonForEachIterator implements the foreach-protocol such that it iterates
/// a single time over a single value.
/// @tparam T											The type of the object to iterate over.
/// @see Iterable
//----------------------------------------------------------------------------------------
template <typename T> class SingletonForEachIterator : public ForEachIterator<SingletonForEachIterator<T>>
{
public:
	using ValueType = typename ConstIf<typename std::remove_reference<T>::type, !std::is_reference<T>::value>::type;

	MAXON_ATTRIBUTE_FORCE_INLINE explicit SingletonForEachIterator(T&& value) : _value(std::forward<T>(value)), _valid(true) { }

	MAXON_ATTRIBUTE_FORCE_INLINE SingletonForEachIterator(SingletonForEachIterator&& src) : MAXON_MOVE_MEMBERS(_value, _valid) { }
	SingletonForEachIterator(const SingletonForEachIterator& src) = default;

	MAXON_ATTRIBUTE_FORCE_INLINE explicit operator Bool() const
	{
		return Bool(_valid);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE void operator ++()
	{
		_valid = false;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE ValueType& operator *() const
	{
		return _value;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE ValueType* operator ->() const
	{
		return &_value;
	}

private:
	T _value;
	Bool _valid;
};

namespace details
{
template <typename COLLECTION, typename... ARGS> inline void EraseHelper(COLLECTION& collection, typename COLLECTION::Iterator& it, std::false_type*, ARGS&&... args)
{
	it = collection.Erase(it, std::forward<ARGS>(args)...);
}
template <typename COLLECTION, typename... ARGS> inline void EraseHelper(COLLECTION& collection, typename COLLECTION::Iterator& it, std::true_type*, ARGS&&... args)
{
	it = collection.SwapErase(it, std::forward<ARGS>(args)...);
}
}

//----------------------------------------------------------------------------------------
/// An EraseIterator is returned by Iterable::EraseIterator.
/// It provides the Erase function which allows to erase the current iteration value from the underlying collection.
/// @see Iterable::EraseIterator
/// @see Iterable::SwapEraseIterator
//----------------------------------------------------------------------------------------
template <typename COLLECTION, Bool SWAP_ERASE, Bool IS_FOREACH_ITERATOR = IsForEachIterator<typename COLLECTION::Iterator>::value> class EraseIterator : public ForEachIterator<EraseIterator<COLLECTION, SWAP_ERASE, IS_FOREACH_ITERATOR>, typename COLLECTION::Iterator>
{
public:
	using Super = ForEachIterator<EraseIterator, typename COLLECTION::Iterator>;

	explicit EraseIterator(COLLECTION& collection) : Super(collection.Begin()), _collection(&collection), _erased(false) { }

	EraseIterator(EraseIterator&& src) : Super(std::move(src)), _collection(src._collection), _erased(src._erased) { }

	//----------------------------------------------------------------------------------------
	/// Removes the current iteration value from the underlying collection. This is a
	/// simple and safe way to remove a value from a collection within a for loop.
	/// You must not access the removed iteration value afterwards,
	/// the only valid operation on an iterator after Erase is ++iterator. Example:
	/// @code
	/// for (auto it = Iterable::EraseIterator(array); it; ++it)
	/// {
	///   if (*it == valueToErase)
	///     it.Erase();
	/// }
	/// @endcode
	//----------------------------------------------------------------------------------------
	template <typename... ARGS> void Erase(ARGS&&... args)
	{
		DebugAssert(!_erased);
		maxon::details::EraseHelper(*_collection, *this, (std::integral_constant<Bool, SWAP_ERASE>*) nullptr, std::forward<ARGS>(args)...);
		_erased = true;
	}

	void operator ++()
	{
		if (_erased)
			_erased = false;
		else
			COLLECTION::Iterator::operator ++();
	}

	void operator ++(int)
	{
		operator ++();
	}

private:
	void operator --();
	void operator --(int);
	void operator +=(int);
	void operator -=(int);
	void operator +(int);
	void operator -(int);
	MAXON_DISALLOW_COPY_AND_ASSIGN(EraseIterator);

	COLLECTION* _collection;
	Bool _erased;
};

template <typename COLLECTION, Bool SWAP_ERASE> class EraseIterator<COLLECTION, SWAP_ERASE, false> : public ForEachIterator<EraseIterator<COLLECTION, SWAP_ERASE, false>, typename COLLECTION::Iterator>
{
public:
	using Super = ForEachIterator<EraseIterator, typename COLLECTION::Iterator>;

	explicit EraseIterator(COLLECTION& collection) : Super(collection.Begin()), _collection(&collection), _end(collection.End()), _erased(false) { }

	EraseIterator(EraseIterator&& src) : Super(std::move(src)), _collection(src._collection), _end(std::move(src._end)), _erased(src._erased) { }

	void Erase()
	{
		DebugAssert(!_erased);
		maxon::details::EraseHelper(*_collection, *this, (std::integral_constant<Bool, SWAP_ERASE>*) nullptr);
		_end = _collection->End();
		_erased = true;
	}

	MAXON_ATTRIBUTE_FORCE_INLINE explicit operator Bool() const
	{
		return Bool(*this != _end);
	}

	void operator ++()
	{
		if (_erased)
			_erased = false;
		else
			COLLECTION::Iterator::operator ++();
	}

	void operator ++(int)
	{
		operator ++();
	}

private:
	void operator --();
	void operator --(int);
	void operator +=(int);
	void operator -=(int);
	void operator +(int);
	void operator -(int);
	MAXON_DISALLOW_COPY_AND_ASSIGN(EraseIterator);

	COLLECTION* _collection;
	typename COLLECTION::Iterator _end;
	Bool _erased;
};



//----------------------------------------------------------------------------------------
/// Iterable defines some static helper functions to construct foreach iterators. A foreach iterator
/// supports the foreach-protocol consisting of the following class members:
/// - A member <tt>type alias std::true_type IsForEachIterator;</tt> indicates that the class defines a foreach iterator.
/// - explicit operator Bool() checks if the iterator object has a valid current value. When this returns
///   false for the first time, the iteration terminates.
/// - operator ++() advances the iterator object.
/// - The function <tt>operator *() const</tt> to return the current iteration value.
/// - A move or copy constructor for the iterator is needed for some operations of Iterable.
///
/// Given this protocol, an iteration over all values is done by
/// @code
/// for (MyForEachIterator it = ...; it; ++it)
/// {
///   MyValueType& value = *it;
///   ...
/// }
/// @endcode
/// The foreach iterators returned by Iterable functions support range-based for loops:
/// @code
/// for (const auto& v : Iterable::Concat(array, Iterable::GetSingleton(x)))
/// {
///   ...
/// }
/// @endcode
///
/// @see @$ref foreach
//----------------------------------------------------------------------------------------
class Iterable
{
public:
	//----------------------------------------------------------------------------------------
	/// Constructs an AutoIterator from a C++ array.
	/// @param[in] array							The array to iterate over.
	/// @tparam T											Type of the array elements.
	/// @tparam N											Size of array.
	/// @return												AutoIterator over @p array.
	//----------------------------------------------------------------------------------------
	template <typename T, Int N> static AutoIterator<T[N]> Get(T (&array)[N])
	{
		return AutoIterator<T[N]>(array);
	}

	//----------------------------------------------------------------------------------------
	/// Constructs an AutoIterator from an iterable collection. An iterable collection
	/// has Begin() and End() functions returning suitable iterators to iterate over the collection. The
	/// returned AutoIterator will iterate over all values from Begin() to End().
	/// @param[in] iterable						The collection to iterate over.
	/// @tparam I											Type of the collection.
	/// @return												AutoIterator over @p iterable.
	//----------------------------------------------------------------------------------------
	template <typename I> static typename SFINAEHelper<AutoIterator<typename std::remove_reference<I>::type>, typename std::remove_reference<I>::type::ConstIterator>::type Get(I&& iterable)
	{
		return AutoIterator<typename std::remove_reference<I>::type>(iterable);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the passed parameter. This overload of the other Get function is useful to get a foreach iterator
	/// from an object which may be either a foreach iterator itself, or an iterable collection for which
	/// an AutoIterator can be created, by just writing
	/// @code
	/// auto it = Iterable::Get(object);
	/// @endcode
	/// If @c object is already a foreach iterator, it will just be moved to @c it, otherwise @c it will
	/// be an AutoIterator for @c object.
	/// @param[in] iterator						The iterator object to iterate over.
	/// @tparam I											Type of the iterator.
	/// @return												@p iterable.
	//----------------------------------------------------------------------------------------
	template <typename I> static typename SFINAEHelper<I&&, typename std::remove_reference<I>::type::IsForEachIterator>::type Get(I&& iterator)
	{
		return std::forward<I>(iterator);
	}

	template <typename ITERABLE> class IteratorType : public std::decay<decltype(Get(std::declval<ITERABLE>()))>
	{
	public:
		using ValueType = decltype(*std::declval<typename IteratorType::type>());
	};

	template <typename ITERABLE> using ValueType = typename IteratorType<ITERABLE>::ValueType;


	//----------------------------------------------------------------------------------------
	/// This function can be used in a range-based for loop to reverse the iteration such
	/// that it starts at the last element of the #iterable and moves towards the first element.
	/// The function can only be used for iterables which have suitable RBegin and REnd functions,
	/// and for C++ arrays.
	/// @code
	/// for (const X& value : Iterable::Reverse(xarray))
	/// {
	/// }
	/// @endcode
	/// @param[in] iterable						The iterable to iterate over in reverse direction.
	/// @return												Temporary object to be used in a range-based for loop.
	//----------------------------------------------------------------------------------------
	template <typename ITERABLE> static maxon::details::ReverseIterable<ITERABLE> Reverse(ITERABLE&& iterable)
	{
		return maxon::details::ReverseIterable<ITERABLE>{std::forward<ITERABLE>(iterable)};
	}

	//----------------------------------------------------------------------------------------
	/// This function returns a for-each iterator over the given collection @p c which allows you
	/// to remove the current iteration value from within a ranged-based for loop.
	/// @code
	/// for (auto it = Iterable::EraseIterator(array); it; ++it)
	/// {
	///   if (*it == valueToErase)
	///     it.Erase();
	/// }
	/// @endcode
	/// The iterator provides an Erase function which allows to erase the current iteration value from the underlying collection.
	/// After erasure, the current element must not be accessed any longer. But it is allowed to advance the iterator
	/// using ++, then it will point to the element behind the erased one.
	/// @param[in,out] c							The collection to iterate over.
	/// @return												Foreach iterator over @p c which allows to safely erase the current element from within a for loop.
	/// @see SwapEraseIterator
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION> static MAXON_ATTRIBUTE_FORCE_INLINE maxon::EraseIterator<COLLECTION, false> EraseIterator(COLLECTION& c)
	{
		return maxon::EraseIterator<COLLECTION, false>(c);
	}

	//----------------------------------------------------------------------------------------
	/// This function returns a for-each iterator over the given collection @p c which allows you
	/// to remove the current iteration value from within a ranged-based for loop.
	/// @code
	/// for (auto it = Iterable::SwapEraseIterator(array); it; ++it)
	/// {
	///   if (*it == valueToErase)
	///     it.Erase();
	/// }
	/// @endcode
	/// The iterator provides an Erase function which allows to erase the current iteration value from the underlying collection
	/// by the collections's SwapErase function. This will generally be more efficient than the normal Erase, but it changes the order
	/// of the collection starting at the current position.
	/// After erasure, the current element must not be accessed any longer. But it is allowed to advance the iterator
	/// using ++, then it will point to the element behind the erased one.
	/// @param[in,out] c							The collection to iterate over.
	/// @return												Foreach iterator over @p c which allows to safely erase the current element from within a for loop.
	/// @see EraseIterator
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION> static MAXON_ATTRIBUTE_FORCE_INLINE maxon::EraseIterator<COLLECTION, true> SwapEraseIterator(COLLECTION& c)
	{
		return maxon::EraseIterator<COLLECTION, true>(c);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator which iterates over the given iterator and also maintains
	/// an index. The index starts with 0 and is automatically incremented for each iteration step,
	/// it can be obtained from the iterator using its GetIndex() function. Example:
	/// @code
	/// for (auto it = Iterable::IndexIterator(set); it; ++it)
	/// {
	///		DiagnosticOutput("Value at index @ is @", it.GetIndex(), *it);
	/// }
	/// @endcode
	///
	/// @param[in] it									The iterator, may be any @ref iterables_predicates "iterable object".
	/// @tparam I											Type of the iterator.
	/// @return												Foreach iterator iterating over @p it.
	//----------------------------------------------------------------------------------------
	template <typename I> static IndexForEachIterator<typename IteratorType<I&&>::type> IndexIterator(I&& it)
	{
		return IndexForEachIterator<typename IteratorType<I&&>::type>(Get(std::forward<I>(it)));
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a singleton foreach iterator. The iterator will iterate a single time over
	/// the given value.
	/// @param[in] value							The single value to iterate over.
	/// @tparam T											Type of the value.
	/// @return												Foreach iterator iterating a single time over the single value.
	//----------------------------------------------------------------------------------------
	template <typename T> static SingletonForEachIterator<T> GetSingleton(T&& value)
	{
		return SingletonForEachIterator<T>(std::forward<T>(value));
	}

	//----------------------------------------------------------------------------------------
	/// Concatenates two foreach iterators. The returned iterator will iterate at first over
	/// the first iterator, then over the second one. This example will iterate over @c array
	/// at first, then over the single value @c x:
	/// @code
	/// for (const auto& i : Iterable::Concat(array, Iterable::GetSingleton(x)))
	/// {
	///   ...
	/// }
	/// @endcode
	/// The result type of the returned iterator will be the common type of the value types
	/// of the two input iterators if you don't specify the @p T parameter. If such a common type
	/// doesn't exist, you have to specify the @p T parameter.
	///
	/// @param[in] it1								The first iterator, may be any @ref iterables_predicates "iterable object".
	/// @param[in] it2								The second iterator, may be any @ref iterables_predicates "iterable object".
	/// @tparam T											The value type of the result iterator.
	/// @tparam I1										Type of the first iterator.
	/// @tparam I2										Type of the second iterator.
	/// @return												Foreach iterator iterating over @p first, then over @p second.
	//----------------------------------------------------------------------------------------
	template <typename T = void, typename I1, typename I2> static ConcatForEachIterator<T, typename IteratorType<I1&&>::type, typename IteratorType<I2&&>::type> Concat(I1&& it1, I2&& it2)
	{
		return ConcatForEachIterator<T, typename IteratorType<I1&&>::type, typename IteratorType<I2&&>::type>(Get(std::forward<I1>(it1)), Get(std::forward<I2>(it2)));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator which iterates over either @p first or @p second, depending on @p select.
	/// If @p select is @c true, the iterator will iterate over all values of @p first (@p second
	/// won't be used at all), and vice versa if @p select is @c false. Example:
	/// @code
	/// for (const auto& i : Iterable::Conditional(sel, arrayA, arrayB))
	/// {
	///   ...
	/// }
	/// @endcode
	/// The result type of the returned iterator will be the common type of the value types
	/// of the two input iterators if you don't specify the @p T parameter. If such a common type
	/// doesn't exist, you have to specify the @p T parameter.
	///
	/// @param[in] select							If @c true, iterate over @p first, otherwise over @p second.
	/// @param[in] it1								The first iterator, may be any @ref iterables_predicates "iterable object".
	/// @param[in] it2								The second iterator, may be any @ref iterables_predicates "iterable object".
	/// @tparam T											The value type of the result iterator.
	/// @tparam I1										Type of the first iterator.
	/// @tparam I2										Type of the second iterator.
	/// @return												Conditional foreach iterator iterating over @p first if @p select is @c true, over @p second otherwise.
	//----------------------------------------------------------------------------------------
	template <typename T = void, typename I1, typename I2> static ConditionalForEachIterator<T, typename IteratorType<I1&&>::type, typename IteratorType<I2&&>::type> Conditional(Bool select, I1&& it1, I2&& it2)
	{
		return ConditionalForEachIterator<T, typename IteratorType<I1&&>::type, typename IteratorType<I2&&>::type>(select, Get(std::forward<I1>(it1)), Get(std::forward<I2>(it2)));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator which maps each of the values of the underlying iterator @p values
	/// by the given function @p fn. I.e., if the original values are v1, v2, ..., the returned
	/// iterator will yield the values fn(v1), fn(v2), ...
	///
	/// For example, to compute the sum of the squared values of an array using GetSum, you write
	/// @code
	/// BaseArray<Int> array;
	/// ...
	/// Int sum = GetSum(Iterable::Map(array, [](Int x) { return x * x; }));
	/// @endcode
	///
	/// @param[in] values							The values to iterate over, may be any @ref iterables_predicates "iterable object".
	/// @param[in] fn									The function which maps each original value to the target value of the returned iterator.
	/// @tparam I											Type of the values.
	/// @tparam MAP										Type of the mapping function.
	/// @return												Foreach iterator iterating over @p values, mapped by @p fn.
	//----------------------------------------------------------------------------------------
	template <typename I, typename MAP> static MapForEachIterator<MAP, typename IteratorType<I&&>::type> Map(I&& values, MAP&& fn)
	{
		return MapForEachIterator<MAP, typename IteratorType<I&&>::type>(Get(std::forward<I>(values)), std::forward<MAP>(fn));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator which iterates only over those @p values which pass the given
	/// @p filter. A value @c x passes the filter unless <tt>!filter(x)</tt> is @c true.
	///
	/// @param[in] values							The values to iterate over, may be any @ref iterables_predicates "iterable object".
	/// @param[in] filter							The filter function. If <tt>!filter(x)</tt> is @c true, @c x will be removed from the iteration.
	/// @tparam I											Type of the values.
	/// @tparam FILTER								Type of the filter function.
	/// @return												Foreach iterator iterating over @p values, but removing those which don't pass @p filter.
	//----------------------------------------------------------------------------------------
	template <typename I, typename FILTER> static FilterForEachIterator<FILTER, typename IteratorType<I&&>::type> Filter(I&& values, FILTER&& filter)
	{
		return FilterForEachIterator<FILTER, typename IteratorType<I&&>::type>(Get(std::forward<I>(values)), std::forward<FILTER>(filter));
	}

	//----------------------------------------------------------------------------------------
	/// Returns a foreach iterator which iterates over two iterators in lockstep. For each
	/// iteration step, the zip iterator has a pair as its value with the first value of the
	/// pair coming from @p it1 and the second value from @p it2. The iteration ends as soon as
	/// one of the two iterators reaches its end.
	///
	/// @param[in] it1								The first iterator, may be any @ref iterables_predicates "iterable object".
	/// @param[in] it2								The second iterator, may be any @ref iterables_predicates "iterable object".
	/// @tparam I1										Type of the first iterator.
	/// @tparam I2										Type of the second iterator.
	/// @return												Foreach iterator iterating over pairs of values from @p it1 and @p it2 in a lockstep fashion.
	//----------------------------------------------------------------------------------------
	template <typename I1, typename I2> static ZipForEachIterator<typename IteratorType<I1&&>::type, typename IteratorType<I2&&>::type> Zip(I1&& it1, I2&& it2)
	{
		return ZipForEachIterator<typename IteratorType<I1&&>::type, typename IteratorType<I2&&>::type>(Get(std::forward<I1>(it1)), Get(std::forward<I2>(it2)));
	}

	template <typename I> static Bool Any(I&& iterable)
	{
		for (const auto& x : std::forward<I>(iterable))
		{
			if (x)
				return true;
		}
		return false;
	}

	template <typename I, typename MAP> static Bool Any(I&& iterable, MAP&& map)
	{
		for (const auto& x : std::forward<I>(iterable))
		{
			if (map(x))
				return true;
		}
		return false;
	}

	template <typename I> static Bool All(I&& iterable)
	{
		for (const auto& x : std::forward<I>(iterable))
		{
			if (!x)
				return false;
		}
		return true;
	}

	template <typename I, typename MAP> static Bool All(I&& iterable, MAP&& map)
	{
		for (const auto& x : std::forward<I>(iterable))
		{
			if (!map(x))
				return false;
		}
		return true;
	}
};

/// @}

} // namespace maxon

#endif // FOREACH_H__
