
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* LanguageInterface::PrivateGetCppName() { return "maxon::LanguageRef"; }

struct LanguageInterface::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = true;
	PRIVATE_MAXON_SF_POINTER(LanguageInterface_Free, Free, MAXON_EXPAND_VA_ARGS, (void), const LanguageInterface* object);
	PRIVATE_MAXON_SF_POINTER(LanguageInterface_Alloc, Alloc, MAXON_IGNORE_VA_ARGS, (LanguageInterface*), const maxon::SourceLocation& allocLocation);
	PRIVATE_MAXON_MF_POINTER(LanguageInterface_LoadResourceString, LoadResourceString, false, LanguageInterface,, (String), const Id& scope, const InternedId& keyValue);
	PRIVATE_MAXON_MF_POINTER(LanguageInterface_GetName, GetName, false, LanguageInterface, const, (String));
	PRIVATE_MAXON_MF_POINTER(LanguageInterface_GetIdentifier, GetIdentifier, false, LanguageInterface, const, (Id));
	PRIVATE_MAXON_MF_POINTER(LanguageInterface_GetFallbackLanguage, GetFallbackLanguage, false, LanguageInterface, const, (LanguageRef));
	PRIVATE_MAXON_MF_POINTER(LanguageInterface_ToString, ToString, false, LanguageInterface, const, (String), const maxon::FormatStatement* fs);
	template <typename IMPL> void Init()
	{
		LanguageInterface_Free = LanguageInterface_Free_GetPtr<IMPL>(true);
		LanguageInterface_Alloc = LanguageInterface_Alloc_GetPtr<IMPL>(true);
		LanguageInterface_LoadResourceString = LanguageInterface_LoadResourceString_GetPtr<IMPL>(0, true).first;
		LanguageInterface_GetName = LanguageInterface_GetName_GetPtr<IMPL>(0, true).first;
		LanguageInterface_GetIdentifier = LanguageInterface_GetIdentifier_GetPtr<IMPL>(0, true).first;
		LanguageInterface_GetFallbackLanguage = LanguageInterface_GetFallbackLanguage_GetPtr<IMPL>(0, true).first;
		LanguageInterface_ToString = LanguageInterface_ToString_GetPtr<IMPL>(0, true).first;
	}
};

struct LanguageInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static void LanguageInterface_Free(const LanguageInterface* object) { return C::Free(object); }
		static LanguageInterface* LanguageInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		PRIVATE_MAXON_MF_WRAPPER(LanguageInterface_LoadResourceString, LanguageInterface,, (String), const Id& scope, const InternedId& keyValue) { return C::Get(PRIVATE_MAXON_MF_THIS(LanguageInterface))->LoadResourceString(scope, keyValue); }
		PRIVATE_MAXON_MF_WRAPPER(LanguageInterface_GetName, LanguageInterface, const, (String)) { return C::Get(PRIVATE_MAXON_MF_THIS(const LanguageInterface))->GetName(); }
		PRIVATE_MAXON_MF_WRAPPER(LanguageInterface_GetIdentifier, LanguageInterface, const, (Id)) { return C::Get(PRIVATE_MAXON_MF_THIS(const LanguageInterface))->GetIdentifier(); }
		PRIVATE_MAXON_MF_WRAPPER(LanguageInterface_GetFallbackLanguage, LanguageInterface, const, (LanguageRef)) { return C::Get(PRIVATE_MAXON_MF_THIS(const LanguageInterface))->GetFallbackLanguage(); }
		PRIVATE_MAXON_MF_WRAPPER(LanguageInterface_ToString, LanguageInterface, const, (String), const maxon::FormatStatement* fs) { return C::Get(PRIVATE_MAXON_MF_THIS(const LanguageInterface))->ToString(fs); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::Free(const LanguageInterface* object) -> void
{
	return MTable::_instance.LanguageInterface_Free(object);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::Alloc(const maxon::SourceLocation& allocLocation) -> LanguageInterface*
{
	return MTable::_instance.LanguageInterface_Alloc(allocLocation);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::LoadResourceString(const Id& scope, const InternedId& keyValue) -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LanguageInterface_LoadResourceString, scope, keyValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::GetName() const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LanguageInterface_GetName);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::GetIdentifier() const -> Id
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LanguageInterface_GetIdentifier);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::GetFallbackLanguage() const -> LanguageRef
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LanguageInterface_GetFallbackLanguage);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::ToString(const maxon::FormatStatement* fs) const -> String
{
	return PRIVATE_MAXON_MF_INVOKE((this), MTable::_instance.LanguageInterface_ToString, fs);
}

auto LanguageInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<LanguageRef>
{
	LanguageInterface* res_ = LanguageInterface::Alloc(MAXON_SOURCE_LOCATION);
	return LanguageRef(maxon::ForwardResultPtr<LanguageInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::Hxx1::Fn<S>::LoadResourceString(const Id& scope, const InternedId& keyValue) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); LanguageInterface* o_ = (LanguageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LanguageInterface_LoadResourceString, scope, keyValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::Hxx1::ConstFn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LanguageInterface* o_ = (const LanguageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LanguageInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LanguageInterface_GetName));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::Hxx1::ConstFn<S>::GetIdentifier() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LanguageInterface* o_ = (const LanguageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LanguageInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Id>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LanguageInterface_GetIdentifier));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::Hxx1::ConstFn<S>::GetFallbackLanguage() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<LanguageRef>, LanguageRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<LanguageRef>, LanguageRef>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LanguageInterface* o_ = (const LanguageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LanguageInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<LanguageRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LanguageInterface_GetFallbackLanguage));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::Hxx1::ConstFn<S>::ToString(const maxon::FormatStatement* fs) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && MAXON_UNLIKELY(this->GetErrorStorage().GetReferencedError())) return ReturnHelper::ReturnErrorOf(this); const LanguageInterface* o_ = (const LanguageInterface*) this->GetPointer(); if (!std::integral_constant<maxon::Bool, maxon::Bool(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR))>::value && MAXON_UNLIKELY(!o_)) { o_ = LanguageInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (PRIVATE_MAXON_MF_INVOKE((o_), MTable::_instance.LanguageInterface_ToString, fs));
}
#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_stringresource)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_LanguageInterface); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_LanguageInterface() { new (s_ui_maxon_LanguageInterface) maxon::EntityUse(LanguageInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/stringresource.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_LanguageInterface(LanguageInterface::_interface.GetReference(), &maxon::g_translationUnit, "maxon/stringresource.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
constexpr const maxon::Char* Resource::PrivateGetCppName() { return nullptr; }

struct Resource::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(Resource_GetDefaultLanguage, GetDefaultLanguage, MAXON_EXPAND_VA_ARGS, (LanguageRef));
	PRIVATE_MAXON_SF_POINTER(Resource_GetCurrentLanguage, GetCurrentLanguage, MAXON_EXPAND_VA_ARGS, (LanguageRef));
	PRIVATE_MAXON_SF_POINTER(Resource_FindLanguage, FindLanguage, MAXON_EXPAND_VA_ARGS, (LanguageRef), const Id& identifier);
	PRIVATE_MAXON_SF_POINTER(Resource_SetCurrentLanguage, SetCurrentLanguage, MAXON_EXPAND_VA_ARGS, (Result<void>), const LanguageRef& language);
	PRIVATE_MAXON_SF_POINTER(Resource_GetAllLanguages, GetAllLanguages, MAXON_EXPAND_VA_ARGS, (Result<BaseArray<LanguageRef>>));
	PRIVATE_MAXON_SF_POINTER(Resource_LoadResourceString, LoadResourceString, MAXON_EXPAND_VA_ARGS, (String), const Id& scope, const InternedId& keyValue);
	PRIVATE_MAXON_SF_POINTER(Resource_WriteLanguagePrf, WriteLanguagePrf, MAXON_EXPAND_VA_ARGS, (Result<void>), const LanguageRef& language);
	PRIVATE_MAXON_SF_POINTER(Resource_ObservableLanguageChanged, ObservableLanguageChanged, MAXON_EXPAND_VA_ARGS, (maxon::ObservableRef<ObservableLanguageChangedDelegate>));
	template <typename IMPL> void Init()
	{
		Resource_GetDefaultLanguage = Resource_GetDefaultLanguage_GetPtr<IMPL>(true);
		Resource_GetCurrentLanguage = Resource_GetCurrentLanguage_GetPtr<IMPL>(true);
		Resource_FindLanguage = Resource_FindLanguage_GetPtr<IMPL>(true);
		Resource_SetCurrentLanguage = Resource_SetCurrentLanguage_GetPtr<IMPL>(true);
		Resource_GetAllLanguages = Resource_GetAllLanguages_GetPtr<IMPL>(true);
		Resource_LoadResourceString = Resource_LoadResourceString_GetPtr<IMPL>(true);
		Resource_WriteLanguagePrf = Resource_WriteLanguagePrf_GetPtr<IMPL>(true);
		Resource_ObservableLanguageChanged = Resource_ObservableLanguageChanged_GetPtr<IMPL>(true);
	}
};

struct Resource::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		using Implementation = C;
		static LanguageRef Resource_GetDefaultLanguage() { return C::GetDefaultLanguage(); }
		static LanguageRef Resource_GetCurrentLanguage() { return C::GetCurrentLanguage(); }
		static LanguageRef Resource_FindLanguage(const Id& identifier) { return C::FindLanguage(identifier); }
		static Result<void> Resource_SetCurrentLanguage(const LanguageRef& language) { return C::SetCurrentLanguage(language); }
		static Result<BaseArray<LanguageRef>> Resource_GetAllLanguages() { return C::GetAllLanguages(); }
		static String Resource_LoadResourceString(const Id& scope, const InternedId& keyValue) { return C::LoadResourceString(scope, keyValue); }
		static Result<void> Resource_WriteLanguagePrf(const LanguageRef& language) { return C::WriteLanguagePrf(language); }
		static maxon::ObservableRef<ObservableLanguageChangedDelegate> Resource_ObservableLanguageChanged() { return C::ObservableLanguageChanged(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Resource::GetDefaultLanguage() -> LanguageRef
{
	return MTable::_instance.Resource_GetDefaultLanguage();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Resource::GetCurrentLanguage() -> LanguageRef
{
	return MTable::_instance.Resource_GetCurrentLanguage();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Resource::FindLanguage(const Id& identifier) -> LanguageRef
{
	return MTable::_instance.Resource_FindLanguage(identifier);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Resource::SetCurrentLanguage(const LanguageRef& language) -> Result<void>
{
	return MTable::_instance.Resource_SetCurrentLanguage(language);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Resource::GetAllLanguages() -> Result<BaseArray<LanguageRef>>
{
	return MTable::_instance.Resource_GetAllLanguages();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Resource::LoadResourceString(const Id& scope, const InternedId& keyValue) -> String
{
	return MTable::_instance.Resource_LoadResourceString(scope, keyValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Resource::WriteLanguagePrf(const LanguageRef& language) -> Result<void>
{
	return MTable::_instance.Resource_WriteLanguagePrf(language);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Resource::ObservableLanguageChanged() -> maxon::ObservableRef<ObservableLanguageChangedDelegate>
{
	return MTable::_instance.Resource_ObservableLanguageChanged();
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_stringresource)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_Resource); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_Resource() { new (s_ui_maxon_Resource) maxon::EntityUse(Resource::_interface.GetReference(), &maxon::g_translationUnit, "maxon/stringresource.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_Resource(Resource::_interface.GetReference(), &maxon::g_translationUnit, "maxon/stringresource.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

