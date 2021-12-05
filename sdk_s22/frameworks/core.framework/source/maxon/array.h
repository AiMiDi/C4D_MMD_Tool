#ifndef ARRAY_H__
#define ARRAY_H__

#include "maxon/string.h"
#include "maxon/datatype.h"

namespace maxon
{

template <typename TYPE> class StaticArrayInterface
{
# ifdef CPP_853_HACK // use space after # so that the source processor doesn't recognize those directives
	CPP_853_HACK_MAXON_INTERFACE_SIMPLE_VIRTUAL(StaticArrayInterface, MAXON_REFERENCE_COPY_ON_WRITE);
# else
	MAXON_INTERFACE_SIMPLE_VIRTUAL(StaticArrayInterface, MAXON_REFERENCE_COPY_ON_WRITE);
# endif
public:
	//----------------------------------------------------------------------------------------
	/// Gets the number of array elements.
	/// @return												Number of array elements.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetCount() const;

	/// @MAXON_ANNOTATION{default=true}
	MAXON_FUNCTION Bool IsEmpty() const
	{
		return GetCount() == 0;
	}

	MAXON_FUNCTION Bool IsPopulated() const
	{
		return GetCount() != 0;
	}

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

	template <typename T> MAXON_FUNCTION ResultMem Set(Int index, T&& value)
	{
		ResultRef<TYPE> x = GetWritable(index);
		if (x == FAILED)
			return false;
		return AssignCopyConvert(x.GetValue(), std::forward<T>(value)) == OK;
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
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<Int> GetWritableBlock(Int index, SimdBlock<TYPE>& block);

	//----------------------------------------------------------------------------------------
	/// Returns a writable copy of this array. This may return a different implementation of the
	/// interface if the current implementation only supports read-only access (for example an
	/// array implementation where all elements have the same value). If there's just a single
	/// reference to the array, the array itself may be returned.
	/// @param[in] cloneElements			True if also the elements shall be cloned, false otherwise (then just a new object with a writable implementation of ArrayInterface is created).
	/// @return												Pointer to the writable array object, nullptr if allocation or copying failed.
	/// @MAXON_ANNOTATION{refclass=false}
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<StaticArrayInterface*> MakeWritable(Bool cloneElements = true) const;

	//----------------------------------------------------------------------------------------
	/// Returns the data type of this array's elements. This may be nullptr if there is no
	/// DataType for the template parameter TYPE.
	/// @return												DataType of the elements or nullptr.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD const DataType& GetValueDataType() const;

	//----------------------------------------------------------------------------------------
	/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD String ToString(const FormatStatement* formatStatement) const;

	MAXON_METHOD Bool IsEqual(const StaticArrayInterface* other, EQUALITY equality) const;

	MAXON_METHOD UInt GetHashCode() const;

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

		explicit IteratorTemplate(CollectionType& a, Int start = 0) : _array(&a)
		{
			StridedBlock<Type> block;
			_blockStartIndex = _array->GetBlock(start, block);
			_blockStartPtr = block.GetFirst();
			_stride = block.GetStride();
			Int stride = GetStride();
			_indexPtr = (Type*)((Char*)_blockStartPtr + (start - _blockStartIndex) * stride);
			_blockEndPtr = (Type*)((Char*)_blockStartPtr + block.GetCount() * stride);
		}

		IteratorTemplate(const IteratorTemplate& src) = default;

		IteratorTemplate() : _indexPtr(nullptr) // it suffices to initialize _indexPtr for a null Iterator because only this is used for ==
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
			return *_indexPtr;
		}

		Type* operator ->() const
		{
			return _indexPtr;
		}

		Bool operator ==(const IteratorTemplate& b) const
		{
			return _indexPtr == b._indexPtr;
		}

		Bool operator <(const IteratorTemplate& b) const
		{
			return GetIndex() < b.GetIndex();
		}

		MAXON_OPERATOR_COMPARISON(IteratorTemplate);

		// prefix operator ++ (increment and fetch)
		IteratorTemplate& operator ++()
		{
			_indexPtr = (Type*)((Char*)_indexPtr + GetStride());
			if (MAXON_UNLIKELY(_indexPtr == _blockEndPtr))
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
			_indexPtr = (Type*)((Char*)_indexPtr + i * GetStride());
			ValidateBlock(true);
			return *this;
		}

		// prefix operator -- (decrement and fetch)
		IteratorTemplate& operator --()
		{
			_indexPtr = (Type*)((Char*)_indexPtr - GetStride());
			if (MAXON_UNLIKELY(_indexPtr < _blockStartPtr))
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
			_indexPtr = (Type*)((Char*)_indexPtr - i * GetStride());
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
			return GetIndex() - b.GetIndex();
		}

		Int GetIndex() const
		{
			return _blockStartIndex + ((Char*)_indexPtr - (Char*)_blockStartPtr) / GetStride();
		}

		Int GetBlock(StridedBlock<Type>& block) const
		{
			Int stride = GetStride();
			block.Set(_blockStartPtr, ((Char*)_blockEndPtr - (Char*)_blockStartPtr) / stride, stride);
			return _blockStartIndex;
		}

		Int GetBlock(Block<Type, false>& block) const
		{
			if (MAXON_LIKELY(GetStride() == sizeof(Type)))
			{
				block.Set(_blockStartPtr, (_blockEndPtr - _blockStartPtr));
				return _blockStartIndex;
			}
			else
			{
				block.Set(_indexPtr, 1);
				return GetIndex();
			}
		}

		// returns a pointer to the block which ensures that the next 'count' elements are in the same non-strided block and advances the iterator by count elements
		Type* FetchNonStridedBlock(Int count = 1)
		{
			DebugAssert(count > 0);
			Int stride = GetStride();
			if (MAXON_LIKELY((((Char*)_indexPtr + (count * stride)) <= (Char*)_blockEndPtr) && stride == sizeof(Type)))
			{
				Type* ptr = _indexPtr;
				_indexPtr += count;
				ValidateBlock(true);
				return ptr;
			}
			return nullptr;
		}

	private:
		void ValidateBlock(Bool check)
		{
			if (!check || MAXON_UNLIKELY((_indexPtr < _blockStartPtr) || (_indexPtr >= _blockEndPtr)))
			{
				StridedBlock<Type> block;
				Int index = _blockStartIndex + ((Char*)_indexPtr - (Char*)_blockStartPtr) / GetStride();
				_blockStartIndex = _array->GetBlock(index, block);
				_blockStartPtr = block.GetFirst();
				_stride = block.GetStride();
				Int stride = GetStride();
				_indexPtr = (Type*)((Char*)_blockStartPtr + (index - _blockStartIndex) * stride);
				_blockEndPtr = (Type*)((Char*)_blockStartPtr + block.GetCount() * stride);
			}
		}

		Int GetStride() const
		{
			return _stride;
		}

		CollectionType* _array;
		Type*	_indexPtr;
		Type* _blockStartPtr;
		Type* _blockEndPtr;
		Int _blockStartIndex;
		Int _stride;
	};

	using Iterator = IteratorTemplate<StaticArrayInterface>;
	using ConstIterator = IteratorTemplate<const StaticArrayInterface>;

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first array element.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION ConstIterator Begin() const
	{
		return ConstIterator(*static_cast<const StaticArrayInterface*>(this));
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first array element.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	Iterator Begin()
	{
		return Iterator(*static_cast<StaticArrayInterface*>(this));
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing one behind the last array element.
	/// @return												Iterator for the array end, this is one behind the last element.
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION ConstIterator End() const
	{
		return ConstIterator(*static_cast<const StaticArrayInterface*>(this), this->GetCount());
	}

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing one behind the last array element.
	/// @return												Iterator for the array end, this is one behind the last element.
	//----------------------------------------------------------------------------------------
	Iterator End()
	{
		return Iterator(*static_cast<StaticArrayInterface*>(this), this->GetCount());
	}

	using StaticArrayInterfaceMarker = void;

private:
	static StaticArrayInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return nullptr;
	}
};

// There's a specialization of the MakeWritable mechanism for arrays to allow for
// read-only implementations of the array interface (such as arrays where all elements are the same).
// These implementations need to create a new writable implementation even if there is just a single reference.
template <typename T> struct StrongCOWRefHandler::MakeWritableHelper<T, typename T::StaticArrayInterfaceMarker>
{
	template <typename R> static MAXON_ATTRIBUTE_FORCE_INLINE ResultRef<T> MakeWritable(R& ref, Bool resetOnError)
	{
		const T* orig = ref.GetPointer();
		T* o = const_cast<T*>(orig);
		if (MAXON_UNLIKELY(o == nullptr))
		{
			o = NewObj(T).GetPointer();
		}
		else
		{
			o = static_cast<T*>(o->MakeWritable(true) iferr_ignore("nullptr indicates error"));
			if (MAXON_LIKELY(o == orig))
				return o;
		}
		if (MAXON_LIKELY(resetOnError || o))
			ref.PrivateSetTarget(ResultPtr<typename R::ReferencedType>(o));
		DebugAssert(!o || (GetReferenceCounter(o) == 1));
		return o;
	}
};

template <typename TYPE> class VArrayInterface : public StaticArrayInterface<TYPE>
{
# ifdef CPP_853_HACK // use space after # so that the source processor doesn't recognize those directives
	CPP_853_HACK_MAXON_INTERFACE_SIMPLE_VIRTUAL_DERIVED(VArrayInterface, MAXON_REFERENCE_COPY_ON_WRITE);
# else
	MAXON_INTERFACE_SIMPLE_VIRTUAL_DERIVED(VArrayInterface, MAXON_REFERENCE_COPY_ON_WRITE);
# endif
public:
	//----------------------------------------------------------------------------------------
	/// For future compatibility, not implemented at the moment.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Result<void> PrivateInsert(Int index, const StridedBlock<const TYPE>& values, Bool move);

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
	template <typename T> MAXON_FUNCTION ResultRef<TYPE> Append(T&& value)
	{
		ResultRef<TYPE> x = Append();
		if (x == FAILED || AssignCopyConvert(x.GetValue(), std::forward<T>(value)) == FAILED)
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
	MAXON_METHOD Result<void> CopyFrom(const VArrayInterface& other);

private:
	static VArrayInterface* Alloc(MAXON_SOURCE_LOCATION_DECLARATION)
	{
		return nullptr;
	}

	friend class StrongCOWRefHandler;
};


template <typename TYPE> class NonConstArray;

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
template <typename TYPE> class ArrayInterface : public ArrayBase0<ArrayInterface<TYPE>, TYPE, VArrayInterface<TYPE>, DefaultCompare>
{

# ifdef CPP_853_HACK // use space after # so that the source processor doesn't recognize those directives
	CPP_853_HACK_MAXON_INTERFACE_SIMPLE_VIRTUAL_DERIVED(ArrayInterface, MAXON_REFERENCE_COPY_ON_WRITE);
# else
	MAXON_INTERFACE_SIMPLE_VIRTUAL_DERIVED(ArrayInterface, MAXON_REFERENCE_COPY_ON_WRITE);
# endif

public:
	using ValueType = TYPE;
	using Super = VArrayInterface<TYPE>;

	using Super::CopyFrom;
	using Super::IsEqual;
	using Super::GetHashCode;
	using Super::ToString;

	using Super::operator [];
	TYPE& operator [](Int index) { return MAXON_NONCONST_COUNTERPART(operator [](index)); }

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
	MAXON_METHOD Int GetBlock(Int index, Block<const TYPE, false>& block) const;

	Int GetBlock(Int index, Block<TYPE, false>& block)
	{
		return GetBlock(index, reinterpret_cast<Block<const TYPE, false>&>(block));
	}

	Int GetBlock(Int index, StridedBlock<const TYPE>& block) const
	{
		Block<const TYPE, false> b;
		Int bs = GetBlock(index, b);
		block.Set(b.GetFirst(), b.GetCount(), this->GetValueSize());
		return bs;
	}

	Int GetBlock(Int index, StridedBlock<TYPE>& block)
	{
		return GetBlock(index, reinterpret_cast<StridedBlock<const TYPE>&>(block));
	}

	//----------------------------------------------------------------------------------------
	/// Calculates the memory usage for this array.
	/// @return												Memory size in bytes.
	//----------------------------------------------------------------------------------------
	MAXON_METHOD Int GetMemorySize() const;

	template <typename T> MAXON_FUNCTION Bool HasType() const
	{
		return this->GetValueDataType() == maxon::GetDataType<T>();
	}

	//----------------------------------------------------------------------------------------
	/// Issues a failed DebugAssert if the DataType of this array doesn't match T. If T is Generic,
	/// no check happens.
	/// @tparam T											Type to check.
	//----------------------------------------------------------------------------------------
	template <typename T> MAXON_FUNCTION void AssertType() const
	{
#ifdef MAXON_TARGET_DEBUG
		if (!STD_IS_REPLACEMENT(same, Generic, T))
		{
			this->GetValueDataType().template AssertType<typename std::conditional<STD_IS_REPLACEMENT(same, Generic, T), Int, T>::type>();
		}
#endif
	}

	//----------------------------------------------------------------------------------------
	/// Casts this array to an array with elements of type T. If T doesn't match the actual data type of this
	/// array, a failed DebugAssert is issued. This function only makes sense when the original array
	/// uses Generic as its type.
	/// @tparam T											Element type of the destination array.
	/// @return												This array, cast to an ArrayInterface of T elements.
	//----------------------------------------------------------------------------------------
	template <typename T> ArrayInterface<T>& AssertCast()
	{
		AssertType<T>();
		return *reinterpret_cast<ArrayInterface<T>*>(this);
	}

	//----------------------------------------------------------------------------------------
	/// Casts this array to an array with elements of type T. If T doesn't match the actual data type of this
	/// array, a failed DebugAssert is issued. This function only makes sense when the original array
	/// uses Generic as its type.
	/// @tparam T											Element type of the destination array.
	/// @return												This array, cast to an ArrayInterface of T elements.
	//----------------------------------------------------------------------------------------
	template <typename T> const ArrayInterface<T>& AssertCast() const
	{
		AssertType<T>();
		return *reinterpret_cast<const ArrayInterface<T>*>(this);
	}

#ifdef MAXON_COMPILER_INTEL
#pragma warning disable 597
#endif
	operator const ArrayInterface<const TYPE>&() const
	{
		return *(ArrayInterface<const TYPE>*) this;
	}

	operator const ArrayInterface<typename std::conditional<STD_IS_REPLACEMENT(same, const TYPE, const Generic), const DummyReturnType, const Generic>::type>&() const
	{
		return *(ArrayInterface<typename std::conditional<STD_IS_REPLACEMENT(same, const TYPE, const Generic), const DummyReturnType, const Generic>::type>*) this;
	}

	operator ArrayInterface<typename std::conditional<STD_IS_REPLACEMENT(same, TYPE, Generic), DummyReturnType, Generic>::type>&()
	{
		return *(ArrayInterface<typename std::conditional<STD_IS_REPLACEMENT(same, TYPE, Generic), DummyReturnType, Generic>::type>*) this;
	}
#ifdef MAXON_COMPILER_INTEL
#pragma warning enable 597
#endif

	operator const NonConstArray<TYPE>&()
	{
		return *reinterpret_cast<const NonConstArray<TYPE>*>(this);
	}

	operator const NonConstArray<typename std::conditional<STD_IS_REPLACEMENT(same, TYPE, Generic), DummyReturnType, Generic>::type>&()
	{
		return *reinterpret_cast<const NonConstArray<typename std::conditional<STD_IS_REPLACEMENT(same, TYPE, Generic), DummyReturnType, Generic>::type>*>(this);
	}


	using Iterator = typename Super::template IteratorTemplate<ArrayInterface>;
	using ConstIterator = typename Super::template IteratorTemplate<const ArrayInterface>;

	//----------------------------------------------------------------------------------------
	/// Returns an iterator pointing to the first array element.
	/// @return												Iterator for the first element (equal to End() if the array is empty).
	//----------------------------------------------------------------------------------------
	MAXON_FUNCTION ConstIterator Begin() const
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
	MAXON_FUNCTION ConstIterator End() const
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
		: ArrayBase0<ArrayInterface<TYPE>, TYPE, VArrayInterface<TYPE>, DefaultCompare>(*reinterpret_cast<const typename VArrayInterface<TYPE>::MTable*>(src._vtable)), _refDummy(src._refDummy)
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
		return nullptr;
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
	operator const NonConstArray<typename std::conditional<STD_IS_REPLACEMENT(same, TYPE, Generic), DummyReturnType, Generic>::type>&() const
	{
		return *reinterpret_cast<const NonConstArray<typename std::conditional<STD_IS_REPLACEMENT(same, TYPE, Generic), DummyReturnType, Generic>::type>*>(this);
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

class ArrayFactory
{
	MAXON_INTERFACE_NONVIRTUAL(ArrayFactory, MAXON_REFERENCE_NONE, "net.maxon.interface.arrayfactory");
public:
	static MAXON_METHOD Result<ArrayInterface<Generic>*> NewBaseArray(const DataType& type, const Generic* src, Bool move);

	template <typename T> static Result<Array<T>> NewBaseArray()
	{
		iferr_scope;
		ArrayInterface<Generic>* res = NewBaseArray(maxon::GetDataType<T>(), nullptr, false) iferr_return;
		return Array<T>(reinterpret_cast<ArrayInterface<T>*>(res));
	}

	template <typename T> static Result<Array<T>> NewBaseArray(const BaseArray<T>& src)
	{
		iferr_scope;
		ArrayInterface<Generic>* res = NewBaseArray(maxon::GetDataType<T>(), reinterpret_cast<const Generic*>(&src), false) iferr_return;
		return Array<T>(reinterpret_cast<ArrayInterface<T>*>(res));
	}

	template <typename T> static Result<Array<T>> NewBaseArray(BaseArray<T>&& src)
	{
		iferr_scope;
		ArrayInterface<Generic>* res = NewBaseArray(maxon::GetDataType<T>(), reinterpret_cast<const Generic*>(&src), true) iferr_return;
		return Array<T>(reinterpret_cast<ArrayInterface<T>*>(res));
	}


	static MAXON_METHOD Result<ArrayInterface<Generic>*> NewBlockArray(const DataType& type, const Generic* src, Bool move);

	template <typename T> static Result<Array<T>> NewBlockArray()
	{
		iferr_scope;
		ArrayInterface<Generic>* res = NewBlockArray(maxon::GetDataType<T>(), nullptr, false) iferr_return;
		return Array<T>(reinterpret_cast<ArrayInterface<T>*>(res));
	}
};

namespace ParametricTypes
{
	MAXON_DECLARATION(ParametricType, Array, "net.maxon.parametrictype.array");
};

template <GET_DATATYPE_POLICY POLICY, typename T> inline Result<DataType> PrivateGetDataType(ArrayInterface<T>**, OverloadRank0)
{
	iferr_scope;
	DataType t = CheckedGetDataType<T, POLICY | GET_DATATYPE_POLICY::NO_DECAY>::Get() iferr_return;
	return ParametricTypes::Array().Instantiate(t);
}

#include "array2.hxx"

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
	MAXON_IMPLEMENTATION_SIMPLE(ArrayImpl, typename);

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

	Result<void> PrivateInsert(Int index, const StridedBlock<const ValueType>& values, Bool move)
	{
		return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::NOT_IMPLEMENTED);
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
		return ResultMem(((ArrayType*) &_array)->Insert(index, values) == OK);
	}

	ResultMem Insert(Int index, const MoveBlock<ValueType>& values)
	{
		if (CONSTARRAY)
			return FAILED;
		return ResultMem(((ArrayType*) &_array)->Insert(index, values) == OK);
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

	Result<Int> GetWritableBlock(Int index, SimdBlock<ValueType>& block)
	{
		return GetBlock(index, reinterpret_cast<SimdBlock<const ValueType>&>(block));
	}

	Int GetBlock(Int index, Block<const ValueType, false>& block) const
	{
		return _array.GetBlock(index, block);
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

	Result<void> CopyFrom(const VArrayInterface<ValueType>& other)
	{
		if (CONSTARRAY)
			return CreateError(MAXON_SOURCE_LOCATION, ERROR_TYPE::NOT_IMPLEMENTED);
		return ((ArrayType*) &_array)->CopyFrom(*((ArrayType*) &static_cast<const ArrayImpl&>(other)._array));
	};

	Result<Interface*> MakeWritable(Bool cloneElements) const
	{
		if (MAXON_LIKELY(!StrongCOWRefHandler::GetReferenceCounter(this).HasMultipleReferences()))
		{
			return const_cast<Interface*>(ToInterface());
		}
		iferr (ArrayImpl* c = ArrayCloneHelper<ARRAY>::New())
			return err;
		if (cloneElements)
		{
			iferr (((ArrayType*) &c->_array)->CopyFrom(*(ArrayType*) &_array))
			{
				DeleteObj(c);
				return err;
			}
		}
		return c;
	}
	String ToString(const FormatStatement* formatStatement) const { return GlobalToString(_array, formatStatement); }

	Int GetMemorySize() const { return _array.GetMemorySize() + (SIZEOF(ArrayImpl) - SIZEOF(ARRAY)); }

	const DataType& GetValueDataType() const
	{
		return GetDataType<ValueType, GET_DATATYPE_POLICY::GENERIC_FOR_UNKNOWN>();
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

	Bool IsEqual(const StaticArrayInterface<ValueType>* other, EQUALITY equality) const
	{
		if (this == other)
			return true;
		if (!other)
			return GetCount() == 0;
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

	UInt GetHashCode() const
	{
		UInt hash = 0;
		for (const StridedBlock<const ValueType>& b : this->GetStridedBlocks())
		{
			for (const ValueType& x : b)
			{
				hash = 31 * hash + CompareTemplate<true>::GetHashCode(x);
			}
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


template <typename ARRAY> MAXON_IMPLEMENTATION_REGISTER_SIMPLE(ArrayImpl<ARRAY>, typename);


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

template <typename T> inline typename std::enable_if<GetCollectionKind<T>::value == COLLECTION_KIND::ARRAY, Result<void>>::type Data::SetImpl(T&& data, OverloadRank1)
{
	iferr_scope;
	using ArrayType = typename std::decay<T>::type;
	ArrayImpl<ArrayType>* a;
	if (STD_IS_REPLACEMENT(reference, T))
	{
		ArrayType copy;
		copy.CopyFrom(data) iferr_return;
		a = NewObj(ArrayImpl<ArrayType>, std::move(copy)) iferr_return;
	}
	else
	{
		a = NewObj(ArrayImpl<ArrayType>, std::move(const_cast<ArrayType&>(data))) iferr_return;
	}
	return SetImpl(Array<typename ArrayType::ValueType>(a), (OverloadRank0) nullptr);
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
