
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
#ifdef MAXON_TARGET_WINDOWS
#endif

struct Application::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<Url> (*_Application_GetTempUrl) (const Url& directory);
	Result<BaseArray<Url>> (*_Application_GetModulePaths) ();
	Int (*_Application_GetCommandLineArgCount) ();
	String (*_Application_GetCommandLineArg) (Int idx);
	DataDictionary (*_Application_GetMachineInfo) ();
	APPLICATIONMODE (*_Application_GetApplicationMode) ();
	Bool (*_Application_SetApplicationMode) (APPLICATIONMODE mode);
	Bool (*_Application_GetFeature) (APPLICATIONFEATURE feature);
	void (*_Application_SetFeature) (APPLICATIONFEATURE feature, Bool value);
	Result<void> (*_Application_GetVersion) (Int& version, String& buildID);
#ifdef MAXON_TARGET_WINDOWS
	SUBSYSTEM (*_Application_GetWindowsSubsystem) ();
#endif
	Result<Url> (*_Application_GetUrlI) (APPLICATION_URLTYPE urlType);
	template <typename IMPL> void Init()
	{
		_Application_GetTempUrl = &IMPL::_Application_GetTempUrl;
		_Application_GetModulePaths = &IMPL::_Application_GetModulePaths;
		_Application_GetCommandLineArgCount = &IMPL::_Application_GetCommandLineArgCount;
		_Application_GetCommandLineArg = &IMPL::_Application_GetCommandLineArg;
		_Application_GetMachineInfo = &IMPL::_Application_GetMachineInfo;
		_Application_GetApplicationMode = &IMPL::_Application_GetApplicationMode;
		_Application_SetApplicationMode = &IMPL::_Application_SetApplicationMode;
		_Application_GetFeature = &IMPL::_Application_GetFeature;
		_Application_SetFeature = &IMPL::_Application_SetFeature;
		_Application_GetVersion = &IMPL::_Application_GetVersion;
#ifdef MAXON_TARGET_WINDOWS
		_Application_GetWindowsSubsystem = &IMPL::_Application_GetWindowsSubsystem;
#endif
		_Application_GetUrlI = &IMPL::_Application_GetUrlI;
	}
};

struct Application::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
	static Result<Url> _Application_GetTempUrl(const Url& directory) { return C::GetTempUrl(directory); }
	static Result<BaseArray<Url>> _Application_GetModulePaths() { return C::GetModulePaths(); }
	static Int _Application_GetCommandLineArgCount() { return C::GetCommandLineArgCount(); }
	static String _Application_GetCommandLineArg(Int idx) { return C::GetCommandLineArg(idx); }
	static DataDictionary _Application_GetMachineInfo() { return C::GetMachineInfo(); }
	static APPLICATIONMODE _Application_GetApplicationMode() { return C::GetApplicationMode(); }
	static Bool _Application_SetApplicationMode(APPLICATIONMODE mode) { return C::SetApplicationMode(mode); }
	static Bool _Application_GetFeature(APPLICATIONFEATURE feature) { return C::GetFeature(feature); }
	static void _Application_SetFeature(APPLICATIONFEATURE feature, Bool value) { return C::SetFeature(feature, value); }
	static Result<void> _Application_GetVersion(Int& version, String& buildID) { return C::GetVersion(version, buildID); }
#ifdef MAXON_TARGET_WINDOWS
	static SUBSYSTEM _Application_GetWindowsSubsystem() { return C::GetWindowsSubsystem(); }
#endif
	static Result<Url> _Application_GetUrlI(APPLICATION_URLTYPE urlType) { return C::GetUrlI(urlType); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetTempUrl(const Url& directory) -> Result<Url>
{
	return MTable::_instance._Application_GetTempUrl(directory);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetModulePaths() -> Result<BaseArray<Url>>
{
	return MTable::_instance._Application_GetModulePaths();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetCommandLineArgCount() -> Int
{
	return MTable::_instance._Application_GetCommandLineArgCount();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetCommandLineArg(Int idx) -> String
{
	return MTable::_instance._Application_GetCommandLineArg(idx);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetMachineInfo() -> DataDictionary
{
	return MTable::_instance._Application_GetMachineInfo();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetApplicationMode() -> APPLICATIONMODE
{
	return MTable::_instance._Application_GetApplicationMode();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::SetApplicationMode(APPLICATIONMODE mode) -> Bool
{
	return MTable::_instance._Application_SetApplicationMode(mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetFeature(APPLICATIONFEATURE feature) -> Bool
{
	return MTable::_instance._Application_GetFeature(feature);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::SetFeature(APPLICATIONFEATURE feature, Bool value) -> void
{
	return MTable::_instance._Application_SetFeature(feature, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetVersion(Int& version, String& buildID) -> Result<void>
{
	return MTable::_instance._Application_GetVersion(version, buildID);
}
#ifdef MAXON_TARGET_WINDOWS
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetWindowsSubsystem() -> SUBSYSTEM
{
	return MTable::_instance._Application_GetWindowsSubsystem();
}
#endif
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetUrlI(APPLICATION_URLTYPE urlType) -> Result<Url>
{
	return MTable::_instance._Application_GetUrlI(urlType);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_Application); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_Application() { new (s_ui_maxon_Application) maxon::EntityUse(Application::_interface.GetReference(), &maxon::g_translationUnit, "maxon/application.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_Application(Application::_interface.GetReference(), &maxon::g_translationUnit, "maxon/application.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

