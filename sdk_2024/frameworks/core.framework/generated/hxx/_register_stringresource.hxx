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
		String LoadResourceString(const Id& scope, const InternedId& keyValue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((LanguageInterface*) this)->LoadResourceString(scope, keyValue); return HXXRET3(UNRESOLVED, String);}
		String GetName() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LanguageInterface*) this)->GetName(); return HXXRET3(UNRESOLVED, String);}
		Id GetIdentifier() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LanguageInterface*) this)->GetIdentifier(); return HXXRET3(UNRESOLVED, Id);}
		LanguageRef GetFallbackLanguage() const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LanguageInterface*) this)->GetFallbackLanguage(); return HXXRET3(UNRESOLVED, LanguageRef);}
		String ToString(const maxon::FormatStatement* fs) const { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return ((const LanguageInterface*) this)->ToString(fs); return HXXRET3(UNRESOLVED, String);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE LanguageInterface::MTable::_returnTypes[] = 
	{
		maxon::UNRESOLVED_RETURN_TYPE::VOID_ZERO_FREE_FUNCTION,
		maxon::details::UnresolvedReturnType<LanguageInterface*>::value,
		maxon::details::UnresolvedReturnType<String>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<String>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<Id>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<LanguageRef>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::details::UnresolvedReturnType<String>::value | maxon::UNRESOLVED_RETURN_TYPE::MEMBER_FUNCTION_FLAG,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool LanguageInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LanguageInterface_Free = PRIVATE_MAXON_MF_CAST(decltype(LanguageInterface_Free), &Hxx2::Wrapper<Hxx2::Unresolved>::LanguageInterface_Free);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LanguageInterface_Alloc = PRIVATE_MAXON_MF_CAST(decltype(LanguageInterface_Alloc), &Hxx2::Wrapper<Hxx2::Unresolved>::LanguageInterface_Alloc);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LanguageInterface_LoadResourceString = PRIVATE_MAXON_MF_CAST(decltype(LanguageInterface_LoadResourceString), &Hxx2::Wrapper<Hxx2::Unresolved>::LanguageInterface_LoadResourceString);
		#else
		tbl->LanguageInterface_LoadResourceString = PRIVATE_MAXON_MF_CAST(decltype(LanguageInterface_LoadResourceString), &Hxx2::Wrapper<Hxx2::Unresolved>::LanguageInterface_LoadResourceString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LanguageInterface_GetName = PRIVATE_MAXON_MF_CAST(decltype(LanguageInterface_GetName), &Hxx2::Wrapper<Hxx2::Unresolved>::LanguageInterface_GetName);
		#else
		tbl->LanguageInterface_GetName = PRIVATE_MAXON_MF_CAST(decltype(LanguageInterface_GetName), &Hxx2::Wrapper<Hxx2::Unresolved>::LanguageInterface_GetName);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Id>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LanguageInterface_GetIdentifier = PRIVATE_MAXON_MF_CAST(decltype(LanguageInterface_GetIdentifier), &Hxx2::Wrapper<Hxx2::Unresolved>::LanguageInterface_GetIdentifier);
		#else
		tbl->LanguageInterface_GetIdentifier = PRIVATE_MAXON_MF_CAST(decltype(LanguageInterface_GetIdentifier), &Hxx2::Wrapper<Hxx2::Unresolved>::LanguageInterface_GetIdentifier);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<LanguageRef>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LanguageInterface_GetFallbackLanguage = PRIVATE_MAXON_MF_CAST(decltype(LanguageInterface_GetFallbackLanguage), &Hxx2::Wrapper<Hxx2::Unresolved>::LanguageInterface_GetFallbackLanguage);
		#else
		tbl->LanguageInterface_GetFallbackLanguage = PRIVATE_MAXON_MF_CAST(decltype(LanguageInterface_GetFallbackLanguage), &Hxx2::Wrapper<Hxx2::Unresolved>::LanguageInterface_GetFallbackLanguage);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->LanguageInterface_ToString = PRIVATE_MAXON_MF_CAST(decltype(LanguageInterface_ToString), &Hxx2::Wrapper<Hxx2::Unresolved>::LanguageInterface_ToString);
		#else
		tbl->LanguageInterface_ToString = PRIVATE_MAXON_MF_CAST(decltype(LanguageInterface_ToString), &Hxx2::Wrapper<Hxx2::Unresolved>::LanguageInterface_ToString);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(LanguageInterface, "net.maxon.interface.language", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int LanguageInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<Id>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<LanguageRef>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<String>(OVERLOAD_MAX_RANK)
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
		"ObservableLanguageChanged@4122d427972e1adc\0" // maxon::ObservableRef<ObservableLanguageChangedDelegate> ObservableLanguageChanged(Bool create)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class Resource::Hxx2::Unresolved : public Resource
	{
	public:
		static const Unresolved* Get(const Resource* o) { return (const Unresolved*) o; }
		static Unresolved* Get(Resource* o) { return (Unresolved*) o; }
		static LanguageRef GetDefaultLanguage() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Resource::GetDefaultLanguage(); return HXXRET3(UNRESOLVED, LanguageRef);}
		static LanguageRef GetCurrentLanguage() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Resource::GetCurrentLanguage(); return HXXRET3(UNRESOLVED, LanguageRef);}
		static LanguageRef FindLanguage(const Id& identifier) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Resource::FindLanguage(identifier); return HXXRET3(UNRESOLVED, LanguageRef);}
		static Result<void> SetCurrentLanguage(const LanguageRef& language) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Resource::SetCurrentLanguage(language); return HXXRET1(UNRESOLVED);}
		static Result<BaseArray<LanguageRef>> GetAllLanguages() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Resource::GetAllLanguages(); return HXXRET1(UNRESOLVED);}
		static String LoadResourceString(const Id& scope, const InternedId& keyValue) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Resource::LoadResourceString(scope, keyValue); return HXXRET3(UNRESOLVED, String);}
		static Result<void> WriteLanguagePrf(const LanguageRef& language) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Resource::WriteLanguagePrf(language); return HXXRET1(UNRESOLVED);}
		static maxon::ObservableRef<ObservableLanguageChangedDelegate> ObservableLanguageChanged(Bool create) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Resource::ObservableLanguageChanged(create); return maxon::ObservableRef<ObservableLanguageChangedDelegate>::DefaultValue();}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE Resource::MTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<LanguageRef>::value,
		maxon::details::UnresolvedReturnType<LanguageRef>::value,
		maxon::details::UnresolvedReturnType<LanguageRef>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Result<BaseArray<LanguageRef>>>::value,
		maxon::details::UnresolvedReturnType<String>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableLanguageChangedDelegate>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool Resource::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<LanguageRef>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Resource_GetDefaultLanguage = PRIVATE_MAXON_MF_CAST(decltype(Resource_GetDefaultLanguage), &Hxx2::Wrapper<Hxx2::Unresolved>::Resource_GetDefaultLanguage);
		#else
		tbl->Resource_GetDefaultLanguage = PRIVATE_MAXON_MF_CAST(decltype(Resource_GetDefaultLanguage), &Hxx2::Wrapper<Hxx2::Unresolved>::Resource_GetDefaultLanguage);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<LanguageRef>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Resource_GetCurrentLanguage = PRIVATE_MAXON_MF_CAST(decltype(Resource_GetCurrentLanguage), &Hxx2::Wrapper<Hxx2::Unresolved>::Resource_GetCurrentLanguage);
		#else
		tbl->Resource_GetCurrentLanguage = PRIVATE_MAXON_MF_CAST(decltype(Resource_GetCurrentLanguage), &Hxx2::Wrapper<Hxx2::Unresolved>::Resource_GetCurrentLanguage);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<LanguageRef>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Resource_FindLanguage = PRIVATE_MAXON_MF_CAST(decltype(Resource_FindLanguage), &Hxx2::Wrapper<Hxx2::Unresolved>::Resource_FindLanguage);
		#else
		tbl->Resource_FindLanguage = PRIVATE_MAXON_MF_CAST(decltype(Resource_FindLanguage), &Hxx2::Wrapper<Hxx2::Unresolved>::Resource_FindLanguage);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Resource_SetCurrentLanguage = PRIVATE_MAXON_MF_CAST(decltype(Resource_SetCurrentLanguage), &Hxx2::Wrapper<Hxx2::Unresolved>::Resource_SetCurrentLanguage);
		#else
		tbl->Resource_SetCurrentLanguage = PRIVATE_MAXON_MF_CAST(decltype(Resource_SetCurrentLanguage), &Hxx2::Wrapper<Hxx2::Unresolved>::Resource_SetCurrentLanguage);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<BaseArray<LanguageRef>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Resource_GetAllLanguages = PRIVATE_MAXON_MF_CAST(decltype(Resource_GetAllLanguages), &Hxx2::Wrapper<Hxx2::Unresolved>::Resource_GetAllLanguages);
		#else
		tbl->Resource_GetAllLanguages = PRIVATE_MAXON_MF_CAST(decltype(Resource_GetAllLanguages), &Hxx2::Wrapper<Hxx2::Unresolved>::Resource_GetAllLanguages);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Resource_LoadResourceString = PRIVATE_MAXON_MF_CAST(decltype(Resource_LoadResourceString), &Hxx2::Wrapper<Hxx2::Unresolved>::Resource_LoadResourceString);
		#else
		tbl->Resource_LoadResourceString = PRIVATE_MAXON_MF_CAST(decltype(Resource_LoadResourceString), &Hxx2::Wrapper<Hxx2::Unresolved>::Resource_LoadResourceString);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Resource_WriteLanguagePrf = PRIVATE_MAXON_MF_CAST(decltype(Resource_WriteLanguagePrf), &Hxx2::Wrapper<Hxx2::Unresolved>::Resource_WriteLanguagePrf);
		#else
		tbl->Resource_WriteLanguagePrf = PRIVATE_MAXON_MF_CAST(decltype(Resource_WriteLanguagePrf), &Hxx2::Wrapper<Hxx2::Unresolved>::Resource_WriteLanguagePrf);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableLanguageChangedDelegate>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Resource_ObservableLanguageChanged = PRIVATE_MAXON_MF_CAST(decltype(Resource_ObservableLanguageChanged), &Hxx2::Wrapper<Hxx2::Unresolved>::Resource_ObservableLanguageChanged);
		#else
		tbl->Resource_ObservableLanguageChanged = PRIVATE_MAXON_MF_CAST(decltype(Resource_ObservableLanguageChanged), &Hxx2::Wrapper<Hxx2::Unresolved>::Resource_ObservableLanguageChanged);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(Resource, "net.maxon.interface.resource", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int Resource::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<LanguageRef>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_stringresource(0
	| maxon::LanguageInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
	| maxon::Resource::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
