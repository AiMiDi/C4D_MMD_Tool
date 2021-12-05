#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_CustomAllocatorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CustomAllocatorInterface::MTable::_instance._CustomAllocatorInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CustomAllocatorInterface::MTable::_instance._CustomAllocatorInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CustomAllocatorInterface::MTable::_instance._CustomAllocatorInterface_Alloc_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "s\0allocLocation\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CustomAllocatorInterface::MTable::_instance._CustomAllocatorInterface_AllocClear)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "s\0allocLocation\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CustomAllocatorInterface::MTable::_instance._CustomAllocatorInterface_Realloc)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "data\0size\0allocLocation\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CustomAllocatorInterface::MTable::_instance._CustomAllocatorInterface_PrivateAlloc)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "size\0clear\0allocLocation\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CustomAllocatorInterface::MTable::_instance._CustomAllocatorInterface_PrivateFree)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "data\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CustomAllocatorInterface::MTable::_instance._CustomAllocatorInterface_PrivateGetDataSize)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "data\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CustomAllocatorInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_CustomAllocatorInterface("net.maxon.interface.customallocator", nullptr, &RegisterReflection_CustomAllocatorInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
