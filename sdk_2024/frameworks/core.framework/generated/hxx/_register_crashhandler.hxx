#if 1
namespace maxon
{
	const maxon::Char* const CrashHandler::MTable::_ids = 
		"SetCallback@a827ef21bf832556\0" // Bool SetCallback(CallbackPtr callback)
		"SetSecondaryCallback@a827ef21bf832556\0" // Bool SetSecondaryCallback(CallbackPtr callback)
		"SetCrashDataDirectory@683e18fe1711316e\0" // Result<void> SetCrashDataDirectory(const Url& dataDirectory)
		"DisplayCrashDialog@e6c94f24e0b7c0c1\0" // void DisplayCrashDialog(const String& title, const String& message)
		"GetProcessModules@3dfdf1701fa19d33\0" // Result<void> GetProcessModules(WritableArrayInterface<CrashModuleEntry>& modules)
		"ResolveBugReport@2fcfab95932301fe\0" // Result<void> ResolveBugReport(const Url& report, const Url& symbolFileArchives, const Url& temporaryDir)
		"ObservableCrashDataDirectory@75fe4282becff6be\0" // maxon::ObservableRef<ObservableCrashDataDirectoryDelegate> ObservableCrashDataDirectory(Bool create)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class CrashHandler::Hxx2::Unresolved : public CrashHandler
	{
	public:
		static const Unresolved* Get(const CrashHandler* o) { return (const Unresolved*) o; }
		static Unresolved* Get(CrashHandler* o) { return (Unresolved*) o; }
		static Bool SetCallback(CallbackPtr callback) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CrashHandler::SetCallback(std::forward<CallbackPtr>(callback)); return maxon::PrivateLogNullptrError(false);}
		static Bool SetSecondaryCallback(CallbackPtr callback) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CrashHandler::SetSecondaryCallback(std::forward<CallbackPtr>(callback)); return maxon::PrivateLogNullptrError(false);}
		static Result<void> SetCrashDataDirectory(const Url& dataDirectory) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return CrashHandler::SetCrashDataDirectory(dataDirectory); return HXXRET1(UNRESOLVED);}
		static void DisplayCrashDialog(const String& title, const String& message) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CrashHandler::DisplayCrashDialog(title, message); return maxon::PrivateLogNullptrError();}
		static Result<void> GetProcessModules(WritableArrayInterface<CrashModuleEntry>& modules) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return CrashHandler::GetProcessModules(modules); return HXXRET1(UNRESOLVED);}
		static Result<void> ResolveBugReport(const Url& report, const Url& symbolFileArchives, const Url& temporaryDir) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return CrashHandler::ResolveBugReport(report, symbolFileArchives, temporaryDir); return HXXRET1(UNRESOLVED);}
		static maxon::ObservableRef<ObservableCrashDataDirectoryDelegate> ObservableCrashDataDirectory(Bool create) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return CrashHandler::ObservableCrashDataDirectory(create); return maxon::ObservableRef<ObservableCrashDataDirectoryDelegate>::DefaultValue();}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE CrashHandler::MTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<Bool>::value,
		maxon::details::UnresolvedReturnType<Bool>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<void>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableCrashDataDirectoryDelegate>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool CrashHandler::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CrashHandler_SetCallback = PRIVATE_MAXON_MF_CAST(decltype(CrashHandler_SetCallback), &Hxx2::Wrapper<Hxx2::Unresolved>::CrashHandler_SetCallback);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CrashHandler_SetSecondaryCallback = PRIVATE_MAXON_MF_CAST(decltype(CrashHandler_SetSecondaryCallback), &Hxx2::Wrapper<Hxx2::Unresolved>::CrashHandler_SetSecondaryCallback);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CrashHandler_SetCrashDataDirectory = PRIVATE_MAXON_MF_CAST(decltype(CrashHandler_SetCrashDataDirectory), &Hxx2::Wrapper<Hxx2::Unresolved>::CrashHandler_SetCrashDataDirectory);
		#else
		tbl->CrashHandler_SetCrashDataDirectory = PRIVATE_MAXON_MF_CAST(decltype(CrashHandler_SetCrashDataDirectory), &Hxx2::Wrapper<Hxx2::Unresolved>::CrashHandler_SetCrashDataDirectory);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->CrashHandler_DisplayCrashDialog = PRIVATE_MAXON_MF_CAST(decltype(CrashHandler_DisplayCrashDialog), &Hxx2::Wrapper<Hxx2::Unresolved>::CrashHandler_DisplayCrashDialog);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CrashHandler_GetProcessModules = PRIVATE_MAXON_MF_CAST(decltype(CrashHandler_GetProcessModules), &Hxx2::Wrapper<Hxx2::Unresolved>::CrashHandler_GetProcessModules);
		#else
		tbl->CrashHandler_GetProcessModules = PRIVATE_MAXON_MF_CAST(decltype(CrashHandler_GetProcessModules), &Hxx2::Wrapper<Hxx2::Unresolved>::CrashHandler_GetProcessModules);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CrashHandler_ResolveBugReport = PRIVATE_MAXON_MF_CAST(decltype(CrashHandler_ResolveBugReport), &Hxx2::Wrapper<Hxx2::Unresolved>::CrashHandler_ResolveBugReport);
		#else
		tbl->CrashHandler_ResolveBugReport = PRIVATE_MAXON_MF_CAST(decltype(CrashHandler_ResolveBugReport), &Hxx2::Wrapper<Hxx2::Unresolved>::CrashHandler_ResolveBugReport);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<maxon::ObservableRef<ObservableCrashDataDirectoryDelegate>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->CrashHandler_ObservableCrashDataDirectory = PRIVATE_MAXON_MF_CAST(decltype(CrashHandler_ObservableCrashDataDirectory), &Hxx2::Wrapper<Hxx2::Unresolved>::CrashHandler_ObservableCrashDataDirectory);
		#else
		tbl->CrashHandler_ObservableCrashDataDirectory = PRIVATE_MAXON_MF_CAST(decltype(CrashHandler_ObservableCrashDataDirectory), &Hxx2::Wrapper<Hxx2::Unresolved>::CrashHandler_ObservableCrashDataDirectory);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(CrashHandler, "net.maxon.interface.crashhandler", nullptr, maxon::EntityBase::FLAGS::NONE);
}
#endif
