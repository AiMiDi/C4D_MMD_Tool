#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_CommandObserverInterface(CommandObserverInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::CommandObserverRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class CommandObserverInterface::ProxyComponent : public maxon::Component<ProxyComponent, CommandObserverInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, CommandObserverInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		maxon::ObservableRef<ObservableCommandStatusDelegate> ObservableCommandStatus() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CommandObserverInterface>();
			maxon::ObservableRef<ObservableCommandStatusDelegate> proxy_result = maxon::ObservableRef<ObservableCommandStatusDelegate>::NullValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CommandObserverInterface_ObservableCommandStatus_Offset)};
			(*handler_)(_fn_CommandObserverInterface_ObservableCommandStatus, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<maxon::ObservableRef<ObservableCommandStatusDelegate>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CommandObserverInterface_ObservableCommandStatus));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CommandObserverInterface_ObservableCommandStatus;
		maxon::ObservableRef<ObservableCommandInvokedDelegate> ObservableCommandInvoked() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CommandObserverInterface>();
			maxon::ObservableRef<ObservableCommandInvokedDelegate> proxy_result = maxon::ObservableRef<ObservableCommandInvokedDelegate>::NullValue();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._CommandObserverInterface_ObservableCommandInvoked_Offset)};
			(*handler_)(_fn_CommandObserverInterface_ObservableCommandInvoked, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<maxon::ObservableRef<ObservableCommandInvokedDelegate>, const maxon::GenericComponent*>::Invoke, (const void*) mt_._CommandObserverInterface_ObservableCommandInvoked));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CommandObserverInterface_ObservableCommandInvoked;
	};
	const maxon::reflection::Function* CommandObserverInterface::ProxyComponent::_fn_CommandObserverInterface_ObservableCommandStatus;
	const maxon::reflection::Function* CommandObserverInterface::ProxyComponent::_fn_CommandObserverInterface_ObservableCommandInvoked;
	PRIVATE_MAXON_COMPONENT_REGISTER(CommandObserverInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_CommandObserverInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CommandObserverInterface, _CommandObserverInterface_ObservableCommandStatus),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CommandObserverInterface, _CommandObserverInterface_ObservableCommandInvoked),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CommandObserverInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_CommandObserverInterface(nullptr, &CommandObserverInterface::ProxyComponent::_descriptor, &RegisterReflection_CommandObserverInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
