#ifndef POINTERARRAY_H__
#define POINTERARRAY_H__

#include "maxon/basearray.h"

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

//----------------------------------------------------------------------------------------
/// Array of pointers to objects.
/// The array consists of pointers to objects of type T (instead of storing the objects directly
/// like a BaseArray does). Internally each time you append or insert an element a new object
/// of type T is allocated, constructed and the corresponding index of the array will point to
/// it. Nonetheless this array has the same interface as a BaseArray except for AppendPtr(),
/// InsertPtr() and PopPtr() which allow you to directly add or remove already existing objects.
/// Like with all other arrays the destructor of the PointerArray will release memory for all
/// objects that are still part of the array. If you want to use the objects yourself after
/// they have been created by the PointerArray you have to take ownership of them by
/// calling PopPtr() or use a BaseArray<T*> instead of a PointerArray<T>.
///
/// Please note that in a C++11 range based for loop you may not call a non-const method
/// that modifies the range (e.g. Erase) - it does not work because the loop does not
/// expect the range to change. Use the Iterable::EraseIterator in that case.
///
/// Performance characteristics:
/// Random access to array elements is constant: O(1).
/// Append or Pop (erase the last) an element is amortized constant: O(1)
/// Insert or Erase an element is best case amortized constant (big elements) or in worst case linear (small elements): O(1) to O(n)
/// @note: Do not rely on the characteristics to pick the right type of collection. Always profile!
///
/// @tparam T											Type of the array elements.
/// @tparam MINCHUNKSIZE					The minimum number of elements upon array creation.
/// @tparam ALLOCATOR							Class for memory allocation.
///
/// @note Note that the array element class has special requirements regarding @link movecopy copy and move constructors @endlink.
/// @see @$ref arrays
//----------------------------------------------------------------------------------------
template <typename T, Int MINCHUNKSIZE = BASEARRAY_DEFAULT_CHUNK_SIZE, typename ALLOCATOR = DefaultAllocator> class PointerArray
	: public ArrayBase<PointerArray<T, MINCHUNKSIZE, ALLOCATOR>, T, EmptyClass, DefaultCompare>
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(PointerArray);

public:
	using Array = BaseArray<T*, MINCHUNKSIZE, BASEARRAYFLAGS::MOVEANDCOPYOBJECTS, ALLOCATOR>;
	using AllocatorType = ALLOCATOR;

	template <Bool CONSTITERATOR> class IteratorTemplate;
	using Iterator = IteratorTemplate<false>;
	using ConstIterator = IteratorTemplate<true>;

	//----------------------------------------------------------------------------------------
	/// Default constructor. Creates an empty arry.
	//----------------------------------------------------------------------------------------
	PointerArray()
	{
	}

	//----------------------------------------------------------------------------------------
	/// This constructor has to be used if an array should use a custom allocator with member variables.
	//----------------------------------------------------------------------------------------
	explicit PointerArray(const ALLOCATOR& a) : _ptr(a)
	{
	}

	//----------------------------------------------------------------------------------------
	/// Destructs the array with all its elements.
	//----------------------------------------------------------------------------------------
	~PointerArray()
	{
		Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Move constructor.
	//----------------------------------------------------------------------------------------
	PointerArray(PointerArray&& src) : _ptr(std::move(src._ptr))
	{
	}

	//----------------------------------------------------------------------------------------
	/// Move assignment operator.
	//----------------------------------------------------------------------------------------
	MAXON_OPERATOR_MOVE_ASSIGNMENT(PointerArray);

	//----------------------------------------------------------------------------------------
	/// Deletes all elements (calls destructors and frees memory).
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		for (Int i = GetCount() - 1; i >= 0; i--)
		{
			T*& element = _ptr[i];
			element->~T();
			Free(element);
		}

		_ptr.Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Deletes all elements, but doesn't free memory (calls destructors though).
	//----------------------------------------------------------------------------------------
	void Flush()
	{
		for (Int i = GetCount() - 1; i >= 0; i--)
		{
			T*& element = _ptr[i];
			element->~T();
			Free(element);
		}

		_ptr.Flush();
	}

	//----------------------------------------------------------------------------------------
	/// Gets the number of array elements.
	/// @return												Number of array elements.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Int GetCount() const
	{
		return _ptr.GetCount();
	}

	//----------------------------------------------------------------------------------------
	/// Gets the number of elements for which memory has been allocated (for a PointerArray this is equal to GetCount()).
	/// @return												Number of array elements for which memory has been allocated.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Int GetCapacityCount() const
	{
		return GetCount();
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for const objects.
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												Array element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE const T& operator [](Int idx) const
	{
		return *_ptr[idx];
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for non-const objects.
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												Array element.
	//----------------------------------------------------------------------------------------
	// this is duplicate code but casting constness away for this case is plain ugly
	MAXON_ATTRIBUTE_FORCE_INLINE T& operator [](Int idx)
	{
		return *_ptr[idx];
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the array.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<T> Append()
	{
		T* element = Alloc();
		if (element)
		{
			new (element) T();
			if (_ptr.Append(element) == FAILED)
			{
				// Appending the pointer failed: Destruct and free element.
				element->~T();
				Free(element);
			}
		}

		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the array and initializes it with a copy of x.
	/// @param[in] x									Value to be copied.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<T> Append(const T& x)
	{
		T* element = Alloc();
		if (element)
		{
			Result<void> res = NewCopy<T>(*element, x);
			if (res == FAILED || _ptr.Append(element) == FAILED)
			{
				// Appending the pointer failed: Destruct and free element.
				if (res == OK)
					element->~T();
				Free(element);
			}
		}

		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the array and moves the content of x to it.
	/// @param[in] x									Value to be moved.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<T> Append(T&& x)
	{
		T* element = Alloc();
		if (element)
		{
			new (element) T(std::move(x));
			if (MAXON_UNLIKELY(_ptr.Append(element) == FAILED))
			{
				// Appending the pointer failed: Move back, destruct and free element.
				x = std::move(*element);
				element->~T();
				Free(element);
			}
		}

		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Appends new elements at the end of the array.
	/// @param[in] values							Block with values to be copied.
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultPtr<T> Append(const Block<const T>& values)
	{
		return Insert(GetCount(), values);
	}

	//----------------------------------------------------------------------------------------
	/// Appends new elements at the end of the array.
	/// @param[in] values							Initializer list with values to be copied.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultPtr<T> Append(const std::initializer_list<T>& values)
	{
		return Insert(GetCount(), values);
	}

	//----------------------------------------------------------------------------------------
	/// PointerArray specific: Adds a pointer to the new element at the end of the array.
	/// @param[in] x									Pointer to new element (PointerArray will take ownership of it).
	/// @return												Element pointer or nullptr (in this case x is still valid).
	//----------------------------------------------------------------------------------------
	ResultPtr<T> AppendPtr(T* x)
	{
		return _ptr.Append(x).GetPointer() ? x : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new default element at index position.
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<T> Insert(Int position)
	{
		T*	element = Alloc();
		if (element)
		{
			new (element) T();
			if (_ptr.Insert(position, element) == FAILED)
			{
				// Appending the pointer failed: Destruct and free element.
				element->~T();
				Free(element);
			}
		}

		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new default element at iterator position.
	/// @param[in] position						Insert position.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultMemT<Iterator> Insert(Iterator position)
	{
		Int	idx = position - Begin();
		T*	element = Insert(idx).GetPointer();
		return element ? Iterator(*this, idx) : Iterator();
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at index position and initializes it with a copy of x.
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] x									Value to be copied.
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<T> Insert(Int position, const T& x)
	{
		T* element = Alloc();
		if (element)
		{
			Result<void> res = NewCopy<T>(*element, x);

			if (res == FAILED || _ptr.Insert(position, element) == FAILED)
			{
				// Inserting the pointer failed: Destruct and free element.
				if (res == OK)
					element->~T();
				Free(element);
			}
		}

		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at iterator position and initializes it with a copy of x.
	/// @param[in] position						Insert position.
	/// @param[in] x									Value to be copied.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultMemT<Iterator> Insert(Iterator position, const T& x)
	{
		Int	idx = position - Begin();
		T*	element = Insert(idx, x).GetPointer();
		return element ? Iterator(*this, idx) : Iterator();
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at index position and moves the content of x to it.
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] x									Value to be moved.
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<T> Insert(Int position, T&& x)
	{
		T*	element = Alloc();
		if (element)
		{
			new (element) T(std::move(x));
			if (_ptr.Insert(position, element) == FAILED)
			{
				// Inserting the pointer failed: Move back, destruct and free element.
				x = std::move(*element);
				element->~T();
				Free(element);
			}
		}

		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at iterator position and moves the content of x to it.
	/// @param[in] position						Insert position.
	/// @param[in] x									Value to be moved.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ResultMemT<Iterator> Insert(Iterator position, T&& x)
	{
		Int	idx = position - Begin();
		T*	element = Insert(idx, std::move(x)).GetPointer();
		return element ? Iterator(*this, idx) : Iterator();
	}

	//----------------------------------------------------------------------------------------
	/// PointerArray specific: Inserts a pointer to a new element at index position.
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] x									Pointer to new element (PointerArray will take ownership of it).
	/// @return												Element pointer or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultPtr<T> InsertPtr(Int position, T* x)
	{
		return _ptr.Insert(position, x) == OK ? x : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at index position (the pointers to all elements from @p position on are moved by the the count of @p values).
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] values							Block with values to be copied.
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultPtr<T> Insert(Int position, const Block<const T>& values)
	{
		T*	element = nullptr;
		Int insertCnt = values.GetCount();

		if (insertCnt > 0)
		{
			const T* x = values.GetFirst();
			T**	ptrs = AllocPointers(insertCnt);
			if (ptrs)
			{
				Int	idx;

				for (idx = 0; idx < insertCnt; idx++)
				{
					T* o = Alloc();
					if (o == nullptr)
						break;

					// Copy  element.
					if (x && NewCopy(*o, *x++) == FAILED)
					{
						Free(o);
						break;
					}
					ptrs[idx] = o;

					// Created copies of all objects?
					if (idx == insertCnt - 1)
					{
						// Break if inserting the pointers failed.
						if (_ptr.Insert(position, ToBlock(ptrs, insertCnt)) == FAILED)
							break;

						element = ptrs[0];
					}
				}

				// Destruct partitially created elements if insertion failed.
				if (idx < insertCnt)
				{
					for (; idx >= 0; idx--)
					{
						ptrs[idx]->~T();
						Free(ptrs[idx]);
					}
				}
				Free(ptrs);
			}
		}
		else
		{
			// Return a dummy pointer if the array is empty.
			element = GetCount() > 0 ? _ptr[position] : (T*) this;
		}
		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at index position (all elements from @p position on are moved by the the count of @p values).
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] values							Initializer list with values to be copied.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultPtr<T> Insert(Int position, const std::initializer_list<T>& values)
	{
		const T* first = values.begin();
		const T* last = values.end();
		Int cnt = last - first;
		return Insert(position, Block<const T>(first, cnt));
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at iterator position (all elements from @p position on are moved by the the count of @p values).
	/// @param[in] position						Insert position.
	/// @param[in] values							Block with values to be copied.
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(Iterator position, const Block<const T>& values)
	{
		Int idx = position - Begin();
		T* element = Insert(idx, values).GetPointer();
		return element ? Iterator(*this, idx) : Iterator();
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at iterator position (all elements from @p position on are moved by the the count of @p values).
	/// @param[in] position						Insert position.
	/// @param[in] values							Initializer list with values to be copied.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(Iterator position, const std::initializer_list<T>& values)
	{
		return Iterator(Insert(position - Begin(), values).UncheckedGetValue());
	}

	//----------------------------------------------------------------------------------------
	/// Erases (removes and deletes) elements.
	/// @param[in] position						Erase index (Erase() will fail if out of bounds and return nullptr).
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) a nullptr will be returned.
	/// @return												Pointer to the element that is now at position. If position equals the number of elements after Erase() a valid pointer is returned but you are not allowed to access it. OutOfMemoryError is only returned on failure (position was out of bounds).
	//----------------------------------------------------------------------------------------
	ResultPtr<T> Erase(Int position, Int eraseCnt = 1)
	{
		Int	cnt = GetCount();
		Int availableCnt = cnt - position;

		if (MAXON_UNLIKELY(UInt(position) > UInt(cnt)))
		{
			DebugStop("The position is invalid.");
			return nullptr;
		}

		if (MAXON_UNLIKELY(UInt(availableCnt) < UInt(eraseCnt)))
		{
			DebugStop("You are trying to erase more elements than available.");
			return nullptr;
		}

		// Destruct elements.
		for (Int idx = position + eraseCnt - 1; idx >= position; idx--)
		{
			T*& element = _ptr[idx];
			element->~T();
			Free(element);
		}

		// Erase pointers.
		T** p = _ptr.Erase(position, eraseCnt).GetPointer();

		// Return a dummy pointer if position is now the array end.
		return position < GetCount() ? *p : (T*) this;
	}

	//----------------------------------------------------------------------------------------
	/// Erases (removes and deletes) elements.
	/// @param[in] position						Erase position.
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) an invalid iterator will be returned.
	/// @return												Iterator for the element that is now at position (its operator Bool() will return false if something failed).
	//----------------------------------------------------------------------------------------
	Iterator Erase(Iterator position, Int eraseCnt = 1)
	{
		Int	idx = position - Begin();
		T*	element = Erase(idx, eraseCnt).GetPointer();

		// Return an invalid iterator if Erase() failed.
		if (element == nullptr)
			return Iterator();

		return Iterator(*this, idx);
	}

	//----------------------------------------------------------------------------------------
	/// Extracts a single element from the list and returns its pointer.
	/// The caller takes ownership of the element.
	/// @param[in] position						Erase index (Erase() will fail if out of bounds and return nullptr).
	/// @param[in,out] dst						Used to return pointer to the erased element (must not be null).
	/// @return												Pointer to the element that is now at position. If position equals the that of the element after Erase(), a valid pointer is returned but you are not allowed to access it. A nullptr is only returned on failure (position was out of bounds).
	//----------------------------------------------------------------------------------------
	ResultPtr<T> ErasePtr(Int position, T** dst)
	{
		Int	cnt = GetCount();

		if (MAXON_UNLIKELY(UInt(position) > UInt(cnt)))
		{
			DebugStop("The position is invalid.");
			return nullptr;
		}

		if (MAXON_UNLIKELY(dst == nullptr))
		{
			DebugStop("The return pointer is invalid.");
			return nullptr;
		}

		// Get the element.
		*dst = _ptr[position];

		// Erase pointers.
		T** p = _ptr.Erase(position, 1).GetPointer();

		// Return a dummy pointer if position is now the array end.
		return position < GetCount() ? *p : (T*) this;
	}

	//----------------------------------------------------------------------------------------
	/// Erases elements within the array and moves elements from the end to the erased gap.
	/// This is generally faster than Erase() because at most eraseCnt elements have to be moved,
	/// but it changes the order of elements.
	/// @param[in] position						Erase index (SwapErase() will fail if out of bounds and return nullptr).
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) false will be returned.
	/// @return												False if position was out of bounds.
	//----------------------------------------------------------------------------------------
	ResultMem SwapErase(Int position, Int eraseCnt = 1)
	{
		Int	cnt = GetCount();
		Int availableCnt = cnt - position;
		Int endIdx = position + eraseCnt;
		Int newCnt = cnt - eraseCnt;

		if (MAXON_UNLIKELY(UInt(position) > UInt(cnt)))
		{
			DebugStop("The position is invalid.");
			return FAILED;
		}

		if (MAXON_UNLIKELY(UInt(availableCnt) < UInt(eraseCnt)))
		{
			DebugStop("You are trying to erase more elements than available.");
			return FAILED;
		}

		// Destruct elements.
		for (Int idx = position + eraseCnt - 1; idx >= position; idx--)
		{
			T*& element = _ptr[idx];
			element->~T();
			Free(element);
		}

		// Copy up to eraseCnt pointers from the end into the gap.
		for (Int moveIdx = Max<Int>(newCnt, endIdx); moveIdx < cnt; moveIdx++, position++)
			_ptr[position] = _ptr[moveIdx];

		// Shrink the pointer array.
		_ptr.Erase(newCnt, eraseCnt) iferr_cannot_fail("Erase failed - someone must have broken the array code.");

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Erases elements within the array and moves elements from the end to the erased gap.
	/// This is generally faster than Erase() because at most eraseCnt elements have to be moved,
	/// but it changes the order of elements.
	/// @param[in] position						Erase position.
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) an invalid iterator will be returned.
	/// @return												Iterator for the element that is now at position (its operator Bool() will return false if something failed).
	//----------------------------------------------------------------------------------------
	Iterator SwapErase(Iterator position, Int eraseCnt = 1)
	{
		if (SwapErase(position - Begin(), eraseCnt) == FAILED)
			return Iterator();

		return position;
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p index.
	/// For a BaseArray, this yields the whole array as a block.
	/// @param[in] position						Element index.
	/// @param[out] block							Block which contains the element at @p index.
	/// @return												Start index of the block. The requested element can be found within the block at @p index - start index.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> MAXON_ATTRIBUTE_FORCE_INLINE Int GetBlock(Int position, Block<T, STRIDED>& block)
	{
		Int cnt = _ptr.GetCount();

		if (UInt(position) >= UInt(cnt))
			block.Set(nullptr, 0, SIZEOF(T));
		else
			block.Set(_ptr[position], 1, SIZEOF(T));

		return position;
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p position.
	/// For a BaseArray, this yields the whole array as a block.
	/// @param[in] position						Element index.
	/// @param[out] block							Block which contains the element at @p position.
	/// @return												Start index of the block. The requested element can be found within the block at @p position - start index.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> MAXON_ATTRIBUTE_FORCE_INLINE Int GetBlock(Int position, Block<const T, STRIDED>& block) const
	{
		return const_cast<PointerArray*>(this)->GetBlock(position, *(Block<T, STRIDED>*) &block);
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p position.
	/// For a BaseArray, this yields the whole array as a block.
	/// @param[in] position						Element position.
	/// @param[out] block							Block which contains the element at @p position.
	/// @return												Start iterator of the block. The requested element can be found within the block at index @p position - start iterator.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> MAXON_ATTRIBUTE_FORCE_INLINE Iterator GetBlock(Iterator position, Block<T, STRIDED>& block)
	{
		GetBlock(position - Begin(), block);
		return position;
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p position.
	/// For a BaseArray, this yields the whole array as a block.
	/// @param[in] position						Element position.
	/// @param[out] block							Block which contains the element at @p index.
	/// @return												Start iterator of the block. The requested element can be found within the block at index @p position - start iterator.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> MAXON_ATTRIBUTE_FORCE_INLINE Iterator GetBlock(Iterator position, Block<const T, STRIDED>& block) const
	{
		return const_cast<PointerArray*>(this)->GetBlock(position, *(Block<T, STRIDED>*) &block);
	}

	//----------------------------------------------------------------------------------------
	/// Returns the first element of the array.
	/// @note The PointerArray uses a separate memory blocks for each element. You must not and
	/// cannot use the pointer returned by GetFirst() to access the array elements like a continous block.
	/// @return												Pointer to the first element (nullptr if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE const T* GetFirst() const
	{
		return (GetCount() > 0) ? _ptr[0] : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the first element of the array.
	/// @note The PointerArray uses a separate memory blocks for each element. You must not and
	/// cannot use the pointer returned by GetFirst() to access the array elements like a continous block.
	/// @return												Pointer to the first element (nullptr if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE T* GetFirst()
	{
		return (GetCount() > 0) ? _ptr[0] : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the last element of the array.
	/// @return												Pointer to the last element (nullptr if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE const T* GetLast() const
	{
		Int last = GetCount() - 1;
		return (last >= 0) ? _ptr[last] : nullptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the last element of the array.
	/// @return												Pointer to the last element (nullptr if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE T* GetLast()
	{
		Int last = GetCount() - 1;
		return (last >= 0) ? _ptr[last] : nullptr;
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
		// Preallocate memory for the pointer table.
		return _ptr.EnsureCapacity(requestedCapacity, resizeFlags);
	}

	//----------------------------------------------------------------------------------------
	/// Resizes the array to contain newCnt elements.
	/// If newCnt is smaller than GetCount() all extra elements are being deleted. If it is
	/// greater the array is expanded and the default constructor is called for new elements.
	/// @param[in] newCnt							New array size.
	/// @param[in] resizeFlags				See COLLECTION_RESIZE_FLAGS (flags other than ON_GROW_UNINITIALIZED/POD_UNINITIALIZED result in default behaviour).
	/// @return												False if allocation failed.
	//----------------------------------------------------------------------------------------
	ResultMem Resize(Int newCnt, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::DEFAULT)
	{
		Int	i;
		Int	cnt = GetCount();
		Int	increment = newCnt - cnt;

		if (increment <= 0)
		{
			// Decrease array size.
			if (newCnt >= 0)
			{
				for (i = newCnt; i < cnt; i++)
				{
					T*& element = _ptr[i];
					element->~T();
					Free(element);
				}

				_ptr.Resize(newCnt) iferr_ignore("Resize is allowed to fail here.");
			}
			else
			{
				DebugStop("Invalid array size specified.");
				return FAILED;
			}
		}
		else
		{
			// Increase array size.
			if (_ptr.Resize(newCnt) == FAILED)
				return FAILED;

			if ((resizeFlags & COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) == COLLECTION_RESIZE_FLAGS::NONE)
			{
				// Insert pointers to initialized elements (default case).
				for (i = cnt; i < newCnt; i++)
				{
					T* element = _ptr[i] = Alloc();
					if (element == nullptr)
						break;
					new (element) T();
				}
			}
			else
			{
				// Insert pointers to uninitialized elements.
				for (i = cnt; i < newCnt; i++)
				{
					_ptr[i] = Alloc();
					if (_ptr[i] == nullptr)
						break;
				}
			}

			if (i < newCnt)
			{
				// Object allocation failed.
				for (; i >= cnt; i--)
				{
					T*& element = _ptr[i];
					element->~T();
					Free(element);
				}

				_ptr.Resize(cnt) iferr_ignore("Resize is allowed to fail here.");

				return FAILED;
			}
		}

		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Deletes the last element.
	/// @param[out] dst								Nullptr or pointer to return value.
	/// @return												True if there was at least one element.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Bool Pop(T* dst = nullptr)
	{
		Int	i = GetCount() - 1;
		if (i >= 0)
		{
			T* element = _ptr[i];
			if (dst)
				*dst = std::move(*element);													// call move operator if available

			element->~T();
			Free(element);
			_ptr.Pop();
			return true;
		}
		return false;
	}

	//----------------------------------------------------------------------------------------
	/// PointerArray specific: Removes the last element and returns the pointer.
	/// @param[out] dst								Used to return pointer to the last element (must not be null), the caller will take ownership of the element.
	/// @return												True if successful.
	//----------------------------------------------------------------------------------------
	Bool PopPtr(T** dst)
	{
		Int	i = GetCount() - 1;
		if (i >= 0)
		{
			*dst = _ptr[i];
			_ptr.Pop();
			return true;
		}
		*dst = nullptr;
		return false;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the index of the element. The element must be part of the array, otherwise (e.g.
	/// if x is a copy of an array element) InvalidArrayIndex will be returned.
	/// This is quite slow because GetIndex() has to iterate over the array.
	/// @return												Index of element or InvalidArrayIndex (not element of this).
	//----------------------------------------------------------------------------------------
	Int GetIndex(const T& x) const
	{
		for (Int i = 0; i < GetCount(); i++)
		{
			if (_ptr[i] == &x)
				return i;
		}

		return InvalidArrayIndex;
	}

	//----------------------------------------------------------------------------------------
	/// Specialization of AppendAllImpl, used by BaseCollection::AppendAll.
	/// @private
	//----------------------------------------------------------------------------------------
	template <typename COLLECTION2> Result<void> AppendAllImpl(COLLECTION2&& other, COLLECTION_RESIZE_FLAGS resizeFlags, Bool overwrite, OverloadRank0)
	{
		if (maxon::IsCollection<COLLECTION2>::value)
		{
			Int oc = maxon::GetCount(other);
			DebugAssert(oc >= 0);
			Int cnt = GetCount();
			if (_ptr.Resize(cnt + oc, resizeFlags) == FAILED)
				return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
			for (const auto& i : std::forward<COLLECTION2>(other))
			{
				T* x = Alloc();
				if (x == nullptr)
				{
					_ptr.Resize(cnt) iferr_ignore("Resize is allowed to fail here.");

					return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
				}
				Result<void> res = NewCopy<T>(*x, i);
				if (res == FAILED)
				{
					Free(x);
					_ptr.Resize(cnt) iferr_ignore("Resize is allowed to fail here.");
					return res;
				}
				_ptr[cnt++] = x;
				DebugAssert(--oc >= 0);
			}
		}
		else
		{
			for (const auto& i : std::forward<COLLECTION2>(other))
			{
				if (Append(i) == FAILED)
					return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
			}
		}
		return OK;
	}

	//----------------------------------------------------------------------------------------
	/// Swaps elements a and b (just the pointers are swapped, this is more efficient than global Swap(array[a], array[b]).
	/// @param[in] a									Position of element to be swapped.
	/// @param[in] b									Position of element to be swapped.
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE void Swap(Iterator a, Iterator b)
	{
		maxon::Swap(a.GetPtr(), b.GetPtr());
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the memory usage for this array.
	/// The array element class must have a public member GetMemorySize that returns an element's size.
	/// @return												Memory size in bytes.
	//----------------------------------------------------------------------------------------
	Int GetMemorySize() const
	{
		Int memUsage = 0;
		for (Int i = 0; i < _ptr.GetCount(); i++)
			memUsage += maxon::GetMemorySizeHelper(*_ptr[i]);

		return memUsage + SIZEOF(*this) + GetCapacityCount() * SIZEOF(T*);
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the first element.
	/// When you modify the array Begin() will change, it is not a constant value.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ConstIterator Begin() const
	{
		return ConstIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the first element.
	/// When you modify the array Begin() will change, it is not a constant value.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Iterator Begin()
	{
		return Iterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the end (End() - 1 is the last element if the array is not empty).
	/// When you modify the array End() will change, it is not a constant value.
	/// @return												Iterator for the array end (points behind the last element).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE ConstIterator End() const
	{
		return ConstIterator(*this, GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the end (End() - 1 is the last element if the array is not empty).
	/// When you modify the array End() will change, it is not a constant value.
	/// @return												Iterator for the array end (points behind the last element).
	//----------------------------------------------------------------------------------------
	MAXON_ATTRIBUTE_FORCE_INLINE Iterator End()
	{
		return Iterator(*this, GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// The PointerArray iterator can be used to iterate over an array or parts of it. For more
	/// ease of use you may want to invoke this via the C++11 range based for loop.
	///
	/// You can use an iterator almost like a pointer, e.g.
	/// @code
	/// it++;								// go to the next element
	/// it--;								// go to the previous element
	/// it += 5;						// advance by 5 elements
	/// it -= 3;						// go back 3 elements
	/// cnt = itB - itA;		// number of elements from itA to itB
	/// it = array.Begin();	// iterator to the first element of the array
	/// *it = value;				// assign value to the elements referenced by the iterator
	/// value = *value;			// get value of the element referenced by the iterator
	/// @endcode
	//----------------------------------------------------------------------------------------
	template <Bool CONSTITERATOR> class IteratorTemplate
	{
	public:
		// For a const iterator, both the PointerArray and its values have to be const within the iterator, otherwise they are non-const.
		// These type aliases have to be used throughout the iterator code instead of just PointerArray or T.
		using CollectionType = typename ConstIf<PointerArray, CONSTITERATOR>::type;
		using Type = typename ConstIf<T, CONSTITERATOR>::type;
		static const Bool isLinearIterator = false;

		// Use a dummy pointer if the array is empty.
		explicit IteratorTemplate(CollectionType& a, Int start = 0) : _data(a.GetCount() ? static_cast<Type* const*>(&a._ptr[0]) + start : (Type* const*) &a)
		{
		}
		explicit IteratorTemplate(Type* const* pos = nullptr) : _data(pos)
		{
		}

		IteratorTemplate(const IteratorTemplate& src) : _data(src._data)
		{
		}
		IteratorTemplate& operator =(const IteratorTemplate& src)
		{
			_data = src._data;																		// self assignment is no problem here, therefore no check if (this != &src)
			return *this;
		}

#ifdef MAXON_COMPILER_INTEL
	#pragma warning disable 597
#endif
		operator ConstIterator&()
		{
			return *(ConstIterator*) this;
		}
#ifdef MAXON_COMPILER_INTEL
	#pragma warning enable 597
#endif

		//----------------------------------------------------------------------------------------
		/// @return												true if the iterator points to an element.
		//----------------------------------------------------------------------------------------
		explicit operator Bool() const
		{
			return Bool(_data != nullptr);
		}

		Type* GetPtr() const
		{
			return *_data;
		}

		Type& operator *() const
		{
			return **_data;
		}

		Type* operator ->() const
		{
			return *_data;
		}

		Bool operator ==(const IteratorTemplate& b) const
		{
			return _data == b._data;
		}

		Bool operator <(const IteratorTemplate& b) const
		{
			return _data < b._data;
		}

		MAXON_OPERATOR_COMPARISON(IteratorTemplate);

		// prefix operator ++ (increment and fetch)
		IteratorTemplate& operator ++()
		{
			_data++;
			return *this;
		}

		// postfix operator ++ (fetch and increment)
		const IteratorTemplate operator ++(int)
		{
			Type* const* tmp = _data;
			_data++;

			// use RVO
			return IteratorTemplate(tmp);
		}

		// operator +=
		IteratorTemplate& operator +=(Int i)
		{
			_data += i;
			return *this;
		}

		// prefix operator -- (decrement and fetch)
		IteratorTemplate& operator --()
		{
			_data--;
			return *this;
		}

		// postfix operator -- (fetch and decrement)
		const IteratorTemplate operator --(int)
		{
			Type* const* tmp = _data;
			_data--;

			// use RVO
			return IteratorTemplate(tmp);
		}

		// operator -=
		IteratorTemplate& operator -=(Int i)
		{
			_data -= i;
			return *this;
		}

		// operator +
		IteratorTemplate operator +(Int i) const
		{
			// use RVO
			return IteratorTemplate(_data + i);
		}

		// operator -
		IteratorTemplate operator -(Int i) const
		{
			// use RVO
			return IteratorTemplate(_data - i);
		}

		Int operator -(const IteratorTemplate& b) const
		{
			return _data - b._data;
		}

	private:
		Type* const* _data;
	};


	//----------------------------------------------------------------------------------------
	/// Disconnects the array's memory buffer and returns it as a block.
	/// Afterwards the array is in the same state as directly after its construction.
	/// @return												The buffer consisting of pointers to elements of type T.
	/// @note The memory needs to be freed with the allocator that the array is using.
	//----------------------------------------------------------------------------------------
	Block<T*> Disconnect()
	{
		return _ptr.Disconnect();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the allocator as reference. Typically this is used by the arrays and other
	/// base classes when multiple of them are "stiched" together as one big object all
	/// shall use one main allocator.
	/// @return												Allocator reference.
	//----------------------------------------------------------------------------------------
	ALLOCATOR& GetAllocator()
	{
		return _ptr.GetAllocator();
	}

	//----------------------------------------------------------------------------------------
	/// Returns the underlying array which stores the pointers to the elements.
	/// @return												Array with pointers.
	//----------------------------------------------------------------------------------------
	Array& GetUnderlyingArray()
	{
		return _ptr;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the underlying array which stores the pointers to the elements.
	/// @return												Array with pointers.
	//----------------------------------------------------------------------------------------
	const Array& GetUnderlyingArray() const
	{
		return _ptr;
	}

private:
	T*	Alloc()
	{
		return (T*) _ptr.GetAllocator().Alloc(SIZEOF(T), MAXON_SOURCE_LOCATION_NAME(T));
	}

	T**	AllocPointers(Int cnt)
	{
		return (T**) _ptr.GetAllocator().Alloc(cnt * SIZEOF(T*), MAXON_SOURCE_LOCATION_NAME(T*));
	}

	template <typename X> void	Free(X*& p)
	{
		_ptr.GetAllocator().Free(p);
		DebugAssert(p == nullptr, "Allocator must null the pointer.");
	}

	Array _ptr;
};

/// @}

} // namespace maxon

#endif // POINTERARRAY_H__
