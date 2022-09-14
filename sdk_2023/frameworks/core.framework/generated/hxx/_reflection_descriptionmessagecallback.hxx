#if 1
#ifdef __API_INTERN__
#endif
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_DescriptionMessageCallbackInterface(DescriptionMessageCallbackInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::DescriptionMessageCallbackRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class DescriptionMessageCallbackInterface::ProxyComponent : public maxon::Component<ProxyComponent, DescriptionMessageCallbackInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, DescriptionMessageCallbackInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<Tuple<Bool, Bool>> DescriptionMessage(const InternedId& id, const Id& cmdId, Int32 type, void* data) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DescriptionMessageCallbackInterface>();
			Result<Tuple<Bool, Bool>> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.DescriptionMessageCallbackInterface_DescriptionMessage_Offset), maxon::reflection::Argument::ByReference(id), maxon::reflection::Argument::ByReference(cmdId), maxon::reflection::Argument::ByValue(type), maxon::reflection::Argument::ByValue(data)};
			(*handler_)(_fn_DescriptionMessageCallbackInterface_DescriptionMessage, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<Tuple<Bool, Bool>>), const InternedId&, const Id&, Int32, void*), reinterpret_cast<const void* const&>(mt_.DescriptionMessageCallbackInterface_DescriptionMessage)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DescriptionMessageCallbackInterface_DescriptionMessage;
	};
	const maxon::reflection::Function* DescriptionMessageCallbackInterface::ProxyComponent::_fn_DescriptionMessageCallbackInterface_DescriptionMessage;
	PRIVATE_MAXON_COMPONENT_REGISTER(DescriptionMessageCallbackInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_DescriptionMessageCallbackInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "id\0cmdId\0type\0data\0", 85LL, DescriptionMessageCallbackInterface, DescriptionMessageCallbackInterface_DescriptionMessage),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DescriptionMessageCallbackInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_DescriptionMessageCallbackInterface(nullptr, &DescriptionMessageCallbackInterface::ProxyComponent::_descriptor, &RegisterReflection_DescriptionMessageCallbackInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#ifdef __API_INTERN__
#endif
#endif
