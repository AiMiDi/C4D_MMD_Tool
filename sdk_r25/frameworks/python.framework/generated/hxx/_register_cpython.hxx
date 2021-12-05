#if 1
namespace maxon
{
	namespace enum33
	{
		enum class PyStringEncodings
		{
		  Utf8,
		  Utf16,
		  Utf32,
		  PyDecode
		} ;
		static const maxon::UInt64 PyStringEncodings_values[] = {maxon::UInt64(enum33::PyStringEncodings::Utf8), maxon::UInt64(enum33::PyStringEncodings::Utf16), maxon::UInt64(enum33::PyStringEncodings::Utf32), maxon::UInt64(enum33::PyStringEncodings::PyDecode)};
		static const maxon::EnumInfo PyStringEncodings_info{"PyStringEncodings", SIZEOF(PyStringEncodings), false, "Utf8\0Utf16\0Utf32\0PyDecode\0", PyStringEncodings_values, std::extent<decltype(PyStringEncodings_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_PyStringEncodings33(){ return enum33::PyStringEncodings_info; }
	namespace enum48
	{
		enum class OWNERSHIP
		{
			NORMAL = 1,			/// Default ownership
			CALLER = 2,			/// Caller owns the object
			CALLEE = 3,			/// Callee owns the object
			CALLER_BUT_COPY = 4,/// Callee owns the object but needs a copy
		} ;
		static const maxon::UInt64 OWNERSHIP_values[] = {maxon::UInt64(enum48::OWNERSHIP::NORMAL), maxon::UInt64(enum48::OWNERSHIP::CALLER), maxon::UInt64(enum48::OWNERSHIP::CALLEE), maxon::UInt64(enum48::OWNERSHIP::CALLER_BUT_COPY)};
		static const maxon::EnumInfo OWNERSHIP_info{"OWNERSHIP", SIZEOF(OWNERSHIP), false, "NORMAL\0CALLER\0CALLEE\0CALLER_BUT_COPY\0", OWNERSHIP_values, std::extent<decltype(OWNERSHIP_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_OWNERSHIP48(){ return enum48::OWNERSHIP_info; }
	namespace py
	{
		namespace enum81
		{
			enum class PATHHANDLE
			{
				OVERWRITE,					/// Overwrite sys.path
				APPEND_AT_END,			/// Append array to sys.path
				INSERT_AT_BEGINNING	/// Insert array at sys.path[0]
			} ;
			static const maxon::UInt64 PATHHANDLE_values[] = {maxon::UInt64(enum81::PATHHANDLE::OVERWRITE), maxon::UInt64(enum81::PATHHANDLE::APPEND_AT_END), maxon::UInt64(enum81::PATHHANDLE::INSERT_AT_BEGINNING)};
			static const maxon::EnumInfo PATHHANDLE_info{"PATHHANDLE", SIZEOF(PATHHANDLE), false, "OVERWRITE\0APPEND_AT_END\0INSERT_AT_BEGINNING\0", PATHHANDLE_values, std::extent<decltype(PATHHANDLE_values)>::value};
		}
		const maxon::EnumInfo& PrivateGetEnumInfo_PATHHANDLE81(){ return enum81::PATHHANDLE_info; }
		namespace enum88
		{
			enum class GILSTATE
			{
				NOT_ACTIVE = 0,											/// GIL is not hold by any thread.
				ACTIVE_BUT_NOT_CURRENT_THREAD = 1,	/// GIL is hold by another thread.
				ACTIVE_AND_CURRENT_THREAD = 2				/// GIL is hold by the current thread
			} ;
			static const maxon::UInt64 GILSTATE_values[] = {maxon::UInt64(enum88::GILSTATE::NOT_ACTIVE), maxon::UInt64(enum88::GILSTATE::ACTIVE_BUT_NOT_CURRENT_THREAD), maxon::UInt64(enum88::GILSTATE::ACTIVE_AND_CURRENT_THREAD)};
			static const maxon::EnumInfo GILSTATE_info{"GILSTATE", SIZEOF(GILSTATE), false, "NOT_ACTIVE\0ACTIVE_BUT_NOT_CURRENT_THREAD\0ACTIVE_AND_CURRENT_THREAD\0", GILSTATE_values, std::extent<decltype(GILSTATE_values)>::value};
		}
		const maxon::EnumInfo& PrivateGetEnumInfo_GILSTATE88(){ return enum88::GILSTATE_info; }
#ifdef MAXON_TARGET_WINDOWS
#endif
		namespace enum133
		{
			enum class CPyMemAllocatorDomain
			{
				CPYMEM_DOMAIN_RAW,
				CPYMEM_DOMAIN_MEM,
				CPYMEM_DOMAIN_OBJ
			} ;
			static const maxon::UInt64 CPyMemAllocatorDomain_values[] = {maxon::UInt64(enum133::CPyMemAllocatorDomain::CPYMEM_DOMAIN_RAW), maxon::UInt64(enum133::CPyMemAllocatorDomain::CPYMEM_DOMAIN_MEM), maxon::UInt64(enum133::CPyMemAllocatorDomain::CPYMEM_DOMAIN_OBJ)};
			static const maxon::EnumInfo CPyMemAllocatorDomain_info{"CPyMemAllocatorDomain", SIZEOF(CPyMemAllocatorDomain), false, "CPYMEM_DOMAIN_RAW\0CPYMEM_DOMAIN_MEM\0CPYMEM_DOMAIN_OBJ\0", CPyMemAllocatorDomain_values, std::extent<decltype(CPyMemAllocatorDomain_values)>::value};
		}
		const maxon::EnumInfo& PrivateGetEnumInfo_CPyMemAllocatorDomain133(){ return enum133::CPyMemAllocatorDomain_info; }
		namespace enum156
		{
			enum class SPECIALPATH
			{
				MAXON_MODULES,												/// Path to the 'maxon' module.
				PREFS_PYTHON_GENERATED_DIRECTORY,			/// Path to the 'generated' directory.
				PREFS_PYTHON_GLOBAL_LIBS,							/// Path to the globals 'libs directory which all Cinema 4D instances share.
				PREFS_PYTHON_LOCAL_LIBS								/// Path to the local 'libs directory which only the current Cinema 4D instance uses.
			} ;
			static const maxon::UInt64 SPECIALPATH_values[] = {maxon::UInt64(enum156::SPECIALPATH::MAXON_MODULES), maxon::UInt64(enum156::SPECIALPATH::PREFS_PYTHON_GENERATED_DIRECTORY), maxon::UInt64(enum156::SPECIALPATH::PREFS_PYTHON_GLOBAL_LIBS), maxon::UInt64(enum156::SPECIALPATH::PREFS_PYTHON_LOCAL_LIBS)};
			static const maxon::EnumInfo SPECIALPATH_info{"SPECIALPATH", SIZEOF(SPECIALPATH), false, "MAXON_MODULES\0PREFS_PYTHON_GENERATED_DIRECTORY\0PREFS_PYTHON_GLOBAL_LIBS\0PREFS_PYTHON_LOCAL_LIBS\0", SPECIALPATH_values, std::extent<decltype(SPECIALPATH_values)>::value};
		}
		const maxon::EnumInfo& PrivateGetEnumInfo_SPECIALPATH156(){ return enum156::SPECIALPATH_info; }
		namespace enum162
		{
			enum class PYGILSTATE
			{
				LOCKED,				/// GIL is locked.
				UNLOCKED			/// GIL is unlocked.
			} ;
			static const maxon::UInt64 PYGILSTATE_values[] = {maxon::UInt64(enum162::PYGILSTATE::LOCKED), maxon::UInt64(enum162::PYGILSTATE::UNLOCKED)};
			static const maxon::EnumInfo PYGILSTATE_info{"PYGILSTATE", SIZEOF(PYGILSTATE), false, "LOCKED\0UNLOCKED\0", PYGILSTATE_values, std::extent<decltype(PYGILSTATE_values)>::value};
		}
		const maxon::EnumInfo& PrivateGetEnumInfo_PYGILSTATE162(){ return enum162::PYGILSTATE_info; }
		namespace enum169
		{
			enum class PYINPUT
			{
				SINGLE = 256,				/// The start symbol from the Python grammar for a single statement
				FILE = 257,					/// The start symbol from the Python grammar for sequences of statements as read from a file or other source
				EVAL = 258					/// The start symbol from the Python grammar for isolated expressions
			} ;
			static const maxon::UInt64 PYINPUT_values[] = {maxon::UInt64(enum169::PYINPUT::SINGLE), maxon::UInt64(enum169::PYINPUT::FILE), maxon::UInt64(enum169::PYINPUT::EVAL)};
			static const maxon::EnumInfo PYINPUT_info{"PYINPUT", SIZEOF(PYINPUT), false, "SINGLE\0FILE\0EVAL\0", PYINPUT_values, std::extent<decltype(PYINPUT_values)>::value};
		}
		const maxon::EnumInfo& PrivateGetEnumInfo_PYINPUT169(){ return enum169::PYINPUT_info; }
		namespace enum178
		{
			enum class PYSTARTOPERATION
			{
				NONE,
				EXECUTE_CODE, 	/// maxon::String
				EXECUTE_MODULE, /// maxon::String
				EXECUTE_FILE, 	/// maxon:Url
				VERSION					/// Version mode
			} ;
			static const maxon::UInt64 PYSTARTOPERATION_values[] = {maxon::UInt64(enum178::PYSTARTOPERATION::NONE), maxon::UInt64(enum178::PYSTARTOPERATION::EXECUTE_CODE), maxon::UInt64(enum178::PYSTARTOPERATION::EXECUTE_MODULE), maxon::UInt64(enum178::PYSTARTOPERATION::EXECUTE_FILE), maxon::UInt64(enum178::PYSTARTOPERATION::VERSION)};
			static const maxon::EnumInfo PYSTARTOPERATION_info{"PYSTARTOPERATION", SIZEOF(PYSTARTOPERATION), false, "NONE\0EXECUTE_CODE\0EXECUTE_MODULE\0EXECUTE_FILE\0VERSION\0", PYSTARTOPERATION_values, std::extent<decltype(PYSTARTOPERATION_values)>::value};
		}
		const maxon::EnumInfo& PrivateGetEnumInfo_PYSTARTOPERATION178(){ return enum178::PYSTARTOPERATION_info; }
		const maxon::Char* const PythonErrorInterface::MTable::_ids = 
		"";
		const maxon::METHOD_FLAGS PythonErrorInterface::MTable::_flags[] = 
		{
			maxon::METHOD_FLAGS::NONE
		};
		PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(PythonErrorInterface, , "net.maxon.python.interface.pythonerror", "maxon.py.PythonErrorInterface", (ErrorInterface::PrivateGetInterface()));
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(PythonErrorObject, , "net.maxon.python.error.python");
		const maxon::Char* const PythonTracebackErrorInterface::MTable::_ids = 
			"SetUrl@17f1a32c75c62168\0" // void SetUrl(const Url& url)
			"GetUrl@dd23129f046419ec\0" // const Url& GetUrl() const
			"SetLineNumber@1f5c923ad8089ced\0" // void SetLineNumber(Int line)
			"GetLineNumber@7d0e6f3d29c239e7\0" // Int GetLineNumber() const
		"";
		const maxon::METHOD_FLAGS PythonTracebackErrorInterface::MTable::_flags[] = 
		{
			maxon::METHOD_FLAGS::NONE,
			maxon::METHOD_FLAGS::NONE,
			maxon::METHOD_FLAGS::NONE,
			maxon::METHOD_FLAGS::NONE,
			maxon::METHOD_FLAGS::NONE
		};
		PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(PythonTracebackErrorInterface, , "net.maxon.python.interface.pythontracebackerror", "maxon.py.PythonTracebackErrorInterface", (ErrorInterface::PrivateGetInterface()));
		template <typename DUMMY> maxon::Int PythonTracebackErrorInterface::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<const Url&>(OVERLOAD_MAX_RANK)
			;
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(PythonTracebackErrorObject, , "net.maxon.python.error.pythontraceback");
		const maxon::Char* const PythonSystemExitErrorInterface::MTable::_ids = 
		"";
		const maxon::METHOD_FLAGS PythonSystemExitErrorInterface::MTable::_flags[] = 
		{
			maxon::METHOD_FLAGS::NONE
		};
		PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(PythonSystemExitErrorInterface, , "net.maxon.python.interface.pythonsystemerror", "maxon.py.PythonSystemExitErrorInterface", (ErrorInterface::PrivateGetInterface()));
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(PythonSystemExitErrorObject, , "net.maxon.python.error.pythonsystem");
		MAXON_WARNING_PUSH
		MAXON_WARNING_DISABLE_DEPRECATED
		class CPythonLibraryInterface::Hxx2::Unresolved : public CPythonLibraryInterface
		{
		public:
			static Result<PYSTARTOPERATION> ParseCommandLine(BaseArray<String>* args, Data* res, PYTHONFLAG* flags) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return CPythonLibraryInterface::ParseCommandLine(args, res, flags); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
			static Result<void> GetUrl(DEFAULTRUNTIME pythonPath, Url& pythonLibrary, Url& pythonHome) { if (maxon::NonvirtualInterfaceReference::PrivateResolve(&_staticInterface, false)) return CPythonLibraryInterface::GetUrl(pythonPath, pythonLibrary, pythonHome); return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::UNRESOLVED);}
		};
		MAXON_WARNING_POP
	#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
		const maxon::NULL_RETURN_TYPE CPythonLibraryInterface::Hxx2::StaticMTable::_returnTypes[] = 
		{
			maxon::details::NullReturnType<Result<PYSTARTOPERATION>>::value,
			maxon::details::NullReturnType<Result<void>>::value,
			maxon::NULL_RETURN_TYPE::OTHER
		};
	#endif
		maxon::Bool CPythonLibraryInterface::Hxx2::StaticMTable::InitUnresolved(maxon::NonvirtualInterfaceReference::UnresolvedAssembler assembler, Hxx2::StaticMTable* tbl)
		{
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<PYSTARTOPERATION>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CPythonLibraryInterface_ParseCommandLine = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_CPythonLibraryInterface_ParseCommandLine;
			#else
			tbl->_CPythonLibraryInterface_ParseCommandLine = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_CPythonLibraryInterface_ParseCommandLine;
			#endif
			#if defined(PRIVATE_MAXON_ASSEMBLE_UNRESOLVED) && !defined(MAXON_TARGET_DEBUG)
			if (maxon::details::NullReturnType<Result<void>>::value == maxon::NULL_RETURN_TYPE::OTHER) tbl->_CPythonLibraryInterface_GetUrl = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_CPythonLibraryInterface_GetUrl;
			#else
			tbl->_CPythonLibraryInterface_GetUrl = &Hxx2::CWrapper<maxon::StaticHelper<Hxx2::Unresolved>>::_CPythonLibraryInterface_GetUrl;
			#endif
		#ifdef PRIVATE_MAXON_ASSEMBLE_UNRESOLVED
			return assembler(&_staticInterface, (maxon::Char*) tbl, _returnTypes, SIZEOF(StaticMTable) / SIZEOF(void*));
		#else
			return true;
		#endif
		}
		const maxon::Char* const CPythonLibraryInterface::MTable::_ids = 
			"Init@369b63ce0651fbeb\0" // Result<void> Init(const Url& librarypath, Bool createSubLibrary)
			"InitTypes@3008090429c5a175\0" // Result<void> InitTypes()
			"InitBuiltinModules@3008090429c5a175\0" // Result<void> InitBuiltinModules()
			"CPy_Initialize@780cdac8f1a33934\0" // void CPy_Initialize()
			"CPy_Finalize@780cdac8f1a33934\0" // void CPy_Finalize()
			"CPyModule_Create@7e07817150b411a3\0" // CPyRef CPyModule_Create(const ModuleDefinition& module)
			"Free@438e4d58dd21cc2f\0" // void Free(const Delegate<void()>& shutdownEngine)
			"GetDll@4a8b669c66b0d7c1\0" // const PythonDll& GetDll() const
			"FopenNative@fdd4c6a70206a894\0" // FILE_native* FopenNative(const Char* name, const Char* mode)
			"LastPythonCallFailed@6860301832818636\0" // Error LastPythonCallFailed(const maxon::SourceLocation& allocLocation, Bool withTraceback, Bool restoreError)
			"RegisterComponentProxy@b9f071d95fd015bd\0" // Result<MPyDataRef> RegisterComponentProxy(const CPyRef& type, const Id& registryId, const ProxyDefinition& baseAndInterfaceIds, const Id& cid, Bool printErrors, ClassInterface::KIND kind, const SourceLocation& loc, Bool createObject, const DataType& dtOfObject)
			"CPy_IsInitialized@d7a8c99431e20a5a\0" // Bool CPy_IsInitialized()
			"CPy_GetVersion@ffb61f6b64d53ecf\0" // const Char* CPy_GetVersion()
			"CPy_GetPlatform@ffb61f6b64d53ecf\0" // const Char* CPy_GetPlatform()
			"CPy_GetCopyright@ffb61f6b64d53ecf\0" // const Char* CPy_GetCopyright()
			"CPy_GetCompiler@ffb61f6b64d53ecf\0" // const Char* CPy_GetCompiler()
			"CPy_GetBuildInfo@ffb61f6b64d53ecf\0" // const Char* CPy_GetBuildInfo()
			"CPy_SetProgramName@d85d74e087a2f051\0" // Result<void> CPy_SetProgramName(const String& name)
			"CPy_SetPythonHome@1db4eca46d9225b9\0" // Result<void> CPy_SetPythonHome(const Url& name)
			"CPy_GetProgramName@19ba073917cf19a1\0" // String CPy_GetProgramName()
			"CPy_GetPythonHome@19ba073917cf19a1\0" // String CPy_GetPythonHome()
			"ExecuteModule@6b86fdd7d5e4e8e0\0" // Bool ExecuteModule(const String& name)
			"CPyCallerContext_New@f7c9019b207e897d\0" // MPyCallerContextRef CPyCallerContext_New()
			"CPyRun_SimpleFileExFlags@683be26d6ed94875\0" // Bool CPyRun_SimpleFileExFlags(FILE_native* fp, const Char* filename, Int32 closeit, CPyCompilerFlags* flags)
			"CPyRun_SimpleFileExFlags@9691b0b7888b17be\0" // Bool CPyRun_SimpleFileExFlags(const Url& url, CPyCompilerFlags* flags)
			"CPyRun_SimpleStringFlags@74a6b4a853d9b60b\0" // CPyRef CPyRun_SimpleStringFlags(const String& code, CPyCompilerFlags* flags)
			"CPyRun_FileExFlags@6a2273446c5330de\0" // NativePyObject* CPyRun_FileExFlags(FILE_native* fp, const Char* filename, Int32 start, NativePyObject* globals, NativePyObject* locals, Int32 closeit, CPyCompilerFlags* flags)
			"CPyRun_InteractiveLoopFlags@7ec50ed0c4e804ce\0" // Result<void> CPyRun_InteractiveLoopFlags(FILE* fp, const Char* filename, CPyCompilerFlags* flags)
			"CPyGilState_Ensure@72bae04b7825d134\0" // PYGILSTATE CPyGilState_Ensure()
			"CPyGilState_Release@5a1147adff76f8be\0" // void CPyGilState_Release(PYGILSTATE state)
			"GetGilState@9dc58276663232fd\0" // GILSTATE GetGilState() const
			"CPyGILState_GetThisThreadState@6553e6bf9de5a971\0" // NativePyThreadState* CPyGILState_GetThisThreadState()
			"CPyThreadState_Swap@71d1a8ca2be0e4\0" // NativePyThreadState* CPyThreadState_Swap(NativePyThreadState* state)
			"CPyThreadState_GetDict@7e06838c6c7d5dbb\0" // CPyRef CPyThreadState_GetDict()
			"CPy_CompileStringFlags@b08b8fd696808f87\0" // CPyCodeRef CPy_CompileStringFlags(const Char* code, const Char* filename, PYINPUT start, CPyCompilerFlags* flags)
			"CPy_Incref@cfbd00f20b90f0cb\0" // void CPy_Incref(NativePyObject* o) const
			"CPy_Decref@cfbd00f20b90f0cb\0" // void CPy_Decref(NativePyObject* o) const
			"CPy_SafeIncref@cfbd00f20b90f0cb\0" // void CPy_SafeIncref(NativePyObject* o) const
			"CPy_SafeDecref@cfbd00f20b90f0cb\0" // void CPy_SafeDecref(NativePyObject* o) const
			"CPyGC_Collect@b7d343c1121f00e5\0" // Int64 CPyGC_Collect()
			"CPyCode_Addr2Line@e4893d7d1813e995\0" // Int32 CPyCode_Addr2Line(const CPyCodeRef& codeObject, Int32 x)
			"UnpackDataType@434bf72e179dba1\0" // CPyRef UnpackDataType(const CPyRef& obj)
			"UnpackData@434bf72e179dba1\0" // CPyRef UnpackData(const CPyRef& obj)
			"CPy_None@cae49f57be9cdf44\0" // CPyConstRef CPy_None() const
			"CPy_True@cae49f57be9cdf44\0" // CPyConstRef CPy_True() const
			"CPy_False@cae49f57be9cdf44\0" // CPyConstRef CPy_False() const
			"CPy_NotImplemented@cae49f57be9cdf44\0" // CPyConstRef CPy_NotImplemented() const
			"CPyErr_Print@780cdac8f1a33934\0" // void CPyErr_Print()
			"CPyErr_Clear@780cdac8f1a33934\0" // void CPyErr_Clear()
			"CPyErr_Occurred@17a41c38a1983f3d\0" // Bool CPyErr_Occurred(CPyRef* type)
			"CPyErr_SetString@60f51753a372d7c0\0" // CPyRef CPyErr_SetString(const CPyRef& errorType, const Char* errorString)
			"CPyErr_SetWithErrnoAndFilename@c6e663fa5b1ad388\0" // CPyRef CPyErr_SetWithErrnoAndFilename(const CPyRef& errorType, Int32 errorNumber, const Char* filename)
			"CPyErr_SetWithErrno@6e22e68418899ad9\0" // CPyRef CPyErr_SetWithErrno(const CPyRef& errorType, Int32 errorNumber)
			"CPyErr_SetString@4e5509b54533ff43\0" // CPyRef CPyErr_SetString(const CPyRef& errorType, const String& errorString)
			"CPyErr_SetNone@27d79b4a89ad1f14\0" // void CPyErr_SetNone(const CPyRef& errorType)
			"CPyErr_Fetch@affad59f12e8f887\0" // void CPyErr_Fetch(CPyRef& type, CPyRef& value, CPyRef& traceback)
			"CPyErr_NormalizeException@affad59f12e8f887\0" // void CPyErr_NormalizeException(CPyRef& type, CPyRef& value, CPyRef& traceback)
			"CPyErr_Restore@561cf0ae772d50b4\0" // void CPyErr_Restore(const CPyRef& type, const CPyRef& value, const CPyRef& traceback)
			"CPyErr_ExceptionMatches@deca63b112827ad6\0" // Bool CPyErr_ExceptionMatches(const CPyRef& exc)
			"CPyExceptionClass_Check@deca63b112827ad6\0" // Bool CPyExceptionClass_Check(const CPyRef& o)
			"CPyCapsule_New@a22498e078a6b155\0" // CPyRef CPyCapsule_New(void* pointer, const Char* name, CPyCapsule_Destructor* destructor) const
			"CPyCapsule_SetPointer@8f2097f394c8a2be\0" // Bool CPyCapsule_SetPointer(const CPyRef& capsule, void* pointer)
			"CPyCapsule_GetPointer@fc45b9731f4aec49\0" // void* CPyCapsule_GetPointer(const CPyRef& capsule, const Char* name)
			"CPyCapsule_GetContext@5d8166e33041ae04\0" // void* CPyCapsule_GetContext(const CPyRef& capsule)
			"CPyCapsule_SetContext@8f2097f394c8a2be\0" // Bool CPyCapsule_SetContext(const CPyRef& capsule, void* context)
			"CPyCapsule_CheckExact@deca63b112827ad6\0" // Bool CPyCapsule_CheckExact(const CPyRef& o)
			"CPyTraceBack_Check@deca63b112827ad6\0" // Bool CPyTraceBack_Check(const CPyRef& o)
			"CPyClass_Check@deca63b112827ad6\0" // Bool CPyClass_Check(const CPyRef& o)
			"CPyTuple_New@4cd1e88e60bfde2b\0" // CPyRef CPyTuple_New(UInt size) const
			"CPyTuple_Size@97a56077b0def02a\0" // UInt CPyTuple_Size(const CPyRef& tuple)
			"CPyTuple_GetItem@aa11be4a5b615f07\0" // CPyRef CPyTuple_GetItem(const CPyRef& tuple, UInt index)
			"CPyTuple_SetItem@1ddb4fcb0260ca66\0" // Bool CPyTuple_SetItem(const CPyRef& tuple, UInt index, const CPyRef& item)
			"CPyTuple_GetSlice@f759b9a01a9f9355\0" // CPyRef CPyTuple_GetSlice(const CPyRef& tuple, UInt from, UInt to)
			"CPyTuple_CheckExact@deca63b112827ad6\0" // Bool CPyTuple_CheckExact(const CPyRef& tuple)
			"CPyObject_HasAttrString@e90708256bc906d7\0" // Bool CPyObject_HasAttrString(const CPyRef& o, const Char* attrName)
			"CPyObject_SetAttrString@16b6070a1182fed3\0" // Bool CPyObject_SetAttrString(const CPyRef& o, const Char* name, const CPyRef& item)
			"CPyObject_GetAttrString@60f51753a372d7c0\0" // CPyRef CPyObject_GetAttrString(const CPyRef& o, const Char* name)
			"CPyObject_Call@a2facce1c311ae21\0" // CPyRef CPyObject_Call(const CPyRef& callable_object, const CPyRef& tupleArg, const CPyRef& kw)
			"CPyObject_Str@434bf72e179dba1\0" // CPyRef CPyObject_Str(const CPyRef& o)
			"CPyObject_Repr@434bf72e179dba1\0" // CPyRef CPyObject_Repr(const CPyRef& o)
			"CPyObject_Dir@434bf72e179dba1\0" // CPyRef CPyObject_Dir(const CPyRef& o)
			"CPyObject_RichCompare@795a52ad38d5ea55\0" // CPyRef CPyObject_RichCompare(const CPyRef& o1, const CPyRef& o2, Int32 opid)
			"CPyObject_Hash@facf45c962c3c3cf\0" // Int64 CPyObject_Hash(const CPyRef& o)
			"CPyObject_IsTrue@deca63b112827ad6\0" // Bool CPyObject_IsTrue(const CPyRef& o)
			"CPyObject_Not@deca63b112827ad6\0" // Bool CPyObject_Not(const CPyRef& o)
			"CPyCallable_Check@deca63b112827ad6\0" // Bool CPyCallable_Check(const CPyRef& o)
			"CPyObject_Length@43246f8e2a3dacc5\0" // Int CPyObject_Length(const CPyRef& o)
			"CPyObject_GetItem@6a5ee3ec473d2295\0" // CPyRef CPyObject_GetItem(const CPyRef& o, const CPyRef& key)
			"CPyObject_GetItemInt@7fbdf23969dcdc38\0" // CPyRef CPyObject_GetItemInt(const CPyRef& o, Int index)
			"CPyObject_GetItemString@60f51753a372d7c0\0" // CPyRef CPyObject_GetItemString(const CPyRef& o, const Char* index)
			"CPyObject_DelItem@7c08ef608c8233f2\0" // Bool CPyObject_DelItem(const CPyRef& o, const CPyRef& key)
			"CPyObject_SetItem@c1958e7fc02df4b6\0" // Bool CPyObject_SetItem(const CPyRef& o, const CPyRef& key, const CPyRef& item)
			"CPyObject_TypeCheck@fdb5ea8db64423da\0" // Bool CPyObject_TypeCheck(const CPyRef& object, const CPyTypeRef& type)
			"CPyObject_CallFunction@434bf72e179dba1\0" // CPyRef CPyObject_CallFunction(const CPyRef& o)
			"CPySys_GetObject@af917b2b26bd8db4\0" // CPyRef CPySys_GetObject(const Char* name)
			"CPySys_SetObject@74a9458f7a9b1977\0" // Bool CPySys_SetObject(const Char* name, const CPyRef& o)
			"CPy_SetPath@1ae7180109e92393\0" // Result<void> CPy_SetPath(const BaseArray<Url>& paths)
			"CPySys_SetPath@f463a0ab1886de38\0" // Result<void> CPySys_SetPath(const BaseArray<Url>& paths, PATHHANDLE add)
			"CPySys_SetArgvEx@7f6cba4c804d8da5\0" // Result<void> CPySys_SetArgvEx(const BaseArray<String>& args, Bool updatepath)
			"CPySys_GetPath@2402681e6e2769bf\0" // BaseArray<Url> CPySys_GetPath()
			"CPySite_AddSiteDir@1db4eca46d9225b9\0" // Result<void> CPySite_AddSiteDir(const Url& siteDir)
			"CPyUnicode_Check@deca63b112827ad6\0" // Bool CPyUnicode_Check(const CPyRef& o)
			"CPyUnicode_FromString@8d2ba27b8a65d68a\0" // CPyRef CPyUnicode_FromString(const Char* str) const
			"CPyUnicode_FromStringAndSize@81af58a12bed1c10\0" // CPyRef CPyUnicode_FromStringAndSize(const Block<const Char>& block)
			"CPyUnicode_AsString@444a0ad1c5dc8896\0" // Result<String> CPyUnicode_AsString(const CPyRef& str)
			"CPyUnicode_AsCString@769f8a403e499c0d\0" // const Char* CPyUnicode_AsCString(const CPyRef& str)
			"CPyUnicode_GetLength@43246f8e2a3dacc5\0" // Int CPyUnicode_GetLength(const CPyRef& str)
			"CPyObject_GetIter@11eadbb48dd4b501\0" // CPyRef CPyObject_GetIter(const CPyRef& o) const
			"CPyIter_Next@11eadbb48dd4b501\0" // CPyRef CPyIter_Next(const CPyRef& it) const
			"CPyDict_New@f0ad936c4a5a3213\0" // CPyRef CPyDict_New() const
			"CPyDict_GetItem@edcd3d7295c2125f\0" // CPyRef CPyDict_GetItem(const CPyRef& dict, const CPyRef& key, Bool raiseKeyError)
			"CPyDict_GetItemString@52152d073a8e709c\0" // CPyRef CPyDict_GetItemString(const CPyRef& dict, const Char* key, Bool raiseKeyError)
			"CPyDict_SetItem@c1958e7fc02df4b6\0" // Bool CPyDict_SetItem(const CPyRef& dict, const CPyRef& key, const CPyRef& item)
			"CPyDict_DelItem@7c08ef608c8233f2\0" // Bool CPyDict_DelItem(const CPyRef& dict, const CPyRef& key)
			"CPyDict_Contains@106d992cfa732557\0" // CONTAINS CPyDict_Contains(const CPyRef& dict, const CPyRef& key)
			"CPyDict_Clear@27d79b4a89ad1f14\0" // void CPyDict_Clear(const CPyRef& dict)
			"CPyDict_Next@afcc75d72019ba7b\0" // Bool CPyDict_Next(const CPyRef& dict, Int& pos, CPyRef& key, CPyRef& value)
			"CPyDict_Keys@434bf72e179dba1\0" // CPyRef CPyDict_Keys(const CPyRef& dict)
			"CPyDict_Values@434bf72e179dba1\0" // CPyRef CPyDict_Values(const CPyRef& dict)
			"CPyDict_Items@434bf72e179dba1\0" // CPyRef CPyDict_Items(const CPyRef& dict)
			"CPyDict_Size@43246f8e2a3dacc5\0" // Int CPyDict_Size(const CPyRef& dict)
			"CPyDict_Copy@434bf72e179dba1\0" // CPyRef CPyDict_Copy(const CPyRef& dict)
			"CPyDict_SetItemString@ca9e97d87a3748cb\0" // Bool CPyDict_SetItemString(const CPyRef& dict, const Char* key, const CPyRef& item) const
			"CPyDict_Check@69ad723b0f678184\0" // Bool CPyDict_Check(const CPyRef& o) const
			"CPyList_New@8a645c70d462f033\0" // CPyRef CPyList_New(UInt size)
			"CPyList_CheckExact@deca63b112827ad6\0" // Bool CPyList_CheckExact(const CPyRef& list)
			"CPyList_Size@43246f8e2a3dacc5\0" // Int CPyList_Size(const CPyRef& list)
			"CPyList_GetItem@aa11be4a5b615f07\0" // CPyRef CPyList_GetItem(const CPyRef& list, UInt index)
			"CPyList_SetItem@1ddb4fcb0260ca66\0" // Bool CPyList_SetItem(const CPyRef& list, UInt anonymous_param_2, const CPyRef& item)
			"CPyList_Insert@1ddb4fcb0260ca66\0" // Bool CPyList_Insert(const CPyRef& list, UInt anonymous_param_2, const CPyRef& item)
			"CPyList_Append@7c08ef608c8233f2\0" // Bool CPyList_Append(const CPyRef& list, const CPyRef& item)
			"CPyList_GetSlice@f759b9a01a9f9355\0" // CPyRef CPyList_GetSlice(const CPyRef& list, UInt from, UInt to)
			"CPyList_SetSlice@342fc712065c9d32\0" // Bool CPyList_SetSlice(const CPyRef& list, UInt from, UInt to, const CPyRef& item)
			"CPyList_Sort@deca63b112827ad6\0" // Bool CPyList_Sort(const CPyRef& list)
			"CPyList_Reverse@deca63b112827ad6\0" // Bool CPyList_Reverse(const CPyRef& list)
			"CPyList_AsTuple@434bf72e179dba1\0" // CPyRef CPyList_AsTuple(const CPyRef& list)
			"CPyDict_DelItemString@e90708256bc906d7\0" // Bool CPyDict_DelItemString(const CPyRef& p, const Char* key)
			"CPyModule_Check@deca63b112827ad6\0" // Bool CPyModule_Check(const CPyRef& o)
			"CPyModule_AddObject@220c424af63efd7c\0" // Result<Bool> CPyModule_AddObject(const CPyRef& module, const Char* name, const CPyRef& value)
			"CPyModule_AddType@fdb5ea8db64423da\0" // Bool CPyModule_AddType(const CPyRef& module, const CPyTypeRef& value)
			"CPyModule_GetDict@434bf72e179dba1\0" // CPyRef CPyModule_GetDict(const CPyRef& module)
			"CPyModule_AddIntConstant@1d6637c5460e702f\0" // Bool CPyModule_AddIntConstant(const CPyRef& mod, const Char* name, long value)
			"CPyImport_ImportModule@af917b2b26bd8db4\0" // CPyRef CPyImport_ImportModule(const Char* name)
			"CPyImport_GetImporter@434bf72e179dba1\0" // CPyRef CPyImport_GetImporter(const CPyRef& path)
			"CPyImport_GetModuleDict@7e06838c6c7d5dbb\0" // CPyRef CPyImport_GetModuleDict()
			"CPyType_Check@deca63b112827ad6\0" // Bool CPyType_Check(const CPyRef& o)
			"CPyType_IsSubtype@c737bf20288603f2\0" // Bool CPyType_IsSubtype(const CPyTypeRef& a, const CPyTypeRef& b)
			"CPyType_HasFeature@ae572ab82016c00d\0" // Bool CPyType_HasFeature(const CPyTypeRef& type, Int64 f) const
			"CPyType_FastSubclass@ae572ab82016c00d\0" // Bool CPyType_FastSubclass(const CPyTypeRef& type, Int64 f) const
			"CPyType_GetName@592b19726929e65e\0" // Result<String> CPyType_GetName(const CPyTypeRef& type)
			"CPyType_Ready@9be9b141a5988131\0" // Bool CPyType_Ready(CPyTypeRef& type)
			"CPyEval_SaveThread@6553e6bf9de5a971\0" // NativePyThreadState* CPyEval_SaveThread()
			"CPyEval_RestoreThread@34ba2310998ee849\0" // void CPyEval_RestoreThread(NativePyThreadState* state)
			"CPyEval_ThreadsInitialized@d7a8c99431e20a5a\0" // Bool CPyEval_ThreadsInitialized()
			"CPyEval_InitThreads@780cdac8f1a33934\0" // void CPyEval_InitThreads()
			"CPyEval_AcquireThread@34ba2310998ee849\0" // void CPyEval_AcquireThread(NativePyThreadState* state)
			"CPyEval_ReleaseThread@34ba2310998ee849\0" // void CPyEval_ReleaseThread(NativePyThreadState* state)
			"CPyEval_GetBuiltins@f0ad936c4a5a3213\0" // CPyRef CPyEval_GetBuiltins() const
			"CPyEval_EvalCode@da9c4245ef715352\0" // CPyRef CPyEval_EvalCode(const CPyCodeRef& code, const CPyRef& globals, const CPyRef& locals) const
			"CPyFloat_Check@deca63b112827ad6\0" // Bool CPyFloat_Check(const CPyRef& o)
			"CPyFloat_FromFloat32@66c0a88cd7a26e52\0" // CPyRef CPyFloat_FromFloat32(Float32 value)
			"CPyFloat_FromFloat64@66bda883679b023d\0" // CPyRef CPyFloat_FromFloat64(Float64 value)
			"CPyFloat_AsFloat64@83a7b67b63caaf6c\0" // Float64 CPyFloat_AsFloat64(const CPyRef& o)
			"CPyLong_Check@deca63b112827ad6\0" // Bool CPyLong_Check(const CPyRef& o)
			"CPyBool_FromBool@26365d1dbb688edf\0" // CPyRef CPyBool_FromBool(Bool value)
			"CPyLong_FromInt16@f1fad38f89e6b40b\0" // CPyRef CPyLong_FromInt16(Int16 value)
			"CPyLong_FromUInt16@7ccad7ea58f94230\0" // CPyRef CPyLong_FromUInt16(UInt16 value)
			"CPyLong_FromInt32@f1fcd395fdebe7d5\0" // CPyRef CPyLong_FromInt32(Int32 value)
			"CPyLong_FromUInt32@7cc8d7e454f4beb6\0" // CPyRef CPyLong_FromUInt32(UInt32 value)
			"CPyLong_FromInt64@f1f7d385f9df1596\0" // CPyRef CPyLong_FromInt64(Int64 value)
			"CPyLong_FromUInt64@7ccdd7f3ed00e6f1\0" // CPyRef CPyLong_FromUInt64(UInt64 value)
			"CPyLong_AsInt16@d8ae151fdf77bc1a\0" // Int16 CPyLong_AsInt16(const CPyRef& o)
			"CPyLong_AsUInt16@efc42e651f68c129\0" // UInt16 CPyLong_AsUInt16(const CPyRef& o)
			"CPyLong_AsInt32@23a06246c9033114\0" // Int32 CPyLong_AsInt32(const CPyRef& o)
			"CPyLong_AsUInt32@f10887154537d627\0" // UInt32 CPyLong_AsUInt32(const CPyRef& o)
			"CPyLong_AsInt64@facf45c962c3c3cf\0" // Int64 CPyLong_AsInt64(const CPyRef& o)
			"CPyLong_AsUInt64@9175cfe52c8dda58\0" // UInt64 CPyLong_AsUInt64(const CPyRef& o)
			"CPyNumber_Check@deca63b112827ad6\0" // Bool CPyNumber_Check(const CPyRef& o)
			"MPyFunction_New@dd443c9519a8bf35\0" // MPyFunctionRef MPyFunction_New(const reflection::Function* func)
			"MPyMember_New@31f229c995d7267d\0" // MPyMemberRef MPyMember_New(const reflection::Member* member)
			"CPyMem_SetAllocator@e59bbe0402e7de90\0" // Result<void> CPyMem_SetAllocator(CPyMemAllocatorDomain domain, CPyMemAllocatorEx* allocator)
			"MPyClass_New@e922bd51b72ab9e5\0" // MPyClassRef MPyClass_New(const reflection::Class* cls)
			"CPy_DebugFlag@309cc57cb8762ee4\0" // Int32* CPy_DebugFlag()
			"CPy_VerboseFlag@309cc57cb8762ee4\0" // Int32* CPy_VerboseFlag()
			"CPy_InteractiveFlag@309cc57cb8762ee4\0" // Int32* CPy_InteractiveFlag()
			"CPy_InspectFlag@309cc57cb8762ee4\0" // Int32* CPy_InspectFlag()
			"CPy_OptimizeFlag@309cc57cb8762ee4\0" // Int32* CPy_OptimizeFlag()
			"CPy_NoSiteFlag@309cc57cb8762ee4\0" // Int32* CPy_NoSiteFlag()
			"CPy_BytesWarningFlag@309cc57cb8762ee4\0" // Int32* CPy_BytesWarningFlag()
			"CPy_FrozenFlag@309cc57cb8762ee4\0" // Int32* CPy_FrozenFlag()
			"CPy_IgnoreEnvironmentFlag@309cc57cb8762ee4\0" // Int32* CPy_IgnoreEnvironmentFlag()
			"CPy_DontWriteBytecodeFlag@309cc57cb8762ee4\0" // Int32* CPy_DontWriteBytecodeFlag()
			"CPy_NoUserSiteDirectory@309cc57cb8762ee4\0" // Int32* CPy_NoUserSiteDirectory()
			"CPyExc_BaseException@f9f9724735b93e16\0" // CPyConstRef CPyExc_BaseException()
			"CPyExc_Exception@f9f9724735b93e16\0" // CPyConstRef CPyExc_Exception()
			"CPyExc_StopIteration@f9f9724735b93e16\0" // CPyConstRef CPyExc_StopIteration()
			"CPyExc_GeneratorExit@f9f9724735b93e16\0" // CPyConstRef CPyExc_GeneratorExit()
			"CPyExc_StandardError@f9f9724735b93e16\0" // CPyConstRef CPyExc_StandardError()
			"CPyExc_ArithmeticError@f9f9724735b93e16\0" // CPyConstRef CPyExc_ArithmeticError()
			"CPyExc_LookupError@f9f9724735b93e16\0" // CPyConstRef CPyExc_LookupError()
			"CPyExc_AssertionError@f9f9724735b93e16\0" // CPyConstRef CPyExc_AssertionError()
			"CPyExc_AttributeError@f9f9724735b93e16\0" // CPyConstRef CPyExc_AttributeError()
			"CPyExc_EOFError@f9f9724735b93e16\0" // CPyConstRef CPyExc_EOFError()
			"CPyExc_FloatingPointError@f9f9724735b93e16\0" // CPyConstRef CPyExc_FloatingPointError()
			"CPyExc_EnvironmentError@f9f9724735b93e16\0" // CPyConstRef CPyExc_EnvironmentError()
			"CPyExc_IOError@f9f9724735b93e16\0" // CPyConstRef CPyExc_IOError()
			"CPyExc_OSError@f9f9724735b93e16\0" // CPyConstRef CPyExc_OSError()
			"CPyExc_ImportError@f9f9724735b93e16\0" // CPyConstRef CPyExc_ImportError()
			"CPyExc_IndexError@f9f9724735b93e16\0" // CPyConstRef CPyExc_IndexError()
			"CPyExc_KeyError@f9f9724735b93e16\0" // CPyConstRef CPyExc_KeyError()
			"CPyExc_KeyboardInterrupt@f9f9724735b93e16\0" // CPyConstRef CPyExc_KeyboardInterrupt()
			"CPyExc_MemoryError@f9f9724735b93e16\0" // CPyConstRef CPyExc_MemoryError()
			"CPyExc_NameError@f9f9724735b93e16\0" // CPyConstRef CPyExc_NameError()
			"CPyExc_OverflowError@f9f9724735b93e16\0" // CPyConstRef CPyExc_OverflowError()
			"CPyExc_RuntimeError@f9f9724735b93e16\0" // CPyConstRef CPyExc_RuntimeError()
			"CPyExc_NotImplementedError@f9f9724735b93e16\0" // CPyConstRef CPyExc_NotImplementedError()
			"CPyExc_SyntaxError@f9f9724735b93e16\0" // CPyConstRef CPyExc_SyntaxError()
			"CPyExc_IndentationError@f9f9724735b93e16\0" // CPyConstRef CPyExc_IndentationError()
			"CPyExc_TabError@f9f9724735b93e16\0" // CPyConstRef CPyExc_TabError()
			"CPyExc_ReferenceError@f9f9724735b93e16\0" // CPyConstRef CPyExc_ReferenceError()
			"CPyExc_SystemError@f9f9724735b93e16\0" // CPyConstRef CPyExc_SystemError()
			"CPyExc_SystemExit@f9f9724735b93e16\0" // CPyConstRef CPyExc_SystemExit()
			"CPyExc_TypeError@f9f9724735b93e16\0" // CPyConstRef CPyExc_TypeError()
			"CPyExc_UnboundLocalError@f9f9724735b93e16\0" // CPyConstRef CPyExc_UnboundLocalError()
			"CPyExc_UnicodeError@f9f9724735b93e16\0" // CPyConstRef CPyExc_UnicodeError()
			"CPyExc_UnicodeEncodeError@f9f9724735b93e16\0" // CPyConstRef CPyExc_UnicodeEncodeError()
			"CPyExc_UnicodeDecodeError@f9f9724735b93e16\0" // CPyConstRef CPyExc_UnicodeDecodeError()
			"CPyExc_UnicodeTranslateError@f9f9724735b93e16\0" // CPyConstRef CPyExc_UnicodeTranslateError()
			"CPyExc_ValueError@f9f9724735b93e16\0" // CPyConstRef CPyExc_ValueError()
			"CPyExc_ZeroDivisionError@f9f9724735b93e16\0" // CPyConstRef CPyExc_ZeroDivisionError()
			"CPyExc_WindowsError@f9f9724735b93e16\0" // CPyConstRef CPyExc_WindowsError()
			"CPyExc_BufferError@f9f9724735b93e16\0" // CPyConstRef CPyExc_BufferError()
			"CPyExc_MemoryErrorInst@f9f9724735b93e16\0" // CPyConstRef CPyExc_MemoryErrorInst()
			"CPyExc_Warning@f9f9724735b93e16\0" // CPyConstRef CPyExc_Warning()
			"CPyExc_UserWarning@f9f9724735b93e16\0" // CPyConstRef CPyExc_UserWarning()
			"CPyExc_DeprecationWarning@f9f9724735b93e16\0" // CPyConstRef CPyExc_DeprecationWarning()
			"CPyExc_PendingDeprecationWarning@f9f9724735b93e16\0" // CPyConstRef CPyExc_PendingDeprecationWarning()
			"CPyExc_SyntaxWarning@f9f9724735b93e16\0" // CPyConstRef CPyExc_SyntaxWarning()
			"CPyExc_RuntimeWarning@f9f9724735b93e16\0" // CPyConstRef CPyExc_RuntimeWarning()
			"CPyExc_FutureWarning@f9f9724735b93e16\0" // CPyConstRef CPyExc_FutureWarning()
			"CPyExc_ImportWarning@f9f9724735b93e16\0" // CPyConstRef CPyExc_ImportWarning()
			"CPyExc_UnicodeWarning@f9f9724735b93e16\0" // CPyConstRef CPyExc_UnicodeWarning()
			"CPyExc_BytesWarning@f9f9724735b93e16\0" // CPyConstRef CPyExc_BytesWarning()
			"CPyNullImporter_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPyNullImporter_Type()
			"CPySuper_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPySuper_Type()
			"CPyBool_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPyBool_Type()
			"CPyObject_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPyObject_Type()
			"CPyModule_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPyModule_Type()
			"CPyUnicode_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPyUnicode_Type()
			"CPyLong_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPyLong_Type()
			"CPyFloat_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPyFloat_Type()
			"CPyTuple_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPyTuple_Type()
			"CPyList_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPyList_Type()
			"CPyDict_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPyDict_Type()
			"CPyClass_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPyClass_Type()
			"CPyTraceBack_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPyTraceBack_Type()
			"CPySlice_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPySlice_Type()
			"CPyType_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPyType_Type()
			"CPyMemoryView_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPyMemoryView_Type()
			"ConvertAndCacheString@f67a8f26cc9ea55c\0" // const PyChar* ConvertAndCacheString(const String& str, PyStringEncodings encoding, UInt* size)
			"RegisterSpecificPythonClass@1fb5466526e4499\0" // Result<void> RegisterSpecificPythonClass(const Id& typeId, const CPyTypeRef& type)
			"PrivateRegisterBuiltinConverter@9dbf32f8bda38786\0" // Result<void> PrivateRegisterBuiltinConverter(const DataType& dt, const DelegatePyObject_AsData& f1, const DelegatePyObject_FromData<>& f2)
			"GetSpecialPath@e0b12b013355f66d\0" // Url GetSpecialPath(SPECIALPATH anonymous_param_1)
			"RegisterSpecialPath@f02cbe1eb9e9acc8\0" // void RegisterSpecialPath(SPECIALPATH anonymous_param_1, const Url& path)
			"MPyDataCapsule_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef MPyDataCapsule_Type()
			"CPyData_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPyData_Type()
			"CPyCapsule_Type@e5513ca0b8c7ce1e\0" // CPyTypeConstRef CPyCapsule_Type()
			"PrivateGetCurrentCallerContext@7e06838c6c7d5dbb\0" // CPyRef PrivateGetCurrentCallerContext()
			"MPyDataType_ToMapperInstance@434bf72e179dba1\0" // CPyRef MPyDataType_ToMapperInstance(const CPyRef& capsule)
			"MPyData_ToMapperInstance@e14eb34289e068ef\0" // CPyRef MPyData_ToMapperInstance(const MPyDataRef& capsule)
			"CPyObject_ToMapperInstance@1785be4abf905f68\0" // CPyRef CPyObject_ToMapperInstance(const DataType& dt, const CPyRef& capsule)
			"AssociateDataTypeWithPythonTypes@531baec0296a5a2a\0" // Result<void> AssociateDataTypeWithPythonTypes(const DataType& dt, const CPyRef& type)
			"GetAssociatedDataType@bf6c039e84c06ff5\0" // Result<CPyRef> GetAssociatedDataType(const DataType& dt)
			"GetConverterPyObject_FromData@992eda8b807af213\0" // DelegatePyObject_FromData<>* GetConverterPyObject_FromData(const DataType& dt)
			"MPyData_New@d1bf0ba21a9a9d39\0" // MPyDataRef MPyData_New(Data& data)
			"MPyData_New@fc8b8a1caad10d50\0" // MPyDataRef MPyData_New(const DataType& dt, Generic* data, Bool owner, const DataType& mapDt)
			"MPyDataType_New@5c06ac5ff6d621c6\0" // MPyDataTypeRef MPyDataType_New(const DataType& dt)
			"MPyDataType_CheckExact@69ad723b0f678184\0" // Bool MPyDataType_CheckExact(const CPyRef& o) const
			"MPyDataType_GetDataType@3f82deeb57368bb3\0" // const DataType& MPyDataType_GetDataType(const MPyDataTypeRef& o) const
			"MPyData_CheckExact@69ad723b0f678184\0" // Bool MPyData_CheckExact(const CPyRef& o) const
			"CPyObject_AsData@f2e13677640d025f\0" // Result<Data*> CPyObject_AsData(Int stackDepth, const CPyRef& obj, const DataType& expected, BlockArray<Data>& k, BaseArray<reflection::Argument>* n)
			"GetRegisteredTypesWithConversions@90ef242678cbedcf\0" // Result<BaseArray<TYPE_CONVERSION_TUPLE>> GetRegisteredTypesWithConversions()
			"ParseDataType@f555c2189bfc8b93\0" // Result<DataType> ParseDataType(const CPyRef& args, Int32 argIndex, Bool canBeNone)
			"SetError@73ea1403e4ac5995\0" // void SetError(const Error& err)
			"SetError@5d6b755aae5191e9\0" // void SetError(const ErrorPtr& err)
			"MaxonConvertAuto@434bf72e179dba1\0" // CPyRef MaxonConvertAuto(const CPyRef& capsule)
			"CPyObject_FromGeneric@3315e8df8ebbaff2\0" // CPyRef CPyObject_FromGeneric(const DataType& origDt, const Generic* object, OWNERSHIP ownership, const CPyTypeRef* expected, Int* count)
			"CreateGlobalDictionary@f0ad936c4a5a3213\0" // CPyRef CreateGlobalDictionary() const
			"GetCurrentTraceback@ec28bf17ee483c71\0" // Result<BaseArray<SourceLocation>> GetCurrentTraceback()
			"GetCPyRefClass@24c2036aeffd1a09\0" // Class<CPyRef> GetCPyRefClass() const
			"GetCPyTypeRefClass@398c37e0ef05cb61\0" // Class<CPyTypeRef> GetCPyTypeRefClass() const
			"GetCPyFrameRefClass@161139eaefc3d42\0" // Class<CPyFrameRef> GetCPyFrameRefClass() const
			"GetCPyTracebackRefClass@f006b39aaa0f21b9\0" // Class<CPyTracebackRef> GetCPyTracebackRefClass() const
			"GetCPyCodeRefClass@97f3ee618d26562c\0" // Class<CPyCodeRef> GetCPyCodeRefClass() const
			"GetMPyClassRefClass@92ebc7fdec81fc39\0" // Class<MPyClassRef> GetMPyClassRefClass() const
			"GetMPyMemberRefClass@813d438befa5221d\0" // Class<MPyMemberRef> GetMPyMemberRefClass() const
			"GetMPyFunctionRefClass@81e63138272a75eb\0" // Class<MPyFunctionRef> GetMPyFunctionRefClass() const
			"GetMPyDataTypeRefClass@88cc43c62157c37b\0" // Class<MPyDataTypeRef> GetMPyDataTypeRefClass() const
			"GetMPyDataRefClass@1bbd1e2a4ab55713\0" // Class<MPyDataRef> GetMPyDataRefClass() const
			"GetMPyCallerContextRefClass@ed4d2d5bf4458a33\0" // Class<MPyCallerContextRef> GetMPyCallerContextRefClass() const
		"";
		const maxon::METHOD_FLAGS CPythonLibraryInterface::MTable::_flags[] = 
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
			maxon::METHOD_FLAGS::NONE,
			maxon::METHOD_FLAGS::NONE,
			maxon::METHOD_FLAGS::NONE
		};
		PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(CPythonLibraryInterface, , "net.maxon.python.interface.python.cpythonlibrary", "maxon.py.CPythonLibraryInterface", (LibraryInterface::PrivateGetInterface()));
		const maxon::Char* const CPythonLibraryInterface::Hxx2::StaticMTable::_ids = 
			"ParseCommandLine@74a0915d2c63e203\0" // Result<PYSTARTOPERATION> ParseCommandLine(BaseArray<String>* args, Data* res, PYTHONFLAG* flags)
			"GetUrl@9008c192e2936f81\0" // Result<void> GetUrl(DEFAULTRUNTIME pythonPath, Url& pythonLibrary, Url& pythonHome)
		"";
		PRIVATE_MAXON_INTERFACE_REGISTER_STATIC(CPythonLibraryInterface, , "net.maxon.python.interface.python.cpythonlibrary");
		template <typename DUMMY> maxon::Int CPythonLibraryInterface::PrivateInstantiateNullValueHelper()
		{
			return 0
			| maxon::details::InstantiateNullReturnValue<BaseArray<Url>>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<CONTAINS>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<CPyCodeRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<CPyConstRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<CPyRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<CPyTypeConstRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<Class<CPyCodeRef>>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<Class<CPyFrameRef>>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<Class<CPyRef>>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<Class<CPyTracebackRef>>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<Class<CPyTypeRef>>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<Class<MPyCallerContextRef>>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<Class<MPyClassRef>>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<Class<MPyDataRef>>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<Class<MPyDataTypeRef>>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<Class<MPyFunctionRef>>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<Class<MPyMemberRef>>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<Error>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<GILSTATE>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<MPyCallerContextRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<MPyClassRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<MPyDataRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<MPyDataTypeRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<MPyFunctionRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<MPyMemberRef>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<PYGILSTATE>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<String>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<Url>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<const DataType&>(OVERLOAD_MAX_RANK)
			| maxon::details::InstantiateNullReturnValue<const PythonDll&>(OVERLOAD_MAX_RANK)
			;
		}
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_NativePyObject,, "net.maxon.python.datatype.nativepyobject");
		namespace specialtype
		{
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_Tuple,, "net.maxon.python.datatype.tuple");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_Slice,, "net.maxon.python.datatype.slice");
			PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(DT_BaseArray,, "net.maxon.python.datatype.basearray");
		}
	}
	const maxon::Char* const PyModuleInterface::MTable::_ids = 
		"GetFunctions3@f1bde589d92c6200\0" // Result<void> GetFunctions3(BaseArray<NativePyCFunctionTable>& functions)
		"GetConstants@ea46e73099ab873c\0" // Result<void> GetConstants(BaseArray<Tuple<const Char*, Int32>>& constants)
	"";
	const maxon::METHOD_FLAGS PyModuleInterface::MTable::_flags[] = 
	{
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE,
		maxon::METHOD_FLAGS::NONE
	};
	PRIVATE_MAXON_INTERFACE_REGISTER_VIRTUAL_SINGLE_BASE(PyModuleInterface, , "net.maxon.python.interface.module", "maxon.PyModuleInterface", (LibraryInterface::PrivateGetInterface()));
	MAXON_REGISTRY_REGISTER(PyModules);
	MAXON_REGISTRY_REGISTER(CPythonLibs);
	namespace CPythonLibs
	{
		PRIVATE_MAXON_DECLARATION_REGISTER_DECLARATION(Lib3, , "net.maxon.python.cpythonlibs.cpy3");
	}
}
#ifndef MAXON_COMPILER_GCC
#else
#endif
#endif
static maxon::details::ForceEvaluation s_forceEval_cpython(0
	| maxon::py::PythonTracebackErrorInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
	| maxon::py::CPythonLibraryInterface::PrivateInstantiateNullValueHelper<maxon::Int>()
);
