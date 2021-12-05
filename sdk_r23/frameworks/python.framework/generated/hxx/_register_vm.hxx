#if 1
namespace maxon
{
	namespace enum20 { enum class VMSETTINGS
	{
		MOVE_ERRORS_TO_RESULT,
		USE_AUTO_GIL
	} ; }
	maxon::String PrivateToString_VMSETTINGS20(std::underlying_type<enum20::VMSETTINGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum20::VMSETTINGS::MOVE_ERRORS_TO_RESULT, (maxon::UInt64) enum20::VMSETTINGS::USE_AUTO_GIL};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "VMSETTINGS", SIZEOF(x), true, values, "MOVE_ERRORS_TO_RESULT\0USE_AUTO_GIL\0", fmt);
	}
	namespace enum30 { enum class VMINITSETTINGS
	{
		CPYTHON_ADDITIONAL_SYS_PATH,				///< maxon::Url
		CPYTHON_INTERPRETERFLAGS,						///< py::PYTHONFLAG
		CPYTHON_SUBINTERPRETER,							///< Bool
	
		PYPY_EXECUTABLE											///< Private.
	} ; }
	maxon::String PrivateToString_VMINITSETTINGS30(std::underlying_type<enum30::VMINITSETTINGS>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum30::VMINITSETTINGS::CPYTHON_ADDITIONAL_SYS_PATH, (maxon::UInt64) enum30::VMINITSETTINGS::CPYTHON_INTERPRETERFLAGS, (maxon::UInt64) enum30::VMINITSETTINGS::CPYTHON_SUBINTERPRETER, (maxon::UInt64) enum30::VMINITSETTINGS::PYPY_EXECUTABLE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "VMINITSETTINGS", SIZEOF(x), false, values, "CPYTHON_ADDITIONAL_SYS_PATH\0CPYTHON_INTERPRETERFLAGS\0CPYTHON_SUBINTERPRETER\0PYPY_EXECUTABLE\0", fmt);
	}
	namespace enum37 { enum class ERRORHANDLING
	{
		PRINT,                  ///<  Any thrown exception will be handled internally
		CLEAR,                  ///<  Any thrown exception will be cleared automatically
		REDIRECT								///<  Any thrown exception will result in a corresponding maxon.Error. The internal error state of the virtual machine is untouched.
	} ; }
	maxon::String PrivateToString_ERRORHANDLING37(std::underlying_type<enum37::ERRORHANDLING>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum37::ERRORHANDLING::PRINT, (maxon::UInt64) enum37::ERRORHANDLING::CLEAR, (maxon::UInt64) enum37::ERRORHANDLING::REDIRECT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "ERRORHANDLING", SIZEOF(x), false, values, "PRINT\0CLEAR\0REDIRECT\0", fmt);
	}
	namespace enum94 { enum class DEFAULTRUNTIME
	{
		NONE,
	// #ifdef MAXON_TARGET_WINDOWS
		DEBUG_37_VS2015, // For Windows Only
		RELEASE_37_VS2015, // For Windows Only
	// #else
		DEBUG_37,
		RELEASE_37,
	// #endif
	
		DEFAULT_37, // auto detect of debug (and vs version on win)
	
		DEFAULT
	} ; }
	maxon::String PrivateToString_DEFAULTRUNTIME94(std::underlying_type<enum94::DEFAULTRUNTIME>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum94::DEFAULTRUNTIME::NONE, (maxon::UInt64) enum94::DEFAULTRUNTIME::DEBUG_37_VS2015, (maxon::UInt64) enum94::DEFAULTRUNTIME::RELEASE_37_VS2015, (maxon::UInt64) enum94::DEFAULTRUNTIME::DEBUG_37, (maxon::UInt64) enum94::DEFAULTRUNTIME::RELEASE_37, (maxon::UInt64) enum94::DEFAULTRUNTIME::DEFAULT_37, (maxon::UInt64) enum94::DEFAULTRUNTIME::DEFAULT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DEFAULTRUNTIME", SIZEOF(x), false, values, "NONE\0DEBUG_37_VS2015\0RELEASE_37_VS2015\0DEBUG_37\0RELEASE_37\0DEFAULT_37\0DEFAULT\0", fmt);
	}
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
		tbl->_LibraryInterface_ConsoleIsAvailable = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_ConsoleIsAvailable;
		#endif
#ifdef MAXON_TARGET_WINDOWS
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int32>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LibraryInterface_GetVsVersion = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_GetVsVersion;
		#else
		tbl->_LibraryInterface_GetVsVersion = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_GetVsVersion;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Url>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LibraryInterface_GetVsRuntimeLibrary = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_GetVsRuntimeLibrary;
		#else
		tbl->_LibraryInterface_GetVsRuntimeLibrary = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_GetVsRuntimeLibrary;
		#endif
#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<String>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LibraryInterface_GetFileContent = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_GetFileContent;
		#else
		tbl->_LibraryInterface_GetFileContent = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_GetFileContent;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LibraryInterface_SetFileContent = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_SetFileContent;
		#else
		tbl->_LibraryInterface_SetFileContent = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_SetFileContent;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const LibraryInterface::MTable::_ids = 
	"";
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
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Ptvs, , "net.maxon.python.vmdebuggerconnection.ptvs");
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
