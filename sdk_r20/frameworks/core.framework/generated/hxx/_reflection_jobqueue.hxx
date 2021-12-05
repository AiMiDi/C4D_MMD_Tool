#if 1
namespace maxon
{
/// @cond IGNORE

/// @endcond

#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_JobQueueInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JobQueueInterface::MTable::_instance._JobQueueInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JobQueueInterface::MTable::_instance._JobQueueInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 2389LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JobQueueInterface::MTable::_instance._JobQueueInterface_GetThreadCount)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JobQueueInterface::MTable::_instance._JobQueueInterface_GetThreadCount_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JobQueueInterface::MTable::_instance._JobQueueInterface_Cancel)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JobQueueInterface::MTable::_instance._JobQueueInterface_CancelAndWait)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JobQueueInterface::MTable::_instance._JobQueueInterface_GetDestinationQueue)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JobQueueInterface::MTable::_instance._JobQueueInterface_SetDestinationQueue)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JobQueueInterface::MTable::_instance._JobQueueInterface_GetMainThreadQueue)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JobQueueInterface::MTable::_instance._JobQueueInterface_GetServiceIOQueue)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
/// @cond IGNORE

			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(JobQueueInterface::MTable::_instance._JobQueueInterface_ExecuteJobs)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, 4LL, nullptr),
/// @endcond

		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&JobQueueInterface::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_JobQueueInterface("net.maxon.interface.jobqueue", nullptr, &RegisterReflection_JobQueueInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
