#if 1
namespace maxon
{
	namespace enum22 { enum class SUBSYSTEM
	{
		UNDEFINED = 0,///< Undefined SUBSYSTEM
		CONSOLE = 1,	///< (/SUBSYSTEM:CONSOLE)
		WINDOWS = 2		///< (/SUBSYSTEM:WINDOWS)
	} ; }
	maxon::String PrivateToString_SUBSYSTEM22(std::underlying_type<enum22::SUBSYSTEM>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum22::SUBSYSTEM::UNDEFINED, (maxon::UInt64) enum22::SUBSYSTEM::CONSOLE, (maxon::UInt64) enum22::SUBSYSTEM::WINDOWS};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SUBSYSTEM", SIZEOF(x), false, values, "UNDEFINED\0CONSOLE\0WINDOWS\0", fmt);
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_SUBSYSTEM, , "net.maxon.datatype.enum.subsystem");
	namespace enum103 { enum class APPLICATION_URLTYPE
	{
		//----------------------------------------------------------------------------------------
		/// The directory where the executable/bundle is placed in.
		/// The executable name is not part of the Url.
		//----------------------------------------------------------------------------------------
		STARTUP_DIR,
	
		//----------------------------------------------------------------------------------------
		/// The Url of the executable (Windows / Linux) or bundle (OS X / iOS).
		//----------------------------------------------------------------------------------------
		APPLICATION,
	
		//----------------------------------------------------------------------------------------
		/// The Url of the inner executable.
		/// Under Windows / Linux this is identical to APPLICATION.
		/// Under OS X / iOS this is the Url inside the bundle.
		//----------------------------------------------------------------------------------------
		APP_EXECUTABLE,
	
		//----------------------------------------------------------------------------------------
		/// The directory where the core modules are placed in.
		//----------------------------------------------------------------------------------------
		CORELIBS_DIR,
	
		//----------------------------------------------------------------------------------------
		/// The directory where the resource is placed in.
		//----------------------------------------------------------------------------------------
		RESOURCE_DIR,
	
		//----------------------------------------------------------------------------------------
		/// Temporary directory where data can be read or written.
		/// The temporary directory is placed in various locations depending on the operating system.
		//----------------------------------------------------------------------------------------
		TEMP_DIR,
	
		//----------------------------------------------------------------------------------------
		/// Preferences directory.
		/// The preferences directory is based on the startup Url of the application. If the parent
		/// directory location is changed, the preferences Url will change as well.
		/// The preferences directory is placed in various locations depending on the operating system.
		//----------------------------------------------------------------------------------------
		PREFS_DIR,
	
		//----------------------------------------------------------------------------------------
		/// Global preferences directory.
		/// The global preferences Url is always in the same place for all applications on the
		/// same operating system.
		//----------------------------------------------------------------------------------------
		GLOBALPREFS_DIR,
	
		//----------------------------------------------------------------------------------------
		/// Users desktop directory.
		//----------------------------------------------------------------------------------------
		DESKTOP_DIR,
	
		//----------------------------------------------------------------------------------------
		/// Users Home directory.
		//----------------------------------------------------------------------------------------
		USER_HOME_DIR,
	
		//----------------------------------------------------------------------------------------
		/// Users documents directory.
		//----------------------------------------------------------------------------------------
		USER_DOCUMENTS_DIR,
	
		//----------------------------------------------------------------------------------------
		/// System application directory. This is where apps are installed by default (e.g. "C:\Program Files")
		//----------------------------------------------------------------------------------------
		SYSTEM_PROGRAMS_DIR,
	
		//----------------------------------------------------------------------------------------
		/// Current working directory.
		//----------------------------------------------------------------------------------------
		CURRENT_WORKING_DIR
	
	} ; }
	maxon::String PrivateToString_APPLICATION_URLTYPE103(std::underlying_type<enum103::APPLICATION_URLTYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum103::APPLICATION_URLTYPE::STARTUP_DIR, (maxon::UInt64) enum103::APPLICATION_URLTYPE::APPLICATION, (maxon::UInt64) enum103::APPLICATION_URLTYPE::APP_EXECUTABLE, (maxon::UInt64) enum103::APPLICATION_URLTYPE::CORELIBS_DIR, (maxon::UInt64) enum103::APPLICATION_URLTYPE::RESOURCE_DIR, (maxon::UInt64) enum103::APPLICATION_URLTYPE::TEMP_DIR, (maxon::UInt64) enum103::APPLICATION_URLTYPE::PREFS_DIR, (maxon::UInt64) enum103::APPLICATION_URLTYPE::GLOBALPREFS_DIR, (maxon::UInt64) enum103::APPLICATION_URLTYPE::DESKTOP_DIR, (maxon::UInt64) enum103::APPLICATION_URLTYPE::USER_HOME_DIR, (maxon::UInt64) enum103::APPLICATION_URLTYPE::USER_DOCUMENTS_DIR, (maxon::UInt64) enum103::APPLICATION_URLTYPE::SYSTEM_PROGRAMS_DIR, (maxon::UInt64) enum103::APPLICATION_URLTYPE::CURRENT_WORKING_DIR};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "APPLICATION_URLTYPE", SIZEOF(x), false, values, "STARTUP_DIR\0APPLICATION\0APP_EXECUTABLE\0CORELIBS_DIR\0RESOURCE_DIR\0TEMP_DIR\0PREFS_DIR\0GLOBALPREFS_DIR\0DESKTOP_DIR\0USER_HOME_DIR\0USER_DOCUMENTS_DIR\0SYSTEM_PROGRAMS_DIR\0CURRENT_WORKING_DIR\0", fmt);
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_APPLICATION_URLTYPE, , "net.maxon.datatype.enum.application_urltype");
	namespace enum110 { enum class APPLICATIONTYPE
	{
		OTHER,			///< Stops the execution as soon as all initializations are done, used for command line mode.
		CPYTHON,		///< application is a python interpreter
		CPYTHON3,		///< application is a python 3 interpreter
	} ; }
	maxon::String PrivateToString_APPLICATIONTYPE110(std::underlying_type<enum110::APPLICATIONTYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum110::APPLICATIONTYPE::OTHER, (maxon::UInt64) enum110::APPLICATIONTYPE::CPYTHON, (maxon::UInt64) enum110::APPLICATIONTYPE::CPYTHON3};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "APPLICATIONTYPE", SIZEOF(x), false, values, "OTHER\0CPYTHON\0CPYTHON3\0", fmt);
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_APPLICATIONTYPE, , "net.maxon.datatype.enum.applicationtype");
	namespace enum119 { enum class APPLICATIONMODE
	{
		DONTWAIT,			///< Stops the execution as soon as all initializations are done, used for command line mode.
		KEEPRUNNING,	///< Keeps the program running after all initializations.
		SHUTDOWN,			///< Quits the application and leave the main loop. Only working when APPLICATIONMODE::KEEPRUNNING was set before.
	} ; }
	maxon::String PrivateToString_APPLICATIONMODE119(std::underlying_type<enum119::APPLICATIONMODE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum119::APPLICATIONMODE::DONTWAIT, (maxon::UInt64) enum119::APPLICATIONMODE::KEEPRUNNING, (maxon::UInt64) enum119::APPLICATIONMODE::SHUTDOWN};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "APPLICATIONMODE", SIZEOF(x), false, values, "DONTWAIT\0KEEPRUNNING\0SHUTDOWN\0", fmt);
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_APPLICATIONMODE, , "net.maxon.datatype.enum.applicationmode");
#ifdef MAXON_TARGET_WINDOWS
#endif
	const maxon::Char* const Application::MTable::_ids = 
		"GetUrl@8d58f90b3bda46de\0" // GetUrl(APPLICATION_URLTYPE urlType)
		"GetTempUrl@80ddfa2d31821f3a\0" // GetTempUrl(const Url& directory)
		"GetModulePaths@cd0d7cbf880d7a5c\0" // GetModulePaths()
		"GetCommandLineArgCount@4386c6f\0" // GetCommandLineArgCount()
		"GetCommandLineArg@fcf0b70602bb46\0" // GetCommandLineArg(Int idx)
		"GetMachineInfo@c916016dbfde0060\0" // GetMachineInfo()
		"GetApplicationMode@81054c8f142a4e73\0" // GetApplicationMode()
		"GetApplicationType@81054c8f20ae9a4a\0" // GetApplicationType()
		"SetApplicationMode@c2b201f9e16b0809\0" // SetApplicationMode(APPLICATIONMODE mode)
		"GetVersion@6842a155716d62eb\0" // GetVersion(Int& version, String& buildID)
#ifdef MAXON_TARGET_WINDOWS
		"GetWindowsSubsystem@f9e177409bbcef\0" // GetWindowsSubsystem()
#endif
	"";
	class Application::Unresolved : public Application
	{
	public:
		static const Unresolved* Get(const Application* o) { return (const Unresolved*) o; }
		static Unresolved* Get(Application* o) { return (Unresolved*) o; }
		static Result<Url> GetUrl(APPLICATION_URLTYPE urlType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Application::GetUrl(urlType); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Url> GetTempUrl(const Url& directory) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Application::GetTempUrl(directory); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<BaseArray<Url>> GetModulePaths() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Application::GetModulePaths(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Int GetCommandLineArgCount() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetCommandLineArgCount(); return 0;}
		static String GetCommandLineArg(Int idx) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetCommandLineArg(idx); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static DataDictionary GetMachineInfo() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetMachineInfo(); return maxon::PrivateIncompleteNullReturnValue<DataDictionary>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static APPLICATIONMODE GetApplicationMode() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetApplicationMode(); return maxon::PrivateIncompleteNullReturnValue<APPLICATIONMODE>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static APPLICATIONTYPE GetApplicationType() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetApplicationType(); return maxon::PrivateIncompleteNullReturnValue<APPLICATIONTYPE>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Bool SetApplicationMode(APPLICATIONMODE mode) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::SetApplicationMode(mode); return maxon::PrivateLogNullptrError(false);}
		static Result<void> GetVersion(Int& version, String& buildID) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Application::GetVersion(version, buildID); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
#ifdef MAXON_TARGET_WINDOWS
		static SUBSYSTEM GetWindowsSubsystem() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetWindowsSubsystem(); return maxon::PrivateIncompleteNullReturnValue<SUBSYSTEM>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
#endif
	};
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE Application::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<Url>>::value,
		maxon::details::NullReturnType<Result<Url>>::value,
		maxon::details::NullReturnType<Result<BaseArray<Url>>>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<DataDictionary>::value,
		maxon::details::NullReturnType<APPLICATIONMODE>::value,
		maxon::details::NullReturnType<APPLICATIONTYPE>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Result<void>>::value,
#ifdef MAXON_TARGET_WINDOWS
		maxon::details::NullReturnType<SUBSYSTEM>::value,
#endif
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool Application::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Url>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetUrl = &Wrapper<Unresolved>::_Application_GetUrl;
	#else
		tbl->_Application_GetUrl = &Wrapper<Unresolved>::_Application_GetUrl;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Url>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetTempUrl = &Wrapper<Unresolved>::_Application_GetTempUrl;
	#else
		tbl->_Application_GetTempUrl = &Wrapper<Unresolved>::_Application_GetTempUrl;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<Url>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetModulePaths = &Wrapper<Unresolved>::_Application_GetModulePaths;
	#else
		tbl->_Application_GetModulePaths = &Wrapper<Unresolved>::_Application_GetModulePaths;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_Application_GetCommandLineArgCount = &Wrapper<Unresolved>::_Application_GetCommandLineArgCount;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetCommandLineArg = &Wrapper<Unresolved>::_Application_GetCommandLineArg;
	#else
		tbl->_Application_GetCommandLineArg = &Wrapper<Unresolved>::_Application_GetCommandLineArg;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<DataDictionary>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetMachineInfo = &Wrapper<Unresolved>::_Application_GetMachineInfo;
	#else
		tbl->_Application_GetMachineInfo = &Wrapper<Unresolved>::_Application_GetMachineInfo;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<APPLICATIONMODE>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetApplicationMode = &Wrapper<Unresolved>::_Application_GetApplicationMode;
	#else
		tbl->_Application_GetApplicationMode = &Wrapper<Unresolved>::_Application_GetApplicationMode;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<APPLICATIONTYPE>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetApplicationType = &Wrapper<Unresolved>::_Application_GetApplicationType;
	#else
		tbl->_Application_GetApplicationType = &Wrapper<Unresolved>::_Application_GetApplicationType;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
	#else
		tbl->_Application_SetApplicationMode = &Wrapper<Unresolved>::_Application_SetApplicationMode;
	#endif
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetVersion = &Wrapper<Unresolved>::_Application_GetVersion;
	#else
		tbl->_Application_GetVersion = &Wrapper<Unresolved>::_Application_GetVersion;
	#endif
#ifdef MAXON_TARGET_WINDOWS
	#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<SUBSYSTEM>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetWindowsSubsystem = &Wrapper<Unresolved>::_Application_GetWindowsSubsystem;
	#else
		tbl->_Application_GetWindowsSubsystem = &Wrapper<Unresolved>::_Application_GetWindowsSubsystem;
	#endif
#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(_returnTypes) - 1);
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(Application, "net.maxon.interface.application", nullptr);
	template <typename DUMMY> maxon::Int Application::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<APPLICATIONMODE>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<APPLICATIONTYPE>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<DataDictionary>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<SUBSYSTEM>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_application(0
	| maxon::Application::PrivateInstantiateNullValueHelper<maxon::Int>()
);
