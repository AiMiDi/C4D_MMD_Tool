#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_DataDictionaryIteratorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryIteratorInterface::MTable::_instance._DataDictionaryIteratorInterface_Destruct)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryIteratorInterface::MTable::_instance._DataDictionaryIteratorInterface_MoveConstruct)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "src\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryIteratorInterface::MTable::_instance._DataDictionaryIteratorInterface_HasValue)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryIteratorInterface::MTable::_instance._DataDictionaryIteratorInterface_IsEqual)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "other\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryIteratorInterface::MTable::_instance._DataDictionaryIteratorInterface_MoveToNext)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(DataDictionaryIteratorInterface::MTable::_instance._DataDictionaryIteratorInterface_GetKeyAndData)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "res\0", 2LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&DataDictionaryIteratorInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_DataDictionaryIteratorInterface("net.maxon.interface.datadictionaryiterator", nullptr, &RegisterReflection_DataDictionaryIteratorInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
