#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ImagePixelDeepImageStorageInterface(ImagePixelDeepImageStorageInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ImagePixelDeepImageStorage");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ImagePixelDeepImageStorageInterface::ProxyComponent : public maxon::Component<ProxyComponent, ImagePixelDeepImageStorageInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ImagePixelDeepImageStorageInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(ImagePixelDeepImageStorageInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ImagePixelDeepImageStorageInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ImagePixelDeepImageStorageInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ImagePixelDeepImageStorageInterface(nullptr, &ImagePixelDeepImageStorageInterface::ProxyComponent::_descriptor, &RegisterReflection_ImagePixelDeepImageStorageInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
