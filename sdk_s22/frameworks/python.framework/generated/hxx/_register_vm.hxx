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
	namespace enum107 { enum class DEFAULTRUNTIME
	{
		NONE,
		SYSTEM_27,
		SYSTEM_36,
	
	// #ifdef MAXON_TARGET_WINDOWS
		DEBUG_27_VS2008, // For Windows Only
		DEBUG_27_VS2013, // For Windows Only
		DEBUG_27_VS2015, // For Windows Only
		DEBUG_36_VS2015, // For Windows Only
	
		RELEASE_27_VS2008, // For Windows Only
		RELEASE_27_VS2015, // For Windows Only
		RELEASE_36_VS2015, // For Windows Only
	// #else
		DEBUG_27,
		RELEASE_27,
	
		DEBUG_36,
		RELEASE_36,
	// #endif
	
		DEFAULT_27, // auto detect of debug (and vs version on win)
		DEFAULT_36, // auto detect of debug (and vs version on win)
	
		DEFAULT
	} ; }
	maxon::String PrivateToString_DEFAULTRUNTIME107(std::underlying_type<enum107::DEFAULTRUNTIME>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum107::DEFAULTRUNTIME::NONE, (maxon::UInt64) enum107::DEFAULTRUNTIME::SYSTEM_27, (maxon::UInt64) enum107::DEFAULTRUNTIME::SYSTEM_36, (maxon::UInt64) enum107::DEFAULTRUNTIME::DEBUG_27_VS2008, (maxon::UInt64) enum107::DEFAULTRUNTIME::DEBUG_27_VS2013, (maxon::UInt64) enum107::DEFAULTRUNTIME::DEBUG_27_VS2015, (maxon::UInt64) enum107::DEFAULTRUNTIME::DEBUG_36_VS2015, (maxon::UInt64) enum107::DEFAULTRUNTIME::RELEASE_27_VS2008, (maxon::UInt64) enum107::DEFAULTRUNTIME::RELEASE_27_VS2015, (maxon::UInt64) enum107::DEFAULTRUNTIME::RELEASE_36_VS2015, (maxon::UInt64) enum107::DEFAULTRUNTIME::DEBUG_27, (maxon::UInt64) enum107::DEFAULTRUNTIME::RELEASE_27, (maxon::UInt64) enum107::DEFAULTRUNTIME::DEBUG_36, (maxon::UInt64) enum107::DEFAULTRUNTIME::RELEASE_36, (maxon::UInt64) enum107::DEFAULTRUNTIME::DEFAULT_27, (maxon::UInt64) enum107::DEFAULTRUNTIME::DEFAULT_36, (maxon::UInt64) enum107::DEFAULTRUNTIME::DEFAULT};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DEFAULTRUNTIME", SIZEOF(x), false, values, "NONE\0SYSTEM_27\0SYSTEM_36\0DEBUG_27_VS2008\0DEBUG_27_VS2013\0DEBUG_27_VS2015\0DEBUG_36_VS2015\0RELEASE_27_VS2008\0RELEASE_27_VS2015\0RELEASE_36_VS2015\0DEBUG_27\0RELEASE_27\0DEBUG_36\0RELEASE_36\0DEFAULT_27\0DEFAULT_36\0DEFAULT\0", fmt);
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
		tbl->_LibraryInterface_ConsoleIsAvailable = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_ConsoleIsAvailable;
		#endif
#ifdef MAXON_TARGET_WINDOWS
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Int32>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LibraryInterface_GetVsVersion = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_GetVsVersion;
		#else
		tbl->_LibraryInterface_GetVsVersion = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_GetVsVersion;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<Url>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LibraryInterface_GetVsRuntimeLibrary = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_GetVsRuntimeLibrary;
		#else
		tbl->_LibraryInterface_GetVsRuntimeLibrary = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_GetVsRuntimeLibrary;
		#endif
#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<String>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LibraryInterface_GetFileContent = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_GetFileContent;
		#else
		tbl->_LibraryInterface_GetFileContent = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_GetFileContent;
		#endif
		#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
		if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_LibraryInterface_SetFileContent = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_SetFileContent;
		#else
		tbl->_LibraryInterface_SetFileContent = &Hxx2::Wrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_LibraryInterface_SetFileContent;
		#endif
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
	#else
		return true;
	#endif
	}
	const maxon::Char* const LibraryInterface::MTable::_ids = 
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(LibraryInterface, , "net.maxon.python.interface.library", "maxon.LibraryInterface", (&ObjectInterface::_interface));
	const maxon::Char* const LibraryInterface::Hxx2::StaticMTable::_ids = 
		"ConsoleIsAvailable@76f018ea\0" // Bool ConsoleIsAvailable()
#ifdef MAXON_TARGET_WINDOWS
		"GetVsVersion@4ab7737ca255be89\0" // Result<Int32> GetVsVersion(Int32 compilerVersion)
		"GetVsRuntimeLibrary@80922f7e0f5fc186\0" // Result<Url> GetVsRuntimeLibrary(Int32 version, Bool release)
#endif
		"GetFileContent@b937b69a2db49bfa\0" // Result<String> GetFileContent(const Url& filepath)
		"SetFileContent@6bea4caeae2df245\0" // Result<void> SetFileContent(const Url& filepath, const String& str, Bool append)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(LibraryInterface, , "net.maxon.python.interface.library");
#ifdef MAXON_COMPILER_GCC
#endif
#ifdef MAXON_COMPILER_GCC
#endif
	const maxon::Char* const VmDebuggerConnectionInterface::MTable::_ids = 
		"GetName@22c6ed80868\0" // String GetName() const
		"GetPath@4e33a06\0" // Url GetPath() const
#ifdef MAXON_COMPILER_GCC
#endif
		"GetStartupScript@22c6ed80868\0" // String GetStartupScript() const
		"GetShutdownScript@22c6ed80868\0" // String GetShutdownScript() const
#ifdef MAXON_COMPILER_GCC
#endif
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(VmDebuggerConnectionInterface, , "net.maxon.python.interface.vmdebuggerconnection", "maxon.VmDebuggerConnectionInterface", (&ObjectInterface::_interface));
	template <typename DUMMY> maxon::Int VmDebuggerConnectionInterface::PrivateInstantiateNullValueHelper()
	{
		return 0
		| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
		| maxon::details::InstantiateNullReturnValue<Url>(OVERLOAD_MAX_RANK)
		;
	}
	const maxon::Char* const VirtualMachineScopeInterface::MTable::_ids = 
		"Init@67f0a760e85fd849\0" // Result<void> Init(const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug)
		"Add@81dccc7fcbd1e3b3\0" // Result<void> Add(const String& name, const Data& data)
		"Get@459990c5ca1a07ca\0" // Result<Data> Get(const String& name)
		"Execute@a54f4799cbe1a498\0" // Result<void> Execute()
		"PrivateInvoke@16151c54e3d77215\0" // Result<Data*> PrivateInvoke(const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments)
		"ErrorHandling@a54f4799cbe1a498\0" // Result<void> ErrorHandling()
		"_PrivateInit@f8566cbbd937ca59\0" // Result<void> _PrivateInit(const LibraryRef& lib)
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(VirtualMachineScopeInterface, , "net.maxon.python.interface.virtualmachinescope", "maxon.VirtualMachineScopeInterface", (&ObjectInterface::_interface));
	const maxon::Char* const VirtualMachineInterface::MTable::_ids = 
		"Init@39ba9727201812a6\0" // Result<void> Init(const LoadRuntime& runtimeInfo, const DataDictionary& settings)
		"Free@6b2e10f\0" // void Free()
		"CreateScope@212416228933c41f\0" // Result<VirtualMachineScopeRef> CreateScope()
		"GetName@11f30f3a12\0" // String GetName()
		"GetVersion@11f30f3a12\0" // String GetVersion()
		"GetCopyright@11f30f3a12\0" // String GetCopyright()
		"GetCompiler@11f30f3a12\0" // String GetCompiler()
		"GetBuildInfo@11f30f3a12\0" // String GetBuildInfo()
		"EnterInteractiveMode@a54f4799cbe1a498\0" // Result<void> EnterInteractiveMode()
		"Execute@84c7b902e2c48cc0\0" // Result<void> Execute(const String& code)
		"Execute@e1e93c17010d01ec\0" // Result<void> Execute(const Url& filepath)
		"ExecuteModule@84c7b902e2c48cc0\0" // Result<void> ExecuteModule(const String& name)
		"GetDocumentString@30a6d5c08cfa5764\0" // Result<void> GetDocumentString(const String& code, DocStringMeta& meta)
		"GetLibraryRef@e779df3f11c52b\0" // LibraryRef GetLibraryRef()
		"GetAllAvailableVirtualMachineLibraries@5c7211360ab939dc\0" // Result<BaseArray<Runtime>> GetAllAvailableVirtualMachineLibraries() const
	"";
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(VirtualMachineInterface, , "net.maxon.python.interface.virtualmachine", "maxon.VirtualMachineInterface", (&ObjectInterface::_interface));
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
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(PyPy, , "net.maxon.python.virtualmachine.pypy");
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
