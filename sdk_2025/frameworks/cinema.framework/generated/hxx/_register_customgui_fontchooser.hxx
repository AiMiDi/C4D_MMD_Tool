#if 1
namespace cinema
{
	namespace enum66
	{
		enum class FONTCHOOSER_POPUP_RESULT
		{
			OK, 		///< User has selected a font.
			CANCEL 	///< User has cancelled popup, either by pressing ESC key or by clicking outside.
		} ;
		static const maxon::UInt64 FONTCHOOSER_POPUP_RESULT_values[] = {maxon::UInt64(enum66::FONTCHOOSER_POPUP_RESULT::OK), maxon::UInt64(enum66::FONTCHOOSER_POPUP_RESULT::CANCEL)};
		static const maxon::EnumInfo FONTCHOOSER_POPUP_RESULT_info{"FONTCHOOSER_POPUP_RESULT", SIZEOF(FONTCHOOSER_POPUP_RESULT), false, "OK\0CANCEL\0", FONTCHOOSER_POPUP_RESULT_values, std::extent<decltype(FONTCHOOSER_POPUP_RESULT_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_FONTCHOOSER_POPUP_RESULT66(){ return enum66::FONTCHOOSER_POPUP_RESULT_info; }
/// @cond IGNORE

#ifndef _FONTCHOOSER_INTERNAL_DEF_
#else
#endif
/// @endcond

}
#endif
