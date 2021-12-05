#if defined(MAXON_TARGET_ANDROID)
#if 1
#ifdef MAXON_TARGET_ANDROID
#endif
namespace maxon
{
#ifdef MAXON_TARGET_ANDROID
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_Java(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_GetMainThreadJavaEnv)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_GetJavaEnv)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_GetJavaVM)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_GetNativeActivityObject)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_GetAssetManager)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_AllcoObject)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0javaClass\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_MakeGlobalRef)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0className\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_DeleteGlobalRef)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0javaClass\0", 13LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_GetFieldID)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0javaClass\0memberName\0signature\0", 69LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_GetLongField)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0obj\0field\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_SetLongField)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0obj\0field\0value\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_ConvertString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0str\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_ConvertString_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0str\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_IntGetStaticObjectField)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0className\0memberName\0signature\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_IntCallStaticMethodObject)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0className\0memberName\0signature\0list\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_IntCallStaticMethodVoid)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0className\0memberName\0signature\0list\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_IntCallStaticMethodLong)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0className\0memberName\0signature\0list\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_IntCallMethodObject)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0object\0className\0memberName\0signature\0list\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_IntCallMethodLong)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0object\0className\0memberName\0signature\0list\0", 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Java::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_Java("net.maxon.interface.java", nullptr, &RegisterReflection_Java, &PRIVATE_MAXON_MODULE);
#endif
#endif
}
#endif
#endif
