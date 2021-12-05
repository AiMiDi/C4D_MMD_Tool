#if 1
namespace maxon
{
	const maxon::Char* const Configuration::MTable::_ids = 
		"QueryBool@fdec8f5c8324ab0f\0" // Result<void> QueryBool(const String& key, Bool& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state)
		"QueryInt@46a8b37f17640ea\0" // Result<void> QueryInt(const String& key, Int& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state)
		"QueryFloat@e833dabcb1e6777f\0" // Result<void> QueryFloat(const String& key, Float& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state)
		"QueryString@a8c95af7bf9e30bc\0" // Result<void> QueryString(const String& key, String& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state)
		"AddHelpForBool@ab066a71f51eff80\0" // Result<void> AddHelpForBool(const String& key, Bool defaultValue, CONFIGURATION_CATEGORY category, const Char* help)
		"AddHelpForInt@acb3e180880efea7\0" // Result<void> AddHelpForInt(const String& key, Int defaultValue, Int minValue, Int maxValue, CONFIGURATION_CATEGORY category, const Char* help)
		"AddHelpForFloat@d3e7350923462284\0" // Result<void> AddHelpForFloat(const String& key, Float defaultValue, Float minValue, Float maxValue, CONFIGURATION_CATEGORY category, const Char* help)
		"AddHelpForString@8c19efa2aca6fd80\0" // Result<void> AddHelpForString(const String& key, const String& defaultValue, CONFIGURATION_CATEGORY category, const Char* help)
		"AddHelpForOption@36dc3bd6a92c997c\0" // Result<void> AddHelpForOption(const String& key, const String& option, Bool isDefaultValue, Bool caseSensitive, CONFIGURATION_CATEGORY category, const Char* help)
		"BroadcastBool@fb08fb7d73c1b710\0" // Result<void> BroadcastBool(const String& key, Bool value)
		"BroadcastInt@db0d7077ecbe471\0" // Result<void> BroadcastInt(const String& key, Int value)
		"BroadcastFloat@214b263615cd2800\0" // Result<void> BroadcastFloat(const String& key, Float value)
		"BroadcastString@21291c5b4237f110\0" // Result<void> BroadcastString(const String& key, const String& value)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class Configuration::Hxx2::Unresolved : public Configuration
	{
	public:
		static const Unresolved* Get(const Configuration* o) { return (const Unresolved*) o; }
		static Unresolved* Get(Configuration* o) { return (Unresolved*) o; }
		static Result<void> QueryBool(const String& key, Bool& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Configuration::QueryBool(key, result, origin, state); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> QueryInt(const String& key, Int& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Configuration::QueryInt(key, result, origin, state); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> QueryFloat(const String& key, Float& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Configuration::QueryFloat(key, result, origin, state); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> QueryString(const String& key, String& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Configuration::QueryString(key, result, origin, state); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
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
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE Configuration::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
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
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_QueryBool = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_QueryBool;
		#else
		tbl->_Configuration_QueryBool = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_QueryBool;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_QueryInt = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_QueryInt;
		#else
		tbl->_Configuration_QueryInt = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_QueryInt;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_QueryFloat = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_QueryFloat;
		#else
		tbl->_Configuration_QueryFloat = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_QueryFloat;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_QueryString = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_QueryString;
		#else
		tbl->_Configuration_QueryString = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_QueryString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_AddHelpForBool = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_AddHelpForBool;
		#else
		tbl->_Configuration_AddHelpForBool = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_AddHelpForBool;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_AddHelpForInt = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_AddHelpForInt;
		#else
		tbl->_Configuration_AddHelpForInt = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_AddHelpForInt;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_AddHelpForFloat = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_AddHelpForFloat;
		#else
		tbl->_Configuration_AddHelpForFloat = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_AddHelpForFloat;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_AddHelpForString = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_AddHelpForString;
		#else
		tbl->_Configuration_AddHelpForString = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_AddHelpForString;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_AddHelpForOption = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_AddHelpForOption;
		#else
		tbl->_Configuration_AddHelpForOption = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_AddHelpForOption;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_BroadcastBool = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_BroadcastBool;
		#else
		tbl->_Configuration_BroadcastBool = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_BroadcastBool;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_BroadcastInt = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_BroadcastInt;
		#else
		tbl->_Configuration_BroadcastInt = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_BroadcastInt;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_BroadcastFloat = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_BroadcastFloat;
		#else
		tbl->_Configuration_BroadcastFloat = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_BroadcastFloat;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Configuration_BroadcastString = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_BroadcastString;
		#else
		tbl->_Configuration_BroadcastString = &Hxx2::Wrapper<Hxx2::Unresolved>::_Configuration_BroadcastString;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(Configuration, "net.maxon.interface.configuration", nullptr);
}
#endif
