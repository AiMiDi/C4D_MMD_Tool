#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_UnsupportedArgumentErrorInterface(UnsupportedArgumentErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::UnsupportedArgumentError");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class UnsupportedArgumentErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, UnsupportedArgumentErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, UnsupportedArgumentErrorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(UnsupportedArgumentErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_UnsupportedArgumentErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UnsupportedArgumentErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_UnsupportedArgumentErrorInterface(nullptr, &UnsupportedArgumentErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_UnsupportedArgumentErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_UnresolvedErrorInterface(UnresolvedErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::UnresolvedError");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class UnresolvedErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, UnresolvedErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, UnresolvedErrorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(UnresolvedErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_UnresolvedErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UnresolvedErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_UnresolvedErrorInterface(nullptr, &UnresolvedErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_UnresolvedErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_UnknownErrorInterface(UnknownErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::UnknownError");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class UnknownErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, UnknownErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, UnknownErrorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(UnknownErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_UnknownErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UnknownErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_UnknownErrorInterface(nullptr, &UnknownErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_UnknownErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_UnsupportedOperationErrorInterface(UnsupportedOperationErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::UnsupportedOperationError");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class UnsupportedOperationErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, UnsupportedOperationErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, UnsupportedOperationErrorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(UnsupportedOperationErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_UnsupportedOperationErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UnsupportedOperationErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_UnsupportedOperationErrorInterface(nullptr, &UnsupportedOperationErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_UnsupportedOperationErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ShutdownErrorInterface(ShutdownErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ShutdownError");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ShutdownErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, ShutdownErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ShutdownErrorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(ShutdownErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ShutdownErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ShutdownErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ShutdownErrorInterface(nullptr, &ShutdownErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_ShutdownErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_DisabledErrorInterface(DisabledErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::DisabledError");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class DisabledErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, DisabledErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, DisabledErrorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(DisabledErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_DisabledErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DisabledErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_DisabledErrorInterface(nullptr, &DisabledErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_DisabledErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_ErrnoErrorInterface(ErrnoErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::ErrnoError");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class ErrnoErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, ErrnoErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, ErrnoErrorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(ErrnoErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_ErrnoErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ErrnoErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_ErrnoErrorInterface(nullptr, &ErrnoErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_ErrnoErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
