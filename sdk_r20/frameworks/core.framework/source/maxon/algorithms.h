#ifndef ALGORITHMS_H__
#define ALGORITHMS_H__

#include "maxon/apibase.h"
#include "maxon/basearray.h"
#include "maxon/optional.h"
#include "maxon/tuple.h"

#include <utility>
#include <iterator>
#include <type_traits>
#include <functional>


namespace maxon
{

// Need this for ADL. Namespace scope so it works with decltype return type.
using std::begin;
using std::end;

template <typename T> std::false_type TestForBeginFunction(OverloadRank0);
template <typename T> decltype(begin(std::declval<T&>())) TestForBeginFunction(OverloadRank1);

template <typename T> std::false_type TestForEndFunction(OverloadRank0);
template <typename T> decltype(end(std::declval<T&>())) TestForEndFunction(OverloadRank1);

template <typename T> struct IsIterable
{
	static const bool value = MAXON_HAS_TRUE_TYPE(TestForBeginFunction<typename std::decay<T>::type>(OVERLOAD_MAX_RANK))
		&& MAXON_HAS_TRUE_TYPE(TestForEndFunction<typename std::decay<T>::type>(OVERLOAD_MAX_RANK));
};

using IndexPair = Pair<Int, Int>;

//----------------------------------------------------------------------------------------
/// Type trait to test if a type is iterable, i.e if it supports begin(t) and end(t).
//----------------------------------------------------------------------------------------
template <typename T, size_t N> struct IsIterable<T[N]>
{
	static const bool value = true;
};

namespace details
{

template <typename T1, typename T2> struct EqualityCompare
{
	Bool operator ()(const T1& x, const T2& y) const { return x == y; }
};

template <typename T1, typename T2> struct LessThanCompare
{
	Bool operator ()(const T1& x, const T2& y) const { return x < y; }
};

} // namespace details

//----------------------------------------------------------------------------------------
/// Initializes elements of value_type type in a sequence by calling their constructor
/// with given arguments. Cannot fail.
///
/// @param[in] first							Start of uninitialized sequence, i.e. pointer to first element.
/// @param[in] sentinel						Sequence delimiter, i.e. pointer to one position after the last element.
/// @param[in] args								Constructor arguments.
/// @return												Iterator to end of the constructed sequence.
//----------------------------------------------------------------------------------------
template
<
	typename ITERATOR, typename SENTINEL, typename ... ARGS,
	typename = typename std::enable_if<!IsIterable<ITERATOR>::value>::type
>
inline auto Construct(ITERATOR first, SENTINEL sentinel, const ARGS& ... args) -> ITERATOR
{
	using ValueType = typename std::iterator_traits<ITERATOR>::value_type;

	for (; !(first == sentinel); ++first)
		new (&*first) ValueType(args ...);

	return first;
}

//----------------------------------------------------------------------------------------
/// Equivalent to Construct(begin(iterable), end(iterable), args ...).
//----------------------------------------------------------------------------------------
template
<
	typename ITERABLE, typename ... ARGS,
	typename = typename std::enable_if<IsIterable<ITERABLE>::value>::type
>
inline auto Construct(ITERABLE&& iterable, const ARGS& ... args) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return Construct(begin(iterable), end(iterable), args ...);
}

//----------------------------------------------------------------------------------------
/// Destructs elements of value_type in a sequence. Cannot fail.
///
/// @param[in] first							Start of sequence, i.e. pointer to first element.
/// @param[in] sentinel						Sequence delimiter, i.e. pointer to one position after the last element.
/// @return												Iterator to end of the destructed sequence.
//----------------------------------------------------------------------------------------
template
<
	typename ITERATOR, typename SENTINEL,
	typename = typename std::enable_if<!IsIterable<ITERATOR>::value>::type
>
inline auto Destruct(ITERATOR first, SENTINEL sentinel) -> ITERATOR
{
	using ValueType = typename std::iterator_traits<ITERATOR>::value_type;

	for (; !(first == sentinel); ++first)
		first->~ValueType();

	return first;
}

//----------------------------------------------------------------------------------------
/// Equivalent to Destruct(begin(iterable), end(iterable)).
//----------------------------------------------------------------------------------------
template
<
	typename ITERABLE,
	typename = typename std::enable_if<IsIterable<ITERABLE>::value>::type
>
inline auto Destruct(ITERABLE&& iterable) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return Destruct(begin(iterable), end(iterable));
}

namespace details
{

template <Bool hasCopyFrom>
struct CopyImplSelector;

template <>
struct CopyImplSelector<false>
{
	template <typename ITERATOR, typename SENTINEL, typename DEST_ITERATOR>
	static auto Copy(ITERATOR first, SENTINEL sentinel, DEST_ITERATOR dest) -> ResultOk<DEST_ITERATOR>
	{
		while (!(first == sentinel))
		{
			*dest = *first;
			++first;
			++dest;
		}
		return dest;
	}

	template <typename ITERATOR, typename SENTINEL, typename DEST_ITERATOR>
	static auto CopyToUninitialized(ITERATOR first, SENTINEL sentinel, DEST_ITERATOR dest) -> ResultOk<DEST_ITERATOR>
	{
		using DestValueType = typename std::iterator_traits<DEST_ITERATOR>::value_type;

		while (!(first == sentinel))
		{
			new (&*dest) DestValueType(*first);
			++first;
			++dest;
		}
		return dest;
	}

	template <typename ITERATOR, typename SENTINEL, typename DEST_ITERATOR, typename PREDICATE>
	static auto CopyIf(ITERATOR first, SENTINEL sentinel, DEST_ITERATOR dest, PREDICATE pred) -> ResultOk<DEST_ITERATOR>
	{
		while (!(first == sentinel))
		{
			if (pred(*first))
			{
				*dest = *first;
				++dest;
			}
			++first;
		}
		return dest;
	}

	template <typename ITERATOR, typename SENTINEL, typename DEST_ITERATOR, typename PREDICATE>
	static auto CopyToUninitializedIf(ITERATOR first, SENTINEL sentinel, DEST_ITERATOR dest, PREDICATE pred) -> ResultOk<DEST_ITERATOR>
	{
		using DestValueType = typename std::iterator_traits<DEST_ITERATOR>::value_type;

		while (!(first == sentinel))
		{
			if (pred(*first))
			{
				new (&*dest) DestValueType(*first);
				++dest;
			}
			++first;
		}
		return dest;
	}
};

template <>
struct CopyImplSelector<true>
{
	template <typename ITERATOR, typename SENTINEL, typename DEST_ITERATOR>
	static auto Copy(ITERATOR first, SENTINEL sentinel, DEST_ITERATOR dest) -> Result<DEST_ITERATOR>
	{
		using ValueType = typename std::iterator_traits<DEST_ITERATOR>::value_type;

		while (!(first == sentinel))
		{
			Result<void> res = AssignCopy<ValueType>(*dest, *first);
			if (MAXON_UNLIKELY(res == FAILED))
			{
				return res.GetError();
			}
			++first;
			++dest;
		}
		return dest;
	}

	template <typename ITERATOR, typename SENTINEL, typename DEST_ITERATOR>
	static auto CopyToUninitialized(ITERATOR first, SENTINEL sentinel, DEST_ITERATOR dest) -> Result<DEST_ITERATOR>
	{
		using ValueType = typename std::iterator_traits<DEST_ITERATOR>::value_type;

		auto curDest = dest;

		while (!(first == sentinel))
		{
			Result<void> res = NewCopy<ValueType>(*curDest, *first);
			if (MAXON_UNLIKELY(res == FAILED))
			{
				// Copy failed: Destruct already copied objects.
				Destruct(dest, curDest);
				return res.GetError();
			}
			++first;
			++curDest;
		}
		return curDest;
	}

	template <typename ITERATOR, typename SENTINEL, typename DEST_ITERATOR, typename PREDICATE>
	static auto CopyIf(ITERATOR first, SENTINEL sentinel, DEST_ITERATOR dest, PREDICATE pred) -> Result<DEST_ITERATOR>
	{
		using ValueType = typename std::iterator_traits<DEST_ITERATOR>::value_type;

		while (!(first == sentinel))
		{
			if (pred(*first))
			{
				Result<void> res = AssignCopy<ValueType>(*dest, *first);
				if (MAXON_UNLIKELY(res == FAILED))
				{
					return res.GetError();
				}
				++dest;
			}
			++first;
		}
		return dest;
	}

	template <typename ITERATOR, typename SENTINEL, typename DEST_ITERATOR, typename PREDICATE>
	static auto CopyToUninitializedIf(ITERATOR first, SENTINEL sentinel, DEST_ITERATOR dest, PREDICATE pred) -> Result<DEST_ITERATOR>
	{
		using ValueType = typename std::iterator_traits<DEST_ITERATOR>::value_type;

		auto curDest = dest;

		while (!(first == sentinel))
		{
			if (pred(*curDest))
			{
				Result<void> res = NewCopy<ValueType>(*curDest, *first);
				if (MAXON_UNLIKELY(res == FAILED))
				{
					// Copy failed: Destruct already copied objects.
					Destruct(dest, curDest);
					return res.GetError();
				}
				++curDest;
			}
			++first;
		}
		return curDest;
	}
};

} // namespace details

//----------------------------------------------------------------------------------------
/// Copy-assigns elements of value_type from one sequence to another.
/// The destination sequence is expected to contain initialized values.
///
/// This function behaves similar to std::copy, but uses maxon error handling instead of exceptions.
/// If copying an object cannot fail, i.e. for POD-types, copy assignment is used.
/// If copying an object can fail, i.e. because of allocations, a member function Result<void> CopyFrom(const T&)
/// must be implemented; copying an object then happens through CopyFrom().
///
/// @param[in] first							Start of source sequence, i.e. pointer to first element.
/// @param[in] sentinel						Source sequence delimiter, i.e. pointer to one position after the last element.
/// @param[in] dest								Start of destination sequence, i.e. pointer to first element.
/// @return												End of the resulting destination sequence, or error if CopyFrom() failed.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename DEST_ITERATOR>
inline auto Copy(ITERATOR first, SENTINEL sentinel, DEST_ITERATOR dest) -> Result<DEST_ITERATOR>
{
	using ValueType = typename std::iterator_traits<ITERATOR>::value_type;
	using Impl = maxon::details::CopyImplSelector<TestForCopyFromMember<ValueType>::isSupported>;

	return Impl::template Copy(first, sentinel, dest);
}

//----------------------------------------------------------------------------------------
/// Equivalent to Copy(begin(iterable), end(iterable), dest).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename DEST_ITERATOR>
inline auto Copy(const ITERABLE& iterable, DEST_ITERATOR dest) -> Result<DEST_ITERATOR>
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return Copy(begin(iterable), end(iterable), dest);
}

//----------------------------------------------------------------------------------------
/// Equivalent to Copy, but only copies elements that match the given predicate.
/// The predicate function should have a signature equivalent to
/// @code
/// Bool func(const ElementType&);
/// @endcode
///
/// @param[in] first							Start of source sequence, i.e. pointer to first element.
/// @param[in] sentinel						Source sequence delimiter, i.e. pointer to one position after the last element.
/// @param[in] dest								Start of destination sequence, i.e. pointer to first element.
/// @param[in] pred								A unary predicate.
/// @return												End of the resulting destination sequence, or error if CopyFrom() failed.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename DEST_ITERATOR, typename PREDICATE>
inline auto CopyIf(ITERATOR first, SENTINEL sentinel, DEST_ITERATOR dest, PREDICATE pred) -> Result<DEST_ITERATOR>
{
	using ValueType = typename std::iterator_traits<ITERATOR>::value_type;
	using Impl = maxon::details::CopyImplSelector<TestForCopyFromMember<ValueType>::isSupported>;

	return Impl::template CopyIf(first, sentinel, dest, pred);
}

//----------------------------------------------------------------------------------------
/// Equivalent to CopyIf(begin(iterable), end(iterable), dest, pred).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename DEST_ITERATOR, typename PREDICATE>
inline auto CopyIf(const ITERABLE& iterable, DEST_ITERATOR dest, PREDICATE pred) -> Result<DEST_ITERATOR>
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return CopyIf(begin(iterable), end(iterable), dest, pred);
}

//----------------------------------------------------------------------------------------
/// Copy-constructs elements of value_type from one sequence to another.
/// The destination sequence is expected to contain uninitialized values.
///
/// See Copy for more details.
///
/// @param[in] first							Start of source sequence, i.e. pointer to first element.
/// @param[in] sentinel						Source sequence delimiter, i.e. pointer to one position after the last element.
/// @param[in] dest								Start of destination sequence, i.e. pointer to first element.
/// @return												End of the resulting destination sequence, or error if CopyFrom() failed.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename DEST_ITERATOR >
inline auto CopyToUninitialized(ITERATOR first, SENTINEL sentinel, DEST_ITERATOR dest) -> Result<DEST_ITERATOR>
{
	using ValueType = typename std::iterator_traits<ITERATOR>::value_type;
	using Impl = maxon::details::CopyImplSelector<TestForCopyFromMember<ValueType>::isSupported>;

	return Impl::template CopyToUninitialized(first, sentinel, dest);
}

//----------------------------------------------------------------------------------------
/// Equivalent to CopyToUninitialized(begin(iterable), end(iterable), dest).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename DEST_ITERATOR>
inline auto CopyToUninitialized(const ITERABLE& iterable, DEST_ITERATOR dest) -> Result<DEST_ITERATOR>
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return Copy(begin(iterable), end(iterable), dest);
}

//----------------------------------------------------------------------------------------
/// Equivalent to CopyToUninitialized, but only copies elements that match the given predicate.
/// The predicate function should have a signature equivalent to
/// @code
/// Bool func(const ElementType&);
/// @endcode
///
/// @param[in] first							Start of source sequence, i.e. pointer to first element.
/// @param[in] sentinel						Source sequence delimiter, i.e. pointer to one position after the last element.
/// @param[in] dest								Start of destination sequence, i.e. pointer to first element.
/// @param[in] pred								A unary predicate.
/// @return												End of the resulting destination sequence, or error if CopyFrom() failed.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename DEST_ITERATOR, typename PREDICATE>
inline auto CopyToUninitializedIf(ITERATOR first, SENTINEL sentinel, DEST_ITERATOR dest, PREDICATE pred) -> Result<DEST_ITERATOR>
{
	using ValueType = typename std::iterator_traits<ITERATOR>::value_type;
	using Impl = maxon::details::CopyImplSelector<TestForCopyFromMember<ValueType>::isSupported>;

	return Impl::template CopyToUninitializedIf(first, sentinel, dest, pred);
}

//----------------------------------------------------------------------------------------
/// Equivalent to CopyToUninitializedIf(begin(iterable), end(iterable), dest, pred).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename DEST_ITERATOR, typename PREDICATE>
inline auto CopyToUninitializedIf(const ITERABLE& iterable, DEST_ITERATOR dest, PREDICATE pred) -> Result<DEST_ITERATOR>
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return CopyToUninitializedIf(begin(iterable), end(iterable), dest, pred);
}

enum class MOVE_MODE
{
	KEEP_SOURCE,
	DESTRUCT_SOURCE
} MAXON_ENUM_LIST(MOVE_MODE);

//----------------------------------------------------------------------------------------
/// Move-assigns elements of value_type from one sequence to another.
/// The destination sequence is expected to contain initialized values.
/// The MODE parameter controls whether the elements in the source sequence will be destructed. Cannot fail.
///
/// This function behaves similar to std::move(a, b) (from <algorithm> - not to be mistaken for the one from <utility>).
///
/// @tparam MODE									Flags to control the behavior of this function.
/// @param[in] first							Start of source sequence, i.e. pointer to first element.
/// @param[in] sentinel						Source sequence delimiter, i.e. pointer to one position after the last element.
/// @param[in] dest								Start of destination sequence, i.e. pointer to first element.
/// @return												End of the resulting destination sequence.
//----------------------------------------------------------------------------------------
template <MOVE_MODE MODE = MOVE_MODE::KEEP_SOURCE, typename ITERATOR, typename SENTINEL, typename DEST_ITERATOR>
inline auto Move(ITERATOR first, SENTINEL sentinel, DEST_ITERATOR dest) -> DEST_ITERATOR
{
	using SourceValueType = typename std::iterator_traits<ITERATOR>::value_type;

	while (!(first == sentinel))
	{
		*dest = std::move(*first);
		if (MODE == MOVE_MODE::DESTRUCT_SOURCE)
			first->~SourceValueType();
		++first;
		++dest;
	}
	return dest;
}

//----------------------------------------------------------------------------------------
/// Equivalent to Move(begin(iterable), end(iterable), dest).
//----------------------------------------------------------------------------------------
template <MOVE_MODE MODE = MOVE_MODE::KEEP_SOURCE, typename ITERABLE, typename DEST_ITERATOR>
inline auto Move(ITERABLE&& iterable, DEST_ITERATOR dest) -> DEST_ITERATOR
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return Move<MODE>(begin(iterable), end(iterable), dest);
}

//----------------------------------------------------------------------------------------
/// Equivalent to Move, but only copies elements that match the given predicate.
/// The predicate function should have a signature equivalent to
/// @code
/// Bool func(const ElementType&);
/// @endcode
///
/// @param[in] first							Start of source sequence, i.e. pointer to first element.
/// @param[in] sentinel						Source sequence delimiter, i.e. pointer to one position after the last element.
/// @param[in] dest								Start of destination sequence, i.e. pointer to first element.
/// @param[in] pred								A unary predicate.
/// @return												End of the resulting destination sequence.
//----------------------------------------------------------------------------------------
template <MOVE_MODE MODE = MOVE_MODE::KEEP_SOURCE, typename ITERATOR, typename SENTINEL, typename DEST_ITERATOR, typename PREDICATE>
inline auto MoveIf(ITERATOR first, SENTINEL sentinel, DEST_ITERATOR dest, PREDICATE pred) -> DEST_ITERATOR
{
	using SourceValueType = typename std::iterator_traits<ITERATOR>::value_type;

	while (!(first == sentinel))
	{
		if (pred(*first))
			*dest++ = std::move(*first);
		if (MODE == MOVE_MODE::DESTRUCT_SOURCE)
			first->~SourceValueType();
		++first;
	}
	return dest;
}

//----------------------------------------------------------------------------------------
/// Equivalent to MoveIf(begin(iterable), end(iterable), dest, pred).
//----------------------------------------------------------------------------------------
template <MOVE_MODE MODE = MOVE_MODE::KEEP_SOURCE, typename ITERABLE, typename DEST_ITERATOR, typename PREDICATE>
inline auto MoveIf(ITERABLE&& iterable, DEST_ITERATOR dest, PREDICATE pred) -> DEST_ITERATOR
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return MoveIf<MODE>(begin(iterable), end(iterable), dest, pred);
}

//----------------------------------------------------------------------------------------
/// Move-constructs elements of value_type from one sequence to another.
/// The destination sequence is expected to contain uninitialized values.
/// The MODE parameter controls whether the elements in the source sequence will be destructed. Cannot fail.
///
/// This function behaves similar to std::move(a, b) (from <algorithm> - not to be mistaken for the one from <utility>).
///
/// @tparam MODE									Flags to control the behavior of this function.
/// @param[in] first							Start of source sequence, i.e. pointer to first element.
/// @param[in] sentinel						Source sequence delimiter, i.e. pointer to one position after the last element.
/// @param[in] dest								Start of destination sequence, i.e. pointer to first element.
/// @return												End of the resulting destination sequence.
//----------------------------------------------------------------------------------------
template <MOVE_MODE MODE = MOVE_MODE::KEEP_SOURCE, typename ITERATOR, typename SENTINEL, typename DEST_ITERATOR>
inline auto MoveToUninitialized(ITERATOR first, SENTINEL sentinel, DEST_ITERATOR dest) -> DEST_ITERATOR
{
	using SourceValueType = typename std::iterator_traits<ITERATOR>::value_type;
	using DestValueType = typename std::iterator_traits<DEST_ITERATOR>::value_type;

	while (!(first == sentinel))
	{
		new (&*dest) DestValueType(std::move(*first));
		if (MODE == MOVE_MODE::DESTRUCT_SOURCE)
			first->~SourceValueType();
		++first;
		++dest;
	}
	return dest;
}

//----------------------------------------------------------------------------------------
/// Equivalent to MoveToUninitialized(begin(iterable), end(iterable), dest).
//----------------------------------------------------------------------------------------
template <MOVE_MODE MODE = MOVE_MODE::KEEP_SOURCE, typename ITERABLE, typename DEST_ITERATOR>
inline auto MoveToUninitialized(ITERABLE&& iterable, DEST_ITERATOR dest) -> DEST_ITERATOR
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return MoveToUninitialized<MODE>(begin(iterable), end(iterable), dest);
}

//----------------------------------------------------------------------------------------
/// Equivalent to MoveToUninitializedIf, but only moves elements that match the given predicate.
/// The predicate function should have a signature equivalent to
/// @code
/// Bool func(const ElementType&);
/// @endcode
///
/// @param[in] first							Start of source sequence, i.e. pointer to first element.
/// @param[in] sentinel						Source sequence delimiter, i.e. pointer to one position after the last element.
/// @param[in] dest								Start of destination sequence, i.e. pointer to first element.
/// @param[in] pred								A unary predicate.
/// @return												End of the resulting destination sequence.
//----------------------------------------------------------------------------------------
template <MOVE_MODE MODE = MOVE_MODE::KEEP_SOURCE, typename ITERATOR, typename SENTINEL, typename DEST_ITERATOR, typename PREDICATE>
inline auto MoveToUninitializedIf(ITERATOR first, SENTINEL sentinel, DEST_ITERATOR dest, PREDICATE pred) -> DEST_ITERATOR
{
	using SourceValueType = typename std::iterator_traits<ITERATOR>::value_type;
	using DestValueType = typename std::iterator_traits<DEST_ITERATOR>::value_type;

	while (!(first == sentinel))
	{
		if (pred(*first))
		{
			new (&*dest) DestValueType(std::move(*first));
			++dest;
		}
		if (MODE == MOVE_MODE::DESTRUCT_SOURCE)
			first->~SourceValueType();
		++first;
	}
	return dest;
}

//----------------------------------------------------------------------------------------
/// Equivalent to MoveToUninitializedIf(begin(iterable), end(iterable), dest, pred).
//----------------------------------------------------------------------------------------
template <MOVE_MODE MODE = MOVE_MODE::KEEP_SOURCE, typename ITERABLE, typename DEST_ITERATOR, typename PREDICATE>
inline auto MoveToUninitializedIf(ITERABLE&& iterable, DEST_ITERATOR dest, PREDICATE pred) -> DEST_ITERATOR
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return MoveToUninitializedIf<MODE>(begin(iterable), end(iterable), dest, pred);
}

//----------------------------------------------------------------------------------------
/// Assigns the given value to all elements in a sequence. The sequence is expected to contain initialized data.
///
/// This function is the equivalent to std::fill.
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @param[in] value							The assigned value.
/// @return												End of filled sequence.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename T>
inline auto Fill(ITERATOR first, SENTINEL sentinel, const T& value) -> ITERATOR
{
	while (!(first == sentinel))
		*first++ = value;

	return first;
}

//----------------------------------------------------------------------------------------
/// Equivalent to Fill(begin(iterable), end(iterable), value).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename T>
inline auto Fill(ITERABLE&& iterable, const T& value) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return Fill(begin(iterable), end(iterable), value);
}

//----------------------------------------------------------------------------------------
/// Assigns the given value to all elements in a sequence. The sequence is expected to contain initialized data.
/// The generator function should have a signature equivalent to
/// @code
/// ElementType func();
/// @endcode
///
/// This function is the equivalent to std::generate.
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @param[in] gen								Generator function.
/// @return												End of generated sequence.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename GENERATOR>
inline auto Generate(ITERATOR first, SENTINEL sentinel, GENERATOR gen) -> ITERATOR
{
	while (!(first == sentinel))
		*first++ = gen();

	return first;
}

//----------------------------------------------------------------------------------------
/// Equivalent to Generate(begin(iterable), end(iterable), gen).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename GENERATOR>
inline auto Generate(ITERABLE&& iterable, GENERATOR gen) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return Generate(begin(iterable), end(iterable), gen);
}

//----------------------------------------------------------------------------------------
/// Returns whether the given unary predicate is true for all elements in a sequence.
/// The predicate function should have a signature equivalent to
/// @code
/// Bool func(const ElementType&);
/// @endcode
///
/// This function is the equivalent to std::all_of.
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @param[in] pred								Unary predicate function.
/// @return												True if predicate was true for all elements.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename PREDICATE>
inline Bool AllOf(ITERATOR first, SENTINEL sentinel, PREDICATE pred)
{
	for (; !(first == sentinel); ++first)
		if (!pred(*first))
			return false;
	return true;
}

//----------------------------------------------------------------------------------------
/// Equivalent to AllOf(begin(iterable), end(iterable), pred).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename PREDICATE>
inline Bool AllOf(const ITERABLE& iterable, PREDICATE pred)
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return AllOf(begin(iterable), end(iterable), pred);
}

//----------------------------------------------------------------------------------------
/// Returns whether the given unary predicate is true for all elements in a sequence.
/// The predicate function should have a signature equivalent to
/// @code
/// Bool func(const ElementType&);
/// @endcode
///
/// This function is the equivalent to std::any_of.
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @param[in] pred								Unary predicate function.
/// @return												True if predicate was true for any element.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename PREDICATE>
inline Bool AnyOf(ITERATOR first, SENTINEL sentinel, PREDICATE pred)
{
	for (; !(first == sentinel); ++first)
		if (pred(*first))
			return true;
	return false;
}

//----------------------------------------------------------------------------------------
/// Equivalent to AnyOf(begin(iterable), end(iterable), pred).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename PREDICATE>
inline Bool AnyOf(const ITERABLE& iterable, PREDICATE pred)
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return AnyOf(begin(iterable), end(iterable), pred);
}

//----------------------------------------------------------------------------------------
/// Returns whether the given unary predicate is true none of the elements in a sequence.
/// The predicate function should have a signature equivalent to
/// @code
/// Bool func(const ElementType&);
/// @endcode
///
/// This function is the equivalent to std::none_of.
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @param[in] pred								Unary predicate function.
/// @return												True if predicate was true none of the elements.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename PREDICATE>
inline Bool NoneOf(ITERATOR first, SENTINEL sentinel, PREDICATE pred)
{
	for (; !(first == sentinel); ++first)
		if (pred(*first))
			return false;
	return true;
}

//----------------------------------------------------------------------------------------
/// Equivalent to NoneOf(begin(iterable), end(iterable), pred).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename PREDICATE>
inline Bool NoneOf(const ITERABLE& iterable, PREDICATE pred)
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return NoneOf(begin(iterable), end(iterable), pred);
}

//----------------------------------------------------------------------------------------
/// Returns whether the elements of two sequences are pair-wise equal, i.e. when they have the same length and seq1[i] == se2[i] for all i.
///
/// This function is the equivalent to std::equal.
///
/// @param[in] first1							Start of first sequence.
/// @param[in] sentinel1					First sequence delimiter.
/// @param[in] first2							Start of second sequence.
/// @param[in] sentinel2					Second sequence delimiter.
/// @return												True if both sequences are equal.
//----------------------------------------------------------------------------------------
template <typename ITERATOR1, typename SENTINEL1, typename ITERATOR2, typename SENTINEL2>
inline Bool Equal(ITERATOR1 first1, SENTINEL1 sentinel1, ITERATOR2 first2, SENTINEL2 sentinel2)
{
	using maxon::details::EqualityCompare;

	using ValueType1 = typename std::iterator_traits<ITERATOR1>::value_type;
	using ValueType2 = typename std::iterator_traits<ITERATOR2>::value_type;

	return Equal(first1, sentinel1, first2, sentinel2, EqualityCompare<ValueType1, ValueType2>());
}

//----------------------------------------------------------------------------------------
/// Equivalent to Equal(begin(iterable1), end(iterable1), begin(iterable2), end(iterable2)).
//----------------------------------------------------------------------------------------
template <typename ITERABLE1, typename ITERABLE2>
inline Bool Equal(const ITERABLE1& iterable1, const ITERABLE2& iterable2)
{
	static_assert(IsIterable<ITERABLE1>::value, "iterable1 must support begin(iterable1) and end(iterable1)");
	static_assert(IsIterable<ITERABLE2>::value, "iterable2 must support begin(iterable2) and end(iterable2)");

	return Equal(begin(iterable1), end(iterable1), begin(iterable2), end(iterable2));
}

//----------------------------------------------------------------------------------------
/// Equivalent to Equal, but uses a custom compare function instead of equality.
/// The compare function should have a signature equivalent to
/// @code
/// Bool comp(const ElementType1&, const ElementType2&);
/// @endcode
///
/// @param[in] first1							Start of first sequence.
/// @param[in] sentinel1					First sequence delimiter.
/// @param[in] first2							Start of second sequence.
/// @param[in] sentinel2					Second sequence delimiter.
/// @param[in] comp								Binary compare function.
/// @return												True if both sequences are equal.
//----------------------------------------------------------------------------------------
template <typename ITERATOR1, typename SENTINEL1, typename ITERATOR2, typename SENTINEL2, typename COMPARE>
inline Bool Equal(ITERATOR1 first1, SENTINEL1 sentinel1, ITERATOR2 first2, SENTINEL2 sentinel2, COMPARE comp)
{
	for (; ; ++first1, ++first2)
	{
		Bool isDone1 = first1 == sentinel1;
		Bool isDone2 = first2 == sentinel2;

		// One done before the other? => different length, not equal
		if (isDone1 != isDone2)
		{
			return false;
		}
		// Both done at the same time, no mismatch yet => equal
		else if (isDone1 && isDone2)
		{
			return true;
		}
		else if (!comp(*first1, *first2))
		{
			return false;
		}
	}
}

//----------------------------------------------------------------------------------------
/// Equivalent to Equal(begin(iterable1), end(iterable1), begin(iterable2), end(iterable2), comp).
//----------------------------------------------------------------------------------------
template <typename ITERABLE1, typename ITERABLE2, typename COMPARE>
inline Bool Equal(const ITERABLE1& iterable1, const ITERABLE2& iterable2, COMPARE comp)
{
	static_assert(IsIterable<ITERABLE1>::value, "iterable1 must support begin(iterable1) and end(iterable1)");
	static_assert(IsIterable<ITERABLE2>::value, "iterable2 must support begin(iterable2) and end(iterable2)");

	return Equal(begin(iterable1), end(iterable1), begin(iterable2), end(iterable2), comp);
}

//----------------------------------------------------------------------------------------
/// Returns whether there's a pair-wise mismatch between elements of two sequences.
/// If no mismatch was found, i.e. both sequences are equal (@see Equal), NO_VALUE is returned.
/// If a mismatch was found and both sequences have the same length, a pair of iterators to the mismatching elements is returned.
/// If length(seq1) < length(seq2), a pair (end(seq1), it2) is returned, and vice versa.
///
/// This function is the equivalent to std::mismatch.
///
/// @param[in] first1							Start of first sequence.
/// @param[in] sentinel1					First sequence delimiter.
/// @param[in] first2							Start of second sequence.
/// @param[in] sentinel2					Second sequence delimiter.
/// @return												Optional pair of mismatched elements.
//----------------------------------------------------------------------------------------
template <typename ITERATOR1, typename SENTINEL1, typename ITERATOR2, typename SENTINEL2>
inline auto Mismatch(ITERATOR1 first1, SENTINEL1 sentinel1, ITERATOR2 first2, SENTINEL2 sentinel2) -> Optional<Pair<ITERATOR1, ITERATOR2>>
{
	using maxon::details::EqualityCompare;

	using ValueType1 = typename std::iterator_traits<ITERATOR1>::value_type;
	using ValueType2 = typename std::iterator_traits<ITERATOR2>::value_type;

	return Mismatch(first1, sentinel1, first2, sentinel2, EqualityCompare<ValueType1, ValueType2>());
}

//----------------------------------------------------------------------------------------
/// Equivalent to Mismatch(begin(iterable1), end(iterable1), begin(iterable2), end(iterable2)).
//----------------------------------------------------------------------------------------
template <typename ITERABLE1, typename ITERABLE2>
inline auto Mismatch(ITERABLE1&& iterable1, ITERABLE2&& iterable2) -> Optional<Pair<decltype(begin(iterable1)), decltype(begin(iterable2))>>
{
	static_assert(IsIterable<ITERABLE1>::value, "iterable1 must support begin(iterable1) and end(iterable1)");
	static_assert(IsIterable<ITERABLE2>::value, "iterable2 must support begin(iterable2) and end(iterable2)");

	return Mismatch(begin(iterable1), end(iterable1), begin(iterable2), end(iterable2));
}

//----------------------------------------------------------------------------------------
/// Equivalent to Mismatch, but uses a custom compare function instead of equality.
/// The compare function should have a signature equivalent to
/// @code
/// Bool comp(const ElementType1&, const ElementType2&);
/// @endcode
///
/// @param[in] first1							Start of first sequence.
/// @param[in] sentinel1					First sequence delimiter.
/// @param[in] first2							Start of second sequence.
/// @param[in] sentinel2					Second sequence delimiter.
/// @param[in] comp								Binary compare function.
/// @return												Optional pair of mismatched elements.
//----------------------------------------------------------------------------------------
template <typename ITERATOR1, typename SENTINEL1, typename ITERATOR2, typename SENTINEL2, typename COMPARE>
inline auto Mismatch(ITERATOR1 first1, SENTINEL1 sentinel1, ITERATOR2 first2, SENTINEL2 sentinel2, COMPARE comp) -> Optional<Pair<ITERATOR1, ITERATOR2>>
{
	for (; ; ++first1, ++first2)
	{
		Bool isDone1 = first1 == sentinel1;
		Bool isDone2 = first2 == sentinel2;

		if (isDone1 && isDone2)
		{
			return NO_VALUE;
		}
		else if (isDone1 || isDone2 || !comp(*first1, *first2))
		{
			return ToTuple(first1, first2);
		}
	}
}

//----------------------------------------------------------------------------------------
/// Equivalent to Mismatch(begin(iterable1), end(iterable1), begin(iterable2), end(iterable2), comp).
//----------------------------------------------------------------------------------------
template <typename ITERABLE1, typename ITERABLE2, typename COMPARE>
inline auto Mismatch(ITERABLE1&& iterable1, ITERABLE2&& iterable2, COMPARE comp) -> Optional<Pair<decltype(begin(iterable1)), decltype(begin(iterable2))>>
{
	static_assert(IsIterable<ITERABLE1>::value, "iterable1 must support begin(iterable1) and end(iterable1)");
	static_assert(IsIterable<ITERABLE2>::value, "iterable2 must support begin(iterable2) and end(iterable2)");

	return Mismatch(begin(iterable1), end(iterable1), begin(iterable2), end(iterable2), comp);
}

//----------------------------------------------------------------------------------------
/// Reorders elements in sequence [first, last) so that the given unary predicate is true for all elements [first, p) and false for all elements in [p, last),
/// i.e. all elements that match the predicate are placed in front of those that don't. The ordering of the elements is not preserved (@see StablePartition).
/// The predicate function should have a signature equivalent to
/// @code
/// Bool func(const ElementType&);
/// @endcode
///
/// This function is the equivalent to std::partition.
///
/// @param[in] first							Start of sequence.
/// @param[in] last								End of sequence.
/// @param[in] pred								Unary predicate function.
/// @return												Iterator of partition point p.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename PREDICATE>
inline auto Partition(ITERATOR first, ITERATOR last, PREDICATE pred) -> ITERATOR
{
	while (true)
	{
		// Scan to first out-of-place element from the beginning
		while (first != last && pred(*first))
			++first;

		// Done?
		if (first == last)
			break;

		// Scan to first out-of-place element from the back
		do { --last; }
		while (first != last && !pred(*last));

		// Done?
		if (first == last)
			break;

		// Swap both out-of-place elements
		Swap(*first, *last);

		++first;
	}

	return first;
}

//----------------------------------------------------------------------------------------
/// Equivalent to Partition(first, last, pred).
/// @c last is determined by incrementing @c first until it matches the sequence delimiter @c sentinel.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename PREDICATE>
inline auto Partition(ITERATOR first, SENTINEL sentinel, PREDICATE pred) -> ITERATOR
{
	ITERATOR last = first;
	while (!(last == sentinel))
		++last;

	return Partition(first, last, pred);
}

//----------------------------------------------------------------------------------------
/// Equivalent to Partition(begin(iterable), end(iterable), pred).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename PREDICATE>
inline auto Partition(ITERABLE&& iterable, PREDICATE pred) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return Partition(begin(iterable), end(iterable), pred);
}

//----------------------------------------------------------------------------------------
/// Returns whether a sequence is partitioned by the given predicate, i.e. there's a partition point
/// p so that the predicate is true for all [first, p) and false for all [p, last).
/// The predicate function should have a signature equivalent to
/// @code
/// Bool func(const ElementType&);
/// @endcode
///
/// This function is the equivalent to std::is_partitioned.
///
/// @param[in] first							Start of sequence.
/// @param[in] last								End of sequence.
/// @param[in] pred								Unary predicate function.
/// @return												True if sequence is partitioned.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename PREDICATE>
inline Bool IsPartitioned(ITERATOR first, ITERATOR last, PREDICATE pred)
{
	// Scan to first element that doesn't match pred from the beginning
	for (; first != last; ++first)
		if (!pred(*first))
			break;

	// If we find an element that matches pred after this point, the list is not partitioned
	for (; first != last; ++first)
		if (pred(*first))
			return false;

	return true;
}

//----------------------------------------------------------------------------------------
/// Equivalent to IsPartitioned(first, last, pred).
/// @c last is determined by incrementing @c first until it matches the sequence delimiter @c sentinel.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename PREDICATE>
inline Bool IsPartitioned(ITERATOR first, SENTINEL sentinel, PREDICATE pred)
{
	ITERATOR last = first;
	while (!(last == sentinel))
		++last;

	return IsPartitioned(first, last, pred);
}

//----------------------------------------------------------------------------------------
/// Equivalent to IsPartitioned(begin(iterable), end(iterable), pred).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename PREDICATE>
inline Bool IsPartitioned(const ITERABLE& iterable, PREDICATE pred)
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return IsPartitioned(begin(iterable), end(iterable), pred);
}

//----------------------------------------------------------------------------------------
/// Reverses the order of the elements in a sequence.
///
/// This function is the equivalent to std::reverse.
///
/// @param[in] first							Start of sequence.
/// @param[in] last								End of sequence.
/// @return												End of the reversed sequence.
//----------------------------------------------------------------------------------------
template <typename ITERATOR>
inline auto Reverse(ITERATOR first, ITERATOR last) -> ITERATOR
{
	for (; first != last && first != --last; ++first)
		Swap(*first, *last);

	return first;
}

//----------------------------------------------------------------------------------------
/// Equivalent to Reverse(first, last).
/// @c last is determined by incrementing @c first until it matches the sequence delimiter @c sentinel.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL>
inline auto Reverse(ITERATOR first, SENTINEL sentinel) -> ITERATOR
{
	ITERATOR last = first;
	while (!(last == sentinel))
		++last;

	return Reverse(first, last);
}

//----------------------------------------------------------------------------------------
/// Equivalent to Reverse(begin(iterable), end(iterable)).
//----------------------------------------------------------------------------------------
template <typename ITERABLE>
inline auto Reverse(ITERABLE&& iterable) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return Reverse(begin(iterable), end(iterable));
}

//----------------------------------------------------------------------------------------
/// Returns an iterator to the first element in a sequence that is equal or greater than the given value.
/// If such an element does not exist, the end of the sequence is returned.
/// Binary search is used to locate the element, so the sequence must be ordered.
/// Elements must be comparable with the less-than operator.
///
/// This function is the equivalent to std::lower_bound.
///
/// @param[in] first							Start of sequence.
/// @param[in] last								End of sequence.
/// @param[in] value							The bounding value.
/// @return												Iterator to position of the lower bound.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename T>
inline auto LowerBound(ITERATOR first, ITERATOR last, const T& value) -> ITERATOR
{
	using maxon::details::LessThanCompare;

	using ValueType = typename std::iterator_traits<ITERATOR>::value_type;

	return LowerBound(first, last, value, LessThanCompare<ValueType, T>());
}

//----------------------------------------------------------------------------------------
/// Equivalent to LowerBound, but uses the given function to compare elements
/// instead of the less-than operator. The sequence must be ordered by the same function.
/// The compare function should have a signature equivalent to
/// @code
/// Bool comp(const ElementType1&, const ElementType2&);
/// @endcode
///
/// @param[in] first							Start of sequence.
/// @param[in] last								End of sequence.
/// @param[in] value							The bounding value.
/// @param[in] comp								Binary compare function.
/// @return												Iterator to position of the lower bound.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename T, typename COMPARE>
inline auto LowerBound(ITERATOR first, ITERATOR last, const T& value, COMPARE comp) -> ITERATOR
{
	Int count = last - first;

	while (count > 0)
	{
		Int step = count / 2;
		ITERATOR it = first + step;

		if (comp(*it, value))
		{
			first = ++it;
			count -= step + 1;
		}
		else
		{
			count = step;
		}
	}

	return first;
}

//----------------------------------------------------------------------------------------
/// Equivalent to LowerBound(first, last, value).
/// @c last is determined by incrementing @c first until it matches the sequence delimiter @c sentinel.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename T>
inline auto LowerBound(ITERATOR first, SENTINEL sentinel, const T& value) -> ITERATOR
{
	ITERATOR last = first;
	while (!(last == sentinel))
		++last;

	return LowerBound(first, last, value);
}

//----------------------------------------------------------------------------------------
/// Equivalent to LowerBound(first, last, value, comp).
/// @c last is determined by incrementing @c first until it matches the sequence delimiter @c sentinel.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename T, typename COMPARE>
inline auto LowerBound(ITERATOR first, SENTINEL sentinel, const T& value, COMPARE comp) -> ITERATOR
{
	ITERATOR last = first;
	while (!(last == sentinel))
		++last;

	return LowerBound(first, last, value, comp);
}

//----------------------------------------------------------------------------------------
/// Equivalent to LowerBound(begin(iterable), end(iterable), value).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename T>
inline auto LowerBound(ITERABLE&& iterable, const T& value) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return LowerBound(begin(iterable), end(iterable), value);
}

//----------------------------------------------------------------------------------------
/// Equivalent to LowerBound(begin(iterable), end(iterable), value, comp).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename T, typename COMPARE>
inline auto LowerBound(ITERABLE&& iterable, const T& value, COMPARE comp) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return LowerBound(begin(iterable), end(iterable), value, comp);
}

//----------------------------------------------------------------------------------------
/// Returns an iterator to the first element in a sequence that is greater than the given value.
/// If such an element does not exist, the end of the sequence is returned.
/// Binary search is used to locate the element, so the sequence must be ordered.
/// Elements must be comparable with the less-than operator.
///
/// This function is the equivalent to std::upper_bound.
///
/// @param[in] first							Start of sequence.
/// @param[in] last								End of sequence.
/// @param[in] value							The bounding value.
/// @return												Iterator to position of the upper bound.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename T>
inline auto UpperBound(ITERATOR first, ITERATOR last, const T& value) -> ITERATOR
{
	using maxon::details::LessThanCompare;

	using ValueType = typename std::iterator_traits<ITERATOR>::value_type;

	return UpperBound(first, last, value, LessThanCompare<T, ValueType>());
}

//----------------------------------------------------------------------------------------
/// Equivalent to UpperBound, but uses the given function to compare elements
/// instead of the less-than operator. The sequence must be ordered by the same function.
/// The compare function should have a signature equivalent to
/// @code
/// Bool comp(const ElementType1&, const ElementType2&);
/// @endcode
///
/// @param[in] first							Start of sequence.
/// @param[in] last								End of sequence.
/// @param[in] value							The bounding value.
/// @param[in] comp								Binary compare function.
/// @return												Iterator to position of the upper bound.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename T, typename COMPARE>
inline auto UpperBound(ITERATOR first, ITERATOR last, const T& value, COMPARE comp) -> ITERATOR
{
	Int count = last - first;

	while (count > 0)
	{
		Int step = count / 2;
		ITERATOR it = first + step;

		if (!comp(value, *it))
		{
			first = ++it;
			count -= step + 1;
		}
		else
		{
			count = step;
		}
	}

	return first;
}

//----------------------------------------------------------------------------------------
/// Equivalent to UpperBound(first, last, value).
/// @c last is determined by incrementing @c first until it matches the sequence delimiter @c sentinel.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename T>
inline auto UpperBound(ITERATOR first, SENTINEL sentinel, const T& value) -> ITERATOR
{
	ITERATOR last = first;
	while (!(last == sentinel))
		++last;

	return UpperBound(first, last, value);
}

//----------------------------------------------------------------------------------------
/// Equivalent to UpperBound(first, last, value, comp).
/// @c last is determined by incrementing @c first until it matches the sequence delimiter @c sentinel.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename T, typename COMPARE>
inline auto UpperBound(ITERATOR first, SENTINEL sentinel, const T& value, COMPARE comp) -> ITERATOR
{
	ITERATOR last = first;
	while (!(last == sentinel))
		++last;

	return UpperBound(first, last, value, comp);
}

//----------------------------------------------------------------------------------------
/// Equivalent to LowerBound(begin(iterable), end(iterable), value).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename T>
inline auto UpperBound(ITERABLE&& iterable, const T& value) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return UpperBound(begin(iterable), end(iterable), value);
}

//----------------------------------------------------------------------------------------
/// Equivalent to LowerBound(begin(iterable), end(iterable), value, comp).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename T, typename COMPARE>
inline auto UpperBound(ITERABLE&& iterable, const T& value, COMPARE comp) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return UpperBound(begin(iterable), end(iterable), value, comp);
}

//----------------------------------------------------------------------------------------
/// Returns an iterator to the first element in a sequence that is equal to the given value,
/// or @c NO_VALUE if no match was found.
/// Binary search is used to locate the element, so the sequence must be ordered.
/// Elements must be comparable with the less-than operator.
///
/// @param[in] first							Start of sequence.
/// @param[in] last								End of sequence.
/// @param[in] value							The bounding value.
/// @return												Iterator to position of the found element.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename T>
inline auto BinarySearch(ITERATOR first, ITERATOR last, const T& value) -> Optional<ITERATOR>
{
	using maxon::details::LessThanCompare;
	using ValueType = typename std::iterator_traits<ITERATOR>::value_type;

	return BinarySearch(first, last, value, LessThanCompare<T, ValueType>());
}

//----------------------------------------------------------------------------------------
/// Equivalent to BinarySearch(first, last, value).
/// @c last is determined by incrementing @c first until it matches the sequence delimiter @c sentinel.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename T>
inline auto BinarySearch(ITERATOR first, SENTINEL sentinel, const T& value) -> Optional<ITERATOR>
{
	ITERATOR last = first;
	while (!(last == sentinel))
		++last;

	return BinarySearch(first, last, value);
}

//----------------------------------------------------------------------------------------
/// Equivalent to BinarySearch, but uses the given function to compare elements
/// instead of the less-than operator. The sequence must be ordered by the same function.
/// The compare function should have a signature equivalent to
/// @code
/// Bool comp(const ElementType1&, const ElementType2&);
/// @endcode
///
/// @param[in] first							Start of sequence.
/// @param[in] last								End of sequence.
/// @param[in] value							The bounding value.
/// @param[in] comp								Binary compare function.
/// @return												Iterator to position of the upper bound.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename T, typename COMPARE>
inline auto BinarySearch(ITERATOR first, ITERATOR last, const T& value, COMPARE comp) -> Optional<ITERATOR>
{
	ITERATOR result = LowerBound(first, last, value, comp);

	if (!(result == last) && !comp(value, *result))
		return result;
	else
		return NO_VALUE;
}

//----------------------------------------------------------------------------------------
/// Equivalent to BinarySearch(first, last, value, comp).
/// @c last is determined by incrementing @c first until it matches the sequence delimiter @c sentinel.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename T, typename COMPARE>
inline auto BinarySearch(ITERATOR first, SENTINEL sentinel, const T& value, COMPARE comp) -> Optional<ITERATOR>
{
	ITERATOR last = first;
	while (!(last == sentinel))
		++last;

	return BinarySearch(first, last, value, comp);
}

//----------------------------------------------------------------------------------------
/// Equivalent to BinarySearch(begin(iterable), end(iterable), value).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename T>
inline auto BinarySearch(ITERABLE&& iterable, const T& value) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return BinarySearch(begin(iterable), end(iterable), value);
}

//----------------------------------------------------------------------------------------
/// Equivalent to BinarySearch(begin(iterable), end(iterable), value, comp).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename T, typename COMPARE>
inline auto BinarySearch(ITERABLE&& iterable, const T& value, COMPARE comp) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return BinarySearch(begin(iterable), end(iterable), value, comp);
}

//----------------------------------------------------------------------------------------
/// Rotates elements in sequence [first, last) to the left so that newFirst becomes the new first element.
///
/// Example:
/// @code
/// CArray<Int> values = { 1, 2, 3, 4, 5, 6 };
/// auto match = BinarySearch(values, 3);
/// if (match)
///		auto it = Rotate(begin(values), end(values), match.GetPosition());
/// // New order: { 3, 4, 5, 6, 1, 2 }
/// // it points to position at index 4 (value 1).
/// @endcode
///
/// This function is the equivalent to std::rotate. Note that the order of the arguments is different here.
///
/// @param[in] first							Start of sequence.
/// @param[in] last								End of sequence.
/// @param[in] newFirst						Iterator to element that should become the new first element.
/// @return												Iterator to new position of old first element.
//----------------------------------------------------------------------------------------
template <typename ITERATOR>
inline auto Rotate(ITERATOR first, ITERATOR last, ITERATOR newFirst) -> ITERATOR
{
	Reverse(first, newFirst);
	Reverse(newFirst, last);
	Reverse(first, last);

	return first + (last - newFirst);
}

//----------------------------------------------------------------------------------------
/// Equivalent to Rotate(begin(iterable), end(iterable), newFirst).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename ITERATOR>
inline auto Rotate(ITERABLE&& iterable, ITERATOR newFirst) -> ITERATOR
{
	return Rotate(begin(iterable), end(iterable), newFirst);
}

//----------------------------------------------------------------------------------------
/// Equivalent to Rotate(first, last, newFirst).
/// @c last is determined by incrementing @c first until it matches the sequence delimiter @c sentinel.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL>
inline auto Rotate(ITERATOR first, SENTINEL sentinel, ITERATOR newFirst) -> ITERATOR
{
	ITERATOR last = first;
	while (!(last == sentinel))
		++last;

	return Rotate(first, last, newFirst);
}

//----------------------------------------------------------------------------------------
/// Returns the number of elements in a sequence that are equal to the given value.
///
/// This function is the equivalent to std::count.
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @param[in] value							The counted value.
/// @return												Number of occurrences.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename T>
inline Int Count(ITERATOR first, SENTINEL sentinel, const T& value)
{
	Int result = 0;

	for (; !(first == sentinel); ++first)
	{
		if (*first == value)
			++result;
	}

	return result;
}

//----------------------------------------------------------------------------------------
/// Equivalent to Count(begin(iterable), end(iterable), value).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename T>
inline Int Count(ITERABLE&& iterable, const T& value)
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return Count(begin(iterable), end(iterable), value);
}

//----------------------------------------------------------------------------------------
/// Returns the number of elements in a sequence that are matched by the given predicate.
/// The predicate function should have a signature equivalent to
/// @code
/// Bool func(const ElementType&);
/// @endcode
///
/// This function is the equivalent to std::count_if.
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @param[in] pred								Unary predicate.
/// @return												Number of occurrences.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename PREDICATE>
inline Int CountIf(ITERATOR first, SENTINEL sentinel, PREDICATE pred)
{
	Int result = 0;

	for (; !(first == sentinel); ++first)
	{
		if (pred(*first))
			++result;
	}

	return result;
}

//----------------------------------------------------------------------------------------
/// Equivalent to CountIf(begin(iterable), end(iterable), pred).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename PREDICATE>
inline auto CountIf(const ITERABLE& iterable, PREDICATE pred) -> Int
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return CountIf(begin(iterable), end(iterable), pred);
}

//----------------------------------------------------------------------------------------
/// Re-arranges elements in sequence so that consecutive (!) duplicate elements are removed.
/// Relative order of the elements is preserved.
///
/// This function is the equivalent to std::unique.
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @return												End of the re-arranged sequence.
//----------------------------------------------------------------------------------------
template
<
	typename ITERATOR, typename SENTINEL,
	typename = typename std::enable_if<!IsIterable<ITERATOR>::value>::type
>
inline auto Unique(ITERATOR first, SENTINEL sentinel) -> ITERATOR
{
	using maxon::details::EqualityCompare;

	using ValueType = typename std::iterator_traits<ITERATOR>::value_type;

	return Unique(first, sentinel, EqualityCompare<ValueType, ValueType>());
}

//----------------------------------------------------------------------------------------
/// Equivalent to Unique(begin(iterable), end(iterable)).
//----------------------------------------------------------------------------------------
template <typename ITERABLE>
inline auto Unique(ITERABLE&& iterable) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return Unique(begin(iterable), end(iterable));
}

//----------------------------------------------------------------------------------------
/// Equivalent to Unique, but uses the given function to compare elements
/// instead of the less-than operator. The sequence must be ordered by the same function.
/// The compare function should have a signature equivalent to
/// @code
/// Bool comp(const ElementType1&, const ElementType2&);
/// @endcode
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @param[in] comp								Binary compare function.
/// @return												End of the re-arranged sequence.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename COMPARE>
inline auto Unique(ITERATOR first, SENTINEL sentinel, COMPARE comp) -> ITERATOR
{
	if (first == sentinel)
		return first;

	ITERATOR result = first;

	while (!(++first == sentinel))
	{
		if (!comp(*result, *first) && ++result != first)
		{
			*result = std::move(*first);
		}
	}

	return ++result;
}

//----------------------------------------------------------------------------------------
/// Equivalent to Unique(begin(iterable), end(iterable), comp).
//----------------------------------------------------------------------------------------
template
<
	typename ITERABLE, typename COMPARE,
	typename = typename std::enable_if<IsIterable<ITERABLE>::value>::type
>
inline auto Unique(ITERABLE&& iterable, COMPARE comp) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return Unique(begin(iterable), end(iterable), comp);
}

//----------------------------------------------------------------------------------------
/// Re-arranges elements in a sequence so that elements equal to value are removed.
/// Relative order of the elements is preserved.
///
/// This function is the equivalent to std::remove.
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @param[in] value							The removed value.
/// @return												End of the re-arranged sequence.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename T>
inline auto Remove(ITERATOR first, SENTINEL sentinel, const T& value) -> ITERATOR
{
	// Find first match
	for (; !(first == sentinel); ++first)
		if (*first == value)
			break;

	if (first == sentinel)
		return first;

	// Shift elements after match
	ITERATOR next = first;
	++first;

	for (; !(first == sentinel); ++first)
	{
		if (!(*first == value))
		{
			*next = std::move(*first);
			++next;
		}
	}

	return next;
}

//----------------------------------------------------------------------------------------
/// Equivalent to Remove(begin(iterable), end(iterable), value).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename T>
inline auto Remove(ITERABLE&& iterable, const T& value) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return Remove(begin(iterable), end(iterable), value);
}

//----------------------------------------------------------------------------------------
/// Re-arranges elements in a sequence so that elements matching the given predicate are removed.
/// Relative order of the elements is preserved.
/// The predicate function should have a signature equivalent to
/// @code
/// Bool func(const ElementType&);
/// @endcode
///
/// This function is the equivalent to std::remove_if.
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @param[in] pred								Unary predicate.
/// @return												End of the re-arranged sequence.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename PREDICATE>
inline auto RemoveIf(ITERATOR first, SENTINEL sentinel, PREDICATE pred) -> ITERATOR
{
	// Find first match
	for (; !(first == sentinel); ++first)
		if (pred(*first))
			break;

	if (first == sentinel)
		return first;

	// Shift elements after match
	ITERATOR next = first;
	++first;

	for (; !(first == sentinel); ++first)
	{
		if (!pred(*first))
		{
			*next = std::move(*first);
			++next;
		}
	}

	return next;
}

//----------------------------------------------------------------------------------------
/// Equivalent to RemoveIf(begin(iterable), end(iterable), pred).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename PREDICATE>
inline auto RemoveIf(ITERABLE&& iterable, PREDICATE pred) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return RemoveIf(begin(iterable), end(iterable), pred);
}

//----------------------------------------------------------------------------------------
/// Replaces elements in sequence [first, ...) that are equal to oldValue with copies of newValue.
///
/// This function is the equivalent to std::replace.
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @param[in] oldValue						Old value.
/// @param[in] newValue						New value.
/// @return												End of the modified sequence.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename T>
inline auto Replace(ITERATOR first, SENTINEL sentinel, const T& oldValue, const T& newValue) -> ITERATOR
{
	for (; !(first == sentinel); ++first)
		if (*first == oldValue)
			*first = newValue;

	return first;
}

//----------------------------------------------------------------------------------------
/// Equivalent to Replace(begin(iterable), end(iterable), oldValue, newValue).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename T>
inline auto Replace(ITERABLE&& iterable, const T& oldValue, const T& newValue) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return Replace(begin(iterable), end(iterable), oldValue, newValue);
}

//----------------------------------------------------------------------------------------
/// Replaces elements in sequence [first, ...) that match the given predicate with copies of newValue.
/// The predicate function should have a signature equivalent to
/// @code
/// Bool func(const ElementType&);
/// @endcode
///
/// This function is the equivalent to std::replace.
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @param[in] pred								Unary predicate.
/// @param[in] newValue						New value.
/// @return												End of the modified sequence.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename PREDICATE, typename T>
inline auto ReplaceIf(ITERATOR first, SENTINEL sentinel, PREDICATE pred, const T& newValue) -> ITERATOR
{
	for (; !(first == sentinel); ++first)
		if (pred(*first))
			*first = newValue;

	return first;
}

//----------------------------------------------------------------------------------------
/// Equivalent to ReplaceIf(begin(iterable), end(iterable), pred, newValue).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename PREDICATE, typename T>
inline auto ReplaceIf(ITERABLE&& iterable, PREDICATE pred, const T& newValue) -> decltype(begin(iterable))
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return ReplaceIf(begin(iterable), end(iterable), pred, newValue);
}

//----------------------------------------------------------------------------------------
/// Folds elements in the sequence [first, ...) from left to right with a binary function.
/// The folding function should have a signature equivalent to
/// @code
/// V func(const V&, const ElementType&);
/// @endcode
///
/// This function is the equivalent to std::accumulate.
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @param[in] op									Folding function.
/// @return												Folded value.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename V, typename BINARYOP>
inline V Fold(ITERATOR first, SENTINEL sentinel, V initialValue, BINARYOP op)
{
	for (; !(first == sentinel); ++first)
		initialValue = op(initialValue, *first);

	return initialValue;
}

//----------------------------------------------------------------------------------------
/// Equivalent to Fold(begin(iterable), end(iterable), initialValue, op).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename V, typename BINARYOP>
inline V Fold(const ITERABLE& iterable, const V& intitialValue, BINARYOP op)
{
	static_assert(IsIterable<ITERABLE>::value, "iterable must support begin(iterable) and end(iterable)");

	return Fold(begin(iterable), end(iterable), intitialValue, op);
}

//----------------------------------------------------------------------------------------
/// Finds the smallest element a sequence, or NO_VALUE if the sequence was empty.
/// Elements must be comparable with the less-than operator.
///
/// This function is the equivalent to std::min_element.
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @return												Iterator to element with minimum value or NO_VALUE.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL>
inline auto MinElement(ITERATOR first, SENTINEL sentinel) -> Optional<ITERATOR>
{
	using maxon::details::LessThanCompare;

	using ValueType = typename std::iterator_traits<ITERATOR>::value_type;

	return MinElement(first, sentinel, LessThanCompare<ValueType, ValueType>());
}

//----------------------------------------------------------------------------------------
/// Equivalent to MinElement, but uses the given function to compare elements instead of the less-than operator.
/// The comparison function should have a signature equivalent to
/// @code
/// Bool func(const ElementType&, const ElementType&);
/// @endcode
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @param[in] comp								Comparison function.
/// @return												Minimum value.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename COMPARE>
inline auto MinElement(ITERATOR first, SENTINEL sentinel, COMPARE comp) -> Optional<ITERATOR>
{
	if (first == sentinel)
		return NO_VALUE;

	ITERATOR minIt = first;
	++first;

	for (; !(first == sentinel); ++first)
		if (comp(*first, *minIt))
			minIt = first;

	return minIt;
}

//----------------------------------------------------------------------------------------
/// Equivalent to MinElement(begin(iterable), end(iterable)).
//----------------------------------------------------------------------------------------
template <typename ITERABLE>
inline auto MinElement(ITERABLE&& iterable) -> Optional<decltype(begin(iterable))>
{
	return MinElement(begin(iterable), end(iterable));
}

//----------------------------------------------------------------------------------------
/// Equivalent to MinElement(begin(iterable), end(iterable), comp).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename COMPARE>
inline auto MinElement(ITERABLE&& iterable, COMPARE comp) -> Optional<decltype(begin(iterable))>
{
	return MinElement(begin(iterable), end(iterable), comp);
}

//----------------------------------------------------------------------------------------
/// Finds the largest element a sequence, or NO_VALUE if the sequence was empty.
/// Elements must be comparable with the less-than operator.
///
/// This function is the equivalent to std::max_element.
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @return												Iterator to element with maximum value or NO_VALUE.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL>
inline auto MaxElement(ITERATOR first, SENTINEL sentinel) -> Optional<ITERATOR>
{
	using maxon::details::LessThanCompare;

	using ValueType = typename std::iterator_traits<ITERATOR>::value_type;

	return MaxElement(first, sentinel, LessThanCompare<ValueType, ValueType>());
}

//----------------------------------------------------------------------------------------
/// Equivalent to MaxElement, but uses the given function to compare elements instead of the less-than operator.
/// The comparison function should have a signature equivalent to
/// @code
/// Bool func(const ElementType&, const ElementType&);
/// @endcode
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @param[in] comp								Comparison function.
/// @return												Maximum value.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename COMPARE>
inline auto MaxElement(ITERATOR first, SENTINEL sentinel, COMPARE comp) -> Optional<ITERATOR>
{
	if (first == sentinel)
		return NO_VALUE;

	ITERATOR minIt = first;
	++first;

	for (; !(first == sentinel); ++first)
		if (comp(*first, *minIt))
			minIt = first;

	return minIt;
}

//----------------------------------------------------------------------------------------
/// Equivalent to MaxElement(begin(iterable), end(iterable)).
//----------------------------------------------------------------------------------------
template <typename ITERABLE>
inline auto MaxElement(ITERABLE&& iterable) -> Optional<decltype(begin(iterable))>
{
	return MaxElement(begin(iterable), end(iterable));
}


//----------------------------------------------------------------------------------------
/// Equivalent to MaxElement(begin(iterable), end(iterable), comp).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename COMPARE>
inline auto MaxElement(ITERABLE&& iterable, COMPARE comp) -> Optional<decltype(begin(iterable))>
{
	return MaxElement(begin(iterable), end(iterable), comp);
}

//----------------------------------------------------------------------------------------
/// Returns the number of elements in a sequence [first, ... last) as Int(last - first).
//----------------------------------------------------------------------------------------
template <typename ITERATOR>
inline Int GetSequenceLength(ITERATOR first, ITERATOR last)
{
	return last - first;
}

//----------------------------------------------------------------------------------------
/// Equivalent to GetSequenceLength(first, last).
/// @c last is determined by incrementing @c first until it matches the sequence delimiter @c sentinel.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL>
inline Int GetSequenceLength(ITERATOR first, SENTINEL sentinel)
{
	ITERATOR last = first;
	while (!(last == sentinel))
		++last;

	return GetSequenceLength(first, last);
}

//----------------------------------------------------------------------------------------
/// Equivalent to GetSequenceLength(begin(iterable), end(iterable)).
//----------------------------------------------------------------------------------------
template <typename ITERABLE>
inline Int GetSequenceLength(const ITERABLE& iterable)
{
	return GetSequenceLength(begin(iterable), end(iterable));
}

enum class NO_MATCH_TYPE
{
	VALUE = 1
} MAXON_ENUM_LIST(NO_MATCH_TYPE);

static const NO_MATCH_TYPE NO_MATCH = NO_MATCH_TYPE::VALUE;

//----------------------------------------------------------------------------------------
/// A Match represents a part of a sequence, consisting of start position and length.
/// Depending on the operation, the position type may be either an iterator or an index.
//----------------------------------------------------------------------------------------
template <typename ITERATOR> class Match
{
public:
	/// Constructs a match that is NO_MATCH.
	Match() = default;

	/// Copy constructor.
	Match(const Match&) = default;

	/// Copy assignment.
	Match& operator =(Match&) = default;

	/// Move constructor.
	Match(Match&& src) : MAXON_MOVE_MEMBERS(_position, _length) { }

	/// Move assignment.
	Match& operator =(Match&& src)
	{
		_position = std::move(src._position);
		_length = src._length;
		return *this;
	}

	/// Implicit construction from NO_MATCH.
	MAXON_IMPLICIT Match(NO_MATCH_TYPE) { }

	/// Assignment of NO_MATCH.
	Match& operator =(NO_MATCH_TYPE)
	{
		_position = ITERATOR();
		_length = 0;
		return *this;
	}

	/// Construction from a position with a default length of 1.
	MAXON_IMPLICIT Match(ITERATOR position) : _position(position), _length(1) { }

	/// Construction from a position and length.
	Match(ITERATOR position, Int length) : _position(position), _length(length) { }

	/// Returns the first position of the match.
	ITERATOR GetPosition() const { return _position; }

	/// Implicit conversion to position type. Equivalent to GetPosition().
	operator ITERATOR() const { return GetPosition(); }

	/// Returns the length of the match.
	Int GetLength() const { return _length; }

	/// Returns, if this match represents a valid position, or if it is a NO_MATCH.
	Bool IsFound() const { return _length > 0; }

	/// Conversion to Bool in conditional expressions (i.e. if statements). Equivalent to IsFound().
	explicit operator Bool() const { return IsFound(); }

private:
	ITERATOR	_position;
	Int				_length = 0;
};

//----------------------------------------------------------------------------------------
/// Match specialization for index position type.
//----------------------------------------------------------------------------------------
template <> class Match<Int>
{
public:
	/// Constructs a match that is NO_MATCH.
	Match() = default;

	/// Copy constructor.
	Match(const Match&) = default;

	/// Copy assignment.
	Match& operator =(Match&) = default;

	/// Implicit construction from NO_MATCH.
	MAXON_IMPLICIT Match(NO_MATCH_TYPE) { }

	/// Assignment of NO_MATCH.
	Match& operator =(NO_MATCH_TYPE)
	{
		_index = 0;
		_length = 0;
		return *this;
	}

	/// Construction from a index position with a default length of 1.
	MAXON_IMPLICIT Match(Int index) : _index(index), _length(1) { }

	/// Construction from a index position and length.
	Match(Int index, Int length) : _index(index), _length(length) { }

	/// Returns the first position of the match.
	Int GetPosition() const { return _index; }

	/// Returns the first position of the match.
	operator Int() const { return GetPosition(); }

	/// Implicit to index type Int. Equivalent to GetPosition().
	Int GetLength() const { return _length; }

	/// Returns, if this match represents a valid position, or if it is a NO_MATCH.
	Bool IsFound() const { return _length > 0; }

	/// Conversion to Bool in conditional expressions (i.e. if statements). Equivalent to IsFound().
	explicit operator Bool() const { return IsFound(); }

private:
	Int		_index = 0;
	Int		_length = 0;
};

//----------------------------------------------------------------------------------------
/// Searches for the first occurrence of a pattern in a sequence.
/// Different matchers allow to search for specific types of patterns, i.e. single values, sub-sequences, predicates.
///
/// Examples:
/// @code
/// CArray<Int> values = { 40, 42, 1, 1, 2, 3 };
///
/// // Search for value 42
/// auto match1 = LinearSearch(values.Begin(), values.End(), ByValue(42));
/// if (match1)
/// {
///		auto it = match.GetPosition();
///   Int length = match.GetLength();
/// }
///
/// // Search for pattern
/// CArray<Int> pattern = { 1, 2, 3 };
/// auto match2 = LinearSearch(values, BySequence(pattern));
///
/// // Search for a value satisfying a predicate
/// auto match3 = LinearSearch(values, ByPredicate([] (Int v) { return v < 33; }));
/// @endcode
///
/// This function is the equivalent to std::find, std::search, ...
///
/// @param[in] first							Start of sequence.
/// @param[in] sentinel						Sequence delimiter.
/// @param[in] matcher						Pattern matcher.
/// @return												Match containing iterator and length to the found subsequence.
//----------------------------------------------------------------------------------------
template <typename ITERATOR, typename SENTINEL, typename MATCHER>
inline auto LinearSearch(ITERATOR first, SENTINEL sentinel, MATCHER matcher) -> Match<ITERATOR>
{
	return matcher.FindNext(first, sentinel);
}

//----------------------------------------------------------------------------------------
/// Equivalent to LinearSearch(begin(iterable), end(iterable), matcher).
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename MATCHER>
inline auto LinearSearch(ITERABLE&& iterable, MATCHER matcher) -> Match<decltype(begin(iterable))>
{
	return matcher.FindNext(begin(iterable), end(iterable));
}

//----------------------------------------------------------------------------------------
/// Index-based version of LinearSearch. For an index pair (N,M) with N <= M, the input sequence is
/// (indexable[N], indexable[N+1], ... , indexable[M-1]).
///
/// Examples:
/// @code
/// CArray<Int> values = { 40, 42, 1, 1, 2, 3 };
///
/// // Search for value 42
/// auto match1 = LinearSearchIndex(values.Begin(), values.End(), ByValue(42));
/// if (match1)
/// {
///		Int index = match.GetPosition();
///   Int length = match.GetLength();
/// }
///
/// @param[in] indexable					Indexable container.
/// @param[in] indexPair					Start and end indices of the input sequence.
/// @param[in] matcher						Pattern matcher.
/// @return												Match containing index and length to the found subsequence.
//----------------------------------------------------------------------------------------
template <typename INDEXABLE, typename MATCHER>
inline auto LinearSearchIndex(const INDEXABLE& indexable, IndexPair indexPair, MATCHER matcher) -> Match<Int>
{
	return matcher.FindNextIndex(indexable, indexPair);
}

//----------------------------------------------------------------------------------------
/// Equivalent to LinearSearchIndex(indexable, {0, GetSequenceLength(indexable)}, matcher).
//----------------------------------------------------------------------------------------
template <typename INDEXABLE, typename MATCHER>
inline auto LinearSearchIndex(const INDEXABLE& indexable, MATCHER matcher) -> Match<Int>
{
	return matcher.FindNextIndex(indexable, {0, GetSequenceLength(indexable)});
}

//----------------------------------------------------------------------------------------
/// Splits a sequence into a variable number of parts, whereat the given matcher is used to find separators.
/// The parts are stored in a BaseArray and of the same type as ITERABLE.
/// If no seperator was found in the sequence, the returned array will be empty.
///
/// To create the parts, the ITERABLE type must be constructible with
/// @code
/// using IteratorType = decltype(begin(iterable));
/// ITERABLE(IteratorType pos, Int length);
/// @endcode
///
/// @param[in] iterable						Input sequence.
/// @param[in] matcher						Separator used to divide the sequence.
/// @return												BaseArray containing the parts, or error if allocation failed.
//----------------------------------------------------------------------------------------
template <typename ITERABLE, typename MATCHER>
inline auto Split(const ITERABLE& iterable, MATCHER matcher) -> Result<BaseArray<ITERABLE>>
{
	iferr_scope;

	BaseArray<ITERABLE> parts;

	auto first = begin(iterable);
	auto last  = end(iterable);

	while (true)
	{
		auto result = matcher.FindNext(first, last);

		// Delimiter was not found
		if (!result.IsFound())
			break;

		auto resultStart = result.GetPosition();
		auto resultEnd = resultStart + result.GetLength();
		Int partLength = GetSequenceLength(first, resultStart);

		parts.Append(ITERABLE{first, partLength}) iferr_return;

		first = resultEnd;
	}

	return std::move(parts);
}

//----------------------------------------------------------------------------------------
/// Index-based version of Split. For an index pair (N,M) with N <= M, the input sequence is
/// (indexable[N], indexable[N+1], ... , indexable[M-1]).
/// The resulting BaseArray contains Matches, storing the index and length of each split part.
///
/// @param[in] indexable					Indexable container.
/// @param[in] indexPair					Start and end indices of the input sequence.
/// @param[in] matcher						Pattern matcher.
/// @return												BaseArray containing Matches, or error if allocation failed.
//----------------------------------------------------------------------------------------
template <typename INDEXABLE, typename MATCHER>
inline auto SplitIndex(const INDEXABLE& indexable, IndexPair indexPair, MATCHER matcher) -> Result<BaseArray<Match<Int>>>
{
	iferr_scope;

	BaseArray<Match<Int>> parts;

	while (true)
	{
		auto result = matcher.FindNextIndex(indexable, indexPair);

		// Delimiter was not found
		if (!result.IsFound())
			break;

		parts.Append({indexPair.first, result.GetPosition() - indexPair.first}) iferr_return;

		indexPair.first = result.GetPosition() + result.GetLength();
	}

	return std::move(parts);
}

//----------------------------------------------------------------------------------------
/// Equivalent to SplitIndex(indexable, {0, GetSequenceLength(indexable)}, matcher).
//----------------------------------------------------------------------------------------
template <typename INDEXABLE, typename MATCHER>
inline auto SplitIndex(const INDEXABLE& indexable, MATCHER matcher) -> Result<void>
{
	return SplitIndex(indexable, {0, GetSequenceLength(indexable)}, matcher);
}

namespace details
{

template <Int REMAINING_COUNT, Int I>
struct StaticSplitHelper
{
	template <typename ITERABLE, typename TUP, typename ITERATOR, typename MATCHER>
	static void Split(TUP& parts, ITERATOR first, ITERATOR last, const MATCHER& matcher)
	{
		auto result = matcher.FindNext(first, last);

		// Delimiter was not found
		if (!result.IsFound())
			return;

		auto resultStart = result.GetPosition();
		auto resultEnd = resultStart + result.GetLength();

		// Everything left of the delimiter is our matched part
		parts.template Get<I>() = ITERABLE(first, GetSequenceLength(first, resultStart));

		// Everything right of the delimiter is passed on to next iteration
		StaticSplitHelper<REMAINING_COUNT - 1, I + 1>::template Split<ITERABLE>(parts, resultEnd, last, matcher);
	}

	template <typename TUP, typename INDEXABLE, typename MATCHER>
	static void SplitIndex(TUP& parts, const INDEXABLE& indexable, IndexPair indexPair, const MATCHER& matcher)
	{
		auto result = matcher.FindNextIndex(indexable, indexPair);

		// Delimiter was not found
		if (!result.IsFound())
			return;

		// Everything left of the delimiter is our matched part
		parts.template Get<I>() = Match<Int>(indexPair.first, result.GetPosition() - indexPair.first);

		indexPair.first = result.GetPosition() + result.GetLength();

		// Everything right of the delimiter is passed on to next iteration
		StaticSplitHelper<REMAINING_COUNT - 1, I + 1>::SplitIndices(parts, indexable, indexPair, matcher);
	}
};

template <Int I>
struct StaticSplitHelper<0, I>
{
	template <typename ITERABLE, typename TUP, typename ITERATOR, typename MATCHER>
	static void Split(TUP& parts, ITERATOR first, ITERATOR last, const MATCHER& matcher)
	{
		parts.template Get<I>() = ITERABLE(first, GetSequenceLength(first, last));
	}

	template <typename TUP, typename INDEXABLE, typename MATCHER>
	static void SplitIndex(TUP& parts, const INDEXABLE& indexable, IndexPair indexPair, const MATCHER& matcher)
	{
		parts.template Get<I>() = Match<Int>(indexPair.first, indexPair.second - indexPair.first);
	}
};

}

//----------------------------------------------------------------------------------------
/// Splits a sequence into @c COUNT parts, whereat the given matcher is used to find separators.
/// The parts are returned in a Tuple and of the same type as ITERABLE.
/// The split strategy is to fill in the tuple elements from left to right as long as more parts are found.
/// This means if the number of found parts N == COUNT, each element contains exactly one part.
/// If N < COUNT, the last COUNT - N elements are emtpy.
/// If N > COUNT, the last element countains the additional N + COUNT parts (including seperators).
///
/// To create the parts, the ITERABLE type must be constructible with
/// @code
/// using IteratorType = decltype(begin(iterable));
/// ITERABLE(IteratorType pos, Int length);
/// @endcode
///
/// @param[in] iterable						Input sequence.
/// @param[in] matcher						Separator used to divide the sequence.
/// @return												Tuple containing split parts.
//----------------------------------------------------------------------------------------
template <Int COUNT, typename ITERABLE, typename MATCHER>
inline auto SplitToTuple(const ITERABLE& iterable, MATCHER matcher) -> HomogenousTupleType<COUNT, ITERABLE>
{
	static_assert(COUNT >= 2, "Split COUNT must be at least 2.");

	HomogenousTupleType<COUNT, ITERABLE> parts;

	maxon::details::StaticSplitHelper<COUNT - 1, 0>::template Split<ITERABLE>(parts, begin(iterable), end(iterable), matcher);

	return parts;
}

//----------------------------------------------------------------------------------------
/// Index-based version of SplitToTuple. For an index pair (N,M) with N <= M, the input sequence is
/// (indexable[N], indexable[N+1], ... , indexable[M-1]).
/// The resulting Tuple contains Matches, storing the index and length of each split part.
///
/// @param[in] indexable					Indexable container.
/// @param[in] indexPair					Start and end indices of the input sequence.
/// @param[in] matcher						Pattern matcher.
/// @return												BaseArray containing Matches, or error if allocation failed.
//----------------------------------------------------------------------------------------
template <Int COUNT, typename INDEXABLE, typename MATCHER>
inline auto SplitToTupleIndex(const INDEXABLE& indexable, IndexPair indexPair, MATCHER matcher) -> HomogenousTupleType<COUNT, Match<Int>>
{
	static_assert(COUNT >= 2, "Split COUNT must be at least 2.");

	HomogenousTupleType<COUNT, Match<Int>> parts;

	maxon::details::StaticSplitHelper<COUNT - 1, 0>::SplitIndices(parts, indexable, indexPair, matcher);

	return parts;
}

//----------------------------------------------------------------------------------------
/// Equivalent to SplitToTupleIndex(indexable, {0, GetSequenceLength(indexable)}, matcher).
//----------------------------------------------------------------------------------------
template <Int COUNT, typename INDEXABLE, typename MATCHER>
inline auto SplitToTupleIndex(const INDEXABLE& indexable, MATCHER matcher) -> HomogenousTupleType<COUNT, Match<Int>>
{
	return SplitToTupleIndex<COUNT>(indexable, IndexPair(0, GetSequenceLength(indexable)), matcher);
}

//----------------------------------------------------------------------------------------
/// Iteratively splits a sequence into parts, whereat the given matcher is used to find separators.
/// Each successive part is passed as an argument to the iterate function.
/// The iteration terminates when all parts have been processed, or if the iteration returns false or an error.
/// In case of an error, it's passed on as the return value.
///
/// To create the parts, the ITERABLE type must be constructible with
/// @code
/// using IteratorType = decltype(begin(iterable));
/// ITERABLE(IteratorType pos, Int length);
/// @endcode
///
/// The iteration function function should have a signature equivalent to
/// @code
/// Bool iterFunc(const ElementType&);
/// @endcode
///
/// @param[in] iterFunc						Iteration function.
/// @param[in] iterable						Input sequence.
/// @param[in] matcher						Separator used to divide the sequence.
/// @return												True, if no iteration function returned false and at least 1 part was found, false otherwise, or an error.
//----------------------------------------------------------------------------------------
template <typename ITERATE_FUNC, typename ITERABLE, typename MATCHER>
inline auto SplitIterate(ITERATE_FUNC iterFunc, const ITERABLE& iterable, MATCHER matcher) -> Result<Bool>
{
	iferr_scope;

	// We only check the "rest" part of the delimiter was matched at least once
	Bool anyMatchFound = false;

	// success is true, if
	// - all iterFunc calls returned true.
	// - we found at least one match.
	Bool success = false;

	auto first = begin(iterable);
	auto last = end(iterable);

	while (true)
	{
		auto result = matcher.FindNext(first, last);

		// Delimiter was not found
		if (!result.IsFound())
			break;

		anyMatchFound = true;

		auto resultStart = result.GetPosition();
		auto resultEnd = resultStart + result.GetLength();

		success = iterFunc(ITERABLE(first, GetSequenceLength(first, resultStart))) iferr_return;
		if (!success)
			break;

		first = resultEnd;
	}

	// This is the "rest" after the last delimiter match
	if (success && anyMatchFound)
	{
		success = iterFunc(ITERABLE(first, GetSequenceLength(first, last))) iferr_return;
	}

	return success;
}
//----------------------------------------------------------------------------------------
/// Index-based version of SplitIterateIndex. For an index pair (N,M) with N <= M, the input sequence is
/// (indexable[N], indexable[N+1], ... , indexable[M-1]).
///
/// The iteration function function should have a signature equivalent to
/// @code
/// Bool iterFunc(const ElementType&);
/// @endcode
///
/// @param[in] iterFunc						Iteration function.
/// @param[in] indexable					Indexable container.
/// @param[in] indexPair					Start and end indices of the input sequence.
/// @param[in] matcher						Pattern matcher.
/// @return												True, if no iteration function returned false and at least 1 part was found, false otherwise, or an error.
//----------------------------------------------------------------------------------------
template <typename ITERATE_FUNC, typename INDEXABLE, typename MATCHER>
inline auto SplitIterateIndex(ITERATE_FUNC iterFunc, const INDEXABLE& indexable, IndexPair indexPair, MATCHER matcher) -> Result<Bool>
{
	iferr_scope;

	// We only check the "rest" part of the delimiter was matched at least once
	Bool anyMatchFound = false;

	// success is true, if
	// - all iterFunc calls returned true.
	// - we found at least one match.
	Bool success = false;

	while (true)
	{
		auto result = matcher.FindNextIndex(indexable, indexPair);

		// Delimiter was not found
		if (!result.IsFound())
			break;

		anyMatchFound = true;

		success = iterFunc(Match<Int>(indexPair.first, result.GetPosition() - indexPair.first)) iferr_return;
		if (!success)
			break;

		indexPair.first = result.GetPosition() + result.GetLength();
	}

	// This is the "rest" after the last delimiter match
	if (success && anyMatchFound)
	{
		success = iterFunc(Match<Int>(indexPair.first, indexPair.second - indexPair.first)) iferr_return;
	}

	return success;
}

//----------------------------------------------------------------------------------------
/// Equivalent to SplitIterateIndex(iterFunc, indexable, {0, GetSequenceLength(indexable)}, matcher).
//----------------------------------------------------------------------------------------
template <typename ITERATE_FUNC, typename INDEXABLE, typename MATCHER>
inline auto SplitIterateIndex(ITERATE_FUNC iterFunc, const INDEXABLE& indexable, const MATCHER& matcher) -> Result<Bool>
{
	return SplitIterateIndex(iterFunc, indexable, {0, GetSequenceLength(indexable)}, matcher);
}

//----------------------------------------------------------------------------------------
/// A matcher that finds the first element which satisfies a predicate.
//----------------------------------------------------------------------------------------
template <typename PRED>
struct PredicateMatcher
{
	explicit PredicateMatcher(const PRED& predIn) : pred(predIn) { }

	PredicateMatcher(const PredicateMatcher&) = default;

	PredicateMatcher& operator =(const PredicateMatcher&) = default;

	template <typename ITERATOR, typename SENTINEL>
	auto FindNext(ITERATOR first, SENTINEL sentinel) const -> Match<ITERATOR>
	{
		for (; !(first == sentinel); ++first)
		{
			if (pred(*first))
				return first;
		}

		return NO_MATCH;
	}

	template <typename INDEXABLE>
	auto FindNextIndex(const INDEXABLE& indexable, IndexPair indexPair) const -> Match<Int>
	{
		Int firstIdx = indexPair.first;
		Int lastIdx  = indexPair.second;

		for (; firstIdx != lastIdx; ++firstIdx)
		{
			if (pred(indexable[firstIdx]))
				return firstIdx;
		}

		return NO_MATCH;
	}

	PRED pred;
};

//----------------------------------------------------------------------------------------
/// A matcher that finds the first element equal to a value.
//----------------------------------------------------------------------------------------
template <typename T>
struct ValuePredicate
{
	ValuePredicate(const ValuePredicate&) = default;
	ValuePredicate& operator =(const ValuePredicate&) = default;

	explicit ValuePredicate(const T& valueIn) : value(valueIn) { }

	template <typename U>
	Bool operator ()(const U& other) const { return other == value; }

	const T& value;
};

//----------------------------------------------------------------------------------------
/// A matcher that finds the first element equal to a value based on a custom comparison function.
//----------------------------------------------------------------------------------------
template <typename T, typename COMPARE>
struct ValueComparePredicate
{
	ValueComparePredicate(const ValueComparePredicate&) = default;
	ValueComparePredicate& operator =(const ValueComparePredicate&) = default;

	ValueComparePredicate(const T& valueIn, const COMPARE& compIn) : value(valueIn), comp(compIn) { }

	template <typename U>
	Bool operator ()(const U& other) const { return comp(other, value); }

	const T& value;
	const COMPARE& comp;
};

//----------------------------------------------------------------------------------------
/// Returns a predicate matcher for the given predicate function.
//----------------------------------------------------------------------------------------
template <typename PRED>
inline auto ByPredicate(const PRED& pred) -> PredicateMatcher<std::reference_wrapper<const PRED>>
{
	return PredicateMatcher<std::reference_wrapper<const PRED>>(pred);
}

//----------------------------------------------------------------------------------------
/// Returns a value matcher for the given value.
//----------------------------------------------------------------------------------------
template <typename T>
inline auto ByValue(const T& value) -> PredicateMatcher<ValuePredicate<T>>
{
	using PredType = ValuePredicate<T>;
	return PredicateMatcher<PredType>(PredType(value));
}

//----------------------------------------------------------------------------------------
/// Returns a value matcher for the given value with a custom comparison function.
//----------------------------------------------------------------------------------------
template <typename T, typename COMPARE>
inline auto ByValue(const T& value, const COMPARE& comp) -> PredicateMatcher<ValueComparePredicate<T, COMPARE>>
{
	using PredType = ValueComparePredicate<T, COMPARE>;
	return PredicateMatcher<PredType>(PredType(value, comp));
}

//----------------------------------------------------------------------------------------
/// A matcher that finds the first sequence of continuous elements which satisfy a predicate.
//----------------------------------------------------------------------------------------
template <typename PRED>
struct RepeatingPredicateMatcher
{
	explicit RepeatingPredicateMatcher(const PRED& predIn) : pred(predIn) { }

	RepeatingPredicateMatcher(const RepeatingPredicateMatcher&) = default;

	RepeatingPredicateMatcher& operator =(const RepeatingPredicateMatcher&) = default;

	template <typename ITERATOR, typename SENTINEL>
	auto FindNext(ITERATOR first, SENTINEL sentinel) const -> Match<ITERATOR>
	{
		for (; !(first == sentinel); ++first)
		{
			if (!pred(*first))
				continue;

			ITERATOR	matchFirst = first++;
			Int				matchLength = 1;

			for (; !(first == sentinel); ++first, ++matchLength)
			{
				if (!pred(*first))
					break;
			}

			return Match<ITERATOR>(matchFirst, matchLength);
		}

		return NO_MATCH;
	}

	template <typename INDEXABLE>
	auto FindNextIndex(const INDEXABLE& indexable, IndexPair indexPair) const -> Match<Int>
	{
		Int firstIdx = indexPair.first;
		Int lastIdx  = indexPair.second;

		for (; firstIdx != lastIdx; ++firstIdx)
		{
			if (!pred(indexable[firstIdx]))
				continue;

			Int	matchFirstIdx = firstIdx++;
			Int	matchLength = 1;

			for (; firstIdx != lastIdx; ++firstIdx, ++matchLength)
			{
				if (!pred(indexable[firstIdx]))
					break;
			}

			return Match<Int>(matchFirstIdx, matchLength);
		}

		return NO_MATCH;
	}

	const PRED& pred;
};

//----------------------------------------------------------------------------------------
/// Returns a repeating predicate matcher for the given predicate function.
//----------------------------------------------------------------------------------------
template <typename PRED>
inline auto ByRepeatingPredicate(const PRED& pred) -> RepeatingPredicateMatcher<PRED>
{
	return RepeatingPredicateMatcher<PRED>(pred);
}

//----------------------------------------------------------------------------------------
/// Returns a repeating value matcher for the given value.
//----------------------------------------------------------------------------------------
template <typename T>
inline auto ByRepeatingValue(const T& value) -> RepeatingPredicateMatcher<ValuePredicate<T>>
{
	using PredType = ValuePredicate<T>;
	return RepeatingPredicateMatcher<PredType>(PredType(value));
}

//----------------------------------------------------------------------------------------
/// Returns a repeating value matcher for the given value with a custom comparison function.
//----------------------------------------------------------------------------------------
template <typename T, typename COMPARE>
inline auto ByRepeatingValue(const T& value, const COMPARE& comp) -> RepeatingPredicateMatcher<ValueComparePredicate<T, COMPARE>>
{
	using PredType = ValueComparePredicate<T, COMPARE>;
	return RepeatingPredicateMatcher<PredType>(PredType(value, comp));
}

//----------------------------------------------------------------------------------------
/// SequenceMatcher
//----------------------------------------------------------------------------------------
template <typename SEARCH_SEQ, typename COMPARE>
struct SequenceMatcher
{
	SequenceMatcher(const SEARCH_SEQ& searchSeqIn, const COMPARE& compIn) : searchSeq(searchSeqIn), comp(compIn) { }

	SequenceMatcher(const SequenceMatcher&) = default;

	SequenceMatcher& operator =(const SequenceMatcher&) = default;

	// Match iterable sequence
	template <typename ITERATOR, typename SENTINEL>
	auto FindNext(ITERATOR first, SENTINEL sentinel) const -> Match<ITERATOR>
	{
		auto searchFirst = begin(searchSeq);
		auto searchLast  = end(searchSeq);

		if (searchFirst == searchLast)
			return NO_MATCH;

		for (; ; ++first)
		{
			auto it = first;
			for (auto searchIt = searchFirst; ; ++it, ++searchIt)
			{
				if (MAXON_UNLIKELY(searchIt == searchLast))
					return Match<ITERATOR>(first, it - first);

				if (MAXON_UNLIKELY(it == sentinel))
					return NO_MATCH;

				if (!comp(*it, *searchIt))
					break;
			}
		}
	}

	// Match indexed portion of sequence
	template <typename INDEXABLE>
	auto FindNextIndex(const INDEXABLE& indexable, IndexPair indexPair) const -> Match<Int>  const
	{
		Int firstIdx = indexPair.first;
		Int lastIdx  = indexPair.second;

		auto searchFirst = begin(indexable);
		auto searchLast  = end(indexable);

		if (searchFirst == searchLast)
			return NO_MATCH;

		for (; ; ++firstIdx)
		{
			Int scanIdx = firstIdx;
			for (auto searchIt = searchFirst; ; ++scanIdx, ++searchIt)
			{
				if (MAXON_UNLIKELY(searchIt == searchLast))
					return Match<Int>(firstIdx, scanIdx - firstIdx);

				if (MAXON_UNLIKELY(scanIdx == lastIdx))
					return NO_MATCH;

				if (!comp(indexable[scanIdx], *searchIt))
					break;
			}
		}
	}

	const SEARCH_SEQ& searchSeq;
	const COMPARE& comp;
};

//----------------------------------------------------------------------------------------
/// Returns a sequence matcher for the given search sequence.
//----------------------------------------------------------------------------------------
template <typename SEARCH_SEQ>
inline auto BySequence(const SEARCH_SEQ& searchSeq) -> SequenceMatcher<SEARCH_SEQ,
	maxon::details::EqualityCompare<typename std::iterator_traits<decltype(begin(searchSeq))>::value_type, typename std::iterator_traits<decltype(begin(searchSeq))>::value_type>>
{
	using maxon::details::EqualityCompare;
	using T = typename std::iterator_traits<decltype(begin(searchSeq))>::value_type;
	return SequenceMatcher<SEARCH_SEQ, EqualityCompare<T, T>>(searchSeq, EqualityCompare<T, T>());
}

//----------------------------------------------------------------------------------------
/// Returns a sequence matcher for the given search sequence with a custom comparison function.
//----------------------------------------------------------------------------------------
template <typename SEARCH_SEQ, typename COMPARE>
inline auto BySequence(const SEARCH_SEQ& searchSeq, const COMPARE& comp) -> SequenceMatcher<SEARCH_SEQ, COMPARE>
{
	return SequenceMatcher<SEARCH_SEQ, COMPARE>(searchSeq, comp);
}

} // namespace maxon

#endif // ALGORITHMS_H__
