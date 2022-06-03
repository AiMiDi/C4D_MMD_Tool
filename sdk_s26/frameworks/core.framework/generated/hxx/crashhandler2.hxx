
#ifndef DOXYGEN

#if defined MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#if MAXON_COMPILER_GCC >= 600
		#pragma GCC diagnostic ignored "-Wmisleading-indentation"
	#endif
#endif

#if 1
constexpr const maxon::Char* CrashHandler::PrivateGetCppName() { return nullptr; }

struct CrashHandler::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Bool (*CrashHandler_SetCallback) (CallbackPtr callback);
	Bool (*CrashHandler_SetSecondaryCallback) (CallbackPtr callback);
	Result<void> (*CrashHandler_SetCrashDataDirectory) (const Url& dataDirectory);
	void (*CrashHandler_DisplayCrashDialog) (const String& title, const String& message);
	Result<void> (*CrashHandler_GetProcessModules) (WritableArrayInterface<CrashModuleEntry>& modules);
	Result<void> (*CrashHandler_ResolveBugReport) (const Url& report, const Url& symbolFileArchives, const Url& temporaryDir);
	maxon::ObservableRef<ObservableCrashDataDirectoryDelegate> (*CrashHandler_ObservableCrashDataDirectory) ();
	template <typename IMPL> void Init()
	{
		CrashHandler_SetCallback = &IMPL::CrashHandler_SetCallback;
		CrashHandler_SetSecondaryCallback = &IMPL::CrashHandler_SetSecondaryCallback;
		CrashHandler_SetCrashDataDirectory = &IMPL::CrashHandler_SetCrashDataDirectory;
		CrashHandler_DisplayCrashDialog = &IMPL::CrashHandler_DisplayCrashDialog;
		CrashHandler_GetProcessModules = &IMPL::CrashHandler_GetProcessModules;
		CrashHandler_ResolveBugReport = &IMPL::CrashHandler_ResolveBugReport;
		CrashHandler_ObservableCrashDataDirectory = &IMPL::CrashHandler_ObservableCrashDataDirectory;
	}
};

struct CrashHandler::Hxx2
{
	class Unresolved;
	template <typename C> class Wrapper
	{
	public:
		static Bool CrashHandler_SetCallback(CallbackPtr callback) { return C::SetCallback(std::forward<CallbackPtr>(callback)); }
		static Bool CrashHandler_SetSecondaryCallback(CallbackPtr callback) { return C::SetSecondaryCallback(std::forward<CallbackPtr>(callback)); }
		static Result<void> CrashHandler_SetCrashDataDirectory(const Url& dataDirectory) { return C::SetCrashDataDirectory(dataDirectory); }
		static void CrashHandler_DisplayCrashDialog(const String& title, const String& message) { return C::DisplayCrashDialog(title, message); }
		static Result<void> CrashHandler_GetProcessModules(WritableArrayInterface<CrashModuleEntry>& modules) { return C::GetProcessModules(modules); }
		static Result<void> CrashHandler_ResolveBugReport(const Url& report, const Url& symbolFileArchives, const Url& temporaryDir) { return C::ResolveBugReport(report, symbolFileArchives, temporaryDir); }
		static maxon::ObservableRef<ObservableCrashDataDirectoryDelegate> CrashHandler_ObservableCrashDataDirectory() { return C::ObservableCrashDataDirectory(); }
	};

};
MAXON_ATTRIBUTE_FORCE_INLINE auto CrashHandler::SetCallback(CallbackPtr callback) -> Bool
{
	return MTable::_instance.CrashHandler_SetCallback(std::forward<CallbackPtr>(callback));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CrashHandler::SetSecondaryCallback(CallbackPtr callback) -> Bool
{
	return MTable::_instance.CrashHandler_SetSecondaryCallback(std::forward<CallbackPtr>(callback));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CrashHandler::SetCrashDataDirectory(const Url& dataDirectory) -> Result<void>
{
	return MTable::_instance.CrashHandler_SetCrashDataDirectory(dataDirectory);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CrashHandler::DisplayCrashDialog(const String& title, const String& message) -> void
{
	return MTable::_instance.CrashHandler_DisplayCrashDialog(title, message);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CrashHandler::GetProcessModules(WritableArrayInterface<CrashModuleEntry>& modules) -> Result<void>
{
	return MTable::_instance.CrashHandler_GetProcessModules(modules);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CrashHandler::ResolveBugReport(const Url& report, const Url& symbolFileArchives, const Url& temporaryDir) -> Result<void>
{
	return MTable::_instance.CrashHandler_ResolveBugReport(report, symbolFileArchives, temporaryDir);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CrashHandler::ObservableCrashDataDirectory() -> maxon::ObservableRef<ObservableCrashDataDirectoryDelegate>
{
	return MTable::_instance.CrashHandler_ObservableCrashDataDirectory();
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT) && !defined(MAXON_DEPENDENCY_DISABLE_crashhandler)
#ifdef MAXON_USE_REGISTER_FUNCTION
MAXON_STATIC_STORAGE(maxon::EntityUse, s_ui_maxon_CrashHandler); \
MAXON_ATTRIBUTE_CONSTRUCTOR static void Register_s_ui_maxon_CrashHandler() { new (s_ui_maxon_CrashHandler) maxon::EntityUse(CrashHandler::_interface.GetReference(), &maxon::g_translationUnit, "maxon/crashhandler.h", false); }
#else // !MAXON_USE_REGISTER_FUNCTION
static maxon::EntityUse s_ui_maxon_CrashHandler(CrashHandler::_interface.GetReference(), &maxon::g_translationUnit, "maxon/crashhandler.h", false);
#endif // MAXON_USE_REGISTER_FUNCTION
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

