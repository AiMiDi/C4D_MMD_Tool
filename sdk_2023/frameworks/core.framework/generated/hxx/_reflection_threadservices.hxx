#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_JobErrorInterface(JobErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION,"maxon::JobError");
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	class JobErrorInterface::ProxyComponent : public maxon::Component<ProxyComponent, JobErrorInterface>
	{
		MAXON_COMPONENT();
	public:
		using typename maxon::Component<ProxyComponent, JobErrorInterface>::_Wrapper;
		static const maxon::Bool PROXY = true;
		maxon::reflection::ProxyHandler _handler;
	};
	PRIVATE_MAXON_COMPONENT_REGISTER(JobErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, &maxon::g_translationUnit, ::MaxonRegistry, maxon::LiteralId());
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION)
	static maxon::Result<void> RegisterReflection_JobErrorInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&JobErrorInterface::_interface), maxon::Block<maxon::reflection::FunctionInfo>());
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION
	static maxon::reflection::ContainerInfo g_reflection_JobErrorInterface(nullptr, &JobErrorInterface::ProxyComponent::_descriptor, &RegisterReflection_JobErrorInterface, &PRIVATE_MAXON_MODULE);
#endif
/// @cond INTERNAL

#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ThreadServices(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_Start)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0priority\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_Enqueue)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0queue\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_Wait)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0timeout\0mode\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_GetResult)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0timeout\0mode\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_Reset)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_Cancel)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_AddFinishedObserver)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0observerPod\0observerQueue\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_AddCancelledObserver)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0observerPod\0observerQueue\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_RemoveCancelledObserver)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0observerPod\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_IsRunning)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_IsCancelled)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_AddJobReference)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_RemoveJobReference)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_CreateStrongJobReference)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_AddWeakJobReference)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0weakRef\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_GetGroup)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_GetCurrentJob)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_GetCurrentThread)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_GetCurrentThreadType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_GetCurrentThreadType_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "threadIdentifier\0", 2LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_GetCpuCount)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_GetStackEnd)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_CreateGroup)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "cnt\0jobSize\0flags\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_CreateGroupForQueue)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "queue\0cnt\0jobSize\0flags\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_AddGroupReference)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_RemoveGroupReference)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_WaitGroup)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0timeout\0mode\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_GroupGetResult)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0timeout\0mode\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_AddJob)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0pod\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_AddGroup)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0subGroup\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_EnqueueGroup)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0queue\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_EnqueueGroupAndWait)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0queue\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_GetStaticJobBuffer)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0capacity\0", 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_GroupBatchAdd)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0first\0memory\0cnt\0size\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_AddGroupFinishedObserver)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0observerPod\0observerQueue\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_GroupCancel)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_GroupMarkAsFinished)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_GetCurrentWorkerThreadIndex)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_IsCurrentJobCancelled)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_AssimilateAlienThread)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_ThreadedExclusiveResource)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "selector\0resourcePtr\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_AddJobStatusReference)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_RemoveJobStatusReference)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ThreadServices::MTable::_instance.ThreadServices_DisconnectPredecessor)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0prev\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ThreadServices::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ThreadServices("net.maxon.interface.threadservices", nullptr, &RegisterReflection_ThreadServices, &PRIVATE_MAXON_MODULE);
#endif
/// @endcond

}
#endif
