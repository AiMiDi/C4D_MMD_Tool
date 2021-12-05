#if 1
namespace maxon
{
	const maxon::Char* const LanguageInterface::MTable::_ids = 
		"Free@5c0d336b74006f2e\0" // Free(const LanguageInterface* object)
		"Alloc@685eb92d48ebcf79\0" // Alloc(const maxon::SourceLocation& allocLocation)
		"LoadResourceString@19f1ca1db56084ad\0" // LoadResourceString(const Id& scope, const InternedId& keyValue)
		"GetName@22c6ed80868\0" // GetName() const
		"GetIdentifier@22aaf2\0" // GetIdentifier() const
		"GetFallbackLanguage@62404ffa164de7b2\0" // GetFallbackLanguage() const
		"ToString@e0aa3c58bc543cb4\0" // ToString(const maxon::FormatStatement* fs) const
	"";
	class LanguageInterface::Unresolved : public LanguageInterface
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
		tbl->_LanguageInterface_Free = &Wrapper<Unresolved>::_LanguageInterface_Free;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_LanguageInterface_Alloc = &Wrapper<Unresolved>::_LanguageInterface_Alloc;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LanguageInterface_LoadResourceString = &Wrapper<Unresolved>::_LanguageInterface_LoadResourceString;
	#else
		tbl->_LanguageInterface_LoadResourceString = &Wrapper<Unresolved>::_LanguageInterface_LoadResourceString;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LanguageInterface_GetName = &Wrapper<Unresolved>::_LanguageInterface_GetName;
	#else
		tbl->_LanguageInterface_GetName = &Wrapper<Unresolved>::_LanguageInterface_GetName;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Id>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LanguageInterface_GetIdentifier = &Wrapper<Unresolved>::_LanguageInterface_GetIdentifier;
	#else
		tbl->_LanguageInterface_GetIdentifier = &Wrapper<Unresolved>::_LanguageInterface_GetIdentifier;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<LanguageRef>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LanguageInterface_GetFallbackLanguage = &Wrapper<Unresolved>::_LanguageInterface_GetFallbackLanguage;
	#else
		tbl->_LanguageInterface_GetFallbackLanguage = &Wrapper<Unresolved>::_LanguageInterface_GetFallbackLanguage;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LanguageInterface_ToString = &Wrapper<Unresolved>::_LanguageInterface_ToString;
	#else
		tbl->_LanguageInterface_ToString = &Wrapper<Unresolved>::_LanguageInterface_ToString;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
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
		"GetDefaultLanguage@62404ffa164de79b\0" // GetDefaultLanguage()
		"GetCurrentLanguage@62404ffa164de79b\0" // GetCurrentLanguage()
		"FindLanguage@b7bf87b167eb895d\0" // FindLanguage(const Id& identifier)
		"SetCurrentLanguage@39bdfe18bf074e63\0" // SetCurrentLanguage(const LanguageRef& language)
		"GetAllLanguages@140dfdd02956b008\0" // GetAllLanguages()
		"LoadResourceString@24477998f6b01116\0" // LoadResourceString(const Id& scope, const InternedId& keyValue)
		"ObservableLanguageChanged@94449cc5e219b96f\0" // ObservableLanguageChanged()
	"";
	class Resource::Unresolved : public Resource
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
		static maxon::ObservableRef<ObservableLanguageChangedDelegate> ObservableLanguageChanged() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Resource::ObservableLanguageChanged(); return maxon::ObservableRef<ObservableLanguageChangedDelegate>::NullValue();}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE Resource::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<LanguageRef>::value,
		maxon::details::NullReturnType<LanguageRef>::value,
		maxon::details::NullReturnType<LanguageRef>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<BaseArray<LanguageRef>>>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<maxon::ObservableRef<ObservableLanguageChangedDelegate>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool Resource::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<LanguageRef>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Resource_GetDefaultLanguage = &Wrapper<Unresolved>::_Resource_GetDefaultLanguage;
	#else
		tbl->_Resource_GetDefaultLanguage = &Wrapper<Unresolved>::_Resource_GetDefaultLanguage;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<LanguageRef>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Resource_GetCurrentLanguage = &Wrapper<Unresolved>::_Resource_GetCurrentLanguage;
	#else
		tbl->_Resource_GetCurrentLanguage = &Wrapper<Unresolved>::_Resource_GetCurrentLanguage;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<LanguageRef>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Resource_FindLanguage = &Wrapper<Unresolved>::_Resource_FindLanguage;
	#else
		tbl->_Resource_FindLanguage = &Wrapper<Unresolved>::_Resource_FindLanguage;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Resource_SetCurrentLanguage = &Wrapper<Unresolved>::_Resource_SetCurrentLanguage;
	#else
		tbl->_Resource_SetCurrentLanguage = &Wrapper<Unresolved>::_Resource_SetCurrentLanguage;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<LanguageRef>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Resource_GetAllLanguages = &Wrapper<Unresolved>::_Resource_GetAllLanguages;
	#else
		tbl->_Resource_GetAllLanguages = &Wrapper<Unresolved>::_Resource_GetAllLanguages;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Resource_LoadResourceString = &Wrapper<Unresolved>::_Resource_LoadResourceString;
	#else
		tbl->_Resource_LoadResourceString = &Wrapper<Unresolved>::_Resource_LoadResourceString;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableLanguageChangedDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Resource_ObservableLanguageChanged = &Wrapper<Unresolved>::_Resource_ObservableLanguageChanged;
	#else
		tbl->_Resource_ObservableLanguageChanged = &Wrapper<Unresolved>::_Resource_ObservableLanguageChanged;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
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
