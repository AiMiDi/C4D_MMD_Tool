#if 1
namespace maxon
{
/// @cond INTERNAL

#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_LockServices(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(LockServices::MTable::_instance.LockServices_Serialize)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "serializer\0jobCallback\0jobParam\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LockServices::MTable::_instance.LockServices_SerializeAsync)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "serializer\0wrapperCallback\0fn\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LockServices::MTable::_instance.LockServices_AllocRWLockSlot)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "arw\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LockServices::MTable::_instance.LockServices_FreeRWLockSlot)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "arw\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LockServices::MTable::_instance.LockServices_ARWReadLock)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "arw\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LockServices::MTable::_instance.LockServices_ARWReadUnlock)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "arw\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LockServices::MTable::_instance.LockServices_ARWWriteLock)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "arw\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LockServices::MTable::_instance.LockServices_ARWWriteUnlock)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "arw\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(LockServices::MTable::_instance.LockServices_ARWAttemptWriteLock)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "arw\0", 0LL, nullptr),
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
