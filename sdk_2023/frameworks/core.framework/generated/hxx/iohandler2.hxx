
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
	PRIVATE_MAXON_MF_POINTER(IoHandlerInterface_GetUrlScheme, GetUrlScheme, true, maxon::GenericComponent, const, (const Id&));
	maxon::Int IoHandlerInterface_GetUrlScheme_Offset;
	PRIVATE_MAXON_MF_POINTER(IoHandlerInterface_SetSystemPath, SetSystemPath, true, maxon::GenericComponent, const, (Result<void>), UrlInterface& url, const String& systemPath);
	maxon::Int IoHandlerInterface_SetSystemPath_Offset;
	PRIVATE_MAXON_MF_POINTER(IoHandlerInterface_GetSystemPath, GetSystemPath, true, maxon::GenericComponent, const, (Result<String>), const UrlInterface& url);
	maxon::Int IoHandlerInterface_GetSystemPath_Offset;
	PRIVATE_MAXON_MF_POINTER(IoHandlerInterface_AppendUrl, AppendUrl, true, maxon::GenericComponent, const, (Result<void>), UrlInterface& url, const String& name);
	maxon::Int IoHandlerInterface_AppendUrl_Offset;
	PRIVATE_MAXON_MF_POINTER(IoHandlerInterface_AppendUrl_1, AppendUrl, true, maxon::GenericComponent, const, (Result<void>), UrlInterface& url, const Url& relativeUrl);
	maxon::Int IoHandlerInterface_AppendUrl_1_Offset;
	PRIVATE_MAXON_MF_POINTER(IoHandlerInterface_RemoveUrl, RemoveUrl, true, maxon::GenericComponent, const, (Result<void>), UrlInterface& url);
	maxon::Int IoHandlerInterface_RemoveUrl_Offset;
	PRIVATE_MAXON_MF_POINTER(IoHandlerInterface_OpenConnection, OpenConnection, true, maxon::GenericComponent, const, (Result<IoConnectionRef>), const Url& name);
	maxon::Int IoHandlerInterface_OpenConnection_Offset;
	PRIVATE_MAXON_MF_POINTER(IoHandlerInterface_Normalize, Normalize, true, maxon::GenericComponent, const, (Result<Url>), const Url& url, NORMALIZEFLAGS flags);
	maxon::Int IoHandlerInterface_Normalize_Offset;
	PRIVATE_MAXON_MF_POINTER(IoHandlerInterface_IoNormalize, IoNormalize, true, maxon::GenericComponent, const, (Result<Url>), const Url& url, NORMALIZEFLAGS flags);
	maxon::Int IoHandlerInterface_IoNormalize_Offset;
	PRIVATE_MAXON_MF_POINTER(IoHandlerInterface_ConvertToUiName, ConvertToUiName, true, maxon::GenericComponent, const, (Result<String>), const UrlInterface& url, CONVERTTOUINAMEFLAGS flags);
	maxon::Int IoHandlerInterface_ConvertToUiName_Offset;
	PRIVATE_MAXON_MF_POINTER(IoHandlerInterface_ConvertToUiNameWithRepository, ConvertToUiNameWithRepository, true, maxon::GenericComponent, const, (Result<String>), const UrlInterface& url, CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository);
	maxon::Int IoHandlerInterface_ConvertToUiNameWithRepository_Offset;
	template <typename W> void Init(maxon::Int offset)
	{
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, GetUrlScheme))
	{
		maxon::Tie(IoHandlerInterface_GetUrlScheme, IoHandlerInterface_GetUrlScheme_Offset) = IoHandlerInterface_GetUrlScheme_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, SetSystemPath))
	{
		maxon::Tie(IoHandlerInterface_SetSystemPath, IoHandlerInterface_SetSystemPath_Offset) = IoHandlerInterface_SetSystemPath_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, GetSystemPath))
	{
		maxon::Tie(IoHandlerInterface_GetSystemPath, IoHandlerInterface_GetSystemPath_Offset) = IoHandlerInterface_GetSystemPath_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, AppendUrl))
	{
		maxon::Tie(IoHandlerInterface_AppendUrl, IoHandlerInterface_AppendUrl_Offset) = IoHandlerInterface_AppendUrl_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, AppendUrl))
	{
		maxon::Tie(IoHandlerInterface_AppendUrl_1, IoHandlerInterface_AppendUrl_1_Offset) = IoHandlerInterface_AppendUrl_1_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, RemoveUrl))
	{
		maxon::Tie(IoHandlerInterface_RemoveUrl, IoHandlerInterface_RemoveUrl_Offset) = IoHandlerInterface_RemoveUrl_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, OpenConnection))
	{
		maxon::Tie(IoHandlerInterface_OpenConnection, IoHandlerInterface_OpenConnection_Offset) = IoHandlerInterface_OpenConnection_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, Normalize))
	{
		maxon::Tie(IoHandlerInterface_Normalize, IoHandlerInterface_Normalize_Offset) = IoHandlerInterface_Normalize_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, IoNormalize))
	{
		maxon::Tie(IoHandlerInterface_IoNormalize, IoHandlerInterface_IoNormalize_Offset) = IoHandlerInterface_IoNormalize_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, ConvertToUiName))
	{
		maxon::Tie(IoHandlerInterface_ConvertToUiName, IoHandlerInterface_ConvertToUiName_Offset) = IoHandlerInterface_ConvertToUiName_GetPtr<W>(offset, true);
	}
	if constexpr (PRIVATE_MAXON_IMPLEMENTS(typename W::Implementation, IoHandlerInterface, ConvertToUiNameWithRepository))
	{
		maxon::Tie(IoHandlerInterface_ConvertToUiNameWithRepository, IoHandlerInterface_ConvertToUiNameWithRepository_Offset) = IoHandlerInterface_ConvertToUiNameWithRepository_GetPtr<W>(offset, true);
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
	PRIVATE_MAXON_SF_POINTER(IoHandlerInterface_GetHandlerForScheme, GetHandlerForScheme, MAXON_EXPAND_VA_ARGS, (IoHandler), const UrlScheme& scheme);
		StaticMTable() = default;
		template <typename IMPL> static void Init(StaticMTable* tbl)
		{
		tbl->IoHandlerInterface_GetHandlerForScheme = IoHandlerInterface_GetHandlerForScheme_GetPtr<IMPL>(true);
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
			if constexpr (!S::Implementation::PROXY)
			{
				if (!(Super0::InitMTablesWithBases(info, offset))) return false;
			}
			auto* vt = (IoHandlerInterface::MTable*) maxon::ObjectInterface::PrivateGetOrCreateMTable(info, IoHandlerInterface::_interface); if (!vt) return false;
			vt->template Init<CWrapper>(offset);
			return true;
		}
		PRIVATE_MAXON_MF_WRAPPER(IoHandlerInterface_GetUrlScheme, maxon::GenericComponent, const, (const Id&)) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetUrlScheme(); }
		PRIVATE_MAXON_MF_WRAPPER(IoHandlerInterface_SetSystemPath, maxon::GenericComponent, const, (Result<void>), UrlInterface& url, const String& systemPath) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->SetSystemPath(url, systemPath); }
		PRIVATE_MAXON_MF_WRAPPER(IoHandlerInterface_GetSystemPath, maxon::GenericComponent, const, (Result<String>), const UrlInterface& url) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->GetSystemPath(url); }
		PRIVATE_MAXON_MF_WRAPPER(IoHandlerInterface_AppendUrl, maxon::GenericComponent, const, (Result<void>), UrlInterface& url, const String& name) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->AppendUrl(url, name); }
		PRIVATE_MAXON_MF_WRAPPER(IoHandlerInterface_AppendUrl_1, maxon::GenericComponent, const, (Result<void>), UrlInterface& url, const Url& relativeUrl) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->AppendUrl(url, relativeUrl); }
		PRIVATE_MAXON_MF_WRAPPER(IoHandlerInterface_RemoveUrl, maxon::GenericComponent, const, (Result<void>), UrlInterface& url) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->RemoveUrl(url); }
		PRIVATE_MAXON_MF_WRAPPER(IoHandlerInterface_OpenConnection, maxon::GenericComponent, const, (Result<IoConnectionRef>), const Url& name) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->OpenConnection(name); }
		PRIVATE_MAXON_MF_WRAPPER(IoHandlerInterface_Normalize, maxon::GenericComponent, const, (Result<Url>), const Url& url, NORMALIZEFLAGS flags) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->Normalize(url, flags); }
		PRIVATE_MAXON_MF_WRAPPER(IoHandlerInterface_IoNormalize, maxon::GenericComponent, const, (Result<Url>), const Url& url, NORMALIZEFLAGS flags) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->IoNormalize(url, flags); }
		PRIVATE_MAXON_MF_WRAPPER(IoHandlerInterface_ConvertToUiName, maxon::GenericComponent, const, (Result<String>), const UrlInterface& url, CONVERTTOUINAMEFLAGS flags) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ConvertToUiName(url, flags); }
		static IoHandler IoHandlerInterface_GetHandlerForScheme(const UrlScheme& scheme) { return S::Implementation::GetHandlerForScheme(scheme); }
		PRIVATE_MAXON_MF_WRAPPER(IoHandlerInterface_ConvertToUiNameWithRepository, maxon::GenericComponent, const, (Result<String>), const UrlInterface& url, CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) { return ((const typename S::Implementation*) PRIVATE_MAXON_MF_THIS(const maxon::GenericComponent))->ConvertToUiNameWithRepository(url, flags, lookupRepository); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::GetUrlScheme() const -> const Id&
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_GetUrlScheme_Offset), mt_.IoHandlerInterface_GetUrlScheme);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::SetSystemPath(UrlInterface& url, const String& systemPath) const -> Result<void>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_SetSystemPath_Offset), mt_.IoHandlerInterface_SetSystemPath, url, systemPath);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::GetSystemPath(const UrlInterface& url) const -> Result<String>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_GetSystemPath_Offset), mt_.IoHandlerInterface_GetSystemPath, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::AppendUrl(UrlInterface& url, const String& name) const -> Result<void>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_AppendUrl_Offset), mt_.IoHandlerInterface_AppendUrl, url, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::AppendUrl(UrlInterface& url, const Url& relativeUrl) const -> Result<void>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_AppendUrl_1_Offset), mt_.IoHandlerInterface_AppendUrl_1, url, relativeUrl);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::RemoveUrl(UrlInterface& url) const -> Result<void>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_RemoveUrl_Offset), mt_.IoHandlerInterface_RemoveUrl, url);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::OpenConnection(const Url& name) const -> Result<IoConnectionRef>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_OpenConnection_Offset), mt_.IoHandlerInterface_OpenConnection, name);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Normalize(const Url& url, NORMALIZEFLAGS flags) const -> Result<Url>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_Normalize_Offset), mt_.IoHandlerInterface_Normalize, url, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::IoNormalize(const Url& url, NORMALIZEFLAGS flags) const -> Result<Url>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_IoNormalize_Offset), mt_.IoHandlerInterface_IoNormalize, url, flags);
}
[[deprecated("use ConvertToUiNameWithRepository instead")]] MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::ConvertToUiName(const UrlInterface& url, CONVERTTOUINAMEFLAGS flags) const -> Result<String>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_ConvertToUiName_Offset), mt_.IoHandlerInterface_ConvertToUiName, url, flags);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::GetHandlerForScheme(const UrlScheme& scheme) -> IoHandler
{
	return Hxx2::StaticMTable::_instance.IoHandlerInterface_GetHandlerForScheme(scheme);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::ConvertToUiNameWithRepository(const UrlInterface& url, CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) const -> Result<String>
{
	const IoHandlerInterface::MTable& mt_ = PRIVATE_MAXON_VTABLE(IoHandlerInterface, this); return PRIVATE_MAXON_MF_INVOKE(((const maxon::GenericComponent*) this + mt_.IoHandlerInterface_ConvertToUiNameWithRepository_Offset), mt_.IoHandlerInterface_ConvertToUiNameWithRepository, url, flags, lookupRepository);
}

template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::GetUrlScheme() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<const Id&>, const Id&>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<const Id&>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_GetUrlScheme) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_GetUrlScheme_Offset), mt_.IoHandlerInterface_GetUrlScheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::SetSystemPath(UrlInterface& url, const String& systemPath) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_SetSystemPath) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_SetSystemPath_Offset), mt_.IoHandlerInterface_SetSystemPath, url, systemPath));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::GetSystemPath(const UrlInterface& url) const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_GetSystemPath) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_GetSystemPath_Offset), mt_.IoHandlerInterface_GetSystemPath, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::AppendUrl(UrlInterface& url, const String& name) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_AppendUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_AppendUrl_Offset), mt_.IoHandlerInterface_AppendUrl, url, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::AppendUrl(UrlInterface& url, const Url& relativeUrl) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_AppendUrl_1) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_AppendUrl_1_Offset), mt_.IoHandlerInterface_AppendUrl_1, url, relativeUrl));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::RemoveUrl(UrlInterface& url) const -> Result<void>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<void>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_RemoveUrl) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_RemoveUrl_Offset), mt_.IoHandlerInterface_RemoveUrl, url));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::OpenConnection(const Url& name) const -> Result<IoConnectionRef>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<IoConnectionRef>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_OpenConnection) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_OpenConnection_Offset), mt_.IoHandlerInterface_OpenConnection, name));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::Normalize(const Url& url, NORMALIZEFLAGS flags) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_Normalize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_Normalize_Offset), mt_.IoHandlerInterface_Normalize, url, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::IoNormalize(const Url& url, NORMALIZEFLAGS flags) const -> Result<Url>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<Url>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_IoNormalize) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_IoNormalize_Offset), mt_.IoHandlerInterface_IoNormalize, url, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::ConvertToUiName(const UrlInterface& url, CONVERTTOUINAMEFLAGS flags) const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_ConvertToUiName) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_ConvertToUiName_Offset), mt_.IoHandlerInterface_ConvertToUiName, url, flags));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::GetHandlerForScheme(const UrlScheme& scheme) -> IoHandler
{
	return (Hxx2::StaticMTable::_instance.IoHandlerInterface_GetHandlerForScheme(scheme));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto IoHandlerInterface::Hxx1::ConstFn<S>::ConvertToUiNameWithRepository(const UrlInterface& url, CONVERTTOUINAMEFLAGS flags, const AssetRepositoryRef& lookupRepository) const -> Result<String>
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, Result<String>>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const IoHandlerInterface* o_ = (const IoHandlerInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = IoHandlerInterface::NullValuePtr(); if (!o_) return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLPTR); } const MTable& mt_ = std::is_same<typename S::Handler, maxon::SuperPointerHandler>::value ? PRIVATE_MAXON_SUPERMTABLE(IoHandlerInterface, o_, IoHandlerInterface_ConvertToUiNameWithRepository) : ((S::PrivateReferencedType::INTERFACE_FLAGS & maxon::EntityBase::FLAGS::SINGLE_IMPLEMENTATION) && S::PrivateReferencedType::HasBaseDetector::template Check<IoHandlerInterface>::value) ? S::PrivateReferencedType::MTable::template GetMTable<IoHandlerInterface>() : PRIVATE_MAXON_VTABLE(IoHandlerInterface, o_); 
	return (PRIVATE_MAXON_MF_INVOKE((reinterpret_cast<const maxon::GenericComponent*>(o_) + mt_.IoHandlerInterface_ConvertToUiNameWithRepository_Offset), mt_.IoHandlerInterface_ConvertToUiNameWithRepository, url, flags, lookupRepository));
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

