#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum67 { enum class BITMAPLOADERACTION
{
	INIT = 1,					///< Initialize.
	LOAD = 2,					///< Load.
	FREE = 3,					///< Free.
	INITLAYERSET = 4,	///< Initialize with a layerset. This call is optional but must be called before @ref BITMAPLOADERACTION::INIT. The BaseBitmap pointer must point to  a <tt>const LayerSet*</tt>. @since R19
} ; }
maxon::String PrivateToString_BITMAPLOADERACTION67(std::underlying_type<enum67::BITMAPLOADERACTION>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum67::BITMAPLOADERACTION::INIT, (maxon::UInt64) enum67::BITMAPLOADERACTION::LOAD, (maxon::UInt64) enum67::BITMAPLOADERACTION::FREE, (maxon::UInt64) enum67::BITMAPLOADERACTION::INITLAYERSET};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "BITMAPLOADERACTION", SIZEOF(x), false, values, "INIT\0LOAD\0FREE\0INITLAYERSET\0", fmt);
}
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
