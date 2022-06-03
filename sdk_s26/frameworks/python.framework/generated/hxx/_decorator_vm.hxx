// This file contains decorator implementations for the interfaces of vm.h. They are intended for copy&paste usage only.

class LibraryDecoratorImpl : public maxon::Component<LibraryDecoratorImpl, LibraryInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
};

class VmDebuggerConnectionDecoratorImpl : public maxon::Component<VmDebuggerConnectionDecoratorImpl, VmDebuggerConnectionInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD String GetName() const
	{
		return maxon::Cast<VmDebuggerConnectionRef>(self.GetDecoratedObject()).GetName();
	}

	MAXON_METHOD Url GetPath() const
	{
		return maxon::Cast<VmDebuggerConnectionRef>(self.GetDecoratedObject()).GetPath();
	}

	MAXON_METHOD String GetStartupScript() const
	{
		return maxon::Cast<VmDebuggerConnectionRef>(self.GetDecoratedObject()).GetStartupScript();
	}

	MAXON_METHOD String GetShutdownScript() const
	{
		return maxon::Cast<VmDebuggerConnectionRef>(self.GetDecoratedObject()).GetShutdownScript();
	}

};

class VirtualMachineScopeDecoratorImpl : public maxon::Component<VirtualMachineScopeDecoratorImpl, VirtualMachineScopeInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug)
	{
		return maxon::Cast<VirtualMachineScopeRef>(self.GetDecoratedObject()).Init(identifier, code, errorHandling, debug);
	}

	MAXON_METHOD Result<void> Add(const String& name, const Data& data)
	{
		return maxon::Cast<VirtualMachineScopeRef>(self.GetDecoratedObject()).Add(name, data);
	}

	MAXON_METHOD Result<Data> Get(const String& name)
	{
		return maxon::Cast<VirtualMachineScopeRef>(self.GetDecoratedObject()).Get(name);
	}

	MAXON_METHOD Result<void> Execute()
	{
		return maxon::Cast<VirtualMachineScopeRef>(self.GetDecoratedObject()).Execute();
	}

	MAXON_METHOD Result<Data*> PrivateInvoke(const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments)
	{
		return maxon::Cast<VirtualMachineScopeRef>(self.GetDecoratedObject()).PrivateInvoke(name, helperStack, expected, arguments);
	}

	MAXON_METHOD Result<void> ErrorHandling()
	{
		return maxon::Cast<VirtualMachineScopeRef>(self.GetDecoratedObject()).ErrorHandling();
	}

	MAXON_METHOD Result<void> _PrivateInit(const LibraryRef& lib)
	{
		return maxon::Cast<VirtualMachineScopeRef>(self.GetDecoratedObject())._PrivateInit(lib);
	}

};

class VirtualMachineDecoratorImpl : public maxon::Component<VirtualMachineDecoratorImpl, VirtualMachineInterface, maxon::DecoratorInterface>
{
	MAXON_COMPONENT();

public:
	MAXON_METHOD Result<void> Init(const LoadRuntime& runtimeInfo, const DataDictionary& settings)
	{
		return maxon::Cast<VirtualMachineRef>(self.GetDecoratedObject()).Init(runtimeInfo, settings);
	}

	MAXON_METHOD void Free()
	{
		return maxon::Cast<VirtualMachineRef>(self.GetDecoratedObject()).Free();
	}

	MAXON_METHOD Result<VirtualMachineScopeRef> CreateScope()
	{
		return maxon::Cast<VirtualMachineRef>(self.GetDecoratedObject()).CreateScope();
	}

	MAXON_METHOD String GetName()
	{
		return maxon::Cast<VirtualMachineRef>(self.GetDecoratedObject()).GetName();
	}

	MAXON_METHOD String GetVersion()
	{
		return maxon::Cast<VirtualMachineRef>(self.GetDecoratedObject()).GetVersion();
	}

	MAXON_METHOD String GetCopyright()
	{
		return maxon::Cast<VirtualMachineRef>(self.GetDecoratedObject()).GetCopyright();
	}

	MAXON_METHOD String GetCompiler()
	{
		return maxon::Cast<VirtualMachineRef>(self.GetDecoratedObject()).GetCompiler();
	}

	MAXON_METHOD String GetBuildInfo()
	{
		return maxon::Cast<VirtualMachineRef>(self.GetDecoratedObject()).GetBuildInfo();
	}

	MAXON_METHOD Result<void> EnterInteractiveMode()
	{
		return maxon::Cast<VirtualMachineRef>(self.GetDecoratedObject()).EnterInteractiveMode();
	}

	MAXON_METHOD Result<void> Execute(const String& code)
	{
		return maxon::Cast<VirtualMachineRef>(self.GetDecoratedObject()).Execute(code);
	}

	MAXON_METHOD Result<void> Execute(const Url& filepath)
	{
		return maxon::Cast<VirtualMachineRef>(self.GetDecoratedObject()).Execute(filepath);
	}

	MAXON_METHOD Result<void> ExecuteModule(const String& name)
	{
		return maxon::Cast<VirtualMachineRef>(self.GetDecoratedObject()).ExecuteModule(name);
	}

	MAXON_METHOD Result<void> GetDocumentString(const String& code, DocStringMeta& meta)
	{
		return maxon::Cast<VirtualMachineRef>(self.GetDecoratedObject()).GetDocumentString(code, meta);
	}

	MAXON_METHOD LibraryRef GetLibraryRef()
	{
		return maxon::Cast<VirtualMachineRef>(self.GetDecoratedObject()).GetLibraryRef();
	}

	MAXON_METHOD Result<BaseArray<Runtime>> GetAllAvailableVirtualMachineLibraries() const
	{
		return maxon::Cast<VirtualMachineRef>(self.GetDecoratedObject()).GetAllAvailableVirtualMachineLibraries();
	}

};
