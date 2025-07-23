#ifndef FIXEDSIZEARRAY_H__
#define FIXEDSIZEARRAY_H__

#include "maxon/block.h"

namespace maxon
{

template <typename T, Int N> class FixedSizeArray
{
public:
	using ValueType = T;

	//----------------------------------------------------------------------------------------
	/// Returns a Block<const T> which represents the elements of the array.
	/// @return												The content of this array as a block.
	//----------------------------------------------------------------------------------------
	Block<const T> ToBlock() const
	{
		return {_elements, N};
	}

	//----------------------------------------------------------------------------------------
	/// Returns a Block<T> which represents the elements of the array.
	/// @return												The content of this array as a block.
	//----------------------------------------------------------------------------------------
	Block<T> ToBlock()
	{
		return {_elements, N};
	}

	//----------------------------------------------------------------------------------------
	/// Converts this FixedSizeArray to a Block<const T> which represents the elements of the array.
	/// @return												The content of this array as a block.
	//----------------------------------------------------------------------------------------
	operator Block<const T>() const
	{
		return {_elements, N};
	}

	//----------------------------------------------------------------------------------------
	/// Converts this FixedSizeArray to a Block<T> which represents the elements of the array.
	/// @return												The content of this array as a block.
	//----------------------------------------------------------------------------------------
	operator Block<T>()
	{
		return {_elements, N};
	}

	//----------------------------------------------------------------------------------------
	/// Converts this FixedSizeArray to a StridedBlock<const T> which represents the elements of the array.
	/// The block will have the natural stride of T.
	/// @return												The content of this array as a strided block.
	//----------------------------------------------------------------------------------------
	operator StridedBlock<const T>() const
	{
		return StridedBlock<const T>(_elements, N, SIZEOF(T));
	}

	//----------------------------------------------------------------------------------------
	/// Converts this FixedSizeArray to a StridedBlock<T> which represents the elements of the array.
	/// The block will have the natural stride of T.
	/// @return												The content of this array as a strided block.
	//----------------------------------------------------------------------------------------
	operator StridedBlock<T>()
	{
		return StridedBlock<T>(_elements, N, SIZEOF(T));
	}

	const T& operator [](Int index) const
	{
		return _elements[index];
	}

	T& operator [](Int index)
	{
		return _elements[index];
	}

	Int GetCount() const
	{
		return N;
	}

	using Iterator = BaseIterator<FixedSizeArray, false>;
	using ConstIterator = BaseIterator<const FixedSizeArray, false>;

	MAXON_ATTRIBUTE_FORCE_INLINE ConstIterator Begin() const
	{
		return ConstIterator(_elements);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Iterator Begin()
	{
		return Iterator(_elements);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE ConstIterator End() const
	{
		return ConstIterator(_elements + N);
	}

	MAXON_ATTRIBUTE_FORCE_INLINE Iterator End()
	{
		return Iterator(_elements + N);
	}

private:
	T _elements[N];
};

}

#endif // FIXEDSIZEARRAY_H__
