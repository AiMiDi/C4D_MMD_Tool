#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_IoMemoryInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(IoMemoryInterface::MTable::_instance._IoMemoryInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(IoMemoryInterface::MTable::_instance._IoMemoryInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(IoMemoryInterface::MTable::_instance._IoMemoryInterface_Alloc_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0src\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(IoMemoryInterface::MTable::_instance._IoMemoryInterface_PrepareReadBuffer)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "buffer\0freeBufferCallback\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(IoMemoryInterface::MTable::_instance._IoMemoryInterface_Reset)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "size\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(IoMemoryInterface::MTable::_instance._IoMemoryInterface_operatorIndex)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "idx\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(IoMemoryInterface::MTable::_instance._IoMemoryInterface_GetSize)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(IoMemoryInterface::MTable::_instance._IoMemoryInterface_IsWritable)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(IoMemoryInterface::MTable::_instance._IoMemoryInterface_GetUrl)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(IoMemoryInterface::MTable::_instance._IoMemoryInterface_ReadBytes)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "position\0data\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(IoMemoryInterface::MTable::_instance._IoMemoryInterface_ReadBytesEOS)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "position\0data\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(IoMemoryInterface::MTable::_instance._IoMemoryInterface_WriteBytes)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "position\0data\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(IoMemoryInterface::MTable::_instance._IoMemoryInterface_OpenInputStream)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "flags\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(IoMemoryInterface::MTable::_instance._IoMemoryInterface_OpenOutputStream)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "flags\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(IoMemoryInterface::MTable::_instance._IoMemoryInterface_OpenInOutputStream)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "flags\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&IoMemoryInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_IoMemoryInterface("net.maxon.interface.iomemory", nullptr, &RegisterReflection_IoMemoryInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
