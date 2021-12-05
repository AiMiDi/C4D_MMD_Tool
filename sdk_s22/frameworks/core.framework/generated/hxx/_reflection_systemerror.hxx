#if 1
#if defined(MAXON_TARGET_MACOS) || defined(MAXON_TARGET_IOS)
#ifdef __OBJC__
#else
#endif
#else
#endif
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_SystemErrorInterface(SystemErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class SystemErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, SystemErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, SystemErrorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(SystemErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_SystemErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&SystemErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_SystemErrorInterface(nullptr, &SystemErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_SystemErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_NSSystemErrorInterface(NSSystemErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class NSSystemErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, NSSystemErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, NSSystemErrorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		void SetNSError(NSError* osError) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<NSSystemErrorInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._NSSystemErrorInterface_SetNSError_Offset), maxon::reflection::Argument::ByValue(osError)};
			(*handler_)(_fn_NSSystemErrorInterface_SetNSError, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, NSError*>::Invoke, (const void*) mt_._NSSystemErrorInterface_SetNSError));
		}
		static const maxon::reflection::Function* _fn_NSSystemErrorInterface_SetNSError;
		NSError* GetNSError() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<NSSystemErrorInterface>();
			NSError* proxy_result = nullptr;
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._NSSystemErrorInterface_GetNSError_Offset)};
			(*handler_)(_fn_NSSystemErrorInterface_GetNSError, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<NSError*, const maxon::GenericComponent*>::Invoke, (const void*) mt_._NSSystemErrorInterface_GetNSError));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_NSSystemErrorInterface_GetNSError;
	};
	const maxon::reflection::Function* NSSystemErrorInterface::ProxyComponent::_fn_NSSystemErrorInterface_SetNSError;
	const maxon::reflection::Function* NSSystemErrorInterface::ProxyComponent::_fn_NSSystemErrorInterface_GetNSError;
	PRIVATE_MAXON_COMPONENT_REGISTER(NSSystemErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_NSSystemErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "osError\0", 1LL, NSSystemErrorInterface, _NSSystemErrorInterface_SetNSError),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, NSSystemErrorInterface, _NSSystemErrorInterface_GetNSError),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&NSSystemErrorInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_NSSystemErrorInterface(nullptr, &NSSystemErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_NSSystemErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
