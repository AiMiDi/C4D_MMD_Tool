// This file contains default implementations for the interfaces of cpython.h. They are intended for copy&paste usage only.

class MyPythonErrorImpl : public maxon::Component<MyPythonErrorImpl, PythonErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyPythonTracebackErrorImpl : public maxon::Component<MyPythonTracebackErrorImpl, PythonTracebackErrorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD void SetUrl(const Url& url)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD const Url& GetUrl() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const Url&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void SetLineNumber(Int line)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Int GetLineNumber() const
	{
		return 0;
	}

};

class MyPythonSystemExitErrorImpl : public maxon::Component<MyPythonSystemExitErrorImpl, PythonSystemExitErrorInterface>
{
	MAXON_COMPONENT();

public:
};

class MyCPythonLibraryImpl : public maxon::Component<MyCPythonLibraryImpl, CPythonLibraryInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const Url& librarypath, Bool createSubLibrary)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InitTypes()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> InitBuiltinModules()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD void CPy_Initialize()
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void CPy_Finalize()
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD CPyRef CPyModule_Create(const ModuleDefinition& module)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void Free(const Delegate<void()>& shutdownEngine)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD const PythonDll& GetDll() const
	{
		return maxon::PrivateIncompleteNullReturnValue<const PythonDll&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD FILE_native* FopenNative(const Char* name, const Char* mode)
	{
		return nullptr;
	}

	MAXON_METHOD Error LastPythonCallFailed(const maxon::SourceLocation& allocLocation, Bool withTraceback, Bool restoreError)
	{
		return maxon::PrivateIncompleteNullReturnValue<Error>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<MPyDataRef> RegisterComponentProxy(const CPyRef& type, const Id& registryId, const ProxyDefinition& baseAndInterfaceIds, const Id& cid, Bool printErrors, ClassInterface::KIND kind, const SourceLocation& loc, Bool createObject, const DataType& dtOfObject)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Bool CPy_IsInitialized()
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD const Char* CPy_GetVersion()
	{
		return nullptr;
	}

	MAXON_METHOD const Char* CPy_GetPlatform()
	{
		return nullptr;
	}

	MAXON_METHOD const Char* CPy_GetCopyright()
	{
		return nullptr;
	}

	MAXON_METHOD const Char* CPy_GetCompiler()
	{
		return nullptr;
	}

	MAXON_METHOD const Char* CPy_GetBuildInfo()
	{
		return nullptr;
	}

	MAXON_METHOD Result<void> CPy_SetProgramName(const String& name)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> CPy_SetPythonHome(const Url& name)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD String CPy_GetProgramName()
	{
		return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD String CPy_GetPythonHome()
	{
		return maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool ExecuteModule(const String& name)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD MPyCallerContextRef CPyCallerContext_New()
	{
		return maxon::PrivateIncompleteNullReturnValue<MPyCallerContextRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool CPyRun_SimpleFileExFlags(FILE_native* fp, const Char* filename, Int32 closeit, CPyCompilerFlags* flags)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyRun_SimpleFileExFlags(const Url& url, CPyCompilerFlags* flags)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CPyRef CPyRun_SimpleStringFlags(const String& code, CPyCompilerFlags* flags)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD NativePyObject* CPyRun_FileExFlags(FILE_native* fp, const Char* filename, Int32 start, NativePyObject* globals, NativePyObject* locals, Int32 closeit, CPyCompilerFlags* flags)
	{
		return nullptr;
	}

	MAXON_METHOD Result<void> CPyRun_InteractiveLoopFlags(FILE* fp, const Char* filename, CPyCompilerFlags* flags)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD PYGILSTATE CPyGilState_Ensure()
	{
		return maxon::PrivateIncompleteNullReturnValue<PYGILSTATE>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void CPyGilState_Release(PYGILSTATE state)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD GILSTATE GetGilState() const
	{
		return maxon::PrivateIncompleteNullReturnValue<GILSTATE>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD NativePyThreadState* CPyGILState_GetThisThreadState()
	{
		return nullptr;
	}

	MAXON_METHOD NativePyThreadState* CPyThreadState_Swap(NativePyThreadState* state)
	{
		return nullptr;
	}

	MAXON_METHOD CPyRef CPyThreadState_GetDict()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyCodeRef CPy_CompileStringFlags(const Char* code, const Char* filename, PYINPUT start, CPyCompilerFlags* flags)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyCodeRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void CPy_Incref(NativePyObject* o) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void CPy_Decref(NativePyObject* o) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void CPy_SafeIncref(NativePyObject* o) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void CPy_SafeDecref(NativePyObject* o) const
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Int64 CPyGC_Collect()
	{
		return 0;
	}

	MAXON_METHOD Int32 CPyCode_Addr2Line(const CPyCodeRef& codeObject, Int32 x)
	{
		return 0;
	}

	MAXON_METHOD CPyRef UnpackDataType(const CPyRef& obj)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef UnpackData(const CPyRef& obj)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPy_None() const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPy_True() const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPy_False() const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPy_NotImplemented() const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void CPyErr_Print()
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void CPyErr_Clear()
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Bool CPyErr_Occurred(CPyRef* type)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CPyRef CPyErr_SetString(const CPyRef& errorType, const Char* errorString)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyErr_SetWithErrnoAndFilename(const CPyRef& errorType, Int32 errorNumber, const Char* filename)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyErr_SetWithErrno(const CPyRef& errorType, Int32 errorNumber)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyErr_SetString(const CPyRef& errorType, const String& errorString)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void CPyErr_SetNone(const CPyRef& errorType)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void CPyErr_Fetch(CPyRef& type, CPyRef& value, CPyRef& traceback)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void CPyErr_NormalizeException(CPyRef& type, CPyRef& value, CPyRef& traceback)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void CPyErr_Restore(const CPyRef& type, const CPyRef& value, const CPyRef& traceback)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Bool CPyErr_ExceptionMatches(const CPyRef& exc)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyExceptionClass_Check(const CPyRef& o)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CPyRef CPyCapsule_New(void* pointer, const Char* name, CPyCapsule_Destructor* destructor) const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool CPyCapsule_SetPointer(const CPyRef& capsule, void* pointer)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD void* CPyCapsule_GetPointer(const CPyRef& capsule, const Char* name)
	{
		return nullptr;
	}

	MAXON_METHOD void* CPyCapsule_GetContext(const CPyRef& capsule)
	{
		return nullptr;
	}

	MAXON_METHOD Bool CPyCapsule_SetContext(const CPyRef& capsule, void* context)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyCapsule_CheckExact(const CPyRef& o)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyTraceBack_Check(const CPyRef& o)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyClass_Check(const CPyRef& o)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CPyRef CPyTuple_New(UInt size) const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD UInt CPyTuple_Size(const CPyRef& tuple)
	{
		return 0;
	}

	MAXON_METHOD CPyRef CPyTuple_GetItem(const CPyRef& tuple, UInt index)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool CPyTuple_SetItem(const CPyRef& tuple, UInt index, const CPyRef& item)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CPyRef CPyTuple_GetSlice(const CPyRef& tuple, UInt from, UInt to)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool CPyTuple_CheckExact(const CPyRef& tuple)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyObject_HasAttrString(const CPyRef& o, const Char* attrName)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyObject_SetAttrString(const CPyRef& o, const Char* name, const CPyRef& item)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CPyRef CPyObject_GetAttrString(const CPyRef& o, const Char* name)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyObject_Call(const CPyRef& callable_object, const CPyRef& tupleArg, const CPyRef& kw)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyObject_Str(const CPyRef& o)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyObject_Repr(const CPyRef& o)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyObject_Dir(const CPyRef& o)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyObject_RichCompare(const CPyRef& o1, const CPyRef& o2, Int32 opid)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Int64 CPyObject_Hash(const CPyRef& o)
	{
		return 0;
	}

	MAXON_METHOD Bool CPyObject_IsTrue(const CPyRef& o)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyObject_Not(const CPyRef& o)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyCallable_Check(const CPyRef& o)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Int CPyObject_Length(const CPyRef& o)
	{
		return 0;
	}

	MAXON_METHOD CPyRef CPyObject_GetItem(const CPyRef& o, const CPyRef& key)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyObject_GetItemInt(const CPyRef& o, Int index)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyObject_GetItemString(const CPyRef& o, const Char* index)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool CPyObject_DelItem(const CPyRef& o, const CPyRef& key)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyObject_SetItem(const CPyRef& o, const CPyRef& key, const CPyRef& item)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyObject_TypeCheck(const CPyRef& object, const CPyTypeRef& type)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CPyRef CPyObject_CallFunction(const CPyRef& o)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPySys_GetObject(const Char* name)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool CPySys_SetObject(const Char* name, const CPyRef& o)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Result<void> CPy_SetPath(const BaseArray<Url>& paths)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> CPySys_SetPath(const BaseArray<Url>& paths, PATHHANDLE add)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> CPySys_SetArgvEx(const BaseArray<String>& args, Bool updatepath)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD BaseArray<Url> CPySys_GetPath()
	{
		return maxon::PrivateIncompleteNullReturnValue<BaseArray<Url>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<void> CPySite_AddSiteDir(const Url& siteDir)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Bool CPyUnicode_Check(const CPyRef& o)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CPyRef CPyUnicode_FromString(const Char* str) const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyUnicode_FromStringAndSize(const Block<const Char>& block)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<String> CPyUnicode_AsString(const CPyRef& str)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD const Char* CPyUnicode_AsCString(const CPyRef& str)
	{
		return nullptr;
	}

	MAXON_METHOD Int CPyUnicode_GetLength(const CPyRef& str)
	{
		return 0;
	}

	MAXON_METHOD CPyRef CPyObject_GetIter(const CPyRef& o) const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyIter_Next(const CPyRef& it) const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyDict_New() const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyDict_GetItem(const CPyRef& dict, const CPyRef& key, Bool raiseKeyError)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyDict_GetItemString(const CPyRef& dict, const Char* key, Bool raiseKeyError)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool CPyDict_SetItem(const CPyRef& dict, const CPyRef& key, const CPyRef& item)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyDict_DelItem(const CPyRef& dict, const CPyRef& key)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CONTAINS CPyDict_Contains(const CPyRef& dict, const CPyRef& key)
	{
		return maxon::PrivateIncompleteNullReturnValue<CONTAINS>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void CPyDict_Clear(const CPyRef& dict)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Bool CPyDict_Next(const CPyRef& dict, Int& pos, CPyRef& key, CPyRef& value)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CPyRef CPyDict_Keys(const CPyRef& dict)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyDict_Values(const CPyRef& dict)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyDict_Items(const CPyRef& dict)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Int CPyDict_Size(const CPyRef& dict)
	{
		return 0;
	}

	MAXON_METHOD CPyRef CPyDict_Copy(const CPyRef& dict)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool CPyDict_SetItemString(const CPyRef& dict, const Char* key, const CPyRef& item) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyDict_Check(const CPyRef& o) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CPyRef CPyList_New(UInt size)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool CPyList_CheckExact(const CPyRef& list)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyList_Clear(const CPyRef& list)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Int CPyList_Size(const CPyRef& list)
	{
		return 0;
	}

	MAXON_METHOD CPyRef CPyList_GetItem(const CPyRef& list, UInt index)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool CPyList_SetItem(const CPyRef& list, UInt anonymous_param_2, const CPyRef& item)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyList_Insert(const CPyRef& list, UInt anonymous_param_2, const CPyRef& item)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyList_Append(const CPyRef& list, const CPyRef& item)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CPyRef CPyList_GetSlice(const CPyRef& list, UInt from, UInt to)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool CPyList_SetSlice(const CPyRef& list, UInt from, UInt to, const CPyRef& item)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyList_Sort(const CPyRef& list)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyList_Reverse(const CPyRef& list)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CPyRef CPyList_AsTuple(const CPyRef& list)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool CPyDict_DelItemString(const CPyRef& p, const Char* key)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyModule_Check(const CPyRef& o)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Result<Bool> CPyModule_AddObject(const CPyRef& module, const Char* name, const CPyRef& value)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Bool CPyModule_AddType(const CPyRef& module, const CPyTypeRef& value)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CPyRef CPyModule_GetDict(const CPyRef& module)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool CPyModule_AddIntConstant(const CPyRef& mod, const Char* name, long value)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CPyRef CPyImport_ImportModule(const Char* name)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyImport_GetImporter(const CPyRef& path)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyImport_GetModuleDict()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool CPyType_Check(const CPyRef& o)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyType_IsSubtype(const CPyTypeRef& a, const CPyTypeRef& b)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyType_HasFeature(const CPyTypeRef& type, Int64 f) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Bool CPyType_FastSubclass(const CPyTypeRef& type, Int64 f) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Result<String> CPyType_GetName(const CPyTypeRef& type)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Bool CPyType_Ready(CPyTypeRef& type)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD NativePyThreadState* CPyEval_SaveThread()
	{
		return nullptr;
	}

	MAXON_METHOD void CPyEval_RestoreThread(NativePyThreadState* state)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD Bool CPyEval_ThreadsInitialized()
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD void CPyEval_InitThreads()
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void CPyEval_AcquireThread(NativePyThreadState* state)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void CPyEval_ReleaseThread(NativePyThreadState* state)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD CPyRef CPyEval_GetBuiltins() const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyEval_EvalCode(const CPyCodeRef& code, const CPyRef& globals, const CPyRef& locals) const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool CPyFloat_Check(const CPyRef& o)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CPyRef CPyFloat_FromFloat32(Float32 value)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyFloat_FromFloat64(Float64 value)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Float64 CPyFloat_AsFloat64(const CPyRef& o)
	{
		return 0;
	}

	MAXON_METHOD Bool CPyLong_Check(const CPyRef& o)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD CPyRef CPyBool_FromBool(Bool value)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyLong_FromInt16(Int16 value)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyLong_FromUInt16(UInt16 value)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyLong_FromInt32(Int32 value)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyLong_FromUInt32(UInt32 value)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyLong_FromInt64(Int64 value)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyLong_FromUInt64(UInt64 value)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Int16 CPyLong_AsInt16(const CPyRef& o)
	{
		return 0;
	}

	MAXON_METHOD UInt16 CPyLong_AsUInt16(const CPyRef& o)
	{
		return 0;
	}

	MAXON_METHOD Int32 CPyLong_AsInt32(const CPyRef& o)
	{
		return 0;
	}

	MAXON_METHOD UInt32 CPyLong_AsUInt32(const CPyRef& o)
	{
		return 0;
	}

	MAXON_METHOD Int64 CPyLong_AsInt64(const CPyRef& o)
	{
		return 0;
	}

	MAXON_METHOD UInt64 CPyLong_AsUInt64(const CPyRef& o)
	{
		return 0;
	}

	MAXON_METHOD Bool CPyNumber_Check(const CPyRef& o)
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD MPyFunctionRef MPyFunction_New(const reflection::Function* func)
	{
		return maxon::PrivateIncompleteNullReturnValue<MPyFunctionRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD MPyHashMapRef MPyHashMap_New(const HashMap<Data, Data>& map)
	{
		return maxon::PrivateIncompleteNullReturnValue<MPyHashMapRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD MPyHashMapRef MPyHashMap_New(HashMap<Data, Data>&& map)
	{
		return maxon::PrivateIncompleteNullReturnValue<MPyHashMapRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD MPyMemberRef MPyMember_New(const reflection::Member* member)
	{
		return maxon::PrivateIncompleteNullReturnValue<MPyMemberRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<void> CPyMem_SetAllocator(CPyMemAllocatorDomain domain, CPyMemAllocatorEx* allocator)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD MPyClassRef MPyClass_New(const reflection::Class* cls)
	{
		return maxon::PrivateIncompleteNullReturnValue<MPyClassRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Int32* CPy_DebugFlag()
	{
		return nullptr;
	}

	MAXON_METHOD Int32* CPy_VerboseFlag()
	{
		return nullptr;
	}

	MAXON_METHOD Int32* CPy_InteractiveFlag()
	{
		return nullptr;
	}

	MAXON_METHOD Int32* CPy_InspectFlag()
	{
		return nullptr;
	}

	MAXON_METHOD Int32* CPy_OptimizeFlag()
	{
		return nullptr;
	}

	MAXON_METHOD Int32* CPy_NoSiteFlag()
	{
		return nullptr;
	}

	MAXON_METHOD Int32* CPy_BytesWarningFlag()
	{
		return nullptr;
	}

	MAXON_METHOD Int32* CPy_FrozenFlag()
	{
		return nullptr;
	}

	MAXON_METHOD Int32* CPy_IgnoreEnvironmentFlag()
	{
		return nullptr;
	}

	MAXON_METHOD Int32* CPy_DontWriteBytecodeFlag()
	{
		return nullptr;
	}

	MAXON_METHOD Int32* CPy_NoUserSiteDirectory()
	{
		return nullptr;
	}

	MAXON_METHOD CPyConstRef CPyExc_BaseException()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_Exception()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_StopIteration()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_GeneratorExit()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_StandardError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_ArithmeticError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_LookupError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_AssertionError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_AttributeError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_EOFError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_FloatingPointError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_EnvironmentError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_IOError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_OSError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_ImportError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_IndexError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_KeyError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_KeyboardInterrupt()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_MemoryError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_NameError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_OverflowError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_RuntimeError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_NotImplementedError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_SyntaxError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_IndentationError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_TabError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_ReferenceError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_SystemError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_SystemExit()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_TypeError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_UnboundLocalError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_UnicodeError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_UnicodeEncodeError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_UnicodeDecodeError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_UnicodeTranslateError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_ValueError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_ZeroDivisionError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_WindowsError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_BufferError()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_MemoryErrorInst()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_Warning()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_UserWarning()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_DeprecationWarning()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_PendingDeprecationWarning()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_SyntaxWarning()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_RuntimeWarning()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_FutureWarning()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_ImportWarning()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_UnicodeWarning()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyConstRef CPyExc_BytesWarning()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPyNullImporter_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPySuper_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPyBool_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPyObject_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPyModule_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPyUnicode_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPyLong_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPyFloat_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPyTuple_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPyList_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPyDict_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPyClass_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPyTraceBack_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPySlice_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPyType_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPyMemoryView_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD const PyChar* ConvertAndCacheString(const String& str, PyStringEncodings encoding, UInt* size)
	{
		return nullptr;
	}

	MAXON_METHOD Result<void> RegisterSpecificPythonClass(const Id& typeId, const CPyTypeRef& type)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> PrivateRegisterBuiltinConverter(const DataType& dt, const DelegatePyObject_AsData& f1, const DelegatePyObject_FromData<>& f2)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Url GetSpecialPath(SPECIALPATH anonymous_param_1)
	{
		return maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD void RegisterSpecialPath(SPECIALPATH anonymous_param_1, const Url& path)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD CPyTypeConstRef MPyDataCapsule_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPyData_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyTypeConstRef CPyCapsule_Type()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyTypeConstRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef PrivateGetCurrentCallerContext()
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef MPyDataType_ToMapperInstance(const CPyRef& capsule)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef MPyData_ToMapperInstance(const MPyDataRef& capsule)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyObject_ToMapperInstance(const DataType& dt, const CPyRef& capsule)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<void> AssociateDataTypeWithPythonTypes(const DataType& dt, const CPyRef& type)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<CPyRef> GetAssociatedDataType(const DataType& dt)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD DelegatePyObject_FromData<>* GetConverterPyObject_FromData(const DataType& dt)
	{
		return nullptr;
	}

	MAXON_METHOD MPyDataRef MPyData_New(Data& data)
	{
		return maxon::PrivateIncompleteNullReturnValue<MPyDataRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD MPyDataRef MPyData_New(const DataType& dt, Generic* data, Bool owner, const DataType& mapDt)
	{
		return maxon::PrivateIncompleteNullReturnValue<MPyDataRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD MPyDataTypeRef MPyDataType_New(const DataType& dt)
	{
		return maxon::PrivateIncompleteNullReturnValue<MPyDataTypeRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool MPyDataType_CheckExact(const CPyRef& o) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD const DataType& MPyDataType_GetDataType(const MPyDataTypeRef& o) const
	{
		return maxon::PrivateIncompleteNullReturnValue<const DataType&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Bool MPyData_CheckExact(const CPyRef& o) const
	{
		return maxon::PrivateLogNullptrError(false);
	}

	MAXON_METHOD Result<Data*> CPyObject_AsData(Int stackDepth, const CPyRef& obj, const DataType& expected, BlockArray<Data>& k, BaseArray<reflection::Argument>* n)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<BaseArray<TYPE_CONVERSION_TUPLE>> GetRegisteredTypesWithConversions()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<DataType> ParseDataType(const CPyRef& args, Int32 argIndex, Bool canBeNone)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD void SetError(const Error& err)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD void SetError(const ErrorPtr& err)
	{
		return maxon::PrivateLogNullptrError();
	}

	MAXON_METHOD CPyRef MaxonConvertAuto(const CPyRef& capsule)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CPyObject_FromGeneric(const DataType& origDt, const Generic* object, OWNERSHIP ownership, const CPyTypeRef* expected, Int* count)
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD CPyRef CreateGlobalDictionary() const
	{
		return maxon::PrivateIncompleteNullReturnValue<CPyRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Result<BaseArray<SourceLocation>> GetCurrentTraceback()
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Class<CPyRef> GetCPyRefClass() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Class<CPyRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Class<CPyTypeRef> GetCPyTypeRefClass() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Class<CPyTypeRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Class<CPyFrameRef> GetCPyFrameRefClass() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Class<CPyFrameRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Class<CPyTracebackRef> GetCPyTracebackRefClass() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Class<CPyTracebackRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Class<CPyCodeRef> GetCPyCodeRefClass() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Class<CPyCodeRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Class<MPyClassRef> GetMPyClassRefClass() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Class<MPyClassRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Class<MPyMemberRef> GetMPyMemberRefClass() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Class<MPyMemberRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Class<MPyFunctionRef> GetMPyFunctionRefClass() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Class<MPyFunctionRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Class<MPyHashMapRef> GetMPyHashMapRefClass() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Class<MPyHashMapRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Class<MPyDataTypeRef> GetMPyDataTypeRefClass() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Class<MPyDataTypeRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Class<MPyDataRef> GetMPyDataRefClass() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Class<MPyDataRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

	MAXON_METHOD Class<MPyCallerContextRef> GetMPyCallerContextRefClass() const
	{
		return maxon::PrivateIncompleteNullReturnValue<Class<MPyCallerContextRef>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
	}

};

class MyPyModuleImpl : public maxon::Component<MyPyModuleImpl, PyModuleInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> GetFunctions3(BaseArray<NativePyCFunctionTable>& functions)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

	MAXON_METHOD Result<void> GetConstants(BaseArray<Tuple<const Char*, Int32>>& constants)
	{
		return maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
	}

};
