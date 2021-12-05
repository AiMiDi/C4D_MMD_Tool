
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1

struct IoHandlerInterface::MTable
{
	PRIVATE_MAXON_IMPLEMENTS_CHECK(AppendUrl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSystemPath);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetUrlScheme);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoNormalize);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Normalize);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(OpenConnection);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RemoveUrl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetSystemPath);
	static const maxon::Char* const _ids;
	static const maxon::Bool HAS_NONSTATIC = false;
	const Id& (*_IoHandlerInterface_GetUrlScheme) (const maxon::GenericComponent* this_);
	maxon::Int _IoHandlerInterface_GetUrlScheme_Offset;
	Result<void> (*_IoHandlerInterface_SetSystemPath) (const maxon::GenericComponent* this_, UrlInterface& url, const String& systemPath);
	maxon::Int _IoHandlerInterface_SetSystemPath_Offset;
	Result<String> (*_IoHandlerInterface_GetSystemPath) (const maxon::GenericComponent* this_, const UrlInterface& url);
	maxon::Int _IoHandlerInterface_GetSystemPath_Offset;
	Result<void> (*_IoHandlerInterface_AppendUrl) (const maxon::GenericComponent* this_, UrlInterface& url, const String& name);
	maxon::Int _IoHandlerInterface_AppendUrl_Offset;
	Result<void> (*_IoHandlerInterface_AppendUrl_1) (const maxon::GenericComponent* this_, UrlInterface& url, const Url& relativeUrl);
	maxon::Int _IoHandlerInterface_AppendUrl_1_Offset;
	Result<void> (*_IoHandlerInterface_RemoveUrl) (const maxon::GenericComponent* this_, UrlInterface& url);
	maxon::Int _IoHandlerInterface_RemoveUrl_Offset;
	Result<IoConnectionRef> (*_IoHandlerInterface_OpenConnection) (const maxon::GenericComponent* this_, const Url& name);
	maxon::Int _IoHandlerInterface_OpenConnection_Offset;
	Result<Url> (*_IoHandlerInterface_Normalize) (const maxon::GenericComponent* this_, const Url& url, NORMALIZEFLAGS flags);
	maxon::Int _IoHandlerInterface_Normalize_Offset;
	Result<Url> (*_IoHandlerInterface_IoNormalize) (const maxon::GenericComponent* this_, const Url& url, NORMALIZEFLAGS flags);
	maxon::Int _IoHandlerInterface_IoNormalize_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, GetUrlScheme))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, GetUrlScheme), W, MTable>::type::_IoHandlerInterface_GetUrlScheme;
			_IoHandlerInterface_GetUrlScheme = reinterpret_cast<const decltype(_IoHandlerInterface_GetUrlScheme)&>(ptr);
			_IoHandlerInterface_GetUrlScheme_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, SetSystemPath))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, SetSystemPath), W, MTable>::type::_IoHandlerInterface_SetSystemPath;
			_IoHandlerInterface_SetSystemPath = reinterpret_cast<const decltype(_IoHandlerInterface_SetSystemPath)&>(ptr);
			_IoHandlerInterface_SetSystemPath_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, GetSystemPath))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, GetSystemPath), W, MTable>::type::_IoHandlerInterface_GetSystemPath;
			_IoHandlerInterface_GetSystemPath = reinterpret_cast<const decltype(_IoHandlerInterface_GetSystemPath)&>(ptr);
			_IoHandlerInterface_GetSystemPath_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, AppendUrl))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, AppendUrl), W, MTable>::type::_IoHandlerInterface_AppendUrl;
			_IoHandlerInterface_AppendUrl = reinterpret_cast<const decltype(_IoHandlerInterface_AppendUrl)&>(ptr);
			_IoHandlerInterface_AppendUrl_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, AppendUrl))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, AppendUrl), W, MTable>::type::_IoHandlerInterface_AppendUrl_1;
			_IoHandlerInterface_AppendUrl_1 = reinterpret_cast<const decltype(_IoHandlerInterface_AppendUrl_1)&>(ptr);
			_IoHandlerInterface_AppendUrl_1_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, RemoveUrl))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, RemoveUrl), W, MTable>::type::_IoHandlerInterface_RemoveUrl;
			_IoHandlerInterface_RemoveUrl = reinterpret_cast<const decltype(_IoHandlerInterface_RemoveUrl)&>(ptr);
			_IoHandlerInterface_RemoveUrl_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, OpenConnection))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, OpenConnection), W, MTable>::type::_IoHandlerInterface_OpenConnection;
			_IoHandlerInterface_OpenConnection = reinterpret_cast<const decltype(_IoHandlerInterface_OpenConnection)&>(ptr);
			_IoHandlerInterface_OpenConnection_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, Normalize))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, Normalize), W, MTable>::type::_IoHandlerInterface_Normalize;
			_IoHandlerInterface_Normalize = reinterpret_cast<const decltype(_IoHandlerInterface_Normalize)&>(ptr);
			_IoHandlerInterface_Normalize_Offset = offset;
		}
		if (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, IoNormalize))
		{
			auto ptr = &std::conditional<PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, IoNormalize), W, MTable>::type::_IoHandlerInterface_IoNormalize;
			_IoHandlerInterface_IoNormalize = reinterpret_cast<const decltype(_IoHandlerInterface_IoNormalize)&>(ptr);
			_IoHandlerInterface_IoNormalize_Offset = offset;
		}
	}
	template <typename W> static maxon::Bool InitWithBases(maxon::ClassInfo* info, maxon::Int offset)
	{
		if (!W::Implementation::PROXY && (!ObjectInterface::MTable::template InitWithBases<W>(info, offset))) return false;
		MTable* vt = (MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, _interface); if (!vt) return false;
		vt->Init<W>(offset); return true;
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<IoHandlerInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	PRIVATE_MAXON_COMPBASE(IoHandlerInterface);
	template <typename I> static const typename I::MTable& GetMTable() { return maxon::GetZeroRef<typename I::MTable>(); }
};

struct IoHandlerInterface::Hxx2
{
	class Unresolved;
	struct StaticMTable
	{
		static StaticMTable _instance;
		static StaticMTable _unresolvedInstance;
		static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, StaticMTable* tbl);
		static const maxon::Char* const _ids;
		static const maxon::NULL_RETURN_TYPE _returnTypes[];
	IoHandler (*_IoHandlerInterface_GetHandlerForScheme) (const UrlScheme& scheme);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->_IoHandlerInterface_GetHandlerForScheme = &IMPL::_IoHandlerInterface_GetHandlerForScheme;
		}
	};
	template <typename S> class Wrapper : public ObjectInterface::Hxx2::template Wrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AppendUrl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSystemPath);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetUrlScheme);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoNormalize);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Normalize);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(OpenConnection);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RemoveUrl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetSystemPath);
	static const Id& _IoHandlerInterface_GetUrlScheme(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetUrlScheme(); }
	static Result<void> _IoHandlerInterface_SetSystemPath(const maxon::GenericComponent* this_, UrlInterface& url, const String& systemPath) { return ((const typename S::Implementation*) this_)->SetSystemPath(url, systemPath); }
	static Result<String> _IoHandlerInterface_GetSystemPath(const maxon::GenericComponent* this_, const UrlInterface& url) { return ((const typename S::Implementation*) this_)->GetSystemPath(url); }
	static Result<void> _IoHandlerInterface_AppendUrl(const maxon::GenericComponent* this_, UrlInterface& url, const String& name) { return ((const typename S::Implementation*) this_)->AppendUrl(url, name); }
	static Result<void> _IoHandlerInterface_AppendUrl_1(const maxon::GenericComponent* this_, UrlInterface& url, const Url& relativeUrl) { return ((const typename S::Implementation*) this_)->AppendUrl(url, relativeUrl); }
	static Result<void> _IoHandlerInterface_RemoveUrl(const maxon::GenericComponent* this_, UrlInterface& url) { return ((const typename S::Implementation*) this_)->RemoveUrl(url); }
	static Result<IoConnectionRef> _IoHandlerInterface_OpenConnection(const maxon::GenericComponent* this_, const Url& name) { return ((const typename S::Implementation*) this_)->OpenConnection(name); }
	static Result<Url> _IoHandlerInterface_Normalize(const maxon::GenericComponent* this_, const Url& url, NORMALIZEFLAGS flags) { return ((const typename S::Implementation*) this_)->Normalize(url, flags); }
	static Result<Url> _IoHandlerInterface_IoNormalize(const maxon::GenericComponent* this_, const Url& url, NORMALIZEFLAGS flags) { return ((const typename S::Implementation*) this_)->IoNormalize(url, flags); }
	static IoHandler _IoHandlerInterface_GetHandlerForScheme(const UrlScheme& scheme) { return S::Implementation::GetHandlerForScheme(scheme); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::GetUrlScheme() const -> const Id&
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_._IoHandlerInterface_GetUrlScheme((const maxon::GenericComponent*) this + mt_._IoHandlerInterface_GetUrlScheme_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::SetSystemPath(UrlInterface& url, const String& systemPath) const -> Result<void>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_._IoHandlerInterface_SetSystemPath((const maxon::GenericComponent*) this + mt_._IoHandlerInterface_SetSystemPath_Offset, url, systemPath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::GetSystemPath(const UrlInterface& url) const -> Result<String>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_._IoHandlerInterface_GetSystemPath((const maxon::GenericComponent*) this + mt_._IoHandlerInterface_GetSystemPath_Offset, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::AppendUrl(UrlInterface& url, const String& name) const -> Result<void>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_._IoHandlerInterface_AppendUrl((const maxon::GenericComponent*) this + mt_._IoHandlerInterface_AppendUrl_Offset, url, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::AppendUrl(UrlInterface& url, const Url& relativeUrl) const -> Result<void>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_._IoHandlerInterface_AppendUrl_1((const maxon::GenericComponent*) this + mt_._IoHandlerInterface_AppendUrl_1_Offset, url, relativeUrl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::RemoveUrl(UrlInterface& url) const -> Result<void>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_._IoHandlerInterface_RemoveUrl((const maxon::GenericComponent*) this + mt_._IoHandlerInterface_RemoveUrl_Offset, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::OpenConnection(const Url& name) const -> Result<IoConnectionRef>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_._IoHandlerInterface_OpenConnection((const maxon::GenericComponent*) this + mt_._IoHandlerInterface_OpenConnection_Offset, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Normalize(const Url& url, NORMALIZEFLAGS flags) const -> Result<Url>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_._IoHandlerInterface_Normalize((const maxon::GenericComponent*) this + mt_._IoHandlerInterface_Normalize_Offset, url, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::IoNormalize(const Url& url, NORMALIZEFLAGS flags) const -> Result<Url>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_._IoHandlerInterface_IoNormalize((const maxon::GenericComponent*) this + mt_._IoHandlerInterface_IoNormalize_Offset, url, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::GetHandlerForScheme(const UrlScheme& scheme) -> IoHandler
{
	return Hxx2::StaticMTable::_instance._IoHandlerInterface_GetHandlerForScheme(scheme);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetUrlScheme() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_GetUrlScheme) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_._IoHandlerInterface_GetUrlScheme(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_GetUrlScheme_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::SetSystemPath(UrlInterface& url, const String& systemPath) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_SetSystemPath) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_._IoHandlerInterface_SetSystemPath(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_SetSystemPath_Offset, url, systemPath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetSystemPath(const UrlInterface& url) const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_GetSystemPath) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_._IoHandlerInterface_GetSystemPath(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_GetSystemPath_Offset, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::AppendUrl(UrlInterface& url, const String& name) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_AppendUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_._IoHandlerInterface_AppendUrl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_AppendUrl_Offset, url, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::AppendUrl(UrlInterface& url, const Url& relativeUrl) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_AppendUrl_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_._IoHandlerInterface_AppendUrl_1(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_AppendUrl_1_Offset, url, relativeUrl));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::RemoveUrl(UrlInterface& url) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_RemoveUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_._IoHandlerInterface_RemoveUrl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_RemoveUrl_Offset, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::OpenConnection(const Url& name) const -> Result<IoConnectionRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<IoConnectionRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_OpenConnection) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_._IoHandlerInterface_OpenConnection(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_OpenConnection_Offset, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::Normalize(const Url& url, NORMALIZEFLAGS flags) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_Normalize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_._IoHandlerInterface_Normalize(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_Normalize_Offset, url, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::IoNormalize(const Url& url, NORMALIZEFLAGS flags) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_IoNormalize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBase::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_._IoHandlerInterface_IoNormalize(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_._IoHandlerInterface_IoNormalize_Offset, url, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstReferenceFunctionsImpl<S>::GetHandlerForScheme(const UrlScheme& scheme) -> IoHandler { return (Hxx2::StaticMTable::_instance._IoHandlerInterface_GetHandlerForScheme(scheme)); }
auto IoHandlerInterface::GetPtr() -> Ptr { return Ptr(this); }
auto IoHandlerInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_IoHandlerInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_IoHandlerInterface() { new (s_ui_maxon_IoHandlerInterface) maxon::EntityUse(IoHandlerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iohandler.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_IoHandlerInterface(IoHandlerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iohandler.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_usi_maxon_IoHandlerInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_usi_maxon_IoHandlerInterface() { new (s_usi_maxon_IoHandlerInterface) maxon::EntityUse(IoHandlerInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/iohandler.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_usi_maxon_IoHandlerInterface(IoHandlerInterface::_staticInterface.GetReference(), &maxon::g_translationUnit, "maxon/iohandler.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

