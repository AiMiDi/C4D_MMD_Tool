
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
	static const maxon::UNRESOLVED_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	PRIVATE_MAXON_SF_POINTER(CrashHandler_SetCallback, SetCallback, MAXON_EXPAND_VA_ARGS, (Bool), CallbackPtr callback);
	PRIVATE_MAXON_SF_POINTER(CrashHandler_SetSecondaryCallback, SetSecondaryCallback, MAXON_EXPAND_VA_ARGS, (Bool), CallbackPtr callback);
	PRIVATE_MAXON_SF_POINTER(CrashHandler_SetCrashDataDirectory, SetCrashDataDirectory, MAXON_EXPAND_VA_ARGS, (Result<void>), const Url& dataDirectory);
	PRIVATE_MAXON_SF_POINTER(CrashHandler_DisplayCrashDialog, DisplayCrashDialog, MAXON_EXPAND_VA_ARGS, (void), const String& title, const String& message);
	PRIVATE_MAXON_SF_POINTER(CrashHandler_GetProcessModules, GetProcessModules, MAXON_EXPAND_VA_ARGS, (Result<void>), WritableArrayInterface<CrashModuleEntry>& modules);
	PRIVATE_MAXON_SF_POINTER(CrashHandler_ResolveBugReport, ResolveBugReport, MAXON_EXPAND_VA_ARGS, (Result<void>), const Url& report, const Url& symbolFileArchives, const Url& temporaryDir);
	PRIVATE_MAXON_SF_POINTER(CrashHandler_ObservableCrashDataDirectory, ObservableCrashDataDirectory, MAXON_EXPAND_VA_ARGS, (maxon::ObservableRef<ObservableCrashDataDirectoryDelegate>), Bool create);
	template <typename IMPL> void Init()
	{
		CrashHandler_SetCallback = CrashHandler_SetCallback_GetPtr<IMPL>(true);
		CrashHandler_SetSecondaryCallback = CrashHandler_SetSecondaryCallback_GetPtr<IMPL>(true);
		CrashHandler_SetCrashDataDirectory = CrashHandler_SetCrashDataDirectory_GetPtr<IMPL>(true);
		CrashHandler_DisplayCrashDialog = CrashHandler_DisplayCrashDialog_GetPtr<IMPL>(true);
		CrashHandler_GetProcessModules = CrashHandler_GetProcessModules_GetPtr<IMPL>(true);
		CrashHandler_ResolveBugReport = CrashHandler_ResolveBugReport_GetPtr<IMPL>(true);
		CrashHandler_ObservableCrashDataDirectory = CrashHandler_ObservableCrashDataDirectory_GetPtr<IMPL>(true);
	}
};

struct CrashHandler::Hxx2
{
	class Unresolved;
	template <typename S> class Wrapper
	{
	public:
		using Implementation = S;
		static Bool CrashHandler_SetCallback(CallbackPtr callback) { return S::SetCallback(std::forward<CallbackPtr>(callback)); }
		static Bool CrashHandler_SetSecondaryCallback(CallbackPtr callback) { return S::SetSecondaryCallback(std::forward<CallbackPtr>(callback)); }
		static Result<void> CrashHandler_SetCrashDataDirectory(const Url& dataDirectory) { return S::SetCrashDataDirectory(dataDirectory); }
		static void CrashHandler_DisplayCrashDialog(const String& title, const String& message) { return S::DisplayCrashDialog(title, message); }
		static Result<void> CrashHandler_GetProcessModules(WritableArrayInterface<CrashModuleEntry>& modules) { return S::GetProcessModules(modules); }
		static Result<void> CrashHandler_ResolveBugReport(const Url& report, const Url& symbolFileArchives, const Url& temporaryDir) { return S::ResolveBugReport(report, symbolFileArchives, temporaryDir); }
		static maxon::ObservableRef<ObservableCrashDataDirectoryDelegate> CrashHandler_ObservableCrashDataDirectory(Bool create) { return S::ObservableCrashDataDirectory(create); }
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
MAXON_ATTRIBUTE_FORCE_INLINE auto CrashHandler::ObservableCrashDataDirectory(Bool create) -> maxon::ObservableRef<ObservableCrashDataDirectoryDelegate>
{
	return MTable::_instance.CrashHandler_ObservableCrashDataDirectory(create);
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

