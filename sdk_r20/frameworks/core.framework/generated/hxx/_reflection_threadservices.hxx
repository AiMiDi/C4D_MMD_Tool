#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_JobErrorInterface(JobErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	class JobErrorInterface::ProxyComponent : public maxon::Component<JobErrorInterface::ProxyComponent, JobErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(JobErrorInterface::ProxyComponent, , maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry,);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::Result<void> RegisterReflection_JobErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&JobErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
	static maxon::reflection::ContainerInfo g_reflection_JobErrorInterface(nullptr, &JobErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_JobErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
/// @cond INTERNAL

#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_ThreadServices(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_Start)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_Enqueue)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_Wait)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetResult)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_Reset)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_Cancel)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AddFinishedObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AddCancelledObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_IsRunning)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_IsCancelled)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AddJobReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_RemoveJobReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_CreateStrongJobReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AddWeakJobReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetGroup)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetCurrentJob)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetCurrentThread)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetCurrentThreadType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetCpuCount)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetStackEnd)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_CreateGroup)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AddGroupReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_RemoveGroupReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_WaitGroup)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GroupGetResult)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AddJob)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AddGroup)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_EnqueueGroup)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_EnqueueGroupAndWait)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetStaticJobBuffer)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GroupBatchAdd)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AddGroupFinishedObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GroupCancel)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GroupMarkAsFinished)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetCurrentWorkerThreadIndex)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_IsCurrentJobCancelled)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_CreateBarrier)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_EnqueueBarrier)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AssimilateAlienThread)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_ThreadedExclusiveResource)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_ThreadProfiling)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ThreadServices::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_ThreadServices("net.maxon.interface.threadservices", nullptr, &RegisterReflection_ThreadServices, &PRIVATE_MAXON_MODULE);
#endif
/// @endcond

}
#endif
