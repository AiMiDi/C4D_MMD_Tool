#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_SecureRandom(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(SecureRandom::MTable::_instance.SecureRandom_GetDefaultProvider)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(SecureRandom::MTable::_instance.SecureRandom_GetRandomNumber)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "provider\0buffer\0", 5LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&SecureRandom::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_SecureRandom("net.maxon.interface.securerandom", nullptr, &RegisterReflection_SecureRandom, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
