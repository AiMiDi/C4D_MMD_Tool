#if 1
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif
template <typename TYPE> class Array;

template <typename TYPE> struct ArrayInterface<TYPE>::ReferenceClassHelper { using type = Array<TYPE>; };

/// Intermediate helper class for ArrayInterface.
template <typename TYPE> template <typename S> class ArrayInterface<TYPE>::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
/// Gets the number of array elements.
/// @return												Number of array elements.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetCount() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEmpty() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsPopulated() const;
/// Array (subscript) operator for const objects.
/// @param[in] index							Element index.
/// @return												Array element.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const TYPE&>, const TYPE&>::type operator [](Int index) const;
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
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetBlock(Int index, Block<const TYPE, false>& block) const;
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
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetBlock(Int index, StridedBlock<const TYPE>& block) const;
/// Returns a clone of this array.
/// @param[in] cloneElements			True if also the elements shall be cloned, false otherwise (then just a new object sharing the same ArrayInterface implementation is created).
/// @return												Pointer to the new array object, nullptr if allocation or copying failed.
	inline Result<ArrayInterface*> Clone(Bool cloneElements = true) const;
/// Returns the data type of this array's elements. This may be nullptr if there is no
/// DataType for the template parameter TYPE.
/// @return												DataType of the elements or nullptr.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType*>, const DataType*>::type GetValueDataType() const;
/// @param[in] formatStatement		Nullptr or additional formatting instruction. Currently no additional formatting instructions are supported.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type ToString(const FormatStatement* formatStatement) const;
/// Calculates the memory usage for this array.
/// @return												Memory size in bytes.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetMemorySize() const;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsEqual(const ArrayInterface* other, EQUALITY equality) const;
	template <typename T> inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type HasType() const;
/// Issues a failed DebugAssert if the DataType of this array doesn't match T. If T is Generic,
/// no check happens.
/// @tparam T											Type to check.
	template <typename T> inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type AssertType() const;
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
/// Returns an iterator pointing to the first array element.
/// @return												Iterator for the first element (equal to End() if the array is empty).
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type Begin() const;
/// Returns an iterator pointing one behind the last array element.
/// @return												Iterator for the array end, this is one behind the last element.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<ConstIterator>, ConstIterator>::type End() const;
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif
};
#ifdef DOXYGEN
template <typename TYPE> template <typename REF> class ArrayInterface<TYPE>::ConstReferenceFunctionsImplDoxy : public ArrayInterface::ConstReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for ArrayInterface.
template <typename TYPE> template <typename S> class ArrayInterface<TYPE>::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Set(Int index, TYPE&& value) const;
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
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetBlock(Int index, Block<TYPE, false>& block) const;
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
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetBlock(Int index, StridedBlock<TYPE>& block) const;
/// Resizes the array to contain count elements.
/// If count is smaller than GetCount() all extra elements are being deleted. If it is
/// greater the array is expanded and the default constructor is called for new elements.
/// @param[in] count							New array size.
/// @param[in] resizeFlags				See COLLECTION_RESIZE_FLAGS.
/// @return												False if allocation failed.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::DEFAULT) const;
/// Prepare the internal array so that it can hold at least the given number of elements with
/// as few further memory allocations as possible.
/// @param[in] requestedCapacity	The desired internal capacity.
/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
/// @return												False if allocation failed.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY) const;
/// Inserts a new element at @p index. The element will be default-constructed.
/// @param[in] index							Insertion index (the array size will increase and the existing elements are moved).
/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type Insert(Int index) const;
/// Inserts a new element at index position and initializes it with a copy of x.
/// @param[in] index							Insert index (the array size will increase and the existing elements are moved).
/// @param[in] data								Value to be copied.
/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type Insert(Int index, const TYPE& data) const;
/// Inserts a new element at index position and moves the content of x to it.
/// @param[in] index							Insert index (the array size will increase and the existing elements are moved).
/// @param[in] data								Value to be moved.
/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type Insert(Int index, NonConstValueType&& data) const;
/// Inserts a number of new elements at @p index. The elements will be copied.
/// @param[in] index							Insertion index (the array size will increase and the existing elements are moved).
/// @param[in] values							Block with values to be copied.
/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
/// @return												False if insert failed.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type Insert(Int index, const Block<const ValueType>& values) const;
/// Inserts a number of new elements at @p index. The elements will be moved.
/// @param[in] index							Insertion index (the array size will increase and the existing elements are moved).
/// @param[in] values							Block with values to be moved.
/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
/// @return												False if insert failed.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type Insert(Int index, const MoveBlock<ValueType>& values) const;
/// Adds a new element at the end of the array. The element will be default-constructed.
/// @return												Element reference or OutOfMemoryError if the allocation failed.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type Append() const;
/// Adds a new element at the end of the array and initializes it with a copy of @p data.
/// @param[in] data								Value to be copied.
/// @return												Element reference or OutOfMemoryError if the allocation failed.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type Append(const TYPE& data) const;
/// Adds a new element at the end of the array and initializes it by moving @p data into it.
/// @param[in] data								Value to be moved.
/// @return												Element reference or OutOfMemoryError if the allocation failed.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type Append(NonConstValueType&& data) const;
/// Deletes the last element.
/// @return												True if there was at least one element.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type Pop() const;
/// Deletes the last element.
/// @param[out] dst								Nullptr or pointer to return value.
/// @return												True if there was at least one element.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type Pop(TYPE* dst) const;
/// Erases (removes and deletes) elements.
/// @param[in] index							Erase index.
/// @param[in] count							Number of elements to be erased (if eraseCnt is higher than what is available at position Erase() will succeed, but remove only the number of available elements).
/// @return												True if operation was successul.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type Erase(Int index, Int count = 1) const;
/// Erases elements within the array and moves elements from the end to the erased gap.
/// This is generally faster than Erase because at most count elements have to be moved,
/// but it changes the order of elements.
/// @param[in] index							Erase index.
/// @param[in] count							Number of elements to be erased (if eraseCnt is higher than what is available at position Erase() will succeed, but remove only the number of available elements).
/// @return												True if operation was successul.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type SwapErase(Int index, Int count = 1) const;
/// Deletes all elements (calls destructors and frees memory).
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Reset() const;
/// Deletes all elements, but doesn't free memory (calls destructors though).
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type Flush() const;
/// Sets this array to a copy of the given other array.
/// @param[in] other							Source array.
/// @return												Success of operation.
	inline Result<void> CopyFrom(const ArrayInterface& other) const;
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif
};
#ifdef DOXYGEN
template <typename TYPE> template <typename REF> class ArrayInterface<TYPE>::ReferenceFunctionsImplDoxy : public ArrayInterface::ReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for ArrayInterface.
template <typename TYPE> template <typename S> class ArrayInterface<TYPE>::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Array<TYPE>, false>::type&() const { return reinterpret_cast<const Array<TYPE>&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Array<TYPE>, false>::type&() { return reinterpret_cast<const Array<TYPE>&>(this->GetBaseRef()); }
/// Array (subscript) operator for non-const objects.
/// @param[in] index							Element index.
/// @return												Array element.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), TYPE&, maxon::Result<TYPE&>>::type GetWritable(Int index);
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Set(Int index, TYPE&& value);
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
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type GetWritableBlock(Int index, Block<TYPE, false>& block);
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
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Int, maxon::Result<Int>>::type GetWritableBlock(Int index, StridedBlock<TYPE>& block);
/// Resizes the array to contain count elements.
/// If count is smaller than GetCount() all extra elements are being deleted. If it is
/// greater the array is expanded and the default constructor is called for new elements.
/// @param[in] count							New array size.
/// @param[in] resizeFlags				See COLLECTION_RESIZE_FLAGS.
/// @return												False if allocation failed.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type Resize(Int count, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::DEFAULT);
/// Prepare the internal array so that it can hold at least the given number of elements with
/// as few further memory allocations as possible.
/// @param[in] requestedCapacity	The desired internal capacity.
/// @param[in] resizeFlags				If ON_GROW_FIT_TO_SIZE is set, the collection will use only as much memory as needed to hold the data.
/// @return												False if allocation failed.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type SetCapacityHint(Int requestedCapacity, COLLECTION_RESIZE_FLAGS resizeFlags = COLLECTION_RESIZE_FLAGS::ON_GROW_RESERVE_CAPACITY);
/// Inserts a new element at @p index. The element will be default-constructed.
/// @param[in] index							Insertion index (the array size will increase and the existing elements are moved).
/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type Insert(Int index);
/// Inserts a new element at index position and initializes it with a copy of x.
/// @param[in] index							Insert index (the array size will increase and the existing elements are moved).
/// @param[in] data								Value to be copied.
/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type Insert(Int index, const TYPE& data);
/// Inserts a new element at index position and moves the content of x to it.
/// @param[in] index							Insert index (the array size will increase and the existing elements are moved).
/// @param[in] data								Value to be moved.
/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type Insert(Int index, NonConstValueType&& data);
/// Inserts a number of new elements at @p index. The elements will be copied.
/// @param[in] index							Insertion index (the array size will increase and the existing elements are moved).
/// @param[in] values							Block with values to be copied.
/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
/// @return												False if insert failed.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type Insert(Int index, const Block<const ValueType>& values);
/// Inserts a number of new elements at @p index. The elements will be moved.
/// @param[in] index							Insertion index (the array size will increase and the existing elements are moved).
/// @param[in] values							Block with values to be moved.
/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
/// @return												False if insert failed.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type Insert(Int index, const MoveBlock<ValueType>& values);
/// Adds a new element at the end of the array. The element will be default-constructed.
/// @return												Element reference or OutOfMemoryError if the allocation failed.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type Append();
/// Adds a new element at the end of the array and initializes it with a copy of @p data.
/// @param[in] data								Value to be copied.
/// @return												Element reference or OutOfMemoryError if the allocation failed.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type Append(const TYPE& data);
/// Adds a new element at the end of the array and initializes it by moving @p data into it.
/// @param[in] data								Value to be moved.
/// @return												Element reference or OutOfMemoryError if the allocation failed.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type Append(NonConstValueType&& data);
/// Deletes the last element.
/// @return												True if there was at least one element.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type Pop();
/// Deletes the last element.
/// @param[out] dst								Nullptr or pointer to return value.
/// @return												True if there was at least one element.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), Bool, maxon::Result<Bool>>::type Pop(TYPE* dst);
/// Erases (removes and deletes) elements.
/// @param[in] index							Erase index.
/// @param[in] count							Number of elements to be erased (if eraseCnt is higher than what is available at position Erase() will succeed, but remove only the number of available elements).
/// @return												True if operation was successul.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type Erase(Int index, Int count = 1);
/// Erases elements within the array and moves elements from the end to the erased gap.
/// This is generally faster than Erase because at most count elements have to be moved,
/// but it changes the order of elements.
/// @param[in] index							Erase index.
/// @param[in] count							Number of elements to be erased (if eraseCnt is higher than what is available at position Erase() will succeed, but remove only the number of available elements).
/// @return												True if operation was successul.
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type SwapErase(Int index, Int count = 1);
/// Deletes all elements (calls destructors and frees memory).
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Reset();
/// Deletes all elements, but doesn't free memory (calls destructors though).
	inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type Flush();
/// Sets this array to a copy of the given other array.
/// @param[in] other							Source array.
/// @return												Success of operation.
	inline Result<void> CopyFrom(const ArrayInterface& other);
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif
	explicit operator maxon::Bool() const MAXON_WORKAROUND_CLANG_DELETED_FUNCTION(S);
	explicit operator maxon::Bool() MAXON_WORKAROUND_CLANG_DELETED_FUNCTION(S);
};
#ifdef DOXYGEN
template <typename TYPE> template <typename REF> class ArrayInterface<TYPE>::COWReferenceFunctionsImplDoxy : public ArrayInterface::COWReferenceFunctionsImpl<REF> { };
#endif

template <typename TYPE> template <typename ST> struct ArrayInterface<TYPE>::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type>::type; };
template <typename TYPE> class ArrayInterface<TYPE>::Reference :
#ifdef DOXYGEN
public COWReferenceFunctionsImplDoxy<Array<TYPE>>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const ArrayInterface<TYPE>, maxon::StrongCOWRefHandler, Array<TYPE>>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<const ArrayInterface<TYPE>, maxon::StrongCOWRefHandler, Array<TYPE>>>>>);
	using NonConst = NonConstRef;
};

/// Array is the reference class of ArrayInterface.
///
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
template <typename TYPE> class Array : public ArrayInterface<TYPE>::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Array, typename ArrayInterface<TYPE>::Reference);
};

#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#else
#endif
#ifdef MAXON_COMPILER_BUG_CONST_TYPE_ALIAS
#else
#endif
#ifdef CPP_853_HACK
#endif
#ifdef CPP_853_HACK
#else
#endif
#endif
