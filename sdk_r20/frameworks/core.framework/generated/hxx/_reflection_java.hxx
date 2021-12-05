#if defined(MAXON_TARGET_ANDROID)
#if 1
#ifdef MAXON_TARGET_ANDROID
#endif
namespace maxon
{
#ifdef MAXON_TARGET_ANDROID
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_Java(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_GetMainThreadJavaEnv)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_GetJavaEnv)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_GetJavaVM)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_GetNativeActivityObject)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_GetAssetManager)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_AllcoObject)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_MakeGlobalRef)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_DeleteGlobalRef)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 13LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_GetFieldID)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 69LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_GetLongField)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 21LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_SetLongField)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 85LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_ConvertString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_ConvertString_1)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_IntGetStaticObjectField)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_IntCallStaticMethodObject)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_IntCallStaticMethodVoid)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_IntCallStaticMethodLong)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_IntCallMethodObject)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(Java::MTable::_instance._Java_IntCallMethodLong)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&Java::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_Java("net.maxon.interface.java", nullptr, &RegisterReflection_Java, &PRIVATE_MAXON_MODULE);
#endif
#endif
}
#endif
#endif
