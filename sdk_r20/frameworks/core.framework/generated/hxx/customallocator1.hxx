#if 1
class CustomAllocatorRef;

struct CustomAllocatorInterface::ReferenceClassHelper { using type = CustomAllocatorRef; };

/// Intermediate helper class for CustomAllocatorInterface.
template <typename S> class CustomAllocatorInterface::ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
{
public:
	ConstReferenceFunctionsImpl() = default;
	using PrivateBaseClass = S;
	using PrivateBaseClass::PrivateBaseClass;
};
#ifdef DOXYGEN
template <typename REF> class CustomAllocatorInterface::ConstReferenceFunctionsImplDoxy : public CustomAllocatorInterface::ConstReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for CustomAllocatorInterface.
template <typename S> class CustomAllocatorInterface::ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	ReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CustomAllocatorRef, true>::type&() const { return reinterpret_cast<const CustomAllocatorRef&>(this->GetBaseRef()); }
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, CustomAllocatorRef, false>::type&() { return reinterpret_cast<const CustomAllocatorRef&>(this->GetBaseRef()); }
Int ComputeArraySize(Int currentSize, Int increment, Int minChunkSize) { return DefaultAllocator::ComputeArraySize(currentSize, increment, minChunkSize); }
	public:
/// Allocates a memory block.
/// THREADSAFE.
/// The memory is not cleared, it may contain a certain byte pattern in debug mode.
/// @param[in] s									Block size in bytes (values < 0 will return nullptr)
/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
/// @return												Memory block address or nullptr.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type Alloc(Int s, const maxon::SourceLocation& allocLocation) const;
/// Allocates a memory block and clears it.
/// THREADSAFE.
/// @param[in] s									Block size in bytes (values < 0 will return nullptr)
/// @param[in] allocLocation			Pass MAXON_SOURCE_LOCATION(_NAME) to add the current source line and file.
/// @return												Memory block address or nullptr.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type AllocClear(Int s, const maxon::SourceLocation& allocLocation) const;
/// Resizes an allocated memory block. If allocation of a new block fails the old one won't be freed.
/// @param[in] data								Data location, can be nullptr.
/// @param[in] size								Minimum new data size (values < 0 will return nullptr).
/// @param[in] allocLocation			Structure with caller data like source file and source line.
/// @return												Data pointer or nullptr.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type Realloc(void* data, Int size, const maxon::SourceLocation& allocLocation) const;
template <typename T> void Free(T*& p) { PrivateFree((void*) p); p = nullptr; }
	public:
Bool IsCompatibleWithDefaultAllocator(void*) const { return false; }
	public:
/// Allocates a block of memory.
/// @param[in] size								Minimum data size (values < 0 will return nullptr).
/// @param[in] clear							If the data should be cleared this must be true.
/// @param[in] allocLocation			Structure with caller data like source file and source line.
/// @return												Data pointer or nullptr.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void*>, void*>::type PrivateAlloc(Int size, Bool clear, const maxon::SourceLocation& allocLocation) const;
/// Frees a memory block (might have been allocated by a different local Allocator of the same type).
/// @param[in] data								Pointer as returned by Alloc, guaranteed to be valid and not nullptr.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type PrivateFree(void* data) const;
/// Returns the maximum size of an allocated block (might be bigger than what was acutally allocated).
/// @param[in] data								Pointer as returned by Alloc, guaranteed to be valid and != nullptr.
/// @return												Block size in bytes (>=allocated size) or 0.
	inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type PrivateGetDataSize(void* data) const;
};
#ifdef DOXYGEN
template <typename REF> class CustomAllocatorInterface::ReferenceFunctionsImplDoxy : public CustomAllocatorInterface::ReferenceFunctionsImpl<REF> { };
#endif

/// Intermediate helper class for CustomAllocatorInterface.
template <typename S> class CustomAllocatorInterface::COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
{
public:
	COWReferenceFunctionsImpl() = default;
	using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
	using PrivateBaseClass::PrivateBaseClass;
	operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, CustomAllocatorRef, false>::type&() { return reinterpret_cast<const CustomAllocatorRef&>(this->GetBaseRef()); }
};
#ifdef DOXYGEN
template <typename REF> class CustomAllocatorInterface::COWReferenceFunctionsImplDoxy : public CustomAllocatorInterface::COWReferenceFunctionsImpl<REF> { };
#endif

template <typename ST> struct CustomAllocatorInterface::ReferenceFunctions { using type = typename std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type>::type; };
class CustomAllocatorInterface::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<CustomAllocatorRef>
#else
public maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<CustomAllocatorInterface, maxon::StrongRefHandler, CustomAllocatorRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<ReferenceFunctions<maxon::RefBaseFunctions<maxon::DirectRef<CustomAllocatorInterface, maxon::StrongRefHandler, CustomAllocatorRef>>>>);
	using NonConst = Super::ReferenceClass;
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<CustomAllocatorRef> Create();
};

/// CustomAllocatorRef is the reference class of CustomAllocatorInterface.
///
/// Custom allocator/memory pool interface
class CustomAllocatorRef : public CustomAllocatorInterface::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(CustomAllocatorRef, Reference);
};

#endif
