#if 1
namespace maxon
{
	const maxon::Char* const IoMemoryInterface::MTable::_ids = 
		"Free@3fc5cd2a06ba355f\0" // void Free(const IoMemoryInterface* object)
		"Alloc@fa8bbec4aa9ca2e8\0" // IoMemoryInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@1157daf7e476f541\0" // IoMemoryInterface* Alloc(const maxon::SourceLocation& allocLocation, const IoMemoryInterface& src)
		"PrepareReadBuffer@5b985452992e18ab\0" // Result<void> PrepareReadBuffer(const Block<const Char>& buffer, const FreeBufferCallback& freeBufferCallback)
		"Reset@44dd4274e7521437\0" // Result<void> Reset(Int size)
		"operatorIndex@27f2b621723e73bf\0" // const Char& operatorIndex(Int idx)
		"GetSize@4386c86\0" // Int GetSize() const
		"IsWritable@76f01901\0" // Bool IsWritable() const
		"GetUrl@a54f479993bcc9e5\0" // Result<Url> GetUrl() const
		"ReadBytes@cacd7b43c50db029\0" // Result<void> ReadBytes(Int position, const Block<Byte>& data) const
		"ReadBytesEOS@8eb11663fc8664ac\0" // Result<Int> ReadBytesEOS(Int position, const Block<Byte>& data) const
		"WriteBytes@509196ff4593f4ce\0" // Result<void> WriteBytes(Int position, const Block<const Byte>& data)
		"OpenInputStream@de6e6ed71b1abeea\0" // Result<InputStreamRef> OpenInputStream(OPENSTREAMFLAGS flags) const
		"OpenOutputStream@14e528d17f28f125\0" // Result<OutputStreamRef> OpenOutputStream(OPENSTREAMFLAGS flags)
		"OpenInOutputStream@5df4ab04f0e33aaa\0" // Result<InOutputStreamRef> OpenInOutputStream(OPENSTREAMFLAGS flags)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class IoMemoryInterface::Hxx2::Unresolved : public IoMemoryInterface
	{
	public:
		static const Unresolved* Get(const IoMemoryInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(IoMemoryInterface* o) { return (Unresolved*) o; }
		static void Free(const IoMemoryInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return IoMemoryInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static IoMemoryInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return IoMemoryInterface::Alloc(allocLocation); return nullptr;}
		static IoMemoryInterface* Alloc(const maxon::SourceLocation& allocLocation, const IoMemoryInterface& src) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return IoMemoryInterface::Alloc(allocLocation, src); return nullptr;}
		Result<void> PrepareReadBuffer(const Block<const Char>& buffer, const FreeBufferCallback& freeBufferCallback) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((IoMemoryInterface*) this)->PrepareReadBuffer(buffer, freeBufferCallback); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> Reset(Int size) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((IoMemoryInterface*) this)->Reset(size); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		const Char& operator [](Int idx) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((IoMemoryInterface*) this)->operator [](idx); return maxon::PrivateIncompleteNullReturnValue<const Char&>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Int GetSize() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const IoMemoryInterface*) this)->GetSize(); return 0;}
		Bool IsWritable() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const IoMemoryInterface*) this)->IsWritable(); return maxon::PrivateLogNullptrError(false);}
		Result<Url> GetUrl() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const IoMemoryInterface*) this)->GetUrl(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> ReadBytes(Int position, const Block<Byte>& data) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const IoMemoryInterface*) this)->ReadBytes(position, data); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<Int> ReadBytesEOS(Int position, const Block<Byte>& data) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const IoMemoryInterface*) this)->ReadBytesEOS(position, data); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<void> WriteBytes(Int position, const Block<const Byte>& data) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((IoMemoryInterface*) this)->WriteBytes(position, data); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<InputStreamRef> OpenInputStream(OPENSTREAMFLAGS flags) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((const IoMemoryInterface*) this)->OpenInputStream(flags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<OutputStreamRef> OpenOutputStream(OPENSTREAMFLAGS flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((IoMemoryInterface*) this)->OpenOutputStream(flags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		Result<InOutputStreamRef> OpenInOutputStream(OPENSTREAMFLAGS flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return ((IoMemoryInterface*) this)->OpenInOutputStream(flags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE IoMemoryInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<IoMemoryInterface*>::value,
		maxon::details::NullReturnType<IoMemoryInterface*>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<const Char&>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<Url>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<Int>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<InputStreamRef>>::value,
		maxon::details::NullReturnType<Result<OutputStreamRef>>::value,
		maxon::details::NullReturnType<Result<InOutputStreamRef>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool IoMemoryInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_IoMemoryInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_IoMemoryInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_IoMemoryInterface_Alloc_1 = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_Alloc_1;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_IoMemoryInterface_PrepareReadBuffer = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_PrepareReadBuffer;
		#else
		tbl->_IoMemoryInterface_PrepareReadBuffer = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_PrepareReadBuffer;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_IoMemoryInterface_Reset = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_Reset;
		#else
		tbl->_IoMemoryInterface_Reset = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_Reset;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Char&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_IoMemoryInterface_operatorIndex = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_operatorIndex;
		#else
		tbl->_IoMemoryInterface_operatorIndex = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_operatorIndex;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_IoMemoryInterface_GetSize = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_GetSize;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_IoMemoryInterface_IsWritable = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_IsWritable;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Url>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_IoMemoryInterface_GetUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_GetUrl;
		#else
		tbl->_IoMemoryInterface_GetUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_GetUrl;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_IoMemoryInterface_ReadBytes = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_ReadBytes;
		#else
		tbl->_IoMemoryInterface_ReadBytes = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_ReadBytes;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_IoMemoryInterface_ReadBytesEOS = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_ReadBytesEOS;
		#else
		tbl->_IoMemoryInterface_ReadBytesEOS = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_ReadBytesEOS;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_IoMemoryInterface_WriteBytes = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_WriteBytes;
		#else
		tbl->_IoMemoryInterface_WriteBytes = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_WriteBytes;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<InputStreamRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_IoMemoryInterface_OpenInputStream = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_OpenInputStream;
		#else
		tbl->_IoMemoryInterface_OpenInputStream = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_OpenInputStream;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<OutputStreamRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_IoMemoryInterface_OpenOutputStream = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_OpenOutputStream;
		#else
		tbl->_IoMemoryInterface_OpenOutputStream = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_OpenOutputStream;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<InOutputStreamRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_IoMemoryInterface_OpenInOutputStream = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_OpenInOutputStream;
		#else
		tbl->_IoMemoryInterface_OpenInOutputStream = &Hxx2::Wrapper<Hxx2::Unresolved>::_IoMemoryInterface_OpenInOutputStream;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(IoMemoryInterface, "net.maxon.interface.iomemory", nullptr);
	template <typename DUMMY> maxon::Int IoMemoryInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<const Char&>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_iomemory(0
	| maxon::IoMemoryInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
