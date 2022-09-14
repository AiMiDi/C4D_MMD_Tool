#if 1
namespace maxon
{
	namespace enum15
	{
		enum class NO_VALUE_TYPE
		{
			VALUE = 1
		} ;
		static const maxon::UInt64 NO_VALUE_TYPE_values[] = {maxon::UInt64(enum15::NO_VALUE_TYPE::VALUE)};
		static const maxon::EnumInfo NO_VALUE_TYPE_info{"NO_VALUE_TYPE", SIZEOF(NO_VALUE_TYPE), false, "VALUE\0", NO_VALUE_TYPE_values, std::extent<decltype(NO_VALUE_TYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_NO_VALUE_TYPE15(){ return enum15::NO_VALUE_TYPE_info; }
#ifdef MAXON_COMPILER_MSVC
#endif
}
#endif
