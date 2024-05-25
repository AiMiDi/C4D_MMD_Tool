#if 1
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum157
{
	enum class INITRENDERFLAG
	{
		NONE							= 0,						///< No flags.
		TEXTURES					= (1 << 0),			///< Use textures.
		PAINTERNOMIP			= (1 << 1),			///< Disable MIP for painting.
		NOMIP							= (1 << 2),			///< Disable MIP.
		PREVIEWRENDER			= (1 << 3),			///< Preview render.\n
																			///< @note	The container of the preview rendered document contains the path to the original document in ID ::DOCUMENT_SECONDARYPATH:
																			/// @code
																			/// if (irs.flags & INITRENDERFLAG::PREVIEWRENDER)
																			/// {
																			/// 	if (irs.doc)
																			/// 	{
																			/// 		const Filename originalPath = irs.doc->GetDataInstanceRef().GetFilename(DOCUMENT_SECONDARYPATH);
																			/// 	}
																			/// }
																			/// @endcode
		IRR								= (1 << 4)			///< Interactive region render.
	} ;
	static const maxon::UInt64 INITRENDERFLAG_values[] = {maxon::UInt64(enum157::INITRENDERFLAG::NONE), maxon::UInt64(enum157::INITRENDERFLAG::TEXTURES), maxon::UInt64(enum157::INITRENDERFLAG::PAINTERNOMIP), maxon::UInt64(enum157::INITRENDERFLAG::NOMIP), maxon::UInt64(enum157::INITRENDERFLAG::PREVIEWRENDER), maxon::UInt64(enum157::INITRENDERFLAG::IRR)};
	static const maxon::EnumInfo INITRENDERFLAG_info{"INITRENDERFLAG", SIZEOF(INITRENDERFLAG), true, "NONE\0TEXTURES\0PAINTERNOMIP\0NOMIP\0PREVIEWRENDER\0IRR\0", INITRENDERFLAG_values, std::extent<decltype(INITRENDERFLAG_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_INITRENDERFLAG157(){ return enum157::INITRENDERFLAG_info; }
#ifdef __API_INTERN__
#else
#endif
#ifdef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
