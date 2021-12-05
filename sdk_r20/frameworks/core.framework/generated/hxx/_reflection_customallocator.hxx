#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_CustomAllocatorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CustomAllocatorInterface::MTable::_instance._CustomAllocatorInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CustomAllocatorInterface::MTable::_instance._CustomAllocatorInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CustomAllocatorInterface::MTable::_instance._CustomAllocatorInterface_Alloc_1)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CustomAllocatorInterface::MTable::_instance._CustomAllocatorInterface_AllocClear)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 20LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CustomAllocatorInterface::MTable::_instance._CustomAllocatorInterface_Realloc)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 84LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CustomAllocatorInterface::MTable::_instance._CustomAllocatorInterface_PrivateAlloc)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 84LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CustomAllocatorInterface::MTable::_instance._CustomAllocatorInterface_PrivateFree)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(CustomAllocatorInterface::MTable::_instance._CustomAllocatorInterface_PrivateGetDataSize)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&CustomAllocatorInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_CustomAllocatorInterface("net.maxon.interface.customallocator", nullptr, &RegisterReflection_CustomAllocatorInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
