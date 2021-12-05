#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_DataDescriptionObjectInterface(DataDescriptionObjectInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class DataDescriptionObjectInterface::ProxyComponent : public maxon::Component<ProxyComponent, DataDescriptionObjectInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, DataDescriptionObjectInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
		Result<DataDescription> GetObjectDescription(const Id& category, const LanguageRef& language, const DataDictionaryObjectRef& objectData) const 
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
			const MTable& mt_ = ((const typename ProxyComponent::PrivateSuperMTable*) proxy_info->_supervtable.GetPointer())->template GetMTable<DataDescriptionObjectInterface>();
			Result<DataDescription> proxy_result = maxon::PrivateGetNullReturnError(maxon::NULL_RETURN_REASON::NULLIMPL);
			maxon::reflection::Argument proxy_args[] = {maxon::reflection::Argument::ByValue(reinterpret_cast<maxon::GenericComponent*>(o_) + mt_._DataDescriptionObjectInterface_GetObjectDescription_Offset), maxon::reflection::Argument::ByReference(category), maxon::reflection::Argument::ByReference(language), maxon::reflection::Argument::ByReference(objectData)};
			(*handler_)(_fn_DataDescriptionObjectInterface_GetObjectDescription, o_, maxon::reflection::ProxyInvocation(std::addressof(proxy_result), proxy_args, &maxon::reflection::Invocation<Result<DataDescription>, const maxon::GenericComponent*, const Id&, const LanguageRef&, const DataDictionaryObjectRef&>::Invoke, (const void*) mt_._DataDescriptionObjectInterface_GetObjectDescription));
			return proxy_result;
		}
		static const maxon::reflection::Function* _fn_DataDescriptionObjectInterface_GetObjectDescription;
	};
	const maxon::reflection::Function* DataDescriptionObjectInterface::ProxyComponent::_fn_DataDescriptionObjectInterface_GetObjectDescription;
	PRIVATE_MAXON_COMPONENT_REGISTER(DataDescriptionObjectInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_DataDescriptionObjectInterface_Static(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDescriptionObjectInterface::Hxx2::StaticMTable::_instance._DataDescriptionObjectInterface_GetObjectName)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "classId\0language\0", 5LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataDescriptionObjectInterface::_staticInterface), maxon::ToBlock(functions));
	}
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_DataDescriptionObjectInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO(CONST_INSTANCE_FUNCTION, "category\0language\0objectData\0", 21LL, DataDescriptionObjectInterface, _DataDescriptionObjectInterface_GetObjectDescription),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataDescriptionObjectInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_DataDescriptionObjectInterface(nullptr, &DataDescriptionObjectInterface::ProxyComponent::_descriptor, &RegisterReflection_DataDescriptionObjectInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_DataDescriptionObjectInterface_Static("net.maxon.interface.datadescriptionobject", nullptr, &RegisterReflection_DataDescriptionObjectInterface_Static, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
