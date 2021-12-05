#if 1
#ifdef __API_INTERN__
#else
/// @cond IGNORE

/// @endcond

namespace enum1534 { enum class MACHINEFEATURESTYPE
	{
		CURRENT			 = 0, ///< Get Machine features for the currently active OpenGL type.
		HARDWARE_OGL = 1, ///< Get Machine features for Hardware OpenGL.
		SOFTWARE_OGL = 2  ///< Get Machine features for Software OpenGL.
	} ; }
maxon::String PrivateToString_MACHINEFEATURESTYPE1534(std::underlying_type<enum1534::MACHINEFEATURESTYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum1534::MACHINEFEATURESTYPE::CURRENT, (maxon::UInt64) enum1534::MACHINEFEATURESTYPE::HARDWARE_OGL, (maxon::UInt64) enum1534::MACHINEFEATURESTYPE::SOFTWARE_OGL};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "MACHINEFEATURESTYPE", SIZEOF(x), false, values, "CURRENT\0HARDWARE_OGL\0SOFTWARE_OGL\0", fmt);
}
#endif
#endif
