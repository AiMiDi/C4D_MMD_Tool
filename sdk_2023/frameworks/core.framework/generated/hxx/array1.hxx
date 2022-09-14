#if 1
class PersistentIdGenerator;

struct PersistentIdGeneratorInterface::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = PersistentIdGenerator;
	/// Intermediate helper class for PersistentIdGeneratorInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(PersistentIdGeneratorInterface**);
		inline Result<void> InitializeBuffer(PersistentIdBuffer& buffer) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type FreeBuffer(PersistentIdBuffer& buffer) const;
		inline Result<void> Move(Int index, PersistentIdBuffer& buffer) const;
		inline Result<void> Advance(Int index, PersistentIdBuffer& buffer) const;
	};
	/// Intermediate helper class for PersistentIdGeneratorInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(PersistentIdGeneratorInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PersistentIdGenerator, false>::type&() const { return reinterpret_cast<const PersistentIdGenerator&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, PersistentIdGenerator, false>::type&() { return reinterpret_cast<const PersistentIdGenerator&>(this->GetBaseRef()); }
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ST::type>,
	ConstFn<typename ST::type>
	> { };
};
class PersistentIdGeneratorInterface::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<PersistentIdGenerator>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const PersistentIdGeneratorInterface, maxon::StrongCOWRefHandler, PersistentIdGenerator>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const PersistentIdGeneratorInterface, maxon::StrongCOWRefHandler, PersistentIdGenerator>>>>);
	using NonConst = Hxx1::NonConstRef;
};

class PersistentIdGeneratorInterface::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<PersistentIdGeneratorInterface, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<PersistentIdGeneratorInterface, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// PersistentIdGenerator is the reference class of PersistentIdGeneratorInterface.
class PersistentIdGenerator : public PersistentIdGeneratorInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(PersistentIdGenerator, typename PersistentIdGeneratorInterface::Hxx1::Reference);
};

template <typename TYPE> class StaticArray;

template <typename TYPE> struct StaticArrayInterface<TYPE>::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = StaticArray<TYPE>;
	/// Intermediate helper class for StaticArrayInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(StaticArrayInterface**);
/// Array (subscript) operator for const objects.
/// @param[in] index							Element index.
/// @return												Array element.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const TYPE&>, const TYPE&>::type operator [](Int index) const;
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
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetBlock(Int index, SimdBlock<const TYPE>& block) const;
/// Returns the data type of this array's elements. This may be nullptr if there is no
/// DataType for the template parameter TYPE.
/// @return												DataType of the elements or nullptr.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const DataType&>, const DataType&>::type GetValueDataType() const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const PersistentIdGenerator&>, const PersistentIdGenerator&>::type GetPersistentIdGenerator() const;

	using Iterator = typename StaticArrayInterface::ConstIterator;
	using ConstIterator = typename StaticArrayInterface::ConstIterator;
	
		public:
/// Returns an iterator pointing to the first array element.
/// @return												Iterator for the first element (equal to End() if the array is empty).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename StaticArrayInterface<TYPE>::ConstIterator>, typename StaticArrayInterface<TYPE>::ConstIterator>::type Begin() const;
/// Returns an iterator pointing one behind the last array element.
/// @return												Iterator for the array end, this is one behind the last element.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename StaticArrayInterface<TYPE>::ConstIterator>, typename StaticArrayInterface<TYPE>::ConstIterator>::type End() const;
	};
	/// Intermediate helper class for StaticArrayInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(StaticArrayInterface**);
/// Array (subscript) operator for non-const objects.
/// @param[in] index							Element index.
/// @return												Array element.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type GetWritable(Int index) const;
		template <typename A> inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type Set(Int index, A&& value) const;
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
		inline Result<Int> GetBlock(Int index, SimdBlock<NonConstValueType>& block) const;
/// Will ensure that all elements of the array are writable for multithreaded access.
/// Besides parallel write use case, MakeAllElementsWritable is not required as GetWritable(Int index) method does all the work.
/// This is useful mostly for paged arrays (GenericContainerInterface::INTERFACES::PAGED_ARRAY).
/// @param[in] copyElements				Clone all the elements.
/// @return												OK on success.
		inline Result<void> MakeAllElementsWritable(Bool copyElements = true) const;
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
		inline Result<void> MakeElementsWritable(Int start, Int end, Bool copyElements = true) const;
	};
	/// Intermediate helper class for StaticArrayInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(StaticArrayInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, StaticArray<TYPE>, false>::type&() const { return reinterpret_cast<const StaticArray<TYPE>&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, StaticArray<TYPE>, false>::type&() { return reinterpret_cast<const StaticArray<TYPE>&>(this->GetBaseRef()); }
/// Array (subscript) operator for non-const objects.
/// @param[in] index							Element index.
/// @return												Array element.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type GetWritable(Int index);
		template <typename A> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type Set(Int index, A&& value);
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
		inline Result<Int> GetWritableBlock(Int index, SimdBlock<NonConstValueType>& block);
/// Will ensure that all elements of the array are writable for multithreaded access.
/// Besides parallel write use case, MakeAllElementsWritable is not required as GetWritable(Int index) method does all the work.
/// This is useful mostly for paged arrays (GenericContainerInterface::INTERFACES::PAGED_ARRAY).
/// @param[in] copyElements				Clone all the elements.
/// @return												OK on success.
		inline Result<void> MakeAllElementsWritable(Bool copyElements = true);
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
		inline Result<void> MakeElementsWritable(Int start, Int end, Bool copyElements = true);
	};
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename GenericIndexableContainerInterface::Hxx1::template FnHelper<ST, NamedTuple<TYPE>>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename GenericIndexableContainerInterface::Hxx1::template FnHelper<ST, NamedTuple<TYPE>>::type>, Fn<typename GenericIndexableContainerInterface::Hxx1::template FnHelper<ST, NamedTuple<TYPE>>::type>>::type
	> { };
};
template <typename TYPE> class StaticArrayInterface<TYPE>::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<StaticArray<TYPE>>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const StaticArrayInterface<TYPE>, maxon::StrongCOWRefHandler, StaticArray<TYPE>>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const StaticArrayInterface<TYPE>, maxon::StrongCOWRefHandler, StaticArray<TYPE>>>>>);
	using NonConst = Hxx1::NonConstRef;
};

template <typename TYPE> class StaticArrayInterface<TYPE>::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<StaticArrayInterface<TYPE>, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<StaticArrayInterface<TYPE>, maxon::StrongRefHandler, NonConstRef>>>>);
};

/// StaticArray is the reference class of StaticArrayInterface.
template <typename TYPE> class StaticArray : public StaticArrayInterface<TYPE>::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(StaticArray, typename StaticArrayInterface<TYPE>::Hxx1::Reference);
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = StaticArray<typename MAP<TYPE>::type>;
	};
};

template <typename TYPE> class Array;

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
template <typename TYPE> struct ArrayInterface<TYPE>::Hxx1
{
	class Reference;
	class NonConstRef;
	using ReferenceClass = Array<TYPE>;
	/// Intermediate helper class for ArrayInterface.
	template <typename S> class ConstFn DOXYGEN_SWITCH_REVERSED(, : public S)
	{
	public:
		ConstFn() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static ConstFn PrivateLookupFn(ArrayInterface**);
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
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetBlock(Int index, Block<const TYPE>& block) const;
/// Calculates the memory usage for this array.
/// @return												Memory size in bytes.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetMemorySize() const;
		template <typename DT> inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type HasType() const;
/// Issues a failed DebugAssert if the DataType of this array doesn't match T. If T is Generic,
/// no check happens.
/// @tparam DT										Type to check.
		template <typename DT> inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type AssertType() const;
#ifdef MAXON_COMPILER_INTEL
#endif
#ifdef MAXON_COMPILER_INTEL
#endif

	using Iterator = typename ArrayInterface::ConstIterator;
	using ConstIterator = typename ArrayInterface::ConstIterator;
	
		public:
/// Returns an iterator pointing to the first array element.
/// @return												Iterator for the first element (equal to End() if the array is empty).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename ArrayInterface<TYPE>::ConstIterator>, typename ArrayInterface<TYPE>::ConstIterator>::type Begin() const;
/// Returns an iterator pointing one behind the last array element.
/// @return												Iterator for the array end, this is one behind the last element.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<typename ArrayInterface<TYPE>::ConstIterator>, typename ArrayInterface<TYPE>::ConstIterator>::type End() const;
#ifdef CPP_853_HACK
#ifdef MAXON_COMPILER_GCC
#else
#endif
#endif
#ifdef CPP_853_HACK
#endif
	};
	/// Intermediate helper class for ArrayInterface.
	template <typename S> class Fn : public ConstFn<S>
	{
	public:
		Fn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static Fn PrivateLookupFn(ArrayInterface**);
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
/// Inserts a new element at index position and initializes it with #value.
/// @param[in] index							Insert index (the array size will increase and the existing elements are moved).
/// @param[in] value							Value to be inserted.
/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type Insert(Int index, const TYPE& value) const;
/// Inserts a new element at index position and initializes it with #value.
/// @param[in] index							Insert index (the array size will increase and the existing elements are moved).
/// @param[in] value							Value to be inserted.
/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type Insert(Int index, TYPE&& value) const;
/// Inserts a number of new elements at @p index. The elements will be copied.
/// @param[in] index							Insertion index (the array size will increase and the existing elements are moved).
/// @param[in] values							Block with values to be copied.
/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
/// @return												False if insert failed.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type Insert(Int index, const Block<const TYPE>& values) const;
/// Inserts a number of new elements at @p index. The elements will be moved.
/// @param[in] index							Insertion index (the array size will increase and the existing elements are moved).
/// @param[in] values							Block with values to be moved.
/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
/// @return												False if insert failed.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type Insert(Int index, const MoveBlock<TYPE>& values) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type InsertBlock(Int index, const Block<const TYPE>& values) const;
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, ResultMem>::type InsertBlock(Int index, const MoveBlock<TYPE>& values) const;
/// Adds a new element at the end of the array. The element will be default-constructed.
/// @return												Element reference or OutOfMemoryError if the allocation failed.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type Append() const;
/// Adds a new element at the end of the array and initializes it with #value.
/// @param[in] value							Value to be appended.
/// @return												Element reference or OutOfMemoryError if the allocation failed.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type Append(const TYPE& value) const;
/// Adds a new element at the end of the array and initializes it with #value.
/// @param[in] value							Value to be appended.
/// @return												Element reference or OutOfMemoryError if the allocation failed.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type Append(TYPE&& value) const;
/// Adds a new element at the end of the array and initializes it with #value.
/// @param[in] value							Value to be appended.
/// @return												Element reference or OutOfMemoryError if the allocation failed.
		template <typename A> inline typename std::conditional<S::HAS_ERROR, maxon::Result<TYPE&>, ResultRef<TYPE>>::type Append(A&& value) const;
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
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type SetPersistentIdGenerator(const PersistentIdGenerator& generator) const;
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
	/// Intermediate helper class for ArrayInterface.
	template <typename S> class COWFn : public ConstFn<S>
	{
	public:
		COWFn() = default;
		using PrivateBaseClass = ConstFn<S>;
		using PrivateBaseClass::PrivateBaseClass;
		using PrivateBaseClass::PrivateLookupFn;
		static COWFn PrivateLookupFn(ArrayInterface**);
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Array<TYPE>, false>::type&() const { return reinterpret_cast<const Array<TYPE>&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongCOWRefHandler, Array<TYPE>, false>::type&() { return reinterpret_cast<const Array<TYPE>&>(this->GetBaseRef()); }

		public: using ValueType = TYPE;
	
		public:
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
/// Inserts a new element at index position and initializes it with #value.
/// @param[in] index							Insert index (the array size will increase and the existing elements are moved).
/// @param[in] value							Value to be inserted.
/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type Insert(Int index, const TYPE& value);
/// Inserts a new element at index position and initializes it with #value.
/// @param[in] index							Insert index (the array size will increase and the existing elements are moved).
/// @param[in] value							Value to be inserted.
/// @return												Element reference or OutOfMemoryError if the allocation failed (or position is out of boundaries).
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type Insert(Int index, TYPE&& value);
/// Inserts a number of new elements at @p index. The elements will be copied.
/// @param[in] index							Insertion index (the array size will increase and the existing elements are moved).
/// @param[in] values							Block with values to be copied.
/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
/// @return												False if insert failed.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type Insert(Int index, const Block<const TYPE>& values);
/// Inserts a number of new elements at @p index. The elements will be moved.
/// @param[in] index							Insertion index (the array size will increase and the existing elements are moved).
/// @param[in] values							Block with values to be moved.
/// 															If the block points to nullptr, only its count is used, and you have to call the constructor of the new elements manually.
/// @return												False if insert failed.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type Insert(Int index, const MoveBlock<TYPE>& values);
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type InsertBlock(Int index, const Block<const TYPE>& values);
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultMem, maxon::Result<void>>::type InsertBlock(Int index, const MoveBlock<TYPE>& values);
/// Adds a new element at the end of the array. The element will be default-constructed.
/// @return												Element reference or OutOfMemoryError if the allocation failed.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type Append();
/// Adds a new element at the end of the array and initializes it with #value.
/// @param[in] value							Value to be appended.
/// @return												Element reference or OutOfMemoryError if the allocation failed.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type Append(const TYPE& value);
/// Adds a new element at the end of the array and initializes it with #value.
/// @param[in] value							Value to be appended.
/// @return												Element reference or OutOfMemoryError if the allocation failed.
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type Append(TYPE&& value);
/// Adds a new element at the end of the array and initializes it with #value.
/// @param[in] value							Value to be appended.
/// @return												Element reference or OutOfMemoryError if the allocation failed.
		template <typename A> inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), ResultRef<TYPE>, maxon::Result<TYPE&>>::type Append(A&& value);
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
		inline typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type SetPersistentIdGenerator(const PersistentIdGenerator& generator);
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
	template <typename ST> struct FnHelper : public std::conditional<
	maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)),
	COWFn<typename ArrayBase0<ArrayInterface<TYPE>, TYPE, StaticArrayInterface<TYPE>, DefaultCompare>::Hxx1::template FnHelper<ST>::type>,
	typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstFn<typename ArrayBase0<ArrayInterface<TYPE>, TYPE, StaticArrayInterface<TYPE>, DefaultCompare>::Hxx1::template FnHelper<ST>::type>, Fn<typename ArrayBase0<ArrayInterface<TYPE>, TYPE, StaticArrayInterface<TYPE>, DefaultCompare>::Hxx1::template FnHelper<ST>::type>>::type
	> { };
};
template <typename TYPE> class ArrayInterface<TYPE>::Hxx1::Reference :
#ifdef DOXYGEN
public COWFnDoxy<Array<TYPE>>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const ArrayInterface<TYPE>, maxon::StrongCOWRefHandler, Array<TYPE>>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<const ArrayInterface<TYPE>, maxon::StrongCOWRefHandler, Array<TYPE>>>>>);
	using NonConst = Hxx1::NonConstRef;
};

template <typename TYPE> class ArrayInterface<TYPE>::Hxx1::NonConstRef :
#ifdef DOXYGEN
public FnDoxy<NonConstRef>
#else
public maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ArrayInterface<TYPE>, maxon::StrongRefHandler, NonConstRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(NonConstRef, maxon::RefBase<Hxx1::FnHelper<maxon::RefBaseFn<maxon::DirectRef<ArrayInterface<TYPE>, maxon::StrongRefHandler, NonConstRef>>>>);
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
template <typename TYPE> class Array : public ArrayInterface<TYPE>::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Array, typename ArrayInterface<TYPE>::Hxx1::Reference);
	struct Instantiation
	{
		template <template <typename> class MAP> using Map = Array<typename MAP<TYPE>::type>;
	};
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
#ifndef CPP_853_HACK
#else
#endif
#ifdef CPP_853_HACK
#else
#endif
#ifdef CPP_853_HACK
#else
#endif
#endif
