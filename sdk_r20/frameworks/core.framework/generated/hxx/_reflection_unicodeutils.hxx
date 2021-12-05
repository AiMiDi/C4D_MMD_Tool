#if 1
namespace maxon
{
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::Result<void> RegisterReflection_UnicodeUtils(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_DecomposeStringHfs)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_DecomposeString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_GetUnicodeVersion)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_NormalizeString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_UniCharDecomposition)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_UniCharHfsDecomposition)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_UniCodeCompare)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_UpperCase)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_TitleCase)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_LowerCase)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UnicodeUtils::_interface), maxon::ToBlock(functions));
	}
	static maxon::reflection::ContainerInfo g_reflection_UnicodeUtils("net.maxon.interface.unicodeutils", nullptr, &RegisterReflection_UnicodeUtils, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
