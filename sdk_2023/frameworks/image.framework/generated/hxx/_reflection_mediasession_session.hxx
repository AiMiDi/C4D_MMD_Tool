#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_MediaSessionInterface(MediaSessionInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::MediaSessionRef");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class MediaSessionInterface::ProxyComponent : public maxon::Component<ProxyComponent, MediaSessionInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, MediaSessionInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<void> ConnectMediaConverter(const MediaConverterRef& input, const MediaConverterRef& output) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaSessionInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_ConnectMediaConverter_Offset), maxon::reflection::Argument::ByReference(input), maxon::reflection::Argument::ByReference(output)};
			(*handler_)(_fn_MediaSessionInterface_ConnectMediaConverter, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const MediaConverterRef&, const MediaConverterRef&), reinterpret_cast<const void* const&>(mt_.MediaSessionInterface_ConnectMediaConverter)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaSessionInterface_ConnectMediaConverter;
		Result<void> Convert(const TimeValue& targetTime, MEDIASESSIONFLAGS flags) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaSessionInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_Convert_Offset), maxon::reflection::Argument::ByReference(targetTime), maxon::reflection::Argument::ByValue(flags)};
			(*handler_)(_fn_MediaSessionInterface_Convert, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>), const TimeValue&, MEDIASESSIONFLAGS), reinterpret_cast<const void* const&>(mt_.MediaSessionInterface_Convert)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaSessionInterface_Convert;
		Result<void> Close() 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaSessionInterface>();
			Result<void> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_Close_Offset)};
			(*handler_)(_fn_MediaSessionInterface_Close, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((Result<void>)), reinterpret_cast<const void* const&>(mt_.MediaSessionInterface_Close)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaSessionInterface_Close;
		ProgressRef GetProgress() const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<MediaSessionInterface>();
			ProgressRef proxy_result = maxon::PrivateIncompleteNullReturnValue<ProgressRef>(maxon::NULL_RETURN_REASON::NULLIMPL, OVERLOAD_MAX_RANK);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_.MediaSessionInterface_GetProgress_Offset)};
			(*handler_)(_fn_MediaSessionInterface_GetProgress, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, PRIVATE_MAXON_MF_REFLECTION_INVOCATION((ProgressRef)), reinterpret_cast<const void* const&>(mt_.MediaSessionInterface_GetProgress)));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_MediaSessionInterface_GetProgress;
	};
	const maxon::reflection::Function* MediaSessionInterface::ProxyComponent::_fn_MediaSessionInterface_ConnectMediaConverter;
	const maxon::reflection::Function* MediaSessionInterface::ProxyComponent::_fn_MediaSessionInterface_Convert;
	const maxon::reflection::Function* MediaSessionInterface::ProxyComponent::_fn_MediaSessionInterface_Close;
	const maxon::reflection::Function* MediaSessionInterface::ProxyComponent::_fn_MediaSessionInterface_GetProgress;
	PRIVATE_MAXON_COMPONENT_REGISTER(MediaSessionInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_MediaSessionInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "input\0output\0", 0LL, MediaSessionInterface, MediaSessionInterface_ConnectMediaConverter),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "targetTime\0flags\0", 5LL, MediaSessionInterface, MediaSessionInterface_Convert),
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "", 0LL, MediaSessionInterface, MediaSessionInterface_Close),
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "", 0LL, MediaSessionInterface, MediaSessionInterface_GetProgress),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&MediaSessionInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_MediaSessionInterface(nullptr, &MediaSessionInterface::ProxyComponent::_descriptor, &RegisterReflection_MediaSessionInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
