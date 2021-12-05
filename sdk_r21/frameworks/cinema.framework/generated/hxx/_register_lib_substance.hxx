#if 1
#ifdef __API_INTERN__
#else
#endif
namespace enum255 { enum class SUBSTANCE_MATERIAL_MODE
{
	STANDARD		= 0,		///< Create standard material.
	METALLIC		= 1,		///< Create metallic material.
	GLOSSY			= 2,		///< Create glossy material.
	AUTO				= 3,		///< Use heuristic to choose one of the three above (see @C4D's user manual).
	NONE				= 100,	///< Do not create material.
} ; }
maxon::String PrivateToString_SUBSTANCE_MATERIAL_MODE255(std::underlying_type<enum255::SUBSTANCE_MATERIAL_MODE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum255::SUBSTANCE_MATERIAL_MODE::STANDARD, (maxon::UInt64) enum255::SUBSTANCE_MATERIAL_MODE::METALLIC, (maxon::UInt64) enum255::SUBSTANCE_MATERIAL_MODE::GLOSSY, (maxon::UInt64) enum255::SUBSTANCE_MATERIAL_MODE::AUTO, (maxon::UInt64) enum255::SUBSTANCE_MATERIAL_MODE::NONE};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SUBSTANCE_MATERIAL_MODE", SIZEOF(x), false, values, "STANDARD\0METALLIC\0GLOSSY\0AUTO\0NONE\0", fmt);
}
namespace enum268 { enum class SUBSTANCE_IMPORT_RESULT
{
	SUCCESS,					///< Success.
	DOESNOTEXIST,			///< File not found.
	NOTANASSET,				///< Wrong file format.
	UNKNOWNERROR,			///< On memory error or when invalid parameters were passed.
} ; }
maxon::String PrivateToString_SUBSTANCE_IMPORT_RESULT268(std::underlying_type<enum268::SUBSTANCE_IMPORT_RESULT>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum268::SUBSTANCE_IMPORT_RESULT::SUCCESS, (maxon::UInt64) enum268::SUBSTANCE_IMPORT_RESULT::DOESNOTEXIST, (maxon::UInt64) enum268::SUBSTANCE_IMPORT_RESULT::NOTANASSET, (maxon::UInt64) enum268::SUBSTANCE_IMPORT_RESULT::UNKNOWNERROR};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SUBSTANCE_IMPORT_RESULT", SIZEOF(x), false, values, "SUCCESS\0DOESNOTEXIST\0NOTANASSET\0UNKNOWNERROR\0", fmt);
}
namespace enum281 { enum class SUBSTANCE_IMPORT_COPY
{
	YES,	///< Automatically copy file to project directory (relative file path).
	NO,		///< Do not copy file to project directory (absolute file path).
	ASK,	///< Ask user.
} ; }
maxon::String PrivateToString_SUBSTANCE_IMPORT_COPY281(std::underlying_type<enum281::SUBSTANCE_IMPORT_COPY>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum281::SUBSTANCE_IMPORT_COPY::YES, (maxon::UInt64) enum281::SUBSTANCE_IMPORT_COPY::NO, (maxon::UInt64) enum281::SUBSTANCE_IMPORT_COPY::ASK};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SUBSTANCE_IMPORT_COPY", SIZEOF(x), false, values, "YES\0NO\0ASK\0", fmt);
}
namespace enum304 { enum class SUBSTANCE_INPUT_TYPE
{
	INTEGER,			///< ::Int32 Integer, one DescID.
	INTEGER_2,		///< ::Int32 Two component integer vector, two DescID.
	INTEGER_3,		///< ::Int32 Three component integer vector, three DescID objects.
	INTEGER_4,		///< ::Int32 Four component integer vector, four DescID objects.
	BOOL,					///< ::Bool Boolean, one DescID.
	FLOAT,				///< ::Float Float, one DescID.
	FLOAT_2,			///< ::Float Two component float vector, two DescID objects.
	FLOAT_3,			///< ::Float Three component float vector, three DescID objects.
	FLOAT_4,			///< ::Float Four component float vector, four DescID objects.
	IMAGE,				///< Filename Image input, one DescID.
	STRING,				///< String String, one DescID.
	COLOR_RGB,		///< ::Vector RGB color vector, one DescID.
	COLOR_RGBA,		///< ::Vector and ::Float RGBA color vector, two DescID objects.
	RESOLUTION,		///< ::Int32 Substance output resolution, two DescID objects , integer, range 4 to 11, 2^n pixels (16 pixels to 2048 pixels)
} ; }
maxon::String PrivateToString_SUBSTANCE_INPUT_TYPE304(std::underlying_type<enum304::SUBSTANCE_INPUT_TYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum304::SUBSTANCE_INPUT_TYPE::INTEGER, (maxon::UInt64) enum304::SUBSTANCE_INPUT_TYPE::INTEGER_2, (maxon::UInt64) enum304::SUBSTANCE_INPUT_TYPE::INTEGER_3, (maxon::UInt64) enum304::SUBSTANCE_INPUT_TYPE::INTEGER_4, (maxon::UInt64) enum304::SUBSTANCE_INPUT_TYPE::BOOL, (maxon::UInt64) enum304::SUBSTANCE_INPUT_TYPE::FLOAT, (maxon::UInt64) enum304::SUBSTANCE_INPUT_TYPE::FLOAT_2, (maxon::UInt64) enum304::SUBSTANCE_INPUT_TYPE::FLOAT_3, (maxon::UInt64) enum304::SUBSTANCE_INPUT_TYPE::FLOAT_4, (maxon::UInt64) enum304::SUBSTANCE_INPUT_TYPE::IMAGE, (maxon::UInt64) enum304::SUBSTANCE_INPUT_TYPE::STRING, (maxon::UInt64) enum304::SUBSTANCE_INPUT_TYPE::COLOR_RGB, (maxon::UInt64) enum304::SUBSTANCE_INPUT_TYPE::COLOR_RGBA, (maxon::UInt64) enum304::SUBSTANCE_INPUT_TYPE::RESOLUTION};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SUBSTANCE_INPUT_TYPE", SIZEOF(x), false, values, "INTEGER\0INTEGER_2\0INTEGER_3\0INTEGER_4\0BOOL\0FLOAT\0FLOAT_2\0FLOAT_3\0FLOAT_4\0IMAGE\0STRING\0COLOR_RGB\0COLOR_RGBA\0RESOLUTION\0", fmt);
}
namespace enum344 { enum class SUBSTANCE_OUTPUT_TYPE
{
	DIFFUSE,
	BASECOLOR,
	OPACITY,
	EMISSIVE,
	AMBIENT,
	AMBIENTOCCLUSION,
	MASK,
	NORMAL,
	BUMP,
	HEIGHT,
	DISPLACEMENT,
	SPECULAR,
	SPECULARLEVEL,
	SPECULARCOLOR,
	GLOSSINESS,
	ROUGHNESS,
	ANISOTROPYLEVEL,
	ANISOTROPYANGLE,
	TRANSMISSIVE,
	REFLECTION,
	REFRACTION,
	ENVIRONMENT,
	IOR,
	SCATTERING0,
	SCATTERING1,
	SCATTERING2,
	SCATTERING3,
	METALLIC,
	ANY,
	UNKNOWN,
	INTERNAL_COUNT
} ; }
maxon::String PrivateToString_SUBSTANCE_OUTPUT_TYPE344(std::underlying_type<enum344::SUBSTANCE_OUTPUT_TYPE>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::DIFFUSE, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::BASECOLOR, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::OPACITY, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::EMISSIVE, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::AMBIENT, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::AMBIENTOCCLUSION, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::MASK, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::NORMAL, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::BUMP, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::HEIGHT, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::DISPLACEMENT, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::SPECULAR, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::SPECULARLEVEL, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::SPECULARCOLOR, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::GLOSSINESS, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::ROUGHNESS, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::ANISOTROPYLEVEL, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::ANISOTROPYANGLE, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::TRANSMISSIVE, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::REFLECTION, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::REFRACTION, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::ENVIRONMENT, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::IOR, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::SCATTERING0, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::SCATTERING1, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::SCATTERING2, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::SCATTERING3, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::METALLIC, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::ANY, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::UNKNOWN, (maxon::UInt64) enum344::SUBSTANCE_OUTPUT_TYPE::INTERNAL_COUNT};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SUBSTANCE_OUTPUT_TYPE", SIZEOF(x), false, values, "DIFFUSE\0BASECOLOR\0OPACITY\0EMISSIVE\0AMBIENT\0AMBIENTOCCLUSION\0MASK\0NORMAL\0BUMP\0HEIGHT\0DISPLACEMENT\0SPECULAR\0SPECULARLEVEL\0SPECULARCOLOR\0GLOSSINESS\0ROUGHNESS\0ANISOTROPYLEVEL\0ANISOTROPYANGLE\0TRANSMISSIVE\0REFLECTION\0REFRACTION\0ENVIRONMENT\0IOR\0SCATTERING0\0SCATTERING1\0SCATTERING2\0SCATTERING3\0METALLIC\0ANY\0UNKNOWN\0INTERNAL_COUNT\0", fmt);
}
/// @cond IGNORE

/// @endcond

#endif
