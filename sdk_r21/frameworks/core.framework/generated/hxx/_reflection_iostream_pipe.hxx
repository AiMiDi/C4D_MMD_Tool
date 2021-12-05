#if 1
namespace maxon
{
#ifdef MAXON_TARGET_WINDOWS
#else
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_IoPipeInOutputStreamInterface(IoPipeInOutputStreamInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class IoPipeInOutputStreamInterface::ProxyComponent : public maxon::Component<ProxyComponent, IoPipeInOutputStreamInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, IoPipeInOutputStreamInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		PIPEHANDLE GetReadHandle() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoPipeInOutputStreamInterface>();
			PIPEHANDLE proxy_result = maxon::PrivateIncompleteNullReturnValue<PIPEHANDLE>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoPipeInOutputStreamInterface_GetReadHandle_Offset)};
			(*handler_)(_fn_IoPipeInOutputStreamInterface_GetReadHandle, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<PIPEHANDLE, const maxon::GenericComponent*>::Invoke, (const void*) mt_._IoPipeInOutputStreamInterface_GetReadHandle));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoPipeInOutputStreamInterface_GetReadHandle;
		PIPEHANDLE GetWriteHandle() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoPipeInOutputStreamInterface>();
			PIPEHANDLE proxy_result = maxon::PrivateIncompleteNullReturnValue<PIPEHANDLE>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoPipeInOutputStreamInterface_GetWriteHandle_Offset)};
			(*handler_)(_fn_IoPipeInOutputStreamInterface_GetWriteHandle, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<PIPEHANDLE, const maxon::GenericComponent*>::Invoke, (const void*) mt_._IoPipeInOutputStreamInterface_GetWriteHandle));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoPipeInOutputStreamInterface_GetWriteHandle;
	};
	const maxon::reflection::Function* IoPipeInOutputStreamInterface::ProxyComponent::_fn_IoPipeInOutputStreamInterface_GetReadHandle;
	const maxon::reflection::Function* IoPipeInOutputStreamInterface::ProxyComponent::_fn_IoPipeInOutputStreamInterface_GetWriteHandle;
	PRIVATE_MAXON_COMPONENT_REGISTER(IoPipeInOutputStreamInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_IoPipeInOutputStreamInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, IoPipeInOutputStreamInterface, _IoPipeInOutputStreamInterface_GetReadHandle),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, IoPipeInOutputStreamInterface, _IoPipeInOutputStreamInterface_GetWriteHandle),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&IoPipeInOutputStreamInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_IoPipeInOutputStreamInterface(nullptr, &IoPipeInOutputStreamInterface::ProxyComponent::_descriptor, &RegisterReflection_IoPipeInOutputStreamInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
