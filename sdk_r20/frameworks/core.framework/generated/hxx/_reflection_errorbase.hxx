#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_OutOfMemoryErrorInterface(OutOfMemoryErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class OutOfMemoryErrorInterface::ProxyComponent : public maxon::Component<OutOfMemoryErrorInterface::ProxyComponent, OutOfMemoryErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(OutOfMemoryErrorInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_OutOfMemoryErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&OutOfMemoryErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_OutOfMemoryErrorInterface(nullptr, &OutOfMemoryErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_OutOfMemoryErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_FunctionNotImplementedErrorInterface(FunctionNotImplementedErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class FunctionNotImplementedErrorInterface::ProxyComponent : public maxon::Component<FunctionNotImplementedErrorInterface::ProxyComponent, FunctionNotImplementedErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(FunctionNotImplementedErrorInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_FunctionNotImplementedErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&FunctionNotImplementedErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_FunctionNotImplementedErrorInterface(nullptr, &FunctionNotImplementedErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_FunctionNotImplementedErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_UnresolvedErrorInterface(UnresolvedErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class UnresolvedErrorInterface::ProxyComponent : public maxon::Component<UnresolvedErrorInterface::ProxyComponent, UnresolvedErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(UnresolvedErrorInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_UnresolvedErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UnresolvedErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_UnresolvedErrorInterface(nullptr, &UnresolvedErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_UnresolvedErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_UnsupportedOperationErrorInterface(UnsupportedOperationErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class UnsupportedOperationErrorInterface::ProxyComponent : public maxon::Component<UnsupportedOperationErrorInterface::ProxyComponent, UnsupportedOperationErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(UnsupportedOperationErrorInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_UnsupportedOperationErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UnsupportedOperationErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_UnsupportedOperationErrorInterface(nullptr, &UnsupportedOperationErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_UnsupportedOperationErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ThreadCancelledErrorInterface(ThreadCancelledErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class ThreadCancelledErrorInterface::ProxyComponent : public maxon::Component<ThreadCancelledErrorInterface::ProxyComponent, ThreadCancelledErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(ThreadCancelledErrorInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_ThreadCancelledErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ThreadCancelledErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_ThreadCancelledErrorInterface(nullptr, &ThreadCancelledErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_ThreadCancelledErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_IllegalArgumentErrorInterface(IllegalArgumentErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class IllegalArgumentErrorInterface::ProxyComponent : public maxon::Component<IllegalArgumentErrorInterface::ProxyComponent, IllegalArgumentErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(IllegalArgumentErrorInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_IllegalArgumentErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&IllegalArgumentErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_IllegalArgumentErrorInterface(nullptr, &IllegalArgumentErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_IllegalArgumentErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_UnsupportedArgumentErrorInterface(UnsupportedArgumentErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class UnsupportedArgumentErrorInterface::ProxyComponent : public maxon::Component<UnsupportedArgumentErrorInterface::ProxyComponent, UnsupportedArgumentErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(UnsupportedArgumentErrorInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_UnsupportedArgumentErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UnsupportedArgumentErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_UnsupportedArgumentErrorInterface(nullptr, &UnsupportedArgumentErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_UnsupportedArgumentErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_NullptrErrorInterface(NullptrErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class NullptrErrorInterface::ProxyComponent : public maxon::Component<NullptrErrorInterface::ProxyComponent, NullptrErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(NullptrErrorInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_NullptrErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&NullptrErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_NullptrErrorInterface(nullptr, &NullptrErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_NullptrErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_IllegalStateErrorInterface(IllegalStateErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class IllegalStateErrorInterface::ProxyComponent : public maxon::Component<IllegalStateErrorInterface::ProxyComponent, IllegalStateErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(IllegalStateErrorInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_IllegalStateErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&IllegalStateErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_IllegalStateErrorInterface(nullptr, &IllegalStateErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_IllegalStateErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_UnknownErrorInterface(UnknownErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class UnknownErrorInterface::ProxyComponent : public maxon::Component<UnknownErrorInterface::ProxyComponent, UnknownErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(UnknownErrorInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_UnknownErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UnknownErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_UnknownErrorInterface(nullptr, &UnknownErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_UnknownErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ShutdownErrorInterface(ShutdownErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class ShutdownErrorInterface::ProxyComponent : public maxon::Component<ShutdownErrorInterface::ProxyComponent, ShutdownErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(ShutdownErrorInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_ShutdownErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ShutdownErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_ShutdownErrorInterface(nullptr, &ShutdownErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_ShutdownErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_UnexpectedErrorInterface(UnexpectedErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class UnexpectedErrorInterface::ProxyComponent : public maxon::Component<UnexpectedErrorInterface::ProxyComponent, UnexpectedErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(UnexpectedErrorInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_UnexpectedErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UnexpectedErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_UnexpectedErrorInterface(nullptr, &UnexpectedErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_UnexpectedErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ErrnoErrorInterface(ErrnoErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class ErrnoErrorInterface::ProxyComponent : public maxon::Component<ErrnoErrorInterface::ProxyComponent, ErrnoErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(ErrnoErrorInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_ErrnoErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ErrnoErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_ErrnoErrorInterface(nullptr, &ErrnoErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_ErrnoErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_UnregisteredDataTypeErrorInterface(UnregisteredDataTypeErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class UnregisteredDataTypeErrorInterface::ProxyComponent : public maxon::Component<UnregisteredDataTypeErrorInterface::ProxyComponent, UnregisteredDataTypeErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(UnregisteredDataTypeErrorInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_UnregisteredDataTypeErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UnregisteredDataTypeErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_UnregisteredDataTypeErrorInterface(nullptr, &UnregisteredDataTypeErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_UnregisteredDataTypeErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_AggregatedErrorInterface(AggregatedErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class AggregatedErrorInterface::ProxyComponent : public maxon::Component<AggregatedErrorInterface::ProxyComponent, AggregatedErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Bool AddError(const Error& error) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<AggregatedErrorInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._AggregatedErrorInterface_AddError_Offset), maxon::reflection::Argument::ByReference(error)};
			(*handler_)(_fn_AggregatedErrorInterface_AddError, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, const Error&>::Invoke, (const void*) mt_._AggregatedErrorInterface_AddError));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_AggregatedErrorInterface_AddError;
		Bool AddError(Error&& error) 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<AggregatedErrorInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._AggregatedErrorInterface_AddError_1_Offset), maxon::reflection::Argument::ByReference(error)};
			(*handler_)(_fn_AggregatedErrorInterface_AddError_1, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Bool, maxon::GenericComponent*, Error&&>::Invoke, (const void*) mt_._AggregatedErrorInterface_AddError_1));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_AggregatedErrorInterface_AddError_1;
		Int GetCount() const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<AggregatedErrorInterface>();
			Int proxy_result = 0;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._AggregatedErrorInterface_GetCount_Offset)};
			(*handler_)(_fn_AggregatedErrorInterface_GetCount, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Int, const maxon::GenericComponent*>::Invoke, (const void*) mt_._AggregatedErrorInterface_GetCount));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_AggregatedErrorInterface_GetCount;
		const Error& GetError(Int index) const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<AggregatedErrorInterface>();
			const Error* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const Error&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._AggregatedErrorInterface_GetError_Offset), maxon::reflection::Argument::ByValue(index)};
			(*handler_)(_fn_AggregatedErrorInterface_GetError, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<const Error&, const maxon::GenericComponent*, Int>::Invoke, (const void*) mt_._AggregatedErrorInterface_GetError));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_AggregatedErrorInterface_GetError;
	};
	const maxon::reflection::Function* AggregatedErrorInterface::ProxyComponent::_fn_AggregatedErrorInterface_AddError;
	const maxon::reflection::Function* AggregatedErrorInterface::ProxyComponent::_fn_AggregatedErrorInterface_AddError_1;
	const maxon::reflection::Function* AggregatedErrorInterface::ProxyComponent::_fn_AggregatedErrorInterface_GetCount;
	const maxon::reflection::Function* AggregatedErrorInterface::ProxyComponent::_fn_AggregatedErrorInterface_GetError;
	PRIVATE_MAXON_COMPONENT_REGISTER(AggregatedErrorInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_AggregatedErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, 4LL, AggregatedErrorInterface, _AggregatedErrorInterface_AddError),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, 4LL, AggregatedErrorInterface, _AggregatedErrorInterface_AddError_1),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 0LL, AggregatedErrorInterface, _AggregatedErrorInterface_GetCount),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 4LL, AggregatedErrorInterface, _AggregatedErrorInterface_GetError),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&AggregatedErrorInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_AggregatedErrorInterface(nullptr, &AggregatedErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_AggregatedErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifdef MAXON_COMPILER_MSVC
#else
#endif
}
#endif
