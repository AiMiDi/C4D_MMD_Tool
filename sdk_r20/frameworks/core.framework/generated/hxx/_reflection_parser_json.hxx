#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_NetworkProtocolJSONInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NetworkProtocolJSONInterface::MTable::_instance._NetworkProtocolJSONInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NetworkProtocolJSONInterface::MTable::_instance._NetworkProtocolJSONInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NetworkProtocolJSONInterface::MTable::_instance._NetworkProtocolJSONInterface_ConvertToJSON)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NetworkProtocolJSONInterface::MTable::_instance._NetworkProtocolJSONInterface_ConvertFromJSON)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(NetworkProtocolJSONInterface::MTable::_instance._NetworkProtocolJSONInterface_ConvertFromJSON_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&NetworkProtocolJSONInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_NetworkProtocolJSONInterface("net.maxon.interface.networkprotocoljson", nullptr, &RegisterReflection_NetworkProtocolJSONInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
