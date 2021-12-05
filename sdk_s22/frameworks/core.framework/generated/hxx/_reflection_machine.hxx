#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MachineInterface(MachineInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
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
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MachineInterface_GetUniqueId_Offset)};
			(*handler_)(_fn_MachineInterface_GetUniqueId, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, const maxon::GenericComponent*>::Invoke, (const void*) mt_._MachineInterface_GetUniqueId));
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
			Result<DataDictionary> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MachineInterface_GetMachineInfo_Offset)};
			(*handler_)(_fn_MachineInterface_GetMachineInfo, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<DataDictionary>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._MachineInterface_GetMachineInfo));
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
			Result<ObjectRef> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MachineInterface_GetInterface_Offset), maxon::reflection::Argument::ByReference(interfaceName)};
			(*handler_)(_fn_MachineInterface_GetInterface, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<ObjectRef>, maxon::GenericComponent*, const Id&>::Invoke, (const void*) mt_._MachineInterface_GetInterface));
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
			MACHINESTATE proxy_result = maxon::PrivateIncompleteNullReturnValue<MACHINESTATE>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MachineInterface_GetState_Offset)};
			(*handler_)(_fn_MachineInterface_GetState, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<MACHINESTATE, const maxon::GenericComponent*>::Invoke, (const void*) mt_._MachineInterface_GetState));
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
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MachineInterface_SetState_Offset), maxon::reflection::Argument::ByValue(stateMask), maxon::reflection::Argument::ByValue(stateFlags)};
			(*handler_)(_fn_MachineInterface_SetState, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, MACHINESTATE, MACHINESTATE>::Invoke, (const void*) mt_._MachineInterface_SetState));
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
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MachineInterface_ToString_Offset), maxon::reflection::Argument::ByValue(formatStatement)};
			(*handler_)(_fn_MachineInterface_ToString, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, const maxon::GenericComponent*, const FormatStatement*>::Invoke, (const void*) mt_._MachineInterface_ToString));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MachineInterface_ToString;
		maxon::ObservableRef<ObservableMessageReceivedDelegate> ObservableMessageReceived() const 
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
			maxon::ObservableRef<ObservableMessageReceivedDelegate> proxy_result = maxon::ObservableRef<ObservableMessageReceivedDelegate>::NullValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._MachineInterface_ObservableMessageReceived_Offset)};
			(*handler_)(_fn_MachineInterface_ObservableMessageReceived, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<maxon::ObservableRef<ObservableMessageReceivedDelegate>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._MachineInterface_ObservableMessageReceived));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MachineInterface_ObservableMessageReceived;
	};
	const maxon::reflection::Function* MachineInterface::ProxyComponent::_fn_MachineInterface_GetUniqueId;
	const maxon::reflection::Function* MachineInterface::ProxyComponent::_fn_MachineInterface_GetMachineInfo;
	const maxon::reflection::Function* MachineInterface::ProxyComponent::_fn_MachineInterface_GetInterface;
	const maxon::reflection::Function* MachineInterface::ProxyComponent::_fn_MachineInterface_GetState;
	const maxon::reflection::Function* MachineInterface::ProxyComponent::_fn_MachineInterface_SetState;
	const maxon::reflection::Function* MachineInterface::ProxyComponent::_fn_MachineInterface_ToString;
	const maxon::reflection::Function* MachineInterface::ProxyComponent::_fn_MachineInterface_ObservableMessageReceived;
	PRIVATE_MAXON_COMPONENT_REGISTER(MachineInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MachineInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MachineInterface, _MachineInterface_GetUniqueId),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MachineInterface, _MachineInterface_GetMachineInfo),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "interfaceName\0", 1LL, MachineInterface, _MachineInterface_GetInterface),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MachineInterface, _MachineInterface_GetState),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "stateMask\0stateFlags\0", 5LL, MachineInterface, _MachineInterface_SetState),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "formatStatement\0", 1LL, MachineInterface, _MachineInterface_ToString),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MachineInterface, _MachineInterface_ObservableMessageReceived),
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
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(MachinesInterface::MTable::_instance._MachinesInterface_GetLocal)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(MachinesInterface::MTable::_instance._MachinesInterface_GetRPCMachines)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "machines\0", 2LL, nullptr),
/// @cond INTERNAL

/// @endcond

			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(MachinesInterface::MTable::_instance._MachinesInterface_FindRPCMachine)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "machineUuid\0", 1LL, nullptr),
/// @cond INTERNAL

/// @endcond

			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(MachinesInterface::MTable::_instance._MachinesInterface_FindOrAddRPCMachine)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "machineUuid\0state\0newMachineCallback\0existingCallback\0", 85LL, nullptr),
/// @cond INTERNAL

/// @endcond

			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(MachinesInterface::MTable::_instance._MachinesInterface_RemoveRPCMachine)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "machine\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(MachinesInterface::MTable::_instance._MachinesInterface_ObservableMachineStateChanged)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
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
