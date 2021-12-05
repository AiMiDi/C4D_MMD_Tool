
#ifndef DOXYGEN

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic push
	#pragma GCC diagnostic ignored "-Wmisleading-indentation"
#endif

#if 1

struct CrashHandler::MTable
{
	static MTable _instance;
	static MTable _unresolvedInstance;
	static const maxon::Char* const _ids;
	static maxon::Bool InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl);
	static const maxon::NULL_RETURN_TYPE _returnTypes[];
	static const maxon::Bool HAS_NONSTATIC = false;
	Bool (*_CrashHandler_SetCallback) (CallbackPtr callback);
	Bool (*_CrashHandler_SetSecondaryCallback) (CallbackPtr callback);
	Result<void> (*_CrashHandler_SetCrashDataDirectory) (const Url& dataDirectory);
	void (*_CrashHandler_DisplayCrashDialog) (const String& title, const String& message);
	Result<void> (*_CrashHandler_ResolveBugReport) (const Url& report, const Url& symbolFileArchives, const Url& temporaryDir);
	maxon::ObservableRef<ObservableCrashDataDirectoryDelegate> (*_CrashHandler_ObservableCrashDataDirectory) ();
	template <typename IMPL> static void Init(MTable* tbl)
	{
		tbl->_CrashHandler_SetCallback = &IMPL::_CrashHandler_SetCallback;
		tbl->_CrashHandler_SetSecondaryCallback = &IMPL::_CrashHandler_SetSecondaryCallback;
		tbl->_CrashHandler_SetCrashDataDirectory = &IMPL::_CrashHandler_SetCrashDataDirectory;
		tbl->_CrashHandler_DisplayCrashDialog = &IMPL::_CrashHandler_DisplayCrashDialog;
		tbl->_CrashHandler_ResolveBugReport = &IMPL::_CrashHandler_ResolveBugReport;
		tbl->_CrashHandler_ObservableCrashDataDirectory = &IMPL::_CrashHandler_ObservableCrashDataDirectory;
	}
};

template <typename C> class CrashHandler::Wrapper
{
public:
	static Bool _CrashHandler_SetCallback(CallbackPtr callback) { return C::SetCallback(std::forward<CallbackPtr>(callback)); }
	static Bool _CrashHandler_SetSecondaryCallback(CallbackPtr callback) { return C::SetSecondaryCallback(std::forward<CallbackPtr>(callback)); }
	static Result<void> _CrashHandler_SetCrashDataDirectory(const Url& dataDirectory) { return C::SetCrashDataDirectory(dataDirectory); }
	static void _CrashHandler_DisplayCrashDialog(const String& title, const String& message) { return C::DisplayCrashDialog(title, message); }
	static Result<void> _CrashHandler_ResolveBugReport(const Url& report, const Url& symbolFileArchives, const Url& temporaryDir) { return C::ResolveBugReport(report, symbolFileArchives, temporaryDir); }
	static maxon::ObservableRef<ObservableCrashDataDirectoryDelegate> _CrashHandler_ObservableCrashDataDirectory() { return C::ObservableCrashDataDirectory(); }
};

MAXON_ATTRIBUTE_FORCE_INLINE auto CrashHandler::SetCallback(CallbackPtr callback) -> Bool
{
	return MTable::_instance._CrashHandler_SetCallback(std::forward<CallbackPtr>(callback));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CrashHandler::SetSecondaryCallback(CallbackPtr callback) -> Bool
{
	return MTable::_instance._CrashHandler_SetSecondaryCallback(std::forward<CallbackPtr>(callback));
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CrashHandler::SetCrashDataDirectory(const Url& dataDirectory) -> Result<void>
{
	return MTable::_instance._CrashHandler_SetCrashDataDirectory(dataDirectory);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CrashHandler::DisplayCrashDialog(const String& title, const String& message) -> void
{
	return MTable::_instance._CrashHandler_DisplayCrashDialog(title, message);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CrashHandler::ResolveBugReport(const Url& report, const Url& symbolFileArchives, const Url& temporaryDir) -> Result<void>
{
	return MTable::_instance._CrashHandler_ResolveBugReport(report, symbolFileArchives, temporaryDir);
}
MAXON_ATTRIBUTE_FORCE_INLINE auto CrashHandler::ObservableCrashDataDirectory() -> maxon::ObservableRef<ObservableCrashDataDirectoryDelegate>
{
	return MTable::_instance._CrashHandler_ObservableCrashDataDirectory();
}

#if defined(MAXON_DEPENDENCY_ENABLE) && !defined(PRIVATE_MAXON_REGISTRATION_UNIT)
static maxon::EntityUse s_ui_maxon_CrashHandler(CrashHandler::_interface.GetReference(), &maxon::g_translationUnit, "maxon/crashhandler.h", false);
#endif
#endif

#ifdef MAXON_COMPILER_GCC
	#pragma GCC diagnostic pop
#endif

#endif

