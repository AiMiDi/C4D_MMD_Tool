#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ColorSpaceInterface(ColorSpaceInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ColorSpace");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ColorSpaceInterface::ProxyComponent : public maxon::Component<ProxyComponent, ColorSpaceInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ColorSpaceInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		const ColorProfile& GetDefaultNonlinearColorProfile() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ColorSpaceInterface>();
			const ColorProfile* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const ColorProfile&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ColorSpaceInterface_GetDefaultNonlinearColorProfile_Offset)};
			(*handler_)(_fn_ColorSpaceInterface_GetDefaultNonlinearColorProfile, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const ColorProfile&, const maxon::GenericComponent*>::Invoke, (const void*) mt_.ColorSpaceInterface_GetDefaultNonlinearColorProfile));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_ColorSpaceInterface_GetDefaultNonlinearColorProfile;
		const ColorProfile& GetDefaultLinearColorProfile() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<ColorSpaceInterface>();
			const ColorProfile* proxy_result = &maxon::PrivateIncompleteNullReturnValue<const ColorProfile&>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.ColorSpaceInterface_GetDefaultLinearColorProfile_Offset)};
			(*handler_)(_fn_ColorSpaceInterface_GetDefaultLinearColorProfile, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<const ColorProfile&, const maxon::GenericComponent*>::Invoke, (const void*) mt_.ColorSpaceInterface_GetDefaultLinearColorProfile));
			return *proxy_result;
		}
		static const maxon::reflection::Function* _fn_ColorSpaceInterface_GetDefaultLinearColorProfile;
	};
	const maxon::reflection::Function* ColorSpaceInterface::ProxyComponent::_fn_ColorSpaceInterface_GetDefaultNonlinearColorProfile;
	const maxon::reflection::Function* ColorSpaceInterface::ProxyComponent::_fn_ColorSpaceInterface_GetDefaultLinearColorProfile;
	PRIVATE_MAXON_COMPONENT_REGISTER(ColorSpaceInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ColorSpaceInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ColorSpaceInterface, ColorSpaceInterface_GetDefaultNonlinearColorProfile),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, ColorSpaceInterface, ColorSpaceInterface_GetDefaultLinearColorProfile),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ColorSpaceInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ColorSpaceInterface(nullptr, &ColorSpaceInterface::ProxyComponent::_descriptor, &RegisterReflection_ColorSpaceInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
