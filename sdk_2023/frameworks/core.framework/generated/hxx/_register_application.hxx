#if 1
namespace maxon
{
	namespace enum23
	{
		enum class SUBSYSTEM
		{
			UNDEFINED = 0,///< Undefined SUBSYSTEM
			CONSOLE = 1,	///< (\/%SUBSYSTEM:%CONSOLE)
			WINDOWS = 2		///< (\/%SUBSYSTEM:%WINDOWS)
		} ;
		static const maxon::UInt64 SUBSYSTEM_values[] = {maxon::UInt64(enum23::SUBSYSTEM::UNDEFINED), maxon::UInt64(enum23::SUBSYSTEM::CONSOLE), maxon::UInt64(enum23::SUBSYSTEM::WINDOWS)};
		static const maxon::EnumInfo SUBSYSTEM_info{"SUBSYSTEM", SIZEOF(SUBSYSTEM), false, "UNDEFINED\0CONSOLE\0WINDOWS\0", SUBSYSTEM_values, std::extent<decltype(SUBSYSTEM_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SUBSYSTEM23(){ return enum23::SUBSYSTEM_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_SUBSYSTEM, , "net.maxon.datatype.enum.subsystem");
	namespace enum120
	{
		enum class APPLICATION_URLTYPE
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
			CURRENT_MODULE_RESOURCE_DIR,
		
			//----------------------------------------------------------------------------------------
			/// Same as PREFS_DIR but without being able to set the path in the config.
			/// Cineware AE plug-in generates a lite.cert file at this location.
			/// Used for placing and reading the Lite certification file.
			//----------------------------------------------------------------------------------------
			PREFS_DIR_STATIC
		} ;
		static const maxon::UInt64 APPLICATION_URLTYPE_values[] = {maxon::UInt64(enum120::APPLICATION_URLTYPE::STARTUP_DIR), maxon::UInt64(enum120::APPLICATION_URLTYPE::APPLICATION), maxon::UInt64(enum120::APPLICATION_URLTYPE::APP_EXECUTABLE), maxon::UInt64(enum120::APPLICATION_URLTYPE::CORELIBS_DIR), maxon::UInt64(enum120::APPLICATION_URLTYPE::RESOURCE_DIR), maxon::UInt64(enum120::APPLICATION_URLTYPE::TEMP_DIR), maxon::UInt64(enum120::APPLICATION_URLTYPE::PREFS_DIR), maxon::UInt64(enum120::APPLICATION_URLTYPE::GLOBALPREFS_DIR), maxon::UInt64(enum120::APPLICATION_URLTYPE::DESKTOP_DIR), maxon::UInt64(enum120::APPLICATION_URLTYPE::USER_HOME_DIR), maxon::UInt64(enum120::APPLICATION_URLTYPE::USER_DOCUMENTS_DIR), maxon::UInt64(enum120::APPLICATION_URLTYPE::SYSTEM_PROGRAMS_DIR), maxon::UInt64(enum120::APPLICATION_URLTYPE::CURRENT_WORKING_DIR), maxon::UInt64(enum120::APPLICATION_URLTYPE::CURRENT_MODULE_DIR), maxon::UInt64(enum120::APPLICATION_URLTYPE::CURRENT_MODULE_RESOURCE_DIR), maxon::UInt64(enum120::APPLICATION_URLTYPE::PREFS_DIR_STATIC)};
		static const maxon::EnumInfo APPLICATION_URLTYPE_info{"APPLICATION_URLTYPE", SIZEOF(APPLICATION_URLTYPE), false, "STARTUP_DIR\0APPLICATION\0APP_EXECUTABLE\0CORELIBS_DIR\0RESOURCE_DIR\0TEMP_DIR\0PREFS_DIR\0GLOBALPREFS_DIR\0DESKTOP_DIR\0USER_HOME_DIR\0USER_DOCUMENTS_DIR\0SYSTEM_PROGRAMS_DIR\0CURRENT_WORKING_DIR\0CURRENT_MODULE_DIR\0CURRENT_MODULE_RESOURCE_DIR\0PREFS_DIR_STATIC\0", APPLICATION_URLTYPE_values, std::extent<decltype(APPLICATION_URLTYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_APPLICATION_URLTYPE120(){ return enum120::APPLICATION_URLTYPE_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_APPLICATION_URLTYPE, , "net.maxon.datatype.enum.application_urltype");
	namespace enum129
	{
		enum class APPLICATIONMODE
		{
			DONTWAIT,			///< Stops the execution as soon as all initializations are done, used for command line mode.
			KEEPRUNNING,	///< Keeps the program running after all initializations.
			SHUTDOWN,			///< Quits the application and leave the main loop. Only working when APPLICATIONMODE::KEEPRUNNING was set before.
		} ;
		static const maxon::UInt64 APPLICATIONMODE_values[] = {maxon::UInt64(enum129::APPLICATIONMODE::DONTWAIT), maxon::UInt64(enum129::APPLICATIONMODE::KEEPRUNNING), maxon::UInt64(enum129::APPLICATIONMODE::SHUTDOWN)};
		static const maxon::EnumInfo APPLICATIONMODE_info{"APPLICATIONMODE", SIZEOF(APPLICATIONMODE), false, "DONTWAIT\0KEEPRUNNING\0SHUTDOWN\0", APPLICATIONMODE_values, std::extent<decltype(APPLICATIONMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_APPLICATIONMODE129(){ return enum129::APPLICATIONMODE_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_APPLICATIONMODE, , "net.maxon.datatype.enum.applicationmode");
	namespace enum137
	{
		enum class APPLICATIONFEATURE
		{
			NONE = 0,								///< Default case
			COMMANDLINE = (1 << 0), ///< Application runs as headless command line version.
			LIBRARY = 		(1 << 1), ///< Frameworks are used by plugins or another host (Cineware, Redshift, ...)
			UI = 					(1 << 2), ///<  UI is enabled (if this is LIBRARY or COMMANDLINE)
		} ;
		static const maxon::UInt64 APPLICATIONFEATURE_values[] = {maxon::UInt64(enum137::APPLICATIONFEATURE::NONE), maxon::UInt64(enum137::APPLICATIONFEATURE::COMMANDLINE), maxon::UInt64(enum137::APPLICATIONFEATURE::LIBRARY), maxon::UInt64(enum137::APPLICATIONFEATURE::UI)};
		static const maxon::EnumInfo APPLICATIONFEATURE_info{"APPLICATIONFEATURE", SIZEOF(APPLICATIONFEATURE), true, "NONE\0COMMANDLINE\0LIBRARY\0UI\0", APPLICATIONFEATURE_values, std::extent<decltype(APPLICATIONFEATURE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_APPLICATIONFEATURE137(){ return enum137::APPLICATIONFEATURE_info; }
	namespace APPMESSAGE
	{
		namespace OPENFILES
		{
			ARGUMENTS_PrivateAttribute ARGUMENTS;
		}
	}
#ifdef MAXON_TARGET_WINDOWS
#endif
	const maxon::Char* const Application::MTable::_ids = 
		"GetTempUrl@f5d52a42bb053487\0" // Result<Url> GetTempUrl(const Url& directory)
		"GetModulePaths@ddbe905e18bb3195\0" // Result<BaseArray<Url>> GetModulePaths()
		"GetCommandLineArgCount@7d0e6f3d10c2128c\0" // Int GetCommandLineArgCount()
		"GetCommandLineArg@fa951fa9754d4813\0" // String GetCommandLineArg(Int idx)
		"GetMachineInfo@72a97bfbdb619a33\0" // DataDictionary GetMachineInfo()
		"GetApplicationMode@2e77a5b7103ba620\0" // APPLICATIONMODE GetApplicationMode()
		"SetApplicationMode@3eab636043f64308\0" // Bool SetApplicationMode(APPLICATIONMODE mode)
		"GetFeature@3c352a3a8d8db75f\0" // Bool GetFeature(APPLICATIONFEATURE feature)
		"SetFeature@84572c442cda7f29\0" // void SetFeature(APPLICATIONFEATURE feature, Bool value)
		"GetVersion@ee9f8427c59a2ea6\0" // Result<void> GetVersion(Int& version, String& buildID)
		"FormatVersionString@fa951fa9754d4813\0" // String FormatVersionString(Int rawVersionNumber)
#ifdef MAXON_TARGET_WINDOWS
		"GetWindowsSubsystem@5e2c1553c536b2fa\0" // SUBSYSTEM GetWindowsSubsystem()
#endif
		"ObservableApplicationMessage@7fc869e8d805252b\0" // maxon::ObservableRef<ObservableApplicationMessageDelegate> ObservableApplicationMessage()
		"GetUrlI@1eefeb278b7f486f\0" // Result<Url> GetUrlI(APPLICATION_URLTYPE urlType)
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
		static String FormatVersionString(Int rawVersionNumber) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::FormatVersionString(rawVersionNumber); return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
#ifdef MAXON_TARGET_WINDOWS
		static SUBSYSTEM GetWindowsSubsystem() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetWindowsSubsystem(); return maxon::PrivateIncompleteNullReturnValue<SUBSYSTEM>(maxon::NULL_RETURN_REASON::UNRESOLVED, OVERLOAD_MAX_RANK);}
#endif
		static maxon::ObservableRef<ObservableApplicationMessageDelegate> ObservableApplicationMessage() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::ObservableApplicationMessage(); return maxon::ObservableRef<ObservableApplicationMessageDelegate>::NullValue();}
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
		maxon::details::NullReturnType<String>::value,
#ifdef MAXON_TARGET_WINDOWS
		maxon::details::NullReturnType<SUBSYSTEM>::value,
#endif
		maxon::details::NullReturnType<maxon::ObservableRef<ObservableApplicationMessageDelegate>>::value,
		maxon::details::NullReturnType<Result<Url>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool Application::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Url>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Application_GetTempUrl = PRIVATE_MAXON_MF_CAST(decltype(Application_GetTempUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetTempUrl);
		#else
		tbl->Application_GetTempUrl = PRIVATE_MAXON_MF_CAST(decltype(Application_GetTempUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetTempUrl);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<BaseArray<Url>>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Application_GetModulePaths = PRIVATE_MAXON_MF_CAST(decltype(Application_GetModulePaths), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetModulePaths);
		#else
		tbl->Application_GetModulePaths = PRIVATE_MAXON_MF_CAST(decltype(Application_GetModulePaths), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetModulePaths);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Application_GetCommandLineArgCount = PRIVATE_MAXON_MF_CAST(decltype(Application_GetCommandLineArgCount), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetCommandLineArgCount);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Application_GetCommandLineArg = PRIVATE_MAXON_MF_CAST(decltype(Application_GetCommandLineArg), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetCommandLineArg);
		#else
		tbl->Application_GetCommandLineArg = PRIVATE_MAXON_MF_CAST(decltype(Application_GetCommandLineArg), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetCommandLineArg);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<DataDictionary>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Application_GetMachineInfo = PRIVATE_MAXON_MF_CAST(decltype(Application_GetMachineInfo), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetMachineInfo);
		#else
		tbl->Application_GetMachineInfo = PRIVATE_MAXON_MF_CAST(decltype(Application_GetMachineInfo), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetMachineInfo);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<APPLICATIONMODE>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Application_GetApplicationMode = PRIVATE_MAXON_MF_CAST(decltype(Application_GetApplicationMode), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetApplicationMode);
		#else
		tbl->Application_GetApplicationMode = PRIVATE_MAXON_MF_CAST(decltype(Application_GetApplicationMode), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetApplicationMode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Application_SetApplicationMode = PRIVATE_MAXON_MF_CAST(decltype(Application_SetApplicationMode), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_SetApplicationMode);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Application_GetFeature = PRIVATE_MAXON_MF_CAST(decltype(Application_GetFeature), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetFeature);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Application_SetFeature = PRIVATE_MAXON_MF_CAST(decltype(Application_SetFeature), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_SetFeature);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Application_GetVersion = PRIVATE_MAXON_MF_CAST(decltype(Application_GetVersion), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetVersion);
		#else
		tbl->Application_GetVersion = PRIVATE_MAXON_MF_CAST(decltype(Application_GetVersion), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetVersion);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<String>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Application_FormatVersionString = PRIVATE_MAXON_MF_CAST(decltype(Application_FormatVersionString), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_FormatVersionString);
		#else
		tbl->Application_FormatVersionString = PRIVATE_MAXON_MF_CAST(decltype(Application_FormatVersionString), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_FormatVersionString);
		#endif
#ifdef MAXON_TARGET_WINDOWS
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<SUBSYSTEM>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Application_GetWindowsSubsystem = PRIVATE_MAXON_MF_CAST(decltype(Application_GetWindowsSubsystem), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetWindowsSubsystem);
		#else
		tbl->Application_GetWindowsSubsystem = PRIVATE_MAXON_MF_CAST(decltype(Application_GetWindowsSubsystem), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetWindowsSubsystem);
		#endif
#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<maxon::ObservableRef<ObservableApplicationMessageDelegate>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Application_ObservableApplicationMessage = PRIVATE_MAXON_MF_CAST(decltype(Application_ObservableApplicationMessage), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_ObservableApplicationMessage);
		#else
		tbl->Application_ObservableApplicationMessage = PRIVATE_MAXON_MF_CAST(decltype(Application_ObservableApplicationMessage), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_ObservableApplicationMessage);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Url>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->Application_GetUrlI = PRIVATE_MAXON_MF_CAST(decltype(Application_GetUrlI), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetUrlI);
		#else
		tbl->Application_GetUrlI = PRIVATE_MAXON_MF_CAST(decltype(Application_GetUrlI), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetUrlI);
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
