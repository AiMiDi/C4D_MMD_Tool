#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_NumberBaseInterface(NumberBaseInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class NumberBaseInterface::ProxyComponent : public maxon::Component<ProxyComponent, NumberBaseInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, NumberBaseInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		NumberBaseRef<> GenericMul(const NumberBaseRef<>& x) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<NumberBaseInterface>();
			NumberBaseRef<> proxy_result = maxon::PrivateNullReturnValue<NumberBaseRef<>>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._NumberBaseInterface_GenericMul_Offset), maxon::reflection::Argument::ByReference(x)};
			(*handler_)(_fn_NumberBaseInterface_GenericMul, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<NumberBaseRef<>, const maxon::GenericComponent*, const NumberBaseRef<>&>::Invoke, (const void*) mt_._NumberBaseInterface_GenericMul));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_NumberBaseInterface_GenericMul;
	};
	const maxon::reflection::Function* NumberBaseInterface::ProxyComponent::_fn_NumberBaseInterface_GenericMul;
	PRIVATE_MAXON_COMPONENT_REGISTER(NumberBaseInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_NumberBaseInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "x\0", 0LL, NumberBaseInterface, _NumberBaseInterface_GenericMul),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&NumberBaseInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_NumberBaseInterface(nullptr, &NumberBaseInterface::ProxyComponent::_descriptor, &RegisterReflection_NumberBaseInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_NumberInterfaceNumberInterface_Int_4_(NumberInterface<Int,4>::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_NumberInterfaceNumberInterface_Int_4_(nullptr, &NumberInterface<Int,4>::ProxyComponent::_descriptor, &RegisterReflection_NumberInterface<Int,4>, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_Number2InterfaceNumber2Interface_Int_(Number2Interface<Int>::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_Number2InterfaceNumber2Interface_Int_(nullptr, &Number2Interface<Int>::ProxyComponent::_descriptor, &RegisterReflection_Number2Interface<Int>, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
