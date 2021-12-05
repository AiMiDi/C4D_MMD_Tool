#if 1
namespace maxon
{
/// @cond INTERNAL

/// @endcond

#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ObserverObjectInterface(ObserverObjectInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ObserverObjectInterface::ProxyComponent : public maxon::Component<ProxyComponent, ObserverObjectInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ObserverObjectInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
/// @cond INTERNAL

		Result<void> AddSenderSignal(ObservableBaseInterface* observable) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObserverObjectInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_AddSenderSignal_Offset), maxon::reflection::Argument::ByValue(observable)};
			(*handler_)(_fn_ObserverObjectInterface_AddSenderSignal, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, ObservableBaseInterface*>::Invoke, (const void*) mt_._ObserverObjectInterface_AddSenderSignal));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObserverObjectInterface_AddSenderSignal;
		void RemoveSenderSignal(ObservableBaseInterface* observable) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObserverObjectInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_RemoveSenderSignal_Offset), maxon::reflection::Argument::ByValue(observable)};
			(*handler_)(_fn_ObserverObjectInterface_RemoveSenderSignal, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, ObservableBaseInterface*>::Invoke, (const void*) mt_._ObserverObjectInterface_RemoveSenderSignal));
		}
		static const maxon::reflection::Function* _fn_ObserverObjectInterface_RemoveSenderSignal;
/// @endcond

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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObserverObjectInterface>();
			String proxy_result = maxon::PrivateIncompleteNullReturnValue<String>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_GetName_Offset)};
			(*handler_)(_fn_ObserverObjectInterface_GetName, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<String, const maxon::GenericComponent*>::Invoke, (const void*) mt_._ObserverObjectInterface_GetName));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObserverObjectInterface_GetName;
		void SetName(const String& name) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObserverObjectInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_SetName_Offset), maxon::reflection::Argument::ByReference(name)};
			(*handler_)(_fn_ObserverObjectInterface_SetName, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, const String&>::Invoke, (const void*) mt_._ObserverObjectInterface_SetName));
		}
		static const maxon::reflection::Function* _fn_ObserverObjectInterface_SetName;
		maxon::ObservableRef<ObserverDestroyedDelegate> ObserverDestroyed() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObserverObjectInterface>();
			maxon::ObservableRef<ObserverDestroyedDelegate> proxy_result = maxon::ObservableRef<ObserverDestroyedDelegate>::NullValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_ObserverDestroyed_Offset)};
			(*handler_)(_fn_ObserverObjectInterface_ObserverDestroyed, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<maxon::ObservableRef<ObserverDestroyedDelegate>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._ObserverObjectInterface_ObserverDestroyed));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObserverObjectInterface_ObserverDestroyed;
		maxon::ObservableRef<ObserverDisconnectNotifyDelegate> ObserverDisconnectNotify() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObserverObjectInterface>();
			maxon::ObservableRef<ObserverDisconnectNotifyDelegate> proxy_result = maxon::ObservableRef<ObserverDisconnectNotifyDelegate>::NullValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_ObserverDisconnectNotify_Offset)};
			(*handler_)(_fn_ObserverObjectInterface_ObserverDisconnectNotify, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<maxon::ObservableRef<ObserverDisconnectNotifyDelegate>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._ObserverObjectInterface_ObserverDisconnectNotify));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObserverObjectInterface_ObserverDisconnectNotify;
		maxon::ObservableRef<ObserverConnectNotifyDelegate> ObserverConnectNotify() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ObserverObjectInterface>();
			maxon::ObservableRef<ObserverConnectNotifyDelegate> proxy_result = maxon::ObservableRef<ObserverConnectNotifyDelegate>::NullValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ObserverObjectInterface_ObserverConnectNotify_Offset)};
			(*handler_)(_fn_ObserverObjectInterface_ObserverConnectNotify, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<maxon::ObservableRef<ObserverConnectNotifyDelegate>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._ObserverObjectInterface_ObserverConnectNotify));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ObserverObjectInterface_ObserverConnectNotify;
	};
/// @cond INTERNAL

	const maxon::reflection::Function* ObserverObjectInterface::ProxyComponent::_fn_ObserverObjectInterface_AddSenderSignal;
	const maxon::reflection::Function* ObserverObjectInterface::ProxyComponent::_fn_ObserverObjectInterface_RemoveSenderSignal;
/// @endcond

	const maxon::reflection::Function* ObserverObjectInterface::ProxyComponent::_fn_ObserverObjectInterface_GetName;
	const maxon::reflection::Function* ObserverObjectInterface::ProxyComponent::_fn_ObserverObjectInterface_SetName;
	const maxon::reflection::Function* ObserverObjectInterface::ProxyComponent::_fn_ObserverObjectInterface_ObserverDestroyed;
	const maxon::reflection::Function* ObserverObjectInterface::ProxyComponent::_fn_ObserverObjectInterface_ObserverDisconnectNotify;
	const maxon::reflection::Function* ObserverObjectInterface::ProxyComponent::_fn_ObserverObjectInterface_ObserverConnectNotify;
	PRIVATE_MAXON_COMPONENT_REGISTER(ObserverObjectInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ObserverObjectInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
/// @cond INTERNAL

			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "observable\0", 1LL, ObserverObjectInterface, _ObserverObjectInterface_AddSenderSignal),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "observable\0", 1LL, ObserverObjectInterface, _ObserverObjectInterface_RemoveSenderSignal),
/// @endcond

			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ObserverObjectInterface, _ObserverObjectInterface_GetName),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "name\0", 1LL, ObserverObjectInterface, _ObserverObjectInterface_SetName),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ObserverObjectInterface, _ObserverObjectInterface_ObserverDestroyed),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ObserverObjectInterface, _ObserverObjectInterface_ObserverDisconnectNotify),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ObserverObjectInterface, _ObserverObjectInterface_ObserverConnectNotify),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ObserverObjectInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ObserverObjectInterface(nullptr, &ObserverObjectInterface::ProxyComponent::_descriptor, &RegisterReflection_ObserverObjectInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
