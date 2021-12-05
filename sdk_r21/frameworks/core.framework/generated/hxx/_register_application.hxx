#if 1
namespace maxon
{
	namespace enum23 { enum class SUBSYSTEM
	{
		UNDEFINED = 0,///< Undefined SUBSYSTEM
		CONSOLE = 1,	///< (\/%SUBSYSTEM:%CONSOLE)
		WINDOWS = 2		///< (\/%SUBSYSTEM:%WINDOWS)
	} ; }
	maxon::String PrivateToString_SUBSYSTEM23(std::underlying_type<enum23::SUBSYSTEM>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum23::SUBSYSTEM::UNDEFINED, (maxon::UInt64) enum23::SUBSYSTEM::CONSOLE, (maxon::UInt64) enum23::SUBSYSTEM::WINDOWS};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SUBSYSTEM", SIZEOF(x), false, values, "UNDEFINED\0CONSOLE\0WINDOWS\0", fmt);
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_SUBSYSTEM, , "net.maxon.datatype.enum.subsystem");
	namespace enum113 { enum class APPLICATION_URLTYPE
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
		CURRENT_WORKING_DIR,
	
		//----------------------------------------------------------------------------------------
		/// Directory of the module that invoked this call.
		//----------------------------------------------------------------------------------------
		CURRENT_MODULE_DIR,
	
		//----------------------------------------------------------------------------------------
		/// Resource directory of the module that invoked this call.
		//----------------------------------------------------------------------------------------
		CURRENT_MODULE_RESOURCE_DIR
	} ; }
	maxon::String PrivateToString_APPLICATION_URLTYPE113(std::underlying_type<enum113::APPLICATION_URLTYPE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum113::APPLICATION_URLTYPE::STARTUP_DIR, (maxon::UInt64) enum113::APPLICATION_URLTYPE::APPLICATION, (maxon::UInt64) enum113::APPLICATION_URLTYPE::APP_EXECUTABLE, (maxon::UInt64) enum113::APPLICATION_URLTYPE::CORELIBS_DIR, (maxon::UInt64) enum113::APPLICATION_URLTYPE::RESOURCE_DIR, (maxon::UInt64) enum113::APPLICATION_URLTYPE::TEMP_DIR, (maxon::UInt64) enum113::APPLICATION_URLTYPE::PREFS_DIR, (maxon::UInt64) enum113::APPLICATION_URLTYPE::GLOBALPREFS_DIR, (maxon::UInt64) enum113::APPLICATION_URLTYPE::DESKTOP_DIR, (maxon::UInt64) enum113::APPLICATION_URLTYPE::USER_HOME_DIR, (maxon::UInt64) enum113::APPLICATION_URLTYPE::USER_DOCUMENTS_DIR, (maxon::UInt64) enum113::APPLICATION_URLTYPE::SYSTEM_PROGRAMS_DIR, (maxon::UInt64) enum113::APPLICATION_URLTYPE::CURRENT_WORKING_DIR, (maxon::UInt64) enum113::APPLICATION_URLTYPE::CURRENT_MODULE_DIR, (maxon::UInt64) enum113::APPLICATION_URLTYPE::CURRENT_MODULE_RESOURCE_DIR};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "APPLICATION_URLTYPE", SIZEOF(x), false, values, "STARTUP_DIR\0APPLICATION\0APP_EXECUTABLE\0CORELIBS_DIR\0RESOURCE_DIR\0TEMP_DIR\0PREFS_DIR\0GLOBALPREFS_DIR\0DESKTOP_DIR\0USER_HOME_DIR\0USER_DOCUMENTS_DIR\0SYSTEM_PROGRAMS_DIR\0CURRENT_WORKING_DIR\0CURRENT_MODULE_DIR\0CURRENT_MODULE_RESOURCE_DIR\0", fmt);
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_APPLICATION_URLTYPE, , "net.maxon.datatype.enum.application_urltype");
	namespace enum122 { enum class APPLICATIONMODE
	{
		DONTWAIT,			///< Stops the execution as soon as all initializations are done, used for command line mode.
		KEEPRUNNING,	///< Keeps the program running after all initializations.
		SHUTDOWN,			///< Quits the application and leave the main loop. Only working when APPLICATIONMODE::KEEPRUNNING was set before.
	} ; }
	maxon::String PrivateToString_APPLICATIONMODE122(std::underlying_type<enum122::APPLICATIONMODE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum122::APPLICATIONMODE::DONTWAIT, (maxon::UInt64) enum122::APPLICATIONMODE::KEEPRUNNING, (maxon::UInt64) enum122::APPLICATIONMODE::SHUTDOWN};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "APPLICATIONMODE", SIZEOF(x), false, values, "DONTWAIT\0KEEPRUNNING\0SHUTDOWN\0", fmt);
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_APPLICATIONMODE, , "net.maxon.datatype.enum.applicationmode");
	namespace enum128 { enum class APPLICATIONFEATURE
	{
		NONE = 0,
		COMMANDLINE = (1 << 0), ///< application runs as headless command line version.
	} ; }
	maxon::String PrivateToString_APPLICATIONFEATURE128(std::underlying_type<enum128::APPLICATIONFEATURE>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum128::APPLICATIONFEATURE::NONE, (maxon::UInt64) enum128::APPLICATIONFEATURE::COMMANDLINE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "APPLICATIONFEATURE", SIZEOF(x), true, values, "NONE\0COMMANDLINE\0", fmt);
	}
#ifdef MAXON_TARGET_WINDOWS
#endif
	const maxon::Char* const Application::MTable::_ids = 
		"GetTempUrl@80ddfa2d31821f3a\0" // Result<Url> GetTempUrl(const Url& directory)
		"GetModulePaths@cd0d7cbf880d7a5c\0" // Result<BaseArray<Url>> GetModulePaths()
		"GetCommandLineArgCount@4386c6f\0" // Int GetCommandLineArgCount()
		"GetCommandLineArg@fcf0b70602bb46\0" // String GetCommandLineArg(Int idx)
		"GetMachineInfo@c916016dbfde0060\0" // DataDictionary GetMachineInfo()
		"GetApplicationMode@81054c8f142a4e73\0" // APPLICATIONMODE GetApplicationMode()
		"SetApplicationMode@c2b201f9e16b0809\0" // Bool SetApplicationMode(APPLICATIONMODE mode)
		"GetFeature@e8f3f5b03a025244\0" // Bool GetFeature(APPLICATIONFEATURE feature)
		"SetFeature@3ee08ae72965b4e2\0" // void SetFeature(APPLICATIONFEATURE feature, Bool value)
		"GetVersion@6842a155716d62eb\0" // Result<void> GetVersion(Int& version, String& buildID)
#ifdef MAXON_TARGET_WINDOWS
		"GetWindowsSubsystem@f9e177409bbcef\0" // SUBSYSTEM GetWindowsSubsystem()
#endif
		"GetUrlI@8d58f90b3bda46de\0" // Result<Url> GetUrlI(APPLICATION_URLTYPE urlType)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class Application::Hxx2::Unresolved : public Application
	{
	public:
		static const Unresolved* Get(const Application* o) { return (const Unresolved*) o; }
		static Unresolved* Get(Application* o) { return (Unresolved*) o; }
		static Result<Url> GetTempUrl(const Url& directory) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Application::GetTempUrl(directory); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<BaseArray<Url>> GetModulePaths() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Application::GetModulePaths(); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Int GetCommandLineArgCount() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetCommandLineArgCount(); return 0;}
		static String GetCommandLineArg(Int idx) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetCommandLineArg(idx); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static DataDictionary GetMachineInfo() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetMachineInfo(); return maxon::PrivateIncompleteNullReturnValue<DataDictionary>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static APPLICATIONMODE GetApplicationMode() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetApplicationMode(); return maxon::PrivateIncompleteNullReturnValue<APPLICATIONMODE>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
		static Bool SetApplicationMode(APPLICATIONMODE mode) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::SetApplicationMode(mode); return maxon::PrivateLogNullptrError(false);}
		static Bool GetFeature(APPLICATIONFEATURE feature) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetFeature(feature); return maxon::PrivateLogNullptrError(false);}
		static void SetFeature(APPLICATIONFEATURE feature, Bool value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::SetFeature(feature, value); return maxon::PrivateLogNullptrError();}
		static Result<void> GetVersion(Int& version, String& buildID) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Application::GetVersion(version, buildID); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
#ifdef MAXON_TARGET_WINDOWS
		static SUBSYSTEM GetWindowsSubsystem() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetWindowsSubsystem(); return maxon::PrivateIncompleteNullReturnValue<SUBSYSTEM>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
#endif
		static Result<Url> GetUrlI(APPLICATION_URLTYPE urlType) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Application::GetUrlI(urlType); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE Application::MTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Result<Url>>::value,
		maxon::details::NullReturnType<Result<BaseArray<Url>>>::value,
		maxon::details::NullReturnType<Int>::value,
		maxon::details::NullReturnType<String>::value,
		maxon::details::NullReturnType<DataDictionary>::value,
		maxon::details::NullReturnType<APPLICATIONMODE>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<Bool>::value,
		maxon::details::NullReturnType<void>::value,
		maxon::details::NullReturnType<Result<void>>::value,
#ifdef MAXON_TARGET_WINDOWS
		maxon::details::NullReturnType<SUBSYSTEM>::value,
#endif
		maxon::details::NullReturnType<Result<Url>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool Application::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Url>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetTempUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetTempUrl;
		#else
		tbl->_Application_GetTempUrl = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetTempUrl;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<Url>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetModulePaths = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetModulePaths;
		#else
		tbl->_Application_GetModulePaths = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetModulePaths;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Application_GetCommandLineArgCount = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetCommandLineArgCount;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetCommandLineArg = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetCommandLineArg;
		#else
		tbl->_Application_GetCommandLineArg = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetCommandLineArg;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<DataDictionary>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetMachineInfo = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetMachineInfo;
		#else
		tbl->_Application_GetMachineInfo = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetMachineInfo;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<APPLICATIONMODE>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetApplicationMode = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetApplicationMode;
		#else
		tbl->_Application_GetApplicationMode = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetApplicationMode;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Application_SetApplicationMode = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_SetApplicationMode;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Application_GetFeature = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetFeature;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->_Application_SetFeature = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_SetFeature;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetVersion = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetVersion;
		#else
		tbl->_Application_GetVersion = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetVersion;
		#endif
#ifdef MAXON_TARGET_WINDOWS
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<SUBSYSTEM>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetWindowsSubsystem = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetWindowsSubsystem;
		#else
		tbl->_Application_GetWindowsSubsystem = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetWindowsSubsystem;
		#endif
#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Url>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_Application_GetUrlI = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetUrlI;
		#else
		tbl->_Application_GetUrlI = &Hxx2::Wrapper<Hxx2::Unresolved>::_Application_GetUrlI;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (maxon::Char*) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(Application, "net.maxon.interface.application", nullptr);
	template <typename DUMMY> maxon::Int Application::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<APPLICATIONMODE>(OVERLOAD_MAX_RANK)
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
