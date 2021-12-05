#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_PixelFormatDynamicInterface(PixelFormatDynamicInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::PixelFormatDynamic");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class PixelFormatDynamicInterface::ProxyComponent : public maxon::Component<ProxyComponent, PixelFormatDynamicInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, PixelFormatDynamicInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<Int> AddChannel(const ImageChannel& channel) 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<PixelFormatDynamicInterface>();
			Result<Int> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._PixelFormatDynamicInterface_AddChannel_Offset), maxon::reflection::Argument::ByReference(channel)};
			(*handler_)(_fn_PixelFormatDynamicInterface_AddChannel, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<Int>, maxon::GenericComponent*, const ImageChannel&>::Invoke, (const void*) mt_._PixelFormatDynamicInterface_AddChannel));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_PixelFormatDynamicInterface_AddChannel;
	};
	const maxon::reflection::Function* PixelFormatDynamicInterface::ProxyComponent::_fn_PixelFormatDynamicInterface_AddChannel;
	PRIVATE_MAXON_COMPONENT_REGISTER(PixelFormatDynamicInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_PixelFormatDynamicInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(INSTANCE_FUNCTION, "channel\0", 1LL, PixelFormatDynamicInterface, _PixelFormatDynamicInterface_AddChannel),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&PixelFormatDynamicInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_PixelFormatDynamicInterface(nullptr, &PixelFormatDynamicInterface::ProxyComponent::_descriptor, &RegisterReflection_PixelFormatDynamicInterface, &PRIVATE_MAXON_MODULE);
#endif
	namespace PixelFormats
	{
	#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
		PRIVATE_MAXON_REGISTRY_DEFINE(Dynamic);
	#endif
	}
}
#endif
