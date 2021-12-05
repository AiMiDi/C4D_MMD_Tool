
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct IoMemoryInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	void (*_IoMemoryInterface_Free) (const IoMemoryInterface* object);
	IoMemoryInterface* (*_IoMemoryInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	IoMemoryInterface* (*_IoMemoryInterface_Alloc_1) (const maxon::SourceLocation& allocLocation, const IoMemoryInterface& src);
	Result<void> (*_IoMemoryInterface_PrepareReadBuffer) (IoMemoryInterface* this_, const Block<const Char>& buffer, const FreeBufferCallback& freeBufferCallback);
	Result<void> (*_IoMemoryInterface_Reset) (IoMemoryInterface* this_, Int size);
	const Char& (*_IoMemoryInterface_operatorIndex) (IoMemoryInterface* this_, Int idx);
	Int (*_IoMemoryInterface_GetSize) (const IoMemoryInterface* this_);
	Bool (*_IoMemoryInterface_IsWritable) (const IoMemoryInterface* this_);
	Result<Url> (*_IoMemoryInterface_GetUrl) (const IoMemoryInterface* this_);
	Result<void> (*_IoMemoryInterface_ReadBytes) (const IoMemoryInterface* this_, Int position, const Block<Byte>& data);
	Result<Int> (*_IoMemoryInterface_ReadBytesEOS) (const IoMemoryInterface* this_, Int position, const Block<Byte>& data);
	Result<void> (*_IoMemoryInterface_WriteBytes) (IoMemoryInterface* this_, Int position, const Block<const Byte>& data);
	Result<InputStreamRef> (*_IoMemoryInterface_OpenInputStream) (const IoMemoryInterface* this_, OPENSTREAMFLAGS flags);
	Result<OutputStreamRef> (*_IoMemoryInterface_OpenOutputStream) (IoMemoryInterface* this_, OPENSTREAMFLAGS flags);
	Result<InOutputStreamRef> (*_IoMemoryInterface_OpenInOutputStream) (IoMemoryInterface* this_, OPENSTREAMFLAGS flags);
	template <typename IMPL> void Init()
	{
		_IoMemoryInterface_Free = &IMPL::_IoMemoryInterface_Free;
		_IoMemoryInterface_Alloc = &IMPL::_IoMemoryInterface_Alloc;
		_IoMemoryInterface_Alloc_1 = &IMPL::_IoMemoryInterface_Alloc_1;
		_IoMemoryInterface_PrepareReadBuffer = &IMPL::_IoMemoryInterface_PrepareReadBuffer;
		_IoMemoryInterface_Reset = &IMPL::_IoMemoryInterface_Reset;
		_IoMemoryInterface_operatorIndex = &IMPL::_IoMemoryInterface_operatorIndex;
		_IoMemoryInterface_GetSize = &IMPL::_IoMemoryInterface_GetSize;
		_IoMemoryInterface_IsWritable = &IMPL::_IoMemoryInterface_IsWritable;
		_IoMemoryInterface_GetUrl = &IMPL::_IoMemoryInterface_GetUrl;
		_IoMemoryInterface_ReadBytes = &IMPL::_IoMemoryInterface_ReadBytes;
		_IoMemoryInterface_ReadBytesEOS = &IMPL::_IoMemoryInterface_ReadBytesEOS;
		_IoMemoryInterface_WriteBytes = &IMPL::_IoMemoryInterface_WriteBytes;
		_IoMemoryInterface_OpenInputStream = &IMPL::_IoMemoryInterface_OpenInputStream;
		_IoMemoryInterface_OpenOutputStream = &IMPL::_IoMemoryInterface_OpenOutputStream;
		_IoMemoryInterface_OpenInOutputStream = &IMPL::_IoMemoryInterface_OpenInOutputStream;
	}
};

struct IoMemoryInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static void _IoMemoryInterface_Free(const IoMemoryInterface* object) { return C::Free(object); }
	static IoMemoryInterface* _IoMemoryInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
	static IoMemoryInterface* _IoMemoryInterface_Alloc_1(const maxon::SourceLocation& allocLocation, const IoMemoryInterface& src) { return C::Alloc(allocLocation, ((const C&) src)); }
	static Result<void> _IoMemoryInterface_PrepareReadBuffer(IoMemoryInterface* this_, const Block<const Char>& buffer, const FreeBufferCallback& freeBufferCallback) { return ((C*) this_)->PrepareReadBuffer(buffer, freeBufferCallback); }
	static Result<void> _IoMemoryInterface_Reset(IoMemoryInterface* this_, Int size) { return ((C*) this_)->Reset(size); }
	static const Char& _IoMemoryInterface_operatorIndex(IoMemoryInterface* this_, Int idx) { return ((C*) this_)->operator [](idx); }
	static Int _IoMemoryInterface_GetSize(const IoMemoryInterface* this_) { return ((const C*) this_)->GetSize(); }
	static Bool _IoMemoryInterface_IsWritable(const IoMemoryInterface* this_) { return ((const C*) this_)->IsWritable(); }
	static Result<Url> _IoMemoryInterface_GetUrl(const IoMemoryInterface* this_) { return ((const C*) this_)->GetUrl(); }
	static Result<void> _IoMemoryInterface_ReadBytes(const IoMemoryInterface* this_, Int position, const Block<Byte>& data) { return ((const C*) this_)->ReadBytes(position, data); }
	static Result<Int> _IoMemoryInterface_ReadBytesEOS(const IoMemoryInterface* this_, Int position, const Block<Byte>& data) { return ((const C*) this_)->ReadBytesEOS(position, data); }
	static Result<void> _IoMemoryInterface_WriteBytes(IoMemoryInterface* this_, Int position, const Block<const Byte>& data) { return ((C*) this_)->WriteBytes(position, data); }
	static Result<InputStreamRef> _IoMemoryInterface_OpenInputStream(const IoMemoryInterface* this_, OPENSTREAMFLAGS flags) { return ((const C*) this_)->OpenInputStream(flags); }
	static Result<OutputStreamRef> _IoMemoryInterface_OpenOutputStream(IoMemoryInterface* this_, OPENSTREAMFLAGS flags) { return ((C*) this_)->OpenOutputStream(flags); }
	static Result<InOutputStreamRef> _IoMemoryInterface_OpenInOutputStream(IoMemoryInterface* this_, OPENSTREAMFLAGS flags) { return ((C*) this_)->OpenInOutputStream(flags); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Free(const IoMemoryInterface* object) -> void
{
	return MTable::_instance._IoMemoryInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Alloc(const maxon::SourceLocation& allocLocation) -> IoMemoryInterface*
{
	return MTable::_instance._IoMemoryInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Alloc(const maxon::SourceLocation& allocLocation, const IoMemoryInterface& src) -> IoMemoryInterface*
{
	return MTable::_instance._IoMemoryInterface_Alloc_1(allocLocation, src);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::PrepareReadBuffer(const Block<const Char>& buffer, const FreeBufferCallback& freeBufferCallback) -> Result<void>
{
	return MTable::_instance._IoMemoryInterface_PrepareReadBuffer(this, buffer, freeBufferCallback);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Reset(Int size) -> Result<void>
{
	return MTable::_instance._IoMemoryInterface_Reset(this, size);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::operator [](Int idx) -> const Char&
{
	return MTable::_instance._IoMemoryInterface_operatorIndex(this, idx);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::GetSize() const -> Int
{
	return MTable::_instance._IoMemoryInterface_GetSize(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::IsWritable() const -> Bool
{
	return MTable::_instance._IoMemoryInterface_IsWritable(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::GetUrl() const -> Result<Url>
{
	return MTable::_instance._IoMemoryInterface_GetUrl(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::ReadBytes(Int position, const Block<Byte>& data) const -> Result<void>
{
	return MTable::_instance._IoMemoryInterface_ReadBytes(this, position, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::ReadBytesEOS(Int position, const Block<Byte>& data) const -> Result<Int>
{
	return MTable::_instance._IoMemoryInterface_ReadBytesEOS(this, position, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::WriteBytes(Int position, const Block<const Byte>& data) -> Result<void>
{
	return MTable::_instance._IoMemoryInterface_WriteBytes(this, position, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::OpenInputStream(OPENSTREAMFLAGS flags) const -> Result<InputStreamRef>
{
	return MTable::_instance._IoMemoryInterface_OpenInputStream(this, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::OpenOutputStream(OPENSTREAMFLAGS flags) -> Result<OutputStreamRef>
{
	return MTable::_instance._IoMemoryInterface_OpenOutputStream(this, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::OpenInOutputStream(OPENSTREAMFLAGS flags) -> Result<InOutputStreamRef>
{
	return MTable::_instance._IoMemoryInterface_OpenInOutputStream(this, flags);
}

auto IoMemoryInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<IoMemoryRef>
{
	IoMemoryInterface* res_ = IoMemoryInterface::Alloc(MAXON_SOURCE_LOCATION);
	return IoMemoryRef(maxon::ForwardResultPtr<IoMemoryInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ReferenceFunctionsImpl<S>::PrepareReadBuffer(const Block<const Char>& buffer, const FreeBufferCallback& freeBufferCallback) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoMemoryInterface* o_ = (IoMemoryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._IoMemoryInterface_PrepareReadBuffer(o_, buffer, freeBufferCallback));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ReferenceFunctionsImpl<S>::Reset(Int size) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoMemoryInterface* o_ = (IoMemoryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._IoMemoryInterface_Reset(o_, size));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ReferenceFunctionsImpl<S>::operator [](Int idx) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Char&>, const Char&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Char&>, const Char&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoMemoryInterface* o_ = (IoMemoryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateIncompleteNullReturnValue<const Char&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); 
	return (MTable::_instance._IoMemoryInterface_operatorIndex(o_, idx));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSize() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Int>, Int>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoMemoryInterface* o_ = (const IoMemoryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoMemoryInterface::NullValuePtr(); if (!o_) return 0; } 
	return (MTable::_instance._IoMemoryInterface_GetSize(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IsWritable() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoMemoryInterface* o_ = (const IoMemoryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoMemoryInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } 
	return (MTable::_instance._IoMemoryInterface_IsWritable(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetUrl() const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoMemoryInterface* o_ = (const IoMemoryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoMemoryInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._IoMemoryInterface_GetUrl(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ReadBytes(Int position, const Block<Byte>& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoMemoryInterface* o_ = (const IoMemoryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoMemoryInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._IoMemoryInterface_ReadBytes(o_, position, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::ReadBytesEOS(Int position, const Block<Byte>& data) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoMemoryInterface* o_ = (const IoMemoryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoMemoryInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._IoMemoryInterface_ReadBytesEOS(o_, position, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ReferenceFunctionsImpl<S>::WriteBytes(Int position, const Block<const Byte>& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoMemoryInterface* o_ = (IoMemoryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._IoMemoryInterface_WriteBytes(o_, position, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ConstReferenceFunctionsImpl<S>::OpenInputStream(OPENSTREAMFLAGS flags) const -> Result<InputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<InputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoMemoryInterface* o_ = (const IoMemoryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoMemoryInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } 
	return (MTable::_instance._IoMemoryInterface_OpenInputStream(o_, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ReferenceFunctionsImpl<S>::OpenOutputStream(OPENSTREAMFLAGS flags) const -> Result<OutputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<OutputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoMemoryInterface* o_ = (IoMemoryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._IoMemoryInterface_OpenOutputStream(o_, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoMemoryInterface::Hxx1::ReferenceFunctionsImpl<S>::OpenInOutputStream(OPENSTREAMFLAGS flags) const -> Result<InOutputStreamRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<InOutputStreamRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoMemoryInterface* o_ = (IoMemoryInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (MTable::_instance._IoMemoryInterface_OpenInOutputStream(o_, flags));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
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

