#if 1
namespace maxon
{
#if defined(PRIVATE_MAXON_REGISTRATION_FRAMEWORK) && !defined(MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL)
	static maxon::Result<void> RegisterReflection_UnicodeUtils(maxon::reflection::Class* cls, maxon::reflection::FunctionRegistrationCallback callback)
	{
		maxon::reflection::FunctionInfo functions[] =
		{
			maxon::reflection::GetFunctionInfo<decltype(UnicodeUtils::MTable::_instance.UnicodeUtils_DecomposeStringHfs)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UnicodeUtils::MTable::_instance.UnicodeUtils_DecomposeString)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "str\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UnicodeUtils::MTable::_instance.UnicodeUtils_GetUnicodeVersion)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UnicodeUtils::MTable::_instance.UnicodeUtils_NormalizeString)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "form\0str\0", 0LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UnicodeUtils::MTable::_instance.UnicodeUtils_UniCharDecomposition)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "chr\0res_decomp\0", 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UnicodeUtils::MTable::_instance.UnicodeUtils_UniCharHfsDecomposition)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "chr\0res_decomp\0", 9LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UnicodeUtils::MTable::_instance.UnicodeUtils_UniCodeCompare)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "a\0b\0", 5LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UnicodeUtils::MTable::_instance.UnicodeUtils_GetCharacterType)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "chr\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UnicodeUtils::MTable::_instance.UnicodeUtils_UpperCase)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "chr\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UnicodeUtils::MTable::_instance.UnicodeUtils_TitleCase)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "chr\0", 1LL, nullptr),
			maxon::reflection::GetFunctionInfo<decltype(UnicodeUtils::MTable::_instance.UnicodeUtils_LowerCase)>(nullptr, maxon::reflection::Member::KIND::FUNCTION, "chr\0", 1LL, nullptr),
		};
		return callback(cls, reinterpret_cast<const maxon::EntityReference*>(&UnicodeUtils::_interface), maxon::ToBlock(functions));
	}
#endif
#ifndef MAXON_REGISTRATION_EXCLUDE_REFLECTION_NONVIRTUAL
	static maxon::reflection::ContainerInfo g_reflection_UnicodeUtils("net.maxon.interface.unicodeutils", nullptr, &RegisterReflection_UnicodeUtils, &PRIVATE_MAXON_MODULE);
#endif
}
#endif
