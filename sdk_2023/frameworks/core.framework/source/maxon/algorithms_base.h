#ifndef ALGORITHMS_PLAIN_H__
#define ALGORITHMS_PLAIN_H__

#include "maxon/apibase.h"


namespace maxon
{

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
		maxon::Swap(*first, *last);

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

} // namespace maxon

#endif // ALGORITHMS_PLAIN_H__
