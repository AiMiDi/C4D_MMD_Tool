#if 1
#ifdef __API_INTERN__
#endif
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_GetExtraDataCallbackInterface(GetExtraDataCallbackInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::GetExtraDataCallbackRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class GetExtraDataCallbackInterface::ProxyComponent : public maxon::Component<ProxyComponent, GetExtraDataCallbackInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, GetExtraDataCallbackInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<DelegateBase> GetExtraDataMessage(const Id& cmdId) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<GetExtraDataCallbackInterface>();
			Result<DelegateBase> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.GetExtraDataCallbackInterface_GetExtraDataMessage_Offset), maxon::reflection::Argument::ByReference(cmdId)};
			(*handler_)(_fn_GetExtraDataCallbackInterface_GetExtraDataMessage, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<DelegateBase>), const Id&), reinterpret_cast<const void* const&>(mt_.GetExtraDataCallbackInterface_GetExtraDataMessage)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_GetExtraDataCallbackInterface_GetExtraDataMessage;
	};
	const maxon::reflection::Function* GetExtraDataCallbackInterface::ProxyComponent::_fn_GetExtraDataCallbackInterface_GetExtraDataMessage;
	PRIVATE_MAXON_COMPONENT_REGISTER(GetExtraDataCallbackInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_GetExtraDataCallbackInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "cmdId\0", 1LL, GetExtraDataCallbackInterface, GetExtraDataCallbackInterface_GetExtraDataMessage),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&GetExtraDataCallbackInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_GetExtraDataCallbackInterface(nullptr, &GetExtraDataCallbackInterface::ProxyComponent::_descriptor, &RegisterReflection_GetExtraDataCallbackInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#ifdef __API_INTERN__
#endif
#endif
