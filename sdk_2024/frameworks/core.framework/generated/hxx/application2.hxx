
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
namespace APPMESSAGE
{
	namespace OPENFILES
	{
	}
	namespace OPENURLS
	{
	}
}
constexpr const maxon::Char* Application::PrivateGetCppName() { return nullptr; }
#ifdef MAXON_TARGET_WINDOWS
#endif

struct Application::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(Application_GetTempUrl, GetTempUrl, MAXON_EXPAND_VA_ARGS, (Result<Url>), const Url& directory);
	PRIVATE_MAXON_SF_POINTER(Application_GetModulePaths, GetModulePaths, MAXON_EXPAND_VA_ARGS, (Result<BaseArray<Url>>));
	PRIVATE_MAXON_SF_POINTER(Application_GetCommandLineArgCount, GetCommandLineArgCount, MAXON_EXPAND_VA_ARGS, (Int));
	PRIVATE_MAXON_SF_POINTER(Application_GetCommandLineArg, GetCommandLineArg, MAXON_EXPAND_VA_ARGS, (String), Int idx);
	PRIVATE_MAXON_SF_POINTER(Application_GetMachineInfo, GetMachineInfo, MAXON_EXPAND_VA_ARGS, (DataDictionary));
	PRIVATE_MAXON_SF_POINTER(Application_GetApplicationMode, GetApplicationMode, MAXON_EXPAND_VA_ARGS, (APPLICATIONMODE));
	PRIVATE_MAXON_SF_POINTER(Application_SetApplicationMode, SetApplicationMode, MAXON_EXPAND_VA_ARGS, (Bool), APPLICATIONMODE mode);
	PRIVATE_MAXON_SF_POINTER(Application_GetFeature, GetFeature, MAXON_EXPAND_VA_ARGS, (Bool), APPLICATIONFEATURE feature);
	PRIVATE_MAXON_SF_POINTER(Application_SetFeature, SetFeature, MAXON_EXPAND_VA_ARGS, (void), APPLICATIONFEATURE feature, Bool value);
	PRIVATE_MAXON_SF_POINTER(Application_GetVersion, GetVersion, MAXON_EXPAND_VA_ARGS, (Result<void>), Int& version, String& buildID);
	PRIVATE_MAXON_SF_POINTER(Application_FormatVersionString, FormatVersionString, MAXON_EXPAND_VA_ARGS, (String), Int rawVersionNumber);
#ifdef MAXON_TARGET_WINDOWS
	PRIVATE_MAXON_SF_POINTER(Application_GetWindowsSubsystem, GetWindowsSubsystem, MAXON_EXPAND_VA_ARGS, (SUBSYSTEM));
#endif
	PRIVATE_MAXON_SF_POINTER(Application_ObservableApplicationMessage, ObservableApplicationMessage, MAXON_EXPAND_VA_ARGS, (maxon::ObservableRef<ObservableApplicationMessageDelegate>), Bool create);
	PRIVATE_MAXON_SF_POINTER(Application_RegisterSystemUrlSchemeHandler, RegisterSystemUrlSchemeHandler, MAXON_EXPAND_VA_ARGS, (Result<void>), const Id& urlScheme, Bool reassignApplication, Delegate<void(const Url&)>&& callback);
	PRIVATE_MAXON_SF_POINTER(Application_CheckSystemUrlSchemeHandlerIsCurrent, CheckSystemUrlSchemeHandlerIsCurrent, MAXON_EXPAND_VA_ARGS, (Bool), const Id& urlScheme);
	PRIVATE_MAXON_SF_POINTER(Application_PrivateGetUrl, PrivateGetUrl, MAXON_EXPAND_VA_ARGS, (Result<Url>), APPLICATION_URLTYPE urlType, const Char* maxonModuleID, const Binary& currentModule);
	template <typename IMPL> void Init()
	{
		Application_GetTempUrl = Application_GetTempUrl_GetPtr<IMPL>(true);
		Application_GetModulePaths = Application_GetModulePaths_GetPtr<IMPL>(true);
		Application_GetCommandLineArgCount = Application_GetCommandLineArgCount_GetPtr<IMPL>(true);
		Application_GetCommandLineArg = Application_GetCommandLineArg_GetPtr<IMPL>(true);
		Application_GetMachineInfo = Application_GetMachineInfo_GetPtr<IMPL>(true);
		Application_GetApplicationMode = Application_GetApplicationMode_GetPtr<IMPL>(true);
		Application_SetApplicationMode = Application_SetApplicationMode_GetPtr<IMPL>(true);
		Application_GetFeature = Application_GetFeature_GetPtr<IMPL>(true);
		Application_SetFeature = Application_SetFeature_GetPtr<IMPL>(true);
		Application_GetVersion = Application_GetVersion_GetPtr<IMPL>(true);
		Application_FormatVersionString = Application_FormatVersionString_GetPtr<IMPL>(true);
#ifdef MAXON_TARGET_WINDOWS
		Application_GetWindowsSubsystem = Application_GetWindowsSubsystem_GetPtr<IMPL>(true);
#endif
		Application_ObservableApplicationMessage = Application_ObservableApplicationMessage_GetPtr<IMPL>(true);
		Application_RegisterSystemUrlSchemeHandler = Application_RegisterSystemUrlSchemeHandler_GetPtr<IMPL>(true);
		Application_CheckSystemUrlSchemeHandlerIsCurrent = Application_CheckSystemUrlSchemeHandlerIsCurrent_GetPtr<IMPL>(true);
		Application_PrivateGetUrl = Application_PrivateGetUrl_GetPtr<IMPL>(true);
	}
};

struct Application::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static Result<Url> Application_GetTempUrl(const Url& directory) { return S::GetTempUrl(directory); }
		static Result<BaseArray<Url>> Application_GetModulePaths() { return S::GetModulePaths(); }
		static Int Application_GetCommandLineArgCount() { return S::GetCommandLineArgCount(); }
		static String Application_GetCommandLineArg(Int idx) { return S::GetCommandLineArg(idx); }
		static DataDictionary Application_GetMachineInfo() { return S::GetMachineInfo(); }
		static APPLICATIONMODE Application_GetApplicationMode() { return S::GetApplicationMode(); }
		static Bool Application_SetApplicationMode(APPLICATIONMODE mode) { return S::SetApplicationMode(mode); }
		static Bool Application_GetFeature(APPLICATIONFEATURE feature) { return S::GetFeature(feature); }
		static void Application_SetFeature(APPLICATIONFEATURE feature, Bool value) { return S::SetFeature(feature, value); }
		static Result<void> Application_GetVersion(Int& version, String& buildID) { return S::GetVersion(version, buildID); }
		static String Application_FormatVersionString(Int rawVersionNumber) { return S::FormatVersionString(rawVersionNumber); }
#ifdef MAXON_TARGET_WINDOWS
		static SUBSYSTEM Application_GetWindowsSubsystem() { return S::GetWindowsSubsystem(); }
#endif
		static maxon::ObservableRef<ObservableApplicationMessageDelegate> Application_ObservableApplicationMessage(Bool create) { return S::ObservableApplicationMessage(create); }
		static Result<void> Application_RegisterSystemUrlSchemeHandler(const Id& urlScheme, Bool reassignApplication, Delegate<void(const Url&)>&& callback) { return S::RegisterSystemUrlSchemeHandler(urlScheme, reassignApplication, std::forward<Delegate<void(const Url&)>>(callback)); }
		static Bool Application_CheckSystemUrlSchemeHandlerIsCurrent(const Id& urlScheme) { return S::CheckSystemUrlSchemeHandlerIsCurrent(urlScheme); }
		static Result<Url> Application_PrivateGetUrl(APPLICATION_URLTYPE urlType, const Char* maxonModuleID, const Binary& currentModule) { return S::PrivateGetUrl(urlType, maxonModuleID, currentModule); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetTempUrl(const Url& directory) -> Result<Url>
{
	return MTable::_instance.Application_GetTempUrl(directory);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetModulePaths() -> Result<BaseArray<Url>>
{
	return MTable::_instance.Application_GetModulePaths();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetCommandLineArgCount() -> Int
{
	return MTable::_instance.Application_GetCommandLineArgCount();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetCommandLineArg(Int idx) -> String
{
	return MTable::_instance.Application_GetCommandLineArg(idx);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetMachineInfo() -> DataDictionary
{
	return MTable::_instance.Application_GetMachineInfo();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetApplicationMode() -> APPLICATIONMODE
{
	return MTable::_instance.Application_GetApplicationMode();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::SetApplicationMode(APPLICATIONMODE mode) -> Bool
{
	return MTable::_instance.Application_SetApplicationMode(mode);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetFeature(APPLICATIONFEATURE feature) -> Bool
{
	return MTable::_instance.Application_GetFeature(feature);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::SetFeature(APPLICATIONFEATURE feature, Bool value) -> void
{
	return MTable::_instance.Application_SetFeature(feature, value);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetVersion(Int& version, String& buildID) -> Result<void>
{
	return MTable::_instance.Application_GetVersion(version, buildID);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::FormatVersionString(Int rawVersionNumber) -> String
{
	return MTable::_instance.Application_FormatVersionString(rawVersionNumber);
}
#ifdef MAXON_TARGET_WINDOWS
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetWindowsSubsystem() -> SUBSYSTEM
{
	return MTable::_instance.Application_GetWindowsSubsystem();
}
#endif
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::ObservableApplicationMessage(Bool create) -> maxon::ObservableRef<ObservableApplicationMessageDelegate>
{
	return MTable::_instance.Application_ObservableApplicationMessage(create);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::RegisterSystemUrlSchemeHandler(const Id& urlScheme, Bool reassignApplication, Delegate<void(const Url&)>&& callback) -> Result<void>
{
	return MTable::_instance.Application_RegisterSystemUrlSchemeHandler(urlScheme, reassignApplication, std::forward<Delegate<void(const Url&)>>(callback));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::CheckSystemUrlSchemeHandlerIsCurrent(const Id& urlScheme) -> Bool
{
	return MTable::_instance.Application_CheckSystemUrlSchemeHandlerIsCurrent(urlScheme);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::PrivateGetUrl(APPLICATION_URLTYPE urlType, const Char* maxonModuleID, const Binary& currentModule) -> Result<Url>
{
	return MTable::_instance.Application_PrivateGetUrl(urlType, maxonModuleID, currentModule);
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_application)
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

