#if 1
#ifdef __API_INTERN__
#else
#endif
namespace enum47 { enum class SCRIPTMETA : int
{
	DOCUMENTATION = 0,
	NAME
} ; }
maxon::String PrivateToString_SCRIPTMETA47(std::underlying_type<enum47::SCRIPTMETA>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum47::SCRIPTMETA::DOCUMENTATION, (maxon::UInt64) enum47::SCRIPTMETA::NAME};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "SCRIPTMETA", SIZEOF(x), false, values, "DOCUMENTATION\0NAME\0", fmt);
}
namespace enum59 { enum class PYFN_FLAGS
{
	VARARGS		= 0x0001,
	KEYWORDS	= 0x0002,
	NOARGS		= 0x0004,
	STATIC		= 0x0020,
	//////////////////////////////////////////////////////////////
	NONE = 0,

	ARGS_KEYWORDS = VARARGS | KEYWORDS
} ; }
maxon::String PrivateToString_PYFN_FLAGS59(std::underlying_type<enum59::PYFN_FLAGS>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum59::PYFN_FLAGS::VARARGS, (maxon::UInt64) enum59::PYFN_FLAGS::KEYWORDS, (maxon::UInt64) enum59::PYFN_FLAGS::NOARGS, (maxon::UInt64) enum59::PYFN_FLAGS::STATIC, (maxon::UInt64) enum59::PYFN_FLAGS::NONE, (maxon::UInt64) enum59::PYFN_FLAGS::ARGS_KEYWORDS};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "PYFN_FLAGS", SIZEOF(x), true, values, "VARARGS\0KEYWORDS\0NOARGS\0STATIC\0NONE\0ARGS_KEYWORDS\0", fmt);
}
namespace enum66 { enum class XPYCOMPILERINPUT
{
	SINGLE	= 256, // Py_single_input
	FILE 		= 257, // Py_file_input
	EVAL 		= 258, // Py_eval_input
} ; }
maxon::String PrivateToString_XPYCOMPILERINPUT66(std::underlying_type<enum66::XPYCOMPILERINPUT>::type x, const maxon::FormatStatement* fmt)
{
	const maxon::UInt64 values[] = {(maxon::UInt64) enum66::XPYCOMPILERINPUT::SINGLE, (maxon::UInt64) enum66::XPYCOMPILERINPUT::FILE, (maxon::UInt64) enum66::XPYCOMPILERINPUT::EVAL};
	return maxon::StringInterface::PrivateEnumToString((maxon::UInt64) x, "XPYCOMPILERINPUT", SIZEOF(x), false, values, "SINGLE\0FILE\0EVAL\0", fmt);
}
#endif
