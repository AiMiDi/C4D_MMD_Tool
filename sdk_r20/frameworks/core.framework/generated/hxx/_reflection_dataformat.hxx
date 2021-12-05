#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_DataFormatReaderInterface(DataFormatReaderInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class DataFormatReaderInterface::ProxyComponent : public maxon::Component<DataFormatReaderInterface::ProxyComponent, DataFormatReaderInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(DataFormatReaderInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_DataFormatReaderInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataFormatReaderInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_DataFormatReaderInterface(nullptr, &DataFormatReaderInterface::ProxyComponent::_descriptor, &RegisterReflection_DataFormatReaderInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_DataFormatWriterInterface(DataFormatWriterInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class DataFormatWriterInterface::ProxyComponent : public maxon::Component<DataFormatWriterInterface::ProxyComponent, DataFormatWriterInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(DataFormatWriterInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_DataFormatWriterInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataFormatWriterInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_DataFormatWriterInterface(nullptr, &DataFormatWriterInterface::ProxyComponent::_descriptor, &RegisterReflection_DataFormatWriterInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(DataFormatReaderFactories);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(DataFormatWriterFactories);
#endif
}
#endif
