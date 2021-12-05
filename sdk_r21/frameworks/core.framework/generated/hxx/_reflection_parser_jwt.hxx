#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_JwtParserInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JwtParserInterface::MTable::_instance._JwtParserInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JwtParserInterface::MTable::_instance._JwtParserInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JwtParserInterface::MTable::_instance._JwtParserInterface_Read)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "nameOrStream\0flags\0stringDecoding\0publicKey\0jsonObjects\0originalToken\0", 2373LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JwtParserInterface::MTable::_instance._JwtParserInterface_Read_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "jwtString\0flags\0stringDecoding\0publicKey\0jsonObjects\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JwtParserInterface::MTable::_instance._JwtParserInterface_Write)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "jsonObject\0stringEncoding\0privateKey\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&JwtParserInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_JwtParserInterface("net.maxon.interface.jwtparser", nullptr, &RegisterReflection_JwtParserInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
