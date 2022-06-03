#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum90
{
	enum class AMFILTERFLAGS
	{
		NONE = 0,											 ///< None.
		SHOWHIDDEN = 1 << 0,					 ///< Show hidden parameters.
		SHOWANIMONLY = 1 << 1,				 ///< Show animated parameters.
		SHOWLOCKED = 1 << 2,					 ///< Show locked parameters.
		HIDEINLINEATTRIBUTES = 1 << 3, ///< Hide attributes if marked with DESC_HIDE_WHEN_INLINE.
		SHOWKEYFRAMESEL = 1 << 4, ///< Hide attributes if they are not in keyframe selection.
		SHOWANIMATED = 1 << 5, ///< Hide attributes if they are not animated.
		SHOWDRIVERDRIVENXPRESSO = 1<<6, ///< Hide attributes if they are an expresso driver or driven.
		SHOWOVERRIDEN = 1<<7, ///< Hide attributes if they are overriden.
	} ;
	static const maxon::UInt64 AMFILTERFLAGS_values[] = {maxon::UInt64(enum90::AMFILTERFLAGS::NONE), maxon::UInt64(enum90::AMFILTERFLAGS::SHOWHIDDEN), maxon::UInt64(enum90::AMFILTERFLAGS::SHOWANIMONLY), maxon::UInt64(enum90::AMFILTERFLAGS::SHOWLOCKED), maxon::UInt64(enum90::AMFILTERFLAGS::HIDEINLINEATTRIBUTES), maxon::UInt64(enum90::AMFILTERFLAGS::SHOWKEYFRAMESEL), maxon::UInt64(enum90::AMFILTERFLAGS::SHOWANIMATED), maxon::UInt64(enum90::AMFILTERFLAGS::SHOWDRIVERDRIVENXPRESSO), maxon::UInt64(enum90::AMFILTERFLAGS::SHOWOVERRIDEN)};
	static const maxon::EnumInfo AMFILTERFLAGS_info{"AMFILTERFLAGS", SIZEOF(AMFILTERFLAGS), true, "NONE\0SHOWHIDDEN\0SHOWANIMONLY\0SHOWLOCKED\0HIDEINLINEATTRIBUTES\0SHOWKEYFRAMESEL\0SHOWANIMATED\0SHOWDRIVERDRIVENXPRESSO\0SHOWOVERRIDEN\0", AMFILTERFLAGS_values, std::extent<decltype(AMFILTERFLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_AMFILTERFLAGS90(){ return enum90::AMFILTERFLAGS_info; }
#ifndef _INTERNAL_DEF_CUSTOMGUI_DESCRIPTION
#endif
/// @cond IGNORE

#if !defined _INTERNAL_DEF_ && !defined __API_INTERN__
#else
#endif
/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
