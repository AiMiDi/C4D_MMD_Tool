#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ConditionVariableInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(ConditionVariableInterface::MTable::_instance.ConditionVariableInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ConditionVariableInterface::MTable::_instance.ConditionVariableInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ConditionVariableInterface::MTable::_instance.ConditionVariableInterface_Alloc_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0isAutoClear\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ConditionVariableInterface::MTable::_instance.ConditionVariableInterface_Clear)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "dependencyCnt\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ConditionVariableInterface::MTable::_instance.ConditionVariableInterface_AddDependency)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ConditionVariableInterface::MTable::_instance.ConditionVariableInterface_Set)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ConditionVariableInterface::MTable::_instance.ConditionVariableInterface_Wait)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "timeout\0mode\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ConditionVariableInterface::MTable::_instance.ConditionVariableInterface_PrivateAddFinishedObserver)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "observerPod\0observerQueue\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ConditionVariableInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ConditionVariableInterface("net.maxon.interface.conditionvariable", nullptr, &RegisterReflection_ConditionVariableInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
