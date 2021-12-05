#if 1
namespace maxon
{
#ifdef MAXON_TARGET_WINDOWS
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_LibraryInterface(LibraryInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::LibraryRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class LibraryInterface::ProxyComponent : public maxon::Component<ProxyComponent, LibraryInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, LibraryInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(LibraryInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_LibraryInterface_Static(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LibraryInterface::Hxx2::StaticMTable::_instance._LibraryInterface_ConsoleIsAvailable)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
#ifdef MAXON_TARGET_WINDOWS
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LibraryInterface::Hxx2::StaticMTable::_instance._LibraryInterface_GetVsVersion)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "compilerVersion\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LibraryInterface::Hxx2::StaticMTable::_instance._LibraryInterface_GetVsRuntimeLibrary)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "version\0release\0", 0LL, nullptr),
#endif
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LibraryInterface::Hxx2::StaticMTable::_instance._LibraryInterface_GetFileContent)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "filepath\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LibraryInterface::Hxx2::StaticMTable::_instance._LibraryInterface_SetFileContent)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "filepath\0str\0append\0", 21LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&LibraryInterface::_staticInterface), maxon::ToBlock(functions));
	}
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_LibraryInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&LibraryInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_LibraryInterface(nullptr, &LibraryInterface::ProxyComponent::_descriptor, &RegisterReflection_LibraryInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_LibraryInterface_Static("net.maxon.python.interface.library", nullptr, &RegisterReflection_LibraryInterface_Static, &PRIVATE_MAXON_MODULE);
#endif
#ifdef MAXON_COMPILER_GCC
#endif
#ifdef MAXON_COMPILER_GCC
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_VmDebuggerConnectionInterface(VmDebuggerConnectionInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::VmDebuggerConnectionRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class VmDebuggerConnectionInterface::ProxyComponent : public maxon::Component<ProxyComponent, VmDebuggerConnectionInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, VmDebuggerConnectionInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		String GetName() const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VmDebuggerConnectionInterface>();
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VmDebuggerConnectionInterface_GetName_Offset)};
			(*handler_)(_fn_VmDebuggerConnectionInterface_GetName, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, const maxon::GenericComponent*>::Invoke, (const void*) mt_._VmDebuggerConnectionInterface_GetName));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VmDebuggerConnectionInterface_GetName;
		Url GetPath() const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VmDebuggerConnectionInterface>();
			Url proxy_result = maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VmDebuggerConnectionInterface_GetPath_Offset)};
			(*handler_)(_fn_VmDebuggerConnectionInterface_GetPath, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Url, const maxon::GenericComponent*>::Invoke, (const void*) mt_._VmDebuggerConnectionInterface_GetPath));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VmDebuggerConnectionInterface_GetPath;
#ifdef MAXON_COMPILER_GCC
#endif
		String GetStartupScript() const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VmDebuggerConnectionInterface>();
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VmDebuggerConnectionInterface_GetStartupScript_Offset)};
			(*handler_)(_fn_VmDebuggerConnectionInterface_GetStartupScript, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, const maxon::GenericComponent*>::Invoke, (const void*) mt_._VmDebuggerConnectionInterface_GetStartupScript));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VmDebuggerConnectionInterface_GetStartupScript;
		String GetShutdownScript() const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VmDebuggerConnectionInterface>();
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VmDebuggerConnectionInterface_GetShutdownScript_Offset)};
			(*handler_)(_fn_VmDebuggerConnectionInterface_GetShutdownScript, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, const maxon::GenericComponent*>::Invoke, (const void*) mt_._VmDebuggerConnectionInterface_GetShutdownScript));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VmDebuggerConnectionInterface_GetShutdownScript;
#ifdef MAXON_COMPILER_GCC
#endif
	};
	const maxon::reflection::Function* VmDebuggerConnectionInterface::ProxyComponent::_fn_VmDebuggerConnectionInterface_GetName;
	const maxon::reflection::Function* VmDebuggerConnectionInterface::ProxyComponent::_fn_VmDebuggerConnectionInterface_GetPath;
#ifdef MAXON_COMPILER_GCC
#endif
	const maxon::reflection::Function* VmDebuggerConnectionInterface::ProxyComponent::_fn_VmDebuggerConnectionInterface_GetStartupScript;
	const maxon::reflection::Function* VmDebuggerConnectionInterface::ProxyComponent::_fn_VmDebuggerConnectionInterface_GetShutdownScript;
#ifdef MAXON_COMPILER_GCC
#endif
	PRIVATE_MAXON_COMPONENT_REGISTER(VmDebuggerConnectionInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_VmDebuggerConnectionInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, VmDebuggerConnectionInterface, _VmDebuggerConnectionInterface_GetName),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, VmDebuggerConnectionInterface, _VmDebuggerConnectionInterface_GetPath),
#ifdef MAXON_COMPILER_GCC
#endif
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, VmDebuggerConnectionInterface, _VmDebuggerConnectionInterface_GetStartupScript),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, VmDebuggerConnectionInterface, _VmDebuggerConnectionInterface_GetShutdownScript),
#ifdef MAXON_COMPILER_GCC
#endif
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&VmDebuggerConnectionInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_VmDebuggerConnectionInterface(nullptr, &VmDebuggerConnectionInterface::ProxyComponent::_descriptor, &RegisterReflection_VmDebuggerConnectionInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_VirtualMachineScopeInterface(VirtualMachineScopeInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::VirtualMachineScopeRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class VirtualMachineScopeInterface::ProxyComponent : public maxon::Component<ProxyComponent, VirtualMachineScopeInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, VirtualMachineScopeInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Init(const String& identifier, const String& code, ERRORHANDLING errorHandling, const VmDebuggerConnectionRef* debug) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineScopeInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_Init_Offset), maxon::reflection::Argument::ByReference(identifier), maxon::reflection::Argument::ByReference(code), maxon::reflection::Argument::ByValue(errorHandling), maxon::reflection::Argument::ByValue(debug)};
			(*handler_)(_fn_VirtualMachineScopeInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const String&, const String&, ERRORHANDLING, const VmDebuggerConnectionRef*>::Invoke, (const void*) mt_._VirtualMachineScopeInterface_Init));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineScopeInterface_Init;
		Result<void> Add(const String& name, const Data& data) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineScopeInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_Add_Offset), maxon::reflection::Argument::ByReference(name), maxon::reflection::Argument::ByReference(data)};
			(*handler_)(_fn_VirtualMachineScopeInterface_Add, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const String&, const Data&>::Invoke, (const void*) mt_._VirtualMachineScopeInterface_Add));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineScopeInterface_Add;
		Result<Data> Get(const String& name) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineScopeInterface>();
			Result<Data> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_Get_Offset), maxon::reflection::Argument::ByReference(name)};
			(*handler_)(_fn_VirtualMachineScopeInterface_Get, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Data>, maxon::GenericComponent*, const String&>::Invoke, (const void*) mt_._VirtualMachineScopeInterface_Get));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineScopeInterface_Get;
		Result<void> Execute() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineScopeInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_Execute_Offset)};
			(*handler_)(_fn_VirtualMachineScopeInterface_Execute, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_._VirtualMachineScopeInterface_Execute));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineScopeInterface_Execute;
		Result<Data*> PrivateInvoke(const String& name, BlockArray<Data>& helperStack, const DataType& expected, const Block<Data*>* arguments) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineScopeInterface>();
			Result<Data*> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_PrivateInvoke_Offset), maxon::reflection::Argument::ByReference(name), maxon::reflection::Argument::ByReference(helperStack), maxon::reflection::Argument::ByReference(expected), maxon::reflection::Argument::ByValue(arguments)};
			(*handler_)(_fn_VirtualMachineScopeInterface_PrivateInvoke, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Data*>, maxon::GenericComponent*, const String&, BlockArray<Data>&, const DataType&, const Block<Data*>*>::Invoke, (const void*) mt_._VirtualMachineScopeInterface_PrivateInvoke));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineScopeInterface_PrivateInvoke;
		Result<void> ErrorHandling() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineScopeInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface_ErrorHandling_Offset)};
			(*handler_)(_fn_VirtualMachineScopeInterface_ErrorHandling, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_._VirtualMachineScopeInterface_ErrorHandling));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineScopeInterface_ErrorHandling;
		Result<void> _PrivateInit(const LibraryRef& lib) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineScopeInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineScopeInterface__PrivateInit_Offset), maxon::reflection::Argument::ByReference(lib)};
			(*handler_)(_fn_VirtualMachineScopeInterface__PrivateInit, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const LibraryRef&>::Invoke, (const void*) mt_._VirtualMachineScopeInterface__PrivateInit));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineScopeInterface__PrivateInit;
	};
	const maxon::reflection::Function* VirtualMachineScopeInterface::ProxyComponent::_fn_VirtualMachineScopeInterface_Init;
	const maxon::reflection::Function* VirtualMachineScopeInterface::ProxyComponent::_fn_VirtualMachineScopeInterface_Add;
	const maxon::reflection::Function* VirtualMachineScopeInterface::ProxyComponent::_fn_VirtualMachineScopeInterface_Get;
	const maxon::reflection::Function* VirtualMachineScopeInterface::ProxyComponent::_fn_VirtualMachineScopeInterface_Execute;
	const maxon::reflection::Function* VirtualMachineScopeInterface::ProxyComponent::_fn_VirtualMachineScopeInterface_PrivateInvoke;
	const maxon::reflection::Function* VirtualMachineScopeInterface::ProxyComponent::_fn_VirtualMachineScopeInterface_ErrorHandling;
	const maxon::reflection::Function* VirtualMachineScopeInterface::ProxyComponent::_fn_VirtualMachineScopeInterface__PrivateInit;
	PRIVATE_MAXON_COMPONENT_REGISTER(VirtualMachineScopeInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_VirtualMachineScopeInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "identifier\0code\0errorHandling\0debug\0", 85LL, VirtualMachineScopeInterface, _VirtualMachineScopeInterface_Init),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "name\0data\0", 5LL, VirtualMachineScopeInterface, _VirtualMachineScopeInterface_Add),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "name\0", 1LL, VirtualMachineScopeInterface, _VirtualMachineScopeInterface_Get),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, VirtualMachineScopeInterface, _VirtualMachineScopeInterface_Execute),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "name\0helperStack\0expected\0arguments\0", 85LL, VirtualMachineScopeInterface, _VirtualMachineScopeInterface_PrivateInvoke),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, VirtualMachineScopeInterface, _VirtualMachineScopeInterface_ErrorHandling),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "lib\0", 0LL, VirtualMachineScopeInterface, _VirtualMachineScopeInterface__PrivateInit),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&VirtualMachineScopeInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_VirtualMachineScopeInterface(nullptr, &VirtualMachineScopeInterface::ProxyComponent::_descriptor, &RegisterReflection_VirtualMachineScopeInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_VirtualMachineInterface(VirtualMachineInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::VirtualMachineRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class VirtualMachineInterface::ProxyComponent : public maxon::Component<ProxyComponent, VirtualMachineInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, VirtualMachineInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> Init(const LoadRuntime& runtimeInfo, const DataDictionary& settings) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_Init_Offset), maxon::reflection::Argument::ByReference(runtimeInfo), maxon::reflection::Argument::ByReference(settings)};
			(*handler_)(_fn_VirtualMachineInterface_Init, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const LoadRuntime&, const DataDictionary&>::Invoke, (const void*) mt_._VirtualMachineInterface_Init));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineInterface_Init;
		void Free() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_Free_Offset)};
			(*handler_)(_fn_VirtualMachineInterface_Free, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*>::Invoke, (const void*) mt_._VirtualMachineInterface_Free));
		}
		static const maxon::reflection::Function* _fn_VirtualMachineInterface_Free;
		Result<VirtualMachineScopeRef> CreateScope() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineInterface>();
			Result<VirtualMachineScopeRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_CreateScope_Offset)};
			(*handler_)(_fn_VirtualMachineInterface_CreateScope, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<VirtualMachineScopeRef>, maxon::GenericComponent*>::Invoke, (const void*) mt_._VirtualMachineInterface_CreateScope));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineInterface_CreateScope;
		String GetName() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineInterface>();
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetName_Offset)};
			(*handler_)(_fn_VirtualMachineInterface_GetName, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, maxon::GenericComponent*>::Invoke, (const void*) mt_._VirtualMachineInterface_GetName));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineInterface_GetName;
		String GetVersion() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineInterface>();
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetVersion_Offset)};
			(*handler_)(_fn_VirtualMachineInterface_GetVersion, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, maxon::GenericComponent*>::Invoke, (const void*) mt_._VirtualMachineInterface_GetVersion));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineInterface_GetVersion;
		String GetCopyright() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineInterface>();
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetCopyright_Offset)};
			(*handler_)(_fn_VirtualMachineInterface_GetCopyright, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, maxon::GenericComponent*>::Invoke, (const void*) mt_._VirtualMachineInterface_GetCopyright));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineInterface_GetCopyright;
		String GetCompiler() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineInterface>();
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetCompiler_Offset)};
			(*handler_)(_fn_VirtualMachineInterface_GetCompiler, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, maxon::GenericComponent*>::Invoke, (const void*) mt_._VirtualMachineInterface_GetCompiler));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineInterface_GetCompiler;
		String GetBuildInfo() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineInterface>();
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetBuildInfo_Offset)};
			(*handler_)(_fn_VirtualMachineInterface_GetBuildInfo, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, maxon::GenericComponent*>::Invoke, (const void*) mt_._VirtualMachineInterface_GetBuildInfo));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineInterface_GetBuildInfo;
		Result<void> EnterInteractiveMode() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_EnterInteractiveMode_Offset)};
			(*handler_)(_fn_VirtualMachineInterface_EnterInteractiveMode, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_._VirtualMachineInterface_EnterInteractiveMode));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineInterface_EnterInteractiveMode;
		Result<void> Execute(const String& code) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_Execute_Offset), maxon::reflection::Argument::ByReference(code)};
			(*handler_)(_fn_VirtualMachineInterface_Execute, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const String&>::Invoke, (const void*) mt_._VirtualMachineInterface_Execute));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineInterface_Execute;
		Result<void> Execute(const Url& filepath) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_Execute_1_Offset), maxon::reflection::Argument::ByReference(filepath)};
			(*handler_)(_fn_VirtualMachineInterface_Execute_1, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const Url&>::Invoke, (const void*) mt_._VirtualMachineInterface_Execute_1));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineInterface_Execute_1;
		Result<void> ExecuteModule(const String& name) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_ExecuteModule_Offset), maxon::reflection::Argument::ByReference(name)};
			(*handler_)(_fn_VirtualMachineInterface_ExecuteModule, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const String&>::Invoke, (const void*) mt_._VirtualMachineInterface_ExecuteModule));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineInterface_ExecuteModule;
		Result<void> GetDocumentString(const String& code, DocStringMeta& meta) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetDocumentString_Offset), maxon::reflection::Argument::ByReference(code), maxon::reflection::Argument::ByReference(meta)};
			(*handler_)(_fn_VirtualMachineInterface_GetDocumentString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const String&, DocStringMeta&>::Invoke, (const void*) mt_._VirtualMachineInterface_GetDocumentString));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineInterface_GetDocumentString;
		LibraryRef GetLibraryRef() 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineInterface>();
			LibraryRef proxy_result = maxon::PrivateIncompleteNullReturnValue<LibraryRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetLibraryRef_Offset)};
			(*handler_)(_fn_VirtualMachineInterface_GetLibraryRef, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<LibraryRef, maxon::GenericComponent*>::Invoke, (const void*) mt_._VirtualMachineInterface_GetLibraryRef));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineInterface_GetLibraryRef;
		Result<BaseArray<Runtime>> GetAllAvailableVirtualMachineLibraries() const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::ObjectInterface* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::ObjectInterface*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::ObjectInterface*) this->self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<VirtualMachineInterface>();
			Result<BaseArray<Runtime>> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries_Offset)};
			(*handler_)(_fn_VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<BaseArray<Runtime>>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries;
	};
	const maxon::reflection::Function* VirtualMachineInterface::ProxyComponent::_fn_VirtualMachineInterface_Init;
	const maxon::reflection::Function* VirtualMachineInterface::ProxyComponent::_fn_VirtualMachineInterface_Free;
	const maxon::reflection::Function* VirtualMachineInterface::ProxyComponent::_fn_VirtualMachineInterface_CreateScope;
	const maxon::reflection::Function* VirtualMachineInterface::ProxyComponent::_fn_VirtualMachineInterface_GetName;
	const maxon::reflection::Function* VirtualMachineInterface::ProxyComponent::_fn_VirtualMachineInterface_GetVersion;
	const maxon::reflection::Function* VirtualMachineInterface::ProxyComponent::_fn_VirtualMachineInterface_GetCopyright;
	const maxon::reflection::Function* VirtualMachineInterface::ProxyComponent::_fn_VirtualMachineInterface_GetCompiler;
	const maxon::reflection::Function* VirtualMachineInterface::ProxyComponent::_fn_VirtualMachineInterface_GetBuildInfo;
	const maxon::reflection::Function* VirtualMachineInterface::ProxyComponent::_fn_VirtualMachineInterface_EnterInteractiveMode;
	const maxon::reflection::Function* VirtualMachineInterface::ProxyComponent::_fn_VirtualMachineInterface_Execute;
	const maxon::reflection::Function* VirtualMachineInterface::ProxyComponent::_fn_VirtualMachineInterface_Execute_1;
	const maxon::reflection::Function* VirtualMachineInterface::ProxyComponent::_fn_VirtualMachineInterface_ExecuteModule;
	const maxon::reflection::Function* VirtualMachineInterface::ProxyComponent::_fn_VirtualMachineInterface_GetDocumentString;
	const maxon::reflection::Function* VirtualMachineInterface::ProxyComponent::_fn_VirtualMachineInterface_GetLibraryRef;
	const maxon::reflection::Function* VirtualMachineInterface::ProxyComponent::_fn_VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries;
	PRIVATE_MAXON_COMPONENT_REGISTER(VirtualMachineInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_VirtualMachineInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "runtimeInfo\0settings\0", 5LL, VirtualMachineInterface, _VirtualMachineInterface_Init),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, VirtualMachineInterface, _VirtualMachineInterface_Free),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, VirtualMachineInterface, _VirtualMachineInterface_CreateScope),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, VirtualMachineInterface, _VirtualMachineInterface_GetName),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, VirtualMachineInterface, _VirtualMachineInterface_GetVersion),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, VirtualMachineInterface, _VirtualMachineInterface_GetCopyright),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, VirtualMachineInterface, _VirtualMachineInterface_GetCompiler),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, VirtualMachineInterface, _VirtualMachineInterface_GetBuildInfo),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, VirtualMachineInterface, _VirtualMachineInterface_EnterInteractiveMode),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "code\0", 1LL, VirtualMachineInterface, _VirtualMachineInterface_Execute),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "filepath\0", 1LL, VirtualMachineInterface, _VirtualMachineInterface_Execute_1),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "name\0", 1LL, VirtualMachineInterface, _VirtualMachineInterface_ExecuteModule),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "code\0meta\0", 9LL, VirtualMachineInterface, _VirtualMachineInterface_GetDocumentString),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, VirtualMachineInterface, _VirtualMachineInterface_GetLibraryRef),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, VirtualMachineInterface, _VirtualMachineInterface_GetAllAvailableVirtualMachineLibraries),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&VirtualMachineInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_VirtualMachineInterface(nullptr, &VirtualMachineInterface::ProxyComponent::_descriptor, &RegisterReflection_VirtualMachineInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(VirtualMachines);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(VmDebuggerConnections);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(PythonVms);
#endif
}
#endif
