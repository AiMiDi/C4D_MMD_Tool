#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_DecoratorInterface(DecoratorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class DecoratorInterface::ProxyComponent : public maxon::Component<ProxyComponent, DecoratorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, DecoratorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		ObjectRef PrivateGetDecoratedObject() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DecoratorInterface>();
			ObjectRef proxy_result = maxon::PrivateIncompleteNullReturnValue<ObjectRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DecoratorInterface_PrivateGetDecoratedObject_Offset)};
			(*handler_)(_fn_DecoratorInterface_PrivateGetDecoratedObject, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<ObjectRef, const maxon::GenericComponent*>::Invoke, (const void*) mt_._DecoratorInterface_PrivateGetDecoratedObject));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DecoratorInterface_PrivateGetDecoratedObject;
	};
	const maxon::reflection::Function* DecoratorInterface::ProxyComponent::_fn_DecoratorInterface_PrivateGetDecoratedObject;
	PRIVATE_MAXON_COMPONENT_REGISTER(DecoratorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_DecoratorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, DecoratorInterface, _DecoratorInterface_PrivateGetDecoratedObject),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DecoratorInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_DecoratorInterface(nullptr, &DecoratorInterface::ProxyComponent::_descriptor, &RegisterReflection_DecoratorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_EagerDecoratorInterface(EagerDecoratorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class EagerDecoratorInterface::ProxyComponent : public maxon::Component<ProxyComponent, EagerDecoratorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, EagerDecoratorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		void PrivateSetDecoratedObject(const ObjectRef& object) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<EagerDecoratorInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._EagerDecoratorInterface_PrivateSetDecoratedObject_Offset), maxon::reflection::Argument::ByReference(object)};
			(*handler_)(_fn_EagerDecoratorInterface_PrivateSetDecoratedObject, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, const ObjectRef&>::Invoke, (const void*) mt_._EagerDecoratorInterface_PrivateSetDecoratedObject));
		}
		static const maxon::reflection::Function* _fn_EagerDecoratorInterface_PrivateSetDecoratedObject;
		void PrivateSetDecoratedObject(ObjectRef&& object) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<EagerDecoratorInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._EagerDecoratorInterface_PrivateSetDecoratedObject_1_Offset), maxon::reflection::Argument::ByReference(object)};
			(*handler_)(_fn_EagerDecoratorInterface_PrivateSetDecoratedObject_1, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, ObjectRef&&>::Invoke, (const void*) mt_._EagerDecoratorInterface_PrivateSetDecoratedObject_1));
		}
		static const maxon::reflection::Function* _fn_EagerDecoratorInterface_PrivateSetDecoratedObject_1;
	};
	const maxon::reflection::Function* EagerDecoratorInterface::ProxyComponent::_fn_EagerDecoratorInterface_PrivateSetDecoratedObject;
	const maxon::reflection::Function* EagerDecoratorInterface::ProxyComponent::_fn_EagerDecoratorInterface_PrivateSetDecoratedObject_1;
	PRIVATE_MAXON_COMPONENT_REGISTER(EagerDecoratorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_EagerDecoratorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "object\0", 1LL, EagerDecoratorInterface, _EagerDecoratorInterface_PrivateSetDecoratedObject),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "object\0", 1LL, EagerDecoratorInterface, _EagerDecoratorInterface_PrivateSetDecoratedObject_1),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&EagerDecoratorInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_EagerDecoratorInterface(nullptr, &EagerDecoratorInterface::ProxyComponent::_descriptor, &RegisterReflection_EagerDecoratorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_WeakDecoratorInterface(WeakDecoratorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class WeakDecoratorInterface::ProxyComponent : public maxon::Component<ProxyComponent, WeakDecoratorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, WeakDecoratorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		void PrivateSetDecoratedObject(const ObjectRef& object) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<WeakDecoratorInterface>();
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._WeakDecoratorInterface_PrivateSetDecoratedObject_Offset), maxon::reflection::Argument::ByReference(object)};
			(*handler_)(_fn_WeakDecoratorInterface_PrivateSetDecoratedObject, o_, maxon::reflection::ProxyInvocation(nullptr, proxy_args, &maxon::reflection::Invocation<void, maxon::GenericComponent*, const ObjectRef&>::Invoke, (const void*) mt_._WeakDecoratorInterface_PrivateSetDecoratedObject));
		}
		static const maxon::reflection::Function* _fn_WeakDecoratorInterface_PrivateSetDecoratedObject;
	};
	const maxon::reflection::Function* WeakDecoratorInterface::ProxyComponent::_fn_WeakDecoratorInterface_PrivateSetDecoratedObject;
	PRIVATE_MAXON_COMPONENT_REGISTER(WeakDecoratorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_WeakDecoratorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "object\0", 1LL, WeakDecoratorInterface, _WeakDecoratorInterface_PrivateSetDecoratedObject),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&WeakDecoratorInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_WeakDecoratorInterface(nullptr, &WeakDecoratorInterface::ProxyComponent::_descriptor, &RegisterReflection_WeakDecoratorInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
