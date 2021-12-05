#if 1
namespace maxon
{
	namespace reflection
	{
		namespace enum23 { enum class FLAGS
			{
				NONE = 0,
				INPUT = 1,
				OUTPUT = 2,
				EXPLICIT_INPUT_OUTPUT = 4
			} ; }
		maxon::String PrivateToString_FLAGS23(std::underlying_type<enum23::FLAGS>::type x, const maxon::FormatStatement* fmt, void*)
		{
			const maxon::UInt64 values[] = {(maxon::UInt64) enum23::FLAGS::NONE, (maxon::UInt64) enum23::FLAGS::INPUT, (maxon::UInt64) enum23::FLAGS::OUTPUT, (maxon::UInt64) enum23::FLAGS::EXPLICIT_INPUT_OUTPUT};
			return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "ParameterType::FLAGS", SIZEOF(x), true, values, "NONE\0INPUT\0OUTPUT\0EXPLICIT_INPUT_OUTPUT\0", fmt);
		}
	}
}
#endif
