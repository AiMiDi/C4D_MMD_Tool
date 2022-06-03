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
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_Start)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0priority\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_Enqueue)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0queue\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_Wait)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0timeout\0mode\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_GetResult)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0timeout\0mode\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_Reset)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_Cancel)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_AddFinishedObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0observerPod\0observerQueue\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_AddCancelledObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0observerPod\0observerQueue\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_RemoveCancelledObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0observerPod\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_IsRunning)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_IsCancelled)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_AddJobReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_RemoveJobReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_CreateStrongJobReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_AddWeakJobReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0weakRef\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_GetGroup)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_GetCurrentJob)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_GetCurrentThread)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_GetCurrentThreadType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_GetCurrentThreadType_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "threadIdentifier\0", 2LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_GetCpuCount)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_GetStackEnd)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_CreateGroup)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "cnt\0jobSize\0flags\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_AddGroupReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_RemoveGroupReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_WaitGroup)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0timeout\0mode\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_GroupGetResult)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0timeout\0mode\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_AddJob)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0pod\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_AddGroup)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0subGroup\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_EnqueueGroup)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0queue\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_EnqueueGroupAndWait)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0queue\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_GetStaticJobBuffer)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0capacity\0", 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_GroupBatchAdd)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0first\0memory\0cnt\0size\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_AddGroupFinishedObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0observerPod\0observerQueue\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_GroupCancel)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_GroupMarkAsFinished)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_GetCurrentWorkerThreadIndex)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_IsCurrentJobCancelled)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_AssimilateAlienThread)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_ThreadedExclusiveResource)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "selector\0resourcePtr\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_AddJobStatusReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance.ThreadServices_RemoveJobStatusReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
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
