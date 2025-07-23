#if 1
namespace cinema
{
	namespace enum66
	{
		enum class BITMAPLOADERACTION
		{
			INIT = 1,					///< Initialize.
			LOAD = 2,					///< Load.
			FREE = 3,					///< Free.
			INITLAYERSET = 4,	///< Initialize with a layerset. This call is optional but must be called before @ref BITMAPLOADERACTION::INIT. The BaseBitmap pointer must point to  a <tt>const LayerSet*</tt>. @since R19
		} ;
		static const maxon::UInt64 BITMAPLOADERACTION_values[] = {maxon::UInt64(enum66::BITMAPLOADERACTION::INIT), maxon::UInt64(enum66::BITMAPLOADERACTION::LOAD), maxon::UInt64(enum66::BITMAPLOADERACTION::FREE), maxon::UInt64(enum66::BITMAPLOADERACTION::INITLAYERSET)};
		static const maxon::EnumInfo BITMAPLOADERACTION_info{"BITMAPLOADERACTION", SIZEOF(BITMAPLOADERACTION), false, "INIT\0LOAD\0FREE\0INITLAYERSET\0", BITMAPLOADERACTION_values, std::extent<decltype(BITMAPLOADERACTION_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_BITMAPLOADERACTION66(){ return enum66::BITMAPLOADERACTION_info; }
}
#endif
