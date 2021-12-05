#if 1
namespace maxon
{
/// @cond INTERNAL

#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_LockServices(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LockServices::MTable::_instance._LockServices_Serialize)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "serializer\0jobCallback\0jobParam\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LockServices::MTable::_instance._LockServices_SerializeAsync)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "serializer\0wrapperCallback\0fn\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LockServices::MTable::_instance._LockServices_AllocRWLockSlot)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "arw\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LockServices::MTable::_instance._LockServices_FreeRWLockSlot)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "arw\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LockServices::MTable::_instance._LockServices_ARWReadLock)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "arw\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LockServices::MTable::_instance._LockServices_ARWReadUnlock)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "arw\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LockServices::MTable::_instance._LockServices_ARWWriteLock)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "arw\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LockServices::MTable::_instance._LockServices_ARWWriteUnlock)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "arw\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LockServices::MTable::_instance._LockServices_ARWAttemptWriteLock)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "arw\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&LockServices::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_LockServices("net.maxon.interface.lockservices", nullptr, &RegisterReflection_LockServices, &PRIVATE_MAXON_MODULE);
#endif
/// @endcond

}
#endif
