
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
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ConvertToUiName);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(ConvertToUiNameWithRepository);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetSystemPath);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(GetUrlScheme);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(IoNormalize);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(Normalize);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(OpenConnection);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(RemoveUrl);
	PRIVATE_MAXON_IMPLEMENTS_CHECK(SetSystemPath);
	static const maxon::Char* const _ids;
	static const maxon::METHOD_FLAGS _flags[];
	static const maxon::Bool HAS_NONSTATIC = false;
	const Id& (*IoHandlerInterface_GetUrlScheme) (const maxon::GenericComponent* this_);
	maxon::Int IoHandlerInterface_GetUrlScheme_Offset;
	Result<void> (*IoHandlerInterface_SetSystemPath) (const maxon::GenericComponent* this_, UrlInterface& url, const String& systemPath);
	maxon::Int IoHandlerInterface_SetSystemPath_Offset;
	Result<String> (*IoHandlerInterface_GetSystemPath) (const maxon::GenericComponent* this_, const UrlInterface& url);
	maxon::Int IoHandlerInterface_GetSystemPath_Offset;
	Result<void> (*IoHandlerInterface_AppendUrl) (const maxon::GenericComponent* this_, UrlInterface& url, const String& name);
	maxon::Int IoHandlerInterface_AppendUrl_Offset;
	Result<void> (*IoHandlerInterface_AppendUrl_1) (const maxon::GenericComponent* this_, UrlInterface& url, const Url& relativeUrl);
	maxon::Int IoHandlerInterface_AppendUrl_1_Offset;
	Result<void> (*IoHandlerInterface_RemoveUrl) (const maxon::GenericComponent* this_, UrlInterface& url);
	maxon::Int IoHandlerInterface_RemoveUrl_Offset;
	Result<IoConnectionRef> (*IoHandlerInterface_OpenConnection) (const maxon::GenericComponent* this_, const Url& name);
	maxon::Int IoHandlerInterface_OpenConnection_Offset;
	Result<Url> (*IoHandlerInterface_Normalize) (const maxon::GenericComponent* this_, const Url& url, NORMALIZEFLAGS flags);
	maxon::Int IoHandlerInterface_Normalize_Offset;
	Result<Url> (*IoHandlerInterface_IoNormalize) (const maxon::GenericComponent* this_, const Url& url, NORMALIZEFLAGS flags);
	maxon::Int IoHandlerInterface_IoNormalize_Offset;
	Result<String> (*IoHandlerInterface_ConvertToUiName) (const maxon::GenericComponent* this_, const UrlInterface& url, CONVERTTOUINAMEFLAGS flags);
	maxon::Int IoHandlerInterface_ConvertToUiName_Offset;
	Result<String> (*IoHandlerInterface_ConvertToUiNameWithRepository) (const maxon::GenericComponent* this_, const UrlInterface& url, CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository);
	maxon::Int IoHandlerInterface_ConvertToUiNameWithRepository_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, GetUrlScheme))
	{
		IoHandlerInterface_GetUrlScheme = &W::IoHandlerInterface_GetUrlScheme;
		IoHandlerInterface_GetUrlScheme_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, SetSystemPath))
	{
		IoHandlerInterface_SetSystemPath = &W::IoHandlerInterface_SetSystemPath;
		IoHandlerInterface_SetSystemPath_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, GetSystemPath))
	{
		IoHandlerInterface_GetSystemPath = &W::IoHandlerInterface_GetSystemPath;
		IoHandlerInterface_GetSystemPath_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, AppendUrl))
	{
		IoHandlerInterface_AppendUrl = &W::IoHandlerInterface_AppendUrl;
		IoHandlerInterface_AppendUrl_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, AppendUrl))
	{
		IoHandlerInterface_AppendUrl_1 = &W::IoHandlerInterface_AppendUrl_1;
		IoHandlerInterface_AppendUrl_1_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, RemoveUrl))
	{
		IoHandlerInterface_RemoveUrl = &W::IoHandlerInterface_RemoveUrl;
		IoHandlerInterface_RemoveUrl_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, OpenConnection))
	{
		IoHandlerInterface_OpenConnection = &W::IoHandlerInterface_OpenConnection;
		IoHandlerInterface_OpenConnection_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, Normalize))
	{
		IoHandlerInterface_Normalize = &W::IoHandlerInterface_Normalize;
		IoHandlerInterface_Normalize_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, IoNormalize))
	{
		IoHandlerInterface_IoNormalize = &W::IoHandlerInterface_IoNormalize;
		IoHandlerInterface_IoNormalize_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, ConvertToUiName))
	{
		IoHandlerInterface_ConvertToUiName = &W::IoHandlerInterface_ConvertToUiName;
		IoHandlerInterface_ConvertToUiName_Offset = offset;
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, ConvertToUiNameWithRepository))
	{
		IoHandlerInterface_ConvertToUiNameWithRepository = &W::IoHandlerInterface_ConvertToUiNameWithRepository;
		IoHandlerInterface_ConvertToUiNameWithRepository_Offset = offset;
	}
	}
	template <typename S> using CombinedMTable = maxon::CombinedMTable<IoHandlerInterface, typename ObjectInterface::MTable::template CombinedMTable<S>>;
	template <typename SUPER> using CompBase = maxon::PrivateComponentBase<IoHandlerInterface, SUPER>;
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
	IoHandler (*IoHandlerInterface_GetHandlerForScheme) (const UrlScheme& scheme);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->IoHandlerInterface_GetHandlerForScheme = &IMPL::IoHandlerInterface_GetHandlerForScheme;
		}
	};
	template <typename S> class CWrapper : public ObjectInterface::Hxx2::template CWrapper<S>
	{
	public:
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(AppendUrl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConvertToUiName);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(ConvertToUiNameWithRepository);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetSystemPath);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(GetUrlScheme);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(IoNormalize);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(Normalize);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(OpenConnection);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(RemoveUrl);
		PRIVATE_MAXON_IMPLEMENTS_HELPER_MEMBER(SetSystemPath);
		static maxon::Bool InitMTablesWithBases(maxon::ClassInfo* info, maxon::Int offset)
		{
			using Super0 = typename ObjectInterface::Hxx2::template CWrapper<S>;
			if (!S::Implementation::PROXY && !(Super0::InitMTablesWithBases(info, offset))) return false;
			auto* vt = (IoHandlerInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, IoHandlerInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		static const Id& IoHandlerInterface_GetUrlScheme(const maxon::GenericComponent* this_) { return ((const typename S::Implementation*) this_)->GetUrlScheme(); }
		static Result<void> IoHandlerInterface_SetSystemPath(const maxon::GenericComponent* this_, UrlInterface& url, const String& systemPath) { return ((const typename S::Implementation*) this_)->SetSystemPath(url, systemPath); }
		static Result<String> IoHandlerInterface_GetSystemPath(const maxon::GenericComponent* this_, const UrlInterface& url) { return ((const typename S::Implementation*) this_)->GetSystemPath(url); }
		static Result<void> IoHandlerInterface_AppendUrl(const maxon::GenericComponent* this_, UrlInterface& url, const String& name) { return ((const typename S::Implementation*) this_)->AppendUrl(url, name); }
		static Result<void> IoHandlerInterface_AppendUrl_1(const maxon::GenericComponent* this_, UrlInterface& url, const Url& relativeUrl) { return ((const typename S::Implementation*) this_)->AppendUrl(url, relativeUrl); }
		static Result<void> IoHandlerInterface_RemoveUrl(const maxon::GenericComponent* this_, UrlInterface& url) { return ((const typename S::Implementation*) this_)->RemoveUrl(url); }
		static Result<IoConnectionRef> IoHandlerInterface_OpenConnection(const maxon::GenericComponent* this_, const Url& name) { return ((const typename S::Implementation*) this_)->OpenConnection(name); }
		static Result<Url> IoHandlerInterface_Normalize(const maxon::GenericComponent* this_, const Url& url, NORMALIZEFLAGS flags) { return ((const typename S::Implementation*) this_)->Normalize(url, flags); }
		static Result<Url> IoHandlerInterface_IoNormalize(const maxon::GenericComponent* this_, const Url& url, NORMALIZEFLAGS flags) { return ((const typename S::Implementation*) this_)->IoNormalize(url, flags); }
		static Result<String> IoHandlerInterface_ConvertToUiName(const maxon::GenericComponent* this_, const UrlInterface& url, CONVERTTOUINAMEFLAGS flags) { return ((const typename S::Implementation*) this_)->ConvertToUiName(url, flags); }
		static IoHandler IoHandlerInterface_GetHandlerForScheme(const UrlScheme& scheme) { return S::Implementation::GetHandlerForScheme(scheme); }
		static Result<String> IoHandlerInterface_ConvertToUiNameWithRepository(const maxon::GenericComponent* this_, const UrlInterface& url, CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) { return ((const typename S::Implementation*) this_)->ConvertToUiNameWithRepository(url, flags, lookupRepository); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::GetUrlScheme() const -> const Id&
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_.IoHandlerInterface_GetUrlScheme((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_GetUrlScheme_Offset);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::SetSystemPath(UrlInterface& url, const String& systemPath) const -> Result<void>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_.IoHandlerInterface_SetSystemPath((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_SetSystemPath_Offset, url, systemPath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::GetSystemPath(const UrlInterface& url) const -> Result<String>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_.IoHandlerInterface_GetSystemPath((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_GetSystemPath_Offset, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::AppendUrl(UrlInterface& url, const String& name) const -> Result<void>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_.IoHandlerInterface_AppendUrl((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_AppendUrl_Offset, url, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::AppendUrl(UrlInterface& url, const Url& relativeUrl) const -> Result<void>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_.IoHandlerInterface_AppendUrl_1((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_AppendUrl_1_Offset, url, relativeUrl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::RemoveUrl(UrlInterface& url) const -> Result<void>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_.IoHandlerInterface_RemoveUrl((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_RemoveUrl_Offset, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::OpenConnection(const Url& name) const -> Result<IoConnectionRef>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_.IoHandlerInterface_OpenConnection((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_OpenConnection_Offset, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Normalize(const Url& url, NORMALIZEFLAGS flags) const -> Result<Url>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_.IoHandlerInterface_Normalize((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_Normalize_Offset, url, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::IoNormalize(const Url& url, NORMALIZEFLAGS flags) const -> Result<Url>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_.IoHandlerInterface_IoNormalize((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_IoNormalize_Offset, url, flags);
}
[[deprecated("use ConvertToUiNameWithRepository instead")]] MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::ConvertToUiName(const UrlInterface& url, CONVERTTOUINAMEFLAGS flags) const -> Result<String>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_.IoHandlerInterface_ConvertToUiName((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_ConvertToUiName_Offset, url, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::GetHandlerForScheme(const UrlScheme& scheme) -> IoHandler
{
	return Hxx2::StaticMTable::_instance.IoHandlerInterface_GetHandlerForScheme(scheme);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::ConvertToUiNameWithRepository(const UrlInterface& url, CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) const -> Result<String>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return mt_.IoHandlerInterface_ConvertToUiNameWithRepository((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_ConvertToUiNameWithRepository_Offset, url, flags, lookupRepository);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::GetUrlScheme() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_GetUrlScheme) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_.IoHandlerInterface_GetUrlScheme(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_GetUrlScheme_Offset));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::SetSystemPath(UrlInterface& url, const String& systemPath) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_SetSystemPath) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_.IoHandlerInterface_SetSystemPath(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_SetSystemPath_Offset, url, systemPath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::GetSystemPath(const UrlInterface& url) const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_GetSystemPath) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_.IoHandlerInterface_GetSystemPath(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_GetSystemPath_Offset, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::AppendUrl(UrlInterface& url, const String& name) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_AppendUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_.IoHandlerInterface_AppendUrl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_AppendUrl_Offset, url, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::AppendUrl(UrlInterface& url, const Url& relativeUrl) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_AppendUrl_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_.IoHandlerInterface_AppendUrl_1(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_AppendUrl_1_Offset, url, relativeUrl));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::RemoveUrl(UrlInterface& url) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_RemoveUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_.IoHandlerInterface_RemoveUrl(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_RemoveUrl_Offset, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::OpenConnection(const Url& name) const -> Result<IoConnectionRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<IoConnectionRef>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_OpenConnection) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_.IoHandlerInterface_OpenConnection(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_OpenConnection_Offset, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::Normalize(const Url& url, NORMALIZEFLAGS flags) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_Normalize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_.IoHandlerInterface_Normalize(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_Normalize_Offset, url, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::IoNormalize(const Url& url, NORMALIZEFLAGS flags) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_IoNormalize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_.IoHandlerInterface_IoNormalize(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_IoNormalize_Offset, url, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::ConvertToUiName(const UrlInterface& url, CONVERTTOUINAMEFLAGS flags) const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_ConvertToUiName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_.IoHandlerInterface_ConvertToUiName(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_ConvertToUiName_Offset, url, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::GetHandlerForScheme(const UrlScheme& scheme) -> IoHandler
{
	return (Hxx2::StaticMTable::_instance.IoHandlerInterface_GetHandlerForScheme(scheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::ConvertToUiNameWithRepository(const UrlInterface& url, CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_ConvertToUiNameWithRepository) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (mt_.IoHandlerInterface_ConvertToUiNameWithRepository(reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_ConvertToUiNameWithRepository_Offset, url, flags, lookupRepository));
}
auto IoHandlerInterface::GetPtr() -> Ptr { return Ptr(this); }
auto IoHandlerInterface::GetPtr() const -> ConstPtr { return ConstPtr(this); }
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_iohandler)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_IoHandlerInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_IoHandlerInterface() { new (s_ui_maxon_IoHandlerInterface) maxon::EntityUse(IoHandlerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iohandler.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_IoHandlerInterface(IoHandlerInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/iohandler.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_iohandler)
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

