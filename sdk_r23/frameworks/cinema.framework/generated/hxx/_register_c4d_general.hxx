#if 1
#ifdef __API_INTERN__
#else
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum1516 { enum class MACHINEFEATURESTYPE
	{
		CURRENT			 = 0, ///< Get Machine features for the currently active OpenGL type.
		HARDWARE_OGL = 1, ///< Get Machine features for Hardware OpenGL.
	} ; }
maxon::String PrivateToString_MACHINEFEATURESTYPE1516(std::underlying_type<enum1516::MACHINEFEATURESTYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum1516::MACHINEFEATURESTYPE::CURRENT, (maxon::UInt64) enum1516::MACHINEFEATURESTYPE::HARDWARE_OGL};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "MACHINEFEATURESTYPE", SIZEOF(x), false, values, "CURRENT\0HARDWARE_OGL\0", fmt);
}
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
#endif
