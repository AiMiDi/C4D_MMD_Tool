#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MachineInterface(MachineInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::MachineRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MachineInterface::ProxyComponent : public maxon::Component<ProxyComponent, MachineInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MachineInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		String GetUniqueId() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MachineInterface>();
			String proxy_result = HXXRET3(NULLIMPL, String);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MachineInterface_GetUniqueId_Offset)};
			(*handler_)(_fn_MachineInterface_GetUniqueId, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((String)), reinterpret_cast<const void* const&>(mt_.MachineInterface_GetUniqueId)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MachineInterface_GetUniqueId;
		Result<DataDictionary> GetMachineInfo() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MachineInterface>();
			Result<DataDictionary> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MachineInterface_GetMachineInfo_Offset)};
			(*handler_)(_fn_MachineInterface_GetMachineInfo, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<DataDictionary>)), reinterpret_cast<const void* const&>(mt_.MachineInterface_GetMachineInfo)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MachineInterface_GetMachineInfo;
		Result<ObjectRef> GetInterface(const Id& interfaceName) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MachineInterface>();
			Result<ObjectRef> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MachineInterface_GetInterface_Offset), maxon::reflection::Argument::ByReference(interfaceName)};
			(*handler_)(_fn_MachineInterface_GetInterface, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<ObjectRef>), const Id&), reinterpret_cast<const void* const&>(mt_.MachineInterface_GetInterface)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MachineInterface_GetInterface;
		MACHINESTATE GetState() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MachineInterface>();
			MACHINESTATE proxy_result = HXXRET3(NULLIMPL, MACHINESTATE);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MachineInterface_GetState_Offset)};
			(*handler_)(_fn_MachineInterface_GetState, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((MACHINESTATE)), reinterpret_cast<const void* const&>(mt_.MachineInterface_GetState)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MachineInterface_GetState;
		Bool SetState(MACHINESTATE stateMask, MACHINESTATE stateFlags) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MachineInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MachineInterface_SetState_Offset), maxon::reflection::Argument::ByValue(stateMask), maxon::reflection::Argument::ByValue(stateFlags)};
			(*handler_)(_fn_MachineInterface_SetState, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Bool), MACHINESTATE, MACHINESTATE), reinterpret_cast<const void* const&>(mt_.MachineInterface_SetState)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MachineInterface_SetState;
		String ToString(const FormatStatement* formatStatement) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MachineInterface>();
			String proxy_result = HXXRET3(NULLIMPL, String);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MachineInterface_ToString_Offset), maxon::reflection::Argument::ByValue(formatStatement)};
			(*handler_)(_fn_MachineInterface_ToString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((String), const FormatStatement*), reinterpret_cast<const void* const&>(mt_.MachineInterface_ToString)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MachineInterface_ToString;
		maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate> ObservablePrivateSplashMessageReceived(Bool create) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MachineInterface>();
			maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate> proxy_result = maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>::DefaultValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MachineInterface_ObservablePrivateSplashMessageReceived_Offset), maxon::reflection::Argument::ByValue(create)};
			(*handler_)(_fn_MachineInterface_ObservablePrivateSplashMessageReceived, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((maxon::ObservableRef<ObservablePrivateSplashMessageReceivedDelegate>), Bool), reinterpret_cast<const void* const&>(mt_.MachineInterface_ObservablePrivateSplashMessageReceived)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MachineInterface_ObservablePrivateSplashMessageReceived;
		maxon::ObservableRef<ObservableActivationChangedDelegate> ObservableActivationChanged(Bool create) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MachineInterface>();
			maxon::ObservableRef<ObservableActivationChangedDelegate> proxy_result = maxon::ObservableRef<ObservableActivationChangedDelegate>::DefaultValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MachineInterface_ObservableActivationChanged_Offset), maxon::reflection::Argument::ByValue(create)};
			(*handler_)(_fn_MachineInterface_ObservableActivationChanged, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((maxon::ObservableRef<ObservableActivationChangedDelegate>), Bool), reinterpret_cast<const void* const&>(mt_.MachineInterface_ObservableActivationChanged)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MachineInterface_ObservableActivationChanged;
	};
	const maxon::reflection::Function* MachineInterface::ProxyComponent::_fn_MachineInterface_GetUniqueId;
	const maxon::reflection::Function* MachineInterface::ProxyComponent::_fn_MachineInterface_GetMachineInfo;
	const maxon::reflection::Function* MachineInterface::ProxyComponent::_fn_MachineInterface_GetInterface;
	const maxon::reflection::Function* MachineInterface::ProxyComponent::_fn_MachineInterface_GetState;
	const maxon::reflection::Function* MachineInterface::ProxyComponent::_fn_MachineInterface_SetState;
	const maxon::reflection::Function* MachineInterface::ProxyComponent::_fn_MachineInterface_ToString;
	const maxon::reflection::Function* MachineInterface::ProxyComponent::_fn_MachineInterface_ObservablePrivateSplashMessageReceived;
	const maxon::reflection::Function* MachineInterface::ProxyComponent::_fn_MachineInterface_ObservableActivationChanged;
	PRIVATE_MAXON_COMPONENT_REGISTER(MachineInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MachineInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MachineInterface, MachineInterface_GetUniqueId),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MachineInterface, MachineInterface_GetMachineInfo),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "interfaceName\0", 1LL, MachineInterface, MachineInterface_GetInterface),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MachineInterface, MachineInterface_GetState),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "stateMask\0stateFlags\0", 5LL, MachineInterface, MachineInterface_SetState),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "formatStatement\0", 1LL, MachineInterface, MachineInterface_ToString),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "create\0", 0LL, MachineInterface, MachineInterface_ObservablePrivateSplashMessageReceived),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "create\0", 0LL, MachineInterface, MachineInterface_ObservableActivationChanged),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MachineInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MachineInterface(nullptr, &MachineInterface::ProxyComponent::_descriptor, &RegisterReflection_MachineInterface, &PRIVATE_MAXON_MODULE);
#endif
/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond

/// @cond INTERNAL

/// @endcond

#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_MachinesInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(MachinesInterface::MTable::_instance.MachinesInterface_GetLocal)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(MachinesInterface::MTable::_instance.MachinesInterface_GetRPCMachines)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "machines\0", 2LL, nullptr),
/// @cond INTERNAL

/// @endcond

			maxon::reflection::GetFunctionInfo<decltype(MachinesInterface::MTable::_instance.MachinesInterface_FindRPCMachine)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "machineUuid\0", 1LL, nullptr),
/// @cond INTERNAL

/// @endcond

			maxon::reflection::GetFunctionInfo<decltype(MachinesInterface::MTable::_instance.MachinesInterface_FindOrAddRPCMachine)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "machineUuid\0state\0newMachineCallback\0existingCallback\0", 85LL, nullptr),
/// @cond INTERNAL

/// @endcond

			maxon::reflection::GetFunctionInfo<decltype(MachinesInterface::MTable::_instance.MachinesInterface_RemoveRPCMachine)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "machine\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(MachinesInterface::MTable::_instance.MachinesInterface_ObservableMachineStateChanged)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "create\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MachinesInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_MachinesInterface("net.maxon.interface.machines", nullptr, &RegisterReflection_MachinesInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_COMPILER_CLANG
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(MachineImplementationFactories);
#endif
}
#endif
