#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ConditionVariableInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ConditionVariableInterface::MTable::_instance._ConditionVariableInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ConditionVariableInterface::MTable::_instance._ConditionVariableInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ConditionVariableInterface::MTable::_instance._ConditionVariableInterface_Alloc_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0isAutoClear\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ConditionVariableInterface::MTable::_instance._ConditionVariableInterface_Clear)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "dependencyCnt\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ConditionVariableInterface::MTable::_instance._ConditionVariableInterface_AddDependency)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ConditionVariableInterface::MTable::_instance._ConditionVariableInterface_Set)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ConditionVariableInterface::MTable::_instance._ConditionVariableInterface_Wait)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "timeout\0mode\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ConditionVariableInterface::MTable::_instance._ConditionVariableInterface_PrivateAddFinishedObserver)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "observerPod\0observerQueue\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ConditionVariableInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ConditionVariableInterface("net.maxon.interface.conditionvariable", nullptr, &RegisterReflection_ConditionVariableInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
