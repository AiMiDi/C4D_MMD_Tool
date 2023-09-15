#ifndef ARRAY_H__
#define ARRAY_H__

#include "maxon/containerbase.h"

namespace maxon
{

class PersistentIdGeneratorInterface
{
	MAXON_INTERFACE_SIMPLE_VIRTUAL(PersistentIdGeneratorInterface, MAXON_REFERENCE_COPY_ON_WRITE);
public:
	MAXON_METHOD Result<void> InitializeBuffer(PersistentIdBuffer& buffer) const;

	MAXON_METHOD void FreeBuffer(PersistentIdBuffer& buffer) const;

	MAXON_METHOD Result<void> Move(Int index, PersistentIdBuffer& buffer) const;

	MAXON_METHOD Result<void> Advance(Int index, PersistentIdBuffer& buffer) const;
};

class PersistentIdGenerator;

template <typename TYPE> class StaticArrayInterface : public GenericIndexableContainerInterface MAXON_GENERIC_BASE(NamedTuple<TYPE>)
{
# ifdef CPP_853_HACK // use space after # so that the source processor doesn't recognize those directives
	CPP_853_HACK_MAXON_INTERFACE_SIMPLE_VIRTUAL_DERIVED(StaticArrayInterface, MAXON_REFERENCE_COPY_ON_WRITE);
# else
	MAXON_INTERFACE_SIMPLE_VIRTUAL_DERIVED(StaticArrayInterface, MAXON_REFERENCE_COPY_ON_WRITE);
# endif

public:
	using ValueType = TYPE;
	using NonConstValueType = ValueType;

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for const objects.
	/// @param[in] index							Element index.
	/// @return												Array element.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const TYPE& operator [](Int index) const;

	//----------------------------------------------------------------------------------------
	/// Array (subscript) operator for non-const objects.
	/// @param[in] index							Element index.
	/// @return												Array element.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultRef<TYPE> GetWritable(Int index);

	template <typename A> MAXON_FUNCTION ResultMem Set(Int index, A&& value)
	{
		ResultRef<TYPE> x = GetWritable(index);
		if (x == FAILED)
			return false;
		return AssignCopyConvert(x.GetValue(), std::forward<A>(value)) == OK;
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous, possibly strided block of array elements which contains the element at @p index.
	/// The returned blocks are guaranteed to form a partition of the array,
	/// i.e., no two blocks overlap, and they cover the whole array.
	///
	/// Using this method can greatly reduce the performance penalty of virtual method
	/// invocations of the Array interface as only one such invocation has to happen per block,
	/// and a block may consist of a relatively large number of elements which can then be
	/// accessed directly.
	///
	/// @param[in] index							Element index.
	/// @param[out] block							Block which contains the element at @p index.
	/// @return												Start index of the block. I.e., the requested element can be found within the block at @p index - start index.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetBlock(Int index, SimdBlock<const TYPE>& block) const;

	Int GetBlock(Int index, StridedBlock<const TYPE>& block) const
	{
		SimdBlock<const TYPE> b;
		Int bs = GetBlock(index, b);
		if (!b.GetInfo().IsSimd())
		{
			block = b.ToBlock();
			return bs;
		}
		Int m = b.GetInfo().GetMultiplicity();
		Int mask = ~(m - 1);
		Int i = (index - bs) & mask;
		block.Set(&b[i], Min(m, block.GetCount() - i), b.GetInfo().GetComponentSize());
		return index & mask;
	}

	Int GetBlock(Int index, Block<const TYPE, false>& block) const
	{
		StridedBlock<const TYPE> b;
		Int bs = GetBlock(index, b);
		if (b.GetStride() == GetValueSize())
		{
			block.Set(b.GetFirst(), b.GetCount());
			return bs;
		}
		block.Set(&b[index - bs], 1);
		return index;
	}

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous, possibly strided writable block of array elements which contains the element at @p index.
	/// The returned blocks are guaranteed to form a partition of the array,
	/// i.e., no two blocks overlap, and they cover the whole array.
	///
	/// Using this method can greatly reduce the performance penalty of virtual method
	/// invocations of the Array interface as only one such invocation has to happen per block,
	/// and a block may consist of a relatively large number of elements which can then be
	/// accessed directly.
	///
	/// @param[in] index							Element index.
	/// @param[out] block							Block which contains the element at @p index.
	/// @return												Start index of the block. I.e., the requested element can be found within the block at @p index - start index.
	/// @MAXON_ANNOTATION{cowName=GetWritableBlock}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> GetBlock(Int index, SimdBlock<NonConstValueType>& block);

	Int GetBlock(Int index, StridedBlock<NonConstValueType>& block)
	{
		SimdBlock<NonConstValueType> b;
		iferr (Int bs = GetBlock(index, b))
		{
			DebugStop();
			return -1;
		}
		if (!b.GetInfo().IsSimd())
		{
			block = b.ToBlock();
			return bs;
		}
		Int m = b.GetInfo().GetMultiplicity();
		Int mask = ~(m - 1);
		Int i = (index - bs) & mask;
		block.Set(&b[i], Min(m, block.GetCount() - i), b.GetInfo().GetComponentSize());
		return index & mask;
	}

	//----------------------------------------------------------------------------------------
	/// Returns the data type of this array's elements. This may be nullptr if there is no
	/// DataType for the template parameter TYPE.
	/// @return												DataType of the elements or nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const DataType& GetValueDataType() const;

	MAXON_METHOD const PersistentIdGenerator& GetPersistentIdGenerator() const;

	//----------------------------------------------------------------------------------------
	/// Will ensure that all elements of the array are writable for multithreaded access.
	/// Besides parallel write use case, MakeAllElementsWritable is not required as GetWritable(Int index) method does all the work.
	/// This is useful mostly for paged arrays (GenericContainerInterface::INTERFACES::PAGED_ARRAY).
	/// @param[in] copyElements				Clone all the elements.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> MakeAllElementsWritable(Bool copyElements = true);

	//----------------------------------------------------------------------------------------
	/// Will ensure that all required elements of the array ([#start, #end]) are writable for multithreaded access.
	/// Elements before and after the given range [#start, #end], will always get copied so that the rest of the target page(s)
	/// are still valid after the write operations. I.e. use #copyElements = false when the range will get overwritten without reading current value.
	/// Besides parallel write use case, MakeElementsWritable is not required as GetWritable(Int index) method does all the work.
	/// This is useful mostly for paged arrays (GenericContainerInterface::INTERFACES::PAGED_ARRAY).
	/// @code
	/// Array<Int> myInts;
	/// ...
	/// // For a single writable element (writable element will not get copied, other elements will):
	/// array.MakeElementsWritable(10, 11, false) iferr_return;
	/// // For a more writable elements (writable elements will get copied, along with all other elements of the target page(s)):
	/// array.MakeElementsWritable(0, 2000, true) iferr_return;
	/// @endcode
	/// @param[in] start							Start index (inclusive).
	/// @param[in] end								End index (exclusive).
	/// @param[in] copyElements				Clone elements of the given range.
	/// @return												OK on success.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> MakeElementsWritable(Int start, Int end, Bool copyElements = true);

	MAXON_METHOD_RESERVE;
	MAXON_METHOD_RESERVE;
	MAXON_METHOD_RESERVE;
	MAXON_METHOD_RESERVE;

	BlockIterator<StaticArrayInterface, TYPE, true, false> GetBlocks() const
	{
		return this;
	}

	BlockIterator<StaticArrayInterface, TYPE, true, true> GetStridedBlocks() const
	{
		return this;
	}

	static const Bool GENERIC = STD_IS_REPLACEMENT(same, const Generic, const TYPE);
	using TYPE_FOR_SIZEOF = typename std::conditional<GENERIC, Char, TYPE>::type;

	Int GetValueSize() const
	{
		DebugAssert(GENERIC || GetValueDataType()->GetValueKind() & VALUEKIND::GENERIC || GetValueDataType()->GetSize() == SIZEOF(TYPE_FOR_SIZEOF));
		return GENERIC ? GetValueDataType()->GetSize() : SIZEOF(TYPE_FOR_SIZEOF);
	}

	template <typename COLLECTION_TYPE> class IteratorTemplate
	{
	public:
		using CollectionType = COLLECTION_TYPE;
		using Type = typename InheritConst<TYPE, COLLECTION_TYPE>::type;

		explicit IteratorTemplate(CollectionType& a) : _array(&a)
		{
			StridedBlock<Type> block;
			_blockStartIndex = _array->GetBlock(0, block);
			DebugAssert(_blockStartIndex == 0);
			_blockEndIndex = block.GetCount();
			_stride = block.GetStride();
			_index = 0;
			_ptr = block.GetFirst();
		}

		explicit IteratorTemplate(CollectionType& a, Int start) : _array(&a)
		{
			StridedBlock<Type> block;
			_blockStartIndex = _array->GetBlock(start, block);
			_blockEndIndex = _blockStartIndex + block.GetCount();
			_stride = block.GetStride();
			_index = start;
			_ptr = (Type*)((Char*)block.GetFirst() + (start - _blockStartIndex) * _stride);
		}

		IteratorTemplate(const IteratorTemplate& src) = default;

		IteratorTemplate() : _index(LIMIT<Int>::MIN) // it suffices to initialize _index for a null Iterator because only this is used for ==
		{
		}

		MAXON_OPERATOR_COPY_ASSIGNMENT(IteratorTemplate);

	#ifdef MAXON_COMPILER_INTEL
	#pragma warning disable 597
	#endif
		operator IteratorTemplate<const COLLECTION_TYPE>&()
		{
			return *reinterpret_cast<IteratorTemplate<const COLLECTION_TYPE>*>(this);
		}
	#ifdef MAXON_COMPILER_INTEL
	#pragma warning enable 597
	#endif

		Type& operator *() const
		{
			return *_ptr;
		}

		Type* operator ->() const
		{
			return _ptr;
		}

		Bool operator ==(const IteratorTemplate& b) const
		{
			return _index == b._index;
		}

		Bool operator <(const IteratorTemplate& b) const
		{
			return _index < b._index;
		}

		MAXON_OPERATOR_COMPARISON(IteratorTemplate);

		// prefix operator ++ (increment and fetch)
		IteratorTemplate& operator ++()
		{
			_ptr = (Type*)((Char*)_ptr + GetStride());
			++_index;
			if (MAXON_UNLIKELY(_index == _blockEndIndex))
			{
				ValidateBlock(false);
			}
			return *this;
		}

		// postfix operator ++ (fetch and increment)
		IteratorTemplate operator ++(int)
		{
			IteratorTemplate tmp = *this;
			this->operator ++();
			return tmp;
		}

		// operator +=
		IteratorTemplate& operator +=(Int i)
		{
			_ptr = (Type*)((Char*)_ptr + i * GetStride());
			_index += i;
			ValidateBlock(true);
			return *this;
		}

		// prefix operator -- (decrement and fetch)
		IteratorTemplate& operator --()
		{
			_ptr = (Type*)((Char*)_ptr - GetStride());
			--_index;
			if (MAXON_UNLIKELY(_index < _blockStartIndex))
			{
				ValidateBlock(false);
			}
			return *this;
		}

		// postfix operator -- (fetch and decrement)
		IteratorTemplate operator --(int)
		{
			IteratorTemplate tmp = *this;
			this->operator --();
			return tmp;
		}

		// operator -=
		IteratorTemplate& operator -=(Int i)
		{
			_ptr = (Type*)((Char*)_ptr - i * GetStride());
			_index -= i;
			ValidateBlock(true);
			return *this;
		}

		// operator +
		IteratorTemplate operator +(Int i) const
		{
			IteratorTemplate it = *this;
			it += i;
			return it;
		}

		IteratorTemplate operator -(Int i) const
		{
			IteratorTemplate it = *this;
			it -= i;
			return it;
		}

		Int operator -(const IteratorTemplate& b) const
		{
			return _index - b._index;
		}

		Int GetIndex() const
		{
			return _index;
		}

		Int GetBlock(StridedBlock<Type>& block) const
		{
			block.Set((Type*) ((Char*) _ptr - (_index - _blockStartIndex) * _stride), _blockEndIndex - _blockStartIndex, _stride);
			return _blockStartIndex;
		}

		Int GetBlock(Block<Type, false>& block) const
		{
			if (MAXON_LIKELY(GetStride() == SIZEOF(Type)))
			{
				block.Set(_ptr - (_index - _blockStartIndex), _blockEndIndex - _blockStartIndex);
				return _blockStartIndex;
			}
			else
			{
				block.Set(_ptr, 1);
				return _index;
			}
		}

		// returns a pointer to the block which ensures that the next 'count' elements are in the same non-strided block and advances the iterator by count elements
		Type* FetchNonStridedBlock(Int count = 1)
		{
			DebugAssert(count > 0);
			if (MAXON_LIKELY(_stride == SIZEOF(Type) && (_index + count) <= _blockEndIndex))
			{
				Type* ptr = _ptr;
				_ptr += count;
				_index += count;
				if (_index == _blockEndIndex)
					ValidateBlock(false);
				return ptr;
			}
			return nullptr;
		}

	private:
		void ValidateBlock(Bool check)
		{
			if (!check || MAXON_UNLIKELY((_index < _blockStartIndex) || (_index >= _blockEndIndex)))
			{
				StridedBlock<Type> block;
				_blockStartIndex = _array->GetBlock(_index, block);
				_blockEndIndex = _blockStartIndex + block.GetCount();
				_stride = block.GetStride();
				_ptr = (Type*)((Char*)block.GetFirst() + (_index - _blockStartIndex) * _stride);
			}
		}

		Int GetStride() const
		{
			return _stride;
		}

		CollectionType* _array;
		Type*	_ptr;
		Int _index;
		Int _stride;
		Int _blockStartIndex;
		Int _blockEndIndex;
	};

	using Iterator = IteratorTemplate<StaticArrayInterface>;
	using ConstIterator = IteratorTemplate<const StaticArrayInterface>;

	MAXON_ADD_TO_CONST_REFERENCE_CLASS
	(
	using Iterator = typename StaticArrayInterface::ConstIterator;
	using ConstIterator = typename StaticArrayInterface::ConstIterator;
	);

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first array element.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION typename StaticArrayInterface<TYPE>::ConstIterator Begin() const
	{
		return ConstIterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first array element.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	Iterator Begin()
	{
		return Iterator(*this);
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing one behind the last array element.
	/// @return												Iterator for the array end, this is one behind the last element.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION typename StaticArrayInterface<TYPE>::ConstIterator End() const
	{
		return ConstIterator(*this, this->GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing one behind the last array element.
	/// @return												Iterator for the array end, this is one behind the last element.
	//----------------------------------------------------------------------------------------
	Iterator End()
	{
		return Iterator(*this, this->GetCount());
	}

private:
	static StaticArrayInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return nullptr;
	}

	friend class StrongCOWRefHandler;
};



template <typename TYPE> class NonConstArray;
class ArrayFactory;

//----------------------------------------------------------------------------------------
/// ArrayInterface is an interface which provides the usual array functions as virtual methods.
/// Each standard array of the MAXON API can be represented as such an interface, so this
/// allows to write non-template functions which nevertheless are able to deal with any kind
/// of array.
///
/// If the function won't modify both the structure and values of the array, you
/// should use a @c const ArrayInterface with @c const elements:
/// @code
/// void Func(const ArrayInterface<const Char>& array);
///
/// BlockArray<Char> myArray;
/// Func(myArray); // OK
/// BaseArray<Char> myArray2;
/// Func(myArray2); // OK
/// @endcode
/// As the access to the array happens via virtual methods, there is an inevitable performance
/// penalty. Often this will be negligible, but if not, you can use the GetBlock function
/// to obtain a fraction of the array as a Block of array elements which are laid out regularly in memory.
/// Then as long as the elements you need to access are within that same block, no further virtual method invocations
/// are necessary. E.g., a BaseArray consists of just a single block, and a BlockArray of a small number of blocks
/// (small compared to the number of elements).
/// The iterator of an ArrayInterface already takes this into account, so it uses the minimum possible number
/// of virtual method invocations.
///
/// For an array which shall be modified, use WritableArrayInterface as type of the function parameter instead.
///
/// @tparam TYPE									Type of elements of the array.
//----------------------------------------------------------------------------------------
template <typename TYPE> class ArrayInterface : public ArrayBase0<ArrayInterface<TYPE>, TYPE, StaticArrayInterface<TYPE>, DefaultCompare>
{

# ifdef CPP_853_HACK // use space after # so that the source processor doesn't recognize those directives
	CPP_853_HACK_MAXON_INTERFACE_SIMPLE_VIRTUAL_DERIVED(ArrayInterface, MAXON_REFERENCE_COPY_ON_WRITE);
# else
	MAXON_INTERFACE_SIMPLE_VIRTUAL_DERIVED(ArrayInterface, MAXON_REFERENCE_COPY_ON_WRITE);
# endif

public:
	using ValueType = TYPE;

	MAXON_ADD_TO_COPY_ON_WRITE_REFERENCE_CLASS(
		public: using ValueType = TYPE;
	);

	using Super = StaticArrayInterface<TYPE>;

	using Super::IsEqual;
	using Super::GetHashCode;
	using Super::GetUniqueHashCode;
	using Super::ToString;

	using Super::operator [];
	TYPE& operator [](Int index) { return Super::GetWritable(index).GetValue(); }

	using Super::GetBlock;

	//----------------------------------------------------------------------------------------
	/// Determines a contiguous non-strided block of array elements which contains the element at @p index.
	/// The returned blocks are guaranteed to form a partition of the array,
	/// i.e., no two blocks overlap, and they cover the whole array.
	///
	/// Using this method can greatly reduce the performance penalty of virtual method
	/// invocations of the Array interface as only one such invocation has to happen per block,
	/// and a block may consist of a relatively large number of elements which can then be
	/// accessed directly.
	///
	/// @param[in] index							Element index.
	/// @param[out] block							Block which contains the element at @p index.
	/// @return												Start index of the block. I.e., the requested element can be found within the block at @p index - start index.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetBlock(Int index, Block<const TYPE>& block) const;

	Int GetBlock(Int index, Block<typename Super::NonConstValueType>& block)
	{
		StridedBlock<typename Super::NonConstValueType> b;
		Int bs = Super::GetBlock(index, b);
		// #LEGACYCOMPATIBILITY: Clean up GetBlock functions
		if (b.GetStride() == Super::GetValueSize())
		{
			block = ToBlock(b.GetFirst(), b.GetCount());
			return bs;
		}
		else
		{
			block = ToBlock(b.GetPtr(index - bs), 1);
			return index;
		}
	}

	//----------------------------------------------------------------------------------------
	/// For future compatibility, not implemented at the moment.
	// #LEGACYCOMPATIBILITY: remove the other Insert methods
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> PrivateInsert(Int index, const StridedBlock<const TYPE>& values, Bool move, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY);

	//----------------------------------------------------------------------------------------
	/// Resizes the array to contain count elements.
	/// If count is smaller than GetCount() all extra elements are being deleted. If it is
	/// greater the array is expanded and the default constructor is called for new elements.
	/// @param[in] count							New array size.
	/// @param[in] resizeFlags				See COLLECTION_RESIZE_FLAGS.
	/// @return												False if allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultMem Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::DEFAULT);

	//----------------------------------------------------------------------------------------
	/// Prepare the internal array so that it can hold at least the given number of elements with
	/// as few further memory allocations as possible.
	/// @param[in] requestedCapacity	The desired internal capacity.
	/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
	/// @return												False if allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultMem SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY);

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at @p index. The element will be default-constructed.
	/// @param[in] index							Insertion index (the array size will increase and the existing elements are moved).
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultRef<TYPE> Insert(Int index);

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at index position and initializes it with #value.
	/// @param[in] index							Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] value							Value to be inserted.
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION ResultRef<TYPE> Insert(Int index, const TYPE& value)
	{
		ResultRef<TYPE> x = Insert(index);
		if (x == FAILED || AssignCopy(x.GetValue(), value) == FAILED)
			return nullptr;
		return x;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a new element at index position and initializes it with #value.
	/// @param[in] index							Insert index (the array size will increase and the existing elements are moved).
	/// @param[in] value							Value to be inserted.
	/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION ResultRef<TYPE> Insert(Int index, TYPE&& value)
	{
		ResultRef<TYPE> x = Insert(index);
		if (x == FAILED)
			return nullptr;
		x.GetValue() = std::move(value);
		return x;
	}

	//----------------------------------------------------------------------------------------
	/// Inserts a number of new elements at @p index. The elements will be copied.
	/// @param[in] index							Insertion index (the array size will increase and the existing elements are moved).
	/// @param[in] values							Block with values to be copied.
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												False if insert failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultMem Insert(Int index, const Block<const TYPE>& values);

	//----------------------------------------------------------------------------------------
	/// Inserts a number of new elements at @p index. The elements will be moved.
	/// @param[in] index							Insertion index (the array size will increase and the existing elements are moved).
	/// @param[in] values							Block with values to be moved.
	/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
	/// @return												False if insert failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultMem Insert(Int index, const MoveBlock<TYPE>& values);

	MAXON_FUNCTION ResultMem InsertBlock(Int index, const Block<const TYPE>& values)
	{
		return Insert(index, values);
	}

	MAXON_FUNCTION ResultMem InsertBlock(Int index, const MoveBlock<TYPE>& values)
	{
		return Insert(index, values);
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the array. The element will be default-constructed.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultRef<TYPE> Append();

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the array and initializes it with #value.
	/// @param[in] value							Value to be appended.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION ResultRef<TYPE> Append(const TYPE& value)
	{
		ResultRef<TYPE> x = Append();
		if (x == FAILED || AssignCopy(x.GetValue(), value) == FAILED)
			return nullptr;
		return x;
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the array and initializes it with #value.
	/// @param[in] value							Value to be appended.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION ResultRef<TYPE> Append(TYPE&& value)
	{
		ResultRef<TYPE> x = Append();
		if (x == FAILED || AssignCopy(x.GetValue(), std::move(value)) == FAILED)
			return nullptr;
		return x;
	}

	//----------------------------------------------------------------------------------------
	/// Adds a new element at the end of the array and initializes it with #value.
	/// @param[in] value							Value to be appended.
	/// @return												Element reference or OutOfMemoryError if the allocation failed.
	//----------------------------------------------------------------------------------------
	template <typename A> MAXON_FUNCTION ResultRef<TYPE> Append(A&& value)
	{
		ResultRef<TYPE> x = Append();
		if (x == FAILED || AssignCopyConvert(x.GetValue(), std::forward<A>(value)) == FAILED)
			return nullptr;
		return x;
	}

	//----------------------------------------------------------------------------------------
	/// Deletes the last element.
	/// @return												True if there was at least one element.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool Pop()
	{
		Int cnt = this->GetCount();
		if (!cnt)
			return false;
		Resize(cnt - 1) iferr_cannot_fail("resize will never fail, mute the warning");
		return true;
	}

	//----------------------------------------------------------------------------------------
	/// Deletes the last element.
	/// @param[out] dst								Nullptr or pointer to return value.
	/// @return												True if there was at least one element.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION Bool Pop(TYPE* dst)
	{
		Int cnt = this->GetCount();
		if (!cnt)
			return false;
		if (dst)
			*dst = std::move(this->operator [](cnt - 1));
		Resize(cnt - 1);
		return true;
	}

	//----------------------------------------------------------------------------------------
	/// Erases (removes and deletes) elements.
	/// @param[in] index							Erase index.
	/// @param[in] count							Number of elements to be erased (if eraseCnt is higher than what is available at position Erase() will succeed, but remove only the number of available elements).
	/// @return												True if operation was successul.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultMem Erase(Int index, Int count = 1);

	//----------------------------------------------------------------------------------------
	/// Erases (removes and deletes) an element.
	/// @param[in] it									Iterator pointing to the element to erase.
	/// @return												True if operation was successul.
	//----------------------------------------------------------------------------------------
	template <typename C> typename ArrayInterface::template IteratorTemplate<C> Erase(const typename ArrayInterface::template IteratorTemplate<C>& it)
	{
		Int i = it.GetIndex();
		Erase(i) iferr_ignore("ignore for now");
		return typename ArrayInterface::template IteratorTemplate<C>(*static_cast<C*>(this), i);
	}

	//----------------------------------------------------------------------------------------
	/// Erases elements within the array and moves elements from the end to the erased gap.
	/// This is generally faster than Erase because at most count elements have to be moved,
	/// but it changes the order of elements.
	/// @param[in] index							Erase index.
	/// @param[in] count							Number of elements to be erased (if eraseCnt is higher than what is available at position Erase() will succeed, but remove only the number of available elements).
	/// @return												True if operation was successul.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD ResultMem SwapErase(Int index, Int count = 1);

	//----------------------------------------------------------------------------------------
	/// Deletes all elements (calls destructors and frees memory).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Reset();

	//----------------------------------------------------------------------------------------
	/// Deletes all elements, but doesn't free memory (calls destructors though).
	//----------------------------------------------------------------------------------------
	MAXON_METHOD void Flush();

	//----------------------------------------------------------------------------------------
	/// Sets this array to a copy of the given other array.
	/// @param[in] other							Source array.
	/// @return												Success of operation.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> CopyFrom(const ArrayInterface& other);

	MAXON_METHOD void SetPersistentIdGenerator(const PersistentIdGenerator& generator);

	//----------------------------------------------------------------------------------------
	/// Calculates the memory usage for this array.
	/// @return												Memory size in bytes.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetMemorySize() const;

	template <typename DT> MAXON_FUNCTION Bool HasType() const
	{
		return this->GetValueDataType() == maxon::GetDataType<typename std::remove_const<DT>::type>();
	}

	//----------------------------------------------------------------------------------------
	/// Issues a failed DebugAssert if the DataType of this array doesn't match T. If T is Generic,
	/// no check happens.
	/// @tparam DT										Type to check.
	//----------------------------------------------------------------------------------------
	template <typename DT> MAXON_FUNCTION void AssertType() const
	{
#ifdef MAXON_TARGET_DEBUG
		if (!STD_IS_REPLACEMENT(same, Generic, DT))
		{
			this->GetValueDataType().template AssertType<typename std::conditional<STD_IS_REPLACEMENT(same, Generic, DT), Int, typename std::remove_const<DT>::type>::type>();
		}
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Casts this array to an array with elements of type T2. If T2 doesn't match the actual data type of this
	/// array, a failed DebugAssert is issued. This function only makes sense when the original array
	/// uses Generic as its type.
	/// @tparam T2										Element type of the destination array.
	/// @return												This array, cast to an ArrayInterface of T2 elements.
	//----------------------------------------------------------------------------------------
	template <typename T2> ArrayInterface<T2>& AssertCast()
	{
		AssertType<T2>();
		return *reinterpret_cast<ArrayInterface<T2>*>(this);
	}

	//----------------------------------------------------------------------------------------
	/// Casts this array to an array with elements of type T2. If T2 doesn't match the actual data type of this
	/// array, a failed DebugAssert is issued. This function only makes sense when the original array
	/// uses Generic as its type.
	/// @tparam T2										Element type of the destination array.
	/// @return												This array, cast to an ArrayInterface of T2 elements.
	//----------------------------------------------------------------------------------------
	template <typename T2> const ArrayInterface<T2>& AssertCast() const
	{
		AssertType<T2>();
		return *reinterpret_cast<const ArrayInterface<T2>*>(this);
	}

#ifdef MAXON_COMPILER_INTEL
#pragma warning disable 597
#endif
	operator const ArrayInterface<const TYPE>&() const
	{
		return *(ArrayInterface<const TYPE>*) this;
	}

	operator const ArrayInterface<typename std::conditional<STD_IS_REPLACEMENT(same, const TYPE, const Generic), DeleteReturnType01, const Generic>::type>&() const
	{
		return *(ArrayInterface<typename std::conditional<STD_IS_REPLACEMENT(same, const TYPE, const Generic), DeleteReturnType01, const Generic>::type>*) this;
	}

	operator ArrayInterface<typename std::conditional<STD_IS_REPLACEMENT(same, TYPE, Generic), DeleteReturnType02, Generic>::type>&()
	{
		return *(ArrayInterface<typename std::conditional<STD_IS_REPLACEMENT(same, TYPE, Generic), DeleteReturnType02, Generic>::type>*) this;
	}
#ifdef MAXON_COMPILER_INTEL
#pragma warning enable 597
#endif

	operator const NonConstArray<TYPE>&()
	{
		return *reinterpret_cast<const NonConstArray<TYPE>*>(this);
	}

	operator const NonConstArray<typename std::conditional<STD_IS_REPLACEMENT(same, TYPE, Generic), DeleteReturnType01, Generic>::type>&()
	{
		return *reinterpret_cast<const NonConstArray<typename std::conditional<STD_IS_REPLACEMENT(same, TYPE, Generic), DeleteReturnType01, Generic>::type>*>(this);
	}


	using Iterator = typename Super::template IteratorTemplate<ArrayInterface>;
	using ConstIterator = typename Super::template IteratorTemplate<const ArrayInterface>;

	MAXON_ADD_TO_CONST_REFERENCE_CLASS
	(
	using Iterator = typename ArrayInterface::ConstIterator;
	using ConstIterator = typename ArrayInterface::ConstIterator;
	);

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first array element.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION typename ArrayInterface<TYPE>::ConstIterator Begin() const
	{
		return ConstIterator(*static_cast<const ArrayInterface*>(this));
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first array element.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	Iterator Begin()
	{
		return Iterator(*static_cast<ArrayInterface*>(this));
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing one behind the last array element.
	/// @return												Iterator for the array end, this is one behind the last element.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION typename ArrayInterface<TYPE>::ConstIterator End() const
	{
		return ConstIterator(*static_cast<const ArrayInterface*>(this), this->GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing one behind the last array element.
	/// @return												Iterator for the array end, this is one behind the last element.
	//----------------------------------------------------------------------------------------
	Iterator End()
	{
		return Iterator(*static_cast<ArrayInterface*>(this), this->GetCount());
	}

#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
	ArrayInterface(const ArrayInterface& src) // GCC constructs from the conversion result, upcasted to ArrayInterface&
#else
private:
	ArrayInterface(const ArrayInterface& src);
public:
	template <typename ARRAY> MAXON_IMPLICIT ArrayInterface(const ArrayImpl<ARRAY>& src) // MSVC constructs directly from the conversion result, which allows a more type-safe hack
#endif
		: ArrayBase0<ArrayInterface<TYPE>, TYPE, StaticArrayInterface<TYPE>, DefaultCompare>(reinterpret_cast<const typename StaticArrayInterface<TYPE>::MTable*>(src._vtableCls + 1)[-1]), _refDummy(src._refDummy)
	{
	}
#endif

protected:
	template <typename ARRAY> friend class ArrayImpl;
#ifdef CPP_853_HACK
	const void* _refDummy;
#endif

private:
	static ArrayInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return reinterpret_cast<ArrayInterface*>(SFINAEHelper<ArrayFactory, TYPE>::type::NewBaseArrayFromContainerType(maxon::GetDataType<ContainerInterface<TYPE>>(), nullptr, false).UncheckedGetValue().Disconnect());
	}

	friend class StrongCOWRefHandler;
};

/// Helper class for the WritableArrayInterface macro.
/// A WritableArrayInterface& parameter is actually a const NonConstArray& parameter,
/// so temporary objects resulting from a conversion of some array to the NonConstArray interface may be bound to such a parameter
/// (this wouldn't be possible if the parameter was non-const).
/// To be able to invoke modifying functions on such a parameter, those functions are implemented as const functions in this class.
template <typename TYPE> class NonConstArray : public ArrayInterface<TYPE>
{
public:
	using Super = ArrayInterface<TYPE>;

	const NonConstArray& ToArray() const
	{
		return *this;
	}
	NonConstArray& ToArray()
	{
		return *this;
	}
	operator const NonConstArray<typename std::conditional<STD_IS_REPLACEMENT(same, TYPE, Generic), DeleteReturnType01, Generic>::type>&() const
	{
		return *reinterpret_cast<const NonConstArray<typename std::conditional<STD_IS_REPLACEMENT(same, TYPE, Generic), DeleteReturnType01, Generic>::type>*>(this);
	}

	TYPE& operator [](Int index) const { return const_cast<NonConstArray*>(this)->Super::operator [](index); }
	Int GetBlock(Int index, Block<TYPE, false>& block) const { return const_cast<NonConstArray*>(this)->Super::GetBlock(index, block); }
	Int GetBlock(Int index, Block<TYPE, true>& block) const { return const_cast<NonConstArray*>(this)->Super::GetBlock(index, block); }
	ResultMem Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::DEFAULT) const { return const_cast<NonConstArray*>(this)->Super::Resize(count, resizeFlags); }
	ResultMem SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY) const { return const_cast<NonConstArray*>(this)->Super::SetCapacityHint(requestedCapacity, resizeFlags); }
	ResultRef<TYPE> Insert(Int index) const { return const_cast<NonConstArray*>(this)->Super::Insert(index); }
	ResultMem Insert(Int index, const Block<const TYPE>& values) const { return const_cast<NonConstArray*>(this)->Super::Insert(index, values); }
	ResultMem Insert(Int index, const MoveBlock<TYPE>& values) const { return const_cast<NonConstArray*>(this)->Super::Insert(index, values); }
	ResultRef<TYPE> Append() const { return const_cast<NonConstArray*>(this)->Super::Append(); }
	ResultRef<TYPE> Append(const TYPE& value) const { return const_cast<NonConstArray*>(this)->Super::Append(value); }
	ResultRef<TYPE> Append(TYPE&& value) const { return const_cast<NonConstArray*>(this)->Super::Append(std::move(value)); }
	template <typename T> ResultRef<TYPE> Append(T&& value) const { return const_cast<NonConstArray*>(this)->Super::Append(std::forward<T>(value)); }
	ResultMem Erase(Int index, Int count = 1) const { return const_cast<NonConstArray*>(this)->Super::Erase(index, count); }
	ResultMem SwapErase(Int index, Int count = 1) const { return const_cast<NonConstArray*>(this)->Super::SwapErase(index, count); }
	void Reset() const { return const_cast<NonConstArray*>(this)->Super::Reset(); }
	void Flush() const { return const_cast<NonConstArray*>(this)->Super::Flush(); }
	Result<void> CopyFrom(const Super& other) const { return const_cast<NonConstArray*>(this)->Super::CopyFrom(other); }

	using ConstIterator = typename Super::Iterator;

	ConstIterator Begin() const
	{
		return ConstIterator(*const_cast<NonConstArray*>(this));
	}

	ConstIterator End() const
	{
		return ConstIterator(*const_cast<NonConstArray*>(this), this->GetCount());
	}

#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
	NonConstArray(const NonConstArray& src) // GCC constructs from the conversion result, upcasted to NonConstArray&
#else
private:
	NonConstArray(const NonConstArray& src);
public:
	template <typename ARRAY> MAXON_IMPLICIT NonConstArray(const ArrayImpl<ARRAY>& src) // MSVC constructs directly from the conversion result, which allows a more type-safe hack
#endif
		: Super(src)
	{
	}
#endif

	template <typename COLLECTION2> Result<void> AppendAll(COLLECTION2&& other, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY) const
	{
		return const_cast<NonConstArray*>(this)->AppendAllImpl(std::forward<COLLECTION2>(other), resizeFlags, true, OVERLOAD_MAX_RANK);
	}

	template <typename COLLECTION2> Result<void> CopyFrom(COLLECTION2&& other, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::FIT_TO_SIZE) const
	{
		if (this == (const void*) &other)
			return OK;
		return const_cast<NonConstArray*>(this)->CopyFromImpl(std::forward<COLLECTION2>(other), resizeFlags, OVERLOAD_MAX_RANK);
	}

protected:
	explicit NonConstArray(const typename Super::MTable& vtable) : Super(vtable) { }

#ifdef CPP_853_HACK

private:
	void operator =(const NonConstArray&);

#else

	~NonConstArray() { }
private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(NonConstArray);

#endif
};

//----------------------------------------------------------------------------------------
/// WritableArrayInterface is used for function parameters which shall be able to receive any kind of
/// standard array of the MAXON API via the ArrayInterface interface mechanism. You have to use WritableArrayInterface
/// instead of ArrayInterface if you want to modify the array within the function. Example:
/// @code
/// void Func(WritableArrayInterface<Char>& array);
///
/// BlockArray<Char> myArray;
/// Func(myArray); // OK
/// BaseArray<Char> myArray2;
/// Func(myArray2); // OK
/// @endcode
/// @see ArrayInterface
//----------------------------------------------------------------------------------------
#ifdef MAXON_COMPILER_BUG_CONST_TYPE_ALIAS
#define WritableArrayInterface const NonConstArray
#else
template <typename T> using WritableArrayInterface = const NonConstArray<T>;
#endif

#include "array1.hxx"

//----------------------------------------------------------------------------------------
/// ArrayFactory provides static methods to create arrays of various implementations of the ArrayInterface in a generic way.
//----------------------------------------------------------------------------------------
class ArrayFactory
{
	MAXON_INTERFACE_NONVIRTUAL(ArrayFactory, MAXON_REFERENCE_NONE, "net.maxon.interface.arrayfactory");
public:
	//----------------------------------------------------------------------------------------
	/// Creates a new array which uses an internal BaseArray implementation. All elements will be in a single contiguous memory block.
	///
	/// The implementation has to obtain the container type from the given element type. In performance-critical code you should
	/// do that yourself outside of the performance-critical part and use the method NewBaseArrayFromContainerType.
	///
	/// @param[in] elementType				The element type of the array.
	/// @param[in] src								A pointer to a BaseArray<T> where T matches the given element type.
	/// 															This will be used to initialize the new array by copying or moving the elements.
	/// 															If src is nullptr, the new array will be empty.
	/// @param[in] move								If true, src will be moved into the new array. Note that this has to make a const_cast of the src parameter.
	/// @return												Newly created array.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Array<Generic>::NonConst> NewBaseArray(const DataType& elementType, const Generic* src, Bool move);

	//----------------------------------------------------------------------------------------
	/// Creates a new array of the given size which uses an internal BaseArray implementation. All elements will be in a single contiguous memory block
	/// and have default-initialized values.
	///
	/// The implementation has to obtain the container type from the given element type. In performance-critical code you should
	/// do that yourself outside of the performance-critical part and use the method NewBaseArrayFromContainerType.
	///
	/// @param[in] type								The element type of the array.
	/// @param[in] size								The initial size of the array.
	/// @param[in] flags							Flags for the initial resize operation.
	/// @return												Newly created array.
	//----------------------------------------------------------------------------------------
	static Result<Array<Generic>::NonConst> NewBaseArray(const DataType& type, Int size = 0, COLLECTION_RESIZE_FLAGS flags = COLLECTION_RESIZE_FLAGS::DEFAULT)
	{
		iferr_scope;
		Array<Generic>::NonConst res = NewBaseArray(type, nullptr, false) iferr_return;
		res.Resize(size, flags) iferr_return;
		return res;
	}

	//----------------------------------------------------------------------------------------
	/// Creates a new array which uses an internal BaseArray implementation. All elements will be in a single contiguous memory block.
	///
	/// This method requires to pass the container type instead of the element type, but it's faster than NewBaseArray.
	/// To obtain the container type from an element type, you can use this code:
	/// @code
	/// ContainerDataType<> t = ParametricTypes::ContainerInterface().Instantiate(elementType) iferr_return;
	///	@endcode
	///
	/// @param[in] containerType			The container type of the array.
	/// @param[in] src								A pointer to a BaseArray<T> where T matches the array's element type.
	/// 															This will be used to initialize the new array by copying or moving the elements.
	/// 															If src is nullptr, the new array will be empty.
	/// @param[in] move								If true, src will be moved into the new array. Note that this has to make a const_cast of the src parameter.
	/// @return												Newly created array.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Array<Generic>::NonConst> NewBaseArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* src, Bool move);


	//----------------------------------------------------------------------------------------
	/// Creates a new array which uses an internal BaseArray implementation. All elements will be in a single contiguous memory block.
	/// @tparam T											Element type of the array to create.
	/// @return												Newly created array.
	//----------------------------------------------------------------------------------------
	template <typename T> static Result<typename Array<T>::NonConst> NewBaseArray()
	{
		iferr_scope;
		Array<Generic>::NonConst res = NewBaseArrayFromContainerType(maxon::GetDataType<ContainerInterface<T>>(), nullptr, false) iferr_return;
		return std::move(reinterpret_cast<typename Array<T>::NonConst&>(res));
	}

	//----------------------------------------------------------------------------------------
	/// Creates a new array which uses an internal BaseArray implementation and is copy-initialized from src. All elements will be in a single contiguous memory block.
	/// @param[in] src								A BaseArray<T> to copy-initialize the new array.
	/// @tparam T											Element type of the array to create.
	/// @return												Newly created array.
	//----------------------------------------------------------------------------------------
	template <typename T> static Result<typename Array<T>::NonConst> NewBaseArray(const BaseArray<T>& src)
	{
		iferr_scope;
		Array<Generic>::NonConst res = NewBaseArrayFromContainerType(maxon::GetDataType<ContainerInterface<T>>(), reinterpret_cast<const Generic*>(&src), false) iferr_return;
		return std::move(reinterpret_cast<typename Array<T>::NonConst&>(res));
	}

	//----------------------------------------------------------------------------------------
	/// Creates a new array which uses an internal BaseArray implementation and is move-initialized from src. All elements will be in a single contiguous memory block.
	/// @param[in] src								A BaseArray<T> to move-initialize the new array.
	/// @tparam T											Element type of the array to create.
	/// @return												Newly created array.
	//----------------------------------------------------------------------------------------
	template <typename T> static Result<typename Array<T>::NonConst> NewBaseArray(BaseArray<T>&& src)
	{
		iferr_scope;
		Array<Generic>::NonConst res = NewBaseArrayFromContainerType(maxon::GetDataType<ContainerInterface<T>>(), reinterpret_cast<const Generic*>(&src), true) iferr_return;
		return std::move(reinterpret_cast<typename Array<T>::NonConst&>(res));
	}


	//----------------------------------------------------------------------------------------
	/// Creates a new array which uses an internal BlockArray implementation. Not all element types are supported.
	/// You can use NewPagedArray for a similar implementation which has the possibility to share copy-on-write blocks
	/// among several arrays.
	///
	/// @param[in] elementType				The element type of the array. Not all element types are supported.
	/// @param[in] src								A pointer to a BlockArray<T> where T matches the given element type.
	/// 															This will be used to initialize the new array by copying or moving the elements.
	/// 															If src is nullptr, the new array will be empty.
	/// @param[in] move								If true, src will be moved into the new array. Note that this has to make a const_cast of the src parameter.
	/// @return												Newly created array.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Array<Generic>::NonConst> NewBlockArray(const DataType& elementType, const Generic* src, Bool move);

	//----------------------------------------------------------------------------------------
	/// Creates a new array which uses an internal BlockArray implementation. Not all element types are supported.
	/// You can use NewPagedArray for a similar implementation which has the possibility to share copy-on-write blocks
	/// among several arrays.
	///
	/// @tparam T											Element type of the array to create. Not all element types are supported.
	/// @return												Newly created array.
	//----------------------------------------------------------------------------------------
	template <typename T> static Result<typename Array<T>::NonConst> NewBlockArray()
	{
		iferr_scope;
		Array<Generic>::NonConst res = NewBlockArray(maxon::GetDataType<T>(), nullptr, false) iferr_return;
		return std::move(reinterpret_cast<typename Array<T>::NonConst&>(res));
	}

	//----------------------------------------------------------------------------------------
	/// Creates a new array which uses an internal implementation based on copy-on-write pages, see NewPagedArray.
	/// You can use this overload when you don't want to provide a base array for default values but just a single default value.
	///
	/// The implementation has to obtain the container type from the given element type. In performance-critical code you should
	/// do that yourself outside of the performance-critical part and use the method NewBaseArrayFromContainerType.
	///
	/// @param[in] elementType				The element type of the array.
	/// @param[in] defaultValue				A pointer to a value of the given element type. This will be used as default value for non-existing pages.
	/// 															If this is nullptr, the null value of the element type will be used.
	/// @param[in] useRefCountForDefault	If true, defaultValue will be held by a strong reference internally. In this case the reference count
	/// 															has to be at least 1 when you call the method.
	/// @return												Newly created paged array.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Array<Generic>::NonConst> NewPagedArray(const DataType& elementType, const Generic* defaultValue = nullptr, Bool useRefCountForDefault = false);

	//----------------------------------------------------------------------------------------
	/// Creates a new array which uses an internal implementation based on copy-on-write pages, see NewPagedArray.
	/// You can use this overload when you don't want to provide a base array for default values but just a single default value.
	///
	/// This method requires to pass the container type instead of the element type, but it's faster than NewPagedArray.
	/// To obtain the container type from an element type, you can use this code:
	/// @code
	/// ContainerDataType<> t = ParametricTypes::ContainerInterface().Instantiate(elementType) iferr_return;
	///	@endcode
	///
	/// @param[in] containerType			The container type of the array.
	/// @param[in] defaultValue				A pointer to a value of the given element type. This will be used as default value for non-existing pages.
	/// 															If this is nullptr, the null value of the element type will be used.
	/// @param[in] useRefCountForDefault	If true, defaultValue will be held by a strong reference internally. In this case the reference count
	/// 															has to be at least 1 when you call the method.
	/// @return												Newly created paged array.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Array<Generic>::NonConst> NewPagedArrayFromContainerType(const ContainerDataType<>& containerType, const Generic* defaultValue = nullptr, Bool useRefCountForDefault = false);


	//----------------------------------------------------------------------------------------
	/// Creates a new array which uses an internal implementation based on copy-on-write pages, see NewPagedArray.
	/// @tparam T											Element type of the array to create.
	/// @return												Newly created paged array.
	//----------------------------------------------------------------------------------------
	template <typename T> static Result<typename Array<T>::NonConst> NewPagedArray()
	{
		iferr_scope;
		Array<Generic>::NonConst res = NewPagedArrayFromContainerType(maxon::GetDataType<ContainerInterface<T>>(), reinterpret_cast<const Generic*>(&NullValue<const T&>()), false) iferr_return;
		return std::move(reinterpret_cast<typename Array<T>::NonConst&>(res));
	}


	//----------------------------------------------------------------------------------------
	/// Creates a new array which is a slice (or even an extension) of a given base array.
	///
	/// For a usual slice start and end index are within the index range of the underlying base array.
	/// E.g. if the base array has the four elements ABCD, start is 1 and end is 3, the slice has two elements BC.
	///
	/// But you can also extend the base array at its ends. If we change start to -2 and end to 9 in the previous example,
	/// there are two extra elements before the base array and 5 behind. The extra elements are filled as follows:
	/// - If cycle is true, the base array is repeated, so in the example we get the elements CDABCDABCDA.
	/// - Otherwise, if there's a default value, this is used, so in the example we get XXABCDXXXXX where X is the default value.
	/// - Otherwise the first and last element of the base are repeated, so we get AAABCDDDDDD.
	///
	/// @param[in] base								The base array from where elements shall be obtained.
	/// @param[in] start							The start index within base (inclusive), can be negative.
	/// @param[in] end								The end index within base (exclusive), can be larger than the size of base.
	/// @param[in] cycle							True if the base array shall be repeated to obtain values outside of the original index range of the base.
	/// @param[in] defaultValue				A pointer to a value of the given element type. This will be used as default value for indices outside of the original index range of the base.
	/// 															If this is nullptr, the first and last element of the base are repeated for indices outside of the original index range of the base.
	/// @param[in] useRefCountForDefault	If true, defaultValue will be held by a strong reference internally. In this case the reference count
	/// 															has to be at least 1 when you call the method.
	/// @return												Newly created sliced array.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Array<Generic>> Slice(const Array<Generic>& base, Int start, Int end, Bool cycle, const Generic* defaultValue = nullptr, Bool useRefCountForDefault = false);

	//----------------------------------------------------------------------------------------
	/// Creates a new array which is a slice of a given base array, see Slice.
	///
	/// @param[in] base								The base array from where elements shall be obtained.
	/// @param[in] start							The start index within base (inclusive), has to be within the index range of base.
	/// @param[in] end								The end index within base (exclusive), has to be within the index range of base.
	/// @return												Newly created sliced array.
	//----------------------------------------------------------------------------------------
	template <typename T> static Result<Array<T>> Slice(const Array<T>& base, Int start, Int end)
	{
		iferr_scope;
		CheckArgument(start >= 0 && start <= end && end <= base.GetCount());
		Array<Generic> res;
		if (base.IsPopulated())
		{
			res = Slice(reinterpret_cast<const Array<Generic>&>(base), start, end, false) iferr_return;
		}
		return std::move(reinterpret_cast<Array<T>&>(res));
	}

	//----------------------------------------------------------------------------------------
	/// Creates a new array which is a slice (or even an extension) of a given base array, see Slice.
	///
	/// @param[in] base								The base array from where elements shall be obtained.
	/// @param[in] start							The start index within base (inclusive), can be negative.
	/// @param[in] end								The end index within base (exclusive), can be larger than the size of base.
	/// @param[in] cycle							True if the base array shall be repeated to obtain values outside of the original index range of the base.
	/// @param[in] defaultValue				A pointer to a value of the given element type. This will be used as default value for indices outside of the original index range of the base.
	/// 															If this is nullptr, the first and last element of the base are repeated for indices outside of the original index range of the base.
	/// @param[in] useRefCountForDefault	If true, defaultValue will be held by a strong reference internally. In this case the reference count
	/// 															has to be at least 1 when you call the method.
	/// @tparam T											Element type of the array to create.
	/// @return												Newly created sliced array.
	//----------------------------------------------------------------------------------------
	template <typename T> static Result<Array<T>> Slice(const Array<T>& base, Int start, Int end, Bool cycle, const T* defaultValue = nullptr, Bool useRefCountForDefault = false)
	{
		iferr_scope;
		CheckArgument(base.IsPopulated() && start <= end);
		Array<Generic> res = Slice(reinterpret_cast<const Array<Generic>&>(base), start, end, cycle, reinterpret_cast<const Generic*>(defaultValue), useRefCountForDefault) iferr_return;
		return std::move(reinterpret_cast<Array<T>&>(res));
	}


	//----------------------------------------------------------------------------------------
	/// Creates a new array where all elements have the same single value. This saves memory because only a single element has to be allocated.
	///
	/// To improve performance you can pass the array's container type to the optional parameter containerType.
	/// To obtain the container type from an element type, you can use this code:
	/// @code
	/// ContainerDataType<> t = ParametricTypes::ContainerInterface().Instantiate(elementType) iferr_return;
	///	@endcode
	///
	/// @param[in] value							The value to use for the array.
	/// @param[in] count							The size of the array. The value will be repeated count times, but without the need to make an allocation for that many elements.
	/// @param[in] containerType			The container type of the array. Can be a null reference, then the container type will be constructed from the value's type.
	/// @return												Newly created array.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Array<Generic>> NewSingleValueArray(const ConstDataPtr& value, Int count, const ContainerDataType<>& containerType = GetPtrSizedZeroRef<ContainerDataType<>>());

	//----------------------------------------------------------------------------------------
	/// Creates a new array where all elements have the same single value. This saves memory because only a single element has to be allocated.
	/// @param[in] value							The value to use for the array.
	/// @param[in] count							The size of the array. The value will be repeated count times, but without the need to make an allocation for that many elements.
	/// @tparam T											Element type of the array to create.
	/// @return												Newly created array.
	//----------------------------------------------------------------------------------------
	template <typename T> static Result<Array<T>> NewSingleValueArray(const T& value, Int count)
	{
		iferr_scope;
		Array<Generic> res = NewSingleValueArray(ConstDataPtr(value), count, maxon::GetDataType<ContainerInterface<T>>()) iferr_return;
		return std::move(reinterpret_cast<Array<T>&>(res));
	}


	//----------------------------------------------------------------------------------------
	/// Creates a new array where the elements are members of the elements of an underlying array.
	/// For example if the underlying array has elements of type Vector, you can extract
	/// the x, y and z members as arrays without the need to allocate memory for the extracted elements,
	/// because the memory of the underlying array will be used. You'd have to pass 0, sizeof(Float),
	/// or 2*sizeof(Float) to the offset parameter for x, y or z, respectively.
	/// From a Vector array you could also extract xy or yz as a Vector2d array, but not xz due to the memory layout of the Vector class.
	///
	/// The method expects the container type of the new array as parameter.
	/// To obtain the container type from an element type, you can use this code:
	/// @code
	/// ContainerDataType<> t = ParametricTypes::ContainerInterface().Instantiate(elementType) iferr_return;
	///	@endcode
	///
	/// @param[in] base								The base array from where elements shall be obtained.
	/// @param[in] offset							The offset (in bytes) of the member within the element type of the base array.
	/// @param[in] containerType			The container type of the array.
	/// @return												Newly created array.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Array<Generic>> ExtractMember(const Array<Generic>& base, Int offset, const ContainerDataType<>& containerType);

	//----------------------------------------------------------------------------------------
	/// Creates a new array where the elements are members of the elements of an underlying array, see ExtractMember.
	///
	/// @param[in] base								The base array from where elements shall be obtained.
	/// @param[in] offset							The offset (in bytes) of the member within the element type of the base array.
	/// @tparam DST										Type of the member.
	/// @tparam SRC										Element type of the base array. Usually this template parameter is deduced by the compiler.
	/// @return												Newly created array.
	//----------------------------------------------------------------------------------------
	template <typename DST, typename SRC> static Result<Array<DST>> ExtractMember(const Array<SRC>& base, Int offset)
	{
		iferr_scope;
		Array<Generic> dst = ExtractMember(reinterpret_cast<const Array<Generic>&>(base), offset, maxon::GetDataType<ContainerInterface<DST>>()) iferr_return;
		return std::move(reinterpret_cast<Array<DST>&>(dst));
	}

	//----------------------------------------------------------------------------------------
	/// Creates a new array where the elements are taken from an underlying array, but interpreted as a different type.
	/// The types have to be compatible regarding their memory layout, constructors and destructors. For example
	/// Vector and Color or ObjectRef and InputStreamRef are compatible, but ObjectRef and ObjectInterface* aren't.
	/// No new memory for the elements will be allocated.
	///
	/// The returned new array will hold a strong reference on the base array unless the base is a @ref NewPagedArray "paged array":
	/// Then a clone of the base is returned (so that pages are shared) but with the new type.
	///
	/// If you want to reinterpret array elements when memory layout is compatible, but constructors or destructors
	/// aren't (such as for the case ObjectRef and ObjectInterface*), you can use the ExtractMember method
	/// with an offset of 0.
	///
	/// The method expects the container type of the new array as parameter.
	/// To obtain the container type from an element type, you can use this code:
	/// @code
	/// ContainerDataType<> t = ParametricTypes::ContainerInterface().Instantiate(elementType) iferr_return;
	///	@endcode
	///
	/// @param[in] base								The base array from where elements shall be obtained.
	/// @param[in] containerType			The container type of the array.
	/// @return												Newly created array.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Array<Generic>> Reinterpret(const Array<Generic>& base, const ContainerDataType<>& containerType);

	//----------------------------------------------------------------------------------------
	/// Creates a new array where the elements are taken from an underlying array, but interpreted as a different type, see Reinterpret.
	///
	/// @param[in] base								The base array from where elements shall be obtained.
	/// @tparam DST										Element type of the array to create.
	/// @tparam SRC										Element type of the base array. Usually this template parameter is deduced by the compiler.
	/// @return												Newly created array.
	//----------------------------------------------------------------------------------------
	template <typename DST, typename SRC> static Result<Array<DST>> Reinterpret(const Array<SRC>& base)
	{
		iferr_scope;
		static_assert(SIZEOF(DST) == SIZEOF(SRC), "Sizes of SRC and DST have to match.");
		Array<Generic> dst = Reinterpret(reinterpret_cast<const Array<Generic>&>(base), maxon::GetDataType<ContainerInterface<DST>>()) iferr_return;
		return std::move(reinterpret_cast<Array<DST>&>(dst));
	}

	//----------------------------------------------------------------------------------------
	/// Creates a new array which uses an internal implementation based on copy-on-write pages. This implementation has the following features:
	/// - The array elements are stored in pages of fixed size.
	/// - Pages are copy-on-write, which means that they can be shared among several paged arrays (e.g. when you make a copy of a paged array).
	/// - Pages are allocated when needed for write access. Whenever there is no page yet for a read access to an index range,
	///   an underlying base array is used instead,
	///   or a default element value. Thus paged arrays can be used for sparse arrays.
	///
	/// @warning
	/// In general write access is NOT thread-safe because of the page management. However you can call the MakeElementsWritable method
	/// in advance to ensure that an index range is directly writable (no further need of page allocation). Afterwards write access to the index range is thread-safe.
	///
	/// @param[in] base								The base array from where elements shall be obtained when the paged array itself hasn't set values for the elements yet.
	/// @param[in] defaultValue				A pointer to a value of the given element type. This will be used as default value for non-existing pages.
	/// 															If this is nullptr, the null value of the element type will be used.
	/// @param[in] useRefCountForDefault	If true, defaultValue will be held by a strong reference internally. In this case the reference count
	/// 															has to be at least 1 when you call the method.
	/// @return												Newly created paged array.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Array<Generic>::NonConst> PrivateNewPagedArrayFromBase(const Array<Generic>& base, const Generic* defaultValue = nullptr, Bool useRefCountForDefault = false);

	//----------------------------------------------------------------------------------------
	/// Creates a new array which uses an internal implementation based on copy-on-write pages, see NewPagedArray.
	/// @param[in] base								The base array from where elements shall be obtained when the paged array itself hasn't set values for the elements yet.
	/// @tparam T											Element type of the array to create.
	/// @return												Newly created paged array.
	//----------------------------------------------------------------------------------------
	template <typename T> static Result<typename Array<T>::NonConst> PrivateNewPagedArrayFromBase(const Array<T>& base)
	{
		iferr_scope;
		Array<Generic>::NonConst res;
		if (base.IsPopulated())
		{
			res = PrivateNewPagedArrayFromBase(reinterpret_cast<const Array<Generic>&>(base), reinterpret_cast<const Generic*>(&NullValue<const T&>()), false) iferr_return;
		}
		else
		{
			res = NewPagedArrayFromContainerType(maxon::GetDataType<ContainerInterface<T>>(), reinterpret_cast<const Generic*>(&NullValue<const T&>()), false) iferr_return;
		}
		return std::move(reinterpret_cast<typename Array<T>::NonConst&>(res));
	}

	//----------------------------------------------------------------------------------------
	/// Converts the source array to an array which uses a single memory block with default stride.
	/// In other words, the block returned by @c{array.GetBlock(0, block)} represents the whole array.
	///
	/// If the source array already fulfills that condition, it is returned directly.
	///
	/// @param[in] source							The array to convert to single block array.
	/// @return												Converted array, it's guaranteed to consist of exactly one block.
	//----------------------------------------------------------------------------------------
	static MAXON_METHOD Result<Array<Generic>> ConvertToSingleBlock(const Array<Generic>& source);

	/// @copydoc ConvertToSingleBlock
	template <typename T> static Result<Array<T>> ConvertToSingleBlock(const Array<T>& source)
	{
		Result<Array<Generic>> res = ConvertToSingleBlock(reinterpret_cast<const Array<Generic>&>(source));
		return std::move(reinterpret_cast<Result<Array<T>>&>(res));
	}
};

namespace ParametricTypes
{
	MAXON_DECLARATION(ParametricType, ArrayInterface, "net.maxon.parametrictype.array");
};

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(ArrayInterface<T>**, OverloadRank0)
{
	iferr_scope;
	DataType t = CheckedGetDataType<T, POLICY>::Get() iferr_return;
	return ParametricTypes::ArrayInterface().Instantiate(t);
}

#include "array2.hxx"

namespace details
{

inline void FreeArrayIteratorPersistentId(PersistentIdBuffer* idBuffer, const PersistentIdGeneratorInterface* ig)
{
	iferr_scope;
	if (MAXON_UNLIKELY(idBuffer))
	{
		if (MAXON_UNLIKELY(ig))
		{
			ig->FreeBuffer(*idBuffer);
		}
		else
		{
			DebugAssert(idBuffer->IsPopulated());
			idBuffer->Pop();
		}
	}
}

inline Result<void> MoveArrayIteratorPersistentId(Int index, PersistentIdBuffer* idBuffer, const PersistentIdGeneratorInterface* ig)
{
	iferr_scope;
	if (MAXON_UNLIKELY(idBuffer))
	{
		if (MAXON_UNLIKELY(ig))
		{
			ig->Move(index, *idBuffer) iferr_return;
		}
		else
		{
			DebugAssert(idBuffer->IsPopulated());
			*(idBuffer->End()-1) = index;
		}
	}
	return OK;
}

template <Bool RANDOM_ACCESS, Bool LOAD_ELEMENTS, typename ARRAY> inline Result<Int> ValidateArrayIterator(const ARRAY& array, Int index, ViewIteratorMember* members, const MemberMap* map, Int* state, PersistentIdBuffer* idBuffer, const PersistentIdGeneratorInterface* ig)
{
	iferr_scope;
	if (index >= array.GetCount())
	{
		if (MAXON_UNLIKELY(idBuffer))
			maxon::details::FreeArrayIteratorPersistentId(idBuffer, ig);
		return -1;
	}

	Int blockEnd = LIMIT<Int>::MAX;

	SimdBlock<const Generic> block;
	// Don't use range-based for-loop to avoid warning about unused variable in release configuration.
	for (Int i = map->count - 1; i >= 0; --i)
	{
		DebugAssert(map->members[i] == 0);
		if (RANDOM_ACCESS || (index >= *state))
		{
			Int bs = array.GetBlock(index, reinterpret_cast<SimdBlock<const typename ARRAY::ValueType>&>(block));
			members->value = &block[index - bs];
			if (LOAD_ELEMENTS)
			{
				members->SetNoIndexing();
			}
			else
			{
				members->SetIndexing(block);
				*state = bs + block.GetCount();
			}
		}
		if (!LOAD_ELEMENTS)
		{
			SetMin(blockEnd, *state);
			++state;
		}
		++members;
	}
	DebugAssert(LOAD_ELEMENTS || (blockEnd > 0 && blockEnd < LIMIT<Int>::MAX));

	MoveArrayIteratorPersistentId(index, idBuffer, ig) iferr_return;

	return blockEnd;
}

inline Result<void> InitArrayIteratorPersistentId(PersistentIdBuffer* idBuffer, const PersistentIdGeneratorInterface* ig)
{
	iferr_scope;
	if (MAXON_UNLIKELY(idBuffer))
	{
		if (MAXON_UNLIKELY(ig))
		{
			ig->InitializeBuffer(*idBuffer) iferr_return;
		}
		else
		{
			idBuffer->Append(0) iferr_return;
		}
	}
	return OK;
}

template <typename ARRAY> inline Result<Int> InitArrayIterator(const ARRAY& array, ViewIteratorMember* members, const MemberMap* map, Int* state, PersistentIdBuffer* idBuffer, const PersistentIdGeneratorInterface* ig)
{
	iferr_scope;
	if (array.GetCount() == 0)
	{
		return -1;
	}

	SimdBlock<const Generic> block;
	Int blockEnd = LIMIT<Int>::MAX;
	Int* ends = (Int*) state;

	// Don't use range-based for-loop to avoid warning about unused variable in release configuration.
	for (Int i = map->count - 1; i >= 0; --i)
	{
		DebugAssert(map->members[i] == 0);
		MAXON_IF_TARGET_DEBUG(Int bs =, ) array.GetBlock(0, reinterpret_cast<SimdBlock<const typename ARRAY::ValueType>&>(block));
		DebugAssert(bs == 0);
		members->value = block.GetFirst();
		members->SetIndexing(block);
		Int endIndex = block.GetCount();
		SetMin(blockEnd, endIndex);
		*(ends++) = endIndex;
		++members;
	}

	DebugAssert(blockEnd > 0 && blockEnd < LIMIT<Int>::MAX);

	InitArrayIteratorPersistentId(idBuffer, ig) iferr_return;

	return blockEnd;
}

inline Result<void> AdvanceArrayIteratorPersistentId(Int index, PersistentIdBuffer& idBuffer, const PersistentIdGeneratorInterface* ig)
{
	iferr_scope;
	if (MAXON_UNLIKELY(ig))
	{
		ig->Advance(index, idBuffer) iferr_return;
	}
	else
	{
		DebugAssert(idBuffer.IsPopulated());
		*(idBuffer.End()-1) = index;
	}
	return OK;
}

}

template <typename ARRAY> class ArrayCloneHelper;

// This class is used to represent standard arrays from the MAXON API by the ArrayInterface interface. The compiler converts those arrays to ArrayImpl which is an implementation of ArrayInterface.
template <typename ARRAY> class ArrayImpl
	: public std::conditional<STD_IS_REPLACEMENT(const, typename std::remove_reference<ARRAY>::type) || !STD_IS_REPLACEMENT(reference, ARRAY),
														ArrayInterface<typename ConstIf<typename std::remove_reference<ARRAY>::type::ValueType, STD_IS_REPLACEMENT(const, typename std::remove_reference<ARRAY>::type)>::type>,
														NonConstArray<typename std::remove_reference<ARRAY>::type::ValueType>>::type
{
public:
	using ArrayType = typename std::decay<ARRAY>::type;
	static const Bool CONSTARRAY = STD_IS_REPLACEMENT(const, typename std::remove_reference<ARRAY>::type);
	static const Bool REFERENCE = STD_IS_REPLACEMENT(reference, ARRAY);
	using ValueType = typename ConstIf<typename ArrayType::ValueType, CONSTARRAY>::type;
	using NonConstValueType = typename std::remove_const<ValueType>::type;
	using Super = typename std::conditional<CONSTARRAY || !REFERENCE, ArrayInterface<ValueType>, NonConstArray<ValueType>>::type;
	using Interface = typename Super::Interface;
	MAXON_IMPLEMENTATION_SIMPLE(ArrayImpl);

	ArrayImpl() : Super(_clsMTable) { }
#ifndef CPP_853_HACK
	explicit ArrayImpl(ARRAY&& array) : Super(_clsMTable), _array(std::forward<ARRAY>(array))
	{
	}

	ArrayImpl(ArrayImpl&& src) : Super(_clsMTable), _array(static_cast<ARRAY&&>(src._array))
	{
// src might be on the stack
//		DebugAssert(System::GetReferenceCounter(&src) == 0);
	}
#else
	explicit ArrayImpl(typename std::conditional<!REFERENCE, ARRAY, DummyParamType>::type&& array) : Super(_clsMTable), _array(std::forward<ARRAY>(array))
	{
		this->_refDummy = &array;
	}

	// MSVC bug workaround: MSVC 1916 only reserves space on stack for base class ArrayInterface, but not for ArrayImpl when the conversion function
	// of collection.h is used. Therefore the additional ArrayImpl member _array must not be accessed.
	explicit ArrayImpl(typename std::conditional<REFERENCE, ARRAY, DummyParamType>::type&& array) : Super(_clsMTable)
	{
		this->_refDummy = &array;
	}
	ArrayImpl(ArrayImpl&& src) : Super(_clsMTable)
	{
		this->_refDummy = src._refDummy;
		CopyArrayMember(_array, src._array);
	}

	#define _array GetArray()
#endif

	const ContainerDataType<>& GetContainerType() const
	{
		return NamedTuple<NonConstValueType>::GetContainerType();
	}

	GenericContainerInterface::INTERFACES GetInterfaces() const
	{
		return GenericContainerInterface::INTERFACES::STATIC_ARRAY | GenericContainerInterface::INTERFACES::ARRAY
			| GenericContainerInterface::INTERFACES::INDEXABLE
			| ConditionalFlag(ArrayType::IsBaseArray::value, GenericContainerInterface::INTERFACES::BASE_ARRAY);
	}

	Int FindMemberIndex(const InternedId& name) const
	{
		return 0;
	}

	Int GetIteratorStateSize(const MemberMap* map) const
	{
		// An Int for each member.
		return map->count * SIZEOF(Int);
	}

	Result<Int> InitIterator(ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer, Bool constAccess) const
	{
		return maxon::details::InitArrayIterator(*this, members, map, reinterpret_cast<Int*>(state), idBuffer, nullptr);
	}

	Result<Int> ValidateIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const
	{
		return maxon::details::ValidateArrayIterator<false, false>(*this, index, members, map, reinterpret_cast<Int*>(state), idBuffer, nullptr);
	}

	void FreeIterator(ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const
	{
		maxon::details::FreeArrayIteratorPersistentId(idBuffer, nullptr);
	}

	Result<Int> MoveIterator(Int index, ViewIteratorMember* members, const MemberMap* map, Char* state, PersistentIdBuffer* idBuffer) const
	{
		return maxon::details::ValidateArrayIterator<true, false>(*this, index, members, map, reinterpret_cast<Int*>(state), idBuffer, nullptr);
	}

	Result<void> AdvancePersistentId(Int index, const Char* state, PersistentIdBuffer& idBuffer) const
	{
		return maxon::details::AdvanceArrayIteratorPersistentId(index, idBuffer, nullptr);
	}

	Result<void> PrivateInsert(Int index, const StridedBlock<const ValueType>& values, Bool move, COLLECTION_RESIZE_FLAGS resizeFlags)
	{
		return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::NOT_IMPLEMENTED);
	}

	const PersistentIdGenerator& GetPersistentIdGenerator() const
	{
		return GetPtrSizedZeroRef<PersistentIdGenerator>();
	}

	void SetPersistentIdGenerator(const PersistentIdGenerator& generator)
	{
		DebugStop("Function not implemented.");
	}

	Result<void> MakeElementsWritable(Int start, Int end, Bool copyElements)
	{
		return OK;
	}

	ResultRef<ValueType> Insert(Int index)
	{
		if (CONSTARRAY)
			return nullptr;
		return ((ArrayType*) &_array)->Insert(index);
	}

	ResultMem Insert(Int index, const Block<const ValueType>& values)
	{
		if (CONSTARRAY)
			return FAILED;
		return ResultMem(((ArrayType*) &_array)->InsertBlock(index, values) == OK);
	}

	ResultMem Insert(Int index, const MoveBlock<ValueType>& values)
	{
		if (CONSTARRAY)
			return FAILED;
		return ResultMem(((ArrayType*) &_array)->InsertBlock(index, values) == OK);
	}

	ResultRef<ValueType> Append()
	{
		if (CONSTARRAY)
			return nullptr;
		return ((ArrayType*) &_array)->Append();
	}

	ResultRef<ValueType> Append(const ValueType& data)
	{
		ValueType* newData = Append().GetPointer();
		if (!newData)
			return nullptr;
		*newData = data;
		return newData;
	}

	ResultRef<ValueType> Append(NonConstValueType&& data)
	{
		ValueType* newData = Append().GetPointer();
		if (!newData)
			return nullptr;
		*newData = std::move(data);
		return newData;
	}

	ResultMem Erase(Int index, Int count)
	{
		if (CONSTARRAY)
			return FAILED;

		if (((ArrayType*) &_array)->Erase(index, count) == FAILED)
			return FAILED;
		return OK;
	}

	ResultMem SwapErase(Int index, Int count)
	{
		if (CONSTARRAY)
			return FAILED;
		return ((ArrayType*) &_array)->SwapErase(index, count);
	}

	Int GetCount() const
	{
		return _array.GetCount();
	}

	const ValueType& operator [](Int index) const
	{
		return _array[index];
	}

	ResultRef<ValueType> GetWritable(Int index)
	{
		return const_cast<ValueType&>(_array[index]);
	}

	Int GetBlock(Int index, SimdBlock<const ValueType>& block) const
	{
		Block<const ValueType> b;
		Int bs = _array.GetBlock(index, b);
		block.ToBlock().Set(b.GetFirst(), b.GetCount(), b.GetStride());
		block.ResetSimdIndexing();
		return bs;
	}

	Result<Int> GetBlock(Int index, SimdBlock<NonConstValueType>& block)
	{
		return GetBlock(index, reinterpret_cast<SimdBlock<const ValueType>&>(block));
	}

	Int GetBlock(Int index, Block<const ValueType>& block) const
	{
		return _array.GetBlock(index, block);
	}

	Int GetBlock(Int index, Block<NonConstValueType>& block)
	{
		return _array.GetBlock(index, reinterpret_cast<Block<const ValueType>&>(block));
	}

	ResultMem Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::DEFAULT)
	{
		if (CONSTARRAY)
			return FAILED;
		return ((ArrayType*) &_array)->Resize(count, resizeFlags);
	}

	ResultMem SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY)
	{
		if (CONSTARRAY)
			return FAILED;
		return ((ArrayType*) &_array)->SetCapacityHint(requestedCapacity, resizeFlags);
	}

	Result<void> CopyFrom(const ArrayInterface<ValueType>& other)
	{
		if (CONSTARRAY)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::NOT_IMPLEMENTED);
		return ((ArrayType*) &_array)->CopyFrom(*((ArrayType*) &static_cast<const ArrayImpl&>(other)._array));
	};

	Result<GenericContainerInterface*> MakeWritable(Bool copyContent) const
	{
		if (MAXON_LIKELY(!StrongCOWRefHandler::GetReferenceCounter(this).HasMultipleReferences()))
		{
			return const_cast<GenericContainerInterface*>(static_cast<const GenericContainerInterface*>(this));
		}

		iferr (ArrayImpl* c = ArrayCloneHelper<ARRAY>::New())
			return err;
		if (copyContent)
		{
			iferr (((ArrayType*) &c->_array)->CopyFrom(*(ArrayType*) &_array))
			{
				DeleteObj(c);
				return err;
			}
		}
		return c;
	}

	String ToString(const FormatStatement* formatStatement = nullptr) const { return GlobalToString(_array, formatStatement); }

	Int GetMemorySize() const { return _array.GetMemorySize() + (SIZEOF(ArrayImpl) - SIZEOF(ARRAY)); }

	const DataType& GetValueDataType() const
	{
		return GetDataType<typename std::remove_const<ValueType>::type, GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN>();
	}

	void Reset()
	{
		if (CONSTARRAY)
			return;
		((ArrayType*) &_array)->Reset();
	}

	void Flush()
	{
		if (CONSTARRAY)
			return;
		((ArrayType*) &_array)->Flush();
	}

	Bool IsEqual(const GenericContainerInterface* o, EQUALITY equality) const
	{
		if (this == o)
			return true;
		if (!o)
			return GetCount() == 0;
		if (!(o->GetInterfaces() & GenericContainerInterface::INTERFACES::STATIC_ARRAY))
			return false;
		const StaticArrayInterface<ValueType>* other = static_cast<const StaticArrayInterface<ValueType>*>(o);
		if (GetCount() != other->GetCount())
			return false;
		if (!GetValueDataType().IsSimilar(other->GetValueDataType()))
			return false;
		auto thisIt = this->Begin();
		if (equality == EQUALITY::DEEP)
		{
			for (const StridedBlock<const ValueType>& b : other->GetStridedBlocks())
			{
				for (const ValueType& x : b)
				{
					if (!CompareTemplate<true, EQUALITY::DEEP, OverloadRank1>::IsEqual(x, *thisIt))
						return false;
					++thisIt;
				}
			}
		}
		else
		{
			for (const StridedBlock<const ValueType>& b : other->GetStridedBlocks())
			{
				for (const ValueType& x : b)
				{
					if (!CompareTemplate<true>::IsEqual(x, *thisIt))
						return false;
					++thisIt;
				}
			}
		}
		return true;
	}

	HashInt GetHashCode() const
	{
		DefaultHasher hash;
		for (const StridedBlock<const ValueType>& b : this->GetStridedBlocks())
		{
			for (const ValueType& x : b)
			{
				hash.Combine(CompareTemplate<true>::GetHashCode(x));
			}
		}
		return hash;
	}

	UniqueHash GetUniqueHashCode() const
	{
		UniqueHasher hash;
		for (const StridedBlock<const ValueType>& b : this->GetStridedBlocks())
		{
			b.template CombineUniqueHash<CompareTemplate<true>>(hash);
		}
		return hash;
	}

#ifdef CPP_853_HACK
	#undef _array

	typename std::add_lvalue_reference<ARRAY>::type GetArray() { return REFERENCE ? *(ArrayType*) this->_refDummy : GetImpl(_array); }

	const ArrayType& GetArray() const { return REFERENCE ? *(const ArrayType*) this->_refDummy : GetImpl(_array); }
#else
	typename std::add_lvalue_reference<ARRAY>::type GetArray() { return _array; }

	const ArrayType& GetArray() const { return _array; }
#endif

private:
	MAXON_DISALLOW_COPY_AND_ASSIGN(ArrayImpl);

#ifdef CPP_853_HACK
	typename std::conditional<REFERENCE, Bool, ARRAY>::type _array;

	template <typename T> static T& GetImpl(T& x)
	{
		return x;
	}

	static ArrayType& GetImpl(Bool)
	{
		return reinterpret_cast<ArrayType&>(g_writableMemory);
	}

	static void CopyArrayMember(ARRAY& dst, ARRAY& src)
	{
		dst = static_cast<ARRAY&&>(src);
	}

	static void CopyArrayMember(Bool, Bool)
	{
	}

#else
	ARRAY _array;
#endif
};


template <typename ARRAY> class ArrayCloneHelper
{
public:
	static ResultPtr<ArrayImpl<ARRAY>> New()
	{
		return NewObj(ArrayImpl<ARRAY>);
	}
};

template <typename ARRAY> class ArrayCloneHelper<ARRAY&>
{
public:
	static ResultPtr<ArrayImpl<ARRAY&>> New()
	{
		DebugStop("Can't clone ArrayImpl when the internal array is a reference!");
		return nullptr;
	}
};


template <typename ARRAY> MAXON_IMPLEMENTATION_SIMPLE_REGISTER(ArrayImpl<ARRAY>);


template <typename COLLECTION, typename VALUETYPE, typename SUPER, typename HASH> inline ArrayImpl<COLLECTION&> ArrayBase<COLLECTION, VALUETYPE, SUPER, HASH>::ToArray()
{
	return ArrayImpl<COLLECTION&>(*static_cast<COLLECTION*>(this));
}

template <typename COLLECTION, typename VALUETYPE, typename SUPER, typename HASH> inline ArrayImpl<const COLLECTION&> ArrayBase<COLLECTION, VALUETYPE, SUPER, HASH>::ToArray() const
{
	return ArrayImpl<const COLLECTION&>(*static_cast<const COLLECTION*>(this));
}

//----------------------------------------------------------------------------------------
/// Returns a pointer to the array reference argument. This function is useful if you have to
/// convert some array to a pointer to an ArrayInterface:
/// @code
/// void Func(const ArrayInterface<const Char>* array);
///
/// BlockArray<Char> myArray;
/// Func(ToArrayPtr(myArray));
/// @endcode
/// For WritableArrayInterface parameters, use ToWritableArrayPtr instead.
///
/// @see ArrayInterface.
///
/// @tparam T											Type of elements of the array, this is deduced by the compiler.
///
/// @note If the argument is a temporary (which usually is the case), the result will be a
/// pointer to a temporary. Make sure that the pointer is used only within the lifetime
/// of the temporary. For the above example, it suffices that Func uses the array only
/// during its execution.
//----------------------------------------------------------------------------------------
template <typename T> inline const ArrayInterface<T>* ToArrayPtr(const ArrayInterface<T>& array)
{
	return &array;
}

//----------------------------------------------------------------------------------------
/// Returns a pointer to the array reference argument. This function is useful if you have to
/// convert some array to a pointer to an ArrayInterface:
/// @code
/// void Func(WritableArrayInterface<const Char>* array);
///
/// BlockArray<Char> myArray;
/// Func(ToWritableArrayPtr(myArray));
/// @endcode
/// For non-modifiable array parameters, use ToArrayPtr instead.
///
/// @see ArrayInterface.
///
/// @tparam T											Type of elements of the array, this is deduced by the compiler.
///
/// @note If the argument is a temporary (which usually is the case), the result will be a
/// pointer to a temporary. Make sure that the pointer is used only within the lifetime
/// of the temporary. For the above example, it suffices that Func uses the array only
/// during its execution.
//----------------------------------------------------------------------------------------
template <typename T> inline WritableArrayInterface<T>* ToWritableArrayPtr(WritableArrayInterface<T>& array)
{
	return &array;
}

template <typename DEST, typename SRC> inline typename std::enable_if<GetCollectionKind<SRC>::value == COLLECTION_KIND::ARRAY, Result<void>>::type Data::SetImpl(SRC&& data, OverloadRank1)
{
	iferr_scope;
	using ArrayType = typename std::decay<SRC>::type;
	ArrayImpl<ArrayType>* a;
	if (STD_IS_REPLACEMENT(reference, SRC))
	{
		ArrayType copy;
		copy.CopyFrom(data) iferr_return;
		a = NewObj(ArrayImpl<ArrayType>, std::move(copy)) iferr_return;
	}
	else
	{
		a = NewObj(ArrayImpl<ArrayType>, std::move(const_cast<ArrayType&>(data))) iferr_return;
	}
	return SetImpl<void>(Array<typename std::conditional<std::is_void<DEST>::value, ArrayType, typename std::decay<DEST>::type>::type::ValueType>(a), (OverloadRank0) nullptr);
}

template <typename T> inline typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY, Result<T>>::type Data::GetImpl(OverloadRank1) const
{
	iferr_scope;
	const Array<typename T::ValueType>& a = Get<Array<typename T::ValueType>>() iferr_return;
	T array;
	array.CopyFrom(a) iferr_return;
	return std::move(array);
}

template <typename T> typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY, Result<T>>::type Data::GetImpl(OverloadRank1)
{
	iferr_scope;
	const Array<typename T::ValueType>& a = Get<Array<typename T::ValueType>>() iferr_return;
	T array;
	array.CopyFrom(a) iferr_return;
	return std::move(array);
}

template <typename T> inline typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY, Result<T>>::type ConstDataPtr::GetImpl(OverloadRank1) const
{
	iferr_scope;
	const Array<typename T::ValueType>& a = Get<Array<typename T::ValueType>>() iferr_return;
	T array;
	array.CopyFrom(a) iferr_return;
	return std::move(array);
}

template <typename T> class ConstDataPtr::Wrapper<T, typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY>::type> : public ConstDataPtr
{
public:
	Result<void> Init(const T& value)
	{
		iferr_scope;
		T copy;
		copy.CopyFrom(value) iferr_return;
		ArrayImpl<T>* a = NewObj(ArrayImpl<T>, std::move(copy)) iferr_return;
		_array = a;
		this->Set(_array);
		return OK;
	}

private:
	Array<typename T::ValueType> _array;
};


} // namespace maxon

#endif // ARRAY_H__
