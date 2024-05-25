#if 1
namespace maxon
{
	namespace enum22
	{
		enum class ACCESSLEVEL
		{
			UNDEFINED = 0,		///< not defined, invalid setting.
			USERINSTALLATION, ///< settings for this users local installation.
			ACCOUNT,					///< settings for the currently logged-in user.
			USER,							///< settings for the current local user.
			MACHINE,					///< settings for all users of the current machine.
			DEFAULTS,					///< settings of the default value (needs to be initialized on startup)
			ALL,							///< start level of the search through all instances USERINSTALLATION -> ACCOUNT -> USER -> MACHINE -> DEFAULT
		} ;
		static const maxon::UInt64 ACCESSLEVEL_values[] = {maxon::UInt64(enum22::ACCESSLEVEL::UNDEFINED), maxon::UInt64(enum22::ACCESSLEVEL::USERINSTALLATION), maxon::UInt64(enum22::ACCESSLEVEL::ACCOUNT), maxon::UInt64(enum22::ACCESSLEVEL::USER), maxon::UInt64(enum22::ACCESSLEVEL::MACHINE), maxon::UInt64(enum22::ACCESSLEVEL::DEFAULTS), maxon::UInt64(enum22::ACCESSLEVEL::ALL)};
		static const maxon::EnumInfo ACCESSLEVEL_info{"ACCESSLEVEL", SIZEOF(ACCESSLEVEL), false, "UNDEFINED\0USERINSTALLATION\0ACCOUNT\0USER\0MACHINE\0DEFAULTS\0ALL\0", ACCESSLEVEL_values, std::extent<decltype(ACCESSLEVEL_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_ACCESSLEVEL22(){ return enum22::ACCESSLEVEL_info; }
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class SettingsInterface::Hxx2::Unresolved : public SettingsInterface
	{
	public:
		static SettingsRef GetSettings(ACCESSLEVEL accessLevel) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, true)) return SettingsInterface::GetSettings(accessLevel); return HXXRET3(UNRESOLVED, SettingsRef);}
		static maxon::ObservableRef<ObservableSettingsChangedDelegate> ObservableSettingsChanged(Bool create) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, true)) return SettingsInterface::ObservableSettingsChanged(create); return maxon::ObservableRef<ObservableSettingsChangedDelegate>::DefaultValue();}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE SettingsInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<SettingsRef>::value,
		maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableSettingsChangedDelegate>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool SettingsInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<SettingsRef>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SettingsInterface_GetSettings = PRIVATE_MAXON_MF_CAST(decltype(SettingsInterface_GetSettings), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::SettingsInterface_GetSettings);
		#else
		tbl->SettingsInterface_GetSettings = PRIVATE_MAXON_MF_CAST(decltype(SettingsInterface_GetSettings), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::SettingsInterface_GetSettings);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableSettingsChangedDelegate>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SettingsInterface_ObservableSettingsChanged = PRIVATE_MAXON_MF_CAST(decltype(SettingsInterface_ObservableSettingsChanged), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::SettingsInterface_ObservableSettingsChanged);
		#else
		tbl->SettingsInterface_ObservableSettingsChanged = PRIVATE_MAXON_MF_CAST(decltype(SettingsInterface_ObservableSettingsChanged), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::SettingsInterface_ObservableSettingsChanged);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (const void**) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const SettingsInterface::MTable::_ids = 
		"GetAccessLevel@a2018d78d7f99ec6\0" // ACCESSLEVEL GetAccessLevel() const
		"GetParentSettings@c07ed741c90a0648\0" // SettingsRef GetParentSettings() const
		"GetSettingsCopy@90fe47221f849817\0" // Result<DataDictionary> GetSettingsCopy(const HashSet<Id>& optionalList, ACCESSLEVEL accessLevel) const
	"";
	const maxon::METHOD_FLAGS SettingsInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(SettingsInterface, , "net.maxon.interface.settingsinterface", (DataDictionaryObjectInterface::PrivateGetInterface()));
	const maxon::Char* const SettingsInterface::Hxx2::StaticMTable::_ids = 
		"GetSettings@f51ae0a29759c57b\0" // SettingsRef GetSettings(ACCESSLEVEL accessLevel)
		"ObservableSettingsChanged@eb5ed3c9920e01af\0" // maxon::ObservableRef<ObservableSettingsChangedDelegate> ObservableSettingsChanged(Bool create)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(SettingsInterface, , "net.maxon.interface.settingsinterface");
	template <typename DUMMY> maxon::Int SettingsInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<ACCESSLEVEL>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<SettingsRef>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_settingsinterface(0
	| maxon::SettingsInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
