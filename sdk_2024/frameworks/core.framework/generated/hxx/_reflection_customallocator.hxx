#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_CustomAllocatorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(CustomAllocatorInterface::MTable::_instance.CustomAllocatorInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CustomAllocatorInterface::MTable::_instance.CustomAllocatorInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CustomAllocatorInterface::MTable::_instance.CustomAllocatorInterface_Alloc_1)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "s\0allocLocation\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CustomAllocatorInterface::MTable::_instance.CustomAllocatorInterface_AllocClear)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "s\0allocLocation\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CustomAllocatorInterface::MTable::_instance.CustomAllocatorInterface_Realloc)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "data\0size\0allocLocation\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CustomAllocatorInterface::MTable::_instance.CustomAllocatorInterface_PrivateAlloc)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "size\0clear\0allocLocation\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CustomAllocatorInterface::MTable::_instance.CustomAllocatorInterface_PrivateFree)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "data\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(CustomAllocatorInterface::MTable::_instance.CustomAllocatorInterface_PrivateGetDataSize)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "data\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CustomAllocatorInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_CustomAllocatorInterface("net.maxon.interface.customallocator", nullptr, &RegisterReflection_CustomAllocatorInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
