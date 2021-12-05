#if 1
namespace enum2804 { enum class DESCIDINFOFLAGS
{
	NONE								= 0,
	INPORT							= 1 << 0,
	INPORT_CONNECTED		= 1 << 1,
	OUTPORT							= 1 << 2,
	OUTPORT_CONNECTED		= 1 << 3
} ; }
maxon::String PrivateToString_DESCIDINFOFLAGS2804(std::underlying_type<enum2804::DESCIDINFOFLAGS>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum2804::DESCIDINFOFLAGS::NONE, (maxon::UInt64) enum2804::DESCIDINFOFLAGS::INPORT, (maxon::UInt64) enum2804::DESCIDINFOFLAGS::INPORT_CONNECTED, (maxon::UInt64) enum2804::DESCIDINFOFLAGS::OUTPORT, (maxon::UInt64) enum2804::DESCIDINFOFLAGS::OUTPORT_CONNECTED};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "DESCIDINFOFLAGS", SIZEOF(x), true, values, "NONE\0INPORT\0INPORT_CONNECTED\0OUTPORT\0OUTPORT_CONNECTED\0", fmt);
}
#endif
