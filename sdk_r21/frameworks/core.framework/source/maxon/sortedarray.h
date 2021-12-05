#ifndef SORTEDARRAY_H__
#define SORTEDARRAY_H__

#include "maxon/parallelsort.h"
#include "maxon/collection.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

//----------------------------------------------------------------------------------------
/// Sorted array.
/// The class can be combined with any standard array type. Sorting is done on first read access,
/// e.g. if you access the array by using the index operator.
/// Note that sorted arrays will be extremely slow if read and write access is constantly alternating,
/// as for every write access a sort needs to be done, which needs O(log n) time. In those cases
/// other datastructures will be better suited.
/// Please also take into consideration that sorted arrays are not thread-safe, even for read-access
/// unless you call Sort() once before multiple threads start reading the data (if the array was in a
/// non-sorted state the first read-access will sort it otherwise, which will obviously cause problems)
///
/// If the data type to be sorted is unknown to DefaultCompare you should inherit from SortedArray and
/// define a LessThan() and an IsEqual() method for comparison of elements. For example:
/// @code
/// class MySortedArray : public SortedArray<MySortedArray, BaseArray<MyType>>
/// {
/// public:
/// 	static Bool LessThan(const MyType& a, const MyType& b) { return a < b; }
///		static Bool IsEqual(const MyType& a, const MyType& b) { return a == b; }
/// };
/// MySortedArray a;
/// a.Append(x) iferr_return;
/// a.Append(y) iferr_return;
/// @endcode
///
/// @note Note that the classes that will be sorted have special requirements regarding @link movecopy copy and move constructors @endlink.
/// @note Note that the comparison must fulfill the condition (a < b) == !(b < a). If this is not the case the sort algorithm will crash.
///       To avoid mistakes when comparing tuples use LexicographicalCompare.
///
/// @tparam MYSELF								The class itself.
/// @tparam ARRAY									The used array, e.g. BaseArray, BlockArray or PointerArray.
/// @tparam FLAGS									See BASESORTFLAGS, normally can be left at default.
/// @tparam PARALLEL							Use parallel sorting, for details see parallelsort.h.
///
/// @note Note that the array element class has special requirements regarding @link movecopy copy and move constructors @endlink.
//----------------------------------------------------------------------------------------
template <typename MYSELF, typename ARRAY, BASESORTFLAGS FLAGS = BASESORTFLAGS::NONE, Bool PARALLEL = false> class SortedArray
	: public ArrayBase<SortedArray<MYSELF, ARRAY, FLAGS, PARALLEL>, typename ARRAY::ValueType, EmptyClass, MYSELF>
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(SortedArray);

public:
	using TYPE = typename ARRAY::ValueType;

	/// The SortedArray iterator is just a type alias for the underlying array's iterator.
	/// This means that using the iterator to access array elements will not sort the
	/// array or mark it as being modified.
	using Iterator = typename ARRAY::Iterator;
	using ConstIterator = typename ARRAY::ConstIterator;

	//----------------------------------------------------------------------------------------
	/// Default constructor. Creates an empty arry.
	//----------------------------------------------------------------------------------------
	SortedArray()
	{
		_sorted = true;
	}

	//----------------------------------------------------------------------------------------
	/// This constructor has to be used if an array should use a custom allocator with member variables.
	//----------------------------------------------------------------------------------------
	explicit SortedArray(const typename ARRAY::AllocatorType& a) : _array(a)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Destructs the array with all its elements.
	//----------------------------------------------------------------------------------------
	~SortedArray()
	{
	}

	//----------------------------------------------------------------------------------------
	/// Move constructor.
	//----------------------------------------------------------------------------------------
	SortedArray(SortedArray&& src) : MAXON_MOVE_MEMBERS(_array, _sorted)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Move assignment operator.
	//----------------------------------------------------------------------------------------
	MAXON_OPERATOR_MOVE_ASSIGNMENT(SortedArray);

	//----------------------------------------------------------------------------------------
	/// Deletes all elements (calls destructors and frees memory).
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		_sorted = true;
		_array.Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Deletes all elements, but doesn't free memory (calls destructors though).
	//----------------------------------------------------------------------------------------
	void Flush()
	{
		_sorted = true;
		_array.Flush();
	}

	//----------------------------------------------------------------------------------------
	/// Prepares the internal buffer(s) to hold at least the given number of elements with
	/// as few further memory allocations as possible.
	/// @note This is just a hint. It does not guarantee that the collection will be able
	/// to store the number of indicated elements.
	/// @param[in] requestedCapacity	The desired internal capacity.
	/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
	/// @return												False if allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY)
	{
		return _array.SetCapacityHint(requestedCapacity, resizeFlags);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the number of array elements.
	/// @return												Number of array elements.
	//----------------------------------------------------------------------------------------
	Int GetCount() const
	{
		return _array.GetCount();
	}

	//----------------------------------------------------------------------------------------
	/// Gets the number of elements for which memory has been allocated (this is usually bigger
	/// than GetCount()).
	/// @return												Number of array elements for which memory has been allocated.
	//----------------------------------------------------------------------------------------
	Int GetCapacityCount() const
	{
		return _array.GetCapacityCount();
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for const objects.
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												Array element.
	//----------------------------------------------------------------------------------------
	const TYPE& operator [](Int idx) const
	{
		CheckSort();
		return _array[idx];
	}

	// the following operator must not be defined as it can't work on sorted arrays
	// TYPE& operator [](Int idx)

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the array.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultRef<TYPE> Append()
	{
		SortChanged();
		return _array.Append();
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the array and initializes it with a copy of x.
	/// @param[in] x									Value to be copied.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultRef<TYPE> Append(const TYPE& x)
	{
		SortChanged();
		return _array.Append(x);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the array and moves the content of x to it.
	/// @param[in] x									Value to be moved.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultRef<TYPE> Append(TYPE&& x)
	{
		SortChanged();
		return _array.Append(std::move(x));
	}

	//----------------------------------------------------------------------------------------
	/// PointerArray specific: Adds a pointer to the new element at the end of the array.
	/// @param[in] x									Pointer to new element (SortedArray will take ownership of it).
	/// @return												Element pointer or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultPtr<TYPE> AppendPtr(TYPE* x)
	{
		SortChanged();
		return _array.AppendPtr(x);
	}

	//----------------------------------------------------------------------------------------
	/// PointerArray specific: Removes the last element and returns the pointer.
	/// @param[out] dst								Used to return pointer to the last element (must not be null), the caller will take ownership of the element.
	/// @return												True if successful.
	//----------------------------------------------------------------------------------------
	Bool PopPtr(TYPE** dst)
	{
		return _array.PopPtr(dst);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new default element at index position.
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultRef<TYPE> Insert(Int position)
	{
		SortChanged();
		return _array.Insert(position);
	}

	//----------------------------------------------------------------------------------------
	/// PointerArray specific: Inserts a pointer to a new element at index position.
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] x									Pointer to new element (SortedArray will take ownership of it).
	/// @return												Element pointer or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultPtr<TYPE> InsertPtr(Int position, TYPE* x)
	{
		SortChanged();
		return _array.InsertPtr(position, x);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new default element at iterator position.
	/// @param[in] position						Insert position.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(Iterator position)
	{
		SortChanged();
		return _array.Insert(position);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at index position and initializes it with a copy of x.
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] x									Value to be copied.
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultRef<TYPE> Insert(Int position, const TYPE& x)
	{
		SortChanged();
		return _array.Insert(position, x);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at iterator position and initializes it with a copy of x.
	/// @param[in] position						Insert position.
	/// @param[in] x									Value to be copied.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(Iterator position, const TYPE& x)
	{
		SortChanged();
		return _array.Insert(position, x);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at index position and moves the content of x to it.
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] x									Value to be moved.
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultRef<TYPE> Insert(Int position, TYPE&& x)
	{
		SortChanged();
		return _array.Insert(position, std::move(x));
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at iterator position and moves the content of x to it.
	/// @param[in] position						Insert position.
	/// @param[in] x									Value to be moved.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(Iterator position, TYPE&& x)
	{
		SortChanged();
		return _array.Insert(position, std::move(x));
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at index position (all elements from position on are moved by the the count of @p values).
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] values							Block with values to be copied.
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultPtr<TYPE> Insert(Int position, const Block<const TYPE>& values)
	{
		SortChanged();
		return _array.Insert(position, values);
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at iterator position (all elements from position on are moved by the the count of @p values).
	/// @param[in] position						Insert position.
	/// @param[in] values							Block with values to be copied.
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(Iterator position, const Block<const TYPE>& values)
	{
		SortChanged();
		return _array.Insert(position, values);
	}

	//----------------------------------------------------------------------------------------
	/// Erases (removes and deletes) elements.
	/// @param[in] position						Erase index (Erase() will fail if out of bounds and return nullptr).
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) a nullptr will be returned.
	/// @return												Pointer to the element that is now at position. If position equals the number of elements after Erase() a valid pointer is returned but you are not allowed to access it. OutOfMemoryError is only returned on failure (position was out of bounds).
	//----------------------------------------------------------------------------------------
	ResultPtr<TYPE> Erase(Int position, Int eraseCnt = 1)
	{
		return _array.Erase(position, eraseCnt);
	}

	//----------------------------------------------------------------------------------------
	/// PointerArray specific: Extracts a single element from the list and returns its pointer.
	/// The caller takes ownership of the element.
	/// @param[in] position						Erase index (Erase() will fail if out of bounds and return nullptr).
	/// @param[in,out] dst						Used to return pointer to the erased element (must not be null).
	/// @return												Pointer to the element that is now at position. If position equals the that of the element after Erase(), a valid pointer is returned but you are not allowed to access it. A nullptr is only returned on failure (position was out of bounds).
	//----------------------------------------------------------------------------------------
	ResultPtr<TYPE> ErasePtr(Int position, TYPE** dst)
	{
		return _array.ErasePtr(position, dst);
	}

	//----------------------------------------------------------------------------------------
	/// Erases elements within the array. For sorted arrays this is identical to the Erase function.
	/// @param[in] position						Erase position.
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) false will be returned.
	/// @return												False if position was out of bounds.
	//----------------------------------------------------------------------------------------
	ResultMem SwapErase(Int position, Int eraseCnt = 1)
	{
		// Call Erase() instead of SwapErase() to keep the array sorted.
		return ResultMem(Erase(position, eraseCnt) == OK);
	}

	//----------------------------------------------------------------------------------------
	/// Erases elements within the array. For sorted arrays this is identical to the Erase function.
	/// @param[in] position						Erase position.
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) an invalid iterator will be returned.
	/// @return												Iterator for the element that is now at position (its operator Bool() will return false if something failed).
	//----------------------------------------------------------------------------------------
	Iterator SwapErase(Iterator position, Int eraseCnt = 1)
	{
		// Call Erase() instead of SwapErase() to keep the array sorted.
		return _array.Erase(position, eraseCnt).UncheckedGetValue();
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p index.
	/// For a BaseArray, this yields the whole array as a block.
	/// @param[in] position						Element index.
	/// @param[out] block							Block which contains the element at @p index.
	/// @return												Start index of the block. The requested element can be found within the block at @p index - start index.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> Int GetBlock(Int position, Block<TYPE, STRIDED>& block)
	{
		return _array.GetBlock(position, block);
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p position.
	/// For a BaseArray, this yields the whole array as a block.
	/// @param[in] position						Element index.
	/// @param[out] block							Block which contains the element at @p position.
	/// @return												Start index of the block. The requested element can be found within the block at @p position - start index.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> Int GetBlock(Int position, Block<const TYPE, STRIDED>& block) const
	{
		return _array.GetBlock(position, block);
	}

	//----------------------------------------------------------------------------------------
	/// Erases (removes and deletes) elements.
	/// @param[in] position						Erase position.
	/// @param[in] eraseCnt						Number of elements to be erased (if eraseCnt is higher than what is available at position Erase() will succeed, but remove only the number of available elements).
	/// @return												Iterator for the element that is now at position (its operator Bool() will return false if something failed).
	//----------------------------------------------------------------------------------------
	Iterator Erase(Iterator position, Int eraseCnt = 1)
	{
		return _array.Erase(position, eraseCnt);
	}

	//----------------------------------------------------------------------------------------
	/// Erases (remove and delete) an element.
	/// @param[in] key								The key that the array is searched for.
	/// @return												True if key was found.
	//----------------------------------------------------------------------------------------
	template <typename SEARCH> Bool EraseKey(const SEARCH& key)
	{
		Int i = FindIndex(key);
		if (i < 0)
			return false;
		_array.Erase(i) iferr_cannot_fail("Erase cannot fail because the index is valid.");
		return true;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the first element of the array.
	/// @return												Pointer to the first element (nullptr if the array is empty).
	//----------------------------------------------------------------------------------------
	const TYPE* GetFirst() const
	{
		CheckSort();
		return _array.GetFirst();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the first element of the array.
	/// @return												Pointer to the first element (nullptr if the array is empty).
	//----------------------------------------------------------------------------------------
	TYPE* GetFirst()
	{
		CheckSort();
		return _array.GetFirst();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the last element of the array.
	/// @return												Pointer to the last element (nullptr if the array is empty).
	//----------------------------------------------------------------------------------------
	const TYPE* GetLast() const
	{
		CheckSort();
		return _array.GetLast();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the last element of the array.
	/// @return												Pointer to the last element (nullptr if the array is empty).
	//----------------------------------------------------------------------------------------
	TYPE* GetLast()
	{
		CheckSort();
		return _array.GetLast();
	}

	//----------------------------------------------------------------------------------------
	/// Resizes the array to contain newCnt elements (BaseArray specific).
	/// If newCnt is smaller than GetCount() all extra elements are being deleted. If it is
	/// greater the array is expanded and the default constructor is called for new elements.
	/// @param[in] newCnt							New array size.
	/// @param[in] resizeFlags				See COLLECTION_RESIZE_FLAGS (support depends on the inherited array).
	/// @return												False if allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem Resize(Int newCnt, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::DEFAULT)
	{
		if (newCnt > _array.GetCount())
		{
			SortChanged();
		}
		return _array.Resize(newCnt, resizeFlags);
	}

	//----------------------------------------------------------------------------------------
	/// Deletes the last element.
	/// @param[out] dst								Nullptr or pointer to return value.
	/// @return												True if there was at least one element.
	//----------------------------------------------------------------------------------------
	Bool Pop(TYPE* dst = nullptr)
	{
		return _array.Pop(dst);
	}

	//----------------------------------------------------------------------------------------
	/// Gets the index of the element. The element must be part of the array, otherwise (e.g.
	/// if x is a copy of an array element) InvalidArrayIndex will be returned.
	/// @return												Index of element or InvalidArrayIndex (not element of this).
	//----------------------------------------------------------------------------------------
	Int GetIndex(const TYPE& x) const
	{
		CheckSort();
		return _array.GetIndex(x);
	}

	//----------------------------------------------------------------------------------------
	/// Copies an array.
	/// @param[in] src								Source array.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	Result<void> CopyFrom(const SortedArray& src)
	{
		_sorted = src._sorted;
		return _array.CopyFrom(src._array);
	}

	/// @copydoc BaseCollection::CopyFrom
	template <typename COLLECTION2, typename = typename std::enable_if<!std::is_same<typename std::decay<COLLECTION2>::type, SortedArray>::value>::type> Result<void> CopyFrom(COLLECTION2&& other)
	{
		_sorted = false;
		return _array.CopyFrom(other);
	}

	//----------------------------------------------------------------------------------------
	/// Swaps elements a and b (equivalent to global Swap(array[a], array[b]).
	/// @param[in] a									Position of element to be swapped.
	/// @param[in] b									Position of element to be swapped.
	//----------------------------------------------------------------------------------------
	void Swap(Iterator a, Iterator b)
	{
		SortChanged();
		_array.Swap(a, b);
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the memory usage for this array.
	/// The array element class must have a public member GetMemorySize that returns an element's size.
	/// @return												Memory size in bytes.
	//----------------------------------------------------------------------------------------
	Int GetMemorySize() const
	{
		return SIZEOF(*this) - SIZEOF(_array) + maxon::GetMemorySizeHelper(_array);
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the first element.
	/// When you modify the array Begin() will change, it is not a constant value.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	ConstIterator Begin() const
	{
		CheckSort();
		return _array.Begin();
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the first element.
	/// When you modify the array Begin() will change, it is not a constant value.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	Iterator Begin()
	{
		CheckSort();
		return _array.Begin();
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the end (End() - 1 is the last element if the array is not empty).
	/// When you modify the array End() will change, it is not a constant value.
	/// @return												Iterator for the array end (this is behind the last element).
	//----------------------------------------------------------------------------------------
	ConstIterator End() const
	{
		CheckSort();
		return _array.End();
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the end (End() - 1 is the last element if the array is not empty).
	/// When you modify the array End() will change, it is not a constant value.
	/// @return												Iterator for the array end (this is behind the last element).
	//----------------------------------------------------------------------------------------
	Iterator End()
	{
		CheckSort();
		return _array.End();
	}

	//----------------------------------------------------------------------------------------
	/// Marks the array as non-sorted.
	/// Sorting will happen upon the next read access.
	//----------------------------------------------------------------------------------------
	void SortChanged()
	{
		_sorted = false;
	}

	//----------------------------------------------------------------------------------------
	/// Manually sorts the array.
	//----------------------------------------------------------------------------------------
	void Sort()
	{
		CheckSort();
	}

	//----------------------------------------------------------------------------------------
	/// Finds an element in an array.
	/// The time for searching will be O(log(n)).
	///
	/// @param[in] key								The key that the array is searched for.
	/// @return												If an element is found a pointer to it will be returned, otherwise the result is nullptr. If multiple elements have the same key value the first of those elements will be returned.
	//----------------------------------------------------------------------------------------
	template <typename SEARCH> TYPE* FindValue(const SEARCH& key)
	{
		CheckSort();
		SimpleSort<MYSELF, FLAGS> sort;
		return sort.Find(key, _array);
	}

	//----------------------------------------------------------------------------------------
	/// Finds an element in an array.
	/// The time for searching will be O(log(n)).
	///
	/// @param[in] key								The key that the array is searched for.
	/// @return												If an element is found a pointer to it will be returned, otherwise the result is nullptr. If multiple elements have the same key value the first of those elements will be returned.
	//----------------------------------------------------------------------------------------
	template <typename SEARCH> const TYPE* FindValue(const SEARCH& key) const
	{
		return const_cast<SortedArray*>(this)->FindValue<SEARCH>(key);
	}

	//----------------------------------------------------------------------------------------
	/// Finds the index of an element in an array.
	/// The time for searching will be O(log(n)).
	///
	/// @param[in] key								The key that the array is searched for.
	/// @return												If an element is found its index will be returned, otherwise the result is the bitwise inverse of the index where key would be inserted (which is always negative). If multiple elements have the same key value the index of the first of those elements will be returned.
	//----------------------------------------------------------------------------------------
	template <typename SEARCH> Int FindIndex(const SEARCH& key) const
	{
		CheckSort();
		SimpleSort<MYSELF, FLAGS> sort;
		return sort.FindIndex(key, _array.Begin(), _array.GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Finds an element in an array or insert it if it was not found.
	/// The time for this operation will be O(log(n)) for searching plus O(n) for inserting.
	/// Keep in mind that the resulting pointer will only be valid right after the operation as any additional array operation might shuffle array indices.
	/// To use this routine the SortedArray class must define the following member: @code static void	InitInsertData(T& initme, const SEARCH& key); @endcode
	///
	/// @param[in] key								The key that the array is searched for.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	template <typename SEARCH> ResultRef<TYPE> InsertValue(const SEARCH& key)
	{
		CheckSort();
		SimpleSort<MYSELF, FLAGS> sort;
		Int insertIdx = NOTOK;
		TYPE* e = sort.FindInsertionIndex(key, _array, insertIdx);
		if (!e)
		{
			e = _array.Insert(insertIdx).GetPointer();
			if (e)
				MYSELF::InitInsertData(*e, key);
		}
		return e;
	}

	//----------------------------------------------------------------------------------------
	/// Finds an element in an array or insert it if it was not found.
	/// The time for this operation will be O(log(n)) for searching plus O(n) for inserting.
	/// Keep in mind that the resulting pointer will only be valid right after the operation as any additional array operation might shuffle array indices.
	/// The value should be filled right after the function returns. InitInsertData is not being called.
	///
	/// @param[in] key								The key that the array is searched for.
	/// @param[out] newElement				Specifies if the element was newly inserted (true) or if it was found in the array (false)
	/// @param[out] index							The index of the found or inserted element. May be nullptr.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	template <typename SEARCH> ResultRef<TYPE> InsertValue(const SEARCH& key, Bool& newElement, Int* index = nullptr)
	{
		CheckSort();
		SimpleSort<MYSELF, FLAGS> sort;
		Int insertIdx = NOTOK;
		TYPE* e = sort.FindInsertionIndex(key, _array, insertIdx);
		if (index)
			*index = insertIdx;
		if (!e)
		{
			e = _array.Insert(insertIdx).GetPointer();
			newElement = true;
		}
		else
		{
			newElement = false;
		}
		return e;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the underlying array.
	/// @return												Underlying array.
	//----------------------------------------------------------------------------------------
	ARRAY& GetUnderlyingArray()
	{
		return _array;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the underlying array.
	/// @return												Underlying array.
	//----------------------------------------------------------------------------------------
	const ARRAY& GetUnderlyingArray() const
	{
		return _array;
	}

private:
	mutable ARRAY	_array;
	mutable Bool	_sorted;

	MAXON_ATTRIBUTE_NO_INLINE void DoSort() const;

	void CheckSort() const
	{
		if (!_sorted)
		{
			DoSort();
		}
	}
};

template <typename MYSELF, typename ARRAY, BASESORTFLAGS FLAGS, Bool PARALLEL> MAXON_ATTRIBUTE_NO_INLINE void SortedArray<MYSELF, ARRAY, FLAGS, PARALLEL>::DoSort() const
{
	if (PARALLEL)
	{
		SimpleParallelSort<MYSELF, FLAGS> sort;
		sort.Sort(_array);
	}
	else
	{
		SimpleSort<MYSELF, FLAGS> sort;
		sort.Sort(_array);
	}
	_sorted = true;
}


//----------------------------------------------------------------------------------------
/// Sorted array template for data types which provide an operator < and operator ==.
///
/// Usage is simply
/// @code
/// DefaultSortedArray<Int> a;
/// a.Append(2) iferr_return;
/// a.Append(1) iferr_return;
/// if (a[0] > a[1]) ...
/// @endcode
///
/// @tparam T											Type of the array elements.
//----------------------------------------------------------------------------------------
template <typename T> class DefaultSortedArray : public SortedArray<DefaultSortedArray<T>, BaseArray<T>>
{
public:
	DefaultSortedArray() { }
	DefaultSortedArray(DefaultSortedArray&& src) : SortedArray<DefaultSortedArray<T>, BaseArray<T>>(std::move(src)) { }
	MAXON_OPERATOR_MOVE_ASSIGNMENT(DefaultSortedArray);

	static Bool LessThan(const T& a, const T& b) { return a < b; }
	static Bool IsEqual(const T& a, const T& b) { return a == b; }
	template <typename SEARCH> static void InitInsertData(T& initme, const SEARCH& key) { initme = key; }
};

/// @}

} // namespace maxon

#endif // SORTEDARRAY_H__
