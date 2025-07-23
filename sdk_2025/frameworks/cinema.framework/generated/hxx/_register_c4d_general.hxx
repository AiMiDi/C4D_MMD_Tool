#if 1
#ifdef __API_INTERN__
#else
namespace cinema
{
	namespace enum1588
	{
		enum class MACHINEFEATURESTYPE
		{
			CURRENT			 = 0, ///< Get Machine features for the currently active OpenGL type.
			HARDWARE_OGL = 1, ///< Get Machine features for Hardware OpenGL.
		} ;
		static const maxon::UInt64 MACHINEFEATURESTYPE_values[] = {maxon::UInt64(enum1588::MACHINEFEATURESTYPE::CURRENT), maxon::UInt64(enum1588::MACHINEFEATURESTYPE::HARDWARE_OGL)};
		static const maxon::EnumInfo MACHINEFEATURESTYPE_info{"MACHINEFEATURESTYPE", SIZEOF(MACHINEFEATURESTYPE), false, "CURRENT\0HARDWARE_OGL\0", MACHINEFEATURESTYPE_values, std::extent<decltype(MACHINEFEATURESTYPE_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_MACHINEFEATURESTYPE1588(){ return enum1588::MACHINEFEATURESTYPE_info; }
}
#endif
#endif
