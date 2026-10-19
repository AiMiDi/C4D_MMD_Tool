#ifndef FIXEDSIZEARRAY_H__
#define FIXEDSIZEARRAY_H__

#include "maxon/block.h"

namespace maxon
{

template <typename T> class Opt;

template <typename T, Int N> class FixedSizeArray : public ArrayBase<FixedSizeArray<T, N>, T, EmptyClass, DefaultCompare>
{
public:
	using ValueType = T;

	static constexpr Bool COPYABLE = std::is_copy_constructible_v<T>;

	FixedSizeArray() = default;

	MAXON_IMPLICIT FixedSizeArray(const std::initializer_list<T>& list)
	{
		if (list.size() == N)
		{
			auto s = list.begin();
			for (T& e : _elements)
			{
				e = *s;
				++s;
			}
		}
		else
		{
			DebugStop("Initializer list doesn't match element count.");
		}
	}

	MAXON_DECLARE_CONDITIONAL_COPY_CONSTRUCTOR(FixedSizeArray, COPYABLE)
	{
		this->operator =(src);
	}

	MAXON_DECLARE_CONDITIONAL_COPY_ASSIGNMENT(FixedSizeArray, COPYABLE)
	{
		auto s = src.Begin();
		for (T& e : _elements)
		{
			e = *s;
			++s;
		}
		return *this;
	}

	Result<void> CopyFrom(const typename std::conditional<COPYABLE, DummyParamType, FixedSizeArray>::type& src)
	{
		iferr_scope;
		auto s = src.Begin();
		for (T& e : _elements)
		{
			AssignCopy(e, *s) iferr_return;
			++s;
		}
		return OK;
	}

	FixedSizeArray& operator =(typename std::conditional<COPYABLE, const T[N], DummyParamType>::type& src)
	{
		const T* s = src;
		for (T& e : _elements)
		{
			e = *s;
			++s;
		}
		return *this;
	}

	Result<void> CopyFrom(typename std::conditional<COPYABLE, DummyParamType, const T[N]>::type& src)
	{
		iferr_scope;
		const T* s = src;
		for (T& e : _elements)
		{
			AssignCopy(e, *s) iferr_return;
			++s;
		}
		return OK;
	}

	FixedSizeArray(FixedSizeArray&& src)
	{
		this->operator =(std::move(src));
	}

	FixedSizeArray& operator =(FixedSizeArray&& src)
	{
		auto s = src.Begin();
		for (T& e : _elements)
		{
			e = std::move(*s);
			++s;
		}
		return *this;
	}

	static FixedSizeArray& Cast(T (&src)[N])
	{
		return reinterpret_cast<FixedSizeArray&>(src);
	}

	static const FixedSizeArray& Cast(const T (&src)[N])
	{
		return reinterpret_cast<const FixedSizeArray&>(src);
	}

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

	using Array = T[N];

	Array& GetUnderlyingArray()
	{
		return _elements;
	}

	using ConstArray = const T[N];

	ConstArray& GetUnderlyingArray() const
	{
		return _elements;
	}

	UniqueHash GetUniqueHashCode() const
	{
		return ToBlock().GetUniqueHashCode();
	}

private:
	T _elements[N];
};

template <Int COUNT> class FixedSizeArraySelector
{
public:
	template <typename T> using Type = FixedSizeArray<T, COUNT>;
};

template <typename K, typename V, Bool SORTED, typename COMPARE, typename ARRAY> class ArrayMap;

/// Finds a value in an array of Pair<K,V>
template <std::size_t SIZE, typename ENTRY, typename K> maxon::Opt<const typename ENTRY::ValueType&> FindValueInUnorderedMap(const ENTRY (&array)[SIZE], const K& key)
{
	return reinterpret_cast<const maxon::ArrayMap<typename ENTRY::KeyType, typename ENTRY::ValueType, false, maxon::DefaultCompare, maxon::FixedSizeArraySelector<SIZE>>&>(array).FindValue(key);
}

}

#endif // FIXEDSIZEARRAY_H__
