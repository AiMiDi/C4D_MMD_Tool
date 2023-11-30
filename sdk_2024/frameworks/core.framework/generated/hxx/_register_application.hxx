#if 1
namespace maxon
{
	namespace enum24
	{
		enum class SUBSYSTEM
		{
			UNDEFINED = 0,///< Undefined SUBSYSTEM
			CONSOLE = 1,	///< (\/%SUBSYSTEM:%CONSOLE)
			WINDOWS = 2		///< (\/%SUBSYSTEM:%WINDOWS)
		} ;
		static const maxon::UInt64 SUBSYSTEM_values[] = {maxon::UInt64(enum24::SUBSYSTEM::UNDEFINED), maxon::UInt64(enum24::SUBSYSTEM::CONSOLE), maxon::UInt64(enum24::SUBSYSTEM::WINDOWS)};
		static const maxon::EnumInfo SUBSYSTEM_info{"SUBSYSTEM", SIZEOF(SUBSYSTEM), false, "UNDEFINED\0CONSOLE\0WINDOWS\0", SUBSYSTEM_values, std::extent<decltype(SUBSYSTEM_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_SUBSYSTEM24(){ return enum24::SUBSYSTEM_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_SUBSYSTEM, , "net.maxon.datatype.enum.subsystem");
	namespace enum126
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
			/// Library directory.
			//----------------------------------------------------------------------------------------
			LIBRARY_DIR,
		
			//----------------------------------------------------------------------------------------
			/// Same as PREFS_DIR but without being able to set the path in the config.
			/// Cineware AE plug-in generates a lite.cert file at this location.
			/// Used for placing and reading the Lite certification file.
			//----------------------------------------------------------------------------------------
			PREFS_DIR_STATIC
		} ;
		static const maxon::UInt64 APPLICATION_URLTYPE_values[] = {maxon::UInt64(enum126::APPLICATION_URLTYPE::STARTUP_DIR), maxon::UInt64(enum126::APPLICATION_URLTYPE::APPLICATION), maxon::UInt64(enum126::APPLICATION_URLTYPE::APP_EXECUTABLE), maxon::UInt64(enum126::APPLICATION_URLTYPE::CORELIBS_DIR), maxon::UInt64(enum126::APPLICATION_URLTYPE::RESOURCE_DIR), maxon::UInt64(enum126::APPLICATION_URLTYPE::TEMP_DIR), maxon::UInt64(enum126::APPLICATION_URLTYPE::PREFS_DIR), maxon::UInt64(enum126::APPLICATION_URLTYPE::GLOBALPREFS_DIR), maxon::UInt64(enum126::APPLICATION_URLTYPE::DESKTOP_DIR), maxon::UInt64(enum126::APPLICATION_URLTYPE::USER_HOME_DIR), maxon::UInt64(enum126::APPLICATION_URLTYPE::USER_DOCUMENTS_DIR), maxon::UInt64(enum126::APPLICATION_URLTYPE::SYSTEM_PROGRAMS_DIR), maxon::UInt64(enum126::APPLICATION_URLTYPE::CURRENT_WORKING_DIR), maxon::UInt64(enum126::APPLICATION_URLTYPE::CURRENT_MODULE_DIR), maxon::UInt64(enum126::APPLICATION_URLTYPE::CURRENT_MODULE_RESOURCE_DIR), maxon::UInt64(enum126::APPLICATION_URLTYPE::LIBRARY_DIR), maxon::UInt64(enum126::APPLICATION_URLTYPE::PREFS_DIR_STATIC)};
		static const maxon::EnumInfo APPLICATION_URLTYPE_info{"APPLICATION_URLTYPE", SIZEOF(APPLICATION_URLTYPE), false, "STARTUP_DIR\0APPLICATION\0APP_EXECUTABLE\0CORELIBS_DIR\0RESOURCE_DIR\0TEMP_DIR\0PREFS_DIR\0GLOBALPREFS_DIR\0DESKTOP_DIR\0USER_HOME_DIR\0USER_DOCUMENTS_DIR\0SYSTEM_PROGRAMS_DIR\0CURRENT_WORKING_DIR\0CURRENT_MODULE_DIR\0CURRENT_MODULE_RESOURCE_DIR\0LIBRARY_DIR\0PREFS_DIR_STATIC\0", APPLICATION_URLTYPE_values, std::extent<decltype(APPLICATION_URLTYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_APPLICATION_URLTYPE126(){ return enum126::APPLICATION_URLTYPE_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_APPLICATION_URLTYPE, , "net.maxon.datatype.enum.application_urltype");
	namespace enum135
	{
		enum class APPLICATIONMODE
		{
			DONTWAIT,			///< Stops the execution as soon as all initializations are done, used for command line mode.
			KEEPRUNNING,	///< Keeps the program running after all initializations.
			SHUTDOWN,			///< Quits the application and leave the main loop. Only working when APPLICATIONMODE::KEEPRUNNING was set before.
		} ;
		static const maxon::UInt64 APPLICATIONMODE_values[] = {maxon::UInt64(enum135::APPLICATIONMODE::DONTWAIT), maxon::UInt64(enum135::APPLICATIONMODE::KEEPRUNNING), maxon::UInt64(enum135::APPLICATIONMODE::SHUTDOWN)};
		static const maxon::EnumInfo APPLICATIONMODE_info{"APPLICATIONMODE", SIZEOF(APPLICATIONMODE), false, "DONTWAIT\0KEEPRUNNING\0SHUTDOWN\0", APPLICATIONMODE_values, std::extent<decltype(APPLICATIONMODE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_APPLICATIONMODE135(){ return enum135::APPLICATIONMODE_info; }
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_APPLICATIONMODE, , "net.maxon.datatype.enum.applicationmode");
	namespace enum143
	{
		enum class APPLICATIONFEATURE
		{
			NONE = 0,								///< Default case
			COMMANDLINE = (1 << 0), ///< Application runs as headless command line version.
			LIBRARY = 		(1 << 1), ///< Frameworks are used by plugins or another host (Cineware, Redshift, ...)
			UI = 					(1 << 2), ///<  UI is enabled (if this is LIBRARY or COMMANDLINE)
		} ;
		static const maxon::UInt64 APPLICATIONFEATURE_values[] = {maxon::UInt64(enum143::APPLICATIONFEATURE::NONE), maxon::UInt64(enum143::APPLICATIONFEATURE::COMMANDLINE), maxon::UInt64(enum143::APPLICATIONFEATURE::LIBRARY), maxon::UInt64(enum143::APPLICATIONFEATURE::UI)};
		static const maxon::EnumInfo APPLICATIONFEATURE_info{"APPLICATIONFEATURE", SIZEOF(APPLICATIONFEATURE), true, "NONE\0COMMANDLINE\0LIBRARY\0UI\0", APPLICATIONFEATURE_values, std::extent<decltype(APPLICATIONFEATURE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_APPLICATIONFEATURE143(){ return enum143::APPLICATIONFEATURE_info; }
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
		"ObservableApplicationMessage@85465bbbd742bd5f\0" // maxon::ObservableRef<ObservableApplicationMessageDelegate> ObservableApplicationMessage(Bool create)
		"RegisterSystemUrlSchemeHandler@a1d7c0ee6d1bab48\0" // Result<void> RegisterSystemUrlSchemeHandler(const Id& urlScheme, Bool reassignApplication, Delegate<void(const Url&)>&& callback)
		"CheckSystemUrlSchemeHandlerIsCurrent@1c8d04d0dcb0bd41\0" // Bool CheckSystemUrlSchemeHandlerIsCurrent(const Id& urlScheme)
		"PrivateGetUrl@4442b467c5f4dc9e\0" // Result<Url> PrivateGetUrl(APPLICATION_URLTYPE urlType, const Char* maxonModuleID, const Binary& currentModule)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class Application::Hxx2::Unresolved : public Application
	{
	public:
		static const Unresolved* Get(const Application* o) { return (const Unresolved*) o; }
		static Unresolved* Get(Application* o) { return (Unresolved*) o; }
		static Result<Url> GetTempUrl(const Url& directory) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Application::GetTempUrl(directory); return HXXRET1(UNRESOLVED);}
		static Result<BaseArray<Url>> GetModulePaths() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Application::GetModulePaths(); return HXXRET1(UNRESOLVED);}
		static Int GetCommandLineArgCount() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetCommandLineArgCount(); return 0;}
		static String GetCommandLineArg(Int idx) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetCommandLineArg(idx); return HXXRET3(UNRESOLVED, String);}
		static DataDictionary GetMachineInfo() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetMachineInfo(); return HXXRET3(UNRESOLVED, DataDictionary);}
		static APPLICATIONMODE GetApplicationMode() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetApplicationMode(); return HXXRET3(UNRESOLVED, APPLICATIONMODE);}
		static Bool SetApplicationMode(APPLICATIONMODE mode) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::SetApplicationMode(mode); return maxon::PrivateLogNullptrError(false);}
		static Bool GetFeature(APPLICATIONFEATURE feature) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetFeature(feature); return maxon::PrivateLogNullptrError(false);}
		static void SetFeature(APPLICATIONFEATURE feature, Bool value) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::SetFeature(feature, value); return maxon::PrivateLogNullptrError();}
		static Result<void> GetVersion(Int& version, String& buildID) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Application::GetVersion(version, buildID); return HXXRET1(UNRESOLVED);}
		static String FormatVersionString(Int rawVersionNumber) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::FormatVersionString(rawVersionNumber); return HXXRET3(UNRESOLVED, String);}
#ifdef MAXON_TARGET_WINDOWS
		static SUBSYSTEM GetWindowsSubsystem() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::GetWindowsSubsystem(); return HXXRET3(UNRESOLVED, SUBSYSTEM);}
#endif
		static maxon::ObservableRef<ObservableApplicationMessageDelegate> ObservableApplicationMessage(Bool create) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::ObservableApplicationMessage(create); return maxon::ObservableRef<ObservableApplicationMessageDelegate>::DefaultValue();}
		static Result<void> RegisterSystemUrlSchemeHandler(const Id& urlScheme, Bool reassignApplication, Delegate<void(const Url&)>&& callback) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Application::RegisterSystemUrlSchemeHandler(urlScheme, reassignApplication, std::forward<Delegate<void(const Url&)>>(callback)); return HXXRET1(UNRESOLVED);}
		static Bool CheckSystemUrlSchemeHandlerIsCurrent(const Id& urlScheme) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return Application::CheckSystemUrlSchemeHandlerIsCurrent(urlScheme); return maxon::PrivateLogNullptrError(false);}
		static Result<Url> PrivateGetUrl(APPLICATION_URLTYPE urlType, const Char* maxonModuleID, const Binary& currentModule) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return Application::PrivateGetUrl(urlType, maxonModuleID, currentModule); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE Application::MTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<Result<Url>>::value,
		maxon::details::UnresolvedReturnType<Result<BaseArray<Url>>>::value,
		maxon::details::UnresolvedReturnType<Int>::value,
		maxon::details::UnresolvedReturnType<String>::value,
		maxon::details::UnresolvedReturnType<DataDictionary>::value,
		maxon::details::UnresolvedReturnType<APPLICATIONMODE>::value,
		maxon::details::UnresolvedReturnType<Bool>::value,
		maxon::details::UnresolvedReturnType<Bool>::value,
		maxon::details::UnresolvedReturnType<void>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<String>::value,
#ifdef MAXON_TARGET_WINDOWS
		maxon::details::UnresolvedReturnType<SUBSYSTEM>::value,
#endif
		maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableApplicationMessageDelegate>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Bool>::value,
		maxon::details::UnresolvedReturnType<Result<Url>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool Application::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Url>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Application_GetTempUrl = PRIVATE_MAXON_MF_CAST(decltype(Application_GetTempUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetTempUrl);
		#else
		tbl->Application_GetTempUrl = PRIVATE_MAXON_MF_CAST(decltype(Application_GetTempUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetTempUrl);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<BaseArray<Url>>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Application_GetModulePaths = PRIVATE_MAXON_MF_CAST(decltype(Application_GetModulePaths), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetModulePaths);
		#else
		tbl->Application_GetModulePaths = PRIVATE_MAXON_MF_CAST(decltype(Application_GetModulePaths), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetModulePaths);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Application_GetCommandLineArgCount = PRIVATE_MAXON_MF_CAST(decltype(Application_GetCommandLineArgCount), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetCommandLineArgCount);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Application_GetCommandLineArg = PRIVATE_MAXON_MF_CAST(decltype(Application_GetCommandLineArg), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetCommandLineArg);
		#else
		tbl->Application_GetCommandLineArg = PRIVATE_MAXON_MF_CAST(decltype(Application_GetCommandLineArg), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetCommandLineArg);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<DataDictionary>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Application_GetMachineInfo = PRIVATE_MAXON_MF_CAST(decltype(Application_GetMachineInfo), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetMachineInfo);
		#else
		tbl->Application_GetMachineInfo = PRIVATE_MAXON_MF_CAST(decltype(Application_GetMachineInfo), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetMachineInfo);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<APPLICATIONMODE>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Application_GetApplicationMode = PRIVATE_MAXON_MF_CAST(decltype(Application_GetApplicationMode), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetApplicationMode);
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
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Application_GetVersion = PRIVATE_MAXON_MF_CAST(decltype(Application_GetVersion), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetVersion);
		#else
		tbl->Application_GetVersion = PRIVATE_MAXON_MF_CAST(decltype(Application_GetVersion), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetVersion);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<String>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Application_FormatVersionString = PRIVATE_MAXON_MF_CAST(decltype(Application_FormatVersionString), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_FormatVersionString);
		#else
		tbl->Application_FormatVersionString = PRIVATE_MAXON_MF_CAST(decltype(Application_FormatVersionString), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_FormatVersionString);
		#endif
#ifdef MAXON_TARGET_WINDOWS
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<SUBSYSTEM>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Application_GetWindowsSubsystem = PRIVATE_MAXON_MF_CAST(decltype(Application_GetWindowsSubsystem), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetWindowsSubsystem);
		#else
		tbl->Application_GetWindowsSubsystem = PRIVATE_MAXON_MF_CAST(decltype(Application_GetWindowsSubsystem), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_GetWindowsSubsystem);
		#endif
#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableApplicationMessageDelegate>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Application_ObservableApplicationMessage = PRIVATE_MAXON_MF_CAST(decltype(Application_ObservableApplicationMessage), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_ObservableApplicationMessage);
		#else
		tbl->Application_ObservableApplicationMessage = PRIVATE_MAXON_MF_CAST(decltype(Application_ObservableApplicationMessage), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_ObservableApplicationMessage);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Application_RegisterSystemUrlSchemeHandler = PRIVATE_MAXON_MF_CAST(decltype(Application_RegisterSystemUrlSchemeHandler), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_RegisterSystemUrlSchemeHandler);
		#else
		tbl->Application_RegisterSystemUrlSchemeHandler = PRIVATE_MAXON_MF_CAST(decltype(Application_RegisterSystemUrlSchemeHandler), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_RegisterSystemUrlSchemeHandler);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->Application_CheckSystemUrlSchemeHandlerIsCurrent = PRIVATE_MAXON_MF_CAST(decltype(Application_CheckSystemUrlSchemeHandlerIsCurrent), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_CheckSystemUrlSchemeHandlerIsCurrent);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<Url>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->Application_PrivateGetUrl = PRIVATE_MAXON_MF_CAST(decltype(Application_PrivateGetUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_PrivateGetUrl);
		#else
		tbl->Application_PrivateGetUrl = PRIVATE_MAXON_MF_CAST(decltype(Application_PrivateGetUrl), &Hxx2::Wrapper<Hxx2::Unresolved>::Application_PrivateGetUrl);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(Application, "net.maxon.interface.application", nullptr, maxon::EntityBase::FLAGS::NONE);
	template <typename DUMMY> maxon::Int Application::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<APPLICATIONMODE>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<DataDictionary>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<SUBSYSTEM>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateDefaultReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
}
#endif
static maxon::details::ForceEvaluation s_forceEval_application(0
	| maxon::Application::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
