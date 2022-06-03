
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
	void (*LanguageInterface_Free) (const LanguageInterface* object);
	LanguageInterface* (*LanguageInterface_Alloc) (const maxon::SourceLocation& allocLocation);
	String (*LanguageInterface_LoadResourceString) (LanguageInterface* this_, const Id& scope, const InternedId& keyValue);
	String (*LanguageInterface_GetName) (const LanguageInterface* this_);
	Id (*LanguageInterface_GetIdentifier) (const LanguageInterface* this_);
	LanguageRef (*LanguageInterface_GetFallbackLanguage) (const LanguageInterface* this_);
	String (*LanguageInterface_ToString) (const LanguageInterface* this_, const maxon::FormatStatement* fs);
	template <typename IMPL> void Init()
	{
		LanguageInterface_Free = &IMPL::LanguageInterface_Free;
		LanguageInterface_Alloc = &IMPL::LanguageInterface_Alloc;
		LanguageInterface_LoadResourceString = &IMPL::LanguageInterface_LoadResourceString;
		LanguageInterface_GetName = &IMPL::LanguageInterface_GetName;
		LanguageInterface_GetIdentifier = &IMPL::LanguageInterface_GetIdentifier;
		LanguageInterface_GetFallbackLanguage = &IMPL::LanguageInterface_GetFallbackLanguage;
		LanguageInterface_ToString = &IMPL::LanguageInterface_ToString;
	}
};

struct LanguageInterface::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static void LanguageInterface_Free(const LanguageInterface* object) { return C::Free(object); }
		static LanguageInterface* LanguageInterface_Alloc(const maxon::SourceLocation& allocLocation) { return C::Alloc(allocLocation); }
		static String LanguageInterface_LoadResourceString(LanguageInterface* this_, const Id& scope, const InternedId& keyValue) { return C::Get(this_)->LoadResourceString(scope, keyValue); }
		static String LanguageInterface_GetName(const LanguageInterface* this_) { return C::Get(this_)->GetName(); }
		static Id LanguageInterface_GetIdentifier(const LanguageInterface* this_) { return C::Get(this_)->GetIdentifier(); }
		static LanguageRef LanguageInterface_GetFallbackLanguage(const LanguageInterface* this_) { return C::Get(this_)->GetFallbackLanguage(); }
		static String LanguageInterface_ToString(const LanguageInterface* this_, const maxon::FormatStatement* fs) { return C::Get(this_)->ToString(fs); }
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
	return MTable::_instance.LanguageInterface_LoadResourceString(this, scope, keyValue);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::GetName() const -> String
{
	return MTable::_instance.LanguageInterface_GetName(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::GetIdentifier() const -> Id
{
	return MTable::_instance.LanguageInterface_GetIdentifier(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::GetFallbackLanguage() const -> LanguageRef
{
	return MTable::_instance.LanguageInterface_GetFallbackLanguage(this);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::ToString(const maxon::FormatStatement* fs) const -> String
{
	return MTable::_instance.LanguageInterface_ToString(this, fs);
}

auto LanguageInterface::Hxx1::Reference::Create() -> maxon::ResultMemT<LanguageRef>
{
	LanguageInterface* res_ = LanguageInterface::Alloc(MAXON_SOURCE_LOCATION);
	return LanguageRef(maxon::ForwardResultPtr<LanguageInterface>(res_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::Hxx1::Fn<S>::LoadResourceString(const Id& scope, const InternedId& keyValue) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); LanguageInterface* o_ = (LanguageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.LanguageInterface_LoadResourceString(o_, scope, keyValue));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::Hxx1::ConstFn<S>::GetName() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LanguageInterface* o_ = (const LanguageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LanguageInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.LanguageInterface_GetName(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::Hxx1::ConstFn<S>::GetIdentifier() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<Id>, Id>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LanguageInterface* o_ = (const LanguageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LanguageInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<Id>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.LanguageInterface_GetIdentifier(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::Hxx1::ConstFn<S>::GetFallbackLanguage() const -> typename std::conditional<S::HAS_ERROR, maxon::Result<LanguageRef>, LanguageRef>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<LanguageRef>, LanguageRef>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LanguageInterface* o_ = (const LanguageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LanguageInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<LanguageRef>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.LanguageInterface_GetFallbackLanguage(o_));
}
template <typename S> MAXON_ATTRIBUTE_FORCE_INLINE auto LanguageInterface::Hxx1::ConstFn<S>::ToString(const maxon::FormatStatement* fs) const -> typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type
{
	using ReturnHelper = maxon::ReferenceFunctionErrorReturnHelper<S::HAS_ERROR, maxon::Bool(S::Handler::KIND & maxon::VALUEKIND::NEVER_NULLPTR), false, typename std::conditional<S::HAS_ERROR, maxon::Result<String>, String>::type>; if (S::HAS_ERROR && this->GetErrorStorage().GetReferencedError()) return ReturnHelper::ReturnErrorOf(this); const LanguageInterface* o_ = (const LanguageInterface*) this->GetPointer(); if (!(S::Handler::KIND & (maxon::VALUEKIND::DEEP_CONSTNESS | maxon::VALUEKIND::NEVER_NULLPTR)) && MAXON_UNLIKELY(!o_)) { o_ = LanguageInterface::NullValuePtr(); if (!o_) return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLPTR, OVERLOAD_MAX_RANK); } 
	return (MTable::_instance.LanguageInterface_ToString(o_, fs));
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
	LanguageRef (*Resource_GetDefaultLanguage) ();
	LanguageRef (*Resource_GetCurrentLanguage) ();
	LanguageRef (*Resource_FindLanguage) (const Id& identifier);
	Result<void> (*Resource_SetCurrentLanguage) (const LanguageRef& language);
	Result<BaseArray<LanguageRef>> (*Resource_GetAllLanguages) ();
	String (*Resource_LoadResourceString) (const Id& scope, const InternedId& keyValue);
	Result<void> (*Resource_WriteLanguagePrf) (const LanguageRef& language);
	maxon::ObservableRef<ObservableLanguageChangedDelegate> (*Resource_ObservableLanguageChanged) ();
	template <typename IMPL> void Init()
	{
		Resource_GetDefaultLanguage = &IMPL::Resource_GetDefaultLanguage;
		Resource_GetCurrentLanguage = &IMPL::Resource_GetCurrentLanguage;
		Resource_FindLanguage = &IMPL::Resource_FindLanguage;
		Resource_SetCurrentLanguage = &IMPL::Resource_SetCurrentLanguage;
		Resource_GetAllLanguages = &IMPL::Resource_GetAllLanguages;
		Resource_LoadResourceString = &IMPL::Resource_LoadResourceString;
		Resource_WriteLanguagePrf = &IMPL::Resource_WriteLanguagePrf;
		Resource_ObservableLanguageChanged = &IMPL::Resource_ObservableLanguageChanged;
	}
};

struct Resource::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
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

