#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_UnicodeUtils(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_DecomposeStringHfs)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_DecomposeString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_GetUnicodeVersion)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_NormalizeString)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "form\0str\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_UniCharDecomposition)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "chr\0res_decomp\0", 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_UniCharHfsDecomposition)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "chr\0res_decomp\0", 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_UniCodeCompare)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0b\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_UpperCase)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "chr\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_TitleCase)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "chr\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<std::remove_pointer<decltype(UnicodeUtils::MTable::_instance._UnicodeUtils_LowerCase)>::type>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "chr\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UnicodeUtils::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_UnicodeUtils("net.maxon.interface.unicodeutils", nullptr, &RegisterReflection_UnicodeUtils, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
