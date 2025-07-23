#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_IoMemoryInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(IoMemoryInterface::MTable::_instance.IoMemoryInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(IoMemoryInterface::MTable::_instance.IoMemoryInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(IoMemoryInterface::MTable::_instance.IoMemoryInterface_Alloc_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0src\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(IoMemoryInterface::MTable::_instance.IoMemoryInterface_PrepareReadBuffer)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "buffer\0freeBufferCallback\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(IoMemoryInterface::MTable::_instance.IoMemoryInterface_Reset)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "size\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(IoMemoryInterface::MTable::_instance.IoMemoryInterface_operatorIndex)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "idx\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(IoMemoryInterface::MTable::_instance.IoMemoryInterface_GetSize)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(IoMemoryInterface::MTable::_instance.IoMemoryInterface_IsWritable)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(IoMemoryInterface::MTable::_instance.IoMemoryInterface_GetUrl)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(IoMemoryInterface::MTable::_instance.IoMemoryInterface_ReadBytes)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "position\0data\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(IoMemoryInterface::MTable::_instance.IoMemoryInterface_ReadBytesEOS)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "position\0data\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(IoMemoryInterface::MTable::_instance.IoMemoryInterface_WriteBytes)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "position\0data\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(IoMemoryInterface::MTable::_instance.IoMemoryInterface_OpenInputStream)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "flags\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(IoMemoryInterface::MTable::_instance.IoMemoryInterface_OpenOutputStream)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "flags\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(IoMemoryInterface::MTable::_instance.IoMemoryInterface_OpenInOutputStream)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "flags\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&IoMemoryInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_IoMemoryInterface("net.maxon.interface.iomemory", nullptr, &RegisterReflection_IoMemoryInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
