#if 1
namespace maxon
{
	namespace reflection
	{
		namespace enum23
		{
			enum class FLAGS
				{
					NONE = 0,
					INPUT = 1,
					OUTPUT = 2,
					EXPLICIT_INPUT_OUTPUT = 4
				} ;
			static const maxon::UInt64 FLAGS_values[] = {maxon::UInt64(enum23::FLAGS::NONE), maxon::UInt64(enum23::FLAGS::INPUT), maxon::UInt64(enum23::FLAGS::OUTPUT), maxon::UInt64(enum23::FLAGS::EXPLICIT_INPUT_OUTPUT)};
			static const maxon::EnumInfo FLAGS_info{"ParameterType::FLAGS", SIZEOF(FLAGS), true, "NONE\0INPUT\0OUTPUT\0EXPLICIT_INPUT_OUTPUT\0", FLAGS_values, std::extent<decltype(FLAGS_values)>::value};
		}
		const maxon::EnumInfo& PrivateGetEnumInfo_FLAGS23(void*){ return enum23::FLAGS_info; }
	}
}
#endif
