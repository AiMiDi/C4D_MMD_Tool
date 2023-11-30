
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* IoMemoryInterface::PrivateGetCppName() { return "maxon::IoMemoryRef"; }

struct IoMemoryInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(IoMemoryInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const IoMemoryInterface* object);
	PRIVATE_MAXON_SF_POINTER(IoMemoryInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (IoMemoryInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_SF_POINTER(IoMemoryInterface_Alloc_1, Alloc, MAXON_IGNORE_VA_ARGS, (IoMemoryInterface*), const maxon::SourceLocation& allocLocation, const IoMemoryInterface& src);
	PRIVATE_MAXON_MF_POINTER(IoMemoryInterface_PrepareReadBuffer, PrepareReadBuffer, false, IoMemoryInterface,, (Result<void>), const Block<const Char>& buffer, const FreeBufferCallback& freeBufferCallback);
	PRIVATE_MAXON_MF_POINTER(IoMemoryInterface_Reset, Reset, false, IoMemoryInterface,, (Result<void>), Int size);
	PRIVATE_MAXON_MF_POINTER(IoMemoryInterface_operatorIndex, operatorIndex, false, IoMemoryInterface,, (const Char&), Int idx);
	PRIVATE_MAXON_MF_POINTER(IoMemoryInterface_GetSize, GetSize, false, IoMemoryInterface, const, (Int));
	PRIVATE_MAXON_MF_POINTER(IoMemoryInterface_IsWritable, IsWritable, false, IoMemoryInterface, const, (Bool));
	PRIVATE_MAXON_MF_POINTER(IoMemoryInterface_GetUrl, GetUrl, false, IoMemoryInterface, const, (Result<Url>));
	PRIVATE_MAXON_MF_POINTER(IoMemoryInterface_ReadBytes, ReadBytes, false, IoMemoryInterface, const, (Result<void>), Int position, const Block<Byte>& data);
	PRIVATE_MAXON_MF_POINTER(IoMemoryInterface_ReadBytesEOS, ReadBytesEOS, false, IoMemoryInterface, const, (Result<Int>), Int position, const Block<Byte>& data);
	PRIVATE_MAXON_MF_POINTER(IoMemoryInterface_WriteBytes, WriteBytes, false, IoMemoryInterface,, (Result<void>), Int position, const Block<const Byte>& data);
	PRIVATE_MAXON_MF_POINTER(IoMemoryInterface_OpenInputStream, OpenInputStream, false, IoMemoryInterface, const, (Result<InputStreamRef>), OPENSTREAMFLAGS flags);
	PRIVATE_MAXON_MF_POINTER(IoMemoryInterface_OpenOutputStream, OpenOutputStream, false, IoMemoryInterface,, (Result<OutputStreamRef>), OPENSTREAMFLAGS flags);
	PRIVATE_MAXON_MF_POINTER(IoMemoryInterface_OpenInOutputStream, OpenInOutputStream, false, IoMemoryInterface,, (Result<InOutputStreamRef>), OPENSTREAMFLAGS flags);
	template <typename IMPL> void Init()
	{
		IoMemoryInterface_Free = IoMemoryInterface_Free_GetPtr<IMPL>(true);
		IoMemoryInterface_Alloc = IoMemoryInterface_Alloc_GetPtr<IMPL>(true);
		IoMemoryInterface_Alloc_1 = IoMemoryInterface_Alloc_1_GetPtr<IMPL>(true);
		IoMemoryInterface_PrepareReadBuffer = IoMemoryInterface_PrepareReadBuffer_GetPtr<IMPL>(0, true).first;
		IoMemoryInterface_Reset = IoMemoryInterface_Reset_GetPtr<IMPL>(0, true).first;
		IoMemoryInterface_operatorIndex = IoMemoryInterface_operatorIndex_GetPtr<IMPL>(0, true).first;
		IoMemoryInterface_GetSize = IoMemoryInterface_GetSize_GetPtr<IMPL>(0, true).first;
		IoMemoryInterface_IsWritable = IoMemoryInterface_IsWritable_GetPtr<IMPL>(0, true).first;
		IoMemoryInterface_GetUrl = IoMemoryInterface_GetUrl_GetPtr<IMPL>(0, true).first;
		IoMemoryInterface_ReadBytes = IoMemoryInterface_ReadBytes_GetPtr<IMPL>(0, true).first;
		IoMemoryInterface_ReadBytesEOS = IoMemoryInterface_ReadBytesEOS_GetPtr<IMPL>(0, true).first;
		IoMemoryInterface_WriteBytes = IoMemoryInterface_WriteBytes_GetPtr<IMPL>(0, true).first;
		IoMemoryInterface_OpenInputStream = IoMemoryInterface_OpenInputStream_GetPtr<IMPL>(0, true).first;
		IoMemoryInterface_OpenOutputStream = IoMemoryInterface_OpenOutputStream_GetPtr<IMPL>(0, true).first;
		IoMemoryInterface_OpenInOutputStream = IoMemoryInterface_OpenInOutputStream_GetPtr<IMPL>(0, true).first;
	}
};

struct IoMemoryInterface::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static void IoMemoryInterface_Free(const IoMemoryInterface* object) { return S::Free(object); }
		static IoMemoryInterface* IoMemoryInterface_Alloc(const maxon::SourceLocation& allocLocation) { return S::Alloc(allocLocation); }
		static IoMemoryInterface* IoMemoryInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const IoMemoryInterface& src) { return S::Alloc(allocLocation, ((const S&) src)); }
		PRIVATE_MAXON_MF_WRAPPER(IoMemoryInterface_PrepareReadBuffer, IoMemoryInterface,, (Result<void>), const Block<const Char>& buffer, const FreeBufferCallback& freeBufferCallback) { return S::Get(PRIVATE_MAXON_MF_THIS(IoMemoryInterface))->PrepareReadBuffer(buffer, freeBufferCallback); }
		PRIVATE_MAXON_MF_WRAPPER(IoMemoryInterface_Reset, IoMemoryInterface,, (Result<void>), Int size) { return S::Get(PRIVATE_MAXON_MF_THIS(IoMemoryInterface))->Reset(size); }
		PRIVATE_MAXON_MF_WRAPPER(IoMemoryInterface_operatorIndex, IoMemoryInterface,, (const Char&), Int idx) { return S::Get(PRIVATE_MAXON_MF_THIS(IoMemoryInterface))->operator [](idx); }
		PRIVATE_MAXON_MF_WRAPPER(IoMemoryInterface_GetSize, IoMemoryInterface, const, (Int)) { return S::Get(PRIVATE_MAXON_MF_THIS(const IoMemoryInterface))->GetSize(); }
		PRIVATE_MAXON_MF_WRAPPER(IoMemoryInterface_IsWritable, IoMemoryInterface, const, (Bool)) { return S::Get(PRIVATE_MAXON_MF_THIS(const IoMemoryInterface))->IsWritable(); }
		PRIVATE_MAXON_MF_WRAPPER(IoMemoryInterface_GetUrl, IoMemoryInterface, const, (Result<Url>)) { return S::Get(PRIVATE_MAXON_MF_THIS(const IoMemoryInterface))->GetUrl(); }
		PRIVATE_MAXON_MF_WRAPPER(IoMemoryInterface_ReadBytes, IoMemoryInterface, const, (Result<void>), Int position, const Block<Byte>& data) { return S::Get(PRIVATE_MAXON_MF_THIS(const IoMemoryInterface))->ReadBytes(position, data); }
		PRIVATE_MAXON_MF_WRAPPER(IoMemoryInterface_ReadBytesEOS, IoMemoryInterface, const, (Result<Int>), Int position, const Block<Byte>& data) { return S::Get(PRIVATE_MAXON_MF_THIS(const IoMemoryInterface))->ReadBytesEOS(position, data); }
		PRIVATE_MAXON_MF_WRAPPER(IoMemoryInterface_WriteBytes, IoMemoryInterface,, (Result<void>), Int position, const Block<const Byte>& data) { return S::Get(PRIVATE_MAXON_MF_THIS(IoMemoryInterface))->WriteBytes(position, data); }
		PRIVATE_MAXON_MF_WRAPPER(IoMemoryInterface_OpenInputStream, IoMemoryInterface, const, (Result<InputStreamRef>), OPENSTREAMFLAGS flags) { return S::Get(PRIVATE_MAXON_MF_THIS(const IoMemoryInterface))->OpenInputStream(flags); }
		PRIVATE_MAXON_MF_WRAPPER(IoMemoryInterface_OpenOutputStream, IoMemoryInterface,, (Result<OutputStreamRef>), OPENSTREAMFLAGS flags) { return S::Get(PRIVATE_MAXON_MF_THIS(IoMemoryInterface))->OpenOutputStream(flags); }
		PRIVATE_MAXON_MF_WRAPPER(IoMemoryInterface_OpenInOutputStream, IoMemoryInterface,, (Result<InOutputStreamRef>), OPENSTREAMFLAGS flags) { return S::Get(PRIVATE_MAXON_MF_THIS(IoMemoryInterface))->OpenInOutputStream(flags); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Free(const IoMemoryInterface* object) -> void
{
	return MTable::_instance.IoMemoryInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Alloc(const maxon::SourceLocation& allocLocation) -> IoMemoryInterface*
{
	return MTable::_instance.IoMemoryInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Alloc(const maxon::SourceLocation& allocLocation, const IoMemoryInterface& src) -> IoMemoryInterface*
{
	return MTable::_instance.IoMemoryInterface_Alloc_1(allocLocation, src);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::PrepareReadBuffer(const Block<const Char>& buffer, const FreeBufferCallback& freeBufferCallback) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.IoMemoryInterface_PrepareReadBuffer, buffer, freeBufferCallback);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Reset(Int size) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.IoMemoryInterface_Reset, size);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::operator [](Int idx) -> const Char&
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.IoMemoryInterface_operatorIndex, idx);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::GetSize() const -> Int
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.IoMemoryInterface_GetSize);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::IsWritable() const -> Bool
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.IoMemoryInterface_IsWritable);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::GetUrl() const -> Result<Url>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.IoMemoryInterface_GetUrl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::ReadBytes(Int position, const Block<Byte>& data) const -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.IoMemoryInterface_ReadBytes, position, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::ReadBytesEOS(Int position, const Block<Byte>& data) const -> Result<Int>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.IoMemoryInterface_ReadBytesEOS, position, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::WriteBytes(Int position, const Block<const Byte>& data) -> Result<void>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.IoMemoryInterface_WriteBytes, position, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::OpenInputStream(OPENSTREAMFLAGS flags) const -> Result<InputStreamRef>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.IoMemoryInterface_OpenInputStream, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::OpenOutputStream(OPENSTREAMFLAGS flags) -> Result<OutputStreamRef>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.IoMemoryInterface_OpenOutputStream, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::OpenInOutputStream(OPENSTREAMFLAGS flags) -> Result<InOutputStreamRef>
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.IoMemoryInterface_OpenInOutputStream, flags);
}

auto IoMemoryInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<IoMemoryRef>
{
	IoMemoryInterface* res_ = IoMemoryInterface::Alloc(MAXON_SOURCE_LOCATION);
	return IoMemoryRef(maxon::ForwardResultPtr<IoMemoryInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::Fn<S>::PrepareReadBuffer(const Block<const Char>& buffer, const FreeBufferCallback& freeBufferCallback) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.IoMemoryInterface_PrepareReadBuffer, buffer, freeBufferCallback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::Fn<S>::Reset(Int size) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.IoMemoryInterface_Reset, size));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::Fn<S>::operator [](Int idx) const -> HXXADDRET2(const Char&)
{
	HXXRETURN0(HXXADDRET2(const Char&)); HXXRES; HXXNONCONST(, , false, HXXRET3(NULLPTR, const Char&)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.IoMemoryInterface_operatorIndex, idx));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ConstFn<S>::GetSize() const -> HXXADDRET2(Int)
{
	HXXRETURN0(HXXADDRET2(Int)); HXXRES; HXXCONST(0) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.IoMemoryInterface_GetSize));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ConstFn<S>::IsWritable() const -> HXXADDRET2(Bool)
{
	HXXRETURN0(HXXADDRET2(Bool)); HXXRES; HXXCONST(maxon::PrivateLogNullptrError(false)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.IoMemoryInterface_IsWritable));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ConstFn<S>::GetUrl() const -> Result<Url>
{
	HXXRETURN0(Result<Url>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.IoMemoryInterface_GetUrl));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ConstFn<S>::ReadBytes(Int position, const Block<Byte>& data) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.IoMemoryInterface_ReadBytes, position, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ConstFn<S>::ReadBytesEOS(Int position, const Block<Byte>& data) const -> Result<Int>
{
	HXXRETURN0(Result<Int>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.IoMemoryInterface_ReadBytesEOS, position, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::Fn<S>::WriteBytes(Int position, const Block<const Byte>& data) const -> Result<void>
{
	HXXRETURN0(Result<void>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.IoMemoryInterface_WriteBytes, position, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ConstFn<S>::OpenInputStream(OPENSTREAMFLAGS flags) const -> Result<InputStreamRef>
{
	HXXRETURN0(Result<InputStreamRef>); HXXRES; HXXCONST(HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.IoMemoryInterface_OpenInputStream, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::Fn<S>::OpenOutputStream(OPENSTREAMFLAGS flags) const -> Result<OutputStreamRef>
{
	HXXRETURN0(Result<OutputStreamRef>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.IoMemoryInterface_OpenOutputStream, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::Fn<S>::OpenInOutputStream(OPENSTREAMFLAGS flags) const -> Result<InOutputStreamRef>
{
	HXXRETURN0(Result<InOutputStreamRef>); HXXRES; HXXNONCONST(, , false, HXXRET1(NULLPTR)) 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.IoMemoryInterface_OpenInOutputStream, flags));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_iomemory)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_IoMemoryInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_IoMemoryInterface() { new (s_ui_maxon_IoMemoryInterface) maxon::EntityUse(IoMemoryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iomemory.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_IoMemoryInterface(IoMemoryInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iomemory.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

