#if 1
#ifdef __API_INTERN__
#else
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum1516
{
	enum class MACHINEFEATURESTYPE
		{
			CURRENT			 = 0, ///< Get Machine features for the currently active OpenGL type.
			HARDWARE_OGL = 1, ///< Get Machine features for Hardware OpenGL.
		} ;
	static const maxon::UInt64 MACHINEFEATURESTYPE_values[] = {maxon::UInt64(enum1516::MACHINEFEATURESTYPE::CURRENT), maxon::UInt64(enum1516::MACHINEFEATURESTYPE::HARDWARE_OGL)};
	static const maxon::EnumInfo MACHINEFEATURESTYPE_info{"MACHINEFEATURESTYPE", SIZEOF(MACHINEFEATURESTYPE), false, "CURRENT\0HARDWARE_OGL\0", MACHINEFEATURESTYPE_values, std::extent<decltype(MACHINEFEATURESTYPE_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_MACHINEFEATURESTYPE1516(){ return enum1516::MACHINEFEATURESTYPE_info; }
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
#endif
