#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_UuidInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_Alloc_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_Alloc_2)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0uuid\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_Alloc_3)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0uuid\0uuidSize\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_IsEmpty)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_CreateId)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_Set)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "uuid\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_Set_1)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "uuid\0uuidSize\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_Get)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "uuid\0uuidSize\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_ToString)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "formatStatement\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_Compare)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "uuid\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_GetHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_GetUniqueHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_DescribeIO)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "stream\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_CreateUuidString)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UuidInterface::MTable::_instance.UuidInterface_CreateUuid)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "uuid\0", 2LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UuidInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_UuidInterface("net.maxon.interface.uuid", nullptr, &RegisterReflection_UuidInterface, &PRIVATE_MAXON_MODULE);
#endif
#if (defined MAXON_TARGET_WINDOWS) && (defined MAXON_TARGET_DEBUG)
#endif
}
#endif
