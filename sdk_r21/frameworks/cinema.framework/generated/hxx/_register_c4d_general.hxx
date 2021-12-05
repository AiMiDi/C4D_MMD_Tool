#if 1
#ifdef __API_INTERN__
#else
/// @cond IGNORE

/// @endcond

namespace enum1544 { enum class MACHINEFEATURESTYPE
	{
		CURRENT			 = 0, ///< Get Machine features for the currently active OpenGL type.
		HARDWARE_OGL = 1, ///< Get Machine features for Hardware OpenGL.
	} ; }
maxon::String PrivateToString_MACHINEFEATURESTYPE1544(std::underlying_type<enum1544::MACHINEFEATURESTYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum1544::MACHINEFEATURESTYPE::CURRENT, (maxon::UInt64) enum1544::MACHINEFEATURESTYPE::HARDWARE_OGL};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "MACHINEFEATURESTYPE", SIZEOF(x), false, values, "CURRENT\0HARDWARE_OGL\0", fmt);
}
#endif
#endif
