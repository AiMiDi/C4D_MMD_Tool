// This file contains decorator implementations for the interfaces of cpython.h. They are intended for copy&paste usage only.

class PythonErrorDecoratorImpl : public maxon::Component<PythonErrorDecoratorImpl, PythonErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class PythonTracebackErrorDecoratorImpl : public maxon::Component<PythonTracebackErrorDecoratorImpl, PythonTracebackErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD void SetUrl(const Url& url)
	{
		return maxon::Cast<PythonTracebackError>(self.GetDecoratedObject()).SetUrl(url);
	}

	MAXON_METHOD const Url& GetUrl() const
	{
		return maxon::Cast<PythonTracebackError>(self.GetDecoratedObject()).GetUrl();
	}

	MAXON_METHOD void SetLineNumber(Int line)
	{
		return maxon::Cast<PythonTracebackError>(self.GetDecoratedObject()).SetLineNumber(line);
	}

	MAXON_METHOD Int GetLineNumber() const
	{
		return maxon::Cast<PythonTracebackError>(self.GetDecoratedObject()).GetLineNumber();
	}

};

class PythonSystemExitErrorDecoratorImpl : public maxon::Component<PythonSystemExitErrorDecoratorImpl, PythonSystemExitErrorInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class CPythonLibraryDecoratorImpl : public maxon::Component<CPythonLibraryDecoratorImpl, CPythonLibraryInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const Url& librarypath, Bool createSubLibrary)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).Init(librarypath, createSubLibrary);
	}

	MAXON_METHOD Result<void> InitTypes()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).InitTypes();
	}

	MAXON_METHOD Result<void> InitBuiltinModules()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).InitBuiltinModules();
	}

	MAXON_METHOD void CPy_Initialize()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_Initialize();
	}

	MAXON_METHOD void CPy_Finalize()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_Finalize();
	}

	MAXON_METHOD CPyRef CPyModule_Create(const ModuleDefinition& module)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyModule_Create(module);
	}

	MAXON_METHOD void Free(const Delegate<void()>& shutdownEngine)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).Free(shutdownEngine);
	}

	MAXON_METHOD const PythonDll& GetDll() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetDll();
	}

	MAXON_METHOD FILE_native* FopenNative(const Char* name, const Char* mode)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).FopenNative(name, mode);
	}

	MAXON_METHOD Error LastPythonCallFailed(const maxon::SourceLocation& allocLocation, Bool withTraceback, Bool restoreError)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).LastPythonCallFailed(allocLocation, withTraceback, restoreError);
	}

	MAXON_METHOD Result<MPyDataRef> RegisterComponentProxy(const CPyRef& type, const Id& registryId, const ProxyDefinition& baseAndInterfaceIds, const Id& cid, Bool printErrors, ClassInterface::KIND kind, const SourceLocation& loc, Bool createObject, const DataType& dtOfObject)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).RegisterComponentProxy(type, registryId, baseAndInterfaceIds, cid, printErrors, kind, loc, createObject, dtOfObject);
	}

	MAXON_METHOD Bool CPy_IsInitialized()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_IsInitialized();
	}

	MAXON_METHOD const Char* CPy_GetVersion()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_GetVersion();
	}

	MAXON_METHOD const Char* CPy_GetPlatform()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_GetPlatform();
	}

	MAXON_METHOD const Char* CPy_GetCopyright()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_GetCopyright();
	}

	MAXON_METHOD const Char* CPy_GetCompiler()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_GetCompiler();
	}

	MAXON_METHOD const Char* CPy_GetBuildInfo()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_GetBuildInfo();
	}

	MAXON_METHOD Result<void> CPy_SetProgramName(const String& name)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_SetProgramName(name);
	}

	MAXON_METHOD Result<void> CPy_SetPythonHome(const Url& name)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_SetPythonHome(name);
	}

	MAXON_METHOD String CPy_GetProgramName()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_GetProgramName();
	}

	MAXON_METHOD String CPy_GetPythonHome()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_GetPythonHome();
	}

	MAXON_METHOD Bool ExecuteModule(const String& name)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).ExecuteModule(name);
	}

	MAXON_METHOD MPyCallerContextRef CPyCallerContext_New()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyCallerContext_New();
	}

	MAXON_METHOD Bool CPyRun_SimpleFileExFlags(FILE_native* fp, const Char* filename, Int32 closeit, CPyCompilerFlags* flags)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyRun_SimpleFileExFlags(fp, filename, closeit, flags);
	}

	MAXON_METHOD Bool CPyRun_SimpleFileExFlags(const Url& url, CPyCompilerFlags* flags)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyRun_SimpleFileExFlags(url, flags);
	}

	MAXON_METHOD CPyRef CPyRun_SimpleStringFlags(const String& code, CPyCompilerFlags* flags)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyRun_SimpleStringFlags(code, flags);
	}

	MAXON_METHOD NativePyObject* CPyRun_FileExFlags(FILE_native* fp, const Char* filename, Int32 start, NativePyObject* globals, NativePyObject* locals, Int32 closeit, CPyCompilerFlags* flags)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyRun_FileExFlags(fp, filename, start, globals, locals, closeit, flags);
	}

	MAXON_METHOD Result<void> CPyRun_InteractiveLoopFlags(FILE* fp, const Char* filename, CPyCompilerFlags* flags)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyRun_InteractiveLoopFlags(fp, filename, flags);
	}

	MAXON_METHOD PYGILSTATE CPyGilState_Ensure()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyGilState_Ensure();
	}

	MAXON_METHOD void CPyGilState_Release(PYGILSTATE state)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyGilState_Release(state);
	}

	MAXON_METHOD GILSTATE GetGilState() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetGilState();
	}

	MAXON_METHOD NativePyThreadState* CPyGILState_GetThisThreadState()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyGILState_GetThisThreadState();
	}

	MAXON_METHOD NativePyThreadState* CPyThreadState_Swap(NativePyThreadState* state)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyThreadState_Swap(state);
	}

	MAXON_METHOD CPyRef CPyThreadState_GetDict()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyThreadState_GetDict();
	}

	MAXON_METHOD CPyCodeRef CPy_CompileStringFlags(const Char* code, const Char* filename, PYINPUT start, CPyCompilerFlags* flags)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_CompileStringFlags(code, filename, start, flags);
	}

	MAXON_METHOD void CPy_Incref(NativePyObject* o) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_Incref(o);
	}

	MAXON_METHOD void CPy_Decref(NativePyObject* o) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_Decref(o);
	}

	MAXON_METHOD void CPy_SafeIncref(NativePyObject* o) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_SafeIncref(o);
	}

	MAXON_METHOD void CPy_SafeDecref(NativePyObject* o) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_SafeDecref(o);
	}

	MAXON_METHOD Int64 CPyGC_Collect()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyGC_Collect();
	}

	MAXON_METHOD Int32 CPyCode_Addr2Line(const CPyCodeRef& codeObject, Int32 x)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyCode_Addr2Line(codeObject, x);
	}

	MAXON_METHOD CPyRef UnpackDataType(const CPyRef& obj)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).UnpackDataType(obj);
	}

	MAXON_METHOD CPyRef UnpackData(const CPyRef& obj)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).UnpackData(obj);
	}

	MAXON_METHOD CPyConstRef CPy_None() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_None();
	}

	MAXON_METHOD CPyConstRef CPy_True() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_True();
	}

	MAXON_METHOD CPyConstRef CPy_False() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_False();
	}

	MAXON_METHOD CPyConstRef CPy_NotImplemented() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_NotImplemented();
	}

	MAXON_METHOD void CPyErr_Print()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyErr_Print();
	}

	MAXON_METHOD void CPyErr_Clear()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyErr_Clear();
	}

	MAXON_METHOD Bool CPyErr_Occurred(CPyRef* type)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyErr_Occurred(type);
	}

	MAXON_METHOD CPyRef CPyErr_SetString(const CPyRef& errorType, const Char* errorString)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyErr_SetString(errorType, errorString);
	}

	MAXON_METHOD CPyRef CPyErr_SetWithErrnoAndFilename(const CPyRef& errorType, Int32 errorNumber, const Char* filename)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyErr_SetWithErrnoAndFilename(errorType, errorNumber, filename);
	}

	MAXON_METHOD CPyRef CPyErr_SetWithErrno(const CPyRef& errorType, Int32 errorNumber)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyErr_SetWithErrno(errorType, errorNumber);
	}

	MAXON_METHOD CPyRef CPyErr_SetString(const CPyRef& errorType, const String& errorString)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyErr_SetString(errorType, errorString);
	}

	MAXON_METHOD void CPyErr_SetNone(const CPyRef& errorType)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyErr_SetNone(errorType);
	}

	MAXON_METHOD void CPyErr_Fetch(CPyRef& type, CPyRef& value, CPyRef& traceback)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyErr_Fetch(type, value, traceback);
	}

	MAXON_METHOD void CPyErr_NormalizeException(CPyRef& type, CPyRef& value, CPyRef& traceback)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyErr_NormalizeException(type, value, traceback);
	}

	MAXON_METHOD void CPyErr_Restore(const CPyRef& type, const CPyRef& value, const CPyRef& traceback)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyErr_Restore(type, value, traceback);
	}

	MAXON_METHOD Bool CPyErr_ExceptionMatches(const CPyRef& exc)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyErr_ExceptionMatches(exc);
	}

	MAXON_METHOD Bool CPyExceptionClass_Check(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExceptionClass_Check(o);
	}

	MAXON_METHOD CPyRef CPyCapsule_New(void* pointer, const Char* name, CPyCapsule_Destructor* destructor) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyCapsule_New(pointer, name, destructor);
	}

	MAXON_METHOD Bool CPyCapsule_SetPointer(const CPyRef& capsule, void* pointer)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyCapsule_SetPointer(capsule, pointer);
	}

	MAXON_METHOD void* CPyCapsule_GetPointer(const CPyRef& capsule, const Char* name)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyCapsule_GetPointer(capsule, name);
	}

	MAXON_METHOD void* CPyCapsule_GetContext(const CPyRef& capsule)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyCapsule_GetContext(capsule);
	}

	MAXON_METHOD Bool CPyCapsule_SetContext(const CPyRef& capsule, void* context)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyCapsule_SetContext(capsule, context);
	}

	MAXON_METHOD Bool CPyCapsule_CheckExact(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyCapsule_CheckExact(o);
	}

	MAXON_METHOD Bool CPyTraceBack_Check(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyTraceBack_Check(o);
	}

	MAXON_METHOD Bool CPyClass_Check(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyClass_Check(o);
	}

	MAXON_METHOD CPyRef CPyTuple_New(UInt size) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyTuple_New(size);
	}

	MAXON_METHOD UInt CPyTuple_Size(const CPyRef& tuple)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyTuple_Size(tuple);
	}

	MAXON_METHOD CPyRef CPyTuple_GetItem(const CPyRef& tuple, UInt index)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyTuple_GetItem(tuple, index);
	}

	MAXON_METHOD Bool CPyTuple_SetItem(const CPyRef& tuple, UInt index, const CPyRef& item)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyTuple_SetItem(tuple, index, item);
	}

	MAXON_METHOD CPyRef CPyTuple_GetSlice(const CPyRef& tuple, UInt from, UInt to)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyTuple_GetSlice(tuple, from, to);
	}

	MAXON_METHOD Bool CPyTuple_CheckExact(const CPyRef& tuple)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyTuple_CheckExact(tuple);
	}

	MAXON_METHOD Bool CPyObject_HasAttrString(const CPyRef& o, const Char* attrName)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_HasAttrString(o, attrName);
	}

	MAXON_METHOD Bool CPyObject_SetAttrString(const CPyRef& o, const Char* name, const CPyRef& item)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_SetAttrString(o, name, item);
	}

	MAXON_METHOD CPyRef CPyObject_GetAttrString(const CPyRef& o, const Char* name)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_GetAttrString(o, name);
	}

	MAXON_METHOD CPyRef CPyObject_Call(const CPyRef& callable_object, const CPyRef& tupleArg, const CPyRef& kw)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_Call(callable_object, tupleArg, kw);
	}

	MAXON_METHOD CPyRef CPyObject_Str(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_Str(o);
	}

	MAXON_METHOD CPyRef CPyObject_Repr(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_Repr(o);
	}

	MAXON_METHOD CPyRef CPyObject_Dir(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_Dir(o);
	}

	MAXON_METHOD CPyRef CPyObject_RichCompare(const CPyRef& o1, const CPyRef& o2, Int32 opid)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_RichCompare(o1, o2, opid);
	}

	MAXON_METHOD Int64 CPyObject_Hash(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_Hash(o);
	}

	MAXON_METHOD Bool CPyObject_IsTrue(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_IsTrue(o);
	}

	MAXON_METHOD Bool CPyObject_Not(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_Not(o);
	}

	MAXON_METHOD Bool CPyCallable_Check(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyCallable_Check(o);
	}

	MAXON_METHOD Int CPyObject_Length(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_Length(o);
	}

	MAXON_METHOD CPyRef CPyObject_GetItem(const CPyRef& o, const CPyRef& key)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_GetItem(o, key);
	}

	MAXON_METHOD CPyRef CPyObject_GetItemInt(const CPyRef& o, Int index)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_GetItemInt(o, index);
	}

	MAXON_METHOD CPyRef CPyObject_GetItemString(const CPyRef& o, const Char* index)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_GetItemString(o, index);
	}

	MAXON_METHOD Bool CPyObject_DelItem(const CPyRef& o, const CPyRef& key)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_DelItem(o, key);
	}

	MAXON_METHOD Bool CPyObject_SetItem(const CPyRef& o, const CPyRef& key, const CPyRef& item)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_SetItem(o, key, item);
	}

	MAXON_METHOD Bool CPyObject_TypeCheck(const CPyRef& object, const CPyTypeRef& type)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_TypeCheck(object, type);
	}

	MAXON_METHOD CPyRef CPyObject_CallFunction(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_CallFunction(o);
	}

	MAXON_METHOD CPyRef CPySys_GetObject(const Char* name)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPySys_GetObject(name);
	}

	MAXON_METHOD Bool CPySys_SetObject(const Char* name, const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPySys_SetObject(name, o);
	}

	MAXON_METHOD Result<void> CPy_SetPath(const BaseArray<Url>& paths)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_SetPath(paths);
	}

	MAXON_METHOD Result<void> CPySys_SetPath(const BaseArray<Url>& paths, PATHHANDLE add)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPySys_SetPath(paths, add);
	}

	MAXON_METHOD Result<void> CPySys_SetArgvEx(const BaseArray<String>& args, Bool updatepath)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPySys_SetArgvEx(args, updatepath);
	}

	MAXON_METHOD BaseArray<Url> CPySys_GetPath()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPySys_GetPath();
	}

	MAXON_METHOD Result<void> CPySite_AddSiteDir(const Url& siteDir)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPySite_AddSiteDir(siteDir);
	}

	MAXON_METHOD Bool CPyUnicode_Check(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyUnicode_Check(o);
	}

	MAXON_METHOD CPyRef CPyUnicode_FromString(const Char* str) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyUnicode_FromString(str);
	}

	MAXON_METHOD CPyRef CPyUnicode_FromStringAndSize(const Block<const Char>& block)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyUnicode_FromStringAndSize(block);
	}

	MAXON_METHOD Result<String> CPyUnicode_AsString(const CPyRef& str)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyUnicode_AsString(str);
	}

	MAXON_METHOD const Char* CPyUnicode_AsCString(const CPyRef& str)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyUnicode_AsCString(str);
	}

	MAXON_METHOD Int CPyUnicode_GetLength(const CPyRef& str)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyUnicode_GetLength(str);
	}

	MAXON_METHOD CPyRef CPyObject_GetIter(const CPyRef& o) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_GetIter(o);
	}

	MAXON_METHOD CPyRef CPyIter_Next(const CPyRef& it) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyIter_Next(it);
	}

	MAXON_METHOD CPyRef CPyDict_New() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_New();
	}

	MAXON_METHOD CPyRef CPyDict_GetItem(const CPyRef& dict, const CPyRef& key, Bool raiseKeyError)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_GetItem(dict, key, raiseKeyError);
	}

	MAXON_METHOD CPyRef CPyDict_GetItemString(const CPyRef& dict, const Char* key, Bool raiseKeyError)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_GetItemString(dict, key, raiseKeyError);
	}

	MAXON_METHOD Bool CPyDict_SetItem(const CPyRef& dict, const CPyRef& key, const CPyRef& item)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_SetItem(dict, key, item);
	}

	MAXON_METHOD Bool CPyDict_DelItem(const CPyRef& dict, const CPyRef& key)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_DelItem(dict, key);
	}

	MAXON_METHOD CONTAINS CPyDict_Contains(const CPyRef& dict, const CPyRef& key)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_Contains(dict, key);
	}

	MAXON_METHOD void CPyDict_Clear(const CPyRef& dict)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_Clear(dict);
	}

	MAXON_METHOD Bool CPyDict_Next(const CPyRef& dict, Int& pos, CPyRef& key, CPyRef& value)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_Next(dict, pos, key, value);
	}

	MAXON_METHOD CPyRef CPyDict_Keys(const CPyRef& dict)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_Keys(dict);
	}

	MAXON_METHOD CPyRef CPyDict_Values(const CPyRef& dict)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_Values(dict);
	}

	MAXON_METHOD CPyRef CPyDict_Items(const CPyRef& dict)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_Items(dict);
	}

	MAXON_METHOD Int CPyDict_Size(const CPyRef& dict)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_Size(dict);
	}

	MAXON_METHOD CPyRef CPyDict_Copy(const CPyRef& dict)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_Copy(dict);
	}

	MAXON_METHOD Bool CPyDict_SetItemString(const CPyRef& dict, const Char* key, const CPyRef& item) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_SetItemString(dict, key, item);
	}

	MAXON_METHOD Bool CPyDict_Check(const CPyRef& o) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_Check(o);
	}

	MAXON_METHOD CPyRef CPyList_New(UInt size)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyList_New(size);
	}

	MAXON_METHOD Bool CPyList_CheckExact(const CPyRef& list)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyList_CheckExact(list);
	}

	MAXON_METHOD Int CPyList_Size(const CPyRef& list)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyList_Size(list);
	}

	MAXON_METHOD CPyRef CPyList_GetItem(const CPyRef& list, UInt index)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyList_GetItem(list, index);
	}

	MAXON_METHOD Bool CPyList_SetItem(const CPyRef& list, UInt anonymous_param_2, const CPyRef& item)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyList_SetItem(list, anonymous_param_2, item);
	}

	MAXON_METHOD Bool CPyList_Insert(const CPyRef& list, UInt anonymous_param_2, const CPyRef& item)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyList_Insert(list, anonymous_param_2, item);
	}

	MAXON_METHOD Bool CPyList_Append(const CPyRef& list, const CPyRef& item)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyList_Append(list, item);
	}

	MAXON_METHOD CPyRef CPyList_GetSlice(const CPyRef& list, UInt from, UInt to)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyList_GetSlice(list, from, to);
	}

	MAXON_METHOD Bool CPyList_SetSlice(const CPyRef& list, UInt from, UInt to, const CPyRef& item)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyList_SetSlice(list, from, to, item);
	}

	MAXON_METHOD Bool CPyList_Sort(const CPyRef& list)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyList_Sort(list);
	}

	MAXON_METHOD Bool CPyList_Reverse(const CPyRef& list)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyList_Reverse(list);
	}

	MAXON_METHOD CPyRef CPyList_AsTuple(const CPyRef& list)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyList_AsTuple(list);
	}

	MAXON_METHOD Bool CPyDict_DelItemString(const CPyRef& p, const Char* key)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_DelItemString(p, key);
	}

	MAXON_METHOD Bool CPyModule_Check(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyModule_Check(o);
	}

	MAXON_METHOD Bool CPyModule_AddObject(const CPyRef& module, const Char* name, const CPyRef& value)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyModule_AddObject(module, name, value);
	}

	MAXON_METHOD CPyRef CPyModule_GetDict(const CPyRef& module)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyModule_GetDict(module);
	}

	MAXON_METHOD Bool CPyModule_AddIntConstant(const CPyRef& mod, const Char* name, long value)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyModule_AddIntConstant(mod, name, value);
	}

	MAXON_METHOD CPyRef CPyImport_ImportModule(const Char* name)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyImport_ImportModule(name);
	}

	MAXON_METHOD CPyRef CPyImport_GetImporter(const CPyRef& path)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyImport_GetImporter(path);
	}

	MAXON_METHOD CPyRef CPyImport_GetModuleDict()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyImport_GetModuleDict();
	}

	MAXON_METHOD Bool CPyType_Check(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyType_Check(o);
	}

	MAXON_METHOD Bool CPyType_IsSubtype(const CPyTypeRef& a, const CPyTypeRef& b)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyType_IsSubtype(a, b);
	}

	MAXON_METHOD Bool CPyType_HasFeature(const CPyTypeRef& type, Int64 f) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyType_HasFeature(type, f);
	}

	MAXON_METHOD Bool CPyType_FastSubclass(const CPyTypeRef& type, Int64 f) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyType_FastSubclass(type, f);
	}

	MAXON_METHOD Result<String> CPyType_GetName(const CPyTypeRef& type)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyType_GetName(type);
	}

	MAXON_METHOD Bool CPyType_Ready(CPyTypeRef& type)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyType_Ready(type);
	}

	MAXON_METHOD NativePyThreadState* CPyEval_SaveThread()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyEval_SaveThread();
	}

	MAXON_METHOD void CPyEval_RestoreThread(NativePyThreadState* state)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyEval_RestoreThread(state);
	}

	MAXON_METHOD Bool CPyEval_ThreadsInitialized()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyEval_ThreadsInitialized();
	}

	MAXON_METHOD void CPyEval_InitThreads()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyEval_InitThreads();
	}

	MAXON_METHOD void CPyEval_AcquireThread(NativePyThreadState* state)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyEval_AcquireThread(state);
	}

	MAXON_METHOD void CPyEval_ReleaseThread(NativePyThreadState* state)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyEval_ReleaseThread(state);
	}

	MAXON_METHOD void CPyEval_ReInitThreads()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyEval_ReInitThreads();
	}

	MAXON_METHOD CPyRef CPyEval_GetBuiltins() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyEval_GetBuiltins();
	}

	MAXON_METHOD CPyRef CPyEval_EvalCode(const CPyCodeRef& code, const CPyRef& globals, const CPyRef& locals) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyEval_EvalCode(code, globals, locals);
	}

	MAXON_METHOD Bool CPyFloat_Check(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyFloat_Check(o);
	}

	MAXON_METHOD CPyRef CPyFloat_FromFloat32(Float32 value)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyFloat_FromFloat32(value);
	}

	MAXON_METHOD CPyRef CPyFloat_FromFloat64(Float64 value)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyFloat_FromFloat64(value);
	}

	MAXON_METHOD Float64 CPyFloat_AsFloat64(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyFloat_AsFloat64(o);
	}

	MAXON_METHOD Bool CPyLong_Check(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyLong_Check(o);
	}

	MAXON_METHOD CPyRef CPyBool_FromBool(Bool value)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyBool_FromBool(value);
	}

	MAXON_METHOD CPyRef CPyLong_FromInt16(Int16 value)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyLong_FromInt16(value);
	}

	MAXON_METHOD CPyRef CPyLong_FromUInt16(UInt16 value)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyLong_FromUInt16(value);
	}

	MAXON_METHOD CPyRef CPyLong_FromInt32(Int32 value)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyLong_FromInt32(value);
	}

	MAXON_METHOD CPyRef CPyLong_FromUInt32(UInt32 value)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyLong_FromUInt32(value);
	}

	MAXON_METHOD CPyRef CPyLong_FromInt64(Int64 value)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyLong_FromInt64(value);
	}

	MAXON_METHOD CPyRef CPyLong_FromUInt64(UInt64 value)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyLong_FromUInt64(value);
	}

	MAXON_METHOD Int16 CPyLong_AsInt16(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyLong_AsInt16(o);
	}

	MAXON_METHOD UInt16 CPyLong_AsUInt16(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyLong_AsUInt16(o);
	}

	MAXON_METHOD Int32 CPyLong_AsInt32(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyLong_AsInt32(o);
	}

	MAXON_METHOD UInt32 CPyLong_AsUInt32(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyLong_AsUInt32(o);
	}

	MAXON_METHOD Int64 CPyLong_AsInt64(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyLong_AsInt64(o);
	}

	MAXON_METHOD UInt64 CPyLong_AsUInt64(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyLong_AsUInt64(o);
	}

	MAXON_METHOD Bool CPyNumber_Check(const CPyRef& o)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyNumber_Check(o);
	}

	MAXON_METHOD MPyFunctionRef MPyFunction_New(const reflection::Function* func)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).MPyFunction_New(func);
	}

	MAXON_METHOD MPyMemberRef MPyMember_New(const reflection::Member* member)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).MPyMember_New(member);
	}

	MAXON_METHOD Result<void> CPyMem_SetAllocator(CPyMemAllocatorDomain domain, CPyMemAllocatorEx* allocator)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyMem_SetAllocator(std::forward<CPyMemAllocatorDomain>(domain), allocator);
	}

	MAXON_METHOD MPyClassRef MPyClass_New(const reflection::Class* cls)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).MPyClass_New(cls);
	}

	MAXON_METHOD Int32* CPy_DebugFlag()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_DebugFlag();
	}

	MAXON_METHOD Int32* CPy_VerboseFlag()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_VerboseFlag();
	}

	MAXON_METHOD Int32* CPy_InteractiveFlag()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_InteractiveFlag();
	}

	MAXON_METHOD Int32* CPy_InspectFlag()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_InspectFlag();
	}

	MAXON_METHOD Int32* CPy_OptimizeFlag()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_OptimizeFlag();
	}

	MAXON_METHOD Int32* CPy_NoSiteFlag()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_NoSiteFlag();
	}

	MAXON_METHOD Int32* CPy_BytesWarningFlag()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_BytesWarningFlag();
	}

	MAXON_METHOD Int32* CPy_FrozenFlag()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_FrozenFlag();
	}

	MAXON_METHOD Int32* CPy_IgnoreEnvironmentFlag()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_IgnoreEnvironmentFlag();
	}

	MAXON_METHOD Int32* CPy_DontWriteBytecodeFlag()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_DontWriteBytecodeFlag();
	}

	MAXON_METHOD Int32* CPy_NoUserSiteDirectory()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPy_NoUserSiteDirectory();
	}

	MAXON_METHOD CPyConstRef CPyExc_BaseException()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_BaseException();
	}

	MAXON_METHOD CPyConstRef CPyExc_Exception()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_Exception();
	}

	MAXON_METHOD CPyConstRef CPyExc_StopIteration()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_StopIteration();
	}

	MAXON_METHOD CPyConstRef CPyExc_GeneratorExit()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_GeneratorExit();
	}

	MAXON_METHOD CPyConstRef CPyExc_StandardError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_StandardError();
	}

	MAXON_METHOD CPyConstRef CPyExc_ArithmeticError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_ArithmeticError();
	}

	MAXON_METHOD CPyConstRef CPyExc_LookupError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_LookupError();
	}

	MAXON_METHOD CPyConstRef CPyExc_AssertionError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_AssertionError();
	}

	MAXON_METHOD CPyConstRef CPyExc_AttributeError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_AttributeError();
	}

	MAXON_METHOD CPyConstRef CPyExc_EOFError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_EOFError();
	}

	MAXON_METHOD CPyConstRef CPyExc_FloatingPointError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_FloatingPointError();
	}

	MAXON_METHOD CPyConstRef CPyExc_EnvironmentError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_EnvironmentError();
	}

	MAXON_METHOD CPyConstRef CPyExc_IOError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_IOError();
	}

	MAXON_METHOD CPyConstRef CPyExc_OSError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_OSError();
	}

	MAXON_METHOD CPyConstRef CPyExc_ImportError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_ImportError();
	}

	MAXON_METHOD CPyConstRef CPyExc_IndexError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_IndexError();
	}

	MAXON_METHOD CPyConstRef CPyExc_KeyError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_KeyError();
	}

	MAXON_METHOD CPyConstRef CPyExc_KeyboardInterrupt()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_KeyboardInterrupt();
	}

	MAXON_METHOD CPyConstRef CPyExc_MemoryError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_MemoryError();
	}

	MAXON_METHOD CPyConstRef CPyExc_NameError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_NameError();
	}

	MAXON_METHOD CPyConstRef CPyExc_OverflowError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_OverflowError();
	}

	MAXON_METHOD CPyConstRef CPyExc_RuntimeError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_RuntimeError();
	}

	MAXON_METHOD CPyConstRef CPyExc_NotImplementedError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_NotImplementedError();
	}

	MAXON_METHOD CPyConstRef CPyExc_SyntaxError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_SyntaxError();
	}

	MAXON_METHOD CPyConstRef CPyExc_IndentationError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_IndentationError();
	}

	MAXON_METHOD CPyConstRef CPyExc_TabError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_TabError();
	}

	MAXON_METHOD CPyConstRef CPyExc_ReferenceError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_ReferenceError();
	}

	MAXON_METHOD CPyConstRef CPyExc_SystemError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_SystemError();
	}

	MAXON_METHOD CPyConstRef CPyExc_SystemExit()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_SystemExit();
	}

	MAXON_METHOD CPyConstRef CPyExc_TypeError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_TypeError();
	}

	MAXON_METHOD CPyConstRef CPyExc_UnboundLocalError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_UnboundLocalError();
	}

	MAXON_METHOD CPyConstRef CPyExc_UnicodeError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_UnicodeError();
	}

	MAXON_METHOD CPyConstRef CPyExc_UnicodeEncodeError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_UnicodeEncodeError();
	}

	MAXON_METHOD CPyConstRef CPyExc_UnicodeDecodeError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_UnicodeDecodeError();
	}

	MAXON_METHOD CPyConstRef CPyExc_UnicodeTranslateError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_UnicodeTranslateError();
	}

	MAXON_METHOD CPyConstRef CPyExc_ValueError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_ValueError();
	}

	MAXON_METHOD CPyConstRef CPyExc_ZeroDivisionError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_ZeroDivisionError();
	}

	MAXON_METHOD CPyConstRef CPyExc_WindowsError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_WindowsError();
	}

	MAXON_METHOD CPyConstRef CPyExc_BufferError()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_BufferError();
	}

	MAXON_METHOD CPyConstRef CPyExc_MemoryErrorInst()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_MemoryErrorInst();
	}

	MAXON_METHOD CPyConstRef CPyExc_RecursionErrorInst()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_RecursionErrorInst();
	}

	MAXON_METHOD CPyConstRef CPyExc_Warning()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_Warning();
	}

	MAXON_METHOD CPyConstRef CPyExc_UserWarning()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_UserWarning();
	}

	MAXON_METHOD CPyConstRef CPyExc_DeprecationWarning()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_DeprecationWarning();
	}

	MAXON_METHOD CPyConstRef CPyExc_PendingDeprecationWarning()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_PendingDeprecationWarning();
	}

	MAXON_METHOD CPyConstRef CPyExc_SyntaxWarning()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_SyntaxWarning();
	}

	MAXON_METHOD CPyConstRef CPyExc_RuntimeWarning()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_RuntimeWarning();
	}

	MAXON_METHOD CPyConstRef CPyExc_FutureWarning()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_FutureWarning();
	}

	MAXON_METHOD CPyConstRef CPyExc_ImportWarning()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_ImportWarning();
	}

	MAXON_METHOD CPyConstRef CPyExc_UnicodeWarning()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_UnicodeWarning();
	}

	MAXON_METHOD CPyConstRef CPyExc_BytesWarning()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyExc_BytesWarning();
	}

	MAXON_METHOD CPyTypeConstRef CPyNullImporter_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyNullImporter_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPySuper_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPySuper_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPyBool_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyBool_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPyObject_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPyModule_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyModule_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPyUnicode_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyUnicode_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPyLong_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyLong_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPyFloat_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyFloat_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPyTuple_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyTuple_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPyList_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyList_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPyDict_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyDict_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPyClass_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyClass_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPyTraceBack_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyTraceBack_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPySlice_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPySlice_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPyType_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyType_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPyMemoryView_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyMemoryView_Type();
	}

	MAXON_METHOD const PyChar* ConvertAndCacheString(const String& str, PyStringEncodings encoding, UInt* size)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).ConvertAndCacheString(str, std::forward<PyStringEncodings>(encoding), size);
	}

	MAXON_METHOD Result<void> RegisterSpecificPythonClass(const Id& typeId, const CPyTypeRef& type)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).RegisterSpecificPythonClass(typeId, type);
	}

	MAXON_METHOD Result<void> PrivateRegisterBuiltinConverter(const DataType& dt, const DelegatePyObject_AsData& f1, const DelegatePyObject_FromData<>& f2)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).PrivateRegisterBuiltinConverter(dt, f1, f2);
	}

	MAXON_METHOD Url GetSpecialPath(SPECIALPATH anonymous_param_1)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetSpecialPath(anonymous_param_1);
	}

	MAXON_METHOD void RegisterSpecialPath(SPECIALPATH anonymous_param_1, const Url& path)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).RegisterSpecialPath(anonymous_param_1, path);
	}

	MAXON_METHOD CPyTypeConstRef MPyDataCapsule_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).MPyDataCapsule_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPyData_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyData_Type();
	}

	MAXON_METHOD CPyTypeConstRef CPyCapsule_Type()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyCapsule_Type();
	}

	MAXON_METHOD CPyRef PrivateGetCurrentCallerContext()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).PrivateGetCurrentCallerContext();
	}

	MAXON_METHOD CPyRef MPyDataType_ToMapperInstance(const CPyRef& capsule)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).MPyDataType_ToMapperInstance(capsule);
	}

	MAXON_METHOD CPyRef MPyData_ToMapperInstance(const MPyDataRef& capsule)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).MPyData_ToMapperInstance(capsule);
	}

	MAXON_METHOD CPyRef CPyObject_ToMapperInstance(const DataType& dt, const CPyRef& capsule)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_ToMapperInstance(dt, capsule);
	}

	MAXON_METHOD Result<void> AssociateDataTypeWithPythonTypes(const DataType& dt, const CPyRef& type)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).AssociateDataTypeWithPythonTypes(dt, type);
	}

	MAXON_METHOD Result<CPyRef> GetAssociatedDataType(const DataType& dt)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetAssociatedDataType(dt);
	}

	MAXON_METHOD DelegatePyObject_FromData<>* GetConverterPyObject_FromData(const DataType& dt)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetConverterPyObject_FromData(dt);
	}

	MAXON_METHOD MPyDataRef MPyData_New(Data& data)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).MPyData_New(data);
	}

	MAXON_METHOD MPyDataRef MPyData_New(const DataType& dt, Generic* data, Bool owner, const DataType& mapDt)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).MPyData_New(dt, data, owner, mapDt);
	}

	MAXON_METHOD MPyDataTypeRef MPyDataType_New(const DataType& dt)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).MPyDataType_New(dt);
	}

	MAXON_METHOD Bool MPyDataType_CheckExact(const CPyRef& o) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).MPyDataType_CheckExact(o);
	}

	MAXON_METHOD const DataType& MPyDataType_GetDataType(const MPyDataTypeRef& o) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).MPyDataType_GetDataType(o);
	}

	MAXON_METHOD Bool MPyData_CheckExact(const CPyRef& o) const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).MPyData_CheckExact(o);
	}

	MAXON_METHOD Result<Data*> CPyObject_AsData(Int stackDepth, const CPyRef& obj, const DataType& expected, BlockArray<Data>& k, BaseArray<reflection::Argument>* n)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_AsData(stackDepth, obj, expected, k, n);
	}

	MAXON_METHOD Result<BaseArray<TYPE_CONVERSION_TUPLE>> GetRegisteredTypesWithConversions()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetRegisteredTypesWithConversions();
	}

	MAXON_METHOD Result<DataType> ParseDataType(const CPyRef& args, Int32 argIndex, Bool canBeNone)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).ParseDataType(args, argIndex, canBeNone);
	}

	MAXON_METHOD void SetError(const Error& err)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).SetError(err);
	}

	MAXON_METHOD void SetError(const ErrorPtr& err)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).SetError(err);
	}

	MAXON_METHOD CPyRef MaxonConvertAuto(const CPyRef& capsule)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).MaxonConvertAuto(capsule);
	}

	MAXON_METHOD CPyRef CPyObject_FromGeneric(const DataType& origDt, const Generic* object, OWNERSHIP ownership, const CPyTypeRef* expected, Int* count)
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CPyObject_FromGeneric(origDt, object, ownership, expected, count);
	}

	MAXON_METHOD CPyRef CreateGlobalDictionary() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).CreateGlobalDictionary();
	}

	MAXON_METHOD Result<BaseArray<SourceLocation>> GetCurrentTraceback()
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetCurrentTraceback();
	}

	MAXON_METHOD Class<CPyRef> GetCPyRefClass() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetCPyRefClass();
	}

	MAXON_METHOD Class<CPyTypeRef> GetCPyTypeRefClass() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetCPyTypeRefClass();
	}

	MAXON_METHOD Class<CPyFrameRef> GetCPyFrameRefClass() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetCPyFrameRefClass();
	}

	MAXON_METHOD Class<CPyTracebackRef> GetCPyTracebackRefClass() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetCPyTracebackRefClass();
	}

	MAXON_METHOD Class<CPyCodeRef> GetCPyCodeRefClass() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetCPyCodeRefClass();
	}

	MAXON_METHOD Class<MPyClassRef> GetMPyClassRefClass() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetMPyClassRefClass();
	}

	MAXON_METHOD Class<MPyMemberRef> GetMPyMemberRefClass() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetMPyMemberRefClass();
	}

	MAXON_METHOD Class<MPyFunctionRef> GetMPyFunctionRefClass() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetMPyFunctionRefClass();
	}

	MAXON_METHOD Class<MPyDataTypeRef> GetMPyDataTypeRefClass() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetMPyDataTypeRefClass();
	}

	MAXON_METHOD Class<MPyDataRef> GetMPyDataRefClass() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetMPyDataRefClass();
	}

	MAXON_METHOD Class<MPyCallerContextRef> GetMPyCallerContextRefClass() const
	{
		return maxon::Cast<CPythonLibraryRef>(self.GetDecoratedObject()).GetMPyCallerContextRefClass();
	}

};

class PyModuleDecoratorImpl : public maxon::Component<PyModuleDecoratorImpl, PyModuleInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> GetFunctions37(BaseArray<NativePyCFunctionTable>& functions)
	{
		return maxon::Cast<PyModuleRef>(self.GetDecoratedObject()).GetFunctions37(functions);
	}

	MAXON_METHOD Result<void> GetConstants(BaseArray<Tuple<const Char*, Int32>>& constants)
	{
		return maxon::Cast<PyModuleRef>(self.GetDecoratedObject()).GetConstants(constants);
	}

};
