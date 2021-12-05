#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_DescriptionProcessorInterface(DescriptionProcessorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class DescriptionProcessorInterface::ProxyComponent : public maxon::Component<ProxyComponent, DescriptionProcessorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, DescriptionProcessorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<GenericData> Process(const Id& descriptionId, const DataDescription& dataDescription) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DescriptionProcessorInterface>();
			Result<GenericData> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DescriptionProcessorInterface_Process_Offset), maxon::reflection::Argument::ByReference(descriptionId), maxon::reflection::Argument::ByReference(dataDescription)};
			(*handler_)(_fn_DescriptionProcessorInterface_Process, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<GenericData>, const maxon::GenericComponent*, const Id&, const DataDescription&>::Invoke, (const void*) mt_._DescriptionProcessorInterface_Process));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DescriptionProcessorInterface_Process;
	};
	const maxon::reflection::Function* DescriptionProcessorInterface::ProxyComponent::_fn_DescriptionProcessorInterface_Process;
	PRIVATE_MAXON_COMPONENT_REGISTER(DescriptionProcessorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_DescriptionProcessorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "descriptionId\0dataDescription\0", 5LL, DescriptionProcessorInterface, _DescriptionProcessorInterface_Process),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DescriptionProcessorInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_DescriptionProcessorInterface(nullptr, &DescriptionProcessorInterface::ProxyComponent::_descriptor, &RegisterReflection_DescriptionProcessorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(DescriptionProcessors);
#endif
}
#endif
