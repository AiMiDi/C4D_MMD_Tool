#if 1
namespace maxon
{
	namespace enum18
	{
		enum class VMSETTINGS
		{
			MOVE_ERRORS_TO_RESULT,
			USE_AUTO_GIL
		} ;
		static const maxon::UInt64 VMSETTINGS_values[] = {maxon::UInt64(enum18::VMSETTINGS::MOVE_ERRORS_TO_RESULT), maxon::UInt64(enum18::VMSETTINGS::USE_AUTO_GIL)};
		static const maxon::EnumInfo VMSETTINGS_info{"VMSETTINGS", SIZEOF(VMSETTINGS), true, "MOVE_ERRORS_TO_RESULT\0USE_AUTO_GIL\0", VMSETTINGS_values, std::extent<decltype(VMSETTINGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_VMSETTINGS18(){ return enum18::VMSETTINGS_info; }
	namespace enum28
	{
		enum class VMINITSETTINGS
		{
			CPYTHON_ADDITIONAL_SYS_PATH,				///< maxon::Url
			CPYTHON_INTERPRETERFLAGS,						///< py::PYTHONFLAG
			CPYTHON_SUBINTERPRETER,							///< Bool
		
			PYPY_EXECUTABLE											///< Private.
		} ;
		static const maxon::UInt64 VMINITSETTINGS_values[] = {maxon::UInt64(enum28::VMINITSETTINGS::CPYTHON_ADDITIONAL_SYS_PATH), maxon::UInt64(enum28::VMINITSETTINGS::CPYTHON_INTERPRETERFLAGS), maxon::UInt64(enum28::VMINITSETTINGS::CPYTHON_SUBINTERPRETER), maxon::UInt64(enum28::VMINITSETTINGS::PYPY_EXECUTABLE)};
		static const maxon::EnumInfo VMINITSETTINGS_info{"VMINITSETTINGS", SIZEOF(VMINITSETTINGS), false, "CPYTHON_ADDITIONAL_SYS_PATH\0CPYTHON_INTERPRETERFLAGS\0CPYTHON_SUBINTERPRETER\0PYPY_EXECUTABLE\0", VMINITSETTINGS_values, std::extent<decltype(VMINITSETTINGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_VMINITSETTINGS28(){ return enum28::VMINITSETTINGS_info; }
	namespace enum35
	{
		enum class ERRORHANDLING
		{
			PRINT,                  ///<  Any thrown exception will be handled internally
			CLEAR,                  ///<  Any thrown exception will be cleared automatically
			REDIRECT								///<  Any thrown exception will result in a corresponding maxon.Error. The internal error state of the virtual machine is untouched.
		} ;
		static const maxon::UInt64 ERRORHANDLING_values[] = {maxon::UInt64(enum35::ERRORHANDLING::PRINT), maxon::UInt64(enum35::ERRORHANDLING::CLEAR), maxon::UInt64(enum35::ERRORHANDLING::REDIRECT)};
		static const maxon::EnumInfo ERRORHANDLING_info{"ERRORHANDLING", SIZEOF(ERRORHANDLING), false, "PRINT\0CLEAR\0REDIRECT\0", ERRORHANDLING_values, std::extent<decltype(ERRORHANDLING_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_ERRORHANDLING35(){ return enum35::ERRORHANDLING_info; }
	namespace enum92
	{
		enum class DEFAULTRUNTIME
		{
			NONE,
		// #ifdef MAXON_TARGET_WINDOWS
			DEBUG_3_VS2015, // For Windows Only
			RELEASE_3_VS2015, // For Windows Only
		// #else
			DEBUG_3,
			RELEASE_3,
		// #endif
		
			DEFAULT_3, // auto detect of debug (and vs version on win)
		
			DEFAULT
		} ;
		static const maxon::UInt64 DEFAULTRUNTIME_values[] = {maxon::UInt64(enum92::DEFAULTRUNTIME::NONE), maxon::UInt64(enum92::DEFAULTRUNTIME::DEBUG_3_VS2015), maxon::UInt64(enum92::DEFAULTRUNTIME::RELEASE_3_VS2015), maxon::UInt64(enum92::DEFAULTRUNTIME::DEBUG_3), maxon::UInt64(enum92::DEFAULTRUNTIME::RELEASE_3), maxon::UInt64(enum92::DEFAULTRUNTIME::DEFAULT_3), maxon::UInt64(enum92::DEFAULTRUNTIME::DEFAULT)};
		static const maxon::EnumInfo DEFAULTRUNTIME_info{"DEFAULTRUNTIME", SIZEOF(DEFAULTRUNTIME), false, "NONE\0DEBUG_3_VS2015\0RELEASE_3_VS2015\0DEBUG_3\0RELEASE_3\0DEFAULT_3\0DEFAULT\0", DEFAULTRUNTIME_values, std::extent<decltype(DEFAULTRUNTIME_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_DEFAULTRUNTIME92(){ return enum92::DEFAULTRUNTIME_info; }
#ifdef MAXON_TARGET_WINDOWS
#endif
	MAXON_WARNING_PUSH
	MAXON_WARNING_DISABLE_DEPRECATED
	class LibraryInterface::Hxx2::Unresolved : public LibraryInterface
	{
	public:
		static Bool ConsoleIsAvailable() { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, true)) return LibraryInterface::ConsoleIsAvailable(); return maxon::PrivateLogNullptrError(false);}
#ifdef MAXON_TARGET_WINDOWS
		static Result<Int32> GetVsVersion(Int32 compilerVersion) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return LibraryInterface::GetVsVersion(compilerVersion); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<Url> GetVsRuntimeLibrary(Int32 version, Bool release) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return LibraryInterface::GetVsRuntimeLibrary(version, release); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
#endif
		static Result<String> GetFileContent(const Url& filepath) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return LibraryInterface::GetFileContent(filepath); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		static Result<void> SetFileContent(const Url& filepath, const String& str, Bool append) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return LibraryInterface::SetFileContent(filepath, str, append); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
	};
	MAXON_WARNING_POP
#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
	const maxon::NULL_RETURN_TYPE LibraryInterface::Hxx2::StaticMTable::_returnTypes[] = 
	{
		maxon::details::NullReturnType<Bool>::value,
#ifdef MAXON_TARGET_WINDOWS
		maxon::details::NullReturnType<Result<Int32>>::value,
		maxon::details::NullReturnType<Result<Url>>::value,
#endif
		maxon::details::NullReturnType<Result<String>>::value,
		maxon::details::NullReturnType<Result<void>>::value,
		maxon::NULL_RETURN_TYPE::OTHER
	};
#endif
	maxon::Bool LibraryInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
	{
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		#else
		tbl->LibraryInterface_ConsoleIsAvailable = PRIVATE_MAXON_MF_CAST(decltype(LibraryInterface_ConsoleIsAvailable), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::LibraryInterface_ConsoleIsAvailable);
		#endif
#ifdef MAXON_TARGET_WINDOWS
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int32>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->LibraryInterface_GetVsVersion = PRIVATE_MAXON_MF_CAST(decltype(LibraryInterface_GetVsVersion), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::LibraryInterface_GetVsVersion);
		#else
		tbl->LibraryInterface_GetVsVersion = PRIVATE_MAXON_MF_CAST(decltype(LibraryInterface_GetVsVersion), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::LibraryInterface_GetVsVersion);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Url>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->LibraryInterface_GetVsRuntimeLibrary = PRIVATE_MAXON_MF_CAST(decltype(LibraryInterface_GetVsRuntimeLibrary), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::LibraryInterface_GetVsRuntimeLibrary);
		#else
		tbl->LibraryInterface_GetVsRuntimeLibrary = PRIVATE_MAXON_MF_CAST(decltype(LibraryInterface_GetVsRuntimeLibrary), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::LibraryInterface_GetVsRuntimeLibrary);
		#endif
#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<String>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->LibraryInterface_GetFileContent = PRIVATE_MAXON_MF_CAST(decltype(LibraryInterface_GetFileContent), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::LibraryInterface_GetFileContent);
		#else
		tbl->LibraryInterface_GetFileContent = PRIVATE_MAXON_MF_CAST(decltype(LibraryInterface_GetFileContent), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::LibraryInterface_GetFileContent);
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->LibraryInterface_SetFileContent = PRIVATE_MAXON_MF_CAST(decltype(LibraryInterface_SetFileContent), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::LibraryInterface_SetFileContent);
		#else
		tbl->LibraryInterface_SetFileContent = PRIVATE_MAXON_MF_CAST(decltype(LibraryInterface_SetFileContent), &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::LibraryInterface_SetFileContent);
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const LibraryInterface::MTable::_ids = 
	"";
	const maxon::METHOD_FLAGS LibraryInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
#ifdef MAXON_TARGET_WINDOWS
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
#endif
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(LibraryInterface, , "net.maxon.python.interface.library", "maxon.LibraryInterface", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const LibraryInterface::Hxx2::StaticMTable::_ids = 
		"ConsoleIsAvailable@12e73654ffd67c7b\0" // Bool ConsoleIsAvailable()
#ifdef MAXON_TARGET_WINDOWS
		"GetVsVersion@bf4e692773a5abfe\0" // Result<Int32> GetVsVersion(Int32 compilerVersion)
		"GetVsRuntimeLibrary@baf7d83ec78776ab\0" // Result<Url> GetVsRuntimeLibrary(Int32 version, Bool release)
#endif
		"GetFileContent@10f6c2ab5771f32f\0" // Result<String> GetFileContent(const Url& filepath)
		"SetFileContent@586f08b73b2e429a\0" // Result<void> SetFileContent(const Url& filepath, const String& str, Bool append)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(LibraryInterface, , "net.maxon.python.interface.library");
#ifdef MAXON_COMPILER_GCC
#endif
#ifdef MAXON_COMPILER_GCC
#endif
	const maxon::Char* const VmDebuggerConnectionInterface::MTable::_ids = 
		"GetName@b8f12dfa16054f01\0" // String GetName() const
		"GetPath@f0cc56ca89511da7\0" // Url GetPath() const
#ifdef MAXON_COMPILER_GCC
#endif
		"GetStartupScript@b8f12dfa16054f01\0" // String GetStartupScript() const
		"GetShutdownScript@b8f12dfa16054f01\0" // String GetShutdownScript() const
#ifdef MAXON_COMPILER_GCC
#endif
	"";
	const maxon::METHOD_FLAGS VmDebuggerConnectionInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
#ifdef MAXON_COMPILER_GCC
#endif
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
#ifdef MAXON_COMPILER_GCC
#endif
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(VmDebuggerConnectionInterface, , "net.maxon.python.interface.vmdebuggerconnection", "maxon.VmDebuggerConnectionInterface", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int VmDebuggerConnectionInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<Url>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const VirtualMachineScopeInterface::MTable::_ids = 
		"Init@33c21a3984713302\0" // Result<void> Init(const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug)
		"Add@a42ea2e61d4d0790\0" // Result<void> Add(const String& name, const Data& data)
		"Get@95dfd3c119bde3d7\0" // Result<Data> Get(const String& name)
		"Execute@3008090429c5a175\0" // Result<void> Execute()
		"PrivateInvoke@2ce9c8d81e2aeaa6\0" // Result<Data*> PrivateInvoke(const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments)
		"ErrorHandling@3008090429c5a175\0" // Result<void> ErrorHandling()
		"_PrivateInit@349a95e33540013a\0" // Result<void> _PrivateInit(const LibraryRef& lib)
	"";
	const maxon::METHOD_FLAGS VirtualMachineScopeInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(VirtualMachineScopeInterface, , "net.maxon.python.interface.virtualmachinescope", "maxon.VirtualMachineScopeInterface", (ObjectInterface::PrivateGetInterface()));
	const maxon::Char* const VirtualMachineInterface::MTable::_ids = 
		"Init@5d83c6766c831e0b\0" // Result<void> Init(const LoadRuntime& runtimeInfo, const DataDictionary& settings)
		"Free@780cdac8f1a33934\0" // void Free()
		"CreateScope@e6ff457e798b2072\0" // Result<VirtualMachineScopeRef> CreateScope()
		"GetName@19ba073917cf19a1\0" // String GetName()
		"GetVersion@19ba073917cf19a1\0" // String GetVersion()
		"GetCopyright@19ba073917cf19a1\0" // String GetCopyright()
		"GetCompiler@19ba073917cf19a1\0" // String GetCompiler()
		"GetBuildInfo@19ba073917cf19a1\0" // String GetBuildInfo()
		"EnterInteractiveMode@3008090429c5a175\0" // Result<void> EnterInteractiveMode()
		"Execute@d85d74e087a2f051\0" // Result<void> Execute(const String& code)
		"Execute@1db4eca46d9225b9\0" // Result<void> Execute(const Url& filepath)
		"ExecuteModule@d85d74e087a2f051\0" // Result<void> ExecuteModule(const String& name)
		"GetDocumentString@41b12d0ccbdde7d7\0" // Result<void> GetDocumentString(const String& code, DocStringMeta& meta)
		"GetLibraryRef@74e52140ff52250a\0" // LibraryRef GetLibraryRef()
		"GetAllAvailableVirtualMachineLibraries@3f5471c230107cf3\0" // Result<BaseArray<Runtime>> GetAllAvailableVirtualMachineLibraries() const
	"";
	const maxon::METHOD_FLAGS VirtualMachineInterface::MTable::_flags[] = 
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
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(VirtualMachineInterface, , "net.maxon.python.interface.virtualmachine", "maxon.VirtualMachineInterface", (ObjectInterface::PrivateGetInterface()));
	template <typename DUMMY> maxon::Int VirtualMachineInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<LibraryRef>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		;
	}
	MAXON_REGISTRY_REGISTER(VirtualMachines);
	namespace VirtualMachines
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CPython, , "net.maxon.python.virtualmachine.cpython");
	}
	MAXON_REGISTRY_REGISTER(VmDebuggerConnections);
	namespace VmDebuggerConnections
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DebugPy, , "net.maxon.python.vmdebuggerconnection.debugpy");
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Pydev, , "net.maxon.python.vmdebuggerconnection.pydev");
	}
	PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(CPythonScope, , "net.maxon.python.virtualmachine.scope");
	MAXON_REGISTRY_REGISTER(PythonVms);
}
#endif
static maxon::details::ForceEvaluation s_forceEval_vm(0
	| maxon::VmDebuggerConnectionInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::VirtualMachineInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
