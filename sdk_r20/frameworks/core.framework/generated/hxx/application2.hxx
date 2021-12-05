
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
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
	Result<Url> (*_Application_GetUrl) (APPLICATION_URLTYPE urlType);
	Result<Url> (*_Application_GetTempUrl) (const Url& directory);
	Result<BaseArray<Url>> (*_Application_GetModulePaths) ();
	Int (*_Application_GetCommandLineArgCount) ();
	String (*_Application_GetCommandLineArg) (Int idx);
	DataDictionary (*_Application_GetMachineInfo) ();
	APPLICATIONMODE (*_Application_GetApplicationMode) ();
	APPLICATIONTYPE (*_Application_GetApplicationType) ();
	Bool (*_Application_SetApplicationMode) (APPLICATIONMODE mode);
	Result<void> (*_Application_GetVersion) (Int& version, String& buildID);
#ifdef MAXON_TARGET_WINDOWS
	SUBSYSTEM (*_Application_GetWindowsSubsystem) ();
#endif
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_Application_GetUrl = &IMPL::_Application_GetUrl;
		tbl->_Application_GetTempUrl = &IMPL::_Application_GetTempUrl;
		tbl->_Application_GetModulePaths = &IMPL::_Application_GetModulePaths;
		tbl->_Application_GetCommandLineArgCount = &IMPL::_Application_GetCommandLineArgCount;
		tbl->_Application_GetCommandLineArg = &IMPL::_Application_GetCommandLineArg;
		tbl->_Application_GetMachineInfo = &IMPL::_Application_GetMachineInfo;
		tbl->_Application_GetApplicationMode = &IMPL::_Application_GetApplicationMode;
		tbl->_Application_GetApplicationType = &IMPL::_Application_GetApplicationType;
		tbl->_Application_SetApplicationMode = &IMPL::_Application_SetApplicationMode;
		tbl->_Application_GetVersion = &IMPL::_Application_GetVersion;
#ifdef MAXON_TARGET_WINDOWS
		tbl->_Application_GetWindowsSubsystem = &IMPL::_Application_GetWindowsSubsystem;
#endif
	}
};

template <typename C> class Application::Wrapper
{
public:
	static Result<Url> _Application_GetUrl(APPLICATION_URLTYPE urlType) { return C::GetUrl(urlType); }
	static Result<Url> _Application_GetTempUrl(const Url& directory) { return C::GetTempUrl(directory); }
	static Result<BaseArray<Url>> _Application_GetModulePaths() { return C::GetModulePaths(); }
	static Int _Application_GetCommandLineArgCount() { return C::GetCommandLineArgCount(); }
	static String _Application_GetCommandLineArg(Int idx) { return C::GetCommandLineArg(idx); }
	static DataDictionary _Application_GetMachineInfo() { return C::GetMachineInfo(); }
	static APPLICATIONMODE _Application_GetApplicationMode() { return C::GetApplicationMode(); }
	static APPLICATIONTYPE _Application_GetApplicationType() { return C::GetApplicationType(); }
	static Bool _Application_SetApplicationMode(APPLICATIONMODE mode) { return C::SetApplicationMode(mode); }
	static Result<void> _Application_GetVersion(Int& version, String& buildID) { return C::GetVersion(version, buildID); }
#ifdef MAXON_TARGET_WINDOWS
	static SUBSYSTEM _Application_GetWindowsSubsystem() { return C::GetWindowsSubsystem(); }
#endif
};

MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetUrl(APPLICATION_URLTYPE urlType) -> Result<Url>
{
	return MTable::_instance._Application_GetUrl(urlType);
}
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
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetApplicationType() -> APPLICATIONTYPE
{
	return MTable::_instance._Application_GetApplicationType();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::SetApplicationMode(APPLICATIONMODE mode) -> Bool
{
	return MTable::_instance._Application_SetApplicationMode(mode);
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

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_Application(Application::_interface.GetReference(), &maxon::g_translationUnit, "maxon/application.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

