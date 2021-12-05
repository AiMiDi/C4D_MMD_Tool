
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct IoErrorInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetUrl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetUrl);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	void (*_IoErrorInterface_SetUrl) (maxon::GenericComponent* this_, const Url& url);
	maxon::Int _IoErrorInterface_SetUrl_Offset;
	const Url& (*_IoErrorInterface_GetUrl) (const maxon::GenericComponent* this_);
	maxon::Int _IoErrorInterface_GetUrl_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoErrorInterface, SetUrl))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoErrorInterface, SetUrl), W, MTable>::type::_IoErrorInterface_SetUrl;
			_IoErrorInterface_SetUrl = reinterpret_cast<const decltype(_IoErrorInterface_SetUrl)&>(ptr);
			_IoErrorInterface_SetUrl_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoErrorInterface, GetUrl))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoErrorInterface, GetUrl), W, MTable>::type::_IoErrorInterface_GetUrl;
			_IoErrorInterface_GetUrl = reinterpret_cast<const decltype(_IoErrorInterface_GetUrl)&>(ptr);
			_IoErrorInterface_GetUrl_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<IoErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(IoErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct IoErrorInterface::Hxx2
{
	template <typename S> class Wrapper : public ErrorInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetUrl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetUrl);
	static void _IoErrorInterface_SetUrl(maxon::GenericComponent* this_, const Url& url) { return ((typename S::Implementation*) this_)->SetUrl(url); }
	static const Url& _IoErrorInterface_GetUrl(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetUrl(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto IoErrorInterface::SetUrl(const Url& url) -> void
{
	const IoErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoErrorInterface, this); return mt_._IoErrorInterface_SetUrl((maxon::GenericComponent*) this + mt_._IoErrorInterface_SetUrl_Offset, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoErrorInterface::GetUrl() const -> const Url&
{
	const IoErrorInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoErrorInterface, this); return mt_._IoErrorInterface_GetUrl((const maxon::GenericComponent*) this + mt_._IoErrorInterface_GetUrl_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoErrorInterface::Hxx1::ReferenceFunctionsImpl<S>::SetUrl(const Url& url) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoErrorInterface* o_ = (IoErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoErrorInterface, o_, IoErrorInterface_SetUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoErrorInterface>() : PRIVATE_MAXON_VTABLE(IoErrorInterface, o_); 
	mt_._IoErrorInterface_SetUrl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoErrorInterface_SetUrl_Offset, url);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoErrorInterface::Hxx1::COWReferenceFunctionsImpl<S>::SetUrl(const Url& url) -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); IoErrorInterface* o_ = (IoErrorInterface*) this->MakeWritable(false).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoErrorInterface, o_, IoErrorInterface_SetUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoErrorInterface>() : PRIVATE_MAXON_VTABLE(IoErrorInterface, o_); 
	mt_._IoErrorInterface_SetUrl(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoErrorInterface_SetUrl_Offset, url);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoErrorInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetUrl() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Url&>, const Url&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoErrorInterface* o_ = (const IoErrorInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoErrorInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoErrorInterface, o_, IoErrorInterface_GetUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoErrorInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoErrorInterface>() : PRIVATE_MAXON_VTABLE(IoErrorInterface, o_); 
	return (mt_._IoErrorInterface_GetUrl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoErrorInterface_GetUrl_Offset));
}
auto IoErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto IoErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_IoErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_IoErrorInterface() { new (s_ui_maxon_IoErrorInterface) maxon::EntityUse(IoErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_IoErrorInterface(IoErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct FileFormatErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!IoErrorInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<FileFormatErrorInterface, typename IoErrorInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(FileFormatErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct FileFormatErrorInterface::Hxx2
{
	template <typename S> class Wrapper : public IoErrorInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

auto FileFormatErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto FileFormatErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_FileFormatErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_FileFormatErrorInterface() { new (s_ui_maxon_FileFormatErrorInterface) maxon::EntityUse(FileFormatErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_FileFormatErrorInterface(FileFormatErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
namespace STREAMFLAGS
{
	struct HTTP_REMOTEADDRESS_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x03711e14f40d7269LL), maxon::UInt(35))> { };
	struct HTTP_HEADER_PrivateAttribute::HASHCODE : public std::integral_constant<maxon::UInt, PRIVATE_MAXON_ID_HASHCODE(maxon::UInt(0x905f8c6586b33d72LL), maxon::UInt(28))> { };
}

struct UnknownFileSizeErrorInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ErrorInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<UnknownFileSizeErrorInterface, typename ErrorInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(UnknownFileSizeErrorInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct UnknownFileSizeErrorInterface::Hxx2
{
	template <typename S> class Wrapper : public ErrorInterface::Hxx2::template Wrapper<S>
	{
	public:
	};

};

auto UnknownFileSizeErrorInterface::GetPtr() -> Ptr { return Ptr(this); }
auto UnknownFileSizeErrorInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_UnknownFileSizeErrorInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_UnknownFileSizeErrorInterface() { new (s_ui_maxon_UnknownFileSizeErrorInterface) maxon::EntityUse(UnknownFileSizeErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_UnknownFileSizeErrorInterface(UnknownFileSizeErrorInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct BaseStreamInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Close);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(DisableBuffering);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetPosition);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetStreamLength);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Seek);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SeekSupported);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<Int64> (*_BaseStreamInterface_GetStreamLength) (const maxon::GenericComponent* this_);
	maxon::Int _BaseStreamInterface_GetStreamLength_Offset;
	Result<Int64> (*_BaseStreamInterface_GetPosition) (const maxon::GenericComponent* this_);
	maxon::Int _BaseStreamInterface_GetPosition_Offset;
	Result<void> (*_BaseStreamInterface_Close) (maxon::GenericComponent* this_);
	maxon::Int _BaseStreamInterface_Close_Offset;
	Bool (*_BaseStreamInterface_SeekSupported) (const maxon::GenericComponent* this_);
	maxon::Int _BaseStreamInterface_SeekSupported_Offset;
	Result<void> (*_BaseStreamInterface_Seek) (maxon::GenericComponent* this_, Int64 position);
	maxon::Int _BaseStreamInterface_Seek_Offset;
	void (*_BaseStreamInterface_DisableBuffering) (maxon::GenericComponent* this_);
	maxon::Int _BaseStreamInterface_DisableBuffering_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, GetStreamLength))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, GetStreamLength), W, MTable>::type::_BaseStreamInterface_GetStreamLength;
			_BaseStreamInterface_GetStreamLength = reinterpret_cast<const decltype(_BaseStreamInterface_GetStreamLength)&>(ptr);
			_BaseStreamInterface_GetStreamLength_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, GetPosition))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, GetPosition), W, MTable>::type::_BaseStreamInterface_GetPosition;
			_BaseStreamInterface_GetPosition = reinterpret_cast<const decltype(_BaseStreamInterface_GetPosition)&>(ptr);
			_BaseStreamInterface_GetPosition_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, Close))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, Close), W, MTable>::type::_BaseStreamInterface_Close;
			_BaseStreamInterface_Close = reinterpret_cast<const decltype(_BaseStreamInterface_Close)&>(ptr);
			_BaseStreamInterface_Close_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, SeekSupported))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, SeekSupported), W, MTable>::type::_BaseStreamInterface_SeekSupported;
			_BaseStreamInterface_SeekSupported = reinterpret_cast<const decltype(_BaseStreamInterface_SeekSupported)&>(ptr);
			_BaseStreamInterface_SeekSupported_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, Seek))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, Seek), W, MTable>::type::_BaseStreamInterface_Seek;
			_BaseStreamInterface_Seek = reinterpret_cast<const decltype(_BaseStreamInterface_Seek)&>(ptr);
			_BaseStreamInterface_Seek_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, DisableBuffering))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, BaseStreamInterface, DisableBuffering), W, MTable>::type::_BaseStreamInterface_DisableBuffering;
			_BaseStreamInterface_DisableBuffering = reinterpret_cast<const decltype(_BaseStreamInterface_DisableBuffering)&>(ptr);
			_BaseStreamInterface_DisableBuffering_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!DataDictionaryObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<BaseStreamInterface, typename DataDictionaryObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(BaseStreamInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct BaseStreamInterface::Hxx2
{
	template <typename S> class Wrapper : public DataDictionaryObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Close);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(DisableBuffering);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetPosition);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetStreamLength);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Seek);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SeekSupported);
	static Result<Int64> _BaseStreamInterface_GetStreamLength(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetStreamLength(); }
	static Result<Int64> _BaseStreamInterface_GetPosition(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetPosition(); }
	static Result<void> _BaseStreamInterface_Close(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Close(); }
	static Bool _BaseStreamInterface_SeekSupported(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->SeekSupported(); }
	static Result<void> _BaseStreamInterface_Seek(maxon::GenericComponent* this_, Int64 position) { return ((typename S::Implementation*) this_)->Seek(position); }
	static void _BaseStreamInterface_DisableBuffering(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->DisableBuffering(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::GetStreamLength() const -> Result<Int64>
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return mt_._BaseStreamInterface_GetStreamLength((const maxon::GenericComponent*) this + mt_._BaseStreamInterface_GetStreamLength_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::GetPosition() const -> Result<Int64>
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return mt_._BaseStreamInterface_GetPosition((const maxon::GenericComponent*) this + mt_._BaseStreamInterface_GetPosition_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Close() -> Result<void>
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return mt_._BaseStreamInterface_Close((maxon::GenericComponent*) this + mt_._BaseStreamInterface_Close_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::SeekSupported() const -> Bool
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return mt_._BaseStreamInterface_SeekSupported((const maxon::GenericComponent*) this + mt_._BaseStreamInterface_SeekSupported_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Seek(Int64 position) -> Result<void>
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return mt_._BaseStreamInterface_Seek((maxon::GenericComponent*) this + mt_._BaseStreamInterface_Seek_Offset, position);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::DisableBuffering() -> void
{
	const BaseStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(BaseStreamInterface, this); return mt_._BaseStreamInterface_DisableBuffering((maxon::GenericComponent*) this + mt_._BaseStreamInterface_DisableBuffering_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetStreamLength() const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BaseStreamInterface* o_ = (const BaseStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BaseStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_GetStreamLength) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (mt_._BaseStreamInterface_GetStreamLength(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._BaseStreamInterface_GetStreamLength_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetPosition() const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BaseStreamInterface* o_ = (const BaseStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BaseStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_GetPosition) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (mt_._BaseStreamInterface_GetPosition(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._BaseStreamInterface_GetPosition_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::ReferenceFunctionsImpl<S>::Close() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (mt_._BaseStreamInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BaseStreamInterface_Close_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::COWReferenceFunctionsImpl<S>::Close() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_Close) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (mt_._BaseStreamInterface_Close(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BaseStreamInterface_Close_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::ConstReferenceFunctionsImpl<S>::SeekSupported() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Bool>, Bool>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const BaseStreamInterface* o_ = (const BaseStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = BaseStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateLogNullptrError(false); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_SeekSupported) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (mt_._BaseStreamInterface_SeekSupported(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._BaseStreamInterface_SeekSupported_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::ReferenceFunctionsImpl<S>::Seek(Int64 position) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_Seek) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (mt_._BaseStreamInterface_Seek(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BaseStreamInterface_Seek_Offset, position));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::COWReferenceFunctionsImpl<S>::Seek(Int64 position) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_Seek) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	return (mt_._BaseStreamInterface_Seek(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BaseStreamInterface_Seek_Offset, position));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::ReferenceFunctionsImpl<S>::DisableBuffering() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<void>, void>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateLogNullptrError(); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_DisableBuffering) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	mt_._BaseStreamInterface_DisableBuffering(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BaseStreamInterface_DisableBuffering_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto BaseStreamInterface::Hxx1::COWReferenceFunctionsImpl<S>::DisableBuffering() -> typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::DEEP_CONSTNESS), void, maxon::Result<void>>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); BaseStreamInterface* o_ = (BaseStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(BaseStreamInterface, o_, BaseStreamInterface_DisableBuffering) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<BaseStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<BaseStreamInterface>() : PRIVATE_MAXON_VTABLE(BaseStreamInterface, o_); 
	mt_._BaseStreamInterface_DisableBuffering(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._BaseStreamInterface_DisableBuffering_Offset);
	return (typename ReturnHelper::ReturnType) maxon::OK;
}
auto BaseStreamInterface::GetPtr() -> Ptr { return Ptr(this); }
auto BaseStreamInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_BaseStreamInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_BaseStreamInterface() { new (s_ui_maxon_BaseStreamInterface) maxon::EntityUse(BaseStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_BaseStreamInterface(BaseStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct InputStreamInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(BytesAvailable);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ReadEOS);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Skip);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<Int64> (*_InputStreamInterface_BytesAvailable) (const maxon::GenericComponent* this_);
	maxon::Int _InputStreamInterface_BytesAvailable_Offset;
	Result<Int> (*_InputStreamInterface_ReadEOS) (maxon::GenericComponent* this_, const Block<Byte>& data);
	maxon::Int _InputStreamInterface_ReadEOS_Offset;
	Result<void> (*_InputStreamInterface_Skip) (maxon::GenericComponent* this_, Int64 bytes);
	maxon::Int _InputStreamInterface_Skip_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InputStreamInterface, BytesAvailable))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InputStreamInterface, BytesAvailable), W, MTable>::type::_InputStreamInterface_BytesAvailable;
			_InputStreamInterface_BytesAvailable = reinterpret_cast<const decltype(_InputStreamInterface_BytesAvailable)&>(ptr);
			_InputStreamInterface_BytesAvailable_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InputStreamInterface, ReadEOS))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InputStreamInterface, ReadEOS), W, MTable>::type::_InputStreamInterface_ReadEOS;
			_InputStreamInterface_ReadEOS = reinterpret_cast<const decltype(_InputStreamInterface_ReadEOS)&>(ptr);
			_InputStreamInterface_ReadEOS_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InputStreamInterface, Skip))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, InputStreamInterface, Skip), W, MTable>::type::_InputStreamInterface_Skip;
			_InputStreamInterface_Skip = reinterpret_cast<const decltype(_InputStreamInterface_Skip)&>(ptr);
			_InputStreamInterface_Skip_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!BaseStreamInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<InputStreamInterface, typename BaseStreamInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(InputStreamInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct InputStreamInterface::Hxx2
{
	template <typename S> class Wrapper : public BaseStreamInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(BytesAvailable);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ReadEOS);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Skip);
	static Result<Int64> _InputStreamInterface_BytesAvailable(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->BytesAvailable(); }
	static Result<Int> _InputStreamInterface_ReadEOS(maxon::GenericComponent* this_, const Block<Byte>& data) { return ((typename S::Implementation*) this_)->ReadEOS(data); }
	static Result<void> _InputStreamInterface_Skip(maxon::GenericComponent* this_, Int64 bytes) { return ((typename S::Implementation*) this_)->Skip(bytes); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::BytesAvailable() const -> Result<Int64>
{
	const InputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InputStreamInterface, this); return mt_._InputStreamInterface_BytesAvailable((const maxon::GenericComponent*) this + mt_._InputStreamInterface_BytesAvailable_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::ReadEOS(const Block<Byte>& data) -> Result<Int>
{
	const InputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InputStreamInterface, this); return mt_._InputStreamInterface_ReadEOS((maxon::GenericComponent*) this + mt_._InputStreamInterface_ReadEOS_Offset, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Skip(Int64 bytes) -> Result<void>
{
	const InputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(InputStreamInterface, this); return mt_._InputStreamInterface_Skip((maxon::GenericComponent*) this + mt_._InputStreamInterface_Skip_Offset, bytes);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::ConstReferenceFunctionsImpl<S>::BytesAvailable() const -> Result<Int64>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int64>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const InputStreamInterface* o_ = (const InputStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = InputStreamInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InputStreamInterface, o_, InputStreamInterface_BytesAvailable) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<InputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InputStreamInterface>() : PRIVATE_MAXON_VTABLE(InputStreamInterface, o_); 
	return (mt_._InputStreamInterface_BytesAvailable(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._InputStreamInterface_BytesAvailable_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::ReferenceFunctionsImpl<S>::Read(const Block<Byte>& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); 
	return (o_->Read(data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::COWReferenceFunctionsImpl<S>::Read(const Block<Byte>& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; static_assert(!std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value, "Can't invoke MAXON_FUNCTION InputStreamInterface::Read on super."); if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); 
	return (o_->Read(data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::ReferenceFunctionsImpl<S>::ReadEOS(const Block<Byte>& data) const -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InputStreamInterface, o_, InputStreamInterface_ReadEOS) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<InputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InputStreamInterface>() : PRIVATE_MAXON_VTABLE(InputStreamInterface, o_); 
	return (mt_._InputStreamInterface_ReadEOS(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._InputStreamInterface_ReadEOS_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::COWReferenceFunctionsImpl<S>::ReadEOS(const Block<Byte>& data) -> Result<Int>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Int>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InputStreamInterface, o_, InputStreamInterface_ReadEOS) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<InputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InputStreamInterface>() : PRIVATE_MAXON_VTABLE(InputStreamInterface, o_); 
	return (mt_._InputStreamInterface_ReadEOS(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._InputStreamInterface_ReadEOS_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::ReferenceFunctionsImpl<S>::Skip(Int64 bytes) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InputStreamInterface, o_, InputStreamInterface_Skip) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<InputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InputStreamInterface>() : PRIVATE_MAXON_VTABLE(InputStreamInterface, o_); 
	return (mt_._InputStreamInterface_Skip(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._InputStreamInterface_Skip_Offset, bytes));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto InputStreamInterface::Hxx1::COWReferenceFunctionsImpl<S>::Skip(Int64 bytes) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); InputStreamInterface* o_ = (InputStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(InputStreamInterface, o_, InputStreamInterface_Skip) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<InputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<InputStreamInterface>() : PRIVATE_MAXON_VTABLE(InputStreamInterface, o_); 
	return (mt_._InputStreamInterface_Skip(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._InputStreamInterface_Skip_Offset, bytes));
}
auto InputStreamInterface::GetPtr() -> Ptr { return Ptr(this); }
auto InputStreamInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_InputStreamInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_InputStreamInterface() { new (s_ui_maxon_InputStreamInterface) maxon::EntityUse(InputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_InputStreamInterface(InputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct OutputStreamInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Flush);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Write);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*_OutputStreamInterface_Write) (maxon::GenericComponent* this_, const Block<const Byte>& data);
	maxon::Int _OutputStreamInterface_Write_Offset;
	Result<void> (*_OutputStreamInterface_Flush) (maxon::GenericComponent* this_);
	maxon::Int _OutputStreamInterface_Flush_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, OutputStreamInterface, Write))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, OutputStreamInterface, Write), W, MTable>::type::_OutputStreamInterface_Write;
			_OutputStreamInterface_Write = reinterpret_cast<const decltype(_OutputStreamInterface_Write)&>(ptr);
			_OutputStreamInterface_Write_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, OutputStreamInterface, Flush))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, OutputStreamInterface, Flush), W, MTable>::type::_OutputStreamInterface_Flush;
			_OutputStreamInterface_Flush = reinterpret_cast<const decltype(_OutputStreamInterface_Flush)&>(ptr);
			_OutputStreamInterface_Flush_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!BaseStreamInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<OutputStreamInterface, typename BaseStreamInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(OutputStreamInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct OutputStreamInterface::Hxx2
{
	template <typename S> class Wrapper : public BaseStreamInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Flush);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Write);
	static Result<void> _OutputStreamInterface_Write(maxon::GenericComponent* this_, const Block<const Byte>& data) { return ((typename S::Implementation*) this_)->Write(data); }
	static Result<void> _OutputStreamInterface_Flush(maxon::GenericComponent* this_) { return ((typename S::Implementation*) this_)->Flush(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Write(const Block<const Byte>& data) -> Result<void>
{
	const OutputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(OutputStreamInterface, this); return mt_._OutputStreamInterface_Write((maxon::GenericComponent*) this + mt_._OutputStreamInterface_Write_Offset, data);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Flush() -> Result<void>
{
	const OutputStreamInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(OutputStreamInterface, this); return mt_._OutputStreamInterface_Flush((maxon::GenericComponent*) this + mt_._OutputStreamInterface_Flush_Offset);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Hxx1::ReferenceFunctionsImpl<S>::Write(const Block<const Byte>& data) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); OutputStreamInterface* o_ = (OutputStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(OutputStreamInterface, o_, OutputStreamInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<OutputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<OutputStreamInterface>() : PRIVATE_MAXON_VTABLE(OutputStreamInterface, o_); 
	return (mt_._OutputStreamInterface_Write(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._OutputStreamInterface_Write_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Hxx1::COWReferenceFunctionsImpl<S>::Write(const Block<const Byte>& data) -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); OutputStreamInterface* o_ = (OutputStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(OutputStreamInterface, o_, OutputStreamInterface_Write) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<OutputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<OutputStreamInterface>() : PRIVATE_MAXON_VTABLE(OutputStreamInterface, o_); 
	return (mt_._OutputStreamInterface_Write(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._OutputStreamInterface_Write_Offset, data));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Hxx1::ReferenceFunctionsImpl<S>::Flush() const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); OutputStreamInterface* o_ = (OutputStreamInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(OutputStreamInterface, o_, OutputStreamInterface_Flush) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<OutputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<OutputStreamInterface>() : PRIVATE_MAXON_VTABLE(OutputStreamInterface, o_); 
	return (mt_._OutputStreamInterface_Flush(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._OutputStreamInterface_Flush_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto OutputStreamInterface::Hxx1::COWReferenceFunctionsImpl<S>::Flush() -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); OutputStreamInterface* o_ = (OutputStreamInterface*) this->MakeWritable(true).GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) return ReturnHelper::Return(this, maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::MAKE_WRITABLE_FAILED)); const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(OutputStreamInterface, o_, OutputStreamInterface_Flush) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<OutputStreamInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<OutputStreamInterface>() : PRIVATE_MAXON_VTABLE(OutputStreamInterface, o_); 
	return (mt_._OutputStreamInterface_Flush(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._OutputStreamInterface_Flush_Offset));
}
auto OutputStreamInterface::GetPtr() -> Ptr { return Ptr(this); }
auto OutputStreamInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_OutputStreamInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_OutputStreamInterface() { new (s_ui_maxon_OutputStreamInterface) maxon::EntityUse(OutputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_OutputStreamInterface(OutputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif

struct InOutputStreamInterface::MTable
{
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	template <typename W> void Init(maxon::Int offset)
	{
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!InputStreamInterface::MTable::template InitWithBases<W>(info, offset) || !OutputStreamInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<InOutputStreamInterface, typename OutputStreamInterface::MTable::template CombinedMTable<typename InputStreamInterface::MTable::template CombinedMTable<S>>>;
	PRIVATE_MAXON_COMPBASE(InOutputStreamInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct InOutputStreamInterface::Hxx2
{
	template <typename S> class Wrapper : public OutputStreamInterface::Hxx2::template Wrapper<typename InputStreamInterface::Hxx2::template Wrapper<S>>
	{
	public:
	};

};

auto InOutputStreamInterface::GetPtr() -> Ptr { return Ptr(this); }
auto InOutputStreamInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_InOutputStreamInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_InOutputStreamInterface() { new (s_ui_maxon_InOutputStreamInterface) maxon::EntityUse(InOutputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_InOutputStreamInterface(InOutputStreamInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iostreams.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

