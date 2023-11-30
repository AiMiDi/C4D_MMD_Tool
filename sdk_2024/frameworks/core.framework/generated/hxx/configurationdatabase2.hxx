
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* Configuration::PrivateGetCppName() { return nullptr; }

struct Configuration::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(Configuration_QueryBool, QueryBool, MAXON_EXPAND_VA_ARGS, (Result<void>), const String& key, Bool& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state);
	PRIVATE_MAXON_SF_POINTER(Configuration_QueryInt, QueryInt, MAXON_EXPAND_VA_ARGS, (Result<void>), const String& key, Int& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state);
	PRIVATE_MAXON_SF_POINTER(Configuration_QueryFloat, QueryFloat, MAXON_EXPAND_VA_ARGS, (Result<void>), const String& key, Float& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state);
	PRIVATE_MAXON_SF_POINTER(Configuration_QueryString, QueryString, MAXON_EXPAND_VA_ARGS, (Result<void>), const String& key, String& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state);
	PRIVATE_MAXON_SF_POINTER(Configuration_AddHelpForBool, AddHelpForBool, MAXON_EXPAND_VA_ARGS, (Result<void>), const String& key, Bool defaultValue, CONFIGURATION_CATEGORY category, const Char* help);
	PRIVATE_MAXON_SF_POINTER(Configuration_AddHelpForInt, AddHelpForInt, MAXON_EXPAND_VA_ARGS, (Result<void>), const String& key, Int defaultValue, Int minValue, Int maxValue, CONFIGURATION_CATEGORY category, const Char* help);
	PRIVATE_MAXON_SF_POINTER(Configuration_AddHelpForFloat, AddHelpForFloat, MAXON_EXPAND_VA_ARGS, (Result<void>), const String& key, Float defaultValue, Float minValue, Float maxValue, CONFIGURATION_CATEGORY category, const Char* help);
	PRIVATE_MAXON_SF_POINTER(Configuration_AddHelpForString, AddHelpForString, MAXON_EXPAND_VA_ARGS, (Result<void>), const String& key, const String& defaultValue, CONFIGURATION_CATEGORY category, const Char* help);
	PRIVATE_MAXON_SF_POINTER(Configuration_AddHelpForOption, AddHelpForOption, MAXON_EXPAND_VA_ARGS, (Result<void>), const String& key, const String& option, Bool isDefaultValue, Bool caseSensitive, CONFIGURATION_CATEGORY category, const Char* help);
	PRIVATE_MAXON_SF_POINTER(Configuration_BroadcastBool, BroadcastBool, MAXON_EXPAND_VA_ARGS, (Result<void>), const String& key, Bool value);
	PRIVATE_MAXON_SF_POINTER(Configuration_BroadcastInt, BroadcastInt, MAXON_EXPAND_VA_ARGS, (Result<void>), const String& key, Int value);
	PRIVATE_MAXON_SF_POINTER(Configuration_BroadcastFloat, BroadcastFloat, MAXON_EXPAND_VA_ARGS, (Result<void>), const String& key, Float value);
	PRIVATE_MAXON_SF_POINTER(Configuration_BroadcastString, BroadcastString, MAXON_EXPAND_VA_ARGS, (Result<void>), const String& key, const String& value);
	template <typename IMPL> void Init()
	{
		Configuration_QueryBool = Configuration_QueryBool_GetPtr<IMPL>(true);
		Configuration_QueryInt = Configuration_QueryInt_GetPtr<IMPL>(true);
		Configuration_QueryFloat = Configuration_QueryFloat_GetPtr<IMPL>(true);
		Configuration_QueryString = Configuration_QueryString_GetPtr<IMPL>(true);
		Configuration_AddHelpForBool = Configuration_AddHelpForBool_GetPtr<IMPL>(true);
		Configuration_AddHelpForInt = Configuration_AddHelpForInt_GetPtr<IMPL>(true);
		Configuration_AddHelpForFloat = Configuration_AddHelpForFloat_GetPtr<IMPL>(true);
		Configuration_AddHelpForString = Configuration_AddHelpForString_GetPtr<IMPL>(true);
		Configuration_AddHelpForOption = Configuration_AddHelpForOption_GetPtr<IMPL>(true);
		Configuration_BroadcastBool = Configuration_BroadcastBool_GetPtr<IMPL>(true);
		Configuration_BroadcastInt = Configuration_BroadcastInt_GetPtr<IMPL>(true);
		Configuration_BroadcastFloat = Configuration_BroadcastFloat_GetPtr<IMPL>(true);
		Configuration_BroadcastString = Configuration_BroadcastString_GetPtr<IMPL>(true);
	}
};

struct Configuration::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static Result<void> Configuration_QueryBool(const String& key, Bool& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) { return S::QueryBool(key, result, origin, state); }
		static Result<void> Configuration_QueryInt(const String& key, Int& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) { return S::QueryInt(key, result, origin, state); }
		static Result<void> Configuration_QueryFloat(const String& key, Float& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) { return S::QueryFloat(key, result, origin, state); }
		static Result<void> Configuration_QueryString(const String& key, String& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) { return S::QueryString(key, result, origin, state); }
		static Result<void> Configuration_AddHelpForBool(const String& key, Bool defaultValue, CONFIGURATION_CATEGORY category, const Char* help) { return S::AddHelpForBool(key, defaultValue, category, help); }
		static Result<void> Configuration_AddHelpForInt(const String& key, Int defaultValue, Int minValue, Int maxValue, CONFIGURATION_CATEGORY category, const Char* help) { return S::AddHelpForInt(key, defaultValue, minValue, maxValue, category, help); }
		static Result<void> Configuration_AddHelpForFloat(const String& key, Float defaultValue, Float minValue, Float maxValue, CONFIGURATION_CATEGORY category, const Char* help) { return S::AddHelpForFloat(key, defaultValue, minValue, maxValue, category, help); }
		static Result<void> Configuration_AddHelpForString(const String& key, const String& defaultValue, CONFIGURATION_CATEGORY category, const Char* help) { return S::AddHelpForString(key, defaultValue, category, help); }
		static Result<void> Configuration_AddHelpForOption(const String& key, const String& option, Bool isDefaultValue, Bool caseSensitive, CONFIGURATION_CATEGORY category, const Char* help) { return S::AddHelpForOption(key, option, isDefaultValue, caseSensitive, category, help); }
		static Result<void> Configuration_BroadcastBool(const String& key, Bool value) { return S::BroadcastBool(key, value); }
		static Result<void> Configuration_BroadcastInt(const String& key, Int value) { return S::BroadcastInt(key, value); }
		static Result<void> Configuration_BroadcastFloat(const String& key, Float value) { return S::BroadcastFloat(key, value); }
		static Result<void> Configuration_BroadcastString(const String& key, const String& value) { return S::BroadcastString(key, value); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Configuration::QueryBool(const String& key, Bool& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) -> Result<void>
{
	return MTable::_instance.Configuration_QueryBool(key, result, origin, state);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Configuration::QueryInt(const String& key, Int& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) -> Result<void>
{
	return MTable::_instance.Configuration_QueryInt(key, result, origin, state);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Configuration::QueryFloat(const String& key, Float& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) -> Result<void>
{
	return MTable::_instance.Configuration_QueryFloat(key, result, origin, state);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Configuration::QueryString(const String& key, String& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) -> Result<void>
{
	return MTable::_instance.Configuration_QueryString(key, result, origin, state);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Configuration::AddHelpForBool(const String& key, Bool defaultValue, CONFIGURATION_CATEGORY category, const Char* help) -> Result<void>
{
	return MTable::_instance.Configuration_AddHelpForBool(key, defaultValue, category, help);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Configuration::AddHelpForInt(const String& key, Int defaultValue, Int minValue, Int maxValue, CONFIGURATION_CATEGORY category, const Char* help) -> Result<void>
{
	return MTable::_instance.Configuration_AddHelpForInt(key, defaultValue, minValue, maxValue, category, help);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Configuration::AddHelpForFloat(const String& key, Float defaultValue, Float minValue, Float maxValue, CONFIGURATION_CATEGORY category, const Char* help) -> Result<void>
{
	return MTable::_instance.Configuration_AddHelpForFloat(key, defaultValue, minValue, maxValue, category, help);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Configuration::AddHelpForString(const String& key, const String& defaultValue, CONFIGURATION_CATEGORY category, const Char* help) -> Result<void>
{
	return MTable::_instance.Configuration_AddHelpForString(key, defaultValue, category, help);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Configuration::AddHelpForOption(const String& key, const String& option, Bool isDefaultValue, Bool caseSensitive, CONFIGURATION_CATEGORY category, const Char* help) -> Result<void>
{
	return MTable::_instance.Configuration_AddHelpForOption(key, option, isDefaultValue, caseSensitive, category, help);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Configuration::BroadcastBool(const String& key, Bool value) -> Result<void>
{
	return MTable::_instance.Configuration_BroadcastBool(key, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Configuration::BroadcastInt(const String& key, Int value) -> Result<void>
{
	return MTable::_instance.Configuration_BroadcastInt(key, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Configuration::BroadcastFloat(const String& key, Float value) -> Result<void>
{
	return MTable::_instance.Configuration_BroadcastFloat(key, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Configuration::BroadcastString(const String& key, const String& value) -> Result<void>
{
	return MTable::_instance.Configuration_BroadcastString(key, value);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_configurationdatabase)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_Configuration); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_Configuration() { new (s_ui_maxon_Configuration) maxon::EntityUse(Configuration::_interface.GetReference(), &maxon::g_translationUnit, "maxon/configurationdatabase.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_Configuration(Configuration::_interface.GetReference(), &maxon::g_translationUnit, "maxon/configurationdatabase.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

