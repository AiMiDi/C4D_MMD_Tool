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
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_Alloc)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_Alloc_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "allocLocation\0object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_IsEqual)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "other\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_OpenProfileFromFile)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "fn\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_OpenProfileFromMemory)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "mem\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_CreateProfile)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "config\0name\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_CreateProfile_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "config\0iccPath\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_CreateProfile_2)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "config\0viewTransform\0displayColorSpace\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_CreateProfile_3)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "viewTransform\0displayColorSpace\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_WriteProfileToMemory)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "mem\0", 2LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_WriteProfileToFile)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "fn\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_GetInfo)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "info\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_GetCrc)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_HasProfile)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_CheckCompatiblePixelFormat)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "pixelFormat\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_IsMonitorProfileMode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_GetHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_GetUniqueHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_GetColorSpace)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_ToString)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "formatStatement\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_GetOcioConfig)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "config\0", 2LL, nullptr),
/// @cond INTERNAL

			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_SetMonitorProfileMode)>(nullptr, maxon::reflection::Member::KIND::INSTANCE_FUNCTION, "on\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileInterface::MTable::_instance.ColorProfileInterface_DescribeIO)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "stream\0", 1LL, nullptr),
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
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileConvertInterface::MTable::_instance.ColorProfileConvertInterface_Free)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "object\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileConvertInterface::MTable::_instance.ColorProfileConvertInterface_Init)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "srcPixelFormat\0srcProfile\0dstPixelFormat\0dstProfile\0intent\0flags\0", 1365LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileConvertInterface::MTable::_instance.ColorProfileConvertInterface_Convert)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "src\0dst\0cnt\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileConvertInterface::MTable::_instance.ColorProfileConvertInterface_GetHashCode)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileConvertInterface::MTable::_instance.ColorProfileConvertInterface_GetNearestNativeFormat)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "format\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileConvertInterface::MTable::_instance.ColorProfileConvertInterface_InitGPU)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "srcProfile\0dstProfile\0flags\0optimization\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(ColorProfileConvertInterface::MTable::_instance.ColorProfileConvertInterface_GetGpuHandler)>(nullptr, maxon::reflection::Member::KIND::CONST_INSTANCE_FUNCTION, "", 0LL, nullptr),
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
