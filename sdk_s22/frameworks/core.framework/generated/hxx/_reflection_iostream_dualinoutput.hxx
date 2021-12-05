#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_IoDualInOutputStreamInterface(IoDualInOutputStreamInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class IoDualInOutputStreamInterface::ProxyComponent : public maxon::Component<ProxyComponent, IoDualInOutputStreamInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, IoDualInOutputStreamInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> SetInputStream(const InputStreamRef& inputStream) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoDualInOutputStreamInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoDualInOutputStreamInterface_SetInputStream_Offset), maxon::reflection::Argument::ByReference(inputStream)};
			(*handler_)(_fn_IoDualInOutputStreamInterface_SetInputStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const InputStreamRef&>::Invoke, (const void*) mt_._IoDualInOutputStreamInterface_SetInputStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoDualInOutputStreamInterface_SetInputStream;
		Result<void> SetOutputStream(const OutputStreamRef& outputStream) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoDualInOutputStreamInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoDualInOutputStreamInterface_SetOutputStream_Offset), maxon::reflection::Argument::ByReference(outputStream)};
			(*handler_)(_fn_IoDualInOutputStreamInterface_SetOutputStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<void>, maxon::GenericComponent*, const OutputStreamRef&>::Invoke, (const void*) mt_._IoDualInOutputStreamInterface_SetOutputStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoDualInOutputStreamInterface_SetOutputStream;
		InputStreamRef GetInputStream() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoDualInOutputStreamInterface>();
			InputStreamRef proxy_result = maxon::PrivateIncompleteNullReturnValue<InputStreamRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoDualInOutputStreamInterface_GetInputStream_Offset)};
			(*handler_)(_fn_IoDualInOutputStreamInterface_GetInputStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<InputStreamRef, const maxon::GenericComponent*>::Invoke, (const void*) mt_._IoDualInOutputStreamInterface_GetInputStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoDualInOutputStreamInterface_GetInputStream;
		OutputStreamRef GetOutputStream() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<IoDualInOutputStreamInterface>();
			OutputStreamRef proxy_result = maxon::PrivateIncompleteNullReturnValue<OutputStreamRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._IoDualInOutputStreamInterface_GetOutputStream_Offset)};
			(*handler_)(_fn_IoDualInOutputStreamInterface_GetOutputStream, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<OutputStreamRef, const maxon::GenericComponent*>::Invoke, (const void*) mt_._IoDualInOutputStreamInterface_GetOutputStream));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_IoDualInOutputStreamInterface_GetOutputStream;
	};
	const maxon::reflection::Function* IoDualInOutputStreamInterface::ProxyComponent::_fn_IoDualInOutputStreamInterface_SetInputStream;
	const maxon::reflection::Function* IoDualInOutputStreamInterface::ProxyComponent::_fn_IoDualInOutputStreamInterface_SetOutputStream;
	const maxon::reflection::Function* IoDualInOutputStreamInterface::ProxyComponent::_fn_IoDualInOutputStreamInterface_GetInputStream;
	const maxon::reflection::Function* IoDualInOutputStreamInterface::ProxyComponent::_fn_IoDualInOutputStreamInterface_GetOutputStream;
	PRIVATE_MAXON_COMPONENT_REGISTER(IoDualInOutputStreamInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_IoDualInOutputStreamInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "inputStream\0", 1LL, IoDualInOutputStreamInterface, _IoDualInOutputStreamInterface_SetInputStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "outputStream\0", 1LL, IoDualInOutputStreamInterface, _IoDualInOutputStreamInterface_SetOutputStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, IoDualInOutputStreamInterface, _IoDualInOutputStreamInterface_GetInputStream),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, IoDualInOutputStreamInterface, _IoDualInOutputStreamInterface_GetOutputStream),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&IoDualInOutputStreamInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_IoDualInOutputStreamInterface(nullptr, &IoDualInOutputStreamInterface::ProxyComponent::_descriptor, &RegisterReflection_IoDualInOutputStreamInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
