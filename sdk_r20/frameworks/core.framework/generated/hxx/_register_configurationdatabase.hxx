#if 1
namespace maxon
{
	const maxon::Char* const Configuration::MTable::_ids = 
		"QueryBool@ef8f9ea4628ac75d\0" // QueryBool(const String& key, Bool& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state)
		"QueryInt@cb8ec20bda75b9b2\0" // QueryInt(const String& key, Int& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state)
		"QueryFloat@a920ecd3d34b1965\0" // QueryFloat(const String& key, Float& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state)
		"QueryString@af6e1b0e826ad996\0" // QueryString(const String& key, String& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state)
		"AddHelpForBool@2facd672d085eb9b\0" // AddHelpForBool(const String& key, Bool defaultValue, CONFIGURATION_CATEGORY category, const Char* help)
		"AddHelpForInt@75f2b3f848ed1a4e\0" // AddHelpForInt(const String& key, Int defaultValue, Int minValue, Int maxValue, CONFIGURATION_CATEGORY category, const Char* help)
		"AddHelpForFloat@6eae270af7793395\0" // AddHelpForFloat(const String& key, Float defaultValue, Float minValue, Float maxValue, CONFIGURATION_CATEGORY category, const Char* help)
		"AddHelpForString@9615c3a79ffb6291\0" // AddHelpForString(const String& key, const String& defaultValue, CONFIGURATION_CATEGORY category, const Char* help)
		"AddHelpForOption@c28c156824143d51\0" // AddHelpForOption(const String& key, const String& option, Bool isDefaultValue, Bool caseSensitive, CONFIGURATION_CATEGORY category, const Char* help)
		"BroadcastBool@8d014d2ca3c36a6d\0" // BroadcastBool(const String& key, Bool value)
		"BroadcastInt@15108ee068644fa0\0" // BroadcastInt(const String& key, Int value)
		"BroadcastFloat@13285867db52dfd3\0" // BroadcastFloat(const String& key, Float value)
		"BroadcastString@3d99cc2bbe81ef37\0" // BroadcastString(const String& key, const String& value)
	"";
	class Configuration::Unresolved : public Configuration
	{
	public:
		static const Unresolved* Get(const Configuration* o) { return (const Unresolved*) o; }
		static Unresolved* Get(Configuration* o) { return (Unresolved*) o; }
		static Bool QueryBool(const String& key, Bool& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Configuration::QueryBool(key, result, origin, state); return maxon::PrivateLogNullptrError(false);}
		static Bool QueryInt(const String& key, Int& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Configuration::QueryInt(key, result, origin, state); return maxon::PrivateLogNullptrError(false);}
		static Bool QueryFloat(const String& key, Float& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Configuration::QueryFloat(key, result, origin, state); return maxon::PrivateLogNullptrError(false);}
		static Bool QueryString(const String& key, String& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Configuration::QueryString(key, result, origin, state); return maxon::PrivateLogNullptrError(false);}
		static Result<void> AddHelpForBool(const String& key, Bool defaultValue, CONFIGURATION_CATEGORY category, const Char* help) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Configuration::AddHelpForBool(key, defaultValue, category, help); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> AddHelpForInt(const String& key, Int defaultValue, Int minValue, Int maxValue, CONFIGURATION_CATEGORY category, const Char* help) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Configuration::AddHelpForInt(key, defaultValue, minValue, maxValue, category, help); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> AddHelpForFloat(const String& key, Float defaultValue, Float minValue, Float maxValue, CONFIGURATION_CATEGORY category, const Char* help) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Configuration::AddHelpForFloat(key, defaultValue, minValue, maxValue, category, help); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> AddHelpForString(const String& key, const String& defaultValue, CONFIGURATION_CATEGORY category, const Char* help) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Configuration::AddHelpForString(key, defaultValue, category, help); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> AddHelpForOption(const String& key, const String& option, Bool isDefaultValue, Bool caseSensitive, CONFIGURATION_CATEGORY category, const Char* help) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Configuration::AddHelpForOption(key, option, isDefaultValue, caseSensitive, category, help); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> BroadcastBool(const String& key, Bool value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Configuration::BroadcastBool(key, value); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> BroadcastInt(const String& key, Int value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Configuration::BroadcastInt(key, value); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> BroadcastFloat(const String& key, Float value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Configuration::BroadcastFloat(key, value); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> BroadcastString(const String& key, const String& value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Configuration::BroadcastString(key, value); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE Configuration::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool Configuration::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_Configuration_QueryBool = &Wrapper<Unresolved>::_Configuration_QueryBool;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_Configuration_QueryInt = &Wrapper<Unresolved>::_Configuration_QueryInt;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_Configuration_QueryFloat = &Wrapper<Unresolved>::_Configuration_QueryFloat;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_Configuration_QueryString = &Wrapper<Unresolved>::_Configuration_QueryString;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_AddHelpForBool = &Wrapper<Unresolved>::_Configuration_AddHelpForBool;
	#else
		tbl->_Configuration_AddHelpForBool = &Wrapper<Unresolved>::_Configuration_AddHelpForBool;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_AddHelpForInt = &Wrapper<Unresolved>::_Configuration_AddHelpForInt;
	#else
		tbl->_Configuration_AddHelpForInt = &Wrapper<Unresolved>::_Configuration_AddHelpForInt;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_AddHelpForFloat = &Wrapper<Unresolved>::_Configuration_AddHelpForFloat;
	#else
		tbl->_Configuration_AddHelpForFloat = &Wrapper<Unresolved>::_Configuration_AddHelpForFloat;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_AddHelpForString = &Wrapper<Unresolved>::_Configuration_AddHelpForString;
	#else
		tbl->_Configuration_AddHelpForString = &Wrapper<Unresolved>::_Configuration_AddHelpForString;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_AddHelpForOption = &Wrapper<Unresolved>::_Configuration_AddHelpForOption;
	#else
		tbl->_Configuration_AddHelpForOption = &Wrapper<Unresolved>::_Configuration_AddHelpForOption;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_BroadcastBool = &Wrapper<Unresolved>::_Configuration_BroadcastBool;
	#else
		tbl->_Configuration_BroadcastBool = &Wrapper<Unresolved>::_Configuration_BroadcastBool;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_BroadcastInt = &Wrapper<Unresolved>::_Configuration_BroadcastInt;
	#else
		tbl->_Configuration_BroadcastInt = &Wrapper<Unresolved>::_Configuration_BroadcastInt;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_BroadcastFloat = &Wrapper<Unresolved>::_Configuration_BroadcastFloat;
	#else
		tbl->_Configuration_BroadcastFloat = &Wrapper<Unresolved>::_Configuration_BroadcastFloat;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_BroadcastString = &Wrapper<Unresolved>::_Configuration_BroadcastString;
	#else
		tbl->_Configuration_BroadcastString = &Wrapper<Unresolved>::_Configuration_BroadcastString;
	#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(Configuration, "net.maxon.interface.configuration", nullptr);
	template <typename DUMMY> maxon::Int Configuration::PrivateInstantiateNullValueHelper()
	{
		return 0
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_configurationdatabase(0
	| maxon::Configuration::PrivateInstantiateNullValueHelper<maxon::Int>()
);
