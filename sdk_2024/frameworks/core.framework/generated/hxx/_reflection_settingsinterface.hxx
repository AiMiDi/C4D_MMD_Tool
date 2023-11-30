#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_SettingsInterface(SettingsInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::SettingsRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class SettingsInterface::ProxyComponent : public maxon::Component<ProxyComponent, SettingsInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, SettingsInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		ACCESSLEVEL GetAccessLevel() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<SettingsInterface>();
			ACCESSLEVEL proxy_result = HXXRET3(NULLIMPL, ACCESSLEVEL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.SettingsInterface_GetAccessLevel_Offset)};
			(*handler_)(_fn_SettingsInterface_GetAccessLevel, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((ACCESSLEVEL)), reinterpret_cast<const void* const&>(mt_.SettingsInterface_GetAccessLevel)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_SettingsInterface_GetAccessLevel;
		SettingsRef GetParentSettings() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<SettingsInterface>();
			SettingsRef proxy_result = HXXRET3(NULLIMPL, SettingsRef);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.SettingsInterface_GetParentSettings_Offset)};
			(*handler_)(_fn_SettingsInterface_GetParentSettings, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((SettingsRef)), reinterpret_cast<const void* const&>(mt_.SettingsInterface_GetParentSettings)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_SettingsInterface_GetParentSettings;
		Result<DataDictionary> GetSettingsCopy(const HashSet<Id>& optionalList, ACCESSLEVEL accessLevel) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<SettingsInterface>();
			Result<DataDictionary> proxy_result = HXXRET1(NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.SettingsInterface_GetSettingsCopy_Offset), maxon::reflection::Argument::ByReference(optionalList), maxon::reflection::Argument::ByValue(accessLevel)};
			(*handler_)(_fn_SettingsInterface_GetSettingsCopy, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<DataDictionary>), const HashSet<Id>&, ACCESSLEVEL), reinterpret_cast<const void* const&>(mt_.SettingsInterface_GetSettingsCopy)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_SettingsInterface_GetSettingsCopy;
	};
	const maxon::reflection::Function* SettingsInterface::ProxyComponent::_fn_SettingsInterface_GetAccessLevel;
	const maxon::reflection::Function* SettingsInterface::ProxyComponent::_fn_SettingsInterface_GetParentSettings;
	const maxon::reflection::Function* SettingsInterface::ProxyComponent::_fn_SettingsInterface_GetSettingsCopy;
	PRIVATE_MAXON_COMPONENT_REGISTER(SettingsInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_SettingsInterface_Static(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(SettingsInterface::Hxx2::StaticMTable::_instance.SettingsInterface_GetSettings)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "accessLevel\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SettingsInterface::Hxx2::StaticMTable::_instance.SettingsInterface_ObservableSettingsChanged)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "create\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&SettingsInterface::_staticInterface), maxon::ToBlock(functions));
	}
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_SettingsInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, SettingsInterface, SettingsInterface_GetAccessLevel),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, SettingsInterface, SettingsInterface_GetParentSettings),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "optionalList\0accessLevel\0", 5LL, SettingsInterface, SettingsInterface_GetSettingsCopy),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&SettingsInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_SettingsInterface(nullptr, &SettingsInterface::ProxyComponent::_descriptor, &RegisterReflection_SettingsInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_SettingsInterface_Static("net.maxon.interface.settingsinterface", nullptr, &RegisterReflection_SettingsInterface_Static, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
