#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_DimensionInterface(DimensionInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::Dimension");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class DimensionInterface::ProxyComponent : public maxon::Component<ProxyComponent, DimensionInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, DimensionInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(DimensionInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, nullptr, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_DimensionInterface_Static(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DimensionInterface::Hxx2::StaticMTable::_instance.DimensionInterface_Get)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "q\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DimensionInterface::_staticInterface), maxon::ToBlock(functions));
	}
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_DimensionInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			MAXON_GET_VIRTUAL_METHOD_INFO_NO_PROXY(CONST_INSTANCE_FUNCTION, "", 0LL, DimensionInterface, DimensionInterface_GetId),
			MAXON_GET_VIRTUAL_METHOD_INFO_NO_PROXY(CONST_INSTANCE_FUNCTION, "q\0", 0LL, DimensionInterface, DimensionInterface_operatorMul),
			MAXON_GET_VIRTUAL_METHOD_INFO_NO_PROXY(CONST_INSTANCE_FUNCTION, "q\0", 0LL, DimensionInterface, DimensionInterface_operatorDiv),
			MAXON_GET_VIRTUAL_METHOD_INFO_NO_PROXY(CONST_INSTANCE_FUNCTION, "exponent\0", 0LL, DimensionInterface, DimensionInterface_operatorXor),
			MAXON_GET_VIRTUAL_METHOD_INFO_NO_PROXY(CONST_INSTANCE_FUNCTION, "qid\0", 0LL, DimensionInterface, DimensionInterface_Copy),
			MAXON_GET_VIRTUAL_METHOD_INFO_NO_PROXY(CONST_INSTANCE_FUNCTION, "q\0", 0LL, DimensionInterface, DimensionInterface_GetExponent),
			MAXON_GET_VIRTUAL_METHOD_INFO_NO_PROXY(CONST_INSTANCE_FUNCTION, "unitId\0siConversionFactor\0", 0LL, DimensionInterface, DimensionInterface_AddUnit),
			MAXON_GET_VIRTUAL_METHOD_INFO_NO_PROXY(CONST_INSTANCE_FUNCTION, "", 0LL, DimensionInterface, DimensionInterface_GetUnits),
			MAXON_GET_VIRTUAL_METHOD_INFO_NO_PROXY(CONST_INSTANCE_FUNCTION, "other\0", 0LL, DimensionInterface, DimensionInterface_IsEquivalent),
			MAXON_GET_VIRTUAL_METHOD_INFO_NO_PROXY(CONST_INSTANCE_FUNCTION, "fs\0", 0LL, DimensionInterface, DimensionInterface_ToString),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DimensionInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_DimensionInterface(nullptr, &DimensionInterface::ProxyComponent::_descriptor, &RegisterReflection_DimensionInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_DimensionInterface_Static("net.maxon.interface.dimension", nullptr, &RegisterReflection_DimensionInterface_Static, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_UnitInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnitInterface::MTable::_instance.UnitInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnitInterface::MTable::_instance.UnitInterface_GetId)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnitInterface::MTable::_instance.UnitInterface_GetDimension)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnitInterface::MTable::_instance.UnitInterface_GetSIConversionFactor)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnitInterface::MTable::_instance.UnitInterface_operatorMul)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "u\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnitInterface::MTable::_instance.UnitInterface_operatorDiv)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "u\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnitInterface::MTable::_instance.UnitInterface_operatorXor)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "exponent\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnitInterface::MTable::_instance.UnitInterface_Copy)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "uid\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnitInterface::MTable::_instance.UnitInterface_Copy_1)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "quantity\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnitInterface::MTable::_instance.UnitInterface_AddToDimension)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnitInterface::MTable::_instance.UnitInterface_Reduce)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnitInterface::MTable::_instance.UnitInterface_ToString)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "fs\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UnitInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_UnitInterface("net.maxon.interface.unit", nullptr, &RegisterReflection_UnitInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(Dimensions);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(Units);
#endif
}
#endif
