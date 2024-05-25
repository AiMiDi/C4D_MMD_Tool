#if 1
#ifdef __API_INTERN__
#else
#endif
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_BEGIN
#endif
namespace enum51
{
	enum class SCRIPTMETA : int
	{
		DOCUMENTATION = 0,
		NAME
	} ;
	static const maxon::UInt64 SCRIPTMETA_values[] = {maxon::UInt64(enum51::SCRIPTMETA::DOCUMENTATION), maxon::UInt64(enum51::SCRIPTMETA::NAME)};
	static const maxon::EnumInfo SCRIPTMETA_info{"SCRIPTMETA", SIZEOF(SCRIPTMETA), false, "DOCUMENTATION\0NAME\0", SCRIPTMETA_values, std::extent<decltype(SCRIPTMETA_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_SCRIPTMETA51(){ return enum51::SCRIPTMETA_info; }
namespace enum63
{
	enum class PYFN_FLAGS
	{
		VARARGS		= 0x0001,
		KEYWORDS	= 0x0002,
		NOARGS		= 0x0004,
		STATIC		= 0x0020,
		//////////////////////////////////////////////////////////////
		NONE = 0,
	
		ARGS_KEYWORDS = VARARGS | KEYWORDS
	} ;
	static const maxon::UInt64 PYFN_FLAGS_values[] = {maxon::UInt64(enum63::PYFN_FLAGS::VARARGS), maxon::UInt64(enum63::PYFN_FLAGS::KEYWORDS), maxon::UInt64(enum63::PYFN_FLAGS::NOARGS), maxon::UInt64(enum63::PYFN_FLAGS::STATIC), maxon::UInt64(enum63::PYFN_FLAGS::NONE), maxon::UInt64(enum63::PYFN_FLAGS::ARGS_KEYWORDS)};
	static const maxon::EnumInfo PYFN_FLAGS_info{"PYFN_FLAGS", SIZEOF(PYFN_FLAGS), true, "VARARGS\0KEYWORDS\0NOARGS\0STATIC\0NONE\0ARGS_KEYWORDS\0", PYFN_FLAGS_values, std::extent<decltype(PYFN_FLAGS_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_PYFN_FLAGS63(){ return enum63::PYFN_FLAGS_info; }
namespace enum70
{
	enum class XPYCOMPILERINPUT
	{
		SINGLE	= 256, // Py_single_input
		FILE 		= 257, // Py_file_input
		EVAL 		= 258, // Py_eval_input
	} ;
	static const maxon::UInt64 XPYCOMPILERINPUT_values[] = {maxon::UInt64(enum70::XPYCOMPILERINPUT::SINGLE), maxon::UInt64(enum70::XPYCOMPILERINPUT::FILE), maxon::UInt64(enum70::XPYCOMPILERINPUT::EVAL)};
	static const maxon::EnumInfo XPYCOMPILERINPUT_info{"XPYCOMPILERINPUT", SIZEOF(XPYCOMPILERINPUT), false, "SINGLE\0FILE\0EVAL\0", XPYCOMPILERINPUT_values, std::extent<decltype(XPYCOMPILERINPUT_values)>::value};
}
const maxon::EnumInfo& PrivateGetEnumInfo_XPYCOMPILERINPUT70(){ return enum70::XPYCOMPILERINPUT_info; }
#ifdef CINEWARE_NAMESPACE_ENABLE
CINEWARE_NAMESPACE_END
#endif
#endif
