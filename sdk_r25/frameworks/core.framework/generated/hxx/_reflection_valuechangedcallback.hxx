#if 1
#ifdef __API_INTERN__
#endif
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ValueChangedCallbackInterface(ValueChangedCallbackInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ValueChangedCallbackRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ValueChangedCallbackInterface::ProxyComponent : public maxon::Component<ProxyComponent, ValueChangedCallbackInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ValueChangedCallbackInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> ValueChangedMessage(const InternedId& id) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ValueChangedCallbackInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._ValueChangedCallbackInterface_ValueChangedMessage_Offset), maxon::reflection::Argument::ByReference(id)};
			(*handler_)(_fn_ValueChangedCallbackInterface_ValueChangedMessage, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const InternedId&>::Invoke, (const void*) mt_._ValueChangedCallbackInterface_ValueChangedMessage));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_ValueChangedCallbackInterface_ValueChangedMessage;
	};
	const maxon::reflection::Function* ValueChangedCallbackInterface::ProxyComponent::_fn_ValueChangedCallbackInterface_ValueChangedMessage;
	PRIVATE_MAXON_COMPONENT_REGISTER(ValueChangedCallbackInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ValueChangedCallbackInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "id\0", 1LL, ValueChangedCallbackInterface, _ValueChangedCallbackInterface_ValueChangedMessage),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ValueChangedCallbackInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ValueChangedCallbackInterface(nullptr, &ValueChangedCallbackInterface::ProxyComponent::_descriptor, &RegisterReflection_ValueChangedCallbackInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#ifdef __API_INTERN__
#endif
#endif
