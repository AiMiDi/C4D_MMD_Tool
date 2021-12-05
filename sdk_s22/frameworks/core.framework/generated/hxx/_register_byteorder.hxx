#if 1
namespace maxon
{
	namespace enum19 { enum class BYTEORDER
	{
		BIG			= 1,	///< Big Endian Format, used on Motorola and IBM Processors (e.g. PowerPC)
		LITTLE	= 2		///< Little Endian Format, used on Intel and ARM Processors
	} ; }
	maxon::String PrivateToString_BYTEORDER19(std::underlying_type<enum19::BYTEORDER>::type x, const maxon::FormatStatement* fmt)
	{
		const maxon::UInt64 values[] = {(maxon::UInt64) enum19::BYTEORDER::BIG, (maxon::UInt64) enum19::BYTEORDER::LITTLE};
		return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "BYTEORDER", SIZEOF(x), false, values, "BIG\0LITTLE\0", fmt);
	}
#if defined(MAXON_TARGET_CPU_PPC) || (defined MAXON_TARGET_MACOS && defined __BIG_ENDIAN__)
#else
#endif
}
#endif
