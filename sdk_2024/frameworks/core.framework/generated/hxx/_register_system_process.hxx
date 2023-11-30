#if 1
namespace maxon
{
	namespace enum29
	{
		enum class EXECUTEPROGRAMFLAGS
		{
			NONE										= 0,
			CAPTURELOGFILE					= 1 << 1,		///< The standard output will be routed into a file.
			DONT_DELETE_LOGFILE			= 1 << 2,		///< The logfile will not be deleted at the end of the call.
			HIDE_APPLICATION				= 1 << 4,		///< Starts the application in hidden mode (e.g. suppresses the console window when running under windows).
		} ;
		static const maxon::UInt64 EXECUTEPROGRAMFLAGS_values[] = {maxon::UInt64(enum29::EXECUTEPROGRAMFLAGS::NONE), maxon::UInt64(enum29::EXECUTEPROGRAMFLAGS::CAPTURELOGFILE), maxon::UInt64(enum29::EXECUTEPROGRAMFLAGS::DONT_DELETE_LOGFILE), maxon::UInt64(enum29::EXECUTEPROGRAMFLAGS::HIDE_APPLICATION)};
		static const maxon::EnumInfo EXECUTEPROGRAMFLAGS_info{"EXECUTEPROGRAMFLAGS", SIZEOF(EXECUTEPROGRAMFLAGS), true, "NONE\0CAPTURELOGFILE\0DONT_DELETE_LOGFILE\0HIDE_APPLICATION\0", EXECUTEPROGRAMFLAGS_values, std::extent<decltype(EXECUTEPROGRAMFLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_EXECUTEPROGRAMFLAGS29(){ return enum29::EXECUTEPROGRAMFLAGS_info; }
	namespace enum47
	{
		enum class EXECUTEPROGRAMCALLBACK
		{
			STARTED,						///< Program started regular.
		
			RUNNING,						///< Program is running, this callback comes every second.
													///< return 0 to continue.
													///< return 'stop' to kill the running process.
		
			FINISHED,						///< Program finish.
			KILLED,							///< Program finish with signal kill.
		
			CLEANUP_OK,					///< Cleanup phase (succeeded case), here the logfile should be deleted!
			CLEANUP_FAILED,			///< Cleanup phase (failed case), here the logfile should be deleted!
		} ;
		static const maxon::UInt64 EXECUTEPROGRAMCALLBACK_values[] = {maxon::UInt64(enum47::EXECUTEPROGRAMCALLBACK::STARTED), maxon::UInt64(enum47::EXECUTEPROGRAMCALLBACK::RUNNING), maxon::UInt64(enum47::EXECUTEPROGRAMCALLBACK::FINISHED), maxon::UInt64(enum47::EXECUTEPROGRAMCALLBACK::KILLED), maxon::UInt64(enum47::EXECUTEPROGRAMCALLBACK::CLEANUP_OK), maxon::UInt64(enum47::EXECUTEPROGRAMCALLBACK::CLEANUP_FAILED)};
		static const maxon::EnumInfo EXECUTEPROGRAMCALLBACK_info{"EXECUTEPROGRAMCALLBACK", SIZEOF(EXECUTEPROGRAMCALLBACK), false, "STARTED\0RUNNING\0FINISHED\0KILLED\0CLEANUP_OK\0CLEANUP_FAILED\0", EXECUTEPROGRAMCALLBACK_values, std::extent<decltype(EXECUTEPROGRAMCALLBACK_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_EXECUTEPROGRAMCALLBACK47(){ return enum47::EXECUTEPROGRAMCALLBACK_info; }
	namespace enum56
	{
		enum class WAIT_PROCESS_RESULT
		{
			FINISHED,						///< Process has finished.
			RUNNING							///< Process is still running.
		} ;
		static const maxon::UInt64 WAIT_PROCESS_RESULT_values[] = {maxon::UInt64(enum56::WAIT_PROCESS_RESULT::FINISHED), maxon::UInt64(enum56::WAIT_PROCESS_RESULT::RUNNING)};
		static const maxon::EnumInfo WAIT_PROCESS_RESULT_info{"WAIT_PROCESS_RESULT", SIZEOF(WAIT_PROCESS_RESULT), false, "FINISHED\0RUNNING\0", WAIT_PROCESS_RESULT_values, std::extent<decltype(WAIT_PROCESS_RESULT_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_WAIT_PROCESS_RESULT56(){ return enum56::WAIT_PROCESS_RESULT_info; }
	const maxon::Char* const SystemProcessKilledErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS SystemProcessKilledErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(SystemProcessKilledErrorInterface, , "net.maxon.interface.systemprocesskillederror", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(SystemProcessKilledErrorObject, , "net.maxon.error.systemprocesskilled");
	const maxon::Char* const SystemProcessOperationErrorInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS SystemProcessOperationErrorInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(SystemProcessOperationErrorInterface, , "net.maxon.interface.systemprocessoperationerror", (ErrorInterface::PrivateGetInterface()));
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(SystemProcessOperationErrorObject, , "net.maxon.error.systemprocessoperation");
	const maxon::Char* const SystemProcessObjectInterface::MTable::_ids = 
		"StartProcess@3008090429c5a175\0" // Result<void> StartProcess()
		"KillProcess@3008090429c5a175\0" // Result<void> KillProcess()
		"GetExitCode@7d0e6f3d29c239e7\0" // Int GetExitCode() const
		"IsRunning@12e73654e6d65520\0" // Bool IsRunning() const
		"GetProcessId@90d1992f5ac44814\0" // UInt GetProcessId() const
		"GetProcessHandle@d3e5147a1ef7917a\0" // void* GetProcessHandle() const
		"GetProcessUrl@f0cc56ca89511da7\0" // Url GetProcessUrl() const
		"GetLogFile@f0cc56ca89511da7\0" // Url GetLogFile() const
		"GetUserData@d3e5147a1ef7917a\0" // void* GetUserData() const
		"GetLoadedDlls@5a77b521cace9388\0" // Result<void> GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) const
		"ObservableProcessFinished@81a2ebf672775888\0" // maxon::ObservableRef<ObservableProcessFinishedDelegate> ObservableProcessFinished(Bool create) const
	"";
	const maxon::METHOD_FLAGS SystemProcessObjectInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(SystemProcessObjectInterface, , "net.maxon.interface.systemprocessobject", (ObserverObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int SystemProcessObjectInterface::PrivateInstantiateDefaultValueHelper()
	{
		return 0
		| maxon::details::InstantiateDefaultReturnValue<Url>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const SystemProcessInterface::MTable::_ids = 
		"CreateProcess@8e0a01a11f26961c\0" // Result<SystemProcessObjectRef> CreateProcess(const Url& programPath, const ArrayInterface<String>& arguments, EXECUTEPROGRAMFLAGS flags, void* userData, const InOutputStreamRef& stdinPipe, const InOutputStreamRef& stdoutPipe, const InOutputStreamRef& stderrPipe)
		"StartProcessAndWait@357c0397ff2bd350\0" // Result<SystemProcessObjectRef> StartProcessAndWait(const Url& programPath, const ArrayInterface<String>& arguments, EXECUTEPROGRAMFLAGS flags, ExecuteProgramCallback callback, void* userData)
		"GetSystemProcesses@bc9de7c8bf4e68b8\0" // Result<void> GetSystemProcesses(const ValueReceiver<const SystemProcessObjectRef&>& processes)
		"GetCurrentProcessId@90d1992f43c423df\0" // UInt GetCurrentProcessId()
		"GetProcess@c831767ae359e066\0" // Result<SystemProcessObjectRef> GetProcess(UInt id)
		"WaitForProcess@4c8994bee52c7f83\0" // Result<WAIT_PROCESS_RESULT> WaitForProcess(const SystemProcessObjectRef& processRef, const TimeValue& timeout)
	"";
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class SystemProcessInterface::Hxx2::Unresolved : public SystemProcessInterface
	{
	public:
		static const Unresolved* Get(const SystemProcessInterface* o) { return (const Unresolved*) o; }
		static Unresolved* Get(SystemProcessInterface* o) { return (Unresolved*) o; }
		static Result<SystemProcessObjectRef> CreateProcess(const Url& programPath, const ArrayInterface<String>& arguments, EXECUTEPROGRAMFLAGS flags, void* userData, const InOutputStreamRef& stdinPipe, const InOutputStreamRef& stdoutPipe, const InOutputStreamRef& stderrPipe) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return SystemProcessInterface::CreateProcess(programPath, arguments, flags, userData, stdinPipe, stdoutPipe, stderrPipe); return HXXRET1(UNRESOLVED);}
		static Result<SystemProcessObjectRef> StartProcessAndWait(const Url& programPath, const ArrayInterface<String>& arguments, EXECUTEPROGRAMFLAGS flags, ExecuteProgramCallback callback, void* userData) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return SystemProcessInterface::StartProcessAndWait(programPath, arguments, flags, std::forward<ExecuteProgramCallback>(callback), userData); return HXXRET1(UNRESOLVED);}
		static Result<void> GetSystemProcesses(const ValueReceiver<const SystemProcessObjectRef&>& processes) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return SystemProcessInterface::GetSystemProcesses(processes); return HXXRET1(UNRESOLVED);}
		static UInt GetCurrentProcessId() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, true)) return SystemProcessInterface::GetCurrentProcessId(); return 0;}
		static Result<SystemProcessObjectRef> GetProcess(UInt id) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return SystemProcessInterface::GetProcess(id); return HXXRET1(UNRESOLVED);}
		static Result<WAIT_PROCESS_RESULT> WaitForProcess(const SystemProcessObjectRef& processRef, const TimeValue& timeout) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_interface, false)) return SystemProcessInterface::WaitForProcess(processRef, timeout); return HXXRET1(UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::UNRESOLVED_RETURN_TYPE SystemProcessInterface::MTable::_returnTypes[] = 
	{
		maxon::details::UnresolvedReturnType<Result<SystemProcessObjectRef>>::value,
		maxon::details::UnresolvedReturnType<Result<SystemProcessObjectRef>>::value,
		maxon::details::UnresolvedReturnType<Result<void>>::value,
		maxon::details::UnresolvedReturnType<UInt>::value,
		maxon::details::UnresolvedReturnType<Result<SystemProcessObjectRef>>::value,
		maxon::details::UnresolvedReturnType<Result<WAIT_PROCESS_RESULT>>::value,
		maxon::UNRESOLVED_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool SystemProcessInterface::MTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, MTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<SystemProcessObjectRef>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SystemProcessInterface_CreateProcess = PRIVATE_MAXON_MF_CAST(decltype(SystemProcessInterface_CreateProcess), &Hxx2::Wrapper<Hxx2::Unresolved>::SystemProcessInterface_CreateProcess);
		#else
		tbl->SystemProcessInterface_CreateProcess = PRIVATE_MAXON_MF_CAST(decltype(SystemProcessInterface_CreateProcess), &Hxx2::Wrapper<Hxx2::Unresolved>::SystemProcessInterface_CreateProcess);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<SystemProcessObjectRef>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SystemProcessInterface_StartProcessAndWait = PRIVATE_MAXON_MF_CAST(decltype(SystemProcessInterface_StartProcessAndWait), &Hxx2::Wrapper<Hxx2::Unresolved>::SystemProcessInterface_StartProcessAndWait);
		#else
		tbl->SystemProcessInterface_StartProcessAndWait = PRIVATE_MAXON_MF_CAST(decltype(SystemProcessInterface_StartProcessAndWait), &Hxx2::Wrapper<Hxx2::Unresolved>::SystemProcessInterface_StartProcessAndWait);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<void>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SystemProcessInterface_GetSystemProcesses = PRIVATE_MAXON_MF_CAST(decltype(SystemProcessInterface_GetSystemProcesses), &Hxx2::Wrapper<Hxx2::Unresolved>::SystemProcessInterface_GetSystemProcesses);
		#else
		tbl->SystemProcessInterface_GetSystemProcesses = PRIVATE_MAXON_MF_CAST(decltype(SystemProcessInterface_GetSystemProcesses), &Hxx2::Wrapper<Hxx2::Unresolved>::SystemProcessInterface_GetSystemProcesses);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->SystemProcessInterface_GetCurrentProcessId = PRIVATE_MAXON_MF_CAST(decltype(SystemProcessInterface_GetCurrentProcessId), &Hxx2::Wrapper<Hxx2::Unresolved>::SystemProcessInterface_GetCurrentProcessId);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<SystemProcessObjectRef>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SystemProcessInterface_GetProcess = PRIVATE_MAXON_MF_CAST(decltype(SystemProcessInterface_GetProcess), &Hxx2::Wrapper<Hxx2::Unresolved>::SystemProcessInterface_GetProcess);
		#else
		tbl->SystemProcessInterface_GetProcess = PRIVATE_MAXON_MF_CAST(decltype(SystemProcessInterface_GetProcess), &Hxx2::Wrapper<Hxx2::Unresolved>::SystemProcessInterface_GetProcess);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if constexpr (maxon::details::UnresolvedReturnType<Result<WAIT_PROCESS_RESULT>>::value == maxon::UNRESOLVED_RETURN_TYPE::OTHER) tbl->SystemProcessInterface_WaitForProcess = PRIVATE_MAXON_MF_CAST(decltype(SystemProcessInterface_WaitForProcess), &Hxx2::Wrapper<Hxx2::Unresolved>::SystemProcessInterface_WaitForProcess);
		#else
		tbl->SystemProcessInterface_WaitForProcess = PRIVATE_MAXON_MF_CAST(decltype(SystemProcessInterface_WaitForProcess), &Hxx2::Wrapper<Hxx2::Unresolved>::SystemProcessInterface_WaitForProcess);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_interface, (const void**) tbl, _returnTypes, SIZEOF(MTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	MAXON_INTERFACE_REGISTER(SystemProcessInterface, "net.maxon.interface.systemprocess", nullptr, maxon::EntityBase::FLAGS::NONE);
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(SystemProcessObjectClass, , "net.maxon.class.systemprocessobject");
}
#endif
static maxon::details::ForceEvaluation s_forceEval_system_process(0
	| maxon::SystemProcessObjectInterface::PrivateInstantiateDefaultValueHelper<maxon::Int>()
);
