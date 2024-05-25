#if 1
namespace maxon
{
/// @cond INTERNAL

#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_RegistryEntryIteratorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(RegistryEntryIteratorInterface::MTable::_instance.RegistryEntryIteratorInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "iterator\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RegistryEntryIteratorInterface::MTable::_instance.RegistryEntryIteratorInterface_HasValue)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RegistryEntryIteratorInterface::MTable::_instance.RegistryEntryIteratorInterface_MoveToNext)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RegistryEntryIteratorInterface::MTable::_instance.RegistryEntryIteratorInterface_GetId)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RegistryEntryIteratorInterface::MTable::_instance.RegistryEntryIteratorInterface_GetEntry)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&RegistryEntryIteratorInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_RegistryEntryIteratorInterface("net.maxon.interface.registryentryiterator", nullptr, &RegisterReflection_RegistryEntryIteratorInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_RegistryInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(RegistryInterface::MTable::_instance.RegistryInterface_GetId)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RegistryInterface::MTable::_instance.RegistryInterface_GetStamp)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RegistryInterface::MTable::_instance.RegistryInterface_GetDataType)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RegistryInterface::MTable::_instance.RegistryInterface_AddObserver)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "observer\0notifyDuringRegistration\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RegistryInterface::MTable::_instance.RegistryInterface_Find)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "registry\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RegistryInterface::MTable::_instance.RegistryInterface_InsertEntry)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "registry\0eid\0value\0module\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RegistryInterface::MTable::_instance.RegistryInterface_EraseEntry)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "registry\0eid\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RegistryInterface::MTable::_instance.RegistryInterface_Register)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "registry\0eid\0value\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RegistryInterface::MTable::_instance.RegistryInterface_FindEntryValue)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "registry\0eid\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(RegistryInterface::MTable::_instance.RegistryInterface_PrivateCreateIterator)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "registry\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&RegistryInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_RegistryInterface("net.maxon.interface.registry", nullptr, &RegisterReflection_RegistryInterface, &PRIVATE_MAXON_MODULE);
#endif
/// @endcond

}
#endif
