#ifndef INDEXITERATOR_H__
#define INDEXITERATOR_H__

#include "maxon/foreach.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

class IndexIteratorDefaultAccess
{
public:
	template <typename ARRAY> static auto Get(ARRAY& array, Int index) -> decltype(array[index]) { return array[index]; };
};

template <typename T, typename ARRAY, typename ACCESS = IndexIteratorDefaultAccess> class IndexIterator : public ForEachIterator<IndexIterator<T, ARRAY, ACCESS>>
{
public:
	IndexIterator(ARRAY& array, Int start, Int end) : _array(&array), _index(start), _end(end) { }

	IndexIterator(const IndexIterator& src) : _array(src._array), _index(src._index), _end(src._end) { }
	MAXON_OPERATOR_COPY_ASSIGNMENT(IndexIterator);

	void operator ++()
	{
		++_index;
	}

	explicit operator Bool() const
	{
		return Bool(_index < _end);
	}

	T operator *() const
	{
		return ACCESS::Get(*_array, _index);
	}

	typename std::remove_reference<T>::type* operator ->() const
	{
		static_assert(std::is_reference<T>::value, "Can't use -> where T it not a reference type.");
		return &ACCESS::Get(*_array, _index);
	}

	Bool operator ==(const IndexIterator& other) const
	{
		return _index == other._index;
	}

	Bool operator !=(const IndexIterator& other) const
	{
		return _index != other._index;
	}

private:
	ARRAY* _array;
	Int _index;
	Int _end;
};

/// @}

} // namespace maxon

#endif // INDEXITERATOR_H__
