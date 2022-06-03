#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_LayerSetInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LayerSetInterface::MTable::_instance.LayerSetInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LayerSetInterface::MTable::_instance.LayerSetInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LayerSetInterface::MTable::_instance.LayerSetInterface_Alloc_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LayerSetInterface::MTable::_instance.LayerSetInterface_SetSelectedLayers)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "layers\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LayerSetInterface::MTable::_instance.LayerSetInterface_GetSelectedLayers)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LayerSetInterface::MTable::_instance.LayerSetInterface_SetSelectedImage)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "image\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LayerSetInterface::MTable::_instance.LayerSetInterface_GetSelectedImage)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LayerSetInterface::MTable::_instance.LayerSetInterface_SetMode)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "mode\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LayerSetInterface::MTable::_instance.LayerSetInterface_GetMode)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LayerSetInterface::MTable::_instance.LayerSetInterface_SetCalculateAlpha)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "calcAlpha\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LayerSetInterface::MTable::_instance.LayerSetInterface_GetCalculateAlpha)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LayerSetInterface::MTable::_instance.LayerSetInterface_IsEqual)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "other\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LayerSetInterface::MTable::_instance.LayerSetInterface_GetHashCode)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(LayerSetInterface::MTable::_instance.LayerSetInterface_DescribeIO)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "stream\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&LayerSetInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_LayerSetInterface("net.maxon.interface.layerset", nullptr, &RegisterReflection_LayerSetInterface, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
