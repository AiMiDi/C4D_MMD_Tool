
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
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Result<Url> (*Application_GetTempUrl) (const Url& directory);
	Result<BaseArray<Url>> (*Application_GetModulePaths) ();
	Int (*Application_GetCommandLineArgCount) ();
	String (*Application_GetCommandLineArg) (Int idx);
	DataDictionary (*Application_GetMachineInfo) ();
	APPLICATIONMODE (*Application_GetApplicationMode) ();
	Bool (*Application_SetApplicationMode) (APPLICATIONMODE mode);
	Bool (*Application_GetFeature) (APPLICATIONFEATURE feature);
	void (*Application_SetFeature) (APPLICATIONFEATURE feature, Bool value);
	Result<void> (*Application_GetVersion) (Int& version, String& buildID);
#ifdef MAXON_TARGET_WINDOWS
	SUBSYSTEM (*Application_GetWindowsSubsystem) ();
#endif
	maxon::ObservableRef<ObservableApplicationMessageDelegate> (*Application_ObservableApplicationMessage) ();
	Result<Url> (*Application_GetUrlI) (APPLICATION_URLTYPE urlType);
	template <typename IMPL> void Init()
	{
		Application_GetTempUrl = &IMPL::Application_GetTempUrl;
		Application_GetModulePaths = &IMPL::Application_GetModulePaths;
		Application_GetCommandLineArgCount = &IMPL::Application_GetCommandLineArgCount;
		Application_GetCommandLineArg = &IMPL::Application_GetCommandLineArg;
		Application_GetMachineInfo = &IMPL::Application_GetMachineInfo;
		Application_GetApplicationMode = &IMPL::Application_GetApplicationMode;
		Application_SetApplicationMode = &IMPL::Application_SetApplicationMode;
		Application_GetFeature = &IMPL::Application_GetFeature;
		Application_SetFeature = &IMPL::Application_SetFeature;
		Application_GetVersion = &IMPL::Application_GetVersion;
#ifdef MAXON_TARGET_WINDOWS
		Application_GetWindowsSubsystem = &IMPL::Application_GetWindowsSubsystem;
#endif
		Application_ObservableApplicationMessage = &IMPL::Application_ObservableApplicationMessage;
		Application_GetUrlI = &IMPL::Application_GetUrlI;
	}
};

struct Application::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static Result<Url> Application_GetTempUrl(const Url& directory) { return C::GetTempUrl(directory); }
		static Result<BaseArray<Url>> Application_GetModulePaths() { return C::GetModulePaths(); }
		static Int Application_GetCommandLineArgCount() { return C::GetCommandLineArgCount(); }
		static String Application_GetCommandLineArg(Int idx) { return C::GetCommandLineArg(idx); }
		static DataDictionary Application_GetMachineInfo() { return C::GetMachineInfo(); }
		static APPLICATIONMODE Application_GetApplicationMode() { return C::GetApplicationMode(); }
		static Bool Application_SetApplicationMode(APPLICATIONMODE mode) { return C::SetApplicationMode(mode); }
		static Bool Application_GetFeature(APPLICATIONFEATURE feature) { return C::GetFeature(feature); }
		static void Application_SetFeature(APPLICATIONFEATURE feature, Bool value) { return C::SetFeature(feature, value); }
		static Result<void> Application_GetVersion(Int& version, String& buildID) { return C::GetVersion(version, buildID); }
#ifdef MAXON_TARGET_WINDOWS
		static SUBSYSTEM Application_GetWindowsSubsystem() { return C::GetWindowsSubsystem(); }
#endif
		static maxon::ObservableRef<ObservableApplicationMessageDelegate> Application_ObservableApplicationMessage() { return C::ObservableApplicationMessage(); }
		static Result<Url> Application_GetUrlI(APPLICATION_URLTYPE urlType) { return C::GetUrlI(urlType); }
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
#ifdef MAXON_TARGET_WINDOWS
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetWindowsSubsystem() -> SUBSYSTEM
{
	return MTable::_instance.Application_GetWindowsSubsystem();
}
#endif
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::ObservableApplicationMessage() -> maxon::ObservableRef<ObservableApplicationMessageDelegate>
{
	return MTable::_instance.Application_ObservableApplicationMessage();
}
MAXON_ATTRIBUTE_FORCE_INLINE auto Application::GetUrlI(APPLICATION_URLTYPE urlType) -> Result<Url>
{
	return MTable::_instance.Application_GetUrlI(urlType);
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

