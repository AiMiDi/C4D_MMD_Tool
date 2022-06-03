#ifndef FLEXIBLE_ARRAY_H__
#define FLEXIBLE_ARRAY_H__

#include "maxon/apibase.h"

namespace maxon
{

#ifdef MAXON_COMPILER_MSVC
	MAXON_WARNING_PUSH

	#pragma warning(disable:4582)
	#pragma warning(disable:4583)
#endif

//----------------------------------------------------------------------------------------
/// FlexibleArray can be used instead of e.g. BaseArray when you don't need dynamic reallocation
/// but make sure in advance to provide enough memory. The class itself uses no allocation, the memory
/// for the count and all elements is within the class itself. This leads to better performance
/// due to improved cache locality.
///
/// There are two typical use cases:
/// - You can add a FlexibleArray as the last member of a class which is dynamically allocated.
///   Then when you allocate memory for an object of that class, you have to make sure
///		that the allocation adds enough memory at the end to hold all array elements.
///		The GetSize function helps to compute the required memory size.
///	- You can allocate and construct a stand-alone FlexibleArray with the Create functions.
/// @tparam T											Type of the array elements.
/// @tparam COUNT									The class to use for the count member. Int by default.
//----------------------------------------------------------------------------------------
template <typename T, typename COUNT = Int> struct FlexibleArray
{
	/// The element type.
	using ValueType = T;

	//----------------------------------------------------------------------------------------
	/// Constructs a FlexibleArray with cnt elements. All elements will be default-initialized.
	/// The storage memory used for the constructor call needs to be large enough to hold those elements.
	/// @param[in] cnt								Number of elements.
	//----------------------------------------------------------------------------------------
	explicit FlexibleArray(Int cnt) : _count(cnt)
	{
		T* m = _elements;
		while (--cnt >= 0)
			new (m++) T();
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a FlexibleArray with a copy of src. All elements will be copied from src.
	/// The storage memory used for the constructor call needs to be large enough to hold those elements.
	/// @param[in] src								A block of elements to copy.
	//----------------------------------------------------------------------------------------
	explicit FlexibleArray(const Block<const T>& src) : _count(src.GetCount())
	{
		Int cnt = _count;
		T* m = _elements;
		const T* s = src.GetFirst();
		while (--cnt >= 0)
			new (m++) T(*(s++));
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a FlexibleArray from src. All elements will be moved from src.
	/// The storage memory used for the constructor call needs to be large enough to hold those elements.
	/// @param[in] src								A block of elements to move.
	//----------------------------------------------------------------------------------------
	explicit FlexibleArray(const MoveBlock<T>& src) : _count(src.GetCount())
	{
		Int cnt = _count;
		T* m = _elements;
		T* s = src.GetFirst();
		while (--cnt >= 0)
			new (m++) T(std::move(*(s++)));
	}

	//----------------------------------------------------------------------------------------
	/// Constructs a FlexibleArray with cnt elements, but without any initialization of the elements.
	/// The storage memory used for the constructor call needs to be large enough to hold those elements.
	/// @param[in] cnt								Number of elements.
	//----------------------------------------------------------------------------------------
	FlexibleArray(Int cnt, ENUM_DONT_INITIALIZE) : _count(cnt)
	{
	}

	~FlexibleArray()
	{
		for (T& m : ToBlock())
		{
			m.~T();
		}
	}

	MAXON_DISALLOW_COPY_AND_ASSIGN(FlexibleArray);

	//----------------------------------------------------------------------------------------
	/// Returns a Block<const T> which represents the elements of the array.
	/// @return												The content of this array as a block.
	//----------------------------------------------------------------------------------------
	Block<const T> ToBlock() const
	{
		return maxon::ToBlock(_elements, _count);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a Block<T> which represents the elements of the array.
	/// @return												The content of this array as a block.
	//----------------------------------------------------------------------------------------
	Block<T> ToBlock()
	{
		return maxon::ToBlock(_elements, _count);
	}

	//----------------------------------------------------------------------------------------
	/// Converts this FlexibleArray to a Block<const T> which represents the elements of the array.
	/// @return												The content of this array as a block.
	//----------------------------------------------------------------------------------------
	operator Block<const T>() const
	{
		return maxon::ToBlock(_elements, _count);
	}

	//----------------------------------------------------------------------------------------
	/// Converts this FlexibleArray to a Block<T> which represents the elements of the array.
	/// @return												The content of this array as a block.
	//----------------------------------------------------------------------------------------
	operator Block<T>()
	{
		return maxon::ToBlock(_elements, _count);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a sub block of this array with contains the elements from the given @p start index up to but not including the given @p end index.
	/// @param[in] start							Start index of the sub block.
	/// @param[in] end								End index of the sub block. The end index is exclusive.
	/// @return												Sub block with elements from @p start up to @p end.
	//----------------------------------------------------------------------------------------
	Block<const T> Slice(Int start, Int end) const
	{
		return maxon::ToBlock(_elements + start, end - start);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a sub block of this array with contains the elements from the given @p start index up to but not including the given @p end index.
	/// @param[in] start							Start index of the sub block.
	/// @param[in] end								End index of the sub block. The end index is exclusive.
	/// @return												Sub block with elements from @p start up to @p end.
	//----------------------------------------------------------------------------------------
	Block<T> Slice(Int start, Int end)
	{
		return maxon::ToBlock(_elements + start, end - start);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a sub block of this array with contains the elements from the given @p start index up to the end of the block.
	/// @param[in] start							Start index of the sub block.
	/// @return												Sub block starting at @p start.
	//----------------------------------------------------------------------------------------
	Block<const T> Slice(Int start) const
	{
		return maxon::ToBlock(_elements + start, _count - start);
	}

	//----------------------------------------------------------------------------------------
	/// Returns a sub block of this array with contains the elements from the given @p start index up to the end of the block.
	/// @param[in] start							Start index of the sub block.
	/// @return												Sub block starting at @p start.
	//----------------------------------------------------------------------------------------
	Block<T> Slice(Int start)
	{
		return maxon::ToBlock(_elements + start, _count - start);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the number of array elements.
	/// @return												Number of array elements.
	//----------------------------------------------------------------------------------------
	Int GetCount() const
	{
		return _count;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the array is empty. This is the same as @c{GetCount() == 0}.
	/// @return												True if the array does not contain any elements.
	//----------------------------------------------------------------------------------------
	Bool IsEmpty() const
	{
		return _count == 0;
	}

	//----------------------------------------------------------------------------------------
	/// Checks if the array is populated. This is the same as @c{GetCount() != 0}.
	/// @return												True if the array contains any elements.
	//----------------------------------------------------------------------------------------
	Bool IsPopulated() const
	{
		return _count != 0;
	}

	//----------------------------------------------------------------------------------------
	/// Shrinks this array by cnt elements. These are removed (and destructed) from the end.
	/// @param[in] cnt								Number of elements to remove.
	//----------------------------------------------------------------------------------------
	void Shrink(Int cnt)
	{
		DebugAssert(UInt(cnt) <= UInt(_count));
		for (Int i = cnt; i < _count; ++i)
		{
			_elements[i].~T();
		}
		_count = cnt;
	}

	//----------------------------------------------------------------------------------------
	/// Erases the element at index. Elements behind index are moved by one.
	/// @param[in] index							Index of the element to remove.
	//----------------------------------------------------------------------------------------
	void Erase(Int index)
	{
		DebugAssert(UInt(index) < UInt(_count));
		for (Int i = index + 1; i < _count; ++i)
		{
			_elements[i - 1] = std::move(_elements[i]);
		}
		_elements[--_count].~T();
	}

	//----------------------------------------------------------------------------------------
	/// Computes the required size for an allocation of class C when C has FlexibleArray as last member and
	/// cnt element shall be held in the array.
	/// @tparam C											Class with a FlexibleArray as last member.
	/// @param[in] cnt								Number of elements to be held in the FlexibleArray.
	//----------------------------------------------------------------------------------------
	template <typename C = FlexibleArray> static Int GetSize(Int cnt)
	{
		return SIZEOF(C) + cnt * SIZEOF(T);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a FlexibleArray of the given size in dynamic memory.
	/// The elements are default-initialized.
	/// @param[in] cnt								Number of elements to be held in the FlexibleArray.
	/// @return												A newly allocated array of the given size. The caller owns the array.
	//----------------------------------------------------------------------------------------
	static ResultPtr<FlexibleArray> Create(Int cnt)
	{
		return MAXON_SAFE_PLACEMENT_NEW(DefaultAllocator::Alloc(GetSize(cnt), MAXON_SOURCE_LOCATION)) FlexibleArray(cnt);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a FlexibleArray of the given size in dynamic memory.
	/// The elements are default-initialized.
	/// @param[in] cnt								Initial number of elements in the FlexibleArray.
	/// @param[in] capacity						Maximum number of elements to be held in the FlexibleArray.
	/// @return												A newly allocated array of the given size. The caller owns the array.
	//----------------------------------------------------------------------------------------
	static ResultPtr<FlexibleArray> Create(Int cnt, Int capacity)
	{
		DebugAssert(capacity >= cnt);
		return MAXON_SAFE_PLACEMENT_NEW(DefaultAllocator::Alloc(GetSize(capacity), MAXON_SOURCE_LOCATION)) FlexibleArray(cnt);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a FlexibleArray of the given content in dynamic memory.
	/// All elements are copied from the values block.
	/// @param[in] values							A block of initial values for the elements of the FlexibleArray.
	/// @return												A newly allocated array with the given content. The caller owns the array.
	//----------------------------------------------------------------------------------------
	static ResultPtr<FlexibleArray> Create(const Block<const T>& values)
	{
		return MAXON_SAFE_PLACEMENT_NEW(DefaultAllocator::Alloc(GetSize(values.GetCount()), MAXON_SOURCE_LOCATION)) FlexibleArray(values);
	}

	//----------------------------------------------------------------------------------------
	/// Creates a FlexibleArray of the given content in dynamic memory.
	/// All elements are moved from the values block.
	/// @param[in] values							A block of initial values for the elements of the FlexibleArray.
	/// @return												A newly allocated array with the given content. The caller owns the array.
	//----------------------------------------------------------------------------------------
	static ResultPtr<FlexibleArray> Create(const MoveBlock<T>& values)
	{
		return MAXON_SAFE_PLACEMENT_NEW(DefaultAllocator::Alloc(GetSize(values.GetCount()), MAXON_SOURCE_LOCATION)) FlexibleArray(values);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the element at the given @p index of this array.
	/// @param[in] index							Index into the array.
	/// @return												Reference to the value at @p index.
	//----------------------------------------------------------------------------------------
	T& operator [](Int index)
	{
		DebugAssert(UInt(index) < UInt(_count));
		return _elements[index];
	}

	/// @copydoc operator[]
	const T& operator [](Int index) const
	{
		DebugAssert(UInt(index) < UInt(_count));
		return _elements[index];
	}

	//----------------------------------------------------------------------------------------
	/// Returns the first element of this array. Even for an empty array this will return a non-null pointer.
	/// @return												Pointer to the first element of this array.
	//----------------------------------------------------------------------------------------
	const T* GetFirst() const
	{
		return _elements;
	}

	/// @copydoc GetFirst
	T* GetFirst()
	{
		return _elements;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the last element of this array. For an empty array this will return nullptr.
	/// @return												Pointer to the last element of this array, or nullptr for an empty array.
	//----------------------------------------------------------------------------------------
	const T* GetLast() const
	{
		return (_count != 0) ? &_elements[_count-1] : nullptr;
	}

	/// @copydoc GetLast
	T* GetLast()
	{
		return (_count != 0) ? &_elements[_count-1] : nullptr;
	}

	using Iterator = BaseIterator<FlexibleArray, false>;
	using ConstIterator = BaseIterator<const FlexibleArray, false>;

	Iterator Begin()
	{
		return Iterator(_elements);
	}

	Iterator End()
	{
		return Iterator(_elements + _count);
	}

	ConstIterator Begin() const
	{
		return ConstIterator(&_elements[0]);
	}

	ConstIterator End() const
	{
		return ConstIterator(_elements + _count);
	}

	/// @copydoc DefaultDoc::operator==
	Bool operator ==(const FlexibleArray& other) const
	{
		return this == &other || ToBlock() == other.ToBlock();
	}

	/// @copydoc DefaultDoc::operator!=
	Bool operator !=(const FlexibleArray& other) const
	{
		return !this->operator ==(other);
	}

	/// @copydoc DefaultDoc::GetHashCode
	HashInt GetHashCode() const
	{
		return ToBlock().GetHashCode();
	}

	/// @copydoc DefaultDoc::ToString
	String ToString(const FormatStatement* fs = nullptr) const
	{
		return ToBlock().ToString(fs);
	}

	static const FlexibleArray& NullValue()
	{
		return reinterpret_cast<const FlexibleArray&>(maxon::NullValue<const COUNT&>());
	}

	const COUNT& PrivateGetCount() const
	{
		return _count;
	}

	COUNT& PrivateGetCount()
	{
		return _count;
	}

private:
	COUNT _count;
#if defined(MAXON_COMPILER_CLANG) ||  defined(MAXON_COMPILER_GCC)
	T _elements[0];
#else
	T _elements[];
#endif
};

#ifdef MAXON_COMPILER_MSVC
	MAXON_WARNING_POP
#endif

// specializations needed because the default implementation of HasXReference uses a class derived from T which isn't possible due to the flexible array member
template <typename T, typename COUNT> struct StrongRefHandler::HasAddReference<FlexibleArray<T, COUNT>> : public std::false_type
{
};

template <typename T, typename COUNT> struct StrongRefHandler::HasRemoveReference<FlexibleArray<T, COUNT>> : public std::false_type
{
};

template <typename T, typename COUNT> struct StrongCOWRefHandler::MakeWritableHelper<FlexibleArray<T, COUNT>>
{
	template <typename R> static MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<FlexibleArray<T, COUNT>> MakeWritable(R& ref, Bool resetOnError)
	{
		FlexibleArray<T, COUNT>* o = const_cast<FlexibleArray<T, COUNT>*>(ref.GetPointer());
		if (MAXON_UNLIKELY(o == nullptr))
		{
			// do nothing
		}
		else if (MAXON_UNLIKELY(GetReferenceCounter(o).HasMultipleReferences()))
		{
			o = FlexibleArray<T, COUNT>::Create(o->ToBlock()).GetPointer();
		}
		else
		{
			return o;
		}
		if (MAXON_LIKELY(resetOnError || o))
			ref.PrivateSetTarget(ResultPtr<const FlexibleArray<T, COUNT>>(o));
		DebugAssert(!o || (GetReferenceCounter(o) == 1));
		return o;
	}
};

}

#endif // FLEXIBLE_ARRAY_H__
