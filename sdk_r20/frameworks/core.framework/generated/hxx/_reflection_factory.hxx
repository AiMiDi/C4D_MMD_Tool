#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_FactoryInterface(FactoryInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class FactoryInterface::ProxyComponent : public maxon::Component<FactoryInterface::ProxyComponent, FactoryInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		const DelegateBase* PrivateGetDelegate() const 
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
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<FactoryInterface>();
			const DelegateBase* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._FactoryInterface_PrivateGetDelegate_Offset)};
			(*handler_)(_fn_FactoryInterface_PrivateGetDelegate, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<const DelegateBase*, const maxon::GenericComponent*>::Invoke, (const void*) mt_._FactoryInterface_PrivateGetDelegate));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_FactoryInterface_PrivateGetDelegate;
	};
	const maxon::reflection::Function* FactoryInterface::ProxyComponent::_fn_FactoryInterface_PrivateGetDelegate;
	PRIVATE_MAXON_COMPONENT_REGISTER(FactoryInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_FactoryInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 0LL, FactoryInterface, _FactoryInterface_PrivateGetDelegate),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&FactoryInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_FactoryInterface(nullptr, &FactoryInterface::ProxyComponent::_descriptor, &RegisterReflection_FactoryInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_FactoryFactory(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(FactoryFactory::MTable::_instance._FactoryFactory_PrivateCreate)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(FactoryFactory::MTable::_instance._FactoryFactory_PrivateCreateCached)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(FactoryFactory::MTable::_instance._FactoryFactory_CreateDataCached)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&FactoryFactory::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_FactoryFactory("net.maxon.interface.factoryfactory", nullptr, &RegisterReflection_FactoryFactory, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
