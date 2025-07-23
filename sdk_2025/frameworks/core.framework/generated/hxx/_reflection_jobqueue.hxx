#if 1
namespace maxon
{
/// @cond IGNORE

/// @endcond

#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_JobQueueInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(JobQueueInterface::MTable::_instance.JobQueueInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(JobQueueInterface::MTable::_instance.JobQueueInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0type\0threadCnt\0mode\0name\0ownerId\0", 2389LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(JobQueueInterface::MTable::_instance.JobQueueInterface_GetThreadCount)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(JobQueueInterface::MTable::_instance.JobQueueInterface_GetThreadCount_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "queue\0maxWaitSessionLevel\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(JobQueueInterface::MTable::_instance.JobQueueInterface_Cancel)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "ownerId\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(JobQueueInterface::MTable::_instance.JobQueueInterface_CancelAndWait)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "ownerId\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(JobQueueInterface::MTable::_instance.JobQueueInterface_EnableThreadAffinity)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "ownerId\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(JobQueueInterface::MTable::_instance.JobQueueInterface_AlwaysUseCurrentThread)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "ownerId\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(JobQueueInterface::MTable::_instance.JobQueueInterface_SetIdleSpinTime)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "ownerId\0spinTime\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(JobQueueInterface::MTable::_instance.JobQueueInterface_GetDestinationQueue)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(JobQueueInterface::MTable::_instance.JobQueueInterface_SetDestinationQueue)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "queue\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(JobQueueInterface::MTable::_instance.JobQueueInterface_GetMainThreadQueue)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(JobQueueInterface::MTable::_instance.JobQueueInterface_GetServiceIOQueue)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
/// @cond IGNORE

			maxon::reflection::GetFunctionInfo<decltype(JobQueueInterface::MTable::_instance.JobQueueInterface_ExecuteJobs)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "timeout\0", 1LL, nullptr),
/// @endcond

		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&JobQueueInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_JobQueueInterface("net.maxon.interface.jobqueue", nullptr, &RegisterReflection_JobQueueInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
