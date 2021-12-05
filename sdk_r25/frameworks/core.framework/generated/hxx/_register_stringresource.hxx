#if 1
namespace maxon
{
	const maxon::Char* const LanguageInterface::MTable::_ids = 
		"Free@67421c19e30b38a9\0" // void Free(const LanguageInterface* object)
		"Alloc@3289d0785d58586a\0" // LanguageInterface* Alloc(const maxon::SourceLocation& allocLocation)
		"LoadResourceString@7efa783af6c2a0a4\0" // String LoadResourceString(const Id& scope, const InternedId& keyValue)
		"GetName@b8f12dfa16054f01\0" // String GetName() const
		"GetIdentifier@33636d531bf4ad19\0" // Id GetIdentifier() const
		"GetFallbackLanguage@40f29d7c3ee8958d\0" // LanguageRef GetFallbackLanguage() const
		"ToString@da40670b9f6f7c7d\0" // String ToString(const maxon::FormatStatement* fs) const
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class LanguageInterface::Hxx2::Unresolved : public LanguageInterface
	{
	public:
		static const Unresolved* Get(const LanguageInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(LanguageInterface* o) { return (Unresolved*) o; }
		static void Free(const LanguageInterface* object) { if (object && maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LanguageInterface::Free(object); return maxon::PrivateLogNullptrError();}
		static LanguageInterface* Alloc(const maxon::SourceLocation& allocLocation) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return LanguageInterface::Alloc(allocLocation); return nullptr;}
		String LoadResourceString(const Id& scope, const InternedId& keyValue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LanguageInterface*) this)->LoadResourceString(scope, keyValue); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		String GetName() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LanguageInterface*) this)->GetName(); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		Id GetIdentifier() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LanguageInterface*) this)->GetIdentifier(); return maxon::PrivateIncompleteNullReturnValue<Id>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		LanguageRef GetFallbackLanguage() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LanguageInterface*) this)->GetFallbackLanguage(); return maxon::PrivateIncompleteNullReturnValue<LanguageRef>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		String ToString(const maxon::FormatStatement* fs) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LanguageInterface*) this)->ToString(fs); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE LanguageInterface::MTable::_returnTypes[] = 
	{
		maxon::NULL_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::NullReturnType<LanguageInterface*>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<Id>::value,
		maxon::details::NullReturnType<LanguageRef>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool LanguageInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LanguageInterface_Free = &Hxx2::Wrapper<Hxx2::Unresolved>::_LanguageInterface_Free;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_LanguageInterface_Alloc = &Hxx2::Wrapper<Hxx2::Unresolved>::_LanguageInterface_Alloc;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LanguageInterface_LoadResourceString = &Hxx2::Wrapper<Hxx2::Unresolved>::_LanguageInterface_LoadResourceString;
		#else
		tbl->_LanguageInterface_LoadResourceString = &Hxx2::Wrapper<Hxx2::Unresolved>::_LanguageInterface_LoadResourceString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LanguageInterface_GetName = &Hxx2::Wrapper<Hxx2::Unresolved>::_LanguageInterface_GetName;
		#else
		tbl->_LanguageInterface_GetName = &Hxx2::Wrapper<Hxx2::Unresolved>::_LanguageInterface_GetName;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Id>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LanguageInterface_GetIdentifier = &Hxx2::Wrapper<Hxx2::Unresolved>::_LanguageInterface_GetIdentifier;
		#else
		tbl->_LanguageInterface_GetIdentifier = &Hxx2::Wrapper<Hxx2::Unresolved>::_LanguageInterface_GetIdentifier;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<LanguageRef>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LanguageInterface_GetFallbackLanguage = &Hxx2::Wrapper<Hxx2::Unresolved>::_LanguageInterface_GetFallbackLanguage;
		#else
		tbl->_LanguageInterface_GetFallbackLanguage = &Hxx2::Wrapper<Hxx2::Unresolved>::_LanguageInterface_GetFallbackLanguage;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LanguageInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_LanguageInterface_ToString;
		#else
		tbl->_LanguageInterface_ToString = &Hxx2::Wrapper<Hxx2::Unresolved>::_LanguageInterface_ToString;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(LanguageInterface, "net.maxon.interface.language", nullptr);
	template <typename DUMMY> maxon::Int LanguageInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<Id>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<LanguageRef>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const Resource::MTable::_ids = 
		"GetDefaultLanguage@40f29d7c25e86e32\0" // LanguageRef GetDefaultLanguage()
		"GetCurrentLanguage@40f29d7c25e86e32\0" // LanguageRef GetCurrentLanguage()
		"FindLanguage@c84f0877d6035202\0" // LanguageRef FindLanguage(const Id& identifier)
		"SetCurrentLanguage@19891a1ee3b2bc20\0" // Result<void> SetCurrentLanguage(const LanguageRef& language)
		"GetAllLanguages@efe23a861625120f\0" // Result<BaseArray<LanguageRef>> GetAllLanguages()
		"LoadResourceString@1f420772fb62b485\0" // String LoadResourceString(const Id& scope, const InternedId& keyValue)
		"WriteLanguagePrf@19891a1ee3b2bc20\0" // Result<void> WriteLanguagePrf(const LanguageRef& language)
		"ObservableLanguageChanged@b9e05ba42c864260\0" // maxon::ObservableRef<ObservableLanguageChangedDelegate> ObservableLanguageChanged()
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class Resource::Hxx2::Unresolved : public Resource
	{
	public:
		static const Unresolved* Get(const Resource* o) { return (const Unresolved*) o; }
		static Unresolved* Get(Resource* o) { return (Unresolved*) o; }
		static LanguageRef GetDefaultLanguage() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Resource::GetDefaultLanguage(); return maxon::PrivateIncompleteNullReturnValue<LanguageRef>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static LanguageRef GetCurrentLanguage() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Resource::GetCurrentLanguage(); return maxon::PrivateIncompleteNullReturnValue<LanguageRef>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static LanguageRef FindLanguage(const Id& identifier) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Resource::FindLanguage(identifier); return maxon::PrivateIncompleteNullReturnValue<LanguageRef>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<void> SetCurrentLanguage(const LanguageRef& language) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Resource::SetCurrentLanguage(language); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<BaseArray<LanguageRef>> GetAllLanguages() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Resource::GetAllLanguages(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static String LoadResourceString(const Id& scope, const InternedId& keyValue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Resource::LoadResourceString(scope, keyValue); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Result<void> WriteLanguagePrf(const LanguageRef& language) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Resource::WriteLanguagePrf(language); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static maxon::ObservableRef<ObservableLanguageChangedDelegate> ObservableLanguageChanged() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Resource::ObservableLanguageChanged(); return maxon::ObservableRef<ObservableLanguageChangedDelegate>::NullValue();}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE Resource::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<LanguageRef>::value,
		maxon::details::NullReturnType<LanguageRef>::value,
		maxon::details::NullReturnType<LanguageRef>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<BaseArray<LanguageRef>>>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<maxon::ObservableRef<ObservableLanguageChangedDelegate>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool Resource::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<LanguageRef>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Resource_GetDefaultLanguage = &Hxx2::Wrapper<Hxx2::Unresolved>::_Resource_GetDefaultLanguage;
		#else
		tbl->_Resource_GetDefaultLanguage = &Hxx2::Wrapper<Hxx2::Unresolved>::_Resource_GetDefaultLanguage;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<LanguageRef>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Resource_GetCurrentLanguage = &Hxx2::Wrapper<Hxx2::Unresolved>::_Resource_GetCurrentLanguage;
		#else
		tbl->_Resource_GetCurrentLanguage = &Hxx2::Wrapper<Hxx2::Unresolved>::_Resource_GetCurrentLanguage;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<LanguageRef>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Resource_FindLanguage = &Hxx2::Wrapper<Hxx2::Unresolved>::_Resource_FindLanguage;
		#else
		tbl->_Resource_FindLanguage = &Hxx2::Wrapper<Hxx2::Unresolved>::_Resource_FindLanguage;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Resource_SetCurrentLanguage = &Hxx2::Wrapper<Hxx2::Unresolved>::_Resource_SetCurrentLanguage;
		#else
		tbl->_Resource_SetCurrentLanguage = &Hxx2::Wrapper<Hxx2::Unresolved>::_Resource_SetCurrentLanguage;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<LanguageRef>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Resource_GetAllLanguages = &Hxx2::Wrapper<Hxx2::Unresolved>::_Resource_GetAllLanguages;
		#else
		tbl->_Resource_GetAllLanguages = &Hxx2::Wrapper<Hxx2::Unresolved>::_Resource_GetAllLanguages;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Resource_LoadResourceString = &Hxx2::Wrapper<Hxx2::Unresolved>::_Resource_LoadResourceString;
		#else
		tbl->_Resource_LoadResourceString = &Hxx2::Wrapper<Hxx2::Unresolved>::_Resource_LoadResourceString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Resource_WriteLanguagePrf = &Hxx2::Wrapper<Hxx2::Unresolved>::_Resource_WriteLanguagePrf;
		#else
		tbl->_Resource_WriteLanguagePrf = &Hxx2::Wrapper<Hxx2::Unresolved>::_Resource_WriteLanguagePrf;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableLanguageChangedDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Resource_ObservableLanguageChanged = &Hxx2::Wrapper<Hxx2::Unresolved>::_Resource_ObservableLanguageChanged;
		#else
		tbl->_Resource_ObservableLanguageChanged = &Hxx2::Wrapper<Hxx2::Unresolved>::_Resource_ObservableLanguageChanged;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(Resource, "net.maxon.interface.resource", nullptr);
	template <typename DUMMY> maxon::Int Resource::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<LanguageRef>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_stringresource(0
	| maxon::LanguageInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::Resource::PrivateInstantiateNullValueHelper<maxon::Int>()
);
