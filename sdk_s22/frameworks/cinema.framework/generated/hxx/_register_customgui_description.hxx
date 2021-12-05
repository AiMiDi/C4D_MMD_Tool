#if 1
namespace enum85 { enum class AMFILTERFLAGS
{
	NONE = 0,											 ///< None.
	SHOWHIDDEN = 1 << 0,					 ///< Show hidden parameters.
	SHOWANIMONLY = 1 << 1,				 ///< Show animated parameters.
	SHOWLOCKED = 1 << 2,					 ///< Show locked parameters.
	HIDEINLINEATTRIBUTES = 1 << 3, ///< Hide attributes if marked with DESC_HIDE_WHEN_INLINE
} ; }
maxon::String PrivateToString_AMFILTERFLAGS85(std::underlying_type<enum85::AMFILTERFLAGS>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum85::AMFILTERFLAGS::NONE, (maxon::UInt64) enum85::AMFILTERFLAGS::SHOWHIDDEN, (maxon::UInt64) enum85::AMFILTERFLAGS::SHOWANIMONLY, (maxon::UInt64) enum85::AMFILTERFLAGS::SHOWLOCKED, (maxon::UInt64) enum85::AMFILTERFLAGS::HIDEINLINEATTRIBUTES};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "AMFILTERFLAGS", SIZEOF(x), true, values, "NONE\0SHOWHIDDEN\0SHOWANIMONLY\0SHOWLOCKED\0HIDEINLINEATTRIBUTES\0", fmt);
}
#ifndef _INTERNAL_DEF_CUSTOMGUI_DESCRIPTION
#endif
/// @cond IGNORE

#if !defined _INTERNAL_DEF_ && !defined __API_INTERN__
#else
#endif
/// @endcond

#endif
