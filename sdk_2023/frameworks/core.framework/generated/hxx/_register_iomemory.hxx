#if 1
namespace maxon
{
	const maxon::Char* const IoMemoryInterface::MTable::_ids = 
		"Free@73681993548f3a26\0" // void Free(const IoMemoryInterface* object)
		"Alloc@fdcf59a3115a044f\0" // IoMemoryInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"Alloc@fbd2f160ab5fe264\0" // IoMemoryInterface* Alloc(const maxon::SourceLocation& allocLocation, const IoMemoryInterface& src)
		"PrepareReadBuffer@19680bffe9e3d052\0" // Result<void> PrepareReadBuffer(const Block<const Char>& buffer, const FreeBufferCallback& freeBufferCallback)
		"Reset@c49f7df11faba36e\0" // Result<void> Reset(Int size)
		"operatorIndex@7068d6d720d11d34\0" // const Char& operatorIndex(Int idx)
		"GetSize@7d0e6f3d29c239e7\0" // Int GetSize() const
		"IsWritable@12e73654e6d65520\0" // Bool IsWritable() const
		"GetUrl@d2fb7b7fcfe4e778\0" // Result<Url> GetUrl() const
		"ReadBytes@bb0d7af98f135360\0" // Result<void> ReadBytes(Int position, const Block<Byte>& data) const
		"ReadBytesEOS@8467aeb83c2fad89\0" // Result<Int> ReadBytesEOS(Int position, const Block<Byte>& data) const
		"WriteBytes@84a25485244d5a57\0" // Result<void> WriteBytes(Int position, const Block<const Byte>& data)
		"OpenInputStream@7b1d04d61287c4a5\0" // Result<InputStreamRef> OpenInputStream(OPENSTREAMFLAGS flags) const
		"OpenOutputStream@757efee960d697b8\0" // Result<OutputStreamRef> OpenOutputStream(OPENSTREAMFLAGS flags)
		"OpenInOutputStream@bf604a61681e719f\0" // Result<InOutputStreamRef> OpenInOutputStream(OPENSTREAMFLAGS flags)
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
		tbl->IoMemoryInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->IoMemoryInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->IoMemoryInterface_Alloc_1 = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_Alloc_1), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_Alloc_1);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->IoMemoryInterface_PrepareReadBuffer = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_PrepareReadBuffer), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_PrepareReadBuffer);
		#else
		tbl->IoMemoryInterface_PrepareReadBuffer = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_PrepareReadBuffer), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_PrepareReadBuffer);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->IoMemoryInterface_Reset = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_Reset), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_Reset);
		#else
		tbl->IoMemoryInterface_Reset = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_Reset), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_Reset);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<const Char&>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->IoMemoryInterface_operatorIndex = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_operatorIndex), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_operatorIndex);
		#else
		tbl->IoMemoryInterface_operatorIndex = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_operatorIndex), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_operatorIndex);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->IoMemoryInterface_GetSize = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_GetSize), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_GetSize);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->IoMemoryInterface_IsWritable = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_IsWritable), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_IsWritable);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Url>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->IoMemoryInterface_GetUrl = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_GetUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_GetUrl);
		#else
		tbl->IoMemoryInterface_GetUrl = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_GetUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_GetUrl);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->IoMemoryInterface_ReadBytes = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_ReadBytes), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_ReadBytes);
		#else
		tbl->IoMemoryInterface_ReadBytes = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_ReadBytes), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_ReadBytes);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->IoMemoryInterface_ReadBytesEOS = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_ReadBytesEOS), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_ReadBytesEOS);
		#else
		tbl->IoMemoryInterface_ReadBytesEOS = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_ReadBytesEOS), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_ReadBytesEOS);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->IoMemoryInterface_WriteBytes = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_WriteBytes), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_WriteBytes);
		#else
		tbl->IoMemoryInterface_WriteBytes = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_WriteBytes), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_WriteBytes);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<InputStreamRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->IoMemoryInterface_OpenInputStream = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_OpenInputStream), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_OpenInputStream);
		#else
		tbl->IoMemoryInterface_OpenInputStream = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_OpenInputStream), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_OpenInputStream);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<OutputStreamRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->IoMemoryInterface_OpenOutputStream = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_OpenOutputStream), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_OpenOutputStream);
		#else
		tbl->IoMemoryInterface_OpenOutputStream = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_OpenOutputStream), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_OpenOutputStream);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<InOutputStreamRef>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->IoMemoryInterface_OpenInOutputStream = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_OpenInOutputStream), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_OpenInOutputStream);
		#else
		tbl->IoMemoryInterface_OpenInOutputStream = PRIVATE_MAXON_MF_CAST(decltype(IoMemoryInterface_OpenInOutputStream), &Hxx2::Wrapper<Hxx2::Unresolved>::IoMemoryInterface_OpenInOutputStream);
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
