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
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_GetMainThreadJavaEnv)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_GetJavaEnv)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_GetJavaVM)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_GetNativeActivityObject)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_GetAssetManager)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_AllcoObject)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0javaClass\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_MakeGlobalRef)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0className\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_DeleteGlobalRef)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0javaClass\0", 13LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_GetFieldID)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0javaClass\0memberName\0signature\0", 69LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_GetLongField)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0obj\0field\0", 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_SetLongField)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0obj\0field\0value\0", 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_ConvertString)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0str\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_ConvertString_1)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0str\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_IntGetStaticObjectField)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0className\0memberName\0signature\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_IntCallStaticMethodObject)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0className\0memberName\0signature\0list\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_IntCallStaticMethodVoid)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0className\0memberName\0signature\0list\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_IntCallStaticMethodLong)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0className\0memberName\0signature\0list\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_IntCallMethodObject)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0object\0className\0memberName\0signature\0list\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(Java::MTable::_instance.Java_IntCallMethodLong)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "env\0object\0className\0memberName\0signature\0list\0", 0LL, nullptr),
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
