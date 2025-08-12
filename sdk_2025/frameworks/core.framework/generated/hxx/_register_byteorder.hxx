#if 1
namespace maxon
{
	namespace enum19
	{
		enum class BYTEORDER
		{
			BIG			= 1,	///< Big Endian Format, used on Motorola and IBM Processors (e.g. PowerPC)
			LITTLE	= 2		///< Little Endian Format, used on Intel and ARM Processors
		} ;
		static const maxon::UInt64 BYTEORDER_values[] = {maxon::UInt64(enum19::BYTEORDER::BIG), maxon::UInt64(enum19::BYTEORDER::LITTLE)};
		static const maxon::EnumInfo BYTEORDER_info{"BYTEORDER", SIZEOF(BYTEORDER), false, "BIG\0LITTLE\0", BYTEORDER_values, std::extent<decltype(BYTEORDER_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_BYTEORDER19(){ return enum19::BYTEORDER_info; }
#if defined(MAXON_TARGET_CPU_PPC) || (defined MAXON_TARGET_MACOS && defined __BIG_ENDIAN__)
#else
#endif
}
#endif
