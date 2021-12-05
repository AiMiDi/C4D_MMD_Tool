#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_SystemProcessKilledErrorInterface(SystemProcessKilledErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class SystemProcessKilledErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, SystemProcessKilledErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, SystemProcessKilledErrorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(SystemProcessKilledErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_SystemProcessKilledErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&SystemProcessKilledErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_SystemProcessKilledErrorInterface(nullptr, &SystemProcessKilledErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_SystemProcessKilledErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_SystemProcessOperationErrorInterface(SystemProcessOperationErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class SystemProcessOperationErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, SystemProcessOperationErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, SystemProcessOperationErrorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(SystemProcessOperationErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_SystemProcessOperationErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&SystemProcessOperationErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_SystemProcessOperationErrorInterface(nullptr, &SystemProcessOperationErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_SystemProcessOperationErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_SystemProcessObjectInterface(SystemProcessObjectInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class SystemProcessObjectInterface::ProxyComponent : public maxon::Component<ProxyComponent, SystemProcessObjectInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, SystemProcessObjectInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> StartProcess() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<SystemProcessObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._SystemProcessObjectInterface_StartProcess_Offset)};
			(*handler_)(_fn_SystemProcessObjectInterface_StartProcess, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_._SystemProcessObjectInterface_StartProcess));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_SystemProcessObjectInterface_StartProcess;
		Result<void> KillProcess() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<SystemProcessObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._SystemProcessObjectInterface_KillProcess_Offset)};
			(*handler_)(_fn_SystemProcessObjectInterface_KillProcess, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*>::Invoke, (const void*) mt_._SystemProcessObjectInterface_KillProcess));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_SystemProcessObjectInterface_KillProcess;
		Int GetExitCode() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<SystemProcessObjectInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._SystemProcessObjectInterface_GetExitCode_Offset)};
			(*handler_)(_fn_SystemProcessObjectInterface_GetExitCode, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Int, const maxon::GenericComponent*>::Invoke, (const void*) mt_._SystemProcessObjectInterface_GetExitCode));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_SystemProcessObjectInterface_GetExitCode;
		Bool IsRunning() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<SystemProcessObjectInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._SystemProcessObjectInterface_IsRunning_Offset)};
			(*handler_)(_fn_SystemProcessObjectInterface_IsRunning, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, const maxon::GenericComponent*>::Invoke, (const void*) mt_._SystemProcessObjectInterface_IsRunning));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_SystemProcessObjectInterface_IsRunning;
		UInt GetProcessId() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<SystemProcessObjectInterface>();
			UInt proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._SystemProcessObjectInterface_GetProcessId_Offset)};
			(*handler_)(_fn_SystemProcessObjectInterface_GetProcessId, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<UInt, const maxon::GenericComponent*>::Invoke, (const void*) mt_._SystemProcessObjectInterface_GetProcessId));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_SystemProcessObjectInterface_GetProcessId;
		void* GetProcessHandle() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<SystemProcessObjectInterface>();
			void* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._SystemProcessObjectInterface_GetProcessHandle_Offset)};
			(*handler_)(_fn_SystemProcessObjectInterface_GetProcessHandle, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<void*, const maxon::GenericComponent*>::Invoke, (const void*) mt_._SystemProcessObjectInterface_GetProcessHandle));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_SystemProcessObjectInterface_GetProcessHandle;
		Url GetProcessUrl() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<SystemProcessObjectInterface>();
			Url proxy_result = maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._SystemProcessObjectInterface_GetProcessUrl_Offset)};
			(*handler_)(_fn_SystemProcessObjectInterface_GetProcessUrl, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Url, const maxon::GenericComponent*>::Invoke, (const void*) mt_._SystemProcessObjectInterface_GetProcessUrl));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_SystemProcessObjectInterface_GetProcessUrl;
		Url GetLogFile() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<SystemProcessObjectInterface>();
			Url proxy_result = maxon::PrivateIncompleteNullReturnValue<Url>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._SystemProcessObjectInterface_GetLogFile_Offset)};
			(*handler_)(_fn_SystemProcessObjectInterface_GetLogFile, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Url, const maxon::GenericComponent*>::Invoke, (const void*) mt_._SystemProcessObjectInterface_GetLogFile));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_SystemProcessObjectInterface_GetLogFile;
		void* GetUserData() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<SystemProcessObjectInterface>();
			void* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._SystemProcessObjectInterface_GetUserData_Offset)};
			(*handler_)(_fn_SystemProcessObjectInterface_GetUserData, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<void*, const maxon::GenericComponent*>::Invoke, (const void*) mt_._SystemProcessObjectInterface_GetUserData));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_SystemProcessObjectInterface_GetUserData;
		Result<void> GetLoadedDlls(const ValueReceiver<const DllRef&>& dlls) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<SystemProcessObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._SystemProcessObjectInterface_GetLoadedDlls_Offset), maxon::reflection::Argument::ByReference(dlls)};
			(*handler_)(_fn_SystemProcessObjectInterface_GetLoadedDlls, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, const maxon::GenericComponent*, const ValueReceiver<const DllRef&>&>::Invoke, (const void*) mt_._SystemProcessObjectInterface_GetLoadedDlls));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_SystemProcessObjectInterface_GetLoadedDlls;
		maxon::ObservableRef<ObservableProcessFinishedDelegate> ObservableProcessFinished() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<SystemProcessObjectInterface>();
			maxon::ObservableRef<ObservableProcessFinishedDelegate> proxy_result = maxon::ObservableRef<ObservableProcessFinishedDelegate>::NullValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._SystemProcessObjectInterface_ObservableProcessFinished_Offset)};
			(*handler_)(_fn_SystemProcessObjectInterface_ObservableProcessFinished, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<maxon::ObservableRef<ObservableProcessFinishedDelegate>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._SystemProcessObjectInterface_ObservableProcessFinished));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_SystemProcessObjectInterface_ObservableProcessFinished;
	};
	const maxon::reflection::Function* SystemProcessObjectInterface::ProxyComponent::_fn_SystemProcessObjectInterface_StartProcess;
	const maxon::reflection::Function* SystemProcessObjectInterface::ProxyComponent::_fn_SystemProcessObjectInterface_KillProcess;
	const maxon::reflection::Function* SystemProcessObjectInterface::ProxyComponent::_fn_SystemProcessObjectInterface_GetExitCode;
	const maxon::reflection::Function* SystemProcessObjectInterface::ProxyComponent::_fn_SystemProcessObjectInterface_IsRunning;
	const maxon::reflection::Function* SystemProcessObjectInterface::ProxyComponent::_fn_SystemProcessObjectInterface_GetProcessId;
	const maxon::reflection::Function* SystemProcessObjectInterface::ProxyComponent::_fn_SystemProcessObjectInterface_GetProcessHandle;
	const maxon::reflection::Function* SystemProcessObjectInterface::ProxyComponent::_fn_SystemProcessObjectInterface_GetProcessUrl;
	const maxon::reflection::Function* SystemProcessObjectInterface::ProxyComponent::_fn_SystemProcessObjectInterface_GetLogFile;
	const maxon::reflection::Function* SystemProcessObjectInterface::ProxyComponent::_fn_SystemProcessObjectInterface_GetUserData;
	const maxon::reflection::Function* SystemProcessObjectInterface::ProxyComponent::_fn_SystemProcessObjectInterface_GetLoadedDlls;
	const maxon::reflection::Function* SystemProcessObjectInterface::ProxyComponent::_fn_SystemProcessObjectInterface_ObservableProcessFinished;
	PRIVATE_MAXON_COMPONENT_REGISTER(SystemProcessObjectInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_SystemProcessObjectInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, SystemProcessObjectInterface, _SystemProcessObjectInterface_StartProcess),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, SystemProcessObjectInterface, _SystemProcessObjectInterface_KillProcess),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, SystemProcessObjectInterface, _SystemProcessObjectInterface_GetExitCode),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, SystemProcessObjectInterface, _SystemProcessObjectInterface_IsRunning),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, SystemProcessObjectInterface, _SystemProcessObjectInterface_GetProcessId),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, SystemProcessObjectInterface, _SystemProcessObjectInterface_GetProcessHandle),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, SystemProcessObjectInterface, _SystemProcessObjectInterface_GetProcessUrl),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, SystemProcessObjectInterface, _SystemProcessObjectInterface_GetLogFile),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, SystemProcessObjectInterface, _SystemProcessObjectInterface_GetUserData),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "dlls\0", 0LL, SystemProcessObjectInterface, _SystemProcessObjectInterface_GetLoadedDlls),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, SystemProcessObjectInterface, _SystemProcessObjectInterface_ObservableProcessFinished),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&SystemProcessObjectInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_SystemProcessObjectInterface(nullptr, &SystemProcessObjectInterface::ProxyComponent::_descriptor, &RegisterReflection_SystemProcessObjectInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_SystemProcessInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SystemProcessInterface::MTable::_instance._SystemProcessInterface_CreateProcess)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "programPath\0arguments\0flags\0userData\0stdinPipe\0stdoutPipe\0stderrPipe\0", 5461LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SystemProcessInterface::MTable::_instance._SystemProcessInterface_StartProcessAndWait)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "programPath\0arguments\0flags\0callback\0userData\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SystemProcessInterface::MTable::_instance._SystemProcessInterface_GetSystemProcesses)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "processes\0", 2LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SystemProcessInterface::MTable::_instance._SystemProcessInterface_GetCurrentProcessId)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SystemProcessInterface::MTable::_instance._SystemProcessInterface_GetProcess)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "id\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(SystemProcessInterface::MTable::_instance._SystemProcessInterface_WaitForProcess)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "processRef\0timeout\0", 5LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&SystemProcessInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_SystemProcessInterface("net.maxon.interface.systemprocess", nullptr, &RegisterReflection_SystemProcessInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
