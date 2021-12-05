#ifndef BLOCKARRAY_H__
#define BLOCKARRAY_H__

#include "maxon/basearray.h"

/// @file

namespace maxon
{

/// @addtogroup STRUCTURES
/// @{

/// Flags for the behaviour of BlockArray when moving objects (only relevant for Insert() and Erase()).
enum class BLOCKARRAYFLAGS
{
	NONE								= 0,				///< Use constructor/destructor or move operator unless the type is trivially copyable using memcpy, memmove or realloc.
	MOVEANDCOPYOBJECTS	= (1 << 0),	///< Elements are PODs and can be copied using memcpy and moved using memmove/realloc (for Resize, Insert, Erase, Append etc.). Overrides the setting of std::is_trivially_copyable<T>.
	NOINSERTERASE				= (1 << 1),	///< Do not support Insert() and Erase() (will make the subscript operator faster).
	GROW_SLOWLY					= (1 << 2)	///< The first block will increase its size gradually (and might move memory) until it reaches 1 << BLOCK_SIZE_EXPONENT.
} MAXON_ENUM_FLAGS(BLOCKARRAYFLAGS);

static const Int BLOCKARRAY_DEFAULT_SIZE_EXPONENT = 10;

//----------------------------------------------------------------------------------------
/// Block array template.
/// The array consists of multiple blocks containing 2^BLOCK_SIZE_EXPONENT elements. Therefore
/// the memory address of the elements will not change if the array grows and no memory is
/// copied. Nonetheless objects have to be copied/moved when you call Insert() or Erase(),
/// but the amount of memory is limited to the size of a block which makes it much faster
/// than a BaseArray for these purposes.
///
/// Please note that in a C++11 range based for loop you may not call a non-const method
/// that modifies the range (e.g. Erase) - it does not work because the loop does not
/// expect the range to change. Use the Iterable::EraseIterator in that case.
///
/// Performance characteristics:
/// Random access to array elements is constant or at least amortized constant (when elements have been removed inbetween): O(1).
/// Append or Pop (erase the last) an element is amortized constant: O(1)
/// Insert or Erase an element can be amortized constant (unless block size and array size mismatch) : O(1)
/// @note: Do not rely on the characteristics to pick the right type of collection. Always profile to check real life performance!
///
/// @tparam T											Type of the array elements.
/// @tparam BLOCK_SIZE_EXPONENT		Size of an array block: 2^BLOCK_SIZE_EXPONENT.
/// @tparam MEMFLAGS							Use BLOCKARRAYFLAGS::NONE unless you know the object can be moved and/or copied.
/// @tparam ALLOCATOR							Class for memory allocation.
///
/// @note Note that the array element class has special requirements regarding @link movecopy copy and move constructors @endlink.
/// @see @$ref arrays
//----------------------------------------------------------------------------------------
template <typename T, Int BLOCK_SIZE_EXPONENT = BLOCKARRAY_DEFAULT_SIZE_EXPONENT, BLOCKARRAYFLAGS MEMFLAGS = BLOCKARRAYFLAGS::NONE, typename ALLOCATOR = DefaultAllocator> class BlockArray
	: public ArrayBase<BlockArray<T, BLOCK_SIZE_EXPONENT, MEMFLAGS, ALLOCATOR>, T, ALLOCATOR, DefaultCompare>
{
	MAXON_DISALLOW_COPY_AND_ASSIGN(BlockArray);

	struct ForwardAllocator;
	using  ArrayBlock = BaseArray<T, (Int) MEMFLAGS & (Int) BLOCKARRAYFLAGS::GROW_SLOWLY ? BASEARRAY_DEFAULT_CHUNK_SIZE : (Int)1 << BLOCK_SIZE_EXPONENT, (BASEARRAYFLAGS) ((Int) MEMFLAGS & ~(Int) BLOCKARRAYFLAGS::NOINSERTERASE), ForwardAllocator>;
	using Super = ArrayBase<BlockArray<T, BLOCK_SIZE_EXPONENT, MEMFLAGS, ALLOCATOR>, T, ALLOCATOR, DefaultCompare>;

public:
	static const Int BLOCK_SIZE = (Int) 1 << BLOCK_SIZE_EXPONENT;
	using AllocatorType = ALLOCATOR;

	template <Bool CONSTITERATOR> class IteratorTemplate;
	using Iterator = IteratorTemplate<false>;
	using ConstIterator = IteratorTemplate<true>;

	BlockArray() :  _blocks(ForwardAllocator(this))
	{
	}

	/// this constructor has to be used if an array should use a custom allocator with member variables
	explicit BlockArray(const ALLOCATOR& a) : Super(a), _blocks(ForwardAllocator(this))
	{
	}

	~BlockArray()
	{
	}

	/// move constructor
	BlockArray(BlockArray&& src) : Super(std::move(src)), MAXON_MOVE_MEMBERS(_blocks)
	{
	}

	/// move assignment operator
	MAXON_OPERATOR_MOVE_ASSIGNMENT(BlockArray);

	//----------------------------------------------------------------------------------------
	/// Deletes all elements (calls destructors and frees memory).
	//----------------------------------------------------------------------------------------
	void Reset()
	{
		_blocks.Reset();
	}

	//----------------------------------------------------------------------------------------
	/// Deletes all elements (calls destructors and frees memory), but doesn't free the memory
	/// of the array which contains the blocks. The memory used by the blocks themselves
	/// is freed nevertheless.
	//----------------------------------------------------------------------------------------
	void Flush()
	{
		_blocks.Flush();
	}

	//----------------------------------------------------------------------------------------
	/// Gets the number of array elements.
	/// @return												Number of array elements.
	//----------------------------------------------------------------------------------------
	Int GetCount() const
	{
		Int blockCnt = _blocks.GetCount();
		Int cnt = 0;

		if (blockCnt > 0)
		{
			// Get the number of elements in already submitted blocks.
			cnt	= _blocks.GetSubmittedElementCount();

			// Add the number of elements in the last block.
			cnt += _blocks[blockCnt - 1].GetCount();
		}

		return cnt;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the number of elements for which memory has been allocated (for a BlockArray this is equal to GetCount() plus the number of free elements in the last block)
	/// @return												Number of array elements for which memory has been allocated.
	//----------------------------------------------------------------------------------------
	Int GetCapacityCount() const
	{
		Int	capacity = GetCount();

		if (capacity > 0)
		{
			const ArrayBlock& last = _blocks[_blocks.GetCount() - 1];
			capacity += last.GetCapacityCount() - last.GetCount();
		}

		return capacity;
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for const objects.
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												Array element.
	//----------------------------------------------------------------------------------------
	const T& operator [](Int idx) const
	{
		const ArrayBlock* block = GetBlockAndIndex(idx);
		return (*block)[idx];
	}

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for non-const objects.
	/// @param[in] idx								Element index (if it's out of bounds you will get an error in debug code only, otherwise it will crash).
	/// @return												Array element.
	//----------------------------------------------------------------------------------------
	// this is duplicate code but casting constness away for this case is plain ugly
	T& operator [](Int idx)
	{
		ArrayBlock* block = GetBlockAndIndex(idx);
		return (*block)[idx];
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the array.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultRef<T> Append()
	{
		ArrayBlock* block = _blocks.GetLast();

		// Append a block if there's none or the current block is full.
		if (MAXON_UNLIKELY(_blocks.IsEmpty() || block->GetCount() == BLOCK_SIZE))
		{
			block = _blocks.Append();
			if (block == nullptr)
				return nullptr;
		}

		return block->Append();
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the array and initializes it with a copy of x.
	/// @param[in] x									Value to be copied.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultRef<T> Append(const T& x)
	{
		ArrayBlock* block = _blocks.GetLast();

		// Append a block if there's none or the current block is full.
		if (MAXON_UNLIKELY(_blocks.IsEmpty() || block->GetCount() == BLOCK_SIZE))
		{
			block = _blocks.Append();
			if (block == nullptr)
				return nullptr;
		}

		return block->Append(x);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the array and moves the content of x to it.
	/// @param[in] x									Value to be moved.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultRef<T> Append(T&& x)
	{
		ArrayBlock* block = _blocks.GetLast();

		// Append a block if there's none or the current block is full.
		if (MAXON_UNLIKELY(_blocks.IsEmpty() || block->GetCount() == BLOCK_SIZE))
		{
			block = _blocks.Append();
			if (block == nullptr)
				return nullptr;
		}

		return block->Append(std::move(x));
	}

	//----------------------------------------------------------------------------------------
	/// Appends new elements at the end of the array.
	/// @param[in] values							Block with values to be copied.
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultPtr<T> Append(const Block<const T>& values)
	{
		return Insert(GetCount(), values);
	}

	//----------------------------------------------------------------------------------------
	/// Appends new elements at the end of the array.
	/// @param[in] values							Initializer list with values to be copied.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	ResultPtr<T> Append(const std::initializer_list<T>& values)
	{
		const T* first = values.begin();
		const T* last = values.end();
		Int cnt = last - first;
		return Append(Block<const T>(first, cnt));
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new default element at index position.
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultRef<T> Insert(Int position)
	{
		T* element = Insert(position, Block<const T>(nullptr, 1)).GetPointer();
		if (MAXON_LIKELY(element != nullptr))
			new (element) T();
		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new default element at iterator position.
	/// @param[in] position						Insert position.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(const Iterator& position)
	{
		ResultMemT<Iterator> element = Insert(position, Block<const T>(nullptr, 1));
		if (MAXON_LIKELY(element == OK))
			new (element.UncheckedGetValue().GetPtr()) T();
		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at index position and initializes it with a copy of x.
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] x									Value to be copied.
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultRef<T> Insert(Int position, const T& x)
	{
		return Insert(position, ToSingletonBlock(x));
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at iterator position and initializes it with a copy of x.
	/// @param[in] position						Insert position.
	/// @param[in] x									Value to be copied.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(const Iterator& position, const T& x)
	{
		return Insert(position, ToSingletonBlock(x));
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at index position and moves the content of x to it.
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] x									Value to be moved.
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultRef<T> Insert(Int position, T&& x)
	{
		T* element = Insert(position, Block<const T>(nullptr, 1)).GetPointer();
		if (MAXON_LIKELY(element != nullptr))
			new (element) T(std::move(x));
		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at iterator position and moves the content of x to it.
	/// @param[in] position						Insert position.
	/// @param[in] x									Value to be moved.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(const Iterator& position, T&& x)
	{
		ResultMemT<Iterator> element = Insert(position, Block<const T>(nullptr, 1));
		if (MAXON_LIKELY(element == OK))
			new (element.UncheckedGetValue().GetPtr()) T(std::move(x));
		return element;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at index position (all elements from position on are moved by the the count of @p values).
	/// @param[in] position						Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] values							Block with values to be copied.
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												Element pointer or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultPtr<T> Insert(Int position, const Block<const T>& values)
	{
		if (_blocks.IsContinuous())
		{
			if (position != GetCount())
			{
				if ((MEMFLAGS & BLOCKARRAYFLAGS::NOINSERTERASE) != BLOCKARRAYFLAGS::NONE)
				{
					DebugStop("Insert() within the array is not supported with these flags.");
					return nullptr;
				}
				_blocks.MarkAsNoncontinuous();
			}
		}

		Int localIdx = position;
		Int blockIdx = ResolveToLocalIndex(localIdx);

		if (UInt(blockIdx) >= UInt(_blocks.GetCount()))
		{
			if ((blockIdx != _blocks.GetCount()) || (localIdx > 0))
			{
				DebugStop("The position is invalid.");
				return nullptr;
			}
		}

		// Insert elements and handle out of memory.
		Int remaining = Insert(blockIdx, localIdx, values);
		if (remaining > 0)
		{
			DebugStop("Insert failed: Remove the the number of elements that have already been inserted before out of memory.");
			Erase(position, values.GetCount() - remaining) iferr_cannot_fail("Erase failed - someone has broken the array code.");
			return nullptr;
		}

		// Check for insert of 0 elements at array end and return a dummy pointer if the array is empty.
		if (MAXON_UNLIKELY(blockIdx == _blocks.GetCount()))
			return blockIdx > 0 ? End().GetPtr() : (T*) this;

		return _blocks[blockIdx].GetFirst() + localIdx;
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
	/// Inserts new elements at iterator position (all elements from position on are moved by the the count of @p values).
	/// @param[in] position						Insert position.
	/// @param[in] values							Block with values to be copied.
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(const Iterator& position, const Block<const T>& values)
	{
		if (_blocks.IsContinuous())
		{
			if (position != End())
			{
				if ((MEMFLAGS & BLOCKARRAYFLAGS::NOINSERTERASE) != BLOCKARRAYFLAGS::NONE)
				{
					DebugStop("Insert() within the array is not supported with these flags.");
					return FAILED;
				}
				else
				{
					_blocks.MarkAsNoncontinuous();
				}
			}
		}

		if (position)
		{
			Int localIdx;
			Int blockIdx = position.GetBlockIndexAndLocalIndex(localIdx);

			// Insert elements to validated block position.
			Int remaining = Insert(blockIdx, localIdx, values);

			// Return the updated iterator if insert was successful.
			if (MAXON_LIKELY(remaining == 0))
				return Iterator(this, blockIdx, localIdx);

			// Handle out of memory.
			DebugStop("Insert failed: Remove the the number of elements that have already been inserted before out of memory.");
			if (Erase(position, values.GetCount() - remaining) == Iterator())
				DebugStop("Erase failed - someone has broken the array code.");
		}

		return FAILED;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts new elements at iterator position (all elements from @p position on are moved by the the count of @p values).
	/// @param[in] position						Insert position.
	/// @param[in] values							Initializer list with values to be copied.
	/// @return												Iterator for the new element or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	ResultMemT<Iterator> Insert(Iterator position, const std::initializer_list<T>& values)
	{
		const T* first = values.begin();
		const T* last = values.end();
		Int cnt = last - first;
		return Insert(position, Block<const T>(first, cnt));
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

		if (MAXON_UNLIKELY(UInt(position) >= UInt(cnt)))
		{
			if (position == cnt && eraseCnt == 0)
			{
				// Return a dummy pointer if the array is empty.
				return cnt > 0 ? End().GetPtr() : (T*) this;
			}

			DebugStop("The position is invalid.");
			return nullptr;
		}

		if (UInt(availableCnt) > UInt(eraseCnt))
		{
			if ((MEMFLAGS & BLOCKARRAYFLAGS::NOINSERTERASE) != BLOCKARRAYFLAGS::NONE)
			{
				DebugStop("Erase within the array is not supported with these flags.");
				return nullptr;
			}

			// Erase within the array will make it non-continuous.
			_blocks.MarkAsNoncontinuous();
		}
		else if (availableCnt != eraseCnt)
		{
			DebugStop("You are trying to erase more elements than available.");
			return nullptr;
		}

		Int localIdx = position;
		Int blockIdx = ResolveToLocalIndex(localIdx);

		if (Erase(blockIdx, localIdx, eraseCnt) > 0)
			DebugStop("You are trying to erase more elements than available.");

		// Check for array end and return a dummy pointer if the array is empty.
		if (MAXON_UNLIKELY(blockIdx == _blocks.GetCount()))
			return blockIdx > 0 ? End().GetPtr() : (T*) this;

		// If all elements from localIdx on have been erased switch to the next block (unless this is already the last block).
		if ((localIdx == _blocks[blockIdx].GetCount()) && (blockIdx + 1 != _blocks.GetCount()))
		{
			localIdx = 0;
			blockIdx += 1;
		}

		return _blocks[blockIdx].GetFirst() + localIdx;
	}

	//----------------------------------------------------------------------------------------
	/// Erases (removes and deletes) elements.
	/// @param[in] position						Erase position.
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) an invalid iterator will be returned.
	/// @return												Iterator for the element that is now at position (its operator Bool() will return false if something failed).
	/// @note To erase an element within a ranged based for loop, you can't use this function directly as you don't have access to the iterator.
	/// But you can use <tt>Iterable::EraseIterator</tt> as in
	/// @code
	/// for (auto it = Iterable::EraseIterator(array); it; ++it)
	/// {
	///   if (*it == valueToErase)
	///     it.Erase();
	/// }
	/// @endcode
	//----------------------------------------------------------------------------------------
	Iterator Erase(const Iterator& position, Int eraseCnt = 1)
	{
		if (position)
		{
			Int availableCnt = End() - position;
			if (UInt(availableCnt) > UInt(eraseCnt))
			{
				if ((MEMFLAGS & BLOCKARRAYFLAGS::NOINSERTERASE) != BLOCKARRAYFLAGS::NONE)
				{
					DebugStop("Erase within the array is not supported with these flags.");
					return Iterator();
				}

				// Erase within the array will make it non-continuous.
				_blocks.MarkAsNoncontinuous();
			}
			else if (availableCnt != eraseCnt)
			{
				DebugStop("You are trying to erase more elements than available.");
				return Iterator();
			}

			Int localIdx;
			Int blockIdx = position.GetBlockIndexAndLocalIndex(localIdx);

			// Erase elements from validated block position.
			Int remaining = Erase(blockIdx, localIdx, eraseCnt);

			// Debug message for eraseCnt.
			if (MAXON_UNLIKELY(remaining > 0))
				DebugStop("You are trying to erase more elements than available.");

			return Iterator(this, blockIdx, localIdx);
		}

		return Iterator();
	}

	//----------------------------------------------------------------------------------------
	/// Erases elements within the array and moves elements from the end to the erased gap.
	/// This is generally faster than Erase because at most eraseCnt elements have to be moved,
	/// but it changes the order of elements.
	/// @param[in] position						Erase index (SwapErase() will fail if out of bounds and return nullptr).
	/// @param[in] eraseCnt						Number of elements to be erased. If eraseCnt is invalid (higher than allowed or negative) false will be returned.
	/// @return												False if position was out of bounds.
	//----------------------------------------------------------------------------------------
	ResultMem SwapErase(Int position, Int eraseCnt = 1)
	{
		Int cnt = GetCount();
		Int availableCnt = cnt - position;

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

		// Calculate the source and destination start index.
		Int srcIdx = Max<Int>(cnt - eraseCnt, position + eraseCnt);
		Int dstIdx = position;
		Int moveCnt = cnt - srcIdx;

		// Get source and destination addresses including block ends.
		ArrayBlock* srcBlock = GetBlockAndIndex(srcIdx);
		ArrayBlock* dstBlock = GetBlockAndIndex(dstIdx);

		Move(dstBlock, dstIdx, srcBlock, srcIdx, moveCnt);

		Erase(cnt - eraseCnt, eraseCnt) iferr_cannot_fail("Shrinking the array should never fail");

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
	Iterator SwapErase(const Iterator& position, Int eraseCnt = 1)
	{
		Iterator erasePosition = position;
		Int availableCnt = End() - position;

		if (UInt(availableCnt) < UInt(eraseCnt))
		{
			DebugStop("You are trying to erase more elements than available.");
			return Iterator();
		}

		if (eraseCnt != availableCnt)
		{
			Int remaining = availableCnt - eraseCnt;

			erasePosition += remaining;

			// Check if source and destination overlap (less to move, but same number of elements to erase).
			Int moveCnt = eraseCnt > remaining ? remaining : eraseCnt;
			Iterator src = position + (availableCnt - moveCnt);
			Int dstIdx;
			Int dstBlockIdx = position.GetBlockIndexAndLocalIndex(dstIdx);
			Int srcIdx;
			Int srcBlockIdx = src.GetBlockIndexAndLocalIndex(srcIdx);

			Move(&_blocks[dstBlockIdx], dstIdx, &_blocks[srcBlockIdx], srcIdx, moveCnt);
		}

		Iterator updatedPosition = Erase(erasePosition, eraseCnt);

		// Return End() if position has become the array end.
		if (updatedPosition == End() && erasePosition == position)
			return updatedPosition;

		return position;
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p position.
	/// The returned blocks are guaranteed to form a partition of the array,
	/// i.e., no two blocks overlap, and they cover the whole array.
	/// @param[in] position						Element index.
	/// @param[out] block							Block which contains the element at @p position.
	/// @return												Start index of the block. The requested element can be found within the block at @p position - start index.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> Int GetBlock(Int position, Block<const T, STRIDED>& block) const
	{
		if ((UInt) position >= (UInt) GetCount())
		{
			block.Reset();
			return position;
		}
		Int i = position;
		const ArrayBlock* b = GetBlockAndIndex(i);
		block.Set(b->GetFirst(), b->GetCount(), SIZEOF(T));
		return position - i;
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p position.
	/// The returned blocks are guaranteed to form a partition of the array,
	/// i.e., no two blocks overlap, and they cover the whole array.
	/// @param[in] position						Element index.
	/// @param[out] block							Block which contains the element at @p position.
	/// @return												Start index of the block. The requested element can be found within the block at @p position - start index.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> Int GetBlock(Int position, Block<T, STRIDED>& block)
	{
		return static_cast<const BlockArray*>(this)->GetBlock(position, reinterpret_cast<Block<const T, STRIDED>&>(block));
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p position.
	/// For a BaseArray, this yields the whole array as a block.
	/// @param[in] position						Element position.
	/// @param[out] block							Block which contains the element at @p position.
	/// @return												Start iterator of the block. The requested element can be found within the block at index @p position - start iterator.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> MAXON_ATTRIBUTE_FORCE_INLINE ConstIterator GetBlock(const ConstIterator& position, Block<const T, STRIDED>& block) const
	{
		return position.GetBlock(block);
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous block of array elements which contains the element at @p position.
	/// For a BaseArray, this yields the whole array as a block.
	/// @param[in] position						Element position.
	/// @param[out] block							Block which contains the element at @p position.
	/// @return												Start iterator of the block. The requested element can be found within the block at index @p position - start iterator.
	//----------------------------------------------------------------------------------------
	template <Bool STRIDED> MAXON_ATTRIBUTE_FORCE_INLINE Iterator GetBlock(const Iterator& position, Block<T, STRIDED>& block)
	{
		return position.GetBlock(block);
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
		return OK;
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
		Int oldCnt = GetCount();

		// Increase array size if elements are to be added.
		if (newCnt > oldCnt)
		{
			ArrayBlock* block	= nullptr;
			Int	blockCnt	= _blocks.GetCount();
			Int	addCnt	= newCnt - oldCnt;

			// Use either DEFAULT or POD_UNINITIALIZED as resize flags for the block.
			resizeFlags = (resizeFlags & COLLECTION_RESIZE_FLAGS::ON_GROW_UNINITIALIZED) ? COLLECTION_RESIZE_FLAGS::POD_UNINITIALIZED : COLLECTION_RESIZE_FLAGS::DEFAULT;

			if (blockCnt > 0)
			{
				block = &_blocks[blockCnt - 1];
				goto add_elements;
			}

			while (addCnt > 0)
			{
				block = _blocks.Append();
				if (block == nullptr)
					return FAILED;

			add_elements:
				Int currentCnt = block->GetCount();
				Int increment = BLOCK_SIZE - currentCnt;

				// Resize the block if not all of its elements are used.
				if (increment > 0)
				{
					if (increment > addCnt)
						increment = addCnt;

					if (block->Resize(currentCnt + increment, resizeFlags) == FAILED)
						break;

					addCnt -= increment;
				}
			}
			return ResultMem(addCnt == 0);
		}
		else if (newCnt == oldCnt)
		{
			return OK;
		}
		else
		{
			// Decrease array size.
			if (newCnt >= 0)
			{
				Erase(newCnt, oldCnt - newCnt) iferr_cannot_fail("Someone has broken the array code.");

				return OK;
			}
			else
			{
				DebugStop("Invalid array size specified.");
			}
		}
		return FAILED;
	}

	//----------------------------------------------------------------------------------------
	/// Deletes the last element.
	/// @param[out] dst								Nullptr or pointer to return value.
	/// @return												True if there was at least one element.
	//----------------------------------------------------------------------------------------
	Bool Pop(T* dst = nullptr)
	{
		Int blockCnt = _blocks.GetCount();
		Bool	success = false;

		if (blockCnt > 0)
		{
			ArrayBlock& block = _blocks[blockCnt - 1];

			if (block.Pop(dst))
			{
				// Remove block if it is empty.
				if (block.GetCount() == 0)
					_blocks.Pop();

				success = true;
			}
		}
		return success;
	}

	//----------------------------------------------------------------------------------------
	/// Gets the index of an element. The element must be part of the array, otherwise (e.g. if x is
	/// a copy of an array element) InvalidArrayIndex will be returned.
	/// This is slower than for a BaseArray because it has to iterate over the block.
	/// @return												Index of element or InvalidIndex (not element of this).
	//----------------------------------------------------------------------------------------
	Int GetIndex(const T& x) const
	{
		Int	idx = 0;

		for (Int i = 0; i < _blocks.GetCount(); i++)
		{
			const ArrayBlock& block = _blocks[i];
			const T* first = &block[0];
			Int	cnt = block.GetCount();

			// Check if x is within the range from first to last element of the block.
			if ((&x >= first) && (&x < first + cnt))
				return idx + &x - first;

			idx += cnt;
		}

		DebugStop();
		return InvalidArrayIndex;
	}

	using Super::CopyFromImpl;

	// specialization for BlockArray
	// TODO: (Anybody) add specialization for BlockArray

	// specialization for BaseArray
	template<typename BASEARRAY, typename = typename std::enable_if<std::is_same<typename std::decay<BASEARRAY>::type, BaseArray<T>>::value>::type>
	Result<void> CopyFromImpl(BASEARRAY&& src, COLLECTION_RESIZE_FLAGS resizeFlags, OverloadRank4)
	{
		Int	cnt = src.GetCount();
		Int	i = 0;

		Reset();

		while (cnt > 0)
		{
			ArrayBlock* block = _blocks.Append();
			Int	insertCnt = cnt > BLOCK_SIZE ? BLOCK_SIZE : cnt;

			if (block == nullptr)
				break;

			if (block->Insert(0, ToBlock(&src[i], insertCnt)) == FAILED)
				return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);

			i += insertCnt;
			cnt -= insertCnt;
		}

		// Array copy successful?
		if (cnt == 0)
			return OK;

		Reset();
		return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::OUT_OF_MEMORY);
	}

	//----------------------------------------------------------------------------------------
	/// Swaps elements a and b (equivalent to global Swap(array[a], array[b]).
	/// @param[in] a									Position of element to be swapped.
	/// @param[in] b									Position of element to be swapped.
	//----------------------------------------------------------------------------------------
	void Swap(Iterator& a, Iterator& b)
	{
		maxon::Swap(*a, *b);
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the memory usage for this array.
	/// The array element class must have a public member GetMemorySize that returns an element's size.
	/// @return												Memory size in bytes.
	//----------------------------------------------------------------------------------------
	Int GetMemorySize() const
	{
		return SIZEOF(*this) - SIZEOF(_blocks) + maxon::GetMemorySizeHelper(_blocks);
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the first element.
	/// When you modify the array Begin() will change, it is not a constant value.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	ConstIterator Begin() const
	{
		return ConstIterator(*this, 0);
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the first element.
	/// When you modify the array Begin() will change, it is not a constant value.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	Iterator Begin()
	{
		return Iterator(*this, 0);
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the end (End() - 1 is the last element if the array is not empty).
	/// When you modify the array End() will change, it is not a constant value.
	/// @return												Iterator for the array end (this is behind the last element).
	//----------------------------------------------------------------------------------------
	ConstIterator End() const
	{
		if (MAXON_UNLIKELY(_blocks.IsEmpty()))
			return ConstIterator(this);
		const ArrayBlock* block = _blocks.GetLast();
		return ConstIterator(this, block, block->End(), block->End());
	}

	//----------------------------------------------------------------------------------------
	/// Gets an iterator for the end (End() - 1 is the last element if the array is not empty).
	/// When you modify the array End() will change, it is not a constant value.
	/// @return												Iterator for the array end (this is behind the last element).
	//----------------------------------------------------------------------------------------
	Iterator End()
	{
		if (MAXON_UNLIKELY(_blocks.IsEmpty()))
			return Iterator(this);
		ArrayBlock* block = _blocks.GetLast();
		return Iterator(this, block, block->End(), block->End());
	}
	
	//----------------------------------------------------------------------------------------
	/// Disconnects the array's memory buffers and returns its content as an array of blocks.
	/// Afterwards the array is in the same state as directly after its construction.
	/// @return												Array of blocks.
	/// @note The memory needs to be freed with the allocator that the array is using.
	//----------------------------------------------------------------------------------------
	BaseArray<ArrayBlock, BASEARRAY_DEFAULT_CHUNK_SIZE, BASEARRAYFLAGS::NONE, ForwardAllocator> Disconnect()
	{
		return _blocks.Disconnect();
	}

	//----------------------------------------------------------------------------------------
	/// The BlockArray iterator uses several tricks to make iteration faster than using a
	/// for loop with operator []. Therefore you should use it (or the C++11 range based for loop)
	/// to iterate over the array or parts of it.
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
		// For a const iterator, the BlockArray, its values, the blocks and their iterators have to be const within the iterator, otherwise they are non-const.
		// These type aliases have to be used throughout the iterator code instead of just BlockArray, T, etc.
		using BlockIterator = typename std::conditional<CONSTITERATOR, typename ArrayBlock::ConstIterator, typename ArrayBlock::Iterator>::type;
		using BlockType = typename ConstIf<ArrayBlock, CONSTITERATOR>::type;

	public:
		using CollectionType = typename ConstIf<BlockArray, CONSTITERATOR>::type;
		using Type = typename ConstIf<T, CONSTITERATOR>::type;
		static const Bool isLinearIterator = false;

		explicit IteratorTemplate(CollectionType& a, Int start = 0) : _array(&a), _block(nullptr)
		{
			Int blockIdx = a.ResolveToLocalIndex(start);

			if (MAXON_UNLIKELY(blockIdx == a._blocks.GetCount()))
			{
				// This is the end iterator. Do not set _block, _iterator and _end if the BlockArray is empty.
				if (blockIdx == 0)
					return;

				blockIdx -= 1;
				start = a._blocks[blockIdx].GetCount();
			}

			_block = &a._blocks[blockIdx];
			_iterator = _block->Begin() + start;
			_end = _block->End();
		}

		explicit IteratorTemplate(CollectionType* a, Int blockIdx, Int localIdx) : _array(a), _block(nullptr)
		{
			Int blockCnt = a->_blocks.GetCount();
			BlockType* block = (a->_blocks.Begin() + blockIdx).GetPtr();

			if (MAXON_UNLIKELY(blockIdx == blockCnt))
			{
				// This is the end iterator. Do not set _block, _iterator and _end if the BlockArray is empty.
				if (blockIdx == 0)
					return;

				// Let the end iterator point at the end of the last block.
				block -= 1;
				localIdx = block->GetCount();
			}
			else if (MAXON_UNLIKELY(localIdx == block->GetCount()))
			{
				// If the index points to the end of the block let it point to the start of the next one (unless it is already the last block).
				if (blockIdx != blockCnt - 1)
				{
					block += 1;
					localIdx = 0;
				}
			}

			_block = block;
			_iterator = block->Begin() + localIdx;
			_end = block->End();
		}

		explicit IteratorTemplate(CollectionType* a = nullptr, BlockType *block = nullptr, BlockIterator it = BlockIterator(), BlockIterator end = BlockIterator()) : _array(a), _block(block), _iterator(it), _end(end)
		{
		}

		IteratorTemplate(const IteratorTemplate& src) : _array(src._array), _block(src._block), _iterator(src._iterator), _end(src._end)
		{
		}

		IteratorTemplate& operator =(const IteratorTemplate& src)
		{
			_array = src._array;																	// self assignment is no problem here, therefore no check if (this != &src)
			_block = src._block;
			_iterator = src._iterator;
			_end = src._end;

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
		/// Determines a contiguous block of array elements to which the iterator points.
		/// @param[out] block							Block which contains the element..
		/// @return												Start iterator of the block.
		//----------------------------------------------------------------------------------------
		template <Bool STRIDED> MAXON_ATTRIBUTE_FORCE_INLINE IteratorTemplate GetBlock(Block<Type, STRIDED>& block) const
		{
			block.Set(_block->GetFirst(), _block->GetCount(), sizeof(T));
			return IteratorTemplate(_array, _block, _block->Begin(), _end);
		}

		Int GetBlockIndexAndLocalIndex(Int& localIdx) const
		{
			if (MAXON_UNLIKELY(_block == nullptr))
			{
				localIdx = 0;
				return 0;
			}

			// Don't use GetIndex() here because it'll return InvalidArrayIndex for the pointer behind the last element.
			localIdx = _iterator - _block->Begin();
			return _block - &_array->_blocks[0];
		}

		//----------------------------------------------------------------------------------------
		/// @return												true if the iterator points to an element.
		//----------------------------------------------------------------------------------------
		explicit operator Bool() const
		{
			return Bool(_array != nullptr);
		}

		Type* GetPtr() const
		{
			return _iterator.GetPtr();
		}

		Type& operator *() const
		{
			return *_iterator;
		}

		Type* operator ->() const
		{
			return &(*_iterator);
		}

		Bool operator ==(const IteratorTemplate& b) const
		{
			return _iterator == b._iterator;
		}

		Bool operator <(const IteratorTemplate& b) const
		{
			if ((_block < b._block) || ((_block == b._block) && (_iterator < b._iterator)))
				return true;

			return false;
		}

		MAXON_OPERATOR_COMPARISON(IteratorTemplate);

		// prefix operator ++ (increment and fetch)
		IteratorTemplate& operator ++()
		{
			++_iterator;

			// At the end of the current block?
			if (_iterator == _end)
			{
				// Not the last block?
				if (_block != &_array->_blocks[_array->_blocks.GetCount() - 1])
				{
					// Go to next block.
					_block++;
					_iterator = _block->Begin();
					_end = _block->End();
				}
			}
			return *this;
		}

		// postfix operator ++ (fetch and increment)
		const IteratorTemplate operator ++(int)
		{
			BlockType*	tmpBlock = _block;
			BlockIterator	tmpIterator = _iterator;
			BlockIterator	tmpEnd = _end;

			++(*this);

			// use RVO
			return IteratorTemplate(_array, tmpBlock, tmpIterator, tmpEnd);
		}

		// operator +=
		IteratorTemplate& operator +=(Int i)
		{
			if (i > 0)
			{
				BlockType* lastBlock = _array->_blocks.GetLast();
				Int	maxDiff = _end - _iterator;

				// Loop while element is not in the current block.
				while (i >= maxDiff)
				{
					if (MAXON_UNLIKELY(_block == lastBlock))
					{
						// For End() the iterator has to point behind the last element of the last block. Anything beyond that is an error.
						if (MAXON_UNLIKELY(i > maxDiff))
						{
							i = maxDiff;
							DebugStop("An invalid offset was specified");
						}
						break;
					}

					i -= maxDiff;

					// Go to next block.
					_block++;
					_iterator = _block->Begin();
					_end = _block->End();

					maxDiff = _end - _iterator;
				}
				_iterator += i;
			}
			else if (i < 0)
			{
				*this -= -i;
			}
			return *this;
		}

		// operator +
		IteratorTemplate operator +(Int i) const
		{
			IteratorTemplate tmp = *this;
			tmp += i;
			return tmp;
		}

		// prefix operator -- (decrement and fetch)
		IteratorTemplate& operator --()
		{
			// At the start of the current block?
			if (_iterator == _block->Begin())
			{
				// Go to previous block.
				_block--;
				_iterator = _end = _block->End();
			}
			--_iterator;
			return *this;
		}

		// postfix operator -- (fetch and decrement)
		const IteratorTemplate operator --(int)
		{
			BlockType*	tmpBlock = _block;
			BlockIterator	tmpIterator = _iterator;
			BlockIterator	tmpEnd = _end;

			--(*this);

			// use RVO
			return IteratorTemplate(_array, tmpBlock, tmpIterator, tmpEnd);
		}

		// operator -=
		IteratorTemplate& operator -=(Int i)
		{
			if (i > 0)
			{
				Int	maxDiff = _iterator - _block->Begin();

				// Loop while element is not in the current block.
				while (i > maxDiff)
				{
					i -= maxDiff;

					// Go to previous block.
					_block--;
					_iterator = _end = _block->End();
					maxDiff = _end - _block->Begin();
				}
				_iterator -= i;
			}
			else if (i < 0)
			{
				*this += -i;
			}
			return *this;
		}

		// operator -
		IteratorTemplate operator -(Int i) const
		{
			IteratorTemplate	tmp = *this;
			tmp -= i;
			return tmp;
		}

		Int operator -(const IteratorTemplate& b) const
		{
			BlockType* block = _block;
			Int	cnt = _iterator - b._iterator;

			if (block > b._block)
			{
				// b has a smaller index (result must be positive).
				cnt = _iterator - block->Begin();

				for (block--; block > b._block; block--)
					cnt += block->GetCount();

				cnt += block->End() - b._iterator;
			}
			else if (block < b._block)
			{
				// b has a bigger index (result must be negative).
				cnt = _iterator - _end;

				for (block++; block < b._block; block++)
					cnt -= block->GetCount();

				cnt -= b._iterator - block->Begin();
			}
			return cnt;
		}

	private:
		CollectionType*								_array;
		BlockType*										_block;
		BlockIterator							_iterator;
		BlockIterator							_end;
	};

	//----------------------------------------------------------------------------------------
	/// Returns the allocator as reference. Typically this is used by the arrays and other
	/// base classes when multiple of them are "stiched" together as one big object all
	/// shall use one main allocator.
	/// @return												Allocator reference.
	//----------------------------------------------------------------------------------------
	ALLOCATOR& GetAllocator()
	{
		return *this;
	}

private:
	//----------------------------------------------------------------------------------------
	/// @return												0 on success or the number of elements not being inserted.
	//----------------------------------------------------------------------------------------
	Int Insert(Int blockIdx, Int localIdx, const Block<const T>& values)
	{
		Int insertCnt = values.GetCount();
		const T* x = values.GetFirst();

		// When End() is used as position the localIdx specifies the end of the last block. If this block
		// is full blockIdx and localIdx must point to the start of a new block which is to be appended.
		if (localIdx == BLOCK_SIZE)
		{
			blockIdx += 1;
			localIdx = 0;
		}

		while (insertCnt > 0)
		{
			ArrayBlock* block = nullptr;
			Int currentBlockSize = 0;

			if (MAXON_UNLIKELY(blockIdx == _blocks.GetCount()))
			{
				// Append a new block.
				block = _blocks.Append();
				if (block == nullptr)
					return insertCnt;
			}
			else
			{
				block = &_blocks[blockIdx];

				// Insert a new block if the current one is full.
				currentBlockSize = block->GetCount(); 
				if (currentBlockSize == BLOCK_SIZE)
				{
					block = _blocks.SplitBlock(blockIdx, localIdx);
					if (block == nullptr)
						return insertCnt;
					currentBlockSize = block->GetCount();
				}
			}

			Int	cnt = insertCnt;
			if (currentBlockSize + insertCnt > BLOCK_SIZE)
			{
				cnt = BLOCK_SIZE - currentBlockSize;
				DebugAssert(cnt != 0, "If cnt is 0 someone has broken the array code.");
			}

			if (block->Insert(localIdx, ToBlock(x, cnt)) == FAILED)
			{
				DebugStop("Insertion failed - someone has broken the array code.");
				break;
			}

			_blocks.UpdateSubmittedElementCount(block, cnt);

			DebugAssert(block->GetCount() <= BLOCK_SIZE, "Someone has broken the array code.");

			if (x)
				x += cnt;
			insertCnt -= cnt;

			blockIdx++;
			localIdx = 0;
		}

		return insertCnt;
	}

	Int Erase(Int blockIdx, Int localIdx, Int eraseCnt)
	{
		while ((eraseCnt > 0) && (blockIdx < _blocks.GetCount()))
		{
			ArrayBlock*	block = &_blocks[blockIdx];
			Int blkCnt = block->GetCount() - localIdx;

			if (blkCnt > eraseCnt)
				blkCnt = eraseCnt;

			block->Erase(localIdx, blkCnt) iferr_cannot_fail("Someone has broken the array code.");
			_blocks.UpdateSubmittedElementCount(block, -blkCnt);

			// Update the number of elements still to erase and advance by a block.
			eraseCnt -= blkCnt;
			blockIdx += 1;
			localIdx = 0;

			// Remove block if it is empty.
			if (block->GetCount() == 0)
			{
				blockIdx -= 1;
				if (_blocks.Erase(blockIdx) == nullptr)
					DebugStop("Erase failed - someone has broken the array code.");
			}
		}

		return eraseCnt;
	}

	void Move(ArrayBlock* dstBlock, Int dstLocalIdx, ArrayBlock* srcBlock, Int srcLocalIdx, Int moveCnt)
	{
		// Get source and destination addresses including block ends.
		T* src = &(*srcBlock)[0];
		T* srcEnd = src + srcBlock->GetCount();
		src += srcLocalIdx;
		T* dst = &(*dstBlock)[0];
		T* dstEnd = dst + dstBlock->GetCount();
		dst += dstLocalIdx;

		// Move elements and switch blocks whenever necessary.
		for (; moveCnt > 0; moveCnt--)
		{
			if (MAXON_UNLIKELY(src == srcEnd))
			{
				// Advance to next source block.
				srcBlock += 1;
				src = &(*srcBlock)[0];
				srcEnd = src + srcBlock->GetCount();
			}

			if (MAXON_UNLIKELY(dst == dstEnd))
			{
				// Advance to next destination block.
				dstBlock += 1;
				dst = &(*dstBlock)[0];
				dstEnd = dst + dstBlock->GetCount();
			}

			*dst++ = std::move(*src++);
		}
	}

	//----------------------------------------------------------------------------------------
	/// Returns the block index and local index within that block for a global array index.
	/// @param[in,out] idx						On input the global index, on return the local index within the block (must be < GetCount()).
	/// @return												Block index.
	//----------------------------------------------------------------------------------------
	Int ResolveToLocalIndex(Int& idx) const
	{
		Int blockIdx = idx >> BLOCK_SIZE_EXPONENT;

		if (((MEMFLAGS & BLOCKARRAYFLAGS::NOINSERTERASE) == BLOCKARRAYFLAGS::NONE) && _blocks.IsContinuous() == false)
		{
			Int blockCnt = _blocks.GetCount();
			Int offset = 0;

			for (blockIdx = 0; blockIdx < blockCnt; blockIdx++)
			{
				Int cnt = _blocks[blockIdx].GetCount();

				if (idx < offset + cnt)
					break;

				offset += cnt;
			}

			idx -= offset;
		}

		idx &= BLOCK_SIZE - 1;
		return blockIdx;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the block and local index within that block for a global array index.
	/// @param[in,out] idx						On input the global index, on return the local index within the block (must be < GetCount()).
	/// @return												Block pointer.
	//----------------------------------------------------------------------------------------
	ArrayBlock* GetBlockAndIndex(Int& idx)
	{
		// This will cause a debug break if blockIdx is invalid.
		return &_blocks[ResolveToLocalIndex(idx)];
	}

	const ArrayBlock* GetBlockAndIndex(Int& idx) const
	{
		// This will cause a debug break if blockIdx is invalid.
		return &_blocks[ResolveToLocalIndex(idx)];
	}

	struct ForwardAllocator
	{
		explicit ForwardAllocator(ALLOCATOR* a) : _a(a)
		{
		}
		ForwardAllocator(const ForwardAllocator& src) : _a(src._a)
		{
		}
		void operator =(const ForwardAllocator&)
		{
		}

		Int ComputeArraySize(Int currentSize, Int increment, Int minChunkSize)
		{
			return _a->ComputeArraySize(currentSize, increment, minChunkSize);
		}
		void* Alloc(Int s, MAXON_SOURCE_LOCATION_DECLARATION)
		{
			return _a->Alloc(s, MAXON_SOURCE_LOCATION_FORWARD);
		}
		void* Realloc(void* p, Int n, MAXON_SOURCE_LOCATION_DECLARATION)
		{
			return _a->Realloc(p, n, MAXON_SOURCE_LOCATION_FORWARD);
		}
		template <typename X> void Free(X*& p)
		{
			_a->Free(p);
		}

	private:
		ALLOCATOR* _a; // we mustn't use ALLOCATOR& because then ForwardAllocator won't be a standard-layout class
	};

	class ArrayOfBlocks
	{
		using Super = BaseArray<ArrayBlock, BASEARRAY_DEFAULT_CHUNK_SIZE, BASEARRAYFLAGS::NONE, ForwardAllocator>;
	public:
		ArrayOfBlocks() : _usedBlockCnt(0), _submittedElementCnt(0), _isContinuous(Int(true)), _reserved(0)
		{
		}
		explicit ArrayOfBlocks(const ForwardAllocator& a) : _array(a), _usedBlockCnt(0), _submittedElementCnt(0), _isContinuous(Int(true)), _reserved(0)
		{
		}
		explicit ArrayOfBlocks(ForwardAllocator&& a) : _array(std::move(a)), _usedBlockCnt(0), _submittedElementCnt(0), _isContinuous(Int(true)), _reserved(0)
		{
		}

		ArrayOfBlocks(ArrayOfBlocks&& src) : _array(std::move(src._array)), _usedBlockCnt(src._usedBlockCnt), _submittedElementCnt(src._submittedElementCnt), _isContinuous(src._isContinuous), _reserved(0)
		{
			src._usedBlockCnt = 0;
			src._submittedElementCnt = 0;
			src._isContinuous = Int(false);
		}

		void Reset()
		{
			_array.Reset();
			_usedBlockCnt = 0;
			_submittedElementCnt = 0;
			_isContinuous = Int(true);
		}

		void Flush()
		{
			_array.Flush();
			_usedBlockCnt = 0;
			_submittedElementCnt = 0;
			_isContinuous = Int(true);
		}

		Int GetCount() const
		{
			return _usedBlockCnt;
		}

		Bool IsEmpty() const
		{
			return _usedBlockCnt == 0;
		}

		Bool IsPopulated() const
		{
			return _usedBlockCnt != 0;
		}

		Bool IsContinuous() const
		{
			return _isContinuous != 0;
		}

		void MarkAsNoncontinuous()
		{
			_isContinuous = 0;
		}

		ArrayBlock& operator [](Int index)
		{
			return _array[index];
		}

		const ArrayBlock& operator [](Int index) const
		{
			return _array[index];
		}

		typename Super::Iterator Begin()
		{
			return _array.Begin();
		}

		typename Super::ConstIterator Begin() const
		{
			return _array.Begin();
		}

		//----------------------------------------------------------------------------------------
		/// @return												Pointer to the last ArrayBlock (undefined if the array is empty).
		//----------------------------------------------------------------------------------------
		ArrayBlock* GetLast()
		{
			return _array.Begin().GetPtr() + (_usedBlockCnt - 1);
		}

		Super Disconnect()
		{
			_usedBlockCnt = 0;
			_submittedElementCnt = 0;
			_isContinuous = Int(true);
			return std::move(_array);
		}

		//----------------------------------------------------------------------------------------
		/// @return												Pointer to the last ArrayBlock (undefined if the array is empty).
		//----------------------------------------------------------------------------------------
		const ArrayBlock* GetLast() const
		{
			return _array.Begin().GetPtr() + (_usedBlockCnt - 1);
		}

		// Ensures that the new Block uses our allocator (which forwards calls to the BlockArray).
		ArrayBlock* Append()
		{
			Int elementsToCommit = _usedBlockCnt > 0 ? _array[_usedBlockCnt - 1].GetCount() : 0;

			if (_usedBlockCnt < _array.GetCount())
			{
				_submittedElementCnt += elementsToCommit;
				_usedBlockCnt += 1;
				return &_array[_usedBlockCnt - 1];
			}

			// Allocate first and then construct because the ArrayBlock element with its allocator must not be moved or copied.
			ArrayBlock* block = _array.Append(MoveBlock<ArrayBlock>(nullptr, 1)).GetPointer();
			if (block)
			{
				new (block) ArrayBlock(_array.GetAllocator());

				_submittedElementCnt += elementsToCommit;
				_usedBlockCnt += 1;

				if (((MEMFLAGS & BLOCKARRAYFLAGS::GROW_SLOWLY) == BLOCKARRAYFLAGS::NONE) || _array.GetCount() > 1)
				{
					block->EnsureCapacity(BLOCK_SIZE) iferr_ignore("A later allocation will either get BLOCK_SIZE or fail.");
				}
			}
			return block;
		}

		// Ensures that the new Block uses our allocator (which forwards calls to the BlockArray).
		ArrayBlock* Insert(Int position)
		{
			Int elementsToCommit = 0;

			if (position == _usedBlockCnt)
			{
				if (_usedBlockCnt > 0)
					elementsToCommit = _array[_usedBlockCnt - 1].GetCount();

				if (_usedBlockCnt < _array.GetCount())
				{
					_submittedElementCnt += elementsToCommit;
					_usedBlockCnt += 1;
					return &_array[_usedBlockCnt - 1];
				}
			}

			ArrayBlock* block = InsertOnly(position);
			if (block)
				_submittedElementCnt += elementsToCommit;

			return block;
		}

		ArrayBlock* Erase(Int position)
		{
			if (position == _usedBlockCnt - 1)
				return Pop();

			ArrayBlock* block = _array.Erase(position).GetPointer();
			if (block)
				_usedBlockCnt -= 1;

			return block;
		}

		ArrayBlock* Pop()
		{
			if (_usedBlockCnt == 0)
				return nullptr;

			_usedBlockCnt -= 1;
			ArrayBlock& block = _array[_usedBlockCnt];

			// Only keep up to one spare block at the end of the array.
			if (_array.GetCount() - _usedBlockCnt > 1)
				_array.Pop();
			else
				block.Flush();

			if (_usedBlockCnt > 0)
				_submittedElementCnt -= _array[_usedBlockCnt - 1].GetCount();

			return &block;
		}

		Int GetIndex(const ArrayBlock& x) const
		{
			return _array.GetIndex(x);
		}

		ArrayBlock* SplitBlock(Int blockIdx, Int localIdx)
		{
			DebugAssert(localIdx < BLOCK_SIZE, "Index must be within the block.");
			ArrayBlock* block = nullptr;

			if (localIdx < BLOCK_SIZE / 2)
			{
				// Insert before current block (clean up, erase already inserted elements if that fails).
				block = InsertOnly(blockIdx);
				if (block == nullptr)
					return nullptr;

				if (localIdx > 0)
				{
					// Insert() has moved or reallocated memory, therefore the full block has a different address than before.
					ArrayBlock* splittableBlock = &_array[blockIdx + 1];

					// Move localIdx elements to the new block.
					if (splittableBlock->MoveAndShrink(*block, 0, localIdx) == FAILED)
						DebugStop();
				}
			}
			else
			{
				// Insert behind current block (clean up, erase already inserted elements if that fails).
				block = InsertOnly(blockIdx + 1);
				if (block == nullptr)
					return nullptr;

				// The insert position is not at the end of the current block. Therefore memory was
				// moved or reallocated and the full block has a different address than before.
				ArrayBlock* splittableBlock = &_array[blockIdx];

				// Move all elements between localIdx and BLOCK_SIZE to the inserted block.
				if (splittableBlock->MoveAndShrink(*block, localIdx, BLOCK_SIZE - localIdx) == FAILED)
					DebugStop();

				// Insert at the end of the "old" block.
				block = splittableBlock;
			}

			// Update the number of submitted elements if the splitted block previously was the last block.
			if (blockIdx == _array.GetCount() - 2)
				_submittedElementCnt += localIdx;

			return block;
		}

		void UpdateSubmittedElementCount(const ArrayBlock* block, Int cnt)
		{
			if (block != GetLast())
				_submittedElementCnt += cnt;
		}

		Int GetSubmittedElementCount() const
		{
#ifdef MAXON_TARGET_DEBUG
			Int submittedBlockCnt = GetCount() - 1;
			Int cnt = 0;

			if (submittedBlockCnt >= 0)
			{
				cnt = submittedBlockCnt << BLOCK_SIZE_EXPONENT;

				if (((MEMFLAGS & BLOCKARRAYFLAGS::NOINSERTERASE) == BLOCKARRAYFLAGS::NONE) && IsContinuous() == false)
				{
					cnt = 0;
					for (Int i = 0; i < submittedBlockCnt; i++)
						cnt += _array[i].GetCount();
				}
			}
			DebugAssert(cnt == _submittedElementCnt);
#endif

			return _submittedElementCnt;
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

	private:
		// Ensures that the new Block uses our allocator (which forwards calls to the BlockArray).
		ArrayBlock* InsertOnly(Int position)
		{
			// Allocate first and then construct because the ArrayBlock element with its allocator must not be moved or copied.
			ArrayBlock* block = _array.Insert(position, MoveBlock<ArrayBlock>(nullptr, 1)).GetPointer();
			if (block)
			{
				new (block) ArrayBlock(_array.GetAllocator());

				_usedBlockCnt += 1;

				if (((MEMFLAGS & BLOCKARRAYFLAGS::GROW_SLOWLY) == BLOCKARRAYFLAGS::NONE) || _array.GetCount() > 1)
				{
					block->EnsureCapacity(BLOCK_SIZE) iferr_ignore("A later allocation will either get BLOCK_SIZE or fail.");
				}
			}
			return block;
		}

	private:
		Super _array;

		Int _usedBlockCnt;					// Number of used blocks.
		Int _submittedElementCnt;		// Number of elements excluding the last (not yet submitted) block.
		Int	_isContinuous;					// _isContinuous is currently being used as a flag. In the future it might be used to the store the last index until which the blocks are continuous (without gaps from Insert/Erase).
		Int _reserved;
	};

private:
	ArrayOfBlocks _blocks;
};


//----------------------------------------------------------------------------------------
/// This selector class is used for template parameters which select the array implementation
/// to use. It will then instruct the template to use the BlockArray implementation.
/// For example, ArrayMap by uses an underlying BaseArray by default. If you want to use
/// a BlockArray instead, you'd write
/// @code
/// ArrayMap<Int, String, true, DefaultCompare, BlockArraySelector<>> map;
/// @endcode
///
/// @tparam BLOCK_SIZE_EXPONENT		Size of an array block: 2^BLOCK_SIZE_EXPONENT.
/// @tparam MEMFLAGS							Use BLOCKARRAYFLAGS::NONE unless you know the object can be moved and/or copied.
/// @tparam ALLOCATOR							Class for memory allocation.
//----------------------------------------------------------------------------------------
template <Int BLOCK_SIZE_EXPONENT = BLOCKARRAY_DEFAULT_SIZE_EXPONENT, BLOCKARRAYFLAGS MEMFLAGS = BLOCKARRAYFLAGS::NONE, typename ALLOCATOR = DefaultAllocator> class BlockArraySelector
{
public:
	template <typename T> using Type = BlockArray<T, BLOCK_SIZE_EXPONENT, MEMFLAGS, ALLOCATOR>;
};


/// @}

} // namespace maxon

#endif // BLOCKARRAY_H__
