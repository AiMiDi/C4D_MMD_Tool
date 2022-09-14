#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_CryptographyStreamConversionInterface(CryptographyStreamConversionInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::CryptographyStreamConversionRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class CryptographyStreamConversionInterface::ProxyComponent : public maxon::Component<ProxyComponent, CryptographyStreamConversionInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, CryptographyStreamConversionInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Bool IsChainingChiffre() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<CryptographyStreamConversionInterface>();
			Bool proxy_result = maxon::PrivateLogNullptrError(false);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.CryptographyStreamConversionInterface_IsChainingChiffre_Offset)};
			(*handler_)(_fn_CryptographyStreamConversionInterface_IsChainingChiffre, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Bool)), reinterpret_cast<const void* const&>(mt_.CryptographyStreamConversionInterface_IsChainingChiffre)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_CryptographyStreamConversionInterface_IsChainingChiffre;
	};
	const maxon::reflection::Function* CryptographyStreamConversionInterface::ProxyComponent::_fn_CryptographyStreamConversionInterface_IsChainingChiffre;
	PRIVATE_MAXON_COMPONENT_REGISTER(CryptographyStreamConversionInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_CryptographyStreamConversionInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, CryptographyStreamConversionInterface, CryptographyStreamConversionInterface_IsChainingChiffre),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CryptographyStreamConversionInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_CryptographyStreamConversionInterface(nullptr, &CryptographyStreamConversionInterface::ProxyComponent::_descriptor, &RegisterReflection_CryptographyStreamConversionInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
