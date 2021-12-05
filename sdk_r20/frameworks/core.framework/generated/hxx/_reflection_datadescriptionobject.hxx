#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_DataDescriptionObjectInterface(DataDescriptionObjectInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class DataDescriptionObjectInterface::ProxyComponent : public maxon::Component<DataDescriptionObjectInterface::ProxyComponent, DataDescriptionObjectInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<DataDescription> GetObjectDescription(const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData) const 
		{
			const maxon::ComponentInfo* proxy_info;
			maxon::Object* o_;
			const maxon::reflection::ProxyHandler* handler_;
			if (maxon::UInt(this) & (SIZEOF(void*)-1))
			{
				o_ = (maxon::Object*) (maxon::UInt(this) & ~maxon::DefaultAllocator::MIN_ALIGNMENT_MASK);
				proxy_info = &maxon::ClassInfo::PrivateGetClassProxyComponentInfo(o_, _descriptor, reinterpret_cast<const maxon::GenericComponent*>(this));
				handler_ = reinterpret_cast<const maxon::reflection::ProxyHandler*>(proxy_info->_classProxyHandler.GetPointer());
			}
			else
			{
				o_ = (maxon::Object*) self.GetPointer();
				proxy_info = &o_->GetClassInfo()->PrivateGetComponentInfo(_descriptor);
				handler_ = &_handler;
			}
			const MTable& mt_ = ((const PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->GetMTable<DataDescriptionObjectInterface>();
			Result<DataDescription> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionObjectInterface_GetObjectDescription_Offset), maxon::reflection::Argument::ByReference(category), maxon::reflection::Argument::ByReference(language), maxon::reflection::Argument::ByReference(objectData)};
			(*handler_)(_fn_DataDescriptionObjectInterface_GetObjectDescription, o_, maxon::reflection::ProxyInvocation(&proxy_result, proxy_args, &maxon::reflection::Invocation<Result<DataDescription>, const maxon::GenericComponent*, const Id&, const LanguageRef&, const DataDictionaryObjectRef&>::Invoke, (const void*) mt_._DataDescriptionObjectInterface_GetObjectDescription));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionObjectInterface_GetObjectDescription;
	};
	const maxon::reflection::Function* DataDescriptionObjectInterface::ProxyComponent::_fn_DataDescriptionObjectInterface_GetObjectDescription;
	PRIVATE_MAXON_COMPONENT_REGISTER(DataDescriptionObjectInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_DataDescriptionObjectInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, 84LL, DataDescriptionObjectInterface, _DataDescriptionObjectInterface_GetObjectDescription),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataDescriptionObjectInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_DataDescriptionObjectInterface(nullptr, &DataDescriptionObjectInterface::ProxyComponent::_descriptor, &RegisterReflection_DataDescriptionObjectInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
