#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_WeakRefServices(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(WeakRefServices::MTable::_instance.WeakRefServices_HasWeakReferences)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "target\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(WeakRefServices::MTable::_instance.WeakRefServices_AddWeakReference)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "weakRef\0target\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(WeakRefServices::MTable::_instance.WeakRefServices_RemoveWeakReference)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "weakRef\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(WeakRefServices::MTable::_instance.WeakRefServices_MoveWeakReference)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dst\0src\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(WeakRefServices::MTable::_instance.WeakRefServices_CopyWeakReference)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "dst\0src\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(WeakRefServices::MTable::_instance.WeakRefServices_ClearAllWeakReferences)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "target\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(WeakRefServices::MTable::_instance.WeakRefServices_TransferAllWeakReferences)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "oldTarget\0newTarget\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(WeakRefServices::MTable::_instance.WeakRefServices_AddObserver)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "target\0callback\0callbackData\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(WeakRefServices::MTable::_instance.WeakRefServices_EraseObserver)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "target\0callback\0callbackData\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(WeakRefServices::MTable::_instance.WeakRefServices_AddMetadata)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "target\0uniqueId\0metadata\0destruct\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(WeakRefServices::MTable::_instance.WeakRefServices_EraseMetadata)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "target\0uniqueId\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(WeakRefServices::MTable::_instance.WeakRefServices_GetMetadata)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "target\0uniqueId\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(WeakRefServices::MTable::_instance.WeakRefServices_BrowseAllWeakReferences)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "oldTarget\0receiver\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&WeakRefServices::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_WeakRefServices("net.maxon.interface.weakrefservices", nullptr, &RegisterReflection_WeakRefServices, &PRIVATE_MAXON_MODULE);
#endif
#ifdef WEAKREF_H__
#ifdef MAXON_TARGET_64BIT
#else
#endif
#endif
}
#endif
