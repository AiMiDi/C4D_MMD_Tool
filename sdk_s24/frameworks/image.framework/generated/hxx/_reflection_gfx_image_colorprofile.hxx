#if 1
#ifdef MAXON_TARGET_LINUX
#endif
namespace maxon
{
/// @cond INTERNAL

/// @endcond

#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ColorProfileInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_Alloc)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_Alloc_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_IsEqual)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "other\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_OpenProfileFromFile)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "fn\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_OpenProfileFromMemory)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "mem\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_WriteProfileToMemory)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "mem\0", 2LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_WriteProfileToFile)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "fn\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_GetInfo)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "info\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_GetCrc)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_HasProfile)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_CheckCompatiblePixelFormat)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "pixelFormat\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_IsMonitorProfileMode)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_GetHashCode)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_GetColorSpace)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_ToString)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "formatStatement\0", 1LL, nullptr),
/// @cond INTERNAL

			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_SetMonitorProfileMode)>::type>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "on\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileInterface::MTable::_instance._ColorProfileInterface_DescribeIO)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "stream\0", 1LL, nullptr),
/// @endcond

		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ColorProfileInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ColorProfileInterface("net.maxon.image.interface.colorprofile", nullptr, &RegisterReflection_ColorProfileInterface, &PRIVATE_MAXON_MODULE);
#endif
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_ColorProfileConvertInterface(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileConvertInterface::MTable::_instance._ColorProfileConvertInterface_Free)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileConvertInterface::MTable::_instance._ColorProfileConvertInterface_Init)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "srcPixelFormat\0srcProfile\0dstPixelFormat\0dstProfile\0intent\0flags\0", 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileConvertInterface::MTable::_instance._ColorProfileConvertInterface_Convert)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "src\0dst\0cnt\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileConvertInterface::MTable::_instance._ColorProfileConvertInterface_GetHashCode)>::type>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(ColorProfileConvertInterface::MTable::_instance._ColorProfileConvertInterface_GetNearestNativeFormat)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "format\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&ColorProfileConvertInterface::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_ColorProfileConvertInterface("net.maxon.image.interface.colorprofileconvert", nullptr, &RegisterReflection_ColorProfileConvertInterface, &PRIVATE_MAXON_MODULE);
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_INTERFACES
	PRIVATE_MAXON_REGISTRY_DEFINE(ColorProfiles);
#endif
}
#endif
