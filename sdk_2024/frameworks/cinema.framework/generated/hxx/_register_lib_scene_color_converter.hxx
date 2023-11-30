#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum46
{
	enum class CONVERSION_FLAGS
		{
			NONE			= 0,			// No flags.
			ADD_UNDO	= 1 << 0, // Create an undo step for all changes. This must not be set when the conversion is called from a thread.
		} ;
	static const maxon::UInt64 CONVERSION_FLAGS_values[] = {maxon::UInt64(enum46::CONVERSION_FLAGS::NONE), maxon::UInt64(enum46::CONVERSION_FLAGS::ADD_UNDO)};
	static const maxon::EnumInfo CONVERSION_FLAGS_info{"SceneColorConverter::CONVERSION_FLAGS", SIZEOF(CONVERSION_FLAGS), true, "NONE\0ADD_UNDO\0", CONVERSION_FLAGS_values, std::extent<decltype(CONVERSION_FLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_CONVERSION_FLAGS46(void*){ return enum46::CONVERSION_FLAGS_info; }
/// @cond IGNORE

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
/// @endcond

#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
