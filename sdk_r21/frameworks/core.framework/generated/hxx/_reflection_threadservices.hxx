#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	static maxon::InterfaceDefinition s_JobErrorInterface(JobErrorInterface::_interface, &maxon::g_translationUnit, maxon::EntityBase::FLAGS::MAIN_DEFINITION);
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
	PRIVATE_MAXON_COMPONENT_REGISTER(JobErrorInterface::ProxyComponent, , typename, maxon::EntityBase::FLAGS::PROXY, ::MaxonRegistry, maxon::LiteralId());
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
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_Start)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0priority\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_Enqueue)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0queue\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_Wait)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0timeout\0mode\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetResult)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0timeout\0mode\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_Reset)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_Cancel)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AddFinishedObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0observerPod\0observerQueue\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AddCancelledObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0observerPod\0observerQueue\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_RemoveCancelledObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0observerPod\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_IsRunning)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_IsCancelled)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AddJobReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_RemoveJobReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_CreateStrongJobReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AddWeakJobReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0weakRef\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetGroup)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "pod\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetCurrentJob)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetCurrentThread)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetCurrentThreadType)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetCpuCount)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetStackEnd)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_CreateGroup)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "cnt\0jobSize\0flags\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AddGroupReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_RemoveGroupReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_WaitGroup)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0timeout\0mode\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GroupGetResult)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0timeout\0mode\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AddJob)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0pod\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AddGroup)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0subGroup\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_EnqueueGroup)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0queue\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_EnqueueGroupAndWait)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0queue\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetStaticJobBuffer)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0capacity\0", 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GroupBatchAdd)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0first\0memory\0cnt\0size\0", 341LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AddGroupFinishedObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0observerPod\0observerQueue\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GroupCancel)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GroupMarkAsFinished)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "group\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_GetCurrentWorkerThreadIndex)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_IsCurrentJobCancelled)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_AssimilateAlienThread)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ThreadServices::MTable::_instance._ThreadServices_ThreadedExclusiveResource)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "selector\0resourcePtr\0", 5LL, nullptr),
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
