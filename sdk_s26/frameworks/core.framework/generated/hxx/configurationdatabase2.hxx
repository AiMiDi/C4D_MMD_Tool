
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
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<void> (*Configuration_QueryBool) (const String& key, Bool& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state);
	Result<void> (*Configuration_QueryInt) (const String& key, Int& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state);
	Result<void> (*Configuration_QueryFloat) (const String& key, Float& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state);
	Result<void> (*Configuration_QueryString) (const String& key, String& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state);
	Result<void> (*Configuration_AddHelpForBool) (const String& key, Bool defaultValue, CONFIGURATION_CATEGORY category, const Char* help);
	Result<void> (*Configuration_AddHelpForInt) (const String& key, Int defaultValue, Int minValue, Int maxValue, CONFIGURATION_CATEGORY category, const Char* help);
	Result<void> (*Configuration_AddHelpForFloat) (const String& key, Float defaultValue, Float minValue, Float maxValue, CONFIGURATION_CATEGORY category, const Char* help);
	Result<void> (*Configuration_AddHelpForString) (const String& key, const String& defaultValue, CONFIGURATION_CATEGORY category, const Char* help);
	Result<void> (*Configuration_AddHelpForOption) (const String& key, const String& option, Bool isDefaultValue, Bool caseSensitive, CONFIGURATION_CATEGORY category, const Char* help);
	Result<void> (*Configuration_BroadcastBool) (const String& key, Bool value);
	Result<void> (*Configuration_BroadcastInt) (const String& key, Int value);
	Result<void> (*Configuration_BroadcastFloat) (const String& key, Float value);
	Result<void> (*Configuration_BroadcastString) (const String& key, const String& value);
	template <typename IMPL> void Init()
	{
		Configuration_QueryBool = &IMPL::Configuration_QueryBool;
		Configuration_QueryInt = &IMPL::Configuration_QueryInt;
		Configuration_QueryFloat = &IMPL::Configuration_QueryFloat;
		Configuration_QueryString = &IMPL::Configuration_QueryString;
		Configuration_AddHelpForBool = &IMPL::Configuration_AddHelpForBool;
		Configuration_AddHelpForInt = &IMPL::Configuration_AddHelpForInt;
		Configuration_AddHelpForFloat = &IMPL::Configuration_AddHelpForFloat;
		Configuration_AddHelpForString = &IMPL::Configuration_AddHelpForString;
		Configuration_AddHelpForOption = &IMPL::Configuration_AddHelpForOption;
		Configuration_BroadcastBool = &IMPL::Configuration_BroadcastBool;
		Configuration_BroadcastInt = &IMPL::Configuration_BroadcastInt;
		Configuration_BroadcastFloat = &IMPL::Configuration_BroadcastFloat;
		Configuration_BroadcastString = &IMPL::Configuration_BroadcastString;
	}
};

struct Configuration::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static Result<void> Configuration_QueryBool(const String& key, Bool& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) { return C::QueryBool(key, result, origin, state); }
		static Result<void> Configuration_QueryInt(const String& key, Int& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) { return C::QueryInt(key, result, origin, state); }
		static Result<void> Configuration_QueryFloat(const String& key, Float& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) { return C::QueryFloat(key, result, origin, state); }
		static Result<void> Configuration_QueryString(const String& key, String& result, CONFIGURATIONENTRY_ORIGIN& origin, CONFIGURATIONENTRY_STATE& state) { return C::QueryString(key, result, origin, state); }
		static Result<void> Configuration_AddHelpForBool(const String& key, Bool defaultValue, CONFIGURATION_CATEGORY category, const Char* help) { return C::AddHelpForBool(key, defaultValue, category, help); }
		static Result<void> Configuration_AddHelpForInt(const String& key, Int defaultValue, Int minValue, Int maxValue, CONFIGURATION_CATEGORY category, const Char* help) { return C::AddHelpForInt(key, defaultValue, minValue, maxValue, category, help); }
		static Result<void> Configuration_AddHelpForFloat(const String& key, Float defaultValue, Float minValue, Float maxValue, CONFIGURATION_CATEGORY category, const Char* help) { return C::AddHelpForFloat(key, defaultValue, minValue, maxValue, category, help); }
		static Result<void> Configuration_AddHelpForString(const String& key, const String& defaultValue, CONFIGURATION_CATEGORY category, const Char* help) { return C::AddHelpForString(key, defaultValue, category, help); }
		static Result<void> Configuration_AddHelpForOption(const String& key, const String& option, Bool isDefaultValue, Bool caseSensitive, CONFIGURATION_CATEGORY category, const Char* help) { return C::AddHelpForOption(key, option, isDefaultValue, caseSensitive, category, help); }
		static Result<void> Configuration_BroadcastBool(const String& key, Bool value) { return C::BroadcastBool(key, value); }
		static Result<void> Configuration_BroadcastInt(const String& key, Int value) { return C::BroadcastInt(key, value); }
		static Result<void> Configuration_BroadcastFloat(const String& key, Float value) { return C::BroadcastFloat(key, value); }
		static Result<void> Configuration_BroadcastString(const String& key, const String& value) { return C::BroadcastString(key, value); }
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

