#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_FactoryInterface(FactoryInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::GenericFactory");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class FactoryInterface::ProxyComponent : public maxon::Component<ProxyComponent, FactoryInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, FactoryInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		const DelegateBase* PrivateGetDelegate() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<FactoryInterface>();
			const DelegateBase* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.FactoryInterface_PrivateGetDelegate_Offset)};
			(*handler_)(_fn_FactoryInterface_PrivateGetDelegate, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((const DelegateBase*)), reinterpret_cast<const void* const&>(mt_.FactoryInterface_PrivateGetDelegate)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_FactoryInterface_PrivateGetDelegate;
	};
	const maxon::reflection::Function* FactoryInterface::ProxyComponent::_fn_FactoryInterface_PrivateGetDelegate;
	PRIVATE_MAXON_COMPONENT_REGISTER(FactoryInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_FactoryInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, FactoryInterface, FactoryInterface_PrivateGetDelegate),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&FactoryInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_FactoryInterface(nullptr, &FactoryInterface::ProxyComponent::_descriptor, &RegisterReflection_FactoryInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_FactoryFactory(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(FactoryFactory::MTable::_instance.FactoryFactory_PrivateCreate)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "func\0params\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(FactoryFactory::MTable::_instance.FactoryFactory_PrivateCreateCached)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "func\0creator\0size\0params\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(FactoryFactory::MTable::_instance.FactoryFactory_CreateDataCached)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "factory\0params\0dc\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&FactoryFactory::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_FactoryFactory("net.maxon.interface.factoryfactory", nullptr, &RegisterReflection_FactoryFactory, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
