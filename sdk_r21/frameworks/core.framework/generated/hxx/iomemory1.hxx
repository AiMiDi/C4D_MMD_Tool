#if 1
class IoMemoryRef;

struct IoMemoryInterface::Hxx1
{
	class Reference;
	using ReferenceClass = IoMemoryRef;
	/// Intermediate helper class for IoMemoryInterface.
	template <typename S> class ConstReferenceFunctionsImpl DOXYGEN_SWITCH(: public S,)
	{
	public:
		ConstReferenceFunctionsImpl() = default;
		using PrivateBaseClass = S;
		using PrivateBaseClass::PrivateBaseClass;
		using FreeBufferCallback = IoMemoryInterface::FreeBufferCallback;
/// Gets the current buffer size.
/// @return												Size of the internal buffer.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type GetSize() const;
/// Returns whether the object is writable (true) or not (false)
/// @return												The current mode.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type IsWritable() const;
/// Creates an Url for this IoMemoryRef class. This name can be used to call InputStreamRef and OutputStreamRef functions with memory files.
/// The Url can be passed to any function that accepts Urls for reading/writing files. E.g. reading/writing images from a memory block etc.
/// InOutputStreamRef is not supported.
/// @return												Url for further operations.
		inline Result<Url> GetUrl() const;
/// Copies the classes buffer from position to destData with the given length.
/// @param[in] position						Start copying memory from this offset. The position is the offset in the classes buffer, not the destination buffer.
/// @param[in] data								Destination buffer.
/// @return												Number of bytes copied.
		inline Result<void> ReadBytes(Int position, const Block<Byte>& data) const;
/// Copies the classes buffer from position to destData with the given length.
/// @param[in] position						Start copying memory from this offset. The position is the offset in the classes buffer, not the destination buffer.
/// @param[in] data								Destination buffer.
/// @return												Number of bytes copied.
		inline Result<Int> ReadBytesEOS(Int position, const Block<Byte>& data) const;
		inline Result<InputStreamRef> OpenInputStream(OPENSTREAMFLAGS flags) const;
	};
	/// Intermediate helper class for IoMemoryInterface.
	template <typename S> class ReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		ReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, IoMemoryRef, true>::type&() const { return reinterpret_cast<const IoMemoryRef&>(this->GetBaseRef()); }
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, maxon::StrongRefHandler, IoMemoryRef, false>::type&() { return reinterpret_cast<const IoMemoryRef&>(this->GetBaseRef()); }
/// Prepares a given memory block for reading. The ownership of the memory can be transfered to the object. The memory will be freed by calling DeleteMem().
/// @param[in] buffer							Block with the available data to read from.
/// @param[in] freeBufferCallback	If a callback/lambda is given the memory should be owned by the object and will be freed by calling the callback. Within the callback the memory should be freed and the pointer must be set to nullptr!
/// 															If "nullptr" the memory needs to be freed by yourself and needs to be kept until this class is not used anymore.
/// @return												OK on success.
		inline Result<void> PrepareReadBuffer(const Block<const Char>& buffer, const FreeBufferCallback& freeBufferCallback) const;
/// Resets the class and preallocate a given size of bytes. In read mode the memory can e.g. be filled with WriteBytes. Write mode only needs size 0 as the data grows dynamically.
/// @param[in] size								Requested size of bytes in the buffer. This memory can be accessed via operator[] or ReadBytes/WriteBytes.
/// @return												OK on success.
		inline Result<void> Reset(Int size) const;
/// Accesses operator to the buffer.
/// @param[in] idx								Index of the data to read.
/// @return												Value of the position in the buffer.
		inline typename std::conditional<S::HAS_ERROR, maxon::Result<const Char&>, const Char&>::type operator [](Int idx) const;
/// Writes the given sourceData at position in the classes buffer with the given length.
/// @param[in] position						Start copying memory to this offset. The position is the offset in the classes buffer, not the source data buffer.
/// @param[in] data								Source data buffer.
/// @return												OK on success.
		inline Result<void> WriteBytes(Int position, const Block<const Byte>& data) const;
		inline Result<OutputStreamRef> OpenOutputStream(OPENSTREAMFLAGS flags) const;
		inline Result<InOutputStreamRef> OpenInOutputStream(OPENSTREAMFLAGS flags) const;
	};
	/// Intermediate helper class for IoMemoryInterface.
	template <typename S> class COWReferenceFunctionsImpl : public ConstReferenceFunctionsImpl<S>
	{
	public:
		COWReferenceFunctionsImpl() = default;
		using PrivateBaseClass = ConstReferenceFunctionsImpl<S>;
		using PrivateBaseClass::PrivateBaseClass;
		operator const typename maxon::RefConversionTarget<S, typename S::Handler, void, IoMemoryRef, false>::type&() { return reinterpret_cast<const IoMemoryRef&>(this->GetBaseRef()); }
	};
	template <typename ST> struct ReferenceFunctionsHelper : public std::conditional<maxon::Bool(ST::type::Handler::KIND & (maxon::VALUEKIND::COW_MASK | maxon::VALUEKIND::DEEP_CONSTNESS)), COWReferenceFunctionsImpl<typename ST::type>, typename std::conditional<std::is_const<typename ST::type::PrivateReferencedType>::value, ConstReferenceFunctionsImpl<typename ST::type>, ReferenceFunctionsImpl<typename ST::type>>::type> { };
};
class IoMemoryInterface::Hxx1::Reference :
#ifdef DOXYGEN
public ReferenceFunctionsImplDoxy<IoMemoryRef>
#else
public maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<IoMemoryInterface, maxon::StrongRefHandler, IoMemoryRef>>>>
#endif
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(Reference, maxon::ReferenceBase<Hxx1::ReferenceFunctionsHelper<maxon::RefBaseFunctions<maxon::DirectRef<IoMemoryInterface, maxon::StrongRefHandler, IoMemoryRef>>>>);
	using NonConst = typename Super::ReferenceClass;
/// Allocators for common use.
	static MAXON_ATTRIBUTE_FORCE_INLINE maxon::ResultMemT<IoMemoryRef> Create();
};

/// IoMemoryRef is the reference class of IoMemoryInterface.
///
/// Helper class for Url of type maxon::URLSCHEME_MEMORY.
/// It turns memory blocks into InputStreams or OutputStreams.
/// This way a memory block can be handled like a real file. The following example shows how to write into a memory file.
/// @code
/// IoMemoryRef mfh = IoMemoryRef::Create() iferr_return;
/// Url writemem = mfh.GetUrl();
/// OutputStreamRef outmem = writemem.OpenOutputStream() iferr_return;
/// outmem.Write("ABCDE", 5);
/// outmem.Write("FGHIJ", 5);
/// outmem.Close();
///
/// for (Int i = 0; i < mfh.GetSize(); i++)
/// {
/// 	OutputWithFlags(OUTPUT::DIAGNOSTIC | OUTPUT::NOLINEBREAK, "@{c}", mfh[i]);
/// }
/// @endcode
/// @code
/// IoMemoryRef mem = IoMemoryRef::Create() iferr_return;
/// Char*	buffer = NewMem(Char, size) iferr_return;
/// mem.PrepareReadBuffer(ToBlock(buffer, size),
/// 	[](const Char*& buffer)
/// 	{
/// 		DeleteMem(buffer);
/// 	}) iferr_return;
/// @endcode
class IoMemoryRef : public IoMemoryInterface::Hxx1::Reference
{
public:
	MAXON_DEFAULT_REFERENCE_CONSTRUCTORS(IoMemoryRef, typename IoMemoryInterface::Hxx1::Reference);
};

#endif
