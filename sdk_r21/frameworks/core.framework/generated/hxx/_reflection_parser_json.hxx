#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_JsonParserInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JsonParserInterface::MTable::_instance._JsonParserInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JsonParserInterface::MTable::_instance._JsonParserInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JsonParserInterface::MTable::_instance._JsonParserInterface_Write)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "jsonObject\0jsonString\0niceFormatting\0", 25LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JsonParserInterface::MTable::_instance._JsonParserInterface_Read)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "jsonString\0flags\0jsonObjects\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JsonParserInterface::MTable::_instance._JsonParserInterface_Read_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "nameOrStream\0flags\0stringDecoding\0jsonObjects\0", 69LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&JsonParserInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_JsonParserInterface("net.maxon.interface.jsonparser", nullptr, &RegisterReflection_JsonParserInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
