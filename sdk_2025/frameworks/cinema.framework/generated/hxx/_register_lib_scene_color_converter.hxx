#if 1
#ifdef __API_INTERN__
#else
#endif
namespace cinema
{
	namespace enum53
	{
		enum class CONVERSION_FLAGS
			{
				NONE			= 0,			// No flags.
				ADD_UNDO	= 1 << 0, // Create an undo step for all changes. This must not be set when the conversion is called from a thread.
				CLASSIC_LINEAR_TO_SRGB = 1 << 1, // The Scene is a classic scene and would have converted Linear to sRGB on color values.
				CLASSIC_SRGB_TO_LINEAR = 1 << 2, // The Scene is a classic scene and would have converted sRGB to Linear on color values.
				FORCE_LINEAR_LIGHTS = 1 << 3, // Forces the conversion from classic or to classic color management to interpret lights to have linear brightness. Otherwise lights will adjust their brightness.
			} ;
		static const maxon::UInt64 CONVERSION_FLAGS_values[] = {maxon::UInt64(enum53::CONVERSION_FLAGS::NONE), maxon::UInt64(enum53::CONVERSION_FLAGS::ADD_UNDO), maxon::UInt64(enum53::CONVERSION_FLAGS::CLASSIC_LINEAR_TO_SRGB), maxon::UInt64(enum53::CONVERSION_FLAGS::CLASSIC_SRGB_TO_LINEAR), maxon::UInt64(enum53::CONVERSION_FLAGS::FORCE_LINEAR_LIGHTS)};
		static const maxon::EnumInfo CONVERSION_FLAGS_info{"SceneColorConverter::CONVERSION_FLAGS", SIZEOF(CONVERSION_FLAGS), true, "NONE\0ADD_UNDO\0CLASSIC_LINEAR_TO_SRGB\0CLASSIC_SRGB_TO_LINEAR\0FORCE_LINEAR_LIGHTS\0", CONVERSION_FLAGS_values, std::extent<decltype(CONVERSION_FLAGS_values)>::value};
	}
	const maxon::EnumInfo& PrivateGetEnumInfo_CONVERSION_FLAGS53(void*){ return enum53::CONVERSION_FLAGS_info; }
/// @cond IGNORE

/// @endcond

}
#endif
