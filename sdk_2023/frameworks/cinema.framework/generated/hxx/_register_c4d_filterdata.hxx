#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum67
{
	enum class BITMAPLOADERACTION
	{
		INIT = 1,					///< Initialize.
		LOAD = 2,					///< Load.
		FREE = 3,					///< Free.
		INITLAYERSET = 4,	///< Initialize with a layerset. This call is optional but must be called before @ref BITMAPLOADERACTION::INIT. The BaseBitmap pointer must point to  a <tt>const LayerSet*</tt>. @since R19
	} ;
	static const maxon::UInt64 BITMAPLOADERACTION_values[] = {maxon::UInt64(enum67::BITMAPLOADERACTION::INIT), maxon::UInt64(enum67::BITMAPLOADERACTION::LOAD), maxon::UInt64(enum67::BITMAPLOADERACTION::FREE), maxon::UInt64(enum67::BITMAPLOADERACTION::INITLAYERSET)};
	static const maxon::EnumInfo BITMAPLOADERACTION_info{"BITMAPLOADERACTION", SIZEOF(BITMAPLOADERACTION), false, "INIT\0LOAD\0FREE\0INITLAYERSET\0", BITMAPLOADERACTION_values, std::extent<decltype(BITMAPLOADERACTION_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_BITMAPLOADERACTION67(){ return enum67::BITMAPLOADERACTION_info; }
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
