#if 1
namespace enum63 { enum class BITMAPLOADERACTION
{
	INIT = 1,					///< Initialize.
	LOAD = 2,					///< Load.
	FREE = 3,					///< Free.
	INITLAYERSET = 4,	///< Initialize with a layerset. This call is optional but must be called before @ref BITMAPLOADERACTION::INIT. The BaseBitmap pointer must point to  a <tt>const LayerSet*</tt>. @since R19
} ; }
maxon::String PrivateToString_BITMAPLOADERACTION63(std::underlying_type<enum63::BITMAPLOADERACTION>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum63::BITMAPLOADERACTION::INIT, (maxon::UInt64) enum63::BITMAPLOADERACTION::LOAD, (maxon::UInt64) enum63::BITMAPLOADERACTION::FREE, (maxon::UInt64) enum63::BITMAPLOADERACTION::INITLAYERSET};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "BITMAPLOADERACTION", SIZEOF(x), false, values, "INIT\0LOAD\0FREE\0INITLAYERSET\0", fmt);
}
#endif
