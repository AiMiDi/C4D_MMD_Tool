#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_WeakRefServices(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(WeakRefServices::MTable::_instance._WeakRefServices_HasWeakReferences)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(WeakRefServices::MTable::_instance._WeakRefServices_AddWeakReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(WeakRefServices::MTable::_instance._WeakRefServices_RemoveWeakReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(WeakRefServices::MTable::_instance._WeakRefServices_MoveWeakReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(WeakRefServices::MTable::_instance._WeakRefServices_CopyWeakReference)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(WeakRefServices::MTable::_instance._WeakRefServices_ClearAllWeakReferences)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(WeakRefServices::MTable::_instance._WeakRefServices_TransferAllWeakReferences)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(WeakRefServices::MTable::_instance._WeakRefServices_AddObserver)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(WeakRefServices::MTable::_instance._WeakRefServices_AddMetadata)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(WeakRefServices::MTable::_instance._WeakRefServices_EraseMetadata)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(WeakRefServices::MTable::_instance._WeakRefServices_GetMetadata)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&WeakRefServices::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_WeakRefServices("net.maxon.interface.weakrefservices", nullptr, &RegisterReflection_WeakRefServices, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
